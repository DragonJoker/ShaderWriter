/*
See LICENSE file in root folder
*/
#include "ShaderWriter/TessellationEvaluationWriter.hpp"

namespace sdw
{
	//*************************************************************************

	Builtin::Builtin( ShaderWriter & writer )
		: m_writer{ &writer }
		, m_shader{ &writer.getShader() }
	{
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, tessCoord{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessCoord"
					, writer.getTypesCache().getVec3F()
					, var::Flag::eShaderInput ) )
			, true }
		, patchVerticesIn{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PatchVerticesIn"
					, writer.getTypesCache().getInt()
					, var::Flag::eShaderInput ) )
			, true }
		, primitiveID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PrimitiveID"
					, writer.getTypesCache().getInt()
					, var::Flag::eShaderInput ) )
			, true }
		, tessLevelOuter{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessLevelOuter"
					, writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u )
					, var::Flag::eShaderInput ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessLevelInner"
					, writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u )
					, var::Flag::eShaderInput ) )
			, true }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_in"
					, PerVertex::getArrayType( writer.getTypesCache(), 32u )
					, var::Flag::eShaderInput ) )
			, true }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( ""
					, PerVertex::getBaseType( writer.getTypesCache() )
					, var::Flag::eShaderOutput ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	TessellationEvaluationWriter::TessellationEvaluationWriter()
		: ShaderWriter{ ast::ShaderStage::eTessellationControl }
	{
	}

	InTessellationEvaluation TessellationEvaluationWriter::getIn()
	{
		return InTessellationEvaluation{ *this };
	}

	OutTessellationEvaluation TessellationEvaluationWriter::getOut()
	{
		return OutTessellationEvaluation{ *this };
	}

	//*************************************************************************
}
