/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwitchCase_H___
#define ___AST_ExprSwitchCase_H___
#pragma once

#include "ExprLiteral.hpp"

namespace ast
{
	class ExprSwitchCase
		: public Expr
	{
	public:
		ExprSwitchCase( ExprLiteralPtr label );

		void accept( ExprVisitorPtr vis )override;

		inline ExprLiteral const & getLabel()const
		{
			return *m_label;
		}

	private:
		ExprLiteralPtr m_label;
	};
}

#endif
