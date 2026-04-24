/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeUniformBuffer_H___
#define ___AST_TypeUniformBuffer_H___
#pragma once

#include "ShaderAST/Type/TypeStruct.hpp"

namespace ast::type
{
	class UniformBuffer
		: public Type
	{
	public:
		SDAST_API UniformBuffer( TypesCache & typesCache
			, std::string name
			, MemoryLayout layout );

		BaseStructPtr getDataType()const
		{
			return m_interface.getType();
		}

		MemoryLayout getMemoryLayout()const
		{
			return getDataType()->getMemoryLayout();
		}

		std::string const & getDataName()const
		{
			return m_interface.getName();
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

	private:
		InterfaceBlock m_interface;
	};
	using UniformBufferPtr = UniformBuffer *;
}

#endif
