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
		eTemp = 1 << 24,
		eAlias = 1 << 25,
	};

	class FlagHolder
	{
	protected:
		~FlagHolder() = default;

	public:
		FlagHolder( Flag flag )
			: m_flags{ uint32_t( flag ) }
		{
		}

		FlagHolder( uint32_t flags )
			: m_flags{ flags }
		{
		}

		uint32_t getFlags()const
		{
			return m_flags;
		}

		void updateFlag( Flag flag, bool set = true )
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

		bool isParam()const
		{
			return hasFlag( Flag::eParam )
				|| hasFlag( Flag::eInputParam )
				|| hasFlag( Flag::eOutputParam );
		}

		bool isStatic()const
		{
			return hasFlag( Flag::eStatic );
		}

		bool isInputParam()const
		{
			return hasFlag( Flag::eInputParam );
		}

		bool isOutputParam()const
		{
			return hasFlag( Flag::eOutputParam );
		}

		bool isShaderInput()const
		{
			return hasFlag( Flag::eShaderInput );
		}

		bool isShaderOutput()const
		{
			return hasFlag( Flag::eShaderOutput );
		}

		bool isPushConstant()const
		{
			return hasFlag( Flag::ePushConstant );
		}

		bool isShaderConstant()const
		{
			return hasFlag( Flag::eShaderConstant );
		}

		bool isSpecialisationConstant()const
		{
			return hasFlag( Flag::eSpecialisationConstant );
		}

		bool isLocale()const
		{
			return hasFlag( Flag::eLocale );
		}

		bool isBuiltin()const
		{
			return hasFlag( Flag::eBuiltin );
		}

		bool isUniform()const
		{
			return hasFlag( Flag::eUniform );
		}

		bool isConstant()const
		{
			return hasFlag( Flag::eConstant );
		}

		bool isImplicit()const
		{
			return hasFlag( Flag::eImplicit );
		}

		bool isFlat()const
		{
			return hasFlag( Flag::eFlat );
		}

		bool isLoopVar()const
		{
			return hasFlag( Flag::eLoopVar );
		}

		bool isMember()const
		{
			return hasFlag( Flag::eMember );
		}

		bool isNoPerspective()const
		{
			return hasFlag( Flag::eNoPerspective );
		}

		bool isPatch()const
		{
			return hasFlag( Flag::ePatch );
		}

		bool isCentroid()const
		{
			return hasFlag( Flag::eCentroid );
		}

		bool isPerSample()const
		{
			return hasFlag( Flag::ePerSample );
		}

		bool isGeometryStream()const
		{
			return hasFlag( Flag::eGeometryStream );
		}

		bool isBlendIndex()const
		{
			return hasFlag( Flag::eBlendIndex );
		}

		bool isTempVar()const
		{
			return hasFlag( Flag::eTemp );
		}

		bool isAlias()const
		{
			return hasFlag( Flag::eAlias );
		}

		bool hasFlag( Flag flag )const
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
		SDAST_API Variable( EntityName nameId
			, VariablePtr outer
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

		std::string const & getName()const
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

	private:
		EntityName m_nameId;
		VariablePtr m_outer;
		type::TypePtr m_type;
	};

	inline VariablePtr makeVariable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, outer
			, type
			, Flag::eTemp );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type
		, Flag flag )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, outer
			, type
			, uint32_t( flag ) | uint32_t( Flag::eTemp ) );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, VariablePtr outer
		, type::TypePtr type
		, uint32_t flags )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, outer
			, type
			, flags | uint32_t( Flag::eTemp ) );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, type::TypePtr type )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, type
			, Flag::eTemp );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, type::TypePtr type
		, uint32_t flags )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, type
			, flags | uint32_t( Flag::eTemp ) );
	}

	inline VariablePtr makeVariable( EntityName nameId
		, type::TypePtr type
		, Flag flag )
	{
		return std::make_shared< Variable >( std::move( nameId )
			, type
			, uint32_t( flag ) | uint32_t( Flag::eTemp ) );
	}

	inline VariablePtr makeVariable( uint32_t id
		, VariablePtr outer
		, type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, outer
			, type
			, Flag::eTemp );
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
			, uint32_t( flag ) | uint32_t( Flag::eTemp ) );
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
			, flags | uint32_t( Flag::eTemp ) );
	}

	inline VariablePtr makeVariable( uint32_t id
		, type::TypePtr type
		, std::string name )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, Flag::eTemp );
	}

	inline VariablePtr makeVariable( uint32_t id
		, type::TypePtr type
		, std::string name
		, uint32_t flags )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, flags | uint32_t( Flag::eTemp ) );
	}

	inline VariablePtr makeVariable( uint32_t id
		, type::TypePtr type
		, std::string name
		, Flag flag )
	{
		return std::make_shared< Variable >( EntityName{ id, name }
			, type
			, uint32_t( flag ) | uint32_t( Flag::eTemp ) );
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
