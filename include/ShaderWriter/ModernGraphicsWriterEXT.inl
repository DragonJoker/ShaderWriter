/*
See LICENSE file in root folder
*/
#include "ModernGraphicsWriterEXT.hpp"

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
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadOutEXTT< PayloadT > payload
		, TaskEXTMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainTask"
			, getEntryPointFlags( ast::EntryPoint::eTask ) | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPoint )
			, function
			, makeInParam( TaskInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadOutEXTT< PayloadT > payload
		, TaskEXTSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainTask"
			, getEntryPointFlags( ast::EntryPoint::eTask ) | uint32_t( ast::stmt::FunctionFlag::eTaskEntryPoint )
			, function
			, makeInParam( TaskSubgroupInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeParam( std::move( payload ) ) );
	}
	/**@}*/
	template< template< ast::var::Flag FlagT > typename PayloadT >
	void ModernGraphicsWriterEXT::dispatchMesh( UInt numGroupsX
		, UInt numGroupsY
		, UInt numGroupsZ
		, TaskPayloadOutEXTT< PayloadT > const & payload )
	{
		addStmt( makeDispatchMesh( getStmtCache()
			, makeExpr( numGroupsX )
			, makeExpr( numGroupsY )
			, makeExpr( numGroupsZ )
			, makeExpr( payload ) ) );
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
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMesh ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMesh ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshSubgroupInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
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
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMesh ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMesh ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshSubgroupInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
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
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMesh ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterEXT::implementEntryPointT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, getEntryPointFlags( ast::EntryPoint::eMesh ) | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshSubgroupInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**@}*/

	//*************************************************************************
}
