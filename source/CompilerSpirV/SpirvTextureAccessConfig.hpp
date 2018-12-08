/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvTextureAccessConfig_H___
#define ___SDW_SpirvTextureAccessConfig_H___
#pragma once

#include "SpirvHelpers.hpp"

#include <ShaderAST/Expr/EnumTextureAccess.hpp>

#include <string>

namespace spirv
{
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

	inline bool hasComp( ast::expr::TextureAccess value )
	{
		bool result{};

		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureGather2DFComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayFComp:
		case ast::expr::TextureAccess::eTextureGather2DRectFComp:
		case ast::expr::TextureAccess::eTextureGather2DIComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayIComp:
		case ast::expr::TextureAccess::eTextureGather2DRectIComp:
		case ast::expr::TextureAccess::eTextureGather2DUComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayUComp:
		case ast::expr::TextureAccess::eTextureGather2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp:
			result = true;
			break;

		default:
			result = false;
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getLod( ast::expr::TextureAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureLod1DF:
		case ast::expr::TextureAccess::eTextureLod2DF:
		case ast::expr::TextureAccess::eTextureLod3DF:
		case ast::expr::TextureAccess::eTextureLodCubeF:
		case ast::expr::TextureAccess::eTextureLod1DArrayF:
		case ast::expr::TextureAccess::eTextureLod2DArrayF:
		case ast::expr::TextureAccess::eTextureLodCubeArrayF:
		case ast::expr::TextureAccess::eTextureLod1DI:
		case ast::expr::TextureAccess::eTextureLod2DI:
		case ast::expr::TextureAccess::eTextureLod3DI:
		case ast::expr::TextureAccess::eTextureLodCubeI:
		case ast::expr::TextureAccess::eTextureLod1DArrayI:
		case ast::expr::TextureAccess::eTextureLod2DArrayI:
		case ast::expr::TextureAccess::eTextureLodCubeArrayI:
		case ast::expr::TextureAccess::eTextureLod1DU:
		case ast::expr::TextureAccess::eTextureLod2DU:
		case ast::expr::TextureAccess::eTextureLod3DU:
		case ast::expr::TextureAccess::eTextureLodCubeU:
		case ast::expr::TextureAccess::eTextureLod1DArrayU:
		case ast::expr::TextureAccess::eTextureLod2DArrayU:
		case ast::expr::TextureAccess::eTextureLodCubeArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset1DF:
		case ast::expr::TextureAccess::eTextureLodOffset2DF:
		case ast::expr::TextureAccess::eTextureLodOffset3DF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureLodOffset1DI:
		case ast::expr::TextureAccess::eTextureLodOffset2DI:
		case ast::expr::TextureAccess::eTextureLodOffset3DI:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset1DU:
		case ast::expr::TextureAccess::eTextureLodOffset2DU:
		case ast::expr::TextureAccess::eTextureLodOffset3DU:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureLod1DShadowF:
		case ast::expr::TextureAccess::eTextureLod2DShadowF:
		case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjLod1DF2:
		case ast::expr::TextureAccess::eTextureProjLod1DF4:
		case ast::expr::TextureAccess::eTextureProjLod2DF3:
		case ast::expr::TextureAccess::eTextureProjLod2DF4:
		case ast::expr::TextureAccess::eTextureProjLod3DF:
		case ast::expr::TextureAccess::eTextureProjLod1DI2:
		case ast::expr::TextureAccess::eTextureProjLod1DI4:
		case ast::expr::TextureAccess::eTextureProjLod2DI3:
		case ast::expr::TextureAccess::eTextureProjLod2DI4:
		case ast::expr::TextureAccess::eTextureProjLod3DI:
		case ast::expr::TextureAccess::eTextureProjLod1DU2:
		case ast::expr::TextureAccess::eTextureProjLod1DU4:
		case ast::expr::TextureAccess::eTextureProjLod2DU3:
		case ast::expr::TextureAccess::eTextureProjLod2DU4:
		case ast::expr::TextureAccess::eTextureProjLod3DU:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTexelFetch1DF:
		case ast::expr::TextureAccess::eTexelFetch2DF:
		case ast::expr::TextureAccess::eTexelFetch3DF:
		case ast::expr::TextureAccess::eTexelFetch1DArrayF:
		case ast::expr::TextureAccess::eTexelFetch2DArrayF:
		case ast::expr::TextureAccess::eTexelFetch1DI:
		case ast::expr::TextureAccess::eTexelFetch2DI:
		case ast::expr::TextureAccess::eTexelFetch3DI:
		case ast::expr::TextureAccess::eTexelFetch1DArrayI:
		case ast::expr::TextureAccess::eTexelFetch2DArrayI:
		case ast::expr::TextureAccess::eTexelFetch1DU:
		case ast::expr::TextureAccess::eTexelFetch2DU:
		case ast::expr::TextureAccess::eTexelFetch3DU:
		case ast::expr::TextureAccess::eTexelFetch1DArrayU:
		case ast::expr::TextureAccess::eTexelFetch2DArrayU:
		case ast::expr::TextureAccess::eTexelFetchOffset1DF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DF:
		case ast::expr::TextureAccess::eTexelFetchOffset3DF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DI:
		case ast::expr::TextureAccess::eTexelFetchOffset3DI:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayI:
		case ast::expr::TextureAccess::eTexelFetchOffset1DU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DU:
		case ast::expr::TextureAccess::eTexelFetchOffset3DU:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayU:
			result = spv::ImageOperandsMask::Lod;
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getGrad( ast::expr::TextureAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureGrad1DF:
		case ast::expr::TextureAccess::eTextureGrad2DF:
		case ast::expr::TextureAccess::eTextureGrad3DF:
		case ast::expr::TextureAccess::eTextureGradCubeF:
		case ast::expr::TextureAccess::eTextureGrad2DRectF:
		case ast::expr::TextureAccess::eTextureGrad1DArrayF:
		case ast::expr::TextureAccess::eTextureGrad2DArrayF:
		case ast::expr::TextureAccess::eTextureGradCubeArrayF:
		case ast::expr::TextureAccess::eTextureGrad1DI:
		case ast::expr::TextureAccess::eTextureGrad2DI:
		case ast::expr::TextureAccess::eTextureGrad3DI:
		case ast::expr::TextureAccess::eTextureGradCubeI:
		case ast::expr::TextureAccess::eTextureGrad2DRectI:
		case ast::expr::TextureAccess::eTextureGrad1DArrayI:
		case ast::expr::TextureAccess::eTextureGrad2DArrayI:
		case ast::expr::TextureAccess::eTextureGradCubeArrayI:
		case ast::expr::TextureAccess::eTextureGrad1DU:
		case ast::expr::TextureAccess::eTextureGrad2DU:
		case ast::expr::TextureAccess::eTextureGrad3DU:
		case ast::expr::TextureAccess::eTextureGradCubeU:
		case ast::expr::TextureAccess::eTextureGrad2DRectU:
		case ast::expr::TextureAccess::eTextureGrad1DArrayU:
		case ast::expr::TextureAccess::eTextureGrad2DArrayU:
		case ast::expr::TextureAccess::eTextureGradCubeArrayU:
		case ast::expr::TextureAccess::eTextureGradOffset1DF:
		case ast::expr::TextureAccess::eTextureGradOffset2DF:
		case ast::expr::TextureAccess::eTextureGradOffset3DF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGradOffset1DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DI:
		case ast::expr::TextureAccess::eTextureGradOffset3DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset1DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DU:
		case ast::expr::TextureAccess::eTextureGradOffset3DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad1DF2:
		case ast::expr::TextureAccess::eTextureProjGrad1DF4:
		case ast::expr::TextureAccess::eTextureProjGrad2DF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DF4:
		case ast::expr::TextureAccess::eTextureProjGrad3DF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGrad1DI2:
		case ast::expr::TextureAccess::eTextureProjGrad1DI4:
		case ast::expr::TextureAccess::eTextureProjGrad2DI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DI4:
		case ast::expr::TextureAccess::eTextureProjGrad3DI:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGrad1DU2:
		case ast::expr::TextureAccess::eTextureProjGrad1DU4:
		case ast::expr::TextureAccess::eTextureProjGrad2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DU4:
		case ast::expr::TextureAccess::eTextureProjGrad3DU:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			result = spv::ImageOperandsMask::Grad;
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getOffset( ast::expr::TextureAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
	// Texel Lookup Functions
		case ast::expr::TextureAccess::eTextureOffset1DF:
		case ast::expr::TextureAccess::eTextureOffset1DFBias:
		case ast::expr::TextureAccess::eTextureOffset2DF:
		case ast::expr::TextureAccess::eTextureOffset2DFBias:
		case ast::expr::TextureAccess::eTextureOffset3DF:
		case ast::expr::TextureAccess::eTextureOffset3DFBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectF:
		case ast::expr::TextureAccess::eTextureOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureOffset1DArrayFBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureOffset2DArrayFBias:
		case ast::expr::TextureAccess::eTextureOffset1DI:
		case ast::expr::TextureAccess::eTextureOffset1DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DI:
		case ast::expr::TextureAccess::eTextureOffset2DIBias:
		case ast::expr::TextureAccess::eTextureOffset3DI:
		case ast::expr::TextureAccess::eTextureOffset3DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectI:
		case ast::expr::TextureAccess::eTextureOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureOffset1DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureOffset2DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset1DU:
		case ast::expr::TextureAccess::eTextureOffset1DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DU:
		case ast::expr::TextureAccess::eTextureOffset2DUBias:
		case ast::expr::TextureAccess::eTextureOffset3DU:
		case ast::expr::TextureAccess::eTextureOffset3DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectU:
		case ast::expr::TextureAccess::eTextureOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureOffset1DArrayUBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureOffset2DArrayUBias:
		case ast::expr::TextureAccess::eTextureGradOffset1DF:
		case ast::expr::TextureAccess::eTextureGradOffset2DF:
		case ast::expr::TextureAccess::eTextureGradOffset3DF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGradOffset1DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DI:
		case ast::expr::TextureAccess::eTextureGradOffset3DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset1DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DU:
		case ast::expr::TextureAccess::eTextureGradOffset3DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DF:
		case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DI:
		case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DU:
		case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DF:
		case ast::expr::TextureAccess::eTextureLodOffset2DF:
		case ast::expr::TextureAccess::eTextureLodOffset3DF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureLodOffset1DI:
		case ast::expr::TextureAccess::eTextureLodOffset2DI:
		case ast::expr::TextureAccess::eTextureLodOffset3DI:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset1DU:
		case ast::expr::TextureAccess::eTextureLodOffset2DU:
		case ast::expr::TextureAccess::eTextureLodOffset3DU:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DF:
		case ast::expr::TextureAccess::eTexelFetchOffset3DF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DRectF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DI:
		case ast::expr::TextureAccess::eTexelFetchOffset3DI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DRectI:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayI:
		case ast::expr::TextureAccess::eTexelFetchOffset1DU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DU:
		case ast::expr::TextureAccess::eTexelFetchOffset3DU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DRectU:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectShadowF:
			result = spv::ImageOperandsMask::Offset;
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getConstOffsets( ast::expr::TextureAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectShadowF:
			result = spv::ImageOperandsMask::ConstOffsets;
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getBias( ast::expr::TextureAccess value )
	{
		spv::ImageOperandsMask result{};

		switch ( value )
		{
	// Texture Query Functions
		case ast::expr::TextureAccess::eTexture1DFBias:
		case ast::expr::TextureAccess::eTexture2DFBias:
		case ast::expr::TextureAccess::eTexture3DFBias:
		case ast::expr::TextureAccess::eTextureCubeFBias:
		case ast::expr::TextureAccess::eTexture1DShadowFBias:
		case ast::expr::TextureAccess::eTexture2DShadowFBias:
		case ast::expr::TextureAccess::eTextureCubeShadowFBias:
		case ast::expr::TextureAccess::eTexture1DArrayFBias:
		case ast::expr::TextureAccess::eTexture2DArrayFBias:
		case ast::expr::TextureAccess::eTextureCubeArrayFBias:
		case ast::expr::TextureAccess::eTexture1DArrayShadowFBias:
		case ast::expr::TextureAccess::eTexture2DArrayShadowFBias:
		case ast::expr::TextureAccess::eTexture1DIBias:
		case ast::expr::TextureAccess::eTexture2DIBias:
		case ast::expr::TextureAccess::eTexture3DIBias:
		case ast::expr::TextureAccess::eTextureCubeIBias:
		case ast::expr::TextureAccess::eTexture1DArrayIBias:
		case ast::expr::TextureAccess::eTexture2DArrayIBias:
		case ast::expr::TextureAccess::eTextureCubeArrayIBias:
		case ast::expr::TextureAccess::eTexture1DUBias:
		case ast::expr::TextureAccess::eTexture2DUBias:
		case ast::expr::TextureAccess::eTexture3DUBias:
		case ast::expr::TextureAccess::eTextureCubeUBias:
		case ast::expr::TextureAccess::eTexture1DArrayUBias:
		case ast::expr::TextureAccess::eTexture2DArrayUBias:
		case ast::expr::TextureAccess::eTextureCubeArrayUBias:
		case ast::expr::TextureAccess::eTextureOffset1DFBias:
		case ast::expr::TextureAccess::eTextureOffset2DFBias:
		case ast::expr::TextureAccess::eTextureOffset3DFBias:
		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset1DArrayFBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayFBias:
		case ast::expr::TextureAccess::eTextureOffset1DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DIBias:
		case ast::expr::TextureAccess::eTextureOffset3DIBias:
		case ast::expr::TextureAccess::eTextureOffset1DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset1DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DUBias:
		case ast::expr::TextureAccess::eTextureOffset3DUBias:
		case ast::expr::TextureAccess::eTextureOffset1DArrayUBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayUBias:
		case ast::expr::TextureAccess::eTextureProj1DF2Bias:
		case ast::expr::TextureAccess::eTextureProj1DF4Bias:
		case ast::expr::TextureAccess::eTextureProj2DF3Bias:
		case ast::expr::TextureAccess::eTextureProj2DF4Bias:
		case ast::expr::TextureAccess::eTextureProj3DFBias:
		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj1DI2Bias:
		case ast::expr::TextureAccess::eTextureProj1DI4Bias:
		case ast::expr::TextureAccess::eTextureProj2DI3Bias:
		case ast::expr::TextureAccess::eTextureProj2DI4Bias:
		case ast::expr::TextureAccess::eTextureProj3DIBias:
		case ast::expr::TextureAccess::eTextureProj1DU2Bias:
		case ast::expr::TextureAccess::eTextureProj1DU4Bias:
		case ast::expr::TextureAccess::eTextureProj2DU3Bias:
		case ast::expr::TextureAccess::eTextureProj2DU4Bias:
		case ast::expr::TextureAccess::eTextureProj3DUBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
			result = spv::ImageOperandsMask::Bias;
			break;
		}

		return result;
	}

	inline spv::ImageOperandsMask getMask( ast::expr::TextureAccess value )
	{
		return getBias( value )
			| getOffset( value )
			| getConstOffsets( value )
			| getGrad( value )
			| getLod( value );
	}

	inline void getSpirVConfig( ast::expr::TextureAccess value
		, IntrinsicConfig & config )
	{
		config.imageOperandsIndex = 0u;
		config.needsImage = false;
		config.mask = getMask( value );
		config.returnComponentsCount = ~( 0u );

		switch ( value )
		{
	// Texture Query Functions
		case ast::expr::TextureAccess::eTextureSize1DF:
		case ast::expr::TextureAccess::eTextureSize2DF:
		case ast::expr::TextureAccess::eTextureSize3DF:
		case ast::expr::TextureAccess::eTextureSizeCubeF:
		case ast::expr::TextureAccess::eTextureSize1DShadowF:
		case ast::expr::TextureAccess::eTextureSize2DShadowF:
		case ast::expr::TextureAccess::eTextureSizeCubeShadowF:
		case ast::expr::TextureAccess::eTextureSizeCubeArrayF:
		case ast::expr::TextureAccess::eTextureSizeCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureSize1DArrayF:
		case ast::expr::TextureAccess::eTextureSize2DArrayF:
		case ast::expr::TextureAccess::eTextureSize1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureSize2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureSize1DI:
		case ast::expr::TextureAccess::eTextureSize2DI:
		case ast::expr::TextureAccess::eTextureSize3DI:
		case ast::expr::TextureAccess::eTextureSizeCubeI:
		case ast::expr::TextureAccess::eTextureSizeCubeArrayI:
		case ast::expr::TextureAccess::eTextureSize1DArrayI:
		case ast::expr::TextureAccess::eTextureSize2DArrayI:
		case ast::expr::TextureAccess::eTextureSize1DU:
		case ast::expr::TextureAccess::eTextureSize2DU:
		case ast::expr::TextureAccess::eTextureSize3DU:
		case ast::expr::TextureAccess::eTextureSizeCubeU:
		case ast::expr::TextureAccess::eTextureSizeCubeArrayU:
		case ast::expr::TextureAccess::eTextureSize1DArrayU:
		case ast::expr::TextureAccess::eTextureSize2DArrayU:
			config.needsImage = true;
			break;

		case ast::expr::TextureAccess::eTextureSize2DRectF:
		case ast::expr::TextureAccess::eTextureSize2DRectShadowF:
		case ast::expr::TextureAccess::eTextureSizeBufferF:
		case ast::expr::TextureAccess::eTextureSize2DRectI:
		case ast::expr::TextureAccess::eTextureSizeBufferI:
		case ast::expr::TextureAccess::eTextureSize2DRectU:
		case ast::expr::TextureAccess::eTextureSizeBufferU:
			config.needsImage = true;
			break;

		case ast::expr::TextureAccess::eTextureQueryLod1DF:
		case ast::expr::TextureAccess::eTextureQueryLod2DF:
		case ast::expr::TextureAccess::eTextureQueryLod3DF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeF:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayF:
		case ast::expr::TextureAccess::eTextureQueryLod1DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod2DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLod1DI:
		case ast::expr::TextureAccess::eTextureQueryLod2DI:
		case ast::expr::TextureAccess::eTextureQueryLod3DI:
		case ast::expr::TextureAccess::eTextureQueryLodCubeI:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayI:
		case ast::expr::TextureAccess::eTextureQueryLod1DU:
		case ast::expr::TextureAccess::eTextureQueryLod2DU:
		case ast::expr::TextureAccess::eTextureQueryLod3DU:
		case ast::expr::TextureAccess::eTextureQueryLodCubeU:
		case ast::expr::TextureAccess::eTextureQueryLod1DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLod2DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLodCubeArrayU:
			break;

		case ast::expr::TextureAccess::eTextureQueryLevels1DF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DF:
		case ast::expr::TextureAccess::eTextureQueryLevels3DF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayShadowF:
		case ast::expr::TextureAccess::eTextureQueryLevels1DI:
		case ast::expr::TextureAccess::eTextureQueryLevels2DI:
		case ast::expr::TextureAccess::eTextureQueryLevels3DI:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeI:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayI:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayI:
		case ast::expr::TextureAccess::eTextureQueryLevels1DU:
		case ast::expr::TextureAccess::eTextureQueryLevels2DU:
		case ast::expr::TextureAccess::eTextureQueryLevels3DU:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeU:
		case ast::expr::TextureAccess::eTextureQueryLevels1DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLevels2DArrayU:
		case ast::expr::TextureAccess::eTextureQueryLevelsCubeArrayU:
			config.needsImage = true;
			break;


	// Texel Lookup Functions
		case ast::expr::TextureAccess::eTexture1DF:
		case ast::expr::TextureAccess::eTexture1DFBias:
		case ast::expr::TextureAccess::eTexture2DF:
		case ast::expr::TextureAccess::eTexture2DFBias:
		case ast::expr::TextureAccess::eTexture3DF:
		case ast::expr::TextureAccess::eTexture3DFBias:
		case ast::expr::TextureAccess::eTextureCubeF:
		case ast::expr::TextureAccess::eTextureCubeFBias:
		case ast::expr::TextureAccess::eTexture1DArrayF:
		case ast::expr::TextureAccess::eTexture1DArrayFBias:
		case ast::expr::TextureAccess::eTexture2DArrayF:
		case ast::expr::TextureAccess::eTexture2DArrayFBias:
		case ast::expr::TextureAccess::eTextureCubeArrayF:
		case ast::expr::TextureAccess::eTextureCubeArrayFBias:
		case ast::expr::TextureAccess::eTexture2DRectF:
		case ast::expr::TextureAccess::eTexture1DI:
		case ast::expr::TextureAccess::eTexture1DIBias:
		case ast::expr::TextureAccess::eTexture2DI:
		case ast::expr::TextureAccess::eTexture2DIBias:
		case ast::expr::TextureAccess::eTexture3DI:
		case ast::expr::TextureAccess::eTexture3DIBias:
		case ast::expr::TextureAccess::eTextureCubeI:
		case ast::expr::TextureAccess::eTextureCubeIBias:
		case ast::expr::TextureAccess::eTexture1DArrayI:
		case ast::expr::TextureAccess::eTexture1DArrayIBias:
		case ast::expr::TextureAccess::eTexture2DArrayI:
		case ast::expr::TextureAccess::eTexture2DArrayIBias:
		case ast::expr::TextureAccess::eTextureCubeArrayI:
		case ast::expr::TextureAccess::eTextureCubeArrayIBias:
		case ast::expr::TextureAccess::eTexture2DRectI:
		case ast::expr::TextureAccess::eTexture1DU:
		case ast::expr::TextureAccess::eTexture1DUBias:
		case ast::expr::TextureAccess::eTexture2DU:
		case ast::expr::TextureAccess::eTexture2DUBias:
		case ast::expr::TextureAccess::eTexture3DU:
		case ast::expr::TextureAccess::eTexture3DUBias:
		case ast::expr::TextureAccess::eTextureCubeU:
		case ast::expr::TextureAccess::eTextureCubeUBias:
		case ast::expr::TextureAccess::eTexture1DArrayU:
		case ast::expr::TextureAccess::eTexture1DArrayUBias:
		case ast::expr::TextureAccess::eTexture2DArrayU:
		case ast::expr::TextureAccess::eTexture2DArrayUBias:
		case ast::expr::TextureAccess::eTextureCubeArrayU:
		case ast::expr::TextureAccess::eTextureCubeArrayUBias:
		case ast::expr::TextureAccess::eTexture2DRectU:
		case ast::expr::TextureAccess::eTextureOffset1DF:
		case ast::expr::TextureAccess::eTextureOffset1DFBias:
		case ast::expr::TextureAccess::eTextureOffset2DF:
		case ast::expr::TextureAccess::eTextureOffset2DFBias:
		case ast::expr::TextureAccess::eTextureOffset3DF:
		case ast::expr::TextureAccess::eTextureOffset3DFBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectF:
		case ast::expr::TextureAccess::eTextureOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureOffset1DArrayFBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureOffset2DArrayFBias:
		case ast::expr::TextureAccess::eTextureOffset1DI:
		case ast::expr::TextureAccess::eTextureOffset1DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DI:
		case ast::expr::TextureAccess::eTextureOffset2DIBias:
		case ast::expr::TextureAccess::eTextureOffset3DI:
		case ast::expr::TextureAccess::eTextureOffset3DIBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectI:
		case ast::expr::TextureAccess::eTextureOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureOffset1DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureOffset2DArrayIBias:
		case ast::expr::TextureAccess::eTextureOffset1DU:
		case ast::expr::TextureAccess::eTextureOffset1DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DU:
		case ast::expr::TextureAccess::eTextureOffset2DUBias:
		case ast::expr::TextureAccess::eTextureOffset3DU:
		case ast::expr::TextureAccess::eTextureOffset3DUBias:
		case ast::expr::TextureAccess::eTextureOffset2DRectU:
		case ast::expr::TextureAccess::eTextureOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureOffset1DArrayUBias:
		case ast::expr::TextureAccess::eTextureOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureOffset2DArrayUBias:
		case ast::expr::TextureAccess::eTextureGrad1DF:
		case ast::expr::TextureAccess::eTextureGrad2DF:
		case ast::expr::TextureAccess::eTextureGrad3DF:
		case ast::expr::TextureAccess::eTextureGradCubeF:
		case ast::expr::TextureAccess::eTextureGrad2DRectF:
		case ast::expr::TextureAccess::eTextureGrad1DArrayF:
		case ast::expr::TextureAccess::eTextureGrad2DArrayF:
		case ast::expr::TextureAccess::eTextureGradCubeArrayF:
		case ast::expr::TextureAccess::eTextureGrad1DI:
		case ast::expr::TextureAccess::eTextureGrad2DI:
		case ast::expr::TextureAccess::eTextureGrad3DI:
		case ast::expr::TextureAccess::eTextureGradCubeI:
		case ast::expr::TextureAccess::eTextureGrad2DRectI:
		case ast::expr::TextureAccess::eTextureGrad1DArrayI:
		case ast::expr::TextureAccess::eTextureGrad2DArrayI:
		case ast::expr::TextureAccess::eTextureGradCubeArrayI:
		case ast::expr::TextureAccess::eTextureGrad1DU:
		case ast::expr::TextureAccess::eTextureGrad2DU:
		case ast::expr::TextureAccess::eTextureGrad3DU:
		case ast::expr::TextureAccess::eTextureGradCubeU:
		case ast::expr::TextureAccess::eTextureGrad2DRectU:
		case ast::expr::TextureAccess::eTextureGrad1DArrayU:
		case ast::expr::TextureAccess::eTextureGrad2DArrayU:
		case ast::expr::TextureAccess::eTextureGradCubeArrayU:
		case ast::expr::TextureAccess::eTextureGradOffset1DF:
		case ast::expr::TextureAccess::eTextureGradOffset2DF:
		case ast::expr::TextureAccess::eTextureGradOffset3DF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGradOffset1DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DI:
		case ast::expr::TextureAccess::eTextureGradOffset3DI:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGradOffset1DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DU:
		case ast::expr::TextureAccess::eTextureGradOffset3DU:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayU:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			break;

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
		case ast::expr::TextureAccess::eTextureOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureGrad1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureGradOffset2DArrayShadowF:
		case ast::expr::TextureAccess::eTextureCubeArrayShadowF:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			break;

		case ast::expr::TextureAccess::eTextureProj1DF2:
		case ast::expr::TextureAccess::eTextureProj1DF2Bias:
		case ast::expr::TextureAccess::eTextureProj1DF4:
		case ast::expr::TextureAccess::eTextureProj1DF4Bias:
		case ast::expr::TextureAccess::eTextureProj2DF3:
		case ast::expr::TextureAccess::eTextureProj2DF3Bias:
		case ast::expr::TextureAccess::eTextureProj2DF4:
		case ast::expr::TextureAccess::eTextureProj2DF4Bias:
		case ast::expr::TextureAccess::eTextureProj3DF:
		case ast::expr::TextureAccess::eTextureProj3DFBias:
		case ast::expr::TextureAccess::eTextureProj2DRectF3:
		case ast::expr::TextureAccess::eTextureProj2DRectF4:
		case ast::expr::TextureAccess::eTextureProj1DI2:
		case ast::expr::TextureAccess::eTextureProj1DI2Bias:
		case ast::expr::TextureAccess::eTextureProj1DI4:
		case ast::expr::TextureAccess::eTextureProj1DI4Bias:
		case ast::expr::TextureAccess::eTextureProj2DI3:
		case ast::expr::TextureAccess::eTextureProj2DI3Bias:
		case ast::expr::TextureAccess::eTextureProj2DI4:
		case ast::expr::TextureAccess::eTextureProj2DI4Bias:
		case ast::expr::TextureAccess::eTextureProj3DI:
		case ast::expr::TextureAccess::eTextureProj3DIBias:
		case ast::expr::TextureAccess::eTextureProj2DRectI3:
		case ast::expr::TextureAccess::eTextureProj2DRectI4:
		case ast::expr::TextureAccess::eTextureProj1DU2:
		case ast::expr::TextureAccess::eTextureProj1DU2Bias:
		case ast::expr::TextureAccess::eTextureProj1DU4:
		case ast::expr::TextureAccess::eTextureProj1DU4Bias:
		case ast::expr::TextureAccess::eTextureProj2DU3:
		case ast::expr::TextureAccess::eTextureProj2DU3Bias:
		case ast::expr::TextureAccess::eTextureProj2DU4:
		case ast::expr::TextureAccess::eTextureProj2DU4Bias:
		case ast::expr::TextureAccess::eTextureProj3DU:
		case ast::expr::TextureAccess::eTextureProj3DUBias:
		case ast::expr::TextureAccess::eTextureProj2DRectU3:
		case ast::expr::TextureAccess::eTextureProj2DRectU4:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjOffset1DF2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjOffset1DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DF3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjOffset2DF4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DF:
		case ast::expr::TextureAccess::eTextureProjOffset3DFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjOffset1DI2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DI3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjOffset2DI4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DI:
		case ast::expr::TextureAccess::eTextureProjOffset3DIBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjOffset1DU2Bias:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjOffset1DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DU3Bias:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjOffset2DU4Bias:
		case ast::expr::TextureAccess::eTextureProjOffset3DU:
		case ast::expr::TextureAccess::eTextureProjOffset3DUBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectU4:
		case ast::expr::TextureAccess::eTextureProjGrad1DF2:
		case ast::expr::TextureAccess::eTextureProjGrad1DF4:
		case ast::expr::TextureAccess::eTextureProjGrad2DF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DF4:
		case ast::expr::TextureAccess::eTextureProjGrad3DF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGrad1DI2:
		case ast::expr::TextureAccess::eTextureProjGrad1DI4:
		case ast::expr::TextureAccess::eTextureProjGrad2DI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DI4:
		case ast::expr::TextureAccess::eTextureProjGrad3DI:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGrad1DU2:
		case ast::expr::TextureAccess::eTextureProjGrad1DU4:
		case ast::expr::TextureAccess::eTextureProjGrad2DU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DU4:
		case ast::expr::TextureAccess::eTextureProjGrad3DU:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectF4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DI:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectI4:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjGradOffset3DU:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU3:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectU4:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			break;

		case ast::expr::TextureAccess::eTextureProj1DShadowF:
		case ast::expr::TextureAccess::eTextureProj1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DShadowF:
		case ast::expr::TextureAccess::eTextureProj2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProj2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset1DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjOffset2DShadowFBias:
		case ast::expr::TextureAccess::eTextureProjOffset2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGrad2DRectShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureProjGradOffset2DRectShadowF:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			break;

		case ast::expr::TextureAccess::eTextureLod1DF:
		case ast::expr::TextureAccess::eTextureLod2DF:
		case ast::expr::TextureAccess::eTextureLod3DF:
		case ast::expr::TextureAccess::eTextureLodCubeF:
		case ast::expr::TextureAccess::eTextureLod1DArrayF:
		case ast::expr::TextureAccess::eTextureLod2DArrayF:
		case ast::expr::TextureAccess::eTextureLodCubeArrayF:
		case ast::expr::TextureAccess::eTextureLod1DI:
		case ast::expr::TextureAccess::eTextureLod2DI:
		case ast::expr::TextureAccess::eTextureLod3DI:
		case ast::expr::TextureAccess::eTextureLodCubeI:
		case ast::expr::TextureAccess::eTextureLod1DArrayI:
		case ast::expr::TextureAccess::eTextureLod2DArrayI:
		case ast::expr::TextureAccess::eTextureLodCubeArrayI:
		case ast::expr::TextureAccess::eTextureLod1DU:
		case ast::expr::TextureAccess::eTextureLod2DU:
		case ast::expr::TextureAccess::eTextureLod3DU:
		case ast::expr::TextureAccess::eTextureLodCubeU:
		case ast::expr::TextureAccess::eTextureLod1DArrayU:
		case ast::expr::TextureAccess::eTextureLod2DArrayU:
		case ast::expr::TextureAccess::eTextureLodCubeArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset1DF:
		case ast::expr::TextureAccess::eTextureLodOffset2DF:
		case ast::expr::TextureAccess::eTextureLodOffset3DF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayF:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureLodOffset1DI:
		case ast::expr::TextureAccess::eTextureLodOffset2DI:
		case ast::expr::TextureAccess::eTextureLodOffset3DI:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureLodOffset1DU:
		case ast::expr::TextureAccess::eTextureLodOffset2DU:
		case ast::expr::TextureAccess::eTextureLodOffset3DU:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayU:
		case ast::expr::TextureAccess::eTextureLodOffset2DArrayU:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			break;

		case ast::expr::TextureAccess::eTextureLod1DShadowF:
		case ast::expr::TextureAccess::eTextureLod2DShadowF:
		case ast::expr::TextureAccess::eTextureLod1DArrayShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset2DShadowF:
		case ast::expr::TextureAccess::eTextureLodOffset1DArrayShadowF:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DF2:
		case ast::expr::TextureAccess::eTextureProjLod1DF4:
		case ast::expr::TextureAccess::eTextureProjLod2DF3:
		case ast::expr::TextureAccess::eTextureProjLod2DF4:
		case ast::expr::TextureAccess::eTextureProjLod3DF:
		case ast::expr::TextureAccess::eTextureProjLod1DI2:
		case ast::expr::TextureAccess::eTextureProjLod1DI4:
		case ast::expr::TextureAccess::eTextureProjLod2DI3:
		case ast::expr::TextureAccess::eTextureProjLod2DI4:
		case ast::expr::TextureAccess::eTextureProjLod3DI:
		case ast::expr::TextureAccess::eTextureProjLod1DU2:
		case ast::expr::TextureAccess::eTextureProjLod1DU4:
		case ast::expr::TextureAccess::eTextureProjLod2DU3:
		case ast::expr::TextureAccess::eTextureProjLod2DU4:
		case ast::expr::TextureAccess::eTextureProjLod3DU:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DF4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DI4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DI:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU2:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU3:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DU4:
		case ast::expr::TextureAccess::eTextureProjLodOffset3DU:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			break;

		case ast::expr::TextureAccess::eTextureProjLod1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLod2DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset1DShadowF:
		case ast::expr::TextureAccess::eTextureProjLodOffset2DShadowF:
			config.returnComponentsCount = 1u;
			config.imageOperandsIndex = 3u;
			break;

		case ast::expr::TextureAccess::eTexelFetch1DF:
		case ast::expr::TextureAccess::eTexelFetch2DF:
		case ast::expr::TextureAccess::eTexelFetch3DF:
		case ast::expr::TextureAccess::eTexelFetch2DRectF:
		case ast::expr::TextureAccess::eTexelFetch1DArrayF:
		case ast::expr::TextureAccess::eTexelFetch2DArrayF:
		case ast::expr::TextureAccess::eTexelFetchBufferF:
		case ast::expr::TextureAccess::eTexelFetch1DI:
		case ast::expr::TextureAccess::eTexelFetch2DI:
		case ast::expr::TextureAccess::eTexelFetch3DI:
		case ast::expr::TextureAccess::eTexelFetch2DRectI:
		case ast::expr::TextureAccess::eTexelFetch1DArrayI:
		case ast::expr::TextureAccess::eTexelFetch2DArrayI:
		case ast::expr::TextureAccess::eTexelFetchBufferI:
		case ast::expr::TextureAccess::eTexelFetch1DU:
		case ast::expr::TextureAccess::eTexelFetch2DU:
		case ast::expr::TextureAccess::eTexelFetch3DU:
		case ast::expr::TextureAccess::eTexelFetch2DRectU:
		case ast::expr::TextureAccess::eTexelFetch1DArrayU:
		case ast::expr::TextureAccess::eTexelFetch2DArrayU:
		case ast::expr::TextureAccess::eTexelFetchBufferU:
		case ast::expr::TextureAccess::eTexelFetchOffset1DF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DF:
		case ast::expr::TextureAccess::eTexelFetchOffset3DF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DRectF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayF:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayF:
		case ast::expr::TextureAccess::eTexelFetchOffset1DI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DI:
		case ast::expr::TextureAccess::eTexelFetchOffset3DI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DRectI:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayI:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayI:
		case ast::expr::TextureAccess::eTexelFetchOffset1DU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DU:
		case ast::expr::TextureAccess::eTexelFetchOffset3DU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DRectU:
		case ast::expr::TextureAccess::eTexelFetchOffset1DArrayU:
		case ast::expr::TextureAccess::eTexelFetchOffset2DArrayU:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 2u;
			config.needsImage = true;
			break;

	// Texture Gather Functions
		case ast::expr::TextureAccess::eTextureGather2DF:
		case ast::expr::TextureAccess::eTextureGather2DFComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayF:
		case ast::expr::TextureAccess::eTextureGather2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeF:
		case ast::expr::TextureAccess::eTextureGatherCubeFComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayF:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayFComp:
		case ast::expr::TextureAccess::eTextureGather2DRectF:
		case ast::expr::TextureAccess::eTextureGather2DRectFComp:
		case ast::expr::TextureAccess::eTextureGather2DI:
		case ast::expr::TextureAccess::eTextureGather2DIComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayI:
		case ast::expr::TextureAccess::eTextureGather2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeI:
		case ast::expr::TextureAccess::eTextureGatherCubeIComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayI:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayIComp:
		case ast::expr::TextureAccess::eTextureGather2DRectI:
		case ast::expr::TextureAccess::eTextureGather2DRectIComp:
		case ast::expr::TextureAccess::eTextureGather2DU:
		case ast::expr::TextureAccess::eTextureGather2DUComp:
		case ast::expr::TextureAccess::eTextureGather2DArrayU:
		case ast::expr::TextureAccess::eTextureGather2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeU:
		case ast::expr::TextureAccess::eTextureGatherCubeUComp:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayU:
		case ast::expr::TextureAccess::eTextureGatherCubeArrayUComp:
		case ast::expr::TextureAccess::eTextureGather2DRectU:
		case ast::expr::TextureAccess::eTextureGather2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffset2DRectUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectF:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectFComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectI:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectIComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DArrayUComp:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectU:
		case ast::expr::TextureAccess::eTextureGatherOffsets2DRectUComp:
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 3u;
			break;

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
			config.returnComponentsCount = 4u;
			config.imageOperandsIndex = 3u;
			break;

		default:
			throw std::runtime_error{ "Unsupported TextureAccess type." };
		}
	}
}

#endif
