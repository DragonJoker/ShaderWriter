/*
See LICENSE file in root folder
*/
#include "ComputeWriter.hpp"

#include "BaseTypes/UInt.hpp"
#include "VecTypes/Vec3.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ParamsT ... params )
		: ComputeInT{ writer
			, makeExpr( writer
				, getShader( writer ).registerName( "compIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, localSizeX
						, localSizeY
						, localSizeZ )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: InputT< DataT >{ writer, std::move( expr ), enabled }
		, numWorkGroups{ getUVec3Member( *this, ast::Builtin::eNumWorkGroups ) }
		, workGroupID{ getUVec3Member( *this, ast::Builtin::eWorkGroupID ) }
		, localInvocationID{ getUVec3Member( *this, ast::Builtin::eLocalInvocationID ) }
		, globalInvocationID{ getUVec3Member( *this, ast::Builtin::eGlobalInvocationID ) }
		, localInvocationIndex{ getUIntMember( *this, ast::Builtin::eLocalInvocationIndex ) }
		, workGroupSize{ getWorkGroupSize( this->getType() ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr ComputeInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT ... params )
	{
		auto result = InputT< DataT >::makeType( cache, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eNumWorkGroups ) )
		{
			result->declMember( ast::Builtin::eNumWorkGroups
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
		}

		return result;
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
		this->implementMainT( ComputeInT< DataT >{ *this, localSizeX, localSizeY, localSizeZ }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( ComputeInT< DataT > in
		, ComputeMainFuncT< DataT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( std::move( in ) ) );
	}

	//*************************************************************************
}
