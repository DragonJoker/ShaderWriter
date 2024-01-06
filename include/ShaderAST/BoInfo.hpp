/*
See LICENSE file in root folder
*/
#ifndef ___AST_BoInfo_H___
#define ___AST_BoInfo_H___
#pragma once

#include <ShaderAST/Type/TypeAccelerationStructure.hpp>
#include <ShaderAST/Type/TypeArray.hpp>
#include <ShaderAST/Type/TypeCache.hpp>
#include <ShaderAST/Type/TypeStruct.hpp>

namespace ast
{
	struct InterfaceBlock
	{
		InterfaceBlock( type::TypesCache & typesCache
			, type::MemoryLayout layout
			, std::string const & name )
			: m_type{ getType( typesCache, layout, name ) }
		{
		}
		
		explicit InterfaceBlock( type::BaseStructPtr dataType )
			: m_type{ std::move( dataType ) }
		{
		}

		std::string const & getName()const
		{
			return m_type->getName();
		}

		template< type::Kind Kind >
		std::pair< type::TypePtr, bool > registerMember( std::string name
			, uint32_t arraySize = ast::type::NotArray )
		{
			static_assert( Kind != type::Kind::eBoolean, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != type::Kind::eVec2B, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != type::Kind::eVec3B, "Can't put a boolean type inside an interface block" );
			static_assert( Kind != type::Kind::eVec4B, "Can't put a boolean type inside an interface block" );
			return registerMember( std::move( name ), m_type->getTypesCache().getBasicType( Kind ), arraySize );
		}

		std::pair< type::TypePtr, bool > registerMember( std::string name
			, type::TypePtr type
			, uint32_t arraySize = ast::type::NotArray )
		{
			auto [mbr, added] = m_type->declMember( std::move( name ), type, arraySize );
			return { mbr.type, added };
		}

		uint32_t findMember( std::string_view name )const
		{
			return m_type->findMember( name );
		}

		bool hasMember( std::string_view name )const
		{
			return m_type->hasMember( name );
		}

		type::TypePtr getMember( std::string_view name )const
		{
			return m_type->getMember( name ).type;
		}

		type::BaseStructPtr getType()const
		{
			return m_type;
		}

		static type::BaseStructPtr getType( type::TypesCache & typesCache
			, type::MemoryLayout layout
			, std::string const & name )
		{
			return typesCache.getStruct( layout, name );
		}

	private:
		type::BaseStructPtr m_type;
	};

	struct BoInfo
		: DescriptorInfoT< type::BaseStruct >
	{
		BoInfo( type::TypesCache & typesCache
			, type::MemoryLayout layout
			, std::string const & name
			, uint32_t bind
			, uint32_t set )
			: DescriptorInfoT{ InterfaceBlock::getType( typesCache, layout, name )
				, { bind, set } }
		{
		}
		
		BoInfo( type::BaseStructPtr dataType
			, uint32_t bind
			, uint32_t set )
			: DescriptorInfoT{ std::move( dataType )
				, { bind, set } }
		{
		}
	};

	using PcbInfo = InterfaceBlock;
	using UboInfo = BoInfo;
	using SsboInfo = BoInfo;
	using ShaderRecordInfo = BoInfo;

	struct AccStructInfo
		: DescriptorInfoT< type::AccelerationStructure >
	{
		AccStructInfo()
			: DescriptorInfoT{ nullptr, { ~0u, ~0u } }
		{
		}

		AccStructInfo( type::AccelerationStructurePtr type
			, uint32_t bind
			, uint32_t set )
			: DescriptorInfoT{ type
				, { bind, set } }
		{
		}

		bool isValid()const
		{
			return type != nullptr;
		}
	};
}

#endif
