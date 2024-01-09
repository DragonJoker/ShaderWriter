/*
See LICENSE file in root folder
*/
#ifndef ___AST_StreamAppend_H___
#define ___AST_StreamAppend_H___
#pragma once

#include "ExprUnary.hpp"

namespace ast::expr
{
	class StreamAppend
		: public Unary
	{
	public:
		SDAST_API StreamAppend( ExprCache & exprCache
			, type::TypePtr type
			, ExprPtr operand );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
