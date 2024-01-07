/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CallableWriter.hpp"

namespace sdw
{
	//*************************************************************************

	CallableIn::CallableIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, launchID{ getU32Vec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getU32Vec3Member( *this, ast::Builtin::eLaunchSize ) }
	{
	}

	CallableIn::CallableIn( ShaderWriter & writer )
		: CallableIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "rayCallIn"
					, makeType( getTypesCache( writer ) )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr CallableIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eCallable
			, FlagT );

		if ( !result->hasMember( ast::Builtin::eLaunchID ) )
		{
			result->declMember( ast::Builtin::eLaunchID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLaunchSize
				, type::Kind::eVec3U32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	CallableWriter::CallableWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eCallable, allocator }
	{
	}

	CallableWriter::CallableWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eCallable, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eCallable
			&& builder.getType() != ast::ShaderStage::eRayTrace )
		{
			throw ast::Exception{ "Can't create a CallableWriter from this kind of builder." };
		}
	}

	//*************************************************************************
}
