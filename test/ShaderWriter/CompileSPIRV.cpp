#include "CompileSPIRV.hpp"

#include "vulkan/vulkan.h"

#include <ShaderWriter/Shader.hpp>

#include <algorithm>
#include <iostream>
#include <sstream>

namespace test
{
#if defined( _WIN32 )

	template< typename FuncT >
	void getFunction( char const * const name, FuncT & function )
	{
		function = reinterpret_cast< FuncT >( wglGetProcAddress( name ) );

		if ( function == nullptr )
		{
			throw std::runtime_error{ std::string( "Couldn't load function" ) + name };
		}
	}

#elif defined( __linux__ )

	template< typename FuncT >
	void getFunction( char const * const name, FuncT & function )
	{
		function = reinterpret_cast< FuncT >( glXGetProcAddressARB( reinterpret_cast< GLubyte const * >( name ) ) );

		if ( function == nullptr )
		{
			throw std::runtime_error{ std::string( "Couldn't load function" ) + name };
		}
	}

#endif

	namespace
	{
		struct LayerProperties
		{
			VkLayerProperties properties;
			std::vector<VkExtensionProperties> instance_extensions;
			std::vector<VkExtensionProperties> device_extensions;
		};

		struct Info
		{
			std::vector< const char * > instance_layer_names;
			std::vector< const char * > instance_extension_names;
			std::vector< LayerProperties > instance_layer_properties;
			VkInstance inst;
			uint32_t apiVersion;

			std::vector< const char *> device_extension_names;
			std::vector< VkPhysicalDevice > gpus;
			VkDevice device;
			uint32_t queue_family_count;
			std::vector< VkQueueFamilyProperties > queue_props;

			PFN_vkCreateDebugReportCallbackEXT dbgCreateDebugReportCallback;
			PFN_vkDestroyDebugReportCallbackEXT dbgDestroyDebugReportCallback;
			PFN_vkDebugReportMessageEXT dbgBreakCallback;
			std::vector< VkDebugReportCallbackEXT > debug_report_callbacks;

			bool compiling{ false };
			std::vector< std::string > errors;
		};

		VkBool32 VKAPI_CALL dbgFunc( VkDebugReportFlagsEXT msgFlags
			, VkDebugReportObjectTypeEXT objType
			, uint64_t srcObject
			, size_t location
			, int32_t msgCode
			, const char *pLayerPrefix
			, const char *pMsg
			, void *pUserData )
		{
			std::ostringstream message;

			if ( msgFlags & VK_DEBUG_REPORT_ERROR_BIT_EXT )
			{
				message << "ERROR: ";
			}
			else if ( msgFlags & VK_DEBUG_REPORT_WARNING_BIT_EXT )
			{
				message << "WARNING: ";
			}
			else if ( msgFlags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT )
			{
				message << "PERFORMANCE WARNING: ";
			}
			else if ( msgFlags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT )
			{
				message << "INFO: ";
			}
			else if ( msgFlags & VK_DEBUG_REPORT_DEBUG_BIT_EXT )
			{
				message << "DEBUG: ";
			}
			message << "[" << pLayerPrefix << "] Code " << msgCode << " : " << pMsg;
			auto info = reinterpret_cast< Info * >( pUserData );

			if ( info->compiling )
			{
				info->errors.push_back( message.str() );
			}
			else
			{
				std::cout << message.str() << std::endl;
			}

		/*
		 * false indicates that layer should not bail-out of an
		 * API call that had validation failures. This may mean that the
		 * app dies inside the driver due to invalid parameter(s).
		 * That's what would happen without validation layers, so we'll
		 * keep that behavior here.
		 */
			return false;
		}

		VkResult initGlobalExtensionProperties( LayerProperties & layer_props )
		{
			VkExtensionProperties *instance_extensions;
			uint32_t instance_extension_count;
			VkResult res;
			char *layer_name = nullptr;

			layer_name = layer_props.properties.layerName;

			do
			{
				res = vkEnumerateInstanceExtensionProperties( layer_name, &instance_extension_count, nullptr );
				if ( res ) return res;

				if ( instance_extension_count == 0 )
				{
					return VK_SUCCESS;
				}

				layer_props.instance_extensions.resize( instance_extension_count );
				instance_extensions = layer_props.instance_extensions.data();
				res = vkEnumerateInstanceExtensionProperties( layer_name, &instance_extension_count, instance_extensions );
			}
			while ( res == VK_INCOMPLETE );

			return res;
		}

		VkResult initGlobalLayerProperties( Info & info )
		{
			uint32_t instance_layer_count;
			VkLayerProperties *vk_props = nullptr;
			VkResult res;
			do
			{
				res = vkEnumerateInstanceLayerProperties( &instance_layer_count, nullptr );
				if ( res ) return res;

				if ( instance_layer_count == 0 )
				{
					return VK_SUCCESS;
				}

				vk_props = ( VkLayerProperties * )realloc( vk_props, instance_layer_count * sizeof( VkLayerProperties ) );

				res = vkEnumerateInstanceLayerProperties( &instance_layer_count, vk_props );
			}
			while ( res == VK_INCOMPLETE );

			for ( uint32_t i = 0; i < instance_layer_count; i++ )
			{
				LayerProperties layer_props;
				layer_props.properties = vk_props[i];
				res = initGlobalExtensionProperties( layer_props );
				if ( res ) return res;
				info.instance_layer_properties.push_back( layer_props );
			}

			free( vk_props );

			return res;
		}
	}

	bool createInstance( Info & info )
	{
		initGlobalLayerProperties( info );
		info.instance_layer_names.push_back( "VK_LAYER_LUNARG_standard_validation" );
		info.instance_extension_names.push_back( VK_EXT_DEBUG_REPORT_EXTENSION_NAME );

		vkEnumerateInstanceVersion( &info.apiVersion );

		// initialize the VkApplicationInfo structure
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pNext = nullptr;
		appInfo.pApplicationName = "Test";
		appInfo.applicationVersion = 1;
		appInfo.pEngineName = "Test";
		appInfo.engineVersion = 1;

		if ( info.apiVersion >= VK_MAKE_VERSION( 1, 1, 0 ) )
		{
			appInfo.apiVersion = VK_MAKE_VERSION( 1, 1, 0 );
		}
		else
		{
			appInfo.apiVersion = VK_MAKE_VERSION( 1, 0, 0 );
		}

		// initialize the VkInstanceCreateInfo structure
		VkInstanceCreateInfo instInfo = {};
		instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instInfo.pNext = nullptr;
		instInfo.flags = 0;
		instInfo.pApplicationInfo = &appInfo;
		instInfo.enabledExtensionCount = uint32_t( info.instance_extension_names.size() );
		instInfo.ppEnabledExtensionNames = info.instance_extension_names.data();
		instInfo.enabledLayerCount = uint32_t( info.instance_layer_names.size() );
		instInfo.ppEnabledLayerNames = info.instance_layer_names.data();
		VkResult res;

		res = vkCreateInstance( &instInfo, nullptr, &info.inst );

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
			info.dbgCreateDebugReportCallback =
				( PFN_vkCreateDebugReportCallbackEXT )vkGetInstanceProcAddr( info.inst, "vkCreateDebugReportCallbackEXT" );
			if ( !info.dbgCreateDebugReportCallback )
			{
				std::cout << "GetInstanceProcAddr: Unable to find "
					"vkCreateDebugReportCallbackEXT function."
					<< std::endl;
				exit( 1 );
			}

			info.dbgDestroyDebugReportCallback =
				( PFN_vkDestroyDebugReportCallbackEXT )vkGetInstanceProcAddr( info.inst, "vkDestroyDebugReportCallbackEXT" );
			if ( !info.dbgDestroyDebugReportCallback )
			{
				std::cout << "GetInstanceProcAddr: Unable to find "
					"vkDestroyDebugReportCallbackEXT function."
					<< std::endl;
				exit( 1 );
			}

			VkDebugReportCallbackCreateInfoEXT create_info = {};
			create_info.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
			create_info.pNext = nullptr;
			create_info.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
			create_info.pfnCallback = dbgFunc;
			create_info.pUserData = &info;

			info.debug_report_callbacks.resize( 1u );
			res = info.dbgCreateDebugReportCallback( info.inst, &create_info, nullptr, info.debug_report_callbacks.data() );
			switch ( res )
			{
			case VK_SUCCESS:
				break;
			case VK_ERROR_OUT_OF_HOST_MEMORY:
				std::cout << "dbgCreateDebugReportCallback: out of host memory\n" << std::endl;
				exit( 1 );
				break;
			default:
				std::cout << "dbgCreateDebugReportCallback: unknown failure\n" << std::endl;
				exit( 1 );
				break;
			}
		}

		return res == VK_SUCCESS;
	}

	bool createDevice( Info & info )
	{
		uint32_t gpuCount = 1;
		auto res = vkEnumeratePhysicalDevices( info.inst, &gpuCount, nullptr );

		if ( res == VK_SUCCESS )
		{
			assert( gpuCount );
			info.gpus.resize( gpuCount );
			res = vkEnumeratePhysicalDevices( info.inst, &gpuCount, info.gpus.data() );

			if ( res == VK_SUCCESS )
			{
				assert( gpuCount >= 1 );
				uint32_t gpuIndex = 0u;

				while ( gpuIndex < gpuCount )
				{
					VkPhysicalDeviceProperties properties = {};
					vkGetPhysicalDeviceProperties( info.gpus[gpuIndex], &properties );

					if ( properties.apiVersion >= info.apiVersion )
					{
						break;
					}

					++gpuIndex;
				}

				VkDeviceQueueCreateInfo queue_info = {};

				vkGetPhysicalDeviceQueueFamilyProperties( info.gpus[gpuIndex], &info.queue_family_count, nullptr );
				assert( info.queue_family_count >= 1 );

				info.queue_props.resize( info.queue_family_count );
				vkGetPhysicalDeviceQueueFamilyProperties( info.gpus[gpuIndex], &info.queue_family_count, info.queue_props.data() );
				assert( info.queue_family_count >= 1 );

				bool found = false;
				for ( unsigned int i = 0; i < info.queue_family_count; i++ )
				{
					if ( info.queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT )
					{
						queue_info.queueFamilyIndex = i;
						found = true;
						break;
					}
				}
				assert( found );
				assert( info.queue_family_count >= 1 );

				float queue_priorities[1] = { 0.0 };
				queue_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
				queue_info.pNext = nullptr;
				queue_info.queueCount = 1;
				queue_info.pQueuePriorities = queue_priorities;

				VkDeviceCreateInfo device_info = {};
				device_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
				device_info.pNext = nullptr;
				device_info.queueCreateInfoCount = 1;
				device_info.pQueueCreateInfos = &queue_info;
				device_info.enabledExtensionCount = uint32_t( info.device_extension_names.size() );
				device_info.ppEnabledExtensionNames = info.device_extension_names.data();
				device_info.enabledLayerCount = 0;
				device_info.ppEnabledLayerNames = nullptr;
				device_info.pEnabledFeatures = nullptr;

				res = vkCreateDevice( info.gpus[gpuIndex], &device_info, nullptr, &info.device );
			}
		}

		return res == VK_SUCCESS;
	}

	bool createShaderModule( Info & info
		, std::vector< uint32_t > const & spirv )
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.pCode = spirv.data();
		createInfo.codeSize = uint32_t( spirv.size() * sizeof( uint32_t ) );
		VkShaderModule module;

		auto result = vkCreateShaderModule( info.device, &createInfo, nullptr, &module ) == VK_SUCCESS;

		if ( result && module != VK_NULL_HANDLE )
		{
			vkDestroyShaderModule( info.device, module, nullptr );
		}

		return result;
	}

	namespace sdw_test
	{
		struct SPIRVContext
		{
			SPIRVContext()
			{
				if ( !createInstance( info ) )
				{
					throw std::runtime_error{ "Can't initialise Vulkan instance" };
				}

				if ( !createDevice( info ) )
				{
					info.dbgDestroyDebugReportCallback( info.inst, *info.debug_report_callbacks.data(), nullptr );
					vkDestroyInstance( info.inst, nullptr );
					throw std::runtime_error{ "Can't initialise Vulkan device" };
				}
			}

			~SPIRVContext()
			{
				vkDestroyDevice( info.device, nullptr );
			}

			Info info{};
		};
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
			std::cout << exc.what() << std::endl;
		}

		return result;
	}

	void destroySPIRVContext( sdw_test::TestCounts & testCounts )
	{
		testCounts.spirv.reset();
	}

	bool compileSpirV( sdw::Shader const & shader
		, std::vector< uint32_t > const & spirv
		, std::string & errors
		, sdw_test::TestCounts & testCounts )
	{
		bool result{ true };
		auto & info = testCounts.spirv->info;
		info.compiling = true;
		info.errors.clear();
		errors = std::string{};
		result = createShaderModule( info, spirv );

		for ( auto & error : info.errors )
		{
			errors += error + "\n";
		}

		return result;
	}
}
