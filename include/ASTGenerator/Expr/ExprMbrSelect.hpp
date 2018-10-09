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

	private:
		VariablePtr m_variable;
	};
}

#endif
