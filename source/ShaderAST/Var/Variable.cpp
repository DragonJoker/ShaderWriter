/*
See LICENSE file in root folder
*/
#include "ShaderAST/Var/Variable.hpp"

#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeFunction.hpp"

namespace ast::var
{
	//*********************************************************************************************

	Variable::Variable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name )
		: Variable{ id, std::move( outer ), std::move( type ), std::move( name ), 0u }
	{
	}

	Variable::Variable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name
		, Flag flag )
		: Variable{ id, std::move( outer ), std::move( type ), std::move( name ), uint32_t( flag ) }
	{
	}

	Variable::Variable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
		: FlagHolder{ flags }
		, m_id{ id }
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

	Variable::Variable( uint32_t id
		, type::TypePtr type
		, std::string name )
		: Variable{ id, nullptr, std::move( type ), std::move( name ), 0u }
	{
	}

	Variable::Variable( uint32_t id
		, type::TypePtr type
		, std::string name
		, Flag flag )
		: Variable{ id, nullptr, std::move( type ), std::move( name ), uint32_t( flag ) }
	{
	}

	Variable::Variable( uint32_t id
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
		: Variable{ id, nullptr, std::move( type ), std::move( name ), flags }
	{
	}

	Variable::Variable( uint32_t id
		, type::FunctionPtr type
		, std::string name )
		: Variable{ id, nullptr, std::move( type ), std::move( name ), Flag::eFunction }
	{
	}

	std::string Variable::getFullName()const
	{
		return m_outer
			? m_outer->getName() + "." + getName()
			: getName();
	}

	//*********************************************************************************************
}
