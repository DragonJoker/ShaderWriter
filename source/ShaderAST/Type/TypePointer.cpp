/*
See LICENSE file in root folder
*/
#include "ShaderAST/Type/TypePointer.hpp"

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::type
{
	//*************************************************************************

	Pointer::Pointer( TypePtr pointerType
		, Storage storage
		, bool isForward )
		: Type{ pointerType->getCache(), Kind::ePointer }
		, m_pointerType{ std::move( pointerType ) }
		, m_storage{ storage }
		, m_isForward{ isForward }
	{
	}

	//*************************************************************************

	size_t getHash( TypePtr pointerType
		, Storage storage
		, bool isForward )
	{
		size_t result = std::hash< TypePtr >{}( pointerType );
		result = hashCombine( result, storage );
		result = hashCombine( result, isForward );
		return result;
	}

	bool operator==( Pointer const & lhs, Pointer const & rhs )
	{
		auto result = static_cast< Type const & >( lhs ) == static_cast< Type const & >( rhs )
			&& lhs.getPointerType() == rhs.getPointerType();
		return result;
	}

	//*************************************************************************
}
