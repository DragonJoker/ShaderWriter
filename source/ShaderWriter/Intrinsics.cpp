/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Intrinsics.hpp"

namespace sdw
{
	Int bitfieldReverse( Int const & value )
	{
		return getFunctionCall< Int >( "bitfieldReverse"
			, value );
	}

	UInt bitfieldReverse( UInt const & value )
	{
		return getFunctionCall< UInt >( "bitfieldReverse"
			, value );
	}

	Int findMSB( Int value )
	{
		return getFunctionCall< Int >( "findMSB"
			, value );
	}

	Int findMSB( UInt value )
	{
		return getFunctionCall< Int >( "findMSB"
			, value );
	}

	Int textureSize( Sampler1D const & sampler
		, Int const lod )
	{
		return getFunctionCall< Int >( "textureSize"
			, sampler
			, lod );
	}

	IVec2 textureSize( Sampler2D const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	IVec3 textureSize( Sampler3D const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	IVec2 textureSize( SamplerCube const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	IVec2 textureSize( Sampler1DArray const & sampler
		, Int const lod )
	{
		return getFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	IVec3 textureSize( Sampler2DArray const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	IVec3 textureSize( SamplerCubeArray const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Int textureSize( Sampler1DShadow const & sampler
		, Int const lod )
	{
		return getFunctionCall< Int >( "textureSize"
			, sampler
			, lod );
	}

	IVec2 textureSize( Sampler2DShadow const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	IVec2 textureSize( SamplerCubeShadow const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	IVec2 textureSize( Sampler1DArrayShadow const & sampler
		, Int const lod )
	{
		return getFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	IVec3 textureSize( Sampler2DArrayShadow const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	IVec3 textureSize( SamplerCubeArrayShadow const & sampler
		, Int const & lod )
	{
		return getFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Vec4 textureGather( Sampler2D const & sampler
		, Vec2 const & value )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value );
	}

	Vec4 textureGather( Sampler2DArray const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value );
	}

	Vec4 textureGather( SamplerCube const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value );
	}

	Vec4 textureGather( SamplerCubeArray const & sampler
		, Vec4 const & value )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value );
	}

	Vec4 textureGather( Sampler2D const & sampler
		, Vec2 const & value
		, Int const & comp )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, comp );
	}

	Vec4 textureGather( Sampler2DArray const & sampler
		, Vec3 const & value
		, Int const & comp )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, comp );
	}

	Vec4 textureGather( SamplerCube const & sampler
		, Vec3 const & value
		, Int const & comp )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, comp );
	}

	Vec4 textureGather( SamplerCubeArray const & sampler
		, Vec4 const & value
		, Int const & comp )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, comp );
	}

	Vec4 textureGather( Sampler2DShadow const & sampler
		, Vec3 const & value
		, Float const & refZ )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, refZ );
	}

	Vec4 textureGather( Sampler2DArrayShadow const & sampler
		, Vec3 const & value
		, Float const & refZ )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, refZ );
	}

	Vec4 textureGather( SamplerCubeShadow const & sampler
		, Vec3 const & value
		, Float const & refZ )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, refZ );
	}

	Vec4 textureGather( SamplerCubeArrayShadow const & sampler
		, Vec4 const & value
		, Float const & refZ )
	{
		return getFunctionCall< Vec4 >( "textureGather"
			, sampler
			, value
			, refZ );
	}

	Vec4 texture( Sampler1D const & sampler
		, Float const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( Sampler1D const & sampler
		, Float const & value
		, Float const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 texture( Sampler2D const & sampler
		, Vec2 const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( Sampler2D const & sampler
		, Vec2 const & value
		, Float const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 texture( Sampler3D const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( Sampler3D const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 texture( SamplerCube const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( SamplerCube const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 textureOffset( Sampler1D const & sampler
		, Float const & value
		, Int const offset )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Vec4 textureOffset( Sampler1D const & sampler
		, Float const & value
		, Int const offset
		, Float const & bias )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Vec4 textureOffset( Sampler2D const & sampler
		, Vec2 const & value
		, IVec2 const offset )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Vec4 textureOffset( Sampler2D const & sampler
		, Vec2 const & value
		, IVec2 const offset
		, Float const & bias )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Vec4 textureOffset( Sampler3D const & sampler
		, Vec3 const & value
		, IVec3 const offset )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Vec4 textureOffset( Sampler3D const & sampler
		, Vec3 const & value
		, IVec3 const offset
		, Float const & bias )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Vec4 textureLodOffset( Sampler1D const & sampler
		, Float const & value
		, Float const & lod
		, Int const offset )
	{
		return getFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Vec4 textureLodOffset( Sampler2D const & sampler
		, Vec2 const & value
		, Float const & lod
		, IVec2 const offset )
	{
		return getFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Vec4 textureLodOffset( Sampler3D const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec3 const offset )
	{
		return getFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Vec4 texelFetch( SamplerBuffer const & sampler
		, Value const & value )
	{
		return getFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value );
	}

	Vec4 texelFetch( Sampler1D const & sampler
		, Value const & value
		, Int const & modif )
	{
		return getFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value
			, modif );
	}

	Vec4 texelFetch( Sampler2D const & sampler
		, Value const & value
		, Int const & modif )
	{
		return getFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value
			, modif );
	}

	Vec4 texelFetch( Sampler3D const & sampler
		, Value const & value
		, Int const & modif )
	{
		return getFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value
			, modif );
	}

	Vec4 texture( Sampler1DArray const & sampler
		, Vec2 const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( Sampler1DArray const & sampler
		, Vec2 const & value
		, Float const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 texture( Sampler2DArray const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( Sampler2DArray const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 texture( SamplerCubeArray const & sampler
		, Vec4 const & value )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Vec4 texture( SamplerCubeArray const & sampler
		, Vec4 const & value
		, Vec4 const & lod )
	{
		return getFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Vec4 textureOffset( Sampler1DArray const & sampler
		, Vec2 const & value
		, Int const offset )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Vec4 textureOffset( Sampler1DArray const & sampler
		, Vec2 const & value
		, Int const offset
		, Vec4 const & bias )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Vec4 textureOffset( Sampler2DArray const & sampler
		, Vec3 const & value
		, IVec2 const offset )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Vec4 textureOffset( Sampler2DArray const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Vec4 const & bias )
	{
		return getFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Vec4 textureLodOffset( Sampler1DArray const & sampler
		, Vec2 const & value
		, Vec4 const & lod
		, Int const offset )
	{
		return getFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Vec4 textureLodOffset( Sampler2DArray const & sampler
		, Vec3 const & value
		, Vec4 const & lod
		, IVec2 const offset )
	{
		return getFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Float texture( Sampler1DShadow const & sampler
		, Vec2 const & value )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Float texture( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Float const & lod )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Float texture( Sampler2DShadow const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Float texture( Sampler2DShadow const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Float texture( SamplerCubeShadow const & sampler
		, Vec4 const & value )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Float texture( SamplerCubeShadow const & sampler
		, Vec4 const & value
		, Float const & lod )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Float textureOffset( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Int const offset )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Float textureOffset( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Int const offset
		, Float const & bias )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Float textureOffset( Sampler2DShadow const & sampler
		, Vec3 const & value
		, IVec2 const offset )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Float textureOffset( Sampler2DShadow const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Float const & bias )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Float textureLodOffset( Sampler1DShadow const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset )
	{
		return getFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Float textureLodOffset( Sampler2DShadow const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec2 const offset )
	{
		return getFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Float texture( Sampler1DArrayShadow const & sampler
		, Vec3 const & value )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Float texture( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Float texture( Sampler2DArrayShadow const & sampler
		, Vec4 const & value )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Float texture( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, Float const & lod )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Float texture( SamplerCubeArrayShadow const & sampler
		, Vec4 const & value
		, Float const & layer )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, layer );
	}

	Float texture( SamplerCubeArrayShadow const & sampler
		, Vec4 const & value
		, Float const & layer
		, Float const & lod )
	{
		return getFunctionCall< Float >( "texture"
			, sampler
			, value
			, layer
			, lod );
	}

	Float textureOffset( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Int const offset )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Float textureOffset( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Int const offset
		, Float const & bias )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Float textureOffset( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, IVec2 const offset )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Float textureOffset( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, IVec2 const offset
		, Float const & bias )
	{
		return getFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Float textureLodOffset( Sampler1DArrayShadow const & sampler
		, Vec3 const & value
		, Float const & lod
		, Int const offset )
	{
		return getFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Float textureLodOffset( Sampler2DArrayShadow const & sampler
		, Vec4 const & value
		, Float const & lod
		, IVec2 const offset )
	{
		return getFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Vec2 reflect( Vec2 const & incident
		, Vec2 const & normal )
	{
		return getFunctionCall< Vec2 >( "reflect"
			, incident
			, normal );
	}

	Vec3 reflect( Vec3 const & incident
		, Vec3 const & normal )
	{
		return getFunctionCall< Vec3 >( "reflect"
			, incident
			, normal );
	}

	Vec4 reflect( Vec4 const & incident
		, Vec4 const & normal )
	{
		return getFunctionCall< Vec4 >( "reflect"
			, incident
			, normal );
	}

	Vec2 refract( Vec2 const & incident
		, Vec2 const & normal
		, Float const & ratio )
	{
		return getFunctionCall< Vec2 >( "refract"
			, incident
			, normal
			, ratio );
	}

	Vec3 refract( Vec3 const & incident
		, Vec3 const & normal
		, Float const & ratio )
	{
		return getFunctionCall< Vec3 >( "refract"
			, incident
			, normal
			, ratio );
	}

	Vec4 refract( Vec4 const & incident
		, Vec4 const & normal
		, Float const & ratio )
	{
		return getFunctionCall< Vec4 >( "refract"
			, incident
			, normal
			, ratio );
	}

	Float length( Value const & value )
	{
		return getFunctionCall< Float >( "length"
			, value );
	}

	Float distance( Value const & lhs
		, Value const & rhs )
	{
		return getFunctionCall< Float >( "distance"
			, lhs
			, rhs );
	}

	Float radians( Value const & value )
	{
		return getFunctionCall< Float >( "radians"
			, value );
	}

	Float cos( Value const & value )
	{
		return getFunctionCall< Float >( "cos"
			, value );
	}

	Float sin( Value const & value )
	{
		return getFunctionCall< Float >( "sin"
			, value );
	}

	Float tan( Value const & value )
	{
		return getFunctionCall< Float >( "tan"
			, value );
	}

	Optional< Int > textureSize( Optional< Sampler1D > const & sampler
		, Int const lod )
	{
		return getOptFunctionCall< Int >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec2 > textureSize( Optional< Sampler2D > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec3 > textureSize( Optional< Sampler3D > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec2 > textureSize( Optional< SamplerCube > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec2 > textureSize( Optional< Sampler1DArray > const & sampler
		, Int const lod )
	{
		return getOptFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec3 > textureSize( Optional< Sampler2DArray > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec3 > textureSize( Optional< SamplerCubeArray > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< Int > textureSize( Optional< Sampler1DShadow > const & sampler
		, Int const lod )
	{
		return getOptFunctionCall< Int >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec2 > textureSize( Optional< Sampler2DShadow > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec2 > textureSize( Optional< SamplerCubeShadow > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec2 > textureSize( Optional< Sampler1DArrayShadow > const & sampler
		, Int const lod )
	{
		return getOptFunctionCall< IVec2 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec3 > textureSize( Optional< Sampler2DArrayShadow > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< IVec3 > textureSize( Optional< SamplerCubeArrayShadow > const & sampler
		, Int const & lod )
	{
		return getOptFunctionCall< IVec3 >( "textureSize"
			, sampler
			, lod );
	}

	Optional< Vec4 > texture( Optional< Sampler1D > const & sampler
		, Float const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< Sampler1D > const & sampler
		, Float const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > texture( Optional< Sampler2D > const & sampler
		, Vec2 const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > texture( Optional< Sampler3D > const & sampler
		, Vec3 const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > texture( Optional< SamplerCube > const & sampler
		, Vec3 const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< SamplerCube > const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler1D > const & sampler
		, Float const & value
		, Int const & offset )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler1D > const & sampler
		, Float const & value
		, Int const & offset
		, Float const & bias )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, IVec2 const & offset )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, IVec2 const & offset
		, Float const & bias )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, IVec3 const & offset )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, IVec3 const & offset
		, Float const & bias )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Vec4 > textureLodOffset( Optional< Sampler1D > const & sampler
		, Float const & value
		, Float const & lod
		, Int const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Vec4 > textureLodOffset( Optional< Sampler2D > const & sampler
		, Vec2 const & value
		, Float const & lod
		, IVec2 const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Vec4 > textureLodOffset( Optional< Sampler3D > const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec3 const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Vec4 > texelFetch( Optional< SamplerBuffer > const & sampler
		, Value const & value )
	{
		return getOptFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value );
	}

	Optional< Vec4 > texelFetch( Optional< Sampler1D > const & sampler
		, Value const & value
		, Int const & modif )
	{
		return getOptFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value
			, modif );
	}

	Optional< Vec4 > texelFetch( Optional< Sampler2D > const & sampler
		, Value const & value
		, Int const & modif )
	{
		return getOptFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value
			, modif );
	}

	Optional< Vec4 > texelFetch( Optional< Sampler3D > const & sampler
		, Value const & value
		, Int const & modif )
	{
		return getOptFunctionCall< Vec4 >( "texelFetch"
			, sampler
			, value
			, modif );
	}

	Optional< Vec4 > texture( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Vec4 const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > texture( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, Vec4 const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > texture( Optional< SamplerCubeArray > const & sampler
		, Vec4 const & value )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value );
	}

	Optional< Vec4 > texture( Optional< SamplerCubeArray > const & sampler
		, Vec4 const & value
		, Vec4 const & lod )
	{
		return getOptFunctionCall< Vec4 >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Int const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Int const offset
		, Vec4 const & bias )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, IVec2 const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Vec4 > textureOffset( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Vec4 const & bias )
	{
		return getOptFunctionCall< Vec4 >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Vec4 > textureLodOffset( Optional< Sampler1DArray > const & sampler
		, Vec2 const & value
		, Vec4 const & lod
		, Int const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Vec4 > textureLodOffset( Optional< Sampler2DArray > const & sampler
		, Vec3 const & value
		, Vec4 const & lod
		, IVec2 const offset )
	{
		return getOptFunctionCall< Vec4 >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Float > texture( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Optional< Float > texture( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Float > texture( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Optional< Float > texture( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Float > texture( Optional< SamplerCubeShadow > const & sampler
		, Vec4 const & value )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Optional< Float > texture( Optional< SamplerCubeShadow > const & sampler
		, Vec4 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Float > textureOffset( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Int const offset )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );

	}

	Optional< Float > textureOffset( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Int const offset
		, Float const & bias )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Float > textureOffset( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, IVec2 const offset )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Float > textureOffset( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, IVec2 const offset
		, Float const & bias )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Float > textureLodOffset( Optional< Sampler1DShadow > const & sampler
		, Vec2 const & value
		, Float const & lod
		, Int const offset )
	{
		return getOptFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Float > textureLodOffset( Optional< Sampler2DShadow > const & sampler
		, Vec3 const & value
		, Float const & lod
		, IVec2 const offset )
	{
		return getOptFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Float > texture( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Optional< Float > texture( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Float > texture( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value );
	}

	Optional< Float > texture( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & lod )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, lod );
	}

	Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & layer )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, layer );
	}

	Optional< Float > texture( Optional< SamplerCubeArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & layer
		, Float const & lod )
	{
		return getOptFunctionCall< Float >( "texture"
			, sampler
			, value
			, layer
			, lod );
	}

	Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Int const offset )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Float > textureOffset( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Int const offset
		, Float const & bias )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, IVec2 const offset )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset );
	}

	Optional< Float > textureOffset( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, IVec2 const offset
		, Float const & bias )
	{
		return getOptFunctionCall< Float >( "textureOffset"
			, sampler
			, value
			, offset
			, bias );
	}

	Optional< Float > textureLodOffset( Optional< Sampler1DArrayShadow > const & sampler
		, Vec3 const & value
		, Float const & lod
		, Int const offset )
	{
		return getOptFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Float > textureLodOffset( Optional< Sampler2DArrayShadow > const & sampler
		, Vec4 const & value
		, Float const & lod
		, IVec2 const offset )
	{
		return getOptFunctionCall< Float >( "textureLodOffset"
			, sampler
			, value
			, lod
			, offset );
	}

	Optional< Vec2 > reflect( Optional< Vec2 > const & lhs
		, Value const & rhs )
	{
		return getOptFunctionCall< Vec2 >( "reflect"
			, lhs
			, rhs );
	}

	Optional< Vec3 > reflect( Optional< Vec3 > const & lhs
		, Value const & rhs )
	{
		return getOptFunctionCall< Vec3 >( "reflect"
			, lhs
			, rhs );
	}

	Optional< Vec4 > reflect( Optional< Vec4 > const & lhs
		, Value const & rhs )
	{
		return getOptFunctionCall< Vec4 >( "reflect"
			, lhs
			, rhs );
	}

	Optional< Float > length( Optional< Value > const & value )
	{
		return getOptFunctionCall< Float >( "length"
			, value );
	}

	Optional< Float > radians( Optional< Value > const & value )
	{
		return getOptFunctionCall< Float >( "radians"
			, value );
	}

	Optional< Float > cos( Optional< Value > const & value )
	{
		return getOptFunctionCall< Float >( "cos"
			, value );
	}

	Optional< Float > sin( Optional< Value > const & value )
	{
		return getOptFunctionCall< Float >( "sin"
			, value );
	}

	Optional< Float > tan( Optional< Value > const & value )
	{
		return getOptFunctionCall< Float >( "tan"
			, value );
	}
}
