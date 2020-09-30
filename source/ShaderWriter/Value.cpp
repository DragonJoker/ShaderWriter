/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Value.hpp"

#include "ShaderWriter/MaybeOptional/MaybeOptional.hpp"

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

	Value::Value( Shader * shader
		, expr::ExprPtr expr )
		: m_expr{ std::move( expr ) }
		, m_shader{ shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
	{
	}

	Value::Value( Value const & rhs )
		: m_expr{ makeExpr( *findShader( rhs ), rhs ) }
		, m_shader{ rhs.m_shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
	{
	}

	Value::Value( Value && rhs )
		: m_expr( std::move( rhs.m_expr ) )
		, m_shader{ rhs.m_shader }
		, m_container{ m_shader ? m_shader->getContainer() : nullptr }
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

	expr::ExprPtr getDummyExpr( Shader & shader
		, type::TypePtr type )
	{
		return shader.getDummyExpr( type );
	}

	expr::ExprPtr makeExpr( Value const & variable
		, bool force )
	{
		assert( variable.getShader() && "Can't use this overload of makeExpr if the Value doesn't have a Shader" );
		return makeExpr( *variable.getShader()
			, variable.getExpr()
			, force );
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
