/*
See LICENSE file in root folder
*/
#ifndef ___SDW_BoInfo_H___
#define ___SDW_BoInfo_H___
#pragma once

#include "ShaderWriterPrerequisites.hpp"

#include <ASTGenerator/Type/TypeArray.hpp>
#include <ASTGenerator/Type/TypeStruct.hpp>

namespace sdw
{
	struct InterfaceBlock
	{
		inline InterfaceBlock( type::MemoryLayout layout
			, std::string name )
			: m_type{ type::makeStructType( layout, std::move( name ) ) }
		{
		}
		
		inline InterfaceBlock( type::StructPtr dataType )
			: m_type{ std::move( dataType ) }
		{
		}

		inline std::string const & getName()const
		{
			return m_type->getName();
		}

		template< type::Kind Kind >
		inline type::TypePtr registerMember( std::string const & name
			, uint32_t arraySize = ast::type::NotArray )
		{
			static_assert( Kind != type::Kind::eBoolean, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != type::Kind::eVec2B, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != type::Kind::eVec3B, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != type::Kind::eVec4B, "Can't put a boolean type inside an interface block" );
			return m_type->declMember( name, Kind, arraySize ).type;
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

		inline type::StructPtr getType()const
		{
			return m_type;
		}

	private:
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
		
		BoInfo( type::StructPtr dataType
			, uint32_t bind
			, uint32_t set )
			: InterfaceBlock{ std::move( dataType ) }
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
