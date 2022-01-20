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
		, launchID{ getUVec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getUVec3Member( *this, ast::Builtin::eLaunchSize ) }
		, primitiveID{ getIntMember( *this, ast::Builtin::ePrimitiveID ) }
		, instanceID{ getIntMember( *this, ast::Builtin::eInstanceID ) }
		, instanceCustomIndex{ getIntMember( *this, ast::Builtin::eInstanceCustomIndex ) }
		, geometryIndex{ getIntMember( *this, ast::Builtin::eGeometryIndex ) }
		, worldRayOrigin{ getVec3Member( *this, ast::Builtin::eWorldRayOrigin ) }
		, worldRayDirection{ getVec3Member( *this, ast::Builtin::eWorldRayDirection ) }
		, objectRayOrigin{ getVec3Member( *this, ast::Builtin::eObjectRayOrigin ) }
		, objectRayDirection{ getVec3Member( *this, ast::Builtin::eObjectRayDirection ) }
		, rayTmin{ getFloatMember( *this, ast::Builtin::eRayTmin ) }
		, rayTmax{ getFloatMember( *this, ast::Builtin::eRayTmax ) }
		, incomingRayFlags{ getUIntMember( *this, ast::Builtin::eIncomingRayFlags ) }
		, hitKind{ getUIntMember( *this, ast::Builtin::eHitKind ) }
		, objectToWorld{ getMat4x3Member( *this, ast::Builtin::eObjectToWorld ) }
		, worldToObject{ getMat4x3Member( *this, ast::Builtin::eWorldToObject ) }
		, hitT{ rayTmax }
	{
	}

	RayAnyHitIn::RayAnyHitIn( ShaderWriter & writer )
		: RayAnyHitIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "rayAnyHitIn"
					, makeType( getTypesCache( writer ) )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr RayAnyHitIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = VoidT< ast::var::Flag::eShaderInput >::makeIOType( cache );

		if ( !result->hasMember( ast::Builtin::eLaunchID ) )
		{
			result->declMember( ast::Builtin::eLaunchID
				, type::Kind::eVec3U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eLaunchSize
				, type::Kind::eVec3U
				, ast::type::NotArray );
			result->declMember( ast::Builtin::ePrimitiveID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInstanceID
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eInstanceCustomIndex
				, type::Kind::eInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eGeometryIndex
				, type::Kind::eInt
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
				, type::Kind::eUInt
				, ast::type::NotArray );
			result->declMember( ast::Builtin::eHitKind
				, type::Kind::eUInt
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

	RayAnyHitWriter::RayAnyHitWriter()
		: ShaderWriter{ ast::ShaderStage::eRayAnyHit }
	{
	}

	void RayAnyHitWriter::ignoreIntersection()
	{
		addStmt( stmt::makeIgnoreIntersection() );
	}

	void RayAnyHitWriter::terminateRay()
	{
		addStmt( stmt::makeTerminateRay() );
	}
}
