/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprLiteral.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, bool value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eBool }
	{
		m_value.boolv = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, signed char value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt8 }
	{
		m_value.int8v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, signed short value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt16 }
	{
		m_value.int16v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, signed int value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt32 }
	{
		m_value.int32v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, signed long value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt32 }
	{
		m_value.int32v = int32_t( value );
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, signed long long value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eInt64 }
	{
		m_value.int64v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, unsigned char value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt8 }
	{
		m_value.uint8v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, unsigned short value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt16 }
	{
		m_value.uint16v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, unsigned int value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt32 }
	{
		m_value.uint32v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, unsigned long value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt32 }
	{
		m_value.uint32v = uint32_t( value );
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, unsigned long long value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eUInt64 }
	{
		m_value.uint64v = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, float value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eFloat }
	{
		m_value.floatv = value;
	}

	Literal::Literal( type::TypesCache & cache
		, type::TypePtr type
		, double value )
		: Expr{ cache, std::move( type ), Kind::eLiteral, Flag::eConstant }
		, m_valueType{ LiteralType::eDouble }
	{
		m_value.doublev = value;
	}

	Literal::Literal( type::TypesCache & cache, bool value )
		: Literal{ cache, cache.getBool(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, signed char value )
		: Literal{ cache, cache.getInt8(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, signed short value )
		: Literal{ cache, cache.getInt16(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, signed int value )
		: Literal{ cache, cache.getInt32(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, signed long value )
		: Literal{ cache, cache.getInt32(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, signed long long value )
		: Literal{ cache, cache.getInt64(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, unsigned char value )
		: Literal{ cache, cache.getUInt8(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, unsigned short value )
		: Literal{ cache, cache.getUInt16(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, unsigned int value )
		: Literal{ cache, cache.getUInt32(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, unsigned long value )
		: Literal{ cache, cache.getUInt32(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, unsigned long long value )
		: Literal{ cache, cache.getUInt64(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, float value )
		: Literal{ cache, cache.getFloat(), value }
	{
	}

	Literal::Literal( type::TypesCache & cache, double value )
		: Literal{ cache, cache.getDouble(), value }
	{
	}

	void Literal::accept( VisitorPtr vis )
	{
		vis->visitLiteralExpr( this );
	}

	LiteralPtr operator~( Literal const & operand )
	{
		return details::replaceLiteral< details::BitNegateLiteral >( operand.getCache()
			, operand );
	}

	LiteralPtr operator|( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::BitOrLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator&( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::BitAndLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator^( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::BitXorLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator!( Literal const & operand )
	{
		return details::replaceLiteral< details::LogNegateLiteral >( operand.getCache()
			, operand );
	}

	LiteralPtr operator||( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::LogOrLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator&&( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::LogAndLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator-( Literal const & operand )
	{
		return details::replaceLiteral< details::ArithNegateLiteral >( operand.getCache()
			, operand );
	}

	LiteralPtr operator+( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::AddLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator-( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::SubtractLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator*( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::MultiplyLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator/( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::DivideLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator%( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::ModuloLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator<<( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::LShiftLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator>>( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::RShiftLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator==( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompEqualLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator!=( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompNEqualLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator<( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompLessLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator<=( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompLEqualLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator>( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompGreaterLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}

	LiteralPtr operator>=( Literal const & lhs, Literal const & rhs )
	{
		return details::replaceLiterals< details::CompGEqualLiterals >( lhs.getCache()
			, lhs
			, rhs );
	}
}
