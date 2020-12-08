/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Bool.hpp"

namespace sdw
{
	//*************************************************************************

	Boolean::Boolean( ShaderWriter & writer
		, expr::ExprPtr expr )
		: Value{ writer, std::move( expr ) }
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

	Boolean::Boolean( bool rhs )
		: Value{ sdw::getCurrentWriter(), makeExpr( sdw::getCurrentWriter(), rhs ) }
	{
	}

	Boolean::Boolean( Value rhs )
		: Value{ ctorCast< Boolean, 1u >( std::move( rhs ) ) }
	{
	}

	Boolean & Boolean::operator=( Boolean const & rhs )
	{
		if ( getContainer() )
		{
			ShaderWriter & writer = *findWriter( *this, rhs );
			addStmt( writer
				, sdw::makeSimple( sdw::makeAssign( getType()
					, makeExpr( writer, *this )
					, makeExpr( writer, rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	Boolean & Boolean::operator=( Optional< Boolean > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( getContainer() )
			{
				ShaderWriter & writer = *findWriter( *this, rhs );
				addStmt( writer
					, sdw::makeSimple( sdw::makeAssign( getType()
						, makeExpr( writer, *this )
						, makeExpr( writer, rhs ) ) ) );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	Boolean & Boolean::operator=( MaybeOptional< Boolean > const & rhs )
	{
		if ( rhs.isEnabled() )
		{
			if ( getContainer() )
			{
				ShaderWriter & writer = *findWriter( *this, rhs );
				addStmt( writer
					, sdw::makeSimple( sdw::makeAssign( getType()
						, makeExpr( writer, *this )
						, makeExpr( writer, rhs ) ) ) );
			}
			else
			{
				Value::operator=( rhs );
			}
		}

		return *this;
	}

	expr::ExprPtr Boolean::makeCondition()const
	{
		return makeExpr( *findWriter( *this ), *this );
	}

	Boolean & Boolean::operator=( bool rhs )
	{
		ShaderWriter & writer = *findWriter( *this, rhs );
		addStmt( writer
			, sdw::makeSimple( sdw::makeAssign( getType()
				, makeExpr( writer, *this )
				, makeExpr( writer, rhs ) ) ) );
		return *this;
	}

	Boolean Boolean::operator!()
	{
		ShaderWriter & writer = *findWriter( *this );
		return Boolean{ writer, sdw::makeLogNot( makeCondition() ) };
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
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	Boolean operator!=( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	Boolean operator||( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogOr );
	}

	Boolean operator&&( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogAnd );
	}

	Optional< Boolean > operator||( Optional< Boolean > const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogOr );
	}

	Optional< Boolean > operator&&( Optional< Boolean > const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogAnd );
	}

	Optional< Boolean > operator||( Boolean const & lhs, Optional< Boolean > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogOr );
	}

	Optional< Boolean > operator&&( Boolean const & lhs, Optional< Boolean > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogAnd );
	}

	Optional< Boolean > operator||( Optional< Boolean > const & lhs, Optional< Boolean > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogOr );
	}

	Optional< Boolean > operator&&( Optional< Boolean > const & lhs, Optional< Boolean > const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogAnd );
	}

	//*************************************************************************
}
