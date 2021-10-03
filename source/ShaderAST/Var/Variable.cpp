/*
See LICENSE file in root folder
*/
#include "ShaderAST/Var/Variable.hpp"

#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeFunction.hpp"

namespace ast::var
{
	//*********************************************************************************************

	Variable::Variable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type
		, uint32_t flags )
		: FlagHolder{ flags }
		, m_nameId{ std::move( nameId ) }
		, m_outer{ std::move( outer ) }
		, m_type{ std::move( type ) }
	{
		if ( outer )
		{
			updateFlag( Flag::eMember, true );
		}

		if ( isOpaqueType( m_type ) )
		{
			updateFlag( Flag::eUniform, true );
			updateFlag( Flag::eConstant, true );
		}

		assert( hasFlag( Flag::eMember ) == bool( m_outer ) );
	}

	Variable::Variable( EntityName nameId
		, type::FunctionPtr type )
		: Variable{ std::move( nameId ), nullptr, std::move( type ), Flag::eFunction }
	{
	}

	Variable::Variable( uint32_t id
		, type::FunctionPtr type
		, std::string name )
		: Variable{ { id, name }, type }
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
