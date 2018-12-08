/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLiteral_H___
#define ___AST_ExprLiteral_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	enum class LiteralType
	{
		eBool,
		eInt,
		eUInt,
		eFloat,
		eDouble,
	};

	template< LiteralType T >
	struct LiteralValueTraits;

	template<>
	struct LiteralValueTraits< LiteralType::eBool >
	{
		using type = bool;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt >
	{
		using type = int32_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt >
	{
		using type = uint32_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eFloat >
	{
		using type = float;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eDouble >
	{
		using type = double;
	};

	template< LiteralType T >
	using LiteralValueType = typename LiteralValueTraits< T >::type;

	union LiteralValue
	{
		bool boolv;
		int32_t intv;
		uint32_t uintv;
		float floatv;
		double doublev;
	};

	class Literal
		: public Expr
	{
	private:
		Literal( type::TypePtr type, bool value );
		Literal( type::TypePtr type, int32_t value );
		Literal( type::TypePtr type, uint32_t value );
		Literal( type::TypePtr type, float value );
		Literal( type::TypePtr type, double value );

	public:
		Literal( type::TypesCache & cache, bool value );
		Literal( type::TypesCache & cache, int32_t value );
		Literal( type::TypesCache & cache, uint32_t value );
		Literal( type::TypesCache & cache, float value );
		Literal( type::TypesCache & cache, double value );

		void accept( VisitorPtr vis )override;

		inline LiteralType getLiteralType()const
		{
			return m_valueType;
		}

		template< LiteralType T >
		inline LiteralValueType< T > getValue()const;

	private:
		LiteralType m_valueType;
		LiteralValue m_value;
	};
	using LiteralPtr = std::unique_ptr< Literal >;

	template< typename T >
	inline LiteralPtr makeLiteral( type::TypesCache & cache
		, T value )
	{
		return std::make_unique< Literal >( cache, value );
	}

	LiteralPtr operator~( Literal const & operand );
	LiteralPtr operator|( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator&( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator^( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator!( Literal const & operand );
	LiteralPtr operator||( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator&&( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator-( Literal const & operand );
	LiteralPtr operator+( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator-( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator*( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator/( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator%( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator<<( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator>>( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator==( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator!=( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator<( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator<=( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator>( Literal const & lhs, Literal const & rhs );
	LiteralPtr operator>=( Literal const & lhs, Literal const & rhs );
}

#include "ExprLiteral.inl"

#endif
