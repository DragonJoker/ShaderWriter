/*
See LICENSE file in root folder
*/
#include "ShaderAST/Visitors/TransformSSA.hpp"

#include "ShaderAST/Visitors/CloneExpr.hpp"
#include "ShaderAST/Visitors/CloneStmt.hpp"
#include "ShaderAST/Visitors/GetExprName.hpp"

namespace ast
{
	namespace
	{
		expr::CompositeType getCompositeType( uint32_t count )
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
			}

			return result;
		}

		ast::expr::SwizzleKind getSwizzleComponents( uint32_t count )
		{
			assert( count > 0 && count < 4 );

			switch ( count )
			{
			case 1:
				return ast::expr::SwizzleKind::e0;
			case 2:
				return ast::expr::SwizzleKind::e01;
			default:
				return ast::expr::SwizzleKind::e012;
			}
		}

		ast::type::TypePtr getExpectedReturnType( ast::expr::ImageAccessCall * expr )
		{
			auto result = expr->getType();

			if ( expr->getImageAccess() >= ast::expr::StorageImageAccess::eImageLoad1DF
				&& expr->getImageAccess() <= ast::expr::StorageImageAccess::eImageLoad2DMSArrayU )
			{
				auto scalar = ast::type::getScalarType( result->getKind() );
				auto components = ast::type::getComponentCount( result );

				if ( components != 4u )
				{
					result = result->getCache().getVec4Type( scalar );
				}
			}

			return result;
		}

		static constexpr uint32_t InvalidComponentCount = ~( 0u );

		uint32_t getReturnComponentCount( ast::expr::CombinedImageAccess value )
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
			case ast::expr::CombinedImageAccess::eTexture2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureCubeArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureGrad2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
			case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
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
			case ast::expr::CombinedImageAccess::eTexture2DRectF:
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
			case ast::expr::CombinedImageAccess::eTexture2DRectI:
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
			case ast::expr::CombinedImageAccess::eTexture2DRectU:
			case ast::expr::CombinedImageAccess::eTextureOffset1DF:
			case ast::expr::CombinedImageAccess::eTextureOffset2DF:
			case ast::expr::CombinedImageAccess::eTextureOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureOffset2DRectF:
			case ast::expr::CombinedImageAccess::eTextureOffset1DArrayF:
			case ast::expr::CombinedImageAccess::eTextureOffset2DArrayF:
			case ast::expr::CombinedImageAccess::eTextureOffset1DI:
			case ast::expr::CombinedImageAccess::eTextureOffset2DI:
			case ast::expr::CombinedImageAccess::eTextureOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureOffset2DRectI:
			case ast::expr::CombinedImageAccess::eTextureOffset1DArrayI:
			case ast::expr::CombinedImageAccess::eTextureOffset2DArrayI:
			case ast::expr::CombinedImageAccess::eTextureOffset1DU:
			case ast::expr::CombinedImageAccess::eTextureOffset2DU:
			case ast::expr::CombinedImageAccess::eTextureOffset3DU:
			case ast::expr::CombinedImageAccess::eTextureOffset2DRectU:
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
			case ast::expr::CombinedImageAccess::eTextureGrad2DRectF:
			case ast::expr::CombinedImageAccess::eTextureGrad1DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGrad2DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGradCubeArrayF:
			case ast::expr::CombinedImageAccess::eTextureGrad1DI:
			case ast::expr::CombinedImageAccess::eTextureGrad2DI:
			case ast::expr::CombinedImageAccess::eTextureGrad3DI:
			case ast::expr::CombinedImageAccess::eTextureGradCubeI:
			case ast::expr::CombinedImageAccess::eTextureGrad2DRectI:
			case ast::expr::CombinedImageAccess::eTextureGrad1DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGrad2DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGradCubeArrayI:
			case ast::expr::CombinedImageAccess::eTextureGrad1DU:
			case ast::expr::CombinedImageAccess::eTextureGrad2DU:
			case ast::expr::CombinedImageAccess::eTextureGrad3DU:
			case ast::expr::CombinedImageAccess::eTextureGradCubeU:
			case ast::expr::CombinedImageAccess::eTextureGrad2DRectU:
			case ast::expr::CombinedImageAccess::eTextureGrad1DArrayU:
			case ast::expr::CombinedImageAccess::eTextureGrad2DArrayU:
			case ast::expr::CombinedImageAccess::eTextureGradCubeArrayU:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DI:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DI:
			case ast::expr::CombinedImageAccess::eTextureGradOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectI:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGradOffset1DU:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DU:
			case ast::expr::CombinedImageAccess::eTextureGradOffset3DU:
			case ast::expr::CombinedImageAccess::eTextureGradOffset2DRectU:
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
			case ast::expr::CombinedImageAccess::eTextureProj2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectF4:
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
			case ast::expr::CombinedImageAccess::eTextureProj2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectI4:
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
			case ast::expr::CombinedImageAccess::eTextureProj2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProj2DRectU4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProjOffset2DRectU4:
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
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad3DI:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjGrad1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGrad3DU:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProjGrad2DRectU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF2:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DF:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectF4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI2:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DI:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectI4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU2:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DU4:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset3DU:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU3:
			case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DRectU4:
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
			case ast::expr::CombinedImageAccess::eTexelFetch2DRectF:
			case ast::expr::CombinedImageAccess::eTexelFetch1DArrayF:
			case ast::expr::CombinedImageAccess::eTexelFetch2DArrayF:
			case ast::expr::CombinedImageAccess::eTexelFetchBufferF:
			case ast::expr::CombinedImageAccess::eTexelFetch1DI:
			case ast::expr::CombinedImageAccess::eTexelFetch2DI:
			case ast::expr::CombinedImageAccess::eTexelFetch3DI:
			case ast::expr::CombinedImageAccess::eTexelFetch2DRectI:
			case ast::expr::CombinedImageAccess::eTexelFetch1DArrayI:
			case ast::expr::CombinedImageAccess::eTexelFetch2DArrayI:
			case ast::expr::CombinedImageAccess::eTexelFetchBufferI:
			case ast::expr::CombinedImageAccess::eTexelFetch1DU:
			case ast::expr::CombinedImageAccess::eTexelFetch2DU:
			case ast::expr::CombinedImageAccess::eTexelFetch3DU:
			case ast::expr::CombinedImageAccess::eTexelFetch2DRectU:
			case ast::expr::CombinedImageAccess::eTexelFetch1DArrayU:
			case ast::expr::CombinedImageAccess::eTexelFetch2DArrayU:
			case ast::expr::CombinedImageAccess::eTexelFetchBufferU:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset1DF:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DF:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset3DF:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectF:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayF:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayF:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset1DI:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DI:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset3DI:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectI:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayI:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayI:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset1DU:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DU:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset3DU:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DRectU:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset1DArrayU:
			case ast::expr::CombinedImageAccess::eTexelFetchOffset2DArrayU:
			case ast::expr::CombinedImageAccess::eTextureGather2DF:
			case ast::expr::CombinedImageAccess::eTextureGather2DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeF:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayF:
			case ast::expr::CombinedImageAccess::eTextureGather2DRectF:
			case ast::expr::CombinedImageAccess::eTextureGather2DI:
			case ast::expr::CombinedImageAccess::eTextureGather2DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeI:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayI:
			case ast::expr::CombinedImageAccess::eTextureGather2DRectI:
			case ast::expr::CombinedImageAccess::eTextureGather2DU:
			case ast::expr::CombinedImageAccess::eTextureGather2DArrayU:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeU:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayU:
			case ast::expr::CombinedImageAccess::eTextureGather2DRectU:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectI:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectU:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectI:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectU:
			case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureGather2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffset2DRectShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DRectShadowF:
				return 4u;

			default:
				return InvalidComponentCount;
			}
		}

		bool needsAlias( expr::Kind kind
			, bool uniform
			, bool param )
		{
			using expr::Kind;
			return ( uniform || kind != Kind::eIdentifier )
				&& ( param || kind != Kind::eMbrSelect )
				&& ( param || kind != Kind::eLiteral )
				&& ( param || kind != Kind::eSwizzle );
		}

		bool isShaderVariable( expr::Expr const & expr )
		{
			return expr.getKind() == expr::Kind::eIdentifier
				&& ( static_cast< expr::Identifier const & >( expr ).getVariable()->isUniform()
					|| static_cast< expr::Identifier const & >( expr ).getVariable()->isShaderInput()
					|| static_cast< expr::Identifier const & >( expr ).getVariable()->isShaderOutput() );
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

		expr::ExprPtr makeOne( type::TypesCache & cache
			, type::Kind scalarType )
		{
			switch ( scalarType )
			{
			case ast::type::Kind::eInt8:
				return ast::expr::makeLiteral( cache, int8_t( 1 ) );
			case ast::type::Kind::eInt16:
				return ast::expr::makeLiteral( cache, int16_t( 1 ) );
			case ast::type::Kind::eInt32:
				return ast::expr::makeLiteral( cache, 1 );
			case ast::type::Kind::eInt64:
				return ast::expr::makeLiteral( cache, 1ll );
			case ast::type::Kind::eUInt8:
				return ast::expr::makeLiteral( cache, uint8_t( 1u ) );
			case ast::type::Kind::eUInt16:
				return ast::expr::makeLiteral( cache, uint16_t( 1u ) );
			case ast::type::Kind::eUInt32:
				return ast::expr::makeLiteral( cache, 1u );
			case ast::type::Kind::eUInt64:
				return ast::expr::makeLiteral( cache, 1ull );
			case ast::type::Kind::eFloat:
				return ast::expr::makeLiteral( cache, 1.0f );
			case ast::type::Kind::eDouble:
				return ast::expr::makeLiteral( cache, 1.0 );
			default:
				AST_Failure( "Unsupported scalar type for literal creation." );
				return nullptr;
			}
		}

		expr::ExprPtr makeOne( type::TypePtr type )
		{
			return makeOne( type->getCache(), type->getKind() );
		}

		expr::ExprPtr makeZero( type::TypesCache & cache
			, type::Kind scalarType )
		{
			switch ( scalarType )
			{
			case ast::type::Kind::eInt8:
				return ast::expr::makeLiteral( cache, int8_t( 0 ) );
			case ast::type::Kind::eInt16:
				return ast::expr::makeLiteral( cache, int16_t( 0 ) );
			case ast::type::Kind::eInt32:
				return ast::expr::makeLiteral( cache, 0 );
			case ast::type::Kind::eInt64:
				return ast::expr::makeLiteral( cache, 0ll );
			case ast::type::Kind::eUInt8:
				return ast::expr::makeLiteral( cache, uint8_t( 0u ) );
			case ast::type::Kind::eUInt16:
				return ast::expr::makeLiteral( cache, uint16_t( 0u ) );
			case ast::type::Kind::eUInt32:
				return ast::expr::makeLiteral( cache, 0u );
			case ast::type::Kind::eUInt64:
				return ast::expr::makeLiteral( cache, 0ull );
			case ast::type::Kind::eFloat:
				return ast::expr::makeLiteral( cache, 0.0f );
			case ast::type::Kind::eDouble:
				return ast::expr::makeLiteral( cache, 0.0 );
			default:
				AST_Failure( "Unsupported scalar type for literal creation." );
				return nullptr;
			}
		}

		ast::expr::ExprPtr makeToBoolCast( ast::type::TypesCache & cache
			, ast::expr::ExprPtr expr )
		{
			auto componentCount = getComponentCount( expr->getType()->getKind() );
			ast::expr::ExprPtr result;
			auto type = expr->getType()->getKind();

			if ( componentCount == 1u )
			{
				result = ast::expr::makeNotEqual( cache
					, std::move( expr )
					, makeZero( cache, type ) );
			}
			else
			{
				ast::expr::ExprList args;
				auto newExpr = std::move( expr );

				for ( auto i = 0u; i < componentCount; ++i )
				{
					args.emplace_back( ast::expr::makeNotEqual( cache
						, ast::expr::makeSwizzle( ast::ExprCloner::submit( newExpr.get() ), ast::expr::SwizzleKind::fromOffset( i ) )
						, makeZero( cache, type ) ) );
				}

				result = ast::expr::makeCompositeConstruct( ast::expr::CompositeType( componentCount )
					, ast::type::Kind::eBoolean
					, std::move( args ) );
			}

			return result;
		}

		ast::expr::ExprPtr makeFromBoolCast( ast::type::TypesCache & cache
			, ast::expr::ExprPtr expr
			, ast::type::Kind dstScalarType )
		{
			auto componentCount = getComponentCount( expr->getType()->getKind() );
			ast::expr::ExprPtr result;

			if ( componentCount == 1u )
			{
				auto scalarType = cache.getBasicType( dstScalarType );
				result = ast::expr::makeQuestion( scalarType
					, std::move( expr )
					, makeOne( cache, dstScalarType )
					, makeZero( cache, dstScalarType ) );
			}
			else
			{
				ast::expr::ExprList args;
				auto newExpr = std::move( expr );
				auto scalarType = cache.getBasicType( dstScalarType );

				for ( auto i = 0u; i < componentCount; ++i )
				{
					args.emplace_back( ast::expr::makeQuestion( scalarType
						, ast::expr::makeSwizzle( ast::ExprCloner::submit( newExpr.get() ), ast::expr::SwizzleKind::fromOffset( i ) )
						, makeOne( cache, dstScalarType )
						, makeZero( cache, dstScalarType ) ) );
				}

				result = ast::expr::makeCompositeConstruct( ast::expr::CompositeType( componentCount )
					, dstScalarType
					, std::move( args ) );
			}

			return result;
		}

		class ExprSSAiser
			: public expr::SimpleVisitor
		{
		public:
			static expr::ExprPtr submit( expr::Expr * expr
				, type::TypesCache & cache
				, stmt::Container * container
				, bool isParam
				, SSAData & data )
			{
				expr::ExprPtr result;
				ExprSSAiser vis{ data, cache, container, isParam, result };
				expr->accept( &vis );

				if ( expr->isNonUniform() )
				{
					result->updateFlag( ast::expr::Flag::eNonUniform );
				}

				return result;
			}

		private:
			ExprSSAiser( SSAData & data
				, type::TypesCache & cache
				, stmt::Container * container
				, bool isParam
				, expr::ExprPtr & result )
				: SimpleVisitor{}
				, m_data{ data }
				, m_cache{ cache }
				, m_container{ container }
				, m_isParam{ isParam }
				, m_result{ result }
			{
			}

		protected:
			void visitUnaryExpr( expr::Unary * expr )override
			{
				switch ( expr->getKind() )
				{
				case expr::Kind::eCopy:
					m_result = std::make_unique< ast::expr::Copy >( doSubmit( expr->getOperand() ) );
					break;
				case expr::Kind::eBitNot:
					doProcessUnExprT< expr::BitNot >( expr );
					break;
				case expr::Kind::eLogNot:
					doProcessUnExprT< expr::LogNot >( expr );
					break;
				case expr::Kind::ePostDecrement:
					doProcessPrePostIncDecExprT< expr::Minus >( expr, false );
					break;
				case expr::Kind::ePostIncrement:
					doProcessPrePostIncDecExprT< expr::Add >( expr, false );
					break;
				case expr::Kind::ePreDecrement:
					doProcessPrePostIncDecExprT< expr::Minus >( expr, true );
					break;
				case expr::Kind::ePreIncrement:
					doProcessPrePostIncDecExprT< expr::Add >( expr, true );
					break;
				case expr::Kind::eUnaryMinus:
					m_result = expr::makeUnaryMinus( doSubmit( expr->getOperand() ) );
					break;
				case expr::Kind::eUnaryPlus:
					m_result = doSubmit( expr->getOperand() );
					break;
				default:
					AST_Failure( "Unexpected unary expression type" );
					break;
				}

				if ( expr->getOperand()->isNonUniform() )
				{
					m_result->updateFlag( ast::expr::Flag::eNonUniform );
				}
			}

			void visitBinaryExpr( expr::Binary * expr )override
			{
				switch ( expr->getKind() )
				{
				case expr::Kind::eArrayAccess:
					doProcessBinExprT< expr::ArrayAccess >( expr );
					break;
				case expr::Kind::eAssign:
					doProcessBinExprT< expr::Assign >( expr );
					break;
				case expr::Kind::eComma:
					doProcessBinExprT< expr::Assign >( expr );
					break;
				case expr::Kind::eModulo:
					doProcessBinExprT< expr::Modulo >( expr );
					break;
				case expr::Kind::eLShift:
					doProcessBinExprT< expr::LShift >( expr );
					break;
				case expr::Kind::eRShift:
					doProcessBinExprT< expr::RShift >( expr );
					break;
				case expr::Kind::eBitAnd:
					doProcessBinExprT< expr::BitAnd >( expr );
					break;
				case expr::Kind::eBitOr:
					doProcessBinExprT< expr::BitOr >( expr );
					break;
				case expr::Kind::eBitXor:
					doProcessBinExprT< expr::BitXor >( expr );
					break;
				case expr::Kind::eLogAnd:
					doProcessBinExprT< expr::LogAnd >( expr );
					break;
				case expr::Kind::eLogOr:
					doProcessBinExprT< expr::LogOr >( expr );
					break;
				case expr::Kind::eEqual:
					doProcessBinExprT< expr::Equal >( expr );
					break;
				case expr::Kind::eGreater:
					doProcessBinExprT< expr::Greater >( expr );
					break;
				case expr::Kind::eGreaterEqual:
					doProcessBinExprT< expr::GreaterEqual >( expr );
					break;
				case expr::Kind::eLess:
					doProcessBinExprT< expr::Less >( expr );
					break;
				case expr::Kind::eLessEqual:
					doProcessBinExprT< expr::LessEqual >( expr );
					break;
				case expr::Kind::eNotEqual:
					doProcessBinExprT< expr::NotEqual >( expr );
					break;
				case expr::Kind::eModuloAssign:
					doProcessAssignBinExprT< expr::Modulo >( expr );
					break;
				case expr::Kind::eLShiftAssign:
					doProcessAssignBinExprT< expr::LShift >( expr );
					break;
				case expr::Kind::eRShiftAssign:
					doProcessAssignBinExprT< expr::RShift >( expr );
					break;
				case expr::Kind::eAndAssign:
					doProcessAssignBinExprT< expr::BitAnd >( expr );
					break;
				case expr::Kind::eNotAssign:
					doProcessAssignUnExprT< expr::BitNot >( expr );
					break;
				case expr::Kind::eOrAssign:
					doProcessAssignBinExprT< expr::BitOr >( expr );
					break;
				case expr::Kind::eXorAssign:
					doProcessAssignBinExprT< expr::BitXor >( expr );
					break;
				default:
					AST_Failure( "Unexpected binary expression type" );
					break;
				}

				if ( expr->getLHS()->isNonUniform()
					|| expr->getRHS()->isNonUniform() )
				{
					m_result->updateFlag( ast::expr::Flag::eNonUniform );
				}
			}

			void visitAddAssignExpr( expr::AddAssign * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eAdd
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
				m_result = expr::makeAssign( expr->getType()
					, doSubmit( expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitAddExpr( expr::Add * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eAdd
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
			}

			void visitCastExpr( ast::expr::Cast * expr )override
			{
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
					m_result = makeToBoolCast( m_cache
						, doSubmit( expr->getOperand() ) );
				}
				else if ( srcScalarType == ast::type::Kind::eBoolean
					&& dstScalarType != ast::type::Kind::eBoolean )
				{
					// Conversion from bool scalar or vector type.
					assert( dstComponents == srcComponents );
					m_result = makeFromBoolCast( m_cache
						, doSubmit( expr->getOperand() )
						, dstScalarType );
				}
				else
				{
					m_result = expr::makeCast( expr->getType()
						, doSubmit( expr->getOperand() ) );
				}
			}

			void visitDivideAssignExpr( expr::DivideAssign * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eDivide
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
				m_result = expr::makeAssign( expr->getType()
					, doSubmit( expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitDivideExpr( expr::Divide * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eDivide
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
			}

			void visitMinusAssignExpr( expr::MinusAssign * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eMinus
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
				m_result = expr::makeAssign( expr->getType()
					, doSubmit( expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitMinusExpr( expr::Minus * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eMinus
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
			}

			void visitTimesAssignExpr( expr::TimesAssign * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eTimes
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
				m_result = expr::makeAssign( expr->getType()
					, doSubmit( expr->getLHS() )
					, std::move( m_result ) );
			}

			void visitTimesExpr( expr::Times * expr )override
			{
				m_result = doWriteBinaryOperation( expr::Kind::eTimes
					, expr->getType()
					, expr->getLHS()
					, expr->getRHS() );
			}

			void visitAggrInitExpr( expr::AggrInit * expr )override
			{
				expr::ExprList initialisers;

				for ( auto & init : expr->getInitialisers() )
				{
					initialisers.push_back( doSubmit( init.get() ) );
					assert( initialisers.back() );
				}

				if ( expr->getIdentifier() )
				{
					m_result = expr::makeAggrInit( expr::makeIdentifier( m_cache, expr->getIdentifier()->getVariable() )
						, std::move( initialisers ) );
				}
				else
				{
					m_result = expr::makeAggrInit( expr->getType()
						, std::move( initialisers ) );
				}
			}

			void visitCompositeConstructExpr( expr::CompositeConstruct * expr )override
			{
				ast::expr::ExprList args;

				if ( expr->getArgList().size() == 1u
					&& !isScalarType( expr->getArgList().front()->getType()->getKind() ) )
				{
					auto & arg = *expr->getArgList().front();
					auto argType = arg.getType();
					ast::var::VariablePtr alias;
					ast::expr::ExprPtr argAlias;
					doMakeAlias( doSubmit( &arg ), false, argAlias, alias );

					if ( isVectorType( argType->getKind() ) )
					{
						doConstructVector( expr
							, argAlias
							, expr->getType()->getKind()
							, args );
					}
					else if ( isMatrixType( argType->getKind() ) )
					{
						doConstructMatrix( expr
							, argAlias
							, expr->getType()->getKind()
							, args );
					}
					else
					{
						// TODO: Struct or array.
					}
				}
				else 
				{
					doConstructOther( expr, args );
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

			void visitFnCallExpr( expr::FnCall * expr )override
			{
				ast::expr::ExprList args;

				struct OutputParam
				{
					ast::expr::ExprPtr param;
					ast::var::VariablePtr alias;
				};
				std::vector< OutputParam > outputParams;
				auto fnType = std::static_pointer_cast< ast::type::Function >( expr->getFn()->getType() );
				auto it = fnType->begin();

				for ( auto & arg : expr->getArgList() )
				{
					auto kind = getNonArrayKind( arg->getType() );
					auto param = *( it++ );

					if ( isOpaqueType( kind ) )
					{
						if ( arg->getKind() == ast::expr::Kind::eArrayAccess )
						{
							ast::var::VariablePtr alias;
							auto newExpr = doSubmit( arg.get() );
							ast::expr::ExprPtr aliasExpr;

							if ( doMakeAlias( std::move( newExpr ), true, aliasExpr, alias ) )
							{
								auto argIdent = findIdentifier( arg, kind, ast::var::Flag::eUniform );

								if ( argIdent )
								{
									// For samplers and imges, the eUniform flag from the function parameter must be removed,
									// since the alias can't have it.
									param->updateFlag( ast::var::Flag::eUniform, false );
									//// Then the eConstant flag must be added, to match
									//auto aliaIdent
									//( aliasExpr )->getVariable()->updateFlag( ast::var::Flag::eConstant, true );
								}
							}

							args.emplace_back( std::move( aliasExpr ) );

							if ( param->isOutputParam()
								&& alias )
							{
								outputParams.push_back( { doSubmit( arg.get() ), alias } );
							}
						}
						else
						{
							// Images/Samplers/Textures are uniform constant pointers.
							args.emplace_back( doSubmit( arg.get() ) );
						}
					}
					else
					{
						ast::expr::ExprPtr aliasExpr;
						ast::var::VariablePtr alias;
						doMakeAlias( doSubmit( arg.get() ), true, aliasExpr, alias );
						args.emplace_back( std::move( aliasExpr ) );

						if ( param->isOutputParam()
							&& alias )
						{
							outputParams.push_back( { doSubmit( arg.get() ), alias } );
						}
					}
				}

				if ( expr->isMember() )
				{
					m_result = ast::expr::makeMemberFnCall( expr->getType()
						, std::make_unique< ast::expr::Identifier >( *expr->getFn() )
						, doSubmit( expr->getInstance() )
						, std::move( args ) );
				}
				else
				{
					m_result = ast::expr::makeFnCall( expr->getType()
						, std::make_unique< ast::expr::Identifier >( *expr->getFn() )
						, std::move( args ) );
				}

				if ( expr->getType()->getKind() != ast::type::Kind::eVoid )
				{
					// Store function result into a return alias, that will be the final result.
					auto var = doCreateAliasVar( expr->getType()
						, std::move( m_result ) );
					m_result = ast::expr::makeIdentifier( m_cache, var );
				}
				else
				{
					doAddStmt( ast::stmt::makeSimple( std::move( m_result ) ) );
				}

				for ( auto & var : outputParams )
				{
					doAddStmt( ast::stmt::makeSimple( ast::expr::makeAssign( var.alias->getType()
						, std::move( var.param )
						, ast::expr::makeIdentifier( m_cache, var.alias ) ) ) );
				}
			}

			void visitIdentifierExpr( expr::Identifier * expr )override
			{
				m_result = expr::makeIdentifier( expr->getCache()
					, expr->getVariable() );
			}

			void visitImageAccessCallExpr( expr::ImageAccessCall * expr )override
			{
				ast::expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( arg.get() ) );
				}

				auto dstType = expr->getType();
				auto srcType = getExpectedReturnType( expr );
				m_result = ast::expr::makeImageAccessCall( srcType
					, expr->getImageAccess()
					, std::move( args ) );

				if ( srcType != dstType )
				{
					assert( ast::type::getScalarType( srcType->getKind() ) == ast::type::getScalarType( dstType->getKind() ) );
					auto dstCount = ast::type::getComponentCount( dstType );

					if ( dstCount == 1u )
					{
						m_result = ast::expr::makeSwizzle( std::move( m_result )
							, ast::expr::SwizzleKind::e0 );
					}
					else if ( dstCount == 2u )
					{
						m_result = ast::expr::makeSwizzle( std::move( m_result )
							, ast::expr::SwizzleKind::e01 );
					}
					else if ( dstCount == 3u )
					{
						m_result = ast::expr::makeSwizzle( std::move( m_result )
							, ast::expr::SwizzleKind::e012 );
					}
				}

				if ( srcType->getKind() != ast::type::Kind::eVoid )
				{
					auto type = m_result->getType();
					auto alias = doCreateAliasVar( type
						, std::move( m_result ) );
					m_result = ast::expr::makeIdentifier( m_cache, alias );
				}
			}

			void visitInitExpr( expr::Init * expr )override
			{
				if ( expr->getInitialiser()->isConstant() )
				{
					m_result = expr::makeInit( expr::makeIdentifier( m_cache, expr->getIdentifier()->getVariable() )
						, doSubmit( expr->getInitialiser() ) );
				}
				else
				{
					expr::ExprPtr aliasExpr;
					var::VariablePtr alias;
					doMakeAlias( doSubmit( expr->getInitialiser() )
						, m_isParam
						, aliasExpr
						, alias );
					m_result = expr::makeInit( expr::makeIdentifier( m_cache, expr->getIdentifier()->getVariable() )
						, std::move( aliasExpr ) );
				}
			}

			void visitIntrinsicCallExpr( expr::IntrinsicCall * expr )override
			{
				auto intrinsic = expr->getIntrinsic();

				if ( intrinsic >= expr::Intrinsic::eMatrixCompMult2x2F
					&& intrinsic <= expr::Intrinsic::eMatrixCompMult4x4D )
				{
					assert( expr->getArgList().size() == 2u );
					m_result = doWriteMatrixBinaryOperation( expr::Kind::eTimes
						, expr->getType()
						, expr->getArgList()[0].get()
						, expr->getArgList()[1].get() );
				}
				else
				{
					expr::ExprList args;

					for ( auto & arg : expr->getArgList() )
					{
						args.emplace_back( doSubmit( arg ) );
					}

					m_result = expr::makeIntrinsicCall( expr->getType()
						, expr->getIntrinsic()
						, std::move( args ) );
				}
			}

			void visitLiteralExpr( expr::Literal * expr )override
			{
				m_result = std::make_unique< expr::Literal >( *expr );
			}

			void visitMbrSelectExpr( expr::MbrSelect * expr )override
			{
				m_result = expr::makeMbrSelect( doSubmit( expr->getOuterExpr() )
					, expr->getMemberIndex()
					, expr->getMemberFlags() );
			}

			void visitQuestionExpr( expr::Question * expr )override
			{
				auto condComponents = getComponentCount( expr->getCtrlExpr()->getType()->getKind() );
				auto opsComponents = getComponentCount( expr->getTrueExpr()->getType()->getKind() );

				if ( condComponents == opsComponents )
				{
					m_result = expr::makeQuestion( expr->getType()
						, doSubmit( expr->getCtrlExpr() )
						, doSubmit( expr->getTrueExpr() )
						, doSubmit( expr->getFalseExpr() ) );
				}
				else
				{
					assert( condComponents == 1u );
					ast::expr::ExprList args;
					expr::ExprPtr argAlias;
					ast::var::VariablePtr alias;
					doMakeAlias( doSubmit( expr->getCtrlExpr() )
						, false
						, argAlias
						, alias );
					args.emplace_back( std::move( argAlias ) );
					m_result = ast::expr::makeQuestion( expr->getType()
						, doSubmit( ast::expr::makeCompositeConstruct( getCompositeType( opsComponents )
							, expr->getCtrlExpr()->getType()->getKind()
							, std::move( args ) ).get() )
						, doSubmit( expr->getTrueExpr() )
						, doSubmit( expr->getFalseExpr() ) );
				}
			}

			void visitStreamAppendExpr( expr::StreamAppend * expr )override
			{
				m_result = expr::makeStreamAppend( doSubmit( expr->getOperand() ) );
			}

			void visitSwitchCaseExpr( expr::SwitchCase * expr )override
			{
				m_result = expr::makeSwitchCase( std::make_unique< expr::Literal >( *expr->getLabel() ) );
			}

			void visitSwitchTestExpr( expr::SwitchTest * expr )override
			{
				m_result = expr::makeSwitchTest( doSubmit( expr->getValue() ) );
			}

			void visitSwizzleExpr( expr::Swizzle * expr )override
			{
				auto outerComponentsCount = getComponentCount( expr->getOuterExpr()->getType()->getKind() );
				auto innerComponentsCount = getComponentCount( expr->getType()->getKind() );
				m_result = doSubmit( expr->getOuterExpr() );

				// Remove unnecessary swizzles
				if ( outerComponentsCount != innerComponentsCount
					|| ( expr->getSwizzle() != ast::expr::SwizzleKind::e0
						&& expr->getSwizzle() != ast::expr::SwizzleKind::e01
						&& expr->getSwizzle() != ast::expr::SwizzleKind::e012
						&& expr->getSwizzle() != ast::expr::SwizzleKind::e0123 ) )
				{
					m_result = expr::makeSwizzle( std::move( m_result )
						, expr->getSwizzle() );
				}
			}

			void visitCombinedImageAccessCallExpr( expr::CombinedImageAccessCall * expr )override
			{
				auto kind = expr->getCombinedImageAccess();
				auto returnComponentsCount = getReturnComponentCount( kind );
				auto returnType = expr->getType();
				auto count = getComponentCount( returnType->getKind() );

				if ( returnComponentsCount != InvalidComponentCount && returnComponentsCount != count )
				{
					assert( returnComponentsCount > count );
					returnType = m_cache.getVector( getScalarType( returnType->getKind() ), returnComponentsCount );
				}

				ast::expr::ExprList args;

				for ( auto & arg : expr->getArgList() )
				{
					args.emplace_back( doSubmit( arg ) );
				}

				m_result = ast::expr::makeCombinedImageAccessCall( returnType
						, kind
						, std::move( args ) );

				if ( returnComponentsCount != InvalidComponentCount && returnComponentsCount != count )
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
					case 4:
						swizzleKind = ast::expr::SwizzleKind::e0123;
						break;
					}

					m_result = ast::expr::makeSwizzle( std::move( m_result ), swizzleKind );
				}

				auto type = m_result->getType();
				auto alias = doCreateAliasVar( type
					, std::move( m_result ) );
				m_result = ast::expr::makeIdentifier( m_cache, alias );
			}

		private:
			var::VariablePtr doCreateVar( type::TypePtr type
				, expr::ExprPtr aliasedExpr
				, uint64_t flags )
			{
				auto kind = getNonArrayKind( type );
				auto result = var::makeVariable( ++m_data.nextVarId
					, type
					, "tmp_" + std::to_string( ++m_data.aliasId )
					, ( var::Flag::eImplicit
						| var::Flag::eLocale
						| flags ) );

				if ( isOpaqueType( kind ) )
				{
					result->updateFlag( var::Flag::eConstant );
					result->updateFlag( var::Flag::eUniform );
				}

				if ( flags & uint64_t( var::Flag::eAlias ) )
				{
					doAddStmt( stmt::makeSimple( expr::makeAlias( result->getType()
						, expr::makeIdentifier( m_cache, result )
						, std::move( aliasedExpr ) ) ) );
				}
				else
				{
					doAddStmt( stmt::makeSimple( expr::makeInit( expr::makeIdentifier( m_cache, result )
						, std::move( aliasedExpr ) ) ) );
				}

				return result;
			}

			var::VariablePtr doCreateAliasVar( type::TypePtr type
				, expr::ExprPtr aliasedExpr )
			{
				return doCreateVar( type
					, std::move( aliasedExpr )
					, ( var::Flag::eTemp | var::Flag::eAlias ) );
			}

			bool doMakeAlias( expr::ExprPtr expr
				, bool param
				, expr::ExprPtr & aliasExpr
				, var::VariablePtr & alias
				, bool force = false )
			{
				if ( expr->getKind() == ast::expr::Kind::eIdentifier
					&& static_cast< ast::expr::Identifier const & >( *expr ).getVariable()->isAlias() )
				{
					aliasExpr = std::move( expr );
					return false;
				}

				auto kind = getNonArrayKind( expr->getType() );

				if ( !force
					&& ( isOpaqueType( kind )
						|| !needsAlias( expr->getKind()
							, isShaderVariable( *expr )
							, param ) ) )
				{
					aliasExpr = std::move( expr );
					return false;
				}

				auto type = expr->getType();
				alias = doCreateAliasVar( type
					, std::move( expr ) );
				aliasExpr = expr::makeIdentifier( m_cache, alias );
				return true;
			}

			expr::ExprPtr doSubmit( expr::Expr * expr )
			{
				return submit( expr, m_cache, m_container, m_isParam, m_data );
			}

			expr::ExprPtr doSubmit( expr::ExprPtr const & expr )
			{
				return doSubmit( expr.get() );
			}

			template< typename ExprT >
			void doProcessAssignBinExprT( expr::Binary * expr )
			{
				expr::ExprPtr aliasExpr;
				var::VariablePtr alias;
				auto lhs = doSubmit( expr->getLHS() );
				doMakeAlias( std::make_unique< ExprT >( expr->getType()
					, doSubmit( lhs )
					, doSubmit( expr->getRHS() ) )
					, false
					, aliasExpr
					, alias
					, true );
				doAddStmt( stmt::makeSimple( expr::makeAssign( lhs->getType()
					, doSubmit( lhs )
					, std::move( aliasExpr ) ) ) );
				m_result = std::move( lhs );
			}

			template< typename ExprT >
			void doProcessAssignUnExprT( expr::Binary * expr )
			{
				expr::ExprPtr aliasExpr;
				var::VariablePtr alias;
				auto lhs = doSubmit( expr->getLHS() );
				doMakeAlias( std::make_unique< ExprT >( expr->getType()
					, doSubmit( expr->getLHS() ) )
					, false
					, aliasExpr
					, alias
					, true );
				doAddStmt( stmt::makeSimple( expr::makeAssign( lhs->getType()
					, doSubmit( lhs )
					, std::move( aliasExpr ) ) ) );
				m_result = std::move( lhs );
			}

			template< typename ExprT >
			void doProcessBinExprT( expr::Binary * expr )
			{
				m_result = std::make_unique< ExprT >( expr->getType()
					, doSubmit( expr->getLHS() )
					, doSubmit( expr->getRHS() ) );
			}

			template< typename ExprT >
			void doProcessUnExprT( expr::Unary * expr )
			{
				m_result = std::make_unique< ExprT >( expr->getType()
					, doSubmit( expr->getOperand() ) );
			}

			template< typename ExprT >
			void doProcessPrePostIncDecExprT( expr::Unary * expr
				, bool isPre )
			{
				var::VariablePtr opAlias;
				auto lhs = doSubmit( expr->getOperand() );

				if ( !isPre )
				{
					opAlias = doCreateVar( expr->getType()
						, doSubmit( lhs )
						, uint32_t( var::Flag::eTemp ) );
				}

				expr::ExprPtr aliasExpr;
				var::VariablePtr alias;
				doMakeAlias( std::make_unique< ExprT >( expr->getType()
					, doSubmit( lhs )
					, makeOne( expr->getType() ) )
					, false
					, aliasExpr
					, alias
					, true );
				doAddStmt( stmt::makeSimple( expr::makeAssign( lhs->getType()
					, doSubmit( lhs )
					, std::move( aliasExpr ) ) ) );

				if ( isPre )
				{
					m_result = std::move( lhs );
				}
				else
				{
					m_result = expr::makeIdentifier( m_cache, opAlias );
				}
			}

			type::TypePtr doPromoteScalar( expr::ExprPtr & lhs
				, expr::ExprPtr & rhs )
			{
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
						expr::ExprList args;
						auto count = getComponentCount( result->getKind() );
						expr::ExprPtr alias;
						var::VariablePtr aliasVar;
						doMakeAlias( doSubmit( lhs.get() ), false, alias, aliasVar );

						for ( auto i = 0u; i < count; ++i )
						{
							args.emplace_back( doSubmit( alias.get() ) );
						}

						lhs = expr::makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
							, args.back()->getType()->getKind()
							, std::move( args ) );
					}
					else if ( rhsScalar )
					{
						result = lhs->getType();
						expr::ExprList args;
						auto count = getComponentCount( result->getKind() );
						expr::ExprPtr alias;
						var::VariablePtr aliasVar;
						doMakeAlias( doSubmit( rhs.get() ), false, alias, aliasVar );

						for ( auto i = 0u; i < count; ++i )
						{
							args.emplace_back( doSubmit( alias.get() ) );
						}

						rhs = expr::makeCompositeConstruct( getCompositeType( getComponentCount( result->getKind() ) )
							, args.back()->getType()->getKind()
							, std::move( args ) );
					}
				}

				return result;
			}

			expr::ExprPtr doWriteBinaryOperation( expr::Kind operation
				, type::TypePtr resType
				, expr::Expr * lhs
				, expr::Expr * rhs )
			{
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
				expr::ExprPtr result;

				if ( lhsMat || rhsMat )
				{
					if ( forceRhsType )
					{
						type = resType;
					}

					expr::ExprList args;
					var::VariablePtr lhsAlias, rhsAlias;
					doMakeAlias( std::move( lhsExpr ), false, lhsExpr, lhsAlias );
					doMakeAlias( std::move( rhsExpr ), false, rhsExpr, rhsAlias );

					switch ( operation )
					{
					case expr::Kind::eAdd:
					case expr::Kind::eDivide:
					case expr::Kind::eMinus:
						result = doWriteMatrixBinaryOperation( operation
							, resType
							, lhsExpr.get()
							, rhsExpr.get() );
						break;
					case expr::Kind::eTimes:
						result = expr::makeTimes( type
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
						result = expr::makeAdd( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eDivide:
						result = expr::makeDivide( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eMinus:
						result = expr::makeMinus( type
							, std::move( lhsExpr )
							, std::move( rhsExpr ) );
						break;
					case expr::Kind::eTimes:
						result = expr::makeTimes( type
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

			expr::ExprPtr doWriteMatrixBinaryOperation( expr::Kind operation
				, type::TypePtr resType
				, expr::Expr * lhs
				, expr::Expr * rhs )
			{
				// one time set up...
				auto lhsType = lhs->getType();
				auto rhsType = rhs->getType();
				bool lhsMat = isMatrixType( lhsType->getKind() );
				bool rhsMat = isMatrixType( rhsType->getKind() );
				auto lhsColumns = getComponentCount( lhsType->getKind() );
				auto rhsColumns = getComponentCount( rhsType->getKind() );
				auto lhsRows = getComponentCount( getComponentType( lhsType->getKind() ) );
				auto rhsRows = getComponentCount( getComponentType( rhsType->getKind() ) );
				auto numCols = lhsMat ? lhsColumns : rhsColumns;
				auto numRows = lhsMat ? lhsRows : rhsRows;
				auto scalarType = getScalarType( resType->getKind() );
				auto vecType = m_cache.getVector( scalarType, numRows );
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

				expr::ExprPtr smearVec;

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
						smearVec = expr::makeCompositeConstruct( composite
							, lhsType->getKind()
							, std::move( params ) );
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
						smearVec = expr::makeCompositeConstruct( composite
							, rhsType->getKind()
							, std::move( params ) );
					}
				}

				expr::ExprList args;

				// do each vector op
				for ( unsigned int c = 0; c < numCols; ++c )
				{
					std::vector<unsigned int> indexes;
					indexes.push_back( c );
					auto lhsVec = lhsMat
						? expr::makeArrayAccess( vecType, doSubmit( lhs ), expr::makeLiteral( m_cache, c ) )
						: ExprCloner::submit( smearVec.get() );
					auto rhsVec = rhsMat
						? expr::makeArrayAccess( vecType, doSubmit( rhs ), expr::makeLiteral( m_cache, c ) )
						: ExprCloner::submit( smearVec.get() );

					switch ( operation )
					{
					case expr::Kind::eAdd:
						args.emplace_back( expr::makeAdd( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					case expr::Kind::eDivide:
						args.emplace_back( expr::makeDivide( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					case expr::Kind::eMinus:
						args.emplace_back( expr::makeMinus( vecType
							, std::move( lhsVec )
							, std::move( rhsVec ) ) );
						break;
					case expr::Kind::eTimes:
						args.emplace_back( expr::makeTimes( vecType
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
					case 4:
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
					case 4:
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
					case 4:
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
					case 4:
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
					return expr::makeCompositeConstruct( composite
						, scalarType
						, std::move( args ) );
				}

				assert( args.size() == 1u );
				return std::move( args[0] );
			}

			void doConstructVector( ast::expr::CompositeConstruct * expr
				, ast::expr::ExprPtr const & newArg
				, ast::type::Kind destKind
				, ast::expr::ExprList & args )
			{
				auto count = getComponentCount( destKind );

				for ( auto i = 0u; i < count; ++i )
				{
					args.emplace_back( ast::expr::makeSwizzle( doSubmit( newArg.get() )
						, ast::expr::SwizzleKind::fromOffset( i ) ) );
				}

				if ( newArg->getType()->getKind() != expr->getType()->getKind() )
				{
					auto dstType = m_cache.getBasicType( getScalarType( expr->getType()->getKind() ) );

					for ( auto & arg : args )
					{
						arg = doSubmit( ast::expr::makeCast( dstType
							, std::move( arg ) ).get() );
					}
				}
			}

			void doConstructMatrix( ast::expr::CompositeConstruct * expr
				, ast::expr::ExprPtr const & newArg
				, ast::type::Kind destKind
				, ast::expr::ExprList & args )
			{
				auto scalarType = getScalarType( destKind );
				auto srcColumnCount = getComponentCount( newArg->getType()->getKind() );
				auto srcRowCount = getComponentCount( getComponentType( newArg->getType()->getKind() ) );
				auto dstColumnCount = getComponentCount( destKind );
				auto dstRowCount = getComponentCount( getComponentType( destKind ) );
				auto minColumnCount = std::min( srcColumnCount, dstColumnCount );

				for ( auto col = 0u; col < minColumnCount; ++col )
				{
					auto arrayAccess = ast::expr::makeArrayAccess( m_cache.getVector( scalarType, srcRowCount )
						, doSubmit( newArg.get() )
						, ast::expr::makeLiteral( m_cache, col ) );

					if ( dstRowCount < srcRowCount )
					{
						args.emplace_back( ast::expr::makeSwizzle( std::move( arrayAccess )
							, getSwizzleComponents( dstRowCount ) ) );
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
								compositeArgs.emplace_back( makeOne( m_cache, scalarType ) );
							}
							else
							{
								compositeArgs.emplace_back( makeZero( m_cache, scalarType ) );
							}
						}

						args.emplace_back( ast::expr::makeCompositeConstruct( getCompositeType( dstRowCount )
							, scalarType
							, std::move( compositeArgs ) ) );
					}
				}

				for ( auto col = minColumnCount; col < dstColumnCount; ++col )
				{
				}
			}

			void doConstructOther( ast::expr::CompositeConstruct * expr
				, ast::expr::ExprList & args )
			{
				auto scalarType = expr->getComponent();

				for ( auto & arg : expr->getArgList() )
				{
					auto newArg = doSubmit( arg.get() );

					if ( isScalarType( newArg->getType()->getKind() ) )
					{
						auto argTypeKind = getScalarType( newArg->getType()->getKind() );

						if ( argTypeKind != scalarType )
						{
							newArg = ast::expr::makeCast( m_cache.getBasicType( scalarType )
								, std::move( newArg ) );
						}
					}

					args.emplace_back( std::move( newArg ) );
				}
			}

			void doAddStmt( stmt::StmtPtr stmt )
			{
				if ( stmt->getKind() == stmt::Kind::eSimple )
				{
					auto expr = static_cast< stmt::Simple const & >( *stmt ).getExpr();

					if ( expr->getKind() == expr::Kind::eIdentifier )
					{
						return;
					}
				}

				m_container->addStmt( std::move( stmt ) );
			}

		private:
			SSAData & m_data;
			type::TypesCache & m_cache;
			stmt::Container * m_container;
			bool m_isParam;
			expr::ExprPtr & m_result;
		};

		class StmtSSAiser
			: public StmtCloner
		{
		public:
			static stmt::ContainerPtr submit( stmt::Container * stmt
				, type::TypesCache & cache
				, SSAData & data )
			{
				stmt::ContainerPtr result = stmt::makeContainer();
				StmtSSAiser vis{ data, cache, result };
				stmt->accept( &vis );
				return result;
			}

		private:
			StmtSSAiser( SSAData & data
				, type::TypesCache & cache
				, stmt::ContainerPtr & result )
				: StmtCloner{ result }
				, m_data{ data }
				, m_cache{ cache }
			{
			}

		protected:
			expr::ExprPtr doSubmit( expr::Expr * expr )override
			{
				return ExprSSAiser::submit( expr
					, m_cache
					, m_current
					, false
					, m_data );
			}

			void visitElseIfStmt( ast::stmt::ElseIf * stmt )override
			{
				AST_Failure( "Unexpected ElseIf statement." );
			}

			void visitElseStmt( ast::stmt::Else * stmt )override
			{
				AST_Failure( "Unexpected Else statement." );
			}

			void visitIfStmt( ast::stmt::If * stmt )override
			{
				auto save = m_current;
				auto ctrlExpr = doSubmit( stmt->getCtrlExpr() );
				auto & cache = ctrlExpr->getCache();
				auto scalarType = getScalarType( ctrlExpr->getType()->getKind() );
				auto cont = ast::stmt::makeIf( ( scalarType != ast::type::Kind::eBoolean )
					? makeToBoolCast( cache, std::move( ctrlExpr ) )
					: std::move( ctrlExpr ) );
				m_current = cont.get();
				visitContainerStmt( stmt );
				m_current = save;
				auto currentIf = cont.get();
				m_current->addStmt( std::move( cont ) );

				// Replace all else ifs by the following :
				// Origin:
				// if (condA){}
				// else if (condB){}
				// else{}
				//
				// Result:
				// if (condA){}
				// else
				// {
				//   if (condB){}
				//   else{}
				// }
				if ( stmt->getElse()
					|| !stmt->getElseIfList().empty() )
				{
					auto & elseIfs = stmt->getElseIfList();
					auto it = elseIfs.begin();

					while ( it != elseIfs.end() )
					{
						auto elseStmt = currentIf->createElse();
						m_current = elseStmt;
						auto & elseIf = *it;
						ctrlExpr = doSubmit( elseIf->getCtrlExpr() );
						scalarType = getScalarType( ctrlExpr->getType()->getKind() );
						cont = ast::stmt::makeIf( ( scalarType != ast::type::Kind::eBoolean )
							? makeToBoolCast( cache, std::move( ctrlExpr ) )
							: std::move( ctrlExpr ) );
						m_current = cont.get();
						visitContainerStmt( elseIf.get() );
						m_current = save;
						currentIf = cont.get();
						elseStmt->addStmt( std::move( cont ) );
						++it;
					}

					if ( stmt->getElse() )
					{
						auto elseStmt = currentIf->createElse();
						m_current = elseStmt;
						visitContainerStmt( stmt->getElse() );
						m_current = save;
					}
				}
			}

			void visitForStmt( stmt::For * stmt )override
			{
				auto block = stmt::makeCompound();
				auto save = m_current;
				m_current = block.get();
				m_current->addStmt( stmt::makeSimple( doSubmit( stmt->getInitExpr() ) ) );
				auto ifStmt = stmt::makeIf( doSubmit( stmt->getCtrlExpr() ) );
				{
					// Do ... while content
					auto doWhileContent = stmt::makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
					auto save2 = m_current;
					m_current = doWhileContent.get();
					visitContainerStmt( stmt );
					doAddStmt( stmt::makeSimple( doSubmit( stmt->getIncrExpr() ) ) );
					m_current = save2;
					ifStmt->addStmt( std::move( doWhileContent ) );
				}
				m_current->addStmt( std::move( ifStmt ) );
				m_current = save;
				m_current->addStmt( std::move( block ) );
			}

			void visitWhileStmt( stmt::While * stmt )override
			{
				auto ifStmt = stmt::makeIf( doSubmit( stmt->getCtrlExpr() ) );
				{
					// Do ... while content
					auto doWhileContent = stmt::makeDoWhile( doSubmit( stmt->getCtrlExpr() ) );
					auto save = m_current;
					m_current = doWhileContent.get();
					visitContainerStmt( stmt );
					m_current = save;
					ifStmt->addStmt( std::move( doWhileContent ) );
				}
				m_current->addStmt( std::move( ifStmt ) );
			}

			void visitFragmentLayoutStmt( stmt::FragmentLayout * stmt )override
			{
				m_fragmentLayoutStmt = stmt;
			}

			void visitOutputGeometryLayoutStmt( stmt::OutputGeometryLayout * stmt )override
			{
				m_outputGeometryLayoutStmt = stmt;
			}

			void visitInputGeometryLayoutStmt( stmt::InputGeometryLayout * stmt )override
			{
				m_inputGeometryLayoutStmt = stmt;
			}

			void visitOutputTessellationControlLayoutStmt( stmt::OutputTessellationControlLayout * stmt )override
			{
				m_outputTessCtrlLayoutStmt = stmt;
			}

			void visitInputTessellationEvaluationLayoutStmt( stmt::InputTessellationEvaluationLayout * stmt )override
			{
				m_intputTessEvalLayoutStmt = stmt;
			}

			void visitFunctionDeclStmt( stmt::FunctionDecl * stmt )override
			{
				if ( stmt->isEntryPoint() )
				{
					if ( stmt->getType()->size() < 2u
						&& ( m_outputGeometryLayoutStmt || m_inputGeometryLayoutStmt ) )
					{
						auto funcType = stmt->getType();
						auto & cache = funcType->getCache();
						auto inType = type::makeGeometryInputType( m_inputGeometryLayoutStmt->getType()
							, m_inputGeometryLayoutStmt->getLayout() );
						auto outType = type::makeGeometryOutputType( m_outputGeometryLayoutStmt->getType()
							, m_outputGeometryLayoutStmt->getLayout()
							, m_outputGeometryLayoutStmt->getPrimCount() );
						var::VariableList parameters;
						parameters.push_back( var::makeVariable( EntityName{ ++m_data.nextVarId, "geomData" }
							, inType
							, var::Flag::eInputParam | var::Flag::eShaderInput ) );
						parameters.push_back( var::makeVariable( EntityName{ ++m_data.nextVarId, "geomStream" }
							, outType
							, var::Flag::eInputParam | var::Flag::eOutputParam | var::Flag::eShaderOutput ) );

						funcType = cache.getFunction( funcType->getReturnType()
							, std::move( parameters ) );
						auto save = m_current;
						auto cont = stmt::makeFunctionDecl( funcType
							, stmt->getName()
							, stmt->getFlags() );
						m_current = cont.get();
						visitContainerStmt( stmt );
						m_current = save;
						m_current->addStmt( std::move( cont ) );
					}
					else
					{
						StmtCloner::visitFunctionDeclStmt( stmt );
					}
				}
				else
				{
					StmtCloner::visitFunctionDeclStmt( stmt );
				}
			}

		private:
			void doAddStmt( stmt::StmtPtr stmt )
			{
				if ( stmt->getKind() == stmt::Kind::eSimple )
				{
					auto expr = static_cast< stmt::Simple const & >( *stmt ).getExpr();

					if ( expr->getKind() == expr::Kind::eIdentifier )
					{
						return;
					}
				}

				m_current->addStmt( std::move( stmt ) );
			}

		private:
			SSAData & m_data;
			type::TypesCache & m_cache;
			stmt::FragmentLayout * m_fragmentLayoutStmt{};
			stmt::OutputGeometryLayout * m_outputGeometryLayoutStmt{};
			stmt::InputGeometryLayout * m_inputGeometryLayoutStmt{};
			stmt::OutputTessellationControlLayout * m_outputTessCtrlLayoutStmt{};
			stmt::InputTessellationEvaluationLayout * m_intputTessEvalLayoutStmt{};
		};
	}

	stmt::ContainerPtr transformSSA( type::TypesCache & cache
		, stmt::Container * container
		, SSAData & ssaData )
	{
		return StmtSSAiser::submit( container, cache, ssaData );
	}
}
