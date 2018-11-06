/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SpirvExprEvaluator_H___
#define ___SDW_SpirvExprEvaluator_H___
#pragma once

#include "SpirvHelpers.hpp"

namespace sdw::spirv
{
	bool eval( expr::Expr * expr
		, PreprocContext const & context );
	expr::LiteralPtr getLiteral( expr::Expr * expr
		, PreprocContext const & context );
}

#endif
