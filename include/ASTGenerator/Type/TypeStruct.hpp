/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeStruct_H___
#define ___AST_TypeStruct_H___
#pragma once

#include "Type.hpp"

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
		struct Member
		{
			type::TypePtr type;
			std::string name;
			uint32_t offset;
			uint32_t size;
		};

	private:
		Struct( Struct * parent
			, uint32_t index
			, Struct const & copy
			, uint32_t arraySize = NotArray );

	public:
		Struct( MemoryLayout layout
			, std::string name
			, uint32_t arraySize = NotArray );
		Member declMember( std::string name
			, type::Kind kind
			, uint32_t arraySize = NotArray );
		Member declMember( std::string name
			, type::TypePtr type );
		Member declMember( std::string name
			, type::StructPtr type );
		Member declMember( std::string name
			, type::StructPtr type
			, uint32_t arraySize );
		Member getMember( std::string const & name );
		StructPtr getUnqualifiedType()const;

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
		std::string m_name;
		std::vector< Member > m_members;
		MemoryLayout m_layout;
	};
	using StructPtr = std::shared_ptr< Struct >;

	inline StructPtr makeStructType( MemoryLayout layout
		, std::string name
		, uint32_t arraySize = NotArray )
	{
		return std::make_shared< Struct >( layout
			, std::move( name )
			, arraySize );
	}

	bool operator==( Type const & lhs, Type const & rhs );
	bool operator==( Struct const & lhs, Struct const & rhs );
	uint32_t getSize( TypePtr type
		, MemoryLayout layout );
}

#endif
