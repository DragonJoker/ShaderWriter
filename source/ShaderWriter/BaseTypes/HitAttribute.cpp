/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/HitAttribute.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	HitAttribute::HitAttribute( ShaderWriter & writer
		, expr::Expr const * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	ReturnWrapperT< Boolean > HitAttribute::reportIntersection( Float const tHit
		, UInt32 const hitKind )const
	{
		return sdw::reportIntersection( tHit
			, hitKind
			, *this );
	}

	expr::ExprPtr makeExpr( HitAttribute const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
