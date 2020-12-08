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
		, vertexIndex{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_VertexIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, instanceIndex{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InstanceIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, drawID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_DrawID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, baseVertex{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_BaseVertex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, baseInstance{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_BaseInstance", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InTessellationControl::InTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, patchVerticesIn{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, primitiveID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, invocationID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, vtx{ writer, makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache(), 32u ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, tessCoord{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessCoord", writer.getTypesCache().getVec3F(), var::Flag::eShaderInput ) ) }
		, patchVerticesIn{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, primitiveID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, tessLevelOuter{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderInput ) ) }
		, tessLevelInner{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderInput ) ) }
		, vtx{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache(), 32u ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InGeometry::InGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, primitiveIDIn{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveIDIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, invocationID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, vtx{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache(), 3u ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InFragment::InFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, fragCoord{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FragCoord", writer.getTypesCache().getVec4F(), var::Flag::eShaderInput ) ) }
		, frontFacing{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FrontFacing", writer.getTypesCache().getBool(), var::Flag::eShaderInput ) ) }
		, pointCoord{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PointCoord", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) ) }
		, sampleID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, samplePosition{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SamplePosition", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) ) }
		, sampleMaskIn{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleMaskIn", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderInput ) ) }
		, clipDistance{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ClipDistance", writer.getTypesCache().getArray( writer.getTypesCache().getFloat() ), var::Flag::eShaderInput ) ) }
		, primitiveID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, layer{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, viewportIndex{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InCompute::InCompute( ShaderWriter & writer )
		: Builtin{ writer }
		, numWorkGroups{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_NumWorkGroups", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, workGroupID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_WorkGroupID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, localInvocationID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_LocalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, globalInvocationID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_GlobalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, localInvocationIndex{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_LocalInvocationIndex", writer.getTypesCache().getUInt(), var::Flag::eShaderInput ) ) }
		, workGroupSize{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_WorkGroupSize", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
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
		, vtx{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eVertexOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationControl::OutTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, tessLevelOuter{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderOutput ) ) }
		, tessLevelInner{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderOutput ) ) }
		, vtx{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_out", PerVertex::getArrayType( writer.getTypesCache(), 32u ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, vtx{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutGeometry::OutGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, primitiveID{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, layer{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, viewportIndex{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, vtx{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findWriter( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutFragment::OutFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, fragDepth{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FragDepth", writer.getTypesCache().getFloat(), var::Flag::eShaderOutput ) ) }
		, sampleMask{ writer, makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleMask", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderOutput ) ) }
	{
	}
	/**@}*/
#pragma endregion
}
