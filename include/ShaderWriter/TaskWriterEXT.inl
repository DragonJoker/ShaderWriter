namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterEXT::dispatchMesh( UInt numGroupsX
		, UInt numGroupsY
		, UInt numGroupsZ
		, TaskPayloadOutEXTT< PayloadT > const & payload )
	{
		addStmt( makeDispatchMesh( getStmtCache()
			, makeExpr( numGroupsX )
			, makeExpr( numGroupsY )
			, makeExpr( numGroupsZ )
			, makeExpr( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadOutEXTT< PayloadT > payload
		, TaskEXTMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPoint )
			, function
			, makeInParam( TaskInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadOutEXTT< PayloadT > payload
		, TaskEXTSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPoint )
			, function
			, makeInParam( TaskSubgroupInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeParam( std::move( payload ) ) );
	}

	//*************************************************************************
}
