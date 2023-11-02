/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TaskWriterEXT.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	//*************************************************************************

	TaskIn::TaskIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, drawID{ getInt32Member( *this, ast::Builtin::eDrawIndex ) }
		, workGroupSize{ getU32Vec3Member( *this, ast::Builtin::eWorkGroupSize ).x() }
		, workGroupID{ getU32Vec3Member( *this, ast::Builtin::eWorkGroupID ).x() }
		, localInvocationID{ getU32Vec3Member( *this, ast::Builtin::eLocalInvocationID ).x() }
		, globalInvocationID{ getU32Vec3Member( *this, ast::Builtin::eGlobalInvocationID ).x() }
		, localInvocationIndex{ getUInt32Member( *this, ast::Builtin::eLocalInvocationIndex ) }
	{
	}

	TaskIn::TaskIn( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
		: TaskIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "taskIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, localSizeY
						, localSizeZ ) ) )
			, true }
	{
	}

	ast::type::StructPtr TaskIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eTask
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
			result->declMember( ast::Builtin::eDrawIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TaskSubgroupIn::TaskSubgroupIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: TaskIn{ writer, std::move( expr ), enabled }
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

	TaskSubgroupIn::TaskSubgroupIn( ShaderWriter & writer
		, uint32_t localSizeX
		, uint32_t localSizeY
		, uint32_t localSizeZ )
		: TaskSubgroupIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "taskSubgroupIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, localSizeY
						, localSizeZ ) ) )
			, true }
	{
	}

	ast::type::StructPtr TaskSubgroupIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = std::static_pointer_cast< ast::type::IOStruct >( TaskIn::makeType( cache ) );

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

	TaskWriterEXT::TaskWriterEXT( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eTask, allocator }
	{
	}

	TaskWriterEXT::TaskWriterEXT( ShaderBuilder & builder )
		: EntryPointWriter{ builder }
	{
	}

	//*************************************************************************
}
