/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/MakeIntrinsic.hpp"

namespace ast::expr
{	// Angle and Trigonometry Functions

	IntrinsicCallPtr makeDegrees1( ExprPtr radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDegrees1
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeDegrees2( ExprPtr radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDegrees2
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeDegrees3( ExprPtr radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDegrees3
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeDegrees4( ExprPtr radians )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDegrees4
			, std::move( radians ) );
	}

	IntrinsicCallPtr makeRadians1F( ExprPtr degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRadians1F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeRadians2F( ExprPtr degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRadians2F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeRadians3F( ExprPtr degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRadians3F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeRadians4F( ExprPtr degrees )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRadians4F
			, std::move( degrees ) );
	}

	IntrinsicCallPtr makeCos1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eCos1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCos2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eCos2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCos3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCos3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCos4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eCos4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSin1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSin2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSin3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSin4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSin4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eTan1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eTan2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eTan3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTan4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eTan4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eCosh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eCosh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCosh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCosh4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eCosh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSinh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSinh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSinh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSinh4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSinh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eTanh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eTanh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eTanh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTanh4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eTanh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAcos1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAcos2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAcos3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcos4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAcos4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAsin1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAsin2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAsin3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsin4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAsin4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtan1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAtan1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtan2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAtan2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtan3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAtan3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtan4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAtan4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAcosh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAcosh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAcosh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAcosh4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAcosh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAsinh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAsinh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAsinh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAsinh4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAsinh4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAtanh1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAtanh2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAtanh3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAtanh4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAtanh4
			, std::move( x ) );
	}

	// Exponential Functions

	IntrinsicCallPtr makePow1( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::ePow1
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makePow2( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::ePow2
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makePow3( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::ePow3
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makePow4( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::ePow4
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeExp1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eExp1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eExp2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eExp3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eExp4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLog1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eLog2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eLog3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eLog4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp21( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eExp21
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp22( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eExp22
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp23( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eExp23
			, std::move( x ) );
	}

	IntrinsicCallPtr makeExp24( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eExp24
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog21( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLog21
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog22( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eLog22
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog23( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eLog23
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLog24( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eLog24
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSqrt1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSqrt2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSqrt3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSqrt4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eSqrt1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSqrt2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSqrt3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSqrt4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSqrt4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInverseSqrt1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInverseSqrt2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInverseSqrt3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInverseSqrt4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eInverseSqrt1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eInverseSqrt2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eInverseSqrt3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInverseSqrt4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eInverseSqrt4D
			, std::move( x ) );
	}

	// Common Functions

	IntrinsicCallPtr makeAbs1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eAbs1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eAbs2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eAbs3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eAbs4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs1I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAbs1I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs2I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eAbs2I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs3I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eAbs3I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs4I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eAbs4I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eAbs1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eAbs2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eAbs3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAbs4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eAbs4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSign1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSign2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSign3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSign4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign1I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eSign1I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign2I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eSign2I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign3I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eSign3I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign4I( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eSign4I
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eSign1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSign2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSign3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSign4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSign4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFloor1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFloor2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFloor3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFloor4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFloor1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFloor2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFloor3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloor4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFloor4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eTrunc1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eTrunc2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eTrunc3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eTrunc4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eTrunc1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eTrunc2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eTrunc3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTrunc4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eTrunc4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRound1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRound2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRound3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRound4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eRound1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eRound2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eRound3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRound4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eRound4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRoundEven1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRoundEven2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRoundEven3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRoundEven4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eRoundEven1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eRoundEven2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eRoundEven3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeRoundEven4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eRoundEven4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eCeil1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eCeil2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCeil3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eCeil4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eCeil1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eCeil2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eCeil3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeCeil4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eCeil4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFract1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFract2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFract3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFract4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFract1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFract2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFract3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFract4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFract4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeMod11F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMod11F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod22F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMod22F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod33F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMod33F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod44F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMod44F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod21F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMod21F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod31F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMod31F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod41F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMod41F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod11D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMod11D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod22D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMod22D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod33D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMod33D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod44D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMod44D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod21D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMod21D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod31D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMod31D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMod41D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMod41D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeModf1F( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eModf1F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf2F( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eModf2F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf3F( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eModf3F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf4F( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eModf4F
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf1D( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eModf1D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf2D( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eModf2D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf3D( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eModf3D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeModf4D( ExprPtr x
		, ExprPtr i )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eModf4D
			, std::move( x )
			, std::move( i ) );
	}

	IntrinsicCallPtr makeMin11F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMin11F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin22F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMin22F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin33F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMin33F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin44F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMin44F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin21F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMin21F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin31F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMin31F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin41F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMin41F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin11D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMin11D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin22D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMin22D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin33D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMin33D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin44D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMin44D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin21D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMin21D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin31D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMin31D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin41D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMin41D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin11I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eMin11I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin22I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMin22I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin33I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMin33I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin44I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMin44I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin21I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMin21I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin31I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMin31I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin41I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMin41I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin11U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eMin11U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin22U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMin22U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin33U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMin33U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin44U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMin44U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin21U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMin21U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin31U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMin31U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMin41U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMin41U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax11F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMax11F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax22F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMax22F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax33F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMax33F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax44F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMax44F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax21F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMax21F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax31F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMax31F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax41F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMax41F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax11D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMax11D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax22D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMax22D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax33D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMax33D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax44D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMax44D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax21D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMax21D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax31D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMax31D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax41D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMax41D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax11I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eMax11I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax22I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMax22I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax33I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMax33I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax44I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMax44I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax21I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eMax21I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax31I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eMax31I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax41I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eMax41I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax11U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eMax11U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax22U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMax22U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax33U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMax33U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax44U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMax44U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax21U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eMax21U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax31U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eMax31U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMax41U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eMax41U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeClamp11F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eClamp11F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp22F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eClamp22F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp33F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eClamp33F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp44F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eClamp44F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp21F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eClamp21F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp31F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eClamp31F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp41F( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eClamp41F
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp11D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eClamp11D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp22D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eClamp22D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp33D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eClamp33D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp44D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eClamp44D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp21D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eClamp21D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp31D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eClamp31D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp41D( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eClamp41D
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp11I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eClamp11I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp22I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eClamp22I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp33I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eClamp33I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp44I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eClamp44I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp21I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eClamp21I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp31I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eClamp31I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp41I( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eClamp41I
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp11U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eClamp11U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp22U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eClamp22U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp33U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eClamp33U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp44U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eClamp44U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp21U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eClamp21U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp31U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eClamp31U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeClamp41U( ExprPtr x
		, ExprPtr minVal
		, ExprPtr maxVal )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eClamp41U
			, std::move( x )
			, std::move( minVal )
			, std::move( maxVal ) );
	}

	IntrinsicCallPtr makeMix11F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMix11F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix22F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMix22F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix33F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMix33F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix44F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMix44F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix21F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMix21F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix31F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMix31F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix41F( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMix41F
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix11FB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eMix11FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix22FB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eMix22FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix33FB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eMix33FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix44FB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eMix44FB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix11D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMix11D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix22D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMix22D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix33D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMix33D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix44D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMix44D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix21D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMix21D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix31D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMix31D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix41D( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMix41D
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix11DB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eMix11DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix22DB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eMix22DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix33DB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eMix33DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeMix44DB( ExprPtr x
		, ExprPtr y
		, ExprPtr a )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eMix44DB
			, std::move( x )
			, std::move( y )
			, std::move( a ) );
	}

	IntrinsicCallPtr makeStep11F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eStep11F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep22F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eStep22F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep33F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eStep33F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep44F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eStep44F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep12F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eStep12F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep13F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eStep13F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep14F( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eStep14F
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep11D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eStep11D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep22D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eStep22D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep33D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eStep33D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep44D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eStep44D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep12D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eStep12D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep13D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eStep13D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeStep14D( ExprPtr edge
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eStep14D
			, std::move( edge )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep11F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eSmoothStep11F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep22F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSmoothStep22F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep33F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSmoothStep33F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep44F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSmoothStep44F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep12F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eSmoothStep12F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep13F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eSmoothStep13F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep14F( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eSmoothStep14F
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep11D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eSmoothStep11D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep22D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSmoothStep22D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep33D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSmoothStep33D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep44D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSmoothStep44D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep12D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eSmoothStep12D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep13D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eSmoothStep13D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeSmoothStep14D( ExprPtr edge0
		, ExprPtr edge1
		, ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eSmoothStep14D
			, std::move( edge0 )
			, std::move( edge1 )
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsnan1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsnan2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsnan3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsnan4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsnan4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eIsinf1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eIsinf2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eIsinf3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIsinf4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eIsinf4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt1( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFloatBitsToInt1
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt2( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFloatBitsToInt2
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt3( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFloatBitsToInt3
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToInt4( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFloatBitsToInt4
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt1( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eFloatBitsToUInt1
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt2( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eFloatBitsToUInt2
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt3( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eFloatBitsToUInt3
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFloatBitsToUInt4( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eFloatBitsToUInt4
			, std::move( value ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eIntBitsToFloat1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eIntBitsToFloat2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eIntBitsToFloat3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeIntBitsToFloat4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eIntBitsToFloat4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eUintBitsToFloat1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUintBitsToFloat2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eUintBitsToFloat3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeUintBitsToFloat4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eUintBitsToFloat4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFma1F( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFma1F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma2F( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFma2F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma3F( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFma3F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma4F( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFma4F
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma1D( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFma1D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma2D( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFma2D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma3D( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFma3D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFma4D( ExprPtr a
		, ExprPtr b
		, ExprPtr c )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFma4D
			, std::move( a )
			, std::move( b )
			, std::move( c ) );
	}

	IntrinsicCallPtr makeFrexp1F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFrexp1F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp2F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFrexp2F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp3F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFrexp3F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp4F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFrexp4F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp1D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFrexp1D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp2D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFrexp2D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp3D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFrexp3D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeFrexp4D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFrexp4D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp1F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLdexp1F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp2F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eLdexp2F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp3F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eLdexp3F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp4F( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eLdexp4F
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp1D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLdexp1D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp2D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eLdexp2D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp3D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eLdexp3D
			, std::move( x )
			, std::move( exp ) );
	}

	IntrinsicCallPtr makeLdexp4D( ExprPtr x
		, ExprPtr exp )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eLdexp4D
			, std::move( x )
			, std::move( exp ) );
	}

	// Floating-point Pack and Unpack Functions

	IntrinsicCallPtr makePackDouble2x32( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::ePackDouble2x32
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackHalf2x16( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackHalf2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackSnorm2x16( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackSnorm4x8( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackSnorm4x8
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackUnorm2x16( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makePackUnorm4x8( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::ePackUnorm4x8
			, std::move( v ) );
	}

	IntrinsicCallPtr makeUnpackDouble2x32( ExprPtr d )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eUnpackDouble2x32
			, std::move( d ) );
	}

	IntrinsicCallPtr makeUnpackHalf2x16( ExprPtr v )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUnpackHalf2x16
			, std::move( v ) );
	}

	IntrinsicCallPtr makeUnpackSnorm2x16( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUnpackSnorm2x16
			, std::move( p ) );
	}

	IntrinsicCallPtr makeUnpackSnorm4x8( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eUnpackSnorm4x8
			, std::move( p ) );
	}

	IntrinsicCallPtr makeUnpackUnorm2x16( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eUnpackUnorm2x16
			, std::move( p ) );
	}

	IntrinsicCallPtr makeUnpackUnorm4x8( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eUnpackUnorm4x8
			, std::move( p ) );
	}

	// Geometric Functions

	IntrinsicCallPtr makeLength1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eLength4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeLength4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eLength4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeDistance1F( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDistance1F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance2F( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDistance2F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance3F( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDistance3F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance4F( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDistance4F
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance1D( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance1D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance2D( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance2D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance3D( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance3D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDistance4D( ExprPtr p0
		, ExprPtr p1 )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDistance4D
			, std::move( p0 )
			, std::move( p1 ) );
	}

	IntrinsicCallPtr makeDot1F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot1F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDot4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot1D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot1D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeDot4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDot4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeCrossF( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eCrossF
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeCrossD( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eCrossD
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNormalize1F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eNormalize1F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eNormalize2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eNormalize3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eNormalize4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize1D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eNormalize1D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eNormalize2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eNormalize3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNormalize4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eNormalize4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeFaceForward1F( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFaceForward1F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward2F( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFaceForward2F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward3F( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFaceForward3F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward4F( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFaceForward4F
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward1D( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eFaceForward1D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward2D( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eFaceForward2D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward3D( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eFaceForward3D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeFaceForward4D( ExprPtr N
		, ExprPtr I
		, ExprPtr Nref )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eFaceForward4D
			, std::move( N )
			, std::move( I )
			, std::move( Nref ) );
	}

	IntrinsicCallPtr makeReflect1F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eReflect1F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect2F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eReflect2F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect3F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eReflect3F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect4F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eReflect4F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect1D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eReflect1D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect2D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eReflect2D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect3D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eReflect3D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeReflect4D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eReflect4D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract1F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eRefract1F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract2F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eRefract2F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract3F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eRefract3F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract4F( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eRefract4F
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract1D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eRefract1D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract2D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2D )
			, Intrinsic::eRefract2D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract3D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3D )
			, Intrinsic::eRefract3D
			, std::move( I )
			, std::move( N ) );
	}

	IntrinsicCallPtr makeRefract4D( ExprPtr I
		, ExprPtr N )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4D )
			, Intrinsic::eRefract4D
			, std::move( I )
			, std::move( N ) );
	}

	// Matrix Functions

	IntrinsicCallPtr makeMatrixCompMult2x2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eMatrixCompMult2x2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3F )
			, Intrinsic::eMatrixCompMult2x3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4F )
			, Intrinsic::eMatrixCompMult2x4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2F )
			, Intrinsic::eMatrixCompMult3x2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eMatrixCompMult3x3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4F )
			, Intrinsic::eMatrixCompMult3x4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2F )
			, Intrinsic::eMatrixCompMult4x2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3F )
			, Intrinsic::eMatrixCompMult4x3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eMatrixCompMult4x4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eMatrixCompMult2x2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3D )
			, Intrinsic::eMatrixCompMult2x3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult2x4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4D )
			, Intrinsic::eMatrixCompMult2x4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2D )
			, Intrinsic::eMatrixCompMult3x2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eMatrixCompMult3x3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult3x4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4D )
			, Intrinsic::eMatrixCompMult3x4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2D )
			, Intrinsic::eMatrixCompMult4x2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3D )
			, Intrinsic::eMatrixCompMult4x3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeMatrixCompMult4x4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eMatrixCompMult4x4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeOuterProduct2x2F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eOuterProduct2x2F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x3F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eOuterProduct3x3F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x4F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eOuterProduct4x4F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x2F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3F )
			, Intrinsic::eOuterProduct3x2F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x3F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2F )
			, Intrinsic::eOuterProduct2x3F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x2F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4F )
			, Intrinsic::eOuterProduct4x2F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x4F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2F )
			, Intrinsic::eOuterProduct2x4F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x3F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4F )
			, Intrinsic::eOuterProduct4x3F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x4F( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3F )
			, Intrinsic::eOuterProduct3x4F
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x2D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eOuterProduct2x2D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x3D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eOuterProduct3x3D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x4D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eOuterProduct4x4D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x2D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3D )
			, Intrinsic::eOuterProduct3x2D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x3D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2D )
			, Intrinsic::eOuterProduct2x3D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x2D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4D )
			, Intrinsic::eOuterProduct4x2D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct2x4D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2D )
			, Intrinsic::eOuterProduct2x4D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct4x3D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4D )
			, Intrinsic::eOuterProduct4x3D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeOuterProduct3x4D( ExprPtr c
		, ExprPtr r )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3D )
			, Intrinsic::eOuterProduct3x4D
			, std::move( c )
			, std::move( r ) );
	}

	IntrinsicCallPtr makeTranspose2x2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eTranspose2x2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2F )
			, Intrinsic::eTranspose2x3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2F )
			, Intrinsic::eTranspose2x4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3F )
			, Intrinsic::eTranspose3x2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eTranspose3x3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3F )
			, Intrinsic::eTranspose3x4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x2F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4F )
			, Intrinsic::eTranspose4x2F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x3F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4F )
			, Intrinsic::eTranspose4x3F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x4F( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eTranspose4x4F
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eTranspose2x2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x2D )
			, Intrinsic::eTranspose2x3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose2x4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x2D )
			, Intrinsic::eTranspose2x4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x3D )
			, Intrinsic::eTranspose3x2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eTranspose3x3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose3x4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x3D )
			, Intrinsic::eTranspose3x4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x2D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x4D )
			, Intrinsic::eTranspose4x2D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x3D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x4D )
			, Intrinsic::eTranspose4x3D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeTranspose4x4D( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eTranspose4x4D
			, std::move( x ) );
	}

	IntrinsicCallPtr makeDeterminant2x2F( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDeterminant2x2F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant3x3F( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDeterminant3x3F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant4x4F( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDeterminant4x4F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant2x2D( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDeterminant2x2D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant3x3D( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDeterminant3x3D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeDeterminant4x4D( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eDouble )
			, Intrinsic::eDeterminant4x4D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse2x2F( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2F )
			, Intrinsic::eInverse2x2F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse3x3F( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3F )
			, Intrinsic::eInverse3x3F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse4x4F( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4F )
			, Intrinsic::eInverse4x4F
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse2x2D( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat2x2D )
			, Intrinsic::eInverse2x2D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse3x3D( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat3x3D )
			, Intrinsic::eInverse3x3D
			, std::move( m ) );
	}

	IntrinsicCallPtr makeInverse4x4D( ExprPtr m )
	{
		return makeIntrinsicCall( makeType( type::Kind::eMat4x4D )
			, Intrinsic::eInverse4x4D
			, std::move( m ) );
	}

	// Vector Relational Functions

	IntrinsicCallPtr makeLessThan2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan2I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan2U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThan2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan3U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThan3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThan4U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThan4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual2U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eLessThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual3U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eLessThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeLessThanEqual4U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eLessThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan2U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThan2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan3U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThan3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThan4U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThan4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual2U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eGreaterThanEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual3U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eGreaterThanEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeGreaterThanEqual4U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eGreaterThanEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual2U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual3U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeEqual4U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4F( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4F
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4D( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4D
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4I( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4I
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual2U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNotEqual2U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual3U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNotEqual3U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeNotEqual4U( ExprPtr x
		, ExprPtr y )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNotEqual4U
			, std::move( x )
			, std::move( y ) );
	}

	IntrinsicCallPtr makeAll2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAll2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAll3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAll3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAll4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAll4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAny2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAny2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAny3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAny3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeAny4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eBoolean )
			, Intrinsic::eAny4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNot2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2B )
			, Intrinsic::eNot2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNot3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3B )
			, Intrinsic::eNot3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeNot4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4B )
			, Intrinsic::eNot4
			, std::move( x ) );
	}

	// Integer Functions

	IntrinsicCallPtr makeUaddCarry1( ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eUaddCarry1
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUaddCarry2( ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eUaddCarry2
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUaddCarry3( ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eUaddCarry3
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUaddCarry4( ExprPtr x
		, ExprPtr y
		, ExprPtr carry )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eUaddCarry4
			, std::move( x )
			, std::move( y )
			, std::move( carry ) );
	}

	IntrinsicCallPtr makeUsubBorrow1( ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eUsubBorrow1
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUsubBorrow2( ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eUsubBorrow2
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUsubBorrow3( ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eUsubBorrow3
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUsubBorrow4( ExprPtr x
		, ExprPtr y
		, ExprPtr borrow )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eUsubBorrow4
			, std::move( x )
			, std::move( y )
			, std::move( borrow ) );
	}

	IntrinsicCallPtr makeUmulExtended1( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeUmulExtended2( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeUmulExtended3( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeUmulExtended4( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eUmulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended1( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended1
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended2( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended2
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended3( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended3
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeImulExtended4( ExprPtr x
		, ExprPtr y
		, ExprPtr msb
		, ExprPtr lsb )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eImulExtended4
			, std::move( x )
			, std::move( y )
			, std::move( msb )
			, std::move( lsb ) );
	}

	IntrinsicCallPtr makeBitfieldExtract1I( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitfieldExtract1I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract2I( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldExtract2I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract3I( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldExtract3I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract4I( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldExtract4I
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract1U( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitfieldExtract1U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract2U( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldExtract2U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract3U( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldExtract3U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldExtract4U( ExprPtr value
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldExtract4U
			, std::move( value )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert1I( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitfieldInsert1I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert2I( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldInsert2I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert3I( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldInsert3I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert4I( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldInsert4I
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert1U( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitfieldInsert1U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert2U( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldInsert2U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert3U( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldInsert3U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldInsert4U( ExprPtr base
		, ExprPtr insert
		, ExprPtr offset
		, ExprPtr bits )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldInsert4U
			, std::move( base )
			, std::move( insert )
			, std::move( offset )
			, std::move( bits ) );
	}

	IntrinsicCallPtr makeBitfieldReverse1I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitfieldReverse1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse2I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitfieldReverse2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse3I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitfieldReverse3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse4I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitfieldReverse4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse1U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitfieldReverse1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse2U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitfieldReverse2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse3U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitfieldReverse3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitfieldReverse4U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitfieldReverse4U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount1I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eBitCount1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount2I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eBitCount2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount3I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eBitCount3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount4I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eBitCount4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount1U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eBitCount1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount2U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2U )
			, Intrinsic::eBitCount2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount3U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3U )
			, Intrinsic::eBitCount3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeBitCount4U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4U )
			, Intrinsic::eBitCount4U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB1I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindLSB1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB2I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB3I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB4I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB1U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindLSB1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB2U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindLSB2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB3U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindLSB3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindLSB4U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindLSB4U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB1I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindMSB1I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB2I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB3I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB4I( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4I
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB1U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eFindMSB1U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB2U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2I )
			, Intrinsic::eFindMSB2U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB3U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3I )
			, Intrinsic::eFindMSB3U
			, std::move( value ) );
	}

	IntrinsicCallPtr makeFindMSB4U( ExprPtr value )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4I )
			, Intrinsic::eFindMSB4U
			, std::move( value ) );
	}

	// Atomic Memory Functions

	IntrinsicCallPtr makeAtomicAddI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicAddI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicAddU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicAddU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMinI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicMinI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMinU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicMinU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMaxI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicMaxI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicMaxU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicMaxU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicAndI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicAndI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicAndU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicAndU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicOrI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicOrI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicOrU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicOrU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicXorI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicXorI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicXorU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicXorU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicExchangeI( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicExchangeI
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicExchangeU( ExprPtr mem
		, ExprPtr data )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicExchangeU
			, std::move( mem )
			, std::move( data ) );
	}

	IntrinsicCallPtr makeAtomicCompSwapI( ExprPtr mem
		, ExprPtr compare )
	{
		return makeIntrinsicCall( makeType( type::Kind::eInt )
			, Intrinsic::eAtomicCompSwapI
			, std::move( mem )
			, std::move( compare ) );
	}

	IntrinsicCallPtr makeAtomicCompSwapU( ExprPtr mem
		, ExprPtr compare )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eAtomicCompSwapU
			, std::move( mem )
			, std::move( compare ) );
	}

	// Derivative Functions

	IntrinsicCallPtr makeDFdx1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdx1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdx2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdx2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdx3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdx3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdx4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdx4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdxCoarse1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdxCoarse2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdxCoarse3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxCoarse4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdxCoarse4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdxFine1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdxFine2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdxFine3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdxFine4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdxFine4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdy1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdy2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdy3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdy4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdy4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdyCoarse1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdyCoarse2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdyCoarse3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyCoarse4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdyCoarse4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eDFdyFine1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eDFdyFine2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eDFdyFine3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeDFdyFine4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eDFdyFine4
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth1( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eFwidth1
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth2( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eFwidth2
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth3( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eFwidth3
			, std::move( p ) );
	}

	IntrinsicCallPtr makeFwidth4( ExprPtr p )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eFwidth4
			, std::move( p ) );
	}

	// Interpolation Functions

	IntrinsicCallPtr makeInterpolateAtCentroid1( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtCentroid1
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtCentroid2( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtCentroid2
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtCentroid3( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtCentroid3
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtCentroid4( ExprPtr x )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtCentroid4
			, std::move( x ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample1( ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtSample1
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample2( ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtSample2
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample3( ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtSample3
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtSample4( ExprPtr interpolant
		, ExprPtr sample )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtSample4
			, std::move( interpolant )
			, std::move( sample ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset1( ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eFloat )
			, Intrinsic::eInterpolateAtOffset1
			, std::move( interpolant )
			, std::move( offset ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset2( ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec2F )
			, Intrinsic::eInterpolateAtOffset2
			, std::move( interpolant )
			, std::move( offset ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset3( ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec3F )
			, Intrinsic::eInterpolateAtOffset3
			, std::move( interpolant )
			, std::move( offset ) );
	}

	IntrinsicCallPtr makeInterpolateAtOffset4( ExprPtr interpolant
		, ExprPtr offset )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVec4F )
			, Intrinsic::eInterpolateAtOffset4
			, std::move( interpolant )
			, std::move( offset ) );
	}

	// Geometry Shader Functions

	IntrinsicCallPtr makeEmitStreamVertex( ExprPtr stream )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEmitStreamVertex
			, std::move( stream ) );
	}

	IntrinsicCallPtr makeEndStreamPrimitive( ExprPtr stream )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEndStreamPrimitive
			, std::move( stream ) );
	}

	IntrinsicCallPtr makeEmitVertex( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEmitVertex );
	}

	IntrinsicCallPtr makeEndPrimitive( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eEndPrimitive );
	}

	// Shader Invocation Control Functions

	IntrinsicCallPtr makeBarrier( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eBarrier );
	}

	// Shader Memory Control Functions

	IntrinsicCallPtr makeMemoryBarrier( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eUInt )
			, Intrinsic::eMemoryBarrier );
	}

	IntrinsicCallPtr makeMemoryBarrierBuffer( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierBuffer );
	}

	IntrinsicCallPtr makeMemoryBarrierShared( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierShared );
	}

	IntrinsicCallPtr makeMemoryBarrierImage( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eMemoryBarrierImage );
	}

	IntrinsicCallPtr makeGroupMemoryBarrier( )
	{
		return makeIntrinsicCall( makeType( type::Kind::eVoid )
			, Intrinsic::eGroupMemoryBarrier );
	}
}
