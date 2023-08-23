#include "ShaderWriter/Helpers.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TaskIn{ *this, localSizeX, 1u, 1u } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TaskSubgroupIn{ *this, localSizeX, 1u, 1u } )
			, makeParam( std::move( payload ) ) );
	}


	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterNV::dispatchMesh( UInt numGroups
		, TaskPayloadOutNVT< PayloadT > const & payload )
	{
		addStmt( sdw::makeSimple( sdw::makeDispatchMeshNV( getTypesCache()
			, makeExpr( payload )
			, makeExpr( numGroups ) ) ) );
	}

	//*************************************************************************
}
