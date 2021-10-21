/*
See LICENSE file in root folder
*/
#include "ComputeWriter.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer )
		: ComputeInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "compIn"
					, makeType( getTypesCache( writer ) )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, numWorkGroups{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_NumWorkGroups"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, workGroupID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_WorkGroupID"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, localInvocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_LocalInvocationID"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, globalInvocationID{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_GlobalInvocationID"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
		, localInvocationIndex{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_LocalInvocationIndex"
					, getTypesCache( writer ).getUInt()
					, FlagT ) )
			, true }
		, workGroupSize{ writer
			, makeIdent( getTypesCache( writer )
				, getShader( writer ).registerBuiltin( "gl_WorkGroupSize"
					, getTypesCache( writer ).getVec3U()
					, FlagT ) )
			, true }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ast::type::TypePtr ComputeInT< DataT >::makeType( ast::type::TypesCache & cache )
	{
		return InputT< DataT >::makeType( cache );
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( uint32_t localSizeX
		, ComputeMainFuncT< DataT > const & function )
	{
		this->implementMainT< DataT >( localSizeX, 1u, 1u, function );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, ComputeMainFuncT< DataT > const & function )
	{
		this->implementMainT< DataT >( localSizeX, localSizeY, 1u, function );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ComputeMainFuncT< DataT > const & function )
	{
		addStmt( stmt::makeInputComputeLayout( localSizeX
			, localSizeY
			, localSizeZ ) );
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( ComputeInT< DataT >{ *this } ) );
	}

	//*************************************************************************
}
