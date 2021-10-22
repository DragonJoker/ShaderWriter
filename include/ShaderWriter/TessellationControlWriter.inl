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
				, getShader( writer ).registerBuiltin( "gl_PatchVerticesIn"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_PrimitiveID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, invocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_InvocationID"
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_in"
					, PerVertex::getArrayType( getTypesCache( writer ), MaxPointsT )
					, FlagT ) )
			, true }
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
		if ( fromEntryPoint )
		{
			addStmt( findWriterMandat( *this )
				, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlInput
					, vtx.getType() ) );
		}
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, uint32_t MaxPointsT >
		ast::type::TypePtr TessControlInT< DataT, MaxPointsT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
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
				, getShader( writer ).registerBuiltin( "gl_TessLevelOuter"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat()
						, getOuterArraySize( DomainT ) )
					, FlagT ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_TessLevelInner"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat()
						, getInnerArraySize( DomainT ) )
					, FlagT ) )
			, hasInnerLevel( DomainT ) }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_out"
					, PerVertex::getArrayType( getTypesCache( writer ), 32u )
					, FlagT ) )
			, true }
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
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT
		, ast::type::OutputDomain DomainT >
	ast::type::TypePtr TessControlOutT< DataT, DomainT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
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
