/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Builtins.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Type/TypeArray.hpp>

namespace sdw
{
	Builtin::Builtin( ShaderWriter & writer )
		: m_writer{ &writer }
		, m_shader{ &writer.getShader() }
	{
	}

#pragma region Built-in inputs
	/**
	*name
	*	Built-in inputs.
	*/
	/**@{*/
	InVertex::InVertex( ShaderWriter & writer )
		: Builtin{ writer }
		, vertexIndex{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_VertexIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, instanceIndex{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_InstanceIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, drawID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_DrawID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, baseVertex{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_BaseVertex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, baseInstance{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_BaseInstance", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
	{
	}

	//*************************************************************************

	InTessellationControl::InTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, patchVerticesIn{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, primitiveID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, invocationID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache(), 32u ), var::Flag::eShaderInput ) )
			, true }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, tessCoord{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessCoord", writer.getTypesCache().getVec3F(), var::Flag::eShaderInput ) )
			, true }
		, patchVerticesIn{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, primitiveID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, tessLevelOuter{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderInput ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderInput ) )
			, true }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache(), 32u ), var::Flag::eShaderInput ) )
			, true }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InputT< Void >::InputT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
	{
	}

	//*************************************************************************

	InGeometry::InGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, primitiveIDIn{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PrimitiveIDIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, invocationID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
	{
	}

	//*************************************************************************

	InFragment::InFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, fragCoord{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_FragCoord", writer.getTypesCache().getVec4F(), var::Flag::eShaderInput ) )
			, true }
		, frontFacing{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_FrontFacing", writer.getTypesCache().getBool(), var::Flag::eShaderInput ) )
			, true }
		, pointCoord{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PointCoord", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) )
			, true }
		, sampleID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_SampleID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, samplePosition{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_SamplePosition", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) )
			, true }
		, sampleMaskIn{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_SampleMaskIn", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderInput ) )
			, true }
		, clipDistance{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_ClipDistance", writer.getTypesCache().getArray( writer.getTypesCache().getFloat() ), var::Flag::eShaderInput ) )
			, true }
		, primitiveID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, layer{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
		, viewportIndex{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) )
			, true }
	{
	}

	//*************************************************************************

	InCompute::InCompute( ShaderWriter & writer )
		: Builtin{ writer }
		, numWorkGroups{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_NumWorkGroups", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) )
			, true }
		, workGroupID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_WorkGroupID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) )
			, true }
		, localInvocationID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_LocalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) )
			, true }
		, globalInvocationID{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_GlobalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) )
			, true }
		, localInvocationIndex{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_LocalInvocationIndex", writer.getTypesCache().getUInt(), var::Flag::eShaderInput ) )
			, true }
		, workGroupSize{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_WorkGroupSize", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) )
			, true }
	{
	}
	/**@}*/
#pragma endregion
#pragma region Built-in outputs
	/**
	*name
	*	Built-in outputs.
	*/
	/**@{*/
	OutVertex::OutVertex( ShaderWriter & writer )
		: Builtin{ writer }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eVertexOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationControl::OutTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, tessLevelOuter{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderOutput ) )
			, true }
		, tessLevelInner{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderOutput ) )
			, true }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_out", PerVertex::getArrayType( writer.getTypesCache(), 32u ), var::Flag::eShaderOutput ) )
			, true }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, vtx{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( findWriterMandat( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutputStreamT< Void >::OutputStreamT( ShaderWriter & writer
		, ast::expr::ExprPtr expr
		, bool enabled )
		: Value{ writer, std::move( expr ), enabled }
		, vtx{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "", PerVertex::getBaseType( getTypesCache( writer ) ), var::Flag::eShaderOutput ) ) }
	{
	}

	OutputStreamT< Void >::OutputStreamT( ShaderWriter & writer
		, type::OutputLayout layout
		, uint32_t count )
		: OutputStreamT{ writer
			, makeExpr( writer
				, sdw::getShader( writer ).registerName( "geomOut"
					, type::makeGeometryOutputType( makeType( getTypesCache( writer ) )
						, layout
						, count ) ) ) }
	{
		addStmt( writer
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	ast::type::TypePtr OutputStreamT< Void >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getVoid();
	}

	void OutputStreamT< Void >::append()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, ast::stmt::makeSimple( ast::expr::makeStreamAppend( sdw::makeExpr( *this ) ) ) );
	}

	void OutputStreamT< Void >::restartStrip()
	{
		ShaderWriter & writer = findWriterMandat( *this );
		addStmt( writer
			, ast::stmt::makeSimple( ast::expr::makeEndPrimitive( getTypesCache( writer ) ) ) );
	}

	//*************************************************************************

	OutGeometry::OutGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, primitiveID{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_PrimitiveID", getTypesCache( writer ).getInt(), var::Flag::eShaderOutput ) )
			, true }
		, layer{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_Layer", getTypesCache( writer ).getInt(), var::Flag::eShaderOutput ) )
			, true }
		, viewportIndex{ writer
			, makeIdent( getTypesCache( writer )
				, sdw::getShader( writer ).registerBuiltin( "gl_ViewportIndex", getTypesCache( writer ).getInt(), var::Flag::eShaderOutput ) )
			, true }
	{
	}

	//*************************************************************************

	OutFragment::OutFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, fragDepth{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_FragDepth", writer.getTypesCache().getFloat(), var::Flag::eShaderOutput ) )
			, true }
		, sampleMask{ writer
			, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_SampleMask", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderOutput ) )
			, true }
	{
	}
	/**@}*/
#pragma endregion
}
