/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypePointer_H___
#define ___AST_TypePointer_H___
#pragma once

#include "TypeArray.hpp"

#include <vector>

namespace ast::type
{
	class Pointer
		: public Type
	{
	public:
		SDAST_API Pointer( TypePtr pointerType
			, Storage storage
			, bool isForward );

		Storage getStorage()const
		{
			return m_storage;
		}

		TypePtr getPointerType()const
		{
			return m_pointerType;
		}

		bool isForward()const
		{
			return m_isForward;
		}

	private:
		TypePtr m_pointerType;
		Storage m_storage;
		bool m_isForward;
	};
	using PointerPtr = std::shared_ptr< Pointer >;

	SDAST_API uint32_t getPointerLevel( TypePtr pointerType );
	SDAST_API size_t getHash( TypePtr pointerType
		, Storage storage
		, bool isForward );

	SDAST_API bool operator==( Pointer const & lhs, Pointer const & rhs );
}

#endif
