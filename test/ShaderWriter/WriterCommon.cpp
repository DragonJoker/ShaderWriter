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
				result = spv::ExecutionModelTaskEXT;
				break;
			case ast::ShaderStage::eMeshNV:
				result = spv::ExecutionModelMeshNV;
				break;
			case ast::ShaderStage::eMesh:
				result = spv::ExecutionModelMeshEXT;
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
				break;
			}

			return result;
		}

		void doSetEntryPoint( ast::ShaderStage stage
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
			doSetEntryPoint( stage, *compiler );
			doSetupOptions( stage, vulkanSemantics, *compiler );
			return compileSpirV( "GLSL", *compiler, testCounts );
		}

		std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
			, ast::ShaderStage stage
			, test::TestCounts & testCounts )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerHLSL >( spirv );
			doSetEntryPoint( stage, *compiler );
			doSetupHlslOptions( *compiler );
			doSetupOptions( stage, false, *compiler );
			return compileSpirV( "HLSL", *compiler, testCounts );
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
				testCounts << "////////////////////////////////////////////////////////////" << endl;
				testCounts << "// " << name << endl;
				testCounts << "////////////////////////////////////////////////////////////" << endl;

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
			, std::vector< uint32_t > spirv
			, std::string const & text
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, bool checkRef )
		{
			//auto parsedShader = spirv::parseSpirv( shader.getType(), spirv );
			std::string errors;
			auto result = test::compileSpirV( shader, spirv, errors, testCounts, infoIndex );
			check( errors.empty() || !checkRef );

			if ( !errors.empty() )
			{
				testCounts << "VkShaderModule creation raised messages, for CompilerSpv output:" << endl;
				testCounts << errors << endl;
				result = false;

				if ( checkRef )
				{
					auto fileName = getExecutableDirectory() + testCounts.testName + std::to_string( testCounts.getTotalCount() ) + ".spv";
					FILE * fileOut = fopen( fileName.c_str(), "wb" );

					if ( fileOut )
					{
						fwrite( spirv.data()
							, sizeof( uint32_t )
							, spirv.size()
							, fileOut );
						fclose( fileOut );
					}

					fileName = getExecutableDirectory() + testCounts.testName + std::to_string( testCounts.getTotalCount() ) + ".ref.spv";
					FILE * fileIn = fopen( fileName.c_str(), "rb" );

					if ( fileIn )
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
						validateSpirV( shader, spirv, errors, testCounts, infoIndex, false );
					}
				}
			}

			return result;
		}

		void validateSpirV( ::ast::Shader const & shader
			, std::vector< uint32_t > const & spirv
			, std::string const & text
			, spirv::SpirVExtensionSet const & requiredExtensions
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, bool display )
		{
			auto isValidated = validateSpirV( shader, spirv, text, testCounts, infoIndex, true );
			check( isValidated );

			if ( !isValidated )
			{
#if SDW_HasCompilerGlsl

				if ( !isRayTraceStage( shader.getType() ) )
				{
					try
					{
						auto cfg = getGlslConfig( glsl::v4_6 );
						cfg.allocator = &testCounts.allocator;
						auto glslangSpirv = compileGlslToSpv( shader.getType()
							, glsl::compileGlsl( shader
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
			}

#if SDW_Test_HasSpirVTools
			std::string errors;
			auto consumer = [&errors]( spv_message_level_t level
				, char const * source
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
			check( isValidated );

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
				&& requiredExtensions.end() == requiredExtensions.find( spirv::KHR_terminate_invocation ) )
			{
				auto crossGlsl = test::validateSpirVToGlsl( spirv, shader.getType(), testCounts
					, ( requiredExtensions.end() != requiredExtensions.find( spirv::KHR_terminate_invocation )
						|| requiredExtensions.end() != requiredExtensions.find( spirv::EXT_demote_to_helper_invocation )
						|| requiredExtensions.end() != requiredExtensions.find( spirv::KHR_shader_subgroup )
						|| requiredExtensions.end() != requiredExtensions.find( spirv::EXT_shader_atomic_float_add )
						|| requiredExtensions.end() != requiredExtensions.find( spirv::EXT_mesh_shader ) ) );
				displayShader( "SPIRV-Cross GLSL", crossGlsl, testCounts, compilers.forceDisplay && display, true );
			}

			if ( compilers.hlsl
				&& !isRayTraceStage( shader.getType() )
				&& !isMeshStage( shader.getType() )
				&& requiredExtensions.end() == requiredExtensions.find( spirv::KHR_terminate_invocation )
				&& requiredExtensions.end() == requiredExtensions.find( spirv::EXT_demote_to_helper_invocation ) )
			{
				auto crossHlsl = test::validateSpirVToHlsl( spirv, shader.getType(), testCounts );
				displayShader( "SPIRV-Cross HLSL", crossHlsl, testCounts, compilers.forceDisplay && display, true );
			}

#endif
		}

		void testWriteDebug( ::ast::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, test::TestCounts & testCounts )
		{
			auto debug = ::sdw::writeDebug( shader );
			displayShader( "Statements", debug, testCounts, compilers.forceDisplay, false );
		}

		void testWriteGlslOnIndex( ::ast::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerGlsl

			auto validate = [&]()
			{
				std::string errors;
				auto config = getGlslConfig( testCounts.getGlslVersion( infoIndex ) );
				config.allocator = &testCounts.allocator;

				if ( isRayTraceStage( shader.getType() )
					|| shader.getType() == ast::ShaderStage::eMesh
					|| shader.getType() == ast::ShaderStage::eTask )
				{
					config.vulkanGlsl = true;
				}

				std::string glsl;

				try
				{
					glsl = glsl::compileGlsl( shader
						, specialisation
						, config );
				}
				catch ( std::exception & exc )
				{
					testCounts << exc.what() << endl;
					return;
				}

				bool isCompiled{ false };

				if ( isRayTraceStage( shader.getType() )
					|| shader.getType() == ast::ShaderStage::eMesh
					|| shader.getType() == ast::ShaderStage::eTask
					|| config.requiredExtensions.end() != config.requiredExtensions.find( glsl::EXT_separate_samplers ) )
				{
					testCounts << "COIN !!";
					try
					{
						compileGlslToSpv( shader.getType(), glsl, 150 );
						isCompiled = true;
					}
					catch ( std::exception & exc )
					{
						errors += exc.what();
					}
				}
				else
				{
					testCounts << "GLOP !!";
					isCompiled = compileGlsl( glsl
						, shader.getType()
						, errors
						, testCounts );
				}

				check( isCompiled );

				if ( !isCompiled )
				{
					displayShader( "GLSL", glsl, testCounts, true, true );
					testCounts << errors << endl;
				}
				else
				{
					displayShader( "GLSL", glsl, testCounts, compilers.forceDisplay, true );
				}
			};
			testCounts.incIndent();
			testCounts << "GLSL version " << std::to_string( testCounts.getGlslVersion( infoIndex ) ) << endl;
			checkNoThrow( validate() );
			testCounts.decIndent();

#endif
		}

		void testWriteGlsl( ::ast::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts )
		{
			if ( compilers.glsl )
			{
				for ( uint32_t infoIndex = 0u; infoIndex < testCounts.getGlslInfosSize(); ++infoIndex )
				{
					testWriteGlslOnIndex( shader
						, specialisation
						, compilers
						, testCounts
						, infoIndex );
				}
			}
		}

		std::string printHlslModel( ast::ShaderStage type
			, uint32_t shaderModel )
		{
			auto major = shaderModel / 10u;
			auto minor = shaderModel % 10u;
			auto model = std::to_string( major ) + "_" + std::to_string( minor );

			switch ( type )
			{
			case ast::ShaderStage::eVertex:
				model = "vs_" + model;
				break;
			case ast::ShaderStage::eTessellationControl:
				model = "hs_" + model;
				break;
			case ast::ShaderStage::eTessellationEvaluation:
				model = "ds_" + model;
				break;
			case ast::ShaderStage::eGeometry:
				model = "gs_" + model;
				break;
			case ast::ShaderStage::eCompute:
				model = "cs_" + model;
				break;
			case ast::ShaderStage::eFragment:
				model = "ps_" + model;
				break;
			case ast::ShaderStage::eMeshNV:
				model = "ms_" + model;
				break;
			case ast::ShaderStage::eMesh:
				model = "ms_" + model;
				break;
			case ast::ShaderStage::eTaskNV:
				model = "as_" + model;
				break;
			case ast::ShaderStage::eTask:
				model = "as_" + model;
				break;
			case ast::ShaderStage::eCallable:
				model = "lib_" + model;
				break;
			case ast::ShaderStage::eRayGeneration:
				model = "lib_" + model;
				break;
			case ast::ShaderStage::eRayIntersection:
				model = "lib_" + model;
				break;
			case ast::ShaderStage::eRayMiss:
				model = "lib_" + model;
				break;
			case ast::ShaderStage::eRayAnyHit:
				model = "lib_" + model;
				break;
			case ast::ShaderStage::eRayClosestHit:
				model = "lib_" + model;
				break;
			default:
				break;
			}

			return model;
		}

		void testWriteHlslOnIndex( ::ast::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerHlsl

			auto validate = [&]()
			{
				std::string errors;
				std::string hlsl;

				try
				{
					hlsl = hlsl::compileHlsl( shader
						, specialisation
						, hlsl::HlslConfig{ testCounts.getHlslVersion( infoIndex )
							, shader.getType()
							, false
							, &testCounts.allocator } );
				}
				catch ( std::exception & exc )
				{
					testCounts << exc.what() << endl;
					return;
				}

				displayShader( "HLSL", hlsl, testCounts, compilers.forceDisplay, true );
				bool isCompiled = compileHlsl( hlsl
					, shader.getType()
					, errors
					, testCounts
					, infoIndex );
				check( isCompiled );

				if ( !isCompiled )
				{
					displayShader( "HLSL", hlsl, testCounts, !compilers.forceDisplay, true );
					testCounts << errors << endl;
				}
			};
			testCounts.incIndent();
			testCounts << "HLSL Shader Model " << printHlslModel( shader.getType(), testCounts.getHlslVersion( infoIndex ) ) << endl;
			checkNoThrow( validate() );
			testCounts.decIndent();
#endif
		}

		void testWriteHlsl( ::ast::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts )
		{
			if ( compilers.hlsl )
			{
				for ( uint32_t infoIndex = 0u; infoIndex < testCounts.getHlslInfosSize(); ++infoIndex )
				{
					testWriteHlslOnIndex( shader
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
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
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
						spirv::SpirVExtensionSet extensions;
						spirv::SpirVConfig config{};
						config.specVersion = testCounts.getSpirVVersion( infoIndex );

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
							}

							config.availableExtensions = &extensions;
						}

						config.allocator = &testCounts.allocator;
						auto module = spirv::compileSpirV( shader, config );
						auto textSpirv = spirv::writeModule( *module );

						if ( textSpirv.empty() )
						{
							testCounts << "Empty shader" << endl;
							return;
						}

						displayShader( "SPIR-V", textSpirv, testCounts, compilers.forceDisplay && availableExtensions, false );
						std::vector< uint32_t > spirv;

						try
						{
							spirv = spirv::serialiseModule( *module );
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
								, spirv
								, textSpirv
								, config.requiredExtensions
								, specialisation
								, compilers
								, testCounts
								, infoIndex
								, availableExtensions );
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
						catch ( std::exception & exc )
						{
							failure( "testWriteSpirV" );
							displayShader( "SPIR-V", textSpirv, testCounts, availableExtensions, false );
							testCounts << "std exception: " << exc.what() << endl;
							throw;
						}
					}
					catch ( ... )
					{
					}
				};
				testCounts.incIndent();
				testCounts << "Vulkan " << printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
					<< " - SPIR-V " << printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) << endl;
				checkNoThrow( validate( false ) );
				checkNoThrow( validate( true ) );
				testCounts.decIndent();
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

		void testWriteSpirV( ::ast::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts )
		{
			if ( compilers.spirV )
			{
				for ( uint32_t infoIndex = 0u; infoIndex < testCounts.getSpirvInfosSize(); ++infoIndex )
				{
					testWriteSpirVOnIndex( shader
						, specialisation
						, compilers
						, testCounts
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

		void validateShadersOnIndex( ast::ShaderArray const & shaders
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
					ast::vk::ProgramPipeline program{ testCounts.getVulkanVersion( infoIndex )
						, testCounts.getSpirVVersion( infoIndex )
						, shaders };
					std::string errors;
					auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
					check( isValidated );
					check( errors.empty() );

					if ( !isValidated
						|| !errors.empty() )
					{
						if ( !errors.empty() )
						{
							testCounts << errors << endl;
						}

#if SDW_Test_HasSpirVCross
						auto validate = [&]( ast::Shader const & shader )
						{
							spirv::SpirVConfig config{};
							config.specVersion = testCounts.getSpirVVersion( infoIndex );
							config.stmtCache = &testCounts.stmtCache;
							config.exprCache = &testCounts.exprCache;
							auto sdwSpirV = spirv::serialiseSpirv( shader, config );
							auto crossGlsl = test::validateSpirVToGlsl( sdwSpirV
								, shader.getType()
								, testCounts
								, true );
							config.stmtCache = &testCounts.stmtCache;
							config.exprCache = &testCounts.exprCache;
							auto textSpirv = spirv::writeSpirv( shader, config );
							displayShader( "SPIR-V", textSpirv, testCounts, true, false );
							displayShader( "SpirV-Cross GLSL", crossGlsl, testCounts, true, true );
							auto cfg = getGlslConfig( glsl::v4_6 );
							cfg.stmtCache = &testCounts.stmtCache;
							cfg.exprCache = &testCounts.exprCache;
							auto glslangSpirv = compileGlslToSpv( shader.getType()
								, glsl::compileGlsl( shader
									, ast::SpecialisationInfo{}
									, cfg ) );
							displayShader( "glslang SPIR-V"
								, spirv::displaySpirv( glslangSpirv )
								, testCounts
								, true
								, true );
						};

						for ( auto & shader : shaders )
						{
							checkNoThrow( validate( shader ) );
						}
#endif
					}
				}
				catch ( std::exception & exc )
				{
					if ( exc.what() != std::string{ "Shader serialization failed." } )
					{
						failure( "Shader validation" );
					}
				}

				testCounts.decIndent();
			}
#endif
		}

		void validateShadersOnIndex( ast::ShaderPtrArray const & shaders
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
					ast::vk::ProgramPipeline program{ testCounts.getVulkanVersion( infoIndex )
						, testCounts.getSpirVVersion( infoIndex )
						, shaders };
					std::string errors;
					auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
					check( isValidated );
					check( errors.empty() );

					if ( !isValidated
						|| !errors.empty() )
					{
						if ( !errors.empty() )
						{
							testCounts << errors << endl;
						}

#if SDW_Test_HasSpirVCross
						auto validate = [&]( ast::Shader const & shader )
						{
							spirv::SpirVConfig config{};
							config.specVersion = testCounts.getSpirVVersion( infoIndex );
							config.stmtCache = &testCounts.stmtCache;
							config.exprCache = &testCounts.exprCache;
							auto sdwSpirV = spirv::serialiseSpirv( shader, config );
							auto crossGlsl = test::validateSpirVToGlsl( sdwSpirV
								, shader.getType()
								, testCounts
								, true );
							config.stmtCache = &testCounts.stmtCache;
							config.exprCache = &testCounts.exprCache;
							auto textSpirv = spirv::writeSpirv( shader, config );
							displayShader( "SPIR-V", textSpirv, testCounts, true, false );
							displayShader( "SpirV-Cross GLSL", crossGlsl, testCounts, true, true );
							auto cfg = getGlslConfig( glsl::v4_6 );
							cfg.stmtCache = &testCounts.stmtCache;
							cfg.exprCache = &testCounts.exprCache;
							auto glslangSpirv = compileGlslToSpv( shader.getType()
								, glsl::compileGlsl( shader
									, ast::SpecialisationInfo{}
									, cfg ) );
							displayShader( "glslang SPIR-V"
								, spirv::displaySpirv( glslangSpirv )
								, testCounts
								, true
								, true );
						};

						for ( auto & shader : shaders )
						{
							checkNoThrow( validate( shader ) );
						}
#endif
					}
				}
				catch ( std::exception & exc )
				{
					if ( exc.what() != std::string{ "Shader serialization failed." } )
					{
						failure( "Shader validation" );
					}
				}

				testCounts.decIndent();
			}
#endif
		}

		void validateShaderOnIndex( ::ast::Shader const & shader
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
					ast::vk::ProgramPipeline program{ testCounts.getVulkanVersion( infoIndex )
						, testCounts.getSpirVVersion( infoIndex )
						, shader };
					std::string errors;
					auto isValidated = validateProgram( program, errors, testCounts, infoIndex );
					check( isValidated );
					check( errors.empty() );

					if ( !isValidated
						|| !errors.empty() )
					{
						if ( !errors.empty() )
						{
							testCounts << errors << endl;
						}

#if SDW_Test_HasSpirVCross
						auto validate = [&]()
						{
							spirv::SpirVConfig config{};
							config.specVersion = testCounts.getSpirVVersion( infoIndex );
							config.stmtCache = &testCounts.stmtCache;
							config.exprCache = &testCounts.exprCache;
							auto sdwSpirV = spirv::serialiseSpirv( shader, config );
							auto crossGlsl = test::validateSpirVToGlsl( sdwSpirV
								, shader.getType()
								, testCounts
								, true );
							config.stmtCache = &testCounts.stmtCache;
							config.exprCache = &testCounts.exprCache;
							auto textSpirv = spirv::writeSpirv( shader, config );
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
							cfg.stmtCache = &testCounts.stmtCache;
							cfg.exprCache = &testCounts.exprCache;
							auto glslangSpirv = compileGlslToSpv( shader.getType()
								, glsl::compileGlsl( shader
									, ast::SpecialisationInfo{}
									, cfg ) );
							displayShader( "glslang SPIR-V"
								, spirv::displaySpirv( glslangSpirv )
								, testCounts
								, true
								, false );
						};
						checkNoThrow( validate() );
#endif
					}
				}
				catch ( std::exception & exc )
				{
					if ( exc.what() != std::string{ "Shader serialization failed." } )
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
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Write shader - " << printStage( shader.getType() ) << " stage" << endl;

		auto specialisation = getSpecialisationInfo( shader );
		testWriteDebug( shader, specialisation, compilers, testCounts );
		testWriteSpirV( shader, specialisation, compilers, testCounts );
		testWriteGlsl( shader, specialisation, compilers, testCounts );
		testWriteHlsl( shader, specialisation, compilers, testCounts );
		testCounts.decIndent();
	}

	void writeShader( sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		writeShader( writer.getShader()
			, testCounts
			, compilers );
	}

	void expectError( std::string value
		, sdw_test::TestCounts & testCounts )
	{
		testCounts.expectedError = std::move( value );
	}

	void validateShaders( ast::ShaderArray const & shaders
		, sdw_test::TestCounts & testCounts
		, Compilers const & compilers )
	{
		testCounts.incIndent();
		testCounts << "Validate shaders" << endl;

		for ( uint32_t infoIndex = 0u; infoIndex < testCounts.getSpirvInfosSize(); ++infoIndex )
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

		for ( uint32_t infoIndex = 0u; infoIndex < testCounts.getSpirvInfosSize(); ++infoIndex )
		{
			validateShadersOnIndex( shaders
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
		testCounts.incIndent();
		testCounts << "Validate shader" << endl;

		for ( uint32_t infoIndex = 0u; infoIndex < testCounts.getSpirvInfosSize(); ++infoIndex )
		{
			validateShaderOnIndex( shader
				, testCounts
				, infoIndex
				, compilers );
		}

		testCounts.decIndent();
	}
}
