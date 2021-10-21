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
					, getTypesCache( writer ).getArray( makeType( getTypesCache( writer ) ), MaxPointsT )
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

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlOutT< DataT >::TessControlOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, tessLevelOuter{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_TessLevelOuter"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat(), 4u )
					, FlagT ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_TessLevelInner"
					, getTypesCache( writer ).getArray( getTypesCache( writer ).getFloat(), 2u )
					, FlagT ) )
			, true }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_out"
					, PerVertex::getArrayType( getTypesCache( writer ), 32u )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessControlOutT< DataT >::TessControlOutT( ShaderWriter & writer )
		: TessControlOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, vtx.getType() ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr TessControlOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return OutputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	TessPatchOutT< DataT >::TessPatchOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: PatchOutT< DataT >{ writer, std::move( expr ), enabled }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	TessPatchOutT< DataT >::TessPatchOutT( ShaderWriter & writer )
		: TessPatchOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "tesscPatch"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr TessPatchOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return PatchOutT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementPatchRoutineT( TessControlPatchRoutineT< InT, MaxPointsT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "sdwPatchRoutine"
			, ast::stmt::FunctionFlag::ePatchRoutine
			, function
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, false } )
			, makeOutParam( TessPatchOutT< PatchT >{ *this } ) );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, uint32_t MaxPointsT
		, template< ast::var::Flag FlagT > typename OutT
		, template< ast::var::Flag FlagT > typename PatchT >
	void TessellationControlWriter::implementMainT( uint32_t outputVertices
		, TessControlMainFuncT< InT, MaxPointsT, OutT, PatchT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TessControlInT< InT, MaxPointsT >{ *this, true } )
			, makeOutParam( TessControlOutT< OutT >{ *this, outputVertices } )
			, makeOutParam( TessPatchOutT< PatchT >{ *this } ) );
	}

	//*************************************************************************
}
