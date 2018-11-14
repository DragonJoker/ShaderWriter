/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Double.hpp"

#include "ShaderWriter/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	Double::Double( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Double::Double( Double && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Double::Double( Double const & rhs )
		: Value{ rhs }
	{
	}

	Double::Double( float rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Double::Double( double rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Double::Double( long double rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Double::Double( Value const & rhs )
		: Value{ rhs }
	{
	}

	Double & Double::operator=( Double const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( type::getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	Double & Double::operator=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator=( double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator=( long double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double::operator float()
	{
		return 0.0f;
	}

	Double & Double::operator+=( Double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator-=( Double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator*=( Double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator/=( Double const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator+=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator-=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator*=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator/=( float const & rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( type::getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator+=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( type::getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Double & Double::operator-=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( type::getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Double & Double::operator*=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( type::getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Double & Double::operator/=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findContainer( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( type::getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	Double operator+( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator-( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator*( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator/( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator+( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator-( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator*( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator/( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator+( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator-( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator*( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator/( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************

	Optional< Double > operator+( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeAdd( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeMinus( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeTimes( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeDivide( type::getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************

	Boolean operator==( Double const & lhs, Double const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator!=( Double const & lhs, Double const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<( Double const & lhs, Double const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<=( Double const & lhs, Double const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>( Double const & lhs, Double const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>=( Double const & lhs, Double const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Optional< Boolean > operator==( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator==( Double const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator!=( Double const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<( Double const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<=( Double const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>( Double const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>=( Double const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< Double > const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Double > const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Double > const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Double > const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Double > const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Double > const & lhs, double const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
