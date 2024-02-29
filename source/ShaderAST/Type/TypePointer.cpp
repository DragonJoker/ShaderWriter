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
		: Type{ pointerType->getTypesCache(), Kind::ePointer }
		, m_pointerType{ std::move( pointerType ) }
		, m_storage{ storage }
		, m_isForward{ isForward }
	{
	}

	//*************************************************************************

	uint32_t getPointerLevel( TypePtr type )
	{
		uint32_t result = 0u;

		while ( type->getKind() == Kind::ePointer )
		{
			++result;
			type = static_cast< Pointer const & >( *type ).getPointerType();
		}

		return result;
	}

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
		auto result = *lhs.getPointerType() == *rhs.getPointerType()
			&& lhs.getStorage() == rhs.getStorage()
			&& lhs.isForward() == rhs.isForward();
		return result;
	}

	//*************************************************************************
}
