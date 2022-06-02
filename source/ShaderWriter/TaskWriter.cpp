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
		, workGroupSize{ getUVec3Member( *this, ast::Builtin::eWorkGroupSize ).x() }
		, workGroupID{ getUVec3Member( *this, ast::Builtin::eWorkGroupID ).x() }
		, localInvocationID{ getUVec3Member( *this, ast::Builtin::eLocalInvocationID ).x() }
		, globalInvocationID{ getUVec3Member( *this, ast::Builtin::eGlobalInvocationID ).x() }
		, localInvocationIndex{ getUIntMember( *this, ast::Builtin::eLocalInvocationIndex ) }
		, drawID{ getIntMember( *this, ast::Builtin::eDrawIndex ) }
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

	TaskWriter::TaskWriter()
		: ShaderWriter{ ast::ShaderStage::eTask }
	{
	}

	void TaskWriter::implementMain( uint32_t localSizeX
		, TaskMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( TaskIn{ *this, localSizeX } ) );
	}

	//*************************************************************************
}
