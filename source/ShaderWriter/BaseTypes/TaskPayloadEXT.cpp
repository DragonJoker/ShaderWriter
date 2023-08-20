/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayloadEXT.hpp"

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	TaskPayloadEXT::TaskPayloadEXT( ShaderWriter & writer
		, expr::Expr * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void TaskPayloadEXT::dispatchMesh( UInt32 taskCountX
		, UInt32 taskCountY
		, UInt32 taskCountZ )const
	{
		getWriter()->addStmt( makeDispatchMesh( makeExpr( taskCountX )
			, makeExpr( taskCountY )
			, makeExpr( taskCountZ )
			, makeExpr( *this ) ) );
	}

	expr::ExprPtr makeExpr( TaskPayloadEXT const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
