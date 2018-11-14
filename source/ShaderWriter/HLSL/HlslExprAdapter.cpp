/*
See LICENSE file in root folder
*/
#include "ShaderWriter/HLSL/HlslExprAdapter.hpp"

#include "ShaderWriter/Intrinsics.hpp"
#include "ShaderWriter/HLSL/HlslHelpers.hpp"
#include "ShaderWriter/HLSL/HlslVariableReplacer.hpp"
#include "ShaderWriter/HLSL/HlslImageAccessConfig.hpp"
#include "ShaderWriter/HLSL/HlslIntrinsicConfig.hpp"
#include "ShaderWriter/HLSL/HlslTextureAccessConfig.hpp"

#include <ASTGenerator/Type/TypeImage.hpp>

namespace sdw::hlsl
{
	namespace
	{
		bool isMatrix( type::Kind kind )
		{
			return kind >= type::Kind::eMat2x2F
				&& kind <= type::Kind::eMat4x4D;
		}

		expr::ExprPtr writeProjectTexCoords2( expr::ExprPtr texcoords )
		{
			expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return expr::makeFnCall( type::getFloat()
				, expr::makeIdentifier( var::makeFunction( "SDW_projectTexCoords2" ) )
				, std::move( args ) );
		}

		expr::ExprPtr writeProjectTexCoords3( expr::ExprPtr texcoords )
		{
			expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return expr::makeFnCall( type::getVec2F()
				, expr::makeIdentifier( var::makeFunction( "SDW_projectTexCoords3" ) )
				, std::move( args ) );
		}

		expr::ExprPtr writeProjectTexCoords4To1( expr::ExprPtr texcoords )
		{
			expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return expr::makeFnCall( type::getFloat()
				, expr::makeIdentifier( var::makeFunction( "SDW_projectTexCoords4To1" ) )
				, std::move( args ) );
		}

		expr::ExprPtr writeProjectTexCoords4To2( expr::ExprPtr texcoords )
		{
			expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return expr::makeFnCall( type::getVec2F()
				, expr::makeIdentifier( var::makeFunction( "SDW_projectTexCoords4To2" ) )
				, std::move( args ) );
		}

		expr::ExprPtr writeProjectTexCoords4( expr::ExprPtr texcoords )
		{
			expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return expr::makeFnCall( type::getVec3F()
				, expr::makeIdentifier( var::makeFunction( "SDW_projectTexCoords4" ) )
				, std::move( args ) );
		}

		expr::ExprPtr writeProjTexCoords( expr::TextureAccess access
			, expr::ExprPtr texcoords )
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
				return writeProjectTexCoords2( std::move( texcoords ) );

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
				return writeProjectTexCoords4To1( std::move( texcoords ) );

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
				return writeProjectTexCoords3( std::move( texcoords ) );

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
				return writeProjectTexCoords4To2( std::move( texcoords ) );

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
				return writeProjectTexCoords4( std::move( texcoords ) );

			default:
				assert( false && "Expected a textureProj access function" );
				return nullptr;
			}
		}

		bool requiresProjTexCoords( expr::TextureAccess access )
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

		expr::TextureAccess getSampleCmp( expr::TextureAccess value )
		{
			assert( value >= expr::TextureAccess::eTextureGrad2DRectShadowF
				&& value <= expr::TextureAccess::eTextureProjGradOffset2DRectShadowF );
			expr::TextureAccess result;

			switch ( value )
			{
			case expr::TextureAccess::eTextureGrad2DRectShadowF:
				result = expr::TextureAccess::eTexture2DRectShadowF;
				break;
			case expr::TextureAccess::eTextureGrad1DShadowF:
				result = expr::TextureAccess::eTexture1DShadowF;
				break;
			case expr::TextureAccess::eTextureGrad2DShadowF:
				result = expr::TextureAccess::eTexture2DShadowF;
				break;
			case expr::TextureAccess::eTextureGrad1DArrayShadowF:
				result = expr::TextureAccess::eTexture1DArrayShadowF;
				break;
			case expr::TextureAccess::eTextureGradOffset2DRectShadowF:
				result = expr::TextureAccess::eTextureOffset2DRectShadowF;
				break;
			case expr::TextureAccess::eTextureGradOffset1DShadowF:
				result = expr::TextureAccess::eTextureOffset1DShadowF;
				break;
			case expr::TextureAccess::eTextureGradOffset2DShadowF:
				result = expr::TextureAccess::eTextureOffset2DShadowF;
				break;
			case expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
				result = expr::TextureAccess::eTextureOffset1DArrayShadowF;
				break;
			case expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
				result = expr::TextureAccess::eTextureOffset2DArrayShadowF;
				break;
			case expr::TextureAccess::eTextureProjGrad1DShadowF:
				result = expr::TextureAccess::eTextureProj1DShadowF;
				break;
			case expr::TextureAccess::eTextureProjGrad2DShadowF:
				result = expr::TextureAccess::eTextureProj2DShadowF;
				break;
			case expr::TextureAccess::eTextureProjGrad2DRectShadowF:
				result = expr::TextureAccess::eTextureProj2DRectShadowF;
				break;
			case expr::TextureAccess::eTextureProjGradOffset1DShadowF:
				result = expr::TextureAccess::eTextureProjOffset1DShadowF;
				break;
			case expr::TextureAccess::eTextureProjGradOffset2DShadowF:
				result = expr::TextureAccess::eTextureProjOffset2DShadowF;
				break;
			case expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
				result = expr::TextureAccess::eTextureProjOffset2DRectShadowF;
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

		bool isShadow( expr::TextureAccess value )
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
			, type::ImageConfiguration const & config )
		{
			return baseName
				+ hlsl::getName( config.dimension )
				+ ( config.isArrayed ? "Array" : "" )
				+ hlsl::getSampledName( config.format );
		}

		type::TypePtr getType( type::ImageFormat format )
		{
			switch ( format )
			{
			case ast::type::ImageFormat::eUnknown:
			case ast::type::ImageFormat::eRgba32f:
			case ast::type::ImageFormat::eRgba16f:
				return type::getVec4F();
			case ast::type::ImageFormat::eRg32f:
			case ast::type::ImageFormat::eRg16f:
				return type::getVec2F();
			case ast::type::ImageFormat::eR32f:
			case ast::type::ImageFormat::eR16f:
				return type::getFloat();
			case ast::type::ImageFormat::eRgba32i:
			case ast::type::ImageFormat::eRgba16i:
			case ast::type::ImageFormat::eRgba8i:
				return type::getVec4I();
			case ast::type::ImageFormat::eRg32i:
			case ast::type::ImageFormat::eRg16i:
			case ast::type::ImageFormat::eRg8i:
				return type::getVec2I();
			case ast::type::ImageFormat::eR32i:
			case ast::type::ImageFormat::eR16i:
			case ast::type::ImageFormat::eR8i:
				return type::getInt();
			case ast::type::ImageFormat::eRgba32u:
			case ast::type::ImageFormat::eRgba16u:
			case ast::type::ImageFormat::eRgba8u:
				return type::getVec4U();
			case ast::type::ImageFormat::eRg32u:
			case ast::type::ImageFormat::eRg16u:
			case ast::type::ImageFormat::eRg8u:
				return type::getVec2U();
			case ast::type::ImageFormat::eR32u:
			case ast::type::ImageFormat::eR16u:
			case ast::type::ImageFormat::eR8u:
				return type::getUInt();
			default:
				assert( false && "hlsl::getType: Unsupported type::ImageFormat" );
				return nullptr;
			}
		}

		expr::ExprPtr swizzleConvert( type::TypePtr dst
			, expr::ExprPtr expr )
		{
			expr::SwizzleKind swizzle;
			auto srcCount = getComponentCount( expr->getType()->getKind() );
			auto dstCount = getComponentCount( dst->getKind() );

			switch ( srcCount )
			{
			case 1:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e00;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e000;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0000;
					break;
				}
				break;
			case 2:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e011;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0111;
					break;
				}
				break;
			case 3:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0122;
					break;
				}
				break;
			case 4:
				switch ( dstCount )
				{
				case 1:
					swizzle = expr::SwizzleKind::e0;
					break;
				case 2:
					swizzle = expr::SwizzleKind::e01;
					break;
				case 3:
					swizzle = expr::SwizzleKind::e012;
					break;
				case 4:
					swizzle = expr::SwizzleKind::e0123;
					break;
				}
				break;
			}

			return std::make_unique< expr::Swizzle >( std::move( expr )
				, swizzle );
		}

		expr::ExprPtr componentCastConvert( type::TypePtr dst
			, expr::ExprPtr expr )
		{
			return expr::makeCast( dst, std::move( expr ) );
		}

		expr::ExprPtr convert( type::TypePtr dst
			, expr::ExprPtr expr )
		{
			auto srcCount = getComponentCount( expr->getType()->getKind() );
			auto dstCount = getComponentCount( dst->getKind() );
			expr::ExprPtr result = std::move( expr );

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
	}

	expr::ExprPtr ExprAdapter::submit( expr::Expr * expr
		, IntrinsicsConfig const & config
		, LinkedVars const & linkedVars
		, VariableExprMap const & inputMembers
		, VariableExprMap const & outputMembers
		, stmt::Container * intrinsics )
	{
		expr::ExprPtr result;
		ExprAdapter vis
		{
			result,
			config,
			linkedVars,
			inputMembers,
			outputMembers,
			intrinsics,
		};
		expr->accept( &vis );
		return result;
	}
			
	expr::ExprPtr ExprAdapter::submit( expr::ExprPtr const & expr
		, IntrinsicsConfig const & config
		, LinkedVars const & linkedVars
		, VariableExprMap const & inputMembers
		, VariableExprMap const & outputMembers
		, stmt::Container * intrinsics )
	{
		return submit( expr.get()
			, config
			, linkedVars
			, inputMembers
			, outputMembers
			, intrinsics );
	}

	ExprAdapter::ExprAdapter( expr::ExprPtr & result
		, IntrinsicsConfig const & config
		, LinkedVars const & linkedVars
		, VariableExprMap const & inputMembers
		, VariableExprMap const & outputMembers
		, stmt::Container * intrinsics )
		: ExprCloner{ result }
		, m_config{ config }
		, m_linkedVars{ linkedVars }
		, m_inputMembers{ inputMembers }
		, m_outputMembers{ outputMembers }
		, m_intrinsics{ intrinsics }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr * expr )
	{
		expr::ExprPtr result;
		ExprAdapter vis
		{
			result,
			m_config,
			m_linkedVars,
			m_inputMembers,
			m_outputMembers,
			m_intrinsics,
		};
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitIdentifierExpr( expr::Identifier * expr )
	{
		auto itInputs = m_inputMembers.find( expr->getVariable() );
		auto itOutputs = m_outputMembers.find( expr->getVariable() );

		if ( m_inputMembers.end() != itInputs )
		{
			m_result = makeExpr( itInputs->second );
		}
		else if ( m_outputMembers.end() != itOutputs )
		{
			m_result = makeExpr( itOutputs->second );
		}
		else
		{
			m_result = expr::makeIdentifier( expr->getVariable() );
		}
	}

	void ExprAdapter::visitCompositeConstructExpr( expr::CompositeConstruct * expr )
	{
		if ( expr->getArgList().size() == 1u
			&& getComponentCount( expr->getArgList().back()->getType()->getKind() ) == 1u
			&& isVectorType( expr->getType()->getKind() ) )
		{
			auto count = getComponentCount( expr->getType()->getKind() );
			m_result = std::make_unique< expr::Swizzle >( doSubmit( expr->getArgList().back().get() )
				, ( count == 2u
					? expr::SwizzleKind::e00
					: ( count == 3u
						? expr::SwizzleKind::e000
						: expr::SwizzleKind::e0000 ) ) );
		}
		else
		{
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeCompositeConstruct( expr->getComposite()
				, expr->getComponent()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitFnCallExpr( expr::FnCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			auto ident = findIdentifier( arg );

			if ( ident )
			{
				auto it = m_linkedVars.find( ident->getVariable() );

				if ( m_linkedVars.end() != it )
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

		m_result = expr::makeFnCall( expr->getType()
			, makeIdent( expr->getFn()->getVariable() )
			, std::move( args ) );
	}

	void ExprAdapter::visitImageAccessCallExpr( expr::ImageAccessCall * expr )
	{
		if ( expr->getImageAccess() >= expr::ImageAccess::eImageSize1DF
			&& expr->getImageAccess() <= expr::ImageAccess::eImageSize2DMSArrayU )
		{
			m_result = doProcessImageSize( expr );
		}
		else if ( expr->getImageAccess() >= expr::ImageAccess::eImageLoad1DF
			&& expr->getImageAccess() <= expr::ImageAccess::eImageLoad2DMSArrayU )
		{
			m_result = doProcessImageLoad( expr );
		}
		else
		{
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeImageAccessCall( expr->getType()
				, expr->getImageAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( expr::IntrinsicCall * expr )
	{
		auto instantChange = getInstantChange( expr->getIntrinsic() );

		if ( instantChange.toOperator )
		{
			switch ( instantChange.operatorKind )
			{
			case expr::Kind::eLess:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeLess( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;
				
			case expr::Kind::eLessEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeLessEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eGreater:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeGreater( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eGreaterEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeGreaterEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eNotEqual:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeNotEqual( doSubmit( expr->getArgList()[0].get() )
					, doSubmit( expr->getArgList()[1].get() ) );
				break;

			case expr::Kind::eLogNot:
				assert( expr->getArgList().size() == 1u );
				m_result = expr::makeLogNot( doSubmit( expr->getArgList()[0].get() ) );
				break;

			case expr::Kind::eTimes:
				assert( expr->getArgList().size() == 2u );
				m_result = expr::makeTimes( expr->getArgList()[0].get()->getType()
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
			expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = expr::makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitTextureAccessCallExpr( expr::TextureAccessCall * expr )
	{
		if ( ( expr->getTextureAccess() >= expr::TextureAccess::eTextureSize1DF
				&& expr->getTextureAccess() <= expr::TextureAccess::eTextureSizeBufferU )
			|| ( expr->getTextureAccess() >= expr::TextureAccess::eTextureQueryLevels1DF
				&& expr->getTextureAccess() <= expr::TextureAccess::eTextureQueryLevelsCubeArrayU ) )
		{
			doProcessTextureQueries( expr );
		}
		else if ( expr->getTextureAccess() >= expr::TextureAccess::eTexelFetch1DF
			&& expr->getTextureAccess() <= expr::TextureAccess::eTexelFetchOffset2DArrayU )
		{
			doProcessTexelFetch( expr );
		}
		else if ( expr->getTextureAccess() >= expr::TextureAccess::eTextureGrad2DRectShadowF
			&& expr->getTextureAccess() <= expr::TextureAccess::eTextureProjGradOffset2DRectShadowF
			&& m_config.requiresShadowSampler )
		{
			doProcessTextureGradShadow( expr );
		}
		else if ( ( expr->getTextureAccess() >= expr::TextureAccess::eTextureGather2DF
				&& expr->getTextureAccess() <= expr::TextureAccess::eTextureGatherOffset2DRectUComp )
			|| ( expr->getTextureAccess() >= expr::TextureAccess::eTextureGather2DShadowF
				&& expr->getTextureAccess() <= expr::TextureAccess::eTextureGatherOffset2DRectShadowF ) )
		{
			doProcessTextureGather( expr );
		}
		else if ( ( expr->getTextureAccess() >= expr::TextureAccess::eTextureGatherOffsets2DF
				&& expr->getTextureAccess() <= expr::TextureAccess::eTextureGatherOffsets2DRectUComp )
			|| ( expr->getTextureAccess() >= expr::TextureAccess::eTextureGatherOffsets2DShadowF
				&& expr->getTextureAccess() <= expr::TextureAccess::eTextureGatherOffsets2DRectShadowF ) )
		{
			doProcessTextureGatherOffsets( expr );
		}
		else
		{
			doProcessTexture( expr );
		}
	}

	void ExprAdapter::visitTimesExpr( expr::Times * expr )
	{
		if ( isMatrix( expr->getType()->getKind() ) )
		{
			expr::ExprList argsList;
			argsList.emplace_back( doSubmit( expr->getLHS() ) );
			argsList.emplace_back( doSubmit( expr->getRHS() ) );
			m_result = expr::makeFnCall( expr->getType()
				, expr::makeIdentifier( var::makeVariable( type::getFunction(), "mul" ) )
				, std::move( argsList ) );
		}
		else
		{
			m_result = expr::makeTimes( expr->getType()
				, doSubmit( expr->getLHS() )
				, doSubmit( expr->getRHS() ) );
		}
	}

	bool ExprAdapter::doProcessSampledImageArg( expr::Expr & arg
		, bool writeSampler
		, expr::ExprList & args )
	{
		bool result = arg.getKind() == expr::Kind::eIdentifier;

		if ( result )
		{
			auto ident = findIdentifier( &arg );
			auto it = m_linkedVars.find( ident->getVariable() );

			if ( m_linkedVars.end() != it )
			{
				args.emplace_back( makeIdent( it->second.first ) );

				if ( writeSampler )
				{
					args.emplace_back( makeIdent( it->second.second ) );
				}
			}
			else
			{
				args.emplace_back( doSubmit( &arg ) );
			}
		}

		return result;
	}

	expr::ExprPtr ExprAdapter::doProcessImageSize( expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_imageSize", config );
		auto it = m_imageSizeFuncs.find( funcName );

		if ( it == m_imageSizeFuncs.end() )
		{
			var::VariableList parameters;
			auto image = var::makeVariable( expr->getArgList()[0]->getType(), "image" );
			parameters.emplace_back( image );
			auto cont = stmt::makeFunctionDecl( expr->getType()
				, funcName
				, parameters );
			type::TypePtr uintType = type::getUInt();
			var::VariableList resVars;
			expr::CompositeType composite{};

			switch ( getComponentCount( expr->getType()->getKind() ) )
			{
			case 1:
			{
				resVars.emplace_back( var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( stmt::makeVariableDecl( resVars.back() ) );
				composite = expr::CompositeType::eScalar;
			}
			break;
			case 2:
			{
				resVars.emplace_back( var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( stmt::makeVariableDecl( resVars.back() ) );
				composite = expr::CompositeType::eVec2;
			}
			break;
			case 3:
			{
				resVars.emplace_back( var::makeVariable( uintType, "dimX" ) );
				cont->addStmt( stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( var::makeVariable( uintType, "dimY" ) );
				cont->addStmt( stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( var::makeVariable( uintType, "dimZ" ) );
				cont->addStmt( stmt::makeVariableDecl( resVars.back() ) );
				composite = expr::CompositeType::eVec3;
			}
			break;
			}

			// The call to image.GetDimensions
			expr::ExprList callArgs;

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( expr::makeIdentifier( var ) );
			}

			if ( config.dimension == type::ImageDim::eCube
				&& !config.isArrayed )
			{
				auto var = var::makeVariable( uintType, "dummy" );
				cont->addStmt( stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( expr::makeIdentifier( var ) );
			}

			cont->addStmt( stmt::makeSimple( expr::makeMemberFnCall( type::getVoid()
				, makeIdent( var::makeFunction( "GetDimensions" ) )
				, makeIdent( image )
				, std::move( callArgs ) ) ) );

			// The return statement
			expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( expr::makeCast( type::getInt()
					, expr::makeIdentifier( var ) ) );
			}

			if ( composite == expr::CompositeType::eScalar )
			{
				cont->addStmt( stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( stmt::makeReturn( expr::makeCompositeConstruct( composite
					, type::Kind::eInt
					, std::move( resArgs ) ) ) );
			}

			it = m_imageSizeFuncs.emplace( funcName
				, static_cast< stmt::Return const & >( *cont->back() ).getExpr()->getType() ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		expr::ExprList argList;
		argList.emplace_back( doSubmit( expr->getArgList().front().get() ) );
		return expr::makeFnCall( it->second
			, expr::makeIdentifier( var::makeFunction( funcName ) )
			, std::move( argList ) );
	}

	expr::ExprPtr ExprAdapter::doProcessImageLoad( expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = getType( config.format );
		expr::ExprPtr result;
		expr::ExprList argList;

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			argList.emplace_back( doSubmit( it->get() ) );
		}

		result = expr::makeMemberFnCall( callRetType
			, expr::makeIdentifier( var::makeFunction( "Load" ) )
			, doSubmit( expr->getArgList().front().get() )
			, std::move( argList ) );

		if ( expr->getType() != callRetType )
		{
			// We'll need to add a swizzle
			result = convert( expr->getType(), std::move( result ) );
		}

		return result;
	}

	void ExprAdapter::doProcessTextureQueries( expr::TextureAccessCall * expr )
	{
		expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			if ( !doProcessSampledImageArg( *arg, false, args ) )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTexelFetch( expr::TextureAccessCall * expr )
	{
		expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessSampledImageArg( *expr->getArgList()[0], false, args );
		assert( isImage );

		if ( expr->getTextureAccess() == expr::TextureAccess::eTexelFetchBufferF
			|| expr->getTextureAccess() == expr::TextureAccess::eTexelFetchBufferI
			|| expr->getTextureAccess() == expr::TextureAccess::eTexelFetchBufferU )
		{
			// For those texel fetch functions, no lod, and none needed.
			assert( expr->getArgList().size() >= 2u );
			args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
		}
		else
		{
			expr::ExprList merged;

			if ( expr->getTextureAccess() == expr::TextureAccess::eTexelFetch2DRectF
				|| expr->getTextureAccess() == expr::TextureAccess::eTexelFetch2DRectI
				|| expr->getTextureAccess() == expr::TextureAccess::eTexelFetch2DRectU )
			{
				// For those texel fetch functions, no lod, hence create a 0 lod.
				assert( expr->getArgList().size() >= 2u );
				// Merge second and literal(0) parameters to the appropriate vector type (int=>ivec2, ivec2=>ivec3, ivec3=>ivec4).
				merged.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
				merged.emplace_back( expr::makeLiteral( 0 ) );
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
			case type::Kind::eInt:
				args.emplace_back( sdw::makeFnCall( type::makeType( typeEnum< IVec2 > )
					, sdw::makeIdent( var::makeFunction( "int2" ) )
					, std::move( merged ) ) );
				break;
			case type::Kind::eVec2I:
				args.emplace_back( sdw::makeFnCall( type::makeType( typeEnum< IVec3 > )
					, sdw::makeIdent( var::makeFunction( "int3" ) )
					, std::move( merged ) ) );
				break;
			case type::Kind::eVec3I:
				args.emplace_back( sdw::makeFnCall( type::makeType( typeEnum< IVec4 > )
					, sdw::makeIdent( var::makeFunction( "int4" ) )
					, std::move( merged ) ) );
				break;
			}
		}

		// Other parameters remain unchanged.
		for ( size_t i = 3u; i < expr->getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( expr->getArgList()[i].get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGradShadow( expr::TextureAccessCall * expr )
	{
		// Sample grad doesn't support SampleComparisonState, replace it with a SampleCmp.
		expr::ExprList args;
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

		auto result = expr::makeTextureAccessCall( expr->getType()
			, getSampleCmp( expr->getTextureAccess() )
			, std::move( args ) );

		// Reparse the created expression, textureProj cases.
		visitTextureAccessCallExpr( result.get() );
	}

	void ExprAdapter::doProcessTextureGather( expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		assert( expr->getArgList().size() >= 2u );
		uint32_t index = 0u;
		expr::ExprList args;
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
			args.push_back( expr::makeLiteral( 0 ) );
			kind = getCompAccess( kind );
		}
		else if ( !isShadow( kind ) )
		{
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGatherOffsets( expr::TextureAccessCall * expr )
	{
		auto kind = expr->getTextureAccess();
		assert( expr->getArgList().size() >= 3u );
		uint32_t index = 0u;
		expr::ExprList args;
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
		assert( offset.getType()->getArraySize() >= 4u );
		args.emplace_back( expr::makeArrayAccess( type::makeType( offset.getType()->getKind() )
			, makeExpr( &offset )
			, expr::makeLiteral( 0u ) ) );
		args.emplace_back( expr::makeArrayAccess( type::makeType( offset.getType()->getKind() )
			, makeExpr( &offset )
			, expr::makeLiteral( 1u ) ) );
		args.emplace_back( expr::makeArrayAccess( type::makeType( offset.getType()->getKind() )
			, makeExpr( &offset )
			, expr::makeLiteral( 2u ) ) );
		args.emplace_back( expr::makeArrayAccess( type::makeType( offset.getType()->getKind() )
			, makeExpr( &offset )
			, expr::makeLiteral( 3u ) ) );

		if ( needsComp( kind ) )
		{
			// Comp parameter of textureGather can be implicitly 0, in GLSL.
			// Hence add it to args.
			args.push_back( expr::makeLiteral( 0 ) );
			kind = getCompAccess( kind );
		}
		else if ( !isShadow( kind ) )
		{
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTexture( expr::TextureAccessCall * expr )
	{
		expr::ExprList args;

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
				args.emplace_back( writeProjTexCoords( expr->getTextureAccess(), doSubmit( arg.get() ) ) );
			}
			else
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			++index;
		}

		m_result = expr::makeTextureAccessCall( expr->getType()
			, expr->getTextureAccess()
			, std::move( args ) );
	}
}
