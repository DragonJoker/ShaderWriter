/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLiteral_H___
#define ___AST_ExprLiteral_H___
#pragma once

#include "Expr.hpp"

namespace ast::expr
{
	class Literal
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
		Literal( bool value );
		Literal( int32_t value );
		Literal( uint32_t value );
		Literal( float value );

		void accept( VisitorPtr vis )override;

		inline ValueType getValue()const
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
	using LiteralPtr = std::unique_ptr< Literal >;

	template< typename T >
	inline LiteralPtr makeLiteral( T value )
	{
		return std::make_unique< Literal >( value );
	}
}

#endif
