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
	constexpr uint32_t makeVersion( uint8_t major, uint8_t minor )
	{
		return ( uint32_t( major ) * 10u
			+ ( uint32_t( minor ) ) );
	}

	static uint32_t constexpr vUnk = makeVersion( 9u, 9u );
	static uint32_t constexpr v4_0 = makeVersion( 4u, 0u );
	static uint32_t constexpr v4_1 = makeVersion( 4u, 1u );
	static uint32_t constexpr v5_0 = makeVersion( 5u, 0u );
	static uint32_t constexpr v5_1 = makeVersion( 5u, 1u );
	static uint32_t constexpr v6_0 = makeVersion( 6u, 0u );
	static uint32_t constexpr v6_1 = makeVersion( 6u, 1u );
	static uint32_t constexpr v6_2 = makeVersion( 6u, 2u );
	static uint32_t constexpr v6_3 = makeVersion( 6u, 3u );
	static uint32_t constexpr v6_4 = makeVersion( 6u, 4u );
	static uint32_t constexpr v6_5 = makeVersion( 6u, 5u );
	static uint32_t constexpr v6_6 = makeVersion( 6u, 6u );

	struct HlslConfig
	{
		uint32_t shaderModel{ v5_0 };
		ast::ShaderStage shaderStage;
		bool flipVertY{ false };
		ast::ShaderAllocator * allocator{};
	};

	SDWHLSL_API std::string compileHlsl( ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig );
	SDWHLSL_API std::string compileHlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, HlslConfig const & writerConfig );
}

#endif
