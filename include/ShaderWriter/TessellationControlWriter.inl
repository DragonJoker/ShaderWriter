/*
See LICENSE file in root folder
*/
#include "TessellationControlWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlInT< DataT, MaxPointsT >::TessControlInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< InputT< DataT > >{ writer, std::move( expr ), enabled }
		, patchVerticesIn{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::ePatchVerticesIn
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::ePrimitiveID
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, invocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eInvocationID
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
	TessControlInT< DataT, MaxPointsT >::TessControlInT( ShaderWriter & writer
		, bool fromEntryPoint )
		: TessControlInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscIn"
					, ast::type::makeTessellationControlInputType( makeType( getTypesCache( writer ) ), MaxPointsT )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
		ast::type::IOStructPtr TessControlInT< DataT, MaxPointsT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = InputT< DataT >::makeType( cache );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	TessControlOutT< DataT, DomainT >::TessControlOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Array< OutputT< DataT > >{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eTessLevelOuter
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat()
						, getOuterArraySize( DomainT ) )
					, FlagT ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eTessLevelInner
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat()
						, getInnerArraySize( DomainT ) )
					, FlagT ) )
			, hasInnerLevel( DomainT ) }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	TessControlOutT< DataT, DomainT >::TessControlOutT( ShaderWriter & writer
		, ast::type::OutputPartitioning partitioning
		, ast::type::OutputTopology topology
		, ast::type::OutputVertexOrder vertexOrder
		, uint32_t outputVertex )
		: TessControlOutT{ writer
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
	ast::type::IOStructPtr TessControlOutT< DataT, DomainT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = OutputT< DataT >::makeType( cache );
		PerVertex::fillType( *result );
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TessControlOutT< OutT, DomainT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( IsolinesTessControlOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TrianglesTessControlOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( QuadsTessControlOutT< OutT >{ *this, partitioning, topology, vertexOrder, outputVertices } ) );
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, true } )
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, true } )
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, true } )
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
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( QuadsTessPatchOutT< PatchT >{ *this, patchLocation } ) );
	}

	//*************************************************************************
}
