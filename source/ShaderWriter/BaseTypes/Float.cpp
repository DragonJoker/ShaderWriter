/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Float.hpp"

#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	Float::Float( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Float::Float( Float && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Float::Float( Float const & rhs )
		: Value{ rhs }
	{
	}

	Float::Float( float rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Float::Float( double rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Float::Float( long double rhs )
		: Value{ nullptr, makeExpr( rhs ) }
	{
	}

	Float::Float( Value const & rhs )
		: Value{ rhs }
	{
	}

	Float & Float::operator=( Float const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	expr::ExprPtr Float::makeCondition()const
	{
		return sdw::makeNEqual( makeExpr( *this )
			, makeExpr( 0.0f ) );
	}

	Float & Float::operator=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator=( double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator=( long double const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float::operator float()
	{
		return 0.0f;
	}

	Float & Float::operator+=( Float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator-=( Float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator*=( Float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator/=( Float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator+=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator-=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator*=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator/=( float const & rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getFloat()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator+=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAddAssign( findTypesCache( *this, rhs ).getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Float & Float::operator-=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeMinusAssign( findTypesCache( *this, rhs ).getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Float & Float::operator*=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeTimesAssign( findTypesCache( *this, rhs ).getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	Float & Float::operator/=( Optional< Float > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeDivideAssign( findTypesCache( *this, rhs ).getFloat()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}

		return *this;
	}

	ast::type::TypePtr Float::makeType( ast::type::TypesCache & cache )
	{
		return cache.getFloat();
	}

	//*************************************************************************

	Float operator+( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator-( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator*( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator/( Float const & lhs, Float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator+( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator-( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator*( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator/( Float const & lhs, float const & rhs )
	{
		return Float{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator+( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator-( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator*( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Float operator/( float const & lhs, Float const & rhs )
	{
		return Float{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	//*************************************************************************

	Optional< Float > operator+( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Float >{ findShader( rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator+( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeAdd( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator-( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeMinus( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator*( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeTimes( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Float > operator/( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Float >{ findShader( lhs, rhs )
			, sdw::makeDivide( findTypesCache( lhs, rhs ).getFloat()
				, makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************

	Boolean operator==( Float const & lhs, Float const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator!=( Float const & lhs, Float const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<( Float const & lhs, Float const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator<=( Float const & lhs, Float const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>( Float const & lhs, Float const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Boolean operator>=( Float const & lhs, Float const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) ) };
	}

	Optional< Boolean > operator==( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs, true ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs, true ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs, true ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs, true ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs, true ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Float > const & lhs, Float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs, true ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Float > const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator==( Float const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator!=( Float const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<( Float const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator<=( Float const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>( Float const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Boolean operator>=( Float const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( Optional< Float > const & lhs, float const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator==( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator!=( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLess( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator<=( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGreater( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator>=( float const & lhs, Optional< Float > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeGEqual( makeExpr( lhs ), makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
