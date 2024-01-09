/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayloadEXT.hpp"

#include "ShaderWriter/Writer.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	TaskPayloadEXT::TaskPayloadEXT( ShaderWriter & writer
		, expr::Expr const * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void TaskPayloadEXT::dispatchMesh( UInt32 const taskCountX
		, UInt32 const taskCountY
		, UInt32 const taskCountZ )const
	{
		getWriter()->addStmt( makeDispatchMesh( getStmtCache( m_plWriter )
			, makeExpr( taskCountX )
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
