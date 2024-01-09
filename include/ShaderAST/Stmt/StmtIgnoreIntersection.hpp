/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtIgnoreIntersection_H___
#define ___AST_StmtIgnoreIntersection_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class IgnoreIntersection
		: public Stmt
	{
	public:
		SDAST_API explicit IgnoreIntersection( StmtCache & stmtCache );

		SDAST_API void accept( VisitorPtr vis )const override;
	};
}

#endif
