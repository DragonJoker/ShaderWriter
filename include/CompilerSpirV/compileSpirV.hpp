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
	static uint32_t constexpr v1_6 = makeVersion( 1u, 6u );

	struct SpirVExtension
	{
		uint32_t reqVersion{ vUnk };
		uint32_t specVersion{ vUnk };
		uint32_t coreInVersion{ vUnk };
		std::string name{};
		bool isMarker{};
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

#define makeSpirVMarker( reqVersion, specVersion, coreInVersion, name )\
	static SpirVExtension const name{ reqVersion, specVersion, coreInVersion, "SDW_"#name, true }

	// Not used yet.
	makeSpirVExtension( v1_0, v1_1, v1_3, KHR_device_group );
	// Enable this extension if you need baseVertex, baseInstance or drawIndex builtins.
	makeSpirVExtension( v1_0, v1_1, v1_3, KHR_shader_draw_parameters );
	// Not used yet.
	makeSpirVExtension( v1_0, v1_1, v1_3, KHR_multiview );
	// Not used yet.
	makeSpirVExtension( v1_0, v1_1, v1_5, KHR_shader_ballot );
	// Enable this extension if you need layer built-in from any shader stage other than mesh or geometry.
	makeSpirVExtension( v1_0, v1_2, v1_5, EXT_shader_viewport_index_layer );
	// Enable this extension if you need sampled images or image runtime arrays.
	makeSpirVExtension( v1_0, v1_3, v1_5, EXT_descriptor_indexing );
	// Enable this extension to prevent mapping of terminate instruction to discard instruction.
	makeSpirVExtension( v1_0, v1_5, v1_6, KHR_terminate_invocation );
	// Not used yet
	makeSpirVExtension( v1_0, v1_1, vUnk, EXT_shader_stencil_export );
	// Enable this extension if you need to use viewportMask builtin.
	makeSpirVExtension( v1_0, v1_1, vUnk, NV_viewport_array2 );
	// Not used yet.
	makeSpirVExtension( v1_0, v1_1, vUnk, NV_stereo_view_rendering );
	// Not used yet.
	makeSpirVExtension( v1_0, v1_1, vUnk, NVX_multiview_per_view_attributes );
	// Allows conversions from/to int16/uint16.
	makeSpirVExtension( v1_0, v1_1, v1_1, KHR_16bit_storage );
	// Allows conversions from/to int8/uint8.
	makeSpirVExtension( v1_0, v1_2, v1_2, KHR_8bit_storage );
	// Enable this extension to be able to use NVIDIA Mesh and Task shader stages.
	makeSpirVExtension( v1_0, v1_3, vUnk, NV_mesh_shader );
	// Enable this extension to be able to enable use derivatives in compute shader stage.
	makeSpirVExtension( v1_0, v1_3, vUnk, NV_compute_shader_derivatives );
	// Enable this extension to prevent mapping of demote instruction to discard instruction.
	makeSpirVExtension( v1_0, v1_4, v1_6, EXT_demote_to_helper_invocation );
	// Enable this extension if you need any of the following intrinsic functions:
	// atomicAddF, atomicAdd2H, atomicAdd4H
	// atomicExchangeF, atomicExchange2H, atomicExchange4H
	// imageAtomicAdd1DF, imageAtomicAdd2DF, imageAtomicAdd3DF, imageAtomicAddCubeF, imageAtomicAddBufferF, imageAtomicAdd2DMSF
	// imageAtomicAdd1DArrayF, imageAtomicAdd2DArrayF, imageAtomicAddCubeArrayF, imageAtomicAdd2DMSArrayF
	// imageAtomicExchange1DF, imageAtomicExchange2DF, imageAtomicExchange3DF, imageAtomicExchangeCubeF, imageAtomicExchangeBufferF
	// imageAtomicExchange1DArrayF, imageAtomicExchange2DArrayF, imageAtomicExchangeCubeArrayF, imageAtomicExchange2DMSF, imageAtomicExchange2DMSArrayF
	makeSpirVExtension( v1_0, v1_5, vUnk, EXT_shader_atomic_float_add );
	// Not used yet.
	makeSpirVExtension( v1_0, v1_5, vUnk, KHR_ray_query );
	// Enable this extension to be able to use buffer references.
	makeSpirVExtension( v1_3, v1_3, v1_5, EXT_physical_storage_buffer );
	// Used for debug info
	makeSpirVExtension( v1_0, v1_0, v1_3, KHR_non_semantic_info );
	// Enable this extension to be able to use any ray tracing shader stage.
	makeSpirVExtension( v1_4, v1_5, vUnk, KHR_ray_tracing );
	// Enable this extension to be able to use EXT Mesh and Task shader stages
	makeSpirVExtension( v1_6, v1_6, vUnk, EXT_mesh_shader );
	// Marker used to tell that the shader uses subgroup intrinsics.
	makeSpirVMarker( v1_3, v1_3, v1_3, KHR_shader_subgroup );

#undef makeSpirVMarker
#undef makeSpirVExtension

	enum class DebugLevel
	{
		eNone,
		eNames,
		eDebugInfo
	};

	struct SpirVConfig
	{
		uint32_t specVersion{ v1_1 };
		SpirVExtensionSet * availableExtensions{};
		DebugLevel debugLevel{};
		ast::ShaderAllocator * allocator{};
		// Filled by writeSpirv/serialiseSpirv
		uint32_t requiredVersion{ vUnk };
		SpirVExtensionSet requiredExtensions{};
	};

	class Module;
	struct ModuleDeleter
	{
		SDWSPIRV_API void operator()( Module * shaderModule );
	};
	using ModulePtr = std::unique_ptr< Module, ModuleDeleter >;
	
	SDWSPIRV_API ModulePtr compileSpirV( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, SpirVConfig & config );
	SDWSPIRV_API ModulePtr compileSpirV( ast::ShaderAllocatorBlock & allocator
		, ast::Shader const & shader
		, SpirVConfig & config );
	SDWSPIRV_API std::string writeModule( Module const & shaderModule
		, bool writeHeader = true );
	SDWSPIRV_API std::vector< uint32_t > serialiseModule( Module const & shaderModule );

	SDWSPIRV_API std::string writeSpirv( ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, SpirVConfig & config
		, bool writeHeader = true );
	SDWSPIRV_API std::string writeSpirv( ast::Shader const & shader
		, SpirVConfig & config
		, bool writeHeader = true );
	SDWSPIRV_API std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, ast::stmt::Container const * statements
		, ast::ShaderStage stage
		, SpirVConfig & config );
	SDWSPIRV_API std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader
		, SpirVConfig & config );
	SDWSPIRV_API std::string displaySpirv( ast::ShaderAllocatorBlock & allocator
		, std::vector< uint32_t > const & spirv );
	SDWSPIRV_API ast::Shader parseSpirv( ast::ShaderAllocatorBlock & allocator
		, ast::ShaderStage stage
		, std::vector< uint32_t > const & spirv );
}

#endif
