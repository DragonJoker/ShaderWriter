/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/RayPayload.hpp"

#include "ShaderWriter/BaseTypes/AccelerationStructure.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	RayPayload::RayPayload( ShaderWriter & writer
		, expr::Expr const * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void RayPayload::traceRay( AccelerationStructure const topLevel
		, UInt32 const rayFlags
		, UInt32 const cullMask
		, UInt32 const sbtRecordOffset
		, UInt32 const sbtRecordStride
		, UInt32 const missIndex
		, RayDesc const rayDesc )const
	{
		sdw::traceRay( topLevel
			, rayFlags
			, cullMask
			, sbtRecordOffset
			, sbtRecordStride
			, missIndex
			, rayDesc
			, *this );
	}

	expr::ExprPtr makeExpr( RayPayload const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
