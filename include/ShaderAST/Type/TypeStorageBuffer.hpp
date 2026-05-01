/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeStorageBuffer_H___
#define ___AST_TypeStorageBuffer_H___
#pragma once

#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::type
{
	class StorageBuffer
		: public Type
	{
	public:
		SDAST_API StorageBuffer( TypesCache & typesCache
			, std::string const & name
			, MemoryLayout layout
			, bool isArray );

		BaseStructPtr getDataType()const noexcept
		{
			return m_interface.getType();
		}

		std::string const & getDataName()const noexcept
		{
			return m_interface.getName();
		}

		MemoryLayout getMemoryLayout()const noexcept
		{
			return getDataType()->getMemoryLayout();
		}

		bool empty()const
		{
			return getDataType()->empty();
		}

		bool isArray()const noexcept
		{
			return m_isArray;
		}

		template< type::Kind Kind >
		std::tuple< type::TypePtr, bool, uint32_t > registerMember( std::string name
			, uint32_t arraySize = ast::type::NotArray )
		{
			return m_interface.registerMember< Kind >( std::move( name ), arraySize );
		}

		std::tuple< type::TypePtr, bool, uint32_t > registerMember( std::string name
			, type::TypePtr type
			, uint32_t arraySize = ast::type::NotArray )
		{
			return m_interface.registerMember( std::move( name ), type, arraySize );
		}

		uint32_t findMember( std::string_view name )const
		{
			return m_interface.findMember( name );
		}

		bool hasMember( std::string_view name )const
		{
			return m_interface.hasMember( name );
		}

		type::TypePtr getMember( std::string_view name )const
		{
			return m_interface.getMember( name );
		}

		type::TypePtr getMember( uint32_t index )const
		{
			return m_interface.getMember( index );
		}

	private:
		InterfaceBlock m_interface;
		bool m_isArray;
	};
	using StorageBufferPtr = StorageBuffer *;

	SDAST_API size_t getHash( MemoryLayout layout
		, std::string const & name
		, bool isArray
		, bool explicitLayout );
}

#endif
