
/*
See LICENSE file in root folder
*/

#include "ShaderWriter/Intrinsics/ImageAccessFunctions.hpp"

#include <ShaderAST/Expr/MakeImageAccess.hpp>

namespace sdw
{
#pragma region imageSize
	/**
	*name
	*	imageSize
	*/
	/**@{*/
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< Image1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< ImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< ImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRectRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRectRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRectRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRectRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRectR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DRectR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< ImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< Image2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< Image2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DRectR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< IImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< IImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< IImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DRectR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DRectUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DRectUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< UImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< UImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg8( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR32( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR16( makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< UImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

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
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< Image2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< IImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg8( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR32( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR32( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR16( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR16( makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< UImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR8( makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

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
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad3DFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad3DFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad3DFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad3DFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad3DFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad3DFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad3DFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad3DFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DRectRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DRectRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DRectFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DRectRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DRectFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DRectRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DRectFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DRectFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DRectFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DRectR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DRectFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DRectFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadBufferFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadBufferFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadBufferFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadBufferFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< ImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< ImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< ImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRectRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRectRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DRectRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRectRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRectRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DRectRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DRectIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DRectIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DRectR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DRectIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DRectIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DRectR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DRectIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DRectIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageBufferR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRectRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRectRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DRectRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DRectURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DRectURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRectRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRectRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DRectRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DRectURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DRectURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DRectUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DRectUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DRectR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DRectUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DRectUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DRectR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DRectUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DRectUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageBufferR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR32( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR32( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR16( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR16( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR8( makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR8( makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRgba32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRgba16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRg32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRg16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFR16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRgba32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< Image2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRgba16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRg32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< Image2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRg16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< Image2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFR16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< IImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< IImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< IImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< UImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< UImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg8( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR16( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR16( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< UImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR8( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

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
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional<  IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMinBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMinBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAndBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAndBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOrBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOrBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXorBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXorBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

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
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap3DUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DRectUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapBufferUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap3DIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DRectR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DRectIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DRectIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapBufferIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< UImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSArrayUR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayUR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSIR32( makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< IImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSArrayIR32( makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

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
