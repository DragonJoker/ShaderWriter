/*
See LICENSE file in root folder
*/
#ifndef ___SDW_PerVertex_H___
#define ___SDW_PerVertex_H___
#pragma once

#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ShaderAST/Stmt/StmtPerVertexDecl.hpp>
#include <ShaderAST/Var/VariableList.hpp>

namespace sdw
{
	struct gl_PerVertex
		: public Value
	{
		SDW_API gl_PerVertex();
		SDW_API gl_PerVertex( ast::Shader * shader
			, ast::expr::ExprPtr expr );
		SDW_API gl_PerVertex( ShaderWriter & writer
			, stmt::PerVertexDecl::Source source = stmt::PerVertexDecl::eVertexOutput );
		Vec4 gl_Position;
		Float gl_PointSize;
		Array< Float > gl_ClipDistance;
		Array< Float > gl_CullDistance;

		SDW_API static ast::type::StructPtr getBaseType( ast::type::TypesCache & cache );
		SDW_API static ast::type::ArrayPtr getArrayType( ast::type::TypesCache & cache );
	};
}

#endif
