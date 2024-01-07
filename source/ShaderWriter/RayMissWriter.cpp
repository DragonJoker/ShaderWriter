/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayMissWriter.hpp"

namespace sdw
{
	//*************************************************************************

	RayMissIn::RayMissIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, launchID{ getU32Vec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getU32Vec3Member( *this, ast::Builtin::eLaunchSize ) }
		, worldRayOrigin{ getVec3Member( *this, ast::Builtin::eWorldRayOrigin ) }
		, worldRayDirection{ getVec3Member( *this, ast::Builtin::eWorldRayDirection ) }
		, rayTmin{ getFloatMember( *this, ast::Builtin::eRayTmin ) }
		, rayTmax{ getFloatMember( *this, ast::Builtin::eRayTmax ) }
		, incomingRayFlags{ getUInt32Member( *this, ast::Builtin::eIncomingRayFlags ) }
		, hitT{ rayTmax }
	{
	}

	RayMissIn::RayMissIn( ShaderWriter & writer )
		: RayMissIn{ writer
		, makeExpr( writer
			, sdw::getBuilder( writer ).registerName( "rayMissIn"
				, makeType( getTypesCache( writer ) )
				, ast::var::Flag::eShaderInput ) )
		, true }
	{
	}

	ast::type::StructPtr RayMissIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eRayMiss
			, FlagT );

		if ( !result->hasMember( ast::Builtin::eLaunchID ) )
		{
			result->declMember( ast::Builtin::eLaunchID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLaunchSize
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorldRayOrigin
				, type::Kind::eVec3F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorldRayDirection
				, type::Kind::eVec3F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eRayTmin
				, type::Kind::eFloat
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eRayTmax
				, type::Kind::eFloat
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eIncomingRayFlags
				, type::Kind::eUInt32
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	RayMissWriter::RayMissWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eRayMiss, allocator }
	{
	}

	RayMissWriter::RayMissWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eRayMiss, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eRayMiss
			&& builder.getType() != ast::ShaderStage::eRayTrace )
		{
			throw ast::Exception{ "Can't create a RayMissWriter from this kind of builder." };
		}
	}

	//*************************************************************************
}
