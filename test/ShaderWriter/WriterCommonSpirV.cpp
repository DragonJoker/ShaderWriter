#include "WriterCommonSpirV.hpp"

#include "CompileGLSL.hpp"
#include "CompileSPIRV.hpp"
#include "GlslToSpv.hpp"
#include "WriterCommonVulkanLayer.hpp"

#if SDW_HasCompilerGlsl
#	include <CompilerGlsl/compileGlsl.hpp>
#endif
#if SDW_HasCompilerSpirV
#	include <CompilerSpirV/compileSpirV.hpp>
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

namespace test::sdw_test
{
	namespace spv_test
	{
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
#if !SDAST_ExceptAssert
				result = spv::ExecutionModelMax;
#endif
				break;
			}

			return result;
		}

		spv::ExecutionModel setEntryPoint( ast::ShaderStage stage
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

		void setupOptions( ast::ShaderStage stage
			, bool vulkanSemantics
			, spirv_cross::CompilerGLSL & compiler )
		{
			auto options = compiler.get_common_options();
			options.separate_shader_objects = true;
			options.vulkan_semantics = vulkanSemantics || isRayTraceStage( stage );
			compiler.set_common_options( options );
		}

		void setupHlslOptions( spirv_cross::CompilerHLSL & compiler )
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
				testCounts.printBlock( "SPIRV-Cross(" + std::string( language ) + "), shader compilation failed: " + std::string( exc.what() ) );
				throw;
			}
			catch ( std::exception & exc )
			{
				testCounts.printBlock( "SPIRV-Cross(" + std::string{ language } + "), shader compilation failed: " + std::string{ exc.what() } );
				throw;
			}
			catch ( ... )
			{
				testCounts.printBlock( "SPIRV-Cross(" + std::string{ language } + "), shader compilation failed: Unknown error" );
				throw;
			}

			return result;
		}
#endif

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
			if ( !errors.empty() && checkRef )
				testCounts.printError( "VkShaderModule creation raised messages, for CompilerSpv output:\n" + errors );

			if ( !errors.empty() )
			{
				result = false;

				if ( checkRef )
				{
					auto fileName = getExecutableDirectory() + testCounts.testName + std::to_string( uintptr_t( statements ) ) + ".spv";

					if ( FILE * fileOut = fopen( fileName.c_str(), "wb" ) )
					{
						fwrite( spirv.data()
							, sizeof( uint32_t )
							, spirv.size()
							, fileOut );
						fclose( fileOut );
					}

					fileName = getExecutableDirectory() + testCounts.testName + std::to_string( uintptr_t( statements ) ) + ".ref.spv";

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
			, ::ast::SpecialisationInfo const & specialisation
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, Compilers const & compilers
			, spirv::SpirVExtensionSet const &requiredExtensions )
		{
			auto isValidated = validateSpirV( shader, statements, stage, spirv, testCounts, infoIndex, true );
			astCheck( isValidated )

#if SDW_HasCompilerGlsl

			if ( !isValidated
				&& !isRayTraceStage( stage ) )
			{
				try
				{
					auto cfg = getGlslConfig( glsl::v4_6 );
					auto glslangSpirv = compileGlslToSpv( stage
						, glsl::compileGlsl( *testCounts.allocatorBlock
							, shader
							, statements
							, stage
							, specialisation
							, cfg ) );
					std::string errors;
					test::compileSpirV( shader, glslangSpirv, errors, testCounts, infoIndex );
					if ( !errors.empty() )
						testCounts.printError( "VkShaderModule creation raised messages, for glslang output:\n" + errors );
				}
				catch ( std::exception & exc )
				{
					testCounts.printBlock( exc.what() );
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
			if ( !isValidated )
				testCounts.printError( printShader( "SPIR-V", text, false ) );
			if ( !errors.empty() )
				testCounts.printError(  "SPIR-V validation raised messages:\n" + errors );
#endif

#if SDW_Test_HasSpirVCross

			if ( compilers.glsl
				&& requiredExtensions.contains( spirv::KHR_terminate_invocation ) )
			{
				if ( auto crossGlsl = validateSpirVToGlsl( spirv, stage, testCounts
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
				if ( auto crossHlsl = validateSpirVToHlsl( spirv, stage, testCounts );
					!crossHlsl.empty() )
				{
					displayShader( "SPIRV-Cross HLSL", crossHlsl, testCounts, compilers.forceDisplay, true );
				}
			}

#endif
		}

		static std::pair< ast::stmt::ContainerPtr, spirv::ModulePtr > generateModule( ::ast::Shader const & shader
			, ::ast::EntryPointConfig const & entryPoint
			, spirv::SpirVConfig & config
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateSpirV" );
			auto statements = ::ast::selectEntryPoint( shader.getStmtCache(), shader.getExprCache(), entryPoint, *shader.getStatements() );
			auto shaderModule = spirv::compileSpirV( *testCounts.allocatorBlock
					, shader
					, statements.get()
					, entryPoint.stage
					, config );
			return { std::move( statements ), std::move( shaderModule ) };
		}

		static std::string generateTextSpirV( spirv::Module const & shaderModule
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateSpirV" );
			return spirv::writeModule( shaderModule );
		}

		static std::vector< uint32_t > generateBinarySpirV( spirv::Module const & shaderModule
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateSpirV" );
			return spirv::serialiseModule( shaderModule );
		}

		void testWriteSpirVOnIndex( ::ast::Shader const & shader
			, ::ast::EntryPointConfigArray const & entryPoints
			, ::ast::SpecialisationInfo const & specialisation
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
							astOn( printEntryPoint( entryPoint ) );
							auto allocator = testCounts.allocator.getBlock();
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
									extensions.emplace( spirv::EXT_shader_atomic_float_add );
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
									extensions.emplace( spirv::EXT_fragment_shader_interlock );
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

							auto [statements, shaderModule] = generateModule( shader, entryPoint, config, testCounts );
							auto textSpirv = generateTextSpirV( *shaderModule, testCounts );

							if ( textSpirv.empty() )
							{
								testCounts.printBlock( "Empty shader" );
								return;
							}

							std::vector< uint32_t > spirv;
							auto print = printShader( "SPIR-V", textSpirv, false );
							try
							{
								spirv = generateBinarySpirV( *shaderModule, testCounts );
								SUCCEED();

								if ( compilers.forceDisplay )
								{
									testCounts.printBlock( print );
								}
							}
							catch ( ... )
							{
								testCounts.printError( print );
								throw;
							}

							try
							{
								validateSpirV( shader
									, statements.get()
									, entryPoint.stage
									, spirv
									, textSpirv
									, specialisation
									, testCounts
									, infoIndex
									, compilers
									, config.requiredExtensions );
								SUCCEED();
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
									testCounts.printError( "spirv_cross exception:\n" + text + "\n" + print );
									throw;
								}
							}
#endif
							catch ( std::exception & )
							{
								testCounts.printError( "testWriteSpirV" );
								throw;
							}
						}
					}
					catch ( std::exception & exc )
					{
						testCounts.printBlock( exc.what() );
					}
					catch ( ... )
					{
						testCounts.printBlock( "Unknown exception" );
					}
				};
				astOn( "Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
					+ " - SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) ) );
				astCheckNoThrow( validate( false ) )
				astCheckNoThrow( validate( true ) )
			}

#endif
		}

		uint32_t getSpvMajor( uint32_t spvVersion )
		{
			return ( spvVersion >> 16u );
		}

		uint32_t getSpvMinor( uint32_t spvVersion )
		{
			return ( ( spvVersion >> 8u ) & 0xFF );
		}
	}

	std::string validateSpirVToGlsl( std::vector< uint32_t > const & spirv
		, ast::ShaderStage stage
		, test::TestCounts & testCounts
		, bool vulkanSemantics )
	{
		auto compiler = std::make_unique< spirv_cross::CompilerGLSL >( spirv );
		std::string result;

		if ( spv_test::setEntryPoint( stage, *compiler ) != spv::ExecutionModelMax )
		{
			spv_test::setupOptions( stage, vulkanSemantics, *compiler );
			result = spv_test::compileSpirV( "GLSL", *compiler, testCounts );
		}

		return result;
	}

	std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
		, ast::ShaderStage stage
		, test::TestCounts & testCounts )
	{
		auto compiler = std::make_unique< spirv_cross::CompilerHLSL >( spirv );
		std::string result;

		if ( spv_test::setEntryPoint( stage, *compiler ) != spv::ExecutionModelMax )
		{
			spv_test::setupHlslOptions( *compiler );
			spv_test::setupOptions( stage, false, *compiler );
			result = spv_test::compileSpirV( "HLSL", *compiler, testCounts );
		}

		return result;
	}

	std::string printSpvVersion( uint32_t spvVersion )
	{
		std::stringstream stream;
		stream << spv_test::getSpvMajor( spvVersion ) << "." << spv_test::getSpvMinor( spvVersion );
		return stream.str();
	}

	void testWriteSpirV( ::ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
		if ( compilers.spirV )
		{
			auto count = testCounts.getSpirvInfosSize();
			for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
			{
#if SDW_Test_SpirVAllDebugLevels
				spv_test::testWriteSpirVOnIndex( shader
					, entryPoints
					, specialisation
					, compilers
					, testCounts
					, spirv::DebugLevel::eNone
					, infoIndex );
				spv_test::testWriteSpirVOnIndex( shader
					, entryPoints
					, specialisation
					, compilers
					, testCounts
					, spirv::DebugLevel::eNames
					, infoIndex );
#endif
				spv_test::testWriteSpirVOnIndex( shader
					, entryPoints
					, specialisation
					, compilers
					, testCounts
					, spirv::DebugLevel::eDebugInfo
					, infoIndex );
			}
		}
	}

	void testValidateSpirV( ast::Shader const & shader
		, ast::EntryPointConfigArray const & entryPoints
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
		if ( compilers.spirV )
		{
			auto count = testCounts.getSpirvInfosSize();
			for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
			{
				validateShaderOnIndex( shader
					, entryPoints
					, testCounts
					, infoIndex
					, compilers );
			}
		}
	}

	void testValidateSpirV( ::ast::ShaderArray const & shaders
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
#if SDW_Test_HasVulkan && SDW_HasCompilerSpirV && SDW_HasVulkanLayer
		auto shadersSpan = ast::vk::convert( shaders );
		auto count = testCounts.getSpirvInfosSize();
		for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
		{
			validateShaderOnIndex( shadersSpan, testCounts, infoIndex, compilers );
		}
#endif
	}

	void testValidateSpirV( ::ast::ShaderPtrArray const & shaders
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
#if SDW_Test_HasVulkan && SDW_HasCompilerSpirV && SDW_HasVulkanLayer
		auto shadersSpan = ast::vk::convert( shaders );
		auto count = testCounts.getSpirvInfosSize();
		for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
		{
			validateShaderOnIndex( shadersSpan, testCounts, infoIndex, compilers );
		}
#endif
	}
}
