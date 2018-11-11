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
		eUniform = 1 << 2,
		eConstant = 1 << 3,
		eShaderInput = 1 << 4,
		eShaderOutput = 1 << 5,
		eShaderConstant = 1 << 6,
		ePushConstant = 1 << 7,
		eLocale = 1 << 8,
		eBuiltin = 1 << 9,
		eImplicit = 1 << 10,
		eMember = 1 << 11,
	};

	class Variable
	{
	public:
		Variable( VariablePtr outer
			, type::TypePtr type
			, std::string name );
		Variable( VariablePtr outer
			, type::TypePtr type
			, std::string name
			, Flag flag );
		Variable( VariablePtr outer
			, type::TypePtr type
			, std::string name
			, uint32_t flags );
		Variable( type::TypePtr type
			, std::string name );
		Variable( type::TypePtr type
			, std::string name
			, Flag flag );
		Variable( type::TypePtr type
			, std::string name
			, uint32_t flags );
		virtual ~Variable();

		inline type::TypePtr getType()const
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

		inline VariablePtr getOuter()const
		{
			return m_outer;
		}

		inline VariablePtr getOutermost()const
		{
			if ( m_outer->isMember() )
			{
				return m_outer->getOuter();
			}

			return m_outer;
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

		inline bool isPushConstant()const
		{
			return hasFlag( Flag::ePushConstant );
		}

		inline bool isShaderConstant()const
		{
			return hasFlag( Flag::eShaderConstant );
		}

		inline bool isLocale()const
		{
			return hasFlag( Flag::eLocale );
		}

		inline bool isBuiltin()const
		{
			return hasFlag( Flag::eBuiltin );
		}

		inline bool isUniform()const
		{
			return hasFlag( Flag::eUniform );
		}

		inline bool isConstant()const
		{
			return hasFlag( Flag::eConstant );
		}

		inline bool isImplicit()const
		{
			return hasFlag( Flag::eImplicit );
		}

		inline bool isMember()const
		{
			assert( hasFlag( Flag::eMember ) == bool( m_outer ) );
			return hasFlag( Flag::eMember )
				&& m_outer;
		}

	private:
		inline bool hasFlag( Flag flag )const
		{
			return Flag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		VariablePtr m_outer;
		type::TypePtr m_type;
		std::string m_name;
		uint32_t m_flags;
	};

	inline VariablePtr makeVariable( VariablePtr outer
		, type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( outer
			, type
			, name );
	}

	inline VariablePtr makeVariable( VariablePtr outer
		, type::TypePtr type
		, std::string name
		, Flag flag )
	{
		return std::make_shared< Variable >( outer
			, type
			, name
			, flag );
	}

	inline VariablePtr makeVariable( VariablePtr outer
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( outer
			, type
			, name
			, flags );
	}

	inline VariablePtr makeVariable( type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( type
			, name );
	}

	inline VariablePtr makeFunction( std::string name )
	{
		return std::make_shared< Variable >( type::getFunction()
			, name );
	}

	inline VariablePtr makeVariable( type::TypePtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( type
			, name
			, flags );
	}

	inline VariablePtr makeVariable( type::TypePtr type
		, std::string name
		, Flag flag )
	{
		return std::make_shared< Variable >( type
			, name
			, flag );
	}

	inline VariablePtr getOutermost( VariablePtr var )
	{
		if ( var->isMember() )
		{
			return getOutermost( var->getOuter() );
		}

		return var;
	}

	inline uint32_t operator|( Flag const lhs, Flag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( Flag const lhs, uint32_t const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}

	inline uint32_t operator|( uint32_t const lhs, Flag const rhs )
	{
		return uint32_t( lhs ) | uint32_t( rhs );
	}
}

#endif
