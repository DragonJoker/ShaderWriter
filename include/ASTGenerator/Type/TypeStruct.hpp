/*
See LICENSE file in root folder
*/
#ifndef ___AST_TypeList_H___
#define ___AST_TypeList_H___
#pragma once

#include "Type.hpp"

#include <vector>

namespace ast::type
{
	class Struct
		: public Type
	{
	private:
		struct Member
		{
			type::TypePtr type;
			std::string name;
		};

	public:
		Struct( std::string name
			, uint32_t arraySize = NotArray );
		void addMember( type::TypePtr type, std::string name );
		Member getMember( std::string const & name );

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

	private:
		std::string m_name;
		std::vector< Member > m_members;
	};
	using StructPtr = std::shared_ptr< Struct >;

	inline StructPtr makeStructType( std::string name
		, uint32_t arraySize = NotArray )
	{
		return std::make_shared< Struct >( std::move( name )
			, arraySize );
	}

}

#endif
