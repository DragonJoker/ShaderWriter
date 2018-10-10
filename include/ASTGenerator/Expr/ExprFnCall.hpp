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

		inline ExprIdentifier * getFn()const
		{
			return m_fn.get();
		}

	private:
		ExprIdentifierPtr m_fn;
		ExprList m_argList;
	};

	inline std::unique_ptr< ExprFnCall > makeFnCallExpr( Type type
		, ExprIdentifierPtr fn
		, ExprList && argList )
	{
		return std::make_unique< ExprFnCall >( type
			, std::move( fn )
			, std::move( argList ) );
	}
}

#endif
