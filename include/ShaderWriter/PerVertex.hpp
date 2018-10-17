/*
See LICENSE file in root folder
*/
#ifndef ___Writer_PerVertex_H___
#define ___Writer_PerVertex_H___
#pragma once

#include "Vec4.hpp"

#include <ASTGenerator/Stmt/StmtPerVertexDecl.hpp>

namespace sdw
{
	struct gl_PerVertex
		: public Value
	{
		gl_PerVertex();
		gl_PerVertex( ShaderWriter & writer
			, stmt::PerVertexDecl::Source source = stmt::PerVertexDecl::eVertexOutput );
		Vec4 gl_Position()const;
		Float gl_PointSize()const;
		Float gl_ClipDistance()const;

	private:
		stmt::PerVertexDecl::Source m_source;
	};
}

#endif
