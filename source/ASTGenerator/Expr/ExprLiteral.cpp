/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprLiteral.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast
{
	ExprLiteral::ExprLiteral( bool value )
		: Expr{ Type::eBoolean, Kind::eLiteral }
		, m_valueType{ ValueType::eBool }
	{
		m_value.boolv = value;
	}

	ExprLiteral::ExprLiteral( int32_t value )
		: Expr{ Type::eInt, Kind::eLiteral }
		, m_valueType{ ValueType::eInt }
	{
		m_value.intv = value;
	}

	ExprLiteral::ExprLiteral( uint32_t value )
		: Expr{ Type::eUInt, Kind::eLiteral }
		, m_valueType{ ValueType::eUInt }
	{
		m_value.uintv = value;
	}

	ExprLiteral::ExprLiteral( float value )
		: Expr{ Type::eFloat, Kind::eLiteral }
		, m_valueType{ ValueType::eFloat }
	{
		m_value.floatv = value;
	}

	void ExprLiteral::accept( ExprVisitorPtr vis )
	{
		vis->visitLiteralExpr( this );
	}
}
