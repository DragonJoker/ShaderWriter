/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwitchCase_H___
#define ___AST_ExprSwitchCase_H___
#pragma once

#include "ExprLiteral.hpp"

namespace ast::expr
{
	class SwitchCase
		: public Expr
	{
	public:
		SDAST_API explicit SwitchCase( ExprCache & exprCache
			, LiteralPtr label );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline Literal * getLabel()const
		{
			return m_label.get();
		}

	private:
		LiteralPtr m_label{};
	};
}

#endif
