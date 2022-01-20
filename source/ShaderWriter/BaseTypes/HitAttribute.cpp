/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/HitAttribute.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	HitAttribute::HitAttribute( ShaderWriter & writer
		, expr::Expr * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	ReturnWrapperT< Boolean > HitAttribute::reportIntersection( Float tHit
		, UInt const & hitKind )
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
