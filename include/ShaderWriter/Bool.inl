/*
See LICENSE file in root folder
*/
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Expr/ExprEqual.hpp>
#include <ASTGenerator/Expr/ExprLess.hpp>
#include <ASTGenerator/Expr/ExprLessEqual.hpp>
#include <ASTGenerator/Expr/ExprGreater.hpp>
#include <ASTGenerator/Expr/ExprGreaterEqual.hpp>
#include <ASTGenerator/Expr/ExprNotEqual.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>

namespace sdw
{
	//*************************************************************************

	template< typename T >
	inline Boolean & Boolean::operator=( T const & rhs )
	{
		updateContainer( rhs );
		addStmt( *findContainer( *this, rhs )
			, stmt::makeSimple( expr::makeAssign( type::getBool()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeNotEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeLess( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeLessEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeGreater( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs, ValueT const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeGreaterEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator==( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeNotEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeLess( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeLessEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeGreater( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( ValueT const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeGreaterEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator==( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator!=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeNotEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeLess( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator<=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeLessEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeGreater( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	template< typename ValueT >
	Optional< Boolean > operator>=( Optional< ValueT > const & lhs, Optional< ValueT > const & rhs )
	{
		return Optional< Boolean >{ findShader( lhs, rhs )
			, expr::makeGreaterEqual( makeExpr( lhs )
				, makeExpr( rhs ) )
			, areOptionalEnabled( lhs, rhs ) };
	}

	//*************************************************************************
}
