/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslSampledImageAccessConfig_H___
#define ___AST_GlslSampledImageAccessConfig_H___
#pragma once

#include "GlslHelpers.hpp"

#include <ShaderAST/Expr/EnumSampledImageAccess.hpp>

namespace glsl
{
	inline void getGlslConfig( ast::expr::SampledImageAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::SampledImageAccess::eSampleGather2DF:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayF:
		case ast::expr::SampledImageAccess::eSampleGather2DRectF:
		case ast::expr::SampledImageAccess::eSampleGather2DI:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGatherCubeI:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayI:
		case ast::expr::SampledImageAccess::eSampleGather2DRectI:
		case ast::expr::SampledImageAccess::eSampleGather2DU:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGatherCubeU:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayU:
		case ast::expr::SampledImageAccess::eSampleGather2DRectU:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DI:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectI:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DU:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectU:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DI:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectI:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DU:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectU:
		case ast::expr::SampledImageAccess::eSampleGather2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectShadowF:
			config.requiredExtensions.insert( ARB_texture_gather );
			break;
		default:
			break;
		}
	}
}

#endif
