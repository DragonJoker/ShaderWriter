/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/MakeIntrinsic.hpp"

namespace ast::expr
{	// Angle and Trigonometry Functions

	IntrinsicCallPtr makeDegrees1( type::TypesCache & cache
		, ExprPtr radians )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDegrees1
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeDegrees2( type::TypesCache & cache
		, ExprPtr radians )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDegrees2
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeDegrees3( type::TypesCache & cache
		, ExprPtr radians )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDegrees3
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeDegrees4( type::TypesCache & cache
		, ExprPtr radians )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDegrees4
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeRadians1F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRadians1F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeRadians2F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRadians2F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeRadians3F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRadians3F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeRadians4F( type::TypesCache & cache
		, ExprPtr degrees )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRadians4F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeCos1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCos1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCos2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCos2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCos3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCos3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCos4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCos4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSin1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSin2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSin3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSin4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTan1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTan2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTan3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTan4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCosh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCosh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCosh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCosh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSinh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSinh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSinh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSinh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTanh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTanh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTanh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTanh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAcos1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAcos2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAcos3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAcos4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAsin1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAsin2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAsin3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAsin4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtan1( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtan1
			, std::move( y_over_x ) );
	}

	IntrinsicCallPtr makeAtan2( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtan2
			, std::move( y_over_x ) );
	}

	IntrinsicCallPtr makeAtan3( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtan3
			, std::move( y_over_x ) );
	}

	IntrinsicCallPtr makeAtan4( type::TypesCache & cache
		, ExprPtr y_over_x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAtan4
			, std::move( y_over_x ) );
	}

	IntrinsicCallPtr makeAcosh1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAcosh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAcosh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAcosh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAcosh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAsinh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAsinh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAsinh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAsinh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAtanh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAtanh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAtanh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAtanh4
			, std::move( x ) );
	}

	// Exponential Functions

	IntrinsicCallPtr makePow1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::ePow1
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makePow2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::ePow2
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makePow3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::ePow3
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makePow4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::ePow4
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeExp1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eExp1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eExp2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eExp3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eExp4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLog1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLog2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLog3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLog4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp21( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eExp21
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp22( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eExp22
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp23( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eExp23
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp24( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eExp24
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog21( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLog21
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog22( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLog22
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog23( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLog23
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog24( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLog24
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSqrt1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSqrt2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSqrt3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSqrt4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSqrt1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSqrt2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSqrt3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSqrt4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInverseSqrt1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInverseSqrt2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInverseSqrt3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInverseSqrt4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eInverseSqrt1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eInverseSqrt2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eInverseSqrt3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eInverseSqrt4D
			, std::move( x ) );
	}

	// Common Functions

	IntrinsicCallPtr makeAbs1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eAbs1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eAbs2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eAbs3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eAbs4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs1I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAbs1I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs2I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eAbs2I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs3I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eAbs3I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs4I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eAbs4I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eAbs1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eAbs2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eAbs3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eAbs4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSign1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSign2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSign3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSign4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign1I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eSign1I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign2I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eSign2I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign3I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eSign3I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign4I( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eSign4I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSign1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSign2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSign3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSign4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFloor1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFloor2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFloor3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFloor4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFloor1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFloor2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFloor3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFloor4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eTrunc1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eTrunc2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eTrunc3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eTrunc4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eTrunc1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eTrunc2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eTrunc3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eTrunc4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRound1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRound2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRound3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRound4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRound1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRound2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRound3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRound4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRoundEven1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRoundEven2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRoundEven3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRoundEven4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRoundEven1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRoundEven2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRoundEven3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRoundEven4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eCeil1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eCeil2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCeil3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eCeil4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eCeil1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eCeil2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eCeil3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eCeil4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFract1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFract2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFract3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFract4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFract1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFract2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFract3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFract4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeMod1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMod1F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMod2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMod3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMod4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMod1D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMod2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMod3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMod4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeModf1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eModf1F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eModf2F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eModf3F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eModf4F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eModf1D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eModf2D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eModf3D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eModf4D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeMin1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMin1F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMin2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMin3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMin4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMin1D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMin2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMin3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMin4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin1I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eMin1I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eMin2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eMin3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eMin4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin1U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eMin1U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eMin2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eMin3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eMin4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMax1F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMax2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMax3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMax4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMax1D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMax2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMax3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMax4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax1I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eMax1I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eMax2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eMax3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eMax4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax1U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eMax1U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eMax2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eMax3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eMax4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeClamp1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eClamp1F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eClamp2F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eClamp3F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eClamp4F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eClamp1D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eClamp2D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eClamp3D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eClamp4D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp1I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eClamp1I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eClamp2I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eClamp3I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eClamp4I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp1U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eClamp1U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eClamp2U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eClamp3U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eClamp4U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeMix1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eMix1F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eMix2F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eMix3F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eMix4F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eMix1D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eMix2D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eMix3D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eMix4D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeStep1F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eStep1F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep2F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eStep2F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep3F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eStep3F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep4F( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eStep4F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep1D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eStep1D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep2D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eStep2D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep3D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eStep3D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep4D( type::TypesCache & cache
		, ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eStep4D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep1F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eSmoothStep1F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep2F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eSmoothStep2F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep3F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eSmoothStep3F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep4F( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eSmoothStep4F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep1D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eSmoothStep1D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep2D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eSmoothStep2D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep3D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eSmoothStep3D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep4D( type::TypesCache & cache
		, ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eSmoothStep4D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eIsnan1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eIsnan1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eIsinf1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eIsinf1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt1( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFloatBitsToInt1
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt2( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFloatBitsToInt2
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt3( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFloatBitsToInt3
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt4( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFloatBitsToInt4
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt1( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eFloatBitsToUInt1
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt2( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eFloatBitsToUInt2
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt3( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eFloatBitsToUInt3
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt4( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eFloatBitsToUInt4
			, std::move( value ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eIntBitsToFloat1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eIntBitsToFloat2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eIntBitsToFloat3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eIntBitsToFloat4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eUintBitsToFloat1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUintBitsToFloat2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eUintBitsToFloat3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUintBitsToFloat4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFma1F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFma1F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma2F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFma2F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma3F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFma3F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma4F( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFma4F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma1D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFma1D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma2D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFma2D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma3D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFma3D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma4D( type::TypesCache & cache
		, ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFma4D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFrexp1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFrexp1F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFrexp2F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFrexp3F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFrexp4F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFrexp1D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFrexp2D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFrexp3D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFrexp4D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLdexp1F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eLdexp2F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eLdexp3F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eLdexp4F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLdexp1D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eLdexp2D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eLdexp3D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eLdexp4D
			, std::move( x )
			, std::move( exp ) );
	}

	// Floating-point Pack and Unpack Functions

	IntrinsicCallPtr makePackDouble2x32( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::ePackDouble2x32
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackHalf2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackHalf2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackSnorm2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackSnorm4x8( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm4x8
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackUnorm2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackUnorm4x8( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm4x8
			, std::move( v ) );
	}

	IntrinsicCallPtr makeUnpackDouble2x32( type::TypesCache & cache
		, ExprPtr d )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eUnpackDouble2x32
			, std::move( d ) );
	}

	IntrinsicCallPtr makeUnpackHalf2x16( type::TypesCache & cache
		, ExprPtr v )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackHalf2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makeUnpackSnorm2x16( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackSnorm2x16
			, std::move( p ) );
	}

	IntrinsicCallPtr makeUnpackSnorm4x8( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUnpackSnorm4x8
			, std::move( p ) );
	}

	IntrinsicCallPtr makeUnpackUnorm2x16( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eUnpackUnorm2x16
			, std::move( p ) );
	}

	IntrinsicCallPtr makeUnpackUnorm4x8( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eUnpackUnorm4x8
			, std::move( p ) );
	}

	// Geometric Functions

	IntrinsicCallPtr makeLength1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eLength4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eLength4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeDistance1F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDistance1F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance2F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDistance2F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance3F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDistance3F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance4F( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDistance4F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance1D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance1D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance2D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance2D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance3D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance3D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance4D( type::TypesCache & cache
		, ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDistance4D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDot1F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot1F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDot4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot1D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot1D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDot4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeCrossF( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eCrossF
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeCrossD( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eCrossD
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNormalize1F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eNormalize1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eNormalize2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eNormalize3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eNormalize4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize1D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eNormalize1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eNormalize2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eNormalize3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eNormalize4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFaceForward1F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFaceForward1F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward2F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFaceForward2F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward3F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFaceForward3F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward4F( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFaceForward4F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward1D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eFaceForward1D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward2D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eFaceForward2D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward3D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eFaceForward3D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward4D( type::TypesCache & cache
		, ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eFaceForward4D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeReflect1F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eReflect1F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect2F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eReflect2F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect3F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eReflect3F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect4F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eReflect4F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect1D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eReflect1D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect2D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eReflect2D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect3D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eReflect3D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect4D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eReflect4D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract1F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eRefract1F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract2F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eRefract2F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract3F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eRefract3F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract4F( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eRefract4F
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract1D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eRefract1D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract2D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2D )
			, Intrinsic::eRefract2D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract3D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3D )
			, Intrinsic::eRefract3D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	IntrinsicCallPtr makeRefract4D( type::TypesCache & cache
		, ExprPtr I
		, ExprPtr N
		, ExprPtr eta )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4D )
			, Intrinsic::eRefract4D
			, std::move( I )
			, std::move( N )
			, std::move( eta ) );
	}

	// Matrix Functions

	IntrinsicCallPtr makeMatrixCompMult2x2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eMatrixCompMult2x2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eMatrixCompMult2x3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eMatrixCompMult2x4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eMatrixCompMult3x2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eMatrixCompMult3x3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eMatrixCompMult3x4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eMatrixCompMult4x2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eMatrixCompMult4x3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eMatrixCompMult4x4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eMatrixCompMult2x2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eMatrixCompMult2x3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eMatrixCompMult2x4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eMatrixCompMult3x2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eMatrixCompMult3x3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eMatrixCompMult3x4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eMatrixCompMult4x2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eMatrixCompMult4x3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eMatrixCompMult4x4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeOuterProduct2x2F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eOuterProduct2x2F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x3F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eOuterProduct3x3F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x4F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eOuterProduct4x4F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x2F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eOuterProduct3x2F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x3F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eOuterProduct2x3F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x2F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eOuterProduct4x2F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x4F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eOuterProduct2x4F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x3F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eOuterProduct4x3F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x4F( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eOuterProduct3x4F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x2D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eOuterProduct2x2D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x3D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eOuterProduct3x3D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x4D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eOuterProduct4x4D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x2D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eOuterProduct3x2D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x3D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eOuterProduct2x3D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x2D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eOuterProduct4x2D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x4D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eOuterProduct2x4D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x3D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eOuterProduct4x3D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x4D( type::TypesCache & cache
		, ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eOuterProduct3x4D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeTranspose2x2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eTranspose2x2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2F )
			, Intrinsic::eTranspose2x3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2F )
			, Intrinsic::eTranspose2x4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3F )
			, Intrinsic::eTranspose3x2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eTranspose3x3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3F )
			, Intrinsic::eTranspose3x4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x2F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4F )
			, Intrinsic::eTranspose4x2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x3F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4F )
			, Intrinsic::eTranspose4x3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x4F( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eTranspose4x4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eTranspose2x2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x2D )
			, Intrinsic::eTranspose2x3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x2D )
			, Intrinsic::eTranspose2x4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x3D )
			, Intrinsic::eTranspose3x2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eTranspose3x3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x3D )
			, Intrinsic::eTranspose3x4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x2D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x4D )
			, Intrinsic::eTranspose4x2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x3D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x4D )
			, Intrinsic::eTranspose4x3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x4D( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eTranspose4x4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeDeterminant2x2F( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant2x2F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant3x3F( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant3x3F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant4x4F( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDeterminant4x4F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant2x2D( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant2x2D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant3x3D( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant3x3D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant4x4D( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eDouble )
			, Intrinsic::eDeterminant4x4D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse2x2F( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2F )
			, Intrinsic::eInverse2x2F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse3x3F( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3F )
			, Intrinsic::eInverse3x3F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse4x4F( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4F )
			, Intrinsic::eInverse4x4F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse2x2D( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat2x2D )
			, Intrinsic::eInverse2x2D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse3x3D( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat3x3D )
			, Intrinsic::eInverse3x3D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse4x4D( type::TypesCache & cache
		, ExprPtr m )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eMat4x4D )
			, Intrinsic::eInverse4x4D
			, std::move( m ) );
	}

	// Vector Relational Functions

	IntrinsicCallPtr makeLessThan2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4F( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4D( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4I( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4U( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeAll2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eAll2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAll3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eAll3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAll4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eAll4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAny2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eAny2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAny3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eAny3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAny4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eBool )
			, Intrinsic::eAny4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNot2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2B )
			, Intrinsic::eNot2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNot3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3B )
			, Intrinsic::eNot3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNot4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4B )
			, Intrinsic::eNot4
			, std::move( x ) );
	}

	// Integer Functions

	IntrinsicCallPtr makeUaddCarry1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eUaddCarry1
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUaddCarry2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eUaddCarry2
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUaddCarry3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eUaddCarry3
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUaddCarry4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eUaddCarry4
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUsubBorrow1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eUsubBorrow1
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUsubBorrow2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eUsubBorrow2
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUsubBorrow3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eUsubBorrow3
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUsubBorrow4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eUsubBorrow4
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUmulExtended1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeUmulExtended2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeUmulExtended3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeUmulExtended4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended1( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended2( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended3( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended4( type::TypesCache & cache
		, ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eImulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeBitfieldExtract1I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitfieldExtract1I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract2I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldExtract2I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract3I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldExtract3I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract4I( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldExtract4I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract1U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitfieldExtract1U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract2U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldExtract2U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract3U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldExtract3U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract4U( type::TypesCache & cache
		, ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldExtract4U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert1I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitfieldInsert1I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert2I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldInsert2I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert3I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldInsert3I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert4I( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldInsert4I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert1U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitfieldInsert1U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert2U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldInsert2U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert3U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldInsert3U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert4U( type::TypesCache & cache
		, ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldInsert4U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldReverse1I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitfieldReverse1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse2I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldReverse2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse3I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldReverse3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse4I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldReverse4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse1U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitfieldReverse1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse2U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldReverse2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse3U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldReverse3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse4U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldReverse4U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount1I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eBitCount1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount2I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eBitCount2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount3I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eBitCount3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount4I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eBitCount4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount1U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eBitCount1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount2U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2U )
			, Intrinsic::eBitCount2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount3U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3U )
			, Intrinsic::eBitCount3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount4U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4U )
			, Intrinsic::eBitCount4U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB1I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindLSB1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB2I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB3I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB4I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB1U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindLSB1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB2U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB3U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB4U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB1I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindMSB1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB2I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB3I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB4I( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB1U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eFindMSB1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB2U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB3U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB4U( type::TypesCache & cache
		, ExprPtr value )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4U
			, std::move( value ) );
	}

	// Atomic Memory Functions

	IntrinsicCallPtr makeAtomicAddI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicAddI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicAddU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicAddU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMinI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicMinI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMinU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicMinU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMaxI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicMaxI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMaxU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicMaxU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicAndI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicAndI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicAndU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicAndU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicOrI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicOrI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicOrU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicOrU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicXorI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicXorI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicXorU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicXorU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicExchangeI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicExchangeI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicExchangeU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicExchangeU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicCompSwapI( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eInt )
			, Intrinsic::eAtomicCompSwapI
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicCompSwapU( type::TypesCache & cache
		, ExprPtr mem
		, ExprPtr compare
		, ExprPtr data )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eAtomicCompSwapU
			, std::move( mem )
			, std::move( compare )
			, std::move( data ) );
	}

	// Derivative Functions

	IntrinsicCallPtr makeDFdx1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdx1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdx2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdx2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdx3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdx3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdx4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdx4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdxCoarse1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdxCoarse2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdxCoarse3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdxCoarse4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdxFine1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdxFine2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdxFine3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdxFine4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdy1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdy2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdy3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdy4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdyCoarse1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdyCoarse2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdyCoarse3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdyCoarse4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eDFdyFine1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eDFdyFine2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eDFdyFine3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eDFdyFine4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth1( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eFwidth1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth2( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eFwidth2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth3( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eFwidth3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth4( type::TypesCache & cache
		, ExprPtr p )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eFwidth4
			, std::move( p ) );
	}

	// Interpolation Functions

	IntrinsicCallPtr makeInterpolateAtCentroid1( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtCentroid1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtCentroid2( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtCentroid2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtCentroid3( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtCentroid3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtCentroid4( type::TypesCache & cache
		, ExprPtr x )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtCentroid4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample1( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtSample1
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample2( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtSample2
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample3( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtSample3
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample4( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtSample4
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset1( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtOffset1
			, std::move( interpolant )
			, std::move( offset ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset2( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtOffset2
			, std::move( interpolant )
			, std::move( offset ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset3( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtOffset3
			, std::move( interpolant )
			, std::move( offset ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset4( type::TypesCache & cache
		, ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtOffset4
			, std::move( interpolant )
			, std::move( offset ) );
	}

	// Geometry Shader Functions

	IntrinsicCallPtr makeEmitStreamVertex( type::TypesCache & cache
		, ExprPtr stream )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEmitStreamVertex
			, std::move( stream ) );
	}

	IntrinsicCallPtr makeEndStreamPrimitive( type::TypesCache & cache
		, ExprPtr stream )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEndStreamPrimitive
			, std::move( stream ) );
	}

	IntrinsicCallPtr makeEmitVertex( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEmitVertex );
	}

	IntrinsicCallPtr makeEndPrimitive( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eEndPrimitive );
	}

	// Shader Invocation Control Functions

	IntrinsicCallPtr makeBarrier( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eBarrier );
	}

	// Shader Memory Control Functions

	IntrinsicCallPtr makeMemoryBarrier( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eUInt )
			, Intrinsic::eMemoryBarrier );
	}

	IntrinsicCallPtr makeMemoryBarrierBuffer( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierBuffer );
	}

	IntrinsicCallPtr makeMemoryBarrierShared( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierShared );
	}

	IntrinsicCallPtr makeMemoryBarrierImage( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierImage );
	}

	IntrinsicCallPtr makeGroupMemoryBarrier( type::TypesCache & cache )
	{
		return makeIntrinsicCall( cache.getBasicType( type::Kind::eVoid )
			, Intrinsic::eGroupMemoryBarrier );
	}
}
