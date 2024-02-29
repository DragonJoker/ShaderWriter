/*
See LICENSE file in root folder
*/
#include "ModernGraphicsWriterNV.hpp"

namespace sdw
{
	//*************************************************************************

	/**
	*name
	*	Task Shader.
	*/
	/**@{*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t taskCount
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainTask"
			, getEntryPointFlags( ast::EntryPoint::eTaskNV ) | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPointNV )
			, function
			, makeInParam( TaskInNV{ *this, taskCount } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t taskCount
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainTask"
			, getEntryPointFlags( ast::EntryPoint::eTaskNV ) | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPointNV )
			, function
			, makeInParam( TaskSubgroupInNV{ *this, taskCount } )
			, makeParam( std::move( payload ) ) );
	}
	/**@}*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	void ModernGraphicsWriterNV::dispatchMesh( UInt numGroups
		, TaskPayloadOutNVT< PayloadT > const & payload )
	{
		addStmt( sdw::makeSimple( getStmtCache()
			, sdw::makeDispatchMeshNV( getTypesCache()
				, makeExpr( payload )
				, makeExpr( numGroups ) ) ) );
	}
	/**@}*/

	//*************************************************************************

	/**
	*name
	*	Mesh Shader.
	*/
	/**@{*/
	/**
	*	Points
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( numGroups
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMeshNV ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshInEXT{ *this, numGroups, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( numGroups
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMeshNV ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshSubgroupInNV{ *this, numGroups, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**
	*	Lines
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( numGroups
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMeshNV ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshInEXT{ *this, numGroups, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( numGroups
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMeshNV ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshSubgroupInNV{ *this, numGroups, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**
	*	Triangles
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( numGroups
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMeshNV ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshInEXT{ *this, numGroups, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( numGroups
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t numGroups
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMeshNV ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshSubgroupInNV{ *this, numGroups, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**@}*/

	//*************************************************************************
}
