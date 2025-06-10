/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Boolean.hpp"

#include <ShaderAST/Stmt/StmtCache.hpp>

namespace sdw
{
	//*************************************************************************

	Boolean::Boolean( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	Boolean::Boolean( bool rhs )
		: Value{ sdw::getCurrentWriter(), makeExpr( sdw::getCurrentWriter(), rhs ), true }
	{
	}

	Boolean::Boolean( Value rhs )
		: Value{ ctorCast< Boolean, 1u >( std::move( rhs ) ) }
	{
	}

	expr::ExprPtr Boolean::makeCondition()const
	{
		return makeExpr( findWriterMandat( *this ), *this );
	}

	ReturnWrapperT< Boolean > Boolean::operator=( bool rhs )
	{
		ShaderWriter & writer = findWriterMandat( *this, rhs );
		return ReturnWrapperT< Boolean >{ writer
			, sdw::makeAssign( getType()
				, makeExpr( writer, *this )
				, makeExpr( writer, rhs ) )
			, isEnabled() };
	}

	ReturnWrapperT< Boolean > Boolean::operator!()const
	{
		ShaderWriter & writer = findWriterMandat( *this );
		return ReturnWrapperT< Boolean >{ writer, sdw::makeLogNot( makeCondition() ), isEnabled() };
	}

	ast::type::TypePtr Boolean::makeType( ast::type::TypesCache & cache )
	{
		return cache.getBool();
	}

	//*************************************************************************

	ReturnWrapperT< Boolean > operator==( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeEqual );
	}

	ReturnWrapperT< Boolean > operator!=( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeNEqual );
	}

	ReturnWrapperT< Boolean > operator||( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogOr );
	}

	ReturnWrapperT< Boolean > operator&&( Boolean const & lhs, Boolean const & rhs )
	{
		return writeComparator< Boolean >( lhs, rhs, sdw::makeLogAnd );
	}

	//*************************************************************************
}
