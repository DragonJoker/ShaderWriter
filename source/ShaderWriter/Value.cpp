#include "ShaderWriter/Value.hpp"

#include "ShaderWriter/Shader.hpp"
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

	Value::Value( Shader * shader
		, expr::ExprPtr expr )
		: m_shader{ shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
		, m_expr{ std::move( expr ) }
	{
	}

	Value::Value( Value const & rhs )
		: m_shader{ rhs.m_shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
		, m_expr{ makeExpr( rhs ) }
	{
	}

	Value::Value( Value && rhs )
		: m_shader{ rhs.m_shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
		, m_expr( std::move( rhs.m_expr ) )
	{
	}

	Value::~Value()
	{
	}

	Value & Value::operator=( Value const & rhs )
	{
		updateContainer( rhs );
		return *this;
	}

	void Value::updateContainer( Value const & value )
	{
		if ( !m_container )
		{
			m_container = findContainer( value );
		}
	}

	stmt::Container * Value::getContainer()const
	{
		if ( m_shader )
		{
			return m_shader->getContainer();
		}

		return nullptr;
	}

	void Value::updateExpr( expr::ExprPtr expr )
	{
		m_expr = std::move( expr );
	}

	expr::ExprPtr makeExpr( Value const & variable )
	{
		return makeExpr( variable.getExpr() );
	}

	var::VariablePtr makeVar( Value const & variable )
	{
		return var::makeVariable( variable.getType()
			, findName( variable.getExpr() ) );
	}

	//*****************************************************************************************
}
