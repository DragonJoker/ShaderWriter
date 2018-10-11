/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Type/TypeStruct.hpp"

#include <algorithm>

namespace ast::type
{
	Struct::Struct( std::string name
		, uint32_t arraySize )
		: Type{ Kind::eStruct, arraySize }
		, m_name{ std::move( name ) }
	{
	}

	void Struct::addMember( type::TypePtr type, std::string name )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Member const & lookup )
			{
				return lookup.name == name;
			} );

		if ( it != m_members.end() )
		{
			throw std::runtime_error{ "Struct member [" + name + "] already exists." };
		}

		m_members.push_back( { std::move( type ), std::string( name ) } );
	}

	Struct::Member Struct::getMember( std::string const & name )
	{
		auto it = std::find_if( m_members.begin()
			, m_members.end()
			, [&name]( Member const & lookup )
			{
				return lookup.name == name;
			} );

		if ( it == m_members.end() )
		{
			throw std::runtime_error{ "Struct member [" + name + "] was not found." };
		}

		return *it;
	}
}
