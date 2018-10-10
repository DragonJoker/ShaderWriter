/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprMbrSelect_H___
#define ___AST_ExprMbrSelect_H___
#pragma once

#include "ExprIdentifier.hpp"
#include "ExprUnary.hpp"

namespace ast
{
	class ExprMbrSelect
		: public ExprUnary
	{
	public:
		ExprMbrSelect( VariablePtr variable
			, ExprIdentifierPtr member );

		void accept( ExprVisitorPtr vis )override;

		inline Variable const & getOuterVar()const
		{
			return *m_variable;
		}

	private:
		VariablePtr m_variable;
	};

	inline std::unique_ptr< ExprMbrSelect > makeMbrSelectExpr( VariablePtr variable
		, ExprIdentifierPtr member )
	{
		return std::make_unique< ExprMbrSelect >( std::move( variable )
			, std::move( member ) );
	}
}

#endif
