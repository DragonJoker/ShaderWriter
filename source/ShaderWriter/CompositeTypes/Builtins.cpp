/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Builtins.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Type/TypeArray.hpp>

namespace sdw
{
	Builtin::Builtin( ShaderWriter & writer )
		: m_shader{ &writer.getShader() }
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
		, vertexIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_VertexIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, instanceIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InstanceIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, drawID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_DrawID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, baseVertex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_BaseVertex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, baseInstance{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_BaseInstance", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InTessellationControl::InTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, patchVerticesIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, primitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, invocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, tessCoord{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessCoord", writer.getTypesCache().getVec3F(), var::Flag::eShaderInput ) ) }
		, patchVerticesIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, primitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, tessLevelOuter{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderInput ) ) }
		, tessLevelInner{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderInput ) ) }
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InGeometry::InGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, primitiveIDIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveIDIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, invocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_in", PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, vtx.getType() ) );
	}

	//*************************************************************************

	InFragment::InFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, fragCoord{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FragCoord", writer.getTypesCache().getVec4F(), var::Flag::eShaderInput ) ) }
		, frontFacing{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FrontFacing", writer.getTypesCache().getBool(), var::Flag::eShaderInput ) ) }
		, pointCoord{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PointCoord", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) ) }
		, sampleID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, samplePosition{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SamplePosition", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) ) }
		, sampleMaskIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleMaskIn", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderInput ) ) }
		, clipDistance{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ClipDistance", writer.getTypesCache().getArray( writer.getTypesCache().getFloat() ), var::Flag::eShaderInput ) ) }
		, primitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, layer{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, viewportIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InCompute::InCompute( ShaderWriter & writer )
		: Builtin{ writer }
		, numWorkGroups{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_NumWorkGroups", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, workGroupID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_WorkGroupID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, localInvocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_LocalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, globalInvocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_GlobalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, localInvocationIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_LocalInvocationIndex", writer.getTypesCache().getUInt(), var::Flag::eShaderInput ) ) }
		, workGroupSize{ &writer.getShader(), makeIdent( writer.getTypesCache()
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
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eVertexOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationControl::OutTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, tessLevelOuter{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderOutput ) ) }
		, tessLevelInner{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderOutput ) ) }
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_out", PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutGeometry::OutGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, primitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, layer{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, viewportIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, vtx{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, vtx.getType() ) );
	}

	//*************************************************************************

	OutFragment::OutFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, fragDepth{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FragDepth", writer.getTypesCache().getFloat(), var::Flag::eShaderOutput ) ) }
		, sampleMask{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleMask", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderOutput ) ) }
	{
	}
	/**@}*/
#pragma endregion
}
