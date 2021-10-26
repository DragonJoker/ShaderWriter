/*
See LICENSE file in root folder
*/
#include "VertexWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, vertexIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eVertexIndex
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, instanceIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eInstanceIndex
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, drawID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eDrawIndex
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, baseVertex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eBaseVertex
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
		, baseInstance{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( ast::Builtin::eBaseInstance
					, getTypesCache( writer ).getInt()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer )
		: VertexInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "vertIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr VertexInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< DataT >{ writer, std::move( expr ), enabled }
		, vtx{ writer, *this, FlagT }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer )
		: VertexOutT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "vertOut"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::IOStructPtr VertexOutT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		ast::type::IOStructPtr result = OutputT< DataT >::makeType( cache );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void VertexWriter::implementMainT( VertexMainFuncT< InT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( VertexInT< InT >{ *this } )
			, makeOutParam( VertexOutT< OutT >{ *this } ) );
	}

	//*************************************************************************
}
