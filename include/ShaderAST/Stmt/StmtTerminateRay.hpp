/*
See LICENSE file in root folder
*/
#ifndef ___AST_StmtTerminateRay_H___
#define ___AST_StmtTerminateRay_H___
#pragma once

#include "Stmt.hpp"

#include "ShaderAST/Expr/Expr.hpp"

namespace ast::stmt
{
	class TerminateRay
		: public Stmt
	{
	public:
		SDAST_API TerminateRay();

		SDAST_API void accept( VisitorPtr vis )override;
	};
	using TerminateRayPtr = std::unique_ptr< TerminateRay >;

	inline TerminateRayPtr makeTerminateRay()
	{
		return std::make_unique< TerminateRay >();
	}
}

#endif
