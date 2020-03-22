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
		, gl_VertexIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_VertexIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_VertexID{ gl_VertexIndex }
		, gl_InstanceIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InstanceIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_InstanceID{ gl_InstanceIndex }
		, gl_DrawID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_DrawID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_BaseVertex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_BaseVertex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_BaseInstance{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_BaseInstance", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InTessellationControl::InTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_PatchVerticesIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_InvocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getTypesCache()
				, writer.getShader().registerBuiltin( "gl_in", gl_PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlInput
				, gl_in.getType() ) );
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_TessCoord{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessCoord", writer.getTypesCache().getVec3F(), var::Flag::eShaderInput ) ) }
		, gl_PatchVerticesIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PatchVerticesIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_TessLevelOuter{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderInput ) ) }
		, gl_TessLevelInner{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderInput ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_in", gl_PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationInput
				, gl_in.getType() ) );
	}

	//*************************************************************************

	InGeometry::InGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_PrimitiveIDIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveIDIn", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_InvocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_InvocationID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_in", gl_PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderInput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryInput
				, gl_in.getType() ) );
	}

	//*************************************************************************

	InFragment::InFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_FragCoord{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FragCoord", writer.getTypesCache().getVec4F(), var::Flag::eShaderInput ) ) }
		, gl_FrontFacing{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FrontFacing", writer.getTypesCache().getBool(), var::Flag::eShaderInput ) ) }
		, gl_PointCoord{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PointCoord", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) ) }
		, gl_SampleID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_SamplePosition{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SamplePosition", writer.getTypesCache().getVec2F(), var::Flag::eShaderInput ) ) }
		, gl_SampleMaskIn{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleMaskIn", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderInput ) ) }
		, gl_ClipDistance{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ClipDistance", writer.getTypesCache().getArray( writer.getTypesCache().getFloat() ), var::Flag::eShaderInput ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_Layer{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
		, gl_ViewportIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InCompute::InCompute( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_NumWorkGroups{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_NumWorkGroups", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_WorkGroupID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_WorkGroupID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_LocalInvocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_LocalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_GlobalInvocationID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_GlobalInvocationID", writer.getTypesCache().getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_LocalInvocationIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_LocalInvocationIndex", writer.getTypesCache().getUInt(), var::Flag::eShaderInput ) ) }
		, gl_WorkGroupSize{ &writer.getShader(), makeIdent( writer.getTypesCache()
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
		, gl_out{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", gl_PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eVertexOutput
				, gl_out.getType() ) );
	}

	//*************************************************************************

	OutTessellationControl::OutTessellationControl( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_TessLevelOuter{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelOuter", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 4u ), var::Flag::eShaderOutput ) ) }
		, gl_TessLevelInner{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_TessLevelInner", writer.getTypesCache().getArray( writer.getTypesCache().getFloat(), 2u ), var::Flag::eShaderOutput ) ) }
		, gl_out{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_out", gl_PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationControlOutput
				, gl_out.getType() ) );
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_out{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", gl_PerVertex::getBaseType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eTessellationEvaluationOutput
				, gl_out.getType() ) );
	}

	//*************************************************************************

	OutGeometry::OutGeometry( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_PrimitiveID", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, gl_Layer{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_Layer", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, gl_ViewportIndex{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_ViewportIndex", writer.getTypesCache().getInt(), var::Flag::eShaderOutput ) ) }
		, gl_out{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "", gl_PerVertex::getArrayType( writer.getTypesCache() ), var::Flag::eShaderOutput ) ) }
	{
		addStmt( *findShader( *this )
			, sdw::makePerVertexDecl( ast::stmt::PerVertexDecl::eGeometryOutput
				, gl_out.getType() ) );
	}

	//*************************************************************************

	OutFragment::OutFragment( ShaderWriter & writer )
		: Builtin{ writer }
		, gl_FragDepth{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_FragDepth", writer.getTypesCache().getFloat(), var::Flag::eShaderOutput ) ) }
		, gl_SampleMask{ &writer.getShader(), makeIdent( writer.getTypesCache()
			, writer.getShader().registerBuiltin( "gl_SampleMask", writer.getTypesCache().getArray( writer.getTypesCache().getInt() ), var::Flag::eShaderOutput ) ) }
	{
	}
	/**@}*/
#pragma endregion
}
