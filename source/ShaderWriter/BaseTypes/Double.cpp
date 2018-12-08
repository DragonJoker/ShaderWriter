/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Double.hpp"

#include "ShaderWriter/BaseTypes/Bool.hpp"

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
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	expr::ExprPtr Double::makeCondition()const
	{
		return sdw::makeNEqual( makeExpr( *this )
			, makeExpr( 0.0 ) );
	}

	Double & Double::operator=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator=( double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator=( long double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getDouble()
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
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator-=( Double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator*=( Double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator/=( Double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator+=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator-=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator*=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator/=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getDouble()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Double & Double::operator+=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Double & Double::operator-=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Double & Double::operator*=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Double & Double::operator/=( Optional< Double > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getDouble()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	ast::type::TypePtr Double::makeType( ast::type::TypesCache & cache )
	{
		return cache.getDouble();
	}

	//*************************************************************************

	Double operator+( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator-( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator*( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator/( Double const & lhs, Double const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator+( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator-( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator*( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator/( Double const & lhs, float const & rhs )
	{
		return Double{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator+( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator-( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator*( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Double operator/( float const & lhs, Double const & rhs )
	{
		return Double{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************

	Optional< Double > operator+( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Double const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Optional< Double > const & lhs, Double const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Optional< Double > const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( float const & lhs, Optional< Double > const & rhs )
	{
		return Optional< Double >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator+( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator-( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator*( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getDouble()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Double > operator/( Optional< Double > const & lhs, float const & rhs )
	{
		return Optional< Double >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getDouble()
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
