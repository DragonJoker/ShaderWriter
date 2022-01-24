/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	MeshInT< DataT >::MeshInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, workGroupSize{ getUVec3Member( *this, ast::Builtin::eWorkGroupSize ) }
		, workGroupID{ getUVec3Member( *this, ast::Builtin::eWorkGroupID ) }
		, localInvocationID{ getUVec3Member( *this, ast::Builtin::eLocalInvocationID ) }
		, globalInvocationID{ getUVec3Member( *this, ast::Builtin::eGlobalInvocationID ) }
		, localInvocationIndex{ getUIntMember( *this, ast::Builtin::eLocalInvocationIndex ) }
		, meshViewCount{ getUIntMember( *this, ast::Builtin::eMeshViewCountNV ) }
		, meshViewIndices{ getUIntMemberArray( *this, ast::Builtin::eMeshViewIndicesNV ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	MeshInT< DataT >::MeshInT( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ParamsT ... params )
		: MeshInT{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "meshIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, localSizeX
						, localSizeY
						, localSizeZ )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::StructPtr MeshInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		auto result = InputT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eWorkGroupID ) )
		{
			result->declMember( ast::Builtin::eWorkGroupSize
				, type::Kind::eVec3U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorkGroupID
				, type::Kind::eVec3U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLocalInvocationID
				, type::Kind::eVec3U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eGlobalInvocationID
				, type::Kind::eVec3U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLocalInvocationIndex
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eMeshViewCountNV
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eMeshViewIndicesNV
				, type::Kind::eUInt
				, ast::type::UnknownArraySize );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	MeshVertexOutT< DataT >::MeshVertexOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, position{ getVec4Member( *this, ast::Builtin::ePosition ) }
		, pointSize{ getFloatMember( *this, ast::Builtin::ePointSize ) }
		, clipDistance{ getFloatMemberArray( *this, ast::Builtin::eClipDistance ) }
		, cullDistance{ getFloatMemberArray( *this, ast::Builtin::eCullDistance ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshVertexOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		ast::type::IOStructPtr result = OutputT< DataT >::makeType( cache
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
		, ParamsT ... params )
		: MeshVertexListOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "meshVertexOut"
					, ast::type::makeMeshVertexOutputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, maxVertices )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshVertexListOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return MeshVertexOutT< DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	TopologyOutT< DataT, TopologyT >::TopologyOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, primitiveIndex{ PrimitiveIndexT< TopologyT >::getMember( *this, ast::Builtin::ePrimitiveIndicesNV ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr TopologyOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		ast::type::IOStructPtr result;

		if constexpr ( std::is_same_v< DataT< FlagT >, VoidT< FlagT > > )
		{
			result = cache.getIOStruct( ast::type::MemoryLayout::eC
				, ( "SDW_VoidTopo"
					+ ( FlagT == ast::var::Flag::eShaderOutput
						? std::string{ "Output" }
						: std::string{ "Input" } ) )
				, FlagT );
		}
		else
		{
			result = OutputT< DataT >::makeType( cache
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
	MeshPrimitiveOutT< DataT, TopologyT >::MeshPrimitiveOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: TopologyOutT< DataT, TopologyT >{ writer, std::move( expr ), enabled }
		, primitiveID{ getIntMember( *this, ast::Builtin::ePrimitiveID ) }
		, layer{ getIntMember( *this, ast::Builtin::eLayer ) }
		, viewportIndex{ getIntMember( *this, ast::Builtin::eViewportIndex ) }
		, viewportMask{ getIntMemberArray( *this, ast::Builtin::eViewportMaskNV ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshPrimitiveOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		ast::type::IOStructPtr result = TopologyOutT< DataT, TopologyT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::ePosition ) )
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
	MeshPrimitiveListOutT< DataT, TopologyT >::MeshPrimitiveListOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
		: Array< MeshPrimitiveOutT< DataT, TopologyT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	MeshPrimitiveListOutT< DataT, TopologyT >::MeshPrimitiveListOutT( ShaderWriter & writer
		, uint32_t maxPrimitives
		, ParamsT ... params )
		: MeshPrimitiveListOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "meshPrimitiveOut"
					, ast::type::makeMeshPrimitiveOutputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, TopologyT
						, maxPrimitives )
					, FlagT | ast::var::Flag::ePerPrimitive ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	void MeshPrimitiveListOutT< DataT, TopologyT >::setMeshOutputCounts( UInt const & numVertices
		, UInt const & numPrimitives )
	{
		sdw::setMeshOutputCounts( numVertices, numPrimitives );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputTopology TopologyT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr MeshPrimitiveListOutT< DataT, TopologyT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		return MeshPrimitiveOutT< DataT, TopologyT >::makeType( cache
			, std::forward< ParamsT >( params )... );
	}

	//*************************************************************************

	/**
	*	Points
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, 1u, 1u }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, localSizeY, 1u }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, PointsMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, localSizeY, localSizeZ }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, PointsMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( MeshInT< InT > meshIn
		, MeshVertexListOutT< VertexT > verticesOut
		, PointsMeshPrimitiveListOutT< PrimitiveT > primitivesOut
		, PointsMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( std::move( meshIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**
	*	Lines
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, 1u, 1u }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, localSizeY, 1u }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, LinesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, localSizeY, localSizeZ }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, LinesMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( MeshInT< InT > meshIn
		, MeshVertexListOutT< VertexT > verticesOut
		, LinesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
		, LinesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( std::move( meshIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/
	/**
	*	Triangles
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, 1u, 1u }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, localSizeY, 1u }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, uint32_t maxVertices
		, uint32_t maxPrimitives
		, TrianglesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		this->implementMainT( MeshInT< InT >{ *this, localSizeX, localSizeY, localSizeZ }
			, MeshVertexListOutT< VertexT >{ *this, maxVertices }
			, TrianglesMeshPrimitiveListOutT< PrimitiveT >{ *this, maxPrimitives }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename VertexT
		, template< ast::var::Flag FlagT > typename PrimitiveT >
	void MeshWriter::implementMainT( MeshInT< InT > meshIn
		, MeshVertexListOutT< VertexT > verticesOut
		, TrianglesMeshPrimitiveListOutT< PrimitiveT > primitivesOut
		, TrianglesMeshMainFuncT< InT, VertexT, PrimitiveT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( std::move( meshIn ) )
			, makeOutParam( std::move( verticesOut ) )
			, makeOutParam( std::move( primitivesOut ) ) );
	}
	/**@}*/

	//*************************************************************************
}
