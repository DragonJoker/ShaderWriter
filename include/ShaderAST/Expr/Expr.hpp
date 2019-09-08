/*
See LICENSE file in root folder
*/
#ifndef ___AST_Expr_H___
#define ___AST_Expr_H___
#pragma once

#include "ShaderAST/Type/TypeCache.hpp"

namespace ast::expr
{
	enum class Kind
		: uint8_t
	{
		eAdd,
		eMinus,
		eTimes,
		eDivide,
		eModulo,
		eLShift,
		eRShift,
		eBitAnd,
		eBitNot,
		eBitOr,
		eBitXor,
		eLogAnd,
		eLogNot,
		eLogOr,
		eCast,
		eInit,
		eAggrInit,
		eFnCall,
		eCompositeConstruct,
		eIntrinsicCall,
		eTextureAccessCall,
		eImageAccessCall,
		eEqual,
		eGreater,
		eGreaterEqual,
		eLess,
		eLessEqual,
		eNotEqual,
		eComma,
		eIdentifier,
		eLiteral,
		eMbrSelect,
		eSwizzle,
		eSwitchTest,
		eSwitchCase,
		eQuestion,
		ePreIncrement,
		ePreDecrement,
		ePostIncrement,
		ePostDecrement,
		eUnaryMinus,
		eUnaryPlus,
		eAssign,
		eAddAssign,
		eMinusAssign,
		eTimesAssign,
		eDivideAssign,
		eModuloAssign,
		eLShiftAssign,
		eRShiftAssign,
		eAndAssign,
		eNotAssign,
		eOrAssign,
		eXorAssign,
		eArrayAccess,
		eAlias,
	};

	enum class Flag
		: uint32_t
	{
		eNone = 0,
		eConstant = 1 << 0,
		eSpecialisationConstant = 1 << 1,
		eImplicit = 1 << 2,
	};

	class Expr
	{
	public:
		Expr( type::TypesCache & cache
			, type::TypePtr type
			, Kind kind );
		virtual ~Expr();

		virtual void accept( VisitorPtr ) = 0;

		inline Kind getKind()const
		{
			return m_kind;
		}

		inline type::TypesCache & getCache()const
		{
			return m_cache;
		}

		inline type::TypePtr getType()const
		{
			return m_type;
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

		inline bool isSpecialisationConstant()const
		{
			return hasFlag( Flag::eSpecialisationConstant );
		}

		inline bool isConstant()const
		{
			return hasFlag( Flag::eConstant );
		}

		inline bool isImplicit()const
		{
			return hasFlag( Flag::eImplicit );
		}

	private:
		inline bool hasFlag( Flag flag )const
		{
			return Flag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		type::TypesCache & m_cache;
		Kind m_kind;
		type::TypePtr m_type;
		uint32_t m_flags;
	};

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
