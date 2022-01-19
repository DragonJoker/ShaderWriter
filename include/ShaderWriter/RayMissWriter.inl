/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayMissWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	template< typename PayloadT >
	void RayMissWriter::implementMainT( uint32_t payloadLocation
		, RayMissMainFuncT< PayloadT > const & function )
	{
		this->implementMainT( RayPayloadInT< PayloadT >{ *this, payloadLocation }
		, function );
	}

	template< typename PayloadT >
	void RayMissWriter::implementMainT( RayPayloadInT< PayloadT > payload
		, RayMissMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( RayMissIn{ *this } )
			, makeInOutParam( std::move( payload ) ) );
	}
}
