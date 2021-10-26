/*
See LICENSE file in root folder
*/
#ifndef ___AST_Variable_H___
#define ___AST_Variable_H___
#pragma once

#include "ShaderAST/Type/Type.hpp"
#include "ShaderAST/Var/FlagHolder.hpp"

namespace ast::var
{
	class Variable
		: public FlagHolder
	{
	public:
		SDAST_API Variable( EntityName nameId
			, VariablePtr outer
			, type::TypePtr type
			, uint32_t flags );
		SDAST_API Variable( uint32_t id
			, Builtin builtin
			, type::TypePtr type
			, uint32_t flags );
		SDAST_API Variable( EntityName nameId
			, type::FunctionPtr type );
		SDAST_API Variable( uint32_t id
			, type::FunctionPtr type
			, std::string name );

		Variable( EntityName nameId
			, VariablePtr outer
			, type::TypePtr type )
			: Variable{ std::move( nameId ), std::move( outer ), std::move( type ), 0u }
		{
		}

		Variable( EntityName nameId
			, VariablePtr outer
			, type::TypePtr type
			, Flag flag )
			: Variable{ std::move( nameId ), std::move( outer ), std::move( type ), uint32_t( flag ) }
		{
		}

		Variable( EntityName nameId
			, type::TypePtr type )
			: Variable{ std::move( nameId ), nullptr, std::move( type ), 0u }
		{
		}

		Variable( EntityName nameId
			, type::TypePtr type
			, Flag flag )
			: Variable{ std::move( nameId ), nullptr, std::move( type ), uint32_t( flag ) }
		{
		}

		Variable( EntityName nameId
			, type::TypePtr type
			, uint32_t flags )
			: Variable{ std::move( nameId ), nullptr, std::move( type ), flags }
		{
		}

		SDAST_API std::string getFullName()const;

		type::TypePtr getType()const
		{
			return m_type;
		}

		void updateType( type::TypePtr type )
		{
			m_type = type;
		}

		std::string getName()const
		{
			return m_nameId.name;
		}

		EntityName const & getEntityName()const
		{
			return m_nameId;
		}

		VariablePtr getOuter()const
		{
			return m_outer;
		}

		VariablePtr getOutermost()const
		{
			if ( m_outer->isMember() )
			{
				return m_outer->getOuter();
			}

			return m_outer;
		}

		bool isMember()const
		{
			assert( hasFlag( Flag::eMember ) == bool( m_outer ) );
			return hasFlag( Flag::eMember )
				&& m_outer;
		}

		uint32_t getId()const
		{
			return m_nameId.id;
		}

		Builtin getBuiltin()const
		{
			return ( isBuiltin()
				? m_builtin
				: Builtin::eNone );
		}

	private:
		EntityName m_nameId;
		VariablePtr m_outer;
		type::TypePtr m_type;
		Builtin m_builtin;
	};

	inline VariablePtr makeVariable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, outer
			, type
			, Flag::eNone );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type
		, Flag flag )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, outer
			, type
			, uint32_t( flag ) );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type
		, uint32_t flags )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, outer
			, type
			, flags );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, type::TypePtr type )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, type
			, Flag::eNone );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, type::TypePtr type
		, uint32_t flags )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, type
			, flags );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, type::TypePtr type
		, Flag flag )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, type
			, uint32_t( flag ) );
	}

	inline VariablePtr makeVariable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, outer
			, type
			, Flag::eNone );
	}

	inline VariablePtr makeVariable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name
		, Flag flag )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, outer
			, type
			, uint32_t( flag ) );
	}

	inline VariablePtr makeVariable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, outer
			, type
			, flags );
	}

	inline VariablePtr makeVariable( uint32_t id
		, type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, Flag::eNone );
	}

	inline VariablePtr makeVariable( uint32_t id
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, flags );
	}

	inline VariablePtr makeVariable( uint32_t id
		, type::TypePtr type
		, std::string name
		, Flag flag )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, uint32_t( flag ) );
	}

	inline VariablePtr makeBuiltin( uint32_t id
		, Builtin builtin
		, type::TypePtr type
		, Flag flag )
	{
		return std::make_shared< Variable >( id
			, builtin
			, type
			, uint32_t( flag ) | uint32_t( Flag::eBuiltin ) );
	}

	inline VariablePtr makeBuiltin( uint32_t id
		, Builtin builtin
		, type::TypePtr type
		, uint32_t flags )
	{
		return std::make_shared< Variable >( id
			, builtin
			, type
			, uint32_t( flags ) | uint32_t( Flag::eBuiltin ) );
	}

	inline VariablePtr makeFunction( uint32_t id
		, type::FunctionPtr type
		, std::string name )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, Flag::eFunction );
	}

	inline VariablePtr getOutermost( VariablePtr var )
	{
		if ( var->isMember() )
		{
			return getOutermost( var->getOuter() );
		}

		return var;
	}

	inline uint32_t operator==( VariablePtr const & lhs
		, VariablePtr const & rhs )
	{
		return ( lhs.get() == rhs.get() )
			|| ( lhs != nullptr
				&& rhs != nullptr
				&& lhs->getId() == rhs->getId() );
	}
}

#endif
