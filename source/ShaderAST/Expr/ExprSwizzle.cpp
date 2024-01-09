/*
See LICENSE file in root folder
*/
#include "ShaderAST/Expr/ExprSwizzle.hpp"

#include "ShaderAST/Expr/ExprVisitor.hpp"

namespace ast::expr
{
	namespace
	{
		type::TypePtr getSwizzleType( type::TypesCache & typesCache
			, type::Kind outer
			, SwizzleKind swizzle )
		{
			if ( swizzle.isOneComponent() )
			{
				return typesCache.getBasicType( getScalarType( outer ) );
			}

			if ( swizzle.isTwoComponents() )
			{
				return typesCache.getVec2Type( getScalarType( outer ) );
			}

			if ( swizzle.isThreeComponents() )
			{
				return typesCache.getVec3Type( getScalarType( outer ) );
			}

			return typesCache.getVec4Type( getScalarType( outer ) );
		}
	}

	Swizzle::Swizzle( ExprCache & exprCache
		, ExprPtr outer
		, SwizzleKind swizzle )
		: Expr{ exprCache
			, sizeof( Swizzle )
			, getExprTypesCache( outer )
			, getSwizzleType( outer->getTypesCache(), outer->getType()->getKind(), swizzle )
			, Kind::eSwizzle
			, ( isExprConstant( outer ) ? Flag::eConstant : Flag::eNone ) }
		, m_outer{ std::move( outer ) }
		, m_swizzle{ swizzle }
	{
	}

	void Swizzle::accept( VisitorPtr vis )const
	{
		vis->visitSwizzleExpr( this );
	}
}
