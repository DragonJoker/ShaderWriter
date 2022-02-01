/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslTextureAccessConfig_H___
#define ___AST_GlslTextureAccessConfig_H___
#pragma once

#include "GlslHelpers.hpp"

#include <ShaderAST/Expr/EnumTextureAccess.hpp>

namespace glsl
{
	inline void getGlslConfig( ast::expr::TextureAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureQueryLod1DF:
		case ast::expr::TextureAccess::eTextureQueryLod2DF:
		case ast::expr::TextureAccess::eTextureQueryLod3DF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeF:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayF:
		case ast::expr::TextureAccess::eTextureQueryLod1DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod2DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod1DI:
		case ast::expr::TextureAccess::eTextureQueryLod2DI:
		case ast::expr::TextureAccess::eTextureQueryLod3DI:
		case ast::expr::TextureAccess::eTextureQueryLodCubeI:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayI:
		case ast::expr::TextureAccess::eTextureQueryLod1DU:
		case ast::expr::TextureAccess::eTextureQueryLod2DU:
		case ast::expr::TextureAccess::eTextureQueryLod3DU:
		case ast::expr::TextureAccess::eTextureQueryLodCubeU:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayU:
			config.requiredExtensions.insert( EXT_gpu_shader4 );
			config.requiredExtensions.insert( EXT_gpu_shader4_1 );
			config.requiredExtensions.insert( ARB_texture_query_lod );
			break;
		case ast::expr::TextureAccess::eTextureQueryLevels1DF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DF:
		case ast::expr::TextureAccess::eTextureQueryLevels3DF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DI:
		case ast::expr::TextureAccess::eTextureQueryLevels2DI:
		case ast::expr::TextureAccess::eTextureQueryLevels3DI:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeI:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayI:
		case ast::expr::TextureAccess::eTextureQueryLevels1DU:
		case ast::expr::TextureAccess::eTextureQueryLevels2DU:
		case ast::expr::TextureAccess::eTextureQueryLevels3DU:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeU:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU:
			config.requiredExtensions.insert( ARB_texture_query_levels );
			break;
		case ast::expr::TextureAccess::eTextureGather2DF:
		case ast::expr::TextureAccess::eTextureGather2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherCubeF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
		case ast::expr::TextureAccess::eTextureGather2DRectF:
		case ast::expr::TextureAccess::eTextureGather2DI:
		case ast::expr::TextureAccess::eTextureGather2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherCubeI:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
		case ast::expr::TextureAccess::eTextureGather2DRectI:
		case ast::expr::TextureAccess::eTextureGather2DU:
		case ast::expr::TextureAccess::eTextureGather2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherCubeU:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
		case ast::expr::TextureAccess::eTextureGather2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
		case ast::expr::TextureAccess::eTextureGather2DShadowF:
		case ast::expr::TextureAccess::eTextureGather2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherCubeShadowF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureGather2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectShadowF:
			config.requiredExtensions.insert( ARB_texture_gather );
			break;
		default:
			break;
		}
	}
}

#endif
