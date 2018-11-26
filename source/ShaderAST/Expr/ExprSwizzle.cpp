/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprSwizzle.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	namespace
	{
		type::TypePtr getSwizzleType( type::TypePtr outer
			, SwizzleKind swizzle )
		{
			if ( swizzle >= SwizzleKind::e0
				&& swizzle <= SwizzleKind::e3 )
			{
				return makeType( getScalarType( outer->getKind() ) );
			}

			if ( swizzle >= SwizzleKind::e00
				&& swizzle <= SwizzleKind::e33 )
			{
				return getVec2Type( getScalarType( outer->getKind() ) );
			}

			if ( swizzle >= SwizzleKind::e000
				&& swizzle <= SwizzleKind::e333 )
			{
				return getVec3Type( getScalarType( outer->getKind() ) );
			}

			return getVec4Type( getScalarType( outer->getKind() ) );
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
