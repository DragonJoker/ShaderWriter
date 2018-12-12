/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Value.hpp"

#include "ShaderWriter/Shader.hpp"
#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

#include <ShaderAST/Expr/ExprAddAssign.hpp>
#include <ShaderAST/Expr/ExprAssign.hpp>
#include <ShaderAST/Expr/ExprDivideAssign.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Expr/ExprMinusAssign.hpp>
#include <ShaderAST/Expr/ExprTimesAssign.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>

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
		, m_expr{ makeExpr( *findShader( rhs ), rhs ) }
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

	expr::ExprPtr makeExpr( Shader const & shader
		, Value const & variable
		, bool force )
	{
		return makeExpr( shader
			, variable.getExpr()
			, force );
	}

	expr::ExprList makeFnArg( Shader const & shader
		, Value const & variable )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( shader
			, variable.getExpr()
			, true ) );
		return result;
	}

	//*****************************************************************************************
}
