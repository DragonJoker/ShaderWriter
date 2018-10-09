/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprFnCall_H___
#define ___AST_ExprFnCall_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprList.hpp"

namespace ast
{
	class ExprFnCall
		: public Expr
	{
	public:
		ExprFnCall( Type type
			, ExprIdentifierPtr fn
			, ExprList && argList );

		void accept( ExprVisitorPtr vis )override;

		inline ExprList const & getArgList()const
		{
			return m_argList;
		}

		inline ExprIdentifier const & getFn()const
		{
			return *m_fn;
		}

	private:
		ExprIdentifierPtr m_fn;
		ExprList m_argList;
	};
}

#endif
