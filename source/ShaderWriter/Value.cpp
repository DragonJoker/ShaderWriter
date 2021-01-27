/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Value.hpp"

#include <ShaderAST/Expr/ExprAddAssign.hpp>
#include <ShaderAST/Expr/ExprAssign.hpp>
#include <ShaderAST/Expr/ExprDivideAssign.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Expr/ExprMinusAssign.hpp>
#include <ShaderAST/Expr/ExprTimesAssign.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/Shader.hpp>

namespace sdw
{
	//*****************************************************************************************

	Value::Value( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: m_expr{ std::move( expr ) }
		, m_writer{ &writer }
		, m_shader{ &sdw::getShader( *m_writer ) }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
		, m_enabled{ enabled }
	{
	}

	Value::Value( Value const & rhs )
		: m_expr{ makeExpr( *rhs.m_writer, rhs ) }
		, m_writer{ rhs.m_writer }
		, m_shader{ rhs.m_shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	Value::Value( Value && rhs )
		: m_expr( std::move( rhs.m_expr ) )
		, m_writer{ rhs.m_writer }
		, m_shader{ rhs.m_shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
		, m_enabled{ rhs.isEnabled() }
	{
	}

	Value::~Value()
	{
	}

	Value & Value::operator=( Value const & rhs )
	{
		assert( getComponentCount( getNonArrayType( getType() ) ) * getArraySize( getType() ) == getComponentCount( getNonArrayType( rhs.getType() ) ) * getArraySize( rhs.getType() )
			&& getComponentType( getNonArrayType( getType() ) ) == getComponentType( getNonArrayType( rhs.getType() ) )
			&& "Can't assign variables with non matching types" );
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

	expr::ExprPtr getDummyExpr( ShaderWriter const & writer
		, type::TypePtr type )
	{
		return getShader( writer ).getDummyExpr( type );
	}

	expr::ExprPtr makeExpr( Value const & variable
		, bool force )
	{
		assert( variable.getShader() && "Can't use this overload of makeExpr if the Value doesn't have a Shader" );
		return makeExpr( *variable.getWriter()
			, variable.getExpr()
			, force );
	}

	expr::ExprPtr makeExpr( ShaderWriter const & writer
		, Value const & value
		, bool force )
	{
		if ( value.isEnabled() || force )
		{
			return makeExpr( writer
				, value.getExpr()
				, force );
		}

		return getDummyExpr( writer, value.getType() );
	}

	expr::ExprList makeFnArg( ShaderWriter const & writer
		, Value const & variable )
	{
		expr::ExprList result;
		result.emplace_back( makeExpr( writer
			, variable.getExpr()
			, true ) );
		return result;
	}

	//*****************************************************************************************
}
