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
	static uint32_t constexpr UnknownArraySize = ~0u;

	class Array
		: public Type
	{
	public:
		SDAST_API explicit Array( TypePtr type
			, uint32_t arraySize = UnknownArraySize );
		SDAST_API Array( Struct * parent
			, uint32_t index
			, TypePtr type
			, Array const & nonMbr );
		SDAST_API Array( Struct & parent
			, uint32_t index
			, TypePtr type
			, Array const & nonMbr );
		SDAST_API TypePtr getMemberType( Struct & parent, uint32_t index )const override;

		inline TypePtr getType()const
		{
			return m_type;
		}

		inline uint32_t getArraySize()const
		{
			return m_arraySize;
		}

	private:
		TypePtr m_type;
		uint32_t m_arraySize;
	};
	using ArrayPtr = std::shared_ptr< Array >;

	SDAST_API size_t getHash( TypePtr type
		, uint32_t arraySize )noexcept;

	SDAST_API bool operator==( Array const & lhs, Array const & rhs )noexcept;
}

#endif
