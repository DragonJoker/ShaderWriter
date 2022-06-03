/*
See LICENSE file in root folder
*/
#include "ShaderWriter/MeshWriter.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	//*************************************************************************

	MeshIn::MeshIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, meshViewCount{ getUIntMember( *this, ast::Builtin::eMeshViewCountNV ) }
		, meshViewIndices{ getUIntMemberArray( *this, ast::Builtin::eMeshViewIndicesNV ) }
		, drawID{ getIntMember( *this, ast::Builtin::eDrawIndex ) }
		, workGroupSize{ getUVec3Member( *this, ast::Builtin::eWorkGroupSize ).x() }
		, workGroupID{ getUVec3Member( *this, ast::Builtin::eWorkGroupID ).x() }
		, localInvocationID{ getUVec3Member( *this, ast::Builtin::eLocalInvocationID ).x() }
		, globalInvocationID{ getUVec3Member( *this, ast::Builtin::eGlobalInvocationID ).x() }
		, localInvocationIndex{ getUIntMember( *this, ast::Builtin::eLocalInvocationIndex ) }
	{
	}

	MeshIn::MeshIn( ShaderWriter & writer
		, uint32_t localSizeX )
		: MeshIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "meshIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, 1u
						, 1u )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr MeshIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "MeshInput"
			, ast::var::Flag::eShaderInput );

		if ( !result->hasMember( ast::Builtin::eWorkGroupID ) )
		{
			result->declMember( ast::Builtin::eWorkGroupSize
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
			result->declMember( ast::Builtin::eMeshViewCountNV
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eMeshViewIndicesNV
				, type::Kind::eUInt
				, ast::type::UnknownArraySize );
			result->declMember( ast::Builtin::eDrawIndex
				, type::Kind::eInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	MeshSubgroupIn::MeshSubgroupIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: MeshIn{ writer, std::move( expr ), enabled }
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

	MeshSubgroupIn::MeshSubgroupIn( ShaderWriter & writer
		, uint32_t localSizeX )
		: MeshSubgroupIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "meshSubgroupIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, 1u
						, 1u ) ) )
			, true }
	{
	}

	ast::type::StructPtr MeshSubgroupIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = std::static_pointer_cast< ast::type::IOStruct >( MeshIn::makeType( cache ) );

		if ( !result->hasMember( ast::Builtin::eNumSubgroups ) )
		{
			result->declMember( ast::Builtin::eNumSubgroups
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupID
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupSize
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupLocalInvocationID
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupEqMask
				, type::Kind::eVec4U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupGeMask
				, type::Kind::eVec4U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupGtMask
				, type::Kind::eVec4U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupLeMask
				, type::Kind::eVec4U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eSubgroupLtMask
				, type::Kind::eVec4U
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	PrimitiveIndexT< ast::type::OutputTopology::ePoint >::FnType const PrimitiveIndexT< ast::type::OutputTopology::ePoint >::getMember = getUIntMember;
	PrimitiveIndexT< ast::type::OutputTopology::eLine >::FnType const PrimitiveIndexT< ast::type::OutputTopology::eLine >::getMember = getUVec2Member;
	PrimitiveIndexT< ast::type::OutputTopology::eTriangle >::FnType const PrimitiveIndexT< ast::type::OutputTopology::eTriangle >::getMember = getUVec3Member;

	//*************************************************************************

	MeshWriter::MeshWriter()
		: ShaderWriter{ ast::ShaderStage::eMesh }
	{
	}

	//*************************************************************************
}
