/*
See LICENSE file in root folder
*/
#include "ShaderWriter/RayCallableWriter.hpp"

namespace sdw
{
	//*************************************************************************

	RayCallableIn::RayCallableIn( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: VoidT< FlagT >{ writer, std::move( expr ), enabled }
		, launchID{ getUVec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getUVec3Member( *this, ast::Builtin::eLaunchSize ) }
	{
	}

	RayCallableIn::RayCallableIn( ShaderWriter & writer )
		: RayCallableIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "rayCallIn"
					, makeType( getTypesCache( writer ) )
				, FlagT ) )
			, true }
	{
	}

	ast::type::IOStructPtr RayCallableIn::makeType( ast::type::TypesCache & cache )
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

	RayCallableWriter::RayCallableWriter()
		: ShaderWriter{ ast::ShaderStage::eRayCallable }
	{
	}

	void RayCallableWriter::ignoreIntersection()
	{
		addStmt( stmt::makeIgnoreIntersection() );
	}

	void RayCallableWriter::terminateRay()
	{
		addStmt( stmt::makeTerminateRay() );
	}

	void RayCallableWriter::implementMain( RayCallableMainFunc const & function )
	{
		( void )implementFunction< Void >( "main"
			, ast::stmt::FunctionFlag::eEntryPoint
			, function
			, makeInParam( RayCallableIn{ *this } ) );
	}
}
