
namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void TaskWriter::implementMainT( uint32_t localSizeX
		, TaskPayloadOutT< PayloadT > payload
		, TaskMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TaskIn{ *this, localSizeX } )
			, makeParam( std::move( payload ) ) );
	}

	//*************************************************************************
}
