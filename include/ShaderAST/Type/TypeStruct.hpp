/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeStruct_H___
#define ___AST_TypeStruct_H___
#pragma once

#include "TypeArray.hpp"

#include <vector>

namespace ast::type
{
	enum class MemoryLayout
	{
		eStd140,
		eStd430,
	};

	class Struct
		: public Type
	{
	public:
		static constexpr uint32_t NotFound = ~0u;

		struct Member
		{
			type::TypePtr type;
			std::string name;
			uint32_t offset;
			uint32_t size;
			uint32_t arrayStride;
		};

	private:
		Struct( TypesCache & cache
			, Struct const & rhs );
		Struct( TypesCache & cache
			, Struct * parent
			, uint32_t index
			, Struct const & copy );
		Struct( TypesCache & cache
			, Struct & parent
			, uint32_t index
			, Struct const & copy );

	public:
		Struct( TypesCache & cache
			, MemoryLayout layout
			, std::string name );
		Member declMember( std::string name
			, type::Kind kind
			, uint32_t arraySize = NotArray );
		Member declMember( std::string name
			, type::TypePtr type );
		Member declMember( std::string name
			, type::StructPtr type );
		Member declMember( std::string name
			, type::ArrayPtr type
			, uint32_t arraySize );
		Member declMember( std::string name
			, type::StructPtr type
			, uint32_t arraySize );
		Member declMember( std::string name
			, type::ArrayPtr type );
		Member getMember( uint32_t index );
		Member getMember( std::string const & name );
		uint32_t findMember( std::string const & name );
		TypePtr getMemberType( Struct & parent, uint32_t index )const override;

		inline bool hasMember( std::string const & name )
		{
			return findMember( name ) != NotFound;
		}

		std::string const & getName()const
		{
			return m_name;
		}

		size_t size()const
		{
			return m_members.size();
		}

		bool empty()const
		{
			return m_members.empty();
		}

		auto begin()const
		{
			return m_members.begin();
		}

		auto end()const
		{
			return m_members.end();
		}

		auto front()const
		{
			return m_members.front();
		}

		auto back()const
		{
			return m_members.back();
		}

		MemoryLayout getMemoryLayout()const
		{
			return m_layout;
		}

	private:
		Member doAddMember( type::TypePtr type
			, std::string const & name );
		void doUpdateOffsets();

	private:
		std::string m_name;
		std::vector< Member > m_members;
		MemoryLayout m_layout;
	};
	using StructPtr = std::shared_ptr< Struct >;

	size_t getHash( type::MemoryLayout layout, std::string const & name );

	bool operator==( Struct const & lhs, Struct const & rhs );

	uint32_t getSize( Type const & type
		, MemoryLayout layout );
	uint32_t getSize( TypePtr type
		, MemoryLayout layout );
	uint32_t getAlignment( Type const & type
		, MemoryLayout layout );
	uint32_t getAlignment( TypePtr type
		, MemoryLayout layout );
	uint32_t getArrayStride( Array const & type
		, MemoryLayout layout );
	uint32_t getArrayStride( ArrayPtr type
		, MemoryLayout layout );
	uint32_t getArrayStride( Type const & type
		, MemoryLayout layout );
	uint32_t getArrayStride( TypePtr type
		, MemoryLayout layout );
}

#endif
