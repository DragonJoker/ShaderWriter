#include "ShaderWriter/Bool.hpp"

#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprLiteral.hpp>
#include <ASTGenerator/Expr/ExprLogAnd.hpp>
#include <ASTGenerator/Expr/ExprLogOr.hpp>
#include <ASTGenerator/Expr/ExprNotEqual.hpp>

namespace sdw
{
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
			addStmt( *findContainer( *this, rhs )
				, stmt::makeSimple( expr::makeAssign( type::getBool()
					, makeExpr( *this )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
		}

		return *this;
	}

	Boolean & Boolean::operator=( bool rhs )
	{
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getBool()
				, makeExpr( *this )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Boolean::operator bool()
	{
		return false;
	}

	Boolean operator==( Value const & lhs, Value const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, expr::makeEqual( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator!=( Value const & lhs, Value const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, expr::makeNotEqual( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator||( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, expr::makeLogOr( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	Boolean operator&&( Boolean const & lhs, Boolean const & rhs )
	{
		return Boolean{ findShader( lhs, rhs )
			, expr::makeLogAnd( makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}
}
