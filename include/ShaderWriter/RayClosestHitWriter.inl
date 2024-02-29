/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayClosestHitWriter.hpp"

namespace sdw
{
	template< typename PayloadT, typename AttrT >
	void RayClosestHitWriter::implementMainT( uint32_t payloadLocation
		, RayClosestHitMainFuncT< PayloadT, AttrT > const & function )
	{
		this->implementMainT( RayPayloadInT< PayloadT >{ *this, payloadLocation }
		, HitAttributeT< AttrT >{ *this }
		, function );
	}

	template< typename PayloadT, typename AttrT >
	void RayClosestHitWriter::implementMainT( RayPayloadInT< PayloadT > payload
		, HitAttributeT< AttrT > attribute
		, RayClosestHitMainFuncT< PayloadT, AttrT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eRayClosestHitEntryPoint )
			, function
			, makeInParam( RayClosestHitIn{ *this } )
			, makeInOutParam( std::move( payload ) )
			, makeInParam( std::move( attribute ) ) );
	}
}
