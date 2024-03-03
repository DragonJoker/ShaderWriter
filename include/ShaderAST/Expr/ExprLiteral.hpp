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
		static type::Kind constexpr typeKind{ type::Kind::eBoolean };
		using type = bool;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt8 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eInt8 };
		using type = signed char;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt16 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eInt16 };
		using type = signed short;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt32 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eInt32 };
		using type = signed int;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eInt64 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eInt64 };
		using type = signed long long;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt8 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eUInt8 };
		using type = unsigned char;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt16 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eUInt16 };
		using type = unsigned short;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt32 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eUInt32 };
		using type = unsigned int;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eUInt64 >
	{
		static type::Kind constexpr typeKind{ type::Kind::eUInt64 };
		using type = unsigned long long;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eFloat >
	{
		static type::Kind constexpr typeKind{ type::Kind::eFloat };
		using type = float;
	};

	template<>
	struct LiteralValueTraits< LiteralType::eDouble >
	{
		static type::Kind constexpr typeKind{ type::Kind::eDouble };
		using type = double;
	};

	template< LiteralType T >
	using LiteralValueType = typename LiteralValueTraits< T >::type;
	template< LiteralType T >
	inline type::Kind constexpr literalValueKind = LiteralValueTraits< T >::typeKind;

	using LitBool = LiteralValueType< LiteralType::eBool >;
	using LitInt8 = LiteralValueType< LiteralType::eInt8 >;
	using LitInt16 = LiteralValueType< LiteralType::eInt16 >;
	using LitInt32 = LiteralValueType< LiteralType::eInt32 >;
	using LitInt64 = LiteralValueType< LiteralType::eInt64 >;
	using LitUInt8 = LiteralValueType< LiteralType::eUInt8 >;
	using LitUInt16 = LiteralValueType< LiteralType::eUInt16 >;
	using LitUInt32 = LiteralValueType< LiteralType::eUInt32 >;
	using LitUInt64 = LiteralValueType< LiteralType::eUInt64 >;
	using LitFloat32 = LiteralValueType< LiteralType::eFloat >;
	using LitFloat64 = LiteralValueType< LiteralType::eDouble >;

	class Literal
		: public Expr
	{
	public:
		union Value
		{
			LitBool boolv;
			LitInt8 int8v;
			LitInt16 int16v;
			LitInt32 int32v;
			LitInt64 int64v;
			LitUInt8 uint8v;
			LitUInt16 uint16v;
			LitUInt32 uint32v;
			LitUInt64 uint64v;
			LitFloat32 floatv;
			LitFloat64 doublev;
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

		SDAST_API void accept( VisitorPtr vis )const override;

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
