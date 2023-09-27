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
		, uint32_t arraySize )
		: Type{ type->getTypesCache(), Kind::eArray }
		, m_type{ std::move( type ) }
		, m_arraySize{ arraySize }
	{
		assert( m_arraySize > NotArray && "Can't create a 0 sized array" );
	}

	Array::Array( Struct * parent
		, uint32_t index
		, TypePtr type
		, Array const & nonMbr
		, uint32_t arraySize )
		: Type{ type->getTypesCache(), parent, index, nonMbr }
		, m_type{ std::move( type ) }
		, m_arraySize{ arraySize }
	{
		assert( m_arraySize > NotArray && "Can't create a 0 sized array" );
	}

	Array::Array( Struct & parent
		, uint32_t index
		, TypePtr type
		, Array const & nonMbr
		, uint32_t arraySize )
		: Array{ &parent, index, type, nonMbr, arraySize }
	{
	}

	TypePtr Array::getMemberType( Struct & parent, uint32_t index )const
	{
		return std::make_shared< Array >( parent
			, index
			, getType()
			, *this
			, getArraySize() );
	}

	//*************************************************************************

	size_t getHash( TypePtr type
		, uint32_t arraySize )noexcept
	{
		size_t result = std::hash< TypePtr >{}( type );
		result = hashCombine( result, arraySize );
		return result;
	}

	bool operator==( Array const & lhs, Array const & rhs )noexcept
	{
		return *lhs.getType() == *rhs.getType()
			&& lhs.getArraySize() == rhs.getArraySize();
	}

	//*************************************************************************
}
