/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	Bool::Bool( Shader * shader
		, expr::ExprPtr expr )
		: Value{ shader, std::move( expr ) }
	{
	}

	Bool::Bool( Bool && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Bool::Bool( Bool const & rhs )
		: Value{ rhs }
	{
	}

	Bool::Bool( Value const & rhs )
		: Value{ rhs }
	{
	}

	Bool & Bool::operator=( Bool const & rhs )
	{
		if ( getContainer() )
		{
			Shader & shader = *findShader( *this, rhs );
			addStmt( shader
				, sdw::makeSimple( sdw::makeAssign( getType()
					, makeExpr( shader, *this )
					, makeExpr( shader, rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	expr::ExprPtr Bool::makeCondition()const
	{
		return makeExpr( *findShader( *this ), *this );
	}

	Bool & Bool::operator=( bool rhs )
	{
		Shader & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( getType()
				, makeExpr( shader, *this )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	Bool::operator bool()
	{
		return false;
	}

	ast::type::TypePtr Bool::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBool();
	}

	//*************************************************************************

	Bool operator==( Bool const & lhs, Bool const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeEqual );
	}

	Bool operator!=( Bool const & lhs, Bool const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeNEqual );
	}

	Bool operator||( Bool const & lhs, Bool const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogOr );
	}

	Bool operator&&( Bool const & lhs, Bool const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogAnd );
	}

	Optional< Bool > operator||( Optional< Bool > const & lhs, Bool const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogOr );
	}

	Optional< Bool > operator&&( Optional< Bool > const & lhs, Bool const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogAnd );
	}

	Optional< Bool > operator||( Bool const & lhs, Optional< Bool > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogOr );
	}

	Optional< Bool > operator&&( Bool const & lhs, Optional< Bool > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogAnd );
	}

	Optional< Bool > operator||( Optional< Bool > const & lhs, Optional< Bool > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogOr );
	}

	Optional< Bool > operator&&( Optional< Bool > const & lhs, Optional< Bool > const & rhs )
	{
		return writeComparator( lhs, rhs, sdw::makeLogAnd );
	}

	//*************************************************************************
}
