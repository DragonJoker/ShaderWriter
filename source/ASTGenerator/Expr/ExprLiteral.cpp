/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLiteral.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Literal::Literal( bool value )
		: Expr{ std::move( type::getBool() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eBool }
	{
		m_value.boolv = value;
	}

	Literal::Literal( int32_t value )
		: Expr{ std::move( type::getInt() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eInt }
	{
		m_value.intv = value;
	}

	Literal::Literal( uint32_t value )
		: Expr{ std::move( type::getUInt() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eUInt }
	{
		m_value.uintv = value;
	}

	Literal::Literal( float value )
		: Expr{ std::move( type::getFloat() ), Kind::eLiteral }
		, m_valueType{ LiteralType::eFloat }
	{
		m_value.floatv = value;
	}

	void Literal::accept( VisitorPtr vis )
	{
		vis->visitLiteralExpr( this );
	}
}
