/*
See LICENSE file in root folder
*/
#include "ShaderAST/Var/Variable.hpp"

namespace ast::var
{
	Variable::Variable( VariablePtr outer
		, type::TypePtr type
		, std::string name )
		: Variable{ std::move( outer ), std::move( type ), std::move( name ), 0u }
	{
	}

	Variable::Variable( VariablePtr outer
		, type::TypePtr type
		, std::string name
		, Flag flag )
		: Variable{ std::move( outer ), std::move( type ), std::move( name ), uint32_t( flag ) }
	{
	}

	Variable::Variable( VariablePtr outer
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
		: m_outer{ std::move( outer ) }
		, m_type{ std::move( type ) }
		, m_name{ std::move( name ) }
		, m_flags{ flags }
	{
		if ( outer )
		{
			m_flags = m_flags | Flag::eMember;
		}

		assert( hasFlag( Flag::eMember ) == bool( m_outer ) );
	}

	Variable::Variable( type::TypePtr type
		, std::string name )
		: Variable{ nullptr, std::move( type ), std::move( name ), 0u }
	{
	}

	Variable::Variable( type::TypePtr type
		, std::string name
		, Flag flag )
		: Variable{ nullptr, std::move( type ), std::move( name ), uint32_t( flag ) }
	{
	}

	Variable::Variable( type::TypePtr type
		, std::string name
		, uint32_t flags )
		: Variable{ nullptr, std::move( type ), std::move( name ), flags }
	{
	}

	Variable::~Variable()
	{
	}
}
