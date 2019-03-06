/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprSwizzle.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	namespace
	{
		type::TypePtr getSwizzleType( type::TypesCache & cache
			, type::Kind outer
			, SwizzleKind swizzle )
		{
			if ( swizzle.isOneComponent() )
			{
				return cache.getBasicType( getScalarType( outer ) );
			}

			if ( swizzle.isTwoComponents() )
			{
				return cache.getVec2Type( getScalarType( outer ) );
			}

			if ( swizzle.isThreeComponents() )
			{
				return cache.getVec3Type( getScalarType( outer ) );
			}

			return cache.getVec4Type( getScalarType( outer ) );
		}
	}

	Swizzle::Swizzle( ExprPtr outer
		, SwizzleKind swizzle )
		: Expr{ getExprTypesCache( outer )
			, getSwizzleType( outer->getCache(), outer->getType()->getKind(), swizzle )
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
