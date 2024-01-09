/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLiteral.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, bool value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eBool }
	{
		m_value.boolv = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, signed char value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt8 }
	{
		m_value.int8v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, signed short value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt16 }
	{
		m_value.int16v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, signed int value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt32 }
	{
		m_value.int32v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, signed long value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt32 }
	{
		m_value.int32v = int32_t( value );
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, signed long long value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt64 }
	{
		m_value.int64v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, unsigned char value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt8 }
	{
		m_value.uint8v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, unsigned short value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt16 }
	{
		m_value.uint16v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, unsigned int value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt32 }
	{
		m_value.uint32v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, unsigned long value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt32 }
	{
		m_value.uint32v = uint32_t( value );
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, unsigned long long value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt64 }
	{
		m_value.uint64v = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, float value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eFloat }
	{
		m_value.floatv = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, type::TypePtr type
		, double value )
		: Expr{ exprCache, sizeof( Literal ), typesCache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eDouble }
	{
		m_value.doublev = value;
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, bool value )
		: Literal{ exprCache, typesCache, typesCache.getBool(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, signed char value )
		: Literal{ exprCache, typesCache, typesCache.getInt8(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, signed short value )
		: Literal{ exprCache, typesCache, typesCache.getInt16(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, signed int value )
		: Literal{ exprCache, typesCache, typesCache.getInt32(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, signed long value )
		: Literal{ exprCache, typesCache, typesCache.getInt32(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, signed long long value )
		: Literal{ exprCache, typesCache, typesCache.getInt64(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, unsigned char value )
		: Literal{ exprCache, typesCache, typesCache.getUInt8(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, unsigned short value )
		: Literal{ exprCache, typesCache, typesCache.getUInt16(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, unsigned int value )
		: Literal{ exprCache, typesCache, typesCache.getUInt32(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, unsigned long value )
		: Literal{ exprCache, typesCache, typesCache.getUInt32(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, unsigned long long value )
		: Literal{ exprCache, typesCache, typesCache.getUInt64(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, float value )
		: Literal{ exprCache, typesCache, typesCache.getFloat(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache
		, type::TypesCache & typesCache
		, double value )
		: Literal{ exprCache, typesCache, typesCache.getDouble(), value }
	{
	}

	Literal::Literal( ExprCache & exprCache, Literal const & rhs )
		: Expr{ exprCache, sizeof( Literal ), rhs.getTypesCache(), rhs.getType(), Kind::eLiteral, Flag( rhs.getFlags() ) }
		, m_valueType{ rhs.m_valueType }
		, m_value{ rhs.m_value }
	{
	}

	void Literal::accept( VisitorPtr vis )const
	{
		vis->visitLiteralExpr( this );
	}

	LiteralPtr Literal::castTo( LiteralType type )const
	{
		return details::replaceLiteral< details::CastLiteral >( getExprCache()
			, getTypesCache()
			, type
			, *this );
	}

	LiteralPtr operator~( Literal const & operand )
	{
		return details::replaceLiteral< details::BitNegateLiteral >( operand.getExprCache()
			, operand.getTypesCache()
			, operand );
	}

	LiteralPtr operator|( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::BitOrLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator&( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::BitAndLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator^( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::BitXorLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator!( Literal const & operand )
	{
		return details::replaceLiteral< details::LogNegateLiteral >( operand.getExprCache()
			, operand.getTypesCache()
			, operand );
	}

	LiteralPtr operator||( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::LogOrLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator&&( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::LogAndLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator-( Literal const & operand )
	{
		return details::replaceLiteral< details::ArithNegateLiteral >( operand.getExprCache()
			, operand.getTypesCache()
			, operand );
	}

	LiteralPtr operator+( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::AddLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator-( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::SubtractLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator*( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::MultiplyLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator/( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::DivideLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator%( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::ModuloLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator<<( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::LShiftLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator>>( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::RShiftLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator==( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompEqualLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator!=( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompNEqualLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator<( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompLessLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator<=( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompLEqualLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator>( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompGreaterLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator>=( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompGEqualLiterals >( lhs.getExprCache()
			, lhs.getTypesCache()
			, lhs
			, rhs );
	}

	LiteralPtr preInc( Literal const & op )
	{
		return details::replaceLiteral< details::PreIncrementLiteral >(op.getExprCache()
			, op.getTypesCache()
			, op );
	}

	LiteralPtr preDec( Literal const & op )
	{
		return details::replaceLiteral< details::PreDecrementLiteral >(op.getExprCache()
			, op.getTypesCache()
			, op );
	}
}
