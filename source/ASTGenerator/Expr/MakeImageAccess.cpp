/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/MakeImageAccess.hpp"

namespace ast::expr
{
	ImageAccessCallPtr makeImageSize1DF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSize1DF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize3DF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeCubeF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeCubeArrayF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DRectF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize1DArrayF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DArrayF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeBufferF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DMSF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DMSArrayF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize1DI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSize1DI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize3DI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeCubeI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeCubeArrayI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DRectI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize1DArrayI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DArrayI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeBufferI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DMSI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DMSArrayI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize1DU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSize1DU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize3DU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize3DU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeCubeU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSizeCubeU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeCubeArrayU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSizeCubeArrayU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DRectU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DRectU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize1DArrayU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize1DArrayU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DArrayU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DArrayU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSizeBufferU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSizeBufferU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DMSU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec2I )
			, ImageAccess::eImageSize2DMSU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSize2DMSArrayU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec3I )
			, ImageAccess::eImageSize2DMSArrayU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSamples2DMSF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSamples2DMSArrayF( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayF
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSamples2DMSI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSamples2DMSArrayI( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayI
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSamples2DMSU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageSamples2DMSArrayU( ExprPtr image )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageSamples2DMSArrayU
			, std::move( image ) );
	}

	ImageAccessCallPtr makeImageLoad1DF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad3DF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DRectF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadCubeF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadBufferF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad1DArrayF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DArrayF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadCubeArrayF( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayF
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DMSF( ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	ImageAccessCallPtr makeImageLoad2DMSArrayF( ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayF
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	ImageAccessCallPtr makeImageLoad1DI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad3DI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DRectI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadCubeI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadBufferI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad1DArrayI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DArrayI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadCubeArrayI( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayI
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	ImageAccessCallPtr makeImageLoad2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	ImageAccessCallPtr makeImageLoad1DU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad3DU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad3DU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DRectU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DRectU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadCubeU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadBufferU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadBufferU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad1DArrayU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad1DArrayU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DArrayU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DArrayU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoadCubeArrayU( ExprPtr image
		, ExprPtr P )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoadCubeArrayU
			, std::move( image )
			, std::move( P ) );
	}

	ImageAccessCallPtr makeImageLoad2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	ImageAccessCallPtr makeImageLoad2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample )
	{
		return makeImageAccessCall( makeType( type::Kind::eVec4F )
			, ImageAccess::eImageLoad2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
}
