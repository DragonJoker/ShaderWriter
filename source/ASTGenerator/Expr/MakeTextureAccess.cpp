/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/MakeTextureAccess.hpp"

namespace ast::expr
{	// Texture Query Functions

	TextureAccessCallPtr makeTextureSize1DF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize3DF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize3DF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize1DShadowF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DShadowF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeShadowF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeArrayF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeArrayShadowF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DRectF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureSize2DRectShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureSize1DArrayF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DArrayF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize1DArrayShadowF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DArrayShadowF( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeBufferF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSizeBufferF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureSize1DI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize3DI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize3DI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeArrayI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DRectI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureSize1DArrayI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DArrayI( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayI
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeBufferI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSizeBufferI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureSize1DU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize3DU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize3DU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeCubeArrayU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DRectU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureSize1DArrayU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSize2DArrayU( ExprPtr texture
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayU
			, std::move( texture )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureSizeBufferU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSizeBufferU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod3DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod3DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DShadowF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DShadowF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeShadowF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DArrayShadowF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DArrayShadowF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeArrayShadowF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod3DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod3DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod3DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod3DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod1DArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLod2DArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLodCubeArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels3DF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels3DF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DArrayF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DArrayF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DArrayShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DArrayShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayShadowF( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayShadowF
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels3DI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels3DI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DArrayI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DArrayI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayI( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayI
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels3DU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels3DU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels1DArrayU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevels2DArrayU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayU
			, std::move( texture ) );
	}

	TextureAccessCallPtr makeTextureQueryLevelsCubeArrayU( ExprPtr texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayU
			, std::move( texture ) );
	}

	// Texel Lookup Functions

	TextureAccessCallPtr makeTexture1DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture2DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture3DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture3DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture3DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureCubeFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture1DArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DArrayFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture2DArrayFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DRectF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DRectF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture2DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture3DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture3DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture3DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureCubeIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture1DArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DArrayIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture2DArrayIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DRectI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DRectI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture2DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture3DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture3DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture3DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureCubeUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture1DArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture1DArrayUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexture2DArrayUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DRectU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DRectU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DF2( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF2
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DF2Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj1DF4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DF4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DF3( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF3
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DF3Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DF4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DF4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj3DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj3DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectF3( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectF3
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectF4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectF4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DI2( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI2
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DI2Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj1DI4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DI4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DI3( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI3
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DI3Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DI4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DI4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj3DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj3DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectI3( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectI3
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectI4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectI4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DU2( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU2
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DU2Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj1DU4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj1DU4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DU3( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU3
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DU3Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DU4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DU4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj3DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj3DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectU3( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectU3
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectU4( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectU4
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureLod1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLodCubeF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLodCubeArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLodCubeI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLodCubeArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLodCubeU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLodCubeArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureOffset1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset3DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DRectF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset3DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DRectI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset3DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DRectU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexelFetch1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DRectF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DRectF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexelFetch1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetchBufferF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchBufferF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexelFetch1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DRectI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DRectI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexelFetch1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetchBufferI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchBufferI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexelFetch1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DRectU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DRectU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexelFetch1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetch2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTexelFetchBufferU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchBufferU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DRectF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DRectI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DRectU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTexelFetchOffset2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DF2( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DF2Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DF4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DF3Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DF4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset3DFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectF3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectF4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DI2( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DI2Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DI4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DI3Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DI4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset3DIBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectI3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectI4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DU2( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DU2Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DU4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DU3Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DU4Bias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset3DUBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectU3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectU4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DF2( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DI2( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DU2( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DF2( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DI2( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DU2( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGrad1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad3DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradCubeF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DRectF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradCubeArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad3DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradCubeI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DRectI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradCubeArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad3DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradCubeU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DRectU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradCubeArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DRectF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DRectI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DRectU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DF2( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad3DF
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectF3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectF4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DI2( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad3DI
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectI3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectI4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DU2( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad3DU
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectU3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectU4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DF2( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset3DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectF3( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectF3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectF4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectF4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DI2( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset3DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectI3( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectI3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectI4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectI4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DU2( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset3DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectU3( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectU3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectU4( ExprPtr texture
		, ExprPtr P
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectU4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}
	
	// Texel Compare Functions

	TextureAccessCallPtr makeTexture1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTexture1DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTexture2DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureCubeShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureCubeShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureCubeShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureCubeShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture1DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTexture1DArrayShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DArrayShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTexture2DArrayShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DArrayShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTexture2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureCubeArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureCubeArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureProj1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureProj1DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureProj2DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProj2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureLod1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLod1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLod2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureLod1DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLod1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureOffset2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset1DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureOffset1DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureOffset2DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset1DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DShadowFBias( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset
		, ExprPtr bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset )
			, std::move( bias ) );
	}

	TextureAccessCallPtr makeTextureProjOffset2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLodOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLodOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureLodOffset1DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLodOffset1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLod1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLod1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLod2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLod2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLodOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjLodOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr lod
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLodOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( lod )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGrad2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGrad1DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset1DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGradOffset2DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGrad1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGrad1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGrad2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGrad2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr pDx
		, ExprPtr pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGrad2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset1DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGradOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGradOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureProjGradOffset2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr dPdx
		, ExprPtr dPdy
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGradOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	// Texture Gather Functions

	TextureAccessCallPtr makeTextureGather2DF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectF( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DRectF
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DRectFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectI( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DRectI
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DRectIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectU( ExprPtr texture
		, ExprPtr P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DRectU
			, std::move( texture )
			, std::move( P ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DRectUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DRectFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DRectIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offset
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DRectUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DF
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectF( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectFComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DRectFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DI
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectI( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectIComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DRectIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DU
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectU( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectUComp( ExprPtr texture
		, ExprPtr P
		, ExprPtr offsets
		, ExprPtr comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DRectUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	// Texture Gather Compare Functions

	TextureAccessCallPtr makeTextureGather2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureGather2DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureGatherCubeArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureGather2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffset2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DArrayShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offsets ) );
	}

	TextureAccessCallPtr makeTextureGatherOffsets2DRectShadowF( ExprPtr texture
		, ExprPtr P
		, ExprPtr refZ
		, ExprPtr offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offsets ) );
	}
}
