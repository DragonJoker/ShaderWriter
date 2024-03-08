/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/SimplifyStatements.hpp"

#include "ShaderAST/ShaderLog.hpp"
#include "ShaderAST/Expr/ExprLiteral.hpp"
#include "ShaderAST/Stmt/StmtCache.hpp"
#include "ShaderAST/Visitors/CloneExpr.hpp"
#include "ShaderAST/Visitors/ResolveConstants.hpp"

namespace ast
{
	namespace simpl
	{
		namespace helpers
		{
			static expr::ExprPtr makeToBoolCast( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::ExprPtr expr )
			{
				auto componentCount = getComponentCount( expr->getType()->getKind() );
				expr::ExprPtr result{};
				auto type = expr->getType();

				if ( componentCount == 1u )
				{
					result = exprCache.makeNotEqual( typesCache
						, std::move( expr )
						, makeZero( exprCache, type ) );
				}
				else
				{
					expr::ExprList args;
					expr::ExprPtr newExpr = std::move( expr );
					type = typesCache.getBasicType( type::getScalarType( type->getKind() ) );

					for ( auto i = 0u; i < componentCount; ++i )
					{
						args.emplace_back( exprCache.makeNotEqual( typesCache
							, exprCache.makeSwizzle( ExprCloner::submit( exprCache, *newExpr ), expr::SwizzleKind::fromOffset( i ) )
							, makeZero( exprCache, type ) ) );
					}

					result = exprCache.makeCompositeConstruct( getCompositeType( componentCount )
						, type::Kind::eBoolean
						, std::move( args ) );
				}

				return result;
			}

			static expr::ExprPtr makeFromBoolCast( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::ExprPtr expr
				, type::Kind dstScalarType )
			{
				auto componentCount = getComponentCount( expr->getType()->getKind() );
				expr::ExprPtr result{};

				if ( componentCount == 1u )
				{
					auto scalarType = typesCache.getBasicType( dstScalarType );
					result = exprCache.makeQuestion( scalarType
						, std::move( expr )
						, makeOne( exprCache, typesCache.getBasicType( dstScalarType ) )
						, makeZero( exprCache, typesCache.getBasicType( dstScalarType ) ) );
				}
				else
				{
					expr::ExprList args;
					expr::ExprPtr newExpr = std::move( expr );
					auto scalarType = typesCache.getBasicType( dstScalarType );

					for ( auto i = 0u; i < componentCount; ++i )
					{
						args.emplace_back( exprCache.makeQuestion( scalarType
							, exprCache.makeSwizzle( ExprCloner::submit( exprCache, *newExpr ), expr::SwizzleKind::fromOffset( i ) )
							, makeOne( exprCache, typesCache.getBasicType( dstScalarType ) )
							, makeZero( exprCache, typesCache.getBasicType( dstScalarType ) ) ) );
					}

					result = exprCache.makeCompositeConstruct( getCompositeType( componentCount )
						, dstScalarType
						, std::move( args ) );
				}

				return result;
			}

			static uint32_t getSwizzleIndex( expr::SwizzleKind::Value swizzle )
			{
				return swizzle == expr::SwizzleKind::e0
					? 0u
					: ( swizzle == expr::SwizzleKind::e1
						? 1u
						: ( swizzle == expr::SwizzleKind::e2
							? 2u
							: 3u ) );
			}

			static expr::SwizzleKind getFinalSwizzle( std::vector< expr::SwizzleKind > const & values
				, std::vector< uint32_t > const & indices )
			{
				expr::SwizzleKind result;
				uint32_t shift = 0u;

				for ( auto & index : indices )
				{
					AST_Assert( index < values.size() );
					auto shifted = expr::SwizzleKind::Value( values[index].getValue() >> shift );
					auto ored = expr::SwizzleKind::Value( result.getValue() | shifted );
					result = expr::SwizzleKind{ ored };
					shift += 4u;
				}

				return result;
			}

			static type::TypePtr getExpectedReturnType( expr::StorageImageAccessCall const * expr )
			{
				auto result = expr->getType();

				if ( expr->getImageAccess() >= expr::StorageImageAccess::eImageLoad1DF
					&& expr->getImageAccess() <= expr::StorageImageAccess::eImageLoad2DMSArrayU )
				{
					auto scalar = type::getScalarType( result->getKind() );
					auto components = type::getComponentCount( result );

					if ( components != 4u )
					{
						result = result->getTypesCache().getVec4Type( scalar );
					}
				}

				return result;
			}

			static constexpr uint32_t InvalidComponentCount = ~0u;

			static uint32_t getReturnComponentCount( expr::CombinedImageAccess value )
			{
				switch ( value )
				{
				case expr::CombinedImageAccess::eTexture1DShadowF:
				case expr::CombinedImageAccess::eTexture1DShadowFBias:
				case expr::CombinedImageAccess::eTexture2DShadowF:
				case expr::CombinedImageAccess::eTexture2DShadowFBias:
				case expr::CombinedImageAccess::eTextureCubeShadowF:
				case expr::CombinedImageAccess::eTextureCubeShadowFBias:
				case expr::CombinedImageAccess::eTexture1DArrayShadowF:
				case expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
				case expr::CombinedImageAccess::eTexture2DArrayShadowF:
				case expr::CombinedImageAccess::eTextureCubeArrayShadowF:
				case expr::CombinedImageAccess::eTextureOffset1DShadowF:
				case expr::CombinedImageAccess::eTextureOffset2DShadowF:
				case expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
				case expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
				case expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
				case expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
				case expr::CombinedImageAccess::eTextureGrad1DShadowF:
				case expr::CombinedImageAccess::eTextureGrad2DShadowF:
				case expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
				case expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
				case expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
				case expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
				case expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
				case expr::CombinedImageAccess::eTextureProj1DShadowF:
				case expr::CombinedImageAccess::eTextureProj1DShadowFBias:
				case expr::CombinedImageAccess::eTextureProj2DShadowF:
				case expr::CombinedImageAccess::eTextureProj2DShadowFBias:
				case expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
				case expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
				case expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
				case expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
				case expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
				case expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
				case expr::CombinedImageAccess::eTextureLod1DShadowF:
				case expr::CombinedImageAccess::eTextureLod2DShadowF:
				case expr::CombinedImageAccess::eTextureLodCubeShadowF:
				case expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
				case expr::CombinedImageAccess::eTextureLod2DArrayShadowF:
				case expr::CombinedImageAccess::eTextureLodCubeArrayShadowF:
				case expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
				case expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
				case expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
				case expr::CombinedImageAccess::eTextureProjLod1DShadowF:
				case expr::CombinedImageAccess::eTextureProjLod2DShadowF:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
					return 1u;

				case expr::CombinedImageAccess::eTexture1DF:
				case expr::CombinedImageAccess::eTexture1DFBias:
				case expr::CombinedImageAccess::eTexture2DF:
				case expr::CombinedImageAccess::eTexture2DFBias:
				case expr::CombinedImageAccess::eTexture3DF:
				case expr::CombinedImageAccess::eTexture3DFBias:
				case expr::CombinedImageAccess::eTextureCubeF:
				case expr::CombinedImageAccess::eTextureCubeFBias:
				case expr::CombinedImageAccess::eTexture1DArrayF:
				case expr::CombinedImageAccess::eTexture1DArrayFBias:
				case expr::CombinedImageAccess::eTexture2DArrayF:
				case expr::CombinedImageAccess::eTexture2DArrayFBias:
				case expr::CombinedImageAccess::eTextureCubeArrayF:
				case expr::CombinedImageAccess::eTextureCubeArrayFBias:
				case expr::CombinedImageAccess::eTexture1DI:
				case expr::CombinedImageAccess::eTexture1DIBias:
				case expr::CombinedImageAccess::eTexture2DI:
				case expr::CombinedImageAccess::eTexture2DIBias:
				case expr::CombinedImageAccess::eTexture3DI:
				case expr::CombinedImageAccess::eTexture3DIBias:
				case expr::CombinedImageAccess::eTextureCubeI:
				case expr::CombinedImageAccess::eTextureCubeIBias:
				case expr::CombinedImageAccess::eTexture1DArrayI:
				case expr::CombinedImageAccess::eTexture1DArrayIBias:
				case expr::CombinedImageAccess::eTexture2DArrayI:
				case expr::CombinedImageAccess::eTexture2DArrayIBias:
				case expr::CombinedImageAccess::eTextureCubeArrayI:
				case expr::CombinedImageAccess::eTextureCubeArrayIBias:
				case expr::CombinedImageAccess::eTexture1DU:
				case expr::CombinedImageAccess::eTexture1DUBias:
				case expr::CombinedImageAccess::eTexture2DU:
				case expr::CombinedImageAccess::eTexture2DUBias:
				case expr::CombinedImageAccess::eTexture3DU:
				case expr::CombinedImageAccess::eTexture3DUBias:
				case expr::CombinedImageAccess::eTextureCubeU:
				case expr::CombinedImageAccess::eTextureCubeUBias:
				case expr::CombinedImageAccess::eTexture1DArrayU:
				case expr::CombinedImageAccess::eTexture1DArrayUBias:
				case expr::CombinedImageAccess::eTexture2DArrayU:
				case expr::CombinedImageAccess::eTexture2DArrayUBias:
				case expr::CombinedImageAccess::eTextureCubeArrayU:
				case expr::CombinedImageAccess::eTextureCubeArrayUBias:
				case expr::CombinedImageAccess::eTextureOffset1DF:
				case expr::CombinedImageAccess::eTextureOffset2DF:
				case expr::CombinedImageAccess::eTextureOffset3DF:
				case expr::CombinedImageAccess::eTextureOffset1DArrayF:
				case expr::CombinedImageAccess::eTextureOffset2DArrayF:
				case expr::CombinedImageAccess::eTextureOffset1DI:
				case expr::CombinedImageAccess::eTextureOffset2DI:
				case expr::CombinedImageAccess::eTextureOffset3DI:
				case expr::CombinedImageAccess::eTextureOffset1DArrayI:
				case expr::CombinedImageAccess::eTextureOffset2DArrayI:
				case expr::CombinedImageAccess::eTextureOffset1DU:
				case expr::CombinedImageAccess::eTextureOffset2DU:
				case expr::CombinedImageAccess::eTextureOffset3DU:
				case expr::CombinedImageAccess::eTextureOffset1DArrayU:
				case expr::CombinedImageAccess::eTextureOffset2DArrayU:
				case expr::CombinedImageAccess::eTextureOffset1DFBias:
				case expr::CombinedImageAccess::eTextureOffset2DFBias:
				case expr::CombinedImageAccess::eTextureOffset3DFBias:
				case expr::CombinedImageAccess::eTextureOffset1DArrayFBias:
				case expr::CombinedImageAccess::eTextureOffset2DArrayFBias:
				case expr::CombinedImageAccess::eTextureOffset1DIBias:
				case expr::CombinedImageAccess::eTextureOffset2DIBias:
				case expr::CombinedImageAccess::eTextureOffset3DIBias:
				case expr::CombinedImageAccess::eTextureOffset1DArrayIBias:
				case expr::CombinedImageAccess::eTextureOffset2DArrayIBias:
				case expr::CombinedImageAccess::eTextureOffset1DUBias:
				case expr::CombinedImageAccess::eTextureOffset2DUBias:
				case expr::CombinedImageAccess::eTextureOffset3DUBias:
				case expr::CombinedImageAccess::eTextureOffset1DArrayUBias:
				case expr::CombinedImageAccess::eTextureOffset2DArrayUBias:
				case expr::CombinedImageAccess::eTextureGrad1DF:
				case expr::CombinedImageAccess::eTextureGrad2DF:
				case expr::CombinedImageAccess::eTextureGrad3DF:
				case expr::CombinedImageAccess::eTextureGradCubeF:
				case expr::CombinedImageAccess::eTextureGrad1DArrayF:
				case expr::CombinedImageAccess::eTextureGrad2DArrayF:
				case expr::CombinedImageAccess::eTextureGradCubeArrayF:
				case expr::CombinedImageAccess::eTextureGrad1DI:
				case expr::CombinedImageAccess::eTextureGrad2DI:
				case expr::CombinedImageAccess::eTextureGrad3DI:
				case expr::CombinedImageAccess::eTextureGradCubeI:
				case expr::CombinedImageAccess::eTextureGrad1DArrayI:
				case expr::CombinedImageAccess::eTextureGrad2DArrayI:
				case expr::CombinedImageAccess::eTextureGradCubeArrayI:
				case expr::CombinedImageAccess::eTextureGrad1DU:
				case expr::CombinedImageAccess::eTextureGrad2DU:
				case expr::CombinedImageAccess::eTextureGrad3DU:
				case expr::CombinedImageAccess::eTextureGradCubeU:
				case expr::CombinedImageAccess::eTextureGrad1DArrayU:
				case expr::CombinedImageAccess::eTextureGrad2DArrayU:
				case expr::CombinedImageAccess::eTextureGradCubeArrayU:
				case expr::CombinedImageAccess::eTextureGradOffset1DF:
				case expr::CombinedImageAccess::eTextureGradOffset2DF:
				case expr::CombinedImageAccess::eTextureGradOffset3DF:
				case expr::CombinedImageAccess::eTextureGradOffset1DArrayF:
				case expr::CombinedImageAccess::eTextureGradOffset2DArrayF:
				case expr::CombinedImageAccess::eTextureGradOffset1DI:
				case expr::CombinedImageAccess::eTextureGradOffset2DI:
				case expr::CombinedImageAccess::eTextureGradOffset3DI:
				case expr::CombinedImageAccess::eTextureGradOffset1DArrayI:
				case expr::CombinedImageAccess::eTextureGradOffset2DArrayI:
				case expr::CombinedImageAccess::eTextureGradOffset1DU:
				case expr::CombinedImageAccess::eTextureGradOffset2DU:
				case expr::CombinedImageAccess::eTextureGradOffset3DU:
				case expr::CombinedImageAccess::eTextureGradOffset1DArrayU:
				case expr::CombinedImageAccess::eTextureGradOffset2DArrayU:
				case expr::CombinedImageAccess::eTextureProj1DF2:
				case expr::CombinedImageAccess::eTextureProj1DF2Bias:
				case expr::CombinedImageAccess::eTextureProj1DF4:
				case expr::CombinedImageAccess::eTextureProj1DF4Bias:
				case expr::CombinedImageAccess::eTextureProj2DF3:
				case expr::CombinedImageAccess::eTextureProj2DF3Bias:
				case expr::CombinedImageAccess::eTextureProj2DF4:
				case expr::CombinedImageAccess::eTextureProj2DF4Bias:
				case expr::CombinedImageAccess::eTextureProj3DF:
				case expr::CombinedImageAccess::eTextureProj3DFBias:
				case expr::CombinedImageAccess::eTextureProj1DI2:
				case expr::CombinedImageAccess::eTextureProj1DI2Bias:
				case expr::CombinedImageAccess::eTextureProj1DI4:
				case expr::CombinedImageAccess::eTextureProj1DI4Bias:
				case expr::CombinedImageAccess::eTextureProj2DI3:
				case expr::CombinedImageAccess::eTextureProj2DI3Bias:
				case expr::CombinedImageAccess::eTextureProj2DI4:
				case expr::CombinedImageAccess::eTextureProj2DI4Bias:
				case expr::CombinedImageAccess::eTextureProj3DI:
				case expr::CombinedImageAccess::eTextureProj3DIBias:
				case expr::CombinedImageAccess::eTextureProj1DU2:
				case expr::CombinedImageAccess::eTextureProj1DU2Bias:
				case expr::CombinedImageAccess::eTextureProj1DU4:
				case expr::CombinedImageAccess::eTextureProj1DU4Bias:
				case expr::CombinedImageAccess::eTextureProj2DU3:
				case expr::CombinedImageAccess::eTextureProj2DU3Bias:
				case expr::CombinedImageAccess::eTextureProj2DU4:
				case expr::CombinedImageAccess::eTextureProj2DU4Bias:
				case expr::CombinedImageAccess::eTextureProj3DU:
				case expr::CombinedImageAccess::eTextureProj3DUBias:
				case expr::CombinedImageAccess::eTextureProjOffset1DF2:
				case expr::CombinedImageAccess::eTextureProjOffset1DF4:
				case expr::CombinedImageAccess::eTextureProjOffset2DF3:
				case expr::CombinedImageAccess::eTextureProjOffset2DF4:
				case expr::CombinedImageAccess::eTextureProjOffset3DF:
				case expr::CombinedImageAccess::eTextureProjOffset1DI2:
				case expr::CombinedImageAccess::eTextureProjOffset1DI4:
				case expr::CombinedImageAccess::eTextureProjOffset2DI3:
				case expr::CombinedImageAccess::eTextureProjOffset2DI4:
				case expr::CombinedImageAccess::eTextureProjOffset3DI:
				case expr::CombinedImageAccess::eTextureProjOffset1DU2:
				case expr::CombinedImageAccess::eTextureProjOffset1DU4:
				case expr::CombinedImageAccess::eTextureProjOffset2DU3:
				case expr::CombinedImageAccess::eTextureProjOffset2DU4:
				case expr::CombinedImageAccess::eTextureProjOffset3DU:
				case expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
				case expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
				case expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
				case expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
				case expr::CombinedImageAccess::eTextureProjOffset3DFBias:
				case expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
				case expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
				case expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
				case expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
				case expr::CombinedImageAccess::eTextureProjOffset3DIBias:
				case expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
				case expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
				case expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
				case expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
				case expr::CombinedImageAccess::eTextureProjOffset3DUBias:
				case expr::CombinedImageAccess::eTextureProjGrad1DF2:
				case expr::CombinedImageAccess::eTextureProjGrad1DF4:
				case expr::CombinedImageAccess::eTextureProjGrad2DF3:
				case expr::CombinedImageAccess::eTextureProjGrad2DF4:
				case expr::CombinedImageAccess::eTextureProjGrad3DF:
				case expr::CombinedImageAccess::eTextureProjGrad1DI2:
				case expr::CombinedImageAccess::eTextureProjGrad1DI4:
				case expr::CombinedImageAccess::eTextureProjGrad2DI3:
				case expr::CombinedImageAccess::eTextureProjGrad2DI4:
				case expr::CombinedImageAccess::eTextureProjGrad3DI:
				case expr::CombinedImageAccess::eTextureProjGrad1DU2:
				case expr::CombinedImageAccess::eTextureProjGrad1DU4:
				case expr::CombinedImageAccess::eTextureProjGrad2DU3:
				case expr::CombinedImageAccess::eTextureProjGrad2DU4:
				case expr::CombinedImageAccess::eTextureProjGrad3DU:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
				case expr::CombinedImageAccess::eTextureProjGradOffset3DF:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
				case expr::CombinedImageAccess::eTextureProjGradOffset3DI:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
				case expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
				case expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
				case expr::CombinedImageAccess::eTextureProjGradOffset3DU:
				case expr::CombinedImageAccess::eTextureLod1DF:
				case expr::CombinedImageAccess::eTextureLod2DF:
				case expr::CombinedImageAccess::eTextureLod3DF:
				case expr::CombinedImageAccess::eTextureLodCubeF:
				case expr::CombinedImageAccess::eTextureLod1DArrayF:
				case expr::CombinedImageAccess::eTextureLod2DArrayF:
				case expr::CombinedImageAccess::eTextureLodCubeArrayF:
				case expr::CombinedImageAccess::eTextureLod1DI:
				case expr::CombinedImageAccess::eTextureLod2DI:
				case expr::CombinedImageAccess::eTextureLod3DI:
				case expr::CombinedImageAccess::eTextureLodCubeI:
				case expr::CombinedImageAccess::eTextureLod1DArrayI:
				case expr::CombinedImageAccess::eTextureLod2DArrayI:
				case expr::CombinedImageAccess::eTextureLodCubeArrayI:
				case expr::CombinedImageAccess::eTextureLod1DU:
				case expr::CombinedImageAccess::eTextureLod2DU:
				case expr::CombinedImageAccess::eTextureLod3DU:
				case expr::CombinedImageAccess::eTextureLodCubeU:
				case expr::CombinedImageAccess::eTextureLod1DArrayU:
				case expr::CombinedImageAccess::eTextureLod2DArrayU:
				case expr::CombinedImageAccess::eTextureLodCubeArrayU:
				case expr::CombinedImageAccess::eTextureLodOffset1DF:
				case expr::CombinedImageAccess::eTextureLodOffset2DF:
				case expr::CombinedImageAccess::eTextureLodOffset3DF:
				case expr::CombinedImageAccess::eTextureLodOffset1DArrayF:
				case expr::CombinedImageAccess::eTextureLodOffset2DArrayF:
				case expr::CombinedImageAccess::eTextureLodOffset1DI:
				case expr::CombinedImageAccess::eTextureLodOffset2DI:
				case expr::CombinedImageAccess::eTextureLodOffset3DI:
				case expr::CombinedImageAccess::eTextureLodOffset1DArrayI:
				case expr::CombinedImageAccess::eTextureLodOffset2DArrayI:
				case expr::CombinedImageAccess::eTextureLodOffset1DU:
				case expr::CombinedImageAccess::eTextureLodOffset2DU:
				case expr::CombinedImageAccess::eTextureLodOffset3DU:
				case expr::CombinedImageAccess::eTextureLodOffset1DArrayU:
				case expr::CombinedImageAccess::eTextureLodOffset2DArrayU:
				case expr::CombinedImageAccess::eTextureProjLod1DF2:
				case expr::CombinedImageAccess::eTextureProjLod1DF4:
				case expr::CombinedImageAccess::eTextureProjLod2DF3:
				case expr::CombinedImageAccess::eTextureProjLod2DF4:
				case expr::CombinedImageAccess::eTextureProjLod3DF:
				case expr::CombinedImageAccess::eTextureProjLod1DI2:
				case expr::CombinedImageAccess::eTextureProjLod1DI4:
				case expr::CombinedImageAccess::eTextureProjLod2DI3:
				case expr::CombinedImageAccess::eTextureProjLod2DI4:
				case expr::CombinedImageAccess::eTextureProjLod3DI:
				case expr::CombinedImageAccess::eTextureProjLod1DU2:
				case expr::CombinedImageAccess::eTextureProjLod1DU4:
				case expr::CombinedImageAccess::eTextureProjLod2DU3:
				case expr::CombinedImageAccess::eTextureProjLod2DU4:
				case expr::CombinedImageAccess::eTextureProjLod3DU:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DF4:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DF4:
				case expr::CombinedImageAccess::eTextureProjLodOffset3DF:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
				case expr::CombinedImageAccess::eTextureProjLodOffset3DI:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
				case expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
				case expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
				case expr::CombinedImageAccess::eTextureProjLodOffset3DU:
				case expr::CombinedImageAccess::eTexelFetch1DF:
				case expr::CombinedImageAccess::eTexelFetch2DF:
				case expr::CombinedImageAccess::eTexelFetch3DF:
				case expr::CombinedImageAccess::eTexelFetch1DArrayF:
				case expr::CombinedImageAccess::eTexelFetch2DArrayF:
				case expr::CombinedImageAccess::eTexelFetchBufferF:
				case expr::CombinedImageAccess::eTexelFetch1DI:
				case expr::CombinedImageAccess::eTexelFetch2DI:
				case expr::CombinedImageAccess::eTexelFetch3DI:
				case expr::CombinedImageAccess::eTexelFetch1DArrayI:
				case expr::CombinedImageAccess::eTexelFetch2DArrayI:
				case expr::CombinedImageAccess::eTexelFetchBufferI:
				case expr::CombinedImageAccess::eTexelFetch1DU:
				case expr::CombinedImageAccess::eTexelFetch2DU:
				case expr::CombinedImageAccess::eTexelFetch3DU:
				case expr::CombinedImageAccess::eTexelFetch1DArrayU:
				case expr::CombinedImageAccess::eTexelFetch2DArrayU:
				case expr::CombinedImageAccess::eTexelFetchBufferU:
				case expr::CombinedImageAccess::eTexelFetchOffset1DF:
				case expr::CombinedImageAccess::eTexelFetchOffset2DF:
				case expr::CombinedImageAccess::eTexelFetchOffset3DF:
				case expr::CombinedImageAccess::eTexelFetchOffset1DArrayF:
				case expr::CombinedImageAccess::eTexelFetchOffset2DArrayF:
				case expr::CombinedImageAccess::eTexelFetchOffset1DI:
				case expr::CombinedImageAccess::eTexelFetchOffset2DI:
				case expr::CombinedImageAccess::eTexelFetchOffset3DI:
				case expr::CombinedImageAccess::eTexelFetchOffset1DArrayI:
				case expr::CombinedImageAccess::eTexelFetchOffset2DArrayI:
				case expr::CombinedImageAccess::eTexelFetchOffset1DU:
				case expr::CombinedImageAccess::eTexelFetchOffset2DU:
				case expr::CombinedImageAccess::eTexelFetchOffset3DU:
				case expr::CombinedImageAccess::eTexelFetchOffset1DArrayU:
				case expr::CombinedImageAccess::eTexelFetchOffset2DArrayU:
				case expr::CombinedImageAccess::eTextureGather2DF:
				case expr::CombinedImageAccess::eTextureGather2DArrayF:
				case expr::CombinedImageAccess::eTextureGatherCubeF:
				case expr::CombinedImageAccess::eTextureGatherCubeArrayF:
				case expr::CombinedImageAccess::eTextureGather2DI:
				case expr::CombinedImageAccess::eTextureGather2DArrayI:
				case expr::CombinedImageAccess::eTextureGatherCubeI:
				case expr::CombinedImageAccess::eTextureGatherCubeArrayI:
				case expr::CombinedImageAccess::eTextureGather2DU:
				case expr::CombinedImageAccess::eTextureGather2DArrayU:
				case expr::CombinedImageAccess::eTextureGatherCubeU:
				case expr::CombinedImageAccess::eTextureGatherCubeArrayU:
				case expr::CombinedImageAccess::eTextureGatherOffset2DF:
				case expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
				case expr::CombinedImageAccess::eTextureGatherOffset2DI:
				case expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
				case expr::CombinedImageAccess::eTextureGatherOffset2DU:
				case expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DF:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DI:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DU:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
				case expr::CombinedImageAccess::eTextureGather2DShadowF:
				case expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
				case expr::CombinedImageAccess::eTextureGatherCubeShadowF:
				case expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
				case expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
				case expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
				case expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
					return 4u;

				default:
					return InvalidComponentCount;
				}
			}

			static expr::ExprPtr negateExpr( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::ExprPtr expr )
			{
				if ( expr->getKind() == expr::Kind::eLogNot )
				{
					return static_cast< expr::LogNot const & >( *expr ).getOperand()->clone();
				}

				return exprCache.makeLogNot( typesCache, std::move( expr ) );
			}

			static expr::ExprPtr extractIndex( expr::Expr const & expr, uint32_t index )
			{
				class ExprVisitor
					: public expr::Visitor
				{
				public:
					static expr::ExprPtr submit( expr::Expr const & expr
						, uint32_t index )
					{
						expr::ExprPtr result;
						ExprVisitor vis{ expr.getExprCache(), index, result };
						expr.accept( &vis );
						return result;
					}

				private:
					explicit ExprVisitor( expr::ExprCache & exprCache
						, uint32_t index
						, expr::ExprPtr & result )
						: m_exprCache{ exprCache }
						, m_result{ result }
						, m_index{ index }
					{
					}

				private:
					expr::ExprPtr doSubmit( expr::Expr const & expr )const
					{
						return submit( expr, m_index );
					}

					type::TypePtr doGetSwizzledType( type::TypePtr type )const
					{
						return type->getTypesCache().getBasicType( getScalarType( type->getKind() ) );
					}

					void doSwizzle( expr::ExprPtr expr )
					{
						auto componentCount = getComponentCount( expr->getType() );

						if ( componentCount == 1u )
						{
							m_result = std::move( expr );
						}
						else if ( componentCount > m_index )
						{
							m_result = m_exprCache.makeSwizzle( std::move( expr )
								, expr::SwizzleKind::fromOffset( m_index ) );
						}
						else
						{
							AST_Failure( "Unexpected component count lower than swizzle index" );
						}
					}

					void visitAddExpr( expr::Add const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeAdd( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitAggrInitExpr( expr::AggrInit const * expr )override
					{
						TraceFunc;
						if ( !expr->hasIdentifier()
							&& expr->getInitialisers().size() > m_index )
						{
							m_result = doSubmit( *expr->getInitialisers()[m_index] );
						}
						else
						{
							doSwizzle( expr->clone() );
						}
					}

					void visitAliasExpr( expr::Alias const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitArrayAccessExpr( expr::ArrayAccess const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitBitAndExpr( expr::BitAnd const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeBitAnd( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitBitNotExpr( expr::BitNot const * expr )override
					{
						TraceFunc;
						auto op = doSubmit( *expr->getOperand() );
						m_result = m_exprCache.makeBitNot( std::move( op ) );
					}

					void visitBitOrExpr( expr::BitOr const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeBitOr( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitBitXorExpr( expr::BitXor const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeBitXor( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitCastExpr( expr::Cast const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitCommaExpr( expr::Comma const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeComma( std::move( lhs )
							, std::move( rhs ) );
					}

					void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
					{
						TraceFunc;
						AST_Assert( m_index < expr->getArgList().size() );
						m_result = doSubmit( *expr->getArgList()[m_index] );
					}

					void visitCopyExpr( expr::Copy const * expr )override
					{
						TraceFunc;
						auto op = doSubmit( *expr->getOperand() );

						if ( op )
						{
							m_result = m_exprCache.makeCopy( std::move( op ) );
						}
					}

					void visitDivideExpr( expr::Divide const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeDivide( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitEqualExpr( expr::Equal const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeEqual( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitFnCallExpr( expr::FnCall const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitGreaterExpr( expr::Greater const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeGreater( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitGreaterEqualExpr( expr::GreaterEqual const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeGreaterEqual( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitIdentifierExpr( expr::Identifier const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitInitExpr( expr::Init const * expr )override
					{
						TraceFunc;
						AST_Assert( expr->hasIdentifier() );
						doSubmit( expr->getIdentifier() );
					}

					void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitLessExpr( expr::Less const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeLess( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitLessEqualExpr( expr::LessEqual const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeLessEqual( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitLiteralExpr( expr::Literal const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitLogAndExpr( expr::LogAnd const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeLogAnd( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitLogNotExpr( expr::LogNot const * expr )override
					{
						TraceFunc;
						auto op = doSubmit( *expr->getOperand() );
						m_result = m_exprCache.makeLogNot( doGetSwizzledType( expr->getType() )
							, std::move( op ) );
					}

					void visitLogOrExpr( expr::LogOr const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeLogOr( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitLShiftExpr( expr::LShift const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeLShift( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitMbrSelectExpr( expr::MbrSelect const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitMinusExpr( expr::Minus const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeMinus( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitModuloExpr( expr::Modulo const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeModulo( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitNotEqualExpr( expr::NotEqual const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeNotEqual( expr->getType()->getTypesCache()
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitQuestionExpr( expr::Question const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitRShiftExpr( expr::RShift const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeRShift( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitSwizzleExpr( expr::Swizzle const * expr )override
					{
						TraceFunc;
						auto componentCount = getComponentCount( expr->getType() );

						if ( componentCount == 1u )
						{
							m_result = expr->clone();
						}
						else if ( componentCount > m_index )
						{
							auto values = getSwizzleValues( expr->getSwizzle() );
							m_result = m_exprCache.makeSwizzle( expr->getOuterExpr()->clone()
								, helpers::getFinalSwizzle( values, { m_index } ) );
						}
						else
						{
							AST_Failure( "Unexpected component count lower than swizzle index" );
						}
					}

					void visitTimesExpr( expr::Times const * expr )override
					{
						TraceFunc;
						auto lhs = doSubmit( *expr->getLHS() );
						auto rhs = doSubmit( *expr->getRHS() );
						m_result = m_exprCache.makeTimes( doGetSwizzledType( expr->getType() )
							, std::move( lhs )
							, std::move( rhs ) );
					}

					void visitUnaryMinusExpr( expr::UnaryMinus const * expr )override
					{
						TraceFunc;
						auto op = doSubmit( *expr->getOperand() );
						m_result = m_exprCache.makeUnaryMinus( std::move( op ) );
					}

					void visitUnaryPlusExpr( expr::UnaryPlus const * expr )override
					{
						TraceFunc;
						auto op = doSubmit( *expr->getOperand() );
						m_result = m_exprCache.makeUnaryPlus( std::move( op ) );
					}

					void visitAddAssignExpr( expr::AddAssign const * expr )override
					{
					}

					void visitAndAssignExpr( expr::AndAssign const * expr )override
					{
					}

					void visitDivideAssignExpr( expr::DivideAssign const * expr )override
					{
					}

					void visitLShiftAssignExpr( expr::LShiftAssign const * expr )override
					{
					}

					void visitMinusAssignExpr( expr::MinusAssign const * expr )override
					{
					}

					void visitModuloAssignExpr( expr::ModuloAssign const * expr )override
					{
					}

					void visitOrAssignExpr( expr::OrAssign const * expr )override
					{
					}

					void visitRShiftAssignExpr( expr::RShiftAssign const * expr )override
					{
					}

					void visitTimesAssignExpr( expr::TimesAssign const * expr )override
					{
					}

					void visitXorAssignExpr( expr::XorAssign const * expr )override
					{
					}

					void visitAssignExpr( expr::Assign const * expr )override
					{
						Logger::logError( "Unexpected Assign expression" );
					}

					void visitPostDecrementExpr( expr::PostDecrement const * expr )override
					{
						Logger::logError( "Unexpected PostDecrement expression" );
					}

					void visitPostIncrementExpr( expr::PostIncrement const * expr )override
					{
						Logger::logError( "Unexpected PostIncrement expression" );
					}

					void visitPreDecrementExpr( expr::PreDecrement const * expr )override
					{
						Logger::logError( "Unexpected PreDecrement expression" );
					}

					void visitPreIncrementExpr( expr::PreIncrement const * expr )override
					{
						Logger::logError( "Unexpected PreIncrement expression" );
					}

					void visitStreamAppendExpr( expr::StreamAppend const * expr )override
					{
						Logger::logError( "Unexpected StreamAppend expression" );
					}

					void visitSwitchCaseExpr( expr::SwitchCase const * expr )override
					{
						Logger::logError( "Unexpected SwitchCase expression" );
					}

					void visitSwitchTestExpr( expr::SwitchTest const * expr )override
					{
						Logger::logError( "Unexpected SwitchTest expression" );
					}

				private:
					expr::ExprCache & m_exprCache;
					expr::ExprPtr & m_result;
					uint32_t m_index;
				};

				return ExprVisitor::submit( expr, index );
			}
		}

		class ExprSimplifier
			: public ExprCloner
		{
		public:
			static expr::ExprPtr submit( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::Expr const & expr )
			{
				expr::ExprPtr result{};
				ExprSimplifier vis{ exprCache, typesCache, result };
				expr.accept( &vis );

				if ( expr.isNonUniform() )
				{
					result->updateFlag( expr::Flag::eNonUniform );
				}

				return result;
			}

		private:
			ExprSimplifier( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, expr::ExprPtr & result )
				: ExprCloner{ exprCache, result }
				, m_typesCache{ typesCache }
			{
			}

		private:
			using ExprCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				return submit( m_exprCache, m_typesCache, expr );
			}

			void visitAddAssignExpr( expr::AddAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eAdd
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitAddExpr( expr::Add const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eAdd
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitCastExpr( expr::Cast const * expr )override
			{
				TraceFunc;
				auto dstScalarType = getScalarType( expr->getType()->getKind() );
				auto srcScalarType = getScalarType( expr->getOperand()->getType()->getKind() );
#if SDAST_ExceptAssert || !defined( NDEBUG )
				auto dstComponents = getComponentCount( expr->getType()->getKind() );
				auto srcComponents = getComponentCount( expr->getOperand()->getType()->getKind() );
#endif

				if ( dstScalarType == type::Kind::eBoolean
					&& srcScalarType != type::Kind::eBoolean )
				{
					// Conversion to bool scalar or vector type.
					AST_Assert( dstComponents == srcComponents );
					m_result = helpers::makeToBoolCast( m_exprCache, m_typesCache
						, doSubmit( *expr->getOperand() ) );
				}
				else if ( srcScalarType == type::Kind::eBoolean
					&& dstScalarType != type::Kind::eBoolean )
				{
					// Conversion from bool scalar or vector type.
					AST_Assert( dstComponents == srcComponents );
					m_result = helpers::makeFromBoolCast( m_exprCache, m_typesCache
						, doSubmit( *expr->getOperand() )
						, dstScalarType );
				}
				else
				{
					m_result = m_exprCache.makeCast( expr->getType()
						, doSubmit( *expr->getOperand() ) );
				}
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
			{
				TraceFunc;
				auto kind = expr->getCombinedImageAccess();
				auto returnComponentsCount = helpers::getReturnComponentCount( kind );
				auto returnType = expr->getType();
				auto count = getComponentCount( returnType->getKind() );

				if ( returnComponentsCount != helpers::InvalidComponentCount && returnComponentsCount != count )
				{
					AST_Assert( returnComponentsCount > count );
					returnType = m_typesCache.getVector( getScalarType( returnType->getKind() ), returnComponentsCount );
				}

				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				m_result = m_exprCache.makeCombinedImageAccessCall( returnType
					, kind
					, std::move( args ) );

				if ( returnComponentsCount != helpers::InvalidComponentCount && returnComponentsCount != count )
				{
					expr::SwizzleKind swizzleKind;

					if ( count == 1u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, expr::SwizzleKind{ expr::SwizzleKind::e0 } );
					}
					else if ( count == 2u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, expr::SwizzleKind{ expr::SwizzleKind::e01 } );
					}
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
			{
				TraceFunc;
				if ( expr->getComposite() == expr::CompositeType::eCombine )
				{
					return ExprCloner::visitCompositeConstructExpr( expr );
				}

				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.push_back( doSubmit( *arg ) );
				}

				// Flatten the composite constructs,
				// to have one initialiser per result component.
				expr::ExprList realArgs;
				bool resultIsMatrix = isMatrixType( expr->getType()->getKind() );

				for ( auto & arg : args )
				{
					doProcessCompositeCtorArg( *expr, std::move( arg ), resultIsMatrix, args.size(), realArgs );
				}

				m_result = m_exprCache.makeCompositeConstruct( expr->getComposite()
					, expr->getComponent()
					, std::move( realArgs ) );
			}

			void visitDivideAssignExpr( expr::DivideAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eDivide
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitDivideExpr( expr::Divide const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eDivide
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
			{
				TraceFunc;
				expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				auto dstType = expr->getType();
				auto srcType = helpers::getExpectedReturnType( expr );
				m_result = m_exprCache.makeStorageImageAccessCall( srcType
					, expr->getImageAccess()
					, std::move( args ) );

				if ( srcType != dstType )
				{
					AST_Assert( type::getScalarType( srcType->getKind() ) == type::getScalarType( dstType->getKind() ) );
					auto dstCount = type::getComponentCount( dstType );

					if ( dstCount == 1u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, expr::SwizzleKind{ expr::SwizzleKind::e0 } );
					}
					else if ( dstCount == 2u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, expr::SwizzleKind{ expr::SwizzleKind::e01 } );
					}
				}
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall const * expr )override
			{
				TraceFunc;
				auto intrinsic = expr->getIntrinsic();

				if ( intrinsic >= expr::Intrinsic::eMatrixCompMult2x2F
					&& intrinsic <= expr::Intrinsic::eMatrixCompMult4x4D )
				{
					AST_Assert( expr->getArgList().size() == 2u );
					m_result = doWriteMatrixPerComponentBinaryOperation( expr::Kind::eTimes
						, expr->getType()
						, *expr->getArgList()[0]
						, *expr->getArgList()[1] );
				}
				else
				{
					expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( *arg ) );
					}

					m_result = m_exprCache.makeIntrinsicCall( expr->getType()
						, expr->getIntrinsic()
						, std::move( args ) );
				}
			}

			void visitLogNotExpr( expr::LogNot const * expr )override
			{
				TraceFunc;
				m_result = helpers::negateExpr( m_exprCache
					, m_typesCache
					, doSubmit( *expr->getOperand() ) );
			}

			void visitMinusAssignExpr( expr::MinusAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eMinus
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitMinusExpr( expr::Minus const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eMinus
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void visitQuestionExpr( expr::Question const * expr )override
			{
				TraceFunc;
				auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
				auto opsComponents = getComponentCount( expr->getTrueExpr()->getType()->getKind() );

				if ( condComponents == opsComponents )
				{
					m_result = m_exprCache.makeQuestion( expr->getType()
						, doSubmit( *expr->getCtrlExpr() )
						, doSubmit( *expr->getTrueExpr() )
						, doSubmit( *expr->getFalseExpr() ) );
				}
				else
				{
					AST_Assert( condComponents == 1u );
					expr::ExprList args;
					args.emplace_back( doSubmit( *expr->getCtrlExpr() ) );
					m_result = m_exprCache.makeQuestion( expr->getType()
						, doSubmit( *m_exprCache.makeCompositeConstruct( getCompositeType( opsComponents )
							, expr->getCtrlExpr()->getType()->getKind()
							, std::move( args ) ) )
						, doSubmit( *expr->getTrueExpr() )
						, doSubmit( *expr->getFalseExpr() ) );
				}
			}

			void visitSwizzleExpr( expr::Swizzle const * expr )override
			{
				TraceFunc;
				auto outer = expr->getOuterExpr();

				if ( !m_result
					&& expr->getOuterExpr()->getKind() == expr::Kind::eSwizzle )
				{
					auto & outerSwizzle = static_cast< expr::Swizzle const & >( *outer );

					if ( expr->getSwizzle().getValue() == outerSwizzle.getSwizzle().getValue()
						&& expr->getType() == outerSwizzle.getType() )
					{
						m_result = m_exprCache.makeSwizzle( doSubmit( outerSwizzle.getOuterExpr() )
							, outerSwizzle.getSwizzle() );
					}
					else
					{
						auto values = getSwizzleValues( outerSwizzle.getSwizzle() );
						auto indices = getSwizzleIndices( expr->getSwizzle() );
						m_result = m_exprCache.makeSwizzle( doSubmit( outerSwizzle.getOuterExpr() )
							, helpers::getFinalSwizzle( values, indices ) );
					}
				}

				if ( !m_result )
				{
					if ( expr->getSwizzle() == expr::SwizzleKind::e0
						|| expr->getSwizzle() == expr::SwizzleKind::e1
						|| expr->getSwizzle() == expr::SwizzleKind::e2
						|| expr->getSwizzle() == expr::SwizzleKind::e3 )
					{
						if ( outer->getKind() == expr::Kind::eCompositeConstruct )
						{
							auto & compositeConstruct = static_cast< expr::CompositeConstruct const & >( *outer );

							if ( compositeConstruct.getArgList().size() == 1u
								&& type::isScalarType( compositeConstruct.getArgList().front()->getType() ) )
							{
								m_result = doSubmit( **compositeConstruct.getArgList().begin() );
							}
							else if ( compositeConstruct.getArgList().size() == type::getComponentCount( compositeConstruct.getType() ) )
							{
								if ( auto index = expr->getSwizzle().toIndex();
									index < compositeConstruct.getArgList().size() )
								{
									m_result = doSubmit( **std::next( compositeConstruct.getArgList().begin()
										, ptrdiff_t( index ) ) );
								}
								else
								{
									AST_Exception( "Out of bounds swizzle index" );
								}
							}
						}
						else
						{
							auto index = expr->getSwizzle().toIndex();
							m_result = helpers::extractIndex( *doSubmit( *outer ), index );
						}
					}
				}

				if ( !m_result )
				{
					m_result = m_exprCache.makeSwizzle( doSubmit( *expr->getOuterExpr() )
						, expr->getSwizzle() );
				}
			}

			void visitTimesAssignExpr( expr::TimesAssign const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eTimes
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
				m_result = m_exprCache.makeAssign( expr->getType()
					, doSubmit( *expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitTimesExpr( expr::Times const * expr )override
			{
				TraceFunc;
				m_result = doWriteBinaryOperation( expr::Kind::eTimes
					, expr->getType()
					, *expr->getLHS()
					, *expr->getRHS() );
			}

			void doFlattenCompositeCtorSingleArg( expr::CompositeConstruct const & expr
				, expr::Expr const & arg
				, type::Kind kind
				, expr::ExprList & realArgs )
			{
				for ( auto i = 0u; i < getComponentsCount( expr.getComposite() ); ++i )
				{
					realArgs.emplace_back( doSubmit( arg ) );
				}

				if ( isScalarType( kind )
					&& kind != expr.getComponent() )
				{
					auto dstType = m_typesCache.getBasicType( expr.getComponent() );

					for ( auto & realArg : realArgs )
					{
						realArg = m_exprCache.makeCast( dstType, std::move( realArg ) );
					}
				}
			}

			void doProcessSubCompositeCtor( expr::CompositeConstruct const & expr
				, expr::Expr const & current
				, type::Kind compKind
				, expr::ExprList & realArgs
				, expr::ExprList & work )
			{
				for ( auto & param : static_cast< expr::CompositeConstruct const & >( current ).getArgList() )
				{
					if ( isScalarType( compKind ) == isScalarType( expr.getComponent() )
						&& isVectorType( compKind ) == isVectorType( expr.getComponent() )
						&& isMatrixType( compKind ) == isMatrixType( expr.getComponent() )
						&& getComponentCount( compKind ) == getComponentCount( expr.getComponent() ) )
					{
						realArgs.emplace_back( doSubmit( *param ) );
					}
					else
					{
						work.emplace_back( doSubmit( *param ) );
					}
				}
			}

			void doFlattenCompositeCtorMultipleArgs( expr::CompositeConstruct const & expr
				, expr::ExprPtr arg
				, type::Kind kind
				, expr::ExprList & realArgs )
			{
				expr::ExprList work;
				work.emplace_back( std::move( arg ) );

				while ( !work.empty() )
				{
					expr::ExprPtr current = std::move( work.front() );
					work.erase( work.begin() );

					expr::ExprList curArgs;
					auto compKind = getComponentType( kind );
					kind = compKind;

					if ( current->getKind() == expr::Kind::eCompositeConstruct )
					{
						// `vec4( vec3( 0.0 ), 1.0 )` => `vec4( 0.0, 0.0, 0.0, 1.0 )`
						doProcessSubCompositeCtor( expr, *current, compKind, realArgs, work );
					}
					else
					{
						realArgs.emplace_back( std::move( current ) );
					}
				}
			}

			void doProcessCompositeCtorArg( expr::CompositeConstruct const & expr
				, expr::ExprPtr arg
				, bool resultIsMatrix
				, size_t argsCount
				, expr::ExprList & realArgs )
			{
				auto argType = arg->getType();
				auto kind = argType->getKind();
				bool processed = false;

				if ( isVectorType( kind ) && !resultIsMatrix )
				{
					processed = true;
					doConstructVector( expr
						, *arg
						, expr.getType()->getKind()
						, realArgs );
				}
				else if ( isMatrixType( kind ) )
				{
					processed = true;
					doConstructMatrix( *arg
						, expr.getType()->getKind()
						, realArgs );
				}
				else
				{
					// TODO: Struct or array.
				}

				if ( !processed
					&& isScalarType( kind ) == isScalarType( expr.getComponent() )
					&& isVectorType( kind ) == isVectorType( expr.getComponent() )
					&& isMatrixType( kind ) == isMatrixType( expr.getComponent() ) )
				{
					if ( argsCount == 1u
						&& getComponentsCount( expr.getComposite() ) > 1u )
					{
						processed = true;
						// Flatten constructs in the form `vec3( 0.0 )` => `vec3( 0.0, 0.0, 0.0 )`
						doFlattenCompositeCtorSingleArg( expr, *arg, kind, realArgs );
					}
					else if ( getComponentCount( kind ) == getComponentCount( expr.getComponent() ) )
					{
						processed = true;
						// Same component type as expected by construct
						realArgs.emplace_back( doSubmit( *arg ) );

						if ( isScalarType( kind )
							&& kind != expr.getComponent() )
						{
							auto dstType = m_typesCache.getBasicType( expr.getComponent() );
							realArgs.back() = m_exprCache.makeCast( dstType, std::move( realArgs.back() ) );
						}
					}
				}

				if ( !processed )
				{
					// Constructs like `vec4( vec3( 0.0 ), 1.0 )` => `vec4( 0.0, 0.0, 0.0, 1.0 )`
					doFlattenCompositeCtorMultipleArgs( expr, std::move( arg ), kind, realArgs );
				}
			}

			void doConstructVector( expr::CompositeConstruct const & expr
				, expr::Expr const & newArg
				, type::Kind destKind
				, expr::ExprList & args )
			{
				TraceFunc;
				auto srcCount = getComponentCount( newArg.getType()->getKind() );
				auto dstCount = getComponentCount( destKind );
				auto count = std::min( srcCount, dstCount );

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( *m_exprCache.makeSwizzle( doSubmit( newArg )
						, expr::SwizzleKind::fromOffset( i ) ) ) );
				}

				if ( getScalarType( newArg.getType()->getKind() ) != getScalarType( expr.getType()->getKind() ) )
				{
					auto dstType = m_typesCache.getBasicType( getScalarType( expr.getType()->getKind() ) );

					for ( auto & arg : args )
					{
						arg = doSubmit( *m_exprCache.makeCast( dstType
							, std::move( arg ) ) );
					}
				}
			}

			void doConstructMatrix( expr::Expr const & newArg
				, type::Kind destKind
				, expr::ExprList & args )
			{
				TraceFunc;
				auto scalarType = getScalarType( destKind );
				auto srcColumnCount = getComponentCount( newArg.getType()->getKind() );
				auto srcRowCount = getComponentCount( getComponentType( newArg.getType()->getKind() ) );
				auto dstColumnCount = getComponentCount( destKind );
				auto dstRowCount = getComponentCount( getComponentType( destKind ) );
				auto minColumnCount = std::min( srcColumnCount, dstColumnCount );

				for ( auto col = 0u; col < minColumnCount; ++col )
				{
					auto arrayAccess = doSubmit( *m_exprCache.makeArrayAccess( m_typesCache.getVector( scalarType, srcRowCount )
						, doSubmit( newArg )
						, m_exprCache.makeLiteral( m_typesCache, col ) ) );

					if ( dstRowCount < srcRowCount )
					{
						args.emplace_back( doSubmit( *m_exprCache.makeSwizzle( std::move( arrayAccess )
							, getSwizzleComponents( dstRowCount ) ) ) );
					}
					else if ( dstRowCount == srcRowCount )
					{
						args.emplace_back( std::move( arrayAccess ) );
					}
					else
					{
						expr::ExprList compositeArgs;
						compositeArgs.emplace_back( std::move( arrayAccess ) );

						for ( auto row = srcRowCount; row < dstRowCount; ++row )
						{
							if ( row == col )
							{
								compositeArgs.emplace_back( makeOne( m_exprCache, m_typesCache.getBasicType( scalarType ) ) );
							}
							else
							{
								compositeArgs.emplace_back( makeZero( m_exprCache, m_typesCache.getBasicType( scalarType ) ) );
							}
						}

						args.emplace_back( m_exprCache.makeCompositeConstruct( getCompositeType( dstRowCount )
							, scalarType
							, std::move( compositeArgs ) ) );
					}
				}
			}

			type::TypePtr doPromoteScalar( expr::ExprPtr & lhs
				, expr::ExprPtr & rhs )
			{
				TraceFunc;
				auto lhsScalar = isScalarType( lhs->getType()->getKind() );
				auto rhsScalar = isScalarType( rhs->getType()->getKind() );
				auto result = lhs->getType();

				if ( !lhsScalar || !rhsScalar )
				{
					if ( !lhsScalar && !rhsScalar )
					{
						AST_Assert( lhs->getType()->getKind() == rhs->getType()->getKind()
							&& "TODO" );
					}
					else if ( lhsScalar )
					{
						result = rhs->getType();
						auto count = getComponentCount( result->getKind() );
						expr::ExprList args;

						for ( auto i = 0u; i < count; ++i )
						{
							args.emplace_back( doSubmit( *lhs ) );
						}

						auto kind = args.back()->getType()->getKind();
						lhs = m_exprCache.makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
							, kind
							, std::move( args ) );
					}
					else if ( rhsScalar )
					{
						result = lhs->getType();
						auto count = getComponentCount( result->getKind() );
						expr::ExprList args;

						for ( auto i = 0u; i < count; ++i )
						{
							args.emplace_back( doSubmit( *rhs ) );
						}

						auto kind = args.back()->getType()->getKind();
						rhs = m_exprCache.makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
							, kind
							, std::move( args ) );
					}
				}

				return result;
			}

			expr::ExprPtr doWriteBinaryOperation( expr::Kind operation
				, type::TypePtr resType
				, expr::Expr const & rlhs
				, expr::Expr const & rrhs )
			{
				TraceFunc;
				auto lhs = &rlhs;
				auto rhs = &rrhs;
				bool needMatchingVectors;
				bool switchParams;
				auto forceRhsType = isMatrixTimesVector( operation
					, lhs->getType()->getKind()
					, rhs->getType()->getKind()
					, switchParams
					, needMatchingVectors );

				if ( switchParams )
				{
					std::swap( lhs, rhs );
				}

				auto lhsType = lhs->getType();
				auto rhsType = rhs->getType();
				bool lhsMat = isMatrixType( lhsType->getKind() );
				bool rhsMat = isMatrixType( rhsType->getKind() );
				auto lhsExpr = doSubmit( lhs );
				auto rhsExpr = doSubmit( rhs );
				auto type = lhsExpr->getType();
				expr::ExprPtr result{};

				if ( lhsMat || rhsMat )
				{
					if ( forceRhsType )
					{
						type = resType;
					}

					expr::ExprList args;

					switch ( operation )
					{
					case expr::Kind::eAdd:
					case expr::Kind::eDivide:
					case expr::Kind::eMinus:
						result = doWriteMatrixPerComponentBinaryOperation( operation
							, resType
							, *lhsExpr
							, *rhsExpr );
						break;
					case expr::Kind::eTimes:
						result = m_exprCache.makeTimes( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					default:
						AST_Failure( "Unsupported binary operation" );
						break;
					}
				}
				else
				{
					if ( needMatchingVectors )
					{
						type = doPromoteScalar( lhsExpr, rhsExpr );
					}

					expr::ExprList args;

					switch ( operation )
					{
					case expr::Kind::eAdd:
						result = m_exprCache.makeAdd( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eDivide:
						result = m_exprCache.makeDivide( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eMinus:
						result = m_exprCache.makeMinus( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eTimes:
						result = m_exprCache.makeTimes( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					default:
						AST_Failure( "Unsupported binary operation" );
					}
				}

				return result;
			}

			expr::ExprPtr doWriteMatrixPerComponentBinaryOperation( expr::Kind operation
				, type::TypePtr resType
				, expr::Expr const & lhs
				, expr::Expr const & rhs )
			{
				TraceFunc;
				// one time set up...
				auto lhsType = lhs.getType();
				auto rhsType = rhs.getType();
				bool lhsMat = isMatrixType( lhsType->getKind() );
				bool rhsMat = isMatrixType( rhsType->getKind() );
				auto lhsColumns = getComponentCount( lhsType->getKind() );
				auto rhsColumns = getComponentCount( rhsType->getKind() );
				auto lhsRows = getComponentCount( getComponentType( lhsType->getKind() ) );
				auto rhsRows = getComponentCount( getComponentType( rhsType->getKind() ) );
				auto numCols = lhsMat ? lhsColumns : rhsColumns;
				auto numRows = lhsMat ? lhsRows : rhsRows;
				auto scalarType = getScalarType( resType->getKind() );
				auto vecType = m_typesCache.getVector( scalarType, numRows );
				expr::CompositeType composite;

				switch ( numRows )
				{
				case 1:
					composite = expr::CompositeType::eScalar;
					break;
				case 2:
					composite = expr::CompositeType::eVec2;
					break;
				case 3:
					composite = expr::CompositeType::eVec3;
					break;
				default:
					composite = expr::CompositeType::eVec4;
					break;
				}

				expr::ExprPtr smearVec{};

				if ( isScalarType( lhsType->getKind() ) )
				{
					if ( composite == expr::CompositeType::eScalar )
					{
						smearVec = doSubmit( lhs );
					}
					else
					{
						expr::ExprList params;
						params.emplace_back( doSubmit( lhs ) );
						smearVec = doSubmit( *m_exprCache.makeCompositeConstruct( composite
							, lhsType->getKind()
							, std::move( params ) ) );
					}
				}
				else if ( isScalarType( rhsType->getKind() ) )
				{
					if ( composite == expr::CompositeType::eScalar )
					{
						smearVec = doSubmit( rhs );
					}
					else
					{
						expr::ExprList params;
						params.emplace_back( doSubmit( rhs ) );
						smearVec = doSubmit( *m_exprCache.makeCompositeConstruct( composite
							, rhsType->getKind()
							, std::move( params ) ) );
					}
				}

				expr::ExprList args;

				// do each vector op
				for ( unsigned int c = 0; c < numCols; ++c )
				{
					std::vector<unsigned int> indexes;
					indexes.push_back( c );
					auto lhsVec = lhsMat
						? m_exprCache.makeArrayAccess( vecType, doSubmit( lhs ), m_exprCache.makeLiteral( m_typesCache, c ) )
						: ExprCloner::submit( m_exprCache, *smearVec );
					auto rhsVec = rhsMat
						? m_exprCache.makeArrayAccess( vecType, doSubmit( rhs ), m_exprCache.makeLiteral( m_typesCache, c ) )
						: ExprCloner::submit( m_exprCache, *smearVec );

					switch ( operation )
					{
					case expr::Kind::eAdd:
						args.emplace_back( m_exprCache.makeAdd( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					case expr::Kind::eDivide:
						args.emplace_back( m_exprCache.makeDivide( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					case expr::Kind::eMinus:
						args.emplace_back( m_exprCache.makeMinus( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					case expr::Kind::eTimes:
						args.emplace_back( m_exprCache.makeTimes( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					default:
						AST_Failure( "Unsupported binary operation" );
					}
				}

				switch ( composite )
				{
				case expr::CompositeType::eScalar:
					switch ( numCols )
					{
					case 1:
						composite = expr::CompositeType::eScalar;
						break;
					case 2:
						composite = expr::CompositeType::eVec2;
						break;
					case 3:
						composite = expr::CompositeType::eVec3;
						break;
					default:
						composite = expr::CompositeType::eVec4;
						break;
					}
					break;
				case expr::CompositeType::eVec2:
					switch ( numCols )
					{
					case 1:
						composite = expr::CompositeType::eVec2;
						break;
					case 2:
						composite = expr::CompositeType::eMat2x2;
						break;
					case 3:
						composite = expr::CompositeType::eMat3x2;
						break;
					default:
						composite = expr::CompositeType::eMat4x2;
						break;
					}
					break;
				case expr::CompositeType::eVec3:
					switch ( numCols )
					{
					case 1:
						composite = expr::CompositeType::eVec3;
						break;
					case 2:
						composite = expr::CompositeType::eMat2x3;
						break;
					case 3:
						composite = expr::CompositeType::eMat3x3;
						break;
					default:
						composite = expr::CompositeType::eMat4x3;
						break;
					}
					break;
				case expr::CompositeType::eVec4:
					switch ( numCols )
					{
					case 1:
						composite = expr::CompositeType::eVec4;
						break;
					case 2:
						composite = expr::CompositeType::eMat2x4;
						break;
					case 3:
						composite = expr::CompositeType::eMat3x4;
						break;
					default:
						composite = expr::CompositeType::eMat4x4;
						break;
					}
					break;
				default:
					break;
				}

				// put the pieces together
				if ( composite != expr::CompositeType::eScalar )
				{
					return m_exprCache.makeCompositeConstruct( composite
						, scalarType
						, std::move( args ) );
				}

				AST_Assert( args.size() == 1u );
				return std::move( args[0] );
			}

		private:
			type::TypesCache & m_typesCache;
		};

		class StmtSimplifier
			: public StmtCloner
		{
		public:
			static stmt::ContainerPtr submit( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::Container const & stmt )
			{
				auto result = stmtCache.makeContainer();
				StmtSimplifier vis{ stmtCache, exprCache, typesCache, result };
				stmt.accept( &vis );
				return result;
			}

		private:
			StmtSimplifier( stmt::StmtCache & stmtCache
				, expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, stmt::ContainerPtr & result )
				: StmtCloner{ stmtCache, exprCache, result }
				, m_typesCache{ typesCache }
			{
			}

			using StmtCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				return ExprSimplifier::submit( m_exprCache, m_typesCache, expr );
			}

			void visitDoWhileStmt( stmt::DoWhile const * stmt )override
			{
				TraceFunc;
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				auto scalarType = getScalarType( ctrlExpr->getType()->getKind() );
				auto doWhileContent = m_stmtCache.makeDoWhile( ( scalarType != type::Kind::eBoolean )
					? helpers::makeToBoolCast( m_exprCache, m_typesCache, std::move( ctrlExpr ) )
					: std::move( ctrlExpr ) );
				auto save = m_current;
				m_current = doWhileContent.get();
				visitContainerStmt( stmt );
				m_current = save;
				m_current->addStmt( std::move( doWhileContent ) );
			}

			void visitIfStmt( stmt::If const * stmt )override
			{
				TraceFunc;
				auto save = m_current;
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				auto scalarType = getScalarType( ctrlExpr->getType()->getKind() );
				auto ifCont = m_stmtCache.makeIf( ( scalarType != type::Kind::eBoolean )
					? helpers::makeToBoolCast( m_exprCache, m_typesCache, std::move( ctrlExpr ) )
					: std::move( ctrlExpr ) );
				m_current = ifCont.get();
				visitContainerStmt( stmt );
				m_current = save;

				if ( auto elseStmt = stmt->getElse() )
				{
					auto elseCont = ifCont->createElse();
					m_current = elseCont;
					visitContainerStmt( elseStmt );
					m_current = save;
				}

				m_current->addStmt( std::move( ifCont ) );
			}

		private:
			type::TypesCache & m_typesCache;
		};
	}

	bool isMatrixTimesVector( expr::Kind exprKind
		, type::Kind lhsTypeKind
		, type::Kind rhsTypeKind
		, bool & switchParams
		, bool & needMatchingVectors )
	{
		needMatchingVectors = true;
		AST_Assert( exprKind != expr::Kind::eImageAccessCall
			&& exprKind != expr::Kind::eIntrinsicCall
			&& exprKind != expr::Kind::eCombinedImageAccessCall
			&& "Unsupported expr::Kind" );
		switchParams = ( exprKind == expr::Kind::eTimes || exprKind == expr::Kind::eTimesAssign )
			&& ( isScalarType( lhsTypeKind ) && ( isVectorType( rhsTypeKind ) || isMatrixType( rhsTypeKind ) ) );

		switch ( exprKind )
		{
		case expr::Kind::eTimes:
		case expr::Kind::eTimesAssign:
			needMatchingVectors = !( ( isFloatType( getScalarType( lhsTypeKind ) ) || isFloatType( getScalarType( rhsTypeKind ) ) )
				&& ( isVectorType( lhsTypeKind ) || isVectorType( rhsTypeKind ) ) );
			return ( isMatrixType( lhsTypeKind ) && isVectorType( rhsTypeKind ) )
				|| ( isVectorType( lhsTypeKind ) && isMatrixType( rhsTypeKind ) );
		default:
			return false;
		}
	}

	std::vector< expr::SwizzleKind > getSwizzleValues( expr::SwizzleKind swizzle )
	{
		auto count = swizzle.getComponentsCount();
		std::vector< expr::SwizzleKind > result;
		result.emplace_back( swizzle.getFirstValue() );

		if ( count >= 2u )
		{
			result.emplace_back( swizzle.getSecondValue() );
		}

		if ( count >= 3u )
		{
			result.emplace_back( swizzle.getThirdValue() );
		}

		if ( count >= 4u )
		{
			result.emplace_back( swizzle.getFourthValue() );
		}

		return result;
	}

	std::vector< uint32_t > getSwizzleIndices( expr::SwizzleKind swizzle )
	{
		std::vector< uint32_t > result;
		result.push_back( simpl::helpers::getSwizzleIndex( swizzle.getFirstValue() ) );
		auto count = swizzle.getComponentsCount();

		if ( count >= 2u )
		{
			result.push_back( simpl::helpers::getSwizzleIndex( swizzle.getSecondValue() ) );
		}

		if ( count >= 3u )
		{
			result.push_back( simpl::helpers::getSwizzleIndex( swizzle.getThirdValue() ) );
		}

		if ( count >= 4u )
		{
			result.push_back( simpl::helpers::getSwizzleIndex( swizzle.getFourthValue() ) );
		}

		return result;
	}

	uint32_t getComponentsCount( expr::CompositeType type )
	{
		switch ( type )
		{
		case expr::CompositeType::eScalar:
			return 1u;
		case expr::CompositeType::eVec2:
		case expr::CompositeType::eMat2x2:
		case expr::CompositeType::eMat2x3:
		case expr::CompositeType::eMat2x4:
		case expr::CompositeType::eCombine:
			return 2u;
		case expr::CompositeType::eVec3:
		case expr::CompositeType::eMat3x2:
		case expr::CompositeType::eMat3x3:
		case expr::CompositeType::eMat3x4:
			return 3u;
		case expr::CompositeType::eVec4:
		case expr::CompositeType::eMat4x2:
		case expr::CompositeType::eMat4x3:
		case expr::CompositeType::eMat4x4:
			return 4u;
		}

		return 0u;
	}

	expr::CompositeType getCompositeType( uint32_t count )
	{
		using expr::CompositeType;
		CompositeType result = CompositeType::eVec4;

		switch ( count )
		{
		case 1:
			result = CompositeType::eScalar;
			break;
		case 2:
			result = CompositeType::eVec2;
			break;
		case 3:
			result = CompositeType::eVec3;
			break;
		case 4:
			result = CompositeType::eVec4;
			break;
		default:
			AST_Failure( "Unsupported count to deduce CompositeType from" );
		}

		return result;
	}

	expr::SwizzleKind getSwizzleComponents( uint32_t count )
	{
		AST_Assert( count > 0 && count < 4 );

		switch ( count )
		{
		case 1:
			return expr::SwizzleKind{ expr::SwizzleKind::e0 };
		case 2:
			return expr::SwizzleKind{ expr::SwizzleKind::e01 };
		default:
			return expr::SwizzleKind{ expr::SwizzleKind::e012 };
		}
	}

	expr::ExprList makeList( expr::ExprPtr arg0 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		return result;
	}

	expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		result.push_back( std::move( arg1 ) );
		return result;
	}

	expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1
		, expr::ExprPtr arg2 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		result.push_back( std::move( arg1 ) );
		result.push_back( std::move( arg2 ) );
		return result;
	}

	expr::ExprList makeList( expr::ExprPtr arg0
		, expr::ExprPtr arg1
		, expr::ExprPtr arg2
		, expr::ExprPtr arg3 )
	{
		expr::ExprList result;
		result.push_back( std::move( arg0 ) );
		result.push_back( std::move( arg1 ) );
		result.push_back( std::move( arg2 ) );
		result.push_back( std::move( arg3 ) );
		return result;
	}

	expr::ExprPtr makeOne( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Kind typeKind )
	{
		expr::ExprPtr result{};

		switch ( typeKind )
		{
		case type::Kind::eInt8:
			result = exprCache.makeLiteral( typesCache, int8_t( 1 ) );
			break;
		case type::Kind::eInt16:
			result = exprCache.makeLiteral( typesCache, int16_t( 1 ) );
			break;
		case type::Kind::eInt32:
			result = exprCache.makeLiteral( typesCache, 1 );
			break;
		case type::Kind::eInt64:
			result = exprCache.makeLiteral( typesCache, 1LL );
			break;
		case type::Kind::eUInt8:
			result = exprCache.makeLiteral( typesCache, uint8_t( 1u ) );
			break;
		case type::Kind::eUInt16:
			result = exprCache.makeLiteral( typesCache, uint16_t( 1u ) );
			break;
		case type::Kind::eUInt32:
			result = exprCache.makeLiteral( typesCache, 1u );
			break;
		case type::Kind::eUInt64:
			result = exprCache.makeLiteral( typesCache, 1ULL );
			break;
		case type::Kind::eFloat:
			result = exprCache.makeLiteral( typesCache, 1.0f );
			break;
		case type::Kind::eDouble:
			result = exprCache.makeLiteral( typesCache, 1.0 );
			break;
		case type::Kind::eVec2I8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt8
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eInt8 ) ) );
			break;
		case type::Kind::eVec3I8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt8
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eInt8 ) ) );
			break;
		case type::Kind::eVec4I8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt8
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eInt8 ) ) );
			break;
		case type::Kind::eVec2I16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt16
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eInt16 ) ) );
			break;
		case type::Kind::eVec3I16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt16
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eInt16 ) ) );
			break;
		case type::Kind::eVec4I16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt16
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eInt16 ) ) );
			break;
		case type::Kind::eVec2I32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt32
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eInt32 ) ) );
			break;
		case type::Kind::eVec3I32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt32
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eInt32 ) ) );
			break;
		case type::Kind::eVec4I32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt32
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eInt32 ) ) );
			break;
		case type::Kind::eVec2I64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt64
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eInt64 ) ) );
			break;
		case type::Kind::eVec3I64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt64
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eInt64 ) ) );
			break;
		case type::Kind::eVec4I64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt64
				, makeList( makeOne( exprCache, typesCache, type::Kind::eInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eInt64 ) ) );
			break;
		case type::Kind::eVec2U8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt8
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt8 ) ) );
			break;
		case type::Kind::eVec3U8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt8
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt8 ) ) );
			break;
		case type::Kind::eVec4U8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt8
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt8 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt8 ) ) );
			break;
		case type::Kind::eVec2U16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt16
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt16 ) ) );
			break;
		case type::Kind::eVec3U16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt16
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt16 ) ) );
			break;
		case type::Kind::eVec4U16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt16
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt16 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt16 ) ) );
			break;
		case type::Kind::eVec2U32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt32
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt32 ) ) );
			break;
		case type::Kind::eVec3U32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt32
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt32 ) ) );
			break;
		case type::Kind::eVec4U32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt32
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt32 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt32 ) ) );
			break;
		case type::Kind::eVec2U64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt64
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt64 ) ) );
			break;
		case type::Kind::eVec3U64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt64
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt64 ) ) );
			break;
		case type::Kind::eVec4U64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt64
				, makeList( makeOne( exprCache, typesCache, type::Kind::eUInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt64 )
					, makeOne( exprCache, typesCache, type::Kind::eUInt64 ) ) );
			break;
		case type::Kind::eVec2F:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eFloat
				, makeList( makeOne( exprCache, typesCache, type::Kind::eFloat )
					, makeOne( exprCache, typesCache, type::Kind::eFloat ) ) );
			break;
		case type::Kind::eVec3F:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eFloat
				, makeList( makeOne( exprCache, typesCache, type::Kind::eFloat )
					, makeOne( exprCache, typesCache, type::Kind::eFloat )
					, makeOne( exprCache, typesCache, type::Kind::eFloat ) ) );
			break;
		case type::Kind::eVec4F:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eFloat
				, makeList( makeOne( exprCache, typesCache, type::Kind::eFloat )
					, makeOne( exprCache, typesCache, type::Kind::eFloat )
					, makeOne( exprCache, typesCache, type::Kind::eFloat )
					, makeOne( exprCache, typesCache, type::Kind::eFloat ) ) );
			break;
		case type::Kind::eVec2D:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eDouble
				, makeList( makeOne( exprCache, typesCache, type::Kind::eDouble )
					, makeOne( exprCache, typesCache, type::Kind::eDouble ) ) );
			break;
		case type::Kind::eVec3D:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eDouble
				, makeList( makeOne( exprCache, typesCache, type::Kind::eDouble )
					, makeOne( exprCache, typesCache, type::Kind::eDouble )
					, makeOne( exprCache, typesCache, type::Kind::eDouble ) ) );
			break;
		case type::Kind::eVec4D:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eDouble
				, makeList( makeOne( exprCache, typesCache, type::Kind::eDouble )
					, makeOne( exprCache, typesCache, type::Kind::eDouble )
					, makeOne( exprCache, typesCache, type::Kind::eDouble )
					, makeOne( exprCache, typesCache, type::Kind::eDouble ) ) );
			break;
		default:
			AST_Failure( "Unsupported scalar type for literal creation." );
		}

		return result;
	}

	expr::ExprPtr makeOne( expr::ExprCache & exprCache
		, type::TypePtr type )
	{
		return makeOne( exprCache, type->getTypesCache(), type->getKind() );
	}

	expr::ExprPtr makeZero( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::Kind typeKind )
	{
		expr::ExprPtr result{};

		switch ( typeKind )
		{
		case type::Kind::eInt8:
			result = exprCache.makeLiteral( typesCache, int8_t( 0 ) );
			break;
		case type::Kind::eInt16:
			result = exprCache.makeLiteral( typesCache, int16_t( 0 ) );
			break;
		case type::Kind::eInt32:
			result = exprCache.makeLiteral( typesCache, 0 );
			break;
		case type::Kind::eInt64:
			result = exprCache.makeLiteral( typesCache, 0LL );
			break;
		case type::Kind::eUInt8:
			result = exprCache.makeLiteral( typesCache, uint8_t( 0u ) );
			break;
		case type::Kind::eUInt16:
			result = exprCache.makeLiteral( typesCache, uint16_t( 0u ) );
			break;
		case type::Kind::eUInt32:
			result = exprCache.makeLiteral( typesCache, 0u );
			break;
		case type::Kind::eUInt64:
			result = exprCache.makeLiteral( typesCache, 0ULL );
			break;
		case type::Kind::eFloat:
			result = exprCache.makeLiteral( typesCache, 0.0f );
			break;
		case type::Kind::eDouble:
			result = exprCache.makeLiteral( typesCache, 0.0 );
			break;
		case type::Kind::eVec2I8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt8
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eInt8 ) ) );
			break;
		case type::Kind::eVec3I8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt8
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eInt8 ) ) );
			break;
		case type::Kind::eVec4I8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt8
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eInt8 ) ) );
			break;
		case type::Kind::eVec2I16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt16
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eInt16 ) ) );
			break;
		case type::Kind::eVec3I16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt16
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eInt16 ) ) );
			break;
		case type::Kind::eVec4I16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt16
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eInt16 ) ) );
			break;
		case type::Kind::eVec2I32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt32
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eInt32 ) ) );
			break;
		case type::Kind::eVec3I32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt32
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eInt32 ) ) );
			break;
		case type::Kind::eVec4I32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt32
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eInt32 ) ) );
			break;
		case type::Kind::eVec2I64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eInt64
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eInt64 ) ) );
			break;
		case type::Kind::eVec3I64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eInt64
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eInt64 ) ) );
			break;
		case type::Kind::eVec4I64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eInt64
				, makeList( makeZero( exprCache, typesCache, type::Kind::eInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eInt64 ) ) );
			break;
		case type::Kind::eVec2U8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt8
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt8 ) ) );
			break;
		case type::Kind::eVec3U8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt8
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt8 ) ) );
			break;
		case type::Kind::eVec4U8:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt8
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt8 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt8 ) ) );
			break;
		case type::Kind::eVec2U16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt16
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt16 ) ) );
			break;
		case type::Kind::eVec3U16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt16
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt16 ) ) );
			break;
		case type::Kind::eVec4U16:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt16
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt16 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt16 ) ) );
			break;
		case type::Kind::eVec2U32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt32
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt32 ) ) );
			break;
		case type::Kind::eVec3U32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt32
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt32 ) ) );
			break;
		case type::Kind::eVec4U32:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt32
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt32 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt32 ) ) );
			break;
		case type::Kind::eVec2U64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eUInt64
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt64 ) ) );
			break;
		case type::Kind::eVec3U64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eUInt64
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt64 ) ) );
			break;
		case type::Kind::eVec4U64:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eUInt64
				, makeList( makeZero( exprCache, typesCache, type::Kind::eUInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt64 )
					, makeZero( exprCache, typesCache, type::Kind::eUInt64 ) ) );
			break;
		case type::Kind::eVec2F:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eFloat
				, makeList( makeZero( exprCache, typesCache, type::Kind::eFloat )
					, makeZero( exprCache, typesCache, type::Kind::eFloat ) ) );
			break;
		case type::Kind::eVec3F:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eFloat
				, makeList( makeZero( exprCache, typesCache, type::Kind::eFloat )
					, makeZero( exprCache, typesCache, type::Kind::eFloat )
					, makeZero( exprCache, typesCache, type::Kind::eFloat ) ) );
			break;
		case type::Kind::eVec4F:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eFloat
				, makeList( makeZero( exprCache, typesCache, type::Kind::eFloat )
					, makeZero( exprCache, typesCache, type::Kind::eFloat )
					, makeZero( exprCache, typesCache, type::Kind::eFloat )
					, makeZero( exprCache, typesCache, type::Kind::eFloat ) ) );
			break;
		case type::Kind::eVec2D:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec2
				, type::Kind::eDouble
				, makeList( makeZero( exprCache, typesCache, type::Kind::eDouble )
					, makeZero( exprCache, typesCache, type::Kind::eDouble ) ) );
			break;
		case type::Kind::eVec3D:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec3
				, type::Kind::eDouble
				, makeList( makeZero( exprCache, typesCache, type::Kind::eDouble )
					, makeZero( exprCache, typesCache, type::Kind::eDouble )
					, makeZero( exprCache, typesCache, type::Kind::eDouble ) ) );
			break;
		case type::Kind::eVec4D:
			result = exprCache.makeCompositeConstruct( expr::CompositeType::eVec4
				, type::Kind::eDouble
				, makeList( makeZero( exprCache, typesCache, type::Kind::eDouble )
					, makeZero( exprCache, typesCache, type::Kind::eDouble )
					, makeZero( exprCache, typesCache, type::Kind::eDouble )
					, makeZero( exprCache, typesCache, type::Kind::eDouble ) ) );
			break;
		default:
			AST_Failure( "Unsupported scalar type for literal creation." );
		}

		return result;
	}

	expr::ExprPtr makeZero( expr::ExprCache & exprCache
		, type::TypePtr type )
	{
		return makeZero( exprCache, type->getTypesCache(), type->getKind() );
	}

	stmt::ContainerPtr simplify( stmt::StmtCache & stmtCache
		, expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, stmt::Container const & stmt )
	{
		return simpl::StmtSimplifier::submit( stmtCache, exprCache, typesCache, stmt );
	}

	expr::ExprPtr simplify( expr::ExprCache & exprCache
		, type::TypesCache & typesCache
		, expr::Expr const & expr )
	{
		return simpl::ExprSimplifier::submit( exprCache, typesCache, expr );
	}
}
