#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

#include "spirv_cpp.hpp"
#include "spirv_cross_util.hpp"
#include "spirv_glsl.hpp"

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

	std::string validateSpirV( std::vector< uint32_t > const & spirv
		, sdw::ShaderType stage )
	{
		auto compiler = std::make_unique< spirv_cross::CompilerGLSL >( spirv );
		doSetEntryPoint( stage, *compiler );
		doSetupOptions( *compiler );
		std::string glsl;
		checkNoThrow( glsl = compileSpirV( *compiler ) );
		return glsl;
	}

	void writeShader( sdw::Shader const & shader
		, sdw::ShaderType type
		, bool validateSpirV )
	{
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// Statements" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << std::endl << sdw::writeDebug( shader ) << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// GLSL" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << std::endl << sdw::writeGlsl( shader, type ) << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// HLSL" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << std::endl << sdw::writeHlsl( shader, type ) << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "// SPIR-V" << std::endl;
		std::cout << "////////////////////////////////////////////////////////////" << std::endl;
		std::cout << std::endl << sdw::writeSpirv( shader, type, false ) << std::endl;

		if ( validateSpirV )
		{
			std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			std::cout << "// SPIRV-Cross" << std::endl;
			std::cout << "////////////////////////////////////////////////////////////" << std::endl;
			std::cout << std::endl << test::validateSpirV( sdw::serializeSpirv( shader, type ), type ) << std::endl;
		}
	}
}
