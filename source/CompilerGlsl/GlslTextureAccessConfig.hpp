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
		case ast::expr::TextureAccess::eTexture1DShadowF:
			config.requiresTexture1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture1DShadowFBias:
			config.requiresTexture1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture2DShadowF:
			config.requiresTexture2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture2DShadowFBias:
			config.requiresTexture2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureCubeShadowF:
			config.requiresTextureCubeShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureCubeShadowFBias:
			config.requiresTextureCubeShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture1DArrayShadowF:
			config.requiresTexture1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
			config.requiresTexture1DArrayShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture2DArrayShadowF:
			config.requiresTexture2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTexture2DArrayShadowFBias:
			config.requiresTexture2DArrayShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTexture2DRectShadowF:
			config.requiresTexture2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowF:
			config.requiresTextureProj1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
			config.requiresTextureProj1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DShadowF:
			config.requiresTextureProj2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
			config.requiresTextureProj2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
			config.requiresTextureProj2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLod1DShadowF:
			config.requiresTextureLod1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLod2DShadowF:
			config.requiresTextureLod2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
			config.requiresTextureLod1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
			config.requiresTextureOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset1DShadowF:
			config.requiresTextureOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
			config.requiresTextureOffset1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DShadowF:
			config.requiresTextureOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
			config.requiresTextureOffset2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
			config.requiresTextureOffset1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
			config.requiresTextureOffset2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
			config.requiresTextureProjOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
			config.requiresTextureProjOffset1DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
			config.requiresTextureProjOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			config.requiresTextureProjOffset2DShadowFBias = true;
			break;

		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
			config.requiresTextureProjOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
			config.requiresTextureLodOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
			config.requiresTextureLodOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
			config.requiresTextureLodOffset1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
			config.requiresTextureProjLod1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
			config.requiresTextureProjLod2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
			config.requiresTextureProjLodOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			config.requiresTextureProjLodOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
			config.requiresTextureGrad2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad1DShadowF:
			config.requiresTextureGrad1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad2DShadowF:
			config.requiresTextureGrad2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
			config.requiresTextureGrad1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
			config.requiresTextureGradOffset2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
			config.requiresTextureGradOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
			config.requiresTextureGradOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
			config.requiresTextureGradOffset1DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
			config.requiresTextureGradOffset2DArrayShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
			config.requiresTextureProjGrad1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
			config.requiresTextureProjGrad2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
			config.requiresTextureProjGrad2DRectShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			config.requiresTextureProjGradOffset1DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
			config.requiresTextureProjGradOffset2DShadowF = true;
			break;

		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			config.requiresTextureProjGradOffset2DRectShadowF = true;
			break;
		}
	}
}

#endif
