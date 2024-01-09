/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/CallableData.hpp"
#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	CallableData::CallableData( ShaderWriter & writer
		, expr::Expr const * expr
		, bool enabled )
		: m_plWriter{ &writer }
		, m_plExpr{ expr }
		, m_plEnabled{ enabled }
	{
	}

	void CallableData::execute( UInt32 const & sbtRecordIndex )const
	{
		sdw::executeCallable( sbtRecordIndex
			, *this );
	}

	expr::ExprPtr makeExpr( CallableData const & value )
	{
		return makeExpr( *value.getWriter()
			, value.getExpr()
			, true );
	}
}
