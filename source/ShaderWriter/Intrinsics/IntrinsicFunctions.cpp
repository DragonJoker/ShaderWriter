
/*
See LICENSE file in root folder
*/

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

#include <ASTGenerator/Expr/MakeIntrinsic.hpp>

namespace sdw
{
#pragma region degrees
	/**
	*name
	*	degrees
	*/
	/**@{*/
	Float degrees( Float const & radians )
	{
		return Float{ findShader( radians )
			, expr::makeDegrees1( makeExpr( radians ) ) };
	}
	Vec2 degrees( Vec2 const & radians )
	{
		return Vec2{ findShader( radians )
			, expr::makeDegrees2( makeExpr( radians ) ) };
	}
	Vec3 degrees( Vec3 const & radians )
	{
		return Vec3{ findShader( radians )
			, expr::makeDegrees3( makeExpr( radians ) ) };
	}
	Vec4 degrees( Vec4 const & radians )
	{
		return Vec4{ findShader( radians )
			, expr::makeDegrees4( makeExpr( radians ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	Float radians( Float const & degrees )
	{
		return Float{ findShader( degrees )
			, expr::makeRadians1F( makeExpr( degrees ) ) };
	}
	Vec2 radians( Vec2 const & degrees )
	{
		return Vec2{ findShader( degrees )
			, expr::makeRadians2F( makeExpr( degrees ) ) };
	}
	Vec3 radians( Vec3 const & degrees )
	{
		return Vec3{ findShader( degrees )
			, expr::makeRadians3F( makeExpr( degrees ) ) };
	}
	Vec4 radians( Vec4 const & degrees )
	{
		return Vec4{ findShader( degrees )
			, expr::makeRadians4F( makeExpr( degrees ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	Float cos( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeCos1( makeExpr( x ) ) };
	}
	Vec2 cos( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeCos2( makeExpr( x ) ) };
	}
	Vec3 cos( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeCos3( makeExpr( x ) ) };
	}
	Vec4 cos( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeCos4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	Float sin( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeSin1( makeExpr( x ) ) };
	}
	Vec2 sin( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeSin2( makeExpr( x ) ) };
	}
	Vec3 sin( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeSin3( makeExpr( x ) ) };
	}
	Vec4 sin( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeSin4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	Float tan( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeTan1( makeExpr( x ) ) };
	}
	Vec2 tan( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeTan2( makeExpr( x ) ) };
	}
	Vec3 tan( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeTan3( makeExpr( x ) ) };
	}
	Vec4 tan( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeTan4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	Float cosh( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeCosh1( makeExpr( x ) ) };
	}
	Vec2 cosh( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeCosh2( makeExpr( x ) ) };
	}
	Vec3 cosh( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeCosh3( makeExpr( x ) ) };
	}
	Vec4 cosh( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeCosh4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	Float sinh( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeSinh1( makeExpr( x ) ) };
	}
	Vec2 sinh( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeSinh2( makeExpr( x ) ) };
	}
	Vec3 sinh( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeSinh3( makeExpr( x ) ) };
	}
	Vec4 sinh( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeSinh4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	Float tanh( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeTanh1( makeExpr( x ) ) };
	}
	Vec2 tanh( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeTanh2( makeExpr( x ) ) };
	}
	Vec3 tanh( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeTanh3( makeExpr( x ) ) };
	}
	Vec4 tanh( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeTanh4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	Float acos( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAcos1( makeExpr( x ) ) };
	}
	Vec2 acos( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAcos2( makeExpr( x ) ) };
	}
	Vec3 acos( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAcos3( makeExpr( x ) ) };
	}
	Vec4 acos( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAcos4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	Float asin( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAsin1( makeExpr( x ) ) };
	}
	Vec2 asin( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAsin2( makeExpr( x ) ) };
	}
	Vec3 asin( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAsin3( makeExpr( x ) ) };
	}
	Vec4 asin( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAsin4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	Float atan( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAtan1( makeExpr( x ) ) };
	}
	Vec2 atan( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAtan2( makeExpr( x ) ) };
	}
	Vec3 atan( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAtan3( makeExpr( x ) ) };
	}
	Vec4 atan( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAtan4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	Float acosh( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAcosh1( makeExpr( x ) ) };
	}
	Vec2 acosh( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAcosh2( makeExpr( x ) ) };
	}
	Vec3 acosh( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAcosh3( makeExpr( x ) ) };
	}
	Vec4 acosh( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAcosh4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	Float asinh( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAsinh1( makeExpr( x ) ) };
	}
	Vec2 asinh( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAsinh2( makeExpr( x ) ) };
	}
	Vec3 asinh( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAsinh3( makeExpr( x ) ) };
	}
	Vec4 asinh( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAsinh4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	Float atanh( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAtanh1( makeExpr( x ) ) };
	}
	Vec2 atanh( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAtanh2( makeExpr( x ) ) };
	}
	Vec3 atanh( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAtanh3( makeExpr( x ) ) };
	}
	Vec4 atanh( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAtanh4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	Float pow( Float const & x
		, Float const & y )
	{
		return Float{ findShader( x, y )
			, expr::makePow1( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 pow( Vec2 const & x
		, Vec2 const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makePow2( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 pow( Vec3 const & x
		, Vec3 const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makePow3( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 pow( Vec4 const & x
		, Vec4 const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makePow4( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region exp
	/**
	*name
	*	exp
	*/
	/**@{*/
	Float exp( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeExp1( makeExpr( x ) ) };
	}
	Vec2 exp( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeExp2( makeExpr( x ) ) };
	}
	Vec3 exp( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeExp3( makeExpr( x ) ) };
	}
	Vec4 exp( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeExp4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	Float log( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeLog1( makeExpr( x ) ) };
	}
	Vec2 log( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeLog2( makeExpr( x ) ) };
	}
	Vec3 log( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeLog3( makeExpr( x ) ) };
	}
	Vec4 log( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeLog4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	Float exp2( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeExp21( makeExpr( x ) ) };
	}
	Vec2 exp2( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeExp22( makeExpr( x ) ) };
	}
	Vec3 exp2( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeExp23( makeExpr( x ) ) };
	}
	Vec4 exp2( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeExp24( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	Float log2( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeLog21( makeExpr( x ) ) };
	}
	Vec2 log2( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeLog22( makeExpr( x ) ) };
	}
	Vec3 log2( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeLog23( makeExpr( x ) ) };
	}
	Vec4 log2( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeLog24( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	Float sqrt( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeSqrt1F( makeExpr( x ) ) };
	}
	Vec2 sqrt( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeSqrt2F( makeExpr( x ) ) };
	}
	Vec3 sqrt( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeSqrt3F( makeExpr( x ) ) };
	}
	Vec4 sqrt( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeSqrt4F( makeExpr( x ) ) };
	}
	Double sqrt( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeSqrt1D( makeExpr( x ) ) };
	}
	DVec2 sqrt( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeSqrt2D( makeExpr( x ) ) };
	}
	DVec3 sqrt( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeSqrt3D( makeExpr( x ) ) };
	}
	DVec4 sqrt( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeSqrt4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	Float inverseSqrt( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeInverseSqrt1F( makeExpr( x ) ) };
	}
	Vec2 inverseSqrt( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeInverseSqrt2F( makeExpr( x ) ) };
	}
	Vec3 inverseSqrt( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeInverseSqrt3F( makeExpr( x ) ) };
	}
	Vec4 inverseSqrt( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeInverseSqrt4F( makeExpr( x ) ) };
	}
	Double inverseSqrt( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeInverseSqrt1D( makeExpr( x ) ) };
	}
	DVec2 inverseSqrt( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeInverseSqrt2D( makeExpr( x ) ) };
	}
	DVec3 inverseSqrt( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeInverseSqrt3D( makeExpr( x ) ) };
	}
	DVec4 inverseSqrt( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeInverseSqrt4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	Float abs( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeAbs1F( makeExpr( x ) ) };
	}
	Vec2 abs( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeAbs2F( makeExpr( x ) ) };
	}
	Vec3 abs( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeAbs3F( makeExpr( x ) ) };
	}
	Vec4 abs( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeAbs4F( makeExpr( x ) ) };
	}
	Int abs( Int const & x )
	{
		return Int{ findShader( x )
			, expr::makeAbs1I( makeExpr( x ) ) };
	}
	IVec2 abs( IVec2 const & x )
	{
		return IVec2{ findShader( x )
			, expr::makeAbs2I( makeExpr( x ) ) };
	}
	IVec3 abs( IVec3 const & x )
	{
		return IVec3{ findShader( x )
			, expr::makeAbs3I( makeExpr( x ) ) };
	}
	IVec4 abs( IVec4 const & x )
	{
		return IVec4{ findShader( x )
			, expr::makeAbs4I( makeExpr( x ) ) };
	}
	Double abs( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeAbs1D( makeExpr( x ) ) };
	}
	DVec2 abs( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeAbs2D( makeExpr( x ) ) };
	}
	DVec3 abs( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeAbs3D( makeExpr( x ) ) };
	}
	DVec4 abs( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeAbs4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	Float sign( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeSign1F( makeExpr( x ) ) };
	}
	Vec2 sign( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeSign2F( makeExpr( x ) ) };
	}
	Vec3 sign( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeSign3F( makeExpr( x ) ) };
	}
	Vec4 sign( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeSign4F( makeExpr( x ) ) };
	}
	Int sign( Int const & x )
	{
		return Int{ findShader( x )
			, expr::makeSign1I( makeExpr( x ) ) };
	}
	IVec2 sign( IVec2 const & x )
	{
		return IVec2{ findShader( x )
			, expr::makeSign2I( makeExpr( x ) ) };
	}
	IVec3 sign( IVec3 const & x )
	{
		return IVec3{ findShader( x )
			, expr::makeSign3I( makeExpr( x ) ) };
	}
	IVec4 sign( IVec4 const & x )
	{
		return IVec4{ findShader( x )
			, expr::makeSign4I( makeExpr( x ) ) };
	}
	Double sign( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeSign1D( makeExpr( x ) ) };
	}
	DVec2 sign( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeSign2D( makeExpr( x ) ) };
	}
	DVec3 sign( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeSign3D( makeExpr( x ) ) };
	}
	DVec4 sign( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeSign4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	Float floor( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeFloor1F( makeExpr( x ) ) };
	}
	Vec2 floor( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeFloor2F( makeExpr( x ) ) };
	}
	Vec3 floor( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeFloor3F( makeExpr( x ) ) };
	}
	Vec4 floor( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeFloor4F( makeExpr( x ) ) };
	}
	Double floor( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeFloor1D( makeExpr( x ) ) };
	}
	DVec2 floor( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeFloor2D( makeExpr( x ) ) };
	}
	DVec3 floor( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeFloor3D( makeExpr( x ) ) };
	}
	DVec4 floor( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeFloor4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	Float trunc( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeTrunc1F( makeExpr( x ) ) };
	}
	Vec2 trunc( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeTrunc2F( makeExpr( x ) ) };
	}
	Vec3 trunc( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeTrunc3F( makeExpr( x ) ) };
	}
	Vec4 trunc( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeTrunc4F( makeExpr( x ) ) };
	}
	Double trunc( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeTrunc1D( makeExpr( x ) ) };
	}
	DVec2 trunc( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeTrunc2D( makeExpr( x ) ) };
	}
	DVec3 trunc( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeTrunc3D( makeExpr( x ) ) };
	}
	DVec4 trunc( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeTrunc4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	Float round( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeRound1F( makeExpr( x ) ) };
	}
	Vec2 round( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeRound2F( makeExpr( x ) ) };
	}
	Vec3 round( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeRound3F( makeExpr( x ) ) };
	}
	Vec4 round( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeRound4F( makeExpr( x ) ) };
	}
	Double round( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeRound1D( makeExpr( x ) ) };
	}
	DVec2 round( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeRound2D( makeExpr( x ) ) };
	}
	DVec3 round( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeRound3D( makeExpr( x ) ) };
	}
	DVec4 round( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeRound4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	Float roundEven( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeRoundEven1F( makeExpr( x ) ) };
	}
	Vec2 roundEven( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeRoundEven2F( makeExpr( x ) ) };
	}
	Vec3 roundEven( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeRoundEven3F( makeExpr( x ) ) };
	}
	Vec4 roundEven( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeRoundEven4F( makeExpr( x ) ) };
	}
	Double roundEven( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeRoundEven1D( makeExpr( x ) ) };
	}
	DVec2 roundEven( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeRoundEven2D( makeExpr( x ) ) };
	}
	DVec3 roundEven( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeRoundEven3D( makeExpr( x ) ) };
	}
	DVec4 roundEven( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeRoundEven4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	Float ceil( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeCeil1F( makeExpr( x ) ) };
	}
	Vec2 ceil( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeCeil2F( makeExpr( x ) ) };
	}
	Vec3 ceil( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeCeil3F( makeExpr( x ) ) };
	}
	Vec4 ceil( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeCeil4F( makeExpr( x ) ) };
	}
	Double ceil( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeCeil1D( makeExpr( x ) ) };
	}
	DVec2 ceil( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeCeil2D( makeExpr( x ) ) };
	}
	DVec3 ceil( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeCeil3D( makeExpr( x ) ) };
	}
	DVec4 ceil( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeCeil4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	Float fract( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeFract1F( makeExpr( x ) ) };
	}
	Vec2 fract( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeFract2F( makeExpr( x ) ) };
	}
	Vec3 fract( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeFract3F( makeExpr( x ) ) };
	}
	Vec4 fract( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeFract4F( makeExpr( x ) ) };
	}
	Double fract( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeFract1D( makeExpr( x ) ) };
	}
	DVec2 fract( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeFract2D( makeExpr( x ) ) };
	}
	DVec3 fract( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeFract3D( makeExpr( x ) ) };
	}
	DVec4 fract( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeFract4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	Float mod( Float const & x
		, Float const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeMod11F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 mod( Vec2 const & x
		, Vec2 const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makeMod22F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 mod( Vec3 const & x
		, Vec3 const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeMod33F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 mod( Vec4 const & x
		, Vec4 const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makeMod44F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 mod( Vec2 const & x
		, Float const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makeMod21F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 mod( Vec3 const & x
		, Float const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeMod31F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 mod( Vec4 const & x
		, Float const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makeMod41F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double mod( Double const & x
		, Double const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeMod11D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec2 mod( DVec2 const & x
		, DVec2 const & y )
	{
		return DVec2{ findShader( x, y )
			, expr::makeMod22D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 mod( DVec3 const & x
		, DVec3 const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeMod33D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec4 mod( DVec4 const & x
		, DVec4 const & y )
	{
		return DVec4{ findShader( x, y )
			, expr::makeMod44D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec2 mod( DVec2 const & x
		, Double const & y )
	{
		return DVec2{ findShader( x, y )
			, expr::makeMod21D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 mod( DVec3 const & x
		, Double const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeMod31D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec4 mod( DVec4 const & x
		, Double const & y )
	{
		return DVec4{ findShader( x, y )
			, expr::makeMod41D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region modf
	/**
	*name
	*	modf
	*/
	/**@{*/
	Float modf( Float const & x
		, Float const & i )
	{
		return Float{ findShader( x, i )
			, expr::makeModf1F( makeExpr( x )
				, makeExpr( i ) ) };
	}
	Vec2 modf( Vec2 const & x
		, Vec2 const & i )
	{
		return Vec2{ findShader( x, i )
			, expr::makeModf2F( makeExpr( x )
				, makeExpr( i ) ) };
	}
	Vec3 modf( Vec3 const & x
		, Vec3 const & i )
	{
		return Vec3{ findShader( x, i )
			, expr::makeModf3F( makeExpr( x )
				, makeExpr( i ) ) };
	}
	Vec4 modf( Vec4 const & x
		, Vec4 const & i )
	{
		return Vec4{ findShader( x, i )
			, expr::makeModf4F( makeExpr( x )
				, makeExpr( i ) ) };
	}
	Double modf( Double const & x
		, Double const & i )
	{
		return Double{ findShader( x, i )
			, expr::makeModf1D( makeExpr( x )
				, makeExpr( i ) ) };
	}
	DVec2 modf( DVec2 const & x
		, DVec2 const & i )
	{
		return DVec2{ findShader( x, i )
			, expr::makeModf2D( makeExpr( x )
				, makeExpr( i ) ) };
	}
	DVec3 modf( DVec3 const & x
		, DVec3 const & i )
	{
		return DVec3{ findShader( x, i )
			, expr::makeModf3D( makeExpr( x )
				, makeExpr( i ) ) };
	}
	DVec4 modf( DVec4 const & x
		, DVec4 const & i )
	{
		return DVec4{ findShader( x, i )
			, expr::makeModf4D( makeExpr( x )
				, makeExpr( i ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region min
	/**
	*name
	*	min
	*/
	/**@{*/
	Float min( Float const & x
		, Float const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeMin11F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 min( Vec2 const & x
		, Vec2 const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makeMin22F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 min( Vec3 const & x
		, Vec3 const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeMin33F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 min( Vec4 const & x
		, Vec4 const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makeMin44F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 min( Vec2 const & x
		, Float const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makeMin21F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 min( Vec3 const & x
		, Float const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeMin31F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 min( Vec4 const & x
		, Float const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makeMin41F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double min( Double const & x
		, Double const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeMin11D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec2 min( DVec2 const & x
		, DVec2 const & y )
	{
		return DVec2{ findShader( x, y )
			, expr::makeMin22D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 min( DVec3 const & x
		, DVec3 const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeMin33D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec4 min( DVec4 const & x
		, DVec4 const & y )
	{
		return DVec4{ findShader( x, y )
			, expr::makeMin44D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec2 min( DVec2 const & x
		, Double const & y )
	{
		return DVec2{ findShader( x, y )
			, expr::makeMin21D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 min( DVec3 const & x
		, Double const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeMin31D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec4 min( DVec4 const & x
		, Double const & y )
	{
		return DVec4{ findShader( x, y )
			, expr::makeMin41D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Int min( Int const & x
		, Int const & y )
	{
		return Int{ findShader( x, y )
			, expr::makeMin11I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec2 min( IVec2 const & x
		, IVec2 const & y )
	{
		return IVec2{ findShader( x, y )
			, expr::makeMin22I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec3 min( IVec3 const & x
		, IVec3 const & y )
	{
		return IVec3{ findShader( x, y )
			, expr::makeMin33I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec4 min( IVec4 const & x
		, IVec4 const & y )
	{
		return IVec4{ findShader( x, y )
			, expr::makeMin44I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec2 min( IVec2 const & x
		, Int const & y )
	{
		return IVec2{ findShader( x, y )
			, expr::makeMin21I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec3 min( IVec3 const & x
		, Int const & y )
	{
		return IVec3{ findShader( x, y )
			, expr::makeMin31I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec4 min( IVec4 const & x
		, Int const & y )
	{
		return IVec4{ findShader( x, y )
			, expr::makeMin41I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UInt min( UInt const & x
		, UInt const & y )
	{
		return UInt{ findShader( x, y )
			, expr::makeMin11U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec2 min( UVec2 const & x
		, UVec2 const & y )
	{
		return UVec2{ findShader( x, y )
			, expr::makeMin22U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec3 min( UVec3 const & x
		, UVec3 const & y )
	{
		return UVec3{ findShader( x, y )
			, expr::makeMin33U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec4 min( UVec4 const & x
		, UVec4 const & y )
	{
		return UVec4{ findShader( x, y )
			, expr::makeMin44U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec2 min( UVec2 const & x
		, UInt const & y )
	{
		return UVec2{ findShader( x, y )
			, expr::makeMin21U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec3 min( UVec3 const & x
		, UInt const & y )
	{
		return UVec3{ findShader( x, y )
			, expr::makeMin31U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec4 min( UVec4 const & x
		, UInt const & y )
	{
		return UVec4{ findShader( x, y )
			, expr::makeMin41U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region max
	/**
	*name
	*	max
	*/
	/**@{*/
	Float max( Float const & x
		, Float const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeMax11F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 max( Vec2 const & x
		, Vec2 const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makeMax22F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 max( Vec3 const & x
		, Vec3 const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeMax33F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 max( Vec4 const & x
		, Vec4 const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makeMax44F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec2 max( Vec2 const & x
		, Float const & y )
	{
		return Vec2{ findShader( x, y )
			, expr::makeMax21F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec3 max( Vec3 const & x
		, Float const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeMax31F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Vec4 max( Vec4 const & x
		, Float const & y )
	{
		return Vec4{ findShader( x, y )
			, expr::makeMax41F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double max( Double const & x
		, Double const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeMax11D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec2 max( DVec2 const & x
		, DVec2 const & y )
	{
		return DVec2{ findShader( x, y )
			, expr::makeMax22D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 max( DVec3 const & x
		, DVec3 const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeMax33D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec4 max( DVec4 const & x
		, DVec4 const & y )
	{
		return DVec4{ findShader( x, y )
			, expr::makeMax44D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec2 max( DVec2 const & x
		, Double const & y )
	{
		return DVec2{ findShader( x, y )
			, expr::makeMax21D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 max( DVec3 const & x
		, Double const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeMax31D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec4 max( DVec4 const & x
		, Double const & y )
	{
		return DVec4{ findShader( x, y )
			, expr::makeMax41D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Int max( Int const & x
		, Int const & y )
	{
		return Int{ findShader( x, y )
			, expr::makeMax11I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec2 max( IVec2 const & x
		, IVec2 const & y )
	{
		return IVec2{ findShader( x, y )
			, expr::makeMax22I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec3 max( IVec3 const & x
		, IVec3 const & y )
	{
		return IVec3{ findShader( x, y )
			, expr::makeMax33I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec4 max( IVec4 const & x
		, IVec4 const & y )
	{
		return IVec4{ findShader( x, y )
			, expr::makeMax44I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec2 max( IVec2 const & x
		, Int const & y )
	{
		return IVec2{ findShader( x, y )
			, expr::makeMax21I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec3 max( IVec3 const & x
		, Int const & y )
	{
		return IVec3{ findShader( x, y )
			, expr::makeMax31I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	IVec4 max( IVec4 const & x
		, Int const & y )
	{
		return IVec4{ findShader( x, y )
			, expr::makeMax41I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UInt max( UInt const & x
		, UInt const & y )
	{
		return UInt{ findShader( x, y )
			, expr::makeMax11U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec2 max( UVec2 const & x
		, UVec2 const & y )
	{
		return UVec2{ findShader( x, y )
			, expr::makeMax22U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec3 max( UVec3 const & x
		, UVec3 const & y )
	{
		return UVec3{ findShader( x, y )
			, expr::makeMax33U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec4 max( UVec4 const & x
		, UVec4 const & y )
	{
		return UVec4{ findShader( x, y )
			, expr::makeMax44U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec2 max( UVec2 const & x
		, UInt const & y )
	{
		return UVec2{ findShader( x, y )
			, expr::makeMax21U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec3 max( UVec3 const & x
		, UInt const & y )
	{
		return UVec3{ findShader( x, y )
			, expr::makeMax31U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	UVec4 max( UVec4 const & x
		, UInt const & y )
	{
		return UVec4{ findShader( x, y )
			, expr::makeMax41U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region clamp
	/**
	*name
	*	clamp
	*/
	/**@{*/
	Float clamp( Float const & x
		, Float const & minVal
		, Float const & maxVal )
	{
		return Float{ findShader( x, minVal, maxVal )
			, expr::makeClamp11F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Vec2 clamp( Vec2 const & x
		, Vec2 const & minVal
		, Vec2 const & maxVal )
	{
		return Vec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Vec3 clamp( Vec3 const & x
		, Vec3 const & minVal
		, Vec3 const & maxVal )
	{
		return Vec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Vec4 clamp( Vec4 const & x
		, Vec4 const & minVal
		, Vec4 const & maxVal )
	{
		return Vec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Vec2 clamp( Vec2 const & x
		, Float const & minVal
		, Float const & maxVal )
	{
		return Vec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Vec3 clamp( Vec3 const & x
		, Float const & minVal
		, Float const & maxVal )
	{
		return Vec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Vec4 clamp( Vec4 const & x
		, Float const & minVal
		, Float const & maxVal )
	{
		return Vec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41F( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Double clamp( Double const & x
		, Double const & minVal
		, Double const & maxVal )
	{
		return Double{ findShader( x, minVal, maxVal )
			, expr::makeClamp11D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	DVec2 clamp( DVec2 const & x
		, DVec2 const & minVal
		, DVec2 const & maxVal )
	{
		return DVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	DVec3 clamp( DVec3 const & x
		, DVec3 const & minVal
		, DVec3 const & maxVal )
	{
		return DVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	DVec4 clamp( DVec4 const & x
		, DVec4 const & minVal
		, DVec4 const & maxVal )
	{
		return DVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	DVec2 clamp( DVec2 const & x
		, Double const & minVal
		, Double const & maxVal )
	{
		return DVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	DVec3 clamp( DVec3 const & x
		, Double const & minVal
		, Double const & maxVal )
	{
		return DVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	DVec4 clamp( DVec4 const & x
		, Double const & minVal
		, Double const & maxVal )
	{
		return DVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41D( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	Int clamp( Int const & x
		, Int const & minVal
		, Int const & maxVal )
	{
		return Int{ findShader( x, minVal, maxVal )
			, expr::makeClamp11I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	IVec2 clamp( IVec2 const & x
		, IVec2 const & minVal
		, IVec2 const & maxVal )
	{
		return IVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	IVec3 clamp( IVec3 const & x
		, IVec3 const & minVal
		, IVec3 const & maxVal )
	{
		return IVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	IVec4 clamp( IVec4 const & x
		, IVec4 const & minVal
		, IVec4 const & maxVal )
	{
		return IVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	IVec2 clamp( IVec2 const & x
		, Int const & minVal
		, Int const & maxVal )
	{
		return IVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	IVec3 clamp( IVec3 const & x
		, Int const & minVal
		, Int const & maxVal )
	{
		return IVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	IVec4 clamp( IVec4 const & x
		, Int const & minVal
		, Int const & maxVal )
	{
		return IVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41I( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UInt clamp( UInt const & x
		, UInt const & minVal
		, UInt const & maxVal )
	{
		return UInt{ findShader( x, minVal, maxVal )
			, expr::makeClamp11U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UVec2 clamp( UVec2 const & x
		, UVec2 const & minVal
		, UVec2 const & maxVal )
	{
		return UVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UVec3 clamp( UVec3 const & x
		, UVec3 const & minVal
		, UVec3 const & maxVal )
	{
		return UVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UVec4 clamp( UVec4 const & x
		, UVec4 const & minVal
		, UVec4 const & maxVal )
	{
		return UVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UVec2 clamp( UVec2 const & x
		, UInt const & minVal
		, UInt const & maxVal )
	{
		return UVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UVec3 clamp( UVec3 const & x
		, UInt const & minVal
		, UInt const & maxVal )
	{
		return UVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	UVec4 clamp( UVec4 const & x
		, UInt const & minVal
		, UInt const & maxVal )
	{
		return UVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41U( makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region mix
	/**
	*name
	*	mix
	*/
	/**@{*/
	Float mix( Float const & x
		, Float const & y
		, Float const & a )
	{
		return Float{ findShader( x, y, a )
			, expr::makeMix11F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec2 mix( Vec2 const & x
		, Vec2 const & y
		, Vec2 const & a )
	{
		return Vec2{ findShader( x, y, a )
			, expr::makeMix22F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec3 mix( Vec3 const & x
		, Vec3 const & y
		, Vec3 const & a )
	{
		return Vec3{ findShader( x, y, a )
			, expr::makeMix33F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec4 mix( Vec4 const & x
		, Vec4 const & y
		, Vec4 const & a )
	{
		return Vec4{ findShader( x, y, a )
			, expr::makeMix44F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec2 mix( Vec2 const & x
		, Vec2 const & y
		, Float const & a )
	{
		return Vec2{ findShader( x, y, a )
			, expr::makeMix21F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec3 mix( Vec3 const & x
		, Vec3 const & y
		, Float const & a )
	{
		return Vec3{ findShader( x, y, a )
			, expr::makeMix31F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec4 mix( Vec4 const & x
		, Vec4 const & y
		, Float const & a )
	{
		return Vec4{ findShader( x, y, a )
			, expr::makeMix41F( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Float mix( Float const & x
		, Float const & y
		, Boolean const & a )
	{
		return Float{ findShader( x, y, a )
			, expr::makeMix11FB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec2 mix( Vec2 const & x
		, Vec2 const & y
		, BVec2 const & a )
	{
		return Vec2{ findShader( x, y, a )
			, expr::makeMix22FB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec3 mix( Vec3 const & x
		, Vec3 const & y
		, BVec3 const & a )
	{
		return Vec3{ findShader( x, y, a )
			, expr::makeMix33FB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Vec4 mix( Vec4 const & x
		, Vec4 const & y
		, BVec4 const & a )
	{
		return Vec4{ findShader( x, y, a )
			, expr::makeMix44FB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Double mix( Double const & x
		, Double const & y
		, Double const & a )
	{
		return Double{ findShader( x, y, a )
			, expr::makeMix11D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec2 mix( DVec2 const & x
		, DVec2 const & y
		, DVec2 const & a )
	{
		return DVec2{ findShader( x, y, a )
			, expr::makeMix22D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec3 mix( DVec3 const & x
		, DVec3 const & y
		, DVec3 const & a )
	{
		return DVec3{ findShader( x, y, a )
			, expr::makeMix33D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec4 mix( DVec4 const & x
		, DVec4 const & y
		, DVec4 const & a )
	{
		return DVec4{ findShader( x, y, a )
			, expr::makeMix44D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec2 mix( DVec2 const & x
		, DVec2 const & y
		, Double const & a )
	{
		return DVec2{ findShader( x, y, a )
			, expr::makeMix21D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec3 mix( DVec3 const & x
		, DVec3 const & y
		, Double const & a )
	{
		return DVec3{ findShader( x, y, a )
			, expr::makeMix31D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec4 mix( DVec4 const & x
		, DVec4 const & y
		, Double const & a )
	{
		return DVec4{ findShader( x, y, a )
			, expr::makeMix41D( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	Double mix( Double const & x
		, Double const & y
		, Boolean const & a )
	{
		return Double{ findShader( x, y, a )
			, expr::makeMix11DB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec2 mix( DVec2 const & x
		, DVec2 const & y
		, BVec2 const & a )
	{
		return DVec2{ findShader( x, y, a )
			, expr::makeMix22DB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec3 mix( DVec3 const & x
		, DVec3 const & y
		, BVec3 const & a )
	{
		return DVec3{ findShader( x, y, a )
			, expr::makeMix33DB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	DVec4 mix( DVec4 const & x
		, DVec4 const & y
		, BVec4 const & a )
	{
		return DVec4{ findShader( x, y, a )
			, expr::makeMix44DB( makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region step
	/**
	*name
	*	step
	*/
	/**@{*/
	Float step( Float const & edge
		, Float const & x )
	{
		return Float{ findShader( edge, x )
			, expr::makeStep11F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Vec2 step( Vec2 const & edge
		, Vec2 const & x )
	{
		return Vec2{ findShader( edge, x )
			, expr::makeStep22F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Vec3 step( Vec3 const & edge
		, Vec3 const & x )
	{
		return Vec3{ findShader( edge, x )
			, expr::makeStep33F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Vec4 step( Vec4 const & edge
		, Vec4 const & x )
	{
		return Vec4{ findShader( edge, x )
			, expr::makeStep44F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Vec2 step( Float const & edge
		, Vec2 const & x )
	{
		return Vec2{ findShader( edge, x )
			, expr::makeStep12F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Vec3 step( Float const & edge
		, Vec3 const & x )
	{
		return Vec3{ findShader( edge, x )
			, expr::makeStep13F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Vec4 step( Float const & edge
		, Vec4 const & x )
	{
		return Vec4{ findShader( edge, x )
			, expr::makeStep14F( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	Double step( Double const & edge
		, Double const & x )
	{
		return Double{ findShader( edge, x )
			, expr::makeStep11D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	DVec2 step( DVec2 const & edge
		, DVec2 const & x )
	{
		return DVec2{ findShader( edge, x )
			, expr::makeStep22D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	DVec3 step( DVec3 const & edge
		, DVec3 const & x )
	{
		return DVec3{ findShader( edge, x )
			, expr::makeStep33D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	DVec4 step( DVec4 const & edge
		, DVec4 const & x )
	{
		return DVec4{ findShader( edge, x )
			, expr::makeStep44D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	DVec2 step( Double const & edge
		, DVec2 const & x )
	{
		return DVec2{ findShader( edge, x )
			, expr::makeStep12D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	DVec3 step( Double const & edge
		, DVec3 const & x )
	{
		return DVec3{ findShader( edge, x )
			, expr::makeStep13D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	DVec4 step( Double const & edge
		, DVec4 const & x )
	{
		return DVec4{ findShader( edge, x )
			, expr::makeStep14D( makeExpr( edge )
				, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region smoothStep
	/**
	*name
	*	smoothStep
	*/
	/**@{*/
	Float smoothStep( Float const & edge0
		, Float const & edge1
		, Float const & x )
	{
		return Float{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep11F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Vec2 smoothStep( Vec2 const & edge0
		, Vec2 const & edge1
		, Vec2 const & x )
	{
		return Vec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep22F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Vec3 smoothStep( Vec3 const & edge0
		, Vec3 const & edge1
		, Vec3 const & x )
	{
		return Vec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep33F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Vec4 smoothStep( Vec4 const & edge0
		, Vec4 const & edge1
		, Vec4 const & x )
	{
		return Vec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep44F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Vec2 smoothStep( Float const & edge0
		, Float const & edge1
		, Vec2 const & x )
	{
		return Vec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep12F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Vec3 smoothStep( Float const & edge0
		, Float const & edge1
		, Vec3 const & x )
	{
		return Vec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep13F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Vec4 smoothStep( Float const & edge0
		, Float const & edge1
		, Vec4 const & x )
	{
		return Vec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep14F( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	Double smoothStep( Double const & edge0
		, Double const & edge1
		, Double const & x )
	{
		return Double{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep11D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	DVec2 smoothStep( DVec2 const & edge0
		, DVec2 const & edge1
		, DVec2 const & x )
	{
		return DVec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep22D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	DVec3 smoothStep( DVec3 const & edge0
		, DVec3 const & edge1
		, DVec3 const & x )
	{
		return DVec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep33D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	DVec4 smoothStep( DVec4 const & edge0
		, DVec4 const & edge1
		, DVec4 const & x )
	{
		return DVec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep44D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	DVec2 smoothStep( Double const & edge0
		, Double const & edge1
		, DVec2 const & x )
	{
		return DVec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep12D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	DVec3 smoothStep( Double const & edge0
		, Double const & edge1
		, DVec3 const & x )
	{
		return DVec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep13D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	DVec4 smoothStep( Double const & edge0
		, Double const & edge1
		, DVec4 const & x )
	{
		return DVec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep14D( makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region isnan
	/**
	*name
	*	isnan
	*/
	/**@{*/
	Boolean isnan( Float const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeIsnan1F( makeExpr( x ) ) };
	}
	BVec2 isnan( Vec2 const & x )
	{
		return BVec2{ findShader( x )
			, expr::makeIsnan2F( makeExpr( x ) ) };
	}
	BVec3 isnan( Vec3 const & x )
	{
		return BVec3{ findShader( x )
			, expr::makeIsnan3F( makeExpr( x ) ) };
	}
	BVec4 isnan( Vec4 const & x )
	{
		return BVec4{ findShader( x )
			, expr::makeIsnan4F( makeExpr( x ) ) };
	}
	Boolean isnan( Double const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeIsnan1D( makeExpr( x ) ) };
	}
	BVec2 isnan( DVec2 const & x )
	{
		return BVec2{ findShader( x )
			, expr::makeIsnan2D( makeExpr( x ) ) };
	}
	BVec3 isnan( DVec3 const & x )
	{
		return BVec3{ findShader( x )
			, expr::makeIsnan3D( makeExpr( x ) ) };
	}
	BVec4 isnan( DVec4 const & x )
	{
		return BVec4{ findShader( x )
			, expr::makeIsnan4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	Boolean isinf( Float const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeIsinf1F( makeExpr( x ) ) };
	}
	BVec2 isinf( Vec2 const & x )
	{
		return BVec2{ findShader( x )
			, expr::makeIsinf2F( makeExpr( x ) ) };
	}
	BVec3 isinf( Vec3 const & x )
	{
		return BVec3{ findShader( x )
			, expr::makeIsinf3F( makeExpr( x ) ) };
	}
	BVec4 isinf( Vec4 const & x )
	{
		return BVec4{ findShader( x )
			, expr::makeIsinf4F( makeExpr( x ) ) };
	}
	Boolean isinf( Double const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeIsinf1D( makeExpr( x ) ) };
	}
	BVec2 isinf( DVec2 const & x )
	{
		return BVec2{ findShader( x )
			, expr::makeIsinf2D( makeExpr( x ) ) };
	}
	BVec3 isinf( DVec3 const & x )
	{
		return BVec3{ findShader( x )
			, expr::makeIsinf3D( makeExpr( x ) ) };
	}
	BVec4 isinf( DVec4 const & x )
	{
		return BVec4{ findShader( x )
			, expr::makeIsinf4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	Int floatBitsToInt( Float const & value )
	{
		return Int{ findShader( value )
			, expr::makeFloatBitsToInt1( makeExpr( value ) ) };
	}
	IVec2 floatBitsToInt( Vec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeFloatBitsToInt2( makeExpr( value ) ) };
	}
	IVec3 floatBitsToInt( Vec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeFloatBitsToInt3( makeExpr( value ) ) };
	}
	IVec4 floatBitsToInt( Vec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeFloatBitsToInt4( makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	UInt floatBitsToUInt( Float const & value )
	{
		return UInt{ findShader( value )
			, expr::makeFloatBitsToUInt1( makeExpr( value ) ) };
	}
	UVec2 floatBitsToUInt( Vec2 const & value )
	{
		return UVec2{ findShader( value )
			, expr::makeFloatBitsToUInt2( makeExpr( value ) ) };
	}
	UVec3 floatBitsToUInt( Vec3 const & value )
	{
		return UVec3{ findShader( value )
			, expr::makeFloatBitsToUInt3( makeExpr( value ) ) };
	}
	UVec4 floatBitsToUInt( Vec4 const & value )
	{
		return UVec4{ findShader( value )
			, expr::makeFloatBitsToUInt4( makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	Float intBitsToFloat( Int const & x )
	{
		return Float{ findShader( x )
			, expr::makeIntBitsToFloat1( makeExpr( x ) ) };
	}
	Vec2 intBitsToFloat( IVec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeIntBitsToFloat2( makeExpr( x ) ) };
	}
	Vec3 intBitsToFloat( IVec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeIntBitsToFloat3( makeExpr( x ) ) };
	}
	Vec4 intBitsToFloat( IVec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeIntBitsToFloat4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	Float uintBitsToFloat( UInt const & x )
	{
		return Float{ findShader( x )
			, expr::makeUintBitsToFloat1( makeExpr( x ) ) };
	}
	Vec2 uintBitsToFloat( UVec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeUintBitsToFloat2( makeExpr( x ) ) };
	}
	Vec3 uintBitsToFloat( UVec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeUintBitsToFloat3( makeExpr( x ) ) };
	}
	Vec4 uintBitsToFloat( UVec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeUintBitsToFloat4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	Float fma( Float const & a
		, Float const & b
		, Float const & c )
	{
		return Float{ findShader( a, b, c )
			, expr::makeFma1F( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	Vec2 fma( Vec2 const & a
		, Vec2 const & b
		, Vec2 const & c )
	{
		return Vec2{ findShader( a, b, c )
			, expr::makeFma2F( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	Vec3 fma( Vec3 const & a
		, Vec3 const & b
		, Vec3 const & c )
	{
		return Vec3{ findShader( a, b, c )
			, expr::makeFma3F( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	Vec4 fma( Vec4 const & a
		, Vec4 const & b
		, Vec4 const & c )
	{
		return Vec4{ findShader( a, b, c )
			, expr::makeFma4F( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	Double fma( Double const & a
		, Double const & b
		, Double const & c )
	{
		return Double{ findShader( a, b, c )
			, expr::makeFma1D( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	DVec2 fma( DVec2 const & a
		, DVec2 const & b
		, DVec2 const & c )
	{
		return DVec2{ findShader( a, b, c )
			, expr::makeFma2D( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	DVec3 fma( DVec3 const & a
		, DVec3 const & b
		, DVec3 const & c )
	{
		return DVec3{ findShader( a, b, c )
			, expr::makeFma3D( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	DVec4 fma( DVec4 const & a
		, DVec4 const & b
		, DVec4 const & c )
	{
		return DVec4{ findShader( a, b, c )
			, expr::makeFma4D( makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region frexp
	/**
	*name
	*	frexp
	*/
	/**@{*/
	Float frexp( Float const & x
		, Int const & exp )
	{
		return Float{ findShader( x, exp )
			, expr::makeFrexp1F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Vec2 frexp( Vec2 const & x
		, IVec2 const & exp )
	{
		return Vec2{ findShader( x, exp )
			, expr::makeFrexp2F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Vec3 frexp( Vec3 const & x
		, IVec3 const & exp )
	{
		return Vec3{ findShader( x, exp )
			, expr::makeFrexp3F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Vec4 frexp( Vec4 const & x
		, IVec4 const & exp )
	{
		return Vec4{ findShader( x, exp )
			, expr::makeFrexp4F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Double frexp( Double const & x
		, Int const & exp )
	{
		return Double{ findShader( x, exp )
			, expr::makeFrexp1D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	DVec2 frexp( DVec2 const & x
		, IVec2 const & exp )
	{
		return DVec2{ findShader( x, exp )
			, expr::makeFrexp2D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	DVec3 frexp( DVec3 const & x
		, IVec3 const & exp )
	{
		return DVec3{ findShader( x, exp )
			, expr::makeFrexp3D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	DVec4 frexp( DVec4 const & x
		, IVec4 const & exp )
	{
		return DVec4{ findShader( x, exp )
			, expr::makeFrexp4D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region ldexp
	/**
	*name
	*	ldexp
	*/
	/**@{*/
	Float ldexp( Float const & x
		, Int const & exp )
	{
		return Float{ findShader( x, exp )
			, expr::makeLdexp1F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Vec2 ldexp( Vec2 const & x
		, IVec2 const & exp )
	{
		return Vec2{ findShader( x, exp )
			, expr::makeLdexp2F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Vec3 ldexp( Vec3 const & x
		, IVec3 const & exp )
	{
		return Vec3{ findShader( x, exp )
			, expr::makeLdexp3F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Vec4 ldexp( Vec4 const & x
		, IVec4 const & exp )
	{
		return Vec4{ findShader( x, exp )
			, expr::makeLdexp4F( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	Double ldexp( Double const & x
		, Int const & exp )
	{
		return Double{ findShader( x, exp )
			, expr::makeLdexp1D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	DVec2 ldexp( DVec2 const & x
		, IVec2 const & exp )
	{
		return DVec2{ findShader( x, exp )
			, expr::makeLdexp2D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	DVec3 ldexp( DVec3 const & x
		, IVec3 const & exp )
	{
		return DVec3{ findShader( x, exp )
			, expr::makeLdexp3D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	DVec4 ldexp( DVec4 const & x
		, IVec4 const & exp )
	{
		return DVec4{ findShader( x, exp )
			, expr::makeLdexp4D( makeExpr( x )
				, makeExpr( exp ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packDouble2x32
	/**
	*name
	*	packDouble2x32
	*/
	/**@{*/
	Double packDouble2x32( UVec2 const & v )
	{
		return Double{ findShader( v )
			, expr::makePackDouble2x32( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	UInt packHalf2x16( Vec2 const & v )
	{
		return UInt{ findShader( v )
			, expr::makePackHalf2x16( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	UInt packSnorm2x16( Vec2 const & v )
	{
		return UInt{ findShader( v )
			, expr::makePackSnorm2x16( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	UInt packSnorm4x8( Vec4 const & v )
	{
		return UInt{ findShader( v )
			, expr::makePackSnorm4x8( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	UInt packUnorm2x16( Vec2 const & v )
	{
		return UInt{ findShader( v )
			, expr::makePackUnorm2x16( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	UInt packUnorm4x8( Vec4 const & v )
	{
		return UInt{ findShader( v )
			, expr::makePackUnorm4x8( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	UVec2 unpackDouble2x32( Double const & d )
	{
		return UVec2{ findShader( d )
			, expr::makeUnpackDouble2x32( makeExpr( d ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	Vec2 unpackHalf2x16( UInt const & v )
	{
		return Vec2{ findShader( v )
			, expr::makeUnpackHalf2x16( makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	Vec2 unpackSnorm2x16( UInt const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeUnpackSnorm2x16( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	Vec4 unpackSnorm4x8( UInt const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeUnpackSnorm4x8( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	Vec2 unpackUnorm2x16( UInt const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeUnpackUnorm2x16( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	Vec4 unpackUnorm4x8( UInt const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeUnpackUnorm4x8( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	Float length( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeLength1F( makeExpr( x ) ) };
	}
	Float length( Vec2 const & x )
	{
		return Float{ findShader( x )
			, expr::makeLength2F( makeExpr( x ) ) };
	}
	Float length( Vec3 const & x )
	{
		return Float{ findShader( x )
			, expr::makeLength3F( makeExpr( x ) ) };
	}
	Float length( Vec4 const & x )
	{
		return Float{ findShader( x )
			, expr::makeLength4F( makeExpr( x ) ) };
	}
	Double length( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeLength1D( makeExpr( x ) ) };
	}
	Double length( DVec2 const & x )
	{
		return Double{ findShader( x )
			, expr::makeLength2D( makeExpr( x ) ) };
	}
	Double length( DVec3 const & x )
	{
		return Double{ findShader( x )
			, expr::makeLength3D( makeExpr( x ) ) };
	}
	Double length( DVec4 const & x )
	{
		return Double{ findShader( x )
			, expr::makeLength4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	Float distance( Float const & p0
		, Float const & p1 )
	{
		return Float{ findShader( p0, p1 )
			, expr::makeDistance1F( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Vec2 distance( Vec2 const & p0
		, Vec2 const & p1 )
	{
		return Vec2{ findShader( p0, p1 )
			, expr::makeDistance2F( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Vec3 distance( Vec3 const & p0
		, Vec3 const & p1 )
	{
		return Vec3{ findShader( p0, p1 )
			, expr::makeDistance3F( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Vec4 distance( Vec4 const & p0
		, Vec4 const & p1 )
	{
		return Vec4{ findShader( p0, p1 )
			, expr::makeDistance4F( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Double distance( Double const & p0
		, Double const & p1 )
	{
		return Double{ findShader( p0, p1 )
			, expr::makeDistance1D( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Double distance( DVec2 const & p0
		, DVec2 const & p1 )
	{
		return Double{ findShader( p0, p1 )
			, expr::makeDistance2D( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Double distance( DVec3 const & p0
		, DVec3 const & p1 )
	{
		return Double{ findShader( p0, p1 )
			, expr::makeDistance3D( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	Double distance( DVec4 const & p0
		, DVec4 const & p1 )
	{
		return Double{ findShader( p0, p1 )
			, expr::makeDistance4D( makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dot
	/**
	*name
	*	dot
	*/
	/**@{*/
	Float dot( Float const & x
		, Float const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeDot1F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Float dot( Vec2 const & x
		, Vec2 const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeDot2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Float dot( Vec3 const & x
		, Vec3 const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeDot3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Float dot( Vec4 const & x
		, Vec4 const & y )
	{
		return Float{ findShader( x, y )
			, expr::makeDot4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double dot( Double const & x
		, Double const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeDot1D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double dot( DVec2 const & x
		, DVec2 const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeDot2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double dot( DVec3 const & x
		, DVec3 const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeDot3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Double dot( DVec4 const & x
		, DVec4 const & y )
	{
		return Double{ findShader( x, y )
			, expr::makeDot4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region cross
	/**
	*name
	*	cross
	*/
	/**@{*/
	Vec3 cross( Vec3 const & x
		, Vec3 const & y )
	{
		return Vec3{ findShader( x, y )
			, expr::makeCrossF( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DVec3 cross( DVec3 const & x
		, DVec3 const & y )
	{
		return DVec3{ findShader( x, y )
			, expr::makeCrossD( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region normalize
	/**
	*name
	*	normalize
	*/
	/**@{*/
	Float normalize( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeNormalize1F( makeExpr( x ) ) };
	}
	Vec2 normalize( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeNormalize2F( makeExpr( x ) ) };
	}
	Vec3 normalize( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeNormalize3F( makeExpr( x ) ) };
	}
	Vec4 normalize( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeNormalize4F( makeExpr( x ) ) };
	}
	Double normalize( Double const & x )
	{
		return Double{ findShader( x )
			, expr::makeNormalize1D( makeExpr( x ) ) };
	}
	DVec2 normalize( DVec2 const & x )
	{
		return DVec2{ findShader( x )
			, expr::makeNormalize2D( makeExpr( x ) ) };
	}
	DVec3 normalize( DVec3 const & x )
	{
		return DVec3{ findShader( x )
			, expr::makeNormalize3D( makeExpr( x ) ) };
	}
	DVec4 normalize( DVec4 const & x )
	{
		return DVec4{ findShader( x )
			, expr::makeNormalize4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	Float faceForward( Float const & N
		, Float const & I
		, Float const & Nref )
	{
		return Float{ findShader( N, I, Nref )
			, expr::makeFaceForward1F( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	Vec2 faceForward( Vec2 const & N
		, Vec2 const & I
		, Vec2 const & Nref )
	{
		return Vec2{ findShader( N, I, Nref )
			, expr::makeFaceForward2F( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	Vec3 faceForward( Vec3 const & N
		, Vec3 const & I
		, Vec3 const & Nref )
	{
		return Vec3{ findShader( N, I, Nref )
			, expr::makeFaceForward3F( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	Vec4 faceForward( Vec4 const & N
		, Vec4 const & I
		, Vec4 const & Nref )
	{
		return Vec4{ findShader( N, I, Nref )
			, expr::makeFaceForward4F( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	Double faceForward( Double const & N
		, Double const & I
		, Double const & Nref )
	{
		return Double{ findShader( N, I, Nref )
			, expr::makeFaceForward1D( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	DVec2 faceForward( DVec2 const & N
		, DVec2 const & I
		, DVec2 const & Nref )
	{
		return DVec2{ findShader( N, I, Nref )
			, expr::makeFaceForward2D( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	DVec3 faceForward( DVec3 const & N
		, DVec3 const & I
		, DVec3 const & Nref )
	{
		return DVec3{ findShader( N, I, Nref )
			, expr::makeFaceForward3D( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	DVec4 faceForward( DVec4 const & N
		, DVec4 const & I
		, DVec4 const & Nref )
	{
		return DVec4{ findShader( N, I, Nref )
			, expr::makeFaceForward4D( makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region reflect
	/**
	*name
	*	reflect
	*/
	/**@{*/
	Float reflect( Float const & I
		, Float const & N )
	{
		return Float{ findShader( I, N )
			, expr::makeReflect1F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Vec2 reflect( Vec2 const & I
		, Vec2 const & N )
	{
		return Vec2{ findShader( I, N )
			, expr::makeReflect2F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Vec3 reflect( Vec3 const & I
		, Vec3 const & N )
	{
		return Vec3{ findShader( I, N )
			, expr::makeReflect3F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Vec4 reflect( Vec4 const & I
		, Vec4 const & N )
	{
		return Vec4{ findShader( I, N )
			, expr::makeReflect4F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Double reflect( Float const & I
		, Double const & N )
	{
		return Double{ findShader( I, N )
			, expr::makeReflect1D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	DVec2 reflect( DVec2 const & I
		, DVec2 const & N )
	{
		return DVec2{ findShader( I, N )
			, expr::makeReflect2D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	DVec3 reflect( DVec3 const & I
		, DVec3 const & N )
	{
		return DVec3{ findShader( I, N )
			, expr::makeReflect3D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	DVec4 reflect( DVec4 const & I
		, DVec4 const & N )
	{
		return DVec4{ findShader( I, N )
			, expr::makeReflect4D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region refract
	/**
	*name
	*	refract
	*/
	/**@{*/
	Float refract( Float const & I
		, Float const & N )
	{
		return Float{ findShader( I, N )
			, expr::makeRefract1F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Vec2 refract( Vec2 const & I
		, Vec2 const & N )
	{
		return Vec2{ findShader( I, N )
			, expr::makeRefract2F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Vec3 refract( Vec3 const & I
		, Vec3 const & N )
	{
		return Vec3{ findShader( I, N )
			, expr::makeRefract3F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Vec4 refract( Vec4 const & I
		, Vec4 const & N )
	{
		return Vec4{ findShader( I, N )
			, expr::makeRefract4F( makeExpr( I )
				, makeExpr( N ) ) };
	}
	Double refract( Double const & I
		, Double const & N )
	{
		return Double{ findShader( I, N )
			, expr::makeRefract1D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	DVec2 refract( DVec2 const & I
		, DVec2 const & N )
	{
		return DVec2{ findShader( I, N )
			, expr::makeRefract2D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	DVec3 refract( DVec3 const & I
		, DVec3 const & N )
	{
		return DVec3{ findShader( I, N )
			, expr::makeRefract3D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	DVec4 refract( DVec4 const & I
		, DVec4 const & N )
	{
		return DVec4{ findShader( I, N )
			, expr::makeRefract4D( makeExpr( I )
				, makeExpr( N ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	Mat2 matrixCompMult( Mat2 const & x
		, Mat2 const & y )
	{
		return Mat2{ findShader( x, y )
			, expr::makeMatrixCompMult2x2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat2x3 matrixCompMult( Mat2x3 const & x
		, Mat2x3 const & y )
	{
		return Mat2x3{ findShader( x, y )
			, expr::makeMatrixCompMult2x3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat2x4 matrixCompMult( Mat2x4 const & x
		, Mat2x4 const & y )
	{
		return Mat2x4{ findShader( x, y )
			, expr::makeMatrixCompMult2x4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat3x2 matrixCompMult( Mat3x2 const & x
		, Mat3x2 const & y )
	{
		return Mat3x2{ findShader( x, y )
			, expr::makeMatrixCompMult3x2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat3 matrixCompMult( Mat3 const & x
		, Mat3 const & y )
	{
		return Mat3{ findShader( x, y )
			, expr::makeMatrixCompMult3x3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat3x4 matrixCompMult( Mat3x4 const & x
		, Mat3x4 const & y )
	{
		return Mat3x4{ findShader( x, y )
			, expr::makeMatrixCompMult3x4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat4x2 matrixCompMult( Mat4x2 const & x
		, Mat4x2 const & y )
	{
		return Mat4x2{ findShader( x, y )
			, expr::makeMatrixCompMult4x2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat4x3 matrixCompMult( Mat4x3 const & x
		, Mat4x3 const & y )
	{
		return Mat4x3{ findShader( x, y )
			, expr::makeMatrixCompMult4x3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	Mat4 matrixCompMult( Mat4 const & x
		, Mat4 const & y )
	{
		return Mat4{ findShader( x, y )
			, expr::makeMatrixCompMult4x4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat2 matrixCompMult( DMat2 const & x
		, DMat2 const & y )
	{
		return DMat2{ findShader( x, y )
			, expr::makeMatrixCompMult2x2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat2x3 matrixCompMult( DMat2x3 const & x
		, DMat2x3 const & y )
	{
		return DMat2x3{ findShader( x, y )
			, expr::makeMatrixCompMult2x3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat2x4 matrixCompMult( DMat2x4 const & x
		, DMat2x4 const & y )
	{
		return DMat2x4{ findShader( x, y )
			, expr::makeMatrixCompMult2x4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat3x2 matrixCompMult( DMat3x2 const & x
		, DMat3x2 const & y )
	{
		return DMat3x2{ findShader( x, y )
			, expr::makeMatrixCompMult3x2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat3 matrixCompMult( DMat3 const & x
		, DMat3 const & y )
	{
		return DMat3{ findShader( x, y )
			, expr::makeMatrixCompMult3x3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat3x4 matrixCompMult( DMat3x4 const & x
		, DMat3x4 const & y )
	{
		return DMat3x4{ findShader( x, y )
			, expr::makeMatrixCompMult3x4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat4x2 matrixCompMult( DMat4x2 const & x
		, DMat4x2 const & y )
	{
		return DMat4x2{ findShader( x, y )
			, expr::makeMatrixCompMult4x2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat4x3 matrixCompMult( DMat4x3 const & x
		, DMat4x3 const & y )
	{
		return DMat4x3{ findShader( x, y )
			, expr::makeMatrixCompMult4x3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	DMat4 matrixCompMult( DMat4 const & x
		, DMat4 const & y )
	{
		return DMat4{ findShader( x, y )
			, expr::makeMatrixCompMult4x4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region outerProduct
	/**
	*name
	*	outerProduct
	*/
	/**@{*/
	Mat2 outerProduct( Vec2 const & c
		, Vec2 const & r )
	{
		return Mat2{ findShader( c, r )
			, expr::makeOuterProduct2x2F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat3 outerProduct( Vec3 const & c
		, Vec3 const & r )
	{
		return Mat3{ findShader( c, r )
			, expr::makeOuterProduct3x3F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat4 outerProduct( Vec4 const & c
		, Vec4 const & r )
	{
		return Mat4{ findShader( c, r )
			, expr::makeOuterProduct4x4F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat2x3 outerProduct( Vec3 const & c
		, Vec2 const & r )
	{
		return Mat2x3{ findShader( c, r )
			, expr::makeOuterProduct3x2F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat3x2 outerProduct( Vec2 const & c
		, Vec3 const & r )
	{
		return Mat3x2{ findShader( c, r )
			, expr::makeOuterProduct2x3F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat2x4 outerProduct( Vec4 const & c
		, Vec2 const & r )
	{
		return Mat2x4{ findShader( c, r )
			, expr::makeOuterProduct4x2F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat4x2 outerProduct( Vec2 const & c
		, Vec4 const & r )
	{
		return Mat4x2{ findShader( c, r )
			, expr::makeOuterProduct2x4F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat3x4 outerProduct( Vec4 const & c
		, Vec3 const & r )
	{
		return Mat3x4{ findShader( c, r )
			, expr::makeOuterProduct4x3F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	Mat4x3 outerProduct( Vec3 const & c
		, Vec4 const & r )
	{
		return Mat4x3{ findShader( c, r )
			, expr::makeOuterProduct3x4F( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat2 outerProduct( DVec2 const & c
		, DVec2 const & r )
	{
		return DMat2{ findShader( c, r )
			, expr::makeOuterProduct2x2D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat3 outerProduct( DVec3 const & c
		, DVec3 const & r )
	{
		return DMat3{ findShader( c, r )
			, expr::makeOuterProduct3x3D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat4 outerProduct( DVec4 const & c
		, DVec4 const & r )
	{
		return DMat4{ findShader( c, r )
			, expr::makeOuterProduct4x4D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat2x3 outerProduct( DVec3 const & c
		, DVec2 const & r )
	{
		return DMat2x3{ findShader( c, r )
			, expr::makeOuterProduct3x2D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat3x2 outerProduct( DVec2 const & c
		, DVec3 const & r )
	{
		return DMat3x2{ findShader( c, r )
			, expr::makeOuterProduct2x3D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat2x4 outerProduct( DVec4 const & c
		, DVec2 const & r )
	{
		return DMat2x4{ findShader( c, r )
			, expr::makeOuterProduct4x2D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat4x2 outerProduct( DVec2 const & c
		, DVec4 const & r )
	{
		return DMat4x2{ findShader( c, r )
			, expr::makeOuterProduct2x4D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat3x4 outerProduct( DVec4 const & c
		, DVec3 const & r )
	{
		return DMat3x4{ findShader( c, r )
			, expr::makeOuterProduct4x3D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	DMat4x3 outerProduct( DVec3 const & c
		, DVec4 const & r )
	{
		return DMat4x3{ findShader( c, r )
			, expr::makeOuterProduct3x4D( makeExpr( c )
				, makeExpr( r ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region transpose
	/**
	*name
	*	transpose
	*/
	/**@{*/
	Mat2 transpose( Mat2 const & x )
	{
		return Mat2{ findShader( x )
			, expr::makeTranspose2x2F( makeExpr( x ) ) };
	}
	Mat3x2 transpose( Mat2x3 const & x )
	{
		return Mat3x2{ findShader( x )
			, expr::makeTranspose2x3F( makeExpr( x ) ) };
	}
	Mat4x2 transpose( Mat2x4 const & x )
	{
		return Mat4x2{ findShader( x )
			, expr::makeTranspose2x4F( makeExpr( x ) ) };
	}
	Mat2x3 transpose( Mat3x2 const & x )
	{
		return Mat2x3{ findShader( x )
			, expr::makeTranspose3x2F( makeExpr( x ) ) };
	}
	Mat3 transpose( Mat3 const & x )
	{
		return Mat3{ findShader( x )
			, expr::makeTranspose3x3F( makeExpr( x ) ) };
	}
	Mat4x3 transpose( Mat3x4 const & x )
	{
		return Mat4x3{ findShader( x )
			, expr::makeTranspose3x4F( makeExpr( x ) ) };
	}
	Mat2x4 transpose( Mat4x2 const & x )
	{
		return Mat2x4{ findShader( x )
			, expr::makeTranspose4x2F( makeExpr( x ) ) };
	}
	Mat3x4 transpose( Mat4x3 const & x )
	{
		return Mat3x4{ findShader( x )
			, expr::makeTranspose4x3F( makeExpr( x ) ) };
	}
	Mat4 transpose( Mat4 const & x )
	{
		return Mat4{ findShader( x )
			, expr::makeTranspose4x4F( makeExpr( x ) ) };
	}
	DMat2 transpose( DMat2 const & x )
	{
		return DMat2{ findShader( x )
			, expr::makeTranspose2x2D( makeExpr( x ) ) };
	}
	DMat3x2 transpose( DMat2x3 const & x )
	{
		return DMat3x2{ findShader( x )
			, expr::makeTranspose2x3D( makeExpr( x ) ) };
	}
	DMat4x2 transpose( DMat2x4 const & x )
	{
		return DMat4x2{ findShader( x )
			, expr::makeTranspose2x4D( makeExpr( x ) ) };
	}
	DMat2x3 transpose( DMat3x2 const & x )
	{
		return DMat2x3{ findShader( x )
			, expr::makeTranspose3x2D( makeExpr( x ) ) };
	}
	DMat3 transpose( DMat3 const & x )
	{
		return DMat3{ findShader( x )
			, expr::makeTranspose3x3D( makeExpr( x ) ) };
	}
	DMat4x3 transpose( DMat3x4 const & x )
	{
		return DMat4x3{ findShader( x )
			, expr::makeTranspose3x4D( makeExpr( x ) ) };
	}
	DMat2x4 transpose( DMat4x2 const & x )
	{
		return DMat2x4{ findShader( x )
			, expr::makeTranspose4x2D( makeExpr( x ) ) };
	}
	DMat3x4 transpose( DMat4x3 const & x )
	{
		return DMat3x4{ findShader( x )
			, expr::makeTranspose4x3D( makeExpr( x ) ) };
	}
	DMat4 transpose( DMat4 const & x )
	{
		return DMat4{ findShader( x )
			, expr::makeTranspose4x4D( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	Float determinant( Mat2 const & m )
	{
		return Float{ findShader( m )
			, expr::makeDeterminant2x2F( makeExpr( m ) ) };
	}
	Float determinant( Mat3 const & m )
	{
		return Float{ findShader( m )
			, expr::makeDeterminant3x3F( makeExpr( m ) ) };
	}
	Float determinant( Mat4 const & m )
	{
		return Float{ findShader( m )
			, expr::makeDeterminant4x4F( makeExpr( m ) ) };
	}
	Double determinant( DMat2 const & m )
	{
		return Double{ findShader( m )
			, expr::makeDeterminant2x2D( makeExpr( m ) ) };
	}
	Double determinant( DMat3 const & m )
	{
		return Double{ findShader( m )
			, expr::makeDeterminant3x3D( makeExpr( m ) ) };
	}
	Double determinant( DMat4 const & m )
	{
		return Double{ findShader( m )
			, expr::makeDeterminant4x4D( makeExpr( m ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	Mat2 inverse( Mat2 const & m )
	{
		return Mat2{ findShader( m )
			, expr::makeInverse2x2F( makeExpr( m ) ) };
	}
	Mat3 inverse( Mat3 const & m )
	{
		return Mat3{ findShader( m )
			, expr::makeInverse3x3F( makeExpr( m ) ) };
	}
	Mat4 inverse( Mat4 const & m )
	{
		return Mat4{ findShader( m )
			, expr::makeInverse4x4F( makeExpr( m ) ) };
	}
	DMat2 inverse( DMat2 const & m )
	{
		return DMat2{ findShader( m )
			, expr::makeInverse2x2D( makeExpr( m ) ) };
	}
	DMat3 inverse( DMat3 const & m )
	{
		return DMat3{ findShader( m )
			, expr::makeInverse3x3D( makeExpr( m ) ) };
	}
	DMat4 inverse( DMat4 const & m )
	{
		return DMat4{ findShader( m )
			, expr::makeInverse4x4D( makeExpr( m ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	BVec2 lessThan( Vec2 const & x
		, Vec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThan2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThan( Vec3 const & x
		, Vec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThan3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThan( Vec4 const & x
		, Vec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThan4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 lessThan( DVec2 const & x
		, DVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThan2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThan( DVec3 const & x
		, DVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThan3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThan( DVec4 const & x
		, DVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThan4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 lessThan( IVec2 const & x
		, IVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThan2I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThan( IVec3 const & x
		, IVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThan3I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThan( IVec4 const & x
		, IVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThan4I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 lessThan( UVec2 const & x
		, UVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThan2U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThan( UVec3 const & x
		, UVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThan3U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThan( UVec4 const & x
		, UVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThan4U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region lessThanEqual
	/**
	*name
	*	lessThanEqual
	*/
	/**@{*/
	BVec2 lessThanEqual( Vec2 const & x
		, Vec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThanEqual( Vec3 const & x
		, Vec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThanEqual( Vec4 const & x
		, Vec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 lessThanEqual( DVec2 const & x
		, DVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThanEqual( DVec3 const & x
		, DVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThanEqual( DVec4 const & x
		, DVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 lessThanEqual( IVec2 const & x
		, IVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThanEqual( IVec3 const & x
		, IVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThanEqual( IVec4 const & x
		, IVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 lessThanEqual( UVec2 const & x
		, UVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 lessThanEqual( UVec3 const & x
		, UVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 lessThanEqual( UVec4 const & x
		, UVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region greaterThan
	/**
	*name
	*	greaterThan
	*/
	/**@{*/
	BVec2 greaterThan( Vec2 const & x
		, Vec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThan( Vec3 const & x
		, Vec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThan( Vec4 const & x
		, Vec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 greaterThan( DVec2 const & x
		, DVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThan( DVec3 const & x
		, DVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThan( DVec4 const & x
		, DVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 greaterThan( IVec2 const & x
		, IVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThan( IVec3 const & x
		, IVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThan( IVec4 const & x
		, IVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 greaterThan( UVec2 const & x
		, UVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThan( UVec3 const & x
		, UVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThan( UVec4 const & x
		, UVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region greaterThanEqual
	/**
	*name
	*	greaterThanEqual
	*/
	/**@{*/
	BVec2 greaterThanEqual( Vec2 const & x
		, Vec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThanEqual( Vec3 const & x
		, Vec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThanEqual( Vec4 const & x
		, Vec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 greaterThanEqual( DVec2 const & x
		, DVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThanEqual( DVec3 const & x
		, DVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThanEqual( DVec4 const & x
		, DVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 greaterThanEqual( IVec2 const & x
		, IVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThanEqual( IVec3 const & x
		, IVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThanEqual( IVec4 const & x
		, IVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 greaterThanEqual( UVec2 const & x
		, UVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 greaterThanEqual( UVec3 const & x
		, UVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 greaterThanEqual( UVec4 const & x
		, UVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region equal
	/**
	*name
	*	equal
	*/
	/**@{*/
	BVec2 equal( Vec2 const & x
		, Vec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeEqual2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 equal( Vec3 const & x
		, Vec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeEqual3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 equal( Vec4 const & x
		, Vec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeEqual4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 equal( DVec2 const & x
		, DVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeEqual2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 equal( DVec3 const & x
		, DVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeEqual3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 equal( DVec4 const & x
		, DVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeEqual4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 equal( IVec2 const & x
		, IVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeEqual2I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 equal( IVec3 const & x
		, IVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeEqual3I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 equal( IVec4 const & x
		, IVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeEqual4I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 equal( UVec2 const & x
		, UVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeEqual2U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 equal( UVec3 const & x
		, UVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeEqual3U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 equal( UVec4 const & x
		, UVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeEqual4U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region notEqual
	/**
	*name
	*	notEqual
	*/
	/**@{*/
	BVec2 notEqual( Vec2 const & x
		, Vec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 notEqual( Vec3 const & x
		, Vec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 notEqual( Vec4 const & x
		, Vec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4F( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 notEqual( DVec2 const & x
		, DVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 notEqual( DVec3 const & x
		, DVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 notEqual( DVec4 const & x
		, DVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4D( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 notEqual( IVec2 const & x
		, IVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 notEqual( IVec3 const & x
		, IVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 notEqual( IVec4 const & x
		, IVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4I( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec2 notEqual( UVec2 const & x
		, UVec2 const & y )
	{
		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec3 notEqual( UVec3 const & x
		, UVec3 const & y )
	{
		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	BVec4 notEqual( UVec4 const & x
		, UVec4 const & y )
	{
		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4U( makeExpr( x )
				, makeExpr( y ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region all
	/**
	*name
	*	all
	*/
	/**@{*/
	Boolean all( BVec2 const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeAll2( makeExpr( x ) ) };
	}
	Boolean all( BVec3 const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeAll3( makeExpr( x ) ) };
	}
	Boolean all( BVec4 const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeAll4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	Boolean any( BVec2 const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeAny2( makeExpr( x ) ) };
	}
	Boolean any( BVec3 const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeAny3( makeExpr( x ) ) };
	}
	Boolean any( BVec4 const & x )
	{
		return Boolean{ findShader( x )
			, expr::makeAny4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region not
	/**
	*name
	*	not
	*/
	/**@{*/
	BVec2 not( BVec2 const & x )
	{
		return BVec2{ findShader( x )
			, expr::makeNot2( makeExpr( x ) ) };
	}
	BVec3 not( BVec3 const & x )
	{
		return BVec3{ findShader( x )
			, expr::makeNot3( makeExpr( x ) ) };
	}
	BVec4 not( BVec4 const & x )
	{
		return BVec4{ findShader( x )
			, expr::makeNot4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	UInt uaddCarry( UInt const & x
		, UInt const & y
		, UInt const & carry )
	{
		return UInt{ findShader( x, y, carry )
			, expr::makeUaddCarry1( makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	UVec2 uaddCarry( UVec2 const & x
		, UVec2 const & y
		, UVec2 const & carry )
	{
		return UVec2{ findShader( x, y, carry )
			, expr::makeUaddCarry2( makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	UVec3 uaddCarry( UVec3 const & x
		, UVec3 const & y
		, UVec3 const & carry )
	{
		return UVec3{ findShader( x, y, carry )
			, expr::makeUaddCarry3( makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	UVec4 uaddCarry( UVec4 const & x
		, UVec4 const & y
		, UVec4 const & carry )
	{
		return UVec4{ findShader( x, y, carry )
			, expr::makeUaddCarry4( makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region usubBorrow
	/**
	*name
	*	usubBorrow
	*/
	/**@{*/
	UInt usubBorrow( UInt const & x
		, UInt const & y
		, UInt const & borrow )
	{
		return UInt{ findShader( x, y, borrow )
			, expr::makeUsubBorrow1( makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	UVec2 usubBorrow( UVec2 const & x
		, UVec2 const & y
		, UVec2 const & borrow )
	{
		return UVec2{ findShader( x, y, borrow )
			, expr::makeUsubBorrow2( makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	UVec3 usubBorrow( UVec3 const & x
		, UVec3 const & y
		, UVec3 const & borrow )
	{
		return UVec3{ findShader( x, y, borrow )
			, expr::makeUsubBorrow3( makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	UVec4 usubBorrow( UVec4 const & x
		, UVec4 const & y
		, UVec4 const & borrow )
	{
		return UVec4{ findShader( x, y, borrow )
			, expr::makeUsubBorrow4( makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region umulExtended
	/**
	*name
	*	umulExtended
	*/
	/**@{*/
	Void umulExtended( UInt const & x
		, UInt const & y
		, UInt const & msb
		, UInt const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended1( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	Void umulExtended( UVec2 const & x
		, UVec2 const & y
		, UVec2 const & msb
		, UVec2 const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended2( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	Void umulExtended( UVec3 const & x
		, UVec3 const & y
		, UVec3 const & msb
		, UVec3 const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended3( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	Void umulExtended( UVec4 const & x
		, UVec4 const & y
		, UVec4 const & msb
		, UVec4 const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended4( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region imulExtended
	/**
	*name
	*	imulExtended
	*/
	/**@{*/
	Void imulExtended( Int const & x
		, Int const & y
		, Int const & msb
		, Int const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended1( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	Void imulExtended( IVec2 const & x
		, IVec2 const & y
		, IVec2 const & msb
		, IVec2 const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended2( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	Void imulExtended( IVec3 const & x
		, IVec3 const & y
		, IVec3 const & msb
		, IVec3 const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended3( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	Void imulExtended( IVec4 const & x
		, IVec4 const & y
		, IVec4 const & msb
		, IVec4 const & lsb )
	{
		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended4( makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitfieldExtract
	/**
	*name
	*	bitfieldExtract
	*/
	/**@{*/
	Int bitfieldExtract( Int const & value
		, Int const & offset
		, Int const & bits )
	{
		return Int{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract1I( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	IVec2 bitfieldExtract( IVec2 const & value
		, Int const & offset
		, Int const & bits )
	{
		return IVec2{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract2I( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	IVec3 bitfieldExtract( IVec3 const & value
		, Int const & offset
		, Int const & bits )
	{
		return IVec3{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract3I( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	IVec4 bitfieldExtract( IVec4 const & value
		, Int const & offset
		, Int const & bits )
	{
		return IVec4{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract4I( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UInt bitfieldExtract( UInt const & value
		, Int const & offset
		, Int const & bits )
	{
		return UInt{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract1U( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UVec2 bitfieldExtract( UVec2 const & value
		, Int const & offset
		, Int const & bits )
	{
		return UVec2{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract2U( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UVec3 bitfieldExtract( UVec3 const & value
		, Int const & offset
		, Int const & bits )
	{
		return UVec3{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract3U( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UVec4 bitfieldExtract( UVec4 const & value
		, Int const & offset
		, Int const & bits )
	{
		return UVec4{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract4U( makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitfieldInsert
	/**
	*name
	*	bitfieldInsert
	*/
	/**@{*/
	Int bitfieldInsert( Int const & base
		, Int const & insert
		, Int const & offset
		, Int const & bits )
	{
		return Int{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert1I( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	IVec2 bitfieldInsert( IVec2 const & base
		, IVec2 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return IVec2{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert2I( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	IVec3 bitfieldInsert( IVec3 const & base
		, IVec3 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return IVec3{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert3I( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	IVec4 bitfieldInsert( IVec4 const & base
		, IVec4 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return IVec4{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert4I( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UInt bitfieldInsert( UInt const & base
		, UInt const & insert
		, Int const & offset
		, Int const & bits )
	{
		return UInt{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert1U( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UVec2 bitfieldInsert( UVec2 const & base
		, UVec2 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return UVec2{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert2U( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UVec3 bitfieldInsert( UVec3 const & base
		, UVec3 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return UVec3{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert3U( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	UVec4 bitfieldInsert( UVec4 const & base
		, UVec4 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return UVec4{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert4U( makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitfieldReverse
	/**
	*name
	*	bitfieldReverse
	*/
	/**@{*/
	Int bitfieldReverse( Int const & value )
	{
		return Int{ findShader( value )
			, expr::makeBitfieldReverse1I( makeExpr( value ) ) };
	}
	IVec2 bitfieldReverse( IVec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeBitfieldReverse2I( makeExpr( value ) ) };
	}
	IVec3 bitfieldReverse( IVec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeBitfieldReverse3I( makeExpr( value ) ) };
	}
	IVec4 bitfieldReverse( IVec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeBitfieldReverse4I( makeExpr( value ) ) };
	}
	UInt bitfieldReverse( UInt const & value )
	{
		return UInt{ findShader( value )
			, expr::makeBitfieldReverse1U( makeExpr( value ) ) };
	}
	UVec2 bitfieldReverse( UVec2 const & value )
	{
		return UVec2{ findShader( value )
			, expr::makeBitfieldReverse2U( makeExpr( value ) ) };
	}
	UVec3 bitfieldReverse( UVec3 const & value )
	{
		return UVec3{ findShader( value )
			, expr::makeBitfieldReverse3U( makeExpr( value ) ) };
	}
	UVec4 bitfieldReverse( UVec4 const & value )
	{
		return UVec4{ findShader( value )
			, expr::makeBitfieldReverse4U( makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	Int bitCount( Int const & value )
	{
		return Int{ findShader( value )
			, expr::makeBitCount1I( makeExpr( value ) ) };
	}
	IVec2 bitCount( IVec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeBitCount2I( makeExpr( value ) ) };
	}
	IVec3 bitCount( IVec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeBitCount3I( makeExpr( value ) ) };
	}
	IVec4 bitCount( IVec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeBitCount4I( makeExpr( value ) ) };
	}
	UInt bitCount( UInt const & value )
	{
		return UInt{ findShader( value )
			, expr::makeBitCount1U( makeExpr( value ) ) };
	}
	UVec2 bitCount( UVec2 const & value )
	{
		return UVec2{ findShader( value )
			, expr::makeBitCount2U( makeExpr( value ) ) };
	}
	UVec3 bitCount( UVec3 const & value )
	{
		return UVec3{ findShader( value )
			, expr::makeBitCount3U( makeExpr( value ) ) };
	}
	UVec4 bitCount( UVec4 const & value )
	{
		return UVec4{ findShader( value )
			, expr::makeBitCount4U( makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	Int findLSB( Int const & value )
	{
		return Int{ findShader( value )
			, expr::makeFindLSB1I( makeExpr( value ) ) };
	}
	IVec2 findLSB( IVec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeFindLSB2I( makeExpr( value ) ) };
	}
	IVec3 findLSB( IVec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeFindLSB3I( makeExpr( value ) ) };
	}
	IVec4 findLSB( IVec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeFindLSB4I( makeExpr( value ) ) };
	}
	Int findLSB( UInt const & value )
	{
		return Int{ findShader( value )
			, expr::makeFindLSB1U( makeExpr( value ) ) };
	}
	IVec2 findLSB( UVec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeFindLSB2U( makeExpr( value ) ) };
	}
	IVec3 findLSB( UVec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeFindLSB3U( makeExpr( value ) ) };
	}
	IVec4 findLSB( UVec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeFindLSB4U( makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	Int findMSB( Int const & value )
	{
		return Int{ findShader( value )
			, expr::makeFindMSB1I( makeExpr( value ) ) };
	}
	IVec2 findMSB( IVec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeFindMSB2I( makeExpr( value ) ) };
	}
	IVec3 findMSB( IVec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeFindMSB3I( makeExpr( value ) ) };
	}
	IVec4 findMSB( IVec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeFindMSB4I( makeExpr( value ) ) };
	}
	Int findMSB( UInt const & value )
	{
		return Int{ findShader( value )
			, expr::makeFindMSB1U( makeExpr( value ) ) };
	}
	IVec2 findMSB( UVec2 const & value )
	{
		return IVec2{ findShader( value )
			, expr::makeFindMSB2U( makeExpr( value ) ) };
	}
	IVec3 findMSB( UVec3 const & value )
	{
		return IVec3{ findShader( value )
			, expr::makeFindMSB3U( makeExpr( value ) ) };
	}
	IVec4 findMSB( UVec4 const & value )
	{
		return IVec4{ findShader( value )
			, expr::makeFindMSB4U( makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	Int atomicAdd( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicAddI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicAdd( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicAddU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicMin
	/**
	*name
	*	atomicMin
	*/
	/**@{*/
	Int atomicMin( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicMinI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicMin( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicMinU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicMax
	/**
	*name
	*	atomicMax
	*/
	/**@{*/
	Int atomicMax( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicMaxI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicMax( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicMaxU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicAnd
	/**
	*name
	*	atomicAnd
	*/
	/**@{*/
	Int atomicAnd( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicAndI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicAnd( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicAndU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicOr
	/**
	*name
	*	atomicOr
	*/
	/**@{*/
	Int atomicOr( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicOrI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicOr( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicOrU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicXor
	/**
	*name
	*	atomicXor
	*/
	/**@{*/
	Int atomicXor( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicXorI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicXor( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicXorU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicExchange
	/**
	*name
	*	atomicExchange
	*/
	/**@{*/
	Int atomicExchange( Int const & mem
		, Int const & data )
	{
		return Int{ findShader( mem, data )
			, expr::makeAtomicExchangeI( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	UInt atomicExchange( UInt const & mem
		, UInt const & data )
	{
		return UInt{ findShader( mem, data )
			, expr::makeAtomicExchangeU( makeExpr( mem )
				, makeExpr( data ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicCompSwap
	/**
	*name
	*	atomicCompSwap
	*/
	/**@{*/
	Int atomicCompSwap( Int const & mem
		, UInt const & compare )
	{
		return Int{ findShader( mem, compare )
			, expr::makeAtomicCompSwapI( makeExpr( mem )
				, makeExpr( compare ) ) };
	}
	UInt atomicCompSwap( UInt const & mem
		, UInt const & compare )
	{
		return UInt{ findShader( mem, compare )
			, expr::makeAtomicCompSwapU( makeExpr( mem )
				, makeExpr( compare ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdx
	/**
	*name
	*	dFdx
	*/
	/**@{*/
	Float dFdx( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeDFdx1( makeExpr( p ) ) };
	}
	Vec2 dFdx( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeDFdx2( makeExpr( p ) ) };
	}
	Vec3 dFdx( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeDFdx3( makeExpr( p ) ) };
	}
	Vec4 dFdx( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeDFdx4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	Float dFdxCoarse( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeDFdxCoarse1( makeExpr( p ) ) };
	}
	Vec2 dFdxCoarse( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeDFdxCoarse2( makeExpr( p ) ) };
	}
	Vec3 dFdxCoarse( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeDFdxCoarse3( makeExpr( p ) ) };
	}
	Vec4 dFdxCoarse( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeDFdxCoarse4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	Float dFdxFine( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeDFdxFine1( makeExpr( p ) ) };
	}
	Vec2 dFdxFine( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeDFdxFine2( makeExpr( p ) ) };
	}
	Vec3 dFdxFine( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeDFdxFine3( makeExpr( p ) ) };
	}
	Vec4 dFdxFine( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeDFdxFine4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	Float dFdy( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeDFdy1( makeExpr( p ) ) };
	}
	Vec2 dFdy( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeDFdy2( makeExpr( p ) ) };
	}
	Vec3 dFdy( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeDFdy3( makeExpr( p ) ) };
	}
	Vec4 dFdy( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeDFdy4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	Float dFdyCoarse( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeDFdyCoarse1( makeExpr( p ) ) };
	}
	Vec2 dFdyCoarse( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeDFdyCoarse2( makeExpr( p ) ) };
	}
	Vec3 dFdyCoarse( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeDFdyCoarse3( makeExpr( p ) ) };
	}
	Vec4 dFdyCoarse( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeDFdyCoarse4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	Float dFdyFine( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeDFdyFine1( makeExpr( p ) ) };
	}
	Vec2 dFdyFine( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeDFdyFine2( makeExpr( p ) ) };
	}
	Vec3 dFdyFine( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeDFdyFine3( makeExpr( p ) ) };
	}
	Vec4 dFdyFine( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeDFdyFine4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	Float fwidth( Float const & p )
	{
		return Float{ findShader( p )
			, expr::makeFwidth1( makeExpr( p ) ) };
	}
	Vec2 fwidth( Vec2 const & p )
	{
		return Vec2{ findShader( p )
			, expr::makeFwidth2( makeExpr( p ) ) };
	}
	Vec3 fwidth( Vec3 const & p )
	{
		return Vec3{ findShader( p )
			, expr::makeFwidth3( makeExpr( p ) ) };
	}
	Vec4 fwidth( Vec4 const & p )
	{
		return Vec4{ findShader( p )
			, expr::makeFwidth4( makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	Float interpolateAtCentroid( Float const & x )
	{
		return Float{ findShader( x )
			, expr::makeInterpolateAtCentroid1( makeExpr( x ) ) };
	}
	Vec2 interpolateAtCentroid( Vec2 const & x )
	{
		return Vec2{ findShader( x )
			, expr::makeInterpolateAtCentroid2( makeExpr( x ) ) };
	}
	Vec3 interpolateAtCentroid( Vec3 const & x )
	{
		return Vec3{ findShader( x )
			, expr::makeInterpolateAtCentroid3( makeExpr( x ) ) };
	}
	Vec4 interpolateAtCentroid( Vec4 const & x )
	{
		return Vec4{ findShader( x )
			, expr::makeInterpolateAtCentroid4( makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	Float interpolateAtSample( Float const & interpolant
		, Int const & sample )
	{
		return Float{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample1( makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	Vec2 interpolateAtSample( Vec2 const & interpolant
		, Int const & sample )
	{
		return Vec2{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample2( makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	Vec3 interpolateAtSample( Vec3 const & interpolant
		, Int const & sample )
	{
		return Vec3{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample3( makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	Vec4 interpolateAtSample( Vec4 const & interpolant
		, Int const & sample )
	{
		return Vec4{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample4( makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtOffset
	/**
	*name
	*	interpolateAtOffset
	*/
	/**@{*/
	Float interpolateAtOffset( Float const & interpolant
		, Vec2 const & offset )
	{
		return Float{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset1( makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	Vec2 interpolateAtOffset( Vec2 const & interpolant
		, Vec2 const & offset )
	{
		return Vec2{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset2( makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	Vec3 interpolateAtOffset( Vec3 const & interpolant
		, Vec2 const & offset )
	{
		return Vec3{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset3( makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	Vec4 interpolateAtOffset( Vec4 const & interpolant
		, Vec2 const & offset )
	{
		return Vec4{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset4( makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region EmitStreamVertex
	/**
	*name
	*	EmitStreamVertex
	*/
	/**@{*/
	Void EmitStreamVertex( Int const & stream )
	{
		return Void{ findShader( stream )
			, expr::makeEmitStreamVertex( makeExpr( stream ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	Void EndStreamPrimitive( Int const & stream )
	{
		return Void{ findShader( stream )
			, expr::makeEndStreamPrimitive( makeExpr( stream ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	Void EmitVertex( )
	{
		return Void{ findShader( )
			, expr::makeEmitVertex( ) };
	}
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	Void EndPrimitive( )
	{
		return Void{ findShader( )
			, expr::makeEndPrimitive( ) };
	}
	/**@}*/
#pragma endregion
#pragma region barrier
	/**
	*name
	*	barrier
	*/
	/**@{*/
	Void barrier( )
	{
		return Void{ findShader( )
			, expr::makeBarrier( ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	UInt memoryBarrier( )
	{
		return UInt{ findShader( )
			, expr::makeMemoryBarrier( ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierBuffer
	/**
	*name
	*	memoryBarrierBuffer
	*/
	/**@{*/
	Void memoryBarrierBuffer( )
	{
		return Void{ findShader( )
			, expr::makeMemoryBarrierBuffer( ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierShared
	/**
	*name
	*	memoryBarrierShared
	*/
	/**@{*/
	Void memoryBarrierShared( )
	{
		return Void{ findShader( )
			, expr::makeMemoryBarrierShared( ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierImage
	/**
	*name
	*	memoryBarrierImage
	*/
	/**@{*/
	Void memoryBarrierImage( )
	{
		return Void{ findShader( )
			, expr::makeMemoryBarrierImage( ) };
	}
	/**@}*/
#pragma endregion
#pragma region groupMemoryBarrier
	/**
	*name
	*	groupMemoryBarrier
	*/
	/**@{*/
	Void groupMemoryBarrier( )
	{
		return Void{ findShader( )
			, expr::makeGroupMemoryBarrier( ) };
	}
	/**@}*/
#pragma endregion
}
