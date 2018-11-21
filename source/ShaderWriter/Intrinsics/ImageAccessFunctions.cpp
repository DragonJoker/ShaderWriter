
/*
See LICENSE file in root folder
*/

#include "ShaderWriter/Intrinsics/ImageAccessFunctions.hpp"

#include <ASTGenerator/Expr/MakeImageAccess.hpp>

namespace sdw
{
#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	Int imageSize( Image1DRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba32( makeExpr( image ) ) };
	}
	Int imageSize( Image1DRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba16( makeExpr( image ) ) };
	}
	Int imageSize( Image1DRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DFRg32( makeExpr( image ) ) };
	}
	Int imageSize( Image1DRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DFRg16( makeExpr( image ) ) };
	}
	Int imageSize( Image1DR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DFR32( makeExpr( image ) ) };
	}
	Int imageSize( Image1DR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DFR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3DRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3DRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3DRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3DRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3DR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image3DR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCubeRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCubeRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCubeRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCubeRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCubeR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( ImageCubeR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( ImageCubeArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRectRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRectRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRectRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRectRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRectR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DRectR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArrayRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArrayRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArrayRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArrayRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArrayR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image1DArrayR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR16( makeExpr( image ) ) };
	}
	Int imageSize( ImageBufferRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba32( makeExpr( image ) ) };
	}
	Int imageSize( ImageBufferRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba16( makeExpr( image ) ) };
	}
	Int imageSize( ImageBufferRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg32( makeExpr( image ) ) };
	}
	Int imageSize( ImageBufferRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg16( makeExpr( image ) ) };
	}
	Int imageSize( ImageBufferR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR32( makeExpr( image ) ) };
	}
	Int imageSize( ImageBufferR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMSRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMSRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMSRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMSRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMSR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( Image2DMSR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( Image2DMSArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR16( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba32( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba16( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba8( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIRg32( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIRg16( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIRg8( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIR32( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIR16( makeExpr( image ) ) };
	}
	Int imageSize( IImage1DR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DIR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage3DR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImageCubeR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImageCubeArrayR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DRectR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage1DArrayR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DArrayR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR8( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba32( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba16( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba8( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg32( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg16( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg8( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR32( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR16( makeExpr( image ) ) };
	}
	Int imageSize( IImageBufferR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( IImage2DMSR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( IImage2DMSArrayR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR8( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DURgba32( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DURgba16( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DURgba8( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DURg32( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DURg16( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DURg8( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DUR32( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DUR16( makeExpr( image ) ) };
	}
	Int imageSize( UImage1DR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSize1DUR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage3DR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImageCubeR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImageCubeArrayR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectUR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectUR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DRectR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectUR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage1DArrayR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DArrayR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR8( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba32( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba16( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba8( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg32( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg16( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg8( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR32( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR16( makeExpr( image ) ) };
	}
	Int imageSize( UImageBufferR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSRgba32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSRgba16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSRgba8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSRg32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSRg16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSRg8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg8( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSR32 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR32( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSR16 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR16( makeExpr( image ) ) };
	}
	IVec2 imageSize( UImage2DMSR8 const & image )
	{
		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayRgba32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayRgba16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayRgba8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayRg32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayRg16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayRg8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg8( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayR32 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR32( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayR16 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR16( makeExpr( image ) ) };
	}
	IVec3 imageSize( UImage2DMSArrayR8 const & image )
	{
		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR8( makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	Int imageSamples( Image2DMSRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba32( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba16( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg32( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg16( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR32( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR16( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArrayRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba32( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArrayRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba16( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArrayRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg32( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArrayRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg16( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArrayR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR32( makeExpr( image ) ) };
	}
	Int imageSamples( Image2DMSArrayR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba32( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba8( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg32( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg8( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR32( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR8( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba32( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba8( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg32( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg8( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR32( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR16( makeExpr( image ) ) };
	}
	Int imageSamples( IImage2DMSArrayR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR8( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba32( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba16( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba8( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg32( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg16( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg8( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR32( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR16( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR8( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayRgba32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba32( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayRgba16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba16( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayRgba8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba8( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayRg32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg32( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayRg16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg16( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayRg8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg8( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayR32 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR32( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayR16 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR16( makeExpr( image ) ) };
	}
	Int imageSamples( UImage2DMSArrayR8 const & image )
	{
		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR8( makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	Vec4 imageLoad( Image1DRgba32 const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image1DRgba16 const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image1DRg32 const & image
		, Int const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image1DRg16 const & image
		, Int const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image1DR32 const & image
		, Int const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad1DFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image1DR16 const & image
		, Int const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad1DFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DRgba32 const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DRgba16 const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image2DRg32 const & image
		, IVec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image2DRg16 const & image
		, IVec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image2DR32 const & image
		, IVec2 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad2DFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image2DR16 const & image
		, IVec2 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad2DFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image3DRgba32 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image3DRgba16 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image3DRg32 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image3DRg16 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image3DR32 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad3DFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image3DR16 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad3DFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DRectRgba32 const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DRectRgba16 const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image2DRectRg32 const & image
		, IVec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DRectFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image2DRectRg16 const & image
		, IVec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DRectFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image2DRectR32 const & image
		, IVec2 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad2DRectFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image2DRectR16 const & image
		, IVec2 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad2DRectFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageCubeRgba32 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageCubeRgba16 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( ImageCubeRg32 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( ImageCubeRg16 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( ImageCubeR32 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( ImageCubeR16 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageBufferRgba32 const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageBufferRgba16 const & image
		, Int const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( ImageBufferRg32 const & image
		, Int const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( ImageBufferRg16 const & image
		, Int const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( ImageBufferR32 const & image
		, Int const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoadBufferFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( ImageBufferR16 const & image
		, Int const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoadBufferFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image1DArrayRgba32 const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image1DArrayRgba16 const & image
		, IVec2 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image1DArrayRg32 const & image
		, IVec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image1DArrayRg16 const & image
		, IVec2 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image1DArrayR32 const & image
		, IVec2 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image1DArrayR16 const & image
		, IVec2 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DArrayRgba32 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DArrayRgba16 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image2DArrayRg32 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( Image2DArrayRg16 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image2DArrayR32 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( Image2DArrayR16 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageCubeArrayRgba32 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( ImageCubeArrayRgba16 const & image
		, IVec3 const & P )
	{
		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( ImageCubeArrayRg32 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec2 imageLoad( ImageCubeArrayRg16 const & image
		, IVec3 const & P )
	{
		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( ImageCubeArrayR32 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Float imageLoad( ImageCubeArrayR16 const & image
		, IVec3 const & P )
	{
		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage1DRgba32 const & image
		, Int const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage1DRgba16 const & image
		, Int const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage1DRgba8 const & image
		, Int const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage1DRg32 const & image
		, Int const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage1DRg16 const & image
		, Int const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage1DRg8 const & image
		, Int const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage1DR32 const & image
		, Int const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage1DR16 const & image
		, Int const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage1DR8 const & image
		, Int const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DRgba32 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DRgba16 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DRgba8 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DRg32 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DRg16 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DRg8 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DR32 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DR16 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DR8 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage3DRgba32 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage3DRgba16 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage3DRgba8 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage3DRg32 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage3DRg16 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage3DRg8 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage3DR32 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage3DR16 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage3DR8 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DRectRgba32 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DRectRgba16 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DRectRgba8 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DRectRg32 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DRectRg16 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DRectRg8 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DRectR32 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DRectIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DRectR16 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DRectIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DRectR8 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DRectIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageCubeRgba32 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageCubeRgba16 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageCubeRgba8 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageCubeRg32 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageCubeRg16 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageCubeRg8 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageCubeR32 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageCubeR16 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageCubeR8 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageBufferRgba32 const & image
		, Int const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageBufferRgba16 const & image
		, Int const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageBufferRgba8 const & image
		, Int const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageBufferRg32 const & image
		, Int const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageBufferRg16 const & image
		, Int const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageBufferRg8 const & image
		, Int const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageBufferR32 const & image
		, Int const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageBufferR16 const & image
		, Int const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageBufferR8 const & image
		, Int const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage1DArrayRgba32 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage1DArrayRgba16 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage1DArrayRgba8 const & image
		, IVec2 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage1DArrayRg32 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage1DArrayRg16 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage1DArrayRg8 const & image
		, IVec2 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage1DArrayR32 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage1DArrayR16 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage1DArrayR8 const & image
		, IVec2 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DArrayRgba32 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DArrayRgba16 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImage2DArrayRgba8 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DArrayRg32 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DArrayRg16 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImage2DArrayRg8 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DArrayR32 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DArrayR16 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImage2DArrayR8 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageCubeArrayRgba32 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageCubeArrayRgba16 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec4 imageLoad( IImageCubeArrayRgba8 const & image
		, IVec3 const & P )
	{
		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageCubeArrayRg32 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageCubeArrayRg16 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	IVec2 imageLoad( IImageCubeArrayRg8 const & image
		, IVec3 const & P )
	{
		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageCubeArrayR32 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageCubeArrayR16 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Int imageLoad( IImageCubeArrayR8 const & image
		, IVec3 const & P )
	{
		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage1DRgba32 const & image
		, Int const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage1DRgba16 const & image
		, Int const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage1DRgba8 const & image
		, Int const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage1DRg32 const & image
		, Int const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage1DRg16 const & image
		, Int const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage1DRg8 const & image
		, Int const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage1DR32 const & image
		, Int const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage1DR16 const & image
		, Int const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage1DR8 const & image
		, Int const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DRgba32 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DRgba16 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DRgba8 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DRg32 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DRg16 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DRg8 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DR32 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DR16 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DR8 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage3DRgba32 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage3DRgba16 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage3DRgba8 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage3DRg32 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage3DRg16 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage3DRg8 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage3DR32 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage3DR16 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage3DR8 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DRectRgba32 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DRectRgba16 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DRectRgba8 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DRectRg32 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DRectRg16 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DRectRg8 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DRectR32 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DRectUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DRectR16 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DRectUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DRectR8 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DRectUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageCubeRgba32 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageCubeRgba16 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageCubeRgba8 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageCubeRg32 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageCubeRg16 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageCubeRg8 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageCubeR32 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageCubeR16 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageCubeR8 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageBufferRgba32 const & image
		, Int const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageBufferRgba16 const & image
		, Int const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageBufferRgba8 const & image
		, Int const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageBufferRg32 const & image
		, Int const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageBufferRg16 const & image
		, Int const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageBufferRg8 const & image
		, Int const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageBufferR32 const & image
		, Int const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageBufferR16 const & image
		, Int const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageBufferR8 const & image
		, Int const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage1DArrayRgba32 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage1DArrayRgba16 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage1DArrayRgba8 const & image
		, IVec2 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage1DArrayRg32 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage1DArrayRg16 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage1DArrayRg8 const & image
		, IVec2 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage1DArrayR32 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage1DArrayR16 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage1DArrayR8 const & image
		, IVec2 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DArrayRgba32 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DArrayRgba16 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImage2DArrayRgba8 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DArrayRg32 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DArrayRg16 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImage2DArrayRg8 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DArrayR32 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DArrayR16 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImage2DArrayR8 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageCubeArrayRgba32 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageCubeArrayRgba16 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec4 imageLoad( UImageCubeArrayRgba8 const & image
		, IVec3 const & P )
	{
		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageCubeArrayRg32 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageCubeArrayRg16 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UVec2 imageLoad( UImageCubeArrayRg8 const & image
		, IVec3 const & P )
	{
		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageCubeArrayR32 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageCubeArrayR16 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	UInt imageLoad( UImageCubeArrayR8 const & image
		, IVec3 const & P )
	{
		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	Vec4 imageLoad( Image2DMSRgba32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( Image2DMSRgba16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec2 imageLoad( Image2DMSRg32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec2 imageLoad( Image2DMSRg16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Float imageLoad( Image2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Float imageLoad( Image2DMSR16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( Image2DMSArrayRgba32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec4 imageLoad( Image2DMSArrayRgba16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec2 imageLoad( Image2DMSArrayRg32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Vec2 imageLoad( Image2DMSArrayRg16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Float imageLoad( Image2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Float imageLoad( Image2DMSArrayR16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec4 imageLoad( IImage2DMSRgba32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec4 imageLoad( IImage2DMSRgba16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec4 imageLoad( IImage2DMSRgba8 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec2 imageLoad( IImage2DMSRg32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec2 imageLoad( IImage2DMSRg16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec2 imageLoad( IImage2DMSRg8 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Int imageLoad( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Int imageLoad( IImage2DMSR16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Int imageLoad( IImage2DMSR8 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec4 imageLoad( IImage2DMSArrayRgba32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec4 imageLoad( IImage2DMSArrayRgba16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec4 imageLoad( IImage2DMSArrayRgba8 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec2 imageLoad( IImage2DMSArrayRg32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec2 imageLoad( IImage2DMSArrayRg16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	IVec2 imageLoad( IImage2DMSArrayRg8 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Int imageLoad( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Int imageLoad( IImage2DMSArrayR16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	Int imageLoad( IImage2DMSArrayR8 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec4 imageLoad( UImage2DMSRgba32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec4 imageLoad( UImage2DMSRgba16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec4 imageLoad( UImage2DMSRgba8 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec2 imageLoad( UImage2DMSRg32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec2 imageLoad( UImage2DMSRg16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec2 imageLoad( UImage2DMSRg8 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UInt imageLoad( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UInt imageLoad( UImage2DMSR16 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UInt imageLoad( UImage2DMSR8 const & image
		, IVec2 const & P
		, Int const & sample )
	{
		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec4 imageLoad( UImage2DMSArrayRgba32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec4 imageLoad( UImage2DMSArrayRgba16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec4 imageLoad( UImage2DMSArrayRgba8 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec2 imageLoad( UImage2DMSArrayRg32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec2 imageLoad( UImage2DMSArrayRg16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UVec2 imageLoad( UImage2DMSArrayRg8 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UInt imageLoad( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UInt imageLoad( UImage2DMSArrayR16 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	UInt imageLoad( UImage2DMSArrayR8 const & image
		, IVec3 const & P
		, Int const & sample )
	{
		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	UInt imageAtomicAdd( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DArrayR32 const & image
		,  IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAdd( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAdd( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicMin
	/**
	*name
	*	imageAtomicMin
	*/
	/**@{*/
	UInt imageAtomicMin( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMin( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMin( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicMax
	/**
	*name
	*	imageAtomicMax
	*/
	/**@{*/
	UInt imageAtomicMax( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicMax( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicMax( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAnd
	/**
	*name
	*	imageAtomicAnd
	*/
	/**@{*/
	UInt imageAtomicAnd( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicAnd( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicAnd( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicOr
	/**
	*name
	*	imageAtomicOr
	*/
	/**@{*/
	UInt imageAtomicOr( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicOr( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicOr( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicXor
	/**
	*name
	*	imageAtomicXor
	*/
	/**@{*/
	UInt imageAtomicXor( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicXor( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicXor( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicExchange
	/**
	*name
	*	imageAtomicExchange
	*/
	/**@{*/
	UInt imageAtomicExchange( UImage1DR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImageBufferR32 const & image
		, Int const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & data )
	{
		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage1DR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImageBufferR32 const & image
		, Int const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & data )
	{
		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicExchange( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Int imageAtomicExchange( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicCompSwap
	/**
	*name
	*	imageAtomicCompSwap
	*/
	/**@{*/
	UInt imageAtomicCompSwap( UImage1DR32 const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DR32 const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage3DR32 const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DRectR32 const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImageCubeR32 const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImageBufferR32 const & image
		, Int const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage1DArrayR32 const & image
		, IVec2 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DArrayR32 const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImageCubeArrayR32 const & image
		, IVec3 const & P
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage1DR32 const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DR32 const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage3DR32 const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DRectR32 const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImageCubeR32 const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImageBufferR32 const & image
		, Int const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage1DArrayR32 const & image
		, IVec2 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DArrayR32 const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImageCubeArrayR32 const & image
		, IVec3 const & P
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	UInt imageAtomicCompSwap( UImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, UInt const & compare
		, UInt const & data )
	{
		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DMSR32 const & image
		, IVec2 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	Int imageAtomicCompSwap( IImage2DMSArrayR32 const & image
		, IVec3 const & P
		, Int const & sample
		, Int const & compare
		, Int const & data )
	{
		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
}
