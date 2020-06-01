/*
See LICENSE file in root folder
*/
#ifndef ___AST_Variable_H___
#define ___AST_Variable_H___
#pragma once

#include "ShaderAST/Type/Type.hpp"

namespace ast::var
{
	enum class Flag
		: uint32_t
	{
		eNone = 0,
		eParam = 1 << 0,
		eInputParam = 1 << 1,
		eOutputParam = 1 << 2,
		eUniform = 1 << 3,
		eConstant = 1 << 4,
		eShaderInput = 1 << 5,
		eShaderOutput = 1 << 6,
		eShaderConstant = 1 << 7,
		eSpecialisationConstant = 1 << 8,
		ePushConstant = 1 << 9,
		eLocale = 1 << 10,
		eBuiltin = 1 << 11,
		eImplicit = 1 << 12,
		eMember = 1 << 13,
		eFunction = 1 << 14,
		eStatic = 1 << 15,
		eFlat = 1 << 16,
		eNoPerspective = 1 << 17,
		ePatch = 1 << 18,
		eCentroid = 1 << 19,
		ePerSample = 1 << 20,
		eGeometryStream = 1 << 21,
		eBlendIndex = 1 << 22,
		eLoopVar = 1 << 23,
	};

	class FlagHolder
	{
	public:
		inline FlagHolder( Flag flag )
			: m_flags{ uint32_t( flag ) }
		{
		}

		inline FlagHolder( uint32_t flags )
			: m_flags{ flags }
		{
		}

		inline uint32_t getFlags()const
		{
			return m_flags;
		}

		inline void updateFlag( Flag flag, bool set = true )
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

		inline bool isParam()const
		{
			return hasFlag( Flag::eParam )
				|| hasFlag( Flag::eInputParam )
				|| hasFlag( Flag::eOutputParam );
		}

		inline bool isStatic()const
		{
			return hasFlag( Flag::eStatic );
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

		inline bool isSpecialisationConstant()const
		{
			return hasFlag( Flag::eSpecialisationConstant );
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

		inline bool isFlat()const
		{
			return hasFlag( Flag::eFlat );
		}

		inline bool isLoopVar()const
		{
			return hasFlag( Flag::eLoopVar );
		}

		inline bool isMember()const
		{
			return hasFlag( Flag::eMember );
		}

		inline bool isNoPerspective()const
		{
			return hasFlag( Flag::eNoPerspective );
		}

		inline bool isPatch()const
		{
			return hasFlag( Flag::ePatch );
		}

		inline bool isCentroid()const
		{
			return hasFlag( Flag::eCentroid );
		}

		inline bool isPerSample()const
		{
			return hasFlag( Flag::ePerSample );
		}

		inline bool isGeometryStream()const
		{
			return hasFlag( Flag::eGeometryStream );
		}

		inline bool isBlendIndex()const
		{
			return hasFlag( Flag::eBlendIndex );
		}

		inline bool hasFlag( Flag flag )const
		{
			return flag == Flag::eNone
				? false
				: Flag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		uint32_t m_flags;
	};

	class Variable
		: public FlagHolder
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
		Variable( type::FunctionPtr type
			, std::string name );
		~Variable();

		std::string getFullName()const;

		inline type::TypePtr getType()const
		{
			return m_type;
		}

		inline std::string const & getName()const
		{
			return m_name;
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

		inline bool isMember()const
		{
			assert( hasFlag( Flag::eMember ) == bool( m_outer ) );
			return hasFlag( Flag::eMember )
				&& m_outer;
		}

	private:
		VariablePtr m_outer;
		type::TypePtr m_type;
		std::string m_name;
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

	inline VariablePtr makeFunction( type::FunctionPtr type
		, std::string name )
	{
		return std::make_shared< Variable >( type
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
