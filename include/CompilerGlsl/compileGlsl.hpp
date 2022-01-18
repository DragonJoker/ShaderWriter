/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterGlsl_H___
#define ___SDW_WriterGlsl_H___

#include <ShaderAST/ShaderASTPrerequisites.hpp>

#include <set>

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
	constexpr uint32_t makeVersion( uint8_t major, uint8_t minor )
	{
		return ( uint32_t( major ) * 100
			+ ( uint32_t( minor ) * 10u ) );
	}

	static uint32_t constexpr vUnk = makeVersion( 9u, 9u );
	static uint32_t constexpr v1_1 = makeVersion( 1u, 1u );
	static uint32_t constexpr v1_2 = makeVersion( 1u, 2u );
	static uint32_t constexpr v1_3 = makeVersion( 1u, 3u );
	static uint32_t constexpr v1_4 = makeVersion( 1u, 4u );
	static uint32_t constexpr v1_5 = makeVersion( 1u, 5u );
	static uint32_t constexpr v3_3 = makeVersion( 3u, 3u );
	static uint32_t constexpr v4_0 = makeVersion( 4u, 0u );
	static uint32_t constexpr v4_1 = makeVersion( 4u, 1u );
	static uint32_t constexpr v4_2 = makeVersion( 4u, 2u );
	static uint32_t constexpr v4_3 = makeVersion( 4u, 3u );
	static uint32_t constexpr v4_4 = makeVersion( 4u, 4u );
	static uint32_t constexpr v4_5 = makeVersion( 4u, 5u );
	static uint32_t constexpr v4_6 = makeVersion( 4u, 6u );

	struct GlslExtension
	{
		uint32_t reqVersion{ vUnk };
		uint32_t specVersion{ vUnk };
		std::string name{};
	};

	struct CompGlslVExtension
	{
		bool operator()( GlslExtension const & lhs, GlslExtension const & rhs )const
		{
			return lhs.name < rhs.name;
		}
	};

	using GlslExtensionSet = std::set< GlslExtension, CompGlslVExtension >;

#define makeGlExtension( reqVersion, specVersion, name )\
	static GlslExtension const name{ reqVersion, specVersion, "GL_"#name }

	makeGlExtension( v1_4, v1_4, ARB_shader_stencil_export );
	makeGlExtension( v1_4, v1_4, KHR_vulkan_glsl );
	makeGlExtension( v1_4, v1_4, EXT_shader_explicit_arithmetic_types_int64 );
	makeGlExtension( v1_4, v4_5, EXT_multiview );
	makeGlExtension( v1_5, v1_5, ARB_explicit_attrib_location );
	makeGlExtension( v1_5, v1_5, NV_gpu_shader5 );
	makeGlExtension( v4_0, v4_0, ARB_separate_shader_objects );
	makeGlExtension( v4_0, v4_0, ARB_texture_cube_map_array );
	makeGlExtension( v4_0, v4_0, ARB_texture_gather );
	makeGlExtension( v4_2, v4_2, ARB_explicit_uniform_location );
	makeGlExtension( v4_2, v4_2, ARB_shading_language_420pack );
	makeGlExtension( v4_2, v4_2, NV_shader_atomic_float );
	makeGlExtension( v4_3, v4_3, NV_viewport_array2 );
	makeGlExtension( v4_3, v4_3, NV_shader_atomic_fp16_vector );
	makeGlExtension( v4_5, v4_5, ARB_shader_ballot );
	makeGlExtension( v4_5, v4_5, ARB_shader_viewport_layer_array );
	makeGlExtension( v4_5, v4_5, NV_stereo_view_rendering );
	makeGlExtension( v4_5, v4_5, NVX_multiview_per_view_attributes );
	makeGlExtension( v4_5, v4_5, EXT_nonuniform_qualifier );
	makeGlExtension( v4_5, v4_6, EXT_buffer_reference2 );
	makeGlExtension( v4_6, v4_6, EXT_shader_atomic_float );
	makeGlExtension( v4_6, v4_6, EXT_ray_tracing );
	makeGlExtension( v4_6, v4_6, EXT_ray_query );
	makeGlExtension( v4_6, v4_6, EXT_scalar_block_layout );

#undef makeGlExtension

	struct GlslConfig
	{
		ast::ShaderStage shaderStage;
		uint32_t wantedVersion{ v4_3 };
		GlslExtensionSet * availableExtensions{};
		bool vulkanGlsl{ false };
		bool flipVertY{ false };
		bool fixupClipDepth{ false };
		bool hasStd430Layout{ false };
		bool hasShaderStorageBuffers{ false };
		bool hasDescriptorSets{ false };
		bool hasBaseInstance{ false };
		// Filled by writeSpirv/serialiseSpirv
		uint32_t requiredVersion{ vUnk };
		GlslExtensionSet requiredExtensions{};
	};

	SDWGLSL_API std::string compileGlsl( ast::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig const & config );
}

#endif
