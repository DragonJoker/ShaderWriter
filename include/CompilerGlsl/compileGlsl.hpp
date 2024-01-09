/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterGlsl_H___
#define ___SDW_WriterGlsl_H___

#include <ShaderAST/ShaderASTPrerequisites.hpp>
#include <GlslCommon/GlslStatementsHelpers.hpp>

#if defined( CompilerGlsl_Static )
#	define SDWGLSL_API
#elif defined( _WIN32 )
#	if defined( CompilerGlsl_Exports )
#		define SDWGLSL_API __declspec( dllexport )
#	else
#		define SDWGLSL_API __declspec( dllimport )
#	endif
#else
#	define SDWGLSL_API
#endif

namespace glsl
{
	using GlslConfig = StmtConfig;

	SDWGLSL_API std::string compileGlsl( ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config );
	SDWGLSL_API std::string compileGlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig & config );
}

#endif
