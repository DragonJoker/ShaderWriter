/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprSampledImageAccessCall.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	//*********************************************************************************************

	SampledImageAccessCall::SampledImageAccessCall( type::TypePtr type
		, SampledImageAccess sampledImageAccess
		, ExprList && argList )
		: Expr{ getExprTypesCache( argList ), std::move( type ), Kind::eSampledImageAccessCall, Flag::eNone }
		, m_sampledImageAccess{ sampledImageAccess }
		, m_argList{ std::move( argList ) }
	{
	}

	void SampledImageAccessCall::accept( VisitorPtr vis )
	{
		vis->visitSampledImageAccessCallExpr( this );
	}

	//*********************************************************************************************

	bool isBiasAndOffset( SampledImageAccess value )
	{
		switch ( value )
		{
		case SampledImageAccess::eSampleOffset1DFBias:
		case SampledImageAccess::eSampleOffset2DFBias:
		case SampledImageAccess::eSampleOffset3DFBias:
		case SampledImageAccess::eSampleOffset1DArrayFBias:
		case SampledImageAccess::eSampleOffset2DArrayFBias:
		case SampledImageAccess::eSampleOffset1DIBias:
		case SampledImageAccess::eSampleOffset2DIBias:
		case SampledImageAccess::eSampleOffset3DIBias:
		case SampledImageAccess::eSampleOffset1DArrayIBias:
		case SampledImageAccess::eSampleOffset2DArrayIBias:
		case SampledImageAccess::eSampleOffset1DUBias:
		case SampledImageAccess::eSampleOffset2DUBias:
		case SampledImageAccess::eSampleOffset3DUBias:
		case SampledImageAccess::eSampleOffset1DArrayUBias:
		case SampledImageAccess::eSampleOffset2DArrayUBias:
		case SampledImageAccess::eSampleProjOffset1DF2Bias:
		case SampledImageAccess::eSampleProjOffset1DF4Bias:
		case SampledImageAccess::eSampleProjOffset2DF3Bias:
		case SampledImageAccess::eSampleProjOffset2DF4Bias:
		case SampledImageAccess::eSampleProjOffset3DFBias:
		case SampledImageAccess::eSampleProjOffset1DI2Bias:
		case SampledImageAccess::eSampleProjOffset1DI4Bias:
		case SampledImageAccess::eSampleProjOffset2DI3Bias:
		case SampledImageAccess::eSampleProjOffset2DI4Bias:
		case SampledImageAccess::eSampleProjOffset3DIBias:
		case SampledImageAccess::eSampleProjOffset1DU2Bias:
		case SampledImageAccess::eSampleProjOffset1DU4Bias:
		case SampledImageAccess::eSampleProjOffset2DU3Bias:
		case SampledImageAccess::eSampleProjOffset2DU4Bias:
		case SampledImageAccess::eSampleProjOffset3DUBias:
			return true;
		default:
			return false;
		}
	}

	bool isProj( ast::expr::SampledImageAccess value )
	{
		switch ( value )
		{
		case ast::expr::SampledImageAccess::eSampleProj1DF2:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProj1DI2:
		case ast::expr::SampledImageAccess::eSampleProj1DU2:
		case ast::expr::SampledImageAccess::eSampleProj1DF2Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProj1DI2Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DU2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DF2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DF2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU2Bias:
		case ast::expr::SampledImageAccess::eSampleProjLod1DF2:
		case ast::expr::SampledImageAccess::eSampleProjLod1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLod1DI2:
		case ast::expr::SampledImageAccess::eSampleProjLod1DU2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DF2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DF2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DI2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DU2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DF2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProj1DF4:
		case ast::expr::SampledImageAccess::eSampleProj1DI4:
		case ast::expr::SampledImageAccess::eSampleProj1DU4:
		case ast::expr::SampledImageAccess::eSampleProj1DF4Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DF4:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI4:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU4:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DF4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProjLod1DF4:
		case ast::expr::SampledImageAccess::eSampleProjLod1DI4:
		case ast::expr::SampledImageAccess::eSampleProjLod1DU4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DF4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DI4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DU4:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DF4:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DI4:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DU4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DF4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DI4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DU4:
		case ast::expr::SampledImageAccess::eSampleProj2DF3:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProj2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProj2DI3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProj2DU3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProj2DF3Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProj2DI3Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DU3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DF3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DF3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU3Bias:
		case ast::expr::SampledImageAccess::eSampleProjLod2DF3:
		case ast::expr::SampledImageAccess::eSampleProjLod2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLod2DI3:
		case ast::expr::SampledImageAccess::eSampleProjLod2DU3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DF3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DF3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DI3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DF3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProj2DF4:
		case ast::expr::SampledImageAccess::eSampleProj2DRectF4:
		case ast::expr::SampledImageAccess::eSampleProj2DI4:
		case ast::expr::SampledImageAccess::eSampleProj2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProj2DU4:
		case ast::expr::SampledImageAccess::eSampleProj2DRectU4:
		case ast::expr::SampledImageAccess::eSampleProj2DF4Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DF4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectF4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectU4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DF4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProjLod2DF4:
		case ast::expr::SampledImageAccess::eSampleProjLod2DI4:
		case ast::expr::SampledImageAccess::eSampleProjLod2DU4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DF4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DI4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DU4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DF4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectF4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DI4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DU4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectU4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DF4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectF4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DI4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DU4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectU4:
		case ast::expr::SampledImageAccess::eSampleProj3DF:
		case ast::expr::SampledImageAccess::eSampleProj3DI:
		case ast::expr::SampledImageAccess::eSampleProj3DU:
		case ast::expr::SampledImageAccess::eSampleProj3DFBias:
		case ast::expr::SampledImageAccess::eSampleProj3DIBias:
		case ast::expr::SampledImageAccess::eSampleProj3DUBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DF:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DI:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DU:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DIBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DUBias:
		case ast::expr::SampledImageAccess::eSampleProjLod3DF:
		case ast::expr::SampledImageAccess::eSampleProjLod3DI:
		case ast::expr::SampledImageAccess::eSampleProjLod3DU:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset3DF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset3DI:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset3DU:
		case ast::expr::SampledImageAccess::eSampleProjGrad3DF:
		case ast::expr::SampledImageAccess::eSampleProjGrad3DI:
		case ast::expr::SampledImageAccess::eSampleProjGrad3DU:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset3DF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset3DI:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset3DU:
			return true;
		default:
			return false;
		}
	}

	bool isShadow( SampledImageAccess value )
	{
		switch ( value )
		{
		case SampledImageAccess::eSample1DShadowF:
		case SampledImageAccess::eSample1DShadowFBias:
		case SampledImageAccess::eSample2DShadowF:
		case SampledImageAccess::eSample2DShadowFBias:
		case SampledImageAccess::eSampleCubeShadowF:
		case SampledImageAccess::eSampleCubeShadowFBias:
		case SampledImageAccess::eSample1DArrayShadowF:
		case SampledImageAccess::eSample1DArrayShadowFBias:
		case SampledImageAccess::eSample2DArrayShadowF:
		case SampledImageAccess::eSample2DRectShadowF:
		case SampledImageAccess::eSampleCubeArrayShadowF:
		case SampledImageAccess::eSampleProj1DShadowF:
		case SampledImageAccess::eSampleProj1DShadowFBias:
		case SampledImageAccess::eSampleProj2DShadowF:
		case SampledImageAccess::eSampleProj2DShadowFBias:
		case SampledImageAccess::eSampleProj2DRectShadowF:
		case SampledImageAccess::eSampleLod1DShadowF:
		case SampledImageAccess::eSampleLod2DShadowF:
		case SampledImageAccess::eSampleLod1DArrayShadowF:
		case SampledImageAccess::eSampleOffset2DRectShadowF:
		case SampledImageAccess::eSampleOffset1DShadowF:
		case SampledImageAccess::eSampleOffset1DShadowFBias:
		case SampledImageAccess::eSampleOffset2DShadowF:
		case SampledImageAccess::eSampleOffset2DShadowFBias:
		case SampledImageAccess::eSampleOffset1DArrayShadowF:
		case SampledImageAccess::eSampleOffset2DArrayShadowF:
		case SampledImageAccess::eSampleProjOffset1DShadowF:
		case SampledImageAccess::eSampleProjOffset1DShadowFBias:
		case SampledImageAccess::eSampleProjOffset2DShadowF:
		case SampledImageAccess::eSampleProjOffset2DShadowFBias:
		case SampledImageAccess::eSampleProjOffset2DRectShadowF:
		case SampledImageAccess::eSampleLodOffset1DShadowF:
		case SampledImageAccess::eSampleLodOffset2DShadowF:
		case SampledImageAccess::eSampleLodOffset1DArrayShadowF:
		case SampledImageAccess::eSampleProjLod1DShadowF:
		case SampledImageAccess::eSampleProjLod2DShadowF:
		case SampledImageAccess::eSampleProjLodOffset1DShadowF:
		case SampledImageAccess::eSampleProjLodOffset2DShadowF:
		case SampledImageAccess::eSampleGrad2DRectShadowF:
		case SampledImageAccess::eSampleGrad1DShadowF:
		case SampledImageAccess::eSampleGrad2DShadowF:
		case SampledImageAccess::eSampleGrad1DArrayShadowF:
		case SampledImageAccess::eSampleGradOffset2DRectShadowF:
		case SampledImageAccess::eSampleGradOffset1DShadowF:
		case SampledImageAccess::eSampleGradOffset2DShadowF:
		case SampledImageAccess::eSampleGradOffset1DArrayShadowF:
		case SampledImageAccess::eSampleGradOffset2DArrayShadowF:
		case SampledImageAccess::eSampleProjGrad1DShadowF:
		case SampledImageAccess::eSampleProjGrad2DShadowF:
		case SampledImageAccess::eSampleProjGrad2DRectShadowF:
		case SampledImageAccess::eSampleProjGradOffset1DShadowF:
		case SampledImageAccess::eSampleProjGradOffset2DShadowF:
		case SampledImageAccess::eSampleProjGradOffset2DRectShadowF:
		case SampledImageAccess::eSampleGather2DShadowF:
		case SampledImageAccess::eSampleGather2DArrayShadowF:
		case SampledImageAccess::eSampleGatherCubeShadowF:
		case SampledImageAccess::eSampleGatherCubeArrayShadowF:
		case SampledImageAccess::eSampleGather2DRectShadowF:
		case SampledImageAccess::eSampleGatherOffset2DShadowF:
		case SampledImageAccess::eSampleGatherOffset2DArrayShadowF:
		case SampledImageAccess::eSampleGatherOffset2DRectShadowF:
		case SampledImageAccess::eSampleGatherOffsets2DShadowF:
		case SampledImageAccess::eSampleGatherOffsets2DArrayShadowF:
		case SampledImageAccess::eSampleGatherOffsets2DRectShadowF:
			return true;
		default:
			return false;
		}
	}

	bool isShadowLodOffset( SampledImageAccess value )
	{
		switch ( value )
		{
		case SampledImageAccess::eSampleLodOffset1DShadowF:
		case SampledImageAccess::eSampleLodOffset2DShadowF:
		case SampledImageAccess::eSampleLodOffset1DArrayShadowF:
		case SampledImageAccess::eSampleProjLodOffset1DShadowF:
		case SampledImageAccess::eSampleProjLodOffset2DShadowF:
			return true;
		default:
			return false;
		}
	}

	//*********************************************************************************************
}
