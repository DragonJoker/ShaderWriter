/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CallableWriter.hpp"

namespace sdw
{
	/**
	*name
	*	Callable.
	*/
	/**@{*/
	template< typename ValueT >
	void RayTraceWriter::implementEntryPointT( uint32_t dataLocation
		, CallableMainFuncT< ValueT > const & function )
	{
		this->implementEntryPointT( CallableDataInT< ValueT >{ *this, dataLocation }
			, function );
	}

	template< typename ValueT >
	void RayTraceWriter::implementEntryPointT( CallableDataInT< ValueT > data
		, CallableMainFuncT< ValueT > const & function )
	{
		( void )implementFunction< Void >( "mainCallable"
			, getEntryPointFlags( ast::EntryPoint::eCallable ) | uint32_t( ast::stmt::FunctionFlag::eCallableEntryPoint )
			, function
			, makeInParam( CallableIn{ *this } )
			, makeInOutParam( std::move( data ) ) );
	}
	/**@}*/
	/**
	*name
	*	Ray Any Hit.
	*/
	/**@{*/
	template< typename PayloadT, typename AttrT >
	void RayTraceWriter::implementEntryPointT( uint32_t payloadLocation
		, RayAnyHitMainFuncT< PayloadT, AttrT > const & function )
	{
		this->implementEntryPointT( RayPayloadInT< PayloadT >{ *this, payloadLocation }
			, HitAttributeT< AttrT >{ *this }
			, function );
	}

	template< typename PayloadT, typename AttrT >
	void RayTraceWriter::implementEntryPointT( RayPayloadInT< PayloadT > payload
		, HitAttributeT< AttrT > attribute
		, RayAnyHitMainFuncT< PayloadT, AttrT > const & function )
	{
		( void )implementFunction< Void >( "mainAnyHit"
			, getEntryPointFlags( ast::EntryPoint::eRayAnyHit ) | uint32_t( ast::stmt::FunctionFlag::eRayAnyHitEntryPoint )
			, function
			, makeInParam( RayAnyHitIn{ *this } )
			, makeInOutParam( std::move( payload ) )
			, makeInParam( std::move( attribute ) ) );
	}
	/**@}*/
	/**
	*name
	*	Ray Closest Hit.
	*/
	/**@{*/
	template< typename PayloadT, typename AttrT >
	void RayTraceWriter::implementEntryPointT( uint32_t payloadLocation
		, RayClosestHitMainFuncT< PayloadT, AttrT > const & function )
	{
		this->implementEntryPointT( RayPayloadInT< PayloadT >{ *this, payloadLocation }
		, HitAttributeT< AttrT >{ *this }
		, function );
	}

	template< typename PayloadT, typename AttrT >
	void RayTraceWriter::implementEntryPointT( RayPayloadInT< PayloadT > payload
		, HitAttributeT< AttrT > attribute
		, RayClosestHitMainFuncT< PayloadT, AttrT > const & function )
	{
		( void )implementFunction< Void >( "mainRayClosestHit"
			, getEntryPointFlags( ast::EntryPoint::eRayClosestHit ) | uint32_t( ast::stmt::FunctionFlag::eRayClosestHitEntryPoint )
			, function
			, makeInParam( RayClosestHitIn{ *this } )
			, makeInOutParam( std::move( payload ) )
			, makeInParam( std::move( attribute ) ) );
	}
	/**@}*/
	/**
	*name
	*	Ray Miss.
	*/
	/**@{*/
	template< typename PayloadT >
	void RayTraceWriter::implementEntryPointT( uint32_t payloadLocation
		, RayMissMainFuncT< PayloadT > const & function )
	{
		this->implementEntryPointT( RayPayloadInT< PayloadT >{ *this, payloadLocation }
		, function );
	}

	template< typename PayloadT >
	void RayTraceWriter::implementEntryPointT( RayPayloadInT< PayloadT > payload
		, RayMissMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainRayMiss"
			, getEntryPointFlags( ast::EntryPoint::eRayMiss ) | uint32_t( ast::stmt::FunctionFlag::eRayMissEntryPoint )
			, function
			, makeInParam( RayMissIn{ *this } )
			, makeInOutParam( std::move( payload ) ) );
	}
	/**@}*/
}
