/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMakeTextureAccess_H___
#define ___AST_ExprMakeTextureAccess_H___
#pragma once

#include "ExprTextureAccessCall.hpp"

namespace ast::expr
{	// Texture Query Functions

	inline TextureAccessCallPtr/*int*/ makeTextureSize1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize3DF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSizeCubeF( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureSize1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSizeCubeShadowF( ExprPtr/*samplerCubeShadow*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSizeCubeArrayF( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSizeCubeArrayShadowF( ExprPtr/*samplerCubeArrayShadow*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DRectF( ExprPtr/*sampler2DRect*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayShadowF
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureSizeBufferF( ExprPtr/*samplerBuffer*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSizeBufferF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureSize1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize3DI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSizeCubeI( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSizeCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DRectI( ExprPtr/*isampler2DRect*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayI
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureSizeBufferI( ExprPtr/*isamplerBuffer*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSizeBufferI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureSize1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSize1DU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize3DU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSizeCubeU( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSizeCubeU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSizeCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSizeCubeArrayU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize2DRectU( ExprPtr/*usampler2DRect*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize2DRectU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*vec2i*/ makeTextureSize1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2I )
			, TextureAccess::eTextureSize1DArrayU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec3i*/ makeTextureSize2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec3I )
			, TextureAccess::eTextureSize2DArrayU
			, std::move( texture )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureSizeBufferU( ExprPtr/*usamplerBuffer*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureSizeBufferU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod3DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeF( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeArrayF( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeShadowF( ExprPtr/*samplerCubeShadow*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeArrayShadowF( ExprPtr/*samplerCubeArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod3DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeI( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod3DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeU( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod1DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLod2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLod2DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec2f*/ makeTextureQueryLodCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec2F )
			, TextureAccess::eTextureQueryLodCubeArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DF( ExprPtr/*sampler1D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DF( ExprPtr/*sampler2D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels3DF( ExprPtr/*sampler3D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels3DF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeF( ExprPtr/*samplerCube*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DArrayF( ExprPtr/*sampler1DArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DArrayF( ExprPtr/*sampler2DArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeArrayF( ExprPtr/*samplerCubeArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DShadowF( ExprPtr/*sampler1DShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DShadowF( ExprPtr/*sampler2DShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeShadowF( ExprPtr/*samplerCubeShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeArrayShadowF( ExprPtr/*samplerCubeArrayShadow*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayShadowF
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DI( ExprPtr/*isampler1D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DI( ExprPtr/*isampler2D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels3DI( ExprPtr/*isampler3D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels3DI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeI( ExprPtr/*isamplerCube*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DArrayI( ExprPtr/*isampler1DArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DArrayI( ExprPtr/*isampler2DArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayI
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DU( ExprPtr/*usampler1D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DU( ExprPtr/*usampler2D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels3DU( ExprPtr/*usampler3D*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels3DU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeU( ExprPtr/*usamplerCube*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels1DArrayU( ExprPtr/*usampler1DArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels1DArrayU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevels2DArrayU( ExprPtr/*usampler2DArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevels2DArrayU
			, std::move( texture ) );
	}

	inline TextureAccessCallPtr/*int*/ makeTextureQueryLevelsCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture )
	{
		return makeTextureAccessCall( makeType( type::Kind::eInt )
			, TextureAccess::eTextureQueryLevelsCubeArrayU
			, std::move( texture ) );
	}

	// Texel Lookup Functions

	inline TextureAccessCallPtr/*vec4f*/ makeTexture1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture1DFBias( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture2DFBias( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture3DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture3DFBias( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureCubeF( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureCubeFBias( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture1DShadowFBias( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture2DShadowFBias( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureCubeShadowF( ExprPtr/*samplerCubeShadow*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureCubeShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureCubeShadowFBias( ExprPtr/*samplerCubeShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureCubeShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture1DArrayFBias( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture1DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture2DArrayFBias( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureCubeArrayF( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureCubeArrayFBias( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureCubeArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture1DArrayShadowFBias( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture1DArrayShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DArrayShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture2DArrayShadowFBias( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DArrayShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexture2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexture2DRectF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTexture2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTexture2DRectShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureCubeArrayShadowF( ExprPtr/*samplerCubeArrayShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ compare )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureCubeArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( compare ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture1DIBias( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture2DIBias( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture3DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture3DIBias( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureCubeI( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureCubeIBias( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture1DArrayIBias( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture1DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture2DArrayIBias( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureCubeArrayIBias( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureCubeArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTexture2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTexture2DRectI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture1DUBias( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture2DUBias( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture3DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture3DUBias( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureCubeU( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureCubeUBias( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture1DArrayUBias( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture1DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture2DArrayUBias( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureCubeArrayUBias( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureCubeArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTexture2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTexture2DRectU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DF2( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF2
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DF2Bias( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DF4( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DF4Bias( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DF3( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF3
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DF3Bias( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DF4( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DF4Bias( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj3DFBias( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProj1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj1DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProj1DShadowFBias( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProj2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj2DShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProj2DShadowFBias( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DRectF3( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectF3
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DRectF4( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectF4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProj2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProj2DRectShadowF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DI2( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI2
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DI2Bias( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DI4( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DI4Bias( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DI3( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI3
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DI3Bias( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DI4( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DI4Bias( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj3DIBias( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DRectI3( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectI3
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DRectI4( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectI4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DU2( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU2
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DU2Bias( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DU4( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj1DU4Bias( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj1DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DU3( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU3
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DU3Bias( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DU4( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DU4Bias( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj3DUBias( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DRectU3( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectU3
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProj2DRectU4( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProj2DRectU4
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodCubeF( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureLod1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLod1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureLod2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLod2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureLod1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLod1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodCubeArrayF( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodCubeI( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodCubeU( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLod2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLod2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodCubeArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DFBias( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DFBias( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset3DFBias( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset1DShadowFBias( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset2DShadowFBias( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DArrayFBias( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DArrayFBias( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureOffset2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureOffset2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DIBias( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DIBias( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset3DIBias( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DArrayIBias( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DArrayIBias( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DUBias( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DUBias( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset3DUBias( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset1DArrayUBias( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset1DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureOffset2DArrayUBias( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureOffset2DArrayUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec2i*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DRectF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchBufferF( ExprPtr/*samplerBuffer*/ texture
		, ExprPtr/*int*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchBufferF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec2i*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DRectI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchBufferI( ExprPtr/*isamplerBuffer*/ texture
		, ExprPtr/*int*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchBufferI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec2i*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DRectU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetch2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetch2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchBufferU( ExprPtr/*usamplerBuffer*/ texture
		, ExprPtr/*int*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchBufferU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*int*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTexelFetchOffset2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3i*/ P
		, ExprPtr/*int*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTexelFetchOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DF2( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DF2Bias( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DF4( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DF4Bias( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DF3( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DF3Bias( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DF4( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DF4Bias( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DF4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset3DFBias( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjOffset1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjOffset1DShadowFBias( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset1DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjOffset2DShadowFBias( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset2DShadowFBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DRectF3( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectF3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DRectF4( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectF4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjOffset2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DI2( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DI2Bias( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DI4( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DI4Bias( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DI3( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DI3Bias( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DI4( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DI4Bias( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DI4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset3DIBias( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DIBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DRectI3( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectI3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DRectI4( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectI4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DU2( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DU2Bias( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU2Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DU4( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset1DU4Bias( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset1DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DU3( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DU3Bias( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU3Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DU4( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DU4Bias( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DU4Bias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset3DUBias( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3i*/ offset
		, ExprPtr/*float*/ bias )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset3DUBias
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( bias ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DRectU3( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectU3
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjOffset2DRectU4( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjOffset2DRectU4
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureLodOffset1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLodOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureLodOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLodOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureLodOffset1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureLodOffset1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureLodOffset2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureLodOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod1DF2( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod1DF4( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod2DF3( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod2DF4( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjLod1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLod1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjLod2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLod2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod1DI2( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod1DI4( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod2DI3( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod2DI4( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod1DU2( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod1DU4( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod2DU3( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod2DU4( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLod3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLod3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset1DF2( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset1DF4( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset2DF3( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset2DF4( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjLodOffset1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLodOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjLodOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjLodOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset1DI2( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset1DI4( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset2DI3( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset2DI4( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset1DU2( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset1DU4( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset2DU3( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset2DU4( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjLodOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ lod
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjLodOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( lod )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad3DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradCubeF( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGrad2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGrad1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGrad2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGrad1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGrad1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradCubeArrayF( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad3DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradCubeI( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad3DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradCubeU( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGrad2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGrad2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradCubeArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset1DF( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGradOffset2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGradOffset1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGradOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset1DArrayF( ExprPtr/*sampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGradOffset1DArrayShadowF( ExprPtr/*sampler1DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset1DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureGradOffset2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureGradOffset2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset1DI( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset1DArrayI( ExprPtr/*isampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset1DU( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*float*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset1DArrayU( ExprPtr/*usampler1DArray*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset1DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGradOffset2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGradOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad1DF2( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad1DF4( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DF3( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DF4( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ pDx
		, ExprPtr/*vec3f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad3DF
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjGrad1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGrad1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjGrad2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGrad2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DRectF3( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectF3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DRectF4( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectF4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjGrad2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGrad2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad1DI2( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad1DI4( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DI3( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DI4( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ pDx
		, ExprPtr/*vec3f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad3DI
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DRectI3( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectI3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DRectI4( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectI4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad1DU2( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad1DU4( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ pDx
		, ExprPtr/*float*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DU3( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DU4( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ pDx
		, ExprPtr/*vec3f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad3DU
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DRectU3( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectU3
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGrad2DRectU4( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ pDx
		, ExprPtr/*vec2f*/ pDy )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGrad2DRectU4
			, std::move( texture )
			, std::move( P )
			, std::move( pDx )
			, std::move( pDy ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset1DF2( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DF2
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset1DF4( ExprPtr/*sampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DF4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DF3( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DF3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DF4( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DF4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset3DF( ExprPtr/*sampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset3DF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjGradOffset1DShadowF( ExprPtr/*sampler1DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGradOffset1DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjGradOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGradOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DRectF3( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectF3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DRectF4( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectF4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*float*/ makeTextureProjGradOffset2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eFloat )
			, TextureAccess::eTextureProjGradOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset1DI2( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DI2
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset1DI4( ExprPtr/*isampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DI4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DI3( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DI3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DI4( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DI4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset3DI( ExprPtr/*isampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset3DI
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DRectI3( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectI3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DRectI4( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectI4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset1DU2( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DU2
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset1DU4( ExprPtr/*usampler1D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ dPdx
		, ExprPtr/*float*/ dPdy
		, ExprPtr/*int*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset1DU4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DU3( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DU3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DU4( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DU4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset3DU( ExprPtr/*usampler3D*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec3f*/ dPdx
		, ExprPtr/*vec3f*/ dPdy
		, ExprPtr/*vec3i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset3DU
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DRectU3( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectU3
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureProjGradOffset2DRectU4( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*vec2f*/ dPdx
		, ExprPtr/*vec2f*/ dPdy
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureProjGradOffset2DRectU4
			, std::move( texture )
			, std::move( P )
			, std::move( dPdx )
			, std::move( dPdy )
			, std::move( offset ) );
	}

	// Texture Gather Functions

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DFComp( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DArrayFComp( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherCubeF( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherCubeFComp( ExprPtr/*samplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherCubeArrayF( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeArrayF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherCubeArrayFComp( ExprPtr/*samplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DRectF
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DRectFComp( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DRectFComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherCubeShadowF( ExprPtr/*samplerCubeShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherCubeArrayShadowF( ExprPtr/*samplerCubeArrayShadow*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*float*/ refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherCubeArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGather2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGather2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGather2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGather2DIComp( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGather2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGather2DArrayIComp( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherCubeI( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherCubeIComp( ExprPtr/*isamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherCubeArrayI( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeArrayI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherCubeArrayIComp( ExprPtr/*isamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherCubeArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGather2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DRectI
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGather2DRectIComp( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGather2DRectIComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGather2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGather2DUComp( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGather2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGather2DArrayUComp( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherCubeU( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherCubeUComp( ExprPtr/*usamplerCube*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherCubeArrayU( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeArrayU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherCubeArrayUComp( ExprPtr/*usamplerCubeArray*/ texture
		, ExprPtr/*vec4f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherCubeArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGather2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DRectU
			, std::move( texture )
			, std::move( P ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGather2DRectUComp( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGather2DRectUComp
			, std::move( texture )
			, std::move( P )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DFComp( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DArrayFComp( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DRectFComp( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DRectFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ refZ
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffset2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffset2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffset2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffset2DIComp( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffset2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffset2DArrayIComp( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffset2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffset2DRectIComp( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffset2DRectIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffset2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffset2DUComp( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffset2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffset2DArrayUComp( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffset2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offset ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffset2DRectUComp( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offset
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffset2DRectUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offset )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DF( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DF
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DFComp( ExprPtr/*sampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DArrayF( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DArrayF
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DArrayFComp( ExprPtr/*sampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DArrayFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DRectF( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DRectF
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DRectFComp( ExprPtr/*sampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DRectFComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DShadowF( ExprPtr/*sampler2DShadow*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*float*/ refZ
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DArrayShadowF( ExprPtr/*sampler2DArrayShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DArrayShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4f*/ makeTextureGatherOffsets2DRectShadowF( ExprPtr/*sampler2DRectShadow*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*float*/ refZ
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4F )
			, TextureAccess::eTextureGatherOffsets2DRectShadowF
			, std::move( texture )
			, std::move( P )
			, std::move( refZ )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffsets2DI( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DI
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffsets2DIComp( ExprPtr/*isampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffsets2DArrayI( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DArrayI
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffsets2DArrayIComp( ExprPtr/*isampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DArrayIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffsets2DRectI( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DRectI
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4i*/ makeTextureGatherOffsets2DRectIComp( ExprPtr/*isampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4I )
			, TextureAccess::eTextureGatherOffsets2DRectIComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffsets2DU( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DU
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffsets2DUComp( ExprPtr/*usampler2D*/ texture
		, ExprPtr/*vec2f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffsets2DArrayU( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DArrayU
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffsets2DArrayUComp( ExprPtr/*usampler2DArray*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DArrayUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffsets2DRectU( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DRectU
			, std::move( texture )
			, std::move( P )
			, std::move( offsets ) );
	}

	inline TextureAccessCallPtr/*vec4u*/ makeTextureGatherOffsets2DRectUComp( ExprPtr/*usampler2DRect*/ texture
		, ExprPtr/*vec3f*/ P
		, ExprPtr/*vec2i*/ offsets
		, ExprPtr/*int*/ comp )
	{
		return makeTextureAccessCall( makeType( type::Kind::eVec4U )
			, TextureAccess::eTextureGatherOffsets2DRectUComp
			, std::move( texture )
			, std::move( P )
			, std::move( offsets )
			, std::move( comp ) );
	}
}

#endif
