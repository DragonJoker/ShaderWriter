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
		case ast::expr::TextureAccess::eTextureGather2DF:
		case ast::expr::TextureAccess::eTextureGather2DFComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayF:
		case ast::expr::TextureAccess::eTextureGather2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeF:
		case ast::expr::TextureAccess::eTextureGatherCubeFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayFComp:
		case ast::expr::TextureAccess::eTextureGather2DRectF:
		case ast::expr::TextureAccess::eTextureGather2DRectFComp:
		case ast::expr::TextureAccess::eTextureGather2DI:
		case ast::expr::TextureAccess::eTextureGather2DIComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayI:
		case ast::expr::TextureAccess::eTextureGather2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeI:
		case ast::expr::TextureAccess::eTextureGatherCubeIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayIComp:
		case ast::expr::TextureAccess::eTextureGather2DRectI:
		case ast::expr::TextureAccess::eTextureGather2DRectIComp:
		case ast::expr::TextureAccess::eTextureGather2DU:
		case ast::expr::TextureAccess::eTextureGather2DUComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayU:
		case ast::expr::TextureAccess::eTextureGather2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeU:
		case ast::expr::TextureAccess::eTextureGatherCubeUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayUComp:
		case ast::expr::TextureAccess::eTextureGather2DRectU:
		case ast::expr::TextureAccess::eTextureGather2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp:
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
			config.requiresTextureGather = true;
			break;
		}
	}
}

#endif
