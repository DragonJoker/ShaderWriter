/*
See LICENSE file in root folder
*/
#ifndef ___SDW_RayTraceWriter_H___
#define ___SDW_RayTraceWriter_H___

#include "ShaderWriter/CallableWriter.hpp"
#include "ShaderWriter/PipelineWriter.hpp"
#include "ShaderWriter/RayAnyHitWriter.hpp"
#include "ShaderWriter/RayClosestHitWriter.hpp"
#include "ShaderWriter/RayGenerationWriter.hpp"
#include "ShaderWriter/RayIntersectionWriter.hpp"
#include "ShaderWriter/RayMissWriter.hpp"

namespace sdw
{
	class RayTraceWriter
		: public PipelineWriter
	{
	public:
		SDW_API explicit RayTraceWriter( ShaderAllocator * allocator = nullptr );
		SDW_API explicit RayTraceWriter( ShaderBuilder & builder );
		/**
		*name
		*	Callable.
		*/
		/**@{*/
		template< typename ValueT >
		void implementEntryPointT( uint32_t dataLocation
			, CallableMainFuncT< ValueT > const & function );
		template< typename ValueT >
		void implementEntryPointT( CallableDataInT< ValueT > data
			, CallableMainFuncT< ValueT > const & function );
		/**@}*/
		/**
		*name
		*	Ray Any Hit.
		*/
		/**@{*/
		template< typename PayloadT, typename AttrT >
		void implementEntryPointT( uint32_t payloadLocation
			, RayAnyHitMainFuncT< PayloadT, AttrT > const & function );
		template< typename PayloadT, typename AttrT >
		void implementEntryPointT( RayPayloadInT< PayloadT > payload
			, HitAttributeT< AttrT > attribute
			, RayAnyHitMainFuncT< PayloadT, AttrT > const & function );

		SDW_API void ignoreIntersection();
		SDW_API void terminateRay();
		/**@}*/
		/**
		*name
		*	Ray Closest Hit.
		*/
		/**@{*/
		template< typename PayloadT, typename AttrT >
		void implementEntryPointT( uint32_t payloadLocation
			, RayClosestHitMainFuncT< PayloadT, AttrT > const & function );
		template< typename PayloadT, typename AttrT >
		void implementEntryPointT( RayPayloadInT< PayloadT > payload
			, HitAttributeT< AttrT > attribute
			, RayClosestHitMainFuncT< PayloadT, AttrT > const & function );
		/**@}*/
		/**
		*name
		*	Ray Generation.
		*/
		/**@{*/
		SDW_API void implementEntryPoint( RayGenerationMainFunc const & function );
		/**@}*/
		/**
		*name
		*	Ray Intersection.
		*/
		/**@{*/
		SDW_API void implementEntryPoint( RayIntersectionMainFunc const & function );
		/**@}*/
		/**
		*name
		*	Ray Miss.
		*/
		/**@{*/
		template< typename PayloadT >
		void implementEntryPointT( uint32_t payloadLocation
			, RayMissMainFuncT< PayloadT > const & function );
		template< typename PayloadT >
		void implementEntryPointT( RayPayloadInT< PayloadT > payload
			, RayMissMainFuncT< PayloadT > const & function );
		/**@}*/
	};
}

#include "RayTraceWriter.inl"

#endif
