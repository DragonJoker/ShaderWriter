/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriterNV.hpp"

namespace sdw
{
	//*************************************************************************

	MeshInNV::MeshInNV( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, meshViewCount{ getUIntMember( *this, ast::Builtin::eMeshViewCountNV ) }
		, meshViewIndices{ getUIntMemberArray( *this, ast::Builtin::eMeshViewIndicesNV ) }
		, drawID{ getUIntMember( *this, ast::Builtin::eDrawIndex ) }
		, workGroupSize{ getUVec3Member( *this, ast::Builtin::eWorkGroupSize ).x() }
		, workGroupID{ getUVec3Member( *this, ast::Builtin::eWorkGroupID ).x() }
		, localInvocationID{ getUVec3Member( *this, ast::Builtin::eLocalInvocationID ).x() }
		, globalInvocationID{ getUVec3Member( *this, ast::Builtin::eGlobalInvocationID ).x() }
		, localInvocationIndex{ getUIntMember( *this, ast::Builtin::eLocalInvocationIndex ) }
	{
	}

	MeshInNV::MeshInNV( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
		: MeshInNV{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "meshIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, localSizeY
						, localSizeZ )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr MeshInNV::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eMesh
			, FlagT );

		if ( !result->hasMember( ast::Builtin::eWorkGroupID ) )
		{
			result->declMember( ast::Builtin::eWorkGroupSize
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
			result->declMember( ast::Builtin::eMeshViewCountNV
				, type::Kind::eUInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eMeshViewIndicesNV
				, type::Kind::eUInt32
				, ast::type::UnknownArraySize );
			result->declMember( ast::Builtin::eDrawIndex
				, type::Kind::eUInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	MeshSubgroupInNV::MeshSubgroupInNV( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: MeshInNV{ writer, std::move( expr ), enabled }
		, numSubgroups{ getUIntMember( *this, ast::Builtin::eNumSubgroups ) }
		, subgroupID{ getUIntMember( *this, ast::Builtin::eSubgroupID ) }
		, subgroupSize{ getUIntMember( *this, ast::Builtin::eSubgroupSize ) }
		, subgroupInvocationID{ getUIntMember( *this, ast::Builtin::eSubgroupLocalInvocationID ) }
		, subgroupEqMask{ getUVec4Member( *this, ast::Builtin::eSubgroupEqMask ) }
		, subgroupGeMask{ getUVec4Member( *this, ast::Builtin::eSubgroupGeMask ) }
		, subgroupGtMask{ getUVec4Member( *this, ast::Builtin::eSubgroupGtMask ) }
		, subgroupLeMask{ getUVec4Member( *this, ast::Builtin::eSubgroupLeMask ) }
		, subgroupLtMask{ getUVec4Member( *this, ast::Builtin::eSubgroupLtMask ) }
	{
	}

	MeshSubgroupInNV::MeshSubgroupInNV( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
		: MeshSubgroupInNV{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "meshSubgroupIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, localSizeY
						, localSizeZ ) ) )
			, true }
	{
	}

	ast::type::StructPtr MeshSubgroupInNV::makeType( ast::type::TypesCache & cache )
	{
		auto result = std::static_pointer_cast< ast::type::IOStruct >( MeshInNV::makeType( cache ) );

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

	MeshWriterNV::MeshWriterNV( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eMeshNV, allocator }
	{
	}

	MeshWriterNV::MeshWriterNV( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eMeshNV, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eMeshNV
			&& builder.getType() != ast::ShaderStage::eModernGraphicsNV )
		{
			throw std::logic_error{ "Can't create a MeshWriterNV from this kind of builder." };
		}
	}

	//*************************************************************************
}
