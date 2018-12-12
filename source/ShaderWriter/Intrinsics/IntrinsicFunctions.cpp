
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
	MaybeOptional< Float > degrees( MaybeOptional< Float > const & radians )
	{
		if ( isAnyOptional( radians ) )
		{
			return Optional< Float >{ findShader( radians )
				, expr::makeDegrees1( findTypesCache( radians )
					, makeExpr( radians ) )
				, areOptionalEnabled( radians ) };
		}

		return Float{ findShader( radians )
			, expr::makeDegrees1( findTypesCache( radians )
					, makeExpr( radians ) ) };
	}
	MaybeOptional< Vec2 > degrees( MaybeOptional< Vec2 > const & radians )
	{
		if ( isAnyOptional( radians ) )
		{
			return Optional< Vec2 >{ findShader( radians )
				, expr::makeDegrees2( findTypesCache( radians )
					, makeExpr( radians ) )
				, areOptionalEnabled( radians ) };
		}

		return Vec2{ findShader( radians )
			, expr::makeDegrees2( findTypesCache( radians )
					, makeExpr( radians ) ) };
	}
	MaybeOptional< Vec3 > degrees( MaybeOptional< Vec3 > const & radians )
	{
		if ( isAnyOptional( radians ) )
		{
			return Optional< Vec3 >{ findShader( radians )
				, expr::makeDegrees3( findTypesCache( radians )
					, makeExpr( radians ) )
				, areOptionalEnabled( radians ) };
		}

		return Vec3{ findShader( radians )
			, expr::makeDegrees3( findTypesCache( radians )
					, makeExpr( radians ) ) };
	}
	MaybeOptional< Vec4 > degrees( MaybeOptional< Vec4 > const & radians )
	{
		if ( isAnyOptional( radians ) )
		{
			return Optional< Vec4 >{ findShader( radians )
				, expr::makeDegrees4( findTypesCache( radians )
					, makeExpr( radians ) )
				, areOptionalEnabled( radians ) };
		}

		return Vec4{ findShader( radians )
			, expr::makeDegrees4( findTypesCache( radians )
					, makeExpr( radians ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region radians
	/**
	*name
	*	radians
	*/
	/**@{*/
	MaybeOptional< Float > radians( MaybeOptional< Float > const & degrees )
	{
		if ( isAnyOptional( degrees ) )
		{
			return Optional< Float >{ findShader( degrees )
				, expr::makeRadians1F( findTypesCache( degrees )
					, makeExpr( degrees ) )
				, areOptionalEnabled( degrees ) };
		}

		return Float{ findShader( degrees )
			, expr::makeRadians1F( findTypesCache( degrees )
					, makeExpr( degrees ) ) };
	}
	MaybeOptional< Vec2 > radians( MaybeOptional< Vec2 > const & degrees )
	{
		if ( isAnyOptional( degrees ) )
		{
			return Optional< Vec2 >{ findShader( degrees )
				, expr::makeRadians2F( findTypesCache( degrees )
					, makeExpr( degrees ) )
				, areOptionalEnabled( degrees ) };
		}

		return Vec2{ findShader( degrees )
			, expr::makeRadians2F( findTypesCache( degrees )
					, makeExpr( degrees ) ) };
	}
	MaybeOptional< Vec3 > radians( MaybeOptional< Vec3 > const & degrees )
	{
		if ( isAnyOptional( degrees ) )
		{
			return Optional< Vec3 >{ findShader( degrees )
				, expr::makeRadians3F( findTypesCache( degrees )
					, makeExpr( degrees ) )
				, areOptionalEnabled( degrees ) };
		}

		return Vec3{ findShader( degrees )
			, expr::makeRadians3F( findTypesCache( degrees )
					, makeExpr( degrees ) ) };
	}
	MaybeOptional< Vec4 > radians( MaybeOptional< Vec4 > const & degrees )
	{
		if ( isAnyOptional( degrees ) )
		{
			return Optional< Vec4 >{ findShader( degrees )
				, expr::makeRadians4F( findTypesCache( degrees )
					, makeExpr( degrees ) )
				, areOptionalEnabled( degrees ) };
		}

		return Vec4{ findShader( degrees )
			, expr::makeRadians4F( findTypesCache( degrees )
					, makeExpr( degrees ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region cos
	/**
	*name
	*	cos
	*/
	/**@{*/
	MaybeOptional< Float > cos( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeCos1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeCos1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > cos( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeCos2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeCos2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > cos( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeCos3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeCos3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > cos( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeCos4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeCos4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sin
	/**
	*name
	*	sin
	*/
	/**@{*/
	MaybeOptional< Float > sin( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeSin1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeSin1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > sin( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeSin2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeSin2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > sin( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeSin3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeSin3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > sin( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeSin4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeSin4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region tan
	/**
	*name
	*	tan
	*/
	/**@{*/
	MaybeOptional< Float > tan( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeTan1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeTan1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > tan( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeTan2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeTan2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > tan( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeTan3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeTan3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > tan( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeTan4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeTan4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region cosh
	/**
	*name
	*	cosh
	*/
	/**@{*/
	MaybeOptional< Float > cosh( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeCosh1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeCosh1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > cosh( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeCosh2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeCosh2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > cosh( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeCosh3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeCosh3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > cosh( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeCosh4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeCosh4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sinh
	/**
	*name
	*	sinh
	*/
	/**@{*/
	MaybeOptional< Float > sinh( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeSinh1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeSinh1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > sinh( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeSinh2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeSinh2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > sinh( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeSinh3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeSinh3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > sinh( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeSinh4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeSinh4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region tanh
	/**
	*name
	*	tanh
	*/
	/**@{*/
	MaybeOptional< Float > tanh( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeTanh1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeTanh1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > tanh( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeTanh2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeTanh2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > tanh( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeTanh3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeTanh3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > tanh( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeTanh4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeTanh4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region acos
	/**
	*name
	*	acos
	*/
	/**@{*/
	MaybeOptional< Float > acos( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeAcos1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeAcos1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > acos( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeAcos2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeAcos2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > acos( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeAcos3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeAcos3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > acos( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeAcos4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeAcos4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region asin
	/**
	*name
	*	asin
	*/
	/**@{*/
	MaybeOptional< Float > asin( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeAsin1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeAsin1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > asin( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeAsin2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeAsin2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > asin( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeAsin3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeAsin3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > asin( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeAsin4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeAsin4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atan
	/**
	*name
	*	atan
	*/
	/**@{*/
	MaybeOptional< Float > atan( MaybeOptional< Float > const & y_over_x )
	{
		if ( isAnyOptional( y_over_x ) )
		{
			return Optional< Float >{ findShader( y_over_x )
				, expr::makeAtan1( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
				, areOptionalEnabled( y_over_x ) };
		}

		return Float{ findShader( y_over_x )
			, expr::makeAtan1( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) ) };
	}
	MaybeOptional< Vec2 > atan( MaybeOptional< Vec2 > const & y_over_x )
	{
		if ( isAnyOptional( y_over_x ) )
		{
			return Optional< Vec2 >{ findShader( y_over_x )
				, expr::makeAtan2( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
				, areOptionalEnabled( y_over_x ) };
		}

		return Vec2{ findShader( y_over_x )
			, expr::makeAtan2( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) ) };
	}
	MaybeOptional< Vec3 > atan( MaybeOptional< Vec3 > const & y_over_x )
	{
		if ( isAnyOptional( y_over_x ) )
		{
			return Optional< Vec3 >{ findShader( y_over_x )
				, expr::makeAtan3( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
				, areOptionalEnabled( y_over_x ) };
		}

		return Vec3{ findShader( y_over_x )
			, expr::makeAtan3( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) ) };
	}
	MaybeOptional< Vec4 > atan( MaybeOptional< Vec4 > const & y_over_x )
	{
		if ( isAnyOptional( y_over_x ) )
		{
			return Optional< Vec4 >{ findShader( y_over_x )
				, expr::makeAtan4( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) )
				, areOptionalEnabled( y_over_x ) };
		}

		return Vec4{ findShader( y_over_x )
			, expr::makeAtan4( findTypesCache( y_over_x )
					, makeExpr( y_over_x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region acosh
	/**
	*name
	*	acosh
	*/
	/**@{*/
	MaybeOptional< Float > acosh( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeAcosh1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeAcosh1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > acosh( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeAcosh2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeAcosh2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > acosh( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeAcosh3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeAcosh3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > acosh( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeAcosh4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeAcosh4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region asinh
	/**
	*name
	*	asinh
	*/
	/**@{*/
	MaybeOptional< Float > asinh( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeAsinh1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeAsinh1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > asinh( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeAsinh2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeAsinh2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > asinh( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeAsinh3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeAsinh3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > asinh( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeAsinh4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeAsinh4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atanh
	/**
	*name
	*	atanh
	*/
	/**@{*/
	MaybeOptional< Float > atanh( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeAtanh1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeAtanh1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > atanh( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeAtanh2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeAtanh2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > atanh( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeAtanh3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeAtanh3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > atanh( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeAtanh4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeAtanh4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region pow
	/**
	*name
	*	pow
	*/
	/**@{*/
	MaybeOptional< Float > pow( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makePow1( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makePow1( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > pow( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makePow2( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makePow2( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > pow( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makePow3( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makePow3( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > pow( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makePow4( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makePow4( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Float > exp( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeExp1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeExp1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > exp( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeExp2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeExp2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > exp( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeExp3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeExp3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > exp( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeExp4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeExp4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region log
	/**
	*name
	*	log
	*/
	/**@{*/
	MaybeOptional< Float > log( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeLog1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeLog1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > log( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeLog2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeLog2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > log( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeLog3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeLog3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > log( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeLog4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeLog4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region exp2
	/**
	*name
	*	exp2
	*/
	/**@{*/
	MaybeOptional< Float > exp2( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeExp21( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeExp21( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > exp2( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeExp22( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeExp22( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > exp2( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeExp23( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeExp23( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > exp2( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeExp24( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeExp24( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region log2
	/**
	*name
	*	log2
	*/
	/**@{*/
	MaybeOptional< Float > log2( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeLog21( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeLog21( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > log2( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeLog22( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeLog22( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > log2( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeLog23( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeLog23( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > log2( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeLog24( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeLog24( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sqrt
	/**
	*name
	*	sqrt
	*/
	/**@{*/
	MaybeOptional< Float > sqrt( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeSqrt1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeSqrt1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > sqrt( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeSqrt2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeSqrt2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > sqrt( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeSqrt3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeSqrt3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > sqrt( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeSqrt4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeSqrt4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > sqrt( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeSqrt1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeSqrt1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > sqrt( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeSqrt2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeSqrt2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > sqrt( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeSqrt3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeSqrt3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > sqrt( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeSqrt4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeSqrt4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region inverseSqrt
	/**
	*name
	*	inverseSqrt
	*/
	/**@{*/
	MaybeOptional< Float > inverseSqrt( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeInverseSqrt1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeInverseSqrt1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > inverseSqrt( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeInverseSqrt2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeInverseSqrt2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > inverseSqrt( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeInverseSqrt3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeInverseSqrt3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > inverseSqrt( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeInverseSqrt4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeInverseSqrt4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > inverseSqrt( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeInverseSqrt1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeInverseSqrt1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > inverseSqrt( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeInverseSqrt2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeInverseSqrt2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > inverseSqrt( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeInverseSqrt3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeInverseSqrt3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > inverseSqrt( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeInverseSqrt4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeInverseSqrt4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region abs
	/**
	*name
	*	abs
	*/
	/**@{*/
	MaybeOptional< Float > abs( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeAbs1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeAbs1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > abs( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeAbs2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeAbs2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > abs( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeAbs3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeAbs3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > abs( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeAbs4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeAbs4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Int > abs( MaybeOptional< Int > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Int >{ findShader( x )
				, expr::makeAbs1I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Int{ findShader( x )
			, expr::makeAbs1I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< IVec2 > abs( MaybeOptional< IVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< IVec2 >{ findShader( x )
				, expr::makeAbs2I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return IVec2{ findShader( x )
			, expr::makeAbs2I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< IVec3 > abs( MaybeOptional< IVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< IVec3 >{ findShader( x )
				, expr::makeAbs3I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return IVec3{ findShader( x )
			, expr::makeAbs3I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< IVec4 > abs( MaybeOptional< IVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< IVec4 >{ findShader( x )
				, expr::makeAbs4I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return IVec4{ findShader( x )
			, expr::makeAbs4I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > abs( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeAbs1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeAbs1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > abs( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeAbs2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeAbs2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > abs( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeAbs3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeAbs3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > abs( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeAbs4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeAbs4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region sign
	/**
	*name
	*	sign
	*/
	/**@{*/
	MaybeOptional< Float > sign( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeSign1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeSign1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > sign( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeSign2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeSign2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > sign( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeSign3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeSign3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > sign( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeSign4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeSign4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Int > sign( MaybeOptional< Int > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Int >{ findShader( x )
				, expr::makeSign1I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Int{ findShader( x )
			, expr::makeSign1I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< IVec2 > sign( MaybeOptional< IVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< IVec2 >{ findShader( x )
				, expr::makeSign2I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return IVec2{ findShader( x )
			, expr::makeSign2I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< IVec3 > sign( MaybeOptional< IVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< IVec3 >{ findShader( x )
				, expr::makeSign3I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return IVec3{ findShader( x )
			, expr::makeSign3I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< IVec4 > sign( MaybeOptional< IVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< IVec4 >{ findShader( x )
				, expr::makeSign4I( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return IVec4{ findShader( x )
			, expr::makeSign4I( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > sign( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeSign1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeSign1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > sign( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeSign2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeSign2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > sign( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeSign3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeSign3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > sign( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeSign4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeSign4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region floor
	/**
	*name
	*	floor
	*/
	/**@{*/
	MaybeOptional< Float > floor( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeFloor1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeFloor1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > floor( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeFloor2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeFloor2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > floor( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeFloor3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeFloor3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > floor( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeFloor4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeFloor4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > floor( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeFloor1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeFloor1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > floor( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeFloor2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeFloor2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > floor( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeFloor3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeFloor3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > floor( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeFloor4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeFloor4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region trunc
	/**
	*name
	*	trunc
	*/
	/**@{*/
	MaybeOptional< Float > trunc( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeTrunc1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeTrunc1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > trunc( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeTrunc2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeTrunc2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > trunc( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeTrunc3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeTrunc3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > trunc( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeTrunc4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeTrunc4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > trunc( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeTrunc1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeTrunc1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > trunc( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeTrunc2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeTrunc2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > trunc( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeTrunc3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeTrunc3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > trunc( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeTrunc4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeTrunc4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region round
	/**
	*name
	*	round
	*/
	/**@{*/
	MaybeOptional< Float > round( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeRound1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeRound1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > round( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeRound2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeRound2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > round( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeRound3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeRound3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > round( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeRound4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeRound4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > round( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeRound1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeRound1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > round( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeRound2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeRound2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > round( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeRound3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeRound3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > round( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeRound4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeRound4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region roundEven
	/**
	*name
	*	roundEven
	*/
	/**@{*/
	MaybeOptional< Float > roundEven( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeRoundEven1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeRoundEven1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > roundEven( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeRoundEven2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeRoundEven2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > roundEven( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeRoundEven3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeRoundEven3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > roundEven( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeRoundEven4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeRoundEven4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > roundEven( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeRoundEven1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeRoundEven1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > roundEven( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeRoundEven2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeRoundEven2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > roundEven( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeRoundEven3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeRoundEven3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > roundEven( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeRoundEven4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeRoundEven4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region ceil
	/**
	*name
	*	ceil
	*/
	/**@{*/
	MaybeOptional< Float > ceil( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeCeil1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeCeil1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > ceil( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeCeil2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeCeil2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > ceil( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeCeil3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeCeil3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > ceil( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeCeil4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeCeil4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > ceil( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeCeil1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeCeil1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > ceil( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeCeil2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeCeil2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > ceil( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeCeil3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeCeil3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > ceil( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeCeil4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeCeil4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region fract
	/**
	*name
	*	fract
	*/
	/**@{*/
	MaybeOptional< Float > fract( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeFract1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeFract1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > fract( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeFract2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeFract2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > fract( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeFract3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeFract3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > fract( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeFract4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeFract4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > fract( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeFract1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeFract1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > fract( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeFract2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeFract2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > fract( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeFract3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeFract3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > fract( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeFract4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeFract4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region mod
	/**
	*name
	*	mod
	*/
	/**@{*/
	MaybeOptional< Float > mod( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeMod11F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeMod11F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > mod( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makeMod22F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makeMod22F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > mod( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeMod33F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeMod33F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > mod( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makeMod44F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makeMod44F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > mod( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makeMod21F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makeMod21F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > mod( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeMod31F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeMod31F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > mod( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makeMod41F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makeMod41F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > mod( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeMod11D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeMod11D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec2 > mod( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec2 >{ findShader( x, y )
				, expr::makeMod22D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec2{ findShader( x, y )
			, expr::makeMod22D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > mod( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeMod33D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeMod33D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec4 > mod( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec4 >{ findShader( x, y )
				, expr::makeMod44D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec4{ findShader( x, y )
			, expr::makeMod44D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec2 > mod( MaybeOptional< DVec2 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec2 >{ findShader( x, y )
				, expr::makeMod21D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec2{ findShader( x, y )
			, expr::makeMod21D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > mod( MaybeOptional< DVec3 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeMod31D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeMod31D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec4 > mod( MaybeOptional< DVec4 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec4 >{ findShader( x, y )
				, expr::makeMod41D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec4{ findShader( x, y )
			, expr::makeMod41D( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Float > modf( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< Float >{ findShader( x, i )
				, expr::makeModf1F( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return Float{ findShader( x, i )
			, expr::makeModf1F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< Vec2 > modf( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< Vec2 >{ findShader( x, i )
				, expr::makeModf2F( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return Vec2{ findShader( x, i )
			, expr::makeModf2F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< Vec3 > modf( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< Vec3 >{ findShader( x, i )
				, expr::makeModf3F( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return Vec3{ findShader( x, i )
			, expr::makeModf3F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< Vec4 > modf( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< Vec4 >{ findShader( x, i )
				, expr::makeModf4F( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return Vec4{ findShader( x, i )
			, expr::makeModf4F( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< Double > modf( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< Double >{ findShader( x, i )
				, expr::makeModf1D( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return Double{ findShader( x, i )
			, expr::makeModf1D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< DVec2 > modf( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< DVec2 >{ findShader( x, i )
				, expr::makeModf2D( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return DVec2{ findShader( x, i )
			, expr::makeModf2D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< DVec3 > modf( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< DVec3 >{ findShader( x, i )
				, expr::makeModf3D( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return DVec3{ findShader( x, i )
			, expr::makeModf3D( findTypesCache( x, i )
					, makeExpr( x )
				, makeExpr( i ) ) };
	}
	MaybeOptional< DVec4 > modf( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & i )
	{
		if ( isAnyOptional( x, i ) )
		{
			return Optional< DVec4 >{ findShader( x, i )
				, expr::makeModf4D( findTypesCache( x, i )
					, makeExpr( x )
					, makeExpr( i ) )
				, areOptionalEnabled( x, i ) };
		}

		return DVec4{ findShader( x, i )
			, expr::makeModf4D( findTypesCache( x, i )
					, makeExpr( x )
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
	MaybeOptional< Float > min( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeMin11F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeMin11F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > min( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makeMin22F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makeMin22F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > min( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeMin33F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeMin33F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > min( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makeMin44F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makeMin44F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > min( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makeMin21F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makeMin21F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > min( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeMin31F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeMin31F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > min( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makeMin41F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makeMin41F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > min( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeMin11D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeMin11D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec2 > min( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec2 >{ findShader( x, y )
				, expr::makeMin22D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec2{ findShader( x, y )
			, expr::makeMin22D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > min( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeMin33D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeMin33D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec4 > min( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec4 >{ findShader( x, y )
				, expr::makeMin44D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec4{ findShader( x, y )
			, expr::makeMin44D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec2 > min( MaybeOptional< DVec2 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec2 >{ findShader( x, y )
				, expr::makeMin21D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec2{ findShader( x, y )
			, expr::makeMin21D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > min( MaybeOptional< DVec3 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeMin31D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeMin31D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec4 > min( MaybeOptional< DVec4 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec4 >{ findShader( x, y )
				, expr::makeMin41D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec4{ findShader( x, y )
			, expr::makeMin41D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Int > min( MaybeOptional< Int > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Int >{ findShader( x, y )
				, expr::makeMin11I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Int{ findShader( x, y )
			, expr::makeMin11I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec2 > min( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec2 >{ findShader( x, y )
				, expr::makeMin22I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec2{ findShader( x, y )
			, expr::makeMin22I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec3 > min( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec3 >{ findShader( x, y )
				, expr::makeMin33I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec3{ findShader( x, y )
			, expr::makeMin33I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec4 > min( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec4 >{ findShader( x, y )
				, expr::makeMin44I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec4{ findShader( x, y )
			, expr::makeMin44I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec2 > min( MaybeOptional< IVec2 > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec2 >{ findShader( x, y )
				, expr::makeMin21I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec2{ findShader( x, y )
			, expr::makeMin21I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec3 > min( MaybeOptional< IVec3 > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec3 >{ findShader( x, y )
				, expr::makeMin31I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec3{ findShader( x, y )
			, expr::makeMin31I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec4 > min( MaybeOptional< IVec4 > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec4 >{ findShader( x, y )
				, expr::makeMin41I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec4{ findShader( x, y )
			, expr::makeMin41I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UInt > min( MaybeOptional< UInt > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UInt >{ findShader( x, y )
				, expr::makeMin11U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UInt{ findShader( x, y )
			, expr::makeMin11U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec2 > min( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec2 >{ findShader( x, y )
				, expr::makeMin22U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec2{ findShader( x, y )
			, expr::makeMin22U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec3 > min( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec3 >{ findShader( x, y )
				, expr::makeMin33U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec3{ findShader( x, y )
			, expr::makeMin33U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec4 > min( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec4 >{ findShader( x, y )
				, expr::makeMin44U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec4{ findShader( x, y )
			, expr::makeMin44U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec2 > min( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec2 >{ findShader( x, y )
				, expr::makeMin21U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec2{ findShader( x, y )
			, expr::makeMin21U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec3 > min( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec3 >{ findShader( x, y )
				, expr::makeMin31U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec3{ findShader( x, y )
			, expr::makeMin31U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec4 > min( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec4 >{ findShader( x, y )
				, expr::makeMin41U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec4{ findShader( x, y )
			, expr::makeMin41U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Float > max( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeMax11F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeMax11F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > max( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makeMax22F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makeMax22F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > max( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeMax33F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeMax33F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > max( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makeMax44F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makeMax44F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec2 > max( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec2 >{ findShader( x, y )
				, expr::makeMax21F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec2{ findShader( x, y )
			, expr::makeMax21F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec3 > max( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeMax31F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeMax31F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Vec4 > max( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec4 >{ findShader( x, y )
				, expr::makeMax41F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec4{ findShader( x, y )
			, expr::makeMax41F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > max( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeMax11D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeMax11D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec2 > max( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec2 >{ findShader( x, y )
				, expr::makeMax22D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec2{ findShader( x, y )
			, expr::makeMax22D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > max( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeMax33D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeMax33D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec4 > max( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec4 >{ findShader( x, y )
				, expr::makeMax44D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec4{ findShader( x, y )
			, expr::makeMax44D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec2 > max( MaybeOptional< DVec2 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec2 >{ findShader( x, y )
				, expr::makeMax21D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec2{ findShader( x, y )
			, expr::makeMax21D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > max( MaybeOptional< DVec3 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeMax31D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeMax31D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec4 > max( MaybeOptional< DVec4 > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec4 >{ findShader( x, y )
				, expr::makeMax41D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec4{ findShader( x, y )
			, expr::makeMax41D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Int > max( MaybeOptional< Int > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Int >{ findShader( x, y )
				, expr::makeMax11I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Int{ findShader( x, y )
			, expr::makeMax11I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec2 > max( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec2 >{ findShader( x, y )
				, expr::makeMax22I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec2{ findShader( x, y )
			, expr::makeMax22I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec3 > max( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec3 >{ findShader( x, y )
				, expr::makeMax33I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec3{ findShader( x, y )
			, expr::makeMax33I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec4 > max( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec4 >{ findShader( x, y )
				, expr::makeMax44I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec4{ findShader( x, y )
			, expr::makeMax44I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec2 > max( MaybeOptional< IVec2 > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec2 >{ findShader( x, y )
				, expr::makeMax21I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec2{ findShader( x, y )
			, expr::makeMax21I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec3 > max( MaybeOptional< IVec3 > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec3 >{ findShader( x, y )
				, expr::makeMax31I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec3{ findShader( x, y )
			, expr::makeMax31I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< IVec4 > max( MaybeOptional< IVec4 > const & x
		, MaybeOptional< Int > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< IVec4 >{ findShader( x, y )
				, expr::makeMax41I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return IVec4{ findShader( x, y )
			, expr::makeMax41I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UInt > max( MaybeOptional< UInt > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UInt >{ findShader( x, y )
				, expr::makeMax11U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UInt{ findShader( x, y )
			, expr::makeMax11U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec2 > max( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec2 >{ findShader( x, y )
				, expr::makeMax22U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec2{ findShader( x, y )
			, expr::makeMax22U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec3 > max( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec3 >{ findShader( x, y )
				, expr::makeMax33U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec3{ findShader( x, y )
			, expr::makeMax33U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec4 > max( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec4 >{ findShader( x, y )
				, expr::makeMax44U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec4{ findShader( x, y )
			, expr::makeMax44U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec2 > max( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec2 >{ findShader( x, y )
				, expr::makeMax21U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec2{ findShader( x, y )
			, expr::makeMax21U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec3 > max( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec3 >{ findShader( x, y )
				, expr::makeMax31U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec3{ findShader( x, y )
			, expr::makeMax31U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< UVec4 > max( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UInt > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< UVec4 >{ findShader( x, y )
				, expr::makeMax41U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return UVec4{ findShader( x, y )
			, expr::makeMax41U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Float > clamp( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & minVal
		, MaybeOptional< Float > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Float >{ findShader( x, minVal, maxVal )
				, expr::makeClamp11F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Float{ findShader( x, minVal, maxVal )
			, expr::makeClamp11F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Vec2 > clamp( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & minVal
		, MaybeOptional< Vec2 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Vec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp22F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Vec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Vec3 > clamp( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & minVal
		, MaybeOptional< Vec3 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Vec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp33F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Vec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Vec4 > clamp( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & minVal
		, MaybeOptional< Vec4 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Vec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp44F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Vec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Vec2 > clamp( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Float > const & minVal
		, MaybeOptional< Float > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Vec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp21F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Vec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Vec3 > clamp( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Float > const & minVal
		, MaybeOptional< Float > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Vec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp31F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Vec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Vec4 > clamp( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Float > const & minVal
		, MaybeOptional< Float > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Vec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp41F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Vec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41F( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Double > clamp( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & minVal
		, MaybeOptional< Double > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Double >{ findShader( x, minVal, maxVal )
				, expr::makeClamp11D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Double{ findShader( x, minVal, maxVal )
			, expr::makeClamp11D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< DVec2 > clamp( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & minVal
		, MaybeOptional< DVec2 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< DVec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp22D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return DVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< DVec3 > clamp( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & minVal
		, MaybeOptional< DVec3 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< DVec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp33D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return DVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< DVec4 > clamp( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & minVal
		, MaybeOptional< DVec4 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< DVec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp44D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return DVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< DVec2 > clamp( MaybeOptional< DVec2 > const & x
		, MaybeOptional< Double > const & minVal
		, MaybeOptional< Double > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< DVec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp21D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return DVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< DVec3 > clamp( MaybeOptional< DVec3 > const & x
		, MaybeOptional< Double > const & minVal
		, MaybeOptional< Double > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< DVec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp31D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return DVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< DVec4 > clamp( MaybeOptional< DVec4 > const & x
		, MaybeOptional< Double > const & minVal
		, MaybeOptional< Double > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< DVec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp41D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return DVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41D( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< Int > clamp( MaybeOptional< Int > const & x
		, MaybeOptional< Int > const & minVal
		, MaybeOptional< Int > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< Int >{ findShader( x, minVal, maxVal )
				, expr::makeClamp11I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return Int{ findShader( x, minVal, maxVal )
			, expr::makeClamp11I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< IVec2 > clamp( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & minVal
		, MaybeOptional< IVec2 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< IVec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp22I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return IVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< IVec3 > clamp( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & minVal
		, MaybeOptional< IVec3 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< IVec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp33I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return IVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< IVec4 > clamp( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & minVal
		, MaybeOptional< IVec4 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< IVec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp44I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return IVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< IVec2 > clamp( MaybeOptional< IVec2 > const & x
		, MaybeOptional< Int > const & minVal
		, MaybeOptional< Int > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< IVec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp21I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return IVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< IVec3 > clamp( MaybeOptional< IVec3 > const & x
		, MaybeOptional< Int > const & minVal
		, MaybeOptional< Int > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< IVec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp31I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return IVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< IVec4 > clamp( MaybeOptional< IVec4 > const & x
		, MaybeOptional< Int > const & minVal
		, MaybeOptional< Int > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< IVec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp41I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return IVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41I( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UInt > clamp( MaybeOptional< UInt > const & x
		, MaybeOptional< UInt > const & minVal
		, MaybeOptional< UInt > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UInt >{ findShader( x, minVal, maxVal )
				, expr::makeClamp11U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UInt{ findShader( x, minVal, maxVal )
			, expr::makeClamp11U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UVec2 > clamp( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & minVal
		, MaybeOptional< UVec2 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UVec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp22U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp22U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UVec3 > clamp( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & minVal
		, MaybeOptional< UVec3 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UVec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp33U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp33U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UVec4 > clamp( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & minVal
		, MaybeOptional< UVec4 > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UVec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp44U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp44U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UVec2 > clamp( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UInt > const & minVal
		, MaybeOptional< UInt > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UVec2 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp21U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UVec2{ findShader( x, minVal, maxVal )
			, expr::makeClamp21U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UVec3 > clamp( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UInt > const & minVal
		, MaybeOptional< UInt > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UVec3 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp31U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UVec3{ findShader( x, minVal, maxVal )
			, expr::makeClamp31U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
				, makeExpr( minVal )
				, makeExpr( maxVal ) ) };
	}
	MaybeOptional< UVec4 > clamp( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UInt > const & minVal
		, MaybeOptional< UInt > const & maxVal )
	{
		if ( isAnyOptional( x, minVal, maxVal ) )
		{
			return Optional< UVec4 >{ findShader( x, minVal, maxVal )
				, expr::makeClamp41U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
					, makeExpr( minVal )
					, makeExpr( maxVal ) )
				, areOptionalEnabled( x, minVal, maxVal ) };
		}

		return UVec4{ findShader( x, minVal, maxVal )
			, expr::makeClamp41U( findTypesCache( x, minVal, maxVal )
					, makeExpr( x )
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
	MaybeOptional< Float > mix( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y
		, MaybeOptional< Float > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Float >{ findShader( x, y, a )
				, expr::makeMix11F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Float{ findShader( x, y, a )
			, expr::makeMix11F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec2 > mix( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y
		, MaybeOptional< Vec2 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec2 >{ findShader( x, y, a )
				, expr::makeMix22F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec2{ findShader( x, y, a )
			, expr::makeMix22F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec3 > mix( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y
		, MaybeOptional< Vec3 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec3 >{ findShader( x, y, a )
				, expr::makeMix33F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec3{ findShader( x, y, a )
			, expr::makeMix33F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec4 > mix( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y
		, MaybeOptional< Vec4 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec4 >{ findShader( x, y, a )
				, expr::makeMix44F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec4{ findShader( x, y, a )
			, expr::makeMix44F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec2 > mix( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y
		, MaybeOptional< Float > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec2 >{ findShader( x, y, a )
				, expr::makeMix21F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec2{ findShader( x, y, a )
			, expr::makeMix21F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec3 > mix( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y
		, MaybeOptional< Float > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec3 >{ findShader( x, y, a )
				, expr::makeMix31F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec3{ findShader( x, y, a )
			, expr::makeMix31F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec4 > mix( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y
		, MaybeOptional< Float > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec4 >{ findShader( x, y, a )
				, expr::makeMix41F( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec4{ findShader( x, y, a )
			, expr::makeMix41F( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Float > mix( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y
		, MaybeOptional< Bool > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Float >{ findShader( x, y, a )
				, expr::makeMix11FB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Float{ findShader( x, y, a )
			, expr::makeMix11FB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec2 > mix( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y
		, MaybeOptional< BVec2 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec2 >{ findShader( x, y, a )
				, expr::makeMix22FB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec2{ findShader( x, y, a )
			, expr::makeMix22FB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec3 > mix( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y
		, MaybeOptional< BVec3 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec3 >{ findShader( x, y, a )
				, expr::makeMix33FB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec3{ findShader( x, y, a )
			, expr::makeMix33FB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Vec4 > mix( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y
		, MaybeOptional< BVec4 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Vec4 >{ findShader( x, y, a )
				, expr::makeMix44FB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Vec4{ findShader( x, y, a )
			, expr::makeMix44FB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Double > mix( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & y
		, MaybeOptional< Double > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Double >{ findShader( x, y, a )
				, expr::makeMix11D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Double{ findShader( x, y, a )
			, expr::makeMix11D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec2 > mix( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y
		, MaybeOptional< DVec2 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec2 >{ findShader( x, y, a )
				, expr::makeMix22D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec2{ findShader( x, y, a )
			, expr::makeMix22D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec3 > mix( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y
		, MaybeOptional< DVec3 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec3 >{ findShader( x, y, a )
				, expr::makeMix33D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec3{ findShader( x, y, a )
			, expr::makeMix33D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec4 > mix( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y
		, MaybeOptional< DVec4 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec4 >{ findShader( x, y, a )
				, expr::makeMix44D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec4{ findShader( x, y, a )
			, expr::makeMix44D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec2 > mix( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y
		, MaybeOptional< Double > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec2 >{ findShader( x, y, a )
				, expr::makeMix21D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec2{ findShader( x, y, a )
			, expr::makeMix21D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec3 > mix( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y
		, MaybeOptional< Double > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec3 >{ findShader( x, y, a )
				, expr::makeMix31D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec3{ findShader( x, y, a )
			, expr::makeMix31D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec4 > mix( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y
		, MaybeOptional< Double > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec4 >{ findShader( x, y, a )
				, expr::makeMix41D( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec4{ findShader( x, y, a )
			, expr::makeMix41D( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< Double > mix( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & y
		, MaybeOptional< Bool > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< Double >{ findShader( x, y, a )
				, expr::makeMix11DB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return Double{ findShader( x, y, a )
			, expr::makeMix11DB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec2 > mix( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y
		, MaybeOptional< BVec2 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec2 >{ findShader( x, y, a )
				, expr::makeMix22DB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec2{ findShader( x, y, a )
			, expr::makeMix22DB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec3 > mix( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y
		, MaybeOptional< BVec3 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec3 >{ findShader( x, y, a )
				, expr::makeMix33DB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec3{ findShader( x, y, a )
			, expr::makeMix33DB( findTypesCache( x, y, a )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( a ) ) };
	}
	MaybeOptional< DVec4 > mix( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y
		, MaybeOptional< BVec4 > const & a )
	{
		if ( isAnyOptional( x, y, a ) )
		{
			return Optional< DVec4 >{ findShader( x, y, a )
				, expr::makeMix44DB( findTypesCache( x, y, a )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( a ) )
				, areOptionalEnabled( x, y, a ) };
		}

		return DVec4{ findShader( x, y, a )
			, expr::makeMix44DB( findTypesCache( x, y, a )
					, makeExpr( x )
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
	MaybeOptional< Float > step( MaybeOptional< Float > const & edge
		, MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Float >{ findShader( edge, x )
				, expr::makeStep11F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Float{ findShader( edge, x )
			, expr::makeStep11F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > step( MaybeOptional< Vec2 > const & edge
		, MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Vec2 >{ findShader( edge, x )
				, expr::makeStep22F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Vec2{ findShader( edge, x )
			, expr::makeStep22F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > step( MaybeOptional< Vec3 > const & edge
		, MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Vec3 >{ findShader( edge, x )
				, expr::makeStep33F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Vec3{ findShader( edge, x )
			, expr::makeStep33F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > step( MaybeOptional< Vec4 > const & edge
		, MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Vec4 >{ findShader( edge, x )
				, expr::makeStep44F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Vec4{ findShader( edge, x )
			, expr::makeStep44F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > step( MaybeOptional< Float > const & edge
		, MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Vec2 >{ findShader( edge, x )
				, expr::makeStep12F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Vec2{ findShader( edge, x )
			, expr::makeStep12F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > step( MaybeOptional< Float > const & edge
		, MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Vec3 >{ findShader( edge, x )
				, expr::makeStep13F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Vec3{ findShader( edge, x )
			, expr::makeStep13F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > step( MaybeOptional< Float > const & edge
		, MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Vec4 >{ findShader( edge, x )
				, expr::makeStep14F( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Vec4{ findShader( edge, x )
			, expr::makeStep14F( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Double > step( MaybeOptional< Double > const & edge
		, MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< Double >{ findShader( edge, x )
				, expr::makeStep11D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return Double{ findShader( edge, x )
			, expr::makeStep11D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > step( MaybeOptional< DVec2 > const & edge
		, MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< DVec2 >{ findShader( edge, x )
				, expr::makeStep22D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return DVec2{ findShader( edge, x )
			, expr::makeStep22D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > step( MaybeOptional< DVec3 > const & edge
		, MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< DVec3 >{ findShader( edge, x )
				, expr::makeStep33D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return DVec3{ findShader( edge, x )
			, expr::makeStep33D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > step( MaybeOptional< DVec4 > const & edge
		, MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< DVec4 >{ findShader( edge, x )
				, expr::makeStep44D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return DVec4{ findShader( edge, x )
			, expr::makeStep44D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > step( MaybeOptional< Double > const & edge
		, MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< DVec2 >{ findShader( edge, x )
				, expr::makeStep12D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return DVec2{ findShader( edge, x )
			, expr::makeStep12D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > step( MaybeOptional< Double > const & edge
		, MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< DVec3 >{ findShader( edge, x )
				, expr::makeStep13D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return DVec3{ findShader( edge, x )
			, expr::makeStep13D( findTypesCache( edge, x )
					, makeExpr( edge )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > step( MaybeOptional< Double > const & edge
		, MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( edge, x ) )
		{
			return Optional< DVec4 >{ findShader( edge, x )
				, expr::makeStep14D( findTypesCache( edge, x )
					, makeExpr( edge )
					, makeExpr( x ) )
				, areOptionalEnabled( edge, x ) };
		}

		return DVec4{ findShader( edge, x )
			, expr::makeStep14D( findTypesCache( edge, x )
					, makeExpr( edge )
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
	MaybeOptional< Float > smoothStep( MaybeOptional< Float > const & edge0
		, MaybeOptional< Float > const & edge1
		, MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Float >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep11F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Float{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep11F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > smoothStep( MaybeOptional< Vec2 > const & edge0
		, MaybeOptional< Vec2 > const & edge1
		, MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Vec2 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep22F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Vec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep22F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > smoothStep( MaybeOptional< Vec3 > const & edge0
		, MaybeOptional< Vec3 > const & edge1
		, MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Vec3 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep33F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Vec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep33F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > smoothStep( MaybeOptional< Vec4 > const & edge0
		, MaybeOptional< Vec4 > const & edge1
		, MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Vec4 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep44F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Vec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep44F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > smoothStep( MaybeOptional< Float > const & edge0
		, MaybeOptional< Float > const & edge1
		, MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Vec2 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep12F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Vec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep12F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > smoothStep( MaybeOptional< Float > const & edge0
		, MaybeOptional< Float > const & edge1
		, MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Vec3 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep13F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Vec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep13F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > smoothStep( MaybeOptional< Float > const & edge0
		, MaybeOptional< Float > const & edge1
		, MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Vec4 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep14F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Vec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep14F( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< Double > smoothStep( MaybeOptional< Double > const & edge0
		, MaybeOptional< Double > const & edge1
		, MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< Double >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep11D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return Double{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep11D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > smoothStep( MaybeOptional< DVec2 > const & edge0
		, MaybeOptional< DVec2 > const & edge1
		, MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< DVec2 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep22D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return DVec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep22D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > smoothStep( MaybeOptional< DVec3 > const & edge0
		, MaybeOptional< DVec3 > const & edge1
		, MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< DVec3 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep33D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return DVec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep33D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > smoothStep( MaybeOptional< DVec4 > const & edge0
		, MaybeOptional< DVec4 > const & edge1
		, MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< DVec4 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep44D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return DVec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep44D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > smoothStep( MaybeOptional< Double > const & edge0
		, MaybeOptional< Double > const & edge1
		, MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< DVec2 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep12D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return DVec2{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep12D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > smoothStep( MaybeOptional< Double > const & edge0
		, MaybeOptional< Double > const & edge1
		, MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< DVec3 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep13D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return DVec3{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep13D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
				, makeExpr( edge1 )
				, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > smoothStep( MaybeOptional< Double > const & edge0
		, MaybeOptional< Double > const & edge1
		, MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( edge0, edge1, x ) )
		{
			return Optional< DVec4 >{ findShader( edge0, edge1, x )
				, expr::makeSmoothStep14D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
					, makeExpr( edge1 )
					, makeExpr( x ) )
				, areOptionalEnabled( edge0, edge1, x ) };
		}

		return DVec4{ findShader( edge0, edge1, x )
			, expr::makeSmoothStep14D( findTypesCache( edge0, edge1, x )
					, makeExpr( edge0 )
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
	MaybeOptional< Bool > isnan( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeIsnan1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeIsnan1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec2 > isnan( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec2 >{ findShader( x )
				, expr::makeIsnan2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec2{ findShader( x )
			, expr::makeIsnan2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec3 > isnan( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec3 >{ findShader( x )
				, expr::makeIsnan3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec3{ findShader( x )
			, expr::makeIsnan3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec4 > isnan( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec4 >{ findShader( x )
				, expr::makeIsnan4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec4{ findShader( x )
			, expr::makeIsnan4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Bool > isnan( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeIsnan1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeIsnan1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec2 > isnan( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec2 >{ findShader( x )
				, expr::makeIsnan2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec2{ findShader( x )
			, expr::makeIsnan2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec3 > isnan( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec3 >{ findShader( x )
				, expr::makeIsnan3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec3{ findShader( x )
			, expr::makeIsnan3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec4 > isnan( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec4 >{ findShader( x )
				, expr::makeIsnan4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec4{ findShader( x )
			, expr::makeIsnan4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region isinf
	/**
	*name
	*	isinf
	*/
	/**@{*/
	MaybeOptional< Bool > isinf( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeIsinf1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeIsinf1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec2 > isinf( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec2 >{ findShader( x )
				, expr::makeIsinf2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec2{ findShader( x )
			, expr::makeIsinf2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec3 > isinf( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec3 >{ findShader( x )
				, expr::makeIsinf3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec3{ findShader( x )
			, expr::makeIsinf3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec4 > isinf( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec4 >{ findShader( x )
				, expr::makeIsinf4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec4{ findShader( x )
			, expr::makeIsinf4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Bool > isinf( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeIsinf1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeIsinf1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec2 > isinf( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec2 >{ findShader( x )
				, expr::makeIsinf2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec2{ findShader( x )
			, expr::makeIsinf2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec3 > isinf( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec3 >{ findShader( x )
				, expr::makeIsinf3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec3{ findShader( x )
			, expr::makeIsinf3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec4 > isinf( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec4 >{ findShader( x )
				, expr::makeIsinf4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec4{ findShader( x )
			, expr::makeIsinf4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region floatBitsToInt
	/**
	*name
	*	floatBitsToInt
	*/
	/**@{*/
	MaybeOptional< Int > floatBitsToInt( MaybeOptional< Float > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeFloatBitsToInt1( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeFloatBitsToInt1( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > floatBitsToInt( MaybeOptional< Vec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeFloatBitsToInt2( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeFloatBitsToInt2( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > floatBitsToInt( MaybeOptional< Vec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeFloatBitsToInt3( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeFloatBitsToInt3( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > floatBitsToInt( MaybeOptional< Vec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeFloatBitsToInt4( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeFloatBitsToInt4( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region floatBitsToUInt
	/**
	*name
	*	floatBitsToUInt
	*/
	/**@{*/
	MaybeOptional< UInt > floatBitsToUInt( MaybeOptional< Float > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UInt >{ findShader( value )
				, expr::makeFloatBitsToUInt1( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UInt{ findShader( value )
			, expr::makeFloatBitsToUInt1( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec2 > floatBitsToUInt( MaybeOptional< Vec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec2 >{ findShader( value )
				, expr::makeFloatBitsToUInt2( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec2{ findShader( value )
			, expr::makeFloatBitsToUInt2( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec3 > floatBitsToUInt( MaybeOptional< Vec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec3 >{ findShader( value )
				, expr::makeFloatBitsToUInt3( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec3{ findShader( value )
			, expr::makeFloatBitsToUInt3( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec4 > floatBitsToUInt( MaybeOptional< Vec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec4 >{ findShader( value )
				, expr::makeFloatBitsToUInt4( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec4{ findShader( value )
			, expr::makeFloatBitsToUInt4( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region intBitsToFloat
	/**
	*name
	*	intBitsToFloat
	*/
	/**@{*/
	MaybeOptional< Float > intBitsToFloat( MaybeOptional< Int > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeIntBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeIntBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > intBitsToFloat( MaybeOptional< IVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeIntBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeIntBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > intBitsToFloat( MaybeOptional< IVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeIntBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeIntBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > intBitsToFloat( MaybeOptional< IVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeIntBitsToFloat4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeIntBitsToFloat4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region uintBitsToFloat
	/**
	*name
	*	uintBitsToFloat
	*/
	/**@{*/
	MaybeOptional< Float > uintBitsToFloat( MaybeOptional< UInt > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeUintBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeUintBitsToFloat1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > uintBitsToFloat( MaybeOptional< UVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeUintBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeUintBitsToFloat2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > uintBitsToFloat( MaybeOptional< UVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeUintBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeUintBitsToFloat3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > uintBitsToFloat( MaybeOptional< UVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeUintBitsToFloat4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeUintBitsToFloat4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region fma
	/**
	*name
	*	fma
	*/
	/**@{*/
	MaybeOptional< Float > fma( MaybeOptional< Float > const & a
		, MaybeOptional< Float > const & b
		, MaybeOptional< Float > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< Float >{ findShader( a, b, c )
				, expr::makeFma1F( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return Float{ findShader( a, b, c )
			, expr::makeFma1F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< Vec2 > fma( MaybeOptional< Vec2 > const & a
		, MaybeOptional< Vec2 > const & b
		, MaybeOptional< Vec2 > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< Vec2 >{ findShader( a, b, c )
				, expr::makeFma2F( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return Vec2{ findShader( a, b, c )
			, expr::makeFma2F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< Vec3 > fma( MaybeOptional< Vec3 > const & a
		, MaybeOptional< Vec3 > const & b
		, MaybeOptional< Vec3 > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< Vec3 >{ findShader( a, b, c )
				, expr::makeFma3F( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return Vec3{ findShader( a, b, c )
			, expr::makeFma3F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< Vec4 > fma( MaybeOptional< Vec4 > const & a
		, MaybeOptional< Vec4 > const & b
		, MaybeOptional< Vec4 > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< Vec4 >{ findShader( a, b, c )
				, expr::makeFma4F( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return Vec4{ findShader( a, b, c )
			, expr::makeFma4F( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< Double > fma( MaybeOptional< Double > const & a
		, MaybeOptional< Double > const & b
		, MaybeOptional< Double > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< Double >{ findShader( a, b, c )
				, expr::makeFma1D( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return Double{ findShader( a, b, c )
			, expr::makeFma1D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< DVec2 > fma( MaybeOptional< DVec2 > const & a
		, MaybeOptional< DVec2 > const & b
		, MaybeOptional< DVec2 > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< DVec2 >{ findShader( a, b, c )
				, expr::makeFma2D( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return DVec2{ findShader( a, b, c )
			, expr::makeFma2D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< DVec3 > fma( MaybeOptional< DVec3 > const & a
		, MaybeOptional< DVec3 > const & b
		, MaybeOptional< DVec3 > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< DVec3 >{ findShader( a, b, c )
				, expr::makeFma3D( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return DVec3{ findShader( a, b, c )
			, expr::makeFma3D( findTypesCache( a, b, c )
					, makeExpr( a )
				, makeExpr( b )
				, makeExpr( c ) ) };
	}
	MaybeOptional< DVec4 > fma( MaybeOptional< DVec4 > const & a
		, MaybeOptional< DVec4 > const & b
		, MaybeOptional< DVec4 > const & c )
	{
		if ( isAnyOptional( a, b, c ) )
		{
			return Optional< DVec4 >{ findShader( a, b, c )
				, expr::makeFma4D( findTypesCache( a, b, c )
					, makeExpr( a )
					, makeExpr( b )
					, makeExpr( c ) )
				, areOptionalEnabled( a, b, c ) };
		}

		return DVec4{ findShader( a, b, c )
			, expr::makeFma4D( findTypesCache( a, b, c )
					, makeExpr( a )
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
	MaybeOptional< Float > frexp( MaybeOptional< Float > const & x
		, MaybeOptional< Int > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Float >{ findShader( x, exp )
				, expr::makeFrexp1F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Float{ findShader( x, exp )
			, expr::makeFrexp1F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Vec2 > frexp( MaybeOptional< Vec2 > const & x
		, MaybeOptional< IVec2 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Vec2 >{ findShader( x, exp )
				, expr::makeFrexp2F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Vec2{ findShader( x, exp )
			, expr::makeFrexp2F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Vec3 > frexp( MaybeOptional< Vec3 > const & x
		, MaybeOptional< IVec3 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Vec3 >{ findShader( x, exp )
				, expr::makeFrexp3F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Vec3{ findShader( x, exp )
			, expr::makeFrexp3F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Vec4 > frexp( MaybeOptional< Vec4 > const & x
		, MaybeOptional< IVec4 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Vec4 >{ findShader( x, exp )
				, expr::makeFrexp4F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Vec4{ findShader( x, exp )
			, expr::makeFrexp4F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Double > frexp( MaybeOptional< Double > const & x
		, MaybeOptional< Int > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Double >{ findShader( x, exp )
				, expr::makeFrexp1D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Double{ findShader( x, exp )
			, expr::makeFrexp1D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< DVec2 > frexp( MaybeOptional< DVec2 > const & x
		, MaybeOptional< IVec2 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< DVec2 >{ findShader( x, exp )
				, expr::makeFrexp2D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return DVec2{ findShader( x, exp )
			, expr::makeFrexp2D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< DVec3 > frexp( MaybeOptional< DVec3 > const & x
		, MaybeOptional< IVec3 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< DVec3 >{ findShader( x, exp )
				, expr::makeFrexp3D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return DVec3{ findShader( x, exp )
			, expr::makeFrexp3D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< DVec4 > frexp( MaybeOptional< DVec4 > const & x
		, MaybeOptional< IVec4 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< DVec4 >{ findShader( x, exp )
				, expr::makeFrexp4D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return DVec4{ findShader( x, exp )
			, expr::makeFrexp4D( findTypesCache( x, exp )
					, makeExpr( x )
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
	MaybeOptional< Float > ldexp( MaybeOptional< Float > const & x
		, MaybeOptional< Int > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Float >{ findShader( x, exp )
				, expr::makeLdexp1F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Float{ findShader( x, exp )
			, expr::makeLdexp1F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Vec2 > ldexp( MaybeOptional< Vec2 > const & x
		, MaybeOptional< IVec2 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Vec2 >{ findShader( x, exp )
				, expr::makeLdexp2F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Vec2{ findShader( x, exp )
			, expr::makeLdexp2F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Vec3 > ldexp( MaybeOptional< Vec3 > const & x
		, MaybeOptional< IVec3 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Vec3 >{ findShader( x, exp )
				, expr::makeLdexp3F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Vec3{ findShader( x, exp )
			, expr::makeLdexp3F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Vec4 > ldexp( MaybeOptional< Vec4 > const & x
		, MaybeOptional< IVec4 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Vec4 >{ findShader( x, exp )
				, expr::makeLdexp4F( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Vec4{ findShader( x, exp )
			, expr::makeLdexp4F( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< Double > ldexp( MaybeOptional< Double > const & x
		, MaybeOptional< Int > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< Double >{ findShader( x, exp )
				, expr::makeLdexp1D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return Double{ findShader( x, exp )
			, expr::makeLdexp1D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< DVec2 > ldexp( MaybeOptional< DVec2 > const & x
		, MaybeOptional< IVec2 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< DVec2 >{ findShader( x, exp )
				, expr::makeLdexp2D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return DVec2{ findShader( x, exp )
			, expr::makeLdexp2D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< DVec3 > ldexp( MaybeOptional< DVec3 > const & x
		, MaybeOptional< IVec3 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< DVec3 >{ findShader( x, exp )
				, expr::makeLdexp3D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return DVec3{ findShader( x, exp )
			, expr::makeLdexp3D( findTypesCache( x, exp )
					, makeExpr( x )
				, makeExpr( exp ) ) };
	}
	MaybeOptional< DVec4 > ldexp( MaybeOptional< DVec4 > const & x
		, MaybeOptional< IVec4 > const & exp )
	{
		if ( isAnyOptional( x, exp ) )
		{
			return Optional< DVec4 >{ findShader( x, exp )
				, expr::makeLdexp4D( findTypesCache( x, exp )
					, makeExpr( x )
					, makeExpr( exp ) )
				, areOptionalEnabled( x, exp ) };
		}

		return DVec4{ findShader( x, exp )
			, expr::makeLdexp4D( findTypesCache( x, exp )
					, makeExpr( x )
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
	MaybeOptional< Double > packDouble2x32( MaybeOptional< UVec2 > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< Double >{ findShader( v )
				, expr::makePackDouble2x32( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return Double{ findShader( v )
			, expr::makePackDouble2x32( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packHalf2x16
	/**
	*name
	*	packHalf2x16
	*/
	/**@{*/
	MaybeOptional< UInt > packHalf2x16( MaybeOptional< Vec2 > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< UInt >{ findShader( v )
				, expr::makePackHalf2x16( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return UInt{ findShader( v )
			, expr::makePackHalf2x16( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packSnorm2x16
	/**
	*name
	*	packSnorm2x16
	*/
	/**@{*/
	MaybeOptional< UInt > packSnorm2x16( MaybeOptional< Vec2 > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< UInt >{ findShader( v )
				, expr::makePackSnorm2x16( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return UInt{ findShader( v )
			, expr::makePackSnorm2x16( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packSnorm4x8
	/**
	*name
	*	packSnorm4x8
	*/
	/**@{*/
	MaybeOptional< UInt > packSnorm4x8( MaybeOptional< Vec4 > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< UInt >{ findShader( v )
				, expr::makePackSnorm4x8( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return UInt{ findShader( v )
			, expr::makePackSnorm4x8( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packUnorm2x16
	/**
	*name
	*	packUnorm2x16
	*/
	/**@{*/
	MaybeOptional< UInt > packUnorm2x16( MaybeOptional< Vec2 > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< UInt >{ findShader( v )
				, expr::makePackUnorm2x16( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return UInt{ findShader( v )
			, expr::makePackUnorm2x16( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region packUnorm4x8
	/**
	*name
	*	packUnorm4x8
	*/
	/**@{*/
	MaybeOptional< UInt > packUnorm4x8( MaybeOptional< Vec4 > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< UInt >{ findShader( v )
				, expr::makePackUnorm4x8( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return UInt{ findShader( v )
			, expr::makePackUnorm4x8( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackDouble2x32
	/**
	*name
	*	unpackDouble2x32
	*/
	/**@{*/
	MaybeOptional< UVec2 > unpackDouble2x32( MaybeOptional< Double > const & d )
	{
		if ( isAnyOptional( d ) )
		{
			return Optional< UVec2 >{ findShader( d )
				, expr::makeUnpackDouble2x32( findTypesCache( d )
					, makeExpr( d ) )
				, areOptionalEnabled( d ) };
		}

		return UVec2{ findShader( d )
			, expr::makeUnpackDouble2x32( findTypesCache( d )
					, makeExpr( d ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackHalf2x16
	/**
	*name
	*	unpackHalf2x16
	*/
	/**@{*/
	MaybeOptional< Vec2 > unpackHalf2x16( MaybeOptional< UInt > const & v )
	{
		if ( isAnyOptional( v ) )
		{
			return Optional< Vec2 >{ findShader( v )
				, expr::makeUnpackHalf2x16( findTypesCache( v )
					, makeExpr( v ) )
				, areOptionalEnabled( v ) };
		}

		return Vec2{ findShader( v )
			, expr::makeUnpackHalf2x16( findTypesCache( v )
					, makeExpr( v ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackSnorm2x16
	/**
	*name
	*	unpackSnorm2x16
	*/
	/**@{*/
	MaybeOptional< Vec2 > unpackSnorm2x16( MaybeOptional< UInt > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeUnpackSnorm2x16( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeUnpackSnorm2x16( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackSnorm4x8
	/**
	*name
	*	unpackSnorm4x8
	*/
	/**@{*/
	MaybeOptional< Vec4 > unpackSnorm4x8( MaybeOptional< UInt > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeUnpackSnorm4x8( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeUnpackSnorm4x8( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackUnorm2x16
	/**
	*name
	*	unpackUnorm2x16
	*/
	/**@{*/
	MaybeOptional< Vec2 > unpackUnorm2x16( MaybeOptional< UInt > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeUnpackUnorm2x16( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeUnpackUnorm2x16( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region unpackUnorm4x8
	/**
	*name
	*	unpackUnorm4x8
	*/
	/**@{*/
	MaybeOptional< Vec4 > unpackUnorm4x8( MaybeOptional< UInt > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeUnpackUnorm4x8( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeUnpackUnorm4x8( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region length
	/**
	*name
	*	length
	*/
	/**@{*/
	MaybeOptional< Float > length( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeLength1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeLength1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Float > length( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeLength2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeLength2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Float > length( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeLength3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeLength3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Float > length( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeLength4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeLength4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > length( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeLength1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeLength1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > length( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeLength2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeLength2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > length( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeLength3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeLength3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > length( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeLength4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeLength4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region distance
	/**
	*name
	*	distance
	*/
	/**@{*/
	MaybeOptional< Float > distance( MaybeOptional< Float > const & p0
		, MaybeOptional< Float > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Float >{ findShader( p0, p1 )
				, expr::makeDistance1F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Float{ findShader( p0, p1 )
			, expr::makeDistance1F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Vec2 > distance( MaybeOptional< Vec2 > const & p0
		, MaybeOptional< Vec2 > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Vec2 >{ findShader( p0, p1 )
				, expr::makeDistance2F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Vec2{ findShader( p0, p1 )
			, expr::makeDistance2F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Vec3 > distance( MaybeOptional< Vec3 > const & p0
		, MaybeOptional< Vec3 > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Vec3 >{ findShader( p0, p1 )
				, expr::makeDistance3F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Vec3{ findShader( p0, p1 )
			, expr::makeDistance3F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Vec4 > distance( MaybeOptional< Vec4 > const & p0
		, MaybeOptional< Vec4 > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Vec4 >{ findShader( p0, p1 )
				, expr::makeDistance4F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Vec4{ findShader( p0, p1 )
			, expr::makeDistance4F( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Double > distance( MaybeOptional< Double > const & p0
		, MaybeOptional< Double > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Double >{ findShader( p0, p1 )
				, expr::makeDistance1D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Double{ findShader( p0, p1 )
			, expr::makeDistance1D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Double > distance( MaybeOptional< DVec2 > const & p0
		, MaybeOptional< DVec2 > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Double >{ findShader( p0, p1 )
				, expr::makeDistance2D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Double{ findShader( p0, p1 )
			, expr::makeDistance2D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Double > distance( MaybeOptional< DVec3 > const & p0
		, MaybeOptional< DVec3 > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Double >{ findShader( p0, p1 )
				, expr::makeDistance3D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Double{ findShader( p0, p1 )
			, expr::makeDistance3D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
				, makeExpr( p1 ) ) };
	}
	MaybeOptional< Double > distance( MaybeOptional< DVec4 > const & p0
		, MaybeOptional< DVec4 > const & p1 )
	{
		if ( isAnyOptional( p0, p1 ) )
		{
			return Optional< Double >{ findShader( p0, p1 )
				, expr::makeDistance4D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
					, makeExpr( p1 ) )
				, areOptionalEnabled( p0, p1 ) };
		}

		return Double{ findShader( p0, p1 )
			, expr::makeDistance4D( findTypesCache( p0, p1 )
					, makeExpr( p0 )
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
	MaybeOptional< Float > dot( MaybeOptional< Float > const & x
		, MaybeOptional< Float > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeDot1F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeDot1F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Float > dot( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeDot2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeDot2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Float > dot( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeDot3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeDot3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Float > dot( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Float >{ findShader( x, y )
				, expr::makeDot4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Float{ findShader( x, y )
			, expr::makeDot4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > dot( MaybeOptional< Double > const & x
		, MaybeOptional< Double > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeDot1D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeDot1D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > dot( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeDot2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeDot2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > dot( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeDot3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeDot3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Double > dot( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Double >{ findShader( x, y )
				, expr::makeDot4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Double{ findShader( x, y )
			, expr::makeDot4D( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Vec3 > cross( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Vec3 >{ findShader( x, y )
				, expr::makeCrossF( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Vec3{ findShader( x, y )
			, expr::makeCrossF( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DVec3 > cross( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DVec3 >{ findShader( x, y )
				, expr::makeCrossD( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DVec3{ findShader( x, y )
			, expr::makeCrossD( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Float > normalize( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeNormalize1F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeNormalize1F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > normalize( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeNormalize2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeNormalize2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > normalize( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeNormalize3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeNormalize3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > normalize( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeNormalize4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeNormalize4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Double > normalize( MaybeOptional< Double > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Double >{ findShader( x )
				, expr::makeNormalize1D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Double{ findShader( x )
			, expr::makeNormalize1D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec2 > normalize( MaybeOptional< DVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec2 >{ findShader( x )
				, expr::makeNormalize2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec2{ findShader( x )
			, expr::makeNormalize2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec3 > normalize( MaybeOptional< DVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec3 >{ findShader( x )
				, expr::makeNormalize3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec3{ findShader( x )
			, expr::makeNormalize3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DVec4 > normalize( MaybeOptional< DVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DVec4 >{ findShader( x )
				, expr::makeNormalize4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DVec4{ findShader( x )
			, expr::makeNormalize4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region faceForward
	/**
	*name
	*	faceForward
	*/
	/**@{*/
	MaybeOptional< Float > faceForward( MaybeOptional< Float > const & N
		, MaybeOptional< Float > const & I
		, MaybeOptional< Float > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< Float >{ findShader( N, I, Nref )
				, expr::makeFaceForward1F( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return Float{ findShader( N, I, Nref )
			, expr::makeFaceForward1F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< Vec2 > faceForward( MaybeOptional< Vec2 > const & N
		, MaybeOptional< Vec2 > const & I
		, MaybeOptional< Vec2 > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< Vec2 >{ findShader( N, I, Nref )
				, expr::makeFaceForward2F( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return Vec2{ findShader( N, I, Nref )
			, expr::makeFaceForward2F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< Vec3 > faceForward( MaybeOptional< Vec3 > const & N
		, MaybeOptional< Vec3 > const & I
		, MaybeOptional< Vec3 > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< Vec3 >{ findShader( N, I, Nref )
				, expr::makeFaceForward3F( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return Vec3{ findShader( N, I, Nref )
			, expr::makeFaceForward3F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< Vec4 > faceForward( MaybeOptional< Vec4 > const & N
		, MaybeOptional< Vec4 > const & I
		, MaybeOptional< Vec4 > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< Vec4 >{ findShader( N, I, Nref )
				, expr::makeFaceForward4F( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return Vec4{ findShader( N, I, Nref )
			, expr::makeFaceForward4F( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< Double > faceForward( MaybeOptional< Double > const & N
		, MaybeOptional< Double > const & I
		, MaybeOptional< Double > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< Double >{ findShader( N, I, Nref )
				, expr::makeFaceForward1D( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return Double{ findShader( N, I, Nref )
			, expr::makeFaceForward1D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< DVec2 > faceForward( MaybeOptional< DVec2 > const & N
		, MaybeOptional< DVec2 > const & I
		, MaybeOptional< DVec2 > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< DVec2 >{ findShader( N, I, Nref )
				, expr::makeFaceForward2D( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return DVec2{ findShader( N, I, Nref )
			, expr::makeFaceForward2D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< DVec3 > faceForward( MaybeOptional< DVec3 > const & N
		, MaybeOptional< DVec3 > const & I
		, MaybeOptional< DVec3 > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< DVec3 >{ findShader( N, I, Nref )
				, expr::makeFaceForward3D( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return DVec3{ findShader( N, I, Nref )
			, expr::makeFaceForward3D( findTypesCache( N, I, Nref )
					, makeExpr( N )
				, makeExpr( I )
				, makeExpr( Nref ) ) };
	}
	MaybeOptional< DVec4 > faceForward( MaybeOptional< DVec4 > const & N
		, MaybeOptional< DVec4 > const & I
		, MaybeOptional< DVec4 > const & Nref )
	{
		if ( isAnyOptional( N, I, Nref ) )
		{
			return Optional< DVec4 >{ findShader( N, I, Nref )
				, expr::makeFaceForward4D( findTypesCache( N, I, Nref )
					, makeExpr( N )
					, makeExpr( I )
					, makeExpr( Nref ) )
				, areOptionalEnabled( N, I, Nref ) };
		}

		return DVec4{ findShader( N, I, Nref )
			, expr::makeFaceForward4D( findTypesCache( N, I, Nref )
					, makeExpr( N )
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
	MaybeOptional< Float > reflect( MaybeOptional< Float > const & I
		, MaybeOptional< Float > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< Float >{ findShader( I, N )
				, expr::makeReflect1F( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return Float{ findShader( I, N )
			, expr::makeReflect1F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< Vec2 > reflect( MaybeOptional< Vec2 > const & I
		, MaybeOptional< Vec2 > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< Vec2 >{ findShader( I, N )
				, expr::makeReflect2F( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return Vec2{ findShader( I, N )
			, expr::makeReflect2F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< Vec3 > reflect( MaybeOptional< Vec3 > const & I
		, MaybeOptional< Vec3 > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< Vec3 >{ findShader( I, N )
				, expr::makeReflect3F( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return Vec3{ findShader( I, N )
			, expr::makeReflect3F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< Vec4 > reflect( MaybeOptional< Vec4 > const & I
		, MaybeOptional< Vec4 > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< Vec4 >{ findShader( I, N )
				, expr::makeReflect4F( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return Vec4{ findShader( I, N )
			, expr::makeReflect4F( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< Double > reflect( MaybeOptional< Float > const & I
		, MaybeOptional< Double > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< Double >{ findShader( I, N )
				, expr::makeReflect1D( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return Double{ findShader( I, N )
			, expr::makeReflect1D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< DVec2 > reflect( MaybeOptional< DVec2 > const & I
		, MaybeOptional< DVec2 > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< DVec2 >{ findShader( I, N )
				, expr::makeReflect2D( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return DVec2{ findShader( I, N )
			, expr::makeReflect2D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< DVec3 > reflect( MaybeOptional< DVec3 > const & I
		, MaybeOptional< DVec3 > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< DVec3 >{ findShader( I, N )
				, expr::makeReflect3D( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return DVec3{ findShader( I, N )
			, expr::makeReflect3D( findTypesCache( I, N )
					, makeExpr( I )
				, makeExpr( N ) ) };
	}
	MaybeOptional< DVec4 > reflect( MaybeOptional< DVec4 > const & I
		, MaybeOptional< DVec4 > const & N )
	{
		if ( isAnyOptional( I, N ) )
		{
			return Optional< DVec4 >{ findShader( I, N )
				, expr::makeReflect4D( findTypesCache( I, N )
					, makeExpr( I )
					, makeExpr( N ) )
				, areOptionalEnabled( I, N ) };
		}

		return DVec4{ findShader( I, N )
			, expr::makeReflect4D( findTypesCache( I, N )
					, makeExpr( I )
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
	MaybeOptional< Float > refract( MaybeOptional< Float > const & I
		, MaybeOptional< Float > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< Float >{ findShader( I, N, eta )
				, expr::makeRefract1F( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return Float{ findShader( I, N, eta )
			, expr::makeRefract1F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< Vec2 > refract( MaybeOptional< Vec2 > const & I
		, MaybeOptional< Vec2 > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< Vec2 >{ findShader( I, N, eta )
				, expr::makeRefract2F( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return Vec2{ findShader( I, N, eta )
			, expr::makeRefract2F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< Vec3 > refract( MaybeOptional< Vec3 > const & I
		, MaybeOptional< Vec3 > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< Vec3 >{ findShader( I, N, eta )
				, expr::makeRefract3F( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return Vec3{ findShader( I, N, eta )
			, expr::makeRefract3F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< Vec4 > refract( MaybeOptional< Vec4 > const & I
		, MaybeOptional< Vec4 > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< Vec4 >{ findShader( I, N, eta )
				, expr::makeRefract4F( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return Vec4{ findShader( I, N, eta )
			, expr::makeRefract4F( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< Double > refract( MaybeOptional< Double > const & I
		, MaybeOptional< Double > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< Double >{ findShader( I, N, eta )
				, expr::makeRefract1D( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return Double{ findShader( I, N, eta )
			, expr::makeRefract1D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< DVec2 > refract( MaybeOptional< DVec2 > const & I
		, MaybeOptional< DVec2 > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< DVec2 >{ findShader( I, N, eta )
				, expr::makeRefract2D( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return DVec2{ findShader( I, N, eta )
			, expr::makeRefract2D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< DVec3 > refract( MaybeOptional< DVec3 > const & I
		, MaybeOptional< DVec3 > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< DVec3 >{ findShader( I, N, eta )
				, expr::makeRefract3D( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return DVec3{ findShader( I, N, eta )
			, expr::makeRefract3D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	MaybeOptional< DVec4 > refract( MaybeOptional< DVec4 > const & I
		, MaybeOptional< DVec4 > const & N
		, MaybeOptional< Float > const & eta )
	{
		if ( isAnyOptional( I, N, eta ) )
		{
			return Optional< DVec4 >{ findShader( I, N, eta )
				, expr::makeRefract4D( findTypesCache( I, N, eta )
					, makeExpr( I )
					, makeExpr( N )
					, makeExpr( eta ) )
				, areOptionalEnabled( I, N, eta ) };
		}

		return DVec4{ findShader( I, N, eta )
			, expr::makeRefract4D( findTypesCache( I, N, eta )
					, makeExpr( I )
				, makeExpr( N )
				, makeExpr( eta ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region matrixCompMult
	/**
	*name
	*	matrixCompMult
	*/
	/**@{*/
	MaybeOptional< Mat2 > matrixCompMult( MaybeOptional< Mat2 > const & x
		, MaybeOptional< Mat2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat2 >{ findShader( x, y )
				, expr::makeMatrixCompMult2x2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat2{ findShader( x, y )
			, expr::makeMatrixCompMult2x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat2x3 > matrixCompMult( MaybeOptional< Mat2x3 > const & x
		, MaybeOptional< Mat2x3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat2x3 >{ findShader( x, y )
				, expr::makeMatrixCompMult2x3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat2x3{ findShader( x, y )
			, expr::makeMatrixCompMult2x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat2x4 > matrixCompMult( MaybeOptional< Mat2x4 > const & x
		, MaybeOptional< Mat2x4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat2x4 >{ findShader( x, y )
				, expr::makeMatrixCompMult2x4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat2x4{ findShader( x, y )
			, expr::makeMatrixCompMult2x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat3x2 > matrixCompMult( MaybeOptional< Mat3x2 > const & x
		, MaybeOptional< Mat3x2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat3x2 >{ findShader( x, y )
				, expr::makeMatrixCompMult3x2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat3x2{ findShader( x, y )
			, expr::makeMatrixCompMult3x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat3 > matrixCompMult( MaybeOptional< Mat3 > const & x
		, MaybeOptional< Mat3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat3 >{ findShader( x, y )
				, expr::makeMatrixCompMult3x3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat3{ findShader( x, y )
			, expr::makeMatrixCompMult3x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat3x4 > matrixCompMult( MaybeOptional< Mat3x4 > const & x
		, MaybeOptional< Mat3x4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat3x4 >{ findShader( x, y )
				, expr::makeMatrixCompMult3x4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat3x4{ findShader( x, y )
			, expr::makeMatrixCompMult3x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat4x2 > matrixCompMult( MaybeOptional< Mat4x2 > const & x
		, MaybeOptional< Mat4x2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat4x2 >{ findShader( x, y )
				, expr::makeMatrixCompMult4x2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat4x2{ findShader( x, y )
			, expr::makeMatrixCompMult4x2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat4x3 > matrixCompMult( MaybeOptional< Mat4x3 > const & x
		, MaybeOptional< Mat4x3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat4x3 >{ findShader( x, y )
				, expr::makeMatrixCompMult4x3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat4x3{ findShader( x, y )
			, expr::makeMatrixCompMult4x3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< Mat4 > matrixCompMult( MaybeOptional< Mat4 > const & x
		, MaybeOptional< Mat4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< Mat4 >{ findShader( x, y )
				, expr::makeMatrixCompMult4x4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return Mat4{ findShader( x, y )
			, expr::makeMatrixCompMult4x4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat2 > matrixCompMult( MaybeOptional< DMat2 > const & x
		, MaybeOptional< DMat2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat2 >{ findShader( x, y )
				, expr::makeMatrixCompMult2x2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat2{ findShader( x, y )
			, expr::makeMatrixCompMult2x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat2x3 > matrixCompMult( MaybeOptional< DMat2x3 > const & x
		, MaybeOptional< DMat2x3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat2x3 >{ findShader( x, y )
				, expr::makeMatrixCompMult2x3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat2x3{ findShader( x, y )
			, expr::makeMatrixCompMult2x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat2x4 > matrixCompMult( MaybeOptional< DMat2x4 > const & x
		, MaybeOptional< DMat2x4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat2x4 >{ findShader( x, y )
				, expr::makeMatrixCompMult2x4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat2x4{ findShader( x, y )
			, expr::makeMatrixCompMult2x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat3x2 > matrixCompMult( MaybeOptional< DMat3x2 > const & x
		, MaybeOptional< DMat3x2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat3x2 >{ findShader( x, y )
				, expr::makeMatrixCompMult3x2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat3x2{ findShader( x, y )
			, expr::makeMatrixCompMult3x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat3 > matrixCompMult( MaybeOptional< DMat3 > const & x
		, MaybeOptional< DMat3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat3 >{ findShader( x, y )
				, expr::makeMatrixCompMult3x3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat3{ findShader( x, y )
			, expr::makeMatrixCompMult3x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat3x4 > matrixCompMult( MaybeOptional< DMat3x4 > const & x
		, MaybeOptional< DMat3x4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat3x4 >{ findShader( x, y )
				, expr::makeMatrixCompMult3x4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat3x4{ findShader( x, y )
			, expr::makeMatrixCompMult3x4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat4x2 > matrixCompMult( MaybeOptional< DMat4x2 > const & x
		, MaybeOptional< DMat4x2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat4x2 >{ findShader( x, y )
				, expr::makeMatrixCompMult4x2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat4x2{ findShader( x, y )
			, expr::makeMatrixCompMult4x2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat4x3 > matrixCompMult( MaybeOptional< DMat4x3 > const & x
		, MaybeOptional< DMat4x3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat4x3 >{ findShader( x, y )
				, expr::makeMatrixCompMult4x3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat4x3{ findShader( x, y )
			, expr::makeMatrixCompMult4x3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< DMat4 > matrixCompMult( MaybeOptional< DMat4 > const & x
		, MaybeOptional< DMat4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< DMat4 >{ findShader( x, y )
				, expr::makeMatrixCompMult4x4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return DMat4{ findShader( x, y )
			, expr::makeMatrixCompMult4x4D( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Mat2 > outerProduct( MaybeOptional< Vec2 > const & c
		, MaybeOptional< Vec2 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat2 >{ findShader( c, r )
				, expr::makeOuterProduct2x2F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat2{ findShader( c, r )
			, expr::makeOuterProduct2x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat3 > outerProduct( MaybeOptional< Vec3 > const & c
		, MaybeOptional< Vec3 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat3 >{ findShader( c, r )
				, expr::makeOuterProduct3x3F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat3{ findShader( c, r )
			, expr::makeOuterProduct3x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat4 > outerProduct( MaybeOptional< Vec4 > const & c
		, MaybeOptional< Vec4 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat4 >{ findShader( c, r )
				, expr::makeOuterProduct4x4F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat4{ findShader( c, r )
			, expr::makeOuterProduct4x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat2x3 > outerProduct( MaybeOptional< Vec3 > const & c
		, MaybeOptional< Vec2 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat2x3 >{ findShader( c, r )
				, expr::makeOuterProduct3x2F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat2x3{ findShader( c, r )
			, expr::makeOuterProduct3x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat3x2 > outerProduct( MaybeOptional< Vec2 > const & c
		, MaybeOptional< Vec3 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat3x2 >{ findShader( c, r )
				, expr::makeOuterProduct2x3F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat3x2{ findShader( c, r )
			, expr::makeOuterProduct2x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat2x4 > outerProduct( MaybeOptional< Vec4 > const & c
		, MaybeOptional< Vec2 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat2x4 >{ findShader( c, r )
				, expr::makeOuterProduct4x2F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat2x4{ findShader( c, r )
			, expr::makeOuterProduct4x2F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat4x2 > outerProduct( MaybeOptional< Vec2 > const & c
		, MaybeOptional< Vec4 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat4x2 >{ findShader( c, r )
				, expr::makeOuterProduct2x4F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat4x2{ findShader( c, r )
			, expr::makeOuterProduct2x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat3x4 > outerProduct( MaybeOptional< Vec4 > const & c
		, MaybeOptional< Vec3 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat3x4 >{ findShader( c, r )
				, expr::makeOuterProduct4x3F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat3x4{ findShader( c, r )
			, expr::makeOuterProduct4x3F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< Mat4x3 > outerProduct( MaybeOptional< Vec3 > const & c
		, MaybeOptional< Vec4 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< Mat4x3 >{ findShader( c, r )
				, expr::makeOuterProduct3x4F( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return Mat4x3{ findShader( c, r )
			, expr::makeOuterProduct3x4F( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat2 > outerProduct( MaybeOptional< DVec2 > const & c
		, MaybeOptional< DVec2 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat2 >{ findShader( c, r )
				, expr::makeOuterProduct2x2D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat2{ findShader( c, r )
			, expr::makeOuterProduct2x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat3 > outerProduct( MaybeOptional< DVec3 > const & c
		, MaybeOptional< DVec3 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat3 >{ findShader( c, r )
				, expr::makeOuterProduct3x3D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat3{ findShader( c, r )
			, expr::makeOuterProduct3x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat4 > outerProduct( MaybeOptional< DVec4 > const & c
		, MaybeOptional< DVec4 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat4 >{ findShader( c, r )
				, expr::makeOuterProduct4x4D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat4{ findShader( c, r )
			, expr::makeOuterProduct4x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat2x3 > outerProduct( MaybeOptional< DVec3 > const & c
		, MaybeOptional< DVec2 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat2x3 >{ findShader( c, r )
				, expr::makeOuterProduct3x2D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat2x3{ findShader( c, r )
			, expr::makeOuterProduct3x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat3x2 > outerProduct( MaybeOptional< DVec2 > const & c
		, MaybeOptional< DVec3 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat3x2 >{ findShader( c, r )
				, expr::makeOuterProduct2x3D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat3x2{ findShader( c, r )
			, expr::makeOuterProduct2x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat2x4 > outerProduct( MaybeOptional< DVec4 > const & c
		, MaybeOptional< DVec2 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat2x4 >{ findShader( c, r )
				, expr::makeOuterProduct4x2D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat2x4{ findShader( c, r )
			, expr::makeOuterProduct4x2D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat4x2 > outerProduct( MaybeOptional< DVec2 > const & c
		, MaybeOptional< DVec4 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat4x2 >{ findShader( c, r )
				, expr::makeOuterProduct2x4D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat4x2{ findShader( c, r )
			, expr::makeOuterProduct2x4D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat3x4 > outerProduct( MaybeOptional< DVec4 > const & c
		, MaybeOptional< DVec3 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat3x4 >{ findShader( c, r )
				, expr::makeOuterProduct4x3D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat3x4{ findShader( c, r )
			, expr::makeOuterProduct4x3D( findTypesCache( c, r )
					, makeExpr( c )
				, makeExpr( r ) ) };
	}
	MaybeOptional< DMat4x3 > outerProduct( MaybeOptional< DVec3 > const & c
		, MaybeOptional< DVec4 > const & r )
	{
		if ( isAnyOptional( c, r ) )
		{
			return Optional< DMat4x3 >{ findShader( c, r )
				, expr::makeOuterProduct3x4D( findTypesCache( c, r )
					, makeExpr( c )
					, makeExpr( r ) )
				, areOptionalEnabled( c, r ) };
		}

		return DMat4x3{ findShader( c, r )
			, expr::makeOuterProduct3x4D( findTypesCache( c, r )
					, makeExpr( c )
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
	MaybeOptional< Mat2 > transpose( MaybeOptional< Mat2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat2 >{ findShader( x )
				, expr::makeTranspose2x2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat2{ findShader( x )
			, expr::makeTranspose2x2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat3x2 > transpose( MaybeOptional< Mat2x3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat3x2 >{ findShader( x )
				, expr::makeTranspose2x3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat3x2{ findShader( x )
			, expr::makeTranspose2x3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat4x2 > transpose( MaybeOptional< Mat2x4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat4x2 >{ findShader( x )
				, expr::makeTranspose2x4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat4x2{ findShader( x )
			, expr::makeTranspose2x4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat2x3 > transpose( MaybeOptional< Mat3x2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat2x3 >{ findShader( x )
				, expr::makeTranspose3x2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat2x3{ findShader( x )
			, expr::makeTranspose3x2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat3 > transpose( MaybeOptional< Mat3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat3 >{ findShader( x )
				, expr::makeTranspose3x3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat3{ findShader( x )
			, expr::makeTranspose3x3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat4x3 > transpose( MaybeOptional< Mat3x4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat4x3 >{ findShader( x )
				, expr::makeTranspose3x4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat4x3{ findShader( x )
			, expr::makeTranspose3x4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat2x4 > transpose( MaybeOptional< Mat4x2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat2x4 >{ findShader( x )
				, expr::makeTranspose4x2F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat2x4{ findShader( x )
			, expr::makeTranspose4x2F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat3x4 > transpose( MaybeOptional< Mat4x3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat3x4 >{ findShader( x )
				, expr::makeTranspose4x3F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat3x4{ findShader( x )
			, expr::makeTranspose4x3F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Mat4 > transpose( MaybeOptional< Mat4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Mat4 >{ findShader( x )
				, expr::makeTranspose4x4F( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Mat4{ findShader( x )
			, expr::makeTranspose4x4F( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat2 > transpose( MaybeOptional< DMat2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat2 >{ findShader( x )
				, expr::makeTranspose2x2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat2{ findShader( x )
			, expr::makeTranspose2x2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat3x2 > transpose( MaybeOptional< DMat2x3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat3x2 >{ findShader( x )
				, expr::makeTranspose2x3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat3x2{ findShader( x )
			, expr::makeTranspose2x3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat4x2 > transpose( MaybeOptional< DMat2x4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat4x2 >{ findShader( x )
				, expr::makeTranspose2x4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat4x2{ findShader( x )
			, expr::makeTranspose2x4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat2x3 > transpose( MaybeOptional< DMat3x2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat2x3 >{ findShader( x )
				, expr::makeTranspose3x2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat2x3{ findShader( x )
			, expr::makeTranspose3x2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat3 > transpose( MaybeOptional< DMat3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat3 >{ findShader( x )
				, expr::makeTranspose3x3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat3{ findShader( x )
			, expr::makeTranspose3x3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat4x3 > transpose( MaybeOptional< DMat3x4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat4x3 >{ findShader( x )
				, expr::makeTranspose3x4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat4x3{ findShader( x )
			, expr::makeTranspose3x4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat2x4 > transpose( MaybeOptional< DMat4x2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat2x4 >{ findShader( x )
				, expr::makeTranspose4x2D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat2x4{ findShader( x )
			, expr::makeTranspose4x2D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat3x4 > transpose( MaybeOptional< DMat4x3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat3x4 >{ findShader( x )
				, expr::makeTranspose4x3D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat3x4{ findShader( x )
			, expr::makeTranspose4x3D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< DMat4 > transpose( MaybeOptional< DMat4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< DMat4 >{ findShader( x )
				, expr::makeTranspose4x4D( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return DMat4{ findShader( x )
			, expr::makeTranspose4x4D( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region determinant
	/**
	*name
	*	determinant
	*/
	/**@{*/
	MaybeOptional< Float > determinant( MaybeOptional< Mat2 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Float >{ findShader( m )
				, expr::makeDeterminant2x2F( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Float{ findShader( m )
			, expr::makeDeterminant2x2F( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Float > determinant( MaybeOptional< Mat3 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Float >{ findShader( m )
				, expr::makeDeterminant3x3F( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Float{ findShader( m )
			, expr::makeDeterminant3x3F( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Float > determinant( MaybeOptional< Mat4 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Float >{ findShader( m )
				, expr::makeDeterminant4x4F( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Float{ findShader( m )
			, expr::makeDeterminant4x4F( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Double > determinant( MaybeOptional< DMat2 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Double >{ findShader( m )
				, expr::makeDeterminant2x2D( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Double{ findShader( m )
			, expr::makeDeterminant2x2D( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Double > determinant( MaybeOptional< DMat3 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Double >{ findShader( m )
				, expr::makeDeterminant3x3D( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Double{ findShader( m )
			, expr::makeDeterminant3x3D( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Double > determinant( MaybeOptional< DMat4 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Double >{ findShader( m )
				, expr::makeDeterminant4x4D( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Double{ findShader( m )
			, expr::makeDeterminant4x4D( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region inverse
	/**
	*name
	*	inverse
	*/
	/**@{*/
	MaybeOptional< Mat2 > inverse( MaybeOptional< Mat2 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Mat2 >{ findShader( m )
				, expr::makeInverse2x2F( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Mat2{ findShader( m )
			, expr::makeInverse2x2F( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Mat3 > inverse( MaybeOptional< Mat3 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Mat3 >{ findShader( m )
				, expr::makeInverse3x3F( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Mat3{ findShader( m )
			, expr::makeInverse3x3F( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< Mat4 > inverse( MaybeOptional< Mat4 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< Mat4 >{ findShader( m )
				, expr::makeInverse4x4F( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return Mat4{ findShader( m )
			, expr::makeInverse4x4F( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< DMat2 > inverse( MaybeOptional< DMat2 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< DMat2 >{ findShader( m )
				, expr::makeInverse2x2D( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return DMat2{ findShader( m )
			, expr::makeInverse2x2D( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< DMat3 > inverse( MaybeOptional< DMat3 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< DMat3 >{ findShader( m )
				, expr::makeInverse3x3D( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return DMat3{ findShader( m )
			, expr::makeInverse3x3D( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	MaybeOptional< DMat4 > inverse( MaybeOptional< DMat4 > const & m )
	{
		if ( isAnyOptional( m ) )
		{
			return Optional< DMat4 >{ findShader( m )
				, expr::makeInverse4x4D( findTypesCache( m )
					, makeExpr( m ) )
				, areOptionalEnabled( m ) };
		}

		return DMat4{ findShader( m )
			, expr::makeInverse4x4D( findTypesCache( m )
					, makeExpr( m ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region lessThan
	/**
	*name
	*	lessThan
	*/
	/**@{*/
	MaybeOptional< BVec2 > lessThan( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThan2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThan2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThan( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThan3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThan3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThan( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThan4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThan4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > lessThan( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThan2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThan2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThan( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThan3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThan3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThan( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThan4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThan4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > lessThan( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThan2I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThan2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThan( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThan3I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThan3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThan( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThan4I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThan4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > lessThan( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThan2U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThan2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThan( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThan3U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThan3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThan( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThan4U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThan4U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > lessThanEqual( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeLessThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeLessThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > lessThanEqual( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeLessThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeLessThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > lessThanEqual( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeLessThanEqual4U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeLessThanEqual4U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< BVec2 > greaterThan( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThan2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThan( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThan3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThan( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThan4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > greaterThan( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThan2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThan( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThan3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThan( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThan4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > greaterThan( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThan2I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThan( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThan3I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThan( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThan4I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > greaterThan( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThan2U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThan2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThan( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThan3U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThan3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThan( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThan4U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThan4U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > greaterThanEqual( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeGreaterThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeGreaterThanEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > greaterThanEqual( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeGreaterThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeGreaterThanEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > greaterThanEqual( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeGreaterThanEqual4U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeGreaterThanEqual4U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< BVec2 > equal( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeEqual2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > equal( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeEqual3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > equal( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeEqual4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > equal( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeEqual2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > equal( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeEqual3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > equal( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeEqual4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > equal( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeEqual2I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > equal( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeEqual3I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > equal( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeEqual4I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > equal( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeEqual2U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > equal( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeEqual3U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > equal( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeEqual4U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeEqual4U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< BVec2 > notEqual( MaybeOptional< Vec2 > const & x
		, MaybeOptional< Vec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeNotEqual2F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > notEqual( MaybeOptional< Vec3 > const & x
		, MaybeOptional< Vec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeNotEqual3F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > notEqual( MaybeOptional< Vec4 > const & x
		, MaybeOptional< Vec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeNotEqual4F( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4F( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > notEqual( MaybeOptional< DVec2 > const & x
		, MaybeOptional< DVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeNotEqual2D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > notEqual( MaybeOptional< DVec3 > const & x
		, MaybeOptional< DVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeNotEqual3D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > notEqual( MaybeOptional< DVec4 > const & x
		, MaybeOptional< DVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeNotEqual4D( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4D( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > notEqual( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeNotEqual2I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > notEqual( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeNotEqual3I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > notEqual( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeNotEqual4I( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4I( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec2 > notEqual( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec2 >{ findShader( x, y )
				, expr::makeNotEqual2U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec2{ findShader( x, y )
			, expr::makeNotEqual2U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec3 > notEqual( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec3 >{ findShader( x, y )
				, expr::makeNotEqual3U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec3{ findShader( x, y )
			, expr::makeNotEqual3U( findTypesCache( x, y )
					, makeExpr( x )
				, makeExpr( y ) ) };
	}
	MaybeOptional< BVec4 > notEqual( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y )
	{
		if ( isAnyOptional( x, y ) )
		{
			return Optional< BVec4 >{ findShader( x, y )
				, expr::makeNotEqual4U( findTypesCache( x, y )
					, makeExpr( x )
					, makeExpr( y ) )
				, areOptionalEnabled( x, y ) };
		}

		return BVec4{ findShader( x, y )
			, expr::makeNotEqual4U( findTypesCache( x, y )
					, makeExpr( x )
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
	MaybeOptional< Bool > all( MaybeOptional< BVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeAll2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeAll2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Bool > all( MaybeOptional< BVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeAll3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeAll3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Bool > all( MaybeOptional< BVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeAll4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeAll4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region any
	/**
	*name
	*	any
	*/
	/**@{*/
	MaybeOptional< Bool > any( MaybeOptional< BVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeAny2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeAny2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Bool > any( MaybeOptional< BVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeAny3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeAny3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Bool > any( MaybeOptional< BVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Bool >{ findShader( x )
				, expr::makeAny4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Bool{ findShader( x )
			, expr::makeAny4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region binNot
	/**
	*name
	*	binNot
	*/
	/**@{*/
	MaybeOptional< BVec2 > binNot( MaybeOptional< BVec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec2 >{ findShader( x )
				, expr::makeNot2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec2{ findShader( x )
			, expr::makeNot2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec3 > binNot( MaybeOptional< BVec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec3 >{ findShader( x )
				, expr::makeNot3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec3{ findShader( x )
			, expr::makeNot3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< BVec4 > binNot( MaybeOptional< BVec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< BVec4 >{ findShader( x )
				, expr::makeNot4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return BVec4{ findShader( x )
			, expr::makeNot4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region uaddCarry
	/**
	*name
	*	uaddCarry
	*/
	/**@{*/
	MaybeOptional< UInt > uaddCarry( MaybeOptional< UInt > const & x
		, MaybeOptional< UInt > const & y
		, MaybeOptional< UInt > const & carry )
	{
		if ( isAnyOptional( x, y, carry ) )
		{
			return Optional< UInt >{ findShader( x, y, carry )
				, expr::makeUaddCarry1( findTypesCache( x, y, carry )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( carry ) )
				, areOptionalEnabled( x, y, carry ) };
		}

		return UInt{ findShader( x, y, carry )
			, expr::makeUaddCarry1( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	MaybeOptional< UVec2 > uaddCarry( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y
		, MaybeOptional< UVec2 > const & carry )
	{
		if ( isAnyOptional( x, y, carry ) )
		{
			return Optional< UVec2 >{ findShader( x, y, carry )
				, expr::makeUaddCarry2( findTypesCache( x, y, carry )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( carry ) )
				, areOptionalEnabled( x, y, carry ) };
		}

		return UVec2{ findShader( x, y, carry )
			, expr::makeUaddCarry2( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	MaybeOptional< UVec3 > uaddCarry( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y
		, MaybeOptional< UVec3 > const & carry )
	{
		if ( isAnyOptional( x, y, carry ) )
		{
			return Optional< UVec3 >{ findShader( x, y, carry )
				, expr::makeUaddCarry3( findTypesCache( x, y, carry )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( carry ) )
				, areOptionalEnabled( x, y, carry ) };
		}

		return UVec3{ findShader( x, y, carry )
			, expr::makeUaddCarry3( findTypesCache( x, y, carry )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( carry ) ) };
	}
	MaybeOptional< UVec4 > uaddCarry( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y
		, MaybeOptional< UVec4 > const & carry )
	{
		if ( isAnyOptional( x, y, carry ) )
		{
			return Optional< UVec4 >{ findShader( x, y, carry )
				, expr::makeUaddCarry4( findTypesCache( x, y, carry )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( carry ) )
				, areOptionalEnabled( x, y, carry ) };
		}

		return UVec4{ findShader( x, y, carry )
			, expr::makeUaddCarry4( findTypesCache( x, y, carry )
					, makeExpr( x )
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
	MaybeOptional< UInt > usubBorrow( MaybeOptional< UInt > const & x
		, MaybeOptional< UInt > const & y
		, MaybeOptional< UInt > const & borrow )
	{
		if ( isAnyOptional( x, y, borrow ) )
		{
			return Optional< UInt >{ findShader( x, y, borrow )
				, expr::makeUsubBorrow1( findTypesCache( x, y, borrow )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( borrow ) )
				, areOptionalEnabled( x, y, borrow ) };
		}

		return UInt{ findShader( x, y, borrow )
			, expr::makeUsubBorrow1( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	MaybeOptional< UVec2 > usubBorrow( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y
		, MaybeOptional< UVec2 > const & borrow )
	{
		if ( isAnyOptional( x, y, borrow ) )
		{
			return Optional< UVec2 >{ findShader( x, y, borrow )
				, expr::makeUsubBorrow2( findTypesCache( x, y, borrow )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( borrow ) )
				, areOptionalEnabled( x, y, borrow ) };
		}

		return UVec2{ findShader( x, y, borrow )
			, expr::makeUsubBorrow2( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	MaybeOptional< UVec3 > usubBorrow( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y
		, MaybeOptional< UVec3 > const & borrow )
	{
		if ( isAnyOptional( x, y, borrow ) )
		{
			return Optional< UVec3 >{ findShader( x, y, borrow )
				, expr::makeUsubBorrow3( findTypesCache( x, y, borrow )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( borrow ) )
				, areOptionalEnabled( x, y, borrow ) };
		}

		return UVec3{ findShader( x, y, borrow )
			, expr::makeUsubBorrow3( findTypesCache( x, y, borrow )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( borrow ) ) };
	}
	MaybeOptional< UVec4 > usubBorrow( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y
		, MaybeOptional< UVec4 > const & borrow )
	{
		if ( isAnyOptional( x, y, borrow ) )
		{
			return Optional< UVec4 >{ findShader( x, y, borrow )
				, expr::makeUsubBorrow4( findTypesCache( x, y, borrow )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( borrow ) )
				, areOptionalEnabled( x, y, borrow ) };
		}

		return UVec4{ findShader( x, y, borrow )
			, expr::makeUsubBorrow4( findTypesCache( x, y, borrow )
					, makeExpr( x )
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
	MaybeOptional< Void > umulExtended( MaybeOptional< UInt > const & x
		, MaybeOptional< UInt > const & y
		, MaybeOptional< UInt > const & msb
		, MaybeOptional< UInt > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeUmulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	MaybeOptional< Void > umulExtended( MaybeOptional< UVec2 > const & x
		, MaybeOptional< UVec2 > const & y
		, MaybeOptional< UVec2 > const & msb
		, MaybeOptional< UVec2 > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeUmulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	MaybeOptional< Void > umulExtended( MaybeOptional< UVec3 > const & x
		, MaybeOptional< UVec3 > const & y
		, MaybeOptional< UVec3 > const & msb
		, MaybeOptional< UVec3 > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeUmulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	MaybeOptional< Void > umulExtended( MaybeOptional< UVec4 > const & x
		, MaybeOptional< UVec4 > const & y
		, MaybeOptional< UVec4 > const & msb
		, MaybeOptional< UVec4 > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeUmulExtended4( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeUmulExtended4( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
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
	MaybeOptional< Void > imulExtended( MaybeOptional< Int > const & x
		, MaybeOptional< Int > const & y
		, MaybeOptional< Int > const & msb
		, MaybeOptional< Int > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeImulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended1( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	MaybeOptional< Void > imulExtended( MaybeOptional< IVec2 > const & x
		, MaybeOptional< IVec2 > const & y
		, MaybeOptional< IVec2 > const & msb
		, MaybeOptional< IVec2 > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeImulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended2( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	MaybeOptional< Void > imulExtended( MaybeOptional< IVec3 > const & x
		, MaybeOptional< IVec3 > const & y
		, MaybeOptional< IVec3 > const & msb
		, MaybeOptional< IVec3 > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeImulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended3( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
				, makeExpr( y )
				, makeExpr( msb )
				, makeExpr( lsb ) ) };
	}
	MaybeOptional< Void > imulExtended( MaybeOptional< IVec4 > const & x
		, MaybeOptional< IVec4 > const & y
		, MaybeOptional< IVec4 > const & msb
		, MaybeOptional< IVec4 > const & lsb )
	{
		if ( isAnyOptional( x, y, msb, lsb ) )
		{
			return Optional< Void >{ findShader( x, y, msb, lsb )
				, expr::makeImulExtended4( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
					, makeExpr( y )
					, makeExpr( msb )
					, makeExpr( lsb ) )
				, areOptionalEnabled( x, y, msb, lsb ) };
		}

		return Void{ findShader( x, y, msb, lsb )
			, expr::makeImulExtended4( findTypesCache( x, y, msb, lsb )
					, makeExpr( x )
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
	MaybeOptional< Int > bitfieldExtract( MaybeOptional< Int > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< Int >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract1I( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return Int{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract1I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< IVec2 > bitfieldExtract( MaybeOptional< IVec2 > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< IVec2 >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract2I( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return IVec2{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract2I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< IVec3 > bitfieldExtract( MaybeOptional< IVec3 > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< IVec3 >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract3I( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return IVec3{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract3I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< IVec4 > bitfieldExtract( MaybeOptional< IVec4 > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< IVec4 >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract4I( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return IVec4{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract4I( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UInt > bitfieldExtract( MaybeOptional< UInt > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< UInt >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract1U( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return UInt{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract1U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UVec2 > bitfieldExtract( MaybeOptional< UVec2 > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< UVec2 >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract2U( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return UVec2{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract2U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UVec3 > bitfieldExtract( MaybeOptional< UVec3 > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< UVec3 >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract3U( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return UVec3{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract3U( findTypesCache( value, offset, bits )
					, makeExpr( value )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UVec4 > bitfieldExtract( MaybeOptional< UVec4 > const & value
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( value, offset, bits ) )
		{
			return Optional< UVec4 >{ findShader( value, offset, bits )
				, expr::makeBitfieldExtract4U( findTypesCache( value, offset, bits )
					, makeExpr( value )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( value, offset, bits ) };
		}

		return UVec4{ findShader( value, offset, bits )
			, expr::makeBitfieldExtract4U( findTypesCache( value, offset, bits )
					, makeExpr( value )
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
	MaybeOptional< Int > bitfieldInsert( MaybeOptional< Int > const & base
		, MaybeOptional< Int > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< Int >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert1I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return Int{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert1I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< IVec2 > bitfieldInsert( MaybeOptional< IVec2 > const & base
		, MaybeOptional< IVec2 > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< IVec2 >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert2I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return IVec2{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert2I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< IVec3 > bitfieldInsert( MaybeOptional< IVec3 > const & base
		, MaybeOptional< IVec3 > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< IVec3 >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert3I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return IVec3{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert3I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< IVec4 > bitfieldInsert( MaybeOptional< IVec4 > const & base
		, MaybeOptional< IVec4 > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< IVec4 >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert4I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return IVec4{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert4I( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UInt > bitfieldInsert( MaybeOptional< UInt > const & base
		, MaybeOptional< UInt > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< UInt >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert1U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return UInt{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert1U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UVec2 > bitfieldInsert( MaybeOptional< UVec2 > const & base
		, MaybeOptional< UVec2 > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< UVec2 >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert2U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return UVec2{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert2U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UVec3 > bitfieldInsert( MaybeOptional< UVec3 > const & base
		, MaybeOptional< UVec3 > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< UVec3 >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert3U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return UVec3{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert3U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
				, makeExpr( insert )
				, makeExpr( offset )
				, makeExpr( bits ) ) };
	}
	MaybeOptional< UVec4 > bitfieldInsert( MaybeOptional< UVec4 > const & base
		, MaybeOptional< UVec4 > const & insert
		, MaybeOptional< Int > const & offset
		, MaybeOptional< Int > const & bits )
	{
		if ( isAnyOptional( base, insert, offset, bits ) )
		{
			return Optional< UVec4 >{ findShader( base, insert, offset, bits )
				, expr::makeBitfieldInsert4U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
					, makeExpr( insert )
					, makeExpr( offset )
					, makeExpr( bits ) )
				, areOptionalEnabled( base, insert, offset, bits ) };
		}

		return UVec4{ findShader( base, insert, offset, bits )
			, expr::makeBitfieldInsert4U( findTypesCache( base, insert, offset, bits )
					, makeExpr( base )
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
	MaybeOptional< Int > bitfieldReverse( MaybeOptional< Int > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeBitfieldReverse1I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeBitfieldReverse1I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > bitfieldReverse( MaybeOptional< IVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeBitfieldReverse2I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeBitfieldReverse2I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > bitfieldReverse( MaybeOptional< IVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeBitfieldReverse3I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeBitfieldReverse3I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > bitfieldReverse( MaybeOptional< IVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeBitfieldReverse4I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeBitfieldReverse4I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UInt > bitfieldReverse( MaybeOptional< UInt > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UInt >{ findShader( value )
				, expr::makeBitfieldReverse1U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UInt{ findShader( value )
			, expr::makeBitfieldReverse1U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec2 > bitfieldReverse( MaybeOptional< UVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec2 >{ findShader( value )
				, expr::makeBitfieldReverse2U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec2{ findShader( value )
			, expr::makeBitfieldReverse2U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec3 > bitfieldReverse( MaybeOptional< UVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec3 >{ findShader( value )
				, expr::makeBitfieldReverse3U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec3{ findShader( value )
			, expr::makeBitfieldReverse3U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec4 > bitfieldReverse( MaybeOptional< UVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec4 >{ findShader( value )
				, expr::makeBitfieldReverse4U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec4{ findShader( value )
			, expr::makeBitfieldReverse4U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region bitCount
	/**
	*name
	*	bitCount
	*/
	/**@{*/
	MaybeOptional< Int > bitCount( MaybeOptional< Int > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeBitCount1I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeBitCount1I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > bitCount( MaybeOptional< IVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeBitCount2I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeBitCount2I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > bitCount( MaybeOptional< IVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeBitCount3I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeBitCount3I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > bitCount( MaybeOptional< IVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeBitCount4I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeBitCount4I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UInt > bitCount( MaybeOptional< UInt > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UInt >{ findShader( value )
				, expr::makeBitCount1U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UInt{ findShader( value )
			, expr::makeBitCount1U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec2 > bitCount( MaybeOptional< UVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec2 >{ findShader( value )
				, expr::makeBitCount2U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec2{ findShader( value )
			, expr::makeBitCount2U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec3 > bitCount( MaybeOptional< UVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec3 >{ findShader( value )
				, expr::makeBitCount3U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec3{ findShader( value )
			, expr::makeBitCount3U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< UVec4 > bitCount( MaybeOptional< UVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< UVec4 >{ findShader( value )
				, expr::makeBitCount4U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return UVec4{ findShader( value )
			, expr::makeBitCount4U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region findLSB
	/**
	*name
	*	findLSB
	*/
	/**@{*/
	MaybeOptional< Int > findLSB( MaybeOptional< Int > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeFindLSB1I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeFindLSB1I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > findLSB( MaybeOptional< IVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeFindLSB2I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeFindLSB2I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > findLSB( MaybeOptional< IVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeFindLSB3I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeFindLSB3I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > findLSB( MaybeOptional< IVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeFindLSB4I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeFindLSB4I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< Int > findLSB( MaybeOptional< UInt > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeFindLSB1U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeFindLSB1U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > findLSB( MaybeOptional< UVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeFindLSB2U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeFindLSB2U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > findLSB( MaybeOptional< UVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeFindLSB3U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeFindLSB3U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > findLSB( MaybeOptional< UVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeFindLSB4U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeFindLSB4U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region findMSB
	/**
	*name
	*	findMSB
	*/
	/**@{*/
	MaybeOptional< Int > findMSB( MaybeOptional< Int > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeFindMSB1I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeFindMSB1I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > findMSB( MaybeOptional< IVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeFindMSB2I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeFindMSB2I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > findMSB( MaybeOptional< IVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeFindMSB3I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeFindMSB3I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > findMSB( MaybeOptional< IVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeFindMSB4I( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeFindMSB4I( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< Int > findMSB( MaybeOptional< UInt > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< Int >{ findShader( value )
				, expr::makeFindMSB1U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return Int{ findShader( value )
			, expr::makeFindMSB1U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec2 > findMSB( MaybeOptional< UVec2 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec2 >{ findShader( value )
				, expr::makeFindMSB2U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec2{ findShader( value )
			, expr::makeFindMSB2U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec3 > findMSB( MaybeOptional< UVec3 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec3 >{ findShader( value )
				, expr::makeFindMSB3U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec3{ findShader( value )
			, expr::makeFindMSB3U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	MaybeOptional< IVec4 > findMSB( MaybeOptional< UVec4 > const & value )
	{
		if ( isAnyOptional( value ) )
		{
			return Optional< IVec4 >{ findShader( value )
				, expr::makeFindMSB4U( findTypesCache( value )
					, makeExpr( value ) )
				, areOptionalEnabled( value ) };
		}

		return IVec4{ findShader( value )
			, expr::makeFindMSB4U( findTypesCache( value )
					, makeExpr( value ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region atomicAdd
	/**
	*name
	*	atomicAdd
	*/
	/**@{*/
	MaybeOptional< Int > atomicAdd( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicAddI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicAddI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicAdd( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicAddU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicAddU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicMin( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicMinI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicMinI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicMin( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicMinU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicMinU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicMax( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicMaxI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicMaxI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicMax( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicMaxU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicMaxU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicAnd( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicAndI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicAndI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicAnd( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicAndU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicAndU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicOr( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicOrI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicOrI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicOr( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicOrU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicOrU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicXor( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicXorI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicXorI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicXor( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicXorU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicXorU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicExchange( MaybeOptional< Int > const & mem
		, MaybeOptional< Int > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< Int >{ findShader( mem, data )
				, expr::makeAtomicExchangeI( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return Int{ findShader( mem, data )
			, expr::makeAtomicExchangeI( findTypesCache( mem, data )
					, makeExpr( mem )
				, makeExpr( data ) ) };
	}
	MaybeOptional< UInt > atomicExchange( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & data )
	{
		if ( isAnyOptional( mem, data ) )
		{
			return Optional< UInt >{ findShader( mem, data )
				, expr::makeAtomicExchangeU( findTypesCache( mem, data )
					, makeExpr( mem )
					, makeExpr( data ) )
				, areOptionalEnabled( mem, data ) };
		}

		return UInt{ findShader( mem, data )
			, expr::makeAtomicExchangeU( findTypesCache( mem, data )
					, makeExpr( mem )
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
	MaybeOptional< Int > atomicCompSwap( MaybeOptional< Int > const & mem
		, MaybeOptional< UInt > const & compare )
	{
		if ( isAnyOptional( mem, compare ) )
		{
			return Optional< Int >{ findShader( mem, compare )
				, expr::makeAtomicCompSwapI( findTypesCache( mem, compare )
					, makeExpr( mem )
					, makeExpr( compare ) )
				, areOptionalEnabled( mem, compare ) };
		}

		return Int{ findShader( mem, compare )
			, expr::makeAtomicCompSwapI( findTypesCache( mem, compare )
					, makeExpr( mem )
				, makeExpr( compare ) ) };
	}
	MaybeOptional< UInt > atomicCompSwap( MaybeOptional< UInt > const & mem
		, MaybeOptional< UInt > const & compare )
	{
		if ( isAnyOptional( mem, compare ) )
		{
			return Optional< UInt >{ findShader( mem, compare )
				, expr::makeAtomicCompSwapU( findTypesCache( mem, compare )
					, makeExpr( mem )
					, makeExpr( compare ) )
				, areOptionalEnabled( mem, compare ) };
		}

		return UInt{ findShader( mem, compare )
			, expr::makeAtomicCompSwapU( findTypesCache( mem, compare )
					, makeExpr( mem )
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
	MaybeOptional< Float > dFdx( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeDFdx1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeDFdx1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > dFdx( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeDFdx2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeDFdx2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > dFdx( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeDFdx3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeDFdx3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > dFdx( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeDFdx4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeDFdx4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdxCoarse
	/**
	*name
	*	dFdxCoarse
	*/
	/**@{*/
	MaybeOptional< Float > dFdxCoarse( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeDFdxCoarse1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeDFdxCoarse1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > dFdxCoarse( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeDFdxCoarse2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeDFdxCoarse2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > dFdxCoarse( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeDFdxCoarse3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeDFdxCoarse3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > dFdxCoarse( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeDFdxCoarse4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeDFdxCoarse4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdxFine
	/**
	*name
	*	dFdxFine
	*/
	/**@{*/
	MaybeOptional< Float > dFdxFine( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeDFdxFine1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeDFdxFine1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > dFdxFine( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeDFdxFine2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeDFdxFine2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > dFdxFine( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeDFdxFine3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeDFdxFine3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > dFdxFine( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeDFdxFine4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeDFdxFine4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdy
	/**
	*name
	*	dFdy
	*/
	/**@{*/
	MaybeOptional< Float > dFdy( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeDFdy1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeDFdy1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > dFdy( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeDFdy2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeDFdy2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > dFdy( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeDFdy3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeDFdy3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > dFdy( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeDFdy4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeDFdy4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdyCoarse
	/**
	*name
	*	dFdyCoarse
	*/
	/**@{*/
	MaybeOptional< Float > dFdyCoarse( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeDFdyCoarse1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeDFdyCoarse1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > dFdyCoarse( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeDFdyCoarse2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeDFdyCoarse2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > dFdyCoarse( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeDFdyCoarse3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeDFdyCoarse3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > dFdyCoarse( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeDFdyCoarse4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeDFdyCoarse4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region dFdyFine
	/**
	*name
	*	dFdyFine
	*/
	/**@{*/
	MaybeOptional< Float > dFdyFine( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeDFdyFine1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeDFdyFine1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > dFdyFine( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeDFdyFine2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeDFdyFine2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > dFdyFine( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeDFdyFine3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeDFdyFine3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > dFdyFine( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeDFdyFine4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeDFdyFine4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region fwidth
	/**
	*name
	*	fwidth
	*/
	/**@{*/
	MaybeOptional< Float > fwidth( MaybeOptional< Float > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Float >{ findShader( p )
				, expr::makeFwidth1( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Float{ findShader( p )
			, expr::makeFwidth1( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec2 > fwidth( MaybeOptional< Vec2 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec2 >{ findShader( p )
				, expr::makeFwidth2( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec2{ findShader( p )
			, expr::makeFwidth2( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec3 > fwidth( MaybeOptional< Vec3 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec3 >{ findShader( p )
				, expr::makeFwidth3( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec3{ findShader( p )
			, expr::makeFwidth3( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	MaybeOptional< Vec4 > fwidth( MaybeOptional< Vec4 > const & p )
	{
		if ( isAnyOptional( p ) )
		{
			return Optional< Vec4 >{ findShader( p )
				, expr::makeFwidth4( findTypesCache( p )
					, makeExpr( p ) )
				, areOptionalEnabled( p ) };
		}

		return Vec4{ findShader( p )
			, expr::makeFwidth4( findTypesCache( p )
					, makeExpr( p ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtCentroid
	/**
	*name
	*	interpolateAtCentroid
	*/
	/**@{*/
	MaybeOptional< Float > interpolateAtCentroid( MaybeOptional< Float > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Float >{ findShader( x )
				, expr::makeInterpolateAtCentroid1( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Float{ findShader( x )
			, expr::makeInterpolateAtCentroid1( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec2 > interpolateAtCentroid( MaybeOptional< Vec2 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec2 >{ findShader( x )
				, expr::makeInterpolateAtCentroid2( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec2{ findShader( x )
			, expr::makeInterpolateAtCentroid2( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec3 > interpolateAtCentroid( MaybeOptional< Vec3 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec3 >{ findShader( x )
				, expr::makeInterpolateAtCentroid3( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec3{ findShader( x )
			, expr::makeInterpolateAtCentroid3( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	MaybeOptional< Vec4 > interpolateAtCentroid( MaybeOptional< Vec4 > const & x )
	{
		if ( isAnyOptional( x ) )
		{
			return Optional< Vec4 >{ findShader( x )
				, expr::makeInterpolateAtCentroid4( findTypesCache( x )
					, makeExpr( x ) )
				, areOptionalEnabled( x ) };
		}

		return Vec4{ findShader( x )
			, expr::makeInterpolateAtCentroid4( findTypesCache( x )
					, makeExpr( x ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region interpolateAtSample
	/**
	*name
	*	interpolateAtSample
	*/
	/**@{*/
	MaybeOptional< Float > interpolateAtSample( MaybeOptional< Float > const & interpolant
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( interpolant, sample ) )
		{
			return Optional< Float >{ findShader( interpolant, sample )
				, expr::makeInterpolateAtSample1( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
					, makeExpr( sample ) )
				, areOptionalEnabled( interpolant, sample ) };
		}

		return Float{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample1( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec2 > interpolateAtSample( MaybeOptional< Vec2 > const & interpolant
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( interpolant, sample ) )
		{
			return Optional< Vec2 >{ findShader( interpolant, sample )
				, expr::makeInterpolateAtSample2( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
					, makeExpr( sample ) )
				, areOptionalEnabled( interpolant, sample ) };
		}

		return Vec2{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample2( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec3 > interpolateAtSample( MaybeOptional< Vec3 > const & interpolant
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( interpolant, sample ) )
		{
			return Optional< Vec3 >{ findShader( interpolant, sample )
				, expr::makeInterpolateAtSample3( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
					, makeExpr( sample ) )
				, areOptionalEnabled( interpolant, sample ) };
		}

		return Vec3{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample3( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
				, makeExpr( sample ) ) };
	}
	MaybeOptional< Vec4 > interpolateAtSample( MaybeOptional< Vec4 > const & interpolant
		, MaybeOptional< Int > const & sample )
	{
		if ( isAnyOptional( interpolant, sample ) )
		{
			return Optional< Vec4 >{ findShader( interpolant, sample )
				, expr::makeInterpolateAtSample4( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
					, makeExpr( sample ) )
				, areOptionalEnabled( interpolant, sample ) };
		}

		return Vec4{ findShader( interpolant, sample )
			, expr::makeInterpolateAtSample4( findTypesCache( interpolant, sample )
					, makeExpr( interpolant )
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
	MaybeOptional< Float > interpolateAtOffset( MaybeOptional< Float > const & interpolant
		, MaybeOptional< Vec2 > const & offset )
	{
		if ( isAnyOptional( interpolant, offset ) )
		{
			return Optional< Float >{ findShader( interpolant, offset )
				, expr::makeInterpolateAtOffset1( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
					, makeExpr( offset ) )
				, areOptionalEnabled( interpolant, offset ) };
		}

		return Float{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset1( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	MaybeOptional< Vec2 > interpolateAtOffset( MaybeOptional< Vec2 > const & interpolant
		, MaybeOptional< Vec2 > const & offset )
	{
		if ( isAnyOptional( interpolant, offset ) )
		{
			return Optional< Vec2 >{ findShader( interpolant, offset )
				, expr::makeInterpolateAtOffset2( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
					, makeExpr( offset ) )
				, areOptionalEnabled( interpolant, offset ) };
		}

		return Vec2{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset2( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	MaybeOptional< Vec3 > interpolateAtOffset( MaybeOptional< Vec3 > const & interpolant
		, MaybeOptional< Vec2 > const & offset )
	{
		if ( isAnyOptional( interpolant, offset ) )
		{
			return Optional< Vec3 >{ findShader( interpolant, offset )
				, expr::makeInterpolateAtOffset3( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
					, makeExpr( offset ) )
				, areOptionalEnabled( interpolant, offset ) };
		}

		return Vec3{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset3( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
				, makeExpr( offset ) ) };
	}
	MaybeOptional< Vec4 > interpolateAtOffset( MaybeOptional< Vec4 > const & interpolant
		, MaybeOptional< Vec2 > const & offset )
	{
		if ( isAnyOptional( interpolant, offset ) )
		{
			return Optional< Vec4 >{ findShader( interpolant, offset )
				, expr::makeInterpolateAtOffset4( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
					, makeExpr( offset ) )
				, areOptionalEnabled( interpolant, offset ) };
		}

		return Vec4{ findShader( interpolant, offset )
			, expr::makeInterpolateAtOffset4( findTypesCache( interpolant, offset )
					, makeExpr( interpolant )
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
	MaybeOptional< Void > EmitStreamVertex( MaybeOptional< Int > const & stream )
	{
		if ( isAnyOptional( stream ) )
		{
			return Optional< Void >{ findShader( stream )
				, expr::makeEmitStreamVertex( findTypesCache( stream )
					, makeExpr( stream ) )
				, areOptionalEnabled( stream ) };
		}

		return Void{ findShader( stream )
			, expr::makeEmitStreamVertex( findTypesCache( stream )
					, makeExpr( stream ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region EndStreamPrimitive
	/**
	*name
	*	EndStreamPrimitive
	*/
	/**@{*/
	MaybeOptional< Void > EndStreamPrimitive( MaybeOptional< Int > const & stream )
	{
		if ( isAnyOptional( stream ) )
		{
			return Optional< Void >{ findShader( stream )
				, expr::makeEndStreamPrimitive( findTypesCache( stream )
					, makeExpr( stream ) )
				, areOptionalEnabled( stream ) };
		}

		return Void{ findShader( stream )
			, expr::makeEndStreamPrimitive( findTypesCache( stream )
					, makeExpr( stream ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region EmitVertex
	/**
	*name
	*	EmitVertex
	*/
	/**@{*/
	MaybeOptional< Void > EmitVertex( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeEmitVertex( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeEmitVertex( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region EndPrimitive
	/**
	*name
	*	EndPrimitive
	*/
	/**@{*/
	MaybeOptional< Void > EndPrimitive( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeEndPrimitive( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeEndPrimitive( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region barrier
	/**
	*name
	*	barrier
	*/
	/**@{*/
	MaybeOptional< Void > barrier( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeBarrier( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeBarrier( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrier
	/**
	*name
	*	memoryBarrier
	*/
	/**@{*/
	MaybeOptional< UInt > memoryBarrier( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< UInt >{ findShader( )
				, expr::makeMemoryBarrier( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return UInt{ findShader( )
			, expr::makeMemoryBarrier( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierBuffer
	/**
	*name
	*	memoryBarrierBuffer
	*/
	/**@{*/
	MaybeOptional< Void > memoryBarrierBuffer( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeMemoryBarrierBuffer( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeMemoryBarrierBuffer( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierShared
	/**
	*name
	*	memoryBarrierShared
	*/
	/**@{*/
	MaybeOptional< Void > memoryBarrierShared( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeMemoryBarrierShared( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeMemoryBarrierShared( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region memoryBarrierImage
	/**
	*name
	*	memoryBarrierImage
	*/
	/**@{*/
	MaybeOptional< Void > memoryBarrierImage( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeMemoryBarrierImage( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeMemoryBarrierImage( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
#pragma region groupMemoryBarrier
	/**
	*name
	*	groupMemoryBarrier
	*/
	/**@{*/
	MaybeOptional< Void > groupMemoryBarrier( )
	{
		if ( isAnyOptional( ) )
		{
			return Optional< Void >{ findShader( )
				, expr::makeGroupMemoryBarrier( findTypesCache( ) )
				, areOptionalEnabled( ) };
		}

		return Void{ findShader( )
			, expr::makeGroupMemoryBarrier( findTypesCache( ) ) };
	}
	/**@}*/
#pragma endregion
}
