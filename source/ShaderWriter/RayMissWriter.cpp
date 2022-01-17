/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayMissWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	//*************************************************************************

	RayMissIn::RayMissIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: VoidT< FlagT >{ writer, std::move( expr ), enabled }
		, launchID{ getUVec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getUVec3Member( *this, ast::Builtin::eLaunchSize ) }
		, worldRayOrigin{ getVec3Member( *this, ast::Builtin::eWorldRayOrigin ) }
		, worldRayDirection{ getVec3Member( *this, ast::Builtin::eWorldRayDirection ) }
		, rayTmin{ getFloatMember( *this, ast::Builtin::eRayTmin ) }
		, rayTmax{ getFloatMember( *this, ast::Builtin::eRayTmax ) }
		, incomingRayFlags{ getUIntMember( *this, ast::Builtin::eIncomingRayFlags ) }
	{
	}

	RayMissIn::RayMissIn( ShaderWriter & writer )
		: RayMissIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "rayMissIn"
					, makeType( getTypesCache( writer ) )
				, FlagT ) )
			, true }
	{
	}

	ast::type::IOStructPtr RayMissIn::makeType( ast::type::TypesCache & cache )
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
				, type::Kind::eUInt
				, ast::type::NotArray );
		}

		return result;
	}

	//*************************************************************************

	RayMissWriter::RayMissWriter()
		: ShaderWriter{ ast::ShaderStage::eRayMiss }
	{
	}

	void RayMissWriter::traceRay( AccelerationStructure const & topLevel
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

	void RayMissWriter::implementMain( RayMissMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( RayMissIn{ *this } ) );
	}
}
