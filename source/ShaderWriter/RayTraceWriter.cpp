/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayTraceWriter.hpp"

#include <ShaderAST/Stmt/StmtIgnoreIntersection.hpp>
#include <ShaderAST/Stmt/StmtTerminateRay.hpp>

namespace sdw
{
	RayTraceWriter::RayTraceWriter( ShaderAllocator * allocator )
		: PipelineWriter{ ast::ShaderStage::eRayTrace, allocator }
	{
	}

	RayTraceWriter::RayTraceWriter( ShaderBuilder & builder )
		: PipelineWriter{ builder }
	{
		if ( builder.getType() != ast::ShaderStage::eRayTrace )
		{
			throw ast::Exception{ "Can't create a RayTraceWriter from this kind of builder." };
		}
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
			, getEntryPointFlags( ast::EntryPoint::eRayGeneration ) | uint32_t( ast::stmt::FunctionFlag::eRayGenerationEntryPoint )
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
			, getEntryPointFlags( ast::EntryPoint::eRayIntersection ) | uint32_t( ast::stmt::FunctionFlag::eRayIntersectionEntryPoint )
			, function
			, makeInParam( RayIntersectionIn{ *this } ) );
	}
	/**@}*/
}
