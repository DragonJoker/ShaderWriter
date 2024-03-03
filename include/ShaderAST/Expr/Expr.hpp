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
		eCopy,
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
		eCombinedImageAccessCall,
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
		eOrAssign,
		eXorAssign,
		eArrayAccess,
		eAlias,
		eStreamAppend,
	};

	enum class Flag
		: uint32_t
	{
		eNone = 0,
		eConstant = 1 << 0,
		eSpecialisationConstant = 1 << 1,
		eImplicit = 1 << 2,
		eNonUniform = 1 << 3,
		eDummy = 1 << 4,
	};

	class Expr
	{
	public:
		SDAST_API Expr( Expr const & ) = delete;
		SDAST_API Expr & operator=( Expr const & )noexcept = delete;
		SDAST_API Expr( Expr && )noexcept = delete;
		SDAST_API Expr & operator=( Expr && ) = delete;
		SDAST_API virtual ~Expr()noexcept = default;

		SDAST_API Expr( ExprCache & exprCache
			, size_t size
			, type::TypesCache & typesCache
			, type::TypePtr type
			, Kind kind
			, Flag flag = Flag::eNone );

		SDAST_API ExprPtr clone()const;

		SDAST_API virtual void accept( VisitorPtr )const
		{
		}

		inline Kind getKind()const noexcept
		{
			return m_kind;
		}

		inline uint32_t getFlags()const noexcept
		{
			return m_flags;
		}

		inline ExprCache & getExprCache()const noexcept
		{
			return *m_exprCache;
		}

		inline type::TypesCache & getTypesCache()const noexcept
		{
			return *m_typesCache;
		}

		inline type::TypePtr getType()const noexcept
		{
			return m_type;
		}

		inline void updateFlag( Flag flag, bool set = true )noexcept
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

		inline bool isSpecialisationConstant()const noexcept
		{
			return hasFlag( Flag::eSpecialisationConstant );
		}

		inline bool isConstant()const noexcept
		{
			return hasFlag( Flag::eConstant );
		}

		inline bool isImplicit()const noexcept
		{
			return hasFlag( Flag::eImplicit );
		}

		inline bool isNonUniform()const noexcept
		{
			return hasFlag( Flag::eNonUniform );
		}

		inline bool isDummy()const noexcept
		{
			return hasFlag( Flag::eDummy );
		}

	private:
		friend class ExprCache;

		size_t getSize()const noexcept
		{
			return m_size;
		}

		inline bool hasFlag( Flag flag )const noexcept
		{
			return Flag( m_flags & uint32_t( flag ) ) == flag;
		}

	private:
		ExprCache * m_exprCache;
		type::TypesCache * m_typesCache;
		size_t m_size;
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
