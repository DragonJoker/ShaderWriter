/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TaskWriter.hpp"
#include "ShaderWriter/CompositeTypes/StructInstance.hpp"

namespace sdw
{
	//*************************************************************************

	TaskIn::TaskIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, drawID{ getIntMember( *this, ast::Builtin::eDrawIndex ) }
		, workGroupSize{ getUVec3Member( *this, ast::Builtin::eWorkGroupSize ).x() }
		, workGroupID{ getUVec3Member( *this, ast::Builtin::eWorkGroupID ).x() }
		, localInvocationID{ getUVec3Member( *this, ast::Builtin::eLocalInvocationID ).x() }
		, globalInvocationID{ getUVec3Member( *this, ast::Builtin::eGlobalInvocationID ).x() }
		, localInvocationIndex{ getUIntMember( *this, ast::Builtin::eLocalInvocationIndex ) }
	{
	}

	TaskIn::TaskIn( ShaderWriter & writer
		, uint32_t localSizeX )
		: TaskIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "taskIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, 1u
						, 1u ) ) )
			, true }
	{
	}

	ast::type::StructPtr TaskIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
			, "TaskInput"
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
			result->declMember( ast::Builtin::eDrawIndex
				, type::Kind::eInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	TaskSubgroupIn::TaskSubgroupIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: TaskIn{ writer, std::move( expr ), enabled }
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

	TaskSubgroupIn::TaskSubgroupIn( ShaderWriter & writer
		, uint32_t localSizeX )
		: TaskSubgroupIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "taskSubgroupIn"
					, ast::type::makeComputeInputType( makeType( getTypesCache( writer ) )
						, localSizeX
						, 1u
						, 1u ) ) )
			, true }
	{
	}

	ast::type::StructPtr TaskSubgroupIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = std::static_pointer_cast< ast::type::IOStruct >( TaskIn::makeType( cache ) );

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

	TaskWriter::TaskWriter()
		: ShaderWriter{ ast::ShaderStage::eTask }
	{
	}

	void TaskWriter::implementMain( uint32_t localSizeX
		, TaskMainFunc const & function )
	{
		implementMainT< VoidT >( localSizeX
			, TaskPayloadOut{ *this }
			, function );
	}

	void TaskWriter::implementMain( uint32_t localSizeX
		, TaskSubgroupMainFunc const & function )
	{
		implementMainT< VoidT >( localSizeX
			, TaskPayloadOut{ *this }
			, function );
	}

	//*************************************************************************
}
