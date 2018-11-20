/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeArray_H___
#define ___AST_TypeArray_H___
#pragma once

#include "Type.hpp"

namespace ast::type
{
	static uint32_t constexpr NotArray = 0u;
	static uint32_t constexpr UnknownArraySize = ~( 0u );

	class Array
		: public Type
	{
	public:
		Array( Struct * parent
			, uint32_t index
			, TypePtr type
			, uint32_t arraySize = UnknownArraySize )
			: Type{ parent, index, Kind::eArray }
			, m_type{ std::move( type ) }
			, m_arraySize{ arraySize }
		{
			assert( m_arraySize > NotArray && "Can't create a 0 sized array" );
		}

		Array( TypePtr type
			, uint32_t arraySize = UnknownArraySize )
			: Type{ Kind::eArray }
			, m_type{ std::move( type ) }
			, m_arraySize{ arraySize }
		{
			assert( m_arraySize > NotArray && "Can't create a 0 sized array" );
		}

		TypePtr getType()const
		{
			return m_type;
		}

		uint32_t getArraySize()const
		{
			return m_arraySize;
		}

	private:
		TypePtr m_type;
		uint32_t m_arraySize;
	};
	using ArrayPtr = std::shared_ptr< Array >;

	inline Kind getNonArrayKind( Type const & type )
	{
		return type.getKind() == type::Kind::eArray
			? static_cast< type::Array const & >( type ).getType()->getKind()
			: type.getKind();
	}

	inline Kind getNonArrayKind( TypePtr type )
	{
		return getNonArrayKind( *type );
	}

	inline uint32_t getArraySize( Type const & type )
	{
		return type.getKind() == type::Kind::eArray
			? static_cast< type::Array const & >( type ).getArraySize()
			: NotArray;
	}

	inline uint32_t getArraySize( TypePtr type )
	{
		return getArraySize( *type );
	}

	inline ArrayPtr makeArrayType( TypePtr type
		, uint32_t arraySize = UnknownArraySize )
	{
		return std::make_shared< Array >( std::move( type )
			, arraySize );
	}
}

#endif
