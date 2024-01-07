/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TaskWriterNV.hpp"

namespace sdw
{
	//*************************************************************************

	TaskInNV::TaskInNV( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, drawID{ getUInt32Member( *this, ast::Builtin::eDrawIndex ) }
		, workGroupSize{ getU32Vec3Member( *this, ast::Builtin::eWorkGroupSize ).x() }
		, workGroupID{ getU32Vec3Member( *this, ast::Builtin::eWorkGroupID ).x() }
		, localInvocationID{ getU32Vec3Member( *this, ast::Builtin::eLocalInvocationID ).x() }
		, globalInvocationID{ getU32Vec3Member( *this, ast::Builtin::eGlobalInvocationID ).x() }
		, localInvocationIndex{ getUInt32Member( *this, ast::Builtin::eLocalInvocationIndex ) }
	{
	}

	TaskInNV::TaskInNV( ShaderWriter & writer
		, uint32_t taskCount )
		: TaskInNV{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "taskIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, taskCount
						, 1u
						, 1u ) ) )
			, true }
	{
	}

	ast::type::StructPtr TaskInNV::makeType( ast::type::TypesCache & cache )
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
				, type::Kind::eUInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TaskSubgroupInNV::TaskSubgroupInNV( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: TaskInNV{ writer, std::move( expr ), enabled }
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

	TaskSubgroupInNV::TaskSubgroupInNV( ShaderWriter & writer
		, uint32_t taskCount )
		: TaskSubgroupInNV{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "taskSubgroupIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, taskCount
						, 1u
						, 1u ) ) )
			, true }
	{
	}

	ast::type::StructPtr TaskSubgroupInNV::makeType( ast::type::TypesCache & cache )
	{
		auto result = std::static_pointer_cast< ast::type::IOStruct >( TaskInNV::makeType( cache ) );

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

	TaskWriterNV::TaskWriterNV( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eTaskNV, allocator }
	{
	}

	TaskWriterNV::TaskWriterNV( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eTaskNV, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eTaskNV
			&& builder.getType() != ast::ShaderStage::eModernGraphicsNV )
		{
			throw ast::Exception{ "Can't create a TaskWriterNV from this kind of builder." };
		}
	}

	//*************************************************************************
}
