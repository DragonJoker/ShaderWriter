/*
See LICENSE file in root folder
*/
#include "HlslExprAdapter.hpp"

#include "HlslHelpers.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslImageAccessConfig.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslTextureAccessConfig.hpp"

#include <ShaderWriter/Intrinsics/Intrinsics.hpp>

#include <ShaderAST/Stmt/StmtReturn.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Stmt/StmtVariableDecl.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>

#include <algorithm>

namespace hlsl
{
	namespace
	{
		bool isMatrix( ast::type::Kind kind )
		{
			return kind >= ast::type::Kind::eMat2x2F
				&& kind <= ast::type::Kind::eMat4x4D;
		}

		ast::expr::ExprPtr writeProjectTexCoords2( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getFloat()
				, ast::expr::makeIdentifier( ast::var::makeFunction( cache, "SDW_projectTexCoords2" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords3( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec2F()
				, ast::expr::makeIdentifier( ast::var::makeFunction( cache, "SDW_projectTexCoords3" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords4To1( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getFloat()
				, ast::expr::makeIdentifier( ast::var::makeFunction( cache, "SDW_projectTexCoords4To1" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords4To2( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec2F()
				, ast::expr::makeIdentifier( ast::var::makeFunction( cache, "SDW_projectTexCoords4To2" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords4( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec3F()
				, ast::expr::makeIdentifier( ast::var::makeFunction( cache, "SDW_projectTexCoords4" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjTexCoords( ast::type::TypesCache & cache
			, ast::expr::TextureAccess access
			, ast::expr::ExprPtr texcoords )
		{
			switch ( access )
			{
			case ast::expr::TextureAccess::eTextureProj1DF2:
			case ast::expr::TextureAccess::eTextureProj1DShadowF:
			case ast::expr::TextureAccess::eTextureProj1DI2:
			case ast::expr::TextureAccess::eTextureProj1DU2:
			case ast::expr::TextureAccess::eTextureProj1DF2Bias:
			case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
			case ast::expr::TextureAccess::eTextureProj1DI2Bias:
			case ast::expr::TextureAccess::eTextureProj1DU2Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DF2:
			case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset1DI2:
			case ast::expr::TextureAccess::eTextureProjOffset1DU2:
			case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
			case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
			case ast::expr::TextureAccess::eTextureProjLod1DF2:
			case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
			case ast::expr::TextureAccess::eTextureProjLod1DI2:
			case ast::expr::TextureAccess::eTextureProjLod1DU2:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
			case ast::expr::TextureAccess::eTextureProjGrad1DF2:
			case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad1DI2:
			case ast::expr::TextureAccess::eTextureProjGrad1DU2:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
				return writeProjectTexCoords2( cache, std::move( texcoords ) );

			case ast::expr::TextureAccess::eTextureProj1DF4:
			case ast::expr::TextureAccess::eTextureProj1DI4:
			case ast::expr::TextureAccess::eTextureProj1DU4:
			case ast::expr::TextureAccess::eTextureProj1DF4Bias:
			case ast::expr::TextureAccess::eTextureProj1DI4Bias:
			case ast::expr::TextureAccess::eTextureProj1DU4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DF4:
			case ast::expr::TextureAccess::eTextureProjOffset1DI4:
			case ast::expr::TextureAccess::eTextureProjOffset1DU4:
			case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
			case ast::expr::TextureAccess::eTextureProjLod1DF4:
			case ast::expr::TextureAccess::eTextureProjLod1DI4:
			case ast::expr::TextureAccess::eTextureProjLod1DU4:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
			case ast::expr::TextureAccess::eTextureProjGrad1DF4:
			case ast::expr::TextureAccess::eTextureProjGrad1DI4:
			case ast::expr::TextureAccess::eTextureProjGrad1DU4:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
				return writeProjectTexCoords4To1( cache, std::move( texcoords ) );

			case ast::expr::TextureAccess::eTextureProj2DF3:
			case ast::expr::TextureAccess::eTextureProj2DShadowF:
			case ast::expr::TextureAccess::eTextureProj2DRectF3:
			case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProj2DI3:
			case ast::expr::TextureAccess::eTextureProj2DRectI3:
			case ast::expr::TextureAccess::eTextureProj2DU3:
			case ast::expr::TextureAccess::eTextureProj2DRectU3:
			case ast::expr::TextureAccess::eTextureProj2DF3Bias:
			case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
			case ast::expr::TextureAccess::eTextureProj2DI3Bias:
			case ast::expr::TextureAccess::eTextureProj2DU3Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DF3:
			case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset2DI3:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
			case ast::expr::TextureAccess::eTextureProjOffset2DU3:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
			case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
			case ast::expr::TextureAccess::eTextureProjLod2DF3:
			case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
			case ast::expr::TextureAccess::eTextureProjLod2DI3:
			case ast::expr::TextureAccess::eTextureProjLod2DU3:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
			case ast::expr::TextureAccess::eTextureProjGrad2DF3:
			case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad2DI3:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
			case ast::expr::TextureAccess::eTextureProjGrad2DU3:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
				return writeProjectTexCoords3( cache, std::move( texcoords ) );

			case ast::expr::TextureAccess::eTextureProj2DF4:
			case ast::expr::TextureAccess::eTextureProj2DRectF4:
			case ast::expr::TextureAccess::eTextureProj2DI4:
			case ast::expr::TextureAccess::eTextureProj2DRectI4:
			case ast::expr::TextureAccess::eTextureProj2DU4:
			case ast::expr::TextureAccess::eTextureProj2DRectU4:
			case ast::expr::TextureAccess::eTextureProj2DF4Bias:
			case ast::expr::TextureAccess::eTextureProj2DI4Bias:
			case ast::expr::TextureAccess::eTextureProj2DU4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DF4:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectF4:
			case ast::expr::TextureAccess::eTextureProjOffset2DI4:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
			case ast::expr::TextureAccess::eTextureProjOffset2DU4:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
			case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
			case ast::expr::TextureAccess::eTextureProjLod2DF4:
			case ast::expr::TextureAccess::eTextureProjLod2DI4:
			case ast::expr::TextureAccess::eTextureProjLod2DU4:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
			case ast::expr::TextureAccess::eTextureProjGrad2DF4:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectF4:
			case ast::expr::TextureAccess::eTextureProjGrad2DI4:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
			case ast::expr::TextureAccess::eTextureProjGrad2DU4:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
				return writeProjectTexCoords4To2( cache, std::move( texcoords ) );

			case ast::expr::TextureAccess::eTextureProj3DF:
			case ast::expr::TextureAccess::eTextureProj3DI:
			case ast::expr::TextureAccess::eTextureProj3DU:
			case ast::expr::TextureAccess::eTextureProj3DFBias:
			case ast::expr::TextureAccess::eTextureProj3DIBias:
			case ast::expr::TextureAccess::eTextureProj3DUBias:
			case ast::expr::TextureAccess::eTextureProjOffset3DF:
			case ast::expr::TextureAccess::eTextureProjOffset3DI:
			case ast::expr::TextureAccess::eTextureProjOffset3DU:
			case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
			case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
			case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
			case ast::expr::TextureAccess::eTextureProjLod3DF:
			case ast::expr::TextureAccess::eTextureProjLod3DI:
			case ast::expr::TextureAccess::eTextureProjLod3DU:
			case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
			case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
			case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
			case ast::expr::TextureAccess::eTextureProjGrad3DF:
			case ast::expr::TextureAccess::eTextureProjGrad3DI:
			case ast::expr::TextureAccess::eTextureProjGrad3DU:
			case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
			case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
			case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
				return writeProjectTexCoords4( cache, std::move( texcoords ) );

			default:
				assert( false && "Expected a textureProj access function" );
				return nullptr;
			}
		}

		bool requiresProjTexCoords( ast::expr::TextureAccess access )
		{
			bool result = false;

			switch ( access )
			{
			case ast::expr::TextureAccess::eTextureProj1DF2:
			case ast::expr::TextureAccess::eTextureProj1DShadowF:
			case ast::expr::TextureAccess::eTextureProj1DI2:
			case ast::expr::TextureAccess::eTextureProj1DU2:
			case ast::expr::TextureAccess::eTextureProj1DF2Bias:
			case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
			case ast::expr::TextureAccess::eTextureProj1DI2Bias:
			case ast::expr::TextureAccess::eTextureProj1DU2Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DF2:
			case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset1DI2:
			case ast::expr::TextureAccess::eTextureProjOffset1DU2:
			case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
			case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
			case ast::expr::TextureAccess::eTextureProjLod1DF2:
			case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
			case ast::expr::TextureAccess::eTextureProjLod1DI2:
			case ast::expr::TextureAccess::eTextureProjLod1DU2:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
			case ast::expr::TextureAccess::eTextureProjGrad1DF2:
			case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad1DI2:
			case ast::expr::TextureAccess::eTextureProjGrad1DU2:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
			case ast::expr::TextureAccess::eTextureProj1DF4:
			case ast::expr::TextureAccess::eTextureProj1DI4:
			case ast::expr::TextureAccess::eTextureProj1DU4:
			case ast::expr::TextureAccess::eTextureProj1DF4Bias:
			case ast::expr::TextureAccess::eTextureProj1DI4Bias:
			case ast::expr::TextureAccess::eTextureProj1DU4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DF4:
			case ast::expr::TextureAccess::eTextureProjOffset1DI4:
			case ast::expr::TextureAccess::eTextureProjOffset1DU4:
			case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
			case ast::expr::TextureAccess::eTextureProjLod1DF4:
			case ast::expr::TextureAccess::eTextureProjLod1DI4:
			case ast::expr::TextureAccess::eTextureProjLod1DU4:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
			case ast::expr::TextureAccess::eTextureProjGrad1DF4:
			case ast::expr::TextureAccess::eTextureProjGrad1DI4:
			case ast::expr::TextureAccess::eTextureProjGrad1DU4:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
			case ast::expr::TextureAccess::eTextureProj2DF3:
			case ast::expr::TextureAccess::eTextureProj2DShadowF:
			case ast::expr::TextureAccess::eTextureProj2DRectF3:
			case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProj2DI3:
			case ast::expr::TextureAccess::eTextureProj2DRectI3:
			case ast::expr::TextureAccess::eTextureProj2DU3:
			case ast::expr::TextureAccess::eTextureProj2DRectU3:
			case ast::expr::TextureAccess::eTextureProj2DF3Bias:
			case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
			case ast::expr::TextureAccess::eTextureProj2DI3Bias:
			case ast::expr::TextureAccess::eTextureProj2DU3Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DF3:
			case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset2DI3:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
			case ast::expr::TextureAccess::eTextureProjOffset2DU3:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
			case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
			case ast::expr::TextureAccess::eTextureProjLod2DF3:
			case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
			case ast::expr::TextureAccess::eTextureProjLod2DI3:
			case ast::expr::TextureAccess::eTextureProjLod2DU3:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
			case ast::expr::TextureAccess::eTextureProjGrad2DF3:
			case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad2DI3:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
			case ast::expr::TextureAccess::eTextureProjGrad2DU3:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
			case ast::expr::TextureAccess::eTextureProj2DF4:
			case ast::expr::TextureAccess::eTextureProj2DRectF4:
			case ast::expr::TextureAccess::eTextureProj2DI4:
			case ast::expr::TextureAccess::eTextureProj2DRectI4:
			case ast::expr::TextureAccess::eTextureProj2DU4:
			case ast::expr::TextureAccess::eTextureProj2DRectU4:
			case ast::expr::TextureAccess::eTextureProj2DF4Bias:
			case ast::expr::TextureAccess::eTextureProj2DI4Bias:
			case ast::expr::TextureAccess::eTextureProj2DU4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DF4:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectF4:
			case ast::expr::TextureAccess::eTextureProjOffset2DI4:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
			case ast::expr::TextureAccess::eTextureProjOffset2DU4:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
			case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
			case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
			case ast::expr::TextureAccess::eTextureProjLod2DF4:
			case ast::expr::TextureAccess::eTextureProjLod2DI4:
			case ast::expr::TextureAccess::eTextureProjLod2DU4:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
			case ast::expr::TextureAccess::eTextureProjGrad2DF4:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectF4:
			case ast::expr::TextureAccess::eTextureProjGrad2DI4:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
			case ast::expr::TextureAccess::eTextureProjGrad2DU4:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
			case ast::expr::TextureAccess::eTextureProj3DF:
			case ast::expr::TextureAccess::eTextureProj3DI:
			case ast::expr::TextureAccess::eTextureProj3DU:
			case ast::expr::TextureAccess::eTextureProj3DFBias:
			case ast::expr::TextureAccess::eTextureProj3DIBias:
			case ast::expr::TextureAccess::eTextureProj3DUBias:
			case ast::expr::TextureAccess::eTextureProjOffset3DF:
			case ast::expr::TextureAccess::eTextureProjOffset3DI:
			case ast::expr::TextureAccess::eTextureProjOffset3DU:
			case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
			case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
			case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
			case ast::expr::TextureAccess::eTextureProjLod3DF:
			case ast::expr::TextureAccess::eTextureProjLod3DI:
			case ast::expr::TextureAccess::eTextureProjLod3DU:
			case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
			case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
			case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
			case ast::expr::TextureAccess::eTextureProjGrad3DF:
			case ast::expr::TextureAccess::eTextureProjGrad3DI:
			case ast::expr::TextureAccess::eTextureProjGrad3DU:
			case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
			case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
			case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
				result = true;
				break;
			}

			return result;
		}

		ast::expr::TextureAccess getSampleCmp( ast::expr::TextureAccess value )
		{
			assert( value >= ast::expr::TextureAccess::eTextureGrad2DRectShadowF
				&& value <= ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF );
			ast::expr::TextureAccess result;

			switch ( value )
			{
			case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
				result = ast::expr::TextureAccess::eTexture2DRectShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGrad1DShadowF:
				result = ast::expr::TextureAccess::eTexture1DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGrad2DShadowF:
				result = ast::expr::TextureAccess::eTexture2DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
				result = ast::expr::TextureAccess::eTexture1DArrayShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
				result = ast::expr::TextureAccess::eTextureOffset2DRectShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
				result = ast::expr::TextureAccess::eTextureOffset1DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
				result = ast::expr::TextureAccess::eTextureOffset2DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
				result = ast::expr::TextureAccess::eTextureOffset1DArrayShadowF;
				break;
			case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
				result = ast::expr::TextureAccess::eTextureOffset2DArrayShadowF;
				break;
			case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
				result = ast::expr::TextureAccess::eTextureProj1DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
				result = ast::expr::TextureAccess::eTextureProj2DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
				result = ast::expr::TextureAccess::eTextureProj2DRectShadowF;
				break;
			case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
				result = ast::expr::TextureAccess::eTextureProjOffset1DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
				result = ast::expr::TextureAccess::eTextureProjOffset2DShadowF;
				break;
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
				result = ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF;
				break;
			}

			return result;
		}

		inline ast::expr::TextureAccess getCompAccess( ast::expr::TextureAccess value )
		{
			switch ( value )
			{
			case ast::expr::TextureAccess::eTextureGather2DF:
				return ast::expr::TextureAccess::eTextureGather2DFComp;
			case ast::expr::TextureAccess::eTextureGather2DArrayF:
				return ast::expr::TextureAccess::eTextureGather2DArrayFComp;
			case ast::expr::TextureAccess::eTextureGatherCubeF:
				return ast::expr::TextureAccess::eTextureGatherCubeFComp;
			case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
				return ast::expr::TextureAccess::eTextureGatherCubeArrayFComp;
			case ast::expr::TextureAccess::eTextureGather2DRectF:
				return ast::expr::TextureAccess::eTextureGather2DRectFComp;
			case ast::expr::TextureAccess::eTextureGather2DI:
				return ast::expr::TextureAccess::eTextureGather2DIComp;
			case ast::expr::TextureAccess::eTextureGather2DArrayI:
				return ast::expr::TextureAccess::eTextureGather2DArrayIComp;
			case ast::expr::TextureAccess::eTextureGatherCubeI:
				return ast::expr::TextureAccess::eTextureGatherCubeIComp;
			case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
				return ast::expr::TextureAccess::eTextureGatherCubeArrayIComp;
			case ast::expr::TextureAccess::eTextureGather2DRectI:
				return ast::expr::TextureAccess::eTextureGather2DRectIComp;
			case ast::expr::TextureAccess::eTextureGather2DU:
				return ast::expr::TextureAccess::eTextureGather2DUComp;
			case ast::expr::TextureAccess::eTextureGather2DArrayU:
				return ast::expr::TextureAccess::eTextureGather2DArrayUComp;
			case ast::expr::TextureAccess::eTextureGatherCubeU:
				return ast::expr::TextureAccess::eTextureGatherCubeUComp;
			case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
				return ast::expr::TextureAccess::eTextureGatherCubeArrayUComp;
			case ast::expr::TextureAccess::eTextureGather2DRectU:
				return ast::expr::TextureAccess::eTextureGather2DRectUComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DF:
				return ast::expr::TextureAccess::eTextureGatherOffset2DFComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
				return ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
				return ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DI:
				return ast::expr::TextureAccess::eTextureGatherOffset2DIComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
				return ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
				return ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DU:
				return ast::expr::TextureAccess::eTextureGatherOffset2DUComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
				return ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp;
			case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
				return ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DFComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DIComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DUComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp;
			case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
				return ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp;

			default:
				throw std::runtime_error{ "Unsupported TextureAccess type." };
			}
		}

		inline bool needsComp( ast::expr::TextureAccess value )
		{
			bool result{};

			switch ( value )
			{
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
				result = true;
				break;

			default:
				result = false;
				break;
			}

			return result;
		}

		bool isShadow( ast::expr::TextureAccess value )
		{
			bool result{};

			switch ( value )
			{
			case ast::expr::TextureAccess::eTexture1DShadowF:
			case ast::expr::TextureAccess::eTexture1DShadowFBias:
			case ast::expr::TextureAccess::eTexture2DShadowF:
			case ast::expr::TextureAccess::eTexture2DShadowFBias:
			case ast::expr::TextureAccess::eTextureCubeShadowF:
			case ast::expr::TextureAccess::eTextureCubeShadowFBias:
			case ast::expr::TextureAccess::eTexture1DArrayShadowF:
			case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
			case ast::expr::TextureAccess::eTexture2DArrayShadowF:
			case ast::expr::TextureAccess::eTexture2DArrayShadowFBias:
			case ast::expr::TextureAccess::eTexture2DRectShadowF:
			case ast::expr::TextureAccess::eTextureCubeArrayShadowF:
			case ast::expr::TextureAccess::eTextureProj1DShadowF:
			case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
			case ast::expr::TextureAccess::eTextureProj2DShadowF:
			case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
			case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
			case ast::expr::TextureAccess::eTextureLod1DShadowF:
			case ast::expr::TextureAccess::eTextureLod2DShadowF:
			case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
			case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
			case ast::expr::TextureAccess::eTextureOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
			case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
			case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
			case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
			case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
			case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
			case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
			case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
			case ast::expr::TextureAccess::eTextureGrad1DShadowF:
			case ast::expr::TextureAccess::eTextureGrad2DShadowF:
			case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
			case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
			case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
			case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
			case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
			case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
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
				result = true;
				break;

			default:
				result = false;
				break;
			}

			return result;
		}

		std::string getName( std::string const & baseName
			, ast::type::ImageConfiguration const & config )
		{
			return baseName
				+ hlsl::getName( config.dimension )
				+ ( config.isArrayed ? "Array" : "" )
				+ hlsl::getSampledName( config.format );
		}

		ast::expr::ExprPtr swizzleConvert( ast::type::TypePtr dst
			, ast::expr::ExprPtr expr )
		{
			ast::expr::SwizzleKind swizzle;
			auto srcCount = getComponentCount( expr->getType()->getKind() );
			auto dstCount = getComponentCount( dst->getKind() );

			switch ( srcCount )
			{
			case 1:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e00;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e000;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0000;
					break;
				}
				break;
			case 2:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e011;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0111;
					break;
				}
				break;
			case 3:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0122;
					break;
				}
				break;
			case 4:
				switch ( dstCount )
				{
				case 1:
					swizzle = ast::expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = ast::expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = ast::expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = ast::expr::SwizzleKind::e0123;
					break;
				}
				break;
			}

			return std::make_unique< ast::expr::Swizzle >( std::move( expr )
				, swizzle );
		}

		ast::expr::ExprPtr componentCastConvert( ast::type::TypePtr dst
			, ast::expr::ExprPtr expr )
		{
			return ast::expr::makeCast( dst, std::move( expr ) );
		}

		ast::expr::ExprPtr convert( ast::type::TypePtr dst
			, ast::expr::ExprPtr expr )
		{
			auto srcCount = getComponentCount( expr->getType()->getKind() );
			auto dstCount = getComponentCount( dst->getKind() );
			ast::expr::ExprPtr result = std::move( expr );

			if ( srcCount == dstCount )
			{
				result = componentCastConvert( dst, std::move( result ) );
			}
			else
			{
				result = swizzleConvert( dst, std::move( result ) );
			}

			return result;
		}

		ast::expr::ExprPtr registerBuiltinInputVar( ast::var::VariablePtr var
			, AdaptationData & adaptationData )
		{
			auto it = adaptationData.inputMembers.find( var );

			if ( it == adaptationData.inputMembers.end() )
			{
				adaptationData.inputVars.emplace( 128, var );
				it = adaptationData.inputMembers.emplace( var
					, ast::expr::makeMbrSelect( sdw::makeIdent( adaptationData.inputVar )
						, uint32_t( adaptationData.inputMembers.size() )
						, sdw::makeIdent( var ) ) ).first;
			}

			return sdw::makeExpr( it->second );
		}

		ast::expr::ExprPtr registerBuiltinOutputVar( ast::var::VariablePtr var
			, AdaptationData & adaptationData )
		{
			auto it = adaptationData.outputMembers.find( var );

			if ( it == adaptationData.outputMembers.end() )
			{
				adaptationData.outputVars.emplace( 128, var );
				it = adaptationData.outputMembers.emplace( var
					, ast::expr::makeMbrSelect( sdw::makeIdent( adaptationData.inputVar )
						, uint32_t( adaptationData.outputMembers.size() )
						, sdw::makeIdent( var ) ) ).first;
			}

			return sdw::makeExpr( it->second );
		}

		ast::expr::ExprPtr registerBuiltinVar( ast::var::VariablePtr var
			, AdaptationData & adaptationData )
		{
			ast::expr::ExprPtr result;

			if ( var->isShaderInput() )
			{
				result = registerBuiltinInputVar( var, adaptationData );
			}
			else
			{
				result = registerBuiltinOutputVar( var, adaptationData );
			}

			return result;
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::Expr * expr
		, IntrinsicsConfig const & config
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			cache,
			result,
			config,
			adaptationData,
			intrinsics,
		};
		expr->accept( &vis );
		return result;
	}
			
	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::ExprPtr const & expr
		, IntrinsicsConfig const & config
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics )
	{
		return submit( cache
			, expr.get()
			, config
			, adaptationData
			, intrinsics );
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::expr::ExprPtr & result
		, IntrinsicsConfig const & config
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_config{ config }
		, m_adaptationData{ adaptationData }
		, m_intrinsics{ intrinsics }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			m_cache,
			result,
			m_config,
			m_adaptationData,
			m_intrinsics,
		};
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto var = expr->getVariable();

		if ( var->isBuiltin() )
		{
			m_result = registerBuiltinVar( var, m_adaptationData );
		}
		else
		{
			auto itInputs = m_adaptationData.inputMembers.find( var );
			auto itOutputs = m_adaptationData.outputMembers.find( var );

			if ( m_adaptationData.inputMembers.end() != itInputs )
			{
				m_result = sdw::makeExpr( itInputs->second );
			}
			else if ( m_adaptationData.outputMembers.end() != itOutputs )
			{
				m_result = sdw::makeExpr( itOutputs->second );
			}
			else
			{
				m_result = ast::expr::makeIdentifier( var );
			}
		}
	}

	void ExprAdapter::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		if ( expr->getArgList().size() == 1u
			&& getComponentCount( expr->getArgList().back()->getType()->getKind() ) == 1u
			&& isVectorType( expr->getType()->getKind() ) )
		{
			auto count = getComponentCount( expr->getType()->getKind() );
			m_result = std::make_unique< ast::expr::Swizzle >( doSubmit( expr->getArgList().back().get() )
				, ( count == 2u
					? ast::expr::SwizzleKind::e00
					: ( count == 3u
						? ast::expr::SwizzleKind::e000
						: ast::expr::SwizzleKind::e0000 ) ) );
		}
		else
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeCompositeConstruct( m_cache
				, expr->getComposite()
				, expr->getComponent()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitFnCallExpr( ast::expr::FnCall * expr )
	{
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			auto ident = ast::findIdentifier( arg );

			if ( ident )
			{
				auto it = m_adaptationData.linkedVars.find( ident->getVariable() );

				if ( m_adaptationData.linkedVars.end() != it )
				{
					args.emplace_back( VariableReplacer::submit( arg, ident->getVariable(), it->second.first ) );
					args.emplace_back( VariableReplacer::submit( arg, ident->getVariable(), it->second.second ) );
				}
				else
				{
					args.emplace_back( doSubmit( arg.get() ) );
				}
			}
			else
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = ast::expr::makeFnCall( expr->getType()
			, sdw::makeIdent( expr->getFn()->getVariable() )
			, std::move( args ) );
	}

	void ExprAdapter::visitImageAccessCallExpr( ast::expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageSize1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageSize2DMSArrayU )
		{
			doProcessImageSize( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageLoad1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageLoad2DMSArrayU )
		{
			doProcessImageLoad( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicAdd1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayI )
		{
			doProcessImageAtomicAdd( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicMin1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicMin2DMSArrayI )
		{
			doProcessImageAtomicMin( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicMax1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicMax2DMSArrayI )
		{
			doProcessImageAtomicMax( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicAnd1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicAnd2DMSArrayI )
		{
			doProcessImageAtomicAnd( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicOr1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicOr2DMSArrayI )
		{
			doProcessImageAtomicOr( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicXor1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicXor2DMSArrayI )
		{
			doProcessImageAtomicXor( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicExchange1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayI )
		{
			doProcessImageAtomicExchange( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicCompSwap1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicCompSwap2DMSArrayI )
		{
			doProcessImageAtomicCompSwap( expr );
		}
		else
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeImageAccessCall( expr->getType()
				, expr->getImageAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall * expr )
	{
		auto instantChange = getInstantChange( expr->getIntrinsic() );

		if ( instantChange.toOperator )
		{
			switch ( instantChange.operatorKind )
			{
			case ast::expr::Kind::eLess:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeLess( m_cache
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;
				
			case ast::expr::Kind::eLessEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeLessEqual( m_cache
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case ast::expr::Kind::eGreater:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeGreater( m_cache
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case ast::expr::Kind::eGreaterEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeGreaterEqual( m_cache
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case ast::expr::Kind::eEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeEqual( m_cache
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case ast::expr::Kind::eNotEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeNotEqual( m_cache
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case ast::expr::Kind::eLogNot:
				assert( expr->getArgList().size() == 1u );
				m_result = ast::expr::makeLogNot( m_cache
					, doSubmit( expr->getArgList()[0].get() ) );
				break;

			case ast::expr::Kind::eTimes:
				assert( expr->getArgList().size() == 2u );
				m_result = ast::expr::makeTimes( expr->getArgList()[0].get()->getType()
					, doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			default:
				assert( false && "Unexpected operator type." );
				break;
			}
		}
		else
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		if ( expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier )
		{
			auto var = static_cast< ast::expr::Identifier const * >( expr->getOuterExpr() )->getVariable();
			auto it = std::find( m_adaptationData.ssboList.begin()
				, m_adaptationData.ssboList.end()
				, var );

			if ( it != m_adaptationData.ssboList.end() )
			{
				m_result = ast::expr::makeIdentifier( expr->getMember()->getVariable() );
			}
			else
			{
				m_result = ast::expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
					, expr->getMemberIndex()
					, ast::expr::makeIdentifier( expr->getMember()->getVariable() ) );
			}
		}
		else
		{
			m_result = ast::expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
				, expr->getMemberIndex()
				, ast::expr::makeIdentifier( expr->getMember()->getVariable() ) );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( ast::expr::TextureAccessCall * expr )
	{
		if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureSize1DF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureSizeBufferU )
		{
			doProcessTextureSize( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureQueryLod1DF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureQueryLodCubeArrayU )
		{
			doProcessTextureQueryLod( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureQueryLevels1DF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU )
		{
			doProcessTextureQueryLevels( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTexelFetch1DF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTexelFetchOffset2DArrayU )
		{
			doProcessTexelFetch( expr );
		}
		else if ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGrad2DRectShadowF
			&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF
			&& m_config.requiresShadowSampler )
		{
			doProcessTextureGradShadow( expr );
		}
		else if ( ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGather2DF
				&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp )
			|| ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGather2DShadowF
				&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffset2DRectShadowF ) )
		{
			doProcessTextureGather( expr );
		}
		else if ( ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGatherOffsets2DF
				&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp )
			|| ( expr->getTextureAccess() >= ast::expr::TextureAccess::eTextureGatherOffsets2DShadowF
				&& expr->getTextureAccess() <= ast::expr::TextureAccess::eTextureGatherOffsets2DRectShadowF ) )
		{
			doProcessTextureGatherOffsets( expr );
		}
		else
		{
			doProcessTexture( expr );
		}
	}

	void ExprAdapter::visitTimesExpr( ast::expr::Times * expr )
	{
		if ( isMatrix( expr->getType()->getKind() ) )
		{
			ast::expr::ExprList argsList;
			argsList.emplace_back( doSubmit( expr->getLHS() ) );
			argsList.emplace_back( doSubmit( expr->getRHS() ) );
			m_result = ast::expr::makeFnCall( expr->getType()
				, ast::expr::makeIdentifier( ast::var::makeVariable( m_cache.getFunction(), "mul" ) )
				, std::move( argsList ) );
		}
		else
		{
			m_result = ast::expr::makeTimes( expr->getType()
				, doSubmit( expr->getLHS() )
				, doSubmit( expr->getRHS() ) );
		}
	}

	bool ExprAdapter::doProcessSampledImageArg( ast::expr::Expr & arg
		, bool writeSampler
		, ast::expr::ExprList & args )
	{
		bool result = arg.getKind() == ast::expr::Kind::eIdentifier;

		if ( result )
		{
			auto ident = ast::findIdentifier( &arg );
			auto it = m_adaptationData.linkedVars.find( ident->getVariable() );

			if ( m_adaptationData.linkedVars.end() != it )
			{
				args.emplace_back( sdw::makeIdent( it->second.first ) );

				if ( writeSampler )
				{
					args.emplace_back( sdw::makeIdent( it->second.second ) );
				}
			}
			else
			{
				args.emplace_back( doSubmit( &arg ) );
			}
		}

		return result;
	}

	void ExprAdapter::doProcessImageSize( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_imageSize", config );
		auto it = m_imageSizeFuncs.find( funcName );

		if ( it == m_imageSizeFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( expr->getArgList()[0]->getType(), "image" );
			parameters.emplace_back( image );
			auto cont = ast::stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			ast::type::TypePtr uintType = m_cache.getUInt();
			ast::var::VariableList resVars;
			ast::expr::CompositeType composite{};

			switch ( getComponentCount( expr->getType()->getKind() ) )
			{
			case 1:
			{
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eScalar;
			}
			break;
			case 2:
			{
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec2;
			}
			break;
			case 3:
			{
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimZ" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec3;
			}
			break;
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( var ) );
			}

			if ( config.dimension == ast::type::ImageDim::eCube
				&& !config.isArrayed )
			{
				auto var = ast::var::makeVariable( uintType, "dummy" );
				cont->addStmt( ast::stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( ast::expr::makeIdentifier( var ) );
			}

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, sdw::makeIdent( ast::var::makeFunction( m_cache, "GetDimensions" ) )
				, sdw::makeIdent( image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( ast::expr::makeCast( m_cache.getInt()
					, ast::expr::makeIdentifier( var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( ast::stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( m_cache
					, composite
					, ast::type::Kind::eInt
					, std::move( resArgs ) ) ) );
			}

			it = m_imageSizeFuncs.emplace( funcName
				, static_cast< ast::stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		argList.emplace_back( doSubmit( expr->getArgList().front().get() ) );
		m_result = ast::expr::makeFnCall( it->second
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageLoad( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = m_cache.getSampledType( config.format );
		ast::expr::ExprList argList;

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			argList.emplace_back( doSubmit( it->get() ) );
		}

		m_result = ast::expr::makeMemberFnCall( callRetType
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, "Load" ) )
			, doSubmit( expr->getArgList().front().get() )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomic( ast::expr::ImageAccessCall * expr
		, std::string const & name
		, std::map< std::string, ast::type::TypePtr > imageAtomicFuncs )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_imageAtomic" + name, config );
		auto it = imageAtomicFuncs.find( funcName );

		if ( it == imageAtomicFuncs.end() )
		{
			// Declare the function
			auto dataType = expr->getArgList()[2]->getType();
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( expr->getArgList()[0]->getType(), "image" );
			auto coord = ast::var::makeVariable( expr->getArgList()[1]->getType(), "coord" );
			auto data = ast::var::makeVariable( dataType, "data" );
			parameters.emplace_back( image );
			parameters.emplace_back( coord );
			parameters.emplace_back( data );
			auto cont = ast::stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			// Function content
			auto res = ast::var::makeVariable( dataType, "res" );
			cont->addStmt( ast::stmt::makeVariableDecl( res ) );

			//	The call to Interlocked<name>
			ast::expr::ExprList callArgs;
			callArgs.emplace_back( std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
				, ast::expr::makeIdentifier( image )
				, ast::expr::makeIdentifier( coord ) ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( data ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( res ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
				, sdw::makeIdent( ast::var::makeFunction( m_cache, "Interlocked" + name ) )
				, std::move( callArgs ) ) ) );

			//	The return statement
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( res ) ) );

			it = imageAtomicFuncs.emplace( funcName
				, static_cast< ast::stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			argList.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeFnCall( it->second
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomicAdd( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Add", m_imageAtomicAddFuncs );
	}

	void ExprAdapter::doProcessImageAtomicMin( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Min", m_imageAtomicMinFuncs );
	}

	void ExprAdapter::doProcessImageAtomicMax( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Max", m_imageAtomicMaxFuncs );
	}

	void ExprAdapter::doProcessImageAtomicAnd( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "And", m_imageAtomicAndFuncs );
	}

	void ExprAdapter::doProcessImageAtomicOr( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Or", m_imageAtomicOrFuncs );
	}

	void ExprAdapter::doProcessImageAtomicXor( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Xor", m_imageAtomicXorFuncs );
	}

	void ExprAdapter::doProcessImageAtomicExchange( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Exchange", m_imageAtomicExchangeFuncs );
	}

	void ExprAdapter::doProcessImageAtomicCompSwap( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_imageAtomicCompSwap", config );
		auto it = m_imageAtomicCompSwapFuncs.find( funcName );

		if ( it == m_imageAtomicCompSwapFuncs.end() )
		{
			// Declare the function
			auto dataType = expr->getArgList()[2]->getType();
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( expr->getArgList()[0]->getType(), "image" );
			auto coord = ast::var::makeVariable( expr->getArgList()[1]->getType(), "coord" );
			auto compare = ast::var::makeVariable( expr->getArgList()[2]->getType(), "compare" );
			auto data = ast::var::makeVariable( dataType, "data" );
			parameters.emplace_back( image );
			parameters.emplace_back( coord );
			parameters.emplace_back( compare );
			parameters.emplace_back( data );
			auto cont = ast::stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			// Function content
			auto res = ast::var::makeVariable( dataType, "res" );
			cont->addStmt( ast::stmt::makeVariableDecl( res ) );

			//	The call to InterlockedCompareExchange
			ast::expr::ExprList callArgs;
			callArgs.emplace_back( std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
				, ast::expr::makeIdentifier( image )
				, ast::expr::makeIdentifier( coord ) ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( compare ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( data ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( res ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
				, sdw::makeIdent( ast::var::makeFunction( m_cache, "InterlockedCompareExchange" ) )
				, std::move( callArgs ) ) ) );

			//	The return statement
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( res ) ) );

			it = m_imageAtomicCompSwapFuncs.emplace( funcName
				, static_cast< ast::stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			argList.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeFnCall( it->second
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureSize( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_textureSize", config );
		auto it = m_imageSizeFuncs.find( funcName );

		if ( it == m_imageSizeFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( imgArgType->getImageType(), "image" );
			parameters.emplace_back( image );
			ast::var::VariablePtr lod;

			if ( config.dimension != ast::type::ImageDim::eBuffer
				&& config.dimension != ast::type::ImageDim::eRect )
			{
				lod = ast::var::makeVariable( expr->getArgList()[1]->getType(), "lod" );
				parameters.emplace_back( lod );
			}

			auto cont = ast::stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			ast::type::TypePtr uintType = m_cache.getUInt();
			ast::var::VariableList resVars;
			ast::expr::CompositeType composite{};

			switch ( getComponentCount( expr->getType()->getKind() ) )
			{
			case 1:
			{
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eScalar;
			}
			break;
			case 2:
			{
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec2;
			}
			break;
			case 3:
			{
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimZ" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec3;
			}
			break;
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;

			if ( lod )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( lod ) );
			}
			else if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				callArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
			}

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( var ) );
			}

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				auto var = ast::var::makeVariable( uintType, "levels" );
				cont->addStmt( ast::stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( ast::expr::makeIdentifier( var ) );
			}

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, sdw::makeIdent( ast::var::makeFunction( m_cache, "GetDimensions" ) )
				, sdw::makeIdent( image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( ast::expr::makeCast( m_cache.getInt()
					, ast::expr::makeIdentifier( var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( ast::stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( m_cache
					, composite
					, ast::type::Kind::eInt
					, std::move( resArgs ) ) ) );
			}

			it = m_imageSizeFuncs.emplace( funcName
				, static_cast< ast::stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			if ( !doProcessSampledImageArg( *arg, false, argList ) )
			{
				argList.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = ast::expr::makeFnCall( it->second
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLod( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_textureQueryLod", config );
		auto it = m_imageLodFuncs.find( funcName );

		if ( it == m_imageLodFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( imgArgType->getImageType(), "texImage" );
			auto sampler = ast::var::makeVariable( imgArgType->getSamplerType(), "texSampler" );
			auto coord = ast::var::makeVariable( expr->getArgList()[1]->getType(), "P" );
			parameters.emplace_back( image );
			parameters.emplace_back( sampler );
			parameters.emplace_back( coord );

			auto cont = ast::stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			ast::type::TypePtr uintType = m_cache.getUInt();

			// The call to image.CalculateLevelOfDetail
			ast::expr::ExprList callArgs;
			callArgs.emplace_back( ast::expr::makeIdentifier( sampler ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( coord ) );

			// The return statement
			ast::expr::ExprList resArgs;
			resArgs.emplace_back( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, sdw::makeIdent( ast::var::makeFunction( m_cache, "CalculateLevelOfDetail" ) )
				, sdw::makeIdent( image )
				, std::move( callArgs ) ) );
			resArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0.0f ) );

			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( m_cache
				, ast::expr::CompositeType::eVec2
				, ast::type::Kind::eFloat
				, std::move( resArgs ) ) ) );

			it = m_imageLodFuncs.emplace( funcName
				, static_cast< ast::stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			if ( !doProcessSampledImageArg( *arg, true, argList ) )
			{
				argList.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = ast::expr::makeFnCall( it->second
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLevels( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_textureQueryLevels", config );
		auto it = m_imageLevelsFuncs.find( funcName );

		if ( it == m_imageLevelsFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( imgArgType->getImageType(), "image" );
			parameters.emplace_back( image );

			auto cont = ast::stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			ast::type::TypePtr uintType = m_cache.getUInt();
			ast::var::VariableList resVars;
			ast::expr::CompositeType composite{};

			switch ( config.dimension )
			{
			case ast::type::ImageDim::e1D:
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				if ( config.isArrayed )
				{
					resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
					cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				}
				break;
			case ast::type::ImageDim::e2D:
			case ast::type::ImageDim::eRect:
			case ast::type::ImageDim::eCube:
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				if ( config.isArrayed )
				{
					resVars.emplace_back( ast::var::makeVariable( uintType, "dimZ" ) );
					cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				}
				break;
			case ast::type::ImageDim::e3D:
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( uintType, "dimZ" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				break;
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				callArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
			}

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( var ) );
			}

			auto levels = ast::var::makeVariable( uintType, "levels" );
			cont->addStmt( ast::stmt::makeVariableDecl( levels ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( levels ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, sdw::makeIdent( ast::var::makeFunction( m_cache, "GetDimensions" ) )
				, sdw::makeIdent( image )
				, std::move( callArgs ) ) ) );

			// The return statement
			cont->addStmt( ast::stmt::makeReturn( sdw::makeIdent( levels ) ) );

			it = m_imageLevelsFuncs.emplace( funcName
				, static_cast< ast::stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		doProcessSampledImageArg( *expr->getArgList()[0], false, argList );

		m_result = ast::expr::makeFnCall( it->second
			, ast::expr::makeIdentifier( ast::var::makeFunction( m_cache, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTexelFetch( ast::expr::TextureAccessCall * expr )
	{
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessSampledImageArg( *expr->getArgList()[0], false, args );
		assert( isImage );

		if ( expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetchBufferF
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetchBufferI
			|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetchBufferU )
		{
			// For those texel fetch functions, no lod, and none needed.
			assert( expr->getArgList().size() >= 2u );
			args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
		}
		else
		{
			ast::expr::ExprList merged;

			if ( expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetch2DRectF
				|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetch2DRectI
				|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetch2DRectU
				|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetchOffset2DRectF
				|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetchOffset2DRectI
				|| expr->getTextureAccess() == ast::expr::TextureAccess::eTexelFetchOffset2DRectU )
			{
				// For those texel fetch functions, no lod, hence create a 0 lod.
				assert( expr->getArgList().size() >= 2u );
				// Merge second and literal(0) parameters to the appropriate vector type (int=>ivec2, ivec2=>ivec3, ivec3=>ivec4).
				merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				merged.emplace_back( ast::expr::makeLiteral( m_cache, 0 ) );
			}
			else
			{
				// For those texel fetch functions, lod is put inside the coords parameter, instead of being aside.
				assert( expr->getArgList().size() >= 3u );
				// Merge second and third parameters to the appropriate vector type (int=>ivec2, ivec2=>ivec3, ivec3=>ivec4).
				merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				merged.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
			}

			switch ( merged[0]->getType()->getKind() )
			{
			case ast::type::Kind::eInt:
				args.emplace_back( sdw::makeCompositeCtor( ast::expr::CompositeType::eVec2
					, ast::type::Kind::eInt
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec2I:
				args.emplace_back( sdw::makeCompositeCtor( ast::expr::CompositeType::eVec3
					, ast::type::Kind::eInt
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec3I:
				args.emplace_back( sdw::makeCompositeCtor( ast::expr::CompositeType::eVec4
					, ast::type::Kind::eInt
					, std::move( merged ) ) );
				break;
			}
		}

		// Other parameters remain unchanged.
		for ( size_t i = 3u; i < expr->getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGradShadow( ast::expr::TextureAccessCall * expr )
	{
		// Sample grad doesn't support SampleComparisonState, replace it with a SampleCmp.
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessSampledImageArg( *expr->getArgList()[0], false, args );
		assert( isImage );
		assert( expr->getArgList().size() >= 5u );
		// Second param is texcoord
		args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
		// Third param is dref value
		args.emplace_back( doSubmit( expr->getArgList()[2].get() ) );
		// Fourth and fifth params ard dPdx and dPdy, drop them

		// Other parameters remain unchanged.
		for ( size_t i = 5u; i < expr->getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		auto result = ast::expr::makeTextureAccessCall( expr->getType()
			, getSampleCmp( expr->getTextureAccess() )
			, std::move( args ) );

		// Reparse the created expression, textureProj cases.
		visitTextureAccessCallExpr( result.get() );
	}

	void ExprAdapter::doProcessTextureGather( ast::expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		assert( expr->getArgList().size() >= 2u );
		uint32_t index = 0u;
		ast::expr::ExprList args;
		// Image
		auto isImage = doProcessSampledImageArg( *expr->getArgList()[index++], true, args );
		assert( isImage );
		// Coord
		args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );

		if ( isShadow( kind ) )
		{
			// Dref value
			assert( expr->getArgList().size() >= 3u );
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		if ( needsComp( kind ) )
		{
			// Comp parameter of textureGather can be implicitly 0, in GLSL.
			// Hence add it to args.
			args.push_back( ast::expr::makeLiteral( m_cache, 0 ) );
			kind = getCompAccess( kind );
		}
		else if ( !isShadow( kind ) )
		{
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGatherOffsets( ast::expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		assert( expr->getArgList().size() >= 3u );
		uint32_t index = 0u;
		ast::expr::ExprList args;
		// Image
		auto isImage = doProcessSampledImageArg( *expr->getArgList()[index++], true, args );
		assert( isImage );
		// Coord
		args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );

		if ( isShadow( kind ) )
		{
			// Dref value
			assert( expr->getArgList().size() >= 4u );
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		// Next parameter contains the 4 offsets.
		auto & offset = *expr->getArgList()[index++];
		assert( getArraySize( offset.getType() ) == 4u );
		auto arrayType = std::static_pointer_cast< ast::type::Array >( offset.getType() );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.makeType( arrayType->getType()->getKind() )
			, sdw::makeExpr( &offset )
			, ast::expr::makeLiteral( m_cache, 0u ) ) );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.makeType( arrayType->getType()->getKind() )
			, sdw::makeExpr( &offset )
			, ast::expr::makeLiteral( m_cache, 1u ) ) );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.makeType( arrayType->getType()->getKind() )
			, sdw::makeExpr( &offset )
			, ast::expr::makeLiteral( m_cache, 2u ) ) );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.makeType( arrayType->getType()->getKind() )
			, sdw::makeExpr( &offset )
			, ast::expr::makeLiteral( m_cache, 3u ) ) );

		if ( needsComp( kind ) )
		{
			// Comp parameter of textureGather can be implicitly 0, in GLSL.
			// Hence add it to args.
			args.push_back( ast::expr::makeLiteral( m_cache, 0 ) );
			kind = getCompAccess( kind );
		}
		else if ( !isShadow( kind ) )
		{
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTexture( ast::expr::TextureAccessCall * expr )
	{
		ast::expr::ExprList args;

		uint32_t index = 0u;
		uint32_t sampler = 0u;

		for ( auto & arg : expr->getArgList() )
		{
			if ( doProcessSampledImageArg( *arg, true, args ) )
			{
				sampler = index;
			}
			else if ( index == sampler + 1
				&& requiresProjTexCoords( expr->getTextureAccess() ) )
			{
				args.emplace_back( writeProjTexCoords( m_cache
					, expr->getTextureAccess()
					, doSubmit( arg.get() ) ) );
			}
			else
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			++index;
		}

		m_result = ast::expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}
}
