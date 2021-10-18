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
	struct SpirVConfig
	{
		static uint32_t constexpr v1_0 = 0x00010000u;
		static uint32_t constexpr v1_1 = 0x00010100u;
		static uint32_t constexpr v1_2 = 0x00010200u;
		static uint32_t constexpr v1_3 = 0x00010300u;
		static uint32_t constexpr v1_4 = 0x00010400u;
		static uint32_t constexpr v1_5 = 0x00010500u;

		uint32_t specVersion{ v1_1 };
	};

	SDWSPIRV_API std::string writeSpirv( ast::Shader const & shader
		, SpirVConfig config
		, bool writeHeader = true );
	SDWSPIRV_API std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, SpirVConfig config );
	SDWSPIRV_API std::string displaySpirv( std::vector< uint32_t > const & spirv );
	SDWSPIRV_API ast::Shader parseSpirv( ast::ShaderStage stage
		, std::vector< uint32_t > const & spirv );
}

#endif
