/*
See LICENSE file in root folder
*/
#include "TessellationControlWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlDataInT< DataT >::TessControlDataInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlDataInT< DataT >::TessControlDataInT( ShaderWriter & writer )
		: TessControlDataInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr TessControlDataInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = InputT< DataT >::makeType( cache );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlListInT< DataT, MaxPointsT >::TessControlListInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< TessControlDataInT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlListInT< DataT, MaxPointsT >::TessControlListInT( ShaderWriter & writer
		, bool fromEntryPoint )
		: TessControlListInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscIn"
					, ast::type::makeTessellationControlInputType( makeType( getTypesCache( writer ) ), MaxPointsT )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	ast::type::IOStructPtr TessControlListInT< DataT, MaxPointsT >::makeType( ast::type::TypesCache & cache )
	{
		return TessControlDataInT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlDataOutT< DataT >::TessControlDataOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlDataOutT< DataT >::TessControlDataOutT( ShaderWriter & writer )
		: TessControlDataOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr TessControlDataOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = OutputT< DataT >::makeType( cache );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	TessControlListOutT< DataT, DomainT >::TessControlListOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< TessControlDataOutT< DataT > >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	TessControlListOutT< DataT, DomainT >::TessControlListOutT( ShaderWriter & writer
		, ast::type::OutputPartitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::OutputVertexOrder vertexOrder
		, uint32_t outputVertex )
		: TessControlListOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscOut"
					, ast::type::makeTessellationControlOutputType( makeType( getTypesCache( writer ) )
						, DomainT
						, partitioning
						, topology
						, vertexOrder
						, outputVertex )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	ast::type::IOStructPtr TessControlListOutT< DataT, DomainT >::makeType( ast::type::TypesCache & cache )
	{
		return TessControlDataOutT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< ast::type::OutputDomain DomainT >
	TessControlOutT< DomainT >::TessControlOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ getMemberArray< Float >( ast::Builtin::eTessLevelOuter ) }
		, tessLevelInner{ getMemberArray< Float >( ast::Builtin::eTessLevelInner ) }
	{
	}

	template< ast::type::OutputDomain DomainT >
	TessControlOutT< DomainT >::TessControlOutT( ShaderWriter & writer )
		: TessControlOutT{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "tesscGlobOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< ast::type::OutputDomain DomainT >
	ast::type::StructPtr TessControlOutT< DomainT >::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "TessControlOut"
			, FlagT );

		if ( !result->hasMember( ast::Builtin::eTessLevelOuter ) )
		{
			result->declMember( ast::Builtin::eTessLevelOuter
				, type::Kind::eFloat
				, getOuterArraySize( DomainT ) );
			result->declMember( ast::Builtin::eTessLevelInner
				, type::Kind::eFloat
				, getInnerArraySize( DomainT ) );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	TessPatchOutT< DataT, DomainT >::TessPatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PatchOutT< DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	TessPatchOutT< DataT, DomainT >::TessPatchOutT( ShaderWriter & writer
		, uint32_t patchLocation )
		: TessPatchOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscPatch"
					, ast::type::makeTessellationOutputPatchType( makeType( getTypesCache( writer ) )
						, patchLocation )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	ast::type::TypePtr TessPatchOutT< DataT, DomainT >::makeType( ast::type::TypesCache & cache )
	{
		return PatchOutT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, ast::type::OutputDomain DomainT >
	void TessellationControlWriter::implementPatchRoutineT( ast::type::OutputPartitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::OutputVertexOrder vertexOrder
		, uint32_t outputVertices
		, TessControlPatchRoutineT< InT, MaxPointsT, OutT, DomainT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TessControlOutT< DomainT >{ *this }
			, makeOutParam( TessControlListOutT< OutT, DomainT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementPatchRoutineT( ast::type::OutputPartitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::OutputVertexOrder vertexOrder
		, uint32_t outputVertices
		, IsolinesTessControlPatchRoutineT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( IsolinesTessControlOut{ *this } )
			, makeOutParam( IsolinesTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementPatchRoutineT( ast::type::OutputPartitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::OutputVertexOrder vertexOrder
		, uint32_t outputVertices
		, TrianglesTessControlPatchRoutineT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TrianglesTessControlOut{ *this } )
			, makeOutParam( TrianglesTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT >
	void TessellationControlWriter::implementPatchRoutineT( ast::type::OutputPartitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::OutputVertexOrder vertexOrder
		, uint32_t outputVertices
		, QuadsTessControlPatchRoutineT< InT, MaxPointsT, OutT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlIn{ *this } )
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( QuadsTessControlOut{ *this } )
			, makeOutParam( QuadsTessControlListOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT
		, ast::type::OutputDomain DomainT >
	void TessellationControlWriter::implementMainT( uint32_t patchLocation
		, TessControlMainFuncT< InT, MaxPointsT, PatchT, DomainT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( TessPatchOutT< PatchT, DomainT >{ *this, patchLocation } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementMainT( uint32_t patchLocation
		, IsolinesTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( IsolinesTessPatchOutT< PatchT >{ *this, patchLocation } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementMainT( uint32_t patchLocation
		, TrianglesTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( TrianglesTessPatchOutT< PatchT >{ *this, patchLocation } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementMainT( uint32_t patchLocation
		, QuadsTessControlMainFuncT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessControlListInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( QuadsTessPatchOutT< PatchT >{ *this, patchLocation } ) );
	}

	//*************************************************************************
}
