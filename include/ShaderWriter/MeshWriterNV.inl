/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriterNV.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	TopologyNVOutT< DataT, TopologyT >::TopologyNVOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eMeshNV, DataT >{ writer, std::move( expr ), enabled }
		, primitiveIndex{ PrimitiveIndexT< TopologyT >::getMember( *this, ast::Builtin::ePrimitiveIndicesNV ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TopologyNVOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result;

		if constexpr ( std::is_same_v< DataT< FlagT >, VoidT< FlagT > > )
		{
			result = cache.getIOStruct( "SDW_VoidTopo"
				, EntryPoint::eMeshNV
				, FlagT );
		}
		else
		{
			result = OutputT< EntryPoint::eMeshNV, DataT >::makeType( cache
				, std::forward< ParamsT >( params )... );
		}

		if ( !result->hasMember( ast::Builtin::ePrimitiveIndicesNV ) )
		{
			result->declMember( ast::Builtin::ePrimitiveIndicesNV
				, PrimitiveIndexT< TopologyT >::Kind
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	MeshNVPrimitiveOutT< DataT, TopologyT >::MeshNVPrimitiveOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: TopologyNVOutT< DataT, TopologyT >{ writer, std::move( expr ), enabled }
		, primitiveID{ getIntMember( *this, ast::Builtin::ePrimitiveID ) }
		, layer{ getIntMember( *this, ast::Builtin::eLayer ) }
		, viewportIndex{ getIntMember( *this, ast::Builtin::eViewportIndex ) }
		, viewportMask{ getIntMemberArray( *this, ast::Builtin::eViewportMaskNV ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshNVPrimitiveOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = TopologyNVOutT< DataT, TopologyT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::ePrimitiveID ) )
		{
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLayer
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eViewportIndex
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eViewportMaskNV
				, type::Kind::eInt
				, 1u );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	MeshNVPrimitiveListOutT< DataT, TopologyT >::MeshNVPrimitiveListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: Array< MeshNVPrimitiveOutT< DataT, TopologyT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	MeshNVPrimitiveListOutT< DataT, TopologyT >::MeshNVPrimitiveListOutT( ShaderWriter & writer
		, uint32_t maxPrimitives
		, ParamsT && ... params )
		: MeshNVPrimitiveListOutT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "meshPrimitiveOut"
					, ast::type::makeMeshPrimitiveOutputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, TopologyT
						, maxPrimitives )
					, FlagT | ast::var::Flag::ePerPrimitive ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	void MeshNVPrimitiveListOutT< DataT, TopologyT >::setMeshOutputCounts( UInt32 const & numVertices
		, UInt32 const & numPrimitives )
	{
		sdw::setMeshOutputCountsNV( numVertices, numPrimitives );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshNVPrimitiveListOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return MeshNVPrimitiveOutT< DataT, TopologyT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	/**
	*	Points
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshInNV{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshSubgroupInNV{ *this, localSizeX, 1u, 1u } )
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
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshInNV{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshSubgroupInNV{ *this, localSizeX, 1u, 1u } )
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
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshNVMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshInNV{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX
			, TaskPayloadInNVT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshNVPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterNV::implementMainT( uint32_t localSizeX
		, TaskPayloadInNVT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshNVPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshNVSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPointNV )
			, function
			, makeInParam( MeshSubgroupInNV{ *this, localSizeX, 1u, 1u } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/

	//*************************************************************************
}
