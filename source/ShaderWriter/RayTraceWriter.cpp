/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayTraceWriter.hpp"

namespace sdw
{
	RayTraceWriter::RayTraceWriter( ShaderAllocator * allocator )
		: PipelineWriter{ ast::ShaderStage::eRayTrace, allocator }
	{
	}
	/**
	*name
	*	Ray Any Hit.
	*/
	/**@{*/
	void RayTraceWriter::ignoreIntersection()
	{
		addStmt( getStmtCache().makeIgnoreIntersection() );
	}

	void RayTraceWriter::terminateRay()
	{
		addStmt( getStmtCache().makeTerminateRay() );
	}
	/**@}*/
	/**
	*name
	*	Ray Generation.
	*/
	/**@{*/
	void RayTraceWriter::implementEntryPoint( RayGenerationMainFunc const & function )
	{
		( void )implementFunction< Void >( "mainRayGeneration"
			, ast::stmt::FunctionFlag::eRayGenerationEntryPoint
			, function
			, makeInParam( RayGenerationIn{ *this } ) );
	}
	/**@}*/
	/**
	*name
	*	Ray Intersection.
	*/
	/**@{*/
	void RayTraceWriter::implementEntryPoint( RayIntersectionMainFunc const & function )
	{
		( void )implementFunction< Void >( "mainRayIntersection"
			, ast::stmt::FunctionFlag::eRayIntersectionEntryPoint
			, function
			, makeInParam( RayIntersectionIn{ *this } ) );
	}
	/**@}*/
}
