/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprFnCall_H___
#define ___AST_ExprFnCall_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprList.hpp"

namespace ast::expr
{
	class FnCall
		: public Expr
	{
	public:
		SDAST_API FnCall( ExprCache & exprCache
			, type::TypePtr type
			, IdentifierPtr fn
			, ExprList argList );
		SDAST_API FnCall( ExprCache & exprCache
			, type::TypePtr type
			, IdentifierPtr fn
			, ExprPtr instance
			, ExprList argList );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline Identifier const * getFn()const
		{
			return m_fn.get();
		}

		inline bool isMember()const
		{
			return m_instance != nullptr;
		}

		inline Expr const * getInstance()const
		{
			return m_instance.get();
		}

	private:
		IdentifierPtr m_fn{};
		ExprList m_argList;
		ExprPtr m_instance{};
	};
}

#endif
