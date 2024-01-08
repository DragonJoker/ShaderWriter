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
	struct PerVertex
	{
		SDW_API explicit PerVertex( StructInstance const & instance );

		Vec4 position;
		Float pointSize;
		Array< Float > clipDistance;
		Array< Float > cullDistance;

		SDW_API static void fillType( ast::type::IOStruct & structType );
	};
}

#endif
