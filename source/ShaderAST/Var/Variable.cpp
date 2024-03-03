/*
See LICENSE file in root folder
*/
#include "ShaderAST/Var/Variable.hpp"

#include "ShaderAST/Type/TypeCache.hpp"
#include "ShaderAST/Type/TypeFunction.hpp"

namespace ast::var
{
	//*********************************************************************************************

	namespace
	{
		std::string getName( Builtin builtin
			, uint64_t flags )
		{
			std::string result{ getName( builtin ) };

			if ( flags & uint64_t( Flag::eShaderOutput ) )
			{
				result = "Out" + result;
			}

			if ( flags & uint64_t( Flag::eShaderInput ) )
			{
				result = "In" + result;
			}

			return result;
		}
	}

	//*********************************************************************************************

	Variable::Variable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type
		, uint64_t flags )
		: FlagHolder{ flags }
		, m_nameId{ std::move( nameId ) }
		, m_outer{ std::move( outer ) }
		, m_type{ std::move( type ) }
		, m_builtin{ Builtin::eNone }
	{
		if ( m_outer )
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

	Variable::Variable( uint32_t id
		, Builtin builtin
		, type::TypePtr type
		, uint64_t flags )
		: FlagHolder{ flags | Flag::eBuiltin }
		, m_nameId{ id, var::getName( builtin, flags ) }
		, m_type{ std::move( type ) }
		, m_builtin{ builtin }
	{
	}

	Variable::Variable( EntityName nameId
		, type::FunctionPtr type )
		: Variable{ std::move( nameId ), nullptr, std::move( type ), Flag::eFunction }
	{
	}

	Variable::Variable( uint32_t id
		, type::FunctionPtr type
		, std::string name )
		: Variable{ { id, std::move( name ) }, type }
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
