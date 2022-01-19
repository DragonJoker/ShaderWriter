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
		, launchID{ getUVec3Member( *this, ast::Builtin::eLaunchID ) }
		, launchSize{ getUVec3Member( *this, ast::Builtin::eLaunchSize ) }
	{
	}

	CallableIn::CallableIn( ShaderWriter & writer )
		: CallableIn{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "rayCallIn"
					, makeType( getTypesCache( writer ) )
					, ast::var::Flag::eShaderInput ) )
			, true }
	{
	}

	ast::type::StructPtr CallableIn::makeType( ast::type::TypesCache & cache )
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
		}

		return result;
	}

	//*************************************************************************

	CallableWriter::CallableWriter()
		: ShaderWriter{ ast::ShaderStage::eCallable }
	{
	}
}
