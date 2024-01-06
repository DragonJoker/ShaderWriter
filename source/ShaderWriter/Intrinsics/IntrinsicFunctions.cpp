/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#include "ShaderWriter/Helpers.hpp"
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
			, expr::makeDegrees1( findExprCache( radians )
				, findTypesCache( radians )
				, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	RetVec2 degrees( Vec2 const radians )
	{
		return RetVec2{ *findWriter( radians )
			, expr::makeDegrees2( findExprCache( radians )
				, findTypesCache( radians )
				, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	RetVec3 degrees( Vec3 const radians )
	{
		return RetVec3{ *findWriter( radians )
			, expr::makeDegrees3( findExprCache( radians )
				, findTypesCache( radians )
				, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	RetVec4 degrees( Vec4 const radians )
	{
		return RetVec4{ *findWriter( radians )
			, expr::makeDegrees4( findExprCache( radians )
				, findTypesCache( radians )
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
			, expr::makeRadians1F( findExprCache( degrees )
				, findTypesCache( degrees )
				, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	RetVec2 radians( Vec2 const degrees )
	{
		return RetVec2{ *findWriter( degrees )
			, expr::makeRadians2F( findExprCache( degrees )
				, findTypesCache( degrees )
				, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	RetVec3 radians( Vec3 const degrees )
	{
		return RetVec3{ *findWriter( degrees )
			, expr::makeRadians3F( findExprCache( degrees )
				, findTypesCache( degrees )
				, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	RetVec4 radians( Vec4 const degrees )
	{
		return RetVec4{ *findWriter( degrees )
			, expr::makeRadians4F( findExprCache( degrees )
				, findTypesCache( degrees )
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
			, expr::makeCos1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 cos( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeCos2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 cos( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeCos3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 cos( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeCos4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeSin1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sin( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSin2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sin( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSin3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sin( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSin4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeTan1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 tan( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeTan2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 tan( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeTan3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 tan( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeTan4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeCosh1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 cosh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeCosh2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 cosh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeCosh3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 cosh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeCosh4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeSinh1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sinh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSinh2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sinh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSinh3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sinh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSinh4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeTanh1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 tanh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeTanh2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 tanh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeTanh3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 tanh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeTanh4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAcos1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 acos( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAcos2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 acos( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAcos3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 acos( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAcos4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAsin1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 asin( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAsin2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 asin( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAsin3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 asin( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAsin4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAtan1( findExprCache( y_over_x )
				, findTypesCache( y_over_x )
				, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	RetVec2 atan( Vec2 const y_over_x )
	{
		return RetVec2{ *findWriter( y_over_x )
			, expr::makeAtan2( findExprCache( y_over_x )
				, findTypesCache( y_over_x )
				, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	RetVec3 atan( Vec3 const y_over_x )
	{
		return RetVec3{ *findWriter( y_over_x )
			, expr::makeAtan3( findExprCache( y_over_x )
				, findTypesCache( y_over_x )
				, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	RetVec4 atan( Vec4 const y_over_x )
	{
		return RetVec4{ *findWriter( y_over_x )
			, expr::makeAtan4( findExprCache( y_over_x )
				, findTypesCache( y_over_x )
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
			, expr::makeAtan21( findExprCache( y, x )
				, findTypesCache( y, x )
				, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	RetVec2 atan2( Vec2 const y
		, Vec2 const x )
	{
		return RetVec2{ *findWriter( y, x )
			, expr::makeAtan22( findExprCache( y, x )
				, findTypesCache( y, x )
				, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	RetVec3 atan2( Vec3 const y
		, Vec3 const x )
	{
		return RetVec3{ *findWriter( y, x )
			, expr::makeAtan23( findExprCache( y, x )
				, findTypesCache( y, x )
				, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	RetVec4 atan2( Vec4 const y
		, Vec4 const x )
	{
		return RetVec4{ *findWriter( y, x )
			, expr::makeAtan24( findExprCache( y, x )
				, findTypesCache( y, x )
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
			, expr::makeAcosh1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 acosh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAcosh2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 acosh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAcosh3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 acosh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAcosh4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAsinh1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 asinh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAsinh2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 asinh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAsinh3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 asinh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAsinh4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAtanh1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 atanh( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAtanh2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 atanh( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAtanh3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 atanh( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAtanh4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makePow1( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 pow( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makePow2( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 pow( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makePow3( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 pow( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makePow4( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeExp1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 exp( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeExp2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 exp( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeExp3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 exp( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeExp4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeLog1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 log( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeLog2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 log( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeLog3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 log( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeLog4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeExp21( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 exp2( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeExp22( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 exp2( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeExp23( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 exp2( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeExp24( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeLog21( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 log2( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeLog22( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 log2( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeLog23( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 log2( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeLog24( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeSqrt1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sqrt( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSqrt2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sqrt( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSqrt3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sqrt( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSqrt4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble sqrt( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeSqrt1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 sqrt( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeSqrt2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 sqrt( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeSqrt3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 sqrt( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeSqrt4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeInverseSqrt1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 inverseSqrt( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeInverseSqrt2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 inverseSqrt( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeInverseSqrt3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 inverseSqrt( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeInverseSqrt4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble inverseSqrt( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeInverseSqrt1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 inverseSqrt( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeInverseSqrt2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 inverseSqrt( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeInverseSqrt3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 inverseSqrt( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeInverseSqrt4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAbs1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 abs( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeAbs2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 abs( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeAbs3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 abs( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeAbs4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetInt32 abs( Int32 const x )
	{
		return RetInt32{ *findWriter( x )
			, expr::makeAbs1I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetI32Vec2 abs( I32Vec2 const x )
	{
		return RetI32Vec2{ *findWriter( x )
			, expr::makeAbs2I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetI32Vec3 abs( I32Vec3 const x )
	{
		return RetI32Vec3{ *findWriter( x )
			, expr::makeAbs3I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetI32Vec4 abs( I32Vec4 const x )
	{
		return RetI32Vec4{ *findWriter( x )
			, expr::makeAbs4I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble abs( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeAbs1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 abs( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeAbs2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 abs( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeAbs3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 abs( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeAbs4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeSign1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 sign( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeSign2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 sign( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeSign3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 sign( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeSign4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetInt32 sign( Int32 const x )
	{
		return RetInt32{ *findWriter( x )
			, expr::makeSign1I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetI32Vec2 sign( I32Vec2 const x )
	{
		return RetI32Vec2{ *findWriter( x )
			, expr::makeSign2I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetI32Vec3 sign( I32Vec3 const x )
	{
		return RetI32Vec3{ *findWriter( x )
			, expr::makeSign3I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetI32Vec4 sign( I32Vec4 const x )
	{
		return RetI32Vec4{ *findWriter( x )
			, expr::makeSign4I( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble sign( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeSign1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 sign( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeSign2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 sign( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeSign3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 sign( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeSign4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeFloor1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 floor( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeFloor2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 floor( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeFloor3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 floor( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeFloor4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble floor( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeFloor1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 floor( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeFloor2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 floor( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeFloor3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 floor( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeFloor4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeTrunc1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 trunc( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeTrunc2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 trunc( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeTrunc3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 trunc( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeTrunc4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble trunc( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeTrunc1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 trunc( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeTrunc2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 trunc( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeTrunc3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 trunc( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeTrunc4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeRound1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 round( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeRound2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 round( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeRound3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 round( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeRound4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble round( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeRound1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 round( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeRound2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 round( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeRound3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 round( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeRound4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeRoundEven1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 roundEven( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeRoundEven2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 roundEven( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeRoundEven3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 roundEven( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeRoundEven4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble roundEven( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeRoundEven1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 roundEven( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeRoundEven2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 roundEven( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeRoundEven3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 roundEven( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeRoundEven4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeCeil1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 ceil( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeCeil2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 ceil( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeCeil3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 ceil( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeCeil4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble ceil( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeCeil1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 ceil( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeCeil2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 ceil( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeCeil3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 ceil( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeCeil4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeFract1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 fract( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeFract2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 fract( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeFract3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 fract( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeFract4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble fract( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeFract1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 fract( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeFract2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 fract( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeFract3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 fract( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeFract4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeMod1F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 mod( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makeMod2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 mod( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeMod3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 mod( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makeMod4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble mod( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeMod1D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec2 mod( DVec2 const x
		, DVec2 const y )
	{
		return RetDVec2{ *findWriter( x, y )
			, expr::makeMod2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 mod( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeMod3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec4 mod( DVec4 const x
		, DVec4 const y )
	{
		return RetDVec4{ *findWriter( x, y )
			, expr::makeMod4D( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeModf1F( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetVec2 modf( Vec2 const x
		, Vec2 const i )
	{
		return RetVec2{ *findWriter( x, i )
			, expr::makeModf2F( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetVec3 modf( Vec3 const x
		, Vec3 const i )
	{
		return RetVec3{ *findWriter( x, i )
			, expr::makeModf3F( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetVec4 modf( Vec4 const x
		, Vec4 const i )
	{
		return RetVec4{ *findWriter( x, i )
			, expr::makeModf4F( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDouble modf( Double const x
		, Double const i )
	{
		return RetDouble{ *findWriter( x, i )
			, expr::makeModf1D( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDVec2 modf( DVec2 const x
		, DVec2 const i )
	{
		return RetDVec2{ *findWriter( x, i )
			, expr::makeModf2D( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDVec3 modf( DVec3 const x
		, DVec3 const i )
	{
		return RetDVec3{ *findWriter( x, i )
			, expr::makeModf3D( findExprCache( x, i )
				, findTypesCache( x, i )
				, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	RetDVec4 modf( DVec4 const x
		, DVec4 const i )
	{
		return RetDVec4{ *findWriter( x, i )
			, expr::makeModf4D( findExprCache( x, i )
				, findTypesCache( x, i )
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
			, expr::makeMin1F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 min( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makeMin2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 min( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeMin3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 min( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makeMin4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble min( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeMin1D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec2 min( DVec2 const x
		, DVec2 const y )
	{
		return RetDVec2{ *findWriter( x, y )
			, expr::makeMin2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 min( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeMin3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec4 min( DVec4 const x
		, DVec4 const y )
	{
		return RetDVec4{ *findWriter( x, y )
			, expr::makeMin4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetInt32 min( Int32 const x
		, Int32 const y )
	{
		return RetInt32{ *findWriter( x, y )
			, expr::makeMin1I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetI32Vec2 min( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetI32Vec2{ *findWriter( x, y )
			, expr::makeMin2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetI32Vec3 min( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetI32Vec3{ *findWriter( x, y )
			, expr::makeMin3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetI32Vec4 min( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetI32Vec4{ *findWriter( x, y )
			, expr::makeMin4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUInt32 min( UInt32 const x
		, UInt32 const y )
	{
		return RetUInt32{ *findWriter( x, y )
			, expr::makeMin1U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetU32Vec2 min( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetU32Vec2{ *findWriter( x, y )
			, expr::makeMin2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetU32Vec3 min( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetU32Vec3{ *findWriter( x, y )
			, expr::makeMin3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetU32Vec4 min( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetU32Vec4{ *findWriter( x, y )
			, expr::makeMin4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeMax1F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec2 max( Vec2 const x
		, Vec2 const y )
	{
		return RetVec2{ *findWriter( x, y )
			, expr::makeMax2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec3 max( Vec3 const x
		, Vec3 const y )
	{
		return RetVec3{ *findWriter( x, y )
			, expr::makeMax3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetVec4 max( Vec4 const x
		, Vec4 const y )
	{
		return RetVec4{ *findWriter( x, y )
			, expr::makeMax4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble max( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeMax1D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec2 max( DVec2 const x
		, DVec2 const y )
	{
		return RetDVec2{ *findWriter( x, y )
			, expr::makeMax2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 max( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeMax3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec4 max( DVec4 const x
		, DVec4 const y )
	{
		return RetDVec4{ *findWriter( x, y )
			, expr::makeMax4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetInt32 max( Int32 const x
		, Int32 const y )
	{
		return RetInt32{ *findWriter( x, y )
			, expr::makeMax1I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetI32Vec2 max( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetI32Vec2{ *findWriter( x, y )
			, expr::makeMax2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetI32Vec3 max( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetI32Vec3{ *findWriter( x, y )
			, expr::makeMax3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetI32Vec4 max( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetI32Vec4{ *findWriter( x, y )
			, expr::makeMax4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetUInt32 max( UInt32 const x
		, UInt32 const y )
	{
		return RetUInt32{ *findWriter( x, y )
			, expr::makeMax1U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetU32Vec2 max( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetU32Vec2{ *findWriter( x, y )
			, expr::makeMax2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetU32Vec3 max( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetU32Vec3{ *findWriter( x, y )
			, expr::makeMax3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetU32Vec4 max( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetU32Vec4{ *findWriter( x, y )
			, expr::makeMax4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeClamp1F( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp2F( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp3F( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp4F( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp1D( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp2D( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp3D( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeClamp4D( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetInt32 clamp( Int32 const x
		, Int32 const minVal
		, Int32 const maxVal )
	{
		return RetInt32{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1I( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetI32Vec2 clamp( I32Vec2 const x
		, I32Vec2 const minVal
		, I32Vec2 const maxVal )
	{
		return RetI32Vec2{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2I( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetI32Vec3 clamp( I32Vec3 const x
		, I32Vec3 const minVal
		, I32Vec3 const maxVal )
	{
		return RetI32Vec3{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3I( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetI32Vec4 clamp( I32Vec4 const x
		, I32Vec4 const minVal
		, I32Vec4 const maxVal )
	{
		return RetI32Vec4{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4I( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetUInt32 clamp( UInt32 const x
		, UInt32 const minVal
		, UInt32 const maxVal )
	{
		return RetUInt32{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1U( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetU32Vec2 clamp( U32Vec2 const x
		, U32Vec2 const minVal
		, U32Vec2 const maxVal )
	{
		return RetU32Vec2{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2U( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetU32Vec3 clamp( U32Vec3 const x
		, U32Vec3 const minVal
		, U32Vec3 const maxVal )
	{
		return RetU32Vec3{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3U( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
				, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	RetU32Vec4 clamp( U32Vec4 const x
		, U32Vec4 const minVal
		, U32Vec4 const maxVal )
	{
		return RetU32Vec4{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4U( findExprCache( x, minVal, maxVal )
				, findTypesCache( x, minVal, maxVal )
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
			, expr::makeMix1F( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix2F( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix3F( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix4F( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix1D( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix2D( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix3D( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeMix4D( findExprCache( x, y, a )
				, findTypesCache( x, y, a )
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
			, expr::makeStep1F( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetVec2 step( Vec2 const edge
		, Vec2 const x )
	{
		return RetVec2{ *findWriter( edge, x )
			, expr::makeStep2F( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetVec3 step( Vec3 const edge
		, Vec3 const x )
	{
		return RetVec3{ *findWriter( edge, x )
			, expr::makeStep3F( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetVec4 step( Vec4 const edge
		, Vec4 const x )
	{
		return RetVec4{ *findWriter( edge, x )
			, expr::makeStep4F( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDouble step( Double const edge
		, Double const x )
	{
		return RetDouble{ *findWriter( edge, x )
			, expr::makeStep1D( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDVec2 step( DVec2 const edge
		, DVec2 const x )
	{
		return RetDVec2{ *findWriter( edge, x )
			, expr::makeStep2D( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDVec3 step( DVec3 const edge
		, DVec3 const x )
	{
		return RetDVec3{ *findWriter( edge, x )
			, expr::makeStep3D( findExprCache( edge, x )
				, findTypesCache( edge, x )
				, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	RetDVec4 step( DVec4 const edge
		, DVec4 const x )
	{
		return RetDVec4{ *findWriter( edge, x )
			, expr::makeStep4D( findExprCache( edge, x )
				, findTypesCache( edge, x )
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
			, expr::makeSmoothStep1F( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep2F( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep3F( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep4F( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep1D( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep2D( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep3D( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeSmoothStep4D( findExprCache( edge0, edge1, x )
				, findTypesCache( edge0, edge1, x )
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
			, expr::makeIsnan1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isnan( Vec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsnan2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isnan( Vec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsnan3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isnan( Vec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsnan4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean isnan( Double const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeIsnan1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isnan( DVec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsnan2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isnan( DVec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsnan3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isnan( DVec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsnan4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeIsinf1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isinf( Vec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsinf2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isinf( Vec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsinf3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isinf( Vec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsinf4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean isinf( Double const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeIsinf1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec2 isinf( DVec2 const x )
	{
		return RetBVec2{ *findWriter( x )
			, expr::makeIsinf2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 isinf( DVec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeIsinf3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 isinf( DVec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeIsinf4D( findExprCache( x )
				, findTypesCache( x )
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
	RetInt32 floatBitsToInt( Float const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeFloatBitsToInt1( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 floatBitsToInt( Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeFloatBitsToInt2( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 floatBitsToInt( Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeFloatBitsToInt3( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 floatBitsToInt( Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeFloatBitsToInt4( findExprCache( value )
				, findTypesCache( value )
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
	RetUInt32 floatBitsToUInt( Float const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeFloatBitsToUInt1( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 floatBitsToUInt( Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeFloatBitsToUInt2( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 floatBitsToUInt( Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeFloatBitsToUInt3( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 floatBitsToUInt( Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeFloatBitsToUInt4( findExprCache( value )
				, findTypesCache( value )
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
	RetFloat intBitsToFloat( Int32 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeIntBitsToFloat1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 intBitsToFloat( I32Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeIntBitsToFloat2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 intBitsToFloat( I32Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeIntBitsToFloat3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 intBitsToFloat( I32Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeIntBitsToFloat4( findExprCache( x )
				, findTypesCache( x )
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
	RetFloat uintBitsToFloat( UInt32 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeUintBitsToFloat1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 uintBitsToFloat( U32Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeUintBitsToFloat2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 uintBitsToFloat( U32Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeUintBitsToFloat3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 uintBitsToFloat( U32Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeUintBitsToFloat4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeFma1F( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma2F( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma3F( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma4F( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma1D( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma2D( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma3D( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
			, expr::makeFma4D( findExprCache( a, b, c )
				, findTypesCache( a, b, c )
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
		, Int32 exp )
	{
		return RetFloat{ *findWriter( x, exp )
			, expr::makeFrexp1F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec2 frexp( Vec2 const x
		, I32Vec2 exp )
	{
		return RetVec2{ *findWriter( x, exp )
			, expr::makeFrexp2F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec3 frexp( Vec3 const x
		, I32Vec3 exp )
	{
		return RetVec3{ *findWriter( x, exp )
			, expr::makeFrexp3F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec4 frexp( Vec4 const x
		, I32Vec4 exp )
	{
		return RetVec4{ *findWriter( x, exp )
			, expr::makeFrexp4F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDouble frexp( Double const x
		, Int32 exp )
	{
		return RetDouble{ *findWriter( x, exp )
			, expr::makeFrexp1D( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec2 frexp( DVec2 const x
		, I32Vec2 exp )
	{
		return RetDVec2{ *findWriter( x, exp )
			, expr::makeFrexp2D( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec3 frexp( DVec3 const x
		, I32Vec3 exp )
	{
		return RetDVec3{ *findWriter( x, exp )
			, expr::makeFrexp3D( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec4 frexp( DVec4 const x
		, I32Vec4 exp )
	{
		return RetDVec4{ *findWriter( x, exp )
			, expr::makeFrexp4D( findExprCache( x, exp )
				, findTypesCache( x, exp )
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
		, Int32 const exp )
	{
		return RetFloat{ *findWriter( x, exp )
			, expr::makeLdexp1F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec2 ldexp( Vec2 const x
		, I32Vec2 const exp )
	{
		return RetVec2{ *findWriter( x, exp )
			, expr::makeLdexp2F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec3 ldexp( Vec3 const x
		, I32Vec3 const exp )
	{
		return RetVec3{ *findWriter( x, exp )
			, expr::makeLdexp3F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetVec4 ldexp( Vec4 const x
		, I32Vec4 const exp )
	{
		return RetVec4{ *findWriter( x, exp )
			, expr::makeLdexp4F( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDouble ldexp( Double const x
		, Int32 const exp )
	{
		return RetDouble{ *findWriter( x, exp )
			, expr::makeLdexp1D( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec2 ldexp( DVec2 const x
		, I32Vec2 const exp )
	{
		return RetDVec2{ *findWriter( x, exp )
			, expr::makeLdexp2D( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec3 ldexp( DVec3 const x
		, I32Vec3 const exp )
	{
		return RetDVec3{ *findWriter( x, exp )
			, expr::makeLdexp3D( findExprCache( x, exp )
				, findTypesCache( x, exp )
				, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	RetDVec4 ldexp( DVec4 const x
		, I32Vec4 const exp )
	{
		return RetDVec4{ *findWriter( x, exp )
			, expr::makeLdexp4D( findExprCache( x, exp )
				, findTypesCache( x, exp )
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
	RetDouble packDouble2x32( U32Vec2 const v )
	{
		return RetDouble{ *findWriter( v )
			, expr::makePackDouble2x32( findExprCache( v )
				, findTypesCache( v )
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
	RetUInt32 packHalf2x16( Vec2 const v )
	{
		return RetUInt32{ *findWriter( v )
			, expr::makePackHalf2x16( findExprCache( v )
				, findTypesCache( v )
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
	RetUInt32 packSnorm2x16( Vec2 const v )
	{
		return RetUInt32{ *findWriter( v )
			, expr::makePackSnorm2x16( findExprCache( v )
				, findTypesCache( v )
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
	RetUInt32 packSnorm4x8( Vec4 const v )
	{
		return RetUInt32{ *findWriter( v )
			, expr::makePackSnorm4x8( findExprCache( v )
				, findTypesCache( v )
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
	RetUInt32 packUnorm2x16( Vec2 const v )
	{
		return RetUInt32{ *findWriter( v )
			, expr::makePackUnorm2x16( findExprCache( v )
				, findTypesCache( v )
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
	RetUInt32 packUnorm4x8( Vec4 const v )
	{
		return RetUInt32{ *findWriter( v )
			, expr::makePackUnorm4x8( findExprCache( v )
				, findTypesCache( v )
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
	RetU32Vec2 unpackDouble2x32( Double const d )
	{
		return RetU32Vec2{ *findWriter( d )
			, expr::makeUnpackDouble2x32( findExprCache( d )
				, findTypesCache( d )
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
	RetVec2 unpackHalf2x16( UInt32 const v )
	{
		return RetVec2{ *findWriter( v )
			, expr::makeUnpackHalf2x16( findExprCache( v )
				, findTypesCache( v )
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
	RetVec2 unpackSnorm2x16( UInt32 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeUnpackSnorm2x16( findExprCache( p )
				, findTypesCache( p )
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
	RetVec4 unpackSnorm4x8( UInt32 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeUnpackSnorm4x8( findExprCache( p )
				, findTypesCache( p )
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
	RetVec2 unpackUnorm2x16( UInt32 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeUnpackUnorm2x16( findExprCache( p )
				, findTypesCache( p )
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
	RetVec4 unpackUnorm4x8( UInt32 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeUnpackUnorm4x8( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeLength1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetFloat length( Vec2 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetFloat length( Vec3 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetFloat length( Vec4 const x )
	{
		return RetFloat{ *findWriter( x )
			, expr::makeLength4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( DVec2 const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( DVec3 const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble length( DVec4 const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeLength4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeDistance1F( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetFloat distance( Vec2 const p0
		, Vec2 const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance2F( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetFloat distance( Vec3 const p0
		, Vec3 const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance3F( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetFloat distance( Vec4 const p0
		, Vec4 const p1 )
	{
		return RetFloat{ *findWriter( p0, p1 )
			, expr::makeDistance4F( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( Double const p0
		, Double const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance1D( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( DVec2 const p0
		, DVec2 const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance2D( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( DVec3 const p0
		, DVec3 const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance3D( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
				, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	RetDouble distance( DVec4 const p0
		, DVec4 const p1 )
	{
		return RetDouble{ *findWriter( p0, p1 )
			, expr::makeDistance4D( findExprCache( p0, p1 )
				, findTypesCache( p0, p1 )
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
			, expr::makeDot1F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetFloat dot( Vec2 const x
		, Vec2 const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetFloat dot( Vec3 const x
		, Vec3 const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetFloat dot( Vec4 const x
		, Vec4 const y )
	{
		return RetFloat{ *findWriter( x, y )
			, expr::makeDot4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( Double const x
		, Double const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot1D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( DVec2 const x
		, DVec2 const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( DVec3 const x
		, DVec3 const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDouble dot( DVec4 const x
		, DVec4 const y )
	{
		return RetDouble{ *findWriter( x, y )
			, expr::makeDot4D( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeCrossF( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDVec3 cross( DVec3 const x
		, DVec3 const y )
	{
		return RetDVec3{ *findWriter( x, y )
			, expr::makeCrossD( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeNormalize1F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 normalize( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeNormalize2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 normalize( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeNormalize3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 normalize( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeNormalize4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDouble normalize( Double const x )
	{
		return RetDouble{ *findWriter( x )
			, expr::makeNormalize1D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec2 normalize( DVec2 const x )
	{
		return RetDVec2{ *findWriter( x )
			, expr::makeNormalize2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec3 normalize( DVec3 const x )
	{
		return RetDVec3{ *findWriter( x )
			, expr::makeNormalize3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDVec4 normalize( DVec4 const x )
	{
		return RetDVec4{ *findWriter( x )
			, expr::makeNormalize4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeFaceForward1F( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward2F( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward3F( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward4F( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward1D( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward2D( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward3D( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeFaceForward4D( findExprCache( N, I, Nref )
				, findTypesCache( N, I, Nref )
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
			, expr::makeReflect1F( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetVec2 reflect( Vec2 const I
		, Vec2 const N )
	{
		return RetVec2{ *findWriter( I, N )
			, expr::makeReflect2F( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetVec3 reflect( Vec3 const I
		, Vec3 const N )
	{
		return RetVec3{ *findWriter( I, N )
			, expr::makeReflect3F( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetVec4 reflect( Vec4 const I
		, Vec4 const N )
	{
		return RetVec4{ *findWriter( I, N )
			, expr::makeReflect4F( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDouble reflect( Double const I
		, Double const N )
	{
		return RetDouble{ *findWriter( I, N )
			, expr::makeReflect1D( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDVec2 reflect( DVec2 const I
		, DVec2 const N )
	{
		return RetDVec2{ *findWriter( I, N )
			, expr::makeReflect2D( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDVec3 reflect( DVec3 const I
		, DVec3 const N )
	{
		return RetDVec3{ *findWriter( I, N )
			, expr::makeReflect3D( findExprCache( I, N )
				, findTypesCache( I, N )
				, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	RetDVec4 reflect( DVec4 const I
		, DVec4 const N )
	{
		return RetDVec4{ *findWriter( I, N )
			, expr::makeReflect4D( findExprCache( I, N )
				, findTypesCache( I, N )
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
			, expr::makeRefract1F( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract2F( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract3F( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract4F( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract1D( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract2D( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract3D( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeRefract4D( findExprCache( I, N, eta )
				, findTypesCache( I, N, eta )
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
			, expr::makeMatrixCompMult2x2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat2x3 matrixCompMult( Mat2x3 const x
		, Mat2x3 const y )
	{
		return RetMat2x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat2x4 matrixCompMult( Mat2x4 const x
		, Mat2x4 const y )
	{
		return RetMat2x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat3x2 matrixCompMult( Mat3x2 const x
		, Mat3x2 const y )
	{
		return RetMat3x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat3 matrixCompMult( Mat3 const x
		, Mat3 const y )
	{
		return RetMat3{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat3x4 matrixCompMult( Mat3x4 const x
		, Mat3x4 const y )
	{
		return RetMat3x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat4x2 matrixCompMult( Mat4x2 const x
		, Mat4x2 const y )
	{
		return RetMat4x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat4x3 matrixCompMult( Mat4x3 const x
		, Mat4x3 const y )
	{
		return RetMat4x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetMat4 matrixCompMult( Mat4 const x
		, Mat4 const y )
	{
		return RetMat4{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat2 matrixCompMult( DMat2 const x
		, DMat2 const y )
	{
		return RetDMat2{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat2x3 matrixCompMult( DMat2x3 const x
		, DMat2x3 const y )
	{
		return RetDMat2x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat2x4 matrixCompMult( DMat2x4 const x
		, DMat2x4 const y )
	{
		return RetDMat2x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat3x2 matrixCompMult( DMat3x2 const x
		, DMat3x2 const y )
	{
		return RetDMat3x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat3 matrixCompMult( DMat3 const x
		, DMat3 const y )
	{
		return RetDMat3{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat3x4 matrixCompMult( DMat3x4 const x
		, DMat3x4 const y )
	{
		return RetDMat3x4{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat4x2 matrixCompMult( DMat4x2 const x
		, DMat4x2 const y )
	{
		return RetDMat4x2{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat4x3 matrixCompMult( DMat4x3 const x
		, DMat4x3 const y )
	{
		return RetDMat4x3{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetDMat4 matrixCompMult( DMat4 const x
		, DMat4 const y )
	{
		return RetDMat4{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x4D( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeOuterProduct2x2F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat3 outerProduct( Vec3 const c
		, Vec3 const r )
	{
		return RetMat3{ *findWriter( c, r )
			, expr::makeOuterProduct3x3F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat4 outerProduct( Vec4 const c
		, Vec4 const r )
	{
		return RetMat4{ *findWriter( c, r )
			, expr::makeOuterProduct4x4F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat2x3 outerProduct( Vec3 const c
		, Vec2 const r )
	{
		return RetMat2x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x2F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat3x2 outerProduct( Vec2 const c
		, Vec3 const r )
	{
		return RetMat3x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x3F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat2x4 outerProduct( Vec4 const c
		, Vec2 const r )
	{
		return RetMat2x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x2F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat4x2 outerProduct( Vec2 const c
		, Vec4 const r )
	{
		return RetMat4x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x4F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat3x4 outerProduct( Vec4 const c
		, Vec3 const r )
	{
		return RetMat3x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x3F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetMat4x3 outerProduct( Vec3 const c
		, Vec4 const r )
	{
		return RetMat4x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x4F( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat2 outerProduct( DVec2 const c
		, DVec2 const r )
	{
		return RetDMat2{ *findWriter( c, r )
			, expr::makeOuterProduct2x2D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat3 outerProduct( DVec3 const c
		, DVec3 const r )
	{
		return RetDMat3{ *findWriter( c, r )
			, expr::makeOuterProduct3x3D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat4 outerProduct( DVec4 const c
		, DVec4 const r )
	{
		return RetDMat4{ *findWriter( c, r )
			, expr::makeOuterProduct4x4D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat2x3 outerProduct( DVec3 const c
		, DVec2 const r )
	{
		return RetDMat2x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x2D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat3x2 outerProduct( DVec2 const c
		, DVec3 const r )
	{
		return RetDMat3x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x3D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat2x4 outerProduct( DVec4 const c
		, DVec2 const r )
	{
		return RetDMat2x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x2D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat4x2 outerProduct( DVec2 const c
		, DVec4 const r )
	{
		return RetDMat4x2{ *findWriter( c, r )
			, expr::makeOuterProduct2x4D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat3x4 outerProduct( DVec4 const c
		, DVec3 const r )
	{
		return RetDMat3x4{ *findWriter( c, r )
			, expr::makeOuterProduct4x3D( findExprCache( c, r )
				, findTypesCache( c, r )
				, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	RetDMat4x3 outerProduct( DVec3 const c
		, DVec4 const r )
	{
		return RetDMat4x3{ *findWriter( c, r )
			, expr::makeOuterProduct3x4D( findExprCache( c, r )
				, findTypesCache( c, r )
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
			, expr::makeTranspose2x2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat3x2 transpose( Mat2x3 const x )
	{
		return RetMat3x2{ *findWriter( x )
			, expr::makeTranspose2x3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat4x2 transpose( Mat2x4 const x )
	{
		return RetMat4x2{ *findWriter( x )
			, expr::makeTranspose2x4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat2x3 transpose( Mat3x2 const x )
	{
		return RetMat2x3{ *findWriter( x )
			, expr::makeTranspose3x2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat3 transpose( Mat3 const x )
	{
		return RetMat3{ *findWriter( x )
			, expr::makeTranspose3x3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat4x3 transpose( Mat3x4 const x )
	{
		return RetMat4x3{ *findWriter( x )
			, expr::makeTranspose3x4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat2x4 transpose( Mat4x2 const x )
	{
		return RetMat2x4{ *findWriter( x )
			, expr::makeTranspose4x2F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat3x4 transpose( Mat4x3 const x )
	{
		return RetMat3x4{ *findWriter( x )
			, expr::makeTranspose4x3F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetMat4 transpose( Mat4 const x )
	{
		return RetMat4{ *findWriter( x )
			, expr::makeTranspose4x4F( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat2 transpose( DMat2 const x )
	{
		return RetDMat2{ *findWriter( x )
			, expr::makeTranspose2x2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat3x2 transpose( DMat2x3 const x )
	{
		return RetDMat3x2{ *findWriter( x )
			, expr::makeTranspose2x3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat4x2 transpose( DMat2x4 const x )
	{
		return RetDMat4x2{ *findWriter( x )
			, expr::makeTranspose2x4D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat2x3 transpose( DMat3x2 const x )
	{
		return RetDMat2x3{ *findWriter( x )
			, expr::makeTranspose3x2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat3 transpose( DMat3 const x )
	{
		return RetDMat3{ *findWriter( x )
			, expr::makeTranspose3x3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat4x3 transpose( DMat3x4 const x )
	{
		return RetDMat4x3{ *findWriter( x )
			, expr::makeTranspose3x4D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat2x4 transpose( DMat4x2 const x )
	{
		return RetDMat2x4{ *findWriter( x )
			, expr::makeTranspose4x2D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat3x4 transpose( DMat4x3 const x )
	{
		return RetDMat3x4{ *findWriter( x )
			, expr::makeTranspose4x3D( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetDMat4 transpose( DMat4 const x )
	{
		return RetDMat4{ *findWriter( x )
			, expr::makeTranspose4x4D( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeDeterminant2x2F( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetFloat determinant( Mat3 const m )
	{
		return RetFloat{ *findWriter( m )
			, expr::makeDeterminant3x3F( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetFloat determinant( Mat4 const m )
	{
		return RetFloat{ *findWriter( m )
			, expr::makeDeterminant4x4F( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDouble determinant( DMat2 const m )
	{
		return RetDouble{ *findWriter( m )
			, expr::makeDeterminant2x2D( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDouble determinant( DMat3 const m )
	{
		return RetDouble{ *findWriter( m )
			, expr::makeDeterminant3x3D( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDouble determinant( DMat4 const m )
	{
		return RetDouble{ *findWriter( m )
			, expr::makeDeterminant4x4D( findExprCache( m )
				, findTypesCache( m )
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
			, expr::makeInverse2x2F( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetMat3 inverse( Mat3 const m )
	{
		return RetMat3{ *findWriter( m )
			, expr::makeInverse3x3F( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetMat4 inverse( Mat4 const m )
	{
		return RetMat4{ *findWriter( m )
			, expr::makeInverse4x4F( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDMat2 inverse( DMat2 const m )
	{
		return RetDMat2{ *findWriter( m )
			, expr::makeInverse2x2D( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDMat3 inverse( DMat3 const m )
	{
		return RetDMat3{ *findWriter( m )
			, expr::makeInverse3x3D( findExprCache( m )
				, findTypesCache( m )
				, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	RetDMat4 inverse( DMat4 const m )
	{
		return RetDMat4{ *findWriter( m )
			, expr::makeInverse4x4D( findExprCache( m )
				, findTypesCache( m )
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
			, expr::makeLessThan2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThan( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThan( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThan( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThan2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThan( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThan3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThan( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThan4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeLessThanEqual2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThanEqual( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThanEqual( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 lessThanEqual( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeLessThanEqual2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 lessThanEqual( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeLessThanEqual3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 lessThanEqual( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeLessThanEqual4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeGreaterThan2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThan( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThan( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThan( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThan2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThan( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThan3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThan( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThan4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeGreaterThanEqual2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThanEqual( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThanEqual( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 greaterThanEqual( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 greaterThanEqual( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 greaterThanEqual( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeEqual2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 equal( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 equal( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 equal( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeEqual2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 equal( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeEqual3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 equal( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeEqual4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeNotEqual2F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( Vec3 const x
		, Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( Vec4 const x
		, Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4F( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 notEqual( DVec2 const x
		, DVec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( DVec3 const x
		, DVec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( DVec4 const x
		, DVec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4D( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 notEqual( I32Vec2 const x
		, I32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( I32Vec3 const x
		, I32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( I32Vec4 const x
		, I32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4I( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec2 notEqual( U32Vec2 const x
		, U32Vec2 const y )
	{
		return RetBVec2{ *findWriter( x, y )
			, expr::makeNotEqual2U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec3 notEqual( U32Vec3 const x
		, U32Vec3 const y )
	{
		return RetBVec3{ *findWriter( x, y )
			, expr::makeNotEqual3U( findExprCache( x, y )
				, findTypesCache( x, y )
				, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	RetBVec4 notEqual( U32Vec4 const x
		, U32Vec4 const y )
	{
		return RetBVec4{ *findWriter( x, y )
			, expr::makeNotEqual4U( findExprCache( x, y )
				, findTypesCache( x, y )
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
			, expr::makeAll2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean all( BVec3 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAll3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean all( BVec4 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAll4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeAny2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean any( BVec3 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAny3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBoolean any( BVec4 const x )
	{
		return RetBoolean{ *findWriter( x )
			, expr::makeAny4( findExprCache( x )
				, findTypesCache( x )
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
			, expr::makeNot2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec3 binNot( BVec3 const x )
	{
		return RetBVec3{ *findWriter( x )
			, expr::makeNot3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetBVec4 binNot( BVec4 const x )
	{
		return RetBVec4{ *findWriter( x )
			, expr::makeNot4( findExprCache( x )
				, findTypesCache( x )
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
	RetUInt32 uaddCarry( UInt32 const x
		, UInt32 const y
		, UInt32 const carry )
	{
		return RetUInt32{ *findWriter( x, y, carry )
			, expr::makeUaddCarry1( findExprCache( x, y, carry )
				, findTypesCache( x, y, carry )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	RetU32Vec2 uaddCarry( U32Vec2 const x
		, U32Vec2 const y
		, U32Vec2 const carry )
	{
		return RetU32Vec2{ *findWriter( x, y, carry )
			, expr::makeUaddCarry2( findExprCache( x, y, carry )
				, findTypesCache( x, y, carry )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	RetU32Vec3 uaddCarry( U32Vec3 const x
		, U32Vec3 const y
		, U32Vec3 const carry )
	{
		return RetU32Vec3{ *findWriter( x, y, carry )
			, expr::makeUaddCarry3( findExprCache( x, y, carry )
				, findTypesCache( x, y, carry )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	RetU32Vec4 uaddCarry( U32Vec4 const x
		, U32Vec4 const y
		, U32Vec4 const carry )
	{
		return RetU32Vec4{ *findWriter( x, y, carry )
			, expr::makeUaddCarry4( findExprCache( x, y, carry )
				, findTypesCache( x, y, carry )
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
	RetUInt32 usubBorrow( UInt32 const x
		, UInt32 const y
		, UInt32 const borrow )
	{
		return RetUInt32{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow1( findExprCache( x, y, borrow )
				, findTypesCache( x, y, borrow )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	RetU32Vec2 usubBorrow( U32Vec2 const x
		, U32Vec2 const y
		, U32Vec2 const borrow )
	{
		return RetU32Vec2{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow2( findExprCache( x, y, borrow )
				, findTypesCache( x, y, borrow )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	RetU32Vec3 usubBorrow( U32Vec3 const x
		, U32Vec3 const y
		, U32Vec3 const borrow )
	{
		return RetU32Vec3{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow3( findExprCache( x, y, borrow )
				, findTypesCache( x, y, borrow )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	RetU32Vec4 usubBorrow( U32Vec4 const x
		, U32Vec4 const y
		, U32Vec4 const borrow )
	{
		return RetU32Vec4{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow4( findExprCache( x, y, borrow )
				, findTypesCache( x, y, borrow )
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
	RetVoid umulExtended( UInt32 const x
		, UInt32 const y
		, UInt32 const msb
		, UInt32 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended1( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid umulExtended( U32Vec2 const x
		, U32Vec2 const y
		, U32Vec2 const msb
		, U32Vec2 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended2( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid umulExtended( U32Vec3 const x
		, U32Vec3 const y
		, U32Vec3 const msb
		, U32Vec3 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended3( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid umulExtended( U32Vec4 const x
		, U32Vec4 const y
		, U32Vec4 const msb
		, U32Vec4 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended4( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
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
	RetVoid imulExtended( Int32 const x
		, Int32 const y
		, Int32 const msb
		, Int32 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended1( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid imulExtended( I32Vec2 const x
		, I32Vec2 const y
		, I32Vec2 const msb
		, I32Vec2 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended2( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid imulExtended( I32Vec3 const x
		, I32Vec3 const y
		, I32Vec3 const msb
		, I32Vec3 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended3( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
				, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	RetVoid imulExtended( I32Vec4 const x
		, I32Vec4 const y
		, I32Vec4 const msb
		, I32Vec4 const lsb )
	{
		return RetVoid{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended4( findExprCache( x, y, msb, lsb )
				, findTypesCache( x, y, msb, lsb )
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
	RetInt32 bitfieldExtract( Int32 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetInt32{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract1I( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetI32Vec2 bitfieldExtract( I32Vec2 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetI32Vec2{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract2I( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetI32Vec3 bitfieldExtract( I32Vec3 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetI32Vec3{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract3I( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetI32Vec4 bitfieldExtract( I32Vec4 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetI32Vec4{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract4I( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetUInt32 bitfieldExtract( UInt32 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetUInt32{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract1U( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetU32Vec2 bitfieldExtract( U32Vec2 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetU32Vec2{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract2U( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetU32Vec3 bitfieldExtract( U32Vec3 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetU32Vec3{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract3U( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
				, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	RetU32Vec4 bitfieldExtract( U32Vec4 const value
		, Int32 const offset
		, Int32 const bits )
	{
		return RetU32Vec4{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract4U( findExprCache( value, offset, bits )
				, findTypesCache( value, offset, bits )
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
	RetInt32 bitfieldInsert( Int32 const base
		, Int32 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetInt32{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert1I( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetI32Vec2 bitfieldInsert( I32Vec2 const base
		, I32Vec2 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetI32Vec2{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert2I( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetI32Vec3 bitfieldInsert( I32Vec3 const base
		, I32Vec3 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetI32Vec3{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert3I( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetI32Vec4 bitfieldInsert( I32Vec4 const base
		, I32Vec4 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetI32Vec4{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert4I( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetUInt32 bitfieldInsert( UInt32 const base
		, UInt32 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetUInt32{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert1U( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetU32Vec2 bitfieldInsert( U32Vec2 const base
		, U32Vec2 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetU32Vec2{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert2U( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetU32Vec3 bitfieldInsert( U32Vec3 const base
		, U32Vec3 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetU32Vec3{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert3U( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
				, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	RetU32Vec4 bitfieldInsert( U32Vec4 const base
		, U32Vec4 const insert
		, Int32 const offset
		, Int32 const bits )
	{
		return RetU32Vec4{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert4U( findExprCache( base, insert, offset, bits )
				, findTypesCache( base, insert, offset, bits )
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
	RetInt32 bitfieldReverse( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeBitfieldReverse1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 bitfieldReverse( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeBitfieldReverse2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 bitfieldReverse( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeBitfieldReverse3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 bitfieldReverse( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeBitfieldReverse4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 bitfieldReverse( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeBitfieldReverse1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 bitfieldReverse( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeBitfieldReverse2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 bitfieldReverse( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeBitfieldReverse3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 bitfieldReverse( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeBitfieldReverse4U( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 bitCount( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeBitCount1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 bitCount( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeBitCount2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 bitCount( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeBitCount3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 bitCount( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeBitCount4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 bitCount( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeBitCount1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 bitCount( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeBitCount2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 bitCount( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeBitCount3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 bitCount( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeBitCount4U( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 findLSB( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeFindLSB1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 findLSB( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeFindLSB2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 findLSB( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeFindLSB3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 findLSB( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeFindLSB4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 findLSB( UInt32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeFindLSB1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 findLSB( U32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeFindLSB2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 findLSB( U32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeFindLSB3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 findLSB( U32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeFindLSB4U( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 findMSB( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeFindMSB1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 findMSB( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeFindMSB2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 findMSB( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeFindMSB3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 findMSB( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeFindMSB4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 findMSB( UInt32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeFindMSB1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 findMSB( U32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeFindMSB2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 findMSB( U32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeFindMSB3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 findMSB( U32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeFindMSB4U( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 atomicAdd( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicAddI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicAdd( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicAddU( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetFloat atomicAdd( Float const mem
		, Float const data )
	{
		return RetFloat{ *findWriter( mem, data )
			, expr::makeAtomicAddF( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec2 atomicAdd( HVec2 const mem
		, HVec2 const data )
	{
		return RetHVec2{ *findWriter( mem, data )
			, expr::makeAtomicAdd2H( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec4 atomicAdd( HVec4 const mem
		, HVec4 const data )
	{
		return RetHVec4{ *findWriter( mem, data )
			, expr::makeAtomicAdd4H( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicMin( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicMinI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicMin( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicMinU( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicMax( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicMaxI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicMax( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicMaxU( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicAnd( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicAndI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicAnd( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicAndU( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicOr( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicOrI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicOr( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicOrU( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicXor( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicXorI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicXor( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicXorU( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicExchange( Int32 const mem
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, data )
			, expr::makeAtomicExchangeI( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetUInt32 atomicExchange( UInt32 const mem
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, data )
			, expr::makeAtomicExchangeU( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetFloat atomicExchange( Float const mem
		, Float const data )
	{
		return RetFloat{ *findWriter( mem, data )
			, expr::makeAtomicExchangeF( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec2 atomicExchange( HVec2 const mem
		, HVec2 const data )
	{
		return RetHVec2{ *findWriter( mem, data )
			, expr::makeAtomicExchange2H( findExprCache( mem, data )
				, findTypesCache( mem, data )
				, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	RetHVec4 atomicExchange( HVec4 const mem
		, HVec4 const data )
	{
		return RetHVec4{ *findWriter( mem, data )
			, expr::makeAtomicExchange4H( findExprCache( mem, data )
				, findTypesCache( mem, data )
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
	RetInt32 atomicCompSwap( Int32 const mem
		, Int32 const compare
		, Int32 const data )
	{
		return RetInt32{ *findWriter( mem, compare, data )
			, expr::makeAtomicCompSwapI( findExprCache( mem, compare, data )
				, findTypesCache( mem, compare, data )
				, makeExpr( mem )
				, makeExpr( compare )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, compare, data ) };
	}
	RetUInt32 atomicCompSwap( UInt32 const mem
		, UInt32 const compare
		, UInt32 const data )
	{
		return RetUInt32{ *findWriter( mem, compare, data )
			, expr::makeAtomicCompSwapU( findExprCache( mem, compare, data )
				, findTypesCache( mem, compare, data )
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
			, expr::makeDFdx1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdx( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdx2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdx( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdx3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdx( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdx4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeDFdxCoarse1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdxCoarse( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdxCoarse2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdxCoarse( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdxCoarse3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdxCoarse( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdxCoarse4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeDFdxFine1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdxFine( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdxFine2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdxFine( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdxFine3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdxFine( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdxFine4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeDFdy1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdy( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdy2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdy( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdy3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdy( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdy4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeDFdyCoarse1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdyCoarse( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdyCoarse2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdyCoarse( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdyCoarse3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdyCoarse( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdyCoarse4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeDFdyFine1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 dFdyFine( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeDFdyFine2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 dFdyFine( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeDFdyFine3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 dFdyFine( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeDFdyFine4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeFwidth1( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec2 fwidth( Vec2 const p )
	{
		return RetVec2{ *findWriter( p )
			, expr::makeFwidth2( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec3 fwidth( Vec3 const p )
	{
		return RetVec3{ *findWriter( p )
			, expr::makeFwidth3( findExprCache( p )
				, findTypesCache( p )
				, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	RetVec4 fwidth( Vec4 const p )
	{
		return RetVec4{ *findWriter( p )
			, expr::makeFwidth4( findExprCache( p )
				, findTypesCache( p )
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
			, expr::makeInterpolateAtCentroid1( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec2 interpolateAtCentroid( Vec2 const x )
	{
		return RetVec2{ *findWriter( x )
			, expr::makeInterpolateAtCentroid2( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec3 interpolateAtCentroid( Vec3 const x )
	{
		return RetVec3{ *findWriter( x )
			, expr::makeInterpolateAtCentroid3( findExprCache( x )
				, findTypesCache( x )
				, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	RetVec4 interpolateAtCentroid( Vec4 const x )
	{
		return RetVec4{ *findWriter( x )
			, expr::makeInterpolateAtCentroid4( findExprCache( x )
				, findTypesCache( x )
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
		, Int32 const sample )
	{
		return RetFloat{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample1( findExprCache( interpolant, sample )
				, findTypesCache( interpolant, sample )
				, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	RetVec2 interpolateAtSample( Vec2 const interpolant
		, Int32 const sample )
	{
		return RetVec2{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample2( findExprCache( interpolant, sample )
				, findTypesCache( interpolant, sample )
				, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	RetVec3 interpolateAtSample( Vec3 const interpolant
		, Int32 const sample )
	{
		return RetVec3{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample3( findExprCache( interpolant, sample )
				, findTypesCache( interpolant, sample )
				, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	RetVec4 interpolateAtSample( Vec4 const interpolant
		, Int32 const sample )
	{
		return RetVec4{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample4( findExprCache( interpolant, sample )
				, findTypesCache( interpolant, sample )
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
			, expr::makeInterpolateAtOffset1( findExprCache( interpolant, offset )
				, findTypesCache( interpolant, offset )
				, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	RetVec2 interpolateAtOffset( Vec2 const interpolant
		, Vec2 const offset )
	{
		return RetVec2{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset2( findExprCache( interpolant, offset )
				, findTypesCache( interpolant, offset )
				, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	RetVec3 interpolateAtOffset( Vec3 const interpolant
		, Vec2 const offset )
	{
		return RetVec3{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset3( findExprCache( interpolant, offset )
				, findTypesCache( interpolant, offset )
				, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	RetVec4 interpolateAtOffset( Vec4 const interpolant
		, Vec2 const offset )
	{
		return RetVec4{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset4( findExprCache( interpolant, offset )
				, findTypesCache( interpolant, offset )
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
	RetVoid EmitStreamVertex( Int32 const stream )
	{
		return RetVoid{ *findWriter( stream )
			, expr::makeEmitStreamVertex( findExprCache( stream )
				, findTypesCache( stream )
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
	RetVoid EndStreamPrimitive( Int32 const stream )
	{
		return RetVoid{ *findWriter( stream )
			, expr::makeEndStreamPrimitive( findExprCache( stream )
				, findTypesCache( stream )
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
			, expr::makeEmitVertex( findExprCache( writer )
				, findTypesCache( writer ) )
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
			, expr::makeEndPrimitive( findExprCache( writer )
				, findTypesCache( writer ) )
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
			, expr::makeHelperInvocation( findExprCache( writer )
				, findTypesCache( writer ) )
			, areOptionalEnabled( writer ) };
	}
	/**@}*/
#pragma endregion
#pragma region controlBarrier
	/**
	*name
	*	controlBarrier
	*/
	/**@{*/
	RetVoid controlBarrier( type::Scope executionScope
		, type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return RetVoid{ *findWriter( executionScope, memoryScope, semantics )
			, expr::makeControlBarrier( findExprCache( executionScope, memoryScope, semantics )
				, findTypesCache( executionScope, memoryScope, semantics )
				, executionScope
				, memoryScope
				, semantics )
			, areOptionalEnabled( executionScope, memoryScope, semantics ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	RetVoid memoryBarrier( type::Scope memoryScope
		, type::MemorySemantics semantics )
	{
		return RetVoid{ *findWriter( memoryScope, semantics )
			, expr::makeMemoryBarrier( findExprCache( memoryScope, semantics )
				, findTypesCache( memoryScope, semantics )
				, memoryScope
				, semantics )
			, areOptionalEnabled( memoryScope, semantics ) };
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
		, UInt32 const rayFlags
		, UInt32 const cullMask
		, UInt32 const sbtRecordOffset
		, UInt32 const sbtRecordStride
		, UInt32 const missIndex
		, RayDesc const rayDesc
		, RayPayload const payload )
	{
		return RetVoid{ *findWriter( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload )
			, expr::makeTraceRay( findExprCache( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload )
				, findTypesCache( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload )
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
		, UInt32 const hitKind
		, HitAttribute const attribs )
	{
		return RetBoolean{ *findWriter( hitT, hitKind, attribs )
			, expr::makeReportIntersection( findExprCache( hitT, hitKind, attribs )
				, findTypesCache( hitT, hitKind, attribs )
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
	RetVoid executeCallable( UInt32 const sbtRecordIndex
		, CallableData const callable )
	{
		return RetVoid{ *findWriter( sbtRecordIndex, callable )
			, expr::makeExecuteCallable( findExprCache( sbtRecordIndex, callable )
				, findTypesCache( sbtRecordIndex, callable )
				, makeExpr( sbtRecordIndex )
				, makeExpr( callable ) )
			, areOptionalEnabled( sbtRecordIndex, callable ) };
	}
	/**@}*/
#pragma endregion
#pragma region setMeshOutputCountsNV
	/**
	*name
	*	setMeshOutputCountsNV
	*/
	/**@{*/
	RetVoid setMeshOutputCountsNV( UInt32 const numVertices
		, UInt32 const numPrimitives )
	{
		return RetVoid{ *findWriter( numVertices, numPrimitives )
			, expr::makeSetMeshOutputCountsNV( findExprCache( numVertices, numPrimitives )
				, findTypesCache( numVertices, numPrimitives )
				, makeExpr( numVertices )
				, makeExpr( numPrimitives ) )
			, areOptionalEnabled( numVertices, numPrimitives ) };
	}
	/**@}*/
#pragma endregion
#pragma region dispatchMeshNV
	/**
	*name
	*	dispatchMeshNV
	*/
	/**@{*/
	RetVoid dispatchMeshNV( TaskPayloadNV const payload
		, UInt32 const numTasks )
	{
		return RetVoid{ *findWriter( payload, numTasks )
			, expr::makeDispatchMeshNV( findExprCache( payload, numTasks )
				, findTypesCache( payload, numTasks )
				, makeExpr( payload )
				, makeExpr( numTasks ) )
			, areOptionalEnabled( payload, numTasks ) };
	}
	/**@}*/
#pragma endregion
#pragma region writePackedPrimitiveIndices4x8NV
	/**
	*name
	*	writePackedPrimitiveIndices4x8NV
	*/
	/**@{*/
	RetVoid writePackedPrimitiveIndices4x8NV( UInt32 const indexOffset
		, UInt32 const packedIndices )
	{
		return RetVoid{ *findWriter( indexOffset, packedIndices )
			, expr::makeWritePackedPrimitiveIndices4x8NV( findExprCache( indexOffset, packedIndices )
				, findTypesCache( indexOffset, packedIndices )
				, makeExpr( indexOffset )
				, makeExpr( packedIndices ) )
			, areOptionalEnabled( indexOffset, packedIndices ) };
	}
	/**@}*/
#pragma endregion
#pragma region setMeshOutputCounts
	/**
	*name
	*	setMeshOutputCounts
	*/
	/**@{*/
	RetVoid setMeshOutputCounts( UInt32 const numVertices
		, UInt32 const numPrimitives )
	{
		return RetVoid{ *findWriter( numVertices, numPrimitives )
			, expr::makeSetMeshOutputCounts( findExprCache( numVertices, numPrimitives )
				, findTypesCache( numVertices, numPrimitives )
				, makeExpr( numVertices )
				, makeExpr( numPrimitives ) )
			, areOptionalEnabled( numVertices, numPrimitives ) };
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
			, expr::makeSubgroupElect( findExprCache( writer )
				, findTypesCache( writer ) )
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
			, expr::makeSubgroupAll( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupAny( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupAllEqual1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Vec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Vec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Vec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Int32 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( I32Vec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( I32Vec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( I32Vec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( UInt32 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( U32Vec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( U32Vec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( U32Vec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( BVec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( BVec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( BVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( Double const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( DVec2 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( DVec3 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAllEqual( DVec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAllEqual4D( findExprCache( value )
				, findTypesCache( value )
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
		, UInt32 const id )
	{
		return RetFloat{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec2 subgroupBroadcast( Vec2 const value
		, UInt32 const id )
	{
		return RetVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec3 subgroupBroadcast( Vec3 const value
		, UInt32 const id )
	{
		return RetVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec4 subgroupBroadcast( Vec4 const value
		, UInt32 const id )
	{
		return RetVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetInt32 subgroupBroadcast( Int32 const value
		, UInt32 const id )
	{
		return RetInt32{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec2 subgroupBroadcast( I32Vec2 const value
		, UInt32 const id )
	{
		return RetI32Vec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec3 subgroupBroadcast( I32Vec3 const value
		, UInt32 const id )
	{
		return RetI32Vec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec4 subgroupBroadcast( I32Vec4 const value
		, UInt32 const id )
	{
		return RetI32Vec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUInt32 subgroupBroadcast( UInt32 const value
		, UInt32 const id )
	{
		return RetUInt32{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec2 subgroupBroadcast( U32Vec2 const value
		, UInt32 const id )
	{
		return RetU32Vec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec3 subgroupBroadcast( U32Vec3 const value
		, UInt32 const id )
	{
		return RetU32Vec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec4 subgroupBroadcast( U32Vec4 const value
		, UInt32 const id )
	{
		return RetU32Vec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBoolean subgroupBroadcast( Boolean const value
		, UInt32 const id )
	{
		return RetBoolean{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec2 subgroupBroadcast( BVec2 const value
		, UInt32 const id )
	{
		return RetBVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec3 subgroupBroadcast( BVec3 const value
		, UInt32 const id )
	{
		return RetBVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec4 subgroupBroadcast( BVec4 const value
		, UInt32 const id )
	{
		return RetBVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDouble subgroupBroadcast( Double const value
		, UInt32 const id )
	{
		return RetDouble{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast1D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec2 subgroupBroadcast( DVec2 const value
		, UInt32 const id )
	{
		return RetDVec2{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast2D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec3 subgroupBroadcast( DVec3 const value
		, UInt32 const id )
	{
		return RetDVec3{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast3D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec4 subgroupBroadcast( DVec4 const value
		, UInt32 const id )
	{
		return RetDVec4{ *findWriter( value, id )
			, expr::makeSubgroupBroadcast4D( findExprCache( value, id )
				, findTypesCache( value, id )
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
			, expr::makeSubgroupBroadcastFirst1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupBroadcastFirst( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupBroadcastFirst( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupBroadcastFirst( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupBroadcastFirst( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupBroadcastFirst( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupBroadcastFirst( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupBroadcastFirst( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupBroadcastFirst( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupBroadcastFirst( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupBroadcastFirst( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupBroadcastFirst( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupBroadcastFirst( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupBroadcastFirst( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupBroadcastFirst( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupBroadcastFirst( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupBroadcastFirst( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupBroadcastFirst( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupBroadcastFirst( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupBroadcastFirst( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupBroadcastFirst4D( findExprCache( value )
				, findTypesCache( value )
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
	RetU32Vec4 subgroupBallot( Boolean const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupBallot( findExprCache( value )
				, findTypesCache( value )
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
	RetBoolean subgroupInverseBallot( U32Vec4 const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInverseBallot( findExprCache( value )
				, findTypesCache( value )
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
	RetBoolean subgroupBallotBitExtract( U32Vec4 const value
		, UInt32 const index )
	{
		return RetBoolean{ *findWriter( value, index )
			, expr::makeSubgroupBallotBitExtract( findExprCache( value, index )
				, findTypesCache( value, index )
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
	RetUInt32 subgroupBallotBitCount( U32Vec4 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupBallotBitCount( findExprCache( value )
				, findTypesCache( value )
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
	RetUInt32 subgroupBallotInclusiveBitCount( U32Vec4 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupBallotInclusiveBitCount( findExprCache( value )
				, findTypesCache( value )
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
	RetUInt32 subgroupBallotExclusiveBitCount( U32Vec4 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupBallotExclusiveBitCount( findExprCache( value )
				, findTypesCache( value )
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
	RetUInt32 subgroupBallotFindLSB( U32Vec4 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupBallotFindLSB( findExprCache( value )
				, findTypesCache( value )
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
	RetUInt32 subgroupBallotFindMSB( U32Vec4 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupBallotFindMSB( findExprCache( value )
				, findTypesCache( value )
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
		, UInt32 const id )
	{
		return RetFloat{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec2 subgroupShuffle( Vec2 const value
		, UInt32 const id )
	{
		return RetVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec3 subgroupShuffle( Vec3 const value
		, UInt32 const id )
	{
		return RetVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec4 subgroupShuffle( Vec4 const value
		, UInt32 const id )
	{
		return RetVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetInt32 subgroupShuffle( Int32 const value
		, UInt32 const id )
	{
		return RetInt32{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec2 subgroupShuffle( I32Vec2 const value
		, UInt32 const id )
	{
		return RetI32Vec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec3 subgroupShuffle( I32Vec3 const value
		, UInt32 const id )
	{
		return RetI32Vec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec4 subgroupShuffle( I32Vec4 const value
		, UInt32 const id )
	{
		return RetI32Vec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUInt32 subgroupShuffle( UInt32 const value
		, UInt32 const id )
	{
		return RetUInt32{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec2 subgroupShuffle( U32Vec2 const value
		, UInt32 const id )
	{
		return RetU32Vec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec3 subgroupShuffle( U32Vec3 const value
		, UInt32 const id )
	{
		return RetU32Vec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec4 subgroupShuffle( U32Vec4 const value
		, UInt32 const id )
	{
		return RetU32Vec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBoolean subgroupShuffle( Boolean const value
		, UInt32 const id )
	{
		return RetBoolean{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec2 subgroupShuffle( BVec2 const value
		, UInt32 const id )
	{
		return RetBVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec3 subgroupShuffle( BVec3 const value
		, UInt32 const id )
	{
		return RetBVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec4 subgroupShuffle( BVec4 const value
		, UInt32 const id )
	{
		return RetBVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDouble subgroupShuffle( Double const value
		, UInt32 const id )
	{
		return RetDouble{ *findWriter( value, id )
			, expr::makeSubgroupShuffle1D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec2 subgroupShuffle( DVec2 const value
		, UInt32 const id )
	{
		return RetDVec2{ *findWriter( value, id )
			, expr::makeSubgroupShuffle2D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec3 subgroupShuffle( DVec3 const value
		, UInt32 const id )
	{
		return RetDVec3{ *findWriter( value, id )
			, expr::makeSubgroupShuffle3D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec4 subgroupShuffle( DVec4 const value
		, UInt32 const id )
	{
		return RetDVec4{ *findWriter( value, id )
			, expr::makeSubgroupShuffle4D( findExprCache( value, id )
				, findTypesCache( value, id )
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
		, UInt32 const mask )
	{
		return RetFloat{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1F( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetVec2 subgroupShuffleXor( Vec2 const value
		, UInt32 const mask )
	{
		return RetVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2F( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetVec3 subgroupShuffleXor( Vec3 const value
		, UInt32 const mask )
	{
		return RetVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3F( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetVec4 subgroupShuffleXor( Vec4 const value
		, UInt32 const mask )
	{
		return RetVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4F( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetInt32 subgroupShuffleXor( Int32 const value
		, UInt32 const mask )
	{
		return RetInt32{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1I( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetI32Vec2 subgroupShuffleXor( I32Vec2 const value
		, UInt32 const mask )
	{
		return RetI32Vec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2I( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetI32Vec3 subgroupShuffleXor( I32Vec3 const value
		, UInt32 const mask )
	{
		return RetI32Vec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3I( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetI32Vec4 subgroupShuffleXor( I32Vec4 const value
		, UInt32 const mask )
	{
		return RetI32Vec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4I( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetUInt32 subgroupShuffleXor( UInt32 const value
		, UInt32 const mask )
	{
		return RetUInt32{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1U( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetU32Vec2 subgroupShuffleXor( U32Vec2 const value
		, UInt32 const mask )
	{
		return RetU32Vec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2U( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetU32Vec3 subgroupShuffleXor( U32Vec3 const value
		, UInt32 const mask )
	{
		return RetU32Vec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3U( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetU32Vec4 subgroupShuffleXor( U32Vec4 const value
		, UInt32 const mask )
	{
		return RetU32Vec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4U( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBoolean subgroupShuffleXor( Boolean const value
		, UInt32 const mask )
	{
		return RetBoolean{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1B( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBVec2 subgroupShuffleXor( BVec2 const value
		, UInt32 const mask )
	{
		return RetBVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2B( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBVec3 subgroupShuffleXor( BVec3 const value
		, UInt32 const mask )
	{
		return RetBVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3B( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetBVec4 subgroupShuffleXor( BVec4 const value
		, UInt32 const mask )
	{
		return RetBVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4B( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDouble subgroupShuffleXor( Double const value
		, UInt32 const mask )
	{
		return RetDouble{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor1D( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDVec2 subgroupShuffleXor( DVec2 const value
		, UInt32 const mask )
	{
		return RetDVec2{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor2D( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDVec3 subgroupShuffleXor( DVec3 const value
		, UInt32 const mask )
	{
		return RetDVec3{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor3D( findExprCache( value, mask )
				, findTypesCache( value, mask )
				, makeExpr( value )
				, makeExpr( mask ) )
			, areOptionalEnabled( value, mask ) };
	}
	RetDVec4 subgroupShuffleXor( DVec4 const value
		, UInt32 const mask )
	{
		return RetDVec4{ *findWriter( value, mask )
			, expr::makeSubgroupShuffleXor4D( findExprCache( value, mask )
				, findTypesCache( value, mask )
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
		, UInt32 const delta )
	{
		return RetFloat{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec2 subgroupShuffleUp( Vec2 const value
		, UInt32 const delta )
	{
		return RetVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec3 subgroupShuffleUp( Vec3 const value
		, UInt32 const delta )
	{
		return RetVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec4 subgroupShuffleUp( Vec4 const value
		, UInt32 const delta )
	{
		return RetVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetInt32 subgroupShuffleUp( Int32 const value
		, UInt32 const delta )
	{
		return RetInt32{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetI32Vec2 subgroupShuffleUp( I32Vec2 const value
		, UInt32 const delta )
	{
		return RetI32Vec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetI32Vec3 subgroupShuffleUp( I32Vec3 const value
		, UInt32 const delta )
	{
		return RetI32Vec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetI32Vec4 subgroupShuffleUp( I32Vec4 const value
		, UInt32 const delta )
	{
		return RetI32Vec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUInt32 subgroupShuffleUp( UInt32 const value
		, UInt32 const delta )
	{
		return RetUInt32{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetU32Vec2 subgroupShuffleUp( U32Vec2 const value
		, UInt32 const delta )
	{
		return RetU32Vec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetU32Vec3 subgroupShuffleUp( U32Vec3 const value
		, UInt32 const delta )
	{
		return RetU32Vec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetU32Vec4 subgroupShuffleUp( U32Vec4 const value
		, UInt32 const delta )
	{
		return RetU32Vec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBoolean subgroupShuffleUp( Boolean const value
		, UInt32 const delta )
	{
		return RetBoolean{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec2 subgroupShuffleUp( BVec2 const value
		, UInt32 const delta )
	{
		return RetBVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec3 subgroupShuffleUp( BVec3 const value
		, UInt32 const delta )
	{
		return RetBVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec4 subgroupShuffleUp( BVec4 const value
		, UInt32 const delta )
	{
		return RetBVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDouble subgroupShuffleUp( Double const value
		, UInt32 const delta )
	{
		return RetDouble{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp1D( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec2 subgroupShuffleUp( DVec2 const value
		, UInt32 const delta )
	{
		return RetDVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp2D( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec3 subgroupShuffleUp( DVec3 const value
		, UInt32 const delta )
	{
		return RetDVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp3D( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec4 subgroupShuffleUp( DVec4 const value
		, UInt32 const delta )
	{
		return RetDVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleUp4D( findExprCache( value, delta )
				, findTypesCache( value, delta )
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
		, UInt32 const delta )
	{
		return RetFloat{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec2 subgroupShuffleDown( Vec2 const value
		, UInt32 const delta )
	{
		return RetVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec3 subgroupShuffleDown( Vec3 const value
		, UInt32 const delta )
	{
		return RetVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetVec4 subgroupShuffleDown( Vec4 const value
		, UInt32 const delta )
	{
		return RetVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4F( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetInt32 subgroupShuffleDown( Int32 const value
		, UInt32 const delta )
	{
		return RetInt32{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetI32Vec2 subgroupShuffleDown( I32Vec2 const value
		, UInt32 const delta )
	{
		return RetI32Vec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetI32Vec3 subgroupShuffleDown( I32Vec3 const value
		, UInt32 const delta )
	{
		return RetI32Vec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetI32Vec4 subgroupShuffleDown( I32Vec4 const value
		, UInt32 const delta )
	{
		return RetI32Vec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4I( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetUInt32 subgroupShuffleDown( UInt32 const value
		, UInt32 const delta )
	{
		return RetUInt32{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetU32Vec2 subgroupShuffleDown( U32Vec2 const value
		, UInt32 const delta )
	{
		return RetU32Vec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetU32Vec3 subgroupShuffleDown( U32Vec3 const value
		, UInt32 const delta )
	{
		return RetU32Vec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetU32Vec4 subgroupShuffleDown( U32Vec4 const value
		, UInt32 const delta )
	{
		return RetU32Vec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4U( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBoolean subgroupShuffleDown( Boolean const value
		, UInt32 const delta )
	{
		return RetBoolean{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec2 subgroupShuffleDown( BVec2 const value
		, UInt32 const delta )
	{
		return RetBVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec3 subgroupShuffleDown( BVec3 const value
		, UInt32 const delta )
	{
		return RetBVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetBVec4 subgroupShuffleDown( BVec4 const value
		, UInt32 const delta )
	{
		return RetBVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4B( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDouble subgroupShuffleDown( Double const value
		, UInt32 const delta )
	{
		return RetDouble{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown1D( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec2 subgroupShuffleDown( DVec2 const value
		, UInt32 const delta )
	{
		return RetDVec2{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown2D( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec3 subgroupShuffleDown( DVec3 const value
		, UInt32 const delta )
	{
		return RetDVec3{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown3D( findExprCache( value, delta )
				, findTypesCache( value, delta )
				, makeExpr( value )
				, makeExpr( delta ) )
			, areOptionalEnabled( value, delta ) };
	}
	RetDVec4 subgroupShuffleDown( DVec4 const value
		, UInt32 const delta )
	{
		return RetDVec4{ *findWriter( value, delta )
			, expr::makeSubgroupShuffleDown4D( findExprCache( value, delta )
				, findTypesCache( value, delta )
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
			, expr::makeSubgroupAdd1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupAdd( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupAdd2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupAdd( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupAdd3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupAdd( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupAdd4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupAdd( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupAdd1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupAdd( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupAdd2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupAdd( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupAdd3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupAdd( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupAdd4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupAdd( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupAdd1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupAdd( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupAdd2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupAdd( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupAdd3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupAdd( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupAdd4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupAdd( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupAdd1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupAdd( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupAdd2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupAdd( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupAdd3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupAdd( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupAdd4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupMul1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupMul( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupMul2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupMul( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupMul3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupMul( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupMul4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupMul( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupMul1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupMul( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupMul2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupMul( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupMul3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupMul( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupMul4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupMul( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupMul1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupMul( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupMul2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupMul( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupMul3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupMul( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupMul4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupMul( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupMul1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupMul( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupMul2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupMul( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupMul3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupMul( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupMul4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupMin1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupMin( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupMin2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupMin( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupMin3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupMin( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupMin4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupMin( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupMin1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupMin( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupMin2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupMin( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupMin3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupMin( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupMin4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupMin( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupMin1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupMin( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupMin2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupMin( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupMin3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupMin( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupMin4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupMin( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupMin1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupMin( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupMin2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupMin( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupMin3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupMin( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupMin4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupMax1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupMax( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupMax2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupMax( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupMax3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupMax( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupMax4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupMax( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupMax1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupMax( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupMax2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupMax( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupMax3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupMax( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupMax4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupMax( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupMax1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupMax( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupMax2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupMax( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupMax3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupMax( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupMax4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupMax( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupMax1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupMax( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupMax2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupMax( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupMax3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupMax( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupMax4D( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupAnd( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupAnd1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupAnd( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupAnd2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupAnd( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupAnd3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupAnd( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupAnd4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupAnd( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupAnd1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupAnd( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupAnd2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupAnd( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupAnd3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupAnd( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupAnd4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupAnd( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupAnd1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupAnd( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupAnd2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupAnd( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupAnd3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupAnd( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupAnd4B( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupOr( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupOr1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupOr( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupOr2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupOr( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupOr3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupOr( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupOr4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupOr( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupOr1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupOr( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupOr2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupOr( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupOr3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupOr( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupOr4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupOr( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupOr1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupOr( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupOr2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupOr( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupOr3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupOr( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupOr4B( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupXor( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupXor1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupXor( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupXor2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupXor( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupXor3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupXor( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupXor4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupXor( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupXor1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupXor( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupXor2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupXor( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupXor3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupXor( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupXor4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupXor( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupXor1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupXor( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupXor2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupXor( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupXor3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupXor( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupXor4B( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupInclusiveAdd1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveAdd( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveAdd( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveAdd( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupInclusiveAdd( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveAdd( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveAdd( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveAdd( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveAdd( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveAdd( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveAdd( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveAdd( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveAdd( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveAdd( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveAdd( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveAdd( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAdd4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupInclusiveMul1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveMul( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveMul( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveMul( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupInclusiveMul( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveMul( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveMul( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveMul( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveMul( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveMul( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveMul( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveMul( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveMul( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveMul( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveMul( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveMul( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMul4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupInclusiveMin1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveMin( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveMin( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveMin( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupInclusiveMin( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveMin( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveMin( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveMin( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveMin( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveMin( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveMin( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveMin( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveMin( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveMin( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveMin( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveMin( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMin4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupInclusiveMax1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupInclusiveMax( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupInclusiveMax( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupInclusiveMax( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupInclusiveMax( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveMax( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveMax( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveMax( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveMax( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveMax( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveMax( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveMax( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupInclusiveMax( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupInclusiveMax( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupInclusiveMax( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupInclusiveMax( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveMax4D( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupInclusiveAnd( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveAnd( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveAnd( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveAnd( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveAnd( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveAnd( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveAnd( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveAnd( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupInclusiveAnd( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupInclusiveAnd( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupInclusiveAnd( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupInclusiveAnd( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveAnd4B( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupInclusiveOr( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveOr( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveOr( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveOr( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveOr( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveOr( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveOr( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveOr( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupInclusiveOr( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupInclusiveOr( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupInclusiveOr( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupInclusiveOr( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveOr4B( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupInclusiveXor( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupInclusiveXor( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupInclusiveXor( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupInclusiveXor( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupInclusiveXor( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupInclusiveXor( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupInclusiveXor( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupInclusiveXor( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupInclusiveXor( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupInclusiveXor( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupInclusiveXor( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupInclusiveXor( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupInclusiveXor4B( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupExclusiveAdd1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveAdd( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveAdd( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveAdd( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupExclusiveAdd( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveAdd( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveAdd( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveAdd( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveAdd( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveAdd( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveAdd( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveAdd( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveAdd( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveAdd( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveAdd( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveAdd( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAdd4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupExclusiveMul1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveMul( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveMul( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveMul( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupExclusiveMul( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveMul( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveMul( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveMul( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveMul( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveMul( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveMul( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveMul( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveMul( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveMul( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveMul( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveMul( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMul4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupExclusiveMin1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveMin( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveMin( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveMin( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupExclusiveMin( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveMin( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveMin( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveMin( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveMin( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveMin( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveMin( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveMin( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveMin( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveMin( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveMin( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveMin( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMin4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupExclusiveMax1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupExclusiveMax( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupExclusiveMax( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupExclusiveMax( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupExclusiveMax( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveMax( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveMax( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveMax( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveMax( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveMax( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveMax( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveMax( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupExclusiveMax( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupExclusiveMax( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupExclusiveMax( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupExclusiveMax( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveMax4D( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupExclusiveAnd( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveAnd( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveAnd( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveAnd( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveAnd( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveAnd( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveAnd( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveAnd( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupExclusiveAnd( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupExclusiveAnd( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupExclusiveAnd( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupExclusiveAnd( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveAnd4B( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupExclusiveOr( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveOr( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveOr( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveOr( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveOr( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveOr( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveOr( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveOr( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupExclusiveOr( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupExclusiveOr( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupExclusiveOr( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupExclusiveOr( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveOr4B( findExprCache( value )
				, findTypesCache( value )
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
	RetInt32 subgroupExclusiveXor( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupExclusiveXor( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupExclusiveXor( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupExclusiveXor( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupExclusiveXor( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupExclusiveXor( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupExclusiveXor( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupExclusiveXor( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupExclusiveXor( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupExclusiveXor( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupExclusiveXor( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupExclusiveXor( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupExclusiveXor4B( findExprCache( value )
				, findTypesCache( value )
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
		, UInt32 const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterAdd( Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterAdd( Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterAdd( Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt32 subgroupClusterAdd( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterAdd( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterAdd( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterAdd( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterAdd( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterAdd( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterAdd( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterAdd( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterAdd( Double const value
		, UInt32 const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd1D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterAdd( DVec2 const value
		, UInt32 const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd2D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterAdd( DVec3 const value
		, UInt32 const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd3D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterAdd( DVec4 const value
		, UInt32 const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAdd4D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
		, UInt32 const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterMul( Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterMul( Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterMul( Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt32 subgroupClusterMul( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterMul( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterMul( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterMul( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterMul( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterMul( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterMul( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterMul( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterMul( Double const value
		, UInt32 const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul1D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterMul( DVec2 const value
		, UInt32 const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul2D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterMul( DVec3 const value
		, UInt32 const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul3D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterMul( DVec4 const value
		, UInt32 const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMul4D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
		, UInt32 const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterMin( Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterMin( Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterMin( Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt32 subgroupClusterMin( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterMin( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterMin( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterMin( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterMin( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterMin( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterMin( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterMin( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterMin( Double const value
		, UInt32 const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin1D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterMin( DVec2 const value
		, UInt32 const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin2D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterMin( DVec3 const value
		, UInt32 const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin3D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterMin( DVec4 const value
		, UInt32 const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMin4D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
		, UInt32 const clusterSize )
	{
		return RetFloat{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec2 subgroupClusterMax( Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec3 subgroupClusterMax( Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetVec4 subgroupClusterMax( Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4F( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetInt32 subgroupClusterMax( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterMax( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterMax( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterMax( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterMax( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterMax( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterMax( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterMax( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDouble subgroupClusterMax( Double const value
		, UInt32 const clusterSize )
	{
		return RetDouble{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax1D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec2 subgroupClusterMax( DVec2 const value
		, UInt32 const clusterSize )
	{
		return RetDVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax2D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec3 subgroupClusterMax( DVec3 const value
		, UInt32 const clusterSize )
	{
		return RetDVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax3D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetDVec4 subgroupClusterMax( DVec4 const value
		, UInt32 const clusterSize )
	{
		return RetDVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterMax4D( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
	RetInt32 subgroupClusterAnd( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterAnd( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterAnd( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterAnd( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterAnd( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterAnd( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterAnd( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterAnd( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBoolean subgroupClusterAnd( Boolean const value
		, UInt32 const clusterSize )
	{
		return RetBoolean{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd1B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec2 subgroupClusterAnd( BVec2 const value
		, UInt32 const clusterSize )
	{
		return RetBVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd2B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec3 subgroupClusterAnd( BVec3 const value
		, UInt32 const clusterSize )
	{
		return RetBVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd3B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec4 subgroupClusterAnd( BVec4 const value
		, UInt32 const clusterSize )
	{
		return RetBVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterAnd4B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
	RetInt32 subgroupClusterOr( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterOr( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterOr( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterOr( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterOr( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterOr( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterOr( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterOr( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBoolean subgroupClusterOr( Boolean const value
		, UInt32 const clusterSize )
	{
		return RetBoolean{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr1B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec2 subgroupClusterOr( BVec2 const value
		, UInt32 const clusterSize )
	{
		return RetBVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr2B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec3 subgroupClusterOr( BVec3 const value
		, UInt32 const clusterSize )
	{
		return RetBVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr3B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec4 subgroupClusterOr( BVec4 const value
		, UInt32 const clusterSize )
	{
		return RetBVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterOr4B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
	RetInt32 subgroupClusterXor( Int32 const value
		, UInt32 const clusterSize )
	{
		return RetInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor1I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec2 subgroupClusterXor( I32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor2I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec3 subgroupClusterXor( I32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor3I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetI32Vec4 subgroupClusterXor( I32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetI32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor4I( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetUInt32 subgroupClusterXor( UInt32 const value
		, UInt32 const clusterSize )
	{
		return RetUInt32{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor1U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec2 subgroupClusterXor( U32Vec2 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor2U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec3 subgroupClusterXor( U32Vec3 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor3U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetU32Vec4 subgroupClusterXor( U32Vec4 const value
		, UInt32 const clusterSize )
	{
		return RetU32Vec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor4U( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBoolean subgroupClusterXor( Boolean const value
		, UInt32 const clusterSize )
	{
		return RetBoolean{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor1B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec2 subgroupClusterXor( BVec2 const value
		, UInt32 const clusterSize )
	{
		return RetBVec2{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor2B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec3 subgroupClusterXor( BVec3 const value
		, UInt32 const clusterSize )
	{
		return RetBVec3{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor3B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
				, makeExpr( value )
				, makeExpr( clusterSize ) )
			, areOptionalEnabled( value, clusterSize ) };
	}
	RetBVec4 subgroupClusterXor( BVec4 const value
		, UInt32 const clusterSize )
	{
		return RetBVec4{ *findWriter( value, clusterSize )
			, expr::makeSubgroupClusterXor4B( findExprCache( value, clusterSize )
				, findTypesCache( value, clusterSize )
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
		, UInt32 const id )
	{
		return RetFloat{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec2 subgroupQuadBroadcast( Vec2 const value
		, UInt32 const id )
	{
		return RetVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec3 subgroupQuadBroadcast( Vec3 const value
		, UInt32 const id )
	{
		return RetVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetVec4 subgroupQuadBroadcast( Vec4 const value
		, UInt32 const id )
	{
		return RetVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4F( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetInt32 subgroupQuadBroadcast( Int32 const value
		, UInt32 const id )
	{
		return RetInt32{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec2 subgroupQuadBroadcast( I32Vec2 const value
		, UInt32 const id )
	{
		return RetI32Vec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec3 subgroupQuadBroadcast( I32Vec3 const value
		, UInt32 const id )
	{
		return RetI32Vec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetI32Vec4 subgroupQuadBroadcast( I32Vec4 const value
		, UInt32 const id )
	{
		return RetI32Vec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4I( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetUInt32 subgroupQuadBroadcast( UInt32 const value
		, UInt32 const id )
	{
		return RetUInt32{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec2 subgroupQuadBroadcast( U32Vec2 const value
		, UInt32 const id )
	{
		return RetU32Vec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec3 subgroupQuadBroadcast( U32Vec3 const value
		, UInt32 const id )
	{
		return RetU32Vec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetU32Vec4 subgroupQuadBroadcast( U32Vec4 const value
		, UInt32 const id )
	{
		return RetU32Vec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4U( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBoolean subgroupQuadBroadcast( Boolean const value
		, UInt32 const id )
	{
		return RetBoolean{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec2 subgroupQuadBroadcast( BVec2 const value
		, UInt32 const id )
	{
		return RetBVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec3 subgroupQuadBroadcast( BVec3 const value
		, UInt32 const id )
	{
		return RetBVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetBVec4 subgroupQuadBroadcast( BVec4 const value
		, UInt32 const id )
	{
		return RetBVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4B( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDouble subgroupQuadBroadcast( Double const value
		, UInt32 const id )
	{
		return RetDouble{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast1D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec2 subgroupQuadBroadcast( DVec2 const value
		, UInt32 const id )
	{
		return RetDVec2{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast2D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec3 subgroupQuadBroadcast( DVec3 const value
		, UInt32 const id )
	{
		return RetDVec3{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast3D( findExprCache( value, id )
				, findTypesCache( value, id )
				, makeExpr( value )
				, makeExpr( id ) )
			, areOptionalEnabled( value, id ) };
	}
	RetDVec4 subgroupQuadBroadcast( DVec4 const value
		, UInt32 const id )
	{
		return RetDVec4{ *findWriter( value, id )
			, expr::makeSubgroupQuadBroadcast4D( findExprCache( value, id )
				, findTypesCache( value, id )
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
			, expr::makeSubgroupQuadSwapHorizontal1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupQuadSwapHorizontal( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupQuadSwapHorizontal( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupQuadSwapHorizontal( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupQuadSwapHorizontal( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupQuadSwapHorizontal( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupQuadSwapHorizontal( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupQuadSwapHorizontal( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupQuadSwapHorizontal( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupQuadSwapHorizontal( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupQuadSwapHorizontal( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupQuadSwapHorizontal( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupQuadSwapHorizontal( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupQuadSwapHorizontal( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupQuadSwapHorizontal( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupQuadSwapHorizontal( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupQuadSwapHorizontal( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupQuadSwapHorizontal( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupQuadSwapHorizontal( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupQuadSwapHorizontal( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapHorizontal4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupQuadSwapVertical1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupQuadSwapVertical( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupQuadSwapVertical( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupQuadSwapVertical( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupQuadSwapVertical( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupQuadSwapVertical( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupQuadSwapVertical( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupQuadSwapVertical( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupQuadSwapVertical( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupQuadSwapVertical( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupQuadSwapVertical( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupQuadSwapVertical( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupQuadSwapVertical( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupQuadSwapVertical( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupQuadSwapVertical( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupQuadSwapVertical( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupQuadSwapVertical( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupQuadSwapVertical( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupQuadSwapVertical( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupQuadSwapVertical( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapVertical4D( findExprCache( value )
				, findTypesCache( value )
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
			, expr::makeSubgroupQuadSwapDiagonal1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 subgroupQuadSwapDiagonal( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 subgroupQuadSwapDiagonal( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 subgroupQuadSwapDiagonal( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 subgroupQuadSwapDiagonal( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 subgroupQuadSwapDiagonal( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 subgroupQuadSwapDiagonal( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 subgroupQuadSwapDiagonal( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 subgroupQuadSwapDiagonal( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 subgroupQuadSwapDiagonal( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 subgroupQuadSwapDiagonal( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 subgroupQuadSwapDiagonal( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBoolean subgroupQuadSwapDiagonal( Boolean const value )
	{
		return RetBoolean{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec2 subgroupQuadSwapDiagonal( BVec2 const value )
	{
		return RetBVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec3 subgroupQuadSwapDiagonal( BVec3 const value )
	{
		return RetBVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetBVec4 subgroupQuadSwapDiagonal( BVec4 const value )
	{
		return RetBVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4B( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble subgroupQuadSwapDiagonal( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 subgroupQuadSwapDiagonal( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 subgroupQuadSwapDiagonal( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 subgroupQuadSwapDiagonal( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeSubgroupQuadSwapDiagonal4D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
#pragma region readInvocation
	/**
	*name
	*	readInvocation
	*/
	/**@{*/
	RetFloat readInvocation( Float const value
		, UInt const invocationIndex )
	{
		return RetFloat{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation1F( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetVec2 readInvocation( Vec2 const value
		, UInt const invocationIndex )
	{
		return RetVec2{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation2F( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetVec3 readInvocation( Vec3 const value
		, UInt const invocationIndex )
	{
		return RetVec3{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation3F( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetVec4 readInvocation( Vec4 const value
		, UInt const invocationIndex )
	{
		return RetVec4{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation4F( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetInt32 readInvocation( Int32 const value
		, UInt const invocationIndex )
	{
		return RetInt32{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation1I( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetI32Vec2 readInvocation( I32Vec2 const value
		, UInt const invocationIndex )
	{
		return RetI32Vec2{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation2I( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetI32Vec3 readInvocation( I32Vec3 const value
		, UInt const invocationIndex )
	{
		return RetI32Vec3{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation3I( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetI32Vec4 readInvocation( I32Vec4 const value
		, UInt const invocationIndex )
	{
		return RetI32Vec4{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation4I( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetUInt32 readInvocation( UInt32 const value
		, UInt const invocationIndex )
	{
		return RetUInt32{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation1U( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetU32Vec2 readInvocation( U32Vec2 const value
		, UInt const invocationIndex )
	{
		return RetU32Vec2{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation2U( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetU32Vec3 readInvocation( U32Vec3 const value
		, UInt const invocationIndex )
	{
		return RetU32Vec3{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation3U( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetU32Vec4 readInvocation( U32Vec4 const value
		, UInt const invocationIndex )
	{
		return RetU32Vec4{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation4U( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetDouble readInvocation( Double const value
		, UInt const invocationIndex )
	{
		return RetDouble{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation1D( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetDVec2 readInvocation( DVec2 const value
		, UInt const invocationIndex )
	{
		return RetDVec2{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation2D( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetDVec3 readInvocation( DVec3 const value
		, UInt const invocationIndex )
	{
		return RetDVec3{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation3D( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	RetDVec4 readInvocation( DVec4 const value
		, UInt const invocationIndex )
	{
		return RetDVec4{ *findWriter( value, invocationIndex )
			, expr::makeReadInvocation4D( findExprCache( value, invocationIndex )
				, findTypesCache( value, invocationIndex )
				, makeExpr( value )
				, makeExpr( invocationIndex ) )
			, areOptionalEnabled( value, invocationIndex ) };
	}
	/**@}*/
#pragma endregion
#pragma region readFirstInvocation
	/**
	*name
	*	readFirstInvocation
	*/
	/**@{*/
	RetFloat readFirstInvocation( Float const value )
	{
		return RetFloat{ *findWriter( value )
			, expr::makeReadFirstInvocation1F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec2 readFirstInvocation( Vec2 const value )
	{
		return RetVec2{ *findWriter( value )
			, expr::makeReadFirstInvocation2F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec3 readFirstInvocation( Vec3 const value )
	{
		return RetVec3{ *findWriter( value )
			, expr::makeReadFirstInvocation3F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetVec4 readFirstInvocation( Vec4 const value )
	{
		return RetVec4{ *findWriter( value )
			, expr::makeReadFirstInvocation4F( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetInt32 readFirstInvocation( Int32 const value )
	{
		return RetInt32{ *findWriter( value )
			, expr::makeReadFirstInvocation1I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec2 readFirstInvocation( I32Vec2 const value )
	{
		return RetI32Vec2{ *findWriter( value )
			, expr::makeReadFirstInvocation2I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec3 readFirstInvocation( I32Vec3 const value )
	{
		return RetI32Vec3{ *findWriter( value )
			, expr::makeReadFirstInvocation3I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetI32Vec4 readFirstInvocation( I32Vec4 const value )
	{
		return RetI32Vec4{ *findWriter( value )
			, expr::makeReadFirstInvocation4I( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetUInt32 readFirstInvocation( UInt32 const value )
	{
		return RetUInt32{ *findWriter( value )
			, expr::makeReadFirstInvocation1U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec2 readFirstInvocation( U32Vec2 const value )
	{
		return RetU32Vec2{ *findWriter( value )
			, expr::makeReadFirstInvocation2U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec3 readFirstInvocation( U32Vec3 const value )
	{
		return RetU32Vec3{ *findWriter( value )
			, expr::makeReadFirstInvocation3U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetU32Vec4 readFirstInvocation( U32Vec4 const value )
	{
		return RetU32Vec4{ *findWriter( value )
			, expr::makeReadFirstInvocation4U( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDouble readFirstInvocation( Double const value )
	{
		return RetDouble{ *findWriter( value )
			, expr::makeReadFirstInvocation1D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec2 readFirstInvocation( DVec2 const value )
	{
		return RetDVec2{ *findWriter( value )
			, expr::makeReadFirstInvocation2D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec3 readFirstInvocation( DVec3 const value )
	{
		return RetDVec3{ *findWriter( value )
			, expr::makeReadFirstInvocation3D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	RetDVec4 readFirstInvocation( DVec4 const value )
	{
		return RetDVec4{ *findWriter( value )
			, expr::makeReadFirstInvocation4D( findExprCache( value )
				, findTypesCache( value )
				, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	/**@}*/
#pragma endregion
}
