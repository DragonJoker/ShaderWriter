/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayloadNV.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	TaskPayloadNV::TaskPayloadNV( ShaderWriter & writer
		, expr::Expr const * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void TaskPayloadNV::dispatchMesh( UInt32 taskCount )const
	{
		sdw::dispatchMeshNV( *this, taskCount );
	}

	expr::ExprPtr makeExpr( TaskPayloadNV const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
