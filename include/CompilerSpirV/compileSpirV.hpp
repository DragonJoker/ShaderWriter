/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterSpirV_H___
#define ___SDW_WriterSpirV_H___

#include <ShaderAST/ShaderASTPrerequisites.hpp>

#include <set>
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
	constexpr uint32_t makeVersion( uint8_t major, uint8_t minor )
	{
		return ( uint32_t( major ) << 16u )
			| ( uint32_t( minor ) << 8u );
	}

	static uint32_t constexpr vUnk = makeVersion( 0xFFu, 0xFFu );
	static uint32_t constexpr v1_0 = makeVersion( 1u, 0u );
	static uint32_t constexpr v1_1 = makeVersion( 1u, 1u );
	static uint32_t constexpr v1_2 = makeVersion( 1u, 2u );
	static uint32_t constexpr v1_3 = makeVersion( 1u, 3u );
	static uint32_t constexpr v1_4 = makeVersion( 1u, 4u );
	static uint32_t constexpr v1_5 = makeVersion( 1u, 5u );

	struct SpirVExtension
	{
		uint32_t reqVersion{ vUnk };
		uint32_t specVersion{ vUnk };
		uint32_t coreInVersion{ vUnk };
		std::string name{};
	};

	struct CompSpirVExtension
	{
		bool operator()( SpirVExtension const & lhs, SpirVExtension const & rhs )const
		{
			return lhs.name < rhs.name;
		}
	};

	using SpirVExtensionSet = std::set< SpirVExtension, CompSpirVExtension >;

#define makeSpirVExtension( reqVersion, specVersion, coreInVersion, name )\
	static SpirVExtension const name{ reqVersion, specVersion, coreInVersion, "SPV_"#name }

	makeSpirVExtension( v1_0, v1_1, v1_3, KHR_device_group );
	makeSpirVExtension( v1_0, v1_1, v1_3, KHR_shader_draw_parameters );
	makeSpirVExtension( v1_0, v1_1, v1_3, KHR_multiview );
	makeSpirVExtension( v1_0, v1_1, v1_5, KHR_shader_ballot );
	makeSpirVExtension( v1_0, v1_2, v1_5, EXT_shader_viewport_index_layer );
	makeSpirVExtension( v1_0, v1_3, v1_5, EXT_descriptor_indexing );
	makeSpirVExtension( v1_0, v1_1, vUnk, EXT_shader_stencil_export );
	makeSpirVExtension( v1_0, v1_1, vUnk, NV_viewport_array2 );
	makeSpirVExtension( v1_0, v1_1, vUnk, NV_stereo_view_rendering );
	makeSpirVExtension( v1_0, v1_1, vUnk, NVX_multiview_per_view_attributes );
	makeSpirVExtension( v1_0, v1_3, vUnk, NV_mesh_shader );
	makeSpirVExtension( v1_0, v1_4, vUnk, EXT_demote_to_helper_invocation );
	makeSpirVExtension( v1_0, v1_5, vUnk, EXT_shader_atomic_float_add );
	makeSpirVExtension( v1_0, v1_5, vUnk, KHR_ray_query );
	makeSpirVExtension( v1_3, v1_3, v1_5, EXT_physical_storage_buffer );
	makeSpirVExtension( v1_4, v1_5, vUnk, KHR_ray_tracing );

#undef makeSpirVExtension

	struct SpirVConfig
	{
		uint32_t specVersion{ v1_1 };
		SpirVExtensionSet * availableExtensions{};
		// Filled by writeSpirv/serialiseSpirv
		uint32_t requiredVersion{ vUnk };
		SpirVExtensionSet requiredExtensions{};
	};

	SDWSPIRV_API std::string writeSpirv( ast::Shader const & shader
		, SpirVConfig & config
		, bool writeHeader = true );
	SDWSPIRV_API std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, SpirVConfig & config );
	SDWSPIRV_API std::string displaySpirv( std::vector< uint32_t > const & spirv );
	SDWSPIRV_API ast::Shader parseSpirv( ast::ShaderStage stage
		, std::vector< uint32_t > const & spirv );
}

#endif
