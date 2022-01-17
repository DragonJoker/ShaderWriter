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
		eUInt64,
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
	struct LiteralValueTraits< LiteralType::eUInt64 >
	{
		using type = uint64_t;
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
		uint32_t uint32v;
		uint64_t uint64v;
		float floatv;
		double doublev;
	};

	class Literal
		: public Expr
	{
	private:
		SDAST_API Literal( type::TypesCache & cache, type::TypePtr type, bool value );
		SDAST_API Literal( type::TypesCache & cache, type::TypePtr type, int32_t value );
		SDAST_API Literal( type::TypesCache & cache, type::TypePtr type, uint32_t value );
		SDAST_API Literal( type::TypesCache & cache, type::TypePtr type, uint64_t value );
		SDAST_API Literal( type::TypesCache & cache, type::TypePtr type, float value );
		SDAST_API Literal( type::TypesCache & cache, type::TypePtr type, double value );

	public:
		SDAST_API Literal( type::TypesCache & cache, bool value );
		SDAST_API Literal( type::TypesCache & cache, int32_t value );
		SDAST_API Literal( type::TypesCache & cache, uint32_t value );
		SDAST_API Literal( type::TypesCache & cache, uint64_t value );
		SDAST_API Literal( type::TypesCache & cache, float value );
		SDAST_API Literal( type::TypesCache & cache, double value );

		SDAST_API void accept( VisitorPtr vis )override;

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

	SDAST_API LiteralPtr operator~( Literal const & operand );
	SDAST_API LiteralPtr operator|( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator&( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator^( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator!( Literal const & operand );
	SDAST_API LiteralPtr operator||( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator&&( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator-( Literal const & operand );
	SDAST_API LiteralPtr operator+( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator-( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator*( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator/( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator%( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator<<( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator>>( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator==( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator!=( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator<( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator<=( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator>( Literal const & lhs, Literal const & rhs );
	SDAST_API LiteralPtr operator>=( Literal const & lhs, Literal const & rhs );
}

#include "ExprLiteral.inl"

#endif
