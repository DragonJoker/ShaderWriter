/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/TaskPayloadNV.hpp"

#include <ShaderAST/Visitors/GetExprName.hpp>

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TaskPayloadOutNVT< DataT >::TaskPayloadOutNVT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PerTaskNVT< ast::EntryPoint::eTaskNV, FlagT, DataT >{ writer, std::move( expr ), enabled }
		, m_internal{ writer, this->getExpr(), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TaskPayloadOutNVT< DataT >::TaskPayloadOutNVT( ShaderWriter & writer
		, ParamsT && ... params )
		: TaskPayloadOutNVT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "payloadOut"
					, ast::type::makeTaskPayloadNVType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ) )
					, FlagT | ast::var::Flag::ePerTaskNV ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	void TaskPayloadOutNVT< DataT >::dispatchMesh( UInt32 taskCount )const
	{
		m_internal.dispatchMesh( taskCount );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TaskPayloadOutNVT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return PerTaskNVT< ast::EntryPoint::eTaskNV, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TaskPayloadInNVT< DataT >::TaskPayloadInNVT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PerTaskNVT< ast::EntryPoint::eMeshNV, FlagT, DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	TaskPayloadInNVT< DataT >::TaskPayloadInNVT( ShaderWriter & writer
		, ParamsT && ... params )
		: TaskPayloadInNVT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "payloadIn"
					, ast::type::makeTaskPayloadInNVType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... ) )
					, FlagT | ast::var::Flag::ePerTaskNV ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TaskPayloadInNVT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return PerTaskNVT< ast::EntryPoint::eMeshNV, FlagT, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*********************************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadOutNVT< DataT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	expr::ExprPtr makeExpr( TaskPayloadInNVT< DataT > const & value )
	{
		return makeExpr( *value.getWriter(), value.getExpr() );
	}

	//*********************************************************************************************
}
