/*
See LICENSE file in root folder
*/
#ifndef ___AST_ExprSwizzle_H___
#define ___AST_ExprSwizzle_H___
#pragma once

#include "Expr.hpp"
#include "SwizzleKind.hpp"

namespace ast::expr
{
	class Swizzle
		: public Expr
	{
	public:
		SDAST_API Swizzle( ExprCache & exprCache
			, ExprPtr outer
			, SwizzleKind swizzle );

		SDAST_API void accept( VisitorPtr vis )const override;

		inline Expr const * getOuterExpr()const
		{
			return m_outer.get();
		}

		inline SwizzleKind getSwizzle()const
		{
			return m_swizzle;
		}

	private:
		ExprPtr m_outer{};
		SwizzleKind m_swizzle;
	};
}

#endif
