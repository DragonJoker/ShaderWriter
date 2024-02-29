/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CallableWriter.hpp"

namespace sdw
{
	template< typename ValueT >
	void CallableWriter::implementMainT( uint32_t dataLocation
		, CallableMainFuncT< ValueT > const & function )
	{
		this->implementMainT( CallableDataInT< ValueT >{ *this, dataLocation }
			, function );
	}

	template< typename ValueT >
	void CallableWriter::implementMainT( CallableDataInT< ValueT > data
		, CallableMainFuncT< ValueT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eCallableEntryPoint )
			, function
			, makeInParam( CallableIn{ *this } )
			, makeInOutParam( std::move( data ) ) );
	}
}
