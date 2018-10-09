/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprModulo_H___
#define ___AST_ExprModulo_H___
#pragma once

#include "ExprBinary.hpp"

namespace ast
{
	class ExprModulo
		: public ExprBinary
	{
	public:
		ExprModulo( Type type
			, ExprPtr lhs
			, ExprPtr rhs );

		void accept( ExprVisitorPtr vis )override;
	};
}

#endif
