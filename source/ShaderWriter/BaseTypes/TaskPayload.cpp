/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayload.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	TaskPayload::TaskPayload( ShaderWriter & writer
		, expr::Expr * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void TaskPayload::dispatchMesh( UInt32 taskCount )
	{
		sdw::dispatchMesh( *this, taskCount );
	}

	expr::ExprPtr makeExpr( TaskPayload const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
