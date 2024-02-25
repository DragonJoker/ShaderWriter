#include "CompileSPIRV.hpp"

#include <ShaderAST/Shader.hpp>

#pragma warning( disable: 5262 )

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wtype-limits"
#if SDW_Test_HasSpirVTools
#	include "spirv-tools/libspirv.hpp"
#endif
#pragma GCC diagnostic pop

#if SDW_Test_HasVulkan

#include "./vulkan/vulkan.h"

#if SDW_HasVulkanLayer
#	include <VulkanLayer/PipelineBuilder.hpp>
#	include <VulkanLayer/ProgramPipeline.hpp>
#	include <VulkanLayer/MakeVkType.hpp>
#endif
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>

#endif

namespace test
{
	namespace sdw_test
	{
		static constexpr uint32_t makeVkVersion( uint32_t variant, uint32_t major, uint32_t minor, uint32_t patch )
		{
			return ( ( ( uint32_t( variant ) ) << 29 )
				| ( ( uint32_t( major ) ) << 22 )
				| ( ( uint32_t( minor ) ) << 12 )
				| ( uint32_t( patch ) ) );
		}

		static constexpr uint32_t spv1_0 = 0x00010000u;
		static constexpr uint32_t spv1_1 = 0x00010100u;
		static constexpr uint32_t spv1_2 = 0x00010200u;
		static constexpr uint32_t spv1_3 = 0x00010300u;
		static constexpr uint32_t spv1_4 = 0x00010400u;
		static constexpr uint32_t spv1_5 = 0x00010500u;
		static constexpr uint32_t spv1_6 = 0x00010600u;

		static constexpr uint32_t vk1_0 = makeVkVersion( 0, 1, 0, 0 );
		static constexpr uint32_t vk1_1 = makeVkVersion( 0, 1, 1, 0 );
		static constexpr uint32_t vk1_2 = makeVkVersion( 0, 1, 2, 0 );
		static constexpr uint32_t vk1_3 = makeVkVersion( 0, 1, 3, 0 );

		static uint32_t getMaxSpvVersion( uint32_t vkVersion )
		{
			uint32_t result{ spv1_0 };

			if ( vkVersion >= vk1_3 )
			{
				result = spv1_6;
			}
			else if ( vkVersion >= vk1_2 )
			{
				result = spv1_5;
			}
			else if ( vkVersion >= vk1_1 )
			{
				result = spv1_3;
			}
			else if ( vkVersion >= vk1_0 )
			{
				result = spv1_0;
			}

			return result;
		}
	}

#if SDW_Test_HasVulkan

	namespace
	{
		struct LayerProperties
		{
			VkLayerProperties properties{};
			std::vector<VkExtensionProperties> instanceExtensions{};
		};

		struct Info
		{
			Info( uint32_t papiVersion
				, uint32_t pspvVersion )
				: apiVersion{ papiVersion }
				, spvVersion{ pspvVersion }
			{
			}

			uint32_t apiVersion;
			uint32_t spvVersion;
			std::vector< const char * > instanceLayerNames{};
			std::vector< const char * > instanceExtensionNames{};
			std::vector< LayerProperties > instanceLayerProperties{};
			VkInstance instance{};

			std::vector< const char *> deviceExtensionNames{};
			std::vector< VkPhysicalDevice > gpus{};
			VkDevice device{};
			uint32_t queueFamilyCount{};
			std::vector< VkQueueFamilyProperties > queueProps{};

			PFN_vkCreateDebugUtilsMessengerEXT dbgCreateDebugUtilsMessenger{};
			PFN_vkDestroyDebugUtilsMessengerEXT dbgDestroyDebugUtilsMessenger{};
			PFN_vkDebugReportMessageEXT dbgBreakCallback{};
			std::vector< VkDebugUtilsMessengerEXT > debugReportCallbacks{};

			bool compiling{};
			std::vector< std::string > errors{};
		};

		using InfoPtr = std::unique_ptr< Info >;

		class StringDelimitedByPipes : public std::string
		{
		};

		std::istream & operator>>( std::istream & is, StringDelimitedByPipes & output )
		{
			std::getline( is, output, '|' );
			return is;
		}

		VkBool32 VKAPI_CALL dbgFunc( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity
			, VkDebugUtilsMessageTypeFlagsEXT messageTypes
			, VkDebugUtilsMessengerCallbackDataEXT const * pCallbackData
			, void * pUserData )
		{
			VkBool32 result = VK_FALSE;

			if ( !pCallbackData->messageIdNumber
				|| pCallbackData->messageIdNumber == 0x79de34d4 )
			{
				return result;
			}

			std::stringstream stream;
			stream.imbue( std::locale{ "C" } );
			bool isError{ false };

			switch ( messageSeverity )
			{
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
				isError = true;
				stream << "Error";
				break;
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
				stream << "Warning";
				break;
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
				stream << "Info";
				break;
			case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
				stream << "Verbose";
				break;
			default:
				break;
			}

			if ( messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT )
			{
				stream << " - General";
			}
			if ( messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT )
			{
				stream << " - Validation";
			}
			if ( messageTypes & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT )
			{
				stream << " - Performance";
			}

			if ( pCallbackData->pMessageIdName )
			{
				stream << " - Message ID: " << pCallbackData->pMessageIdName << std::endl;
			}

			stream << "Code: 0x" << std::hex << pCallbackData->messageIdNumber << std::endl;
			stream << "Message: " << std::endl;
			std::istringstream iss( pCallbackData->pMessage );
			std::vector< std::string > results
			{
				std::istream_iterator< StringDelimitedByPipes >( iss ),
				std::istream_iterator< StringDelimitedByPipes >()
			};

			for ( auto & line : results )
			{
				stream << "    " << line << std::endl;

				if ( line.find( "failed to compile internal representation" ) != std::string::npos )
				{
					isError = true;
				}
			}

			auto info = reinterpret_cast< Info * >( pUserData );

			if ( info->compiling && isError )
			{
				info->errors.push_back( stream.str() );
			}
			else
			{
				std::cout << stream.str() << std::endl;
			}

			// The return value of this callback controls wether the Vulkan call that caused
			// the validation message will be aborted or not
			// Return VK_FALSE if we DON'T want Vulkan calls that cause a validation message 
			// (and return a VkResult) to abort
			// Return VK_TRUE if you instead want to have calls abort, and the function will 
			// return VK_ERROR_VALIDATION_FAILED_EXT 
			return result;
		}

		VkResult initInstanceExtensionProperties( LayerProperties & layerProps )
		{
			VkExtensionProperties * instanceExtensions;
			uint32_t instanceExtensionCount;
			VkResult res;
			char *layer_name = nullptr;

			layer_name = layerProps.properties.layerName;

			do
			{
				res = vkEnumerateInstanceExtensionProperties( layer_name, &instanceExtensionCount, nullptr );
				if ( res ) return res;

				if ( instanceExtensionCount == 0 )
				{
					return VK_SUCCESS;
				}

				layerProps.instanceExtensions.resize( instanceExtensionCount );
				instanceExtensions = layerProps.instanceExtensions.data();
				res = vkEnumerateInstanceExtensionProperties( layer_name, &instanceExtensionCount, instanceExtensions );
			}
			while ( res == VK_INCOMPLETE );

			return res;
		}

		VkResult initDeviceExtensionProperties( VkPhysicalDevice physicalDevice
			, std::vector< VkExtensionProperties > & deviceExtensions )
		{
			VkResult res;
			char const * layerName = "";

			do
			{
				uint32_t count;
				res = vkEnumerateDeviceExtensionProperties( physicalDevice
					, layerName
					, &count
					, nullptr );

				if ( res )
				{
					return res;
				}

				if ( count == 0 )
				{
					return VK_SUCCESS;
				}

				deviceExtensions.resize( count );
				auto extensions = deviceExtensions.data();
				res = vkEnumerateDeviceExtensionProperties( physicalDevice
					, layerName
					, &count
					, extensions );
			}
			while ( res == VK_INCOMPLETE );

			return res;
		}

		VkResult initGlobalLayerProperties( Info & info )
		{
			uint32_t instanceLayerCount;
			std::vector< VkLayerProperties > layersProps;
			VkResult res;
			do
			{
				res = vkEnumerateInstanceLayerProperties( &instanceLayerCount, nullptr );

				if ( res )
				{
					return res;
				}

				if ( instanceLayerCount == 0 )
				{
					return VK_SUCCESS;
				}

				layersProps.resize( instanceLayerCount );
				res = vkEnumerateInstanceLayerProperties( &instanceLayerCount, layersProps.data() );
			}
			while ( res == VK_INCOMPLETE );

			for ( uint32_t i = 0; i < instanceLayerCount; i++ )
			{
				LayerProperties layerProps;
				layerProps.properties = layersProps[i];
				res = initInstanceExtensionProperties( layerProps );

				if ( res )
				{
					return res;
				}

				info.instanceLayerProperties.push_back( layerProps );
			}

			return res;
		}

		bool isLayerSupported( std::string_view name
			, std::vector< LayerProperties > const & cont )
		{
			return ( cont.end() != std::find_if( cont.begin()
				, cont.end()
				, [&name]( LayerProperties const & lookup )
				{
					return lookup.properties.layerName == name;
				} ) );
		}

		bool isExtensionSupported( std::string_view name
			, std::vector< VkExtensionProperties > const & cont )
		{
			return ( cont.end() != std::find_if( cont.begin()
				, cont.end()
				, [&name]( VkExtensionProperties const & lookup )
				{
					return lookup.extensionName == name;
				} ) );
		}

		bool createInstance( Info & info )
		{
			initGlobalLayerProperties( info );
			info.instanceLayerNames.push_back( "VK_LAYER_KHRONOS_validation" );
			info.instanceExtensionNames.push_back( VK_EXT_DEBUG_UTILS_EXTENSION_NAME );

			if ( isLayerSupported( VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME
				, info.instanceLayerProperties ) )
			{
				info.instanceExtensionNames.push_back( VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME );
			}

			uint32_t apiVersion{};
			vkEnumerateInstanceVersion( &apiVersion );

			if ( apiVersion < info.apiVersion )
			{
				std::cout << "Required version not supported by Vulkan instance\n";
				return false;
			}

			// initialize the VkApplicationInfo structure
			auto appInfo = ast::vk::makeVkStruct< VkApplicationInfo >();
			appInfo.pApplicationName = "Test";
			appInfo.applicationVersion = VK_MAKE_API_VERSION( 0, MAIN_VERSION_MAJOR, MAIN_VERSION_MINOR, MAIN_VERSION_BUILD );
			appInfo.pEngineName = "Test";
			appInfo.engineVersion = 1;
			appInfo.apiVersion = info.apiVersion;

			// initialize the VkInstanceCreateInfo structure
			auto instInfo = ast::vk::makeVkStruct< VkInstanceCreateInfo >();
			instInfo.pNext = nullptr;
			instInfo.flags = 0;
			instInfo.pApplicationInfo = &appInfo;
			instInfo.enabledExtensionCount = uint32_t( info.instanceExtensionNames.size() );
			instInfo.ppEnabledExtensionNames = info.instanceExtensionNames.data();
			instInfo.enabledLayerCount = uint32_t( info.instanceLayerNames.size() );
			instInfo.ppEnabledLayerNames = info.instanceLayerNames.data();
			VkResult res;

			res = vkCreateInstance( &instInfo, nullptr, &info.instance );

			if ( res == VK_ERROR_INCOMPATIBLE_DRIVER )
			{
				std::cout << "cannot find a compatible Vulkan ICD\n";
			}
			else if ( res )
			{
				std::cout << "unknown error\n";
			}

			if ( res == VK_SUCCESS )
			{
	#pragma warning( push )
	#pragma warning( disable: 4191 )
				info.dbgCreateDebugUtilsMessenger =
					PFN_vkCreateDebugUtilsMessengerEXT( vkGetInstanceProcAddr( info.instance, "vkCreateDebugUtilsMessengerEXT" ) );
				if ( !info.dbgCreateDebugUtilsMessenger )
				{
					std::cout << "GetInstanceProcAddr: Unable to find "
						"vkCreateDebugUtilsMessengerEXT function."
						<< std::endl;
					exit( 1 );
				}

				info.dbgDestroyDebugUtilsMessenger =
					PFN_vkDestroyDebugUtilsMessengerEXT( vkGetInstanceProcAddr( info.instance, "vkDestroyDebugUtilsMessengerEXT" ) );
				if ( !info.dbgDestroyDebugUtilsMessenger )
				{
					std::cout << "GetInstanceProcAddr: Unable to find "
						"vkDestroyDebugUtilsMessengerEXT function."
						<< std::endl;
					exit( 1 );
				}
	#pragma warning( pop )

				VkDebugUtilsMessageSeverityFlagsEXT severityFlags = 0u
					| VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
				VkDebugUtilsMessageTypeFlagsEXT typeFlags = 0u
					| VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
					| VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
				auto createInfo = ast::vk::makeVkStruct< VkDebugUtilsMessengerCreateInfoEXT >( 0u
					, severityFlags
					, typeFlags
					, dbgFunc
					, &info );

				info.debugReportCallbacks.resize( 1u );
				res = info.dbgCreateDebugUtilsMessenger( info.instance, &createInfo, nullptr, info.debugReportCallbacks.data() );
				switch ( res )
				{
				case VK_SUCCESS:
					break;
				case VK_ERROR_OUT_OF_HOST_MEMORY:
					std::cout << "dbgCreateDebugUtilsMessenger: out of host memory\n" << std::endl;
					exit( 1 );
				default:
					std::cout << "dbgCreateDebugUtilsMessenger: unknown failure\n" << std::endl;
					exit( 1 );
				}
			}

			return res == VK_SUCCESS;
		}

		bool createDevice( Info & info )
		{
			uint32_t gpuCount = 1;
			auto res = vkEnumeratePhysicalDevices( info.instance, &gpuCount, nullptr );

			if ( res == VK_SUCCESS )
			{
				assert( gpuCount );
				info.gpus.resize( gpuCount );
				res = vkEnumeratePhysicalDevices( info.instance, &gpuCount, info.gpus.data() );

				if ( res == VK_SUCCESS )
				{
					assert( gpuCount >= 1 );
					uint32_t gpuIndex = 0u;

					while ( gpuIndex < gpuCount )
					{
						VkPhysicalDeviceProperties properties = {};
						vkGetPhysicalDeviceProperties( info.gpus[gpuIndex], &properties );
						++gpuIndex;

						if ( properties.apiVersion >= info.apiVersion )
						{
							break;
						}
					}

					--gpuIndex;
					auto gpu = info.gpus[gpuIndex];
					auto queue_info = ast::vk::makeVkStruct< VkDeviceQueueCreateInfo >();
					queue_info.queueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;

					vkGetPhysicalDeviceQueueFamilyProperties( gpu, &info.queueFamilyCount, nullptr );
					assert( info.queueFamilyCount >= 1 );

					info.queueProps.resize( info.queueFamilyCount );
					vkGetPhysicalDeviceQueueFamilyProperties( gpu, &info.queueFamilyCount, info.queueProps.data() );
					assert( info.queueFamilyCount >= 1 );

					for ( unsigned int i = 0; i < info.queueFamilyCount; i++ )
					{
						if ( info.queueProps[i].queueFlags & VK_QUEUE_GRAPHICS_BIT )
						{
							queue_info.queueFamilyIndex = i;
							break;
						}
					}
					assert( queue_info.queueFamilyIndex != VK_QUEUE_FAMILY_IGNORED );
					assert( info.queueFamilyCount >= 1 );

					float queue_priorities[1] = { 0.0 };
					queue_info.queueCount = 1;
					queue_info.pQueuePriorities = queue_priorities;

					std::vector<VkExtensionProperties> device_extensions;
					initDeviceExtensionProperties( info.gpus[0], device_extensions );
					struct VkStructure
					{
						VkStructureType sType;
						VkStructure * pNext;
					};
					std::vector< VkStructure * > featuresStructs;
					VkPhysicalDeviceFeatures features{};
					auto features2 = ast::vk::makeVkStruct< VkPhysicalDeviceFeatures2 >();
					auto features12 = ast::vk::makeVkStruct< VkPhysicalDeviceVulkan12Features >();
					auto features11 = ast::vk::makeVkStruct< VkPhysicalDeviceVulkan11Features >();
					auto drawParamsFeatures = ast::vk::makeVkStruct< VkPhysicalDeviceShaderDrawParametersFeatures >();
					auto accelFeature = ast::vk::makeVkStruct< VkPhysicalDeviceAccelerationStructureFeaturesKHR >();
					auto rtPipelineFeature = ast::vk::makeVkStruct< VkPhysicalDeviceRayTracingPipelineFeaturesKHR >();
					auto demoteFeature = ast::vk::makeVkStruct< VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT >();
					auto terminateFeature = ast::vk::makeVkStruct< VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR >();
					auto meshNVFeature = ast::vk::makeVkStruct< VkPhysicalDeviceMeshShaderFeaturesNV >();
					auto atomicFloatFeature = ast::vk::makeVkStruct< VkPhysicalDeviceShaderAtomicFloatFeaturesEXT >();
					bool hasFeatures2 = false;
					bool hasVulkan1_1 = false;
					bool hasFloatControls = false;
					bool hasSpirv1_4 = false;

					if ( info.apiVersion >= VK_MAKE_API_VERSION( 0, 1, 2, 0 ) )
					{
						hasFeatures2 = true;
						hasVulkan1_1 = true;
						hasFloatControls = true;
						hasSpirv1_4 = true;
						featuresStructs.push_back( reinterpret_cast< VkStructure * >( &features12 ) );
						featuresStructs.push_back( reinterpret_cast< VkStructure * >( &features11 ) );
					}
					else if ( info.apiVersion >= VK_MAKE_API_VERSION( 0, 1, 1, 0 ) )
					{
						hasFeatures2 = true;
						hasVulkan1_1 = true;
						featuresStructs.push_back( reinterpret_cast< VkStructure * >( &drawParamsFeatures ) );
					}
					else
					{
						if ( isExtensionSupported( "VK_KHR_shader_draw_parameters"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_KHR_shader_draw_parameters" );
						}
					}

					if ( !hasFeatures2
						&& isExtensionSupported( "VK_KHR_get_physical_device_properties2"
							, device_extensions ) )
					{
						hasFeatures2 = true;
						info.deviceExtensionNames.push_back( "VK_KHR_get_physical_device_properties2" );
					}

					if ( hasFeatures2 )
					{
						if ( !hasFloatControls
							&& isExtensionSupported( "VK_KHR_shader_float_controls"
								, device_extensions ) )
						{
							hasFloatControls = true;
							info.deviceExtensionNames.push_back( "VK_KHR_shader_float_controls" );
						}

						if ( !hasSpirv1_4
							&& hasVulkan1_1
							&& hasFloatControls )
						{
							if ( isExtensionSupported( "VK_KHR_spirv_1_4"
								, device_extensions ) )
							{
								hasSpirv1_4 = true;
								info.deviceExtensionNames.push_back( "VK_KHR_spirv_1_4" );
							}
						}

						if ( isExtensionSupported( "VK_EXT_shader_atomic_float"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_EXT_shader_atomic_float" );
							featuresStructs.push_back( reinterpret_cast< VkStructure * >( &atomicFloatFeature ) );
						}

						if ( isExtensionSupported( "VK_EXT_mesh_shader"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_EXT_mesh_shader" );
							//featuresStructs.push_back( reinterpret_cast< VkStructure * >( &meshEXTFeature ) );
						}

						if ( isExtensionSupported( "VK_NV_mesh_shader"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_NV_mesh_shader" );
							featuresStructs.push_back( reinterpret_cast< VkStructure * >( &meshNVFeature ) );
						}

						if ( isExtensionSupported( "VK_KHR_shader_terminate_invocation"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_KHR_shader_terminate_invocation" );
							featuresStructs.push_back( reinterpret_cast< VkStructure * >( &terminateFeature ) );
						}

						if ( isExtensionSupported( "VK_EXT_shader_demote_to_helper_invocation"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_EXT_shader_demote_to_helper_invocation" );
							featuresStructs.push_back( reinterpret_cast< VkStructure * >( &demoteFeature ) );
						}

						if ( isExtensionSupported( "VK_EXT_descriptor_indexing"
							, device_extensions ) )
						{
							info.deviceExtensionNames.push_back( "VK_EXT_descriptor_indexing" );

							if ( isExtensionSupported( "VK_KHR_buffer_device_address"
								, device_extensions ) )
							{
								info.deviceExtensionNames.push_back( "VK_KHR_buffer_device_address" );

								if ( isExtensionSupported( "VK_KHR_acceleration_structure"
									, device_extensions ) )
								{
									info.deviceExtensionNames.push_back( "VK_KHR_acceleration_structure" );
									featuresStructs.push_back( reinterpret_cast< VkStructure * >( &accelFeature ) );

									if ( hasSpirv1_4
										&& isExtensionSupported( "VK_KHR_ray_tracing_pipeline"
											, device_extensions ) )
									{
										info.deviceExtensionNames.push_back( "VK_KHR_ray_tracing_pipeline" );
										featuresStructs.push_back( reinterpret_cast< VkStructure * >( &rtPipelineFeature ) );
									}
								}
							}
						}
					}

					if ( isExtensionSupported( "VK_KHR_deferred_host_operations"
						, device_extensions ) )
					{
						info.deviceExtensionNames.push_back( "VK_KHR_deferred_host_operations" );
					}

					VkStructure * current = reinterpret_cast< VkStructure * >( &features2 );

					// build up chain of all used extension features
					for ( size_t i = 0; i < featuresStructs.size(); i++ )
					{
						current->pNext = featuresStructs[i];

						while ( current->pNext )
						{
							current = current->pNext;
						}
					}

					if ( info.apiVersion >= VK_MAKE_API_VERSION( 0, 1, 1, 0 ) )
					{
						vkGetPhysicalDeviceFeatures2( gpu, &features2 );
						features = features2.features;
					}
					else
					{
						vkGetPhysicalDeviceFeatures( gpu, &features );
					}

					auto device_info = ast::vk::makeVkStruct< VkDeviceCreateInfo >();
					device_info.queueCreateInfoCount = 1;
					device_info.pQueueCreateInfos = &queue_info;
					device_info.enabledExtensionCount = uint32_t( info.deviceExtensionNames.size() );
					device_info.ppEnabledExtensionNames = info.deviceExtensionNames.data();
					device_info.enabledLayerCount = 0;
					device_info.ppEnabledLayerNames = nullptr;

					if ( info.apiVersion >= VK_MAKE_API_VERSION( 0, 1, 1, 0 ) )
					{
						device_info.pNext = &features2;
					}
					else
					{
						device_info.pEnabledFeatures = &features;
					}

					res = vkCreateDevice( gpu, &device_info, nullptr, &info.device );
				}
			}

			return res == VK_SUCCESS;
		}

		std::ostream & operator<<( std::ostream & stream
			, std::vector< uint32_t > const & spirv )
		{
			for ( auto i = 0u; i < spirv.size(); i += 8 )
			{
				for ( auto j = i; j < spirv.size() && j < i + 8; ++j )
				{
					stream << std::hex << std::setfill( '0' ) << std::setw( 8 ) << spirv[j] << " ";
				}

				stream << "\n";
			}

			return stream;
		}

		bool createShaderModule( Info & info
			, std::vector< uint32_t > const & spirv )
		{
			auto createInfo = ast::vk::makeVkStruct< VkShaderModuleCreateInfo >();
			createInfo.pCode = spirv.data();
			createInfo.codeSize = size_t( uint64_t( spirv.size() ) * sizeof( uint32_t ) );
			VkShaderModule shaderModule;
			bool result = false;

			try
			{
				result = vkCreateShaderModule( info.device, &createInfo, nullptr, &shaderModule ) == VK_SUCCESS;

				if ( result && shaderModule != nullptr )
				{
					vkDestroyShaderModule( info.device, shaderModule, nullptr );
				}
			}
			catch ( ... )
			{
				result = false;
			}

			return result;
		}
	}

	namespace sdw_test
	{
		struct SPIRVContext
		{
			SPIRVContext( SPIRVContext const & ) = delete;
			SPIRVContext & operator=( SPIRVContext const & ) = delete;
			SPIRVContext( SPIRVContext && )noexcept = delete;
			SPIRVContext & operator=( SPIRVContext && )noexcept = delete;

			SPIRVContext()noexcept
			{
				static const std::vector< uint32_t > spvVersions{ spv1_0, spv1_1, spv1_2, spv1_3, spv1_4, spv1_5, spv1_6 };
				static const std::vector< uint32_t > vkVersions{ vk1_0, vk1_1, vk1_2, vk1_3 };

				uint32_t maxApiVersion{};
				vkEnumerateInstanceVersion( &maxApiVersion );

				for ( auto vkV : vkVersions )
				{
					if ( vkV <= maxApiVersion )
					{
						auto maxSpvVersion = getMaxSpvVersion( vkV );

						for ( auto it = spvVersions.begin(); it != spvVersions.end(); ++it )
						{
							if ( *it <= maxSpvVersion )
							{
								infos.push_back( initialiseInfo( vkV, *it ) );
							}
						}
					}
				}
			}

			~SPIRVContext()noexcept
			{
				for ( auto & info : infos )
				{
					if ( info )
					{
						vkDestroyDevice( info->device, nullptr );
					}
				}
			}

			static InfoPtr initialiseInfo( uint32_t apiVersion
				, uint32_t spvVersion )
			{
				auto result = std::make_unique< Info >( apiVersion, spvVersion );

				if ( createInstance( *result )
					&& !createDevice( *result ) )
				{
					result->dbgDestroyDebugUtilsMessenger( result->instance
						, *result->debugReportCallbacks.data()
						, nullptr );
					vkDestroyInstance( result->instance, nullptr );
					throw std::runtime_error{ "Can't initialise Vulkan device" };
				}

				return result;
			}

			std::vector< InfoPtr > infos;
		};
	}

	static Info * retrieveInfo( sdw_test::TestCounts const & testCounts
		, [[maybe_unused]] uint32_t infoIndex )
	{
#if SDW_Test_Coverage
		return testCounts.spirv->infos.back().get();
#else
		return testCounts.spirv->infos[infoIndex].get();
#endif
	}

	bool retrieveIsSpirVInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return retrieveInfo( testCounts, infoIndex )
			&& retrieveInfo( testCounts, infoIndex )->instance
			&& retrieveInfo( testCounts, infoIndex )->device;
	}

	uint32_t retrieveVulkanVersion( sdw_test::TestCounts const & testCounts
		, [[maybe_unused]] uint32_t infoIndex )
	{
		auto info = retrieveInfo( testCounts, infoIndex );
		return info
			? info->apiVersion
			: 0u;
	}

	uint32_t retrieveSPIRVVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		if ( !retrieveIsSpirVInitialised( testCounts, infoIndex ) )
		{
			return 0u;
		}

		auto info = retrieveInfo( testCounts, infoIndex );
		return info->spvVersion;
	}

	uint32_t retrieveSpirVInfosSize( [[maybe_unused]] sdw_test::TestCounts const & testCounts )
	{
#if SDW_Test_Coverage
		return 1u;
#else
		return uint32_t( testCounts.spirv->infos.size() );
#endif
	}

	uint32_t getSpirVTargetEnv( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		auto spvVersion = retrieveSPIRVVersion( testCounts, infoIndex );

		switch ( spvVersion )
		{
		case sdw_test::spv1_0:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_0;
		case sdw_test::spv1_1:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_1;
		case sdw_test::spv1_2:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_2;
		case sdw_test::spv1_3:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_3;
		case sdw_test::spv1_4:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_4;
		case sdw_test::spv1_5:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_5;
		case sdw_test::spv1_6:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_6;
		default:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_6;
		}
	}

	bool createSPIRVContext( sdw_test::TestCounts & testCounts )
	{
		bool result = false;

		try
		{
			testCounts.spirv = std::make_shared< sdw_test::SPIRVContext >();
			result = true;
		}
		catch ( std::exception & exc )
		{
			testCounts << exc.what() << endl;
		}

		return result;
	}

	void destroySPIRVContext( sdw_test::TestCounts & testCounts )
	{
		testCounts.spirv.reset();
	}

	template< typename FuncT >
	bool wrapCall( std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex
		, FuncT func )
	{
		auto & info = *retrieveInfo( testCounts, infoIndex );
		info.compiling = true;
		bool result = func();
		info.compiling = false;

		if ( !info.errors.empty() )
		{
			auto errorsList = std::move( info.errors );

			if ( errorsList.size() == 1u )
			{
				auto it = errorsList.front().find( testCounts.expectedError );

				if ( it == std::string::npos
					|| testCounts.expectedError.empty() )
				{
					result = false;
					errors += errorsList.front() + "\n";
				}
			}
			else
			{
				result = false;

				for ( auto & error : errorsList )
				{
					errors += error + "\n";
				}
			}
		}

		return result;
	}

	bool compileSpirV( ast::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
		auto result = wrapCall( errors
			, testCounts
			, infoIndex
			, [&]()
			{
				auto info = retrieveInfo( testCounts, infoIndex );
				return createShaderModule( *info, spirv );
			} );

		if ( !result )
		{
			std::stringstream stream;
			stream.imbue( std::locale{ "C" } );
			stream << "SPIR-V size: " << spirv.size() << "\n"
				<< "SPIR-V:\n"
				<< spirv << std::endl;
			errors += stream.str();
		}

		return result;
	}

#if SDW_HasVulkanLayer
	namespace
	{
		uint32_t getSize( VkFormat format )
		{
			switch ( format )
			{
			case VK_FORMAT_R8_UNORM:
				return 1u;
			case VK_FORMAT_R16_SFLOAT:
			case VK_FORMAT_R8G8_UNORM:
				return 2u;
			case VK_FORMAT_R8G8B8_UNORM:
				return 3u;
			case VK_FORMAT_R32_SINT:
			case VK_FORMAT_R32_UINT:
			case VK_FORMAT_R32_SFLOAT:
			case VK_FORMAT_R8G8B8A8_UNORM:
			case VK_FORMAT_R16G16_SFLOAT:
				return 4u;
			case VK_FORMAT_R16G16B16_SFLOAT:
				return 6u;
			case VK_FORMAT_R64_SFLOAT:
			case VK_FORMAT_R32G32_SINT:
			case VK_FORMAT_R32G32_UINT:
			case VK_FORMAT_R16G16B16A16_SFLOAT:
			case VK_FORMAT_R32G32_SFLOAT:
				return 8u;
			case VK_FORMAT_R32G32B32_SINT:
			case VK_FORMAT_R32G32B32_UINT:
			case VK_FORMAT_R32G32B32_SFLOAT:
				return 12u;
			case VK_FORMAT_R32G32B32A32_SINT:
			case VK_FORMAT_R32G32B32A32_UINT:
			case VK_FORMAT_R32G32B32A32_SFLOAT:
			case VK_FORMAT_R64G64_SFLOAT:
				return 16u;
			case VK_FORMAT_R64G64B64_SFLOAT:
				return 24u;
			case VK_FORMAT_R64G64B64A64_SFLOAT:
				return 32u;
			default:
				AST_Failure( "Unsupported VkFormat for a vertex attribute." );
				return 4u;
			}
		}

		VkRenderPass createRenderPass( ast::vk::ProgramPipeline const & program
			, ast::vk::BuilderContext const & context
			, std::string & errors
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
			auto attachmentsMap = program.getAttachmentDescriptions();
			std::vector< VkAttachmentDescription > attachments;
			std::vector< VkAttachmentReference > references;

			for ( auto const & [_, attach] : attachmentsMap )
			{
				attachments.push_back( attach );
				auto & attachment = attachments.back();
				attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
				attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
				attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
				attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
				attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
				attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
				references.push_back( { uint32_t( attachments.size() - 1u )
					, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL } );
			}

			std::vector< VkSubpassDescription > subpasses;
			subpasses.push_back( { 0u
					, VK_PIPELINE_BIND_POINT_GRAPHICS
					, 0u
					, nullptr
					, uint32_t( references.size() )
					, references.data()
					, nullptr
					, nullptr
					, 0u
					, nullptr } );

			std::vector< VkSubpassDependency > dependencies;
			dependencies.push_back( { VK_SUBPASS_EXTERNAL
					, 0u
					, VK_PIPELINE_STAGE_HOST_BIT
					, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT
					, VK_ACCESS_HOST_READ_BIT
					, VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT
					, VK_DEPENDENCY_BY_REGION_BIT } );
			dependencies.push_back( { 0u
					, VK_SUBPASS_EXTERNAL
					, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT
					, VK_PIPELINE_STAGE_HOST_BIT
					, VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT
					, VK_ACCESS_HOST_READ_BIT
					, VK_DEPENDENCY_BY_REGION_BIT } );

			auto renderPassCreate = ast::vk::makeVkStruct< VkRenderPassCreateInfo >( 0u
				, uint32_t( attachments.size() )
				, attachments.data()
				, uint32_t( subpasses.size() )
				, subpasses.data()
				, uint32_t( dependencies.size() )
				, dependencies.data() );
			VkRenderPass renderPass{ nullptr };

			if ( !wrapCall( errors
				, testCounts
				, infoIndex
				, [&]()
				{
					return ast::vk::checkError( vkCreateRenderPass( context.device
						, &renderPassCreate
						, context.allocator
						, &renderPass ) );
				} ) )
			{
				if ( renderPass )
				{
					vkDestroyRenderPass( context.device
						, renderPass
						, context.allocator );
				}

				failure( "VkRenderPass creation." );
				renderPass = nullptr;
			}

			return renderPass;
		}

		VkPipeline createComputePipeline( ast::vk::PipelineBuilder const & builder
			, ast::vk::PipelineShaderStageCreateInfo const & shaderStage
			, VkPipelineLayout pipelineLayout
			, std::string & errors
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
			auto createInfos = ast::vk::makeVkStruct< VkComputePipelineCreateInfo >( 0u
				, shaderStage.data
				, pipelineLayout
				, nullptr
				, 0 );
			VkPipeline pipeline{ nullptr };

			if ( !wrapCall( errors
				, testCounts
				, infoIndex
				, [&]()
				{
					return ast::vk::checkError( builder.createComputePipeline( createInfos, &pipeline ) );
				} ) )
			{
				if ( pipeline )
				{
					vkDestroyPipeline( builder.getDevice()
						, pipeline
						, builder.getAllocator() );
				}

				failure( "Pipeline creation" );
				pipeline = nullptr;
			}

			return pipeline;
		}

		VkPipeline createGraphicsPipeline( ast::vk::ProgramPipeline const & program
			, ast::vk::PipelineBuilder const & builder
			, ast::vk::PipelineShaderStageArray const & shaderStages
			, VkPipelineLayout pipelineLayout
			, VkRenderPass renderPass
			, std::string & errors
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
			bool hasTessellation = program.hasTessellationStage();
			auto attachmentsMap = program.getAttachmentDescriptions();

			// Pipeline shader stage states
			ast::vk::VkPipelineShaderStageArray vkShaderStages;

			for ( auto & stage : shaderStages )
			{
				vkShaderStages.push_back( stage.data );
			}

			// Pipeline vertex input state
			auto vertexAttributes = program.getVertexAttributes();
			uint32_t size = 0u;

			for ( auto & attribute : vertexAttributes )
			{
				attribute.binding = 0u;
				attribute.offset = size;
				size += getSize( attribute.format );
			}

			VkVertexInputBindingDescription binding{ 0u
				, size
				, VK_VERTEX_INPUT_RATE_VERTEX };
			auto vertexInputState = ast::vk::makeVkStruct< VkPipelineVertexInputStateCreateInfo >( 0u
				, size ? 1u : 0u
				, size ? &binding : nullptr
				, size ? uint32_t( vertexAttributes.size() ) : 0u
				, size ? vertexAttributes.data() : nullptr );
			auto inputAssemblyState = ast::vk::makeVkStruct< VkPipelineInputAssemblyStateCreateInfo >(0u
				, ( hasTessellation ? VK_PRIMITIVE_TOPOLOGY_PATCH_LIST : VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST )
				, VK_FALSE );
			VkViewport viewport{ 0.0f, 0.0f, 800.0f, 600.0f, 0.0f, 1.0f };
			VkRect2D scissor{ { 0, 0 }, { 800u, 600u } };
			auto viewportState = ast::vk::makeVkStruct< VkPipelineViewportStateCreateInfo >( 0u
				, 1u
				, &viewport
				, 1u
				, &scissor );
			auto rasterizationState = ast::vk::makeVkStruct< VkPipelineRasterizationStateCreateInfo >( 0u
				, VK_FALSE
				, VK_FALSE
				, VK_POLYGON_MODE_FILL
				, VkCullModeFlags( VK_CULL_MODE_NONE )
				, VK_FRONT_FACE_COUNTER_CLOCKWISE
				, VK_FALSE
				, 0.0f
				, 0.0f
				, 0.0f
				, 1.0f );
			auto multisampleState = ast::vk::makeVkStruct< VkPipelineMultisampleStateCreateInfo >( 0u
				, VK_SAMPLE_COUNT_1_BIT
				, VK_FALSE
				, 0.0f
				, nullptr
				, VK_FALSE
				, VK_FALSE );
			std::vector< VkPipelineColorBlendAttachmentState > colorBlendAttachments;
			colorBlendAttachments.resize( attachmentsMap.size(), VkPipelineColorBlendAttachmentState{} );
			auto colorBlendState = ast::vk::makeVkStruct< VkPipelineColorBlendStateCreateInfo >( 0u
				, VK_FALSE
				, VK_LOGIC_OP_COPY
				, uint32_t( colorBlendAttachments.size() )
				, colorBlendAttachments.data() );
			colorBlendState.blendConstants[0] = {};
			colorBlendState.blendConstants[1] = {};
			colorBlendState.blendConstants[2] = {};
			colorBlendState.blendConstants[3] = {};
			auto tessellationState = ast::vk::makeVkStruct< VkPipelineTessellationStateCreateInfo >( 0u
				, program.getTessellationControlPoints() );
			auto createInfos = ast::vk::makeVkStruct< VkGraphicsPipelineCreateInfo >( 0u
				, uint32_t( vkShaderStages.size() )
				, vkShaderStages.data()
				, &vertexInputState
				, &inputAssemblyState
				, hasTessellation ? &tessellationState : nullptr
				, &viewportState
				, &rasterizationState
				, &multisampleState
				, nullptr //depthStencilState
				, &colorBlendState
				, nullptr //dynamicState
				, pipelineLayout
				, renderPass
				, 0u
				, nullptr
				, 0 );
			VkPipeline pipeline{ nullptr };

			if ( !wrapCall( errors
				, testCounts
				, infoIndex
				, [&]()
				{
					return ast::vk::checkError( builder.createGraphicsPipeline( createInfos, &pipeline ) );
				} ) )
			{
				if ( pipeline )
				{
					vkDestroyPipeline( builder.getDevice()
						, pipeline
						, builder.getAllocator() );
				}

				if ( errors.find( "failed to compile internal representation" ) == std::string::npos )
				{
					failure( "VkPipeline creation" );
				}

				pipeline = nullptr;
			}

			return pipeline;
		}
	}

	ast::vk::BuilderContext createBuilderContext( sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
		ast::vk::BuilderContext result
		{
			retrieveInfo( testCounts, infoIndex )->device,
			nullptr,
			nullptr,
			vkCreateGraphicsPipelines,
			vkCreateComputePipelines,
			vkCreateShaderModule,
			vkCreatePipelineLayout,
			vkCreateDescriptorSetLayout,
		};
		return result;
	}

	bool validateProgram( ast::vk::ProgramPipeline const & program
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
		if ( program.getStageCount() == 0u )
		{
			failure( "No shader stage" );
			return false;
		}

		auto context = createBuilderContext( testCounts, infoIndex );
		ast::vk::PipelineBuilder builder{ context, program };
		ast::vk::VkShaderModuleArray modules;
		checkNoThrow( modules = builder.createShaderModules() )

		if ( modules.empty() )
		{
			failure( "No shader module" );
			return false;
		}

		bool result = false;
		ast::vk::VkDescriptorSetLayoutArray descriptorLayouts;
		checkNoThrow( descriptorLayouts = builder.createDescriptorSetLayouts() )
		VkPipelineLayout pipelineLayout{};
		checkNoThrow( pipelineLayout = builder.createPipelineLayout( descriptorLayouts ) )

		if ( !pipelineLayout )
		{
			failure( "VkPipelineLayout creation" );
		}
		else
		{
			ast::vk::PipelineShaderStageArray shaderStages;
			checkNoThrow( shaderStages = builder.createShaderStages( modules, {} ) )

			if ( shaderStages.size() == 1u )
			{
				if ( program.getStageFlags() != ast::vk::makeFlag( ast::ShaderStage::eCompute ) )
				{
					failure( "Not enough shader stages" );
				}
				else
				{
					if ( VkPipeline pipeline = createComputePipeline( builder
						, shaderStages.front()
						, pipelineLayout
						, errors
						, testCounts
						, infoIndex ) )
					{
						result = true;
						vkDestroyPipeline( context.device, pipeline, context.allocator );
					}
				}
			}
			else
			{
				// Render pass and subpass
				if ( VkRenderPass renderPass = createRenderPass( program
					, context
					, errors
					, testCounts
					, infoIndex ) )
				{
					if ( VkPipeline pipeline = createGraphicsPipeline( program
						, builder
						, shaderStages
						, pipelineLayout
						, renderPass
						, errors
						, testCounts
						, infoIndex ) )
					{
						result = true;
						vkDestroyPipeline( context.device, pipeline, context.allocator );
					}

					vkDestroyRenderPass( context.device, renderPass, context.allocator );
				}
			}

			vkDestroyPipelineLayout( context.device, pipelineLayout, context.allocator );
		}

		for ( auto layout : descriptorLayouts )
		{
			vkDestroyDescriptorSetLayout( context.device, layout, context.allocator );
		}

		for ( auto shaderModule : modules )
		{
			vkDestroyShaderModule( context.device, shaderModule, context.allocator );
		}

		return result;
	}

#endif

#else

	namespace sdw_test
	{
		static std::vector< std::pair< uint32_t, uint32_t > > const & getShaderModels()
		{
			static std::vector< std::pair< uint32_t, uint32_t > > shaderModels = []()
			{
				static const std::vector< uint32_t > spvVersions{ spv1_0, spv1_1, spv1_2, spv1_3, spv1_4, spv1_5, spv1_6 };
				static const std::vector< uint32_t > vkVersions{ vk1_0, vk1_1, vk1_2, vk1_3 };

				uint32_t maxApiVersion{ vk1_3 };
				std::vector< std::pair< uint32_t, uint32_t > > result;

				for ( auto vkV : vkVersions )
				{
					if ( vkV <= maxApiVersion )
					{
						auto maxSpvVersion = getMaxSpvVersion( vkV );

						for ( auto it = spvVersions.begin(); it != spvVersions.end(); ++it )
						{
							if ( *it <= maxSpvVersion )
							{
								result.emplace_back( vkV, *it );
							}
						}
					}
				}

				return result;
			}();
			return shaderModels;
		}
	}

	bool retrieveIsSpirVInitialised( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}

	uint32_t retrieveVulkanVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
#if SDW_Test_Coverage
		return sdw_test::getShaderModels().back().first;
#else
		return sdw_test::getShaderModels()[infoIndex].first;
#endif
	}

	uint32_t retrieveSPIRVVersion( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
#if SDW_Test_Coverage
		return sdw_test::getShaderModels().back().second;
#else
		return sdw_test::getShaderModels()[infoIndex].second;
#endif
	}

	uint32_t retrieveSpirVInfosSize( sdw_test::TestCounts const & testCounts )
	{
#if SDW_Test_Coverage
		return 1u;
#else
		return uint32_t( sdw_test::getShaderModels().size() );
#endif
	}

	uint32_t getSpirVTargetEnv( sdw_test::TestCounts const & testCounts
		, uint32_t infoIndex )
	{
#if SDW_Test_HasSpirVTools
		auto spvVersion = retrieveSPIRVVersion( testCounts, infoIndex );

		switch ( spvVersion )
		{
		case sdw_test::spv1_0:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_0;
		case sdw_test::spv1_1:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_1;
		case sdw_test::spv1_2:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_2;
		case sdw_test::spv1_3:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_3;
		case sdw_test::spv1_4:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_4;
		case sdw_test::spv1_5:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_5;
		case sdw_test::spv1_6:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_6;
		default:
			return spv_target_env::SPV_ENV_UNIVERSAL_1_6;
		}
#else
		return 0u;
#endif
	}

	bool createSPIRVContext( sdw_test::TestCounts & testCounts )
	{
		return true;
	}

	void destroySPIRVContext( sdw_test::TestCounts & testCounts )
	{
	}

	bool compileSpirV( ast::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
		return true;
	}

#if SDW_HasVulkanLayer
	bool validateProgram( ast::vk::ProgramPipeline const & program
		, std::string & errors
		, sdw_test::TestCounts & testCounts
		, uint32_t infoIndex )
	{
	}
#endif

#endif
}
