/*
See LICENSE file in root folder
*/
#include "ShaderWriter/CompositeTypes/Builtins.hpp"

#include "ShaderWriter/Writer.hpp"

#include <ShaderAST/Type/TypeArray.hpp>

namespace sdw
{
	//*************************************************************************

	InVertex::InVertex( ShaderWriter & writer )
		: gl_VertexID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_VertexID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_InstanceID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_InstanceID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_DrawID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_DrawID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_BaseVertex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_BaseVertex", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_BaseInstance{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_BaseInstance", type::getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InTessellationControl::InTessellationControl( ShaderWriter & writer )
		: gl_PatchVerticesIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PatchVerticesIn", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_InvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_InvocationID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_in", nullptr, var::Flag::eShaderInput ) ) }// TODO
	{
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: gl_TessCoord{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessCoord", type::getVec3F(), var::Flag::eShaderInput ) ) }
		, gl_PatchVerticesIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PatchVerticesIn", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_TessLevelOuter{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelOuter", type::makeArrayType( type::getFloat(), 4u ), var::Flag::eShaderInput ) ) }
		, gl_TessLevelInner{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelInner", type::makeArrayType( type::getFloat(), 2u ), var::Flag::eShaderInput ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_in", nullptr, var::Flag::eShaderInput ) ) }// TODO
	{
	}

	//*************************************************************************

	InGeometry::InGeometry( ShaderWriter & writer )
		: gl_PrimitiveIDIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveIDIn", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_InvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_InvocationID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_in", nullptr, var::Flag::eShaderInput ) ) }// TODO
	{
	}

	//*************************************************************************

	InFragment::InFragment( ShaderWriter & writer )
		: gl_FragCoord{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_FragCoord", type::getVec4F(), var::Flag::eShaderInput ) ) }
		, gl_FrontFacing{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_FrontFacing", type::getBool(), var::Flag::eShaderInput ) ) }
		, gl_PointCoord{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PointCoord", type::getVec2F(), var::Flag::eShaderInput ) ) }
		, gl_SampleID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SampleID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_SamplePosition{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SamplePosition", type::getVec2F(), var::Flag::eShaderInput ) ) }
		, gl_SampleMaskIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SampleMaskIn", type::makeArrayType( type::getInt(), type::UnknownArraySize ), var::Flag::eShaderInput ) ) }
		, gl_ClipDistance{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_ClipDistance", type::makeArrayType( type::getFloat(), type::UnknownArraySize ), var::Flag::eShaderInput ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_Layer{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_Layer", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_ViewportIndex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_ViewportIndex", type::getInt(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	InCompute::InCompute( ShaderWriter & writer )
		: gl_NumWorkGroups{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_NumWorkGroups", type::getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_WorkGroupID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_WorkGroupID", type::getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_LocalInvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_LocalInvocationID", type::getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_GlobalInvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_GlobalInvocationID", type::getVec3U(), var::Flag::eShaderInput ) ) }
		, gl_LocalInvocationIndex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_LocalInvocationIndex", type::getInt(), var::Flag::eShaderInput ) ) }
		, gl_WorkGroupSize{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_WorkGroupSize", type::getVec3U(), var::Flag::eShaderInput ) ) }
	{
	}

	//*************************************************************************

	OutVertex::OutVertex( ShaderWriter & writer )
		: gl_out{ writer, stmt::PerVertexDecl::Source::eVertexOutput }
	{
	}

	//*************************************************************************

	OutTessellationControl::OutTessellationControl( ShaderWriter & writer )
		: gl_TessLevelOuter{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelOuter", type::makeArrayType( type::getFloat(), 4u ), var::Flag::eShaderOutput ) ) }
		, gl_TessLevelInner{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelInner", type::makeArrayType( type::getFloat(), 2u ), var::Flag::eShaderOutput ) ) }
		, gl_out{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_out", nullptr, var::Flag::eShaderOutput ) ) }// TODO
	{
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: gl_out{ writer, stmt::PerVertexDecl::Source::eTessellationControlOutput }
	{
	}

	//*************************************************************************

	OutGeometry::OutGeometry( ShaderWriter & writer )
		: gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt(), var::Flag::eShaderOutput ) ) }
		, gl_Layer{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_Layer", type::getInt(), var::Flag::eShaderOutput ) ) }
		, gl_ViewportIndex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_ViewportIndex", type::getInt(), var::Flag::eShaderOutput ) ) }
		, gl_out{ writer, stmt::PerVertexDecl::Source::eGeometryOutput }
	{
	}

	//*************************************************************************

	OutFragment::OutFragment( ShaderWriter & writer )
		: gl_FragDepth{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_FragDepth", type::getFloat(), var::Flag::eShaderOutput ) ) }
		, gl_SampleMask{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SampleMask", type::makeArrayType( type::getInt(), type::UnknownArraySize ), var::Flag::eShaderOutput ) ) }
	{
	}

	//*************************************************************************
}
