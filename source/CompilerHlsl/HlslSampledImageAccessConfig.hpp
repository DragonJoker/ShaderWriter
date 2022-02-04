/*
See LICENSE file in root folder
*/
#ifndef ___AST_HlslSampledImageAccessConfig_H___
#define ___AST_HlslSampledImageAccessConfig_H___
#pragma once

#include "HlslHelpers.hpp"

#include <ShaderAST/Expr/EnumSampledImageAccess.hpp>

#include <stdexcept>

namespace hlsl
{
	inline void getHlslConfig( ast::expr::SampledImageAccess value
		, IntrinsicsConfig & config )
	{
		switch ( value )
		{
		case ast::expr::SampledImageAccess::eSample1DShadowF:
		case ast::expr::SampledImageAccess::eSample1DShadowFBias:
		case ast::expr::SampledImageAccess::eSample2DShadowF:
		case ast::expr::SampledImageAccess::eSample2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleCubeShadowF:
		case ast::expr::SampledImageAccess::eSampleCubeShadowFBias:
		case ast::expr::SampledImageAccess::eSample1DArrayShadowF:
		case ast::expr::SampledImageAccess::eSample1DArrayShadowFBias:
		case ast::expr::SampledImageAccess::eSample2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSample2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleCubeArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProj2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleLod1DShadowF:
		case ast::expr::SampledImageAccess::eSampleLod2DShadowF:
		case ast::expr::SampledImageAccess::eSampleLod1DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleOffset1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleOffset2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleOffset1DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleOffset2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleLodOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleLodOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleLodOffset1DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLod1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLod2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectShadowF:
			config.requiresShadowSampler = true;
			config.requiresShadowOnTiled = ( value == ast::expr::SampledImageAccess::eSampleCubeShadowF
				|| value == ast::expr::SampledImageAccess::eSampleCubeShadowFBias
				|| value == ast::expr::SampledImageAccess::eSampleCubeArrayShadowF
				|| value == ast::expr::SampledImageAccess::eSampleGatherCubeShadowF
				|| value == ast::expr::SampledImageAccess::eSampleGatherCubeArrayShadowF
				|| value == ast::expr::SampledImageAccess::eSampleLod1DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleLod2DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleLod1DArrayShadowF
				|| value == ast::expr::SampledImageAccess::eSampleLodOffset1DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleLodOffset2DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleLodOffset1DArrayShadowF
				|| value == ast::expr::SampledImageAccess::eSampleProjLod1DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleProjLod2DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleProjLodOffset1DShadowF
				|| value == ast::expr::SampledImageAccess::eSampleProjLodOffset2DShadowF );
			break;

		case ast::expr::SampledImageAccess::eSampleGrad1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DShadowF:
		case ast::expr::SampledImageAccess::eSampleGrad1DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGradOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleGradOffset1DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleGrad2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGrad2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DArrayShadowF:
			throw std::runtime_error{ "Unsupported grad shadow" };

		case ast::expr::SampledImageAccess::eSample1DI:
		case ast::expr::SampledImageAccess::eSample1DIBias:
		case ast::expr::SampledImageAccess::eSample2DI:
		case ast::expr::SampledImageAccess::eSample2DIBias:
		case ast::expr::SampledImageAccess::eSample3DI:
		case ast::expr::SampledImageAccess::eSample3DIBias:
		case ast::expr::SampledImageAccess::eSampleCubeI:
		case ast::expr::SampledImageAccess::eSampleCubeIBias:
		case ast::expr::SampledImageAccess::eSample1DArrayI:
		case ast::expr::SampledImageAccess::eSample1DArrayIBias:
		case ast::expr::SampledImageAccess::eSample2DArrayI:
		case ast::expr::SampledImageAccess::eSample2DArrayIBias:
		case ast::expr::SampledImageAccess::eSampleCubeArrayI:
		case ast::expr::SampledImageAccess::eSampleCubeArrayIBias:
		case ast::expr::SampledImageAccess::eSample2DRectI:
		case ast::expr::SampledImageAccess::eSample1DU:
		case ast::expr::SampledImageAccess::eSample1DUBias:
		case ast::expr::SampledImageAccess::eSample2DU:
		case ast::expr::SampledImageAccess::eSample2DUBias:
		case ast::expr::SampledImageAccess::eSample3DU:
		case ast::expr::SampledImageAccess::eSample3DUBias:
		case ast::expr::SampledImageAccess::eSampleCubeU:
		case ast::expr::SampledImageAccess::eSampleCubeUBias:
		case ast::expr::SampledImageAccess::eSample1DArrayU:
		case ast::expr::SampledImageAccess::eSample1DArrayUBias:
		case ast::expr::SampledImageAccess::eSample2DArrayU:
		case ast::expr::SampledImageAccess::eSample2DArrayUBias:
		case ast::expr::SampledImageAccess::eSampleCubeArrayU:
		case ast::expr::SampledImageAccess::eSampleCubeArrayUBias:
		case ast::expr::SampledImageAccess::eSample2DRectU:
		case ast::expr::SampledImageAccess::eSampleProj1DI2:
		case ast::expr::SampledImageAccess::eSampleProj1DI2Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DI4:
		case ast::expr::SampledImageAccess::eSampleProj1DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DI3:
		case ast::expr::SampledImageAccess::eSampleProj2DI3Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DI4:
		case ast::expr::SampledImageAccess::eSampleProj2DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProj3DI:
		case ast::expr::SampledImageAccess::eSampleProj3DIBias:
		case ast::expr::SampledImageAccess::eSampleProj2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProj1DU2:
		case ast::expr::SampledImageAccess::eSampleProj1DU2Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DU4:
		case ast::expr::SampledImageAccess::eSampleProj1DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DU3:
		case ast::expr::SampledImageAccess::eSampleProj2DU3Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DU4:
		case ast::expr::SampledImageAccess::eSampleProj2DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProj3DU:
		case ast::expr::SampledImageAccess::eSampleProj3DUBias:
		case ast::expr::SampledImageAccess::eSampleProj2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectU4:
		case ast::expr::SampledImageAccess::eSampleLod1DI:
		case ast::expr::SampledImageAccess::eSampleLod2DI:
		case ast::expr::SampledImageAccess::eSampleLod3DI:
		case ast::expr::SampledImageAccess::eSampleLodCubeI:
		case ast::expr::SampledImageAccess::eSampleLod1DArrayI:
		case ast::expr::SampledImageAccess::eSampleLod2DArrayI:
		case ast::expr::SampledImageAccess::eSampleLodCubeArrayI:
		case ast::expr::SampledImageAccess::eSampleLod1DU:
		case ast::expr::SampledImageAccess::eSampleLod2DU:
		case ast::expr::SampledImageAccess::eSampleLod3DU:
		case ast::expr::SampledImageAccess::eSampleLodCubeU:
		case ast::expr::SampledImageAccess::eSampleLod1DArrayU:
		case ast::expr::SampledImageAccess::eSampleLod2DArrayU:
		case ast::expr::SampledImageAccess::eSampleLodCubeArrayU:
		case ast::expr::SampledImageAccess::eSampleOffset1DI:
		case ast::expr::SampledImageAccess::eSampleOffset1DIBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DI:
		case ast::expr::SampledImageAccess::eSampleOffset2DIBias:
		case ast::expr::SampledImageAccess::eSampleOffset3DI:
		case ast::expr::SampledImageAccess::eSampleOffset3DIBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DRectI:
		case ast::expr::SampledImageAccess::eSampleOffset1DArrayI:
		case ast::expr::SampledImageAccess::eSampleOffset1DArrayIBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DArrayI:
		case ast::expr::SampledImageAccess::eSampleOffset2DArrayIBias:
		case ast::expr::SampledImageAccess::eSampleOffset1DU:
		case ast::expr::SampledImageAccess::eSampleOffset1DUBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DU:
		case ast::expr::SampledImageAccess::eSampleOffset2DUBias:
		case ast::expr::SampledImageAccess::eSampleOffset3DU:
		case ast::expr::SampledImageAccess::eSampleOffset3DUBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DRectU:
		case ast::expr::SampledImageAccess::eSampleOffset1DArrayU:
		case ast::expr::SampledImageAccess::eSampleOffset1DArrayUBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DArrayU:
		case ast::expr::SampledImageAccess::eSampleOffset2DArrayUBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI4:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DI:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DIBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU4:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU4:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU4Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DU:
		case ast::expr::SampledImageAccess::eSampleProjOffset3DUBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectU4:
		case ast::expr::SampledImageAccess::eSampleLodOffset1DI:
		case ast::expr::SampledImageAccess::eSampleLodOffset2DI:
		case ast::expr::SampledImageAccess::eSampleLodOffset3DI:
		case ast::expr::SampledImageAccess::eSampleLodOffset1DArrayI:
		case ast::expr::SampledImageAccess::eSampleLodOffset2DArrayI:
		case ast::expr::SampledImageAccess::eSampleLodOffset1DU:
		case ast::expr::SampledImageAccess::eSampleLodOffset2DU:
		case ast::expr::SampledImageAccess::eSampleLodOffset3DU:
		case ast::expr::SampledImageAccess::eSampleLodOffset1DArrayU:
		case ast::expr::SampledImageAccess::eSampleLodOffset2DArrayU:
		case ast::expr::SampledImageAccess::eSampleProjLod1DI2:
		case ast::expr::SampledImageAccess::eSampleProjLod1DI4:
		case ast::expr::SampledImageAccess::eSampleProjLod2DI3:
		case ast::expr::SampledImageAccess::eSampleProjLod2DI4:
		case ast::expr::SampledImageAccess::eSampleProjLod3DI:
		case ast::expr::SampledImageAccess::eSampleProjLod1DU2:
		case ast::expr::SampledImageAccess::eSampleProjLod1DU4:
		case ast::expr::SampledImageAccess::eSampleProjLod2DU3:
		case ast::expr::SampledImageAccess::eSampleProjLod2DU4:
		case ast::expr::SampledImageAccess::eSampleProjLod3DU:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DI4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DI4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset3DI:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DU4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DU4:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset3DU:
		case ast::expr::SampledImageAccess::eSampleGrad1DI:
		case ast::expr::SampledImageAccess::eSampleGrad2DI:
		case ast::expr::SampledImageAccess::eSampleGrad3DI:
		case ast::expr::SampledImageAccess::eSampleGradCubeI:
		case ast::expr::SampledImageAccess::eSampleGrad2DRectI:
		case ast::expr::SampledImageAccess::eSampleGrad1DArrayI:
		case ast::expr::SampledImageAccess::eSampleGrad2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGradCubeArrayI:
		case ast::expr::SampledImageAccess::eSampleGrad1DU:
		case ast::expr::SampledImageAccess::eSampleGrad2DU:
		case ast::expr::SampledImageAccess::eSampleGrad3DU:
		case ast::expr::SampledImageAccess::eSampleGradCubeU:
		case ast::expr::SampledImageAccess::eSampleGrad2DRectU:
		case ast::expr::SampledImageAccess::eSampleGrad1DArrayU:
		case ast::expr::SampledImageAccess::eSampleGrad2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGradCubeArrayU:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DI2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DI4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DI3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DI4:
		case ast::expr::SampledImageAccess::eSampleProjGrad3DI:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DU2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DU4:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DU4:
		case ast::expr::SampledImageAccess::eSampleProjGrad3DU:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectU4:
		case ast::expr::SampledImageAccess::eSampleGradOffset1DI:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DI:
		case ast::expr::SampledImageAccess::eSampleGradOffset3DI:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DRectI:
		case ast::expr::SampledImageAccess::eSampleGradOffset1DArrayI:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGradOffset1DU:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DU:
		case ast::expr::SampledImageAccess::eSampleGradOffset3DU:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DRectU:
		case ast::expr::SampledImageAccess::eSampleGradOffset1DArrayU:
		case ast::expr::SampledImageAccess::eSampleGradOffset2DArrayU:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DI4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DI4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset3DI:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectI4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DU4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DU4:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset3DU:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectU4:
			throw std::runtime_error{ "Unsupported non-float texture sampling" };
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::SampledImageAccess::eSample1DShadowFBias:
		case ast::expr::SampledImageAccess::eSample2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleCubeShadowFBias:
		case ast::expr::SampledImageAccess::eSample1DArrayShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleOffset1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleOffset2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowFBias:
			config.requiresShadowOnTiled = true;
			break;
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::SampledImageAccess::eSampleGather2DF:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayF:
		case ast::expr::SampledImageAccess::eSampleGather2DRectF:
		case ast::expr::SampledImageAccess::eSampleGather2DI:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGatherCubeI:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayI:
		case ast::expr::SampledImageAccess::eSampleGather2DRectI:
		case ast::expr::SampledImageAccess::eSampleGather2DU:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGatherCubeU:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayU:
		case ast::expr::SampledImageAccess::eSampleGather2DRectU:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DI:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectI:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DU:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectU:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DI:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayI:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectI:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DU:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayU:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectU:
		case ast::expr::SampledImageAccess::eSampleGather2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherCubeArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGather2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DArrayShadowF:
		case ast::expr::SampledImageAccess::eSampleGatherOffsets2DRectShadowF:
			config.requiresGather = true;
			break;
		default:
			break;
		}

		switch ( value )
		{
		case ast::expr::SampledImageAccess::eSampleProj1DF2:
		case ast::expr::SampledImageAccess::eSampleProj1DI2:
		case ast::expr::SampledImageAccess::eSampleProj1DU2:
		case ast::expr::SampledImageAccess::eSampleProj1DF2Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DI2Bias:
		case ast::expr::SampledImageAccess::eSampleProj1DU2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DF2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DF2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DI2Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DU2Bias:
		case ast::expr::SampledImageAccess::eSampleProjLod1DF2:
		case ast::expr::SampledImageAccess::eSampleProjLod1DI2:
		case ast::expr::SampledImageAccess::eSampleProjLod1DU2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DF2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DF2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DI2:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DU2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DF2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DI2:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DU2:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProj1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset1DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjLod1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad1DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset1DShadowF:
			config.requiresProjectTexCoords2 = true;
			break;

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
			config.requiresProjectTexCoords4To1 = true;
			break;

		case ast::expr::SampledImageAccess::eSampleProj2DF3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProj2DI3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProj2DU3:
		case ast::expr::SampledImageAccess::eSampleProj2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProj2DF3Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DI3Bias:
		case ast::expr::SampledImageAccess::eSampleProj2DU3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DF3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DF3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DI3Bias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DU3Bias:
		case ast::expr::SampledImageAccess::eSampleProjLod2DF3:
		case ast::expr::SampledImageAccess::eSampleProjLod2DI3:
		case ast::expr::SampledImageAccess::eSampleProjLod2DU3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DF3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DF3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DI3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DF3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectF3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DI3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectI3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DU3:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectU3:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProj2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProj2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProjOffset2DShadowFBias:
		case ast::expr::SampledImageAccess::eSampleProjLod2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjLodOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGrad2DRectShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DShadowF:
		case ast::expr::SampledImageAccess::eSampleProjGradOffset2DRectShadowF:
			config.requiresProjectTexCoords3 = true;
			break;

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
			config.requiresProjectTexCoords4To2 = true;
			break;

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
			config.requiresProjectTexCoords4 = true;
			break;

		default:
			break;
		}
	}
}

#endif
