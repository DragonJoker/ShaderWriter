/*
See LICENSE file in root folder
*/
#include "ASTGenerator/Expr/ExprSwizzle.hpp"

#include "ASTGenerator/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	namespace
	{
		type::TypePtr getSwizzleType( type::TypePtr outer
			, SwizzleKind swizzle )
		{
			assert( isVectorType( outer->getKind() ) );

			if ( swizzle >= SwizzleKind::e0
				&& swizzle <= SwizzleKind::e3 )
			{
				return makeType( getComponentType( outer->getKind() ) );
			}

			if ( swizzle >= SwizzleKind::e00
				&& swizzle <= SwizzleKind::e33 )
			{
				return getVec2Type( getComponentType( outer->getKind() ) );
			}

			if ( swizzle >= SwizzleKind::e000
				&& swizzle <= SwizzleKind::e333 )
			{
				return getVec3Type( getComponentType( outer->getKind() ) );
			}

			return getVec4Type( getComponentType( outer->getKind() ) );
		}
	}

	Swizzle::Swizzle( ExprPtr outer
		, SwizzleKind swizzle )
		: Expr{ getSwizzleType( outer->getType(), swizzle )
			, Kind::eSwizzle }
		, m_outer{ std::move( outer ) }
		, m_swizzle{ swizzle }
	{
	}

	void Swizzle::accept( VisitorPtr vis )
	{
		vis->visitSwizzleExpr( this );
	}
}
