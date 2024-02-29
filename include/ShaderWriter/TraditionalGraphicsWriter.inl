/*
See LICENSE file in root folder
*/
#include "TraditionalGraphicsWriter.hpp"

namespace sdw
{
	//*************************************************************************

	/**
	*name
	*	Vertex Shader.
	*/
	/**@{*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void TraditionalGraphicsWriter::implementEntryPointT( VertexMainFuncT< InT, OutT > const & function )
	{
		this->implementEntryPointT( VertexInT< InT >{ *this }
			, VertexOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void TraditionalGraphicsWriter::implementEntryPointT( VertexInT< InT > in
		, VertexOutT< OutT > out
		, VertexMainFuncT< InT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainVertex"
			, getEntryPointFlags( ast::EntryPoint::eVertex ) | uint32_t( ast::stmt::FunctionFlag::eVertexEntryPoint )
			, function
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**@}*/

	//*************************************************************************

	/**
	*name
	*	Geometry Shader.
	*/
	/**@{*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< uint32_t MaxPrimCountT, typename InputArrT, typename OutStreamT >
	inline void TraditionalGraphicsWriter::implementEntryPointT( GeometryMainFuncT< InputArrT, OutStreamT > const & function )
	{
		this->implementEntryPointT( InputArrT{ *this }
			, OutStreamT{ *this, MaxPrimCountT }
			, function );
	}

	template< typename InputArrT, typename OutStreamT >
	inline void TraditionalGraphicsWriter::implementEntryPointT( InputArrT in
		, OutStreamT out
		, GeometryMainFuncT< InputArrT, OutStreamT > const & function )
	{
		( void )implementFunction< Void >( "mainGeometry"
			, getEntryPointFlags( ast::EntryPoint::eGeometry ) | uint32_t( ast::stmt::FunctionFlag::eGeometryEntryPoint )
			, function
			, makeInParam( GeometryIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeInOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**
	*name
	*	Stream Output declaration.
	*/
	/**@{*/
	template< typename T >
	inline T TraditionalGraphicsWriter::declStreamOutput( std::string name
		, uint32_t location
		, uint32_t streamIndex
		, bool enabled )
	{
		return declStreamOutput< T >( std::move( name )
			, location
			, streamIndex
			, 0u
			, enabled );
	}

	template< typename T >
	inline T TraditionalGraphicsWriter::declStreamOutput( std::string name
		, uint32_t location
		, uint32_t streamIndex
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
			, EntryPoint::eGeometry
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( makeInOutStreamVariableDecl( getStmtCache()
				, var
				, location
				, streamIndex ) );
		}

		return T{ *this
			, makeExpr( *this, var )
			, enabled };
	}

	template< typename T >
	inline Array< T > TraditionalGraphicsWriter::declStreamOutputArray( std::string name
		, uint32_t location
		, uint32_t streamIndex
		, uint32_t dimension
		, bool enabled )
	{
		return declStreamOutputArray< T >( std::move( name )
			, location
			, streamIndex
			, dimension
			, 0u
			, enabled );
	}

	template< typename T >
	inline Array< T > TraditionalGraphicsWriter::declStreamOutputArray( std::string name
		, uint32_t location
		, uint32_t streamIndex
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
			, EntryPoint::eGeometry
			, location
			, attributes | var::Flag::eGeometryStream
			, type );

		if ( enabled )
		{
			addStmt( makeInOutStreamVariableDecl( getStmtCache(), var
				, location
				, streamIndex ) );
		}

		return Array< T >{ *this
			, makeExpr( *this, var )
			, enabled };
	}
	/**@}*/
	/**@}*/

	//*************************************************************************

	/**
	*name
	*	Tessellation Control Shader.
	*/
	/**@{*/
	/**
	*name
	*	Patch routine declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( uint32_t patchLocation
		, TessControlPatchRoutineT< InT, MaxPointsT, PatchT, DomainT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( TessPatchOutT< PatchT, DomainT >{ *this, patchLocation } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( uint32_t patchLocation
		, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		this->implementPatchRoutineT( TessControlListInT< InT, MaxPointsT >{ *this, true }
			, IsolinesTessPatchOutT< PatchT >{ *this, patchLocation }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( uint32_t patchLocation
		, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		this->implementPatchRoutineT( TessControlListInT< InT, MaxPointsT >{ *this, true }
			, TrianglesTessPatchOutT< PatchT >{ *this, patchLocation }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( uint32_t patchLocation
		, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		this->implementPatchRoutineT( TessControlListInT< InT, MaxPointsT >{ *this, true }
			, QuadsTessPatchOutT< PatchT >{ *this, patchLocation }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
		, IsolinesTessPatchOutT< PatchT > out
		, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
		, TrianglesTessPatchOutT< PatchT > out
		, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TraditionalGraphicsWriter::implementPatchRoutineT( TessControlListInT< InT, MaxPointsT > in
		, QuadsTessPatchOutT< PatchT > out
		, QuadsTessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlPatchRoutineIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, ast::type::PatchDomain DomainT >
	void TraditionalGraphicsWriter::implementEntryPointT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, TessControlMainFuncT< InT, MaxPointsT, OutT, DomainT > const & function )
	{
		( void )implementFunction< Void >( "mainTessControl"
			, getEntryPointFlags( ast::EntryPoint::eTessellationControl ) | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TessControlListOutT< OutT, DomainT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		this->implementEntryPointT( TessControlListInT< InT, MaxPointsT >{ *this, false }
			, IsolinesTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		this->implementEntryPointT( TessControlListInT< InT, MaxPointsT >{ *this, false }
			, TrianglesTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( ast::type::Partitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::PrimitiveOrdering vertexOrder
		, uint32_t outputVertices
		, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		this->implementEntryPointT( TessControlListInT< InT, MaxPointsT >{ *this, false }
			, QuadsTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( TessControlListInT< InT, MaxPointsT > in
		, IsolinesTessControlListOutT< OutT > out
		, IsolinesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessControl"
			, getEntryPointFlags( ast::EntryPoint::eTessellationControl ) | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( TessControlListInT< InT, MaxPointsT > in
		, TrianglesTessControlListOutT< OutT > out
		, TrianglesTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessControl"
			, getEntryPointFlags( ast::EntryPoint::eTessellationControl ) | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( TessControlListInT< InT, MaxPointsT > in
		, QuadsTessControlListOutT< OutT > out
		, QuadsTessControlMainFuncT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessControl"
			, getEntryPointFlags( ast::EntryPoint::eTessellationControl ) | uint32_t( ast::stmt::FunctionFlag::eTessellationControlEntryPoint )
			, function
			, makeInParam( TessControlMainIn{ *this } )
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**@}*/

	//*************************************************************************

	/**
	*name
	*	Tessellation Evaluation Shader.
	*/
	/**@{*/
	/**
	*name
	*	Entry point declaration.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::PatchDomain DomainT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, TessEvalMainFuncT< InT, MaxPointsT, PatchT, DomainT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessEvaluation"
			, getEntryPointFlags( ast::EntryPoint::eTessellationEvaluation ) | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( TessEvalListInT< InT, MaxPointsT >{ *this, DomainT, partitioning, ordering } )
			, makeInParam( TessPatchInT< PatchT, DomainT >{ *this, patchLocation } )
			, makeOutParam( TessEvalDataOutT< OutT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		this->implementEntryPointT( TessEvalListInT< InT, MaxPointsT >{ *this, ast::type::PatchDomain::eIsolines, partitioning, ordering }
			, IsolinesTessPatchInT< PatchT >{ *this, patchLocation }
			, TessEvalDataOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		this->implementEntryPointT( TessEvalListInT< InT, MaxPointsT >{ *this, ast::type::PatchDomain::eTriangles, partitioning, ordering }
			, TrianglesTessPatchInT< PatchT >{ *this, patchLocation }
			, TessEvalDataOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( uint32_t patchLocation
		, ast::type::Partitioning partitioning
		, ast::type::PrimitiveOrdering ordering
		, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		this->implementEntryPointT( TessEvalListInT< InT, MaxPointsT >{ *this, ast::type::PatchDomain::eQuads, partitioning, ordering }
			, QuadsTessPatchInT< PatchT >{ *this, patchLocation }
			, TessEvalDataOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( TessEvalListInT< InT, MaxPointsT > listIn
		, IsolinesTessPatchInT< PatchT > patchIn
		, TessEvalDataOutT< OutT > out
		, IsolinesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessEvaluation"
			, getEntryPointFlags( ast::EntryPoint::eTessellationEvaluation ) | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( std::move( listIn ) )
			, makeInParam( std::move( patchIn ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( TessEvalListInT< InT, MaxPointsT > listIn
		, TrianglesTessPatchInT< PatchT > patchIn
		, TessEvalDataOutT< OutT > out
		, TrianglesTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessEvaluation"
			, getEntryPointFlags( ast::EntryPoint::eTessellationEvaluation ) | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( std::move( listIn ) )
			, makeInParam( std::move( patchIn ) )
			, makeOutParam( std::move( out ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, template< ast::var::Flag FlagT > typename OutT >
	void TraditionalGraphicsWriter::implementEntryPointT( TessEvalListInT< InT, MaxPointsT > listIn
		, QuadsTessPatchInT< PatchT > patchIn
		, TessEvalDataOutT< OutT > out
		, QuadsTessEvalMainFuncT< InT, MaxPointsT, PatchT, OutT > const & function )
	{
		( void )implementFunction< Void >( "mainTessEvaluation"
			, getEntryPointFlags( ast::EntryPoint::eTessellationEvaluation ) | uint32_t( ast::stmt::FunctionFlag::eTessellationEvaluationEntryPoint )
			, function
			, makeInParam( TessEvalMainIn{ *this } )
			, makeInParam( std::move( listIn ) )
			, makeInParam( std::move( patchIn ) )
			, makeOutParam( std::move( out ) ) );
	}
	/**@}*/
	/**@}*/

	//*************************************************************************
}
