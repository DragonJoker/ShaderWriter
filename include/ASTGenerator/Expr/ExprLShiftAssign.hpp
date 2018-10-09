/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShiftAssign_H___
#define ___AST_ExprLShiftAssign_H___
#pragma once

#include "ExprAssign.hpp"

namespace ast
{
	class ExprLShiftAssign
		: public ExprAssign
	{
	public:
		ExprLShiftAssign( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
