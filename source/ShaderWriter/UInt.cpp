#include "ShaderWriter/UInt.hpp"

#include "ShaderWriter/Int.hpp"

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
	UInt::UInt( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
	{
	}

	UInt::UInt( UInt && rhs )
		: Value{ std::move( rhs ) }
	{
	}

	UInt::UInt( UInt const & rhs )
		: Value{ rhs }
	{
	}

	UInt::UInt( Value const & rhs )
		: Value{ rhs }
	{
	}

	UInt & UInt::operator=( UInt const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( type::getUInt()
					, make( m_expr )
					, make( rhs ) ) ) );
		}
		else
		{
			Value::operator=( rhs );
			m_container = rhs.m_container;
		}

		return *this;
	}

	UInt & UInt::operator=( int32_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getUInt()
				, make( m_expr )
				, make( uint32_t( rhs ) ) ) ) );
		return *this;
	}

	UInt & UInt::operator=( int64_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getUInt()
				, make( m_expr )
				, make( uint64_t( rhs ) ) ) ) );
		return *this;
	}

	UInt & UInt::operator=( uint32_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	UInt & UInt::operator=( uint64_t rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	UInt::operator uint32_t()
	{
		return 0u;
	}

	UInt & UInt::operator++()
	{
		m_expr = expr::makePreIncrement( std::move( m_expr ) );
		return *this;
	}

	UInt UInt::operator++( int )
	{
		return UInt{ m_container, expr::makePostIncrement( std::move( m_expr ) ) };
	}

	UInt & UInt::operator--()
	{
		m_expr = expr::makePreDecrement( std::move( m_expr ) );
		return *this;
	}

	UInt UInt::operator--( int )
	{
		return UInt{ m_container, expr::makePostDecrement( std::move( m_expr ) ) };
	}

	inline UInt & UInt::operator<<=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeLShiftAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator>>=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeRShiftAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator<<=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeLShiftAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator>>=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeRShiftAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator<<=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeLShiftAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator>>=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeRShiftAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator&=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAndAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator|=( int rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeOrAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator&=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAndAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator|=( Int const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeOrAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator&=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAndAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt & UInt::operator|=( UInt const & rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeOrAssign( type::getUInt()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	inline UInt operator<<( UInt const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeLShift( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator>>( UInt const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeRShift( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator<<( UInt const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeLShift( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator>>( UInt const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeRShift( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator<<( UInt const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeLShift( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator>>( UInt const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeRShift( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator&( UInt const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitAnd( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator|( UInt const & lhs, int rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitOr( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator&( UInt const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitAnd( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator|( UInt const & lhs, Int const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitOr( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator&( UInt const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitAnd( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator|( UInt const & lhs, UInt const & rhs )
	{
		return Int{ lhs.m_container
			, expr::makeBitOr( type::getUInt()
				, make( lhs )
				, make( rhs ) ) };
	}

	inline UInt operator~( UInt const & expr )
	{
		return Int{ expr.m_container
			, expr::makeBitNot( type::getUInt()
				, make( expr ) ) };
	}
}
