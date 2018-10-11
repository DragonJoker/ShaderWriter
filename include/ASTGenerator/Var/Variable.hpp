/*
See LICENSE file in root folder
*/
#ifndef ___AST_Variable_H___
#define ___AST_Variable_H___
#pragma once

#include "ASTGenerator/Type/Type.hpp"

namespace ast::var
{
	enum class Flag
		: uint32_t
	{
		eNone = 0,
		eInputParam = 1 << 0,
		eOutputParam = 1 << 1,
		eBound = 1 << 2,
		eShaderInput = 1 << 3,
		eShaderOutput = 1 << 4,
		eShaderConstant = 1 << 5,
		eUniform = 1 << 6,
		eLocale = 1 << 7,
		eBuiltIn = 1 << 8,
	};

	class Variable
	{
	public:
	public:
		Variable( type::TypePtr type
			, std::string name );
		Variable( type::TypePtr type
			, std::string name
			, uint32_t flags );
		Variable( type::TypePtr type
			, std::string name
			, Flag flag );
		virtual ~Variable();

		inline type::TypePtr get()const
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

		inline bool isInputParam()const
		{
			return hasFlag( Flag::eInputParam );
		}

		inline bool isOutputParam()const
		{
			return hasFlag( Flag::eOutputParam );
		}

		inline bool isShaderInput()const
		{
			return hasFlag( Flag::eShaderInput );
		}

		inline bool isShaderOutput()const
		{
			return hasFlag( Flag::eShaderOutput );
		}

		inline bool isShaderConstant()const
		{
			return hasFlag( Flag::eShaderConstant );
		}

		inline bool isLocale()const
		{
			return hasFlag( Flag::eLocale );
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
		type::TypePtr m_type;
		std::string m_name;
		uint32_t m_flags;
	};

	inline VariablePtr makeVariable( type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( type, name );
	}

	inline VariablePtr makeVariable( type::TypePtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( type, name, flags );
	}

	inline VariablePtr makeVariable( type::TypePtr type
		, std::string name
		, Flag flag )
	{
		return std::make_shared< Variable >( type, name, flag );
	}
}

#endif
