/*
See LICENSE file in root folder
*/
#ifndef ___AST_Variable_H___
#define ___AST_Variable_H___
#pragma once

#include "ASTGenerator/ASTGeneratorPrerequisites.hpp"

namespace ast
{
	class Variable
	{
	public:
		enum class Flag
			: uint32_t
		{
			eNone = 0,
			eInput = 1 << 0,
			eOutput = 1 << 1,
			eBound = 1 << 2,
		};

	public:
		Variable( Type type
			, std::string name );
		Variable( Type type
			, std::string name
			, uint32_t flags );
		Variable( Type type
			, std::string name
			, Flag flag );
		virtual ~Variable();

		inline Type getType()const
		{
			return m_type;
		}

		inline std::string const & getName()const
		{
			return m_name;
		}

		inline void setFlag( Flag flag, bool set = true )
		{
			if ( set )
			{
				m_flags |= uint32_t( flag );
			}
			else
			{
				m_flags &= ~uint32_t( flag );
			}
		}

		inline bool isInput()const
		{
			return hasFlag( Flag::eInput );
		}

		inline bool isOutput()const
		{
			return hasFlag( Flag::eOutput );
		}

		inline bool isBound()const
		{
			return hasFlag( Flag::eBound );
		}

	private:
		inline bool hasFlag( Flag flag )const
		{
			return Flag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		Type m_type;
		std::string m_name;
		uint32_t m_flags;
	};

	inline VariablePtr makeVariable( Type type
		, std::string name )
	{
		return std::make_shared< Variable >( type, name );
	}

	inline VariablePtr makeVariable( Type type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( type, name, flags );
	}

	inline VariablePtr makeVariable( Type type
		, std::string name
		, Variable::Flag flag )
	{
		return std::make_shared< Variable >( type, name, flag );
	}
}

#endif
