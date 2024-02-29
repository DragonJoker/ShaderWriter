/*
See LICENSE file in root folder
*/
#include "ComputeWriter.hpp"

#include "ShaderWriter/BaseTypes/UInt.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ComputeInT< DataT >::ComputeInT( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ParamsT && ... params )
		: ComputeInT{ writer
			, makeExpr( writer
				, getBuilder( writer ).registerName( "compIn"
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
		: InputT< EntryPoint::eCompute, DataT >{ writer, std::move( expr ), enabled }
		, numWorkGroups{ getU32Vec3Member( *this, ast::Builtin::eNumWorkGroups ) }
		, workGroupID{ getU32Vec3Member( *this, ast::Builtin::eWorkGroupID ) }
		, localInvocationID{ getU32Vec3Member( *this, ast::Builtin::eLocalInvocationID ) }
		, globalInvocationID{ getU32Vec3Member( *this, ast::Builtin::eGlobalInvocationID ) }
		, localInvocationIndex{ getUInt32Member( *this, ast::Builtin::eLocalInvocationIndex ) }
		, workGroupSize{ getWorkGroupSize( this->getType() ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr ComputeInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		auto result = InputT< EntryPoint::eCompute, DataT >::makeType( cache, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eNumWorkGroups ) )
		{
			result->declMember( ast::Builtin::eNumWorkGroups
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorkGroupID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLocalInvocationID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eGlobalInvocationID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLocalInvocationIndex
				, type::Kind::eUInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	SubgroupInT< DataT >::SubgroupInT( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, ParamsT && ... params )
		: SubgroupInT{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "subgroupIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ), std::forward< ParamsT >( params )... )
						, localSizeX
						, localSizeY
						, localSizeZ )
					, FlagT ) ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	SubgroupInT< DataT >::SubgroupInT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: ComputeInT< DataT >{ writer, std::move( expr ), enabled }
		, numSubgroups{ getUInt32Member( *this, ast::Builtin::eNumSubgroups ) }
		, subgroupID{ getUInt32Member( *this, ast::Builtin::eSubgroupID ) }
		, subgroupSize{ getUInt32Member( *this, ast::Builtin::eSubgroupSize ) }
		, subgroupInvocationID{ getUInt32Member( *this, ast::Builtin::eSubgroupLocalInvocationID ) }
		, subgroupEqMask{ getU32Vec4Member( *this, ast::Builtin::eSubgroupEqMask ) }
		, subgroupGeMask{ getU32Vec4Member( *this, ast::Builtin::eSubgroupGeMask ) }
		, subgroupGtMask{ getU32Vec4Member( *this, ast::Builtin::eSubgroupGtMask ) }
		, subgroupLeMask{ getU32Vec4Member( *this, ast::Builtin::eSubgroupLeMask ) }
		, subgroupLtMask{ getU32Vec4Member( *this, ast::Builtin::eSubgroupLtMask ) }
	{
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	template< typename ... ParamsT >
	ast::type::IOStructPtr SubgroupInT< DataT >::makeType( ast::type::TypesCache & cache
		, ParamsT && ... params )
	{
		auto result = ComputeInT< DataT >::makeType( cache, std::forward< ParamsT >( params )... );

		if ( !result->hasMember( ast::Builtin::eNumSubgroups ) )
		{
			result->declMember( ast::Builtin::eNumSubgroups
				, type::Kind::eUInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupID
				, type::Kind::eUInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupSize
				, type::Kind::eUInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupLocalInvocationID
				, type::Kind::eUInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupEqMask
				, type::Kind::eVec4U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupGeMask
				, type::Kind::eVec4U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupGtMask
				, type::Kind::eVec4U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupLeMask
				, type::Kind::eVec4U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupLtMask
				, type::Kind::eVec4U32
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
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eComputeEntryPoint )
			, function
			, makeInParam( std::move( in ) ) );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( uint32_t localSizeX
		, SubgroupMainFuncT< DataT > const & function )
	{
		this->implementMainT< DataT >( localSizeX, 1u, 1u, function );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, SubgroupMainFuncT< DataT > const & function )
	{
		this->implementMainT< DataT >( localSizeX, localSizeY, 1u, function );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ
		, SubgroupMainFuncT< DataT > const & function )
	{
		this->implementMainT( SubgroupInT< DataT >{ *this, localSizeX, localSizeY, localSizeZ }
			, function );
	}

	template< template< ast::var::Flag FlagT > typename DataT >
	inline void ComputeWriter::implementMainT( SubgroupInT< DataT > in
		, SubgroupMainFuncT< DataT > const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eComputeEntryPoint )
			, function
			, makeInParam( std::move( in ) ) );
	}

	//*************************************************************************
}
