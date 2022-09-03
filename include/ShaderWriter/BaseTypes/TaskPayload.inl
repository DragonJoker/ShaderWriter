/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayload.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TaskPayloadOutT< DataT >::TaskPayloadOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PerTaskT< DataT, FlagT >{ writer, std::move( expr ), enabled }
		, m_internal{ writer, this->getExpr(), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TaskPayloadOutT< DataT >::TaskPayloadOutT( ShaderWriter & writer
		, ParamsT ... params )
		: TaskPayloadOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "payloadOut"
					, ast::type::makeTaskPayloadType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ) )
					, FlagT | ast::var::Flag::ePerTask ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void TaskPayloadOutT< DataT >::dispatchMesh( UInt32 taskCount )
	{
		m_internal.dispatchMesh( taskCount );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TaskPayloadOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return PerTaskT< DataT, FlagT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TaskPayloadInT< DataT >::TaskPayloadInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PerTaskT< DataT, FlagT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TaskPayloadInT< DataT >::TaskPayloadInT( ShaderWriter & writer
		, ParamsT ... params )
		: TaskPayloadInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "payloadIn"
					, ast::type::makeTaskPayloadInType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ) )
					, FlagT | ast::var::Flag::ePerTask ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TaskPayloadInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return PerTaskT< DataT, FlagT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*********************************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadOutT< DataT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadInT< DataT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
