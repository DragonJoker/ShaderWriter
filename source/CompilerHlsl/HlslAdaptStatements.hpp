/*
See LICENSE file in root folder
*/
#ifndef ___SDW_HlslAdaptStatements_H___
#define ___SDW_HlslAdaptStatements_H___
#pragma once

#include "HlslHelpers.hpp"
#include "HlslShader.hpp"

namespace hlsl
{
	ast::stmt::ContainerPtr adaptStatements( ast::stmt::StmtCache & stmtCache
		, ast::expr::ExprCache & exprCache
		, HlslShader & shader
		, ast::stmt::Container const & container
		, IntrinsicsConfig const & intrinsicsConfig
		, HlslConfig const & writerConfig
		, AdaptationData & adaptationData );
}

#endif
