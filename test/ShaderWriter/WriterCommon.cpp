#include "WriterCommon.hpp"

#include "CompileGLSL.hpp"
#include "CompileHLSL.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

#include "spirv_cpp.hpp"
#include "spirv_cross_util.hpp"
#include "spirv_glsl.hpp"
#include "spirv_hlsl.hpp"

#define SDW_Test_DisplayShaders 0

namespace test
{
	namespace
	{
		std::string getName( sdw::ShaderType stage )
		{
			switch ( stage )
			{
			case sdw::ShaderType::eVertex:
				return "Vertex";
			case sdw::ShaderType::eGeometry:
				return "Geometry";
			case sdw::ShaderType::eTessellationControl:
				return "TessellationControl";
			case sdw::ShaderType::eTessellationEvaluation:
				return "TessellationEvaluation";
			case sdw::ShaderType::eFragment:
				return "Fragment";
			case sdw::ShaderType::eCompute:
				return "Compute";
			default:
				assert( false && "Unsupported shader stage flag" );
				return "Undefined";
			}
		}
		
		spv::ExecutionModel getExecutionModel( sdw::ShaderType stage )
		{
			spv::ExecutionModel result{};

			switch ( stage )
			{
			case sdw::ShaderType::eVertex:
				result = spv::ExecutionModelVertex;
				break;
			case sdw::ShaderType::eGeometry:
				result = spv::ExecutionModelGeometry;
				break;
			case sdw::ShaderType::eTessellationControl:
				result = spv::ExecutionModelTessellationControl;
				break;
			case sdw::ShaderType::eTessellationEvaluation:
				result = spv::ExecutionModelTessellationEvaluation;
				break;
			case sdw::ShaderType::eFragment:
				result = spv::ExecutionModelFragment;
				break;
			case sdw::ShaderType::eCompute:
				result = spv::ExecutionModelGLCompute;
				break;
			default:
				assert( false && "Unsupported shader stage flag" );
				break;
			}

			return result;
		}

		void doSetEntryPoint( sdw::ShaderType stage
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
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerGLSL >( spirv );
			doSetEntryPoint( stage, *compiler );
			doSetupOptions( *compiler );
			return compileSpirV( "HLSL", *compiler );
		}

		std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
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

		void validateSpirV( std::vector< uint32_t > const & spirv
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto crossGlsl = test::validateSpirVToGlsl( spirv, stage, testCounts );
			displayShader( "SPIRV-Cross GLSL", crossGlsl );
			auto crossHlsl = test::validateSpirVToHlsl( spirv, stage, testCounts );
			displayShader( "SPIRV-Cross HLSL", crossHlsl );
		}

		void testWriteDebug( sdw::Shader const & shader
			, sdw::ShaderType stage
			, sdw::SpecialisationInfo const & specialisation
			, test::TestCounts & testCounts )
		{
			auto debug = sdw::writeDebug( shader );
			displayShader( "Statements", debug );
		}

		void testWriteGlsl( sdw::Shader const & shader
			, sdw::ShaderType stage
			, sdw::SpecialisationInfo const & specialisation
			, bool validateGlsl
			, test::TestCounts & testCounts )
		{
			std::string errors;
			auto glsl = sdw::compileGlsl( shader, stage, specialisation );

			if ( validateGlsl && !compileGlsl( glsl, stage, errors ) )
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

		void testWriteHlsl( sdw::Shader const & shader
			, sdw::ShaderType stage
			, sdw::SpecialisationInfo const & specialisation
			, bool validateHlsl
			, test::TestCounts & testCounts )
		{
			std::string errors;
			auto hlsl = sdw::compileHlsl( shader, stage, specialisation );

			if ( validateHlsl && !compileHlsl( hlsl, stage, errors ) )
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

		void testWriteSpirV( sdw::Shader const & shader
			, sdw::ShaderType stage
			, sdw::SpecialisationInfo const & specialisation
			, bool validateSpirV
			, test::TestCounts & testCounts )
		{
			auto textSpirv = sdw::writeSpirv( shader, stage, true );
			displayShader( "SPIR-V", textSpirv );
			std::vector< uint32_t > spirv;

			try
			{
				spirv = sdw::serialiseSpirv( shader, stage );
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
					test::validateSpirV( spirv
						, stage
						, testCounts );
				}
				catch ( spirv_cross::CompilerError & exc )
				{
					std::string text = exc.what();

					if ( text.find( "is not supported in HLSL" ) == std::string::npos
						&& text.find( "is not supported on HLSL" ) == std::string::npos
						&& text.find( "does not exist in HLSL" ) == std::string::npos )
					{
						displayShader( "SPIR-V", textSpirv, true );
					}
				}
			}
		}

		std::vector< uint8_t > getSpecData( sdw::SpecConstantInfo const & info )
		{
			return std::vector< uint8_t >( size_t( getSize( info.type
					, ast::type::MemoryLayout::eStd430 ) )
				, 0 );
		}

		sdw::SpecialisationInfo getSpecialisationInfo( sdw::Shader const & shader )
		{
			auto & specInfo = shader.getSpecConstants();
			sdw::SpecialisationInfo result;

			for ( auto & info : specInfo )
			{
				result.data.push_back( { info.second, getSpecData( info.second ) } );
			}

			return result;
		}
	}

	void writeShader( sdw::ShaderWriter const & writer
		, test::TestCounts & testCounts
		, bool validateSpirV
		, bool validateHlsl
		, bool validateGlsl )
	{
		auto specialisation = getSpecialisationInfo( writer.getShader() );
		checkNoThrow( testWriteDebug( writer.getShader(), writer.getShaderType(), specialisation, testCounts ) );
		checkNoThrow( testWriteSpirV( writer.getShader(), writer.getShaderType(), specialisation, validateSpirV, testCounts ) );
		checkNoThrow( testWriteGlsl( writer.getShader(), writer.getShaderType(), specialisation, validateGlsl, testCounts ) );
		checkNoThrow( testWriteHlsl( writer.getShader(), writer.getShaderType(), specialisation, validateHlsl, testCounts ) );
	}
}
