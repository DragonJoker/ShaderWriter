/*
See LICENSE file in root folder
*/
#include "VertexWriter.hpp"

#include "BaseTypes/Int.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< EntryPoint::eVertex, DataT >{ writer, std::move( expr ), enabled }
		, vertexIndex{ getInt32Member( *this, ast::Builtin::eVertexIndex ) }
		, instanceIndex{ getInt32Member( *this, ast::Builtin::eInstanceIndex ) }
		, drawID{ getInt32Member( *this, ast::Builtin::eDrawIndex ) }
		, baseVertex{ getInt32Member( *this, ast::Builtin::eBaseVertex ) }
		, baseInstance{ getInt32Member( *this, ast::Builtin::eBaseInstance ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	VertexInT< DataT >::VertexInT( ShaderWriter & writer
		, ParamsT && ... params )
		: VertexInT< DataT >{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "vertIn"
					, makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr VertexInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		auto result = InputT< EntryPoint::eVertex, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eVertexIndex ) )
		{
			result->declMember( ast::Builtin::eVertexIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInstanceIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eDrawIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eBaseVertex
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eBaseInstance
				, type::Kind::eInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: OutputT< EntryPoint::eVertex, DataT >{ writer, std::move( expr ), enabled }
		, vtx{ *this }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	VertexOutT< DataT >::VertexOutT( ShaderWriter & writer
		, ParamsT && ... params )
		: VertexOutT< DataT >{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "vertOut"
					, makeType( getTypesCache( writer )
						, std::forward< ParamsT >( params )... )
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr VertexOutT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		ast::type::IOStructPtr result = OutputT< EntryPoint::eVertex, DataT >::makeType( cache
			, std::forward< ParamsT >( params )... );
		PerVertex::fillType( *result );
		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void VertexWriter::implementMainT( VertexMainFuncT< InT, OutT > const & function )
	{
		this->implementMainT( VertexInT< InT >{ *this }
			, VertexOutT< OutT >{ *this }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename InT
		, template< ast::var::Flag FlagT > typename OutT >
	inline void VertexWriter::implementMainT( VertexInT< InT > in
		, VertexOutT< OutT > out
		, VertexMainFuncT< InT, OutT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eVertexEntryPoint )
			, function
			, makeInParam( std::move( in ) )
			, makeOutParam( std::move( out ) ) );
	}

	//*************************************************************************
}
