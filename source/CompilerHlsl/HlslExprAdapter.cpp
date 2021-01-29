/*
See LICENSE file in root folder
*/
#include "HlslExprAdapter.hpp"

#include "HlslHelpers.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslImageAccessConfig.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslTextureAccessConfig.hpp"

#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeSampledImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <algorithm>
#include <stdexcept>

namespace hlsl
{
	namespace
	{
		bool isMatrix( ast::type::Kind kind )
		{
			return kind >= ast::type::Kind::eMat2x2F
				&& kind <= ast::type::Kind::eMat4x4D;
		}

		ast::type::Kind getBuiltinHlslKind( std::string const & name
			, ast::type::Kind input )
		{
			ast::type::Kind result = input;

			if ( name == "gl_VertexID"
				|| name == "gl_VertexIndex"
				|| name == "gl_InstanceID"
				|| name == "gl_InstanceIndex"
				|| name == "gl_DrawID"
				|| name == "gl_BaseVertex"
				|| name == "gl_BaseInstance"
				|| name == "gl_PatchVerticesIn"
				|| name == "gl_PrimitiveID"
				|| name == "gl_InvocationID"
				|| name == "gl_PrimitiveIDIn"
				|| name == "gl_SampleID"
				|| name == "gl_Layer"
				|| name == "gl_ViewportIndex" )
			{
				result = ast::type::Kind::eUInt;
			}

			return result;
		}

		ast::expr::ExprPtr writeProjectTexCoords2( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( cache.getVec2F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getFloat()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( cache.getFunction( cache.getFloat(), params )
					, "SDW_projectTexCoords2" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords3( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( cache.getVec3F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec2F()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( cache.getFunction( cache.getVec2F(), params )
					, "SDW_projectTexCoords3" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords4To1( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( cache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getFloat()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( cache.getFunction( cache.getFloat(), params )
					, "SDW_projectTexCoords4To1" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords4To2( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( cache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec2F()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( cache.getFunction( cache.getVec2F(), params )
					, "SDW_projectTexCoords4To2" ) )
				, std::move( args ) );
		}

		ast::expr::ExprPtr writeProjectTexCoords4( ast::type::TypesCache & cache
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( cache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec3F()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( cache.getFunction( cache.getVec3F(), params )
					, "SDW_projectTexCoords4" ) )
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

			default:
				break;
			}

			return result;
		}

		ast::expr::TextureAccess getSampleCmp( ast::expr::TextureAccess value )
		{
			assert( value >= ast::expr::TextureAccess::eTextureGrad2DRectShadowF
				&& value <= ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF );
			ast::expr::TextureAccess result{};

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
			default:
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

		ast::expr::ExprPtr registerBuiltinInputVar( ast::type::TypesCache & cache
			, ast::var::VariablePtr var
			, AdaptationData & adaptationData )
		{
			auto it = adaptationData.inputMembers.find( var );

			if ( it == adaptationData.inputMembers.end() )
			{
				auto hlslKind = getBuiltinHlslKind( var->getName()
					, var->getType()->getKind() );

				if ( hlslKind != var->getType()->getKind() )
				{
					var = ast::var::makeVariable( cache.getBasicType( hlslKind )
						, var->getName() );
				}

				adaptationData.inputVars.emplace( 128, var );
				auto index = adaptationData.globalInputStruct->findMember( var->getName() );

				if ( index == ast::type::Struct::NotFound )
				{
					if ( var->getType()->getKind() == ast::type::Kind::eStruct )
					{
						adaptationData.globalInputStruct->declMember( var->getName()
							, std::static_pointer_cast< ast::type::Struct >( var->getType() ) );
					}
					else if ( var->getType()->getKind() == ast::type::Kind::eArray )
					{
						adaptationData.globalInputStruct->declMember( var->getName()
							, std::static_pointer_cast< ast::type::Array >( var->getType() ) );
					}
					else
					{
						adaptationData.globalInputStruct->declMember( var->getName()
							, var->getType() );
					}

					index = adaptationData.globalInputStruct->findMember( var->getName() );
				}

				it = adaptationData.inputMembers.emplace( var
					, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( cache, adaptationData.inputVar )
						, index
						, var->getFlags() ) ).first;
			}

			return ast::ExprCloner::submit( it->second );
		}

		ast::expr::ExprPtr registerBuiltinOutputVar( ast::type::TypesCache & cache
			, ast::var::VariablePtr var
			, AdaptationData & adaptationData )
		{
			ast::expr::ExprPtr save{ nullptr };
			ast::expr::Expr * toClone{ nullptr };
			auto it = adaptationData.outputMembers.find( var );

			if ( it == adaptationData.outputMembers.end() )
			{
				adaptationData.outputVars.emplace( 128, var );
				bool added = false;

				if ( var->getType()->getKind() == ast::type::Kind::eStruct )
				{
					if ( std::static_pointer_cast< ast::type::Struct >( var->getType() )->getName() != "gl_PerVertex" )
					{
						adaptationData.globalOutputStruct->declMember( var->getName()
							, std::static_pointer_cast< ast::type::Struct >( var->getType() ) );
						added = true;
					}
				}
				else if ( var->getType()->getKind() == ast::type::Kind::eArray )
				{
					adaptationData.globalOutputStruct->declMember( var->getName()
						, std::static_pointer_cast< ast::type::Array >( var->getType() ) );
					added = true;
				}
				else
				{
					adaptationData.globalOutputStruct->declMember( var->getName()
						, var->getType() );
					added = true;
				}

				if ( added )
				{
					it = adaptationData.outputMembers.emplace( var
						, ast::expr::makeMbrSelect( ast::expr::makeIdentifier( cache, adaptationData.outputVar )
							, uint32_t( adaptationData.outputMembers.size() )
							, var->getFlags() ) ).first;
					toClone = it->second.get();
				}
				else
				{
					save = ast::expr::makeIdentifier( cache, adaptationData.outputVar );
					toClone = save.get();
				}
			}

			return ast::ExprCloner::submit( toClone );
		}

		ast::expr::ExprPtr registerBuiltinVar( ast::type::TypesCache & cache
			, ast::var::VariablePtr var
			, AdaptationData & adaptationData )
		{
			ast::expr::ExprPtr result;

			if ( var->isShaderInput() )
			{
				result = registerBuiltinInputVar( cache, var, adaptationData );
			}
			else
			{
				result = registerBuiltinOutputVar( cache, var, adaptationData );
			}

			return result;
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::Expr * expr
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis
		{
			cache,
			result,
			container,
			intrinsicsConfig,
			writerConfig,
			adaptationData,
			intrinsics,
		};
		expr->accept( &vis );
		return result;
	}
			
	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::ExprPtr const & expr
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics )
	{
		return submit( cache
			, expr.get()
			, container
			, intrinsicsConfig
			, writerConfig
			, adaptationData
			, intrinsics );
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::expr::ExprPtr & result
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_container{ container }
		, m_intrinsicsConfig{ intrinsicsConfig }
		, m_writerConfig{ writerConfig }
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
			m_container,
			m_intrinsicsConfig,
			m_writerConfig,
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
			m_result = registerBuiltinVar( m_cache, var, m_adaptationData );
		}
		else
		{
			auto itInputs = m_adaptationData.inputMembers.find( var );
			auto itOutputs = m_adaptationData.outputMembers.find( var );
			auto itReplaced = m_adaptationData.replacedVars.find( var );

			if ( m_adaptationData.inputMembers.end() != itInputs )
			{
				m_result = ast::ExprCloner::submit( itInputs->second );
			}
			else if ( m_adaptationData.outputMembers.end() != itOutputs )
			{
				m_result = ast::ExprCloner::submit( itOutputs->second );
			}
			else if ( m_adaptationData.replacedVars.end() != itReplaced )
			{
				m_result = ast::ExprCloner::submit( itReplaced->second );
			}
			else
			{
				m_result = ast::expr::makeIdentifier( m_cache, var );
			}
		}

		updateLinkedVars( var, m_adaptationData.linkedVars );
	}

	void ExprAdapter::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
		bool processed = false;

		if ( expr->getArgList().size() == 1u )
		{
			auto arg = expr->getArgList().back().get();

			if ( getComponentCount( arg->getType()->getKind() ) == 1u
				&& isVectorType( expr->getType()->getKind() ) )
			{
				auto count = getComponentCount( expr->getType()->getKind() );

				if ( arg->getKind() == ast::expr::Kind::eLiteral )
				{
					ast::expr::ExprList args;

					for ( auto i = 0u; i < count; ++i )
					{
						args.emplace_back( doSubmit( arg ) );
					}

					m_result = ast::expr::makeCompositeConstruct( expr->getComposite()
						, expr->getComponent()
						, std::move( args ) );
					processed = true;
				}
				else
				{
					m_result = std::make_unique< ast::expr::Swizzle >( doSubmit( arg )
						, ( count == 2u
							? ast::expr::SwizzleKind::e00
							: ( count == 3u
								? ast::expr::SwizzleKind::e000
								: ast::expr::SwizzleKind::e0000 ) ) );
					processed = true;
				}
			}
			else if ( isMatrixType( expr->getType()->getKind() )
				&& isMatrixType( arg->getType()->getKind() )
				&& expr->getType()->getKind() != arg->getType()->getKind() )
			{
				// Function-like cast to matrix of another type, make it a cast.
				m_result = ast::expr::makeCast( expr->getType()
					, doSubmit( arg ) );
				processed = true;
			}
		}

		if ( !processed )
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_result = ast::expr::makeCompositeConstruct( expr->getComposite()
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
				auto var = ident->getVariable();
				auto it = updateLinkedVars( var, m_adaptationData.linkedVars );

				if ( m_adaptationData.linkedVars.end() != it )
				{
					args.emplace_back( VariableReplacer::submit( arg, var, it->second.first ) );
					args.emplace_back( VariableReplacer::submit( arg, var, it->second.second ) );
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
			, ast::expr::makeIdentifier( m_cache, expr->getFn()->getVariable() )
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
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageStore2DMSArrayU )
		{
			doProcessImageStore( expr, m_adaptationData.funcs.imageStoreFuncs );
		}
		else if ( expr->getImageAccess() >= ast::expr::ImageAccess::eImageAtomicAdd1DU
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicAdd2DMSArrayF )
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
			&& expr->getImageAccess() <= ast::expr::ImageAccess::eImageAtomicExchange2DMSArrayF )
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
		auto adaptationInfo = getAdaptationInfo( expr->getIntrinsic() );

		if ( adaptationInfo.operatorChange.toOperator )
		{
			switch ( adaptationInfo.operatorChange.operatorKind )
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
		else if ( adaptationInfo.atomicChange.isAtomic )
		{
			// GLSL atomics return the old value, while in HLSL it is the last parameter
			// Hence, we first create the output value variable.
			auto aliasVar = doMakeAlias( expr->getType() );
			m_container->addStmt( ast::stmt::makeVariableDecl( aliasVar ) );
			// We then parse the parameters.
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			// We add the created output alias to the parameters list.
			args.emplace_back( ast::expr::makeIdentifier( m_cache, aliasVar ) );
			// We add the call to the intrinsic, and add it to the container
			m_container->addStmt( ast::stmt::makeSimple( ast::expr::makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) ) ) );
			// The resulting expression is now the alias.
			m_result = ast::expr::makeIdentifier( m_cache, aliasVar );
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
		auto processed = false;

		if ( expr->getOuterExpr()->getKind() == ast::expr::Kind::eIdentifier )
		{
			auto var = static_cast< ast::expr::Identifier const * >( expr->getOuterExpr() )->getVariable();

			if ( var->isBuiltin()
				&& var->getType()->getKind() == ast::type::Kind::eStruct )
			{
				auto mbrName = ( static_cast< ast::type::Struct const & >( *var->getType() ).begin() + expr->getMemberIndex() )->name;

				auto it = std::find_if( m_adaptationData.outputVars.begin()
					, m_adaptationData.outputVars.end()
					, [&mbrName]( VariableIdMap::value_type const & lookup )
					{
						return mbrName == lookup.second->getName();
					} );

				if ( it != m_adaptationData.outputVars.end() )
				{
					auto itMbr = m_adaptationData.outputMembers.find( it->second );

					if ( itMbr != m_adaptationData.outputMembers.end() )
					{
						m_result = ast::ExprCloner::submit( itMbr->second );
						processed = true;
					}
				}
			}
			else
			{
				auto it = std::find( m_adaptationData.ssboList.begin()
					, m_adaptationData.ssboList.end()
					, var );

				if ( it != m_adaptationData.ssboList.end() )
				{
					auto var = ast::var::makeVariable( expr->getType()
						, expr->getOuterType()->getMember( expr->getMemberIndex() ).name
						, expr->getMemberFlags() );
					m_result = ast::expr::makeIdentifier( m_cache, var );
					processed = true;
				}
			}
		}

		if ( !processed )
		{
			m_result = ast::expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
				, expr->getMemberIndex()
				, expr->getMemberFlags() );
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
			&& m_intrinsicsConfig.requiresShadowSampler )
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
		if ( isMatrix( expr->getType()->getKind() )
			|| isMatrix( expr->getLHS()->getType()->getKind() )
			|| isMatrix( expr->getRHS()->getType()->getKind() ) )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( expr->getLHS()->getType(), "lhs" ) );
			params.push_back( ast::var::makeVariable( expr->getRHS()->getType(), "rhs" ) );
			ast::expr::ExprList argsList;
			argsList.emplace_back( doSubmit( expr->getLHS() ) );
			argsList.emplace_back( doSubmit( expr->getRHS() ) );
			m_result = ast::expr::makeFnCall( expr->getType()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeVariable( m_cache.getFunction( expr->getType(), params )
					, "mul" ) )
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
		bool result = arg.getKind() == ast::expr::Kind::eIdentifier
			|| arg.getKind() == ast::expr::Kind::eArrayAccess;

		if ( result )
		{
			auto ident = ast::findIdentifier( &arg );
			auto it = m_adaptationData.linkedVars.find( ident->getVariable() );

			if ( m_adaptationData.linkedVars.end() != it )
			{
				if ( arg.getKind() == ast::expr::Kind::eArrayAccess )
				{
					args.emplace_back( ast::expr::makeArrayAccess( it->second.first->getType()
						, ast::expr::makeIdentifier( m_cache, it->second.first )
						, doSubmit( static_cast< ast::expr::ArrayAccess const & >( arg ).getRHS() ) ) );

					if ( writeSampler )
					{
						args.emplace_back( ast::expr::makeArrayAccess( it->second.second->getType()
							, ast::expr::makeIdentifier( m_cache, it->second.second )
							, doSubmit( static_cast< ast::expr::ArrayAccess const & >( arg ).getRHS() ) ) );
					}
				}
				else
				{
					args.emplace_back( ast::expr::makeIdentifier( m_cache, it->second.first ) );

					if ( writeSampler )
					{
						args.emplace_back( ast::expr::makeIdentifier( m_cache, it->second.second ) );
					}
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
		auto it = m_adaptationData.funcs.imageSizeFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageSizeFuncs.end() )
		{
			ast::var::VariableList resVars;
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( expr->getArgList()[0]->getType(), "image" );
			parameters.emplace_back( image );
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			ast::type::TypePtr uintType = m_cache.getUInt();
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
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
			}

			if ( config.dimension == ast::type::ImageDim::eCube
				&& !config.isArrayed )
			{
				auto var = ast::var::makeVariable( uintType, "dummy" );
				cont->addStmt( ast::stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
			}

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( m_cache.getFunction( m_cache.getVoid(), resVars )
					, "GetDimensions" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( ast::expr::makeCast( m_cache.getInt()
					, ast::expr::makeIdentifier( m_cache, var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( ast::stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( composite
					, ast::type::Kind::eInt
					, std::move( resArgs ) ) ) );
			}

			it = m_adaptationData.funcs.imageSizeFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		argList.emplace_back( doSubmit( expr->getArgList().front().get() ) );
		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second
				, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageLoad( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = m_cache.getSampledType( config.format );
		ast::expr::ExprList argList;
		ast::var::VariableList paramList;
		uint32_t index = 0u;
		paramList.emplace_back( ast::var::makeVariable( expr->getArgList().front()->getType()
			, "p" + std::to_string( index++ ) ) );

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			argList.emplace_back( doSubmit( it->get() ) );
			paramList.emplace_back( ast::var::makeVariable( argList.back()->getType()
				, "p" + std::to_string( index++ ) ) );
		}

		m_result = ast::expr::makeMemberFnCall( callRetType
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( m_cache.getFunction( expr->getType(), paramList )
				, "Load" ) )
			, doSubmit( expr->getArgList().front().get() )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageStore( ast::expr::ImageAccessCall * expr
		, std::map< std::string, ast::type::FunctionPtr > & imageStoreFuncs )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_imageStore", config );
		auto it = imageStoreFuncs.find( funcName );

		if ( it == imageStoreFuncs.end() )
		{
			auto & args = expr->getArgList();
			auto hasSample = expr->getImageAccess() == ast::expr::ImageAccess::eImageStore2DMSF
				|| expr->getImageAccess() == ast::expr::ImageAccess::eImageStore2DMSArrayF
				|| expr->getImageAccess() == ast::expr::ImageAccess::eImageStore2DMSI
				|| expr->getImageAccess() == ast::expr::ImageAccess::eImageStore2DMSArrayI
				|| expr->getImageAccess() == ast::expr::ImageAccess::eImageStore2DMSU
				|| expr->getImageAccess() == ast::expr::ImageAccess::eImageStore2DMSArrayU;
			auto dataType = args.back()->getType();
			ast::var::VariableList parameters;
			parameters.push_back( ast::var::makeVariable( expr->getArgList()[0]->getType(), "image" ) );
			parameters.push_back( ast::var::makeVariable( expr->getArgList()[1]->getType(), "coord" ) );

			if ( hasSample )
			{
				parameters.push_back( ast::var::makeVariable( expr->getArgList()[2]->getType(), "sample" ) );
			}

			parameters.push_back( ast::var::makeVariable( dataType, "data" ) );
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			// Function content
			//	image[coord] = data
			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeAssign( dataType
				, std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
					, ast::expr::makeIdentifier( m_cache, parameters[0] )
					, ast::expr::makeIdentifier( m_cache, parameters[1] ) )
				, ast::expr::makeIdentifier( m_cache, parameters.back() ) ) ) );

			it = imageStoreFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			argList.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomic( ast::expr::ImageAccessCall * expr
		, std::string const & name
		, std::map< std::string, ast::type::FunctionPtr > & imageAtomicFuncs )
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
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			// Function content
			auto res = ast::var::makeVariable( dataType, "res" );
			cont->addStmt( ast::stmt::makeVariableDecl( res ) );

			//	The call to Interlocked<name>
			ast::expr::ExprList callArgs;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
				, ast::expr::makeIdentifier( m_cache, image )
				, ast::expr::makeIdentifier( m_cache, coord ) ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p0" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, data ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p1" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, res ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p2" ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( m_cache.getFunction( m_cache.getVoid(), callParameters )
					, "Interlocked" + name ) )
				, std::move( callArgs ) ) ) );

			//	The return statement
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( m_cache, res ) ) );

			it = imageAtomicFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			argList.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomicAdd( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Add", m_adaptationData.funcs.imageAtomicAddFuncs );
	}

	void ExprAdapter::doProcessImageAtomicMin( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Min", m_adaptationData.funcs.imageAtomicMinFuncs );
	}

	void ExprAdapter::doProcessImageAtomicMax( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Max", m_adaptationData.funcs.imageAtomicMaxFuncs );
	}

	void ExprAdapter::doProcessImageAtomicAnd( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "And", m_adaptationData.funcs.imageAtomicAndFuncs );
	}

	void ExprAdapter::doProcessImageAtomicOr( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Or", m_adaptationData.funcs.imageAtomicOrFuncs );
	}

	void ExprAdapter::doProcessImageAtomicXor( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Xor", m_adaptationData.funcs.imageAtomicXorFuncs );
	}

	void ExprAdapter::doProcessImageAtomicExchange( ast::expr::ImageAccessCall * expr )
	{
		doProcessImageAtomic( expr, "Exchange", m_adaptationData.funcs.imageAtomicExchangeFuncs );
	}

	void ExprAdapter::doProcessImageAtomicCompSwap( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_imageAtomicCompSwap", config );
		auto it = m_adaptationData.funcs.imageAtomicCompSwapFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageAtomicCompSwapFuncs.end() )
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
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			// Function content
			auto res = ast::var::makeVariable( dataType, "res" );
			cont->addStmt( ast::stmt::makeVariableDecl( res ) );

			//	The call to InterlockedCompareExchange
			ast::expr::ExprList callArgs;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
				, ast::expr::makeIdentifier( m_cache, image )
				, ast::expr::makeIdentifier( m_cache, coord ) ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p0" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, compare ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p1" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, data ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p2" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, res ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p3" ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( m_cache.getFunction( expr->getType(), callParameters )
					, "InterlockedCompareExchange" ) )
				, std::move( callArgs ) ) ) );

			//	The return statement
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( m_cache, res ) ) );

			it = m_adaptationData.funcs.imageAtomicCompSwapFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			argList.emplace_back( doSubmit( arg.get() ) );
		}

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureSize( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_textureSize", config );
		auto it = m_adaptationData.funcs.imageSizeFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageSizeFuncs.end() )
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

			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
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
			uint32_t index = 0u;
			ast::var::VariableList callParameters;

			if ( lod )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, lod ) );
				callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			}
			else if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				callArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
				callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			}

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			}

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				auto var = ast::var::makeVariable( uintType, "levels" );
				cont->addStmt( ast::stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			}

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache
					, ast::var::makeFunction( m_cache.getFunction( expr->getType(), callParameters )
						, "GetDimensions" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( ast::expr::makeCast( m_cache.getInt()
					, ast::expr::makeIdentifier( m_cache, var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( ast::stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( composite
					, ast::type::Kind::eInt
					, std::move( resArgs ) ) ) );
			}

			it = m_adaptationData.funcs.imageSizeFuncs.emplace( funcName, functionType ).first;
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

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLod( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_textureQueryLod", config );
		auto it = m_adaptationData.funcs.imageLodFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageLodFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( imgArgType->getImageType(), "texImage" );
			auto sampler = ast::var::makeVariable( imgArgType->getSamplerType(), "texSampler" );
			auto coord = ast::var::makeVariable( expr->getArgList()[1]->getType(), "P" );
			parameters.emplace_back( image );
			parameters.emplace_back( sampler );
			parameters.emplace_back( coord );

			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			ast::type::TypePtr uintType = m_cache.getUInt();

			// The call to image.CalculateLevelOfDetail
			ast::expr::ExprList callArgs;
			uint32_t index = 0u;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, sampler ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, coord ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );

			// The return statement
			ast::expr::ExprList resArgs;
			resArgs.emplace_back( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( m_cache.getFunction( expr->getType(), callParameters )
					, "CalculateLevelOfDetail" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) );
			resArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0.0f ) );

			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec2
				, ast::type::Kind::eFloat
				, std::move( resArgs ) ) ) );

			it = m_adaptationData.funcs.imageLodFuncs.emplace( funcName, functionType ).first;
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

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLevels( ast::expr::TextureAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::SampledImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = getName( "SDW_textureQueryLevels", config );
		auto it = m_adaptationData.funcs.imageLevelsFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageLevelsFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( imgArgType->getImageType(), "image" );
			parameters.emplace_back( image );

			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			ast::type::TypePtr uintType = m_cache.getUInt();
			ast::var::VariableList resVars;

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
			default:
				break;
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;
			uint32_t index = 0u;
			ast::var::VariableList callParameters;

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				callArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
				callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			}

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );
			}

			auto levels = ast::var::makeVariable( uintType, "levels" );
			cont->addStmt( ast::stmt::makeVariableDecl( levels ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, levels ) );
			callParameters.emplace_back( ast::var::makeVariable( callArgs.back()->getType(), "p" + std::to_string( index++ ) ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache
					, ast::var::makeFunction( m_cache.getFunction( expr->getType(), callParameters )
						, "GetDimensions" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( m_cache, levels ) ) );

			it = m_adaptationData.funcs.imageLevelsFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		doProcessSampledImageArg( *expr->getArgList()[0], false, argList );

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( it->second
				, funcName ) )
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
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec2
					, ast::type::Kind::eInt
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec2I:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec3
					, ast::type::Kind::eInt
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec3I:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec4
					, ast::type::Kind::eInt
					, std::move( merged ) ) );
				break;
			default:
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
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.getBasicType( arrayType->getType()->getKind() )
			, ast::ExprCloner::submit( &offset )
			, ast::expr::makeLiteral( m_cache, 0u ) ) );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.getBasicType( arrayType->getType()->getKind() )
			, ast::ExprCloner::submit( &offset )
			, ast::expr::makeLiteral( m_cache, 1u ) ) );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.getBasicType( arrayType->getType()->getKind() )
			, ast::ExprCloner::submit( &offset )
			, ast::expr::makeLiteral( m_cache, 2u ) ) );
		args.emplace_back( ast::expr::makeArrayAccess( m_cache.getBasicType( arrayType->getType()->getKind() )
			, ast::ExprCloner::submit( &offset )
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

	ast::var::VariablePtr ExprAdapter::doMakeAlias( ast::type::TypePtr type )
	{
		++m_adaptationData.aliasId;
		return ast::var::makeVariable( std::move( type )
			, "temp_" + std::to_string( m_adaptationData.aliasId ) );
	}
}
