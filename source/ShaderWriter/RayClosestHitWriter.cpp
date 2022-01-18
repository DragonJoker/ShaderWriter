/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayClosestHitWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	//*************************************************************************

	RayClosestHitIn::RayClosestHitIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: VoidT< FlagT >{ writer, std::move( expr ), enabled }
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

	RayClosestHitIn::RayClosestHitIn( ShaderWriter & writer )
		: RayClosestHitIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "rayClosesHitIn"
					, makeType( getTypesCache( writer ) )
				, FlagT ) )
			, true }
	{
	}

	ast::type::IOStructPtr RayClosestHitIn::makeType( ast::type::TypesCache & cache )
	{
		auto result = VoidT< FlagT >::makeIOType( cache );

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

	RayClosestHitWriter::RayClosestHitWriter()
		: ShaderWriter{ ast::ShaderStage::eRayClosestHit }
	{
	}

	void RayClosestHitWriter::traceRay( AccelerationStructure const & topLevel
		, UInt const & rayFlags
		, UInt const & cullMask
		, UInt const & sbtRecordOffset
		, UInt const & sbtRecordStride
		, UInt const & missIndex
		, Vec3 const & origin
		, Float const & Tmin
		, Vec3 const & direction
		, Float const & Tmax
		, Int const & payload )
	{
		sdw::traceRay( topLevel
			, rayFlags
			, cullMask
			, sbtRecordOffset
			, sbtRecordStride
			, missIndex
			, origin
			, Tmin
			, direction
			, Tmax
			, payload );
	}

	void RayClosestHitWriter::implementMain( RayClosestHitMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( RayClosestHitIn{ *this } ) );
	}
}
