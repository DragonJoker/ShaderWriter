/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	Boolean::Boolean( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Boolean::Boolean( Boolean && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Boolean::Boolean( Boolean const & rhs )
		: Value{ rhs }
	{
	}

	Boolean::Boolean( Value const & rhs )
		: Value{ rhs }
	{
	}

	Boolean & Boolean::operator=( Boolean const & rhs )
	{
		if ( getContainer() )
		{
			addStmt( *findShader( *this, rhs )
				, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getBool()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	expr::ExprPtr Boolean::makeCondition()const
	{
		return makeExpr( *this );
	}

	Boolean & Boolean::operator=( bool rhs )
	{
		addStmt( *findShader( *this, rhs )
			, sdw::makeSimple( sdw::makeAssign( findTypesCache( *this, rhs ).getBool()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Boolean::operator bool()
	{
		return false;
	}

	ast::type::TypePtr Boolean::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBool();
	}

	//*************************************************************************

	Boolean operator==( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeEqual( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator!=( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeNEqual( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator||( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator&&( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Optional< Boolean > operator||( Optional< Boolean > const & lhs, Boolean const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator&&( Optional< Boolean > const & lhs, Boolean const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs, true )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator||( Boolean const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator&&( Boolean const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator||( Optional< Boolean > const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogOr( makeExpr( lhs, true )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	Optional< Boolean > operator&&( Optional< Boolean > const & lhs, Optional< Boolean > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, sdw::makeLogAnd( makeExpr( lhs, true )
				, makeExpr( rhs, true ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
