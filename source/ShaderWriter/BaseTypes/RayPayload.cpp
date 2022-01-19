/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/RayPayload.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	RayPayload::RayPayload( ShaderWriter & writer
		, expr::Expr * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void RayPayload::traceRay( AccelerationStructure const & topLevel
		, UInt const & rayFlags
		, UInt const & cullMask
		, UInt const & sbtRecordOffset
		, UInt const & sbtRecordStride
		, UInt const & missIndex
		, Vec3 const & origin
		, Float const & Tmin
		, Vec3 const & direction
		, Float const & Tmax )
	{
		sdw::traceRay( topLevel
			, rayFlags
			, cullMask
			, sbtRecordOffset
			, sbtRecordStride
			, missIndex
			, origin
			, Tmin
			, direction
			, Tmax
			, *this );
	}

	expr::ExprPtr makeExpr( RayPayload const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
