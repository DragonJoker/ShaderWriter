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
		SDAST_API Swizzle( ExprPtr outer
			, SwizzleKind swizzle );

		SDAST_API void accept( VisitorPtr vis )override;

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
		assert( type::isVectorType( outer->getType()->getKind() )
			|| ( type::isScalarType( outer->getType()->getKind() )
				&& ( swizzle == SwizzleKind::e0
					|| swizzle == SwizzleKind::e00
					|| swizzle == SwizzleKind::e000
					|| swizzle == SwizzleKind::e0000 ) ) );
		return std::make_unique< Swizzle >( std::move( outer )
			, swizzle );
	}
}

#endif
