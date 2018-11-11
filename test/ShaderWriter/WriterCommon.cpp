#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

#include "spirv_cpp.hpp"
#include "spirv_cross_util.hpp"
#include "spirv_glsl.hpp"
#include "spirv_hlsl.hpp"

namespace test
{
	bool compileHlsl( std::string const & shader
		, sdw::ShaderType type );

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

		std::string compileSpirV( spirv_cross::Compiler & compiler )
		{
			std::string result;
			try
			{
				result = compiler.compile();
			}
			catch ( std::exception & exc )
			{
				std::cerr << "Shader compilation failed: " << exc.what();
				throw;
			}
			catch ( ... )
			{
				std::cerr << "Shader compilation failed: Unknown error";
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
			std::string glsl;
			checkNoThrow( glsl = compileSpirV( *compiler ) );
			return glsl;
		}

		std::string validateSpirVToHlsl( std::vector< uint32_t > const & spirv
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto compiler = std::make_unique< spirv_cross::CompilerHLSL >( spirv );
			doSetEntryPoint( stage, *compiler );
			doSetupHlslOptions( *compiler );
			doSetupOptions( *compiler );
			std::string hlsl;
			checkNoThrow( hlsl = compileSpirV( *compiler ) );
			return hlsl;
		}

		void validateSpirV( std::vector< uint32_t > const & spirv
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto crossGlsl = test::validateSpirVToGlsl( spirv, stage, testCounts );
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << "// SPIRV-Cross GLSL" << std::endl;
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << std::endl << crossGlsl << std::endl;
			auto crossHlsl = test::validateSpirVToHlsl( spirv, stage, testCounts );
			//check( compileHlsl( crossHlsl, stage ) );
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << "// SPIRV-Cross HLSL" << std::endl;
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << std::endl << crossHlsl << std::endl;
		}

		void testWriteDebug( sdw::Shader const & shader
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto debug = sdw::writeDebug( shader );
			std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			std::cout << "// Statements" << std::endl;
			std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			std::cout << std::endl << debug << std::endl;
		}

		void testWriteGlsl( sdw::Shader const & shader
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto glsl = sdw::writeGlsl( shader, stage );
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << "// GLSL" << std::endl;
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << std::endl << glsl << std::endl;
		}

		void testWriteHlsl( sdw::Shader const & shader
			, sdw::ShaderType stage
			, test::TestCounts & testCounts )
		{
			auto hlsl = sdw::writeHlsl( shader, stage );
			check( compileHlsl( hlsl, stage ) );
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << "// HLSL" << std::endl;
			//std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			//std::cout << std::endl << hlsl << std::endl;
		}

		void testWriteSpirV( sdw::Shader const & shader
			, sdw::ShaderType stage
			, bool validateSpirV
			, test::TestCounts & testCounts )
		{
			auto textSpirv = sdw::writeSpirv( shader, stage, false );
			std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			std::cout << "// SPIR-V" << std::endl;
			std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			std::cout << std::endl << textSpirv << std::endl;

			if ( validateSpirV )
			{
				test::validateSpirV( sdw::serializeSpirv( shader, stage )
					, stage
					, testCounts );
			}
		}
	}

	void writeShader( sdw::Shader const & shader
		, sdw::ShaderType stage
		, test::TestCounts & testCounts
		, bool validateSpirV )
	{
		checkNoThrow( testWriteDebug( shader, stage, testCounts ) );
		checkNoThrow( testWriteSpirV( shader, stage, validateSpirV, testCounts ) );
		checkNoThrow( testWriteGlsl( shader, stage, testCounts ) );
		checkNoThrow( testWriteHlsl( shader, stage, testCounts ) );
	}
}
