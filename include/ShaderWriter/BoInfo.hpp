/*
See LICENSE file in root folder
*/
#ifndef ___SDW_BoInfo_H___
#define ___SDW_BoInfo_H___
#pragma once

#include "ShaderWriterPrerequisites.hpp"

#include <ASTGenerator/Type/TypeStruct.hpp>

namespace sdw
{
	struct InterfaceBlock
	{
		inline InterfaceBlock( type::MemoryLayout layout
			, std::string name )
			: m_name{ std::move( name ) }
			, m_type{ type::makeStructType( layout, m_name ) }
		{
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline type::TypePtr registerMember( std::string const & name
			, type::Kind kind
			, uint32_t arraySize = ast::type::NotArray )
		{
			return m_type->declMember( name, kind, arraySize ).type;
		}

		inline type::TypePtr registerMember( std::string const & name
			, type::StructPtr type
			, uint32_t arraySize = ast::type::NotArray )
		{
			return m_type->declMember( name, type, arraySize ).type;
		}

		inline type::TypePtr getMember( std::string const & name )const
		{
			return m_type->getMember( name ).type;
		}

		inline type::TypePtr getType()const
		{
			return m_type;
		}

	private:
		std::string m_name;
		type::StructPtr m_type;
	};

	struct BoInfo
		: public InterfaceBlock
	{
		BoInfo( type::MemoryLayout layout
			, std::string name
			, uint32_t bind
			, uint32_t set )
			: InterfaceBlock{ layout, std::move( name ) }
			, m_bind{ bind }
			, m_set{ set }
		{
		}

		inline uint32_t getBindingPoint()const
		{
			return m_bind;
		}

		inline uint32_t getSetPoint()const
		{
			return m_set;
		}

	private:
		uint32_t m_bind;
		uint32_t m_set;
	};
}

#endif
