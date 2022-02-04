/*
See LICENSE file in root folder
*/
#ifndef ___AST_GlslSampledImageAccessFunctions_H___
#define ___AST_GlslSampledImageAccessFunctions_H___
#pragma once

#include "GlslHelpers.hpp"

#include <ShaderAST/Stmt/StmtContainer.hpp>

namespace glsl
{
	void compileGlslSampledImageAccessFunctions( ast::stmt::Container * container
		, IntrinsicsConfig const & config );
}

#endif
