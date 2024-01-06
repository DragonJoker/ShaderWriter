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
		eInt8,
		eInt16,
		eInt32,
		eInt64,
		eUInt8,
		eUInt16,
		eUInt32,
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
	struct LiteralValueTraits< LiteralType::eInt8 >
	{
		using type = int8_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt16 >
	{
		using type = int16_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt32 >
	{
		using type = int32_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt64 >
	{
		using type = int64_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt8 >
	{
		using type = uint8_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt16 >
	{
		using type = uint16_t;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt32 >
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

	class Literal
		: public Expr
	{
	public:
		union Value
		{
			bool boolv;
			int8_t int8v;
			int16_t int16v;
			int32_t int32v;
			int64_t int64v;
			uint8_t uint8v;
			uint16_t uint16v;
			uint32_t uint32v;
			uint64_t uint64v;
			float floatv;
			double doublev;
		};

	private:
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, bool value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, signed char value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, signed short value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, signed int value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, signed long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, signed long long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, unsigned char value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, unsigned short value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, unsigned int value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, unsigned long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, unsigned long long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, float value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, type::TypePtr type, double value );

	public:
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, bool value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, signed char value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, signed short value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, signed int value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, signed long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, signed long long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, unsigned char value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, unsigned short value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, unsigned int value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, unsigned long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, unsigned long long value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, float value );
		SDAST_API Literal( ExprCache & exprCache, type::TypesCache & typesCache, double value );

		SDAST_API Literal( ExprCache & exprCache, Literal const & rhs );

		SDAST_API void accept( VisitorPtr vis )override;

		SDAST_API LiteralPtr castTo( LiteralType type )const;

		inline LiteralType getLiteralType()const
		{
			return m_valueType;
		}

		template< LiteralType T >
		LiteralValueType< T > getValue()const;

	private:
		LiteralType m_valueType;
		Value m_value;
	};

	template< expr::LiteralType TargetT, typename SourceT >
	expr::LiteralValueType< TargetT > convert( SourceT const & v );
	template< template< typename TypeT > typename OperatorT >
	expr::LiteralPtr replaceLiterals( type::TypesCache & typesCache
		, expr::Literal const & lhs
		, expr::Literal const & rhs );
	template< LiteralType T >
	LiteralValueType< T > getLiteralValue( Expr const & expr );

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
	SDAST_API LiteralPtr preInc( Literal const & op );
	SDAST_API LiteralPtr preDec( Literal const & op );
}

#include "ExprLiteral.inl"

#endif
