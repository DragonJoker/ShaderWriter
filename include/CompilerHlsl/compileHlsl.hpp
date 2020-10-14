/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterHlsl_H___
#define ___SDW_WriterHlsl_H___

#include <ShaderAST/ShaderASTPrerequisites.hpp>

#if defined( CompilerHlsl_Static )
#	define SDWHLSL_API
#elif defined( _WIN32 )
#	if defined( CompilerHlsl_Exports )
#		define SDWHLSL_API __declspec( dllexport )
#	else
#		define SDWHLSL_API __declspec( dllimport )
#	endif
#else
#	define SDWHLSL_API
#endif

namespace hlsl
{
	struct HlslConfig
	{
		ast::ShaderStage shaderStage;
		bool flipVertY{ false };
	};

	SDWHLSL_API std::string compileHlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig );
}

#endif
