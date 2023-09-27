/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprEvaluator_H___
#define ___SDW_SpirvExprEvaluator_H___
#pragma once

#include "SpirvHelpers.hpp"

namespace spirv
{
	bool eval( ast::expr::ExprCache & exprCache
		, ast::expr::Expr * expr
		, PreprocContext const & context );
	ast::expr::LiteralPtr getLiteral( ast::expr::ExprCache & exprCache
		, ast::expr::Expr * expr
		, PreprocContext const & context );
}

#endif
