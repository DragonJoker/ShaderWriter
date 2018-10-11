#include "ShaderWriter/Float.hpp"

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
	Float::Float( stmt::Container * container
		, expr::ExprPtr expr )
		: Value{ container, std::move( expr ) }
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

	Float::Float( Value const & rhs )
		: Value{ rhs }
	{
	}

	Float & Float::operator=( Float const & rhs )
	{
		if ( m_container )
		{
			addStmt( *m_container
				, stmt::makeSimple( expr::makeAssign( type::getFloat()
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

	Float & Float::operator=( float rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator=( double rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	Float & Float::operator=( long double rhs )
	{
		addStmt( *m_container
			, stmt::makeSimple( expr::makeAssign( type::getFloat()
				, make( m_expr )
				, make( rhs ) ) ) );
		return *this;
	}

	Float::operator float()
	{
		return 0.0f;
	}
}
