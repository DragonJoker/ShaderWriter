/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayIntersectionWriter.hpp"

#include "ShaderWriter/Intrinsics/Intrinsics.hpp"

namespace sdw
{
	//*************************************************************************

	RayIntersectionIn::RayIntersectionIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: StructInstance{ writer, std::move( expr ), enabled }
		, launchID{ getU32Vec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getU32Vec3Member( *this, ast::Builtin::eLaunchSize ) }
		, primitiveID{ getInt32Member( *this, ast::Builtin::ePrimitiveID ) }
		, instanceID{ getInt32Member( *this, ast::Builtin::eInstanceID ) }
		, instanceCustomIndex{ getInt32Member( *this, ast::Builtin::eInstanceCustomIndex ) }
		, geometryIndex{ getInt32Member( *this, ast::Builtin::eGeometryIndex ) }
		, worldRayOrigin{ getVec3Member( *this, ast::Builtin::eWorldRayOrigin ) }
		, worldRayDirection{ getVec3Member( *this, ast::Builtin::eWorldRayDirection ) }
		, objectRayOrigin{ getVec3Member( *this, ast::Builtin::eObjectRayOrigin ) }
		, objectRayDirection{ getVec3Member( *this, ast::Builtin::eObjectRayDirection ) }
		, rayTmin{ getFloatMember( *this, ast::Builtin::eRayTmin ) }
		, rayTmax{ getFloatMember( *this, ast::Builtin::eRayTmax ) }
		, incomingRayFlags{ getUInt32Member( *this, ast::Builtin::eIncomingRayFlags ) }
		, objectToWorld{ getMat4x3Member( *this, ast::Builtin::eObjectToWorld ) }
		, worldToObject{ getMat4x3Member( *this, ast::Builtin::eWorldToObject ) }
		, hitT{ rayTmax }
	{
	}

	RayIntersectionIn::RayIntersectionIn( ShaderWriter & writer )
		: RayIntersectionIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "rayIntersectIn"
					, makeType( getTypesCache( writer ) )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr RayIntersectionIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eRayIntersection
			, FlagT );

		if ( !result->hasMember( ast::Builtin::eLaunchID ) )
		{
			result->declMember( ast::Builtin::eLaunchID
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLaunchSize
				, type::Kind::eVec3U32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInstanceID
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInstanceCustomIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eGeometryIndex
				, type::Kind::eInt32
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorldRayOrigin
				, type::Kind::eVec3F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorldRayDirection
				, type::Kind::eVec3F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eObjectRayOrigin
				, type::Kind::eVec3F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eObjectRayDirection
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
			result->declMember( ast::Builtin::eObjectToWorld
				, type::Kind::eMat4x3F
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eWorldToObject
				, type::Kind::eMat4x3F
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	RayIntersectionWriter::RayIntersectionWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eRayIntersection, allocator }
	{
	}

	RayIntersectionWriter::RayIntersectionWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eRayIntersection, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eRayIntersection
			&& builder.getType() != ast::ShaderStage::eRayTrace )
		{
			throw ast::Exception{ "Can't create a RayIntersectionWriter from this kind of builder." };
		}
	}

	void RayIntersectionWriter::implementMain( RayIntersectionMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, getEntryPointFlags() | uint32_t( ast::stmt::FunctionFlag::eRayIntersectionEntryPoint )
			, function
			, makeInParam( RayIntersectionIn{ *this } ) );
	}

	//*************************************************************************
}
