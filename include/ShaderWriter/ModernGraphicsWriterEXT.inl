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
			, ast::stmt::FunctionFlag::eTaskEntryPoint
			, function
			, makeInParam( TaskIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eTaskEntryPoint
			, function
			, makeInParam( TaskSubgroupIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eMeshEntryPoint
			, function
			, makeInParam( MeshIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eMeshEntryPoint
			, function
			, makeInParam( MeshSubgroupIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eMeshEntryPoint
			, function
			, makeInParam( MeshIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eMeshEntryPoint
			, function
			, makeInParam( MeshSubgroupIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eMeshEntryPoint
			, function
			, makeInParam( MeshIn{ *this, localSizeX, localSizeY, localSizeZ } )
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
			, ast::stmt::FunctionFlag::eMeshEntryPoint
			, function
			, makeInParam( MeshSubgroupIn{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**@}*/

	//*************************************************************************

	/**
	*name
	*	Fragment Shader.
	*/
	/**@{*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void ModernGraphicsWriterEXT::implementEntryPointT( FragmentMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( ast::FragmentOrigin::eUpperLeft
			, ast::FragmentCenter::eHalfPixel
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void ModernGraphicsWriterEXT::implementEntryPointT( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( FragmentInT< InT >{ *this, origin, center }
			, FragmentOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void ModernGraphicsWriterEXT::implementEntryPointT( FragmentInT< InT > in
		, FragmentOutT< OutT > out
		, FragmentMainFuncT< InT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainFragment"
			, ast::stmt::FunctionFlag::eFragmentEntryPoint
			, function
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**
	*name
	*	Blend Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T ModernGraphicsWriterEXT::declBlendOutput( std::string name
		, uint32_t location
		, uint32_t blendIndex
		, bool enabled )
	{
		return declBlendOutput< T >( std::move( name )
			, location
			, blendIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline T ModernGraphicsWriterEXT::declBlendOutput( std::string name
		, uint32_t location
		, uint32_t blendIndex
		, uint64_t attributes
		, bool enabled )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = T::makeType( getTypesCache() );
		auto var = registerOutput( std::move( name )
			, location
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( makeInOutBlendVariableDecl( getStmtCache()
				, var
				, location
				, blendIndex ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > ModernGraphicsWriterEXT::declBlendOutputArray( std::string name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declBlendOutputArray< T >( std::move( name )
			, location
			, blendIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > ModernGraphicsWriterEXT::declBlendOutputArray( std::string name
		, uint32_t location
		, uint32_t blendIndex
		, uint32_t dimension
		, uint64_t attributes
		, bool enabled )
	{
		static_assert( !isSameV< T, Boolean >, "Bool is not supported as output type" );
		static_assert( !isSameV< T, BVec2 >, "BVec2 is not supported as output type" );
		static_assert( !isSameV< T, BVec3 >, "BVec3 is not supported as output type" );
		static_assert( !isSameV< T, BVec4 >, "BVec4 is not supported as output type" );
		static_assert( !isSameV< T, Double >, "Double is not supported as output type" );
		static_assert( !isSameV< T, DVec2 >, "DVec2 is not supported as output type" );
		static_assert( !isSameV< T, DVec3 >, "DVec3 is not supported as output type" );
		static_assert( !isSameV< T, DVec4 >, "DVec4 is not supported as output type" );
		auto type = Array< T >::makeType( getTypesCache()
			, dimension );
		auto var = registerOutput( std::move( name )
			, location
			, blendIndex
			, attributes | var::Flag::eBlendIndex
			, type );

		if ( enabled )
		{
			addStmt( makeInOutBlendVariableDecl( getStmtCache()
				, var
				, location
				, blendIndex ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
	/**@}*/

	//*************************************************************************
}
