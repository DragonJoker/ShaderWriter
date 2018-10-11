#include "ShaderWriter/Value.hpp"

//#include "ShaderWriter/Shader.hpp"
#include "ShaderWriter/Optional.hpp"

#include <ASTGenerator/Expr/ExprAddAssign.hpp>
#include <ASTGenerator/Expr/ExprAssign.hpp>
#include <ASTGenerator/Expr/ExprDivideAssign.hpp>
#include <ASTGenerator/Expr/ExprIdentifier.hpp>
#include <ASTGenerator/Expr/ExprLiteral.hpp>
#include <ASTGenerator/Expr/ExprMinusAssign.hpp>
#include <ASTGenerator/Expr/ExprTimesAssign.hpp>
#include <ASTGenerator/Stmt/StmtSimple.hpp>

namespace sdw
{
	//*****************************************************************************************

	Value::Value( stmt::Container * container
		, expr::ExprPtr expr )
		: m_container{ container }
		, m_expr{ std::move( expr ) }
	{
	}

	Value::Value( Value const & rhs )
		: m_container{ rhs.m_container }
		, m_expr{ makeExpr( rhs ) }
	{
	}

	Value::Value( Value && rhs )
		: m_container{ rhs.m_container }
		, m_expr( std::move( rhs.m_expr ) )
	{
	}

	Value::~Value()
	{
	}

	Value & Value::operator=( Value const & rhs )
	{
		if ( !m_container )
		{
			m_container = rhs.m_container;
		}

		return *this;
	}

	void Value::updateContainer( Value const & variable )
	{
		if ( !m_container )
		{
			m_container = variable.m_container;
		}
	}

	expr::ExprPtr makeExpr( Value const & variable )
	{
		return makeExpr( variable.m_expr );
	}

	var::VariablePtr makeVar( Value const & variable )
	{
		return var::makeVariable( variable.m_expr->getType()
			, getTypeName( variable.m_expr ) );
	}

	//*****************************************************************************************
}
