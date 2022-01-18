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
		SDAST_API IgnoreIntersection();

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using IgnoreIntersectionPtr = std::unique_ptr< IgnoreIntersection >;

	inline IgnoreIntersectionPtr makeIgnoreIntersection()
	{
		return std::make_unique< IgnoreIntersection >();
	}
}

#endif
