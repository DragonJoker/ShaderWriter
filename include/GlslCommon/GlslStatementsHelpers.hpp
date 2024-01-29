/*
See LICENSE file in root folder
*/
#ifndef ___SDW_GlslStatementsHelpers_H___
#define ___SDW_GlslStatementsHelpers_H___
#pragma once

#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

#include <map>
#include <set>
#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 5262 )
#include <sstream>
#pragma warning( pop )

#if defined( GlslCommon_Static )
#	define SDWGLC_API
#elif defined( _WIN32 )
#	if defined( GlslCommon_Exports )
#		define SDWGLC_API __declspec( dllexport )
#	else
#		define SDWGLC_API __declspec( dllimport )
#	endif
#else
#	define SDWGLC_API
#endif

namespace glsl
{
	static uint32_t constexpr InvalidIndex = ~0u;

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
		uint32_t coreVersion{ vUnk };
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

#define makeGlExtension( reqVersion, specVersion, coreVersion, name )\
	static GlslExtension const name{ reqVersion, specVersion, coreVersion, "GL_"#name }

	makeGlExtension( v1_1, v1_1, v4_0, EXT_gpu_shader4 );
	makeGlExtension( v1_1, v1_1, v4_1, EXT_gpu_shader4_1 );
	makeGlExtension( v1_3, v1_3, v4_0, ARB_sample_shading );
	makeGlExtension( v1_3, v1_3, v4_0, ARB_texture_query_lod );
	makeGlExtension( v1_1, v1_1, v4_0, EXT_texture_shadow_lod );
	makeGlExtension( v1_3, v1_3, v4_3, ARB_texture_query_levels );
	makeGlExtension( v1_4, v1_4, v4_2, ARB_shading_language_420pack );
	makeGlExtension( v1_4, v1_4, vUnk, ARB_shader_stencil_export );
	makeGlExtension( v1_4, v4_5, vUnk, KHR_vulkan_glsl );
	makeGlExtension( v1_4, v4_5, vUnk, EXT_multiview );
	makeGlExtension( v1_4, v4_5, vUnk, EXT_shader_explicit_arithmetic_types_int8 );
	makeGlExtension( v1_4, v4_5, vUnk, EXT_shader_explicit_arithmetic_types_int16 );
	makeGlExtension( v1_4, v4_5, vUnk, EXT_shader_explicit_arithmetic_types_int64 );
	makeGlExtension( v1_4, v4_5, vUnk, EXT_demote_to_helper_invocation );
	makeGlExtension( v1_5, v1_5, v4_0, ARB_gpu_shader5 );
	makeGlExtension( v1_5, v1_5, v4_0, ARB_gpu_shader_fp64 );
	makeGlExtension( v1_5, v1_5, v4_0, ARB_tessellation_shader );
	makeGlExtension( v1_5, v1_5, v4_2, ARB_shader_image_load_store );
	makeGlExtension( v1_5, v1_5, v4_3, ARB_fragment_layer_viewport );
	makeGlExtension( v1_5, v1_5, v4_3, ARB_explicit_attrib_location );
	makeGlExtension( v1_5, v1_5, vUnk, NV_gpu_shader5 );
	makeGlExtension( v1_5, v1_5, vUnk, ARB_viewport_array );
	makeGlExtension( v4_0, v4_0, v4_1, ARB_separate_shader_objects );
	makeGlExtension( v4_0, v4_0, vUnk, ARB_texture_cube_map_array );
	makeGlExtension( v4_0, v4_0, vUnk, ARB_texture_gather );
	makeGlExtension( v4_0, v4_0, vUnk, ARB_gpu_shader_int64 );
	makeGlExtension( v4_0, v4_2, v4_3, ARB_shader_storage_buffer_object );
	makeGlExtension( v4_1, v4_1, v4_2, ARB_shading_language_packing );
	makeGlExtension( v4_2, v4_2, v4_3, ARB_shader_image_size );
	makeGlExtension( v4_2, v4_2, v4_3, ARB_explicit_uniform_location );
	makeGlExtension( v4_2, v4_2, vUnk, ARB_compute_shader );
	makeGlExtension( v4_2, v4_2, vUnk, NV_shader_atomic_float );
	makeGlExtension( v4_3, v4_3, vUnk, NV_viewport_array2 );
	makeGlExtension( v4_3, v4_3, vUnk, NV_shader_atomic_fp16_vector );
	makeGlExtension( v4_4, v4_4, v4_5, ARB_derivative_control );
	makeGlExtension( v4_5, v4_5, vUnk, ARB_shader_ballot );
	makeGlExtension( v4_5, v4_5, vUnk, ARB_shader_viewport_layer_array );
	makeGlExtension( v4_5, v4_5, vUnk, NV_stereo_view_rendering );
	makeGlExtension( v4_5, v4_5, vUnk, NVX_multiview_per_view_attributes );
	makeGlExtension( v4_5, v4_5, vUnk, EXT_nonuniform_qualifier );
	makeGlExtension( v4_5, v4_5, vUnk, NV_mesh_shader );
	makeGlExtension( v4_5, v4_5, vUnk, EXT_mesh_shader );
	makeGlExtension( v4_5, v4_6, vUnk, EXT_buffer_reference2 );
	makeGlExtension( v4_6, v4_6, vUnk, EXT_shader_atomic_float );
	makeGlExtension( v4_6, v4_6, vUnk, EXT_ray_tracing );
	makeGlExtension( v4_6, v4_6, vUnk, EXT_ray_query );
	makeGlExtension( v4_6, v4_6, vUnk, EXT_scalar_block_layout );
	makeGlExtension( v4_6, v4_6, vUnk, ARB_shader_draw_parameters );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_basic );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_vote );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_arithmetic );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_ballot );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_shuffle );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_shuffle_relative );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_clustered );
	makeGlExtension( v4_6, v4_6, vUnk, KHR_shader_subgroup_quad );
	makeGlExtension( vUnk, vUnk, vUnk, EXT_separate_samplers );

#undef makeGlExtension

	struct StmtConfig
	{
		ast::ShaderStage shaderStage{};
		uint32_t wantedVersion{ v4_3 };
		GlslExtensionSet availableExtensions{};
		bool vulkanGlsl{ false };
		bool flipVertY{ false };
		bool fixupClipDepth{ false };
		bool hasStd430Layout{ false };
		bool hasShaderStorageBuffers{ false };
		bool hasDescriptorSets{ false };
		bool hasBaseInstance{ false };
		ast::ShaderAllocator * allocator{};
		// Filled by writeGlsl
		uint32_t requiredVersion{ vUnk };
		GlslExtensionSet requiredExtensions{};
	};

	struct RangeInfo
	{
		uint32_t start{ 1u };
		uint32_t end{ 1u };
	};

	struct SourceInfo
	{
		RangeInfo lines{};
		RangeInfo columns{};
		ast::stmt::Stmt const * scope{};
	};

	enum class StatementType
	{
		eNone,
		eStructureDecl,
		eStructureMemberDecl,
		eFunctionDecl,
		eVariableDecl,
		eVariableBlockDecl,
		eBuiltinVariableDecl,
		eScopeLine,
		eStructureScopeBegin,
		eStructureScopeEnd,
		eFunctionScopeBegin,
		eFunctionScopeEnd,
		eLexicalScopeBegin,
		eLexicalScopeEnd,
		eControlBegin,
		eControlEnd,
	};

	using ExprsColumns = std::map< ast::expr::Expr const *, RangeInfo >;

	struct Statement
	{
		StatementType type{};
		SourceInfo source{};
		ast::stmt::Stmt const * stmt{};
		ExprsColumns exprs;
	};

	using StatementsList = std::vector< Statement >;

	struct Statements
	{
		std::string source;
		StatementsList statements;
	};

	struct IntrinsicsConfig
	{
		ast::ShaderStage stage;

		bool requiresFma1F{ false };
		bool requiresFma2F{ false };
		bool requiresFma3F{ false };
		bool requiresFma4F{ false };
		bool requiresFma1D{ false };
		bool requiresFma2D{ false };
		bool requiresFma3D{ false };
		bool requiresFma4D{ false };
		bool requiresRayDescDecl{ false };
		bool requiresBlendIndex{ false };
		bool requiresSeparateSamplers{ false };
		bool requiresInt8{ false };
		bool requiresInt16{ false };
		bool requiresInt64{ false };

		GlslExtensionSet requiredExtensions{};
	};

	template< typename ValueT >
	inline std::string writeValue( ValueT const & v )
	{
		std::stringstream stream;
		stream.imbue( std::locale{ "C" } );
		stream << v;
		return stream.str();
	}

	SDWGLC_API std::string getTypeName( ast::type::Kind kind );
	SDWGLC_API std::string getTypeName( ast::type::ImagePtr type );
	SDWGLC_API std::string getTypeName( ast::type::SamplerPtr type );
	SDWGLC_API std::string getTypeName( ast::type::CombinedImagePtr type );
	SDWGLC_API std::string getTypeName( ast::type::SampledImagePtr type );
	SDWGLC_API std::string getTypeName( ast::type::TypePtr type );
	SDWGLC_API void checkType( ast::type::TypePtr type
		, IntrinsicsConfig & config );

	SDWGLC_API RangeInfo getColumnData( Statement const * statement
		, ast::expr::Expr const & expr );
	SDWGLC_API RangeInfo getColumnData( Statement const * statement );

	inline bool checkBufferMemoryBarrier( ast::type::MemorySemantics semantics )
	{
		return ( semantics & ast::type::MemorySemanticsMask::eUniformMemory ) == ast::type::MemorySemanticsMask::eUniformMemory;
	}

	inline bool checkSharedMemoryBarrier( ast::type::MemorySemantics semantics )
	{
		return ( semantics & ast::type::MemorySemanticsMask::eWorkgroupMemory ) == ast::type::MemorySemanticsMask::eWorkgroupMemory;
	}

	inline bool checkImageMemoryBarrier( ast::type::MemorySemantics semantics )
	{
		return ( semantics & ast::type::MemorySemanticsMask::eImageMemory ) == ast::type::MemorySemanticsMask::eImageMemory;
	}

	inline bool checkAllMemoryBarrier( ast::type::MemorySemantics semantics )
	{
		return checkBufferMemoryBarrier( semantics ) && checkSharedMemoryBarrier( semantics ) && checkImageMemoryBarrier( semantics );
	}

	inline bool checkAnyMemoryBarrier( ast::type::MemorySemantics semantics )
	{
		return checkBufferMemoryBarrier( semantics ) || checkSharedMemoryBarrier( semantics ) || checkImageMemoryBarrier( semantics );
	}
}

#endif
