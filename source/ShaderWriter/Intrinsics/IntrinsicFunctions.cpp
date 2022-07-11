/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#include "ShaderWriter/BaseTypes/AccelerationStructure.hpp"
#include "ShaderWriter/BaseTypes/Void.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Boolean.hpp"
#include "ShaderWriter/BaseTypes/Double.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

#include <ShaderAST/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region degrees
	/**
	*name
	*	degrees
	*/
	/**@{*/
	RetFloat degrees( Float const radians )
	{
		return RetFloat{ *findWriter( radians )
			, expr::makeDegrees1( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	RetVec2 degrees( Vec2 const radians )
	{
		return RetVec2{ *findWriter( radians )
			, expr::makeDegrees2( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	RetVec3 degrees( Vec3 const radians )
	{
		return RetVec3{ *findWriter( radians )
			, expr::makeDegrees3( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	RetVec4 degrees( Vec4 const radians )
	{
		return RetVec4{ *findWriter( radians )
			, expr::makeDegrees4( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	RetFloat radians( Float const degrees )
	{
		return RetFloat{ *findWriter( degrees )
			, expr::makeRadians1F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	RetVec2 radians( Vec2 const degrees )
	{
		return RetVec2{ *findWriter( degrees )
			, expr::makeRadians2F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	RetVec3 radians( Vec3 const degrees )
	{
		return RetVec3{ *findWriter( degrees )
			, expr::makeRadians3F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	RetVec4 radians( Vec4 const degrees )
	{
		return RetVec4{ *findWriter( degrees )
			, expr::makeRadians4F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	RetFloat cos( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeCos1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 cos( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeCos2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 cos( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeCos3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 cos( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeCos4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	RetFloat sin( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeSin1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sin( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSin2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sin( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSin3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sin( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSin4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	RetFloat tan( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeTan1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 tan( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeTan2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 tan( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeTan3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 tan( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeTan4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	RetFloat cosh( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeCosh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 cosh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeCosh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 cosh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeCosh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 cosh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeCosh4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	RetFloat sinh( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeSinh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sinh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSinh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sinh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSinh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sinh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSinh4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	RetFloat tanh( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeTanh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 tanh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeTanh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 tanh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeTanh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 tanh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeTanh4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	RetFloat acos( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeAcos1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 acos( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAcos2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 acos( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAcos3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 acos( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAcos4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	RetFloat asin( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeAsin1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 asin( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAsin2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 asin( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAsin3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 asin( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAsin4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	RetFloat atan( Float const y_over_x )
	{
		return RetFloat{ *findWriter( y_over_x )
			, expr::makeAtan1( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	RetVec2 atan( Vec2 const y_over_x )
	{
		return RetVec2{ *findWriter( y_over_x )
			, expr::makeAtan2( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	RetVec3 atan( Vec3 const y_over_x )
	{
		return RetVec3{ *findWriter( y_over_x )
			, expr::makeAtan3( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	RetVec4 atan( Vec4 const y_over_x )
	{
		return RetVec4{ *findWriter( y_over_x )
			, expr::makeAtan4( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	/**@}*/
#pragma endregion
#pragma region atan2
	/**
	*name
	*	atan2
	*/
	/**@{*/
	RetFloat atan2( Float const y
		, Float const x )
	{
		return RetFloat{ *findWriter( y, x )
			, expr::makeAtan21( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	RetVec2 atan2( Vec2 const y
		, Vec2 const x )
	{
		return RetVec2{ *findWriter( y, x )
			, expr::makeAtan22( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	RetVec3 atan2( Vec3 const y
		, Vec3 const x )
	{
		return RetVec3{ *findWriter( y, x )
			, expr::makeAtan23( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	RetVec4 atan2( Vec4 const y
		, Vec4 const x )
	{
		return RetVec4{ *findWriter( y, x )
			, expr::makeAtan24( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	RetFloat acosh( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeAcosh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 acosh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAcosh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 acosh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAcosh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 acosh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAcosh4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	RetFloat asinh( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeAsinh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 asinh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAsinh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 asinh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAsinh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 asinh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAsinh4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	RetFloat atanh( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeAtanh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 atanh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAtanh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 atanh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAtanh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 atanh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAtanh4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	RetFloat pow( Float const x
		, Float const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makePow1( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 pow( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makePow2( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 pow( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makePow3( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 pow( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makePow4( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region exp
	/**
	*name
	*	exp
	*/
	/**@{*/
	RetFloat exp( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeExp1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 exp( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeExp2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 exp( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeExp3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 exp( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeExp4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	RetFloat log( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLog1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 log( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeLog2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 log( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeLog3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 log( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeLog4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	RetFloat exp2( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeExp21( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 exp2( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeExp22( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 exp2( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeExp23( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 exp2( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeExp24( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	RetFloat log2( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLog21( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 log2( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeLog22( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 log2( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeLog23( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 log2( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeLog24( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	RetFloat sqrt( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeSqrt1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sqrt( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSqrt2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sqrt( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSqrt3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sqrt( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSqrt4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble sqrt( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeSqrt1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 sqrt( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeSqrt2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 sqrt( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeSqrt3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 sqrt( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeSqrt4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	RetFloat inverseSqrt( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeInverseSqrt1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 inverseSqrt( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeInverseSqrt2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 inverseSqrt( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeInverseSqrt3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 inverseSqrt( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeInverseSqrt4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble inverseSqrt( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeInverseSqrt1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 inverseSqrt( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeInverseSqrt2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 inverseSqrt( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeInverseSqrt3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 inverseSqrt( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeInverseSqrt4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	RetFloat abs( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeAbs1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 abs( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAbs2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 abs( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAbs3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 abs( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAbs4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetInt abs( Int const x )
	{
		return RetInt{ *findWriter( x )
			, expr::makeAbs1I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetIVec2 abs( IVec2 const x )
	{
		return RetIVec2{ *findWriter( x )
			, expr::makeAbs2I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetIVec3 abs( IVec3 const x )
	{
		return RetIVec3{ *findWriter( x )
			, expr::makeAbs3I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetIVec4 abs( IVec4 const x )
	{
		return RetIVec4{ *findWriter( x )
			, expr::makeAbs4I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble abs( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeAbs1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 abs( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeAbs2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 abs( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeAbs3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 abs( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeAbs4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	RetFloat sign( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeSign1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sign( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSign2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sign( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSign3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sign( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSign4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetInt sign( Int const x )
	{
		return RetInt{ *findWriter( x )
			, expr::makeSign1I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetIVec2 sign( IVec2 const x )
	{
		return RetIVec2{ *findWriter( x )
			, expr::makeSign2I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetIVec3 sign( IVec3 const x )
	{
		return RetIVec3{ *findWriter( x )
			, expr::makeSign3I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetIVec4 sign( IVec4 const x )
	{
		return RetIVec4{ *findWriter( x )
			, expr::makeSign4I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble sign( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeSign1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 sign( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeSign2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 sign( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeSign3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 sign( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeSign4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	RetFloat floor( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeFloor1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 floor( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeFloor2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 floor( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeFloor3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 floor( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeFloor4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble floor( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeFloor1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 floor( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeFloor2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 floor( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeFloor3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 floor( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeFloor4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	RetFloat trunc( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeTrunc1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 trunc( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeTrunc2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 trunc( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeTrunc3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 trunc( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeTrunc4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble trunc( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeTrunc1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 trunc( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeTrunc2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 trunc( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeTrunc3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 trunc( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeTrunc4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	RetFloat round( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeRound1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 round( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeRound2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 round( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeRound3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 round( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeRound4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble round( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeRound1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 round( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeRound2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 round( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeRound3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 round( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeRound4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	RetFloat roundEven( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeRoundEven1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 roundEven( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeRoundEven2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 roundEven( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeRoundEven3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 roundEven( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeRoundEven4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble roundEven( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeRoundEven1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 roundEven( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeRoundEven2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 roundEven( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeRoundEven3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 roundEven( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeRoundEven4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	RetFloat ceil( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeCeil1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 ceil( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeCeil2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 ceil( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeCeil3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 ceil( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeCeil4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble ceil( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeCeil1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 ceil( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeCeil2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 ceil( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeCeil3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 ceil( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeCeil4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	RetFloat fract( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeFract1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 fract( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeFract2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 fract( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeFract3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 fract( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeFract4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble fract( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeFract1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 fract( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeFract2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 fract( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeFract3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 fract( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeFract4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	RetFloat mod( Float const x
		, Float const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeMod1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 mod( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makeMod2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 mod( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeMod3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 mod( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makeMod4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble mod( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeMod1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec2 mod( DVec2 const x
		, DVec2 const y )
	{
		return RetDVec2{ *findWriter( x, y )
			, expr::makeMod2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 mod( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeMod3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec4 mod( DVec4 const x
		, DVec4 const y )
	{
		return RetDVec4{ *findWriter( x, y )
			, expr::makeMod4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region modf
	/**
	*name
	*	modf
	*/
	/**@{*/
	RetFloat modf( Float const x
		, Float const i )
	{
		return RetFloat{ *findWriter( x, i )
			, expr::makeModf1F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetVec2 modf( Vec2 const x
		, Vec2 const i )
	{
		return RetVec2{ *findWriter( x, i )
			, expr::makeModf2F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetVec3 modf( Vec3 const x
		, Vec3 const i )
	{
		return RetVec3{ *findWriter( x, i )
			, expr::makeModf3F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetVec4 modf( Vec4 const x
		, Vec4 const i )
	{
		return RetVec4{ *findWriter( x, i )
			, expr::makeModf4F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDouble modf( Double const x
		, Double const i )
	{
		return RetDouble{ *findWriter( x, i )
			, expr::makeModf1D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDVec2 modf( DVec2 const x
		, DVec2 const i )
	{
		return RetDVec2{ *findWriter( x, i )
			, expr::makeModf2D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDVec3 modf( DVec3 const x
		, DVec3 const i )
	{
		return RetDVec3{ *findWriter( x, i )
			, expr::makeModf3D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDVec4 modf( DVec4 const x
		, DVec4 const i )
	{
		return RetDVec4{ *findWriter( x, i )
			, expr::makeModf4D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	/**@}*/
#pragma endregion
#pragma region min
	/**
	*name
	*	min
	*/
	/**@{*/
	RetFloat min( Float const x
		, Float const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeMin1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 min( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makeMin2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 min( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeMin3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 min( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makeMin4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble min( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeMin1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec2 min( DVec2 const x
		, DVec2 const y )
	{
		return RetDVec2{ *findWriter( x, y )
			, expr::makeMin2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 min( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeMin3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec4 min( DVec4 const x
		, DVec4 const y )
	{
		return RetDVec4{ *findWriter( x, y )
			, expr::makeMin4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetInt min( Int const x
		, Int const y )
	{
		return RetInt{ *findWriter( x, y )
			, expr::makeMin1I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetIVec2 min( IVec2 const x
		, IVec2 const y )
	{
		return RetIVec2{ *findWriter( x, y )
			, expr::makeMin2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetIVec3 min( IVec3 const x
		, IVec3 const y )
	{
		return RetIVec3{ *findWriter( x, y )
			, expr::makeMin3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetIVec4 min( IVec4 const x
		, IVec4 const y )
	{
		return RetIVec4{ *findWriter( x, y )
			, expr::makeMin4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUInt min( UInt const x
		, UInt const y )
	{
		return RetUInt{ *findWriter( x, y )
			, expr::makeMin1U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUVec2 min( UVec2 const x
		, UVec2 const y )
	{
		return RetUVec2{ *findWriter( x, y )
			, expr::makeMin2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUVec3 min( UVec3 const x
		, UVec3 const y )
	{
		return RetUVec3{ *findWriter( x, y )
			, expr::makeMin3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUVec4 min( UVec4 const x
		, UVec4 const y )
	{
		return RetUVec4{ *findWriter( x, y )
			, expr::makeMin4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region max
	/**
	*name
	*	max
	*/
	/**@{*/
	RetFloat max( Float const x
		, Float const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeMax1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 max( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makeMax2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 max( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeMax3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 max( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makeMax4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble max( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeMax1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec2 max( DVec2 const x
		, DVec2 const y )
	{
		return RetDVec2{ *findWriter( x, y )
			, expr::makeMax2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 max( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeMax3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec4 max( DVec4 const x
		, DVec4 const y )
	{
		return RetDVec4{ *findWriter( x, y )
			, expr::makeMax4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetInt max( Int const x
		, Int const y )
	{
		return RetInt{ *findWriter( x, y )
			, expr::makeMax1I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetIVec2 max( IVec2 const x
		, IVec2 const y )
	{
		return RetIVec2{ *findWriter( x, y )
			, expr::makeMax2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetIVec3 max( IVec3 const x
		, IVec3 const y )
	{
		return RetIVec3{ *findWriter( x, y )
			, expr::makeMax3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetIVec4 max( IVec4 const x
		, IVec4 const y )
	{
		return RetIVec4{ *findWriter( x, y )
			, expr::makeMax4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUInt max( UInt const x
		, UInt const y )
	{
		return RetUInt{ *findWriter( x, y )
			, expr::makeMax1U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUVec2 max( UVec2 const x
		, UVec2 const y )
	{
		return RetUVec2{ *findWriter( x, y )
			, expr::makeMax2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUVec3 max( UVec3 const x
		, UVec3 const y )
	{
		return RetUVec3{ *findWriter( x, y )
			, expr::makeMax3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUVec4 max( UVec4 const x
		, UVec4 const y )
	{
		return RetUVec4{ *findWriter( x, y )
			, expr::makeMax4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region clamp
	/**
	*name
	*	clamp
	*/
	/**@{*/
	RetFloat clamp( Float const x
		, Float const minVal
		, Float const maxVal )
	{
		return RetFloat{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetVec2 clamp( Vec2 const x
		, Vec2 const minVal
		, Vec2 const maxVal )
	{
		return RetVec2{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetVec3 clamp( Vec3 const x
		, Vec3 const minVal
		, Vec3 const maxVal )
	{
		return RetVec3{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetVec4 clamp( Vec4 const x
		, Vec4 const minVal
		, Vec4 const maxVal )
	{
		return RetVec4{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetDouble clamp( Double const x
		, Double const minVal
		, Double const maxVal )
	{
		return RetDouble{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetDVec2 clamp( DVec2 const x
		, DVec2 const minVal
		, DVec2 const maxVal )
	{
		return RetDVec2{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetDVec3 clamp( DVec3 const x
		, DVec3 const minVal
		, DVec3 const maxVal )
	{
		return RetDVec3{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetDVec4 clamp( DVec4 const x
		, DVec4 const minVal
		, DVec4 const maxVal )
	{
		return RetDVec4{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetInt clamp( Int const x
		, Int const minVal
		, Int const maxVal )
	{
		return RetInt{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetIVec2 clamp( IVec2 const x
		, IVec2 const minVal
		, IVec2 const maxVal )
	{
		return RetIVec2{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetIVec3 clamp( IVec3 const x
		, IVec3 const minVal
		, IVec3 const maxVal )
	{
		return RetIVec3{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetIVec4 clamp( IVec4 const x
		, IVec4 const minVal
		, IVec4 const maxVal )
	{
		return RetIVec4{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetUInt clamp( UInt const x
		, UInt const minVal
		, UInt const maxVal )
	{
		return RetUInt{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetUVec2 clamp( UVec2 const x
		, UVec2 const minVal
		, UVec2 const maxVal )
	{
		return RetUVec2{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetUVec3 clamp( UVec3 const x
		, UVec3 const minVal
		, UVec3 const maxVal )
	{
		return RetUVec3{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetUVec4 clamp( UVec4 const x
		, UVec4 const minVal
		, UVec4 const maxVal )
	{
		return RetUVec4{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	/**@}*/
#pragma endregion
#pragma region mix
	/**
	*name
	*	mix
	*/
	/**@{*/
	RetFloat mix( Float const x
		, Float const y
		, Float const a )
	{
		return RetFloat{ *findWriter( x, y, a )
			, expr::makeMix1F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetVec2 mix( Vec2 const x
		, Vec2 const y
		, Vec2 const a )
	{
		return RetVec2{ *findWriter( x, y, a )
			, expr::makeMix2F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetVec3 mix( Vec3 const x
		, Vec3 const y
		, Vec3 const a )
	{
		return RetVec3{ *findWriter( x, y, a )
			, expr::makeMix3F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetVec4 mix( Vec4 const x
		, Vec4 const y
		, Vec4 const a )
	{
		return RetVec4{ *findWriter( x, y, a )
			, expr::makeMix4F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetDouble mix( Double const x
		, Double const y
		, Double const a )
	{
		return RetDouble{ *findWriter( x, y, a )
			, expr::makeMix1D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetDVec2 mix( DVec2 const x
		, DVec2 const y
		, DVec2 const a )
	{
		return RetDVec2{ *findWriter( x, y, a )
			, expr::makeMix2D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetDVec3 mix( DVec3 const x
		, DVec3 const y
		, DVec3 const a )
	{
		return RetDVec3{ *findWriter( x, y, a )
			, expr::makeMix3D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	RetDVec4 mix( DVec4 const x
		, DVec4 const y
		, DVec4 const a )
	{
		return RetDVec4{ *findWriter( x, y, a )
			, expr::makeMix4D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	/**@}*/
#pragma endregion
#pragma region step
	/**
	*name
	*	step
	*/
	/**@{*/
	RetFloat step( Float const edge
		, Float const x )
	{
		return RetFloat{ *findWriter( edge, x )
			, expr::makeStep1F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetVec2 step( Vec2 const edge
		, Vec2 const x )
	{
		return RetVec2{ *findWriter( edge, x )
			, expr::makeStep2F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetVec3 step( Vec3 const edge
		, Vec3 const x )
	{
		return RetVec3{ *findWriter( edge, x )
			, expr::makeStep3F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetVec4 step( Vec4 const edge
		, Vec4 const x )
	{
		return RetVec4{ *findWriter( edge, x )
			, expr::makeStep4F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDouble step( Double const edge
		, Double const x )
	{
		return RetDouble{ *findWriter( edge, x )
			, expr::makeStep1D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDVec2 step( DVec2 const edge
		, DVec2 const x )
	{
		return RetDVec2{ *findWriter( edge, x )
			, expr::makeStep2D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDVec3 step( DVec3 const edge
		, DVec3 const x )
	{
		return RetDVec3{ *findWriter( edge, x )
			, expr::makeStep3D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDVec4 step( DVec4 const edge
		, DVec4 const x )
	{
		return RetDVec4{ *findWriter( edge, x )
			, expr::makeStep4D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	/**@}*/
#pragma endregion
#pragma region smoothStep
	/**
	*name
	*	smoothStep
	*/
	/**@{*/
	RetFloat smoothStep( Float const edge0
		, Float const edge1
		, Float const x )
	{
		return RetFloat{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep1F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetVec2 smoothStep( Vec2 const edge0
		, Vec2 const edge1
		, Vec2 const x )
	{
		return RetVec2{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep2F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetVec3 smoothStep( Vec3 const edge0
		, Vec3 const edge1
		, Vec3 const x )
	{
		return RetVec3{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep3F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetVec4 smoothStep( Vec4 const edge0
		, Vec4 const edge1
		, Vec4 const x )
	{
		return RetVec4{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep4F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetDouble smoothStep( Double const edge0
		, Double const edge1
		, Double const x )
	{
		return RetDouble{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep1D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetDVec2 smoothStep( DVec2 const edge0
		, DVec2 const edge1
		, DVec2 const x )
	{
		return RetDVec2{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep2D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetDVec3 smoothStep( DVec3 const edge0
		, DVec3 const edge1
		, DVec3 const x )
	{
		return RetDVec3{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep3D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	RetDVec4 smoothStep( DVec4 const edge0
		, DVec4 const edge1
		, DVec4 const x )
	{
		return RetDVec4{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep4D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	/**@}*/
#pragma endregion
#pragma region isnan
	/**
	*name
	*	isnan
	*/
	/**@{*/
	RetBoolean isnan( Float const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeIsnan1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isnan( Vec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsnan2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isnan( Vec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsnan3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isnan( Vec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsnan4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean isnan( Double const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeIsnan1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isnan( DVec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsnan2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isnan( DVec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsnan3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isnan( DVec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsnan4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	RetBoolean isinf( Float const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeIsinf1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isinf( Vec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsinf2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isinf( Vec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsinf3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isinf( Vec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsinf4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean isinf( Double const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeIsinf1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isinf( DVec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsinf2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isinf( DVec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsinf3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isinf( DVec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsinf4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	RetInt floatBitsToInt( Float const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeFloatBitsToInt1( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 floatBitsToInt( Vec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeFloatBitsToInt2( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 floatBitsToInt( Vec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeFloatBitsToInt3( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 floatBitsToInt( Vec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeFloatBitsToInt4( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	RetUInt floatBitsToUInt( Float const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeFloatBitsToUInt1( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 floatBitsToUInt( Vec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeFloatBitsToUInt2( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 floatBitsToUInt( Vec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeFloatBitsToUInt3( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 floatBitsToUInt( Vec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeFloatBitsToUInt4( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	RetFloat intBitsToFloat( Int const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeIntBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 intBitsToFloat( IVec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeIntBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 intBitsToFloat( IVec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeIntBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 intBitsToFloat( IVec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeIntBitsToFloat4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	RetFloat uintBitsToFloat( UInt const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeUintBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 uintBitsToFloat( UVec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeUintBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 uintBitsToFloat( UVec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeUintBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 uintBitsToFloat( UVec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeUintBitsToFloat4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	RetFloat fma( Float const a
		, Float const b
		, Float const c )
	{
		return RetFloat{ *findWriter( a, b, c )
			, expr::makeFma1F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetVec2 fma( Vec2 const a
		, Vec2 const b
		, Vec2 const c )
	{
		return RetVec2{ *findWriter( a, b, c )
			, expr::makeFma2F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetVec3 fma( Vec3 const a
		, Vec3 const b
		, Vec3 const c )
	{
		return RetVec3{ *findWriter( a, b, c )
			, expr::makeFma3F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetVec4 fma( Vec4 const a
		, Vec4 const b
		, Vec4 const c )
	{
		return RetVec4{ *findWriter( a, b, c )
			, expr::makeFma4F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetDouble fma( Double const a
		, Double const b
		, Double const c )
	{
		return RetDouble{ *findWriter( a, b, c )
			, expr::makeFma1D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetDVec2 fma( DVec2 const a
		, DVec2 const b
		, DVec2 const c )
	{
		return RetDVec2{ *findWriter( a, b, c )
			, expr::makeFma2D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetDVec3 fma( DVec3 const a
		, DVec3 const b
		, DVec3 const c )
	{
		return RetDVec3{ *findWriter( a, b, c )
			, expr::makeFma3D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	RetDVec4 fma( DVec4 const a
		, DVec4 const b
		, DVec4 const c )
	{
		return RetDVec4{ *findWriter( a, b, c )
			, expr::makeFma4D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	/**@}*/
#pragma endregion
#pragma region frexp
	/**
	*name
	*	frexp
	*/
	/**@{*/
	RetFloat frexp( Float const x
		, Int  exp )
	{
		return RetFloat{ *findWriter( x, exp )
			, expr::makeFrexp1F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec2 frexp( Vec2 const x
		, IVec2  exp )
	{
		return RetVec2{ *findWriter( x, exp )
			, expr::makeFrexp2F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec3 frexp( Vec3 const x
		, IVec3  exp )
	{
		return RetVec3{ *findWriter( x, exp )
			, expr::makeFrexp3F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec4 frexp( Vec4 const x
		, IVec4  exp )
	{
		return RetVec4{ *findWriter( x, exp )
			, expr::makeFrexp4F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDouble frexp( Double const x
		, Int  exp )
	{
		return RetDouble{ *findWriter( x, exp )
			, expr::makeFrexp1D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec2 frexp( DVec2 const x
		, IVec2  exp )
	{
		return RetDVec2{ *findWriter( x, exp )
			, expr::makeFrexp2D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec3 frexp( DVec3 const x
		, IVec3  exp )
	{
		return RetDVec3{ *findWriter( x, exp )
			, expr::makeFrexp3D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec4 frexp( DVec4 const x
		, IVec4  exp )
	{
		return RetDVec4{ *findWriter( x, exp )
			, expr::makeFrexp4D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	/**@}*/
#pragma endregion
#pragma region ldexp
	/**
	*name
	*	ldexp
	*/
	/**@{*/
	RetFloat ldexp( Float const x
		, Int const exp )
	{
		return RetFloat{ *findWriter( x, exp )
			, expr::makeLdexp1F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec2 ldexp( Vec2 const x
		, IVec2 const exp )
	{
		return RetVec2{ *findWriter( x, exp )
			, expr::makeLdexp2F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec3 ldexp( Vec3 const x
		, IVec3 const exp )
	{
		return RetVec3{ *findWriter( x, exp )
			, expr::makeLdexp3F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec4 ldexp( Vec4 const x
		, IVec4 const exp )
	{
		return RetVec4{ *findWriter( x, exp )
			, expr::makeLdexp4F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDouble ldexp( Double const x
		, Int const exp )
	{
		return RetDouble{ *findWriter( x, exp )
			, expr::makeLdexp1D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec2 ldexp( DVec2 const x
		, IVec2 const exp )
	{
		return RetDVec2{ *findWriter( x, exp )
			, expr::makeLdexp2D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec3 ldexp( DVec3 const x
		, IVec3 const exp )
	{
		return RetDVec3{ *findWriter( x, exp )
			, expr::makeLdexp3D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec4 ldexp( DVec4 const x
		, IVec4 const exp )
	{
		return RetDVec4{ *findWriter( x, exp )
			, expr::makeLdexp4D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	/**@}*/
#pragma endregion
#pragma region packDouble2x32
	/**
	*name
	*	packDouble2x32
	*/
	/**@{*/
	RetDouble packDouble2x32( UVec2 const v )
	{
		return RetDouble{ *findWriter( v )
			, expr::makePackDouble2x32( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	RetUInt packHalf2x16( Vec2 const v )
	{
		return RetUInt{ *findWriter( v )
			, expr::makePackHalf2x16( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	RetUInt packSnorm2x16( Vec2 const v )
	{
		return RetUInt{ *findWriter( v )
			, expr::makePackSnorm2x16( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	RetUInt packSnorm4x8( Vec4 const v )
	{
		return RetUInt{ *findWriter( v )
			, expr::makePackSnorm4x8( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	RetUInt packUnorm2x16( Vec2 const v )
	{
		return RetUInt{ *findWriter( v )
			, expr::makePackUnorm2x16( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	RetUInt packUnorm4x8( Vec4 const v )
	{
		return RetUInt{ *findWriter( v )
			, expr::makePackUnorm4x8( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	RetUVec2 unpackDouble2x32( Double const d )
	{
		return RetUVec2{ *findWriter( d )
			, expr::makeUnpackDouble2x32( findTypesCache( d )
					, makeExpr( d ) )
			, areOptionalEnabled( d ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	RetVec2 unpackHalf2x16( UInt const v )
	{
		return RetVec2{ *findWriter( v )
			, expr::makeUnpackHalf2x16( findTypesCache( v )
					, makeExpr( v ) )
			, areOptionalEnabled( v ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	RetVec2 unpackSnorm2x16( UInt const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeUnpackSnorm2x16( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	RetVec4 unpackSnorm4x8( UInt const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeUnpackSnorm4x8( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	RetVec2 unpackUnorm2x16( UInt const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeUnpackUnorm2x16( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	RetVec4 unpackUnorm4x8( UInt const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeUnpackUnorm4x8( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	RetFloat length( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetFloat length( Vec2 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetFloat length( Vec3 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetFloat length( Vec4 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( DVec2 const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( DVec3 const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( DVec4 const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	RetFloat distance( Float const p0
		, Float const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance1F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetFloat distance( Vec2 const p0
		, Vec2 const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance2F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetFloat distance( Vec3 const p0
		, Vec3 const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance3F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetFloat distance( Vec4 const p0
		, Vec4 const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance4F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( Double const p0
		, Double const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance1D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( DVec2 const p0
		, DVec2 const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance2D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( DVec3 const p0
		, DVec3 const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance3D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( DVec4 const p0
		, DVec4 const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance4D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	/**@}*/
#pragma endregion
#pragma region dot
	/**
	*name
	*	dot
	*/
	/**@{*/
	RetFloat dot( Float const x
		, Float const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetFloat dot( Vec2 const x
		, Vec2 const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetFloat dot( Vec3 const x
		, Vec3 const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetFloat dot( Vec4 const x
		, Vec4 const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( DVec2 const x
		, DVec2 const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( DVec3 const x
		, DVec3 const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( DVec4 const x
		, DVec4 const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region cross
	/**
	*name
	*	cross
	*/
	/**@{*/
	RetVec3 cross( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeCrossF( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 cross( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeCrossD( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region normalize
	/**
	*name
	*	normalize
	*/
	/**@{*/
	RetFloat normalize( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeNormalize1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 normalize( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeNormalize2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 normalize( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeNormalize3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 normalize( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeNormalize4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble normalize( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeNormalize1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 normalize( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeNormalize2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 normalize( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeNormalize3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 normalize( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeNormalize4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	RetFloat faceForward( Float const N
		, Float const I
		, Float const Nref )
	{
		return RetFloat{ *findWriter( N, I, Nref )
			, expr::makeFaceForward1F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetVec2 faceForward( Vec2 const N
		, Vec2 const I
		, Vec2 const Nref )
	{
		return RetVec2{ *findWriter( N, I, Nref )
			, expr::makeFaceForward2F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetVec3 faceForward( Vec3 const N
		, Vec3 const I
		, Vec3 const Nref )
	{
		return RetVec3{ *findWriter( N, I, Nref )
			, expr::makeFaceForward3F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetVec4 faceForward( Vec4 const N
		, Vec4 const I
		, Vec4 const Nref )
	{
		return RetVec4{ *findWriter( N, I, Nref )
			, expr::makeFaceForward4F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetDouble faceForward( Double const N
		, Double const I
		, Double const Nref )
	{
		return RetDouble{ *findWriter( N, I, Nref )
			, expr::makeFaceForward1D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetDVec2 faceForward( DVec2 const N
		, DVec2 const I
		, DVec2 const Nref )
	{
		return RetDVec2{ *findWriter( N, I, Nref )
			, expr::makeFaceForward2D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetDVec3 faceForward( DVec3 const N
		, DVec3 const I
		, DVec3 const Nref )
	{
		return RetDVec3{ *findWriter( N, I, Nref )
			, expr::makeFaceForward3D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	RetDVec4 faceForward( DVec4 const N
		, DVec4 const I
		, DVec4 const Nref )
	{
		return RetDVec4{ *findWriter( N, I, Nref )
			, expr::makeFaceForward4D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	/**@}*/
#pragma endregion
#pragma region reflect
	/**
	*name
	*	reflect
	*/
	/**@{*/
	RetFloat reflect( Float const I
		, Float const N )
	{
		return RetFloat{ *findWriter( I, N )
			, expr::makeReflect1F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetVec2 reflect( Vec2 const I
		, Vec2 const N )
	{
		return RetVec2{ *findWriter( I, N )
			, expr::makeReflect2F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetVec3 reflect( Vec3 const I
		, Vec3 const N )
	{
		return RetVec3{ *findWriter( I, N )
			, expr::makeReflect3F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetVec4 reflect( Vec4 const I
		, Vec4 const N )
	{
		return RetVec4{ *findWriter( I, N )
			, expr::makeReflect4F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDouble reflect( Double const I
		, Double const N )
	{
		return RetDouble{ *findWriter( I, N )
			, expr::makeReflect1D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDVec2 reflect( DVec2 const I
		, DVec2 const N )
	{
		return RetDVec2{ *findWriter( I, N )
			, expr::makeReflect2D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDVec3 reflect( DVec3 const I
		, DVec3 const N )
	{
		return RetDVec3{ *findWriter( I, N )
			, expr::makeReflect3D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDVec4 reflect( DVec4 const I
		, DVec4 const N )
	{
		return RetDVec4{ *findWriter( I, N )
			, expr::makeReflect4D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	/**@}*/
#pragma endregion
#pragma region refract
	/**
	*name
	*	refract
	*/
	/**@{*/
	RetFloat refract( Float const I
		, Float const N
		, Float const eta )
	{
		return RetFloat{ *findWriter( I, N, eta )
			, expr::makeRefract1F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetVec2 refract( Vec2 const I
		, Vec2 const N
		, Float const eta )
	{
		return RetVec2{ *findWriter( I, N, eta )
			, expr::makeRefract2F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetVec3 refract( Vec3 const I
		, Vec3 const N
		, Float const eta )
	{
		return RetVec3{ *findWriter( I, N, eta )
			, expr::makeRefract3F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetVec4 refract( Vec4 const I
		, Vec4 const N
		, Float const eta )
	{
		return RetVec4{ *findWriter( I, N, eta )
			, expr::makeRefract4F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetDouble refract( Double const I
		, Double const N
		, Float const eta )
	{
		return RetDouble{ *findWriter( I, N, eta )
			, expr::makeRefract1D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetDVec2 refract( DVec2 const I
		, DVec2 const N
		, Float const eta )
	{
		return RetDVec2{ *findWriter( I, N, eta )
			, expr::makeRefract2D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetDVec3 refract( DVec3 const I
		, DVec3 const N
		, Float const eta )
	{
		return RetDVec3{ *findWriter( I, N, eta )
			, expr::makeRefract3D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	RetDVec4 refract( DVec4 const I
		, DVec4 const N
		, Float const eta )
	{
		return RetDVec4{ *findWriter( I, N, eta )
			, expr::makeRefract4D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	RetMat2 matrixCompMult( Mat2 const x
		, Mat2 const y )
	{
		return RetMat2{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat2x3 matrixCompMult( Mat2x3 const x
		, Mat2x3 const y )
	{
		return RetMat2x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat2x4 matrixCompMult( Mat2x4 const x
		, Mat2x4 const y )
	{
		return RetMat2x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat3x2 matrixCompMult( Mat3x2 const x
		, Mat3x2 const y )
	{
		return RetMat3x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat3 matrixCompMult( Mat3 const x
		, Mat3 const y )
	{
		return RetMat3{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat3x4 matrixCompMult( Mat3x4 const x
		, Mat3x4 const y )
	{
		return RetMat3x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat4x2 matrixCompMult( Mat4x2 const x
		, Mat4x2 const y )
	{
		return RetMat4x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat4x3 matrixCompMult( Mat4x3 const x
		, Mat4x3 const y )
	{
		return RetMat4x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat4 matrixCompMult( Mat4 const x
		, Mat4 const y )
	{
		return RetMat4{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat2 matrixCompMult( DMat2 const x
		, DMat2 const y )
	{
		return RetDMat2{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat2x3 matrixCompMult( DMat2x3 const x
		, DMat2x3 const y )
	{
		return RetDMat2x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat2x4 matrixCompMult( DMat2x4 const x
		, DMat2x4 const y )
	{
		return RetDMat2x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat3x2 matrixCompMult( DMat3x2 const x
		, DMat3x2 const y )
	{
		return RetDMat3x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat3 matrixCompMult( DMat3 const x
		, DMat3 const y )
	{
		return RetDMat3{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat3x4 matrixCompMult( DMat3x4 const x
		, DMat3x4 const y )
	{
		return RetDMat3x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat4x2 matrixCompMult( DMat4x2 const x
		, DMat4x2 const y )
	{
		return RetDMat4x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat4x3 matrixCompMult( DMat4x3 const x
		, DMat4x3 const y )
	{
		return RetDMat4x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat4 matrixCompMult( DMat4 const x
		, DMat4 const y )
	{
		return RetDMat4{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region outerProduct
	/**
	*name
	*	outerProduct
	*/
	/**@{*/
	RetMat2 outerProduct( Vec2 const c
		, Vec2 const r )
	{
		return RetMat2{ *findWriter( c, r )
			, expr::makeOuterProduct2x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat3 outerProduct( Vec3 const c
		, Vec3 const r )
	{
		return RetMat3{ *findWriter( c, r )
			, expr::makeOuterProduct3x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat4 outerProduct( Vec4 const c
		, Vec4 const r )
	{
		return RetMat4{ *findWriter( c, r )
			, expr::makeOuterProduct4x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat2x3 outerProduct( Vec3 const c
		, Vec2 const r )
	{
		return RetMat2x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat3x2 outerProduct( Vec2 const c
		, Vec3 const r )
	{
		return RetMat3x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat2x4 outerProduct( Vec4 const c
		, Vec2 const r )
	{
		return RetMat2x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat4x2 outerProduct( Vec2 const c
		, Vec4 const r )
	{
		return RetMat4x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat3x4 outerProduct( Vec4 const c
		, Vec3 const r )
	{
		return RetMat3x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat4x3 outerProduct( Vec3 const c
		, Vec4 const r )
	{
		return RetMat4x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat2 outerProduct( DVec2 const c
		, DVec2 const r )
	{
		return RetDMat2{ *findWriter( c, r )
			, expr::makeOuterProduct2x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat3 outerProduct( DVec3 const c
		, DVec3 const r )
	{
		return RetDMat3{ *findWriter( c, r )
			, expr::makeOuterProduct3x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat4 outerProduct( DVec4 const c
		, DVec4 const r )
	{
		return RetDMat4{ *findWriter( c, r )
			, expr::makeOuterProduct4x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat2x3 outerProduct( DVec3 const c
		, DVec2 const r )
	{
		return RetDMat2x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat3x2 outerProduct( DVec2 const c
		, DVec3 const r )
	{
		return RetDMat3x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat2x4 outerProduct( DVec4 const c
		, DVec2 const r )
	{
		return RetDMat2x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat4x2 outerProduct( DVec2 const c
		, DVec4 const r )
	{
		return RetDMat4x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat3x4 outerProduct( DVec4 const c
		, DVec3 const r )
	{
		return RetDMat3x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat4x3 outerProduct( DVec3 const c
		, DVec4 const r )
	{
		return RetDMat4x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	/**@}*/
#pragma endregion
#pragma region transpose
	/**
	*name
	*	transpose
	*/
	/**@{*/
	RetMat2 transpose( Mat2 const x )
	{
		return RetMat2{ *findWriter( x )
			, expr::makeTranspose2x2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat3x2 transpose( Mat2x3 const x )
	{
		return RetMat3x2{ *findWriter( x )
			, expr::makeTranspose2x3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat4x2 transpose( Mat2x4 const x )
	{
		return RetMat4x2{ *findWriter( x )
			, expr::makeTranspose2x4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat2x3 transpose( Mat3x2 const x )
	{
		return RetMat2x3{ *findWriter( x )
			, expr::makeTranspose3x2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat3 transpose( Mat3 const x )
	{
		return RetMat3{ *findWriter( x )
			, expr::makeTranspose3x3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat4x3 transpose( Mat3x4 const x )
	{
		return RetMat4x3{ *findWriter( x )
			, expr::makeTranspose3x4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat2x4 transpose( Mat4x2 const x )
	{
		return RetMat2x4{ *findWriter( x )
			, expr::makeTranspose4x2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat3x4 transpose( Mat4x3 const x )
	{
		return RetMat3x4{ *findWriter( x )
			, expr::makeTranspose4x3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat4 transpose( Mat4 const x )
	{
		return RetMat4{ *findWriter( x )
			, expr::makeTranspose4x4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat2 transpose( DMat2 const x )
	{
		return RetDMat2{ *findWriter( x )
			, expr::makeTranspose2x2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat3x2 transpose( DMat2x3 const x )
	{
		return RetDMat3x2{ *findWriter( x )
			, expr::makeTranspose2x3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat4x2 transpose( DMat2x4 const x )
	{
		return RetDMat4x2{ *findWriter( x )
			, expr::makeTranspose2x4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat2x3 transpose( DMat3x2 const x )
	{
		return RetDMat2x3{ *findWriter( x )
			, expr::makeTranspose3x2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat3 transpose( DMat3 const x )
	{
		return RetDMat3{ *findWriter( x )
			, expr::makeTranspose3x3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat4x3 transpose( DMat3x4 const x )
	{
		return RetDMat4x3{ *findWriter( x )
			, expr::makeTranspose3x4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat2x4 transpose( DMat4x2 const x )
	{
		return RetDMat2x4{ *findWriter( x )
			, expr::makeTranspose4x2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat3x4 transpose( DMat4x3 const x )
	{
		return RetDMat3x4{ *findWriter( x )
			, expr::makeTranspose4x3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat4 transpose( DMat4 const x )
	{
		return RetDMat4{ *findWriter( x )
			, expr::makeTranspose4x4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	RetFloat determinant( Mat2 const m )
	{
		return RetFloat{ *findWriter( m )
			, expr::makeDeterminant2x2F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetFloat determinant( Mat3 const m )
	{
		return RetFloat{ *findWriter( m )
			, expr::makeDeterminant3x3F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetFloat determinant( Mat4 const m )
	{
		return RetFloat{ *findWriter( m )
			, expr::makeDeterminant4x4F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDouble determinant( DMat2 const m )
	{
		return RetDouble{ *findWriter( m )
			, expr::makeDeterminant2x2D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDouble determinant( DMat3 const m )
	{
		return RetDouble{ *findWriter( m )
			, expr::makeDeterminant3x3D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDouble determinant( DMat4 const m )
	{
		return RetDouble{ *findWriter( m )
			, expr::makeDeterminant4x4D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	RetMat2 inverse( Mat2 const m )
	{
		return RetMat2{ *findWriter( m )
			, expr::makeInverse2x2F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetMat3 inverse( Mat3 const m )
	{
		return RetMat3{ *findWriter( m )
			, expr::makeInverse3x3F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetMat4 inverse( Mat4 const m )
	{
		return RetMat4{ *findWriter( m )
			, expr::makeInverse4x4F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDMat2 inverse( DMat2 const m )
	{
		return RetDMat2{ *findWriter( m )
			, expr::makeInverse2x2D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDMat3 inverse( DMat3 const m )
	{
		return RetDMat3{ *findWriter( m )
			, expr::makeInverse3x3D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDMat4 inverse( DMat4 const m )
	{
		return RetDMat4{ *findWriter( m )
			, expr::makeInverse4x4D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	RetBVec2 lessThan( Vec2 const x
		, Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThan( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThan( IVec2 const x
		, IVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( IVec3 const x
		, IVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( IVec4 const x
		, IVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThan( UVec2 const x
		, UVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( UVec3 const x
		, UVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( UVec4 const x
		, UVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region lessThanEqual
	/**
	*name
	*	lessThanEqual
	*/
	/**@{*/
	RetBVec2 lessThanEqual( Vec2 const x
		, Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThanEqual( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThanEqual( IVec2 const x
		, IVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( IVec3 const x
		, IVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( IVec4 const x
		, IVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThanEqual( UVec2 const x
		, UVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( UVec3 const x
		, UVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( UVec4 const x
		, UVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region greaterThan
	/**
	*name
	*	greaterThan
	*/
	/**@{*/
	RetBVec2 greaterThan( Vec2 const x
		, Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThan( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThan( IVec2 const x
		, IVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( IVec3 const x
		, IVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( IVec4 const x
		, IVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThan( UVec2 const x
		, UVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( UVec3 const x
		, UVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( UVec4 const x
		, UVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region greaterThanEqual
	/**
	*name
	*	greaterThanEqual
	*/
	/**@{*/
	RetBVec2 greaterThanEqual( Vec2 const x
		, Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThanEqual( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThanEqual( IVec2 const x
		, IVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( IVec3 const x
		, IVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( IVec4 const x
		, IVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThanEqual( UVec2 const x
		, UVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( UVec3 const x
		, UVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( UVec4 const x
		, UVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region equal
	/**
	*name
	*	equal
	*/
	/**@{*/
	RetBVec2 equal( Vec2 const x
		, Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 equal( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 equal( IVec2 const x
		, IVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( IVec3 const x
		, IVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( IVec4 const x
		, IVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 equal( UVec2 const x
		, UVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( UVec3 const x
		, UVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( UVec4 const x
		, UVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region notEqual
	/**
	*name
	*	notEqual
	*/
	/**@{*/
	RetBVec2 notEqual( Vec2 const x
		, Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 notEqual( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 notEqual( IVec2 const x
		, IVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( IVec3 const x
		, IVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( IVec4 const x
		, IVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 notEqual( UVec2 const x
		, UVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( UVec3 const x
		, UVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( UVec4 const x
		, UVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	/**@}*/
#pragma endregion
#pragma region all
	/**
	*name
	*	all
	*/
	/**@{*/
	RetBoolean all( BVec2 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAll2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean all( BVec3 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAll3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean all( BVec4 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAll4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	RetBoolean any( BVec2 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAny2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean any( BVec3 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAny3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean any( BVec4 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAny4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region binNot
	/**
	*name
	*	binNot
	*/
	/**@{*/
	RetBVec2 binNot( BVec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeNot2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 binNot( BVec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeNot3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 binNot( BVec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeNot4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	RetUInt uaddCarry( UInt const x
		, UInt const y
		, UInt const carry )
	{
		return RetUInt{ *findWriter( x, y, carry )
			, expr::makeUaddCarry1( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	RetUVec2 uaddCarry( UVec2 const x
		, UVec2 const y
		, UVec2 const carry )
	{
		return RetUVec2{ *findWriter( x, y, carry )
			, expr::makeUaddCarry2( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	RetUVec3 uaddCarry( UVec3 const x
		, UVec3 const y
		, UVec3 const carry )
	{
		return RetUVec3{ *findWriter( x, y, carry )
			, expr::makeUaddCarry3( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	RetUVec4 uaddCarry( UVec4 const x
		, UVec4 const y
		, UVec4 const carry )
	{
		return RetUVec4{ *findWriter( x, y, carry )
			, expr::makeUaddCarry4( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	/**@}*/
#pragma endregion
#pragma region usubBorrow
	/**
	*name
	*	usubBorrow
	*/
	/**@{*/
	RetUInt usubBorrow( UInt const x
		, UInt const y
		, UInt const borrow )
	{
		return RetUInt{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow1( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	RetUVec2 usubBorrow( UVec2 const x
		, UVec2 const y
		, UVec2 const borrow )
	{
		return RetUVec2{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow2( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	RetUVec3 usubBorrow( UVec3 const x
		, UVec3 const y
		, UVec3 const borrow )
	{
		return RetUVec3{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow3( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	RetUVec4 usubBorrow( UVec4 const x
		, UVec4 const y
		, UVec4 const borrow )
	{
		return RetUVec4{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow4( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	/**@}*/
#pragma endregion
#pragma region umulExtended
	/**
	*name
	*	umulExtended
	*/
	/**@{*/
	RetVoid umulExtended( UInt const x
		, UInt const y
		, UInt const msb
		, UInt const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid umulExtended( UVec2 const x
		, UVec2 const y
		, UVec2 const msb
		, UVec2 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid umulExtended( UVec3 const x
		, UVec3 const y
		, UVec3 const msb
		, UVec3 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid umulExtended( UVec4 const x
		, UVec4 const y
		, UVec4 const msb
		, UVec4 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended4( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	/**@}*/
#pragma endregion
#pragma region imulExtended
	/**
	*name
	*	imulExtended
	*/
	/**@{*/
	RetVoid imulExtended( Int const x
		, Int const y
		, Int const msb
		, Int const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid imulExtended( IVec2 const x
		, IVec2 const y
		, IVec2 const msb
		, IVec2 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid imulExtended( IVec3 const x
		, IVec3 const y
		, IVec3 const msb
		, IVec3 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid imulExtended( IVec4 const x
		, IVec4 const y
		, IVec4 const msb
		, IVec4 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended4( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitfieldExtract
	/**
	*name
	*	bitfieldExtract
	*/
	/**@{*/
	RetInt bitfieldExtract( Int const value
		, Int const offset
		, Int const bits )
	{
		return RetInt{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract1I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetIVec2 bitfieldExtract( IVec2 const value
		, Int const offset
		, Int const bits )
	{
		return RetIVec2{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract2I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetIVec3 bitfieldExtract( IVec3 const value
		, Int const offset
		, Int const bits )
	{
		return RetIVec3{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract3I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetIVec4 bitfieldExtract( IVec4 const value
		, Int const offset
		, Int const bits )
	{
		return RetIVec4{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract4I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetUInt bitfieldExtract( UInt const value
		, Int const offset
		, Int const bits )
	{
		return RetUInt{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract1U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetUVec2 bitfieldExtract( UVec2 const value
		, Int const offset
		, Int const bits )
	{
		return RetUVec2{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract2U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetUVec3 bitfieldExtract( UVec3 const value
		, Int const offset
		, Int const bits )
	{
		return RetUVec3{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract3U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetUVec4 bitfieldExtract( UVec4 const value
		, Int const offset
		, Int const bits )
	{
		return RetUVec4{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract4U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitfieldInsert
	/**
	*name
	*	bitfieldInsert
	*/
	/**@{*/
	RetInt bitfieldInsert( Int const base
		, Int const insert
		, Int const offset
		, Int const bits )
	{
		return RetInt{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert1I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetIVec2 bitfieldInsert( IVec2 const base
		, IVec2 const insert
		, Int const offset
		, Int const bits )
	{
		return RetIVec2{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert2I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetIVec3 bitfieldInsert( IVec3 const base
		, IVec3 const insert
		, Int const offset
		, Int const bits )
	{
		return RetIVec3{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert3I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetIVec4 bitfieldInsert( IVec4 const base
		, IVec4 const insert
		, Int const offset
		, Int const bits )
	{
		return RetIVec4{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert4I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetUInt bitfieldInsert( UInt const base
		, UInt const insert
		, Int const offset
		, Int const bits )
	{
		return RetUInt{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert1U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetUVec2 bitfieldInsert( UVec2 const base
		, UVec2 const insert
		, Int const offset
		, Int const bits )
	{
		return RetUVec2{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert2U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetUVec3 bitfieldInsert( UVec3 const base
		, UVec3 const insert
		, Int const offset
		, Int const bits )
	{
		return RetUVec3{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert3U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetUVec4 bitfieldInsert( UVec4 const base
		, UVec4 const insert
		, Int const offset
		, Int const bits )
	{
		return RetUVec4{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert4U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitfieldReverse
	/**
	*name
	*	bitfieldReverse
	*/
	/**@{*/
	RetInt bitfieldReverse( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeBitfieldReverse1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 bitfieldReverse( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeBitfieldReverse2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 bitfieldReverse( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeBitfieldReverse3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 bitfieldReverse( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeBitfieldReverse4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt bitfieldReverse( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeBitfieldReverse1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 bitfieldReverse( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeBitfieldReverse2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 bitfieldReverse( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeBitfieldReverse3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 bitfieldReverse( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeBitfieldReverse4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	RetInt bitCount( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeBitCount1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 bitCount( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeBitCount2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 bitCount( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeBitCount3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 bitCount( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeBitCount4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt bitCount( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeBitCount1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 bitCount( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeBitCount2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 bitCount( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeBitCount3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 bitCount( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeBitCount4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	RetInt findLSB( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeFindLSB1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 findLSB( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeFindLSB2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 findLSB( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeFindLSB3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 findLSB( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeFindLSB4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt findLSB( UInt const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeFindLSB1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 findLSB( UVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeFindLSB2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 findLSB( UVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeFindLSB3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 findLSB( UVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeFindLSB4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	RetInt findMSB( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeFindMSB1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 findMSB( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeFindMSB2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 findMSB( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeFindMSB3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 findMSB( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeFindMSB4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt findMSB( UInt const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeFindMSB1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 findMSB( UVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeFindMSB2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 findMSB( UVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeFindMSB3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 findMSB( UVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeFindMSB4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	RetInt atomicAdd( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicAddI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicAdd( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicAddU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetFloat atomicAdd( Float const mem
		, Float const data )
	{
		return RetFloat{ *findWriter( mem, data )
			, expr::makeAtomicAddF( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec2 atomicAdd( HVec2 const mem
		, HVec2 const data )
	{
		return RetHVec2{ *findWriter( mem, data )
			, expr::makeAtomicAdd2H( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec4 atomicAdd( HVec4 const mem
		, HVec4 const data )
	{
		return RetHVec4{ *findWriter( mem, data )
			, expr::makeAtomicAdd4H( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicMin
	/**
	*name
	*	atomicMin
	*/
	/**@{*/
	RetInt atomicMin( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicMinI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicMin( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicMinU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicMax
	/**
	*name
	*	atomicMax
	*/
	/**@{*/
	RetInt atomicMax( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicMaxI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicMax( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicMaxU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicAnd
	/**
	*name
	*	atomicAnd
	*/
	/**@{*/
	RetInt atomicAnd( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicAndI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicAnd( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicAndU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicOr
	/**
	*name
	*	atomicOr
	*/
	/**@{*/
	RetInt atomicOr( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicOrI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicOr( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicOrU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicXor
	/**
	*name
	*	atomicXor
	*/
	/**@{*/
	RetInt atomicXor( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicXorI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicXor( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicXorU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicExchange
	/**
	*name
	*	atomicExchange
	*/
	/**@{*/
	RetInt atomicExchange( Int const mem
		, Int const data )
	{
		return RetInt{ *findWriter( mem, data )
			, expr::makeAtomicExchangeI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt atomicExchange( UInt const mem
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, data )
			, expr::makeAtomicExchangeU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetFloat atomicExchange( Float const mem
		, Float const data )
	{
		return RetFloat{ *findWriter( mem, data )
			, expr::makeAtomicExchangeF( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec2 atomicExchange( HVec2 const mem
		, HVec2 const data )
	{
		return RetHVec2{ *findWriter( mem, data )
			, expr::makeAtomicExchange2H( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec4 atomicExchange( HVec4 const mem
		, HVec4 const data )
	{
		return RetHVec4{ *findWriter( mem, data )
			, expr::makeAtomicExchange4H( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicCompSwap
	/**
	*name
	*	atomicCompSwap
	*/
	/**@{*/
	RetInt atomicCompSwap( Int const mem
		, Int const compare
		, Int const data )
	{
		return RetInt{ *findWriter( mem, compare, data )
			, expr::makeAtomicCompSwapI( findTypesCache( mem, compare, data )
					, makeExpr( mem )
				, makeExpr( compare )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, compare, data ) };
	}
	RetUInt atomicCompSwap( UInt const mem
		, UInt const compare
		, UInt const data )
	{
		return RetUInt{ *findWriter( mem, compare, data )
			, expr::makeAtomicCompSwapU( findTypesCache( mem, compare, data )
					, makeExpr( mem )
				, makeExpr( compare )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, compare, data ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdx
	/**
	*name
	*	dFdx
	*/
	/**@{*/
	RetFloat dFdx( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeDFdx1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdx( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdx2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdx( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdx3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdx( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdx4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	RetFloat dFdxCoarse( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeDFdxCoarse1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdxCoarse( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdxCoarse2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdxCoarse( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdxCoarse3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdxCoarse( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdxCoarse4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	RetFloat dFdxFine( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeDFdxFine1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdxFine( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdxFine2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdxFine( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdxFine3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdxFine( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdxFine4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	RetFloat dFdy( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeDFdy1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdy( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdy2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdy( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdy3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdy( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdy4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	RetFloat dFdyCoarse( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeDFdyCoarse1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdyCoarse( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdyCoarse2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdyCoarse( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdyCoarse3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdyCoarse( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdyCoarse4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	RetFloat dFdyFine( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeDFdyFine1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdyFine( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdyFine2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdyFine( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdyFine3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdyFine( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdyFine4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	RetFloat fwidth( Float const p )
	{
		return RetFloat{ *findWriter( p )
			, expr::makeFwidth1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 fwidth( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeFwidth2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 fwidth( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeFwidth3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 fwidth( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeFwidth4( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	RetFloat interpolateAtCentroid( Float const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeInterpolateAtCentroid1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 interpolateAtCentroid( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeInterpolateAtCentroid2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 interpolateAtCentroid( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeInterpolateAtCentroid3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 interpolateAtCentroid( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeInterpolateAtCentroid4( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	RetFloat interpolateAtSample( Float const interpolant
		, Int const sample )
	{
		return RetFloat{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample1( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	RetVec2 interpolateAtSample( Vec2 const interpolant
		, Int const sample )
	{
		return RetVec2{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample2( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	RetVec3 interpolateAtSample( Vec3 const interpolant
		, Int const sample )
	{
		return RetVec3{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample3( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	RetVec4 interpolateAtSample( Vec4 const interpolant
		, Int const sample )
	{
		return RetVec4{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample4( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtOffset
	/**
	*name
	*	interpolateAtOffset
	*/
	/**@{*/
	RetFloat interpolateAtOffset( Float const interpolant
		, Vec2 const offset )
	{
		return RetFloat{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset1( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	RetVec2 interpolateAtOffset( Vec2 const interpolant
		, Vec2 const offset )
	{
		return RetVec2{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset2( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	RetVec3 interpolateAtOffset( Vec3 const interpolant
		, Vec2 const offset )
	{
		return RetVec3{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset3( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	RetVec4 interpolateAtOffset( Vec4 const interpolant
		, Vec2 const offset )
	{
		return RetVec4{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset4( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	/**@}*/
#pragma endregion
#pragma region EmitStreamVertex
	/**
	*name
	*	EmitStreamVertex
	*/
	/**@{*/
	RetVoid EmitStreamVertex( Int const stream )
	{
		return RetVoid{ *findWriter( stream )
			, expr::makeEmitStreamVertex( findTypesCache( stream )
					, makeExpr( stream ) )
			, areOptionalEnabled( stream ) };
	}
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	RetVoid EndStreamPrimitive( Int const stream )
	{
		return RetVoid{ *findWriter( stream )
			, expr::makeEndStreamPrimitive( findTypesCache( stream )
					, makeExpr( stream ) )
			, areOptionalEnabled( stream ) };
	}
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	RetVoid EmitVertex( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeEmitVertex( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	RetVoid EndPrimitive( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeEndPrimitive( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region barrier
	/**
	*name
	*	barrier
	*/
	/**@{*/
	RetVoid barrier( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeBarrier( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region helperInvocation
	/**
	*name
	*	helperInvocation
	*/
	/**@{*/
	RetBoolean helperInvocation( ShaderWriter & writer )
	{
		return RetBoolean{ *findWriter( writer )
			, expr::makeHelperInvocation( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	RetUInt memoryBarrier( ShaderWriter & writer )
	{
		return RetUInt{ *findWriter( writer )
			, expr::makeMemoryBarrier( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierBuffer
	/**
	*name
	*	memoryBarrierBuffer
	*/
	/**@{*/
	RetVoid memoryBarrierBuffer( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeMemoryBarrierBuffer( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierShared
	/**
	*name
	*	memoryBarrierShared
	*/
	/**@{*/
	RetVoid memoryBarrierShared( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeMemoryBarrierShared( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierImage
	/**
	*name
	*	memoryBarrierImage
	*/
	/**@{*/
	RetVoid memoryBarrierImage( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeMemoryBarrierImage( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region groupMemoryBarrier
	/**
	*name
	*	groupMemoryBarrier
	*/
	/**@{*/
	RetVoid groupMemoryBarrier( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeGroupMemoryBarrier( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region traceRay
	/**
	*name
	*	traceRay
	*/
	/**@{*/
	RetVoid traceRay( AccelerationStructure const topLevel
		, UInt const rayFlags
		, UInt const cullMask
		, UInt const sbtRecordOffset
		, UInt const sbtRecordStride
		, UInt const missIndex
		, RayDesc const rayDesc
		, RayPayload const payload )
	{
		return RetVoid{ *findWriter( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload )
			, expr::makeTraceRay( findTypesCache( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload )
					, makeExpr( topLevel )
				, makeExpr( rayFlags )
				, makeExpr( cullMask )
				, makeExpr( sbtRecordOffset )
				, makeExpr( sbtRecordStride )
				, makeExpr( missIndex )
				, makeExpr( rayDesc )
				, makeExpr( payload ) )
			, areOptionalEnabled( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload ) };
	}
	/**@}*/
#pragma endregion
#pragma region reportIntersection
	/**
	*name
	*	reportIntersection
	*/
	/**@{*/
	RetBoolean reportIntersection( Float const hitT
		, UInt const hitKind
		, HitAttribute const attribs )
	{
		return RetBoolean{ *findWriter( hitT, hitKind, attribs )
			, expr::makeReportIntersection( findTypesCache( hitT, hitKind, attribs )
					, makeExpr( hitT )
				, makeExpr( hitKind )
				, makeExpr( attribs ) )
			, areOptionalEnabled( hitT, hitKind, attribs ) };
	}
	/**@}*/
#pragma endregion
#pragma region executeCallable
	/**
	*name
	*	executeCallable
	*/
	/**@{*/
	RetVoid executeCallable( UInt const sbtRecordIndex
		, CallableData const callable )
	{
		return RetVoid{ *findWriter( sbtRecordIndex, callable )
			, expr::makeExecuteCallable( findTypesCache( sbtRecordIndex, callable )
					, makeExpr( sbtRecordIndex )
				, makeExpr( callable ) )
			, areOptionalEnabled( sbtRecordIndex, callable ) };
	}
	/**@}*/
#pragma endregion
#pragma region setMeshOutputCounts
	/**
	*name
	*	setMeshOutputCounts
	*/
	/**@{*/
	RetVoid setMeshOutputCounts( UInt const numVertices
		, UInt const numPrimitives )
	{
		return RetVoid{ *findWriter( numVertices, numPrimitives )
			, expr::makeSetMeshOutputCounts( findTypesCache( numVertices, numPrimitives )
					, makeExpr( numVertices )
				, makeExpr( numPrimitives ) )
			, areOptionalEnabled( numVertices, numPrimitives ) };
	}
	/**@}*/
#pragma endregion
#pragma region dispatchMesh
	/**
	*name
	*	dispatchMesh
	*/
	/**@{*/
	RetVoid dispatchMesh( TaskPayload const payload
		, UInt const numTasks )
	{
		return RetVoid{ *findWriter( payload, numTasks )
			, expr::makeDispatchMesh( findTypesCache( payload, numTasks )
					, makeExpr( payload )
				, makeExpr( numTasks ) )
			, areOptionalEnabled( payload, numTasks ) };
	}
	/**@}*/
#pragma endregion
#pragma region writePackedPrimitiveIndices4x8
	/**
	*name
	*	writePackedPrimitiveIndices4x8
	*/
	/**@{*/
	RetVoid writePackedPrimitiveIndices4x8( UInt const indexOffset
		, UInt const packedIndices )
	{
		return RetVoid{ *findWriter( indexOffset, packedIndices )
			, expr::makeWritePackedPrimitiveIndices4x8( findTypesCache( indexOffset, packedIndices )
					, makeExpr( indexOffset )
				, makeExpr( packedIndices ) )
			, areOptionalEnabled( indexOffset, packedIndices ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBarrier
	/**
	*name
	*	subgroupBarrier
	*/
	/**@{*/
	RetVoid subgroupBarrier( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeSubgroupBarrier( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMemoryBarrier
	/**
	*name
	*	subgroupMemoryBarrier
	*/
	/**@{*/
	RetVoid subgroupMemoryBarrier( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeSubgroupMemoryBarrier( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMemoryBarrierBuffer
	/**
	*name
	*	subgroupMemoryBarrierBuffer
	*/
	/**@{*/
	RetVoid subgroupMemoryBarrierBuffer( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeSubgroupMemoryBarrierBuffer( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMemoryBarrierShared
	/**
	*name
	*	subgroupMemoryBarrierShared
	*/
	/**@{*/
	RetVoid subgroupMemoryBarrierShared( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeSubgroupMemoryBarrierShared( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMemoryBarrierImage
	/**
	*name
	*	subgroupMemoryBarrierImage
	*/
	/**@{*/
	RetVoid subgroupMemoryBarrierImage( ShaderWriter & writer )
	{
		return RetVoid{ *findWriter( writer )
			, expr::makeSubgroupMemoryBarrierImage( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupElect
	/**
	*name
	*	subgroupElect
	*/
	/**@{*/
	RetBoolean subgroupElect( ShaderWriter & writer )
	{
		return RetBoolean{ *findWriter( writer )
			, expr::makeSubgroupElect( findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupAll
	/**
	*name
	*	subgroupAll
	*/
	/**@{*/
	RetBoolean subgroupAll( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAll( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupAny
	/**
	*name
	*	subgroupAny
	*/
	/**@{*/
	RetBoolean subgroupAny( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAny( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupAllEqual
	/**
	*name
	*	subgroupAllEqual
	*/
	/**@{*/
	RetBoolean subgroupAllEqual( Float const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Vec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Vec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Vec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Int const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( IVec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( IVec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( IVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( UInt const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( UVec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( UVec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( UVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( BVec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( BVec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( BVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Double const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( DVec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( DVec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( DVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBroadcast
	/**
	*name
	*	subgroupBroadcast
	*/
	/**@{*/
	RetFloat subgroupBroadcast( Float const value
		, UInt const id )
	{
		return RetFloat{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec2 subgroupBroadcast( Vec2 const value
		, UInt const id )
	{
		return RetVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec3 subgroupBroadcast( Vec3 const value
		, UInt const id )
	{
		return RetVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec4 subgroupBroadcast( Vec4 const value
		, UInt const id )
	{
		return RetVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetInt subgroupBroadcast( Int const value
		, UInt const id )
	{
		return RetInt{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec2 subgroupBroadcast( IVec2 const value
		, UInt const id )
	{
		return RetIVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec3 subgroupBroadcast( IVec3 const value
		, UInt const id )
	{
		return RetIVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec4 subgroupBroadcast( IVec4 const value
		, UInt const id )
	{
		return RetIVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUInt subgroupBroadcast( UInt const value
		, UInt const id )
	{
		return RetUInt{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec2 subgroupBroadcast( UVec2 const value
		, UInt const id )
	{
		return RetUVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec3 subgroupBroadcast( UVec3 const value
		, UInt const id )
	{
		return RetUVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec4 subgroupBroadcast( UVec4 const value
		, UInt const id )
	{
		return RetUVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBoolean subgroupBroadcast( Boolean const value
		, UInt const id )
	{
		return RetBoolean{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec2 subgroupBroadcast( BVec2 const value
		, UInt const id )
	{
		return RetBVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec3 subgroupBroadcast( BVec3 const value
		, UInt const id )
	{
		return RetBVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec4 subgroupBroadcast( BVec4 const value
		, UInt const id )
	{
		return RetBVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDouble subgroupBroadcast( Double const value
		, UInt const id )
	{
		return RetDouble{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec2 subgroupBroadcast( DVec2 const value
		, UInt const id )
	{
		return RetDVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec3 subgroupBroadcast( DVec3 const value
		, UInt const id )
	{
		return RetDVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec4 subgroupBroadcast( DVec4 const value
		, UInt const id )
	{
		return RetDVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBroadcastFirst
	/**
	*name
	*	subgroupBroadcastFirst
	*/
	/**@{*/
	RetFloat subgroupBroadcastFirst( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupBroadcastFirst( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupBroadcastFirst( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupBroadcastFirst( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupBroadcastFirst( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupBroadcastFirst( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupBroadcastFirst( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupBroadcastFirst( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupBroadcastFirst( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupBroadcastFirst( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupBroadcastFirst( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupBroadcastFirst( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupBroadcastFirst( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupBroadcastFirst( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupBroadcastFirst( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupBroadcastFirst( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupBroadcastFirst( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupBroadcastFirst( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupBroadcastFirst( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupBroadcastFirst( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallot
	/**
	*name
	*	subgroupBallot
	*/
	/**@{*/
	RetUVec4 subgroupBallot( Boolean const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupBallot( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInverseBallot
	/**
	*name
	*	subgroupInverseBallot
	*/
	/**@{*/
	RetBoolean subgroupInverseBallot( UVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInverseBallot( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallotBitExtract
	/**
	*name
	*	subgroupBallotBitExtract
	*/
	/**@{*/
	RetBoolean subgroupBallotBitExtract( UVec4 const value
		, UInt const index )
	{
		return RetBoolean{ *findWriter( value, index )
			, expr::makeSubgroupBallotBitExtract( findTypesCache( value, index )
					, makeExpr( value )
				, makeExpr( index ) )
			, areOptionalEnabled( value, index ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallotBitCount
	/**
	*name
	*	subgroupBallotBitCount
	*/
	/**@{*/
	RetUInt subgroupBallotBitCount( UVec4 const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupBallotBitCount( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallotInclusiveBitCount
	/**
	*name
	*	subgroupBallotInclusiveBitCount
	*/
	/**@{*/
	RetUInt subgroupBallotInclusiveBitCount( UVec4 const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupBallotInclusiveBitCount( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallotExclusiveBitCount
	/**
	*name
	*	subgroupBallotExclusiveBitCount
	*/
	/**@{*/
	RetUInt subgroupBallotExclusiveBitCount( UVec4 const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupBallotExclusiveBitCount( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallotFindLSB
	/**
	*name
	*	subgroupBallotFindLSB
	*/
	/**@{*/
	RetUInt subgroupBallotFindLSB( UVec4 const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupBallotFindLSB( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupBallotFindMSB
	/**
	*name
	*	subgroupBallotFindMSB
	*/
	/**@{*/
	RetUInt subgroupBallotFindMSB( UVec4 const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupBallotFindMSB( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupShuffle
	/**
	*name
	*	subgroupShuffle
	*/
	/**@{*/
	RetFloat subgroupShuffle( Float const value
		, UInt const id )
	{
		return RetFloat{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec2 subgroupShuffle( Vec2 const value
		, UInt const id )
	{
		return RetVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec3 subgroupShuffle( Vec3 const value
		, UInt const id )
	{
		return RetVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec4 subgroupShuffle( Vec4 const value
		, UInt const id )
	{
		return RetVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetInt subgroupShuffle( Int const value
		, UInt const id )
	{
		return RetInt{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec2 subgroupShuffle( IVec2 const value
		, UInt const id )
	{
		return RetIVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec3 subgroupShuffle( IVec3 const value
		, UInt const id )
	{
		return RetIVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec4 subgroupShuffle( IVec4 const value
		, UInt const id )
	{
		return RetIVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUInt subgroupShuffle( UInt const value
		, UInt const id )
	{
		return RetUInt{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec2 subgroupShuffle( UVec2 const value
		, UInt const id )
	{
		return RetUVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec3 subgroupShuffle( UVec3 const value
		, UInt const id )
	{
		return RetUVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec4 subgroupShuffle( UVec4 const value
		, UInt const id )
	{
		return RetUVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBoolean subgroupShuffle( Boolean const value
		, UInt const id )
	{
		return RetBoolean{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec2 subgroupShuffle( BVec2 const value
		, UInt const id )
	{
		return RetBVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec3 subgroupShuffle( BVec3 const value
		, UInt const id )
	{
		return RetBVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec4 subgroupShuffle( BVec4 const value
		, UInt const id )
	{
		return RetBVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDouble subgroupShuffle( Double const value
		, UInt const id )
	{
		return RetDouble{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec2 subgroupShuffle( DVec2 const value
		, UInt const id )
	{
		return RetDVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec3 subgroupShuffle( DVec3 const value
		, UInt const id )
	{
		return RetDVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec4 subgroupShuffle( DVec4 const value
		, UInt const id )
	{
		return RetDVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupShuffleXor
	/**
	*name
	*	subgroupShuffleXor
	*/
	/**@{*/
	RetFloat subgroupShuffleXor( Float const value
		, UInt const mask )
	{
		return RetFloat{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1F( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetVec2 subgroupShuffleXor( Vec2 const value
		, UInt const mask )
	{
		return RetVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2F( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetVec3 subgroupShuffleXor( Vec3 const value
		, UInt const mask )
	{
		return RetVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3F( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetVec4 subgroupShuffleXor( Vec4 const value
		, UInt const mask )
	{
		return RetVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4F( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetInt subgroupShuffleXor( Int const value
		, UInt const mask )
	{
		return RetInt{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1I( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetIVec2 subgroupShuffleXor( IVec2 const value
		, UInt const mask )
	{
		return RetIVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2I( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetIVec3 subgroupShuffleXor( IVec3 const value
		, UInt const mask )
	{
		return RetIVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3I( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetIVec4 subgroupShuffleXor( IVec4 const value
		, UInt const mask )
	{
		return RetIVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4I( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetUInt subgroupShuffleXor( UInt const value
		, UInt const mask )
	{
		return RetUInt{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1U( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetUVec2 subgroupShuffleXor( UVec2 const value
		, UInt const mask )
	{
		return RetUVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2U( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetUVec3 subgroupShuffleXor( UVec3 const value
		, UInt const mask )
	{
		return RetUVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3U( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetUVec4 subgroupShuffleXor( UVec4 const value
		, UInt const mask )
	{
		return RetUVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4U( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBoolean subgroupShuffleXor( Boolean const value
		, UInt const mask )
	{
		return RetBoolean{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1B( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBVec2 subgroupShuffleXor( BVec2 const value
		, UInt const mask )
	{
		return RetBVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2B( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBVec3 subgroupShuffleXor( BVec3 const value
		, UInt const mask )
	{
		return RetBVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3B( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBVec4 subgroupShuffleXor( BVec4 const value
		, UInt const mask )
	{
		return RetBVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4B( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDouble subgroupShuffleXor( Double const value
		, UInt const mask )
	{
		return RetDouble{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1D( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDVec2 subgroupShuffleXor( DVec2 const value
		, UInt const mask )
	{
		return RetDVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2D( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDVec3 subgroupShuffleXor( DVec3 const value
		, UInt const mask )
	{
		return RetDVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3D( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDVec4 subgroupShuffleXor( DVec4 const value
		, UInt const mask )
	{
		return RetDVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4D( findTypesCache( value, mask )
					, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupShuffleUp
	/**
	*name
	*	subgroupShuffleUp
	*/
	/**@{*/
	RetFloat subgroupShuffleUp( Float const value
		, UInt const delta )
	{
		return RetFloat{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec2 subgroupShuffleUp( Vec2 const value
		, UInt const delta )
	{
		return RetVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec3 subgroupShuffleUp( Vec3 const value
		, UInt const delta )
	{
		return RetVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec4 subgroupShuffleUp( Vec4 const value
		, UInt const delta )
	{
		return RetVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetInt subgroupShuffleUp( Int const value
		, UInt const delta )
	{
		return RetInt{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetIVec2 subgroupShuffleUp( IVec2 const value
		, UInt const delta )
	{
		return RetIVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetIVec3 subgroupShuffleUp( IVec3 const value
		, UInt const delta )
	{
		return RetIVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetIVec4 subgroupShuffleUp( IVec4 const value
		, UInt const delta )
	{
		return RetIVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUInt subgroupShuffleUp( UInt const value
		, UInt const delta )
	{
		return RetUInt{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUVec2 subgroupShuffleUp( UVec2 const value
		, UInt const delta )
	{
		return RetUVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUVec3 subgroupShuffleUp( UVec3 const value
		, UInt const delta )
	{
		return RetUVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUVec4 subgroupShuffleUp( UVec4 const value
		, UInt const delta )
	{
		return RetUVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBoolean subgroupShuffleUp( Boolean const value
		, UInt const delta )
	{
		return RetBoolean{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec2 subgroupShuffleUp( BVec2 const value
		, UInt const delta )
	{
		return RetBVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec3 subgroupShuffleUp( BVec3 const value
		, UInt const delta )
	{
		return RetBVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec4 subgroupShuffleUp( BVec4 const value
		, UInt const delta )
	{
		return RetBVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDouble subgroupShuffleUp( Double const value
		, UInt const delta )
	{
		return RetDouble{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec2 subgroupShuffleUp( DVec2 const value
		, UInt const delta )
	{
		return RetDVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec3 subgroupShuffleUp( DVec3 const value
		, UInt const delta )
	{
		return RetDVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec4 subgroupShuffleUp( DVec4 const value
		, UInt const delta )
	{
		return RetDVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupShuffleDown
	/**
	*name
	*	subgroupShuffleDown
	*/
	/**@{*/
	RetFloat subgroupShuffleDown( Float const value
		, UInt const delta )
	{
		return RetFloat{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec2 subgroupShuffleDown( Vec2 const value
		, UInt const delta )
	{
		return RetVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec3 subgroupShuffleDown( Vec3 const value
		, UInt const delta )
	{
		return RetVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec4 subgroupShuffleDown( Vec4 const value
		, UInt const delta )
	{
		return RetVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4F( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetInt subgroupShuffleDown( Int const value
		, UInt const delta )
	{
		return RetInt{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetIVec2 subgroupShuffleDown( IVec2 const value
		, UInt const delta )
	{
		return RetIVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetIVec3 subgroupShuffleDown( IVec3 const value
		, UInt const delta )
	{
		return RetIVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetIVec4 subgroupShuffleDown( IVec4 const value
		, UInt const delta )
	{
		return RetIVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4I( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUInt subgroupShuffleDown( UInt const value
		, UInt const delta )
	{
		return RetUInt{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUVec2 subgroupShuffleDown( UVec2 const value
		, UInt const delta )
	{
		return RetUVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUVec3 subgroupShuffleDown( UVec3 const value
		, UInt const delta )
	{
		return RetUVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUVec4 subgroupShuffleDown( UVec4 const value
		, UInt const delta )
	{
		return RetUVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4U( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBoolean subgroupShuffleDown( Boolean const value
		, UInt const delta )
	{
		return RetBoolean{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec2 subgroupShuffleDown( BVec2 const value
		, UInt const delta )
	{
		return RetBVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec3 subgroupShuffleDown( BVec3 const value
		, UInt const delta )
	{
		return RetBVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec4 subgroupShuffleDown( BVec4 const value
		, UInt const delta )
	{
		return RetBVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4B( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDouble subgroupShuffleDown( Double const value
		, UInt const delta )
	{
		return RetDouble{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec2 subgroupShuffleDown( DVec2 const value
		, UInt const delta )
	{
		return RetDVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec3 subgroupShuffleDown( DVec3 const value
		, UInt const delta )
	{
		return RetDVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec4 subgroupShuffleDown( DVec4 const value
		, UInt const delta )
	{
		return RetDVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4D( findTypesCache( value, delta )
					, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupAdd
	/**
	*name
	*	subgroupAdd
	*/
	/**@{*/
	RetFloat subgroupAdd( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupAdd1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupAdd( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupAdd2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupAdd( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupAdd3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupAdd( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupAdd4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupAdd( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupAdd1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupAdd( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupAdd2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupAdd( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupAdd3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupAdd( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupAdd4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupAdd( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupAdd1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupAdd( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupAdd2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupAdd( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupAdd3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupAdd( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupAdd4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupAdd( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupAdd1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupAdd( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupAdd2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupAdd( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupAdd3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupAdd( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupAdd4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMul
	/**
	*name
	*	subgroupMul
	*/
	/**@{*/
	RetFloat subgroupMul( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupMul1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupMul( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupMul2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupMul( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupMul3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupMul( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupMul4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupMul( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupMul1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupMul( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupMul2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupMul( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupMul3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupMul( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupMul4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupMul( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupMul1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupMul( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupMul2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupMul( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupMul3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupMul( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupMul4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupMul( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupMul1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupMul( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupMul2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupMul( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupMul3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupMul( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupMul4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMin
	/**
	*name
	*	subgroupMin
	*/
	/**@{*/
	RetFloat subgroupMin( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupMin1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupMin( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupMin2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupMin( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupMin3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupMin( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupMin4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupMin( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupMin1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupMin( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupMin2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupMin( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupMin3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupMin( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupMin4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupMin( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupMin1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupMin( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupMin2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupMin( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupMin3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupMin( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupMin4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupMin( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupMin1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupMin( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupMin2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupMin( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupMin3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupMin( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupMin4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupMax
	/**
	*name
	*	subgroupMax
	*/
	/**@{*/
	RetFloat subgroupMax( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupMax1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupMax( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupMax2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupMax( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupMax3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupMax( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupMax4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupMax( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupMax1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupMax( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupMax2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupMax( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupMax3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupMax( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupMax4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupMax( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupMax1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupMax( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupMax2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupMax( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupMax3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupMax( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupMax4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupMax( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupMax1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupMax( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupMax2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupMax( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupMax3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupMax( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupMax4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupAnd
	/**
	*name
	*	subgroupAnd
	*/
	/**@{*/
	RetInt subgroupAnd( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupAnd1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupAnd( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupAnd2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupAnd( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupAnd3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupAnd( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupAnd4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupAnd( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupAnd1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupAnd( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupAnd2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupAnd( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupAnd3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupAnd( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupAnd4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAnd( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAnd1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupAnd( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupAnd2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupAnd( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupAnd3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupAnd( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupAnd4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupOr
	/**
	*name
	*	subgroupOr
	*/
	/**@{*/
	RetInt subgroupOr( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupOr1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupOr( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupOr2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupOr( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupOr3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupOr( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupOr4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupOr( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupOr1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupOr( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupOr2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupOr( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupOr3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupOr( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupOr4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupOr( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupOr1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupOr( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupOr2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupOr( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupOr3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupOr( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupOr4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupXor
	/**
	*name
	*	subgroupXor
	*/
	/**@{*/
	RetInt subgroupXor( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupXor1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupXor( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupXor2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupXor( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupXor3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupXor( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupXor4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupXor( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupXor1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupXor( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupXor2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupXor( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupXor3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupXor( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupXor4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupXor( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupXor1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupXor( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupXor2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupXor( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupXor3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupXor( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupXor4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveAdd
	/**
	*name
	*	subgroupInclusiveAdd
	*/
	/**@{*/
	RetFloat subgroupInclusiveAdd( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveAdd( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveAdd( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveAdd( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupInclusiveAdd( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveAdd( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveAdd( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveAdd( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveAdd( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveAdd( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveAdd( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveAdd( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveAdd( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveAdd( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveAdd( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveAdd( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveMul
	/**
	*name
	*	subgroupInclusiveMul
	*/
	/**@{*/
	RetFloat subgroupInclusiveMul( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveMul( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveMul( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveMul( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupInclusiveMul( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveMul( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveMul( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveMul( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveMul( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveMul( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveMul( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveMul( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveMul( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveMul( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveMul( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveMul( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveMin
	/**
	*name
	*	subgroupInclusiveMin
	*/
	/**@{*/
	RetFloat subgroupInclusiveMin( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveMin( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveMin( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveMin( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupInclusiveMin( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveMin( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveMin( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveMin( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveMin( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveMin( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveMin( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveMin( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveMin( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveMin( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveMin( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveMin( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveMax
	/**
	*name
	*	subgroupInclusiveMax
	*/
	/**@{*/
	RetFloat subgroupInclusiveMax( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveMax( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveMax( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveMax( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupInclusiveMax( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveMax( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveMax( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveMax( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveMax( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveMax( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveMax( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveMax( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveMax( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveMax( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveMax( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveMax( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveAnd
	/**
	*name
	*	subgroupInclusiveAnd
	*/
	/**@{*/
	RetInt subgroupInclusiveAnd( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveAnd( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveAnd( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveAnd( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveAnd( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveAnd( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveAnd( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveAnd( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupInclusiveAnd( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupInclusiveAnd( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupInclusiveAnd( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupInclusiveAnd( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveOr
	/**
	*name
	*	subgroupInclusiveOr
	*/
	/**@{*/
	RetInt subgroupInclusiveOr( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveOr( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveOr( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveOr( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveOr( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveOr( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveOr( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveOr( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupInclusiveOr( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupInclusiveOr( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupInclusiveOr( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupInclusiveOr( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupInclusiveXor
	/**
	*name
	*	subgroupInclusiveXor
	*/
	/**@{*/
	RetInt subgroupInclusiveXor( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupInclusiveXor( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupInclusiveXor( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupInclusiveXor( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupInclusiveXor( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupInclusiveXor( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupInclusiveXor( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupInclusiveXor( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupInclusiveXor( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupInclusiveXor( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupInclusiveXor( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupInclusiveXor( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveAdd
	/**
	*name
	*	subgroupExclusiveAdd
	*/
	/**@{*/
	RetFloat subgroupExclusiveAdd( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveAdd( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveAdd( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveAdd( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupExclusiveAdd( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveAdd( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveAdd( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveAdd( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveAdd( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveAdd( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveAdd( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveAdd( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveAdd( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveAdd( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveAdd( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveAdd( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveMul
	/**
	*name
	*	subgroupExclusiveMul
	*/
	/**@{*/
	RetFloat subgroupExclusiveMul( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveMul( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveMul( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveMul( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupExclusiveMul( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveMul( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveMul( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveMul( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveMul( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveMul( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveMul( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveMul( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveMul( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveMul( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveMul( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveMul( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveMin
	/**
	*name
	*	subgroupExclusiveMin
	*/
	/**@{*/
	RetFloat subgroupExclusiveMin( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveMin( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveMin( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveMin( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupExclusiveMin( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveMin( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveMin( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveMin( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveMin( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveMin( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveMin( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveMin( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveMin( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveMin( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveMin( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveMin( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveMax
	/**
	*name
	*	subgroupExclusiveMax
	*/
	/**@{*/
	RetFloat subgroupExclusiveMax( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveMax( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveMax( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveMax( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupExclusiveMax( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveMax( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveMax( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveMax( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveMax( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveMax( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveMax( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveMax( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveMax( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveMax( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveMax( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveMax( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveAnd
	/**
	*name
	*	subgroupExclusiveAnd
	*/
	/**@{*/
	RetInt subgroupExclusiveAnd( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveAnd( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveAnd( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveAnd( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveAnd( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveAnd( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveAnd( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveAnd( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupExclusiveAnd( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupExclusiveAnd( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupExclusiveAnd( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupExclusiveAnd( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveOr
	/**
	*name
	*	subgroupExclusiveOr
	*/
	/**@{*/
	RetInt subgroupExclusiveOr( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveOr( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveOr( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveOr( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveOr( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveOr( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveOr( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveOr( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupExclusiveOr( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupExclusiveOr( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupExclusiveOr( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupExclusiveOr( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupExclusiveXor
	/**
	*name
	*	subgroupExclusiveXor
	*/
	/**@{*/
	RetInt subgroupExclusiveXor( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupExclusiveXor( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupExclusiveXor( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupExclusiveXor( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupExclusiveXor( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupExclusiveXor( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupExclusiveXor( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupExclusiveXor( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupExclusiveXor( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupExclusiveXor( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupExclusiveXor( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupExclusiveXor( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterAdd
	/**
	*name
	*	subgroupClusterAdd
	*/
	/**@{*/
	RetFloat subgroupClusterAdd( Float const value
		, UInt const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterAdd( Vec2 const value
		, UInt const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterAdd( Vec3 const value
		, UInt const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterAdd( Vec4 const value
		, UInt const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt subgroupClusterAdd( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterAdd( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterAdd( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterAdd( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterAdd( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterAdd( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterAdd( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterAdd( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterAdd( Double const value
		, UInt const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterAdd( DVec2 const value
		, UInt const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterAdd( DVec3 const value
		, UInt const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterAdd( DVec4 const value
		, UInt const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterMul
	/**
	*name
	*	subgroupClusterMul
	*/
	/**@{*/
	RetFloat subgroupClusterMul( Float const value
		, UInt const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterMul( Vec2 const value
		, UInt const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterMul( Vec3 const value
		, UInt const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterMul( Vec4 const value
		, UInt const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt subgroupClusterMul( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterMul( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterMul( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterMul( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterMul( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterMul( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterMul( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterMul( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterMul( Double const value
		, UInt const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterMul( DVec2 const value
		, UInt const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterMul( DVec3 const value
		, UInt const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterMul( DVec4 const value
		, UInt const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterMin
	/**
	*name
	*	subgroupClusterMin
	*/
	/**@{*/
	RetFloat subgroupClusterMin( Float const value
		, UInt const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterMin( Vec2 const value
		, UInt const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterMin( Vec3 const value
		, UInt const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterMin( Vec4 const value
		, UInt const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt subgroupClusterMin( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterMin( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterMin( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterMin( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterMin( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterMin( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterMin( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterMin( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterMin( Double const value
		, UInt const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterMin( DVec2 const value
		, UInt const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterMin( DVec3 const value
		, UInt const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterMin( DVec4 const value
		, UInt const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterMax
	/**
	*name
	*	subgroupClusterMax
	*/
	/**@{*/
	RetFloat subgroupClusterMax( Float const value
		, UInt const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterMax( Vec2 const value
		, UInt const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterMax( Vec3 const value
		, UInt const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterMax( Vec4 const value
		, UInt const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4F( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt subgroupClusterMax( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterMax( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterMax( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterMax( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterMax( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterMax( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterMax( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterMax( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterMax( Double const value
		, UInt const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterMax( DVec2 const value
		, UInt const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterMax( DVec3 const value
		, UInt const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterMax( DVec4 const value
		, UInt const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4D( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterAnd
	/**
	*name
	*	subgroupClusterAnd
	*/
	/**@{*/
	RetInt subgroupClusterAnd( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterAnd( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterAnd( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterAnd( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterAnd( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterAnd( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterAnd( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterAnd( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBoolean subgroupClusterAnd( Boolean const value
		, UInt const clusterSize )
	{
		return RetBoolean{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd1B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec2 subgroupClusterAnd( BVec2 const value
		, UInt const clusterSize )
	{
		return RetBVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd2B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec3 subgroupClusterAnd( BVec3 const value
		, UInt const clusterSize )
	{
		return RetBVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd3B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec4 subgroupClusterAnd( BVec4 const value
		, UInt const clusterSize )
	{
		return RetBVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd4B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterOr
	/**
	*name
	*	subgroupClusterOr
	*/
	/**@{*/
	RetInt subgroupClusterOr( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterOr( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterOr( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterOr( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterOr( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterOr( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterOr( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterOr( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBoolean subgroupClusterOr( Boolean const value
		, UInt const clusterSize )
	{
		return RetBoolean{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr1B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec2 subgroupClusterOr( BVec2 const value
		, UInt const clusterSize )
	{
		return RetBVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr2B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec3 subgroupClusterOr( BVec3 const value
		, UInt const clusterSize )
	{
		return RetBVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr3B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec4 subgroupClusterOr( BVec4 const value
		, UInt const clusterSize )
	{
		return RetBVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr4B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupClusterXor
	/**
	*name
	*	subgroupClusterXor
	*/
	/**@{*/
	RetInt subgroupClusterXor( Int const value
		, UInt const clusterSize )
	{
		return RetInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor1I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec2 subgroupClusterXor( IVec2 const value
		, UInt const clusterSize )
	{
		return RetIVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor2I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec3 subgroupClusterXor( IVec3 const value
		, UInt const clusterSize )
	{
		return RetIVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor3I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetIVec4 subgroupClusterXor( IVec4 const value
		, UInt const clusterSize )
	{
		return RetIVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor4I( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt subgroupClusterXor( UInt const value
		, UInt const clusterSize )
	{
		return RetUInt{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor1U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec2 subgroupClusterXor( UVec2 const value
		, UInt const clusterSize )
	{
		return RetUVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor2U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec3 subgroupClusterXor( UVec3 const value
		, UInt const clusterSize )
	{
		return RetUVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor3U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUVec4 subgroupClusterXor( UVec4 const value
		, UInt const clusterSize )
	{
		return RetUVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor4U( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBoolean subgroupClusterXor( Boolean const value
		, UInt const clusterSize )
	{
		return RetBoolean{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor1B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec2 subgroupClusterXor( BVec2 const value
		, UInt const clusterSize )
	{
		return RetBVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor2B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec3 subgroupClusterXor( BVec3 const value
		, UInt const clusterSize )
	{
		return RetBVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor3B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec4 subgroupClusterXor( BVec4 const value
		, UInt const clusterSize )
	{
		return RetBVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor4B( findTypesCache( value, clusterSize )
					, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupQuadBroadcast
	/**
	*name
	*	subgroupQuadBroadcast
	*/
	/**@{*/
	RetFloat subgroupQuadBroadcast( Float const value
		, UInt const id )
	{
		return RetFloat{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec2 subgroupQuadBroadcast( Vec2 const value
		, UInt const id )
	{
		return RetVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec3 subgroupQuadBroadcast( Vec3 const value
		, UInt const id )
	{
		return RetVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec4 subgroupQuadBroadcast( Vec4 const value
		, UInt const id )
	{
		return RetVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4F( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetInt subgroupQuadBroadcast( Int const value
		, UInt const id )
	{
		return RetInt{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec2 subgroupQuadBroadcast( IVec2 const value
		, UInt const id )
	{
		return RetIVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec3 subgroupQuadBroadcast( IVec3 const value
		, UInt const id )
	{
		return RetIVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetIVec4 subgroupQuadBroadcast( IVec4 const value
		, UInt const id )
	{
		return RetIVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4I( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUInt subgroupQuadBroadcast( UInt const value
		, UInt const id )
	{
		return RetUInt{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec2 subgroupQuadBroadcast( UVec2 const value
		, UInt const id )
	{
		return RetUVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec3 subgroupQuadBroadcast( UVec3 const value
		, UInt const id )
	{
		return RetUVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUVec4 subgroupQuadBroadcast( UVec4 const value
		, UInt const id )
	{
		return RetUVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4U( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBoolean subgroupQuadBroadcast( Boolean const value
		, UInt const id )
	{
		return RetBoolean{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec2 subgroupQuadBroadcast( BVec2 const value
		, UInt const id )
	{
		return RetBVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec3 subgroupQuadBroadcast( BVec3 const value
		, UInt const id )
	{
		return RetBVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec4 subgroupQuadBroadcast( BVec4 const value
		, UInt const id )
	{
		return RetBVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4B( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDouble subgroupQuadBroadcast( Double const value
		, UInt const id )
	{
		return RetDouble{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec2 subgroupQuadBroadcast( DVec2 const value
		, UInt const id )
	{
		return RetDVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec3 subgroupQuadBroadcast( DVec3 const value
		, UInt const id )
	{
		return RetDVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec4 subgroupQuadBroadcast( DVec4 const value
		, UInt const id )
	{
		return RetDVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4D( findTypesCache( value, id )
					, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupQuadSwapHorizontal
	/**
	*name
	*	subgroupQuadSwapHorizontal
	*/
	/**@{*/
	RetFloat subgroupQuadSwapHorizontal( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupQuadSwapHorizontal( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupQuadSwapHorizontal( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupQuadSwapHorizontal( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupQuadSwapHorizontal( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupQuadSwapHorizontal( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupQuadSwapHorizontal( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupQuadSwapHorizontal( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupQuadSwapHorizontal( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupQuadSwapHorizontal( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupQuadSwapHorizontal( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupQuadSwapHorizontal( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupQuadSwapHorizontal( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupQuadSwapHorizontal( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupQuadSwapHorizontal( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupQuadSwapHorizontal( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupQuadSwapHorizontal( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupQuadSwapHorizontal( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupQuadSwapHorizontal( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupQuadSwapHorizontal( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupQuadSwapVertical
	/**
	*name
	*	subgroupQuadSwapVertical
	*/
	/**@{*/
	RetFloat subgroupQuadSwapVertical( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupQuadSwapVertical( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupQuadSwapVertical( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupQuadSwapVertical( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupQuadSwapVertical( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupQuadSwapVertical( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupQuadSwapVertical( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupQuadSwapVertical( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupQuadSwapVertical( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupQuadSwapVertical( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupQuadSwapVertical( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupQuadSwapVertical( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupQuadSwapVertical( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupQuadSwapVertical( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupQuadSwapVertical( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupQuadSwapVertical( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupQuadSwapVertical( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupQuadSwapVertical( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupQuadSwapVertical( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupQuadSwapVertical( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region subgroupQuadSwapDiagonal
	/**
	*name
	*	subgroupQuadSwapDiagonal
	*/
	/**@{*/
	RetFloat subgroupQuadSwapDiagonal( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupQuadSwapDiagonal( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupQuadSwapDiagonal( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupQuadSwapDiagonal( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4F( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt subgroupQuadSwapDiagonal( Int const value )
	{
		return RetInt{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec2 subgroupQuadSwapDiagonal( IVec2 const value )
	{
		return RetIVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec3 subgroupQuadSwapDiagonal( IVec3 const value )
	{
		return RetIVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetIVec4 subgroupQuadSwapDiagonal( IVec4 const value )
	{
		return RetIVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt subgroupQuadSwapDiagonal( UInt const value )
	{
		return RetUInt{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec2 subgroupQuadSwapDiagonal( UVec2 const value )
	{
		return RetUVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec3 subgroupQuadSwapDiagonal( UVec3 const value )
	{
		return RetUVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUVec4 subgroupQuadSwapDiagonal( UVec4 const value )
	{
		return RetUVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupQuadSwapDiagonal( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupQuadSwapDiagonal( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupQuadSwapDiagonal( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupQuadSwapDiagonal( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4B( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupQuadSwapDiagonal( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupQuadSwapDiagonal( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupQuadSwapDiagonal( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupQuadSwapDiagonal( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4D( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
}
