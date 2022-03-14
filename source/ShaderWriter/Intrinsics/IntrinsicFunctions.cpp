/*
See LICENSE file in root folder
*/
/*
This file is generated, don't modify it!
*/
#include "ShaderWriter/BaseTypes/AccelerationStructure.hpp"
#include "ShaderWriter/BaseTypes/Void.hpp"
#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Bool.hpp"
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
	ReturnWrapperT< Float > degrees( Float const & radians )
	{
		return ReturnWrapperT< Float >{ *findWriter( radians )
			, expr::makeDegrees1( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	ReturnWrapperT< Vec2 > degrees( Vec2 const & radians )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( radians )
			, expr::makeDegrees2( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	ReturnWrapperT< Vec3 > degrees( Vec3 const & radians )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( radians )
			, expr::makeDegrees3( findTypesCache( radians )
					, makeExpr( radians ) )
			, areOptionalEnabled( radians ) };
	}
	ReturnWrapperT< Vec4 > degrees( Vec4 const & radians )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( radians )
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
	ReturnWrapperT< Float > radians( Float const & degrees )
	{
		return ReturnWrapperT< Float >{ *findWriter( degrees )
			, expr::makeRadians1F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	ReturnWrapperT< Vec2 > radians( Vec2 const & degrees )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( degrees )
			, expr::makeRadians2F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	ReturnWrapperT< Vec3 > radians( Vec3 const & degrees )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( degrees )
			, expr::makeRadians3F( findTypesCache( degrees )
					, makeExpr( degrees ) )
			, areOptionalEnabled( degrees ) };
	}
	ReturnWrapperT< Vec4 > radians( Vec4 const & degrees )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( degrees )
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
	ReturnWrapperT< Float > cos( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeCos1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > cos( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeCos2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > cos( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeCos3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > cos( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > sin( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeSin1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > sin( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeSin2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > sin( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeSin3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > sin( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > tan( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeTan1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > tan( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeTan2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > tan( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeTan3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > tan( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > cosh( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeCosh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > cosh( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeCosh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > cosh( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeCosh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > cosh( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > sinh( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeSinh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > sinh( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeSinh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > sinh( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeSinh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > sinh( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > tanh( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeTanh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > tanh( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeTanh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > tanh( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeTanh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > tanh( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > acos( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeAcos1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > acos( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeAcos2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > acos( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeAcos3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > acos( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > asin( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeAsin1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > asin( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeAsin2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > asin( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeAsin3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > asin( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > atan( Float const & y_over_x )
	{
		return ReturnWrapperT< Float >{ *findWriter( y_over_x )
			, expr::makeAtan1( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	ReturnWrapperT< Vec2 > atan( Vec2 const & y_over_x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( y_over_x )
			, expr::makeAtan2( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	ReturnWrapperT< Vec3 > atan( Vec3 const & y_over_x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( y_over_x )
			, expr::makeAtan3( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
			, areOptionalEnabled( y_over_x ) };
	}
	ReturnWrapperT< Vec4 > atan( Vec4 const & y_over_x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( y_over_x )
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
	ReturnWrapperT< Float > atan2( Float const & y
		, Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( y, x )
			, expr::makeAtan21( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	ReturnWrapperT< Vec2 > atan2( Vec2 const & y
		, Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( y, x )
			, expr::makeAtan22( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	ReturnWrapperT< Vec3 > atan2( Vec3 const & y
		, Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( y, x )
			, expr::makeAtan23( findTypesCache( y, x )
					, makeExpr( y )
				, makeExpr( x ) )
			, areOptionalEnabled( y, x ) };
	}
	ReturnWrapperT< Vec4 > atan2( Vec4 const & y
		, Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( y, x )
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
	ReturnWrapperT< Float > acosh( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeAcosh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > acosh( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeAcosh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > acosh( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeAcosh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > acosh( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > asinh( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeAsinh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > asinh( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeAsinh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > asinh( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeAsinh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > asinh( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > atanh( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeAtanh1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > atanh( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeAtanh2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > atanh( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeAtanh3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > atanh( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > pow( Float const & x
		, Float const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makePow1( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec2 > pow( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, y )
			, expr::makePow2( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec3 > pow( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, y )
			, expr::makePow3( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec4 > pow( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< Float > exp( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeExp1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > exp( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeExp2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > exp( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeExp3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > exp( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > log( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeLog1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > log( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeLog2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > log( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeLog3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > log( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > exp2( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeExp21( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > exp2( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeExp22( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > exp2( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeExp23( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > exp2( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > log2( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeLog21( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > log2( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeLog22( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > log2( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeLog23( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > log2( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > sqrt( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeSqrt1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > sqrt( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeSqrt2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > sqrt( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeSqrt3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > sqrt( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeSqrt4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > sqrt( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeSqrt1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > sqrt( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeSqrt2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > sqrt( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeSqrt3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > sqrt( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > inverseSqrt( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeInverseSqrt1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > inverseSqrt( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeInverseSqrt2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > inverseSqrt( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeInverseSqrt3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > inverseSqrt( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeInverseSqrt4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > inverseSqrt( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeInverseSqrt1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > inverseSqrt( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeInverseSqrt2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > inverseSqrt( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeInverseSqrt3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > inverseSqrt( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > abs( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeAbs1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > abs( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeAbs2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > abs( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeAbs3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > abs( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeAbs4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Int > abs( Int const & x )
	{
		return ReturnWrapperT< Int >{ *findWriter( x )
			, expr::makeAbs1I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< IVec2 > abs( IVec2 const & x )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( x )
			, expr::makeAbs2I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< IVec3 > abs( IVec3 const & x )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( x )
			, expr::makeAbs3I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< IVec4 > abs( IVec4 const & x )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( x )
			, expr::makeAbs4I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > abs( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeAbs1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > abs( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeAbs2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > abs( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeAbs3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > abs( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > sign( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeSign1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > sign( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeSign2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > sign( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeSign3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > sign( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeSign4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Int > sign( Int const & x )
	{
		return ReturnWrapperT< Int >{ *findWriter( x )
			, expr::makeSign1I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< IVec2 > sign( IVec2 const & x )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( x )
			, expr::makeSign2I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< IVec3 > sign( IVec3 const & x )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( x )
			, expr::makeSign3I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< IVec4 > sign( IVec4 const & x )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( x )
			, expr::makeSign4I( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > sign( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeSign1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > sign( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeSign2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > sign( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeSign3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > sign( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > floor( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeFloor1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > floor( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeFloor2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > floor( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeFloor3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > floor( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeFloor4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > floor( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeFloor1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > floor( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeFloor2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > floor( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeFloor3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > floor( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > trunc( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeTrunc1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > trunc( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeTrunc2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > trunc( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeTrunc3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > trunc( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeTrunc4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > trunc( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeTrunc1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > trunc( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeTrunc2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > trunc( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeTrunc3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > trunc( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > round( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeRound1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > round( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeRound2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > round( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeRound3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > round( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeRound4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > round( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeRound1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > round( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeRound2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > round( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeRound3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > round( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > roundEven( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeRoundEven1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > roundEven( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeRoundEven2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > roundEven( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeRoundEven3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > roundEven( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeRoundEven4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > roundEven( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeRoundEven1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > roundEven( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeRoundEven2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > roundEven( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeRoundEven3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > roundEven( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > ceil( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeCeil1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > ceil( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeCeil2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > ceil( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeCeil3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > ceil( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeCeil4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > ceil( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeCeil1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > ceil( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeCeil2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > ceil( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeCeil3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > ceil( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > fract( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeFract1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > fract( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeFract2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > fract( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeFract3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > fract( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeFract4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > fract( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeFract1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > fract( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeFract2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > fract( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeFract3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > fract( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > mod( Float const & x
		, Float const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeMod1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec2 > mod( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, y )
			, expr::makeMod2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec3 > mod( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, y )
			, expr::makeMod3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec4 > mod( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, y )
			, expr::makeMod4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > mod( Double const & x
		, Double const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
			, expr::makeMod1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec2 > mod( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, y )
			, expr::makeMod2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec3 > mod( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, y )
			, expr::makeMod3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec4 > mod( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< Float > modf( Float const & x
		, Float const & i )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, i )
			, expr::makeModf1F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< Vec2 > modf( Vec2 const & x
		, Vec2 const & i )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, i )
			, expr::makeModf2F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< Vec3 > modf( Vec3 const & x
		, Vec3 const & i )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, i )
			, expr::makeModf3F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< Vec4 > modf( Vec4 const & x
		, Vec4 const & i )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, i )
			, expr::makeModf4F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< Double > modf( Double const & x
		, Double const & i )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, i )
			, expr::makeModf1D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< DVec2 > modf( DVec2 const & x
		, DVec2 const & i )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, i )
			, expr::makeModf2D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< DVec3 > modf( DVec3 const & x
		, DVec3 const & i )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, i )
			, expr::makeModf3D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) )
			, areOptionalEnabled( x, i ) };
	}
	ReturnWrapperT< DVec4 > modf( DVec4 const & x
		, DVec4 const & i )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, i )
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
	ReturnWrapperT< Float > min( Float const & x
		, Float const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeMin1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec2 > min( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, y )
			, expr::makeMin2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec3 > min( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, y )
			, expr::makeMin3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec4 > min( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, y )
			, expr::makeMin4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > min( Double const & x
		, Double const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
			, expr::makeMin1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec2 > min( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, y )
			, expr::makeMin2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec3 > min( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, y )
			, expr::makeMin3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec4 > min( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, y )
			, expr::makeMin4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Int > min( Int const & x
		, Int const & y )
	{
		return ReturnWrapperT< Int >{ *findWriter( x, y )
			, expr::makeMin1I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< IVec2 > min( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( x, y )
			, expr::makeMin2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< IVec3 > min( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( x, y )
			, expr::makeMin3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< IVec4 > min( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( x, y )
			, expr::makeMin4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UInt > min( UInt const & x
		, UInt const & y )
	{
		return ReturnWrapperT< UInt >{ *findWriter( x, y )
			, expr::makeMin1U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UVec2 > min( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( x, y )
			, expr::makeMin2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UVec3 > min( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( x, y )
			, expr::makeMin3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UVec4 > min( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< Float > max( Float const & x
		, Float const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeMax1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec2 > max( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, y )
			, expr::makeMax2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec3 > max( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, y )
			, expr::makeMax3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Vec4 > max( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, y )
			, expr::makeMax4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > max( Double const & x
		, Double const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
			, expr::makeMax1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec2 > max( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, y )
			, expr::makeMax2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec3 > max( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, y )
			, expr::makeMax3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec4 > max( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, y )
			, expr::makeMax4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Int > max( Int const & x
		, Int const & y )
	{
		return ReturnWrapperT< Int >{ *findWriter( x, y )
			, expr::makeMax1I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< IVec2 > max( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( x, y )
			, expr::makeMax2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< IVec3 > max( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( x, y )
			, expr::makeMax3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< IVec4 > max( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( x, y )
			, expr::makeMax4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UInt > max( UInt const & x
		, UInt const & y )
	{
		return ReturnWrapperT< UInt >{ *findWriter( x, y )
			, expr::makeMax1U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UVec2 > max( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( x, y )
			, expr::makeMax2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UVec3 > max( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( x, y )
			, expr::makeMax3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< UVec4 > max( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< Float > clamp( Float const & x
		, Float const & minVal
		, Float const & maxVal )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< Vec2 > clamp( Vec2 const & x
		, Vec2 const & minVal
		, Vec2 const & maxVal )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< Vec3 > clamp( Vec3 const & x
		, Vec3 const & minVal
		, Vec3 const & maxVal )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< Vec4 > clamp( Vec4 const & x
		, Vec4 const & minVal
		, Vec4 const & maxVal )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< Double > clamp( Double const & x
		, Double const & minVal
		, Double const & maxVal )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< DVec2 > clamp( DVec2 const & x
		, DVec2 const & minVal
		, DVec2 const & maxVal )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< DVec3 > clamp( DVec3 const & x
		, DVec3 const & minVal
		, DVec3 const & maxVal )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< DVec4 > clamp( DVec4 const & x
		, DVec4 const & minVal
		, DVec4 const & maxVal )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< Int > clamp( Int const & x
		, Int const & minVal
		, Int const & maxVal )
	{
		return ReturnWrapperT< Int >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< IVec2 > clamp( IVec2 const & x
		, IVec2 const & minVal
		, IVec2 const & maxVal )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< IVec3 > clamp( IVec3 const & x
		, IVec3 const & minVal
		, IVec3 const & maxVal )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< IVec4 > clamp( IVec4 const & x
		, IVec4 const & minVal
		, IVec4 const & maxVal )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp4I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< UInt > clamp( UInt const & x
		, UInt const & minVal
		, UInt const & maxVal )
	{
		return ReturnWrapperT< UInt >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp1U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< UVec2 > clamp( UVec2 const & x
		, UVec2 const & minVal
		, UVec2 const & maxVal )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp2U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< UVec3 > clamp( UVec3 const & x
		, UVec3 const & minVal
		, UVec3 const & maxVal )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( x, minVal, maxVal )
			, expr::makeClamp3U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) )
			, areOptionalEnabled( x, minVal, maxVal ) };
	}
	ReturnWrapperT< UVec4 > clamp( UVec4 const & x
		, UVec4 const & minVal
		, UVec4 const & maxVal )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( x, minVal, maxVal )
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
	ReturnWrapperT< Float > mix( Float const & x
		, Float const & y
		, Float const & a )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y, a )
			, expr::makeMix1F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< Vec2 > mix( Vec2 const & x
		, Vec2 const & y
		, Vec2 const & a )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, y, a )
			, expr::makeMix2F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< Vec3 > mix( Vec3 const & x
		, Vec3 const & y
		, Vec3 const & a )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, y, a )
			, expr::makeMix3F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< Vec4 > mix( Vec4 const & x
		, Vec4 const & y
		, Vec4 const & a )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, y, a )
			, expr::makeMix4F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< Double > mix( Double const & x
		, Double const & y
		, Double const & a )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y, a )
			, expr::makeMix1D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< DVec2 > mix( DVec2 const & x
		, DVec2 const & y
		, DVec2 const & a )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, y, a )
			, expr::makeMix2D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< DVec3 > mix( DVec3 const & x
		, DVec3 const & y
		, DVec3 const & a )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, y, a )
			, expr::makeMix3D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) )
			, areOptionalEnabled( x, y, a ) };
	}
	ReturnWrapperT< DVec4 > mix( DVec4 const & x
		, DVec4 const & y
		, DVec4 const & a )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, y, a )
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
	ReturnWrapperT< Float > step( Float const & edge
		, Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( edge, x )
			, expr::makeStep1F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< Vec2 > step( Vec2 const & edge
		, Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( edge, x )
			, expr::makeStep2F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< Vec3 > step( Vec3 const & edge
		, Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( edge, x )
			, expr::makeStep3F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< Vec4 > step( Vec4 const & edge
		, Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( edge, x )
			, expr::makeStep4F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< Double > step( Double const & edge
		, Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( edge, x )
			, expr::makeStep1D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< DVec2 > step( DVec2 const & edge
		, DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( edge, x )
			, expr::makeStep2D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< DVec3 > step( DVec3 const & edge
		, DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( edge, x )
			, expr::makeStep3D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) )
			, areOptionalEnabled( edge, x ) };
	}
	ReturnWrapperT< DVec4 > step( DVec4 const & edge
		, DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( edge, x )
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
	ReturnWrapperT< Float > smoothStep( Float const & edge0
		, Float const & edge1
		, Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep1F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< Vec2 > smoothStep( Vec2 const & edge0
		, Vec2 const & edge1
		, Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep2F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< Vec3 > smoothStep( Vec3 const & edge0
		, Vec3 const & edge1
		, Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep3F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< Vec4 > smoothStep( Vec4 const & edge0
		, Vec4 const & edge1
		, Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep4F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< Double > smoothStep( Double const & edge0
		, Double const & edge1
		, Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep1D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< DVec2 > smoothStep( DVec2 const & edge0
		, DVec2 const & edge1
		, DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep2D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< DVec3 > smoothStep( DVec3 const & edge0
		, DVec3 const & edge1
		, DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( edge0, edge1, x )
			, expr::makeSmoothStep3D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) )
			, areOptionalEnabled( edge0, edge1, x ) };
	}
	ReturnWrapperT< DVec4 > smoothStep( DVec4 const & edge0
		, DVec4 const & edge1
		, DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( edge0, edge1, x )
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
	ReturnWrapperT< Boolean > isnan( Float const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeIsnan1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec2 > isnan( Vec2 const & x )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x )
			, expr::makeIsnan2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec3 > isnan( Vec3 const & x )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x )
			, expr::makeIsnan3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec4 > isnan( Vec4 const & x )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x )
			, expr::makeIsnan4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Boolean > isnan( Double const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeIsnan1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec2 > isnan( DVec2 const & x )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x )
			, expr::makeIsnan2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec3 > isnan( DVec3 const & x )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x )
			, expr::makeIsnan3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec4 > isnan( DVec4 const & x )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Boolean > isinf( Float const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeIsinf1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec2 > isinf( Vec2 const & x )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x )
			, expr::makeIsinf2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec3 > isinf( Vec3 const & x )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x )
			, expr::makeIsinf3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec4 > isinf( Vec4 const & x )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x )
			, expr::makeIsinf4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Boolean > isinf( Double const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeIsinf1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec2 > isinf( DVec2 const & x )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x )
			, expr::makeIsinf2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec3 > isinf( DVec3 const & x )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x )
			, expr::makeIsinf3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec4 > isinf( DVec4 const & x )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Int > floatBitsToInt( Float const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeFloatBitsToInt1( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > floatBitsToInt( Vec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeFloatBitsToInt2( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > floatBitsToInt( Vec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeFloatBitsToInt3( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > floatBitsToInt( Vec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
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
	ReturnWrapperT< UInt > floatBitsToUInt( Float const & value )
	{
		return ReturnWrapperT< UInt >{ *findWriter( value )
			, expr::makeFloatBitsToUInt1( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec2 > floatBitsToUInt( Vec2 const & value )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( value )
			, expr::makeFloatBitsToUInt2( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec3 > floatBitsToUInt( Vec3 const & value )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( value )
			, expr::makeFloatBitsToUInt3( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec4 > floatBitsToUInt( Vec4 const & value )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( value )
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
	ReturnWrapperT< Float > intBitsToFloat( Int const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeIntBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > intBitsToFloat( IVec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeIntBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > intBitsToFloat( IVec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeIntBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > intBitsToFloat( IVec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > uintBitsToFloat( UInt const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeUintBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > uintBitsToFloat( UVec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeUintBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > uintBitsToFloat( UVec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeUintBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > uintBitsToFloat( UVec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > fma( Float const & a
		, Float const & b
		, Float const & c )
	{
		return ReturnWrapperT< Float >{ *findWriter( a, b, c )
			, expr::makeFma1F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< Vec2 > fma( Vec2 const & a
		, Vec2 const & b
		, Vec2 const & c )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( a, b, c )
			, expr::makeFma2F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< Vec3 > fma( Vec3 const & a
		, Vec3 const & b
		, Vec3 const & c )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( a, b, c )
			, expr::makeFma3F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< Vec4 > fma( Vec4 const & a
		, Vec4 const & b
		, Vec4 const & c )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( a, b, c )
			, expr::makeFma4F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< Double > fma( Double const & a
		, Double const & b
		, Double const & c )
	{
		return ReturnWrapperT< Double >{ *findWriter( a, b, c )
			, expr::makeFma1D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< DVec2 > fma( DVec2 const & a
		, DVec2 const & b
		, DVec2 const & c )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( a, b, c )
			, expr::makeFma2D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< DVec3 > fma( DVec3 const & a
		, DVec3 const & b
		, DVec3 const & c )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( a, b, c )
			, expr::makeFma3D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) )
			, areOptionalEnabled( a, b, c ) };
	}
	ReturnWrapperT< DVec4 > fma( DVec4 const & a
		, DVec4 const & b
		, DVec4 const & c )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( a, b, c )
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
	ReturnWrapperT< Float > frexp( Float const & x
		, Int & exp )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, exp )
			, expr::makeFrexp1F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Vec2 > frexp( Vec2 const & x
		, IVec2 & exp )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, exp )
			, expr::makeFrexp2F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Vec3 > frexp( Vec3 const & x
		, IVec3 & exp )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, exp )
			, expr::makeFrexp3F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Vec4 > frexp( Vec4 const & x
		, IVec4 & exp )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, exp )
			, expr::makeFrexp4F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Double > frexp( Double const & x
		, Int & exp )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, exp )
			, expr::makeFrexp1D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< DVec2 > frexp( DVec2 const & x
		, IVec2 & exp )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, exp )
			, expr::makeFrexp2D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< DVec3 > frexp( DVec3 const & x
		, IVec3 & exp )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, exp )
			, expr::makeFrexp3D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< DVec4 > frexp( DVec4 const & x
		, IVec4 & exp )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, exp )
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
	ReturnWrapperT< Float > ldexp( Float const & x
		, Int const & exp )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, exp )
			, expr::makeLdexp1F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Vec2 > ldexp( Vec2 const & x
		, IVec2 const & exp )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x, exp )
			, expr::makeLdexp2F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Vec3 > ldexp( Vec3 const & x
		, IVec3 const & exp )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, exp )
			, expr::makeLdexp3F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Vec4 > ldexp( Vec4 const & x
		, IVec4 const & exp )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x, exp )
			, expr::makeLdexp4F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< Double > ldexp( Double const & x
		, Int const & exp )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, exp )
			, expr::makeLdexp1D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< DVec2 > ldexp( DVec2 const & x
		, IVec2 const & exp )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x, exp )
			, expr::makeLdexp2D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< DVec3 > ldexp( DVec3 const & x
		, IVec3 const & exp )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, exp )
			, expr::makeLdexp3D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) )
			, areOptionalEnabled( x, exp ) };
	}
	ReturnWrapperT< DVec4 > ldexp( DVec4 const & x
		, IVec4 const & exp )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x, exp )
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
	ReturnWrapperT< Double > packDouble2x32( UVec2 const & v )
	{
		return ReturnWrapperT< Double >{ *findWriter( v )
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
	ReturnWrapperT< UInt > packHalf2x16( Vec2 const & v )
	{
		return ReturnWrapperT< UInt >{ *findWriter( v )
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
	ReturnWrapperT< UInt > packSnorm2x16( Vec2 const & v )
	{
		return ReturnWrapperT< UInt >{ *findWriter( v )
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
	ReturnWrapperT< UInt > packSnorm4x8( Vec4 const & v )
	{
		return ReturnWrapperT< UInt >{ *findWriter( v )
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
	ReturnWrapperT< UInt > packUnorm2x16( Vec2 const & v )
	{
		return ReturnWrapperT< UInt >{ *findWriter( v )
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
	ReturnWrapperT< UInt > packUnorm4x8( Vec4 const & v )
	{
		return ReturnWrapperT< UInt >{ *findWriter( v )
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
	ReturnWrapperT< UVec2 > unpackDouble2x32( Double const & d )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( d )
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
	ReturnWrapperT< Vec2 > unpackHalf2x16( UInt const & v )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( v )
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
	ReturnWrapperT< Vec2 > unpackSnorm2x16( UInt const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
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
	ReturnWrapperT< Vec4 > unpackSnorm4x8( UInt const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Vec2 > unpackUnorm2x16( UInt const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
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
	ReturnWrapperT< Vec4 > unpackUnorm4x8( UInt const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > length( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeLength1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Float > length( Vec2 const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeLength2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Float > length( Vec3 const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeLength3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Float > length( Vec4 const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeLength4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > length( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeLength1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > length( DVec2 const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeLength2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > length( DVec3 const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeLength3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > length( DVec4 const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
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
	ReturnWrapperT< Float > distance( Float const & p0
		, Float const & p1 )
	{
		return ReturnWrapperT< Float >{ *findWriter( p0, p1 )
			, expr::makeDistance1F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Float > distance( Vec2 const & p0
		, Vec2 const & p1 )
	{
		return ReturnWrapperT< Float >{ *findWriter( p0, p1 )
			, expr::makeDistance2F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Float > distance( Vec3 const & p0
		, Vec3 const & p1 )
	{
		return ReturnWrapperT< Float >{ *findWriter( p0, p1 )
			, expr::makeDistance3F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Float > distance( Vec4 const & p0
		, Vec4 const & p1 )
	{
		return ReturnWrapperT< Float >{ *findWriter( p0, p1 )
			, expr::makeDistance4F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Double > distance( Double const & p0
		, Double const & p1 )
	{
		return ReturnWrapperT< Double >{ *findWriter( p0, p1 )
			, expr::makeDistance1D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Double > distance( DVec2 const & p0
		, DVec2 const & p1 )
	{
		return ReturnWrapperT< Double >{ *findWriter( p0, p1 )
			, expr::makeDistance2D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Double > distance( DVec3 const & p0
		, DVec3 const & p1 )
	{
		return ReturnWrapperT< Double >{ *findWriter( p0, p1 )
			, expr::makeDistance3D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) )
			, areOptionalEnabled( p0, p1 ) };
	}
	ReturnWrapperT< Double > distance( DVec4 const & p0
		, DVec4 const & p1 )
	{
		return ReturnWrapperT< Double >{ *findWriter( p0, p1 )
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
	ReturnWrapperT< Float > dot( Float const & x
		, Float const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeDot1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Float > dot( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeDot2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Float > dot( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeDot3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Float > dot( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< Float >{ *findWriter( x, y )
			, expr::makeDot4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > dot( Double const & x
		, Double const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
			, expr::makeDot1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > dot( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
			, expr::makeDot2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > dot( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
			, expr::makeDot3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Double > dot( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< Double >{ *findWriter( x, y )
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
	ReturnWrapperT< Vec3 > cross( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x, y )
			, expr::makeCrossF( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DVec3 > cross( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x, y )
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
	ReturnWrapperT< Float > normalize( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeNormalize1F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > normalize( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeNormalize2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > normalize( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeNormalize3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > normalize( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
			, expr::makeNormalize4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Double > normalize( Double const & x )
	{
		return ReturnWrapperT< Double >{ *findWriter( x )
			, expr::makeNormalize1D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec2 > normalize( DVec2 const & x )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( x )
			, expr::makeNormalize2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec3 > normalize( DVec3 const & x )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( x )
			, expr::makeNormalize3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DVec4 > normalize( DVec4 const & x )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > faceForward( Float const & N
		, Float const & I
		, Float const & Nref )
	{
		return ReturnWrapperT< Float >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward1F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< Vec2 > faceForward( Vec2 const & N
		, Vec2 const & I
		, Vec2 const & Nref )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward2F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< Vec3 > faceForward( Vec3 const & N
		, Vec3 const & I
		, Vec3 const & Nref )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward3F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< Vec4 > faceForward( Vec4 const & N
		, Vec4 const & I
		, Vec4 const & Nref )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward4F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< Double > faceForward( Double const & N
		, Double const & I
		, Double const & Nref )
	{
		return ReturnWrapperT< Double >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward1D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< DVec2 > faceForward( DVec2 const & N
		, DVec2 const & I
		, DVec2 const & Nref )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward2D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< DVec3 > faceForward( DVec3 const & N
		, DVec3 const & I
		, DVec3 const & Nref )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( N, I, Nref )
			, expr::makeFaceForward3D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) )
			, areOptionalEnabled( N, I, Nref ) };
	}
	ReturnWrapperT< DVec4 > faceForward( DVec4 const & N
		, DVec4 const & I
		, DVec4 const & Nref )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( N, I, Nref )
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
	ReturnWrapperT< Float > reflect( Float const & I
		, Float const & N )
	{
		return ReturnWrapperT< Float >{ *findWriter( I, N )
			, expr::makeReflect1F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< Vec2 > reflect( Vec2 const & I
		, Vec2 const & N )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( I, N )
			, expr::makeReflect2F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< Vec3 > reflect( Vec3 const & I
		, Vec3 const & N )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( I, N )
			, expr::makeReflect3F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< Vec4 > reflect( Vec4 const & I
		, Vec4 const & N )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( I, N )
			, expr::makeReflect4F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< Double > reflect( Double const & I
		, Double const & N )
	{
		return ReturnWrapperT< Double >{ *findWriter( I, N )
			, expr::makeReflect1D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< DVec2 > reflect( DVec2 const & I
		, DVec2 const & N )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( I, N )
			, expr::makeReflect2D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< DVec3 > reflect( DVec3 const & I
		, DVec3 const & N )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( I, N )
			, expr::makeReflect3D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) )
			, areOptionalEnabled( I, N ) };
	}
	ReturnWrapperT< DVec4 > reflect( DVec4 const & I
		, DVec4 const & N )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( I, N )
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
	ReturnWrapperT< Float > refract( Float const & I
		, Float const & N
		, Float const & eta )
	{
		return ReturnWrapperT< Float >{ *findWriter( I, N, eta )
			, expr::makeRefract1F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< Vec2 > refract( Vec2 const & I
		, Vec2 const & N
		, Float const & eta )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( I, N, eta )
			, expr::makeRefract2F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< Vec3 > refract( Vec3 const & I
		, Vec3 const & N
		, Float const & eta )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( I, N, eta )
			, expr::makeRefract3F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< Vec4 > refract( Vec4 const & I
		, Vec4 const & N
		, Float const & eta )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( I, N, eta )
			, expr::makeRefract4F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< Double > refract( Double const & I
		, Double const & N
		, Float const & eta )
	{
		return ReturnWrapperT< Double >{ *findWriter( I, N, eta )
			, expr::makeRefract1D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< DVec2 > refract( DVec2 const & I
		, DVec2 const & N
		, Float const & eta )
	{
		return ReturnWrapperT< DVec2 >{ *findWriter( I, N, eta )
			, expr::makeRefract2D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< DVec3 > refract( DVec3 const & I
		, DVec3 const & N
		, Float const & eta )
	{
		return ReturnWrapperT< DVec3 >{ *findWriter( I, N, eta )
			, expr::makeRefract3D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) )
			, areOptionalEnabled( I, N, eta ) };
	}
	ReturnWrapperT< DVec4 > refract( DVec4 const & I
		, DVec4 const & N
		, Float const & eta )
	{
		return ReturnWrapperT< DVec4 >{ *findWriter( I, N, eta )
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
	ReturnWrapperT< Mat2 > matrixCompMult( Mat2 const & x
		, Mat2 const & y )
	{
		return ReturnWrapperT< Mat2 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat2x3 > matrixCompMult( Mat2x3 const & x
		, Mat2x3 const & y )
	{
		return ReturnWrapperT< Mat2x3 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat2x4 > matrixCompMult( Mat2x4 const & x
		, Mat2x4 const & y )
	{
		return ReturnWrapperT< Mat2x4 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat3x2 > matrixCompMult( Mat3x2 const & x
		, Mat3x2 const & y )
	{
		return ReturnWrapperT< Mat3x2 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat3 > matrixCompMult( Mat3 const & x
		, Mat3 const & y )
	{
		return ReturnWrapperT< Mat3 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat3x4 > matrixCompMult( Mat3x4 const & x
		, Mat3x4 const & y )
	{
		return ReturnWrapperT< Mat3x4 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat4x2 > matrixCompMult( Mat4x2 const & x
		, Mat4x2 const & y )
	{
		return ReturnWrapperT< Mat4x2 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat4x3 > matrixCompMult( Mat4x3 const & x
		, Mat4x3 const & y )
	{
		return ReturnWrapperT< Mat4x3 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< Mat4 > matrixCompMult( Mat4 const & x
		, Mat4 const & y )
	{
		return ReturnWrapperT< Mat4 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat2 > matrixCompMult( DMat2 const & x
		, DMat2 const & y )
	{
		return ReturnWrapperT< DMat2 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat2x3 > matrixCompMult( DMat2x3 const & x
		, DMat2x3 const & y )
	{
		return ReturnWrapperT< DMat2x3 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat2x4 > matrixCompMult( DMat2x4 const & x
		, DMat2x4 const & y )
	{
		return ReturnWrapperT< DMat2x4 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult2x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat3x2 > matrixCompMult( DMat3x2 const & x
		, DMat3x2 const & y )
	{
		return ReturnWrapperT< DMat3x2 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat3 > matrixCompMult( DMat3 const & x
		, DMat3 const & y )
	{
		return ReturnWrapperT< DMat3 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat3x4 > matrixCompMult( DMat3x4 const & x
		, DMat3x4 const & y )
	{
		return ReturnWrapperT< DMat3x4 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult3x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat4x2 > matrixCompMult( DMat4x2 const & x
		, DMat4x2 const & y )
	{
		return ReturnWrapperT< DMat4x2 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat4x3 > matrixCompMult( DMat4x3 const & x
		, DMat4x3 const & y )
	{
		return ReturnWrapperT< DMat4x3 >{ *findWriter( x, y )
			, expr::makeMatrixCompMult4x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< DMat4 > matrixCompMult( DMat4 const & x
		, DMat4 const & y )
	{
		return ReturnWrapperT< DMat4 >{ *findWriter( x, y )
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
	ReturnWrapperT< Mat2 > outerProduct( Vec2 const & c
		, Vec2 const & r )
	{
		return ReturnWrapperT< Mat2 >{ *findWriter( c, r )
			, expr::makeOuterProduct2x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat3 > outerProduct( Vec3 const & c
		, Vec3 const & r )
	{
		return ReturnWrapperT< Mat3 >{ *findWriter( c, r )
			, expr::makeOuterProduct3x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat4 > outerProduct( Vec4 const & c
		, Vec4 const & r )
	{
		return ReturnWrapperT< Mat4 >{ *findWriter( c, r )
			, expr::makeOuterProduct4x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat2x3 > outerProduct( Vec3 const & c
		, Vec2 const & r )
	{
		return ReturnWrapperT< Mat2x3 >{ *findWriter( c, r )
			, expr::makeOuterProduct3x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat3x2 > outerProduct( Vec2 const & c
		, Vec3 const & r )
	{
		return ReturnWrapperT< Mat3x2 >{ *findWriter( c, r )
			, expr::makeOuterProduct2x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat2x4 > outerProduct( Vec4 const & c
		, Vec2 const & r )
	{
		return ReturnWrapperT< Mat2x4 >{ *findWriter( c, r )
			, expr::makeOuterProduct4x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat4x2 > outerProduct( Vec2 const & c
		, Vec4 const & r )
	{
		return ReturnWrapperT< Mat4x2 >{ *findWriter( c, r )
			, expr::makeOuterProduct2x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat3x4 > outerProduct( Vec4 const & c
		, Vec3 const & r )
	{
		return ReturnWrapperT< Mat3x4 >{ *findWriter( c, r )
			, expr::makeOuterProduct4x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< Mat4x3 > outerProduct( Vec3 const & c
		, Vec4 const & r )
	{
		return ReturnWrapperT< Mat4x3 >{ *findWriter( c, r )
			, expr::makeOuterProduct3x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat2 > outerProduct( DVec2 const & c
		, DVec2 const & r )
	{
		return ReturnWrapperT< DMat2 >{ *findWriter( c, r )
			, expr::makeOuterProduct2x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat3 > outerProduct( DVec3 const & c
		, DVec3 const & r )
	{
		return ReturnWrapperT< DMat3 >{ *findWriter( c, r )
			, expr::makeOuterProduct3x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat4 > outerProduct( DVec4 const & c
		, DVec4 const & r )
	{
		return ReturnWrapperT< DMat4 >{ *findWriter( c, r )
			, expr::makeOuterProduct4x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat2x3 > outerProduct( DVec3 const & c
		, DVec2 const & r )
	{
		return ReturnWrapperT< DMat2x3 >{ *findWriter( c, r )
			, expr::makeOuterProduct3x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat3x2 > outerProduct( DVec2 const & c
		, DVec3 const & r )
	{
		return ReturnWrapperT< DMat3x2 >{ *findWriter( c, r )
			, expr::makeOuterProduct2x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat2x4 > outerProduct( DVec4 const & c
		, DVec2 const & r )
	{
		return ReturnWrapperT< DMat2x4 >{ *findWriter( c, r )
			, expr::makeOuterProduct4x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat4x2 > outerProduct( DVec2 const & c
		, DVec4 const & r )
	{
		return ReturnWrapperT< DMat4x2 >{ *findWriter( c, r )
			, expr::makeOuterProduct2x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat3x4 > outerProduct( DVec4 const & c
		, DVec3 const & r )
	{
		return ReturnWrapperT< DMat3x4 >{ *findWriter( c, r )
			, expr::makeOuterProduct4x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) )
			, areOptionalEnabled( c, r ) };
	}
	ReturnWrapperT< DMat4x3 > outerProduct( DVec3 const & c
		, DVec4 const & r )
	{
		return ReturnWrapperT< DMat4x3 >{ *findWriter( c, r )
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
	ReturnWrapperT< Mat2 > transpose( Mat2 const & x )
	{
		return ReturnWrapperT< Mat2 >{ *findWriter( x )
			, expr::makeTranspose2x2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat3x2 > transpose( Mat2x3 const & x )
	{
		return ReturnWrapperT< Mat3x2 >{ *findWriter( x )
			, expr::makeTranspose2x3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat4x2 > transpose( Mat2x4 const & x )
	{
		return ReturnWrapperT< Mat4x2 >{ *findWriter( x )
			, expr::makeTranspose2x4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat2x3 > transpose( Mat3x2 const & x )
	{
		return ReturnWrapperT< Mat2x3 >{ *findWriter( x )
			, expr::makeTranspose3x2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat3 > transpose( Mat3 const & x )
	{
		return ReturnWrapperT< Mat3 >{ *findWriter( x )
			, expr::makeTranspose3x3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat4x3 > transpose( Mat3x4 const & x )
	{
		return ReturnWrapperT< Mat4x3 >{ *findWriter( x )
			, expr::makeTranspose3x4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat2x4 > transpose( Mat4x2 const & x )
	{
		return ReturnWrapperT< Mat2x4 >{ *findWriter( x )
			, expr::makeTranspose4x2F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat3x4 > transpose( Mat4x3 const & x )
	{
		return ReturnWrapperT< Mat3x4 >{ *findWriter( x )
			, expr::makeTranspose4x3F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Mat4 > transpose( Mat4 const & x )
	{
		return ReturnWrapperT< Mat4 >{ *findWriter( x )
			, expr::makeTranspose4x4F( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat2 > transpose( DMat2 const & x )
	{
		return ReturnWrapperT< DMat2 >{ *findWriter( x )
			, expr::makeTranspose2x2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat3x2 > transpose( DMat2x3 const & x )
	{
		return ReturnWrapperT< DMat3x2 >{ *findWriter( x )
			, expr::makeTranspose2x3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat4x2 > transpose( DMat2x4 const & x )
	{
		return ReturnWrapperT< DMat4x2 >{ *findWriter( x )
			, expr::makeTranspose2x4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat2x3 > transpose( DMat3x2 const & x )
	{
		return ReturnWrapperT< DMat2x3 >{ *findWriter( x )
			, expr::makeTranspose3x2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat3 > transpose( DMat3 const & x )
	{
		return ReturnWrapperT< DMat3 >{ *findWriter( x )
			, expr::makeTranspose3x3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat4x3 > transpose( DMat3x4 const & x )
	{
		return ReturnWrapperT< DMat4x3 >{ *findWriter( x )
			, expr::makeTranspose3x4D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat2x4 > transpose( DMat4x2 const & x )
	{
		return ReturnWrapperT< DMat2x4 >{ *findWriter( x )
			, expr::makeTranspose4x2D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat3x4 > transpose( DMat4x3 const & x )
	{
		return ReturnWrapperT< DMat3x4 >{ *findWriter( x )
			, expr::makeTranspose4x3D( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< DMat4 > transpose( DMat4 const & x )
	{
		return ReturnWrapperT< DMat4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > determinant( Mat2 const & m )
	{
		return ReturnWrapperT< Float >{ *findWriter( m )
			, expr::makeDeterminant2x2F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Float > determinant( Mat3 const & m )
	{
		return ReturnWrapperT< Float >{ *findWriter( m )
			, expr::makeDeterminant3x3F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Float > determinant( Mat4 const & m )
	{
		return ReturnWrapperT< Float >{ *findWriter( m )
			, expr::makeDeterminant4x4F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Double > determinant( DMat2 const & m )
	{
		return ReturnWrapperT< Double >{ *findWriter( m )
			, expr::makeDeterminant2x2D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Double > determinant( DMat3 const & m )
	{
		return ReturnWrapperT< Double >{ *findWriter( m )
			, expr::makeDeterminant3x3D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Double > determinant( DMat4 const & m )
	{
		return ReturnWrapperT< Double >{ *findWriter( m )
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
	ReturnWrapperT< Mat2 > inverse( Mat2 const & m )
	{
		return ReturnWrapperT< Mat2 >{ *findWriter( m )
			, expr::makeInverse2x2F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Mat3 > inverse( Mat3 const & m )
	{
		return ReturnWrapperT< Mat3 >{ *findWriter( m )
			, expr::makeInverse3x3F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< Mat4 > inverse( Mat4 const & m )
	{
		return ReturnWrapperT< Mat4 >{ *findWriter( m )
			, expr::makeInverse4x4F( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< DMat2 > inverse( DMat2 const & m )
	{
		return ReturnWrapperT< DMat2 >{ *findWriter( m )
			, expr::makeInverse2x2D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< DMat3 > inverse( DMat3 const & m )
	{
		return ReturnWrapperT< DMat3 >{ *findWriter( m )
			, expr::makeInverse3x3D( findTypesCache( m )
					, makeExpr( m ) )
			, areOptionalEnabled( m ) };
	}
	ReturnWrapperT< DMat4 > inverse( DMat4 const & m )
	{
		return ReturnWrapperT< DMat4 >{ *findWriter( m )
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
	ReturnWrapperT< BVec2 > lessThan( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThan2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThan( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThan3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThan( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeLessThan4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > lessThan( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThan2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThan( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThan3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThan( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeLessThan4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > lessThan( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThan2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThan( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThan3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThan( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeLessThan4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > lessThan( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThan2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThan( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThan3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThan( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< BVec2 > lessThanEqual( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThanEqual( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThanEqual( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeLessThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > lessThanEqual( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThanEqual( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThanEqual( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeLessThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > lessThanEqual( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThanEqual( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThanEqual( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeLessThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > lessThanEqual( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeLessThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > lessThanEqual( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeLessThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > lessThanEqual( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< BVec2 > greaterThan( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThan2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThan( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThan3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThan( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeGreaterThan4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > greaterThan( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThan2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThan( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThan3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThan( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeGreaterThan4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > greaterThan( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThan2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThan( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThan3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThan( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeGreaterThan4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > greaterThan( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThan2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThan( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThan3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThan( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< BVec2 > greaterThanEqual( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThanEqual( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThanEqual( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > greaterThanEqual( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThanEqual( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThanEqual( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > greaterThanEqual( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThanEqual( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThanEqual( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > greaterThanEqual( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > greaterThanEqual( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeGreaterThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > greaterThanEqual( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< BVec2 > equal( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > equal( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > equal( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > equal( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > equal( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > equal( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > equal( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > equal( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > equal( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > equal( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > equal( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > equal( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< BVec2 > notEqual( Vec2 const & x
		, Vec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeNotEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > notEqual( Vec3 const & x
		, Vec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeNotEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > notEqual( Vec4 const & x
		, Vec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeNotEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > notEqual( DVec2 const & x
		, DVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeNotEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > notEqual( DVec3 const & x
		, DVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeNotEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > notEqual( DVec4 const & x
		, DVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeNotEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > notEqual( IVec2 const & x
		, IVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeNotEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > notEqual( IVec3 const & x
		, IVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeNotEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > notEqual( IVec4 const & x
		, IVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
			, expr::makeNotEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec2 > notEqual( UVec2 const & x
		, UVec2 const & y )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x, y )
			, expr::makeNotEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec3 > notEqual( UVec3 const & x
		, UVec3 const & y )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x, y )
			, expr::makeNotEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) )
			, areOptionalEnabled( x, y ) };
	}
	ReturnWrapperT< BVec4 > notEqual( UVec4 const & x
		, UVec4 const & y )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x, y )
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
	ReturnWrapperT< Boolean > all( BVec2 const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeAll2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Boolean > all( BVec3 const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeAll3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Boolean > all( BVec4 const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
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
	ReturnWrapperT< Boolean > any( BVec2 const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeAny2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Boolean > any( BVec3 const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
			, expr::makeAny3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Boolean > any( BVec4 const & x )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( x )
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
	ReturnWrapperT< BVec2 > binNot( BVec2 const & x )
	{
		return ReturnWrapperT< BVec2 >{ *findWriter( x )
			, expr::makeNot2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec3 > binNot( BVec3 const & x )
	{
		return ReturnWrapperT< BVec3 >{ *findWriter( x )
			, expr::makeNot3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< BVec4 > binNot( BVec4 const & x )
	{
		return ReturnWrapperT< BVec4 >{ *findWriter( x )
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
	ReturnWrapperT< UInt > uaddCarry( UInt const & x
		, UInt const & y
		, UInt const & carry )
	{
		return ReturnWrapperT< UInt >{ *findWriter( x, y, carry )
			, expr::makeUaddCarry1( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	ReturnWrapperT< UVec2 > uaddCarry( UVec2 const & x
		, UVec2 const & y
		, UVec2 const & carry )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( x, y, carry )
			, expr::makeUaddCarry2( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	ReturnWrapperT< UVec3 > uaddCarry( UVec3 const & x
		, UVec3 const & y
		, UVec3 const & carry )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( x, y, carry )
			, expr::makeUaddCarry3( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) )
			, areOptionalEnabled( x, y, carry ) };
	}
	ReturnWrapperT< UVec4 > uaddCarry( UVec4 const & x
		, UVec4 const & y
		, UVec4 const & carry )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( x, y, carry )
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
	ReturnWrapperT< UInt > usubBorrow( UInt const & x
		, UInt const & y
		, UInt const & borrow )
	{
		return ReturnWrapperT< UInt >{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow1( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	ReturnWrapperT< UVec2 > usubBorrow( UVec2 const & x
		, UVec2 const & y
		, UVec2 const & borrow )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow2( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	ReturnWrapperT< UVec3 > usubBorrow( UVec3 const & x
		, UVec3 const & y
		, UVec3 const & borrow )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( x, y, borrow )
			, expr::makeUsubBorrow3( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) )
			, areOptionalEnabled( x, y, borrow ) };
	}
	ReturnWrapperT< UVec4 > usubBorrow( UVec4 const & x
		, UVec4 const & y
		, UVec4 const & borrow )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( x, y, borrow )
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
	ReturnWrapperT< Void > umulExtended( UInt const & x
		, UInt const & y
		, UInt const & msb
		, UInt const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	ReturnWrapperT< Void > umulExtended( UVec2 const & x
		, UVec2 const & y
		, UVec2 const & msb
		, UVec2 const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	ReturnWrapperT< Void > umulExtended( UVec3 const & x
		, UVec3 const & y
		, UVec3 const & msb
		, UVec3 const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
			, expr::makeUmulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	ReturnWrapperT< Void > umulExtended( UVec4 const & x
		, UVec4 const & y
		, UVec4 const & msb
		, UVec4 const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
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
	ReturnWrapperT< Void > imulExtended( Int const & x
		, Int const & y
		, Int const & msb
		, Int const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	ReturnWrapperT< Void > imulExtended( IVec2 const & x
		, IVec2 const & y
		, IVec2 const & msb
		, IVec2 const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	ReturnWrapperT< Void > imulExtended( IVec3 const & x
		, IVec3 const & y
		, IVec3 const & msb
		, IVec3 const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
			, expr::makeImulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) )
			, areOptionalEnabled( x, y, msb, lsb ) };
	}
	ReturnWrapperT< Void > imulExtended( IVec4 const & x
		, IVec4 const & y
		, IVec4 const & msb
		, IVec4 const & lsb )
	{
		return ReturnWrapperT< Void >{ *findWriter( x, y, msb, lsb )
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
	ReturnWrapperT< Int > bitfieldExtract( Int const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< Int >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract1I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< IVec2 > bitfieldExtract( IVec2 const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract2I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< IVec3 > bitfieldExtract( IVec3 const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract3I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< IVec4 > bitfieldExtract( IVec4 const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract4I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< UInt > bitfieldExtract( UInt const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UInt >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract1U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< UVec2 > bitfieldExtract( UVec2 const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract2U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< UVec3 > bitfieldExtract( UVec3 const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( value, offset, bits )
			, expr::makeBitfieldExtract3U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( value, offset, bits ) };
	}
	ReturnWrapperT< UVec4 > bitfieldExtract( UVec4 const & value
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( value, offset, bits )
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
	ReturnWrapperT< Int > bitfieldInsert( Int const & base
		, Int const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< Int >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert1I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< IVec2 > bitfieldInsert( IVec2 const & base
		, IVec2 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert2I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< IVec3 > bitfieldInsert( IVec3 const & base
		, IVec3 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert3I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< IVec4 > bitfieldInsert( IVec4 const & base
		, IVec4 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert4I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< UInt > bitfieldInsert( UInt const & base
		, UInt const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UInt >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert1U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< UVec2 > bitfieldInsert( UVec2 const & base
		, UVec2 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert2U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< UVec3 > bitfieldInsert( UVec3 const & base
		, UVec3 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( base, insert, offset, bits )
			, expr::makeBitfieldInsert3U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) )
			, areOptionalEnabled( base, insert, offset, bits ) };
	}
	ReturnWrapperT< UVec4 > bitfieldInsert( UVec4 const & base
		, UVec4 const & insert
		, Int const & offset
		, Int const & bits )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( base, insert, offset, bits )
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
	ReturnWrapperT< Int > bitfieldReverse( Int const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeBitfieldReverse1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > bitfieldReverse( IVec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeBitfieldReverse2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > bitfieldReverse( IVec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeBitfieldReverse3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > bitfieldReverse( IVec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
			, expr::makeBitfieldReverse4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UInt > bitfieldReverse( UInt const & value )
	{
		return ReturnWrapperT< UInt >{ *findWriter( value )
			, expr::makeBitfieldReverse1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec2 > bitfieldReverse( UVec2 const & value )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( value )
			, expr::makeBitfieldReverse2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec3 > bitfieldReverse( UVec3 const & value )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( value )
			, expr::makeBitfieldReverse3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec4 > bitfieldReverse( UVec4 const & value )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( value )
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
	ReturnWrapperT< Int > bitCount( Int const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeBitCount1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > bitCount( IVec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeBitCount2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > bitCount( IVec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeBitCount3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > bitCount( IVec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
			, expr::makeBitCount4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UInt > bitCount( UInt const & value )
	{
		return ReturnWrapperT< UInt >{ *findWriter( value )
			, expr::makeBitCount1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec2 > bitCount( UVec2 const & value )
	{
		return ReturnWrapperT< UVec2 >{ *findWriter( value )
			, expr::makeBitCount2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec3 > bitCount( UVec3 const & value )
	{
		return ReturnWrapperT< UVec3 >{ *findWriter( value )
			, expr::makeBitCount3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< UVec4 > bitCount( UVec4 const & value )
	{
		return ReturnWrapperT< UVec4 >{ *findWriter( value )
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
	ReturnWrapperT< Int > findLSB( Int const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeFindLSB1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > findLSB( IVec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeFindLSB2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > findLSB( IVec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeFindLSB3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > findLSB( IVec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
			, expr::makeFindLSB4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< Int > findLSB( UInt const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeFindLSB1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > findLSB( UVec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeFindLSB2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > findLSB( UVec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeFindLSB3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > findLSB( UVec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
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
	ReturnWrapperT< Int > findMSB( Int const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeFindMSB1I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > findMSB( IVec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeFindMSB2I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > findMSB( IVec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeFindMSB3I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > findMSB( IVec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
			, expr::makeFindMSB4I( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< Int > findMSB( UInt const & value )
	{
		return ReturnWrapperT< Int >{ *findWriter( value )
			, expr::makeFindMSB1U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec2 > findMSB( UVec2 const & value )
	{
		return ReturnWrapperT< IVec2 >{ *findWriter( value )
			, expr::makeFindMSB2U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec3 > findMSB( UVec3 const & value )
	{
		return ReturnWrapperT< IVec3 >{ *findWriter( value )
			, expr::makeFindMSB3U( findTypesCache( value )
					, makeExpr( value ) )
			, areOptionalEnabled( value ) };
	}
	ReturnWrapperT< IVec4 > findMSB( UVec4 const & value )
	{
		return ReturnWrapperT< IVec4 >{ *findWriter( value )
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
	ReturnWrapperT< Int > atomicAdd( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicAddI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicAdd( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
			, expr::makeAtomicAddU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< Float > atomicAdd( Float const & mem
		, Float const & data )
	{
		return ReturnWrapperT< Float >{ *findWriter( mem, data )
			, expr::makeAtomicAddF( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< HVec2 > atomicAdd( HVec2 const & mem
		, HVec2 const & data )
	{
		return ReturnWrapperT< HVec2 >{ *findWriter( mem, data )
			, expr::makeAtomicAdd2H( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< HVec4 > atomicAdd( HVec4 const & mem
		, HVec4 const & data )
	{
		return ReturnWrapperT< HVec4 >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicMin( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicMinI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicMin( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicMax( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicMaxI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicMax( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicAnd( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicAndI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicAnd( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicOr( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicOrI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicOr( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicXor( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicXorI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicXor( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicExchange( Int const & mem
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, data )
			, expr::makeAtomicExchangeI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< UInt > atomicExchange( UInt const & mem
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, data )
			, expr::makeAtomicExchangeU( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< Float > atomicExchange( Float const & mem
		, Float const & data )
	{
		return ReturnWrapperT< Float >{ *findWriter( mem, data )
			, expr::makeAtomicExchangeF( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< HVec2 > atomicExchange( HVec2 const & mem
		, HVec2 const & data )
	{
		return ReturnWrapperT< HVec2 >{ *findWriter( mem, data )
			, expr::makeAtomicExchange2H( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, data ) };
	}
	ReturnWrapperT< HVec4 > atomicExchange( HVec4 const & mem
		, HVec4 const & data )
	{
		return ReturnWrapperT< HVec4 >{ *findWriter( mem, data )
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
	ReturnWrapperT< Int > atomicCompSwap( Int const & mem
		, Int const & compare
		, Int const & data )
	{
		return ReturnWrapperT< Int >{ *findWriter( mem, compare, data )
			, expr::makeAtomicCompSwapI( findTypesCache( mem, compare, data )
					, makeExpr( mem )
				, makeExpr( compare )
				, makeExpr( data ) )
			, areOptionalEnabled( mem, compare, data ) };
	}
	ReturnWrapperT< UInt > atomicCompSwap( UInt const & mem
		, UInt const & compare
		, UInt const & data )
	{
		return ReturnWrapperT< UInt >{ *findWriter( mem, compare, data )
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
	ReturnWrapperT< Float > dFdx( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeDFdx1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > dFdx( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeDFdx2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > dFdx( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeDFdx3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > dFdx( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > dFdxCoarse( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeDFdxCoarse1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > dFdxCoarse( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeDFdxCoarse2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > dFdxCoarse( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeDFdxCoarse3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > dFdxCoarse( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > dFdxFine( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeDFdxFine1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > dFdxFine( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeDFdxFine2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > dFdxFine( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeDFdxFine3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > dFdxFine( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > dFdy( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeDFdy1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > dFdy( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeDFdy2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > dFdy( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeDFdy3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > dFdy( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > dFdyCoarse( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeDFdyCoarse1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > dFdyCoarse( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeDFdyCoarse2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > dFdyCoarse( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeDFdyCoarse3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > dFdyCoarse( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > dFdyFine( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeDFdyFine1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > dFdyFine( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeDFdyFine2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > dFdyFine( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeDFdyFine3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > dFdyFine( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > fwidth( Float const & p )
	{
		return ReturnWrapperT< Float >{ *findWriter( p )
			, expr::makeFwidth1( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec2 > fwidth( Vec2 const & p )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( p )
			, expr::makeFwidth2( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec3 > fwidth( Vec3 const & p )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( p )
			, expr::makeFwidth3( findTypesCache( p )
					, makeExpr( p ) )
			, areOptionalEnabled( p ) };
	}
	ReturnWrapperT< Vec4 > fwidth( Vec4 const & p )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( p )
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
	ReturnWrapperT< Float > interpolateAtCentroid( Float const & x )
	{
		return ReturnWrapperT< Float >{ *findWriter( x )
			, expr::makeInterpolateAtCentroid1( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec2 > interpolateAtCentroid( Vec2 const & x )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( x )
			, expr::makeInterpolateAtCentroid2( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec3 > interpolateAtCentroid( Vec3 const & x )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( x )
			, expr::makeInterpolateAtCentroid3( findTypesCache( x )
					, makeExpr( x ) )
			, areOptionalEnabled( x ) };
	}
	ReturnWrapperT< Vec4 > interpolateAtCentroid( Vec4 const & x )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( x )
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
	ReturnWrapperT< Float > interpolateAtSample( Float const & interpolant
		, Int const & sample )
	{
		return ReturnWrapperT< Float >{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample1( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	ReturnWrapperT< Vec2 > interpolateAtSample( Vec2 const & interpolant
		, Int const & sample )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample2( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	ReturnWrapperT< Vec3 > interpolateAtSample( Vec3 const & interpolant
		, Int const & sample )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( interpolant, sample )
			, expr::makeInterpolateAtSample3( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) )
			, areOptionalEnabled( interpolant, sample ) };
	}
	ReturnWrapperT< Vec4 > interpolateAtSample( Vec4 const & interpolant
		, Int const & sample )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( interpolant, sample )
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
	ReturnWrapperT< Float > interpolateAtOffset( Float const & interpolant
		, Vec2 const & offset )
	{
		return ReturnWrapperT< Float >{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset1( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	ReturnWrapperT< Vec2 > interpolateAtOffset( Vec2 const & interpolant
		, Vec2 const & offset )
	{
		return ReturnWrapperT< Vec2 >{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset2( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	ReturnWrapperT< Vec3 > interpolateAtOffset( Vec3 const & interpolant
		, Vec2 const & offset )
	{
		return ReturnWrapperT< Vec3 >{ *findWriter( interpolant, offset )
			, expr::makeInterpolateAtOffset3( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) )
			, areOptionalEnabled( interpolant, offset ) };
	}
	ReturnWrapperT< Vec4 > interpolateAtOffset( Vec4 const & interpolant
		, Vec2 const & offset )
	{
		return ReturnWrapperT< Vec4 >{ *findWriter( interpolant, offset )
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
	ReturnWrapperT< Void > EmitStreamVertex( Int const & stream )
	{
		return ReturnWrapperT< Void >{ *findWriter( stream )
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
	ReturnWrapperT< Void > EndStreamPrimitive( Int const & stream )
	{
		return ReturnWrapperT< Void >{ *findWriter( stream )
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
	ReturnWrapperT< Void > EmitVertex( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Void > EndPrimitive( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Void > barrier( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Boolean > helperInvocation( ShaderWriter & writer )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( writer )
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
	ReturnWrapperT< UInt > memoryBarrier( ShaderWriter & writer )
	{
		return ReturnWrapperT< UInt >{ *findWriter( writer )
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
	ReturnWrapperT< Void > memoryBarrierBuffer( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Void > memoryBarrierShared( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Void > memoryBarrierImage( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Void > groupMemoryBarrier( ShaderWriter & writer )
	{
		return ReturnWrapperT< Void >{ *findWriter( writer )
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
	ReturnWrapperT< Void > traceRay( AccelerationStructure const & topLevel
		, UInt const & rayFlags
		, UInt const & cullMask
		, UInt const & sbtRecordOffset
		, UInt const & sbtRecordStride
		, UInt const & missIndex
		, RayDesc const & rayDesc
		, RayPayload const & payload )
	{
		return ReturnWrapperT< Void >{ *findWriter( topLevel, rayFlags, cullMask, sbtRecordOffset, sbtRecordStride, missIndex, rayDesc, payload )
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
	ReturnWrapperT< Boolean > reportIntersection( Float const & hitT
		, UInt const & hitKind
		, HitAttribute const & attribs )
	{
		return ReturnWrapperT< Boolean >{ *findWriter( hitT, hitKind, attribs )
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
	ReturnWrapperT< Void > executeCallable( UInt const & sbtRecordIndex
		, CallableData const & callable )
	{
		return ReturnWrapperT< Void >{ *findWriter( sbtRecordIndex, callable )
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
	ReturnWrapperT< Void > setMeshOutputCounts( UInt const & numVertices
		, UInt const & numPrimitives )
	{
		return ReturnWrapperT< Void >{ *findWriter( numVertices, numPrimitives )
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
	ReturnWrapperT< Void > dispatchMesh( TaskPayload const & payload
		, UInt const & numTasks )
	{
		return ReturnWrapperT< Void >{ *findWriter( payload, numTasks )
			, expr::makeDispatchMesh( findTypesCache( payload, numTasks )
					, makeExpr( payload )
				, makeExpr( numTasks ) )
			, areOptionalEnabled( payload, numTasks ) };
	}
	/**@}*/
#pragma endregion
}
