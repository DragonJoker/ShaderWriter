/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/SimplifyStatements.hpp"

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
			static std::vector< expr::SwizzleKind > getSwizzleValues( expr::SwizzleKind swizzle )
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
					assert( index < values.size() );
					auto shifted = ast::expr::SwizzleKind::Value( values[index].getValue() >> shift );
					auto ored = ast::expr::SwizzleKind::Value( result.getValue() | shifted );
					result = ast::expr::SwizzleKind{ ored };
					shift += 4u;
				}

				return result;
			}

			static ast::type::TypePtr getExpectedReturnType( ast::expr::StorageImageAccessCall const * expr )
			{
				auto result = expr->getType();

				if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageLoad1DF
					&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageLoad2DMSArrayU )
				{
					auto scalar = ast::type::getScalarType( result->getKind() );
					auto components = ast::type::getComponentCount( result );

					if ( components != 4u )
					{
						result = result->getTypesCache().getVec4Type( scalar );
					}
				}

				return result;
			}

			static uint32_t getComponentsCount( expr::CompositeType type )
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

			static expr::CompositeType getCompositeType( uint32_t count )
			{
				using expr::CompositeType;
				CompositeType result = CompositeType::eScalar;

				switch ( count )
				{
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
					result = CompositeType::eVec4;
					break;
				}

				return result;
			}

			static ast::expr::SwizzleKind getSwizzleComponents( uint32_t count )
			{
				assert( count > 0 && count < 4 );

				switch ( count )
				{
				case 1:
					return ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 };
				case 2:
					return ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e01 };
				default:
					return ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e012 };
				}
			}

			static expr::ExprPtr makeZero( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, type::Kind scalarType )
			{
				switch ( scalarType )
				{
				case ast::type::Kind::eInt8:
					return exprCache.makeLiteral( typesCache, int8_t( 0 ) );
				case ast::type::Kind::eInt16:
					return exprCache.makeLiteral( typesCache, int16_t( 0 ) );
				case ast::type::Kind::eInt32:
					return exprCache.makeLiteral( typesCache, 0 );
				case ast::type::Kind::eInt64:
					return exprCache.makeLiteral( typesCache, 0LL );
				case ast::type::Kind::eUInt8:
					return exprCache.makeLiteral( typesCache, uint8_t( 0u ) );
				case ast::type::Kind::eUInt16:
					return exprCache.makeLiteral( typesCache, uint16_t( 0u ) );
				case ast::type::Kind::eUInt32:
					return exprCache.makeLiteral( typesCache, 0u );
				case ast::type::Kind::eUInt64:
					return exprCache.makeLiteral( typesCache, 0ULL );
				case ast::type::Kind::eFloat:
					return exprCache.makeLiteral( typesCache, 0.0f );
				case ast::type::Kind::eDouble:
					return exprCache.makeLiteral( typesCache, 0.0 );
				default:
					AST_Failure( "Unsupported scalar type for literal creation." );
					return nullptr;
				}
			}

			static expr::ExprPtr makeOne( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, type::Kind scalarType )
			{
				switch ( scalarType )
				{
				case ast::type::Kind::eInt8:
					return exprCache.makeLiteral( typesCache, int8_t( 1 ) );
				case ast::type::Kind::eInt16:
					return exprCache.makeLiteral( typesCache, int16_t( 1 ) );
				case ast::type::Kind::eInt32:
					return exprCache.makeLiteral( typesCache, 1 );
				case ast::type::Kind::eInt64:
					return exprCache.makeLiteral( typesCache, 1LL );
				case ast::type::Kind::eUInt8:
					return exprCache.makeLiteral( typesCache, uint8_t( 1u ) );
				case ast::type::Kind::eUInt16:
					return exprCache.makeLiteral( typesCache, uint16_t( 1u ) );
				case ast::type::Kind::eUInt32:
					return exprCache.makeLiteral( typesCache, 1u );
				case ast::type::Kind::eUInt64:
					return exprCache.makeLiteral( typesCache, 1ULL );
				case ast::type::Kind::eFloat:
					return exprCache.makeLiteral( typesCache, 1.0f );
				case ast::type::Kind::eDouble:
					return exprCache.makeLiteral( typesCache, 1.0 );
				default:
					AST_Failure( "Unsupported scalar type for literal creation." );
					return nullptr;
				}
			}

			static ast::expr::ExprPtr makeToBoolCast( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, ast::expr::ExprPtr expr )
			{
				auto componentCount = getComponentCount( expr->getType()->getKind() );
				ast::expr::ExprPtr result{};
				auto type = expr->getType()->getKind();

				if ( componentCount == 1u )
				{
					result = exprCache.makeNotEqual( typesCache
						, std::move( expr )
						, makeZero( exprCache, typesCache, type ) );
				}
				else
				{
					ast::expr::ExprList args;
					expr::ExprPtr newExpr = std::move( expr );

					for ( auto i = 0u; i < componentCount; ++i )
					{
						args.emplace_back( exprCache.makeNotEqual( typesCache
							, exprCache.makeSwizzle( ast::ExprCloner::submit( exprCache, *newExpr ), ast::expr::SwizzleKind::fromOffset( i ) )
							, makeZero( exprCache, typesCache, type ) ) );
					}

					result = exprCache.makeCompositeConstruct( ast::expr::CompositeType( componentCount )
						, ast::type::Kind::eBoolean
						, std::move( args ) );
				}

				return result;
			}

			static ast::expr::ExprPtr makeFromBoolCast( expr::ExprCache & exprCache
				, type::TypesCache & typesCache
				, ast::expr::ExprPtr expr
				, ast::type::Kind dstScalarType )
			{
				auto componentCount = getComponentCount( expr->getType()->getKind() );
				ast::expr::ExprPtr result{};

				if ( componentCount == 1u )
				{
					auto scalarType = typesCache.getBasicType( dstScalarType );
					result = exprCache.makeQuestion( scalarType
						, std::move( expr )
						, makeOne( exprCache, typesCache, dstScalarType )
						, makeZero( exprCache, typesCache, dstScalarType ) );
				}
				else
				{
					ast::expr::ExprList args;
					expr::ExprPtr newExpr = std::move( expr );
					auto scalarType = typesCache.getBasicType( dstScalarType );

					for ( auto i = 0u; i < componentCount; ++i )
					{
						args.emplace_back( exprCache.makeQuestion( scalarType
							, exprCache.makeSwizzle( ast::ExprCloner::submit( exprCache, *newExpr ), ast::expr::SwizzleKind::fromOffset( i ) )
							, makeOne( exprCache, typesCache, dstScalarType )
							, makeZero( exprCache, typesCache, dstScalarType ) ) );
					}

					result = exprCache.makeCompositeConstruct( ast::expr::CompositeType( componentCount )
						, dstScalarType
						, std::move( args ) );
				}

				return result;
			}

			static constexpr uint32_t InvalidComponentCount = ~0u;

			static uint32_t getReturnComponentCount( ast::expr::CombinedImageAccess value )
			{
				switch ( value )
				{
				case ast::expr::CombinedImageAccess::eTexture1DShadowF:
				case ast::expr::CombinedImageAccess::eTexture1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTexture2DShadowF:
				case ast::expr::CombinedImageAccess::eTexture2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureCubeShadowFBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
					return 1u;

				case ast::expr::CombinedImageAccess::eTexture1DF:
				case ast::expr::CombinedImageAccess::eTexture1DFBias:
				case ast::expr::CombinedImageAccess::eTexture2DF:
				case ast::expr::CombinedImageAccess::eTexture2DFBias:
				case ast::expr::CombinedImageAccess::eTexture3DF:
				case ast::expr::CombinedImageAccess::eTexture3DFBias:
				case ast::expr::CombinedImageAccess::eTextureCubeF:
				case ast::expr::CombinedImageAccess::eTextureCubeFBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayF:
				case ast::expr::CombinedImageAccess::eTexture1DArrayFBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayF:
				case ast::expr::CombinedImageAccess::eTexture2DArrayFBias:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayFBias:
				case ast::expr::CombinedImageAccess::eTexture1DI:
				case ast::expr::CombinedImageAccess::eTexture1DIBias:
				case ast::expr::CombinedImageAccess::eTexture2DI:
				case ast::expr::CombinedImageAccess::eTexture2DIBias:
				case ast::expr::CombinedImageAccess::eTexture3DI:
				case ast::expr::CombinedImageAccess::eTexture3DIBias:
				case ast::expr::CombinedImageAccess::eTextureCubeI:
				case ast::expr::CombinedImageAccess::eTextureCubeIBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayI:
				case ast::expr::CombinedImageAccess::eTexture1DArrayIBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayI:
				case ast::expr::CombinedImageAccess::eTexture2DArrayIBias:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayIBias:
				case ast::expr::CombinedImageAccess::eTexture1DU:
				case ast::expr::CombinedImageAccess::eTexture1DUBias:
				case ast::expr::CombinedImageAccess::eTexture2DU:
				case ast::expr::CombinedImageAccess::eTexture2DUBias:
				case ast::expr::CombinedImageAccess::eTexture3DU:
				case ast::expr::CombinedImageAccess::eTexture3DUBias:
				case ast::expr::CombinedImageAccess::eTextureCubeU:
				case ast::expr::CombinedImageAccess::eTextureCubeUBias:
				case ast::expr::CombinedImageAccess::eTexture1DArrayU:
				case ast::expr::CombinedImageAccess::eTexture1DArrayUBias:
				case ast::expr::CombinedImageAccess::eTexture2DArrayU:
				case ast::expr::CombinedImageAccess::eTexture2DArrayUBias:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureCubeArrayUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureOffset1DI:
				case ast::expr::CombinedImageAccess::eTextureOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureOffset1DU:
				case ast::expr::CombinedImageAccess::eTextureOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureOffset1DFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset3DFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayFBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset3DIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayIBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset3DUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset1DArrayUBias:
				case ast::expr::CombinedImageAccess::eTextureOffset2DArrayUBias:
				case ast::expr::CombinedImageAccess::eTextureGrad1DF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DF:
				case ast::expr::CombinedImageAccess::eTextureGrad3DF:
				case ast::expr::CombinedImageAccess::eTextureGradCubeF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGrad2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGradCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureGrad1DI:
				case ast::expr::CombinedImageAccess::eTextureGrad2DI:
				case ast::expr::CombinedImageAccess::eTextureGrad3DI:
				case ast::expr::CombinedImageAccess::eTextureGradCubeI:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGrad2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGradCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureGrad1DU:
				case ast::expr::CombinedImageAccess::eTextureGrad2DU:
				case ast::expr::CombinedImageAccess::eTextureGrad3DU:
				case ast::expr::CombinedImageAccess::eTextureGradCubeU:
				case ast::expr::CombinedImageAccess::eTextureGrad1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGrad2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGradCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureProj1DF2:
				case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
				case ast::expr::CombinedImageAccess::eTextureProj1DF4:
				case ast::expr::CombinedImageAccess::eTextureProj1DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DF3:
				case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DF4:
				case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj3DF:
				case ast::expr::CombinedImageAccess::eTextureProj3DFBias:
				case ast::expr::CombinedImageAccess::eTextureProj1DI2:
				case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
				case ast::expr::CombinedImageAccess::eTextureProj1DI4:
				case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DI3:
				case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DI4:
				case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj3DI:
				case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
				case ast::expr::CombinedImageAccess::eTextureProj1DU2:
				case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
				case ast::expr::CombinedImageAccess::eTextureProj1DU4:
				case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DU3:
				case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
				case ast::expr::CombinedImageAccess::eTextureProj2DU4:
				case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProj3DU:
				case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
				case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad3DF:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureLod1DF:
				case ast::expr::CombinedImageAccess::eTextureLod2DF:
				case ast::expr::CombinedImageAccess::eTextureLod3DF:
				case ast::expr::CombinedImageAccess::eTextureLodCubeF:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureLod1DI:
				case ast::expr::CombinedImageAccess::eTextureLod2DI:
				case ast::expr::CombinedImageAccess::eTextureLod3DI:
				case ast::expr::CombinedImageAccess::eTextureLodCubeI:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureLod1DU:
				case ast::expr::CombinedImageAccess::eTextureLod2DU:
				case ast::expr::CombinedImageAccess::eTextureLod3DU:
				case ast::expr::CombinedImageAccess::eTextureLodCubeU:
				case ast::expr::CombinedImageAccess::eTextureLod1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureLod2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureLodCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset3DU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTextureLodOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLod3DF:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLod3DI:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjLod1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjLod2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLod3DU:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF2:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF3:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DF4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DF:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI2:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI3:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DI4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DI:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU2:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU3:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DU4:
				case ast::expr::CombinedImageAccess::eTextureProjLodOffset3DU:
				case ast::expr::CombinedImageAccess::eTexelFetch1DF:
				case ast::expr::CombinedImageAccess::eTexelFetch2DF:
				case ast::expr::CombinedImageAccess::eTexelFetch3DF:
				case ast::expr::CombinedImageAccess::eTexelFetch1DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetch2DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetchBufferF:
				case ast::expr::CombinedImageAccess::eTexelFetch1DI:
				case ast::expr::CombinedImageAccess::eTexelFetch2DI:
				case ast::expr::CombinedImageAccess::eTexelFetch3DI:
				case ast::expr::CombinedImageAccess::eTexelFetch1DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetch2DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetchBufferI:
				case ast::expr::CombinedImageAccess::eTexelFetch1DU:
				case ast::expr::CombinedImageAccess::eTexelFetch2DU:
				case ast::expr::CombinedImageAccess::eTexelFetch3DU:
				case ast::expr::CombinedImageAccess::eTexelFetch1DArrayU:
				case ast::expr::CombinedImageAccess::eTexelFetch2DArrayU:
				case ast::expr::CombinedImageAccess::eTexelFetchBufferU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset3DF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset3DI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset3DU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayU:
				case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGather2DF:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayF:
				case ast::expr::CombinedImageAccess::eTextureGather2DI:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeI:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayI:
				case ast::expr::CombinedImageAccess::eTextureGather2DU:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeU:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
				case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
				case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
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

					void visitAddAssignExpr( ast::expr::AddAssign const * expr )override
					{
						AST_Failure( "Unexpected AddAssign expression" );
					}

					void visitAggrInitExpr( ast::expr::AggrInit const * expr )override
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

					void visitAliasExpr( ast::expr::Alias const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitAndAssignExpr( ast::expr::AndAssign const * expr )override
					{
						AST_Failure( "Unexpected AndAssign expression" );
					}

					void visitArrayAccessExpr( expr::ArrayAccess const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitAssignExpr( ast::expr::Assign const * expr )override
					{
						AST_Failure( "Unexpected Assign expression" );
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

						if ( rhs && lhs )
						{
							m_result = m_exprCache.makeComma( std::move( lhs )
								, std::move( rhs ) );
						}
						else if ( lhs )
						{
							m_result = std::move( lhs );
						}
						else if ( rhs )
						{
							m_result = std::move( rhs );
						}
					}

					void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitCompositeConstructExpr( ast::expr::CompositeConstruct const * expr )override
					{
						TraceFunc;
						if ( expr->getArgList().size() > m_index )
						{
							m_result = doSubmit( *expr->getArgList()[m_index] );
						}
						else
						{
							doSwizzle( expr->clone() );
						}
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

					void visitDivideAssignExpr( ast::expr::DivideAssign const * expr )override
					{
						AST_Failure( "Unexpected DivideAssign expression" );
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

					void visitIdentifierExpr( ast::expr::Identifier const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitImageAccessCallExpr( expr::StorageImageAccessCall const * expr )override
					{
						TraceFunc;
						doSwizzle( expr->clone() );
					}

					void visitInitExpr( ast::expr::Init const * expr )override
					{
						TraceFunc;
						if ( expr->hasIdentifier() )
						{
							doSubmit( expr->getIdentifier() );
						}
						else
						{
							doSubmit( *expr->getInitialiser() );
						}
					}

					void visitIntrinsicCallExpr( ast::expr::IntrinsicCall const * expr )override
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

					void visitLiteralExpr( ast::expr::Literal const * expr )override
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

					void visitLShiftAssignExpr( ast::expr::LShiftAssign const * expr )override
					{
						AST_Failure( "Unexpected LShiftAssign expression" );
					}

					void visitMbrSelectExpr( ast::expr::MbrSelect const * expr )override
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

					void visitMinusAssignExpr( ast::expr::MinusAssign const * expr )override
					{
						AST_Failure( "Unexpected MinusAssign expression" );
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

					void visitModuloAssignExpr( ast::expr::ModuloAssign const * expr )override
					{
						AST_Failure( "Unexpected ModuloAssign expression" );
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

					void visitOrAssignExpr( ast::expr::OrAssign const * expr )override
					{
						AST_Failure( "Unexpected OrAssign expression" );
					}

					void visitPostDecrementExpr( expr::PostDecrement const * expr )override
					{
						AST_Failure( "Unexpected PostDecrement expression" );
					}

					void visitPostIncrementExpr( expr::PostIncrement const * expr )override
					{
						AST_Failure( "Unexpected PostIncrement expression" );
					}

					void visitPreDecrementExpr( expr::PreDecrement const * expr )override
					{
						AST_Failure( "Unexpected PreDecrement expression" );
					}

					void visitPreIncrementExpr( expr::PreIncrement const * expr )override
					{
						AST_Failure( "Unexpected PreIncrement expression" );
					}

					void visitQuestionExpr( ast::expr::Question const * expr )override
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

					void visitRShiftAssignExpr( ast::expr::RShiftAssign const * expr )override
					{
						AST_Failure( "Unexpected RShiftAssign expression" );
					}

					void visitStreamAppendExpr( ast::expr::StreamAppend const * expr )override
					{
						AST_Failure( "Unexpected StreamAppend expression" );
					}

					void visitSwitchCaseExpr( ast::expr::SwitchCase const * expr )override
					{
						AST_Failure( "Unexpected SwitchCase expression" );
					}

					void visitSwitchTestExpr( ast::expr::SwitchTest const * expr )override
					{
						AST_Failure( "Unexpected SwitchTest expression" );
					}

					void visitSwizzleExpr( ast::expr::Swizzle const * expr )override
					{
						TraceFunc;
						auto componentCount = getComponentCount( expr->getType() );

						if ( componentCount == 1u )
						{
							m_result = expr->clone();
						}
						else if ( componentCount > m_index )
						{
							auto values = helpers::getSwizzleValues( expr->getSwizzle() );
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

					void visitTimesAssignExpr( ast::expr::TimesAssign const * expr )override
					{
						AST_Failure( "Unexpected TimesAssign expression" );
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

					void visitXorAssignExpr( ast::expr::XorAssign const * expr )override
					{
						AST_Failure( "Unexpected XorAssign expression" );
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
			using ast::ExprCloner::doSubmit;

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

			void visitCastExpr( ast::expr::Cast const * expr )override
			{
				TraceFunc;
				auto dstScalarType = getScalarType( expr->getType()->getKind() );
				auto srcScalarType = getScalarType( expr->getOperand()->getType()->getKind() );
#if !defined( NDEBUG )
				auto dstComponents = getComponentCount( expr->getType()->getKind() );
				auto srcComponents = getComponentCount( expr->getOperand()->getType()->getKind() );
#endif

				if ( dstScalarType == ast::type::Kind::eBoolean
					&& srcScalarType != ast::type::Kind::eBoolean )
				{
					// Conversion to bool scalar or vector type.
					assert( dstComponents == srcComponents );
					m_result = helpers::makeToBoolCast( m_exprCache, m_typesCache
						, doSubmit( *expr->getOperand() ) );
				}
				else if ( srcScalarType == ast::type::Kind::eBoolean
					&& dstScalarType != ast::type::Kind::eBoolean )
				{
					// Conversion from bool scalar or vector type.
					assert( dstComponents == srcComponents );
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
					assert( returnComponentsCount > count );
					returnType = m_typesCache.getVector( getScalarType( returnType->getKind() ), returnComponentsCount );
				}

				ast::expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( *arg ) );
				}

				m_result = m_exprCache.makeCombinedImageAccessCall( returnType
						, kind
						, std::move( args ) );

				if ( returnComponentsCount != helpers::InvalidComponentCount && returnComponentsCount != count )
				{
					ast::expr::SwizzleKind swizzleKind;

					switch ( count )
					{
					case 1:
						swizzleKind = ast::expr::SwizzleKind::e0;
						break;
					case 2:
						swizzleKind = ast::expr::SwizzleKind::e01;
						break;
					case 3:
						swizzleKind = ast::expr::SwizzleKind::e012;
						break;
					default:
						swizzleKind = ast::expr::SwizzleKind::e0123;
						break;
					}

					m_result = m_exprCache.makeSwizzle( std::move( m_result ), swizzleKind );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct const * expr )override
			{
				TraceFunc;
				if ( expr->getComposite() == expr::CompositeType::eCombine )
				{
					return ExprCloner::visitCompositeConstructExpr( expr );
				}
				else
				{
					ast::expr::ExprList args;

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
				ast::expr::ExprList args;

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
					assert( ast::type::getScalarType( srcType->getKind() ) == ast::type::getScalarType( dstType->getKind() ) );
					auto dstCount = ast::type::getComponentCount( dstType );

					if ( dstCount == 1u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e0 } );
					}
					else if ( dstCount == 2u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e01 } );
					}
					else if ( dstCount == 3u )
					{
						m_result = m_exprCache.makeSwizzle( std::move( m_result )
							, ast::expr::SwizzleKind{ ast::expr::SwizzleKind::e012 } );
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
					assert( expr->getArgList().size() == 2u );
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
					assert( condComponents == 1u );
					ast::expr::ExprList args;
					args.emplace_back( doSubmit( *expr->getCtrlExpr() ) );
					m_result = m_exprCache.makeQuestion( expr->getType()
						, doSubmit( *m_exprCache.makeCompositeConstruct( helpers::getCompositeType( opsComponents )
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
						auto values = helpers::getSwizzleValues( outerSwizzle.getSwizzle() );
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
								m_result = doSubmit( **std::next( compositeConstruct.getArgList().begin()
									, ptrdiff_t( expr->getSwizzle().toIndex() ) ) );
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
				for ( auto i = 0u; i < helpers::getComponentsCount( expr.getComposite() ); ++i )
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
						&& helpers::getComponentsCount( expr.getComposite() ) > 1u )
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

			void doConstructVector( ast::expr::CompositeConstruct const & expr
				, ast::expr::Expr const & newArg
				, ast::type::Kind destKind
				, ast::expr::ExprList & args )
			{
				TraceFunc;
				auto srcCount = getComponentCount( newArg.getType()->getKind() );
				auto dstCount = getComponentCount( destKind );
				auto count = std::min( srcCount, dstCount );

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( doSubmit( *m_exprCache.makeSwizzle( doSubmit( newArg )
						, ast::expr::SwizzleKind::fromOffset( i ) ) ) );
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

			void doConstructMatrix( ast::expr::Expr const & newArg
				, ast::type::Kind destKind
				, ast::expr::ExprList & args )
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
					auto arrayAccess = m_exprCache.makeArrayAccess( m_typesCache.getVector( scalarType, srcRowCount )
						, doSubmit( newArg )
						, m_exprCache.makeLiteral( m_typesCache, col ) );

					if ( dstRowCount < srcRowCount )
					{
						args.emplace_back( m_exprCache.makeSwizzle( std::move( arrayAccess )
							, helpers::getSwizzleComponents( dstRowCount ) ) );
					}
					else if ( dstRowCount == srcRowCount )
					{
						args.emplace_back( std::move( arrayAccess ) );
					}
					else
					{
						ast::expr::ExprList compositeArgs;
						compositeArgs.emplace_back( std::move( arrayAccess ) );

						for ( auto row = srcRowCount; row < dstRowCount; ++row )
						{
							if ( row == col )
							{
								compositeArgs.emplace_back( helpers::makeOne( m_exprCache, m_typesCache, scalarType ) );
							}
							else
							{
								compositeArgs.emplace_back( helpers::makeZero( m_exprCache, m_typesCache, scalarType ) );
							}
						}

						args.emplace_back( m_exprCache.makeCompositeConstruct( helpers::getCompositeType( dstRowCount )
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
						assert( lhs->getType()->getKind() == rhs->getType()->getKind()
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
						lhs = m_exprCache.makeCompositeConstruct( helpers::getCompositeType( getComponentCount( result->getKind() ) )
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
						rhs = m_exprCache.makeCompositeConstruct( helpers::getCompositeType( getComponentCount( result->getKind() ) )
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
						break;
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
						break;
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

				assert( args.size() == 1u );
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

			using ast::StmtCloner::doSubmit;

			expr::ExprPtr doSubmit( expr::Expr const & expr )override
			{
				return ExprSimplifier::submit( m_exprCache, m_typesCache, expr );
			}

			void visitDoWhileStmt( stmt::DoWhile const * stmt )override
			{
				TraceFunc;
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				auto scalarType = getScalarType( ctrlExpr->getType()->getKind() );
				auto doWhileContent = m_stmtCache.makeDoWhile( ( scalarType != ast::type::Kind::eBoolean )
					? helpers::makeToBoolCast( m_exprCache, m_typesCache, std::move( ctrlExpr ) )
					: std::move( ctrlExpr ) );
				auto save = m_current;
				m_current = doWhileContent.get();
				visitContainerStmt( stmt );
				m_current = save;
				m_current->addStmt( std::move( doWhileContent ) );
			}

			void visitElseIfStmt( ast::stmt::ElseIf const * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else const * stmt )override
			{
				AST_Failure( "Unexpected Else statement." );
			}

			void visitIfStmt( stmt::If const * stmt )override
			{
				TraceFunc;
				auto save = m_current;
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				auto scalarType = getScalarType( ctrlExpr->getType()->getKind() );
				auto ifCont = m_stmtCache.makeIf( ( scalarType != ast::type::Kind::eBoolean )
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
		assert( exprKind != expr::Kind::eImageAccessCall
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

	expr::ExprPtr makeOne( expr::ExprCache & exprCache
		, type::TypePtr type )
	{
		return simpl::helpers::makeOne( exprCache, type->getTypesCache(), type->getKind() );
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
