/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprLShift_H___
#define ___AST_ExprLShift_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprLShift
		: public ExprBinary
	{
	public:
		ExprLShift( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
