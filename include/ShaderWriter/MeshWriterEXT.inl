/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriterEXT.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	MeshVertexOutT< DataT >::MeshVertexOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eMesh, DataT >{ writer, std::move( expr ), enabled }
		, position{ getVec4Member( *this, ast::Builtin::ePosition ) }
		, pointSize{ getFloatMember( *this, ast::Builtin::ePointSize ) }
		, clipDistance{ getFloatMemberArray( *this, ast::Builtin::eClipDistance ) }
		, cullDistance{ getFloatMemberArray( *this, ast::Builtin::eCullDistance ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshVertexOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = OutputT< EntryPoint::eMesh, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::ePosition ) )
		{
			result->declMember( ast::Builtin::ePosition
				, type::Kind::eVec4F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::ePointSize
				, type::Kind::eFloat
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eClipDistance
				, type::Kind::eFloat
				, 8u );
			result->declMember( ast::Builtin::eCullDistance
				, type::Kind::eFloat
				, 8u );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	MeshVertexListOutT< DataT >::MeshVertexListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: Array< MeshVertexOutT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	MeshVertexListOutT< DataT >::MeshVertexListOutT( ShaderWriter & writer
		, uint32_t maxVertices
		, ParamsT && ... params )
		: MeshVertexListOutT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "meshVertexOut"
					, ast::type::makeMeshVertexOutputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, maxVertices )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshVertexListOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return MeshVertexOutT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	TopologyEXTOutT< DataT, TopologyT >::TopologyEXTOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eMesh, DataT >{ writer, std::move( expr ), enabled }
		, primitiveIndex{ PrimitiveIndexT< TopologyT >::getMember( *this, PrimitiveIndexT< TopologyT >::Builtin ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TopologyEXTOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result;

		if constexpr ( std::is_same_v< DataT< FlagT >, VoidT< FlagT > > )
		{
			result = cache.getIOStruct( "SDW_VoidTopo"
				, EntryPoint::eMesh
				, FlagT );
		}
		else
		{
			result = OutputT< EntryPoint::eMesh, DataT >::makeType( cache
				, std::forward< ParamsT >( params )... );
		}

		if ( !result->hasMember( PrimitiveIndexT< TopologyT >::Builtin ) )
		{
			result->declMember( PrimitiveIndexT< TopologyT >::Builtin
				, PrimitiveIndexT< TopologyT >::Kind
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	MeshEXTPrimitiveOutT< DataT, TopologyT >::MeshEXTPrimitiveOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: TopologyEXTOutT< DataT, TopologyT >{ writer, std::move( expr ), enabled }
		, primitiveID{ getIntMember( *this, ast::Builtin::ePrimitiveID ) }
		, layer{ getIntMember( *this, ast::Builtin::eLayer ) }
		, viewportIndex{ getIntMember( *this, ast::Builtin::eViewportIndex ) }
		, cullPrimitive{ getBoolMember( *this, ast::Builtin::eCullPrimitive ) }
		, viewportMask{ getIntMemberArray( *this, ast::Builtin::eViewportMaskNV ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshEXTPrimitiveOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = TopologyEXTOutT< DataT, TopologyT >::makeType( cache
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
			result->declMember( ast::Builtin::eCullPrimitive
				, type::Kind::eBoolean
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
	MeshEXTPrimitiveListOutT< DataT, TopologyT >::MeshEXTPrimitiveListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: Array< MeshEXTPrimitiveOutT< DataT, TopologyT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	MeshEXTPrimitiveListOutT< DataT, TopologyT >::MeshEXTPrimitiveListOutT( ShaderWriter & writer
		, uint32_t maxPrimitives
		, ParamsT && ... params )
		: MeshEXTPrimitiveListOutT{ writer
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
	void MeshEXTPrimitiveListOutT< DataT, TopologyT >::setMeshOutputCounts( UInt32 const & numVertices
		, UInt32 const & numPrimitives )
	{
		sdw::setMeshOutputCounts( numVertices, numPrimitives );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshEXTPrimitiveListOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		return MeshEXTPrimitiveOutT< DataT, TopologyT >::makeType( cache
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
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
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
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
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
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshEXTMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( localSizeX, localSizeY, localSizeZ
			, TaskPayloadInEXTT< PayloadT >{ *this }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename PayloadT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriterEXT::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, TaskPayloadInEXTT< PayloadT > payloadIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshEXTPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshEXTSubgroupMainFuncT< PayloadT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eMeshEntryPoint )
			, function
			, makeInParam( MeshSubgroupInEXT{ *this, localSizeX, localSizeY, localSizeZ } )
			, makeInParam( std::move( payloadIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/

	//*************************************************************************
}
