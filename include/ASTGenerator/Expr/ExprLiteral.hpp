/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLiteral_H___
#define ___AST_ExprLiteral_H___
#pragma once

#include "Expr.hpp"

namespace ast
{
	class ExprLiteral
		: public Expr
	{
	public:
		enum class ValueType
		{
			eBool,
			eInt,
			eUInt,
			eFloat,
		};
		template< ValueType T >
		struct ValueTraits;

		template<>
		struct ValueTraits< ValueType::eBool >
		{
			using type = bool;
		};

		template<>
		struct ValueTraits< ValueType::eInt >
		{
			using type = int32_t;
		};

		template<>
		struct ValueTraits< ValueType::eUInt >
		{
			using type = uint32_t;
		};

		template<>
		struct ValueTraits< ValueType::eFloat >
		{
			using type = float;
		};

	public:
		ExprLiteral( bool value );
		ExprLiteral( int32_t value );
		ExprLiteral( uint32_t value );
		ExprLiteral( float value );

		void accept( ExprVisitorPtr vis )override;

		inline ValueType getValueType()const
		{
			return m_valueType;
		}

		template< ValueType T >
		inline typename ValueTraits< T >::type getValue()const
		{
			if constexpr ( T == ValueType::eBool )
			{
				assert( m_valueType == ValueType::eBool );
				return m_value.boolv;
			}

			if constexpr ( T == ValueType::eInt )
			{
				assert( m_valueType == ValueType::eInt );
				return m_value.intv;
			}

			if constexpr ( T == ValueType::eUInt )
			{
				assert( m_valueType == ValueType::eUInt );
				return m_value.uintv;
			}

			if constexpr ( T == ValueType::eFloat )
			{
				assert( m_valueType == ValueType::eFloat );
				return m_value.floatv;
			}
		}

	private:
		ValueType m_valueType;
		union
		{
			bool boolv;
			int32_t intv;
			uint32_t uintv;
			float floatv;
		} m_value;
	};
	using ExprLiteralPtr = std::unique_ptr< ExprLiteral >;

	template< typename T >
	inline ExprLiteralPtr makeLiteralExpr( T value )
	{
		return std::make_unique< ExprLiteral >( value );
	}
}

#endif
