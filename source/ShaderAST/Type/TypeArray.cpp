/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeArray.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

#include <algorithm>

namespace ast::type
{
	//*************************************************************************

	Array::Array( TypePtr type
		, uint32_t arraySize
		, bool needsExplicitLayout )
		: Type{ type->getTypesCache(), Kind::eArray, needsExplicitLayout }
		, m_type{ std::move( type ) }
		, m_arraySize{ arraySize }
	{
		if ( m_arraySize == NotArray )
		{
			throw Exception{ "Can't create a 0 sized array" };
		}
	}

	Array::Array( Struct * parent
		, uint32_t index
		, TypePtr type
		, ArrayPtr nonMbr )
		: Type{ type->getTypesCache(), parent, index, nonMbr }
		, m_type{ std::move( type ) }
		, m_arraySize{ nonMbr->getArraySize() }
	{
	}

	Array::Array( Struct & parent
		, uint32_t index
		, TypePtr type
		, ArrayPtr nonMbr )
		: Array{ &parent, index, type, nonMbr }
	{
	}

	//*************************************************************************

	size_t getHash( TypePtr type
		, uint32_t arraySize
		, bool needsExplicitLayout )noexcept
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, arraySize );
		result = hashCombine( result, needsExplicitLayout );
		return result;
	}

	bool operator==( Array const & lhs, Array const & rhs )noexcept
	{
		return *lhs.getType() == *rhs.getType()
			&& lhs.getArraySize() == rhs.getArraySize();
	}

	//*************************************************************************
}
