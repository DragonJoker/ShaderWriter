#include "WriterCommonSpirV.hpp"

#include "CompileGLSL.hpp"
#include "CompileSPIRV.hpp"
#include "GlslToSpv.hpp"
#include "WriterCommonVulkanLayer.hpp"

#include <ShaderAST/Visitors/PreprocessShader.hpp>
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

		static spv::ExecutionModel getExecutionModel( ast::ShaderStage stage )
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
#	if SPV_VERSION >= 0x10600
				result = spv::ExecutionModelTaskEXT;
#	else
				result = spv::ExecutionModelTaskNV;
#	endif
				break;
			case ast::ShaderStage::eMeshNV:
				result = spv::ExecutionModelMax;
				break;
			case ast::ShaderStage::eMesh:
#	if SPV_VERSION >= 0x10600
				result = spv::ExecutionModelMeshEXT;
#	else
				result = spv::ExecutionModelMax;
#	endif
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
#	if !SDAST_ExceptAssert
				result = spv::ExecutionModelMax;
#	endif
				break;
			}

			return result;
		}

		static spv::ExecutionModel setEntryPoint( ast::ShaderStage stage
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

		static void setupOptions( ast::ShaderStage stage
			, bool vulkanSemantics
			, spirv_cross::CompilerGLSL & compiler )
		{
			auto options = compiler.get_common_options();
			options.separate_shader_objects = true;
			options.vulkan_semantics = vulkanSemantics || isRayTraceStage( stage );
			compiler.set_common_options( options );
		}

		static void setupHlslOptions( spirv_cross::CompilerHLSL & compiler )
		{
			auto options = compiler.get_hlsl_options();
			options.shader_model = 60;
			compiler.set_hlsl_options( options );
		}

		static std::string compileSpirV( std::string_view language
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

		static std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
			, ast::ShaderStage stage
			, test::TestCounts & testCounts
			, Compilers const & compilers
			, spirv::SpirVExtensionSet const & requiredExtensions )
		{
			std::string result;

			if ( compilers.hlsl.enable
				&& !isRayTraceStage( stage )
				&& !isMeshStage( stage )
				&& requiredExtensions.contains( spirv::KHR_terminate_invocation )
				&& requiredExtensions.contains( spirv::EXT_demote_to_helper_invocation ) )
			{
				auto compiler = std::make_unique< spirv_cross::CompilerHLSL >( spirv );

				if ( spv_test::setEntryPoint( stage, *compiler ) != spv::ExecutionModelMax )
				{
					spv_test::setupHlslOptions( *compiler );
					spv_test::setupOptions( stage, false, *compiler );
					result = spv_test::compileSpirV( "HLSL", *compiler, testCounts );
				}
			}

			return result;
		}

		static std::string validateSpirVToGlsl( std::vector< uint32_t > const & spirv
			, ast::ShaderStage stage
			, test::TestCounts & testCounts
			, Compilers const & compilers
			, spirv::SpirVExtensionSet const & requiredExtensions )
		{
			std::string result;

			if ( compilers.glsl.enable
				&& requiredExtensions.contains( spirv::KHR_terminate_invocation ) )
			{
				result = sdw_test::validateSpirVToGlsl( spirv, stage, testCounts, true );
			}

			return result;
		}

#endif

		static bool validateGeneratedSpirV( ::ast::Shader const & shader
			, ::ast::stmt::Container * statements
			, ::ast::ShaderStage stage
			, std::vector< uint32_t > spirv
			, sdw_test::TestCounts & testCounts
			, ::ast::SpecialisationInfo const & specialisation
			, uint32_t infoIndex
			, bool availableExtensions
			, std::string & errors )
		{
			std::string compileErrors;
			auto result = test::compileSpirV( shader, spirv, compileErrors, testCounts, infoIndex );
			if ( !compileErrors.empty() )
				errors += "VkShaderModule creation raised messages, for CompilerSpv output:\n" + compileErrors + "\n";

			if ( !compileErrors.empty() )
			{
				result = false;
				auto fileName = getExecutableDirectory() + testCounts.testName + std::to_string( uintptr_t( statements ) ) + ".spv";

				if ( FILE * fileOut = fopen( fileName.c_str(), "wb" ) )
				{
					fwrite( spirv.data()
						, sizeof( uint32_t )
						, spirv.size()
						, fileOut );
					fclose( fileOut );
				}

				if ( availableExtensions && !isRayTraceStage( stage ) )
				{
					try
					{
						auto cfg = getGlslConfig( glsl::v4_6, testCounts );
						if ( auto glslangSpirv = compileGlslToSpv( stage
							, glsl::compileGlsl( *testCounts.allocatorBlock
								, shader
								, statements
								, stage
								, specialisation
								, cfg )
							, retrieveSPIRVVersion( testCounts, infoIndex ) );
							!glslangSpirv.empty() )
						{
							std::string glslangCompileErrors;
							if ( test::compileSpirV( shader, glslangSpirv, glslangCompileErrors, testCounts, infoIndex ) )
							{
								auto parsedShader = spirv::displaySpirv( *testCounts.allocatorBlock, glslangSpirv );
								errors += "glslang generated SPIR-V:\n"
									+ parsedShader;
							}
						}
					}
					catch ( std::exception & )
					{
						// Optional step, do nothing on error.
					}
				}
			}

			return result;
		}

		static bool toolsValidateSpirV( std::vector< uint32_t > const & spirv
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, std::string & errors )
		{
#if SDW_Test_HasSpirVTools
			std::string spvToolsErrors;
			auto consumer = [&spvToolsErrors]( [[maybe_unused]] spv_message_level_t level
				, [[maybe_unused]] char const * source
				, spv_position_t position
				, char const * message )
				{
					spvToolsErrors += "Index " + std::to_string( position.index ) + ": " + message + std::string{ "\n" };
				};

			spvtools::SpirvTools tools{ spv_target_env( getSpirVTargetEnv( testCounts, infoIndex ) ) };
			tools.SetMessageConsumer( consumer );
			spvtools::ValidatorOptions valOptions;
			valOptions.SetScalarBlockLayout( true );
			auto result = tools.Validate( spirv.data(), spirv.size(), valOptions );
			if ( !spvToolsErrors.empty() )
				errors += "SPIR-V validation raised messages:\n" + spvToolsErrors;
			return result;
#else
			return true;
#endif
		}

		static bool validateSpirV( ::ast::Shader const & shader
			, ::ast::stmt::Container * statements
			, ::ast::ShaderStage stage
			, std::vector< uint32_t > const & spirv
			, std::string const & text
			, ::ast::SpecialisationInfo const & specialisation
			, sdw_test::TestCounts & testCounts
			, uint32_t infoIndex
			, Compilers const & compilers
			, bool availableExtensions
			, spirv::SpirVExtensionSet const & requiredExtensions
			, std::string & errors )
		{
			std::string validateErrors;
			auto isValidated = validateGeneratedSpirV( shader, statements, stage, spirv, testCounts, specialisation, infoIndex, availableExtensions, validateErrors );
			if ( !isValidated )
				errors += validateErrors;

			std::string toolsErrors;
			auto isToolsValidated = toolsValidateSpirV( spirv, testCounts, infoIndex, toolsErrors );
			if ( !isToolsValidated )
				errors += toolsErrors;

#if SDW_Test_HasSpirVCross

			if ( auto crossGlsl = validateSpirVToGlsl( spirv, stage, testCounts, compilers, requiredExtensions );
				!crossGlsl.empty() )
			{
				errors += printShader( "SPIRV-Cross GLSL", crossGlsl, true );
			}

			if ( auto crossHlsl = validateSpirVToHlsl( spirv, stage, testCounts, compilers, requiredExtensions );
				!crossHlsl.empty() )
			{
				errors += printShader( "SPIRV-Cross HLSL", crossHlsl, true );
			}

#endif
			astCheckNoThrow( spirv::parseSpirv( shader.getAllocator(), stage, spirv ) )

			return isValidated && isToolsValidated;
		}

		static spirv::ModulePtr generateModule( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, ::ast::ShaderStage stage
			, spirv::SpirVConfig & config
			, TestCounts & testCounts )
		{
			auto timerBlock = testCounts.beginTimer( "generateSpirV" );
			auto shaderModule = spirv::compilePreprocessedSpirV( *testCounts.allocatorBlock
				, shader
				, preprocessResult
				, stage
				, config );
			return shaderModule;
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

		static std::string getDebugLevelName( spirv::DebugLevel debugLevel )
		{
			switch ( debugLevel )
			{
			case spirv::DebugLevel::eNames:
				return "Names";
			case spirv::DebugLevel::eDebugInfo:
				return "DebugInfo";
			default:
				return "None";
			}
		}

		static void testWriteSpirVOnIndex( ::ast::Shader const & shader
			, ::ast::PreprocessResult & preprocessResult
			, ::ast::ShaderStage stage
			, ::ast::SpecialisationInfo const & specialisation
			, Compilers const & compilers
			, sdw_test::TestCounts & testCounts
			, spirv::DebugLevel debugLevel
			, uint32_t infoIndex )
		{
#if SDW_HasCompilerSpirV

			if ( testCounts.isSpirVInitialised( infoIndex )
				&& !testCounts.isSpvIgnored( infoIndex, compilers.spirV.ignoredSpv )
				&& testCounts.isSpvRequested( infoIndex, compilers.spirV.requestedSpv )
				&& testCounts.isVulkanRequested( infoIndex, compilers.spirV.requestedVulkan )
				&& ( compilers.spirV.requestedDebugLevel == ~0u
					|| compilers.spirV.requestedDebugLevel == uint32_t( debugLevel ) ) )
			{
				auto validate = [&]( bool availableExtensions )
					{
						bool error{};
						try
						{
							auto allocator = testCounts.allocator.getBlock();
							spirv::SpirVConfig config;
							config.specVersion = testCounts.getSpirVVersion( infoIndex );
							config.debugLevel = debugLevel;
							spirv::SpirVExtensionSet extension;

							if ( availableExtensions )
							{
								extension = getSpirVExtensions( config, testCounts, infoIndex );
								config.availableExtensions = &extension;
							}

							auto shaderModule = generateModule( shader, preprocessResult, stage, config, testCounts );
							auto textSpirv = generateTextSpirV( *shaderModule, testCounts );

							if ( textSpirv.empty() )
							{
								error = true;
								throw std::runtime_error{ "Empty shader" };
							}

							std::vector< uint32_t > spirv;
							auto print = printShader( "SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) )
									+ " - Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
									+ " - Debug " + getDebugLevelName( debugLevel )
								, textSpirv, false );
							try
							{
								spirv = generateBinarySpirV( *shaderModule, testCounts );
								SUCCEED();
							}
							catch ( ... )
							{
								testCounts.printError( print );
								throw;
							}

							try
							{
								if ( std::string errors;
									!validateSpirV( shader
										, preprocessResult.statements.get()
										, stage
										, spirv
										, textSpirv
										, specialisation
										, testCounts
										, infoIndex
										, compilers
										, availableExtensions
										, config.requiredExtensions
										, errors ) )
								{
									error = ( errors.find( "VK_AMD_gpu_shader_half_float" ) == std::string::npos
										&& errors.find( "useless application of layout qualifier" ) == std::string::npos );
									throw std::runtime_error{ errors };
								}

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
									if ( availableExtensions )
										testCounts.printBlock( print );
									error = true;
									throw std::runtime_error{ "spirv_cross exception:\n" + text };
								}
							}
#endif
							catch ( std::exception & exc )
							{
								if ( availableExtensions )
									throw std::runtime_error{ print + exc.what() };
								throw;
							}

							if ( compilers.forceDisplay && availableExtensions )
								testCounts.printBlock( print );
						}
						catch ( spirv::UnsupportedExtensionException & )
						{
							return;
						}
						catch ( std::exception & exc )
						{
							if ( error )
								testCounts.printError( exc.what() );
							else
								testCounts.printBlock( exc.what() );
						}
						catch ( ... )
						{
							testCounts.printError( "Unknown exception" );
						}
					};
				astOn( "Vulkan " + printVkVersion( testCounts.getVulkanVersion( infoIndex ) )
					+ " - SPIR-V " + printSpvVersion( testCounts.getSpirVVersion( infoIndex ) )
					+ " - Debug " + getDebugLevelName( debugLevel ) );
				astCheckNoThrow( validate( true ) )
			}

#endif
		}

		static uint32_t getSpvMajor( uint32_t spvVersion )
		{
			return ( spvVersion >> 16u );
		}

		static uint32_t getSpvMinor( uint32_t spvVersion )
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

	std::string printSpvVersion( uint32_t spvVersion )
	{
		std::stringstream stream;
		stream << spv_test::getSpvMajor( spvVersion ) << "." << spv_test::getSpvMinor( spvVersion );
		return stream.str();
	}

	void testWriteSpirV( ::ast::Shader const & shader
		, ::ast::PreprocessResult & preprocessResult
		, ::ast::ShaderStage stage
		, ::ast::SpecialisationInfo const & specialisation
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
		if ( compilers.spirV.enable )
		{
			auto count = testCounts.getSpirvInfosSize();
			for ( uint32_t infoIndex = 0u; infoIndex < count; ++infoIndex )
			{
#if SDW_Test_SpirVAllDebugLevels
				spv_test::testWriteSpirVOnIndex( shader
					, preprocessResult
					, stage
					, specialisation
					, compilers
					, testCounts
					, spirv::DebugLevel::eNone
					, infoIndex );
				spv_test::testWriteSpirVOnIndex( shader
					, preprocessResult
					, stage
					, specialisation
					, compilers
					, testCounts
					, spirv::DebugLevel::eNames
					, infoIndex );
#endif
				spv_test::testWriteSpirVOnIndex( shader
					, preprocessResult
					, stage
					, specialisation
					, compilers
					, testCounts
					, spirv::DebugLevel::eDebugInfo
					, infoIndex );
			}
		}
	}

	void testValidateSpirV( ast::Shader const & shader
		, ::ast::EntryPointConfigArray const & entryPoints
		, Compilers const & compilers
		, sdw_test::TestCounts & testCounts )
	{
#if SDW_Test_HasVulkan && SDW_HasVulkanLayer
		if ( compilers.spirV.enable )
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
#endif
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
