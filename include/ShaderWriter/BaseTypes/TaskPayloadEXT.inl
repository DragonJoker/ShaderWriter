/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayloadEXT.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TaskPayloadOutEXTT< DataT >::TaskPayloadOutEXTT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PerTaskT< ast::EntryPoint::eTask, FlagT, DataT >{ writer, std::move( expr ), enabled }
		, m_internal{ writer, this->getExpr(), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TaskPayloadOutEXTT< DataT >::TaskPayloadOutEXTT( ShaderWriter & writer
		, ParamsT && ... params )
		: TaskPayloadOutEXTT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "payloadOut"
					, ast::type::makeTaskPayloadType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ) )
					, FlagT | ast::var::Flag::ePerTask ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void TaskPayloadOutEXTT< DataT >::dispatchMesh( UInt32 taskCountX
		, UInt32 taskCountY
		, UInt32 taskCountZ )const
	{
		return m_internal.dispatchMesh( taskCountX, taskCountY, taskCountZ );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TaskPayloadOutEXTT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return PerTaskT< ast::EntryPoint::eTask, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TaskPayloadInEXTT< DataT >::TaskPayloadInEXTT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PerTaskT< ast::EntryPoint::eMesh, FlagT, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TaskPayloadInEXTT< DataT >::TaskPayloadInEXTT( ShaderWriter & writer
		, ParamsT && ... params )
		: TaskPayloadInEXTT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "payloadIn"
					, ast::type::makeTaskPayloadInType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ) )
					, FlagT | ast::var::Flag::ePerTask ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TaskPayloadInEXTT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return PerTaskT< ast::EntryPoint::eMesh, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*********************************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadOutEXTT< DataT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadInEXTT< DataT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
