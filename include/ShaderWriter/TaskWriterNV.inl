#include "ShaderWriter/Helpers.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterNV::implementMainT( uint32_t taskCount
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPointNV )
			, function
			, makeInParam( TaskInNV{ *this, taskCount } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterNV::implementMainT( uint32_t taskCount
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPointNV )
			, function
			, makeInParam( TaskSubgroupInNV{ *this, taskCount } )
			, makeParam( std::move( payload ) ) );
	}


	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterNV::dispatchMesh( UInt numGroups
		, TaskPayloadOutNVT< PayloadT > const & payload )
	{
		addStmt( sdw::makeSimple( getStmtCache()
			, sdw::makeDispatchMeshNV( getTypesCache()
				, makeExpr( payload )
				, makeExpr( numGroups ) ) ) );
	}

	//*************************************************************************
}
