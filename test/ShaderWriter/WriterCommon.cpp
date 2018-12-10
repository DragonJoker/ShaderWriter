#include "WriterCommon.hpp"

#include "CompileGLSL.hpp"
#include "CompileHLSL.hpp"
#include "CompileSPIRV.hpp"

#include <CompilerGlsl/compileGlsl.hpp>
#include <CompilerHlsl/compileHlsl.hpp>
#include <CompilerSpirV/compileSpirV.hpp>
#include <CompilerSpirV/SpirvModule.hpp>

#include "spirv_cpp.hpp"
#include "spirv_cross_util.hpp"
#include "spirv_glsl.hpp"
#include "spirv_hlsl.hpp"

#define SDW_Test_DisplayShaders 0

namespace test
{
	namespace
	{
		std::string getName( ::sdw::ShaderType stage )
		{
			switch ( stage )
			{
			case ::sdw::ShaderType::eVertex:
				return "Vertex";
			case ::sdw::ShaderType::eGeometry:
				return "Geometry";
			case ::sdw::ShaderType::eTessellationControl:
				return "TessellationControl";
			case ::sdw::ShaderType::eTessellationEvaluation:
				return "TessellationEvaluation";
			case ::sdw::ShaderType::eFragment:
				return "Fragment";
			case ::sdw::ShaderType::eCompute:
				return "Compute";
			default:
				assert( false && "Unsupported shader stage flag" );
				return "Undefined";
			}
		}
		
		spv::ExecutionModel getExecutionModel( ::sdw::ShaderType stage )
		{
			spv::ExecutionModel result{};

			switch ( stage )
			{
			case ::sdw::ShaderType::eVertex:
				result = spv::ExecutionModelVertex;
				break;
			case ::sdw::ShaderType::eGeometry:
				result = spv::ExecutionModelGeometry;
				break;
			case ::sdw::ShaderType::eTessellationControl:
				result = spv::ExecutionModelTessellationControl;
				break;
			case ::sdw::ShaderType::eTessellationEvaluation:
				result = spv::ExecutionModelTessellationEvaluation;
				break;
			case ::sdw::ShaderType::eFragment:
				result = spv::ExecutionModelFragment;
				break;
			case ::sdw::ShaderType::eCompute:
				result = spv::ExecutionModelGLCompute;
				break;
			default:
				assert( false && "Unsupported shader stage flag" );
				break;
			}

			return result;
		}

		void doSetEntryPoint( ::sdw::ShaderType stage
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

		void doSetupOptions( spirv_cross::CompilerGLSL & compiler )
		{
			auto options = compiler.get_common_options();
			options.vulkan_semantics = true;
			compiler.set_common_options( options );
		}

		void doSetupHlslOptions( spirv_cross::CompilerHLSL & compiler )
		{
			auto options = compiler.get_hlsl_options();
			options.shader_model = 50;
			compiler.set_hlsl_options( options );
		}

		std::string compileSpirV( std::string const & language
			, spirv_cross::Compiler & compiler )
		{
			std::string result;
			try
			{
				result = compiler.compile();
			}
			catch ( spirv_cross::CompilerError & exc )
			{
				std::cout << "SPIRV-Cross(" << language << "), shader compilation failed: " << exc.what() << std::endl;
				throw;
			}
			catch ( std::exception & exc )
			{
				std::cout << "SPIRV-Cross(" << language << "), shader compilation failed: " << exc.what() << std::endl;
				throw;
			}
			catch ( ... )
			{
				std::cout << "SPIRV-Cross(" << language << "), shader compilation failed: Unknown error" << std::endl;
				throw;
			}

			return result;
		}

		std::string validateSpirVToGlsl( std::vector< uint32_t > const & spirv
			, ::sdw::ShaderType stage
			, sdw_test::TestCounts & testCounts )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerGLSL >( spirv );
			doSetEntryPoint( stage, *compiler );
			doSetupOptions( *compiler );
			return compileSpirV( "HLSL", *compiler );
		}

		std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
			, ::sdw::ShaderType stage
			, sdw_test::TestCounts & testCounts )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerHLSL >( spirv );
			doSetEntryPoint( stage, *compiler );
			doSetupHlslOptions( *compiler );
			doSetupOptions( *compiler );
			return compileSpirV( "HLSL", *compiler );
		}

		void displayShader( std::string const & name
			, std::string const & shader
			, bool force = false )
		{
			if ( force || SDW_Test_DisplayShaders )
			{
				std::cout << "////////////////////////////////////////////////////////////" << std::endl;
				std::cout << "// " << name << std::endl;
				std::cout << "////////////////////////////////////////////////////////////" << std::endl;
				std::cout << std::endl << shader << std::endl;
			}
		}

		bool validateSpirV( ::sdw::Shader const & shader
			, std::vector< uint32_t > spirv
			, std::string const & text
			, sdw_test::TestCounts & testCounts
			, bool checkRef )
		{
			std::string errors;
			auto result = test::compileSpirV( shader, spirv, errors, testCounts );

			if ( !errors.empty() )
			{
				std::cout << "VkShaderModule creation raised messages:" << std::endl;
				std::cout << errors << std::endl;
				checkRef = checkRef
					&& ( errors.find( "Capability SampledRect is not allowed by Vulkan 1.1" ) == std::string::npos
						&& errors.find( "Capability ImageRect is not allowed by Vulkan 1.1" ) == std::string::npos );

				if ( checkRef )
				{
					failure( "compileSpirV( spirv, stage )" );
					auto fileName = getExecutableDirectory() + testCounts.testName + std::to_string( testCounts.totalCount ) + ".spv";
					FILE * fileOut = fopen( fileName.c_str(), "wb" );

					if ( fileOut )
					{
						fwrite( spirv.data()
							, sizeof( uint32_t )
							, spirv.size()
							, fileOut );
						fclose( fileOut );
					}

					auto moduleOut = spirv::Module::deserialize( spirv );
					fileName = getExecutableDirectory() + testCounts.testName + std::to_string( testCounts.totalCount ) + ".ref.spv";
					FILE * fileIn = fopen( fileName.c_str(), "rb" );

					if ( fileIn )
					{
						fseek( fileIn, 0, SEEK_END );
						auto size = ftell( fileIn );
						fseek( fileIn, 0, SEEK_SET );

						if ( size > 0 && ( size % sizeof( uint32_t ) ) == 0 )
						{
							spirv.resize( size / sizeof( uint32_t ) );
							fread( spirv.data()
								, sizeof( uint32_t )
								, spirv.size()
								, fileIn );
						}

						fclose( fileIn );
						validateSpirV( shader, spirv, errors, testCounts, false );
						auto moduleIn = spirv::Module::deserialize( spirv );
					}
				}
			}

			return result;
		}

		void validateSpirV( ::sdw::Shader const & shader
			, std::vector< uint32_t > spirv
			, std::string const & text
			, bool validateHlsl
			, bool validateGlsl
			, sdw_test::TestCounts & testCounts )
		{
			if ( validateSpirV( shader, spirv, text, testCounts, true ) )
			{
				if ( validateGlsl )
				{
					auto crossGlsl = test::validateSpirVToGlsl( spirv, shader.getType(), testCounts );
					displayShader( "SPIRV-Cross GLSL", crossGlsl );
				}

				if ( validateHlsl )
				{
					auto crossHlsl = test::validateSpirVToHlsl( spirv, shader.getType(), testCounts );
					displayShader( "SPIRV-Cross HLSL", crossHlsl );
				}
			}
			else
			{
				displayShader( "SPIR-V", text, true );
			}
		}

		void testWriteDebug( ::sdw::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, sdw_test::TestCounts & testCounts )
		{
			auto debug = ::sdw::writeDebug( shader );
			displayShader( "Statements", debug );
		}

		void testWriteGlsl( ::sdw::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, bool validateGlsl
			, sdw_test::TestCounts & testCounts )
		{
			std::string errors;
			auto glsl = glsl::compileGlsl( shader
				, specialisation
				, glsl::GlslConfig{} );

			if ( validateGlsl && !compileGlsl( glsl
				, shader.getType()
				, errors
				, testCounts ) )
			{
				displayShader( "GLSL", glsl, true );
				std::cout << errors << std::endl;
				failure( "compileGlsl( glsl, stage )" );
			}
			else
			{
				displayShader( "GLSL", glsl );
			}
		}

		void testWriteHlsl( ::sdw::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, bool validateHlsl
			, sdw_test::TestCounts & testCounts )
		{
			std::string errors;
			auto hlsl = hlsl::compileHlsl( shader, specialisation );

			if ( validateHlsl && !compileHlsl( hlsl
				, shader.getType()
				, errors
				, testCounts ) )
			{
				displayShader( "HLSL", hlsl, true );
				std::cout << errors << std::endl;
				failure( "compileHlsl( hlsl, stage )" );
			}
			else
			{
				displayShader( "HLSL", hlsl );
			}
		}

		void testWriteSpirV( ::sdw::Shader const & shader
			, ::sdw::SpecialisationInfo const & specialisation
			, bool validateSpirV
			, bool validateHlsl
			, bool validateGlsl
			, sdw_test::TestCounts & testCounts )
		{
			auto textSpirv = spirv::writeSpirv( shader );
			displayShader( "SPIR-V", textSpirv );
			std::vector< uint32_t > spirv;

			try
			{
				spirv = spirv::serialiseSpirv( shader );
			}
			catch ( ... )
			{
				displayShader( "SPIR-V", textSpirv, true );
				throw;
			}

			if ( validateSpirV )
			{
				try
				{
					test::validateSpirV( shader
						, spirv
						, textSpirv
						, validateHlsl
						, validateGlsl
						, testCounts );
				}
				catch ( spirv_cross::CompilerError & exc )
				{
					std::string text = exc.what();

					if ( text.find( "not supported in HLSL" ) == std::string::npos
						&& text.find( "not supported on HLSL" ) == std::string::npos
						&& text.find( "exist in HLSL" ) == std::string::npos )
					{
						displayShader( "SPIR-V", textSpirv, true );
					}
				}
				catch ( std::exception & exc )
				{
					displayShader( "SPIR-V", textSpirv, true );
					std::cout << exc.what() << std::endl;
				}
			}
		}

		std::vector< uint8_t > getSpecData( ::sdw::SpecConstantInfo const & info )
		{
			return std::vector< uint8_t >( size_t( getSize( info.type
					, ast::type::MemoryLayout::eStd430 ) )
				, 0 );
		}

		::sdw::SpecialisationInfo getSpecialisationInfo( ::sdw::Shader const & shader )
		{
			auto & specInfo = shader.getSpecConstants();
			::sdw::SpecialisationInfo result;

			for ( auto & info : specInfo )
			{
				result.data.push_back( { info.second, getSpecData( info.second ) } );
			}

			return result;
		}
	}

	namespace sdw_test
	{
		void TestCounts::initialise( std::string const & name )
		{
			test::TestCounts::initialise( name );
			createGLSLContext( *this );
			createHLSLContext( *this );
			createSPIRVContext( *this );
		}

		void TestCounts::cleanup()
		{
			destroySPIRVContext( *this );
			destroyHLSLContext( *this );
			destroyGLSLContext( *this );
			test::TestCounts::cleanup();
		}
	}

	void writeShader( ::sdw::ShaderWriter const & writer
		, sdw_test::TestCounts & testCounts
		, bool validateSpirV
		, bool validateHlsl
		, bool validateGlsl )
	{
		auto specialisation = getSpecialisationInfo( writer.getShader() );
		checkNoThrow( testWriteDebug( writer.getShader(), specialisation, testCounts ) );
		checkNoThrow( testWriteSpirV( writer.getShader(), specialisation, validateSpirV, validateHlsl, validateGlsl, testCounts ) );
		checkNoThrow( testWriteGlsl( writer.getShader(), specialisation, validateGlsl, testCounts ) );
		checkNoThrow( testWriteHlsl( writer.getShader(), specialisation, validateHlsl, testCounts ) );
	}
}
