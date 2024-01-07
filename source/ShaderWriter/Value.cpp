/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Value.hpp"
#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Expr/ExprAddAssign.hpp>
#include <ShaderAST/Expr/ExprAssign.hpp>
#include <ShaderAST/Expr/ExprDivideAssign.hpp>
#include <ShaderAST/Expr/ExprIdentifier.hpp>
#include <ShaderAST/Expr/ExprLiteral.hpp>
#include <ShaderAST/Expr/ExprMinusAssign.hpp>
#include <ShaderAST/Expr/ExprTimesAssign.hpp>
#include <ShaderAST/Stmt/StmtSimple.hpp>
#include <ShaderAST/ShaderBuilder.hpp>

namespace sdw
{
	//*****************************************************************************************

	Value::Value( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: m_expr{ std::move( expr ) }
		, m_writer{ &writer }
		, m_container{ m_writer->getBuilder().getContainer() }
		, m_enabled{ enabled }
	{
	}

	Value::Value( Value const & rhs )
		: Value{ findWriterMandat( rhs )
			, makeExpr( findWriterMandat( rhs ), rhs )
			, rhs.isEnabled() }
	{
	}

	Value::Value( Value && rhs )noexcept
		: Value{ findWriterMandat( rhs )
		, makeExpr( findWriterMandat( rhs ), rhs )
		, rhs.isEnabled() }
	{
		rhs.m_expr = {};
		rhs.m_enabled = {};
		rhs.m_container = {};
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
		if ( m_writer )
		{
			return m_writer->getBuilder().getContainer();
		}

		return nullptr;
	}

	void Value::updateExpr( expr::ExprPtr expr )
	{
		m_expr = std::move( expr );
	}

	ast::ShaderBuilder & Value::getBuilder()const
	{
		assert( getWriter() );
		return getWriter()->getBuilder();
	}

	void Value::doCopy( Value const & rhs )
	{
		if ( isEnabled() && rhs.isEnabled() && m_expr && !m_expr->isConstant() )
		{
			sdw::ShaderWriter & writer = sdw::findWriterMandat( *this, rhs );
			sdw::addStmt( writer
				, sdw::makeSimple( getStmtCache( writer )
					, sdw::makeAssign( getType()
						, sdw::makeExpr( writer, *this )
						, sdw::makeExpr( writer, rhs ) ) ) );
		}
	}

	void Value::doMove( Value && rhs )noexcept
	{
		try
		{
			if ( isEnabled() && rhs.isEnabled() && m_expr && !m_expr->isConstant() )
			{
				sdw::ShaderWriter & writer = sdw::findWriterMandat( *this, rhs );
				sdw::addStmt( writer
					, sdw::makeSimple( getStmtCache( writer )
						, sdw::makeAssign( getType()
							, sdw::makeExpr( writer, *this )
							, std::move( rhs.m_expr ) ) ) );
			}
		}
		catch ( ... )
		{
		}
	}

	//*****************************************************************************************

	expr::ExprPtr getDummyExpr( ShaderWriter const & writer
		, type::TypePtr type )
	{
		return getBuilder( writer ).getDummyExpr( type );
	}

	expr::ExprPtr makeExpr( Value const & variable
		, bool force )
	{
		assert( variable.getWriter() && "Can't use this overload of makeExpr if the Value doesn't have a Shader" );
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
