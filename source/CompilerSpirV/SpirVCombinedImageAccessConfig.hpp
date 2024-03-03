/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvTextureAccessConfig_H___
#define ___SDW_SpirvTextureAccessConfig_H___
#pragma once

#include "SpirVHelpers.hpp"

#include <ShaderAST/Expr/EnumCombinedImageAccess.hpp>

#include <string>
#include <stdexcept>

namespace spirv
{
	inline spv::ImageOperandsMask getLod( ast::expr::CombinedImageAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
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
		case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
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
		case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTexelFetch1DF:
		case ast::expr::CombinedImageAccess::eTexelFetch2DF:
		case ast::expr::CombinedImageAccess::eTexelFetch3DF:
		case ast::expr::CombinedImageAccess::eTexelFetch1DArrayF:
		case ast::expr::CombinedImageAccess::eTexelFetch2DArrayF:
		case ast::expr::CombinedImageAccess::eTexelFetch1DI:
		case ast::expr::CombinedImageAccess::eTexelFetch2DI:
		case ast::expr::CombinedImageAccess::eTexelFetch3DI:
		case ast::expr::CombinedImageAccess::eTexelFetch1DArrayI:
		case ast::expr::CombinedImageAccess::eTexelFetch2DArrayI:
		case ast::expr::CombinedImageAccess::eTexelFetch1DU:
		case ast::expr::CombinedImageAccess::eTexelFetch2DU:
		case ast::expr::CombinedImageAccess::eTexelFetch3DU:
		case ast::expr::CombinedImageAccess::eTexelFetch1DArrayU:
		case ast::expr::CombinedImageAccess::eTexelFetch2DArrayU:
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
			result = spv::ImageOperandsLodMask;
			break;
		default:
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getGrad( ast::expr::CombinedImageAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
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
		case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
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
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
			result = spv::ImageOperandsGradMask;
			break;
		default:
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getOffset( ast::expr::CombinedImageAccess value
		, bool constOffset )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
	// Texel Lookup Functions
		case ast::expr::CombinedImageAccess::eTextureOffset1DF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DI:
		case ast::expr::CombinedImageAccess::eTextureOffset1DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DU:
		case ast::expr::CombinedImageAccess::eTextureOffset1DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureOffset3DUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayUBias:
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
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DI:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DU:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DUBias:
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
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
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
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
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
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
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
			result = spv::ImageOperandsConstOffsetMask;
			break;
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
			if ( constOffset )
			{
				result = spv::ImageOperandsConstOffsetMask;
			}
			else
			{
				result = spv::ImageOperandsOffsetMask;
			}
			break;
		default:
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getConstOffsets( ast::expr::CombinedImageAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			result = spv::ImageOperandsConstOffsetsMask;
			break;
		default:
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getBias( ast::expr::CombinedImageAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
	// Texture Query Functions
		case ast::expr::CombinedImageAccess::eTexture1DFBias:
		case ast::expr::CombinedImageAccess::eTexture2DFBias:
		case ast::expr::CombinedImageAccess::eTexture3DFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeFBias:
		case ast::expr::CombinedImageAccess::eTexture1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayFBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayFBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayFBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayShadowFBias:
		case ast::expr::CombinedImageAccess::eTexture1DIBias:
		case ast::expr::CombinedImageAccess::eTexture2DIBias:
		case ast::expr::CombinedImageAccess::eTexture3DIBias:
		case ast::expr::CombinedImageAccess::eTextureCubeIBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayIBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayIBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayIBias:
		case ast::expr::CombinedImageAccess::eTexture1DUBias:
		case ast::expr::CombinedImageAccess::eTexture2DUBias:
		case ast::expr::CombinedImageAccess::eTexture3DUBias:
		case ast::expr::CombinedImageAccess::eTextureCubeUBias:
		case ast::expr::CombinedImageAccess::eTexture1DArrayUBias:
		case ast::expr::CombinedImageAccess::eTexture2DArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureCubeArrayUBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
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
		case ast::expr::CombinedImageAccess::eTextureProj1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DI4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DIBias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU2Bias:
		case ast::expr::CombinedImageAccess::eTextureProj1DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU3Bias:
		case ast::expr::CombinedImageAccess::eTextureProj2DU4Bias:
		case ast::expr::CombinedImageAccess::eTextureProj3DUBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset3DFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
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
			result = spv::ImageOperandsBiasMask;
			break;
		default:
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getMask( ast::expr::CombinedImageAccess value
		, bool constOffset )
	{
		return getBias( value )
			| getOffset( value, constOffset )
			| getConstOffsets( value )
			| getGrad( value )
			| getLod( value );
	}

	inline spv::ImageOperandsMask getMask( ast::expr::CombinedImageAccess value )
	{
		return getBias( value )
			| getGrad( value )
			| getLod( value );
	}

	inline void getSpirVConfig( ast::expr::CombinedImageAccess value
		, IntrinsicConfig & config )
	{
		config.imageOperandsIndex = 0u;
		config.offsetIndex = 0u;
		config.needsImage = false;
		config.mask = getMask( value );
		config.returnComponentsCount = InvalidComponentCount;

		switch ( value )
		{
	// Texture Query Functions
		case ast::expr::CombinedImageAccess::eTextureSize1DF:
		case ast::expr::CombinedImageAccess::eTextureSize2DF:
		case ast::expr::CombinedImageAccess::eTextureSize3DF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeF:
		case ast::expr::CombinedImageAccess::eTextureSize1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureSize1DI:
		case ast::expr::CombinedImageAccess::eTextureSize2DI:
		case ast::expr::CombinedImageAccess::eTextureSize3DI:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeI:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureSize1DU:
		case ast::expr::CombinedImageAccess::eTextureSize2DU:
		case ast::expr::CombinedImageAccess::eTextureSize3DU:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeU:
		case ast::expr::CombinedImageAccess::eTextureSizeCubeArrayU:
		case ast::expr::CombinedImageAccess::eTextureSize1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureSize2DArrayU:
			config.needsImage = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureSizeBufferF:
		case ast::expr::CombinedImageAccess::eTextureSizeBufferI:
		case ast::expr::CombinedImageAccess::eTextureSizeBufferU:
			config.needsImage = true;
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLod1DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod3DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLod2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLodCubeArrayU:
			break;

		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayI:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels3DU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels1DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevels2DArrayU:
		case ast::expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU:
			config.needsImage = true;
			break;


	// Texel Lookup Functions
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
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			break;

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
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			config.needsImage = true;
			break;

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
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			config.offsetIndex = config.imageOperandsIndex;
			break;

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
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			config.needsImage = true;
			config.offsetIndex = config.imageOperandsIndex;
			break;

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
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			config.offsetIndex = config.imageOperandsIndex + 1u;
			break;

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
		case ast::expr::CombinedImageAccess::eTextureGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProj2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjGrad1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGrad2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLod2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodCubeArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLod2DShadowF:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			break;

		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureOffset2DShadowFBias:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			config.offsetIndex = config.imageOperandsIndex;
			break;

		case ast::expr::CombinedImageAccess::eTextureGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			config.offsetIndex = config.imageOperandsIndex + 1u;
			break;

	// Texture Gather Functions
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
		case ast::expr::CombinedImageAccess::eTextureGather2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGather2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 3u;
			break;

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
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 3u;
			config.offsetIndex = config.imageOperandsIndex + 1u;
			break;

		default:
			throw ast::Exception{ "Unsupported CombinedImageAccess type." };
		}
	}
}

#endif
