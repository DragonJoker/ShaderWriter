/*
See LICENSE file in root folder
*/
#include "HlslExprAdapter.hpp"

#include "HlslHelpers.hpp"
#include "HlslVariableReplacer.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslStorageImageAccessConfig.hpp"
#include "HlslCombinedImageAccessConfig.hpp"

#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>

#include <algorithm>
#include <stdexcept>

#pragma GCC diagnostic ignored "-Wrestrict"
#pragma GCC diagnostic ignored "-Wnull-dereference"

namespace hlsl
{
	namespace HlslExprAdapterInternal
	{
		static bool isMatrix( ast::type::Kind kind )
		{
			return kind >= ast::type::Kind::eMat2x2F
				&& kind <= ast::type::Kind::eMat4x4D;
		}

		static ast::type::TypePtr getFloatType( ast::type::TypePtr type )
		{
			switch ( type->getKind() )
			{
			case ast::type::Kind::eDouble:
				return type->getCache().getFloat();
			case ast::type::Kind::eVec2D:
				return type->getCache().getVec2F();
			case ast::type::Kind::eVec3D:
				return type->getCache().getVec3F();
			case ast::type::Kind::eVec4D:
				return type->getCache().getVec4F();
			case ast::type::Kind::eMat2x2D:
				return type->getCache().getMat2x2F();
			case ast::type::Kind::eMat2x3D:
				return type->getCache().getMat2x3F();
			case ast::type::Kind::eMat2x4D:
				return type->getCache().getMat2x4F();
			case ast::type::Kind::eMat3x2D:
				return type->getCache().getMat3x2F();
			case ast::type::Kind::eMat3x3D:
				return type->getCache().getMat3x3F();
			case ast::type::Kind::eMat3x4D:
				return type->getCache().getMat3x4F();
			case ast::type::Kind::eMat4x2D:
				return type->getCache().getMat4x2F();
			case ast::type::Kind::eMat4x3D:
				return type->getCache().getMat4x3F();
			case ast::type::Kind::eMat4x4D:
				return type->getCache().getMat4x4F();
			default:
				return type;
			}
		}

		static ast::expr::ExprPtr writeProjectTexCoords2( ast::type::TypesCache & cache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( ++nextVarId
				, cache.getVec2F()
				, "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getFloat()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( ++nextVarId
						, cache.getFunction( cache.getFloat(), params )
					, "SDW_projectTexCoords2" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords3( ast::type::TypesCache & cache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( ++nextVarId
				, cache.getVec3F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec2F()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( ++nextVarId
						, cache.getFunction( cache.getVec2F(), params )
					, "SDW_projectTexCoords3" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords4To1( ast::type::TypesCache & cache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( ++nextVarId
				, cache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getFloat()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( ++nextVarId
						, cache.getFunction( cache.getFloat(), params )
					, "SDW_projectTexCoords4To1" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords4To2( ast::type::TypesCache & cache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( ++nextVarId
				, cache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec2F()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( ++nextVarId
						, cache.getFunction( cache.getVec2F(), params )
					, "SDW_projectTexCoords4To2" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords4( ast::type::TypesCache & cache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( ++nextVarId
				, cache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			return ast::expr::makeFnCall( cache.getVec3F()
				, ast::expr::makeIdentifier( cache
					, ast::var::makeFunction( ++nextVarId
						, cache.getFunction( cache.getVec3F(), params )
					, "SDW_projectTexCoords4" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjTexCoords( ast::type::TypesCache & cache
			, uint32_t & nextVarId
			, ast::expr::CombinedImageAccess access
			, ast::expr::ExprPtr texcoords )
		{
			switch ( access )
			{
			case ast::expr::CombinedImageAccess::eTextureProj1DF2:
			case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj1DI2:
			case ast::expr::CombinedImageAccess::eTextureProj1DU2:
			case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
			case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
			case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
				return writeProjectTexCoords2( cache, nextVarId, std::move( texcoords ) );

			case ast::expr::CombinedImageAccess::eTextureProj1DF4:
			case ast::expr::CombinedImageAccess::eTextureProj1DI4:
			case ast::expr::CombinedImageAccess::eTextureProj1DU4:
			case ast::expr::CombinedImageAccess::eTextureProj1DF4Bias:
			case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
			case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjLod1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
				return writeProjectTexCoords4To1( cache, nextVarId, std::move( texcoords ) );

			case ast::expr::CombinedImageAccess::eTextureProj2DF3:
			case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj2DI3:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProj2DU3:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU3:
				return writeProjectTexCoords3( cache, nextVarId, std::move( texcoords ) );

			case ast::expr::CombinedImageAccess::eTextureProj2DF4:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProj2DI4:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProj2DU4:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectU4:
			case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjLod2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU4:
				return writeProjectTexCoords4To2( cache, nextVarId, std::move( texcoords ) );

			case ast::expr::CombinedImageAccess::eTextureProj3DF:
			case ast::expr::CombinedImageAccess::eTextureProj3DI:
			case ast::expr::CombinedImageAccess::eTextureProj3DU:
			case ast::expr::CombinedImageAccess::eTextureProj3DFBias:
			case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
			case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
			case ast::expr::CombinedImageAccess::eTextureProjLod3DF:
			case ast::expr::CombinedImageAccess::eTextureProjLod3DI:
			case ast::expr::CombinedImageAccess::eTextureProjLod3DU:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DU:
			case ast::expr::CombinedImageAccess::eTextureProjGrad3DF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
			case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
				return writeProjectTexCoords4( cache, nextVarId, std::move( texcoords ) );

			default:
				AST_Failure( "Expected a textureProj access function" );
				return nullptr;
			}
		}

		static ast::expr::CombinedImageAccess getSampleCmp( ast::expr::CombinedImageAccess value )
		{
			assert( value >= ast::expr::CombinedImageAccess::eTextureGrad2DRectShadowF
				&& value <= ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF );
			ast::expr::CombinedImageAccess result{};

			switch ( value )
			{
			case ast::expr::CombinedImageAccess::eTextureGrad2DRectShadowF:
				result = ast::expr::CombinedImageAccess::eTexture2DRectShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
				result = ast::expr::CombinedImageAccess::eTexture1DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
				result = ast::expr::CombinedImageAccess::eTexture2DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
				result = ast::expr::CombinedImageAccess::eTexture1DArrayShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectShadowF:
				result = ast::expr::CombinedImageAccess::eTextureOffset2DRectShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureOffset1DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureOffset2DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
				result = ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
				result = ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProj1DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProj2DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProj2DRectShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProjOffset2DRectShadowF;
				break;
			default:
				break;
			}

			return result;
		}

		static std::string getName( std::string const & baseName
			, ast::type::ImageConfiguration const & config )
		{
			return baseName
				+ hlsl::getName( config.dimension )
				+ ( config.isArrayed ? "Array" : "" )
				+ hlsl::getSampledName( config.format );
		}
	}

	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::Expr * expr
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics
		, bool preventVarTypeReplacement )
	{
		ast::expr::ExprPtr result;
		ExprAdapter vis{ cache
			, result
			, container
			, intrinsicsConfig
			, writerConfig
			, adaptationData
			, intrinsics
			, preventVarTypeReplacement };
		expr->accept( &vis );
		return result;
	}
			
	ast::expr::ExprPtr ExprAdapter::submit( ast::type::TypesCache & cache
		, ast::expr::ExprPtr const & expr
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics
		, bool preventVarTypeReplacement )
	{
		return submit( cache
			, expr.get()
			, container
			, intrinsicsConfig
			, writerConfig
			, adaptationData
			, intrinsics
			, preventVarTypeReplacement );
	}

	ExprAdapter::ExprAdapter( ast::type::TypesCache & cache
		, ast::expr::ExprPtr & result
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics
		, bool preventVarTypeReplacement )
		: ExprCloner{ result }
		, m_cache{ cache }
		, m_container{ container }
		, m_intrinsicsConfig{ intrinsicsConfig }
		, m_writerConfig{ writerConfig }
		, m_adaptationData{ adaptationData }
		, m_intrinsics{ intrinsics }
		, m_preventVarTypeReplacement{ preventVarTypeReplacement }
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
			m_preventVarTypeReplacement,
		};
		expr->accept( &vis );
		return result;
	}

	void ExprAdapter::visitArrayAccessExpr( ast::expr::ArrayAccess * expr )
	{
		auto arrayIndex = doSubmit( expr->getRHS() );
		auto arrayOuter = doSubmit( expr->getLHS() );

		if ( arrayOuter->getKind() == ast::expr::Kind::eMbrSelect
			&& getArraySize( arrayOuter->getType() ) == ast::type::NotArray )
		{
			auto & mbrSelect = static_cast< ast::expr::MbrSelect const & >( *arrayOuter );
			auto mbr = mbrSelect.getOuterType()->getMember( mbrSelect.getMemberIndex() );
			auto selectOuter = mbrSelect.getOuterExpr();

			if ( mbr.builtin == ast::Builtin::eClipDistance )
			{
				assert( arrayIndex->getKind() == ast::expr::Kind::eLiteral );
				auto & lit = static_cast< ast::expr::Literal const & >( *arrayIndex );
				uint32_t index{};

				switch ( lit.getLiteralType() )
				{
				case ast::expr::LiteralType::eInt8:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eInt8 >() );
					break;
				case ast::expr::LiteralType::eInt16:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eInt16 >() );
					break;
				case ast::expr::LiteralType::eInt32:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eInt32 >() );
					break;
				case ast::expr::LiteralType::eInt64:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eInt64 >() );
					break;
				case ast::expr::LiteralType::eUInt8:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eUInt8 >() );
					break;
				case ast::expr::LiteralType::eUInt16:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eUInt16 >() );
					break;
				case ast::expr::LiteralType::eUInt32:
					index = lit.getValue< ast::expr::LiteralType::eUInt32 >();
					break;
				case ast::expr::LiteralType::eUInt64:
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eUInt64 >() );
					break;
				default:
					break;
				}

				auto mbrIndex = mbrSelect.getMemberIndex();

				if ( index > 3 )
				{
					index -= 4;
					++mbrIndex;
				}

				m_result = ast::expr::makeMbrSelect( ast::ExprCloner::submit( selectOuter )
					, mbrIndex
					, mbrSelect.getMemberFlags() );
				m_result = ast::expr::makeArrayAccess( expr->getType()
					, std::move( m_result )
					, ast::expr::makeLiteral( m_cache, index ) );
			}
			else if ( expr->getLHS()->getKind() != ast::expr::Kind::eMbrSelect )
			{
				m_result = ast::ExprCloner::submit( selectOuter );
				m_result = ast::expr::makeArrayAccess( mbrSelect.getOuterType()
					, std::move( m_result )
					, std::move( arrayIndex ) );
				m_result = ast::expr::makeMbrSelect( std::move( m_result )
					, mbrSelect.getMemberIndex()
					, mbrSelect.getMemberFlags() );
			}
			else
			{
				m_result = std::make_unique< ast::expr::ArrayAccess >( expr->getType()
					, std::move( arrayOuter )
					, std::move( arrayIndex ) );
			}
		}
		else
		{
			m_result = std::make_unique< ast::expr::ArrayAccess >( expr->getType()
				, std::move( arrayOuter )
				, std::move( arrayIndex ) );
		}
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier * expr )
	{
		auto var = expr->getVariable();
		m_result = m_adaptationData.processPending( expr->getVariable() );

		if ( !m_result )
		{
			auto itReplaced = m_adaptationData.replacedVars.find( var );

			if ( m_adaptationData.replacedVars.end() != itReplaced
				&& !m_preventVarTypeReplacement )
			{
				m_result = ast::ExprCloner::submit( itReplaced->second );
				assert( m_result );
			}
			else
			{
				m_result = ast::expr::makeIdentifier( m_cache, var );
			}
		}

		if ( m_adaptationData.isHlslType( var->getType() )
			&& !m_preventVarTypeReplacement )
		{
			m_result = ast::expr::makeMbrSelect( std::move( m_result )
				, 0u
				, var->getFlags() );
		}

		updateLinkedVars( var
			, m_adaptationData.linkedVars
			, m_adaptationData.nextVarId );
	}

	void ExprAdapter::visitCompositeConstructExpr( ast::expr::CompositeConstruct * expr )
	{
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
				}
				else
				{
					m_result = std::make_unique< ast::expr::Swizzle >( doSubmit( arg )
						, ( count == 2u
							? ast::expr::SwizzleKind::e00
							: ( count == 3u
								? ast::expr::SwizzleKind::e000
								: ast::expr::SwizzleKind::e0000 ) ) );
				}
			}
			else if ( isMatrixType( expr->getType()->getKind() )
				&& isMatrixType( arg->getType()->getKind() )
				&& expr->getType()->getKind() != arg->getType()->getKind() )
			{
				// Function-like cast to matrix of another type, make it a cast.
				m_result = ast::expr::makeCast( expr->getType()
					, doSubmit( arg ) );
			}
		}

		if ( !m_result )
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
			{
				m_result = ast::expr::makeCompositeConstruct( std::move( args.front() )
					, std::move( args.back() ) );
			}
			else
			{
				m_result = ast::expr::makeCompositeConstruct( expr->getComposite()
					, expr->getComponent()
					, std::move( args ) );
			}
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

				if ( var->isAlias() )
				{
					var->updateFlag( ast::var::Flag::eAlias, false );
				}

				auto it = updateLinkedVars( var
					, m_adaptationData.linkedVars
					, m_adaptationData.nextVarId );

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
		if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageSize1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageSize2DMSArrayU )
		{
			doProcessImageSize( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageLoad1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageLoad2DMSArrayU )
		{
			doProcessImageLoad( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageStore2DMSArrayU )
		{
			doProcessImageStore( expr, m_adaptationData.funcs.imageStoreFuncs );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAdd1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF )
		{
			doProcessImageAtomicAdd( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicMin1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayI )
		{
			doProcessImageAtomicMin( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicMax1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayI )
		{
			doProcessImageAtomicMax( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAnd1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayI )
		{
			doProcessImageAtomicAnd( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicOr1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayI )
		{
			doProcessImageAtomicOr( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicXor1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayI )
		{
			doProcessImageAtomicXor( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicExchange1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF )
		{
			doProcessImageAtomicExchange( expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicCompSwap1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI )
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
				AST_Failure( "Unexpected operator type." );
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
		else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eWritePackedPrimitiveIndices4x8NV )
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			auto it = std::find_if( m_adaptationData.getRoutines().begin()
				, m_adaptationData.getRoutines().end()
				, []( auto & lookup )
				{
					return lookup.second->isMain;
				} );

			if ( it != m_adaptationData.getRoutines().end() )
			{
				auto primitiveIndices = it->second->getOutputPrimitives();

				switch ( it->second->getOutputTopology() )
				{
				case ast::type::OutputTopology::ePoint:
					{
						ast::expr::ExprPtr indices = doWriteUnpack1( *expr->getArgList().front()
							, *expr->getArgList().back() );
						auto dstType = getNonArrayType( primitiveIndices->getType() );
						auto dstIndex = ast::expr::makeArrayAccess( dstType
							, ast::expr::makeIdentifier( m_cache, primitiveIndices )
							, std::move( args.front() ) );
						m_result = ast::expr::makeAssign( dstType, std::move( dstIndex ), std::move( indices ) );
					}
					break;
				case ast::type::OutputTopology::eLine:
					{
						ast::expr::ExprPtr indices = doWriteUnpack2( *expr->getArgList().front()
							, *expr->getArgList().back() );
						auto dstType = getNonArrayType( primitiveIndices->getType() );
						auto dstIndex = ast::expr::makeArrayAccess( dstType
							, ast::expr::makeIdentifier( m_cache, primitiveIndices )
							, std::move( args.front() ) );
						m_result = ast::expr::makeAssign( dstType, std::move( dstIndex ), std::move( indices ) );
					}
					break;
				case ast::type::OutputTopology::eTriangle:
					{
						ast::expr::ExprPtr indices = doWriteUnpack3( *expr->getArgList().front()
							, *expr->getArgList().back() );
						auto dstType = getNonArrayType( primitiveIndices->getType() );
						auto dstIndex = ast::expr::makeArrayAccess( dstType
							, ast::expr::makeIdentifier( m_cache, primitiveIndices )
							, std::move( args.front() ) );
						m_result = ast::expr::makeAssign( dstType, std::move( dstIndex ), std::move( indices ) );
					}
					break;
				default:
					break;
				}
			}
		}
		else if ( expr->getIntrinsic() != ast::expr::Intrinsic::eHelperInvocation )
		{
			ast::expr::ExprList args;
			m_preventVarTypeReplacement = expr->getIntrinsic() == ast::expr::Intrinsic::eTraceRay
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eExecuteCallable
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eReportIntersection;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			m_preventVarTypeReplacement = false;

			if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEmitVertex )
			{
				m_result = ast::expr::makeStreamAppend( ast::expr::makeComma( ast::expr::makeIdentifier( m_cache, m_adaptationData.getHFOutputs().paramVar )
					, ast::expr::makeIdentifier( m_cache, m_adaptationData.getHFOutputs().separateVar ) ) );
			}
			else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEmitStreamVertex )
			{
				args.insert( args.begin()
					, ast::expr::makeIdentifier( m_cache, m_adaptationData.getHFOutputs().paramVar ) );
			}
			else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eDispatchMeshNV )
			{
				auto payload = std::move( args.front() );
				auto localSizeX = std::move( args.back() );
				args.clear();
				args.emplace_back( std::move( localSizeX ) );
				args.emplace_back( ast::expr::makeLiteral( m_cache, 1u ) );
				args.emplace_back( ast::expr::makeLiteral( m_cache, 1u ) );
				args.emplace_back( std::move( payload ) );
			}
			else if ( adaptationInfo.isStrictFloat )
			{
				for ( auto & arg : args )
				{
					if ( isDoubleType( arg->getType()->getKind() ) )
					{
						auto type = HlslExprAdapterInternal::getFloatType( arg->getType() );
						arg = ast::expr::makeCast( type, std::move( arg ) );
					}
				}
			}

			if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEndPrimitive
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eEmitStreamVertex
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eEndStreamPrimitive )
			{
				args.insert( args.begin()
					, ast::expr::makeIdentifier( m_cache, m_adaptationData.getHFOutputs().paramVar ) );
			}

			m_result = ast::expr::makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitStreamAppendExpr( ast::expr::StreamAppend * expr )
	{
		m_result = ast::expr::makeStreamAppend( ast::expr::makeComma( ast::expr::makeIdentifier( m_cache, m_adaptationData.getHFOutputs().paramVar )
			, ast::expr::makeIdentifier( m_cache, m_adaptationData.getHFOutputs().separateVar ) ) );
	}

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect * expr )
	{
		auto outer = expr->getOuterExpr();
		ast::expr::ExprPtr indexExpr;
		auto structType = expr->getOuterType();
		{
			if ( outer->getKind() == ast::expr::Kind::eArrayAccess )
			{
				auto & arrayAccess = static_cast< ast::expr::ArrayAccess const & >( *outer );
				indexExpr = doSubmit( arrayAccess.getRHS() );
				outer = arrayAccess.getLHS();
			}

			if ( outer->getKind() == ast::expr::Kind::eIdentifier )
			{
				auto ident = ast::findIdentifier( outer );
				auto var = ident->getVariable();

				auto it = std::find( m_adaptationData.ssboList.begin()
					, m_adaptationData.ssboList.end()
					, var );

				if ( it != m_adaptationData.ssboList.end() )
				{
					auto tmp = ast::var::makeVariable( ++m_adaptationData.nextVarId
						, expr->getType()
						, expr->getOuterType()->getMember( expr->getMemberIndex() ).name
						, expr->getMemberFlags() );
					m_result = ast::expr::makeIdentifier( m_cache, tmp );
				}
			}
		}

		if ( !m_result )
		{
			if ( expr->isBuiltin() )
			{
				auto writeFuncCall = [this]( ast::type::TypePtr retType
					, std::string name )
				{
					return ast::expr::makeFnCall( retType
						, ast::expr::makeIdentifier( m_cache
							, ast::var::makeFunction( m_adaptationData.nextVarId
								, m_cache.getFunction( retType, {} )
								, std::move( name ) ) )
						, {} );
				};
				auto mbr = structType->getMember( expr->getMemberIndex() );

				switch ( mbr.builtin )
				{
				case ast::Builtin::eLaunchID:
					m_result = writeFuncCall( mbr.type, "DispatchRaysIndex" );
					break;
				case ast::Builtin::eLaunchSize:
					m_result = writeFuncCall( mbr.type, "DispatchRaysDimensions" );
					break;
				case ast::Builtin::eInstanceCustomIndex:
					m_result = writeFuncCall( mbr.type, "InstanceID" );
					break;
				case ast::Builtin::eInstanceID:
					m_result = writeFuncCall( mbr.type, "InstanceIndex" );
					break;
				case ast::Builtin::eGeometryIndex:
					m_result = writeFuncCall( mbr.type, "InstanceIndex" );
					break;
				case ast::Builtin::ePrimitiveID:
					if ( isRayTraceStage( m_writerConfig.shaderStage ) )
					{
						m_result = writeFuncCall( mbr.type, "PrimitiveIndex" );
					}
					break;
				case ast::Builtin::eWorldRayOrigin:
					m_result = writeFuncCall( mbr.type, "WorldRayOrigin" );
					break;
				case ast::Builtin::eWorldRayDirection:
					m_result = writeFuncCall( mbr.type, "WorldRayDirection" );
					break;
				case ast::Builtin::eObjectRayOrigin:
					m_result = writeFuncCall( mbr.type, "ObjectRayOrigin" );
					break;
				case ast::Builtin::eObjectRayDirection:
					m_result = writeFuncCall( mbr.type, "ObjectRayDirection" );
					break;
				case ast::Builtin::eRayTmin:
					m_result = writeFuncCall( mbr.type, "RayTMin" );
					break;
				case ast::Builtin::eRayTmax:
					m_result = writeFuncCall( mbr.type, "RayTCurrent" );
					break;
				case ast::Builtin::eIncomingRayFlags:
					m_result = writeFuncCall( mbr.type, "RayFlags" );
					break;
				case ast::Builtin::eHitKind:
					m_result = writeFuncCall( mbr.type, "HitKind" );
					break;
				case ast::Builtin::eObjectToWorld:
					m_result = writeFuncCall( mbr.type, "ObjectToWorld3x4" );
					break;
				case ast::Builtin::eWorldToObject:
					m_result = writeFuncCall( mbr.type, "ObjectToWorld3x4" );
					break;
				case ast::Builtin::eSubgroupSize:
					m_result = writeFuncCall( mbr.type, "WaveGetLaneCount" );
					break;
				case ast::Builtin::eSubgroupLocalInvocationID:
					m_result = writeFuncCall( mbr.type, "WaveGetLaneIndex" );
					break;
				default:
					//noop
					break;
				}
			}
		}

		if ( !m_result
			&& !isRayTraceStage( m_writerConfig.shaderStage ) )
		{
			m_result = m_adaptationData.processPendingMbr( expr->getOuterExpr()
				, expr->getMemberIndex()
				, *expr
				, *this );
		}

		if ( !m_result )
		{
			m_result = ast::expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
				, expr->getMemberIndex()
				, expr->getMemberFlags() );
		}
	}

	void ExprAdapter::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall * expr )
	{
		if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureSize1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureSizeBufferU )
		{
			doProcessTextureSize( expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureQueryLod1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU )
		{
			doProcessTextureQueryLod( expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureQueryLevels1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU )
		{
			doProcessTextureQueryLevels( expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTexelFetch1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayU )
		{
			doProcessTexelFetch( expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGrad2DRectShadowF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF
			&& m_intrinsicsConfig.requiresShadowSampler )
		{
			doProcessTextureGradShadow( expr );
		}
		else if ( ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectU )
			|| ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DShadowF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectShadowF ) )
		{
			doProcessTextureGather( expr );
		}
		else if ( ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectU )
			|| ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectShadowF ) )
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
		if ( HlslExprAdapterInternal::isMatrix( expr->getType()->getKind() )
			|| HlslExprAdapterInternal::isMatrix( expr->getLHS()->getType()->getKind() )
			|| HlslExprAdapterInternal::isMatrix( expr->getRHS()->getType()->getKind() ) )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getLHS()->getType()
				, "lhs" ) );
			params.push_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getRHS()->getType()
				, "rhs" ) );
			ast::expr::ExprList argsList;
			argsList.emplace_back( doSubmit( expr->getLHS() ) );
			argsList.emplace_back( doSubmit( expr->getRHS() ) );
			m_result = ast::expr::makeFnCall( expr->getType()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeVariable( ++m_adaptationData.nextVarId
					, m_cache.getFunction( expr->getType(), params )
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

	void ExprAdapter::doPushSplImgArg( ast::expr::Expr & imageArg
		, ast::var::VariablePtr imageVar
		, ast::expr::Expr & samplerArg
		, ast::var::VariablePtr samplerVar
		, bool writeSampler
		, ast::expr::ExprList & args )
	{
		if ( imageArg.getKind() == ast::expr::Kind::eArrayAccess )
		{
			args.emplace_back( ast::expr::makeArrayAccess( imageVar->getType()
				, ast::expr::makeIdentifier( m_cache, imageVar )
				, doSubmit( static_cast< ast::expr::ArrayAccess const & >( imageArg ).getRHS() ) ) );
		}
		else
		{
			args.emplace_back( ast::expr::makeIdentifier( m_cache, imageVar ) );
		}

		if ( writeSampler )
		{
			if ( samplerArg.getKind() == ast::expr::Kind::eArrayAccess )
			{
				args.emplace_back( ast::expr::makeArrayAccess( samplerVar->getType()
					, ast::expr::makeIdentifier( m_cache, samplerVar )
					, doSubmit( static_cast< ast::expr::ArrayAccess const & >( samplerArg ).getRHS() ) ) );
			}
			else
			{
				args.emplace_back( ast::expr::makeIdentifier( m_cache, samplerVar ) );
			}
		}
	}

	bool ExprAdapter::doProcessTextureArg( ast::expr::Expr & arg
		, bool writeSampler
		, ast::expr::ExprList & args )
	{
		bool result = arg.getKind() == ast::expr::Kind::eIdentifier
			|| arg.getKind() == ast::expr::Kind::eArrayAccess
			|| arg.getKind() == ast::expr::Kind::eCompositeConstruct;

		if ( result )
		{
			if ( arg.getKind() == ast::expr::Kind::eCompositeConstruct )
			{
				result = static_cast< ast::expr::CompositeConstruct & >( arg ).getComposite() == ast::expr::CompositeType::eCombine;

				if ( result )
				{
					auto image = doSubmit( static_cast< ast::expr::CompositeConstruct & >( arg ).getArgList()[0].get() );
					auto imgVar = ast::findIdentifier( image )->getVariable();
					auto sampler = doSubmit( static_cast< ast::expr::CompositeConstruct & >( arg ).getArgList()[1].get() );
					auto splVar = ast::findIdentifier( sampler )->getVariable();
					doPushSplImgArg( *image, imgVar
						, *sampler, splVar
						, writeSampler, args );
				}
			}
			else
			{
				auto ident = ast::findIdentifier( &arg );
				auto it = m_adaptationData.linkedVars.find( ident->getVariable() );

				if ( m_adaptationData.linkedVars.end() != it )
				{
					doPushSplImgArg( arg, it->second.first
						, arg, it->second.second
						, writeSampler, args );
				}
				else
				{
					args.emplace_back( doSubmit( &arg ) );
				}
			}
		}

		return result;
	}

	void ExprAdapter::doProcessImageSize( ast::expr::ImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageSize", config );
		auto it = m_adaptationData.funcs.imageSizeFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageSizeFuncs.end() )
		{
			ast::var::VariableList resVars;
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[0]->getType()
				, "image" );
			parameters.emplace_back( image );
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			ast::type::TypePtr uintType = m_cache.getUInt32();
			ast::expr::CompositeType composite{};

			switch ( getComponentCount( expr->getType()->getKind() ) )
			{
			case 1:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eScalar;
				break;
			case 2:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimZ" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec3;
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
				auto var = ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dummy" );
				cont->addStmt( ast::stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
			}

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
					, m_cache.getFunction( m_cache.getVoid(), resVars )
					, "GetDimensions" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( ast::expr::makeCast( m_cache.getInt32()
					, ast::expr::makeIdentifier( m_cache, var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( ast::stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( composite
					, ast::type::Kind::eInt32
					, std::move( resArgs ) ) ) );
			}

			it = m_adaptationData.funcs.imageSizeFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		argList.emplace_back( doSubmit( expr->getArgList().front().get() ) );
		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
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
		paramList.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
			, expr->getArgList().front()->getType()
			, "p" + std::to_string( index++ ) ) );

		for ( auto it = expr->getArgList().begin() + 1u; it != expr->getArgList().end(); ++it )
		{
			argList.emplace_back( doSubmit( it->get() ) );
			paramList.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, argList.back()->getType()
				, "p" + std::to_string( index++ ) ) );
		}

		m_result = ast::expr::makeMemberFnCall( callRetType
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, m_cache.getFunction( expr->getType(), paramList )
				, "Load" ) )
			, doSubmit( expr->getArgList().front().get() )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageStore( ast::expr::ImageAccessCall * expr
		, std::map< std::string, ast::type::FunctionPtr > & imageStoreFuncs )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageStore", config );
		auto it = imageStoreFuncs.find( funcName );

		if ( it == imageStoreFuncs.end() )
		{
			auto & args = expr->getArgList();
			auto hasSample = expr->getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSF
				|| expr->getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSArrayF
				|| expr->getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSI
				|| expr->getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSArrayI
				|| expr->getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSU
				|| expr->getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSArrayU;
			auto dataType = args.back()->getType();
			ast::var::VariableList parameters;
			parameters.push_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[0]->getType()
				, "image" ) );
			parameters.push_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[1]->getType()
				, "coord" ) );

			if ( hasSample )
			{
				parameters.push_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, expr->getArgList()[2]->getType()
					, "sample" ) );
			}

			parameters.push_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, dataType
				, "data" ) );
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
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
				, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomic( ast::expr::ImageAccessCall * expr
		, std::string const & name
		, std::map< std::string, ast::type::FunctionPtr > & imageAtomicFuncs )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageAtomic" + name, config );
		auto it = imageAtomicFuncs.find( funcName );

		if ( it == imageAtomicFuncs.end() )
		{
			// Declare the function
			auto dataType = expr->getArgList()[2]->getType();
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[0]->getType()
				, "image" );
			auto coord = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[1]->getType()
				, "coord" );
			auto data = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, dataType
				, "data" );
			parameters.emplace_back( image );
			parameters.emplace_back( coord );
			parameters.emplace_back( data );
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			// Function content
			auto res = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, dataType
				, "res" );
			cont->addStmt( ast::stmt::makeVariableDecl( res ) );

			//	The call to Interlocked<name>
			ast::expr::ExprList callArgs;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
				, ast::expr::makeIdentifier( m_cache, image )
				, ast::expr::makeIdentifier( m_cache, coord ) ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p0" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, data ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p1" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, res ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p2" ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
					, m_cache.getFunction( m_cache.getVoid(), callParameters )
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
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
				, funcName ) )
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
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageAtomicCompSwap", config );
		auto it = m_adaptationData.funcs.imageAtomicCompSwapFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageAtomicCompSwapFuncs.end() )
		{
			// Declare the function
			auto dataType = expr->getArgList()[2]->getType();
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[0]->getType()
				, "image" );
			auto coord = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[1]->getType()
				, "coord" );
			auto compare = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[2]->getType()
				, "compare" );
			auto data = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, dataType, "data" );
			parameters.emplace_back( image );
			parameters.emplace_back( coord );
			parameters.emplace_back( compare );
			parameters.emplace_back( data );
			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			// Function content
			auto res = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, dataType
				, "res" );
			cont->addStmt( ast::stmt::makeVariableDecl( res ) );

			//	The call to InterlockedCompareExchange
			ast::expr::ExprList callArgs;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( std::make_unique< ast::expr::ArrayAccess >( m_cache.getSampledType( config.format )
				, ast::expr::makeIdentifier( m_cache, image )
				, ast::expr::makeIdentifier( m_cache, coord ) ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p0" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, compare ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p1" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, data ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p2" ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, res ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p3" ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
					, m_cache.getFunction( expr->getType(), callParameters )
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
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
				, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureSize( ast::expr::CombinedImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_textureSize", config );
		auto it = m_adaptationData.funcs.imageSizeFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageSizeFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, imgArgType->getImageType()
				, "image" );
			parameters.emplace_back( image );
			ast::var::VariablePtr lod;

			if ( config.dimension != ast::type::ImageDim::eBuffer
				&& config.dimension != ast::type::ImageDim::eRect )
			{
				lod = ast::var::makeVariable( ++m_adaptationData.nextVarId
					, expr->getArgList()[1]->getType()
					, "lod" );
				parameters.emplace_back( lod );
			}

			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			ast::type::TypePtr uintType = m_cache.getUInt32();
			ast::var::VariableList resVars;
			ast::expr::CompositeType composite{};

			switch ( getComponentCount( expr->getType()->getKind() ) )
			{
			case 1:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eScalar;
				break;
			case 2:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimZ" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec3;
				break;
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;
			uint32_t index = 0u;
			ast::var::VariableList callParameters;

			if ( lod )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, lod ) );
				callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, callArgs.back()->getType()
					, "p" + std::to_string( index++ ) ) );
			}
			else if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				callArgs.emplace_back( ast::expr::makeLiteral( m_cache, 0u ) );
				callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, callArgs.back()->getType()
					, "p" + std::to_string( index++ ) ) );
			}

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, callArgs.back()->getType()
					, "p" + std::to_string( index++ ) ) );
			}

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				auto var = ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "levels" );
				cont->addStmt( ast::stmt::makeVariableDecl( var ) );
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, callArgs.back()->getType()
					, "p" + std::to_string( index++ ) ) );
			}

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache
					, ast::var::makeFunction( ++m_adaptationData.nextVarId
						, m_cache.getFunction( expr->getType(), callParameters )
						, "GetDimensions" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto & var : resVars )
			{
				resArgs.emplace_back( ast::expr::makeCast( m_cache.getInt32()
					, ast::expr::makeIdentifier( m_cache, var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( ast::stmt::makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( ast::stmt::makeReturn( ast::expr::makeCompositeConstruct( composite
					, ast::type::Kind::eInt32
					, std::move( resArgs ) ) ) );
			}

			it = m_adaptationData.funcs.imageSizeFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr->getArgList() )
		{
			if ( !doProcessTextureArg( *arg, false, argList ) )
			{
				argList.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
				, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLod( ast::expr::CombinedImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_textureQueryLod", config );
		auto it = m_adaptationData.funcs.imageLodFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageLodFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, imgArgType->getImageType()
				, "texImage" );
			auto sampler = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, imgArgType->getSamplerType()
				, "texSampler" );
			auto coord = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, expr->getArgList()[1]->getType()
				, "P" );
			parameters.emplace_back( image );
			parameters.emplace_back( sampler );
			parameters.emplace_back( coord );

			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );

			// The call to image.CalculateLevelOfDetail
			ast::expr::ExprList callArgs;
			uint32_t index = 0u;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, sampler ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p" + std::to_string( index++ ) ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, coord ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p" + std::to_string( index++ ) ) );

			// The return statement
			ast::expr::ExprList resArgs;
			resArgs.emplace_back( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
					, m_cache.getFunction( expr->getType(), callParameters )
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
			if ( !doProcessTextureArg( *arg, true, argList ) )
			{
				argList.emplace_back( doSubmit( arg.get() ) );
			}
		}

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
				, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLevels( ast::expr::CombinedImageAccessCall * expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr->getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_textureQueryLevels", config );
		auto it = m_adaptationData.funcs.imageLevelsFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageLevelsFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, imgArgType->getImageType()
				, "image" );
			parameters.emplace_back( image );

			auto functionType = m_cache.getFunction( expr->getType(), parameters );
			auto cont = ast::stmt::makeFunctionDecl( functionType, funcName );
			ast::type::TypePtr uintType = m_cache.getUInt32();
			ast::var::VariableList resVars;

			switch ( config.dimension )
			{
			case ast::type::ImageDim::e1D:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				if ( config.isArrayed )
				{
					resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
						, uintType
						, "dimY" ) );
					cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				}
				break;
			case ast::type::ImageDim::e2D:
			case ast::type::ImageDim::eRect:
			case ast::type::ImageDim::eCube:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				if ( config.isArrayed )
				{
					resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
						, uintType
						, "dimZ" ) );
					cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				}
				break;
			case ast::type::ImageDim::e3D:
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimX" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimY" ) );
				cont->addStmt( ast::stmt::makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, uintType
					, "dimZ" ) );
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
				callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, callArgs.back()->getType()
					, "p" + std::to_string( index++ ) ) );
			}

			for ( auto & var : resVars )
			{
				callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
					, callArgs.back()->getType()
					, "p" + std::to_string( index++ ) ) );
			}

			auto levels = ast::var::makeVariable( ++m_adaptationData.nextVarId
				, uintType
				, "levels" );
			cont->addStmt( ast::stmt::makeVariableDecl( levels ) );
			callArgs.emplace_back( ast::expr::makeIdentifier( m_cache, levels ) );
			callParameters.emplace_back( ast::var::makeVariable( ++m_adaptationData.nextVarId
				, callArgs.back()->getType()
				, "p" + std::to_string( index++ ) ) );

			cont->addStmt( ast::stmt::makeSimple( ast::expr::makeMemberFnCall( m_cache.getVoid()
				, ast::expr::makeIdentifier( m_cache
					, ast::var::makeFunction( ++m_adaptationData.nextVarId
						, m_cache.getFunction( expr->getType(), callParameters )
						, "GetDimensions" ) )
				, ast::expr::makeIdentifier( m_cache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			cont->addStmt( ast::stmt::makeReturn( ast::expr::makeIdentifier( m_cache, levels ) ) );

			it = m_adaptationData.funcs.imageLevelsFuncs.emplace( funcName, functionType ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		doProcessTextureArg( *expr->getArgList()[0], false, argList );

		m_result = ast::expr::makeFnCall( it->second->getReturnType()
			, ast::expr::makeIdentifier( m_cache, ast::var::makeFunction( ++m_adaptationData.nextVarId
				, it->second
				, funcName ) )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTexelFetch( ast::expr::CombinedImageAccessCall * expr )
	{
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessTextureArg( *expr->getArgList()[0], false, args );

		if ( !isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		if ( expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchBufferF
			|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchBufferI
			|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchBufferU )
		{
			// For those texel fetch functions, no lod, and none needed.
			assert( expr->getArgList().size() >= 2u );
			args.emplace_back( doSubmit( expr->getArgList()[1].get() ) );
		}
		else
		{
			ast::expr::ExprList merged;

			if ( expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetch2DRectF
				|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetch2DRectI
				|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetch2DRectU
				|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectF
				|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectI
				|| expr->getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectU )
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
			case ast::type::Kind::eInt32:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec2
					, ast::type::Kind::eInt32
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec2I32:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec3
					, ast::type::Kind::eInt32
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec3I32:
				args.emplace_back( ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec4
					, ast::type::Kind::eInt32
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

		m_result = ast::expr::makeCombinedImageAccessCall( expr->getType()
			, expr->getCombinedImageAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGradShadow( ast::expr::CombinedImageAccessCall * expr )
	{
		// Sample grad doesn't support SampleComparisonState, replace it with a SampleCmp.
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessTextureArg( *expr->getArgList()[0], false, args );

		if ( !isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

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

		auto result = ast::expr::makeCombinedImageAccessCall( expr->getType()
			, HlslExprAdapterInternal::getSampleCmp( expr->getCombinedImageAccess() )
			, std::move( args ) );

		// Reparse the created expression, textureProj cases.
		visitCombinedImageAccessCallExpr( result.get() );
	}

	void ExprAdapter::doProcessTextureGather( ast::expr::CombinedImageAccessCall * expr )
	{
		auto kind = expr->getCombinedImageAccess();
		assert( expr->getArgList().size() >= 2u );
		uint32_t index = 0u;
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessTextureArg( *expr->getArgList()[index++], true, args );

		if ( !isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		auto coord = doSubmit( expr->getArgList()[index++].get() );

		if ( !isShadow( kind ) )
		{
			// Component
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		// Coord
		args.emplace_back( std::move( coord ) );

		if ( isShadow( kind ) )
		{
			// Dref value
			assert( expr->getArgList().size() >= 3u );
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		while ( index < expr->getArgList().size() )
		{
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

		m_result = ast::expr::makeCombinedImageAccessCall( expr->getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGatherOffsets( ast::expr::CombinedImageAccessCall * expr )
	{
		auto kind = expr->getCombinedImageAccess();
		assert( expr->getArgList().size() >= 3u );
		uint32_t index = 0u;
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessTextureArg( *expr->getArgList()[index++], true, args );

		if ( !isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		if ( !isShadow( kind ) )
		{
			// Component
			args.emplace_back( doSubmit( expr->getArgList()[index++].get() ) );
		}

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

		m_result = ast::expr::makeCombinedImageAccessCall( expr->getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTexture( ast::expr::CombinedImageAccessCall * expr )
	{
		ast::expr::ExprList args;
		uint32_t index = 0u;
		uint32_t sampler = 0u;

		for ( auto & arg : expr->getArgList() )
		{
			if ( doProcessTextureArg( *arg, true, args ) )
			{
				sampler = index;
			}
			else if ( index == sampler + 1
				&& isProj( expr->getCombinedImageAccess() ) )
			{
				args.emplace_back(HlslExprAdapterInternal::writeProjTexCoords( m_cache
					, m_adaptationData.nextVarId
					, expr->getCombinedImageAccess()
					, doSubmit( arg.get() ) ) );
			}
			else
			{
				args.emplace_back( doSubmit( arg.get() ) );
			}

			++index;
		}

		if ( isBiasAndOffset( expr->getCombinedImageAccess() )
			|| isShadowLodOffset( expr->getCombinedImageAccess() ) )
		{
			auto biasOrOffset = std::move( args.back() );
			args.pop_back();
			auto offsetOrLod = std::move( args.back() );
			args.pop_back();
			args.emplace_back( std::move( biasOrOffset ) );
			args.emplace_back( std::move( offsetOrLod ) );
		}

		m_result = ast::expr::makeCombinedImageAccessCall( expr->getType()
			, expr->getCombinedImageAccess()
			, std::move( args ) );
	}

	ast::var::VariablePtr ExprAdapter::doMakeAlias( ast::type::TypePtr type )
	{
		++m_adaptationData.aliasId;
		return ast::var::makeVariable( ++m_adaptationData.nextVarId
			, std::move( type )
			, "temp_" + std::to_string( m_adaptationData.aliasId )
			, ( ast::var::Flag::eAlias
				| ast::var::Flag::eTemp ) );
	}

	ast::expr::ExprPtr ExprAdapter::doWriteUnpack1( ast::expr::Expr & index
		, ast::expr::Expr & packed )
	{
		auto value = doSubmit( &packed );
		return ast::expr::makeBitAnd( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 0x000000FFu  ) );
	}

	ast::expr::ExprPtr ExprAdapter::doWriteUnpack2( ast::expr::Expr & index
		, ast::expr::Expr & packed )
	{
		ast::expr::ExprList args;
		auto value = doSubmit( &packed );
		args.emplace_back( ast::expr::makeBitAnd( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 0x000000FFu ) ) );
		value = doSubmit( &packed );
		value = ast::expr::makeBitAnd( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 0x0000FF00u ) );
		args.emplace_back( ast::expr::makeRShift( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 8u ) ) );
		return ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec2
			, packed.getType()->getKind()
			, std::move( args ) );
	}

	ast::expr::ExprPtr ExprAdapter::doWriteUnpack3( ast::expr::Expr & index
		, ast::expr::Expr & packed )
	{
		ast::expr::ExprList args;
		auto value = doSubmit( &packed );
		args.emplace_back( ast::expr::makeBitAnd( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 0x000000FFu ) ) );
		value = doSubmit( &packed );
		value = ast::expr::makeBitAnd( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 0x0000FF00u ) );
		args.emplace_back( ast::expr::makeRShift( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 8u ) ) );
		value = doSubmit( &packed );
		value = ast::expr::makeBitAnd( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 0x00FF0000u ) );
		args.emplace_back( ast::expr::makeRShift( packed.getType()
			, std::move( value )
			, ast::expr::makeLiteral( m_cache, 16u ) ) );
		return ast::expr::makeCompositeConstruct( ast::expr::CompositeType::eVec3
			, packed.getType()->getKind()
			, std::move( args ) );
	}
}
