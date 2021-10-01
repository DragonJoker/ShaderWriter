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
			TypePtr type;
			std::string name;
			uint32_t offset;
			uint32_t size;
			uint32_t arrayStride;
		};

	private:
		SDAST_API Struct( TypesCache & cache
			, Struct const & rhs );
		SDAST_API Struct( TypesCache & cache
			, Struct * parent
			, uint32_t index
			, Struct const & copy );
		SDAST_API Struct( TypesCache & cache
			, Struct & parent
			, uint32_t index
			, Struct const & copy );

	public:
		SDAST_API Struct( TypesCache & cache
			, MemoryLayout layout
			, std::string name );
		SDAST_API Member declMember( std::string name
			, Kind kind
			, uint32_t arraySize = NotArray );
		SDAST_API Member declMember( std::string name
			, TypePtr type );
		SDAST_API Member declMember( std::string name
			, StructPtr type );
		SDAST_API Member declMember( std::string name
			, ArrayPtr type
			, uint32_t arraySize );
		SDAST_API Member declMember( std::string name
			, StructPtr type
			, uint32_t arraySize );
		SDAST_API Member declMember( std::string name
			, ArrayPtr type );
		SDAST_API Member getMember( uint32_t index );
		SDAST_API Member getMember( std::string const & name );
		SDAST_API uint32_t findMember( std::string const & name );
		SDAST_API TypePtr getMemberType( Struct & parent, uint32_t index )const override;

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
		SDAST_API Member doAddMember( TypePtr type
			, std::string const & name );
		SDAST_API void doUpdateOffsets();

	private:
		std::string m_name;
		std::vector< Member > m_members;
		MemoryLayout m_layout;
	};
	using StructPtr = std::shared_ptr< Struct >;

	SDAST_API size_t getHash( MemoryLayout layout, std::string const & name );

	SDAST_API bool operator==( Struct const & lhs, Struct const & rhs );

	SDAST_API uint32_t getSize( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getSize( TypePtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getAlignment( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getAlignment( TypePtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( Array const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( ArrayPtr type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( Type const & type
		, MemoryLayout layout );
	SDAST_API uint32_t getArrayStride( TypePtr type
		, MemoryLayout layout );
}

#endif
