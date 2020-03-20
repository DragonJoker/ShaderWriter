/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterSpirV_H___
#define ___SDW_WriterSpirV_H___

#include <ShaderAST/ShaderASTPrerequisites.hpp>

#include <vector>

#if defined( CompilerSpirV_Static )
#	define SDWSPIRV_API
#elif defined( _WIN32 )
#	if defined( CompilerSpirV_Exports )
#		define SDWSPIRV_API __declspec( dllexport )
#	else
#		define SDWSPIRV_API __declspec( dllimport )
#	endif
#else
#	define SDWSPIRV_API
#endif

namespace spirv
{
	SDWSPIRV_API std::string writeSpirv( ast::Shader const & shader
		, bool writeHeader = true );
	SDWSPIRV_API std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader );
}

#endif
