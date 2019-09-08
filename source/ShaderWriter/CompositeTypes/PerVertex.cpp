/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	namespace
	{
		InterfaceBlock doGetInfo( ast::type::TypesCache & cache )
		{
			InterfaceBlock result{ cache, type::MemoryLayout::eStd430, "gl_PerVertex" };
			result.registerMember< type::Kind::eVec4F >( "gl_Position" );
			result.registerMember< type::Kind::eFloat >( "gl_PointSize" );
			result.registerMember< type::Kind::eFloat >( "gl_ClipDistance", 8u );
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
		: Value{ &writer.getShader(), makeExpr( writer.getShader(), var::makeVariable( doGetInfo( writer.getTypesCache() ).getType(), "" ) ) }
		, gl_Position{ &writer.getShader()
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_Position"
				, std::static_pointer_cast< type::Struct >( getType() )->getMember( "gl_Position" ).type
				, getBuiltinFlag( source ) ) ) }
		, gl_PointSize{ &writer.getShader()
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PointSize"
				, std::static_pointer_cast< type::Struct >( getType() )->getMember( "gl_PointSize" ).type
				, getBuiltinFlag( source ) ) ) }
		, gl_ClipDistance{ &writer.getShader()
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_ClipDistance"
				, std::static_pointer_cast< type::Struct >( getType() )->getMember( "gl_ClipDistance" ).type
				, getBuiltinFlag( source ) ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( source, getType() ) );
	}
}
