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

	Boolean::Boolean( bool rhs )
		: Value{ &sdw::getShader( sdw::getCurrentWriter() ), makeExpr( sdw::getShader( sdw::getCurrentWriter() ), rhs ) }
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

	Boolean & Boolean::operator=( Optional< Boolean > const & rhs )
	{
		if ( rhs.isEnabled() )
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
		}

		return *this;
	}

	Boolean & Boolean::operator=( MaybeOptional< Boolean > const & rhs )
	{
		if ( rhs.isEnabled() )
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
		}

		return *this;
	}

	expr::ExprPtr Boolean::makeCondition()const
	{
		return makeExpr( *findShader( *this ), *this );
	}

	Boolean & Boolean::operator=( bool rhs )
	{
		Shader & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( getType()
				, makeExpr( shader, *this )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	Boolean Boolean::operator!()
	{
		Shader & shader = *findShader( *this );
		return Boolean{ &shader, sdw::makeLogNot( makeCondition() ) };
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
