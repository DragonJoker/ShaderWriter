/*
See LICENSE file in root folder
*/
#include "ShaderWriter/PerVertex.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	namespace
	{
		type::TypePtr doGetType()
		{
			auto result = type::makeStructType( "gl_PerVertex" );
			result->addMember( type::getVec4F(), "gl_Position" );
			result->addMember( type::getFloat(), "gl_PointSize" );
			result->addMember( type::makeType( type::Kind::eFloat, type::UnknownArraySize ), "gl_ClipDistance" );
			return result;
		}
	}

	gl_PerVertex::gl_PerVertex()
		: Value{ nullptr, makeExpr( var::makeVariable( doGetType(), "" ) ) }
		, m_source{ stmt::PerVertexDecl::Source::eVertexOutput }
	{
	}

	gl_PerVertex::gl_PerVertex( ShaderWriter & writer, stmt::PerVertexDecl::Source source )
		: Value{ &writer.getShader(), makeExpr( var::makeVariable( doGetType(), "" ) ) }
		, m_source{ source }
	{
		addStmt( *findContainer( *this )
			, sdw::makePerVertexDecl( source ) );
	}

	Vec4 gl_PerVertex::gl_Position()const
	{
		return Vec4{ findShader( *this )
			, makeExpr( var::makeVariable( type::getVec4F(), "gl_Position" ) ) };
	}

	Float gl_PerVertex::gl_PointSize()const
	{
		return Float{ findShader( *this )
			, makeExpr( var::makeVariable( type::getFloat(), "gl_PointSize" ) ) };
	}

	Float gl_PerVertex::gl_ClipDistance()const
	{
		return Float{ findShader( *this )
			, makeExpr( var::makeVariable( type::makeType( type::Kind::eFloat, type::UnknownArraySize ), "gl_ClipDistance" ) ) };
	}
}
