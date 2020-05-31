/*
See LICENSE file in root folder
*/
#include "ShaderAST/Var/Variable.hpp"

#include "ShaderAST/Type/TypeFunction.hpp"

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
		: FlagHolder{ flags }
		, m_outer{ std::move( outer ) }
		, m_type{ std::move( type ) }
		, m_name{ std::move( name ) }
	{
		if ( outer )
		{
			updateFlag( Flag::eMember, true );
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

	Variable::Variable( type::FunctionPtr type
		, std::string name )
		: Variable{ nullptr, std::move( type ), std::move( name ), Flag::eFunction }
	{
	}

	Variable::~Variable()
	{
	}

	std::string Variable::getFullName()const
	{
		return m_outer
			? m_outer->getName() + "." + getName()
			: getName();
	}
}
