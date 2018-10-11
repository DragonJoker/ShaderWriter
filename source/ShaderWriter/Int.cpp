#include "ShaderWriter/Int.hpp"

#include "ShaderWriter/UInt.hpp"

#include <ASTGenerator/Expr/ExprAndAssign.hpp>
#include <ASTGenerator/Expr/ExprBitAnd.hpp>
#include <ASTGenerator/Expr/ExprBitNot.hpp>
#include <ASTGenerator/Expr/ExprBitOr.hpp>
#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprLiteral.hpp>
#include <ASTGenerator/Expr/ExprLShift.hpp>
#include <ASTGenerator/Expr/ExprLShiftAssign.hpp>
#include <ASTGenerator/Expr/ExprOrAssign.hpp>
#include <ASTGenerator/Expr/ExprPostDecrement.hpp>
#include <ASTGenerator/Expr/ExprPostIncrement.hpp>
#include <ASTGenerator/Expr/ExprPreDecrement.hpp>
#include <ASTGenerator/Expr/ExprPreIncrement.hpp>
#include <ASTGenerator/Expr/ExprRShift.hpp>
#include <ASTGenerator/Expr/ExprRShiftAssign.hpp>

namespace sdw
{
	Int::Int( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	Int::Int( Int && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	Int::Int( Int const & rhs )
		: Value{ rhs }
	{
	}

	Int::Int( Value const & rhs )
		: Value{ rhs }
	{
	}

	Int & Int::operator=( Int const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( type::getInt()
					, makeExpr( m_expr )
					, makeExpr( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
			m_container = rhs.m_container;
		}

		return *this;
	}

	Int & Int::operator=( int32_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator=( int64_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	Int & Int::operator=( uint32_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( int32_t( rhs ) ) ) ) );
		return *this;
	}

	Int & Int::operator=( uint64_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( int64_t( rhs ) ) ) ) );
		return *this;
	}

	Int::operator uint32_t()
	{
		return 0u;
	}

	Int & Int::operator++()
	{
		m_expr = expr::makePreIncrement( std::move( m_expr ) );
		return *this;
	}

	Int Int::operator++( int )
	{
		return Int{ m_container, expr::makePostIncrement( std::move( m_expr ) ) };
	}

	Int & Int::operator--()
	{
		m_expr = expr::makePreDecrement( std::move( m_expr ) );
		return *this;
	}

	Int Int::operator--( int )
	{
		return Int{ m_container, expr::makePostDecrement( std::move( m_expr ) ) };
	}

	inline Int & Int::operator<<=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator>>=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator<<=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator>>=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator<<=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeLShiftAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator>>=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeRShiftAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator&=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator|=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator&=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator|=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator&=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAndAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int & Int::operator|=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeOrAssign( type::getInt()
				, makeExpr( m_expr )
				, makeExpr( rhs ) ) ) );
		return *this;
	}

	inline Int operator<<( Int const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator>>( Int const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator<<( Int const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator>>( Int const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator<<( Int const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeLShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator>>( Int const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeRShift( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator&( Int const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator|( Int const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator&( Int const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator|( Int const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator&( Int const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitAnd( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator|( Int const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitOr( type::getInt()
				, makeExpr( lhs )
				, makeExpr( rhs ) ) };
	}

	inline Int operator~( Int const & expr )
	{
		return Int{ expr.m_container
			, expr::makeBitNot( type::getInt()
				, makeExpr( expr ) ) };
	}
}
