namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriter::dispatchMesh( UInt numGroupsX
		, UInt numGroupsY
		, UInt numGroupsZ
		, TaskPayloadOutT< PayloadT > const & payload )
	{
		addStmt( makeDispatchMesh( makeExpr( numGroupsX )
			, makeExpr( numGroupsY )
			, makeExpr( numGroupsZ )
			, makeExpr( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadOutT< PayloadT > payload
		, TaskMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TaskIn{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadOutT< PayloadT > payload
		, TaskSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TaskSubgroupIn{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeParam( std::move( payload ) ) );
	}

	//*************************************************************************
}
