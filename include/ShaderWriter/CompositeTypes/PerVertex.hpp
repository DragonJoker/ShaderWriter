/*
See LICENSE file in root folder
*/
#ifndef ___SDW_PerVertex_H___
#define ___SDW_PerVertex_H___
#pragma once

#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ASTGenerator/Stmt/StmtPerVertexDecl.hpp>
#include <ASTGenerator/Var/VariableList.hpp>

namespace sdw
{
	struct gl_PerVertex
		: public Value
	{
		gl_PerVertex();
		gl_PerVertex( ShaderWriter & writer
			, stmt::PerVertexDecl::Source source = stmt::PerVertexDecl::eVertexOutput );
		Vec4 gl_Position;
		Float gl_PointSize;
		Array< Float > gl_ClipDistance;
	};
}

#endif
