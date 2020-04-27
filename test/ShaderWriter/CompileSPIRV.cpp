#include "CompileSPIRV.hpp"

#include <ShaderAST/Shader.hpp>

#if SDW_Test_HasVulkan

#include "vulkan/vulkan.h"

#include <VulkanLayer/PipelineBuilder.hpp>
#include <VulkanLayer/ProgramPipeline.hpp>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>

namespace test
{
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

		class StringDelimitedByPipes : public std::string
		{
		};

		std::istream & operator>>( std::istream & is, StringDelimitedByPipes & output )
		{
			std::getline( is, output, '|' );
			return is;
		}

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
				assert( false && "Unsupported VkFormat for a vertex attribute." );
				return 4u;
			}
		}

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
			message << "[" << pLayerPrefix << "]" << std::endl;
			message << "  Code " << msgCode << ":" << std::endl;
			std::istringstream iss( pMsg );
			std::vector< std::string > results
			{
				std::istream_iterator< StringDelimitedByPipes >( iss ),
				std::istream_iterator< StringDelimitedByPipes >()
			};

			for ( auto & line : results )
			{
				message << "    " << line << std::endl;
			}

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
					++gpuIndex;

					if ( properties.apiVersion >= info.apiVersion )
					{
						break;
					}
				}

				--gpuIndex;
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
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.pCode = spirv.data();
		createInfo.codeSize = uint32_t( spirv.size() * sizeof( uint32_t ) );
		VkShaderModule module;
		bool result = false;

		try
		{
			result = vkCreateShaderModule( info.device, &createInfo, nullptr, &module ) == VK_SUCCESS;

			if ( result && module != VK_NULL_HANDLE )
			{
				vkDestroyShaderModule( info.device, module, nullptr );
			}
		}
		catch ( ... )
		{
			result = false;
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

	bool compileSpirV( ast::Shader const & shader
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

		if ( info.errors.size() == 1u )
		{
			auto it = info.errors.front().find( testCounts.expectedError );

			if ( it == std::string::npos )
			{
				errors += info.errors.front() + "\n";
				std::stringstream stream;
				stream << "SPIR-V size: " << spirv.size() << "\n"
					<< "SPIR-V:\n"
					<< spirv << std::endl;
				errors += stream.str();
			}
		}
		else
		{
			for ( auto & error : info.errors )
			{
				errors += error + "\n";
			}
		}

		return result;
	}

	ast::vk::BuilderContext createBuilderContext( sdw_test::TestCounts & testCounts )
	{
		ast::vk::BuilderContext result
		{
			testCounts.spirv->info.device,
			VK_NULL_HANDLE,
			nullptr,
			vkCreateGraphicsPipelines,
			vkCreateComputePipelines,
			vkCreateShaderModule,
			vkCreatePipelineLayout,
			vkCreateDescriptorSetLayout,
		};
		return result;
	}

	VkRenderPass createRenderPass( ast::vk::ProgramPipeline program
		, ast::vk::BuilderContext const & context
		, sdw_test::TestCounts & testCounts )
	{
		auto attachmentsMap = program.getAttachmentDescriptions();
		std::vector< VkAttachmentDescription > attachments;
		std::vector< VkAttachmentReference > references;

		for ( auto & attachmentIt : attachmentsMap )
		{
			attachments.push_back( attachmentIt.second );
			auto & attachment = attachments.back();
			attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
			attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
			attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
			attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
			attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
			attachment.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
			references.push_back( VkAttachmentReference
				{
					uint32_t( attachments.size() - 1u ),
					VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
				} );
		}

		std::vector< VkSubpassDescription > subpasses;
		subpasses.push_back( VkSubpassDescription
			{
				0u,
				VK_PIPELINE_BIND_POINT_GRAPHICS,
				0u,
				nullptr,
				uint32_t( references.size() ),
				references.data(),
				nullptr,
				nullptr,
				0u,
				nullptr,
			} );

		std::vector< VkSubpassDependency > dependencies;
		dependencies.push_back( VkSubpassDependency
			{
				VK_SUBPASS_EXTERNAL,
				0u,
				VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
				VK_ACCESS_HOST_READ_BIT,
				VK_ACCESS_HOST_READ_BIT,
				VK_DEPENDENCY_BY_REGION_BIT,
			} );
		dependencies.push_back( VkSubpassDependency
			{
				0u,
				VK_SUBPASS_EXTERNAL,
				VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
				VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
				VK_ACCESS_HOST_READ_BIT,
				VK_ACCESS_HOST_READ_BIT,
				VK_DEPENDENCY_BY_REGION_BIT,
			} );

		VkRenderPassCreateInfo renderPassCreate
		{
			VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
			nullptr,
			0u,
			uint32_t( attachments.size() ),
			attachments.data(),
			uint32_t( subpasses.size() ),
			subpasses.data(),
			uint32_t( dependencies.size() ),
			dependencies.data(),
		};
		VkRenderPass renderPass{ VK_NULL_HANDLE };

		if ( !ast::vk::checkError( vkCreateRenderPass( context.device
			, &renderPassCreate
			, context.allocator
			, &renderPass ) ) )
		{
			failure( "VkRenderPass creation." );
			renderPass = VK_NULL_HANDLE;
		}

		return renderPass;
	}

	VkPipeline createComputePipeline( ast::vk::ProgramPipeline program
		, ast::vk::PipelineBuilder const & builder
		, ast::vk::PipelineShaderStageCreateInfo const & shaderStage
		, VkPipelineLayout pipelineLayout
		, sdw_test::TestCounts & testCounts )
	{
		VkComputePipelineCreateInfo createInfos
		{
			VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,
			nullptr,
			0u,
			shaderStage.data,
			pipelineLayout,
			VK_NULL_HANDLE,
			0u,
		};
		VkPipeline pipeline{ VK_NULL_HANDLE };

		if ( !ast::vk::checkError( builder.createComputePipeline( createInfos
			, &pipeline ) ) )
		{
			failure( "Pipeline creation." );
			pipeline = VK_NULL_HANDLE;
		}

		return pipeline;
	}

	VkPipeline createGraphicsPipeline( ast::vk::ProgramPipeline program
		, ast::vk::PipelineBuilder const & builder
		, ast::vk::PipelineShaderStageArray const & shaderStages
		, VkPipelineLayout pipelineLayout
		, VkRenderPass renderPass
		, sdw_test::TestCounts & testCounts )
	{
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

		VkVertexInputBindingDescription binding
		{
			0u,
			size,
			VK_VERTEX_INPUT_RATE_VERTEX,
		};
		VkPipelineVertexInputStateCreateInfo vertexInputState
		{
			VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
			nullptr,
			0u,
			size ? 1u : 0u,
			size ? &binding : nullptr,
			size ? uint32_t( vertexAttributes.size() ) : 0u,
			size ? vertexAttributes.data() : nullptr,
		};

		// Pipeline input assembly state
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyState
		{
			VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
			VK_FALSE,
		};

		// Pipeline viewport state.
		VkViewport viewport{ 0.0f, 0.0f, 800.0f, 600.0f, 0.0f, 1.0f };
		VkRect2D scissor{ { 0, 0 }, { 800u, 600u } };
		VkPipelineViewportStateCreateInfo viewportState
		{
			VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
			nullptr,
			0u,
			1u,
			&viewport,
			1u,
			&scissor,
		};

		// Pipeline rasterization state.
		VkPipelineRasterizationStateCreateInfo rasterizationState
		{
			VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_FALSE,
			VK_FALSE,
			VK_POLYGON_MODE_FILL,
			VK_CULL_MODE_NONE,
			VK_FRONT_FACE_COUNTER_CLOCKWISE,
			VK_FALSE,
			0.0f,
			0.0f,
			0.0f,
			1.0f,
		};

		// Pipeline multisample state.
		VkPipelineMultisampleStateCreateInfo multisampleState
		{
			VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_SAMPLE_COUNT_1_BIT,
			VK_FALSE,
			0.0f,
			nullptr,
			VK_FALSE,
			VK_FALSE,
		};

		// Pipeline color blend state
		std::vector< VkPipelineColorBlendAttachmentState > colorBlendAttachments;
		colorBlendAttachments.resize( attachmentsMap.size(), VkPipelineColorBlendAttachmentState{} );
		VkPipelineColorBlendStateCreateInfo colorBlendState
		{
			VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
			nullptr,
			0u,
			VK_FALSE,
			VK_LOGIC_OP_COPY,
			uint32_t( colorBlendAttachments.size() ),
			colorBlendAttachments.data(),
		};

		// Pipeline
		VkGraphicsPipelineCreateInfo createInfos
		{
			VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
			nullptr,
			0u,
			uint32_t( vkShaderStages.size() ),
			vkShaderStages.data(),
			&vertexInputState,
			&inputAssemblyState,
			nullptr, //tessellationState,
			&viewportState,
			&rasterizationState,
			&multisampleState,
			nullptr, //depthStencilState,
			&colorBlendState,
			nullptr, //dynamicState,
			pipelineLayout,
			renderPass,
			0u,
			VK_NULL_HANDLE,
			0u,
		};
		VkPipeline pipeline{ VK_NULL_HANDLE };

		if ( !ast::vk::checkError( builder.createGraphicsPipeline( createInfos
			, &pipeline ) ) )
		{
			failure( "VkPipeline creation." );
			pipeline = VK_NULL_HANDLE;
		}

		return pipeline;
	}

	bool validateProgram( ast::vk::ProgramPipeline const & program
		, sdw_test::TestCounts & testCounts )
	{
		if ( program.getStageCount() == 0u )
		{
			failure( "No shader stage" );
			return false;
		}

		auto context = createBuilderContext( testCounts );
		ast::vk::PipelineBuilder builder{ context, program };
		ast::vk::ShaderModuleArray modules;
		checkNoThrow( modules = builder.createShaderModules() );

		if ( modules.empty() )
		{
			failure( "No shader module" );
			return false;
		}

		bool result = false;
		ast::vk::DescriptorSetLayoutArray descriptorLayouts;
		checkNoThrow( descriptorLayouts = builder.createDescriptorSetLayouts() );
		VkPipelineLayout pipelineLayout;
		checkNoThrow( pipelineLayout = builder.createPipelineLayout( descriptorLayouts ) );

		if ( !pipelineLayout )
		{
			failure( "VkPipeline creation" );
		}
		else
		{
			ast::vk::PipelineShaderStageArray shaderStages;
			checkNoThrow( shaderStages = builder.createShaderStages( modules, {} ) );

			if ( shaderStages.size() == 1u )
			{
				if ( program.getStageFlags() != ast::vk::makeFlag( ast::ShaderStage::eCompute ) )
				{
					failure( "Not enough shader stages" );
				}
				else
				{
					if ( VkPipeline pipeline = createComputePipeline( program
						, builder
						, shaderStages.front()
						, pipelineLayout
						, testCounts ) )
					{
						result = true;
						vkDestroyPipeline( context.device, pipeline, context.allocator );
					}
				}
			}
			else
			{
				// Render pass and subpass
				if ( VkRenderPass renderPass = createRenderPass( program, context, testCounts ) )
				{
					if ( VkPipeline pipeline = createGraphicsPipeline( program
						, builder
						, shaderStages
						, pipelineLayout
						, renderPass
						, testCounts ) )
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

		for ( auto module : modules )
		{
			vkDestroyShaderModule( context.device, module, context.allocator );
		}

		return result;
	}
}

#else

namespace test
{
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
		, sdw_test::TestCounts & testCounts )
	{
		return true;
	}
}

#endif
