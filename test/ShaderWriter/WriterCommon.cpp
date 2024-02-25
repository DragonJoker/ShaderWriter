#include "WriterCommon.hpp"

#include "CompileGLSL.hpp"
#include "CompileHLSL.hpp"
#include "CompileSPIRV.hpp"
#include "GlslToSpv.hpp"

#if SDW_HasCompilerGlsl
#	include <CompilerGlsl/compileGlsl.hpp>
#endif
#if SDW_HasCompilerHlsl
#	include <CompilerHlsl/compileHlsl.hpp>
#endif
#if SDW_HasCompilerSpirV
#	include <CompilerSpirV/compileSpirV.hpp>
#	if SDW_Test_HasVulkan && SDW_HasVulkanLayer
#		include <VulkanLayer/PipelineBuilder.hpp>
#		include <VulkanLayer/ProgramPipeline.hpp>
#	endif
#endif

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wtype-limits"
#if SDW_Test_HasSpirVCross
#	include "spirv_cpp.hpp"
#	include "spirv_cross_util.hpp"
#	include "spirv_glsl.hpp"
#	include "spirv_hlsl.hpp"
#endif
#if SDW_Test_HasSpirVTools
#	include "spirv-tools/libspirv.hpp"
#endif
#pragma GCC diagnostic pop

#pragma warning( disable: 5262 )
#include <iomanip>

namespace test
{
	namespace
	{
#if SDW_HasCompilerGlsl

		glsl::GlslExtensionSet getExtensions( uint32_t glslVersion )
		{
			glsl::GlslExtensionSet result;

			if ( glslVersion >= glsl::v4_6 )
			{
				result.insert( glsl::EXT_shader_atomic_float );
				result.insert( glsl::EXT_ray_tracing );
				result.insert( glsl::EXT_ray_query );
				result.insert( glsl::EXT_scalar_block_layout );
			}

			if ( glslVersion >= glsl::v4_5 )
			{
				result.insert( glsl::ARB_shader_ballot );
				result.insert( glsl::ARB_shader_viewport_layer_array );
				result.insert( glsl::NV_stereo_view_rendering );
				result.insert( glsl::NVX_multiview_per_view_attributes );
				result.insert( glsl::EXT_nonuniform_qualifier );
				result.insert( glsl::NV_mesh_shader );
				result.insert( glsl::EXT_mesh_shader );
				result.insert( glsl::EXT_buffer_reference2 );
			}

			if ( glslVersion >= glsl::v4_3 )
			{
				result.insert( glsl::NV_viewport_array2 );
				result.insert( glsl::NV_shader_atomic_fp16_vector );
			}

			if ( glslVersion >= glsl::v4_2 )
			{
				result.insert( glsl::ARB_compute_shader );
				result.insert( glsl::ARB_explicit_uniform_location );
				result.insert( glsl::ARB_shading_language_420pack );
				result.insert( glsl::NV_shader_atomic_float );
			}

			if ( glslVersion >= glsl::v4_1 )
			{
				result.insert( glsl::ARB_shading_language_packing );
			}

			if ( glslVersion >= glsl::v4_0 )
			{
				result.insert( glsl::ARB_separate_shader_objects );
				result.insert( glsl::ARB_texture_cube_map_array );
				result.insert( glsl::ARB_texture_gather );
				result.insert( glsl::ARB_gpu_shader_int64 );
			}

			if ( glslVersion >= glsl::v3_3 )
			{
				result.insert( glsl::ARB_shader_stencil_export );
				result.insert( glsl::KHR_vulkan_glsl );
				result.insert( glsl::EXT_multiview );
				result.insert( glsl::ARB_explicit_attrib_location );
				result.insert( glsl::ARB_shader_image_load_store );
				result.insert( glsl::EXT_gpu_shader4 );
				result.insert( glsl::ARB_gpu_shader5 );
				result.insert( glsl::EXT_gpu_shader4_1 );
				result.insert( glsl::ARB_texture_query_lod );
				result.insert( glsl::ARB_texture_query_levels );
				result.insert( glsl::ARB_shader_draw_parameters );
				result.insert( glsl::ARB_fragment_layer_viewport );
				result.insert( glsl::ARB_tessellation_shader );
				result.insert( glsl::EXT_texture_shadow_lod );
			}

			if ( glslVersion >= glsl::v1_5 )
			{
				result.insert( glsl::NV_gpu_shader5 );
			}

			if ( glslVersion >= glsl::v1_4 )
			{
				result.insert( glsl::EXT_shader_explicit_arithmetic_types_int8 );
				result.insert( glsl::EXT_shader_explicit_arithmetic_types_int16 );
				result.insert( glsl::EXT_shader_explicit_arithmetic_types_int64 );
				result.insert( glsl::EXT_demote_to_helper_invocation );
			}

			return result;
		}

		glsl::GlslConfig getGlslConfig( uint32_t glslVersion )
		{
			glsl::GlslConfig const result
			{
				ast::ShaderStage::eCompute, // shaderStage;
				glslVersion, // shaderLanguageVersion;
				getExtensions( glslVersion ), // availableExtensions;
				( glslVersion >= glsl::v4_6 ), // vulkanGlsl;
				false, // flipVertY;
				false, // fixupClipDepth;
				true, // hasStd430Layout;
				true, // hasShaderStorageBuffers;
				true, // hasDescriptorSets;
				true, // hasBaseInstance;
			};
			return result;
		}

#endif

#if SDW_Test_HasSpirVCross
		spv::ExecutionModel getExecutionModel( ast::ShaderStage stage )
		{
			spv::ExecutionModel result{};

			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				result = spv::ExecutionModelVertex;
				break;
			case ast::ShaderStage::eGeometry:
				result = spv::ExecutionModelGeometry;
				break;
			case ast::ShaderStage::eTessellationControl:
				result = spv::ExecutionModelTessellationControl;
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				result = spv::ExecutionModelTessellationEvaluation;
				break;
			case ast::ShaderStage::eFragment:
				result = spv::ExecutionModelFragment;
				break;
			case ast::ShaderStage::eTaskNV:
				result = spv::ExecutionModelTaskNV;
				break;
			case ast::ShaderStage::eTask:
#if SPV_VERSION >= 0x10600
				result = spv::ExecutionModelTaskEXT;
#else
				result = spv::ExecutionModelTaskNV;
#endif
				break;
			case ast::ShaderStage::eMeshNV:
				result = spv::ExecutionModelMax;
				break;
			case ast::ShaderStage::eMesh:
#if SPV_VERSION >= 0x10600
				result = spv::ExecutionModelMeshEXT;
#else
				result = spv::ExecutionModelMax;
#endif
				break;
			case ast::ShaderStage::eCompute:
				result = spv::ExecutionModelGLCompute;
				break;
			case ast::ShaderStage::eRayAnyHit:
				result = spv::ExecutionModelAnyHitKHR;
				break;
			case ast::ShaderStage::eCallable:
				result = spv::ExecutionModelCallableKHR;
				break;
			case ast::ShaderStage::eRayClosestHit:
				result = spv::ExecutionModelClosestHitKHR;
				break;
			case ast::ShaderStage::eRayGeneration:
				result = spv::ExecutionModelRayGenerationKHR;
				break;
			case ast::ShaderStage::eRayIntersection:
				result = spv::ExecutionModelIntersectionKHR;
				break;
			case ast::ShaderStage::eRayMiss:
				result = spv::ExecutionModelMissKHR;
				break;
			default:
				AST_Failure( "Unsupported shader stage flag" );
				result = spv::ExecutionModelMax;
				break;
			}

			return result;
		}

		spv::ExecutionModel doSetEntryPoint( ast::ShaderStage stage
			, spirv_cross::CompilerGLSL & compiler )
		{
			auto model = getExecutionModel( stage );
			std::string entryPoint;

			for ( auto & e : compiler.get_entry_points_and_stages() )
			{
				if ( entryPoint.empty() && e.execution_model == model )
				{
					entryPoint = e.name;
				}
			}

			if ( !entryPoint.empty() )
			{
				compiler.set_entry_point( entryPoint, model );
			}

			return model;
		}

		void doSetupOptions( ast::ShaderStage stage
			, bool vulkanSemantics
			, spirv_cross::CompilerGLSL & compiler )
		{
			auto options = compiler.get_common_options();
			options.separate_shader_objects = true;
			options.vulkan_semantics = vulkanSemantics || isRayTraceStage( stage );
			compiler.set_common_options( options );
		}

		void doSetupHlslOptions( spirv_cross::CompilerHLSL & compiler )
		{
			auto options = compiler.get_hlsl_options();
			options.shader_model = 60;
			compiler.set_hlsl_options( options );
		}

		std::string compileSpirV( std::string_view language
			, spirv_cross::Compiler & compiler
			, test::TestCounts & testCounts )
		{
			std::string result;
			try
			{
				compiler.build_combined_image_samplers();
				result = compiler.compile();
			}
			catch ( spirv_cross::CompilerError & exc )
			{
				testCounts << "SPIRV-Cross(" << language << "), shader compilation failed: " << exc.what() << endl;
				throw;
			}
			catch ( std::exception & exc )
			{
				testCounts << "SPIRV-Cross(" << language << "), shader compilation failed: " << exc.what() << endl;
				throw;
			}
			catch ( ... )
			{
				testCounts << "SPIRV-Cross(" << language << "), shader compilation failed: Unknown error" << endl;
				throw;
			}

			return result;
		}

		std::string validateSpirVToGlsl( std::vector< uint32_t > const & spirv
			, ast::ShaderStage stage
			, test::TestCounts & testCounts
			, bool vulkanSemantics )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerGLSL >( spirv );
			std::string result;

			if ( doSetEntryPoint( stage, *compiler ) != spv::ExecutionModelMax )
			{
				doSetupOptions( stage, vulkanSemantics, *compiler );
				result = compileSpirV( "GLSL", *compiler, testCounts );
			}

			return result;
		}

		std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
			, ast::ShaderStage stage
			, test::TestCounts & testCounts )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerHLSL >( spirv );
			std::string result;

			if ( doSetEntryPoint( stage, *compiler ) != spv::ExecutionModelMax )
			{
				doSetupHlslOptions( *compiler );
				doSetupOptions( stage, false, *compiler );
				result = compileSpirV( "HLSL", *compiler, testCounts );
			}

			return result;
		}
#endif

#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
		std::ostream & operator<<( std::ostream & stream, VkSpecializationMapEntry const & rhs )
		{
			stream << rhs.constantID << ", " << rhs.offset << ", " << rhs.size;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, ast::vk::PipelineShaderStageCreateInfo const & rhs )
		{
			stream << rhs->flags << ", " << rhs->stage << ", " << rhs->module << ", " << rhs->pName;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkWriteDescriptorSet const & rhs )
		{
			stream << rhs.dstSet << ", " << rhs.dstBinding << ", " << rhs.dstArrayElement << ", " << rhs.descriptorType;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkDescriptorImageInfo const & rhs )
		{
			stream << rhs.sampler << ", " << rhs.imageView << ", " << rhs.imageLayout;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkDescriptorBufferInfo const & rhs )
		{
			stream << rhs.buffer << ", " << rhs.offset << ", " << rhs.range;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkSpecializationInfo const & rhs )
		{
			stream << rhs.dataSize;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkVertexInputAttributeDescription const & rhs )
		{
			stream << rhs.location << ", " << rhs.binding << ", " << rhs.format << ", " << rhs.offset;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkAttachmentDescription const & rhs )
		{
			stream << rhs.flags << ", " << rhs.format << ", " << rhs.samples << ", " << rhs.loadOp << ", " << rhs.storeOp << ", " << rhs.stencilLoadOp << ", " << rhs.stencilStoreOp << ", " << rhs.initialLayout << ", " << rhs.finalLayout;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkShaderModuleCreateInfo const & rhs )
		{
			stream << rhs.flags << ", " << rhs.codeSize;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkDescriptorSetLayoutBinding const & rhs )
		{
			stream << rhs.binding << ", " << rhs.descriptorType << ", " << rhs.stageFlags << ", " << rhs.pImmutableSamplers;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkDescriptorSetLayoutCreateInfo const & rhs )
		{
			stream << rhs.flags;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkDescriptorPoolSize const & rhs )
		{
			stream << rhs.type << ", " << rhs.descriptorCount;

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, VkPushConstantRange const & rhs )
		{
			stream << rhs.stageFlags << ", " << rhs.offset << ", " << rhs.size;

			return stream;
		}

		template< typename DataT, typename ValueT, typename CountT, size_t DataOffsetT, size_t CountOffsetT, size_t DivisorT >
		std::ostream & operator<<( std::ostream & stream, ast::vk::ArrayHolder< DataT, ValueT, CountT, DataOffsetT, CountOffsetT, DivisorT > const & rhs )
		{
			stream << "  Base Values: " << rhs.data;

			if ( !rhs.values.empty() )
			{
				stream << std::endl << "  Entries:" << std::endl;

				for ( auto const & value : rhs.values )
				{
					stream << value << std::endl;
				}
			}

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, ast::vk::WriteDescriptorSet const & rhs )
		{
			std::visit( [&stream]( auto && arg )
			{
				stream << arg << std::endl;
			}, rhs );

			return stream;
		}

		template< typename DataT >
		std::ostream & operator<<( std::ostream & stream, std::optional< DataT > const & rhs )
		{
			if ( rhs )
			{
				stream << *rhs << std::endl;
			}

			return stream;
		}

		template< typename DataT >
		std::ostream & operator<<( std::ostream & stream, std::vector< DataT > const & rhs )
		{
			if ( !rhs.empty() )
			{
				stream << "  Entries:" << std::endl;

				for ( auto const & data : rhs )
				{
					stream << "    " << data << std::endl;
				}
			}

			return stream;
		}

		template< typename KeyT, typename DataT >
		std::ostream & operator<<( std::ostream & stream, std::map< KeyT, DataT > const & rhs )
		{
			if ( !rhs.empty() )
			{
				stream << "  Entries:" << std::endl;

				for ( auto const & [key, data] : rhs )
				{
					stream << "    " << key << ": " << data << std::endl;
				}
			}

			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, ast::vk::ProgramPipeline const & rhs )
		{
			stream << "Shader Stages: " << std::endl;
			stream << rhs.getShaderStages() << std::endl;
			stream << "Specialization Infos: " << std::endl;
			stream << rhs.getSpecializationInfos() << std::endl;
			stream << "DescriptorSet Writes: " << std::endl;
			stream << rhs.getDescriptorSetWrites() << std::endl;
			stream << "Vertex Attributes: " << std::endl;
			stream << rhs.getVertexAttributes() << std::endl;
			stream << "AttachmentDescriptions: " << std::endl;
			stream << rhs.getAttachmentDescriptions() << std::endl;
			stream << "ShaderModules: " << std::endl;
			stream << rhs.getShaderModules() << std::endl;
			stream << "DescriptorLayouts: " << std::endl;
			stream << rhs.getDescriptorLayouts() << std::endl;
			stream << "DescriptorPoolSizes: " << std::endl;
			stream << rhs.getDescriptorPoolSizes( 1u ) << std::endl;
			stream << "PushConstantRanges: " << std::endl;
			stream << rhs.getPushConstantRanges() << std::endl;
			return stream;
		}

		TestCounts & operator<<( TestCounts & counts, ast::vk::ProgramPipeline const & rhs )
		{
			std::stringstream stream;
			stream.imbue( std::locale{ "C" } );
			stream << rhs;
			counts << stream.str();
			return counts;
		}
#endif

		std::string printNumber( uint32_t index )
		{
			std::stringstream stream;
			stream << std::setw( 6 ) << std::left << index;
			return stream.str();
		}

		void displayShader( std::string_view name
			, std::string const & shader
			, test::TestCounts & testCounts
			, bool force
			, bool lines )
		{
			if ( force )
			{
				if ( !name.empty() )
				{
					testCounts << "////////////////////////////////////////////////////////////" << endl;
					testCounts << "// " << name << endl;
					testCounts << "////////////////////////////////////////////////////////////" << endl;
				}

				if ( lines )
				{
					std::stringstream stream{ shader };
					std::stringstream out;
					std::string line;
					uint32_t index = 1u;

					while ( std::getline( stream, line, '\n' ) )
					{
						out << printNumber( index++ ) << line << std::endl;
					}

					testCounts << endl << out.str() << endl;
				}
				else
				{
					testCounts << endl << shader;
				}

				testCounts << endl;
			}
		}

		bool validateSpirV( ::ast::Shader const & shader
			, ::ast::stmt::Container * statements
			, ::ast::ShaderStage stage
			, std::vector< uint32_t > spirv
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, bool checkRef )
		{
			//auto parsedShader = spirv::parseSpirv( stage, spirv );
			std::string errors;
			auto result = test::compileSpirV( shader, spirv, errors, testCounts, infoIndex );
			check( errors.empty() || !checkRef )

			if ( !errors.empty() )
			{
				testCounts << "VkShaderModule creation raised messages, for CompilerSpv output:" << endl;
				testCounts << errors << endl;
				result = false;

				if ( checkRef )
				{
					auto fileName = getExecutableDirectory() + testCounts.testName + std::to_string( testCounts.getTotalCount() ) + ".spv";

					if ( FILE * fileOut = fopen( fileName.c_str(), "wb" ) )
					{
						fwrite( spirv.data()
							, sizeof( uint32_t )
							, spirv.size()
							, fileOut );
						fclose( fileOut );
					}

					fileName = getExecutableDirectory() + testCounts.testName + std::to_string( testCounts.getTotalCount() ) + ".ref.spv";

					if ( FILE * fileIn = fopen( fileName.c_str(), "rb" ) )
					{
						fseek( fileIn, 0, SEEK_END );
						auto size = ftell( fileIn );
						fseek( fileIn, 0, SEEK_SET );

						if ( size > 0 && ( size % sizeof( uint32_t ) ) == 0 )
						{
							spirv.resize( size / sizeof( uint32_t ) );
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
							(void)fread( spirv.data()
								, sizeof( uint32_t )
								, spirv.size()
								, fileIn );
#pragma GCC diagnostic pop
						}

						fclose( fileIn );
						validateSpirV( shader, statements, stage, spirv, testCounts, infoIndex, false );
					}
				}
			}

			return result;
		}

		void validateSpirV( ::ast::Shader const & shader
			, ::ast::stmt::Container * statements
			, ::ast::ShaderStage stage
			, std::vector< uint32_t > const & spirv
			, std::string const & text
			, ::sdw::SpecialisationInfo const & specialisation
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, Compilers const & compilers
			, spirv::SpirVExtensionSet const &requiredExtensions )
		{
			auto isValidated = validateSpirV( shader, statements, stage, spirv, testCounts, infoIndex, true );
			check( isValidated )

#if SDW_HasCompilerGlsl

			if ( !isValidated
				&& !isRayTraceStage( stage ) )
			{
				try
				{
					auto cfg = getGlslConfig( glsl::v4_6 );
					cfg.allocator = &testCounts.allocator;
					auto glslangSpirv = compileGlslToSpv( stage
						, glsl::compileGlsl( shader
							, statements
							, stage
							, specialisation
							, cfg ) );
					std::string errors;
					test::compileSpirV( shader, glslangSpirv, errors, testCounts, infoIndex );

					if ( !errors.empty() )
					{
						testCounts << "VkShaderModule creation raised messages, for glslang output:" << endl;
						testCounts << errors << endl;
					}
				}
				catch ( std::exception & exc )
				{
					testCounts << exc.what() << endl;
					throw;
				}
			}

#endif

#if SDW_Test_HasSpirVTools
			std::string errors;
			auto consumer = [&errors]( [[maybe_unused]] spv_message_level_t level
				, [[maybe_unused]] char const * source
				, spv_position_t position
				, char const * message )
			{
				errors += "Index " + std::to_string( position.index ) + ": " + message + std::string{ "\n" };
			};

			spvtools::SpirvTools tools{ spv_target_env( getSpirVTargetEnv( testCounts, infoIndex ) ) };
			tools.SetMessageConsumer( consumer );
			spvtools::ValidatorOptions valOptions;
			valOptions.SetScalarBlockLayout( true );
			isValidated = tools.Validate( spirv.data(), spirv.size(), valOptions ) && isValidated;
			check( isValidated )

			if ( !errors.empty() )
			{
				testCounts << "SpirV validation raised messages:" << endl;
				testCounts << errors << endl;
			}
#endif

			if ( !isValidated )
			{
				displayShader( "SPIR-V", text, testCounts, true, false );
			}

#if SDW_Test_HasSpirVCross

			if ( compilers.glsl
				&& requiredExtensions.contains( spirv::KHR_terminate_invocation ) )
			{
				if ( auto crossGlsl = test::validateSpirVToGlsl( spirv, stage, testCounts
						, ( requiredExtensions.contains( spirv::KHR_terminate_invocation )
							|| requiredExtensions.contains( spirv::EXT_demote_to_helper_invocation )
							|| requiredExtensions.contains( spirv::KHR_shader_subgroup )
							|| requiredExtensions.contains( spirv::EXT_shader_atomic_float_add )
							|| requiredExtensions.contains( spirv::EXT_mesh_shader ) ) );
						!crossGlsl.empty() )
				{
					displayShader( "SPIRV-Cross GLSL", crossGlsl, testCounts, compilers.forceDisplay, true );
				}
			}

			if ( compilers.hlsl
				&& !isRayTraceStage( stage )
				&& !isMeshStage( stage )
				&& requiredExtensions.contains( spirv::KHR_terminate_invocation )
				&& requiredExtensions.contains( spirv::EXT_demote_to_helper_invocation ) )
			{
				if ( auto crossHlsl = test::validateSpirVToHlsl( spirv, stage, testCounts );
					!crossHlsl.empty() )
				{
					displayShader( "SPIRV-Cross HLSL", crossHlsl, testCounts, compilers.forceDisplay, true );
				}
			}

#endif
		}

		std::string printStage( ast::ShaderStage stage )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				return "Vertex";
			case ast::ShaderStage::eTessellationControl:
				return "Tessellation Control";
			case ast::ShaderStage::eTessellationEvaluation:
				return "Tessellation Evaluation";
			case ast::ShaderStage::eGeometry:
				return "Geometry";
			case ast::ShaderStage::eFragment:
				return "Fragment";
			case ast::ShaderStage::eTaskNV:
				return "TaskNV";
			case ast::ShaderStage::eMeshNV:
				return "MeshNV";
			case ast::ShaderStage::eTask:
				return "Task";
			case ast::ShaderStage::eMesh:
				return "Mesh";
			case ast::ShaderStage::eCompute:
				return "Compute";
			case ast::ShaderStage::eRayGeneration:
				return "Ray Generation";
			case ast::ShaderStage::eRayClosestHit:
				return "Ray Closest Hit";
			case ast::ShaderStage::eRayMiss:
				return "Ray Miss";
			case ast::ShaderStage::eRayIntersection:
				return "Ray Intersection";
			case ast::ShaderStage::eRayAnyHit:
				return "Ray Any Hit";
			case ast::ShaderStage::eCallable:
				return "Ray Callable";
			default:
				return "Unknown???"; 
			}
		}

		void testWriteDebug( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, Compilers const & compilers
			, test::TestCounts & testCounts )
		{
			if ( compilers.debug )
			{
				testCounts.incIndent();
				testCounts << "Debug statements, full" << endl;

				for ( auto & entryPoint : entryPoints )
				{
					testCounts.incIndent();
					testCounts << printStage( entryPoint.stage ) << " stage, entry point :[" << entryPoint.name << "]" << endl;
					auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );

					try
					{
						auto debug = ::sdw::writeDebug( *statements );
						displayShader( "Statements", debug, testCounts, compilers.forceDisplay, false );
						success();
					}
					catch ( std::exception & exc )
					{
						failure( "testWriteFullDebug" );
						testCounts << exc.what() << endl;
					}

					testCounts.decIndent();
				}

				testCounts << "Debug statements, preprocessed" << endl;

				for ( auto & entryPoint : entryPoints )
				{
					testCounts.incIndent();
					testCounts << printStage( entryPoint.stage ) << " stage, entry point :[" << entryPoint.name << "]" << endl;
					auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );

					try
					{
						auto debug = ::sdw::writeDebugPreprocessed( shader, *statements );
						displayShader( "Statements", debug, testCounts, compilers.forceDisplay, false );
						success();
					}
					catch ( std::exception & exc )
					{
						failure( "testWritePreprocessedDebug" );
						testCounts << exc.what() << endl;
					}

					testCounts.decIndent();
				}

				testCounts.decIndent();
			}
		}

		void testWriteGlslOnIndex( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerGlsl

			auto validate = [&]()
			{
				for ( auto & entryPoint : entryPoints )
				{
					testCounts.incIndent();
					testCounts << printStage( entryPoint.stage ) << " stage, entry point :[" << entryPoint.name << "]" << endl;
					std::string errors;
					auto config = getGlslConfig( testCounts.getGlslVersion( infoIndex ) );
					config.allocator = &testCounts.allocator;

					if ( isRayTraceStage( entryPoint.stage )
						|| entryPoint.stage == ast::ShaderStage::eMesh
						|| entryPoint.stage == ast::ShaderStage::eTask )
					{
						config.vulkanGlsl = true;
					}

					std::string glsl;

					try
					{
						auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
						glsl = glsl::compileGlsl( shader
							, statements.get()
							, entryPoint.stage
							, specialisation
							, config );
					}
					catch ( std::exception & exc )
					{
						testCounts << exc.what() << endl;
						testCounts.decIndent();
						return;
					}

					bool isCompiled{ false };

					if ( isRayTraceStage( entryPoint.stage )
						|| entryPoint.stage == ast::ShaderStage::eMesh
						|| entryPoint.stage == ast::ShaderStage::eTask
						|| config.requiredExtensions.end() != config.requiredExtensions.find( glsl::EXT_separate_samplers ) )
					{
						try
						{
							compileGlslToSpv( entryPoint.stage, glsl, 150 );
							isCompiled = true;
						}
						catch ( std::exception & exc )
						{
							errors += exc.what();
						}
					}
					else
					{
						isCompiled = compileGlsl( glsl
							, entryPoint.stage
							, errors
							, testCounts );
					}

					check( isCompiled )

					if ( !isCompiled )
					{
						displayShader( "GLSL", glsl, testCounts, true, true );
						testCounts << errors << endl;
					}
					else
					{
						displayShader( "GLSL", glsl, testCounts, compilers.forceDisplay, true );
					}
					
					testCounts.decIndent();
				}
			};
			testCounts.incIndent();
			testCounts << "GLSL version " << std::to_string( testCounts.getGlslVersion( infoIndex ) ) << endl;
			checkNoThrow( validate() )
			testCounts.decIndent();

#endif
		}

		void testWriteGlsl( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts )
		{
			if ( compilers.glsl )
			{
				auto count = testCounts.getGlslInfosSize();
				for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
				{
					testWriteGlslOnIndex( shader
						, entryPoints
						, specialisation
						, compilers
						, testCounts
						, infoIndex );
				}
			}
		}

		void testWriteHlslOnIndex( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerHlsl

			auto validate = [&]()
			{
				for ( auto & entryPoint : entryPoints )
				{
					testCounts.incIndent();
					testCounts << printStage( entryPoint.stage ) << " stage, entry point :[" << entryPoint.name << "]" << endl;
					std::string errors;
					std::string hlsl;

					try
					{
						auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
						hlsl = hlsl::compileHlsl( shader
							, statements.get()
							, entryPoint.stage
							, specialisation
							, hlsl::HlslConfig{ testCounts.getHlslVersion( infoIndex )
								, entryPoint.stage
								, false
								, &testCounts.allocator } );
					}
					catch ( std::exception & exc )
					{
						testCounts << exc.what() << endl;
						testCounts.decIndent();
						return;
					}

					displayShader( "HLSL", hlsl, testCounts, compilers.forceDisplay, true );
					bool isCompiled = compileHlsl( hlsl
						, entryPoint.stage
						, errors
						, testCounts
						, infoIndex );
					check( isCompiled )

					if ( !isCompiled )
					{
						displayShader( "HLSL", hlsl, testCounts, !compilers.forceDisplay, true );
						testCounts << errors << endl;
					}

					testCounts.decIndent();
				}
			};
			testCounts.incIndent();
			auto shaderModel = testCounts.getHlslVersion( infoIndex );
			auto major = shaderModel / 10u;
			auto minor = shaderModel % 10u;
			auto model = std::to_string( major ) + "_" + std::to_string( minor );
			testCounts << "HLSL Shader Model " << model << endl;
			checkNoThrow( validate() )
			testCounts.decIndent();
#endif
		}

		void testWriteHlsl( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts )
		{
			if ( compilers.hlsl )
			{
				auto count = testCounts.getHlslInfosSize();
				for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
				{
					testWriteHlslOnIndex( shader
						, entryPoints
						, specialisation
						, compilers
						, testCounts
						, infoIndex );
				}
			}
		}

		uint32_t getVkMajor( uint32_t vkVersion )
		{
			return ( ( vkVersion >> 22u ) & 0x7FU );
		}

		uint32_t getVkMinor( uint32_t vkVersion )
		{
			return ( ( vkVersion >> 12u ) & 0x3FFU );
		}

		std::string printVkVersion( uint32_t vkVersion )
		{
			std::stringstream stream;
			stream << getVkMajor( vkVersion ) << "." << getVkMinor( vkVersion );
			return stream.str();
		}

		uint32_t getSpvMajor( uint32_t spvVersion )
		{
			return ( spvVersion >> 16u );
		}

		uint32_t getSpvMinor( uint32_t spvVersion )
		{
			return ( ( spvVersion >> 8u ) & 0xFF );
		}

		std::string printSpvVersion( uint32_t spvVersion )
		{
			std::stringstream stream;
			stream << getSpvMajor( spvVersion ) << "." << getSpvMinor( spvVersion );
			return stream.str();
		}

		void testWriteSpirVOnIndex( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, spirv::DebugLevel debugLevel
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerSpirV

			if ( testCounts.isSpirVInitialised( infoIndex )
				&& !testCounts.isSpvIgnored( infoIndex, compilers.ignoredSpv ) )
			{
				auto validate = [&]( bool availableExtensions )
				{
					try
					{
						for ( auto & entryPoint : entryPoints )
						{
							testCounts.incIndent();

							if ( !availableExtensions )
							{
								testCounts << printStage( entryPoint.stage ) << " stage" << ", entry point :[" << entryPoint.name << "]" << endl;
							}

							spirv::SpirVExtensionSet extensions;
							spirv::SpirVConfig config{};
							config.specVersion = testCounts.getSpirVVersion( infoIndex );
							config.debugLevel = debugLevel;

							if ( availableExtensions )
							{
								if ( config.specVersion >= spirv::v1_6 )
								{
									extensions.emplace( spirv::EXT_mesh_shader );
								}

								if ( config.specVersion >= spirv::v1_5 )
								{
									extensions.emplace( spirv::KHR_terminate_invocation );
								}

								if ( config.specVersion >= spirv::v1_4 )
								{
									extensions.emplace( spirv::EXT_demote_to_helper_invocation );
									extensions.emplace( spirv::KHR_ray_tracing );
								}

								if ( config.specVersion >= spirv::v1_3 )
								{
									extensions.emplace( spirv::NV_mesh_shader );
									extensions.emplace( spirv::EXT_descriptor_indexing );
									extensions.emplace( spirv::EXT_physical_storage_buffer );
									extensions.emplace( spirv::KHR_shader_subgroup );
								}

								if ( config.specVersion >= spirv::v1_2 )
								{
									extensions.emplace( spirv::KHR_8bit_storage );
								}

								if ( config.specVersion >= spirv::v1_1 )
								{
									extensions.emplace( spirv::KHR_16bit_storage );
									extensions.emplace( spirv::KHR_shader_ballot );
									extensions.emplace( spirv::KHR_shader_draw_parameters );
								}

								if ( config.debugLevel == spirv::DebugLevel::eDebugInfo && config.specVersion >= spirv::v1_0 )
								{
									extensions.emplace( spirv::KHR_non_semantic_info );
								}

								config.availableExtensions = &extensions;
							}

							config.allocator = &testCounts.allocator;
							auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
							auto shaderModule = spirv::compileSpirV( *testCounts.allocatorBlock
								, shader
								, statements.get()
								, entryPoint.stage
								, config );
							auto textSpirv = spirv::writeModule( *shaderModule );

							if ( textSpirv.empty() )
							{
								testCounts << "Empty shader" << endl;
								testCounts.decIndent();
								return;
							}

							displayShader( "SPIR-V", textSpirv, testCounts, compilers.forceDisplay && availableExtensions, false );
							std::vector< uint32_t > spirv;

							try
							{
								spirv = spirv::serialiseModule( *shaderModule );
								success();
							}
							catch ( ... )
							{
								failure( "testWriteSpirV" );
								displayShader( "SPIR-V", textSpirv, testCounts, availableExtensions, false );
								throw;
							}

							try
							{
								test::validateSpirV( shader
									, statements.get()
									, entryPoint.stage
									, spirv
									, textSpirv
									, specialisation
									, testCounts
									, infoIndex
									, compilers
									, config.requiredExtensions );
								success();
							}
#if SDW_Test_HasSpirVCross
							catch ( spirv_cross::CompilerError & exc )
							{
								std::string text = exc.what();

								if ( text.find( "not supported in HLSL" ) == std::string::npos
									&& text.find( "not supported on HLSL" ) == std::string::npos
									&& text.find( "exist in HLSL" ) == std::string::npos
									&& text.find( "Unsupported builtin in HLSL" ) == std::string::npos
									&& text.find( "Unsupported execution model" ) == std::string::npos
									&& text.find( "No function currently in scope" ) == std::string::npos
									&& text.find( "Cannot subdivide a scalar value!" ) == std::string::npos
									&& text.find( "NumWorkgroups builtin is used" ) == std::string::npos
									&& text.find( "Cannot resolve expression type" ) == std::string::npos
									&& text.find( "Wave ops requires SM 6.0 or higher" ) == std::string::npos
									&& text.find( "Cannot trivially implement InverseBallot in HLSL" ) == std::string::npos
									&& text.find( "Cannot trivially implement BallotBitCount in HLSL" ) == std::string::npos
									&& text.find( "Cannot trivially implement BallotBitCount Inclusive Scan in HLSL" ) == std::string::npos
									&& text.find( "Cannot trivially implement BallotBitCount Exclusive Scan in HLSL" ) == std::string::npos
									&& text.find( "Cannot trivially implement BallotFindLSB in HLSL" ) == std::string::npos
									&& text.find( "Cannot trivially implement BallotFindMSB in HLSL" ) == std::string::npos
									&& text.find( "Cannot trivially implement BallotBitExtract in HLSL" ) == std::string::npos )
								{
									failure( "testWriteSpirV" );
									displayShader( "SPIR-V", textSpirv, testCounts, availableExtensions, false );
									testCounts << "spirv_cross exception: " << text << endl;
									throw;
								}
							}
#endif
							catch ( std::exception & )
							{
								failure( "testWriteSpirV" );
								displayShader( "SPIR-V", textSpirv, testCounts, availableExtensions, false );
								throw;
							}

							testCounts.decIndent();
						}
					}
					catch ( std::exception & exc )
					{
						testCounts << exc.what() << endl;
						testCounts.decIndent();
					}
					catch ( ... )
					{
						testCounts << "Unknown exception" << endl;
						testCounts.decIndent();
					}
				};
				testCounts.incIndent();
				testCounts << "Vulkan " << printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
					<< " - SPIR-V " << printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) << endl;
				checkNoThrow( validate( false ) )
				checkNoThrow( validate( true ) )
				testCounts.decIndent();
			}

#endif
		}

		void testWriteSpirV( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts )
		{
			if ( compilers.spirV )
			{
				auto count = testCounts.getSpirvInfosSize();
				for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
				{
#if SDW_Test_SpirVAllDebugLevels
					testWriteSpirVOnIndex( shader
						, entryPoints
						, specialisation
						, compilers
						, testCounts
						, spirv::DebugLevel::eNone
						, infoIndex );
					testWriteSpirVOnIndex( shader
						, entryPoints
						, specialisation
						, compilers
						, testCounts
						, spirv::DebugLevel::eNames
						, infoIndex );
#endif
					testWriteSpirVOnIndex( shader
						, entryPoints
						, specialisation
						, compilers
						, testCounts
						, spirv::DebugLevel::eDebugInfo
						, infoIndex );
				}
			}
		}

		std::vector< uint8_t > getSpecData( ::sdw::SpecConstantInfo const & info )
		{
			return std::vector< uint8_t >( size_t( getSize( info.type
					, ast::type::MemoryLayout::eStd430 ) )
				, 0 );
		}

		::sdw::SpecialisationInfo getSpecialisationInfo( ::ast::Shader const & shader )
		{
			auto & specInfo = shader.getSpecConstants();
			::sdw::SpecialisationInfo result;

			for ( auto & info : specInfo )
			{
				result.data.push_back( { info.second, getSpecData( info.second ) } );
			}

			return result;
		}

		auto spirvCrossValidate( ast::Shader const & shader
			, ast::EntryPointConfigArray const & entryPoints
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_Test_HasSpirVCross
			for ( auto const & entryPoint : entryPoints )
			{
				spirv::SpirVConfig config{};
				config.debugLevel = spirv::DebugLevel::eNames;
				auto statements = ::ast::selectEntryPoint( shader.getStmtCache()
					, shader.getExprCache()
					, entryPoint
					, *shader.getStatements() );
				config.specVersion = testCounts.getSpirVVersion( infoIndex );
				auto sdwSpirV = spirv::serialiseSpirv( shader
					, statements.get()
					, entryPoint.stage
					, config );
				auto crossGlsl = test::validateSpirVToGlsl( sdwSpirV
					, entryPoint.stage
					, testCounts
					, true );
				auto textSpirv = spirv::writeSpirv( shader
					, statements.get()
					, entryPoint.stage
					, config );
				displayShader( "SPIR-V"
					, textSpirv
					, testCounts
					, true
					, false );
				displayShader( "SpirV-Cross GLSL"
					, crossGlsl
					, testCounts
					, true
					, true );
				auto cfg = getGlslConfig( glsl::v4_6 );
				auto glslangSpirv = compileGlslToSpv( entryPoint.stage
					, glsl::compileGlsl( shader
						, statements.get()
						, entryPoint.stage
						, ast::SpecialisationInfo{}
						, cfg ) );
				displayShader( "glslang SPIR-V"
					, spirv::displaySpirv( shader.getAllocator(), glslangSpirv )
					, testCounts
					, true
					, false );
			}
#endif
		}

		ast::ShaderStage getShaderStage( ast::Shader const & shader )
		{
			return shader.getType();
		}

		ast::ShaderStage getShaderStage( ast::ShaderPtr const & shader )
		{
			return getShaderStage( *shader );
		}

		ast::ShaderAllocatorBlock * getAllocator( ast::Shader const & shader )
		{
			return &shader.getAllocator();
		}

		ast::ShaderAllocatorBlock * getAllocator( ast::ShaderPtr const & shader )
		{
			return getAllocator( *shader );
		}

		ast::Shader const & getShader( ast::Shader const & shader )
		{
			return shader;
		}

		ast::Shader const & getShader( ast::ShaderPtr const & shader )
		{
			return *shader;
		}

		template< typename ShaderArrayT >
		void validateShadersOnIndex( ShaderArrayT const & shaders
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, Compilers const & compilers )
		{
#if SDW_Test_HasVulkan && SDW_HasCompilerSpirV && SDW_HasVulkanLayer
			if ( compilers.spirV
				&& testCounts.isSpirVInitialised( infoIndex ) )
			{
				testCounts.incIndent();
				testCounts << "Vulkan " << printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
					<< " - SPIR-V " << printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) << endl;

				try
				{
					ast::vk::ProgramPipeline program{ testCounts.getSpirVVersion( infoIndex )
						, shaders };

					if ( compilers.forceDisplay )
					{
						testCounts << program << endl;
					}

					std::string errors;

					if ( auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
						errors.find( "failed to compile internal representation" ) == std::string::npos
							&& errors.find( "unexpected compilation failure" ) == std::string::npos )
					{
						check( isValidated )
						check( errors.empty() )

						if ( !isValidated
							|| !errors.empty() )
						{
							if ( !errors.empty() )
							{
								testCounts << errors << endl;
								testCounts << program << endl;
							}

							for ( auto const & shader : shaders )
							{
								ast::EntryPointConfigArray entryPoints{ ast::StlAllocatorT< ast::EntryPointConfig >{ getAllocator( shader ) } };
								entryPoints.emplace_back( getShaderStage( shader ), "main" );
								checkNoThrow( spirvCrossValidate( getShader( shader )
									, entryPoints
									, testCounts
									, infoIndex ) );
							}
						}
					}
				}
				catch ( std::exception & exc )
				{
					auto err = std::string{ exc.what() };

					if ( err != std::string{ "Shader serialization failed." }
						&& err.find( "failed to compile internal representation" ) == std::string::npos
						&& err.find( "unexpected compilation failure" ) == std::string::npos )
					{
						failure( "Shader validation" );
					}
				}

				testCounts.decIndent();
			}
#endif
		}

		void validateShaderOnIndex( ::ast::Shader const & shader
			, ast::EntryPointConfigArray const & entryPoints
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, Compilers const & compilers )
		{
#if SDW_Test_HasVulkan && SDW_HasCompilerSpirV && SDW_HasVulkanLayer
			if ( compilers.spirV
				&& testCounts.isSpirVInitialised( infoIndex ) )
			{
				testCounts.incIndent();
				testCounts << "Vulkan " << printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
					<< " - SPIR-V " << printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) << endl;

				try
				{
					ast::vk::ProgramPipeline program{ testCounts.getSpirVVersion( infoIndex )
						, shader
						, entryPoints };

					if ( compilers.forceDisplay )
					{
						testCounts << program << endl;
					}

					std::string errors;

					if ( auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
						errors.find( "failed to compile internal representation" ) == std::string::npos
							&& errors.find( "unexpected compilation failure" ) == std::string::npos )
					{
						check( isValidated )
						check( errors.empty() )

						if ( !isValidated
							|| !errors.empty() )
						{
							if ( !errors.empty() )
							{
								testCounts << errors << endl;
							}

							checkNoThrow( spirvCrossValidate( shader, entryPoints, testCounts, infoIndex ) );
						}
					}
				}
				catch ( std::exception & exc )
				{
					auto err = std::string{ exc.what() };

					if ( err != std::string{ "Shader serialization failed." }
						&& err.find( "failed to compile internal representation" ) == std::string::npos
						&& err.find( "unexpected compilation failure" ) == std::string::npos )
					{
						failure( "Shader validation" );
					}
				}

				testCounts.decIndent();
			}
#endif
		}
	}

	namespace sdw_test
	{
		TestSuite::TestSuite( std::string name )
			: test::TestSuite{ std::move( name ) }
		{
			initialiseGlslang();
		}
		
		TestSuite::~TestSuite()
		{
			cleanupGlslang();
		}

		TestCounts::TestCounts( test::TestSuite & psuite )
			: test::TestCounts{ psuite }
		{
		}

		void TestCounts::doInitialise()
		{
			createGLSLContext( *this );
			createHLSLContext( *this );
			createSPIRVContext( *this );
		}

		void TestCounts::doCleanup()
		{
			destroySPIRVContext( *this );
			destroyHLSLContext( *this );
			destroyGLSLContext( *this );
		}

		bool TestCounts::isSpirVInitialised( uint32_t infoIndex )const
		{
			return retrieveIsSpirVInitialised( *this, infoIndex );
		}

		bool TestCounts::isSpvIgnored( uint32_t infoIndex, uint32_t ignoredSpvVersion )const
		{
			return retrieveSPIRVVersion( *this, infoIndex ) == ignoredSpvVersion;
		}

		uint32_t TestCounts::getVulkanVersion( uint32_t infoIndex )const
		{
			return retrieveVulkanVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getSpirVVersion( uint32_t infoIndex )const
		{
			return retrieveSPIRVVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getSpirvInfosSize()const
		{
			return retrieveSpirVInfosSize( *this );
		}

		bool TestCounts::isHlslInitialised( uint32_t infoIndex )const
		{
			return retrieveIsHLSLInitialised( *this, infoIndex );
		}

		uint32_t TestCounts::getHlslVersion( uint32_t infoIndex )const
		{
			return retrieveHLSLVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getHlslInfosSize()const
		{
			return retrieveHLSLInfosSize( *this );
		}

		bool TestCounts::isGlslInitialised( uint32_t infoIndex )const
		{
			return retrieveIsGLSLInitialised( *this, infoIndex );
		}

		uint32_t TestCounts::getGlslVersion( uint32_t infoIndex )const
		{
			return retrieveGLSLVersion( *this, infoIndex );
		}

		uint32_t TestCounts::getGlslInfosSize()const
		{
			return retrieveGLSLInfosSize( *this );
		}
	}

	void writeShader( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		auto specialisation = getSpecialisationInfo( shader );
		testWriteDebug( shader, entryPoints, compilers, testCounts );
		testWriteSpirV( shader, entryPoints, specialisation, compilers, testCounts );
		testWriteGlsl( shader, entryPoints, specialisation, compilers, testCounts );
		testWriteHlsl( shader, entryPoints, specialisation, compilers, testCounts );
	}

	void writeShader( ::ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		ast::EntryPointConfigArray entryPoints{ &shader.getAllocator() };
		entryPoints.emplace_back( shader.getType(), "main" );
		writeShader( shader
			, entryPoints
			, testCounts
			, compilers );
	}

	void writeShader( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		writeShader( writer.getShader()
			, testCounts
			, compilers );
	}

	void writeProgram( ::ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Write program" << endl;
		writeShader( shader
			, ast::listEntryPoints( *shader.getStatements() )
			, testCounts
			, compilers );
		testCounts.decIndent();
	}

	void writeProgram( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		writeProgram( writer.getShader()
			, testCounts
			, compilers );
	}

	void expectError( std::string value
		, sdw_test::TestCounts & testCounts )
	{
		testCounts.expectedError = std::move( value );
	}

	void validateShaders( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Validate shaders" << endl;

		auto count = testCounts.getSpirvInfosSize();
		for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
		{
			validateShaderOnIndex( shader
				, entryPoints
				, testCounts
				, infoIndex
				, compilers );
		}

		testCounts.decIndent();
	}

	void validateShaders( ast::ShaderArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Validate shaders" << endl;

		auto count = testCounts.getSpirvInfosSize();
		for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
		{
			validateShadersOnIndex( shaders
				, testCounts
				, infoIndex
				, compilers );
		}

		testCounts.decIndent();
	}

	void validateShaders( ast::ShaderPtrArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Validate shaders" << endl;

		auto count = testCounts.getSpirvInfosSize();
		for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
		{
			validateShadersOnIndex( shaders
				, testCounts
				, infoIndex
				, compilers );
		}

		testCounts.decIndent();
	}

	void validateShader( ast::Shader const & shader
		, ast::EntryPointConfig const & entryPoint
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Validate shader" << endl;
		ast::EntryPointConfigArray entryPoints{ &shader.getAllocator() };
		entryPoints.push_back( entryPoint );

		auto count = testCounts.getSpirvInfosSize();
		for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
		{
			validateShaderOnIndex( shader
				, entryPoints
				, testCounts
				, infoIndex
				, compilers );
		}

		testCounts.decIndent();
	}

	void validateShader( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		validateShader( shader
			, ::ast::EntryPointConfig{ shader.getType(), "main" }
		, testCounts
			, compilers );
	}

	void validateProgram( ast::Shader const & shader
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Validate program" << endl;

		if ( auto entryPoints = ast::listEntryPoints( *shader.getStatements() );
			entryPoints.size() > 1u )
		{
			validateShaders( shader
				, entryPoints
				, testCounts
				, compilers );
		}
		else
		{
			validateShader( shader
				, entryPoints.front()
				, testCounts
				, compilers );
		}

		testCounts.decIndent();
	}

	void validateProgram( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		validateProgram( writer.getShader()
			, testCounts
			, compilers );
	}
}
