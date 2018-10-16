/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtEmitVertex_H___
#define ___AST_StmtEmitVertex_H___
#pragma once

#include "Stmt.hpp"

#include "ASTGenerator/Expr/Expr.hpp"

namespace ast::stmt
{
	class EmitVertex
		: public Stmt
	{
	public:
		EmitVertex();

		void accept( VisitorPtr vis )override;
	};
	using EmitVertexPtr = std::unique_ptr< EmitVertex >;

	inline EmitVertexPtr makeEmitVertex()
	{
		return std::make_unique< EmitVertex >();
	}
}

#endif
