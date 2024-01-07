/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayAnyHitWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

#include <ShaderAST/Stmt/StmtIgnoreIntersection.hpp>
#include <ShaderAST/Stmt/StmtTerminateRay.hpp>

namespace sdw
{
	//*************************************************************************

	RayAnyHitIn::RayAnyHitIn( ShaderWriter & writer
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
		, hitKind{ getUInt32Member( *this, ast::Builtin::eHitKind ) }
		, objectToWorld{ getMat4x3Member( *this, ast::Builtin::eObjectToWorld ) }
		, worldToObject{ getMat4x3Member( *this, ast::Builtin::eWorldToObject ) }
		, hitT{ rayTmax }
	{
	}

	RayAnyHitIn::RayAnyHitIn( ShaderWriter & writer )
		: RayAnyHitIn{ writer
			, makeExpr( writer
				, sdw::getBuilder( writer ).registerName( "rayAnyHitIn"
					, makeType( getTypesCache( writer ) )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr RayAnyHitIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = cache.getIOStruct( "SDW_Main"
			, ast::EntryPoint::eRayAnyHit
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
			result->declMember( ast::Builtin::eHitKind
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

	RayAnyHitWriter::RayAnyHitWriter( ShaderAllocator * allocator )
		: EntryPointWriter{ ast::ShaderStage::eRayAnyHit, allocator }
	{
	}

	RayAnyHitWriter::RayAnyHitWriter( ShaderBuilder & builder )
		: EntryPointWriter{ ast::ShaderStage::eRayAnyHit, builder }
	{
		if ( builder.getType() != ast::ShaderStage::eRayAnyHit
			&& builder.getType() != ast::ShaderStage::eRayTrace )
		{
			throw ast::Exception{ "Can't create a RayAnyHitWriter from this kind of builder." };
		}
	}

	void RayAnyHitWriter::ignoreIntersection()
	{
		addStmt( getStmtCache().makeIgnoreIntersection() );
	}

	void RayAnyHitWriter::terminateRay()
	{
		addStmt( getStmtCache().makeTerminateRay() );
	}

	//*************************************************************************
}
