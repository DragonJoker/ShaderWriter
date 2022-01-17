/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayGenerationWriter.hpp"

#include "ShaderWriter/Intrinsics/IntrinsicFunctions.hpp"

namespace sdw
{
	//*************************************************************************

	RayGenerationIn::RayGenerationIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: VoidT< FlagT >{ writer, std::move( expr ), enabled }
		, launchID{ getUVec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getUVec3Member( *this, ast::Builtin::eLaunchSize ) }
	{
	}

	RayGenerationIn::RayGenerationIn( ShaderWriter & writer )
		: RayGenerationIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "rayGenIn"
					, makeType( getTypesCache( writer ) )
				, FlagT ) )
			, true }
	{
	}

	ast::type::IOStructPtr RayGenerationIn::makeType( ast::type::TypesCache & cache )
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
		}

		return result;
	}

	//*************************************************************************

	RayGenerationWriter::RayGenerationWriter()
		: ShaderWriter{ ast::ShaderStage::eRayGeneration }
	{
	}

	void RayGenerationWriter::traceRay( AccelerationStructure const & topLevel
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

	void RayGenerationWriter::implementMain( RayGenerationMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( RayGenerationIn{ *this } ) );
	}
}
