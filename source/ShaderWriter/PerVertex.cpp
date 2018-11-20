/*
See LICENSE file in root folder
*/
#include "ShaderWriter/PerVertex.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	namespace
	{
		InterfaceBlock doGetInfo()
		{
			InterfaceBlock result{ type::MemoryLayout::eStd430, "gl_PerVertex" };
			result.registerMember< type::Kind::eVec4F >( "gl_Position" );
			result.registerMember< type::Kind::eFloat >( "gl_PointSize" );
			result.registerMember< type::Kind::eFloat >( "gl_ClipDistance", type::UnknownArraySize );
			return result;
		}

		bool isInput( stmt::PerVertexDecl::Source source )
		{
			return source == stmt::PerVertexDecl::Source::eGeometryInput
				|| source == stmt::PerVertexDecl::Source::eTessellationControlInput
				|| source == stmt::PerVertexDecl::Source::eTessellationEvaluationInput;
		}

		var::Flag getBuiltinFlag( stmt::PerVertexDecl::Source source )
		{
			return isInput( source )
				? var::Flag::eShaderInput
				: var::Flag::eShaderOutput;
		}
	}

	gl_PerVertex::gl_PerVertex( ShaderWriter & writer
		, stmt::PerVertexDecl::Source source )
		: Value{ &writer.getShader(), makeExpr( var::makeVariable( doGetInfo().getType(), "" ) ) }
		, m_source{ source }
		, gl_Position{ &writer.getShader()
			, makeIdent( writer.getShader().registerBuiltin( "gl_Position"
				, std::static_pointer_cast< type::Struct >( getType() )->getMember( "gl_Position" ).type, getBuiltinFlag( m_source ) ) ) }
		, gl_PointSize{ &writer.getShader()
			, makeIdent( writer.getShader().registerBuiltin( "gl_PointSize"
				, std::static_pointer_cast< type::Struct >( getType() )->getMember( "gl_PointSize" ).type, getBuiltinFlag( m_source ) ) ) }
		, gl_ClipDistance{ &writer.getShader()
			, makeIdent( writer.getShader().registerBuiltin( "gl_ClipDistance"
				, std::static_pointer_cast< type::Struct >( getType() )->getMember( "gl_ClipDistance" ).type, getBuiltinFlag( m_source ) ) ) }
	{
		addStmt( *findContainer( *this )
			, sdw::makePerVertexDecl( source, getType() ) );
	}
}
