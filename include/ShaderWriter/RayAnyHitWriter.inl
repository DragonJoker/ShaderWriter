/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayAnyHitWriter.hpp"

namespace sdw
{
	template< typename PayloadT, typename AttrT >
	void RayAnyHitWriter::implementMainT( uint32_t payloadLocation
		, RayAnyHitMainFuncT< PayloadT, AttrT > const & function )
	{
		this->implementMainT( RayPayloadInT< PayloadT >{ *this, payloadLocation }
			, HitAttributeT< AttrT >{ *this }
			, function );
	}

	template< typename PayloadT, typename AttrT >
	void RayAnyHitWriter::implementMainT( RayPayloadInT< PayloadT > payload
		, HitAttributeT< AttrT > attribute
		, RayAnyHitMainFuncT< PayloadT, AttrT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eRayAnyHitEntryPoint )
			, function
			, makeInParam( RayAnyHitIn{ *this } )
			, makeInOutParam( std::move( payload ) )
			, makeInParam( std::move( attribute ) ) );
	}
}
