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

	ImageAccessCallPtr makeImageAtomicAdd1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAddCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAddCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAddCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAdd2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAdd2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMinCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMin2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMinCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMinCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMin2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMin2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMaxCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicMax2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMaxCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMaxCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicMax2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicMax2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAndCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAndCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAndCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicAnd2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicAnd2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOrCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicOr2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOrCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOrCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicOr2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicOr2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXorCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicXor2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXorCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXorCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicXor2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicXor2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange3DUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange3DUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchangeCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchangeCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicExchange2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicExchange2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayFU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayFU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayIU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayIU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap3DUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DRectUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapBufferUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUU( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eUInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayUU
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayFI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayFI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayII
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayII( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayII
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap3DUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap3DUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DRectUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DRectUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapBufferUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapBufferUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap1DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap1DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwapCubeArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwapCubeArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}

	ImageAccessCallPtr makeImageAtomicCompSwap2DMSArrayUI( ExprPtr image
		, ExprPtr P
		, ExprPtr sample
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeImageAccessCall( makeType( type::Kind::eInt )
			, ImageAccess::eImageAtomicCompSwap2DMSArrayUI
			, std::move( image )
			, std::move( P )
			, std::move( sample )
			, std::move( compare )
			, std::move( data ) );
	}
}
