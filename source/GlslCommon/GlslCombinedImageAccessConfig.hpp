/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslTextureAccessConfig_H___
#define ___AST_GlslTextureAccessConfig_H___
#pragma once

#include "GlslStatementsHelpers.hpp"

#include <ShaderAST/Expr/EnumCombinedImageAccess.hpp>

namespace glsl
{
	inline void getGlslConfig( ast::expr::CombinedImageAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU:
			config.requiredExtensions.insert( EXT_gpu_shader4 );
			config.requiredExtensions.insert( EXT_gpu_shader4_1 );
			config.requiredExtensions.insert( ARB_texture_query_lod );
			break;
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
			config.requiredExtensions.insert( ARB_texture_query_levels );
			break;
		case ast::expr::CombinedImageAccess::eTextureLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayShadowF:
			config.requiredExtensions.insert( EXT_texture_shadow_lod );
			break;
		case ast::expr::CombinedImageAccess::eTextureGather2DF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureGather2DI:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeI:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureGather2DU:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeU:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			config.requiredExtensions.insert( ARB_texture_gather );
			break;
		default:
			break;
		}
	}
}

#endif
