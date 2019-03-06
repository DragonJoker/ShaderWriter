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
		Swizzle( ExprPtr outer
			, SwizzleKind swizzle );

		void accept( VisitorPtr vis )override;

		inline Expr * getOuterExpr()const
		{
			return m_outer.get();
		}

		inline SwizzleKind getSwizzle()const
		{
			return m_swizzle;
		}

	private:
		ExprPtr m_outer;
		SwizzleKind m_swizzle;
	};
	using SwizzlePtr = std::unique_ptr< Swizzle >;

	inline SwizzlePtr makeSwizzle( ExprPtr outer
		, SwizzleKind swizzle )
	{
		assert( type::isVectorType( outer->getType()->getKind() ) );
		return std::make_unique< Swizzle >( std::move( outer )
			, swizzle );
	}
}

#endif
