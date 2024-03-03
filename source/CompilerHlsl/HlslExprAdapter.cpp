/*
See LICENSE file in root folder
*/
#include "HlslExprAdapter.hpp"

#include "HlslHelpers.hpp"
#include "HlslReplaceVariables.hpp"
#include "HlslIntrinsicConfig.hpp"
#include "HlslShader.hpp"
#include "HlslStorageImageAccessConfig.hpp"
#include "HlslCombinedImageAccessConfig.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>
#include <ShaderAST/Stmt/StmtVisitor.hpp>
#include <ShaderAST/Type/TypeImage.hpp>
#include <ShaderAST/Type/TypeCombinedImage.hpp>
#include <ShaderAST/Visitors/GetExprName.hpp>
#include <ShaderAST/Visitors/ResolveConstants.hpp>

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
				return type->getTypesCache().getFloat();
			case ast::type::Kind::eVec2D:
				return type->getTypesCache().getVec2F();
			case ast::type::Kind::eVec3D:
				return type->getTypesCache().getVec3F();
			case ast::type::Kind::eVec4D:
				return type->getTypesCache().getVec4F();
			case ast::type::Kind::eMat2x2D:
				return type->getTypesCache().getMat2x2F();
			case ast::type::Kind::eMat2x3D:
				return type->getTypesCache().getMat2x3F();
			case ast::type::Kind::eMat2x4D:
				return type->getTypesCache().getMat2x4F();
			case ast::type::Kind::eMat3x2D:
				return type->getTypesCache().getMat3x2F();
			case ast::type::Kind::eMat3x3D:
				return type->getTypesCache().getMat3x3F();
			case ast::type::Kind::eMat3x4D:
				return type->getTypesCache().getMat3x4F();
			case ast::type::Kind::eMat4x2D:
				return type->getTypesCache().getMat4x2F();
			case ast::type::Kind::eMat4x3D:
				return type->getTypesCache().getMat4x3F();
			case ast::type::Kind::eMat4x4D:
				return type->getTypesCache().getMat4x4F();
			default:
				return type;
			}
		}

		static ast::expr::ExprPtr writeProjectTexCoords2( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			++nextVarId;
			params.push_back( ast::var::makeVariable( nextVarId
				, typesCache.getVec2F()
				, "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			++nextVarId;
			return exprCache.makeFnCall( typesCache.getFloat()
				, exprCache.makeIdentifier( typesCache
					, ast::var::makeFunction( nextVarId
						, typesCache.getFunction( typesCache.getFloat(), params )
					, "SDW_projectTexCoords2" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords3( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			++nextVarId;
			params.push_back( ast::var::makeVariable( nextVarId
				, typesCache.getVec3F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			++nextVarId;
			return exprCache.makeFnCall( typesCache.getVec2F()
				, exprCache.makeIdentifier( typesCache
					, ast::var::makeFunction( nextVarId
						, typesCache.getFunction( typesCache.getVec2F(), params )
					, "SDW_projectTexCoords3" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords4To1( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			++nextVarId;
			params.push_back( ast::var::makeVariable( nextVarId
				, typesCache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			++nextVarId;
			return exprCache.makeFnCall( typesCache.getFloat()
				, exprCache.makeIdentifier( typesCache
					, ast::var::makeFunction( nextVarId
						, typesCache.getFunction( typesCache.getFloat(), params )
					, "SDW_projectTexCoords4To1" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords4To2( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			++nextVarId;
			params.push_back( ast::var::makeVariable( nextVarId
				, typesCache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			++nextVarId;
			return exprCache.makeFnCall( typesCache.getVec2F()
				, exprCache.makeIdentifier( typesCache
					, ast::var::makeFunction( nextVarId
						, typesCache.getFunction( typesCache.getVec2F(), params )
					, "SDW_projectTexCoords4To2" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjectTexCoords4( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
			, uint32_t & nextVarId
			, ast::expr::ExprPtr texcoords )
		{
			ast::var::VariableList params;
			++nextVarId;
			params.push_back( ast::var::makeVariable( nextVarId
				, typesCache.getVec4F(), "texcoords" ) );
			ast::expr::ExprList args;
			args.emplace_back( std::move( texcoords ) );
			++nextVarId;
			return exprCache.makeFnCall( typesCache.getVec3F()
				, exprCache.makeIdentifier( typesCache
					, ast::var::makeFunction( nextVarId
						, typesCache.getFunction( typesCache.getVec3F(), params )
					, "SDW_projectTexCoords4" ) )
				, std::move( args ) );
		}

		static ast::expr::ExprPtr writeProjTexCoords( ast::expr::ExprCache & exprCache
			, ast::type::TypesCache & typesCache
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
				return writeProjectTexCoords2( exprCache, typesCache, nextVarId, std::move( texcoords ) );

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
				return writeProjectTexCoords4To1( exprCache, typesCache, nextVarId, std::move( texcoords ) );

			case ast::expr::CombinedImageAccess::eTextureProj2DF3:
			case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj2DI3:
			case ast::expr::CombinedImageAccess::eTextureProj2DU3:
			case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
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
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
				return writeProjectTexCoords3( exprCache, typesCache, nextVarId, std::move( texcoords ) );

			case ast::expr::CombinedImageAccess::eTextureProj2DF4:
			case ast::expr::CombinedImageAccess::eTextureProj2DI4:
			case ast::expr::CombinedImageAccess::eTextureProj2DU4:
			case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
			case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
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
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
				return writeProjectTexCoords4To2( exprCache, typesCache, nextVarId, std::move( texcoords ) );

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
				return writeProjectTexCoords4( exprCache, typesCache, nextVarId, std::move( texcoords ) );

			default:
				AST_Failure( "Expected a textureProj access function" );
				return nullptr;
			}
		}

		static ast::expr::CombinedImageAccess getSampleCmp( ast::expr::CombinedImageAccess value )
		{
			assert( value >= ast::expr::CombinedImageAccess::eTextureGrad1DShadowF
				&& value <= ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF );
			ast::expr::CombinedImageAccess result{};

			switch ( value )
			{
			case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
				result = ast::expr::CombinedImageAccess::eTexture1DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
				result = ast::expr::CombinedImageAccess::eTexture2DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
				result = ast::expr::CombinedImageAccess::eTexture1DArrayShadowF;
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
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF;
				break;
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
				result = ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF;
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

	ast::expr::ExprPtr ExprAdapter::submit( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::Expr const & expr
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics
		, bool preventVarTypeReplacement )
	{
		ast::expr::ExprPtr result{};
		ExprAdapter vis{ stmtCache
			, exprCache
			, typesCache
			, result
			, container
			, intrinsicsConfig
			, writerConfig
			, adaptationData
			, intrinsics
			, preventVarTypeReplacement };
		expr.accept( &vis );
		return result;
	}

	ExprAdapter::ExprAdapter( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, ast::type::TypesCache & typesCache
		, ast::expr::ExprPtr & result
		, ast::stmt::Container * container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData
		, ast::stmt::Container * intrinsics
		, bool preventVarTypeReplacement )
		: ExprCloner{ exprCache, result }
		, m_stmtCache{ stmtCache }
		, m_typesCache{ typesCache }
		, m_container{ container }
		, m_intrinsicsConfig{ intrinsicsConfig }
		, m_writerConfig{ writerConfig }
		, m_adaptationData{ adaptationData }
		, m_intrinsics{ intrinsics }
		, m_preventVarTypeReplacement{ preventVarTypeReplacement }
	{
	}

	ast::expr::ExprPtr ExprAdapter::doSubmit( ast::expr::Expr const & expr )
	{
		ast::expr::ExprPtr result{};
		ExprAdapter vis{ m_stmtCache
			, m_exprCache
			, m_typesCache
			, result
			, m_container
			, m_intrinsicsConfig
			, m_writerConfig
			, m_adaptationData
			, m_intrinsics
			, m_preventVarTypeReplacement };
		expr.accept( &vis );
		return result;
	}

	void ExprAdapter::visitArrayAccessExpr( ast::expr::ArrayAccess const * expr )
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
					index = uint32_t( lit.getValue< ast::expr::LiteralType::eUInt32 >() );
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

				m_result = m_exprCache.makeMbrSelect( ast::ExprCloner::submit( m_exprCache, selectOuter )
					, mbrIndex
					, mbrSelect.getMemberFlags() );
				m_result = m_exprCache.makeArrayAccess( expr->getType()
					, std::move( m_result )
					, m_exprCache.makeLiteral( m_typesCache, index ) );
			}
			else if ( expr->getLHS()->getKind() != ast::expr::Kind::eMbrSelect )
			{
				m_result = ast::ExprCloner::submit( m_exprCache, selectOuter );
				m_result = m_exprCache.makeArrayAccess( mbrSelect.getOuterType()
					, std::move( m_result )
					, std::move( arrayIndex ) );
				m_result = m_exprCache.makeMbrSelect( std::move( m_result )
					, mbrSelect.getMemberIndex()
					, mbrSelect.getMemberFlags() );
			}
			else
			{
				m_result = m_exprCache.makeArrayAccess( expr->getType()
					, std::move( arrayOuter )
					, std::move( arrayIndex ) );
			}
		}
		else
		{
			m_result = m_exprCache.makeArrayAccess( expr->getType()
				, std::move( arrayOuter )
				, std::move( arrayIndex ) );
		}
	}

	void ExprAdapter::visitAssignExpr( ast::expr::Assign const * expr )
	{
		if ( expr->getRHS()->getKind() == ast::expr::Kind::eAggrInit )
		{
			// Can't assign directly from aggr init, need a temp var in between
			auto & exprCache = expr->getExprCache();
			auto var = m_adaptationData.shader->registerName( "tmp_" + std::to_string( m_adaptationData.getNextAliasId() ), expr->getType() );
			m_container->addStmt( m_stmtCache.makeSimple( exprCache.makeInit( exprCache.makeIdentifier( m_typesCache, var )
				, doSubmit( expr->getRHS() ) ) ) );
			m_container->addStmt( m_stmtCache.makeSimple( exprCache.makeAssign( expr->getType()
				, doSubmit( expr->getLHS() )
				, exprCache.makeIdentifier( m_typesCache, var ) ) ) );
		}
		else
		{
			ExprCloner::visitAssignExpr( expr );
		}
	}

	void ExprAdapter::visitIdentifierExpr( ast::expr::Identifier const * expr )
	{
		auto var = expr->getVariable();
		m_result = m_adaptationData.processPending( expr->getVariable() );

		if ( !m_result )
		{
			auto itReplaced = m_adaptationData.replacedVars.find( var );

			if ( m_adaptationData.replacedVars.end() != itReplaced
				&& !m_preventVarTypeReplacement )
			{
				m_result = ast::ExprCloner::submit( m_exprCache, *itReplaced->second );
				assert( m_result );
			}
			else
			{
				m_result = m_exprCache.makeIdentifier( m_typesCache, var );
			}
		}

		if ( m_adaptationData.isHlslType( var->getType() )
			&& !m_preventVarTypeReplacement )
		{
			m_result = m_exprCache.makeMbrSelect( std::move( m_result )
				, 0u
				, var->getFlags() );
		}

		updateLinkedVars( var
			, m_adaptationData.linkedVars
			, m_adaptationData.nextVarId );
	}

	void ExprAdapter::visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )
	{
		if ( expr->getArgList().size() == 1u )
		{
			doProcessSingleArgCompositeConstruct( *expr );
		}

		if ( !m_result )
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( *arg ) );
			}

			if ( expr->getComposite() == ast::expr::CompositeType::eCombine )
			{
				m_result = m_exprCache.makeCompositeConstruct( std::move( args.front() )
					, std::move( args.back() ) );
			}
			else
			{
				m_result = m_exprCache.makeCompositeConstruct( expr->getComposite()
					, expr->getComponent()
					, std::move( args ) );
			}
		}
	}

	void ExprAdapter::visitFnCallExpr( ast::expr::FnCall const * expr )
	{
		ast::expr::ExprList args;

		for ( auto & arg : expr->getArgList() )
		{
			auto ident = ast::findIdentifier( *arg );

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
					args.emplace_back( replaceVariables( m_exprCache, *arg, var, it->second.first ) );
					args.emplace_back( replaceVariables( m_exprCache, *arg, var, it->second.second ) );
				}
				else
				{
					args.emplace_back( doSubmit( *arg ) );
				}
			}
			else if ( arg->getKind() == ast::expr::Kind::eAggrInit )
			{
				auto aliasVar = doMakeAlias( arg->getType() );
				m_container->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( m_typesCache, aliasVar )
					, doSubmit( *arg ) ) ) );
				args.emplace_back( m_exprCache.makeIdentifier( m_typesCache, aliasVar ) );
			}
			else
			{
				args.emplace_back( doSubmit( *arg ) );
			}
		}

		auto funcVar = expr->getFn()->getVariable();

		if ( auto it = m_adaptationData.replacedFuncVars.find( funcVar->getId() );
			it != m_adaptationData.replacedFuncVars.end() )
		{
			funcVar = it->second;
		}

		m_result = m_exprCache.makeFnCall( expr->getType()
			, m_exprCache.makeIdentifier( m_typesCache, std::move( funcVar ) )
			, std::move( args ) );
	}

	void ExprAdapter::visitImageAccessCallExpr( ast::expr::StorageImageAccessCall const * expr )
	{
		if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageSize1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageSize2DMSArrayU )
		{
			doProcessImageSize( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageLoad1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageLoad2DMSArrayU )
		{
			doProcessImageLoad( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageStore1DF
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageStore2DMSArrayU )
		{
			doProcessImageStore( *expr, m_adaptationData.funcs.imageStoreFuncs );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAdd1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF )
		{
			doProcessImageAtomicAdd( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicMin1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicMin2DMSArrayI )
		{
			doProcessImageAtomicMin( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicMax1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicMax2DMSArrayI )
		{
			doProcessImageAtomicMax( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicAnd1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicAnd2DMSArrayI )
		{
			doProcessImageAtomicAnd( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicOr1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicOr2DMSArrayI )
		{
			doProcessImageAtomicOr( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicXor1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicXor2DMSArrayI )
		{
			doProcessImageAtomicXor( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicExchange1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF )
		{
			doProcessImageAtomicExchange( *expr );
		}
		else if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageAtomicCompSwap1DU
			&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI )
		{
			doProcessImageAtomicCompSwap( *expr );
		}
		else
		{
			ast::expr::ExprList args;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( *arg ) );
			}

			m_result = m_exprCache.makeStorageImageAccessCall( expr->getType()
				, expr->getImageAccess()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )
	{
		auto adaptationInfo = getAdaptationInfo( expr->getIntrinsic() );

		if ( adaptationInfo.operatorChange.toOperator )
		{
			doProcessIntrinsicOperator( *expr, adaptationInfo );
		}
		else if ( adaptationInfo.atomicChange.isAtomic )
		{
			doProcessIntrinsicAtomic( *expr );
		}
		else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eWritePackedPrimitiveIndices4x8NV )
		{
			doProcessIntrinsicPackedPrimitiveIndices( *expr );
		}
		else if ( expr->getIntrinsic() != ast::expr::Intrinsic::eHelperInvocation )
		{
			ast::expr::ExprList args;
			m_preventVarTypeReplacement = expr->getIntrinsic() == ast::expr::Intrinsic::eTraceRay
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eExecuteCallable
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eReportIntersection;

			for ( auto & arg : expr->getArgList() )
			{
				args.emplace_back( doSubmit( *arg ) );
			}

			m_preventVarTypeReplacement = false;

			if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEmitVertex )
			{
				m_result = m_exprCache.makeStreamAppend( m_exprCache.makeComma( m_exprCache.makeIdentifier( m_typesCache, m_adaptationData.getHFOutputs().paramVar )
					, m_exprCache.makeIdentifier( m_typesCache, m_adaptationData.getHFOutputs().separateVar ) ) );
			}
			else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEmitStreamVertex )
			{
				args.insert( args.begin()
					, m_exprCache.makeIdentifier( m_typesCache, m_adaptationData.getHFOutputs().paramVar ) );
			}
			else if ( expr->getIntrinsic() == ast::expr::Intrinsic::eDispatchMeshNV )
			{
				auto payload = std::move( args.front() );
				auto localSizeX = std::move( args.back() );
				args.clear();
				args.emplace_back( std::move( localSizeX ) );
				args.emplace_back( m_exprCache.makeLiteral( m_typesCache, 1u ) );
				args.emplace_back( m_exprCache.makeLiteral( m_typesCache, 1u ) );
				args.emplace_back( std::move( payload ) );
			}
			else if ( adaptationInfo.isStrictFloat )
			{
				for ( auto & arg : args )
				{
					if ( isDoubleType( arg->getType()->getKind() ) )
					{
						auto type = HlslExprAdapterInternal::getFloatType( arg->getType() );
						arg = m_exprCache.makeCast( type, std::move( arg ) );
					}
				}
			}

			if ( expr->getIntrinsic() == ast::expr::Intrinsic::eEndPrimitive
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eEmitStreamVertex
				|| expr->getIntrinsic() == ast::expr::Intrinsic::eEndStreamPrimitive )
			{
				args.insert( args.begin()
					, m_exprCache.makeIdentifier( m_typesCache, m_adaptationData.getHFOutputs().paramVar ) );
			}

			m_result = m_exprCache.makeIntrinsicCall( expr->getType()
				, expr->getIntrinsic()
				, std::move( args ) );
		}
	}

	void ExprAdapter::visitStreamAppendExpr( ast::expr::StreamAppend const * expr )
	{
		m_result = m_exprCache.makeStreamAppend( m_exprCache.makeComma( m_exprCache.makeIdentifier( m_typesCache, m_adaptationData.getHFOutputs().paramVar )
			, m_exprCache.makeCast( m_adaptationData.getHFOutputs().paramStruct
				, m_exprCache.makeIdentifier( m_typesCache, m_adaptationData.getHFOutputs().separateVar ) ) ) );
	}

	void ExprAdapter::visitMbrSelectExpr( ast::expr::MbrSelect const * expr )
	{
		auto outer = expr->getOuterExpr();
		ast::expr::ExprPtr indexExpr{};
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
				auto ident = ast::findIdentifier( *outer );
				auto var = ident->getVariable();

				auto it = std::find( m_adaptationData.ssboList.begin()
					, m_adaptationData.ssboList.end()
					, var );

				if ( it != m_adaptationData.ssboList.end() )
				{
					auto tmp = ast::var::makeVariable( m_adaptationData.getNextVarId()
						, expr->getType()
						, expr->getOuterType()->getMember( expr->getMemberIndex() ).name
						, expr->getMemberFlags() );
					m_result = m_exprCache.makeIdentifier( m_typesCache, tmp );
				}
			}
		}

		if ( !m_result
			&& expr->isBuiltin() )
		{
			auto writeFuncCall = [this]( ast::type::TypePtr retType
				, std::string name )
			{
				return m_exprCache.makeFnCall( retType
					, m_exprCache.makeIdentifier( m_typesCache
						, ast::var::makeFunction( m_adaptationData.nextVarId
							, m_typesCache.getFunction( retType, {} )
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

		if ( !m_result
			&& !isRayTraceStage( m_writerConfig.shaderStage ) )
		{
			m_result = m_adaptationData.processPendingMbr( *expr->getOuterExpr()
				, expr->getMemberIndex()
				, *expr
				, *this );
		}

		if ( !m_result )
		{
			m_result = m_exprCache.makeMbrSelect( doSubmit( expr->getOuterExpr() )
				, expr->getMemberIndex()
				, expr->getMemberFlags() );
		}
	}

	void ExprAdapter::visitCombinedImageAccessCallExpr( ast::expr::CombinedImageAccessCall const * expr )
	{
		if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureSize1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureSizeBufferU )
		{
			doProcessTextureSize( *expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureQueryLod1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU )
		{
			doProcessTextureQueryLod( *expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureQueryLevels1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU )
		{
			doProcessTextureQueryLevels( *expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTexelFetch1DF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayU )
		{
			doProcessTexelFetch( *expr );
		}
		else if ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGrad1DShadowF
			&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF
			&& m_intrinsicsConfig.requiresShadowSampler )
		{
			doProcessTextureGradShadow( *expr );
		}
		else if ( ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU )
			|| ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGather2DShadowF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF ) )
		{
			doProcessTextureGather( *expr );
		}
		else if ( ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU )
			|| ( expr->getCombinedImageAccess() >= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF
				&& expr->getCombinedImageAccess() <= ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF ) )
		{
			doProcessTextureGatherOffsets( *expr );
		}
		else
		{
			doProcessTexture( *expr );
		}
	}

	void ExprAdapter::visitTimesExpr( ast::expr::Times const * expr )
	{
		if ( HlslExprAdapterInternal::isMatrix( expr->getType()->getKind() )
			|| HlslExprAdapterInternal::isMatrix( expr->getLHS()->getType()->getKind() )
			|| HlslExprAdapterInternal::isMatrix( expr->getRHS()->getType()->getKind() ) )
		{
			ast::var::VariableList params;
			params.push_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr->getLHS()->getType()
				, "lhs" ) );
			params.push_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr->getRHS()->getType()
				, "rhs" ) );
			ast::expr::ExprList argsList;
			argsList.emplace_back( doSubmit( expr->getLHS() ) );
			argsList.emplace_back( doSubmit( expr->getRHS() ) );
			m_result = m_exprCache.makeFnCall( expr->getType()
				, m_exprCache.makeIdentifier( m_typesCache, ast::var::makeVariable( m_adaptationData.getNextVarId()
					, m_typesCache.getFunction( expr->getType(), params )
					, "mul" ) )
				, std::move( argsList ) );
		}
		else
		{
			m_result = m_exprCache.makeTimes( expr->getType()
				, doSubmit( expr->getLHS() )
				, doSubmit( expr->getRHS() ) );
		}
	}

	void ExprAdapter::doPushSplImgArg( ast::expr::Expr const & imageArg
		, ast::var::VariablePtr imageVar
		, ast::expr::Expr const & samplerArg
		, ast::var::VariablePtr samplerVar
		, bool writeSampler
		, ast::expr::ExprList & args )
	{
		if ( imageArg.getKind() == ast::expr::Kind::eArrayAccess )
		{
			args.emplace_back( m_exprCache.makeArrayAccess( imageVar->getType()
				, m_exprCache.makeIdentifier( m_typesCache, imageVar )
				, doSubmit( static_cast< ast::expr::ArrayAccess const & >( imageArg ).getRHS() ) ) );
		}
		else
		{
			args.emplace_back( m_exprCache.makeIdentifier( m_typesCache, imageVar ) );
		}

		if ( writeSampler )
		{
			if ( samplerArg.getKind() == ast::expr::Kind::eArrayAccess )
			{
				args.emplace_back( m_exprCache.makeArrayAccess( samplerVar->getType()
					, m_exprCache.makeIdentifier( m_typesCache, samplerVar )
					, doSubmit( static_cast< ast::expr::ArrayAccess const & >( samplerArg ).getRHS() ) ) );
			}
			else
			{
				args.emplace_back( m_exprCache.makeIdentifier( m_typesCache, samplerVar ) );
			}
		}
	}

	void ExprAdapter::doProcessIntrinsicOperator( ast::expr::IntrinsicCall const & expr
		, IntrinsicAdaptationInfo const & adaptationInfo )
	{
		switch ( adaptationInfo.operatorChange.operatorKind )
		{
		case ast::expr::Kind::eLess:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeLess( m_typesCache
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		case ast::expr::Kind::eLessEqual:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeLessEqual( m_typesCache
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		case ast::expr::Kind::eGreater:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeGreater( m_typesCache
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		case ast::expr::Kind::eGreaterEqual:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeGreaterEqual( m_typesCache
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		case ast::expr::Kind::eEqual:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeEqual( m_typesCache
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		case ast::expr::Kind::eNotEqual:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeNotEqual( m_typesCache
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		case ast::expr::Kind::eLogNot:
			assert( expr.getArgList().size() == 1u );
			m_result = m_exprCache.makeLogNot( m_typesCache
				, doSubmit( *expr.getArgList()[0] ) );
			break;

		case ast::expr::Kind::eTimes:
			assert( expr.getArgList().size() == 2u );
			m_result = m_exprCache.makeTimes( expr.getArgList()[0]->getType()
				, doSubmit( *expr.getArgList()[0] )
				, doSubmit( *expr.getArgList()[1] ) );
			break;

		default:
			AST_Failure( "Unexpected operator type." );
			break;
		}
	}

	void ExprAdapter::doProcessIntrinsicAtomic( ast::expr::IntrinsicCall const & expr )
	{
		// GLSL atomics return the old value, while in HLSL it is the last parameter
		// Hence, we first create the output value variable.
		auto aliasVar = doMakeAlias( expr.getType() );
		m_container->addStmt( m_stmtCache.makeVariableDecl( aliasVar ) );
		// We then parse the parameters.
		ast::expr::ExprList args;

		for ( auto & arg : expr.getArgList() )
		{
			args.emplace_back( doSubmit( *arg ) );
		}

		// We add the created output alias to the parameters list.
		args.emplace_back( m_exprCache.makeIdentifier( m_typesCache, aliasVar ) );
		// We add the call to the intrinsic, and add it to the container
		m_container->addStmt( m_stmtCache.makeSimple( m_exprCache.makeIntrinsicCall( expr.getType()
			, expr.getIntrinsic()
			, std::move( args ) ) ) );
		// The resulting expression is now the alias.
		m_result = m_exprCache.makeIdentifier( m_typesCache, aliasVar );
	}

	void ExprAdapter::doProcessIntrinsicPackedPrimitiveIndices( ast::expr::IntrinsicCall const & expr )
	{
		ast::expr::ExprList args;

		for ( auto & arg : expr.getArgList() )
		{
			args.emplace_back( doSubmit( *arg ) );
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
					ast::expr::ExprPtr indices = doWriteUnpack1( *expr.getArgList().back() );
					auto dstType = getNonArrayType( primitiveIndices->getType() );
					auto dstIndex = m_exprCache.makeArrayAccess( dstType
						, m_exprCache.makeIdentifier( m_typesCache, primitiveIndices )
						, std::move( args.front() ) );
					m_result = m_exprCache.makeAssign( dstType, std::move( dstIndex ), std::move( indices ) );
				}
				break;
			case ast::type::OutputTopology::eLine:
				{
					ast::expr::ExprPtr indices = doWriteUnpack2( *expr.getArgList().back() );
					auto dstType = getNonArrayType( primitiveIndices->getType() );
					auto dstIndex = m_exprCache.makeArrayAccess( dstType
						, m_exprCache.makeIdentifier( m_typesCache, primitiveIndices )
						, std::move( args.front() ) );
					m_result = m_exprCache.makeAssign( dstType, std::move( dstIndex ), std::move( indices ) );
				}
				break;
			case ast::type::OutputTopology::eTriangle:
				{
					ast::expr::ExprPtr indices = doWriteUnpack3( *expr.getArgList().back() );
					auto dstType = getNonArrayType( primitiveIndices->getType() );
					auto dstIndex = m_exprCache.makeArrayAccess( dstType
						, m_exprCache.makeIdentifier( m_typesCache, primitiveIndices )
						, std::move( args.front() ) );
					m_result = m_exprCache.makeAssign( dstType, std::move( dstIndex ), std::move( indices ) );
				}
				break;
			default:
				break;
			}
		}
	}

	void ExprAdapter::doProcessSingleArgCompositeConstruct( ast::expr::CompositeConstruct const & expr )
	{
		auto arg = expr.getArgList().back().get();

		if ( getComponentCount( arg->getType()->getKind() ) == 1u
			&& isVectorType( expr.getType()->getKind() ) )
		{
			auto count = getComponentCount( expr.getType()->getKind() );

			if ( arg->getKind() == ast::expr::Kind::eLiteral )
			{
				ast::expr::ExprList args;

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( arg ) );
				}

				m_result = m_exprCache.makeCompositeConstruct( expr.getComposite()
					, expr.getComponent()
					, std::move( args ) );
			}
			else
			{
				m_result = m_exprCache.makeSwizzle( doSubmit( arg )
					, ast::expr::SwizzleKind{ count == 2u
						? ast::expr::SwizzleKind::e00
						: ( count == 3u
							? ast::expr::SwizzleKind::e000
							: ast::expr::SwizzleKind::e0000 ) } );
			}
		}
		else if ( isMatrixType( expr.getType()->getKind() )
			&& isMatrixType( arg->getType()->getKind() )
			&& expr.getType()->getKind() != arg->getType()->getKind() )
		{
			// Function-like cast to matrix of another type, make it a cast.
			m_result = m_exprCache.makeCast( expr.getType()
				, doSubmit( arg ) );
		}
	}

	bool ExprAdapter::doProcessTextureArg( ast::expr::Expr const & arg
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
				result = static_cast< ast::expr::CompositeConstruct const & >( arg ).getComposite() == ast::expr::CompositeType::eCombine;

				if ( result )
				{
					auto image = doSubmit( *static_cast< ast::expr::CompositeConstruct const & >( arg ).getArgList()[0] );
					auto imgVar = ast::findIdentifier( *image )->getVariable();
					auto sampler = doSubmit( *static_cast< ast::expr::CompositeConstruct const & >( arg ).getArgList()[1] );
					auto splVar = ast::findIdentifier( *sampler )->getVariable();
					doPushSplImgArg( *image, imgVar
						, *sampler, splVar
						, writeSampler, args );
				}
			}
			else
			{
				auto ident = ast::findIdentifier( arg );
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

	void ExprAdapter::doProcessImageSize( ast::expr::StorageImageAccessCall const & expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageSize", config );
		auto it = m_adaptationData.funcs.imageSizeFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageSizeFuncs.end() )
		{
			ast::var::VariableList resVars;
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[0]->getType()
				, "image" );
			parameters.emplace_back( image );
			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );
			ast::type::TypePtr uintType = m_typesCache.getUInt32();
			ast::expr::CompositeType composite{};

			switch ( getComponentCount( expr.getType()->getKind() ) )
			{
			case 1:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eScalar;
				break;
			case 2:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimY" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimY" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimZ" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec3;
				break;
			default:
				AST_Failure( "Invalid count for image size" );
				throw ast::Exception{ "Invalid count for image size" };
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;

			for ( auto const & var : resVars )
			{
				callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, var ) );
			}

			if ( config.dimension == ast::type::ImageDim::eCube
				&& !config.isArrayed )
			{
				auto var = ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dummy" );
				cont->addStmt( m_stmtCache.makeVariableDecl( var ) );
				callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, var ) );
			}

			cont->addStmt( m_stmtCache.makeSimple( m_exprCache.makeMemberFnCall( m_typesCache.getVoid()
				, m_exprCache.makeIdentifier( m_typesCache, ast::var::makeFunction( m_adaptationData.getNextVarId()
					, m_typesCache.getFunction( m_typesCache.getVoid(), resVars )
					, "GetDimensions" ) )
				, m_exprCache.makeIdentifier( m_typesCache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto const & var : resVars )
			{
				resArgs.emplace_back( m_exprCache.makeCast( m_typesCache.getInt32()
					, m_exprCache.makeIdentifier( m_typesCache, var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( m_stmtCache.makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( m_stmtCache.makeReturn( m_exprCache.makeCompositeConstruct( composite
					, ast::type::Kind::eInt32
					, std::move( resArgs ) ) ) );
			}

			it = m_adaptationData.funcs.imageSizeFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		argList.emplace_back( doSubmit( *expr.getArgList().front() ) );
		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageLoad( ast::expr::StorageImageAccessCall const & expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto callRetType = m_typesCache.getSampledType( config.format );
		ast::expr::ExprList argList;
		ast::var::VariableList paramList;
		uint32_t index = 0u;
		paramList.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
			, expr.getArgList().front()->getType()
			, "p" + std::to_string( index ) ) );
		++index;

		for ( auto it = expr.getArgList().begin() + 1u; it != expr.getArgList().end(); ++it )
		{
			argList.emplace_back( doSubmit( **it ) );
			paramList.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, argList.back()->getType()
				, "p" + std::to_string( index ) ) );
			++index;
		}

		m_result = m_exprCache.makeMemberFnCall( callRetType
			, m_exprCache.makeIdentifier( m_typesCache, ast::var::makeFunction( m_adaptationData.getNextVarId()
				, m_typesCache.getFunction( expr.getType(), paramList )
				, "Load" ) )
			, doSubmit( *expr.getArgList().front() )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageStore( ast::expr::StorageImageAccessCall const & expr
		, std::map< std::string, FuncNames::Function, std::less<> > & imageStoreFuncs )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageStore", config );
		auto it = imageStoreFuncs.find( funcName );

		if ( it == imageStoreFuncs.end() )
		{
			auto & args = expr.getArgList();
			auto hasSample = expr.getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSF
				|| expr.getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSArrayF
				|| expr.getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSI
				|| expr.getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSArrayI
				|| expr.getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSU
				|| expr.getImageAccess() == ast::expr::StorageImageAccess::eImageStore2DMSArrayU;
			auto dataType = args.back()->getType();
			ast::var::VariableList parameters;
			parameters.push_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[0]->getType()
				, "image" ) );
			parameters.push_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[1]->getType()
				, "coord" ) );

			if ( hasSample )
			{
				parameters.push_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, expr.getArgList()[2]->getType()
					, "sample" ) );
			}

			parameters.push_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, dataType
				, "data" ) );
			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );
			// Function content
			//	image[coord] = data
			cont->addStmt( m_stmtCache.makeSimple( m_exprCache.makeAssign( dataType
				, m_exprCache.makeArrayAccess( m_typesCache.getSampledType( config.format )
					, m_exprCache.makeIdentifier( m_typesCache, parameters[0] )
					, m_exprCache.makeIdentifier( m_typesCache, parameters[1] ) )
				, m_exprCache.makeIdentifier( m_typesCache, parameters.back() ) ) ) );

			it = imageStoreFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr.getArgList() )
		{
			argList.emplace_back( doSubmit( *arg ) );
		}

		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomic( ast::expr::StorageImageAccessCall const & expr
		, std::string const & name
		, std::map< std::string, FuncNames::Function, std::less<> > & imageAtomicFuncs )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageAtomic" + name, config );
		auto it = imageAtomicFuncs.find( funcName );

		if ( it == imageAtomicFuncs.end() )
		{
			// Declare the function
			auto dataType = expr.getArgList()[2]->getType();
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[0]->getType()
				, "image" );
			auto coord = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[1]->getType()
				, "coord" );
			auto data = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, dataType
				, "data" );
			parameters.emplace_back( image );
			parameters.emplace_back( coord );
			parameters.emplace_back( data );
			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );
			// Function content
			auto res = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, dataType
				, "res" );
			cont->addStmt( m_stmtCache.makeVariableDecl( res ) );

			//	The call to Interlocked<name>
			ast::expr::ExprList callArgs;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( m_exprCache.makeArrayAccess( m_typesCache.getSampledType( config.format )
				, m_exprCache.makeIdentifier( m_typesCache, image )
				, m_exprCache.makeIdentifier( m_typesCache, coord ) ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p0" ) );
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, data ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p1" ) );
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, res ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p2" ) );

			cont->addStmt( m_stmtCache.makeSimple( m_exprCache.makeFnCall( m_typesCache.getVoid()
				, m_exprCache.makeIdentifier( m_typesCache, ast::var::makeFunction( m_adaptationData.getNextVarId()
					, m_typesCache.getFunction( m_typesCache.getVoid(), callParameters )
					, "Interlocked" + name ) )
				, std::move( callArgs ) ) ) );

			//	The return statement
			cont->addStmt( m_stmtCache.makeReturn( m_exprCache.makeIdentifier( m_typesCache, res ) ) );

			it = imageAtomicFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr.getArgList() )
		{
			argList.emplace_back( doSubmit( *arg ) );
		}

		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessImageAtomicAdd( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "Add", m_adaptationData.funcs.imageAtomicAddFuncs );
	}

	void ExprAdapter::doProcessImageAtomicMin( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "Min", m_adaptationData.funcs.imageAtomicMinFuncs );
	}

	void ExprAdapter::doProcessImageAtomicMax( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "Max", m_adaptationData.funcs.imageAtomicMaxFuncs );
	}

	void ExprAdapter::doProcessImageAtomicAnd( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "And", m_adaptationData.funcs.imageAtomicAndFuncs );
	}

	void ExprAdapter::doProcessImageAtomicOr( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "Or", m_adaptationData.funcs.imageAtomicOrFuncs );
	}

	void ExprAdapter::doProcessImageAtomicXor( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "Xor", m_adaptationData.funcs.imageAtomicXorFuncs );
	}

	void ExprAdapter::doProcessImageAtomicExchange( ast::expr::StorageImageAccessCall const & expr )
	{
		doProcessImageAtomic( expr, "Exchange", m_adaptationData.funcs.imageAtomicExchangeFuncs );
	}

	void ExprAdapter::doProcessImageAtomicCompSwap( ast::expr::StorageImageAccessCall const & expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::Image >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_imageAtomicCompSwap", config );
		auto it = m_adaptationData.funcs.imageAtomicCompSwapFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageAtomicCompSwapFuncs.end() )
		{
			// Declare the function
			auto dataType = expr.getArgList()[2]->getType();
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[0]->getType()
				, "image" );
			auto coord = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[1]->getType()
				, "coord" );
			auto compare = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[2]->getType()
				, "compare" );
			auto data = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, dataType, "data" );
			parameters.emplace_back( image );
			parameters.emplace_back( coord );
			parameters.emplace_back( compare );
			parameters.emplace_back( data );
			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );
			// Function content
			auto res = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, dataType
				, "res" );
			cont->addStmt( m_stmtCache.makeVariableDecl( res ) );

			//	The call to InterlockedCompareExchange
			ast::expr::ExprList callArgs;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( m_exprCache.makeArrayAccess( m_typesCache.getSampledType( config.format )
				, m_exprCache.makeIdentifier( m_typesCache, image )
				, m_exprCache.makeIdentifier( m_typesCache, coord ) ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p0" ) );
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, compare ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p1" ) );
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, data ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p2" ) );
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, res ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p3" ) );

			cont->addStmt( m_stmtCache.makeSimple( m_exprCache.makeFnCall( m_typesCache.getVoid()
				, m_exprCache.makeIdentifier( m_typesCache, ast::var::makeFunction( m_adaptationData.getNextVarId()
					, m_typesCache.getFunction( expr.getType(), callParameters )
					, "InterlockedCompareExchange" ) )
				, std::move( callArgs ) ) ) );

			//	The return statement
			cont->addStmt( m_stmtCache.makeReturn( m_exprCache.makeIdentifier( m_typesCache, res ) ) );

			it = m_adaptationData.funcs.imageAtomicCompSwapFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr.getArgList() )
		{
			argList.emplace_back( doSubmit( *arg ) );
		}

		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureSize( ast::expr::CombinedImageAccessCall const & expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_textureSize", config );
		auto it = m_adaptationData.funcs.imageSizeFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageSizeFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, imgArgType->getImageType()
				, "image" );
			parameters.emplace_back( image );
			ast::var::VariablePtr lod;

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				lod = ast::var::makeVariable( m_adaptationData.getNextVarId()
					, expr.getArgList()[1]->getType()
					, "lod" );
				parameters.emplace_back( lod );
			}

			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );
			ast::type::TypePtr uintType = m_typesCache.getUInt32();
			ast::var::VariableList resVars;
			ast::expr::CompositeType composite{};

			switch ( getComponentCount( expr.getType()->getKind() ) )
			{
			case 1:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eScalar;
				break;
			case 2:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimY" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec2;
				break;
			case 3:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimY" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimZ" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				composite = ast::expr::CompositeType::eVec3;
				break;
			default:
				AST_Failure( "Invalid count for image size" );
				throw ast::Exception{ "Invalid count for texture size" };
			}

			// The call to image.GetDimensions
			ast::expr::ExprList callArgs;
			uint32_t index = 0u;
			ast::var::VariableList callParameters;

			if ( lod )
			{
				callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, lod ) );
				callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, callArgs.back()->getType()
					, "p" + std::to_string( index ) ) );
				++index;
			}
			else if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				callArgs.emplace_back( m_exprCache.makeLiteral( m_typesCache, 0u ) );
				callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, callArgs.back()->getType()
					, "p" + std::to_string( index ) ) );
				++index;
			}

			for ( auto const & var : resVars )
			{
				callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, callArgs.back()->getType()
					, "p" + std::to_string( index ) ) );
				++index;
			}

			if ( config.dimension != ast::type::ImageDim::eBuffer )
			{
				auto var = ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "levels" );
				cont->addStmt( m_stmtCache.makeVariableDecl( var ) );
				callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, callArgs.back()->getType()
					, "p" + std::to_string( index ) ) );
			}

			cont->addStmt( m_stmtCache.makeSimple( m_exprCache.makeMemberFnCall( m_typesCache.getVoid()
				, m_exprCache.makeIdentifier( m_typesCache
					, ast::var::makeFunction( m_adaptationData.getNextVarId()
						, m_typesCache.getFunction( expr.getType(), callParameters )
						, "GetDimensions" ) )
				, m_exprCache.makeIdentifier( m_typesCache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			ast::expr::ExprList resArgs;

			for ( auto const & var : resVars )
			{
				resArgs.emplace_back( m_exprCache.makeCast( m_typesCache.getInt32()
					, m_exprCache.makeIdentifier( m_typesCache, var ) ) );
			}

			if ( composite == ast::expr::CompositeType::eScalar )
			{
				cont->addStmt( m_stmtCache.makeReturn( std::move( resArgs.back() ) ) );
			}
			else
			{
				cont->addStmt( m_stmtCache.makeReturn( m_exprCache.makeCompositeConstruct( composite
					, ast::type::Kind::eInt32
					, std::move( resArgs ) ) ) );
			}

			it = m_adaptationData.funcs.imageSizeFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr.getArgList() )
		{
			if ( !doProcessTextureArg( *arg, false, argList ) )
			{
				argList.emplace_back( doSubmit( *arg ) );
			}
		}

		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLod( ast::expr::CombinedImageAccessCall const & expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_textureQueryLod", config );
		auto it = m_adaptationData.funcs.imageLodFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageLodFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, imgArgType->getImageType()
				, "texImage" );
			auto sampler = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, imgArgType->getSamplerType()
				, "texSampler" );
			auto coord = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, expr.getArgList()[1]->getType()
				, "P" );
			parameters.emplace_back( image );
			parameters.emplace_back( sampler );
			parameters.emplace_back( coord );

			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );

			// The call to image.CalculateLevelOfDetail
			ast::expr::ExprList callArgs;
			uint32_t index = 0u;
			ast::var::VariableList callParameters;
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, sampler ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p" + std::to_string( index ) ) );
			++index;
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, coord ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p" + std::to_string( index ) ) );

			// The return statement
			ast::expr::ExprList resArgs;
			resArgs.emplace_back( m_exprCache.makeMemberFnCall( m_typesCache.getVoid()
				, m_exprCache.makeIdentifier( m_typesCache, ast::var::makeFunction( m_adaptationData.getNextVarId()
					, m_typesCache.getFunction( expr.getType(), callParameters )
					, "CalculateLevelOfDetail" ) )
				, m_exprCache.makeIdentifier( m_typesCache, image )
				, std::move( callArgs ) ) );
			resArgs.emplace_back( m_exprCache.makeLiteral( m_typesCache, 0.0f ) );

			cont->addStmt( m_stmtCache.makeReturn( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec2
				, ast::type::Kind::eFloat
				, std::move( resArgs ) ) ) );

			it = m_adaptationData.funcs.imageLodFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;

		for ( auto & arg : expr.getArgList() )
		{
			if ( !doProcessTextureArg( *arg, true, argList ) )
			{
				argList.emplace_back( doSubmit( *arg ) );
			}
		}

		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTextureQueryLevels( ast::expr::CombinedImageAccessCall const & expr )
	{
		auto imgArgType = std::static_pointer_cast< ast::type::CombinedImage >( expr.getArgList()[0]->getType() );
		auto config = imgArgType->getConfig();
		auto funcName = HlslExprAdapterInternal::getName( "SDW_textureQueryLevels", config );
		auto it = m_adaptationData.funcs.imageLevelsFuncs.find( funcName );

		if ( it == m_adaptationData.funcs.imageLevelsFuncs.end() )
		{
			ast::var::VariableList parameters;
			auto image = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, imgArgType->getImageType()
				, "image" );
			parameters.emplace_back( image );

			auto functionType = m_typesCache.getFunction( expr.getType(), parameters );
			auto functionVar = ast::var::makeFunction( m_adaptationData.getNextVarId()
				, functionType
				, funcName );
			auto cont = m_stmtCache.makeFunctionDecl( functionVar );
			ast::type::TypePtr uintType = m_typesCache.getUInt32();
			ast::var::VariableList resVars;

			switch ( config.dimension )
			{
			case ast::type::ImageDim::e1D:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				if ( config.isArrayed )
				{
					resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
						, uintType
						, "dimY" ) );
					cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				}
				break;
			case ast::type::ImageDim::e2D:
			case ast::type::ImageDim::eCube:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimY" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				if ( config.isArrayed )
				{
					resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
						, uintType
						, "dimZ" ) );
					cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				}
				break;
			case ast::type::ImageDim::e3D:
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimX" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimY" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
				resVars.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, uintType
					, "dimZ" ) );
				cont->addStmt( m_stmtCache.makeVariableDecl( resVars.back() ) );
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
				callArgs.emplace_back( m_exprCache.makeLiteral( m_typesCache, 0u ) );
				callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, callArgs.back()->getType()
					, "p" + std::to_string( index ) ) );
				++index;
			}

			for ( auto const & var : resVars )
			{
				callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, var ) );
				callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
					, callArgs.back()->getType()
					, "p" + std::to_string( index ) ) );
				++index;
			}

			auto levels = ast::var::makeVariable( m_adaptationData.getNextVarId()
				, uintType
				, "levels" );
			cont->addStmt( m_stmtCache.makeVariableDecl( levels ) );
			callArgs.emplace_back( m_exprCache.makeIdentifier( m_typesCache, levels ) );
			callParameters.emplace_back( ast::var::makeVariable( m_adaptationData.getNextVarId()
				, callArgs.back()->getType()
				, "p" + std::to_string( index ) ) );

			cont->addStmt( m_stmtCache.makeSimple( m_exprCache.makeMemberFnCall( m_typesCache.getVoid()
				, m_exprCache.makeIdentifier( m_typesCache
					, ast::var::makeFunction( m_adaptationData.getNextVarId()
						, m_typesCache.getFunction( expr.getType(), callParameters )
						, "GetDimensions" ) )
				, m_exprCache.makeIdentifier( m_typesCache, image )
				, std::move( callArgs ) ) ) );

			// The return statement
			cont->addStmt( m_stmtCache.makeReturn( m_exprCache.makeIdentifier( m_typesCache, levels ) ) );

			it = m_adaptationData.funcs.imageLevelsFuncs.try_emplace( funcName, functionType, functionVar ).first;
			m_intrinsics->addStmt( std::move( cont ) );
		}

		ast::expr::ExprList argList;
		doProcessTextureArg( *expr.getArgList()[0], false, argList );

		m_result = m_exprCache.makeFnCall( it->second.type->getReturnType()
			, m_exprCache.makeIdentifier( m_typesCache, it->second.var )
			, std::move( argList ) );
	}

	void ExprAdapter::doProcessTexelFetch( ast::expr::CombinedImageAccessCall const & expr )
	{
		ast::expr::ExprList args;
		// First parameter should be sampled image
		if ( auto isImage = doProcessTextureArg( *expr.getArgList()[0], false, args );
			!isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		if ( expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchBufferF
			|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchBufferI
			|| expr.getCombinedImageAccess() == ast::expr::CombinedImageAccess::eTexelFetchBufferU )
		{
			// For those texel fetch functions, no lod, and none needed.
			assert( expr.getArgList().size() >= 2u );
			args.emplace_back( doSubmit( *expr.getArgList()[1] ) );
		}
		else
		{
			ast::expr::ExprList merged;
			// For those texel fetch functions, lod is put inside the coords parameter, instead of being aside.
			assert( expr.getArgList().size() >= 3u );
			// Merge second and third parameters to the appropriate vector type (int=>ivec2, ivec2=>ivec3, ivec3=>ivec4).
			merged.emplace_back( doSubmit( *expr.getArgList()[1] ) );
			merged.emplace_back( doSubmit( *expr.getArgList()[2] ) );

			switch ( merged[0]->getType()->getKind() )
			{
			case ast::type::Kind::eInt32:
				args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec2
					, ast::type::Kind::eInt32
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec2I32:
				args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec3
					, ast::type::Kind::eInt32
					, std::move( merged ) ) );
				break;
			case ast::type::Kind::eVec3I32:
				args.emplace_back( m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec4
					, ast::type::Kind::eInt32
					, std::move( merged ) ) );
				break;
			default:
				break;
			}
		}

		// Other parameters remain unchanged.
		for ( size_t i = 3u; i < expr.getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( *expr.getArgList()[i] ) );
		}

		m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
			, expr.getCombinedImageAccess()
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGradShadow( ast::expr::CombinedImageAccessCall const & expr )
	{
		// Sample grad doesn't support SampleComparisonState, replace it with a SampleCmp.
		ast::expr::ExprList args;
		// First parameter should be sampled image
		if ( auto isImage = doProcessTextureArg( *expr.getArgList()[0], false, args );
			!isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		assert( expr.getArgList().size() >= 5u );
		// Second param is texcoord
		args.emplace_back( doSubmit( *expr.getArgList()[1] ) );
		// Third param is dref value
		args.emplace_back( doSubmit( *expr.getArgList()[2] ) );
		// Fourth and fifth params ard dPdx and dPdy, drop them

		// Other parameters remain unchanged.
		for ( size_t i = 5u; i < expr.getArgList().size(); ++i )
		{
			args.emplace_back( doSubmit( *expr.getArgList()[i] ) );
		}

		auto result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
			, HlslExprAdapterInternal::getSampleCmp( expr.getCombinedImageAccess() )
			, std::move( args ) );

		// Reparse the created expression, textureProj cases.
		visitCombinedImageAccessCallExpr( result.get() );
	}

	void ExprAdapter::doProcessTextureGather( ast::expr::CombinedImageAccessCall const & expr )
	{
		auto kind = expr.getCombinedImageAccess();
		assert( expr.getArgList().size() >= 2u );
		uint32_t index = 0u;
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessTextureArg( *expr.getArgList()[index], true, args );
		++index;

		if ( !isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		auto coord = doSubmit( *expr.getArgList()[index] );
		++index;

		if ( !isShadow( kind ) )
		{
			// Component
			args.emplace_back( doSubmit( *expr.getArgList()[index] ) );
			++index;
		}

		// Coord
		args.emplace_back( std::move( coord ) );

		if ( isShadow( kind ) )
		{
			// Dref value
			assert( expr.getArgList().size() >= 3u );
			args.emplace_back( doSubmit( *expr.getArgList()[index] ) );
			++index;
		}

		while ( index < expr.getArgList().size() )
		{
			auto & origArg = expr.getArgList()[index];
			++index;

			if ( origArg->getKind() == ast::expr::Kind::eAggrInit )
			{
				auto aliasVar = doMakeAlias( origArg->getType() );
				m_container->addStmt( m_stmtCache.makeSimple( m_exprCache.makeInit( m_exprCache.makeIdentifier( m_typesCache, aliasVar )
					, doSubmit( *origArg ) ) ) );
				args.emplace_back( m_exprCache.makeIdentifier( m_typesCache, aliasVar ) );
			}
			else
			{
				args.emplace_back( doSubmit( *origArg ) );
			}
		}

		m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTextureGatherOffsets( ast::expr::CombinedImageAccessCall const & expr )
	{
		auto kind = expr.getCombinedImageAccess();
		assert( expr.getArgList().size() >= 3u );
		uint32_t index = 0u;
		ast::expr::ExprList args;
		// First parameter should be sampled image
		auto isImage = doProcessTextureArg( *expr.getArgList()[index], true, args );
		++index;

		if ( !isImage )
		{
			AST_Failure( "First parameter should be sampled image" );
		}

		if ( !isShadow( kind ) )
		{
			// Component
			args.emplace_back( doSubmit( *expr.getArgList()[index] ) );
			++index;
		}

		// Coord
		args.emplace_back( doSubmit( *expr.getArgList()[index] ) );
		++index;

		if ( isShadow( kind ) )
		{
			// Dref value
			assert( expr.getArgList().size() >= 4u );
			args.emplace_back( doSubmit( *expr.getArgList()[index] ) );
			++index;
		}

		// Next parameter contains the 4 offsets.
		auto const & offset = *expr.getArgList()[index];
		assert( getArraySize( offset.getType() ) == 4u );
		auto arrayType = std::static_pointer_cast< ast::type::Array >( offset.getType() );
		args.emplace_back( ast::resolveConstants( m_exprCache
			, *m_exprCache.makeArrayAccess( m_typesCache.getBasicType( arrayType->getType()->getKind() )
				, ast::ExprCloner::submit( m_exprCache, &offset )
				, m_exprCache.makeLiteral( m_typesCache, 0u ) ).get() ) );
		args.emplace_back( ast::resolveConstants( m_exprCache
			, *m_exprCache.makeArrayAccess( m_typesCache.getBasicType( arrayType->getType()->getKind() )
				, ast::ExprCloner::submit( m_exprCache, &offset )
				, m_exprCache.makeLiteral( m_typesCache, 1u ) ).get() ) );
		args.emplace_back( ast::resolveConstants( m_exprCache
			, *m_exprCache.makeArrayAccess( m_typesCache.getBasicType( arrayType->getType()->getKind() )
				, ast::ExprCloner::submit( m_exprCache, &offset )
				, m_exprCache.makeLiteral( m_typesCache, 2u ) ).get() ) );
		args.emplace_back( ast::resolveConstants( m_exprCache
			, *m_exprCache.makeArrayAccess( m_typesCache.getBasicType( arrayType->getType()->getKind() )
				, ast::ExprCloner::submit( m_exprCache, &offset )
				, m_exprCache.makeLiteral( m_typesCache, 3u ) ).get() ) );

		m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
			, kind
			, std::move( args ) );
	}

	void ExprAdapter::doProcessTexture( ast::expr::CombinedImageAccessCall const & expr )
	{
		ast::expr::ExprList args;
		uint32_t index = 0u;
		uint32_t sampler = 0u;

		for ( auto & arg : expr.getArgList() )
		{
			if ( doProcessTextureArg( *arg, true, args ) )
			{
				sampler = index;
			}
			else if ( index == sampler + 1
				&& isProj( expr.getCombinedImageAccess() ) )
			{
				args.emplace_back(HlslExprAdapterInternal::writeProjTexCoords( m_exprCache
					, m_typesCache
					, m_adaptationData.nextVarId
					, expr.getCombinedImageAccess()
					, doSubmit( *arg ) ) );
			}
			else
			{
				args.emplace_back( doSubmit( *arg ) );
			}

			++index;
		}

		if ( isBiasAndOffset( expr.getCombinedImageAccess() )
			|| isShadowLodOffset( expr.getCombinedImageAccess() ) )
		{
			auto biasOrOffset = std::move( args.back() );
			args.pop_back();
			auto offsetOrLod = std::move( args.back() );
			args.pop_back();
			args.emplace_back( std::move( biasOrOffset ) );
			args.emplace_back( std::move( offsetOrLod ) );
		}

		m_result = m_exprCache.makeCombinedImageAccessCall( expr.getType()
			, expr.getCombinedImageAccess()
			, std::move( args ) );
	}

	ast::var::VariablePtr ExprAdapter::doMakeAlias( ast::type::TypePtr type )
	{
		m_adaptationData.getNextAliasId();
		return ast::var::makeVariable( m_adaptationData.getNextVarId()
			, std::move( type )
			, "temp_" + std::to_string( m_adaptationData.aliasId )
			, ( ast::var::Flag::eAlias
				| ast::var::Flag::eTemp ) );
	}

	ast::expr::ExprPtr ExprAdapter::doWriteUnpack1( ast::expr::Expr const & packed )
	{
		auto value = doSubmit( &packed );
		return m_exprCache.makeBitAnd( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 0x000000FFu  ) );
	}

	ast::expr::ExprPtr ExprAdapter::doWriteUnpack2( ast::expr::Expr const & packed )
	{
		ast::expr::ExprList args;
		auto value = doSubmit( &packed );
		args.emplace_back( m_exprCache.makeBitAnd( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 0x000000FFu ) ) );
		value = doSubmit( &packed );
		value = m_exprCache.makeBitAnd( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 0x0000FF00u ) );
		args.emplace_back( m_exprCache.makeRShift( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 8u ) ) );
		return m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec2
			, packed.getType()->getKind()
			, std::move( args ) );
	}

	ast::expr::ExprPtr ExprAdapter::doWriteUnpack3( ast::expr::Expr const & packed )
	{
		ast::expr::ExprList args;
		auto value = doSubmit( &packed );
		args.emplace_back( m_exprCache.makeBitAnd( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 0x000000FFu ) ) );
		value = doSubmit( &packed );
		value = m_exprCache.makeBitAnd( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 0x0000FF00u ) );
		args.emplace_back( m_exprCache.makeRShift( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 8u ) ) );
		value = doSubmit( &packed );
		value = m_exprCache.makeBitAnd( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 0x00FF0000u ) );
		args.emplace_back( m_exprCache.makeRShift( packed.getType()
			, std::move( value )
			, m_exprCache.makeLiteral( m_typesCache, 16u ) ) );
		return m_exprCache.makeCompositeConstruct( ast::expr::CompositeType::eVec3
			, packed.getType()->getKind()
			, std::move( args ) );
	}
}
