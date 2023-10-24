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
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainTask"
			, ast::stmt::FunctionFlag::eTaskEntryPointNV
			, function
			, makeInParam( TaskIn{ *this, localSizeX, 1u, 1u } )
			, makeParam( std::move( payload ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadOutNVT< PayloadT > payload
		, TaskNVSubgroupMainFuncT< PayloadT > const & function )
	{
		( void )implementFunction< Void >( "mainTask"
			, ast::stmt::FunctionFlag::eTaskEntryPointNV
			, function
			, makeInParam( TaskSubgroupIn{ *this, localSizeX, 1u, 1u } )
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
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, ast::stmt::FunctionFlag::eMeshEntryPointNV
			, function
			, makeInParam( MeshIn{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, ast::stmt::FunctionFlag::eMeshEntryPointNV
			, function
			, makeInParam( MeshSubgroupIn{ *this, localSizeX, 1u, 1u } )
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
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, ast::stmt::FunctionFlag::eMeshEntryPointNV
			, function
			, makeInParam( MeshIn{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, ast::stmt::FunctionFlag::eMeshEntryPointNV
			, function
			, makeInParam( MeshSubgroupIn{ *this, localSizeX, 1u, 1u } )
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
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, ast::stmt::FunctionFlag::eMeshEntryPointNV
			, function
			, makeInParam( MeshIn{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementEntryPointT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void ModernGraphicsWriterNV::implementEntryPointT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "mainMesh"
			, ast::stmt::FunctionFlag::eMeshEntryPointNV
			, function
			, makeInParam( MeshSubgroupIn{ *this, localSizeX, 1u, 1u } )
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
	inline void ModernGraphicsWriterNV::implementEntryPointT( FragmentMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( ast::FragmentOrigin::eUpperLeft
			, ast::FragmentCenter::eHalfPixel
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void ModernGraphicsWriterNV::implementEntryPointT( ast::FragmentOrigin origin
		, ast::FragmentCenter center
		, FragmentMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( FragmentInT< InT >{ *this, origin, center }
			, FragmentOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void ModernGraphicsWriterNV::implementEntryPointT( FragmentInT< InT > in
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
	inline T ModernGraphicsWriterNV::declBlendOutput( std::string name
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
	inline T ModernGraphicsWriterNV::declBlendOutput( std::string name
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
	inline Array< T > ModernGraphicsWriterNV::declBlendOutputArray( std::string name
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
	inline Array< T > ModernGraphicsWriterNV::declBlendOutputArray( std::string name
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
