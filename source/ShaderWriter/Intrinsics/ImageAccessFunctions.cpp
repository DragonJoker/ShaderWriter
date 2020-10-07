
/*
See LICENSE file in root folder
*/

#include "ShaderWriter/BaseTypes/Void.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Bool.hpp"
#include "ShaderWriter/BaseTypes/Double.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/UInt.hpp"
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
	MaybeOptional< Int > imageSize( MaybeOptional< RImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RIImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWIImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WIImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RIImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWIImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WIImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RIImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWIImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WIImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImage1DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSize1DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSize1DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage3DR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize3DUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize3DUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImageCubeR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSizeCubeUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSizeCubeUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImageCubeArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSizeCubeArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSizeCubeArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage1DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize1DArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize1DArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RUImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< RWUImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSize( MaybeOptional< WUImageBufferR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSizeBufferUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSizeBufferUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RUImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< RWUImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec2 > imageSize( MaybeOptional< WUImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec2 >{ findShader( image )
				, expr::makeImageSize2DMSUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec2{ findShader( image )
			, expr::makeImageSize2DMSUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RUImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< RWUImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< IVec3 > imageSize( MaybeOptional< WUImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< IVec3 >{ findShader( image )
				, expr::makeImageSize2DMSArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return IVec3{ findShader( image )
			, expr::makeImageSize2DMSArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageSamples
	/**
	*name
	*	imageSamples
	*/
	/**@{*/
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayFR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayFR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RIImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWIImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIRg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIRg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WIImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayIR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayIR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RUImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< RWUImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayRgba32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayRgba16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayRgba8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURgba8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURgba8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayRg32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayRg16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayRg8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayURg8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayURg8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayR32 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR32( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR32( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayR16 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR16( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR16( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	MaybeOptional< Int > imageSamples( MaybeOptional< WUImage2DMSArrayR8 > const & image )
	{
		if ( isAnyOptional( image ) )
		{
			return Optional< Int >{ findShader( image )
				, expr::makeImageSamples2DMSArrayUR8( findTypesCache( image )
					, makeExpr( image ) )
				, areOptionalEnabled( image ) };
		}

		return Int{ findShader( image )
			, expr::makeImageSamples2DMSArrayUR8( findTypesCache( image )
				, makeExpr( image ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageLoad
	/**
	*name
	*	imageLoad
	*/
	/**@{*/
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad1DFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad1DFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad1DFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad1DFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad1DFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad1DFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad2DFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad2DFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad2DFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad2DFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad2DFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad2DFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad3DFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad3DFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad3DFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad3DFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad3DFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad3DFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad3DFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad3DFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad3DFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad3DFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad3DFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad3DFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad3DFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad3DFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoadCubeFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoadCubeFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoadCubeFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoadCubeFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoadCubeFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoadCubeFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadBufferFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadBufferFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoadBufferFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoadBufferFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoadBufferFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoadBufferFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadBufferFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadBufferFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoadBufferFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoadBufferFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad1DArrayFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad1DArrayFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoad2DArrayFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoad2DArrayFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Vec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Vec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< HVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return HVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Float >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Float{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Half >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayFR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Half{ findShader( image, P )
			, expr::makeImageLoadCubeArrayFR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage1DRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage1DR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage1DRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage1DR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad3DIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad3DIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad3DIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad3DIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageBufferR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadBufferIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadBufferIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageBufferR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadBufferIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadBufferIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad1DArrayIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad1DArrayIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoad2DArrayIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoad2DArrayIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< IVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIRg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return IVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIRg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< Int >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayIR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return Int{ findShader( image, P )
			, expr::makeImageLoadCubeArrayIR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage1DRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage1DR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage1DRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage1DRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage1DRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage1DR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage1DR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad3DURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad3DURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad3DURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad3DURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad3DUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad3DUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageBufferR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadBufferURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadBufferURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadBufferURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadBufferURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageBufferR16 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageBufferR8 > const & image
		, MaybeOptional< Int > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadBufferUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadBufferUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad1DArrayURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad1DArrayURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad1DArrayURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad1DArrayUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad1DArrayUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoad2DArrayURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoad2DArrayURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoad2DArrayURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoad2DArrayUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoad2DArrayUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec4 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURgba8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec4{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURgba8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UVec2 >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayURg8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UVec2{ findShader( image, P )
			, expr::makeImageLoadCubeArrayURg8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR32( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR32( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR16( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR16( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P )
	{
		if ( isAnyOptional( image, P ) )
		{
			return Optional< UInt >{ findShader( image, P )
				, expr::makeImageLoadCubeArrayUR8( findTypesCache( image, P )
					, makeExpr( image )
					, makeExpr( P ) )
				, areOptionalEnabled( image, P ) };
		}

		return UInt{ findShader( image, P )
			, expr::makeImageLoadCubeArrayUR8( findTypesCache( image, P )
				, makeExpr( image )
				, makeExpr( P ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Half >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Half{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Half >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSFR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Half{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSFR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Half >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Half{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > imageLoad( MaybeOptional< RWImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec4 > imageLoad( MaybeOptional< RWImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > imageLoad( MaybeOptional< RWImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Vec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Vec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< HVec2 > imageLoad( MaybeOptional< RWImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return HVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Float > imageLoad( MaybeOptional< RWImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Float >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Float{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Half > imageLoad( MaybeOptional< RWImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Half >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayFR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Half{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayFR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIRg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIRg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSIR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSIR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RIImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RIImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RIImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec4 > imageLoad( MaybeOptional< RWIImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< IVec2 > imageLoad( MaybeOptional< RWIImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< IVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIRg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return IVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIRg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Int > imageLoad( MaybeOptional< RWIImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< Int >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayIR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return Int{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayIR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSURg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSURg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSUR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSUR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RUImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RUImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RUImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec4 > imageLoad( MaybeOptional< RWUImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec4 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURgba8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec4{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURgba8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UVec2 > imageLoad( MaybeOptional< RWUImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UVec2 >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayURg8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UVec2{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayURg8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR32( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR32( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR16( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR16( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< UInt > imageLoad( MaybeOptional< RWUImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( image, P, sample ) )
		{
			return Optional< UInt >{ findShader( image, P, sample )
				, expr::makeImageLoad2DMSArrayUR8( findTypesCache( image, P, sample )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample ) )
				, areOptionalEnabled( image, P, sample ) };
		}

		return UInt{ findShader( image, P, sample )
			, expr::makeImageLoad2DMSArrayUR8( findTypesCache( image, P, sample )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageStore
	/**
	*name
	*	imageStore
	*/
	/**@{*/
	Void imageStore( MaybeOptional< WImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageBufferR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageBufferR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayFR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageBufferR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageBufferR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIRg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayIR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage3DR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore3DUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageBufferR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferRgba32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferRgba8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferRg32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferRg8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferR16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageBufferR8 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreBufferUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage1DArrayR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore1DArrayUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStore2DArrayUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURgba32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURgba8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURg32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayURg8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayUR16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImageCubeArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, data )
			, expr::makeImageStoreCubeArrayUR8( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSFR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Vec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Half > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayFR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIRg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSIR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WIImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< IVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIRg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWIImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayIR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSUR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSUR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSRgba32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSRgba8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSRg32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSRg8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSURg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSR16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSUR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSR8 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSUR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayUR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< WUImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayUR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayRgba32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURgba32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayRgba8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec4 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURgba8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayRg32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURg32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayRg8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UVec2 > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayURg8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayR16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayUR16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	Void imageStore( MaybeOptional< RWUImage2DMSArrayR8 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		return Void{ findShader( image, P, sample, data )
			, expr::makeImageStore2DMSArrayUR8( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imageAtomicAdd
	/**
	*name
	*	imageAtomicAdd
	*/
	/**@{*/
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional<  IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd3DFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAdd3DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAddBufferFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAddBufferFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd1DArrayFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAdd1DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage2DArrayRgba16 > const & image
		, MaybeOptional<  IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage2DArrayRg16 > const & image
		, MaybeOptional<  IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage2DArrayR32 > const & image
		, MaybeOptional<  IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAdd2DArrayFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAdd2DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicAddCubeArrayFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicAddCubeArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAdd( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAdd( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSFRgba16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec4{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSFRg16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec2{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Float >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSFR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Float{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicAdd( MaybeOptional< RWImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayFRgba16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec4{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicAdd( MaybeOptional< RWImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayFRg16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec2{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicAdd( MaybeOptional< RWImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Float >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAdd2DMSArrayFR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Float{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAdd2DMSArrayFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMinBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMinBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMin2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMin2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMinCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMinCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMin( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMin( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMin2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMin2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMax2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMax2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicMaxCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicMaxCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicMax( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicMax( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicMax2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicMax2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAndBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAndBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAnd2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAnd2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicAndCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicAndCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicAnd( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicAnd( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicAnd2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicAnd2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOrBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOrBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOr2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOr2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicOrCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicOrCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicOr( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicOr( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicOr2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicOr2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXorBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXorBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXor2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXor2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicXorCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicXorCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicXor( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicXor( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicXor2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicXor2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< UInt >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayUR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return UInt{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayUR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Int >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayIR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Int{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayIR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage1DRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage1DRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage2DRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage2DRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage3DRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage3DRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange3DFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchange3DFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImageCubeRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImageCubeRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImageBufferRgba16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImageBufferRg16 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeBufferFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeBufferFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage1DArrayRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage1DArrayRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange1DArrayFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchange1DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage2DArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage2DArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchange2DArrayFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchange2DArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImageCubeArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayFRgba16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec4{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayFRgba16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImageCubeArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayFRg16( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return HVec2{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayFRg16( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, data ) )
		{
			return Optional< Float >{ findShader( image, P, data )
				, expr::makeImageAtomicExchangeCubeArrayFR32( findTypesCache( image, P, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, data ) };
		}

		return Float{ findShader( image, P, data )
			, expr::makeImageAtomicExchangeCubeArrayFR32( findTypesCache( image, P, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicExchange( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayUR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return UInt{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayUR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicExchange( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayIR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Int{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayIR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage2DMSRgba16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSFRgba16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec4{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage2DMSRg16 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSFRg16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec2{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Float >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSFR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Float{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec4 > imageAtomicExchange( MaybeOptional< RWImage2DMSArrayRgba16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec4 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec4 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayFRgba16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec4{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayFRgba16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< HVec2 > imageAtomicExchange( MaybeOptional< RWImage2DMSArrayRg16 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< HVec2 > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< HVec2 >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayFRg16( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return HVec2{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayFRg16( findTypesCache( image, P, sample, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Float > imageAtomicExchange( MaybeOptional< RWImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Float > const & data )
	{
		if ( isAnyOptional( image, P, sample, data ) )
		{
			return Optional< Float >{ findShader( image, P, sample, data )
				, expr::makeImageAtomicExchange2DMSArrayFR32( findTypesCache( image, P, sample, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, data ) };
		}

		return Float{ findShader( image, P, sample, data )
			, expr::makeImageAtomicExchange2DMSArrayFR32( findTypesCache( image, P, sample, data )
				, makeExpr( image )
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
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap3DUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapBufferUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DArrayUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DArrayUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeArrayUR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return UInt{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayUR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage1DR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage2DR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage3DR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap3DIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap3DIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImageCubeR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImageBufferR32 > const & image
		, MaybeOptional< Int > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapBufferIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapBufferIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage1DArrayR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap1DArrayIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap1DArrayIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage2DArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwap2DArrayIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwap2DArrayIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImageCubeArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, compare, data )
				, expr::makeImageAtomicCompSwapCubeArrayIR32( findTypesCache( image, P, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, compare, data ) };
		}

		return Int{ findShader( image, P, compare, data )
			, expr::makeImageAtomicCompSwapCubeArrayIR32( findTypesCache( image, P, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSUR32( findTypesCache( image, P, sample, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSUR32( findTypesCache( image, P, sample, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > imageAtomicCompSwap( MaybeOptional< RWUImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< UInt > const & compare
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< UInt >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSArrayUR32( findTypesCache( image, P, sample, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return UInt{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayUR32( findTypesCache( image, P, sample, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage2DMSR32 > const & image
		, MaybeOptional< IVec2 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSIR32( findTypesCache( image, P, sample, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSIR32( findTypesCache( image, P, sample, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	MaybeOptional< Int > imageAtomicCompSwap( MaybeOptional< RWIImage2DMSArrayR32 > const & image
		, MaybeOptional< IVec3 > const & P
		, MaybeOptional< Int > const & sample
		, MaybeOptional< Int > const & compare
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( image, P, sample, compare, data ) )
		{
			return Optional< Int >{ findShader( image, P, sample, compare, data )
				, expr::makeImageAtomicCompSwap2DMSArrayIR32( findTypesCache( image, P, sample, compare, data )
					, makeExpr( image )
					, makeExpr( P )
					, makeExpr( sample )
					, makeExpr( compare )
					, makeExpr( data ) )
				, areOptionalEnabled( image, P, sample, compare, data ) };
		}

		return Int{ findShader( image, P, sample, compare, data )
			, expr::makeImageAtomicCompSwap2DMSArrayIR32( findTypesCache( image, P, sample, compare, data )
				, makeExpr( image )
				, makeExpr( P )
				, makeExpr( sample )
				, makeExpr( compare )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
}
