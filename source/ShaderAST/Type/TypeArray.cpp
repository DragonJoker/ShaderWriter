/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypeArray.hpp"
#include "ShaderAST/Type/TypeStruct.hpp"

#include <algorithm>

namespace ast::type
{
	//*************************************************************************

	Array::Array( Struct * parent
		, uint32_t index
		, TypePtr type
		, uint32_t arraySize )
		: Type{ parent, index, Kind::eArray }
		, m_type{ std::move( type ) }
		, m_arraySize{ arraySize }
	{
		assert( m_arraySize > NotArray && "Can't create a 0 sized array" );
	}

	Array::Array( TypePtr type
		, uint32_t arraySize )
		: Type{ Kind::eArray }
		, m_type{ std::move( type ) }
		, m_arraySize{ arraySize }
	{
		assert( m_arraySize > NotArray && "Can't create a 0 sized array" );
	}

	//*************************************************************************

	bool operator==( Array const & lhs, Array const & rhs )
	{
		return *lhs.getType() == *rhs.getType()
			&& lhs.getArraySize() == rhs.getArraySize();
	}

	//*************************************************************************
}
