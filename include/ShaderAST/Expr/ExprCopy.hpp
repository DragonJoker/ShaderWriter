/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprCopy_H___
#define ___AST_ExprCopy_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class Copy
		: public Unary
	{
	public:
		SDAST_API explicit Copy( ExprCache & exprCache
			, ExprPtr op );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
