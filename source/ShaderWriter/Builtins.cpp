/*
See LICENSE file in root folder
*/
#include "ShaderWriter/Builtins.hpp"

#include "ShaderWriter/Writer.hpp"

namespace sdw
{
	//*************************************************************************

	InVertex::InVertex( ShaderWriter & writer )
		: gl_VertexID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_VertexID", type::getInt() ) ) }
		, gl_InstanceID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_InstanceID", type::getInt() ) ) }
		, gl_DrawID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_DrawID", type::getInt() ) ) }
		, gl_BaseVertex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_BaseVertex", type::getInt() ) ) }
		, gl_BaseInstance{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_BaseInstance", type::getInt() ) ) }
	{
	}

	//*************************************************************************

	InTessellationControl::InTessellationControl( ShaderWriter & writer )
		: gl_PatchVerticesIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PatchVerticesIn", type::getInt() ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt() ) ) }
		, gl_InvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_InvocationID", type::getInt() ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_in", nullptr ) ) }// TODO
	{
	}

	//*************************************************************************

	InTessellationEvaluation::InTessellationEvaluation( ShaderWriter & writer )
		: gl_TessCoord{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessCoord", type::getVec3F() ) ) }
		, gl_PatchVerticesIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PatchVerticesIn", type::getInt() ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt() ) ) }
		, gl_TessLevelOuter{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelOuter", type::getFloat( 4u ) ) ) }
		, gl_TessLevelInner{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelInner", type::getFloat( 2u ) ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_in", nullptr ) ) }// TODO
	{
	}

	//*************************************************************************

	InGeometry::InGeometry( ShaderWriter & writer )
		: gl_PrimitiveIDIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveIDIn", type::getInt() ) ) }
		, gl_InvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_InvocationID", type::getInt() ) ) }
		, gl_in{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_in", nullptr ) ) }// TODO
	{
	}

	//*************************************************************************

	InFragment::InFragment( ShaderWriter & writer )
		: gl_FragCoord{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_FragCoord", type::getVec4F() ) ) }
		, gl_FrontFacing{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_FrontFacing", type::getBool() ) ) }
		, gl_PointCoord{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PointCoord", type::getVec2F() ) ) }
		, gl_SampleID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SampleID", type::getInt() ) ) }
		, gl_SamplePosition{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SamplePosition", type::getVec2F() ) ) }
		, gl_SampleMaskIn{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SampleMaskIn", type::getInt( type::UnknownArraySize ) ) ) }
		, gl_ClipDistance{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_ClipDistance", type::getFloat( type::UnknownArraySize ) ) ) }
		, gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt() ) ) }
		, gl_Layer{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_Layer", type::getInt() ) ) }
		, gl_ViewportIndex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_ViewportIndex", type::getInt() ) ) }
	{
	}

	//*************************************************************************

	InCompute::InCompute( ShaderWriter & writer )
		: gl_NumWorkGroups{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_NumWorkGroups", type::getVec3U() ) ) }
		, gl_WorkGroupID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_WorkGroupID", type::getVec3U() ) ) }
		, gl_LocalInvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_LocalInvocationID", type::getVec3U() ) ) }
		, gl_GlobalInvocationID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_GlobalInvocationID", type::getVec3U() ) ) }
		, gl_LocalInvocationIndex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_LocalInvocationIndex", type::getInt() ) ) }
		, gl_WorkGroupSize{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_WorkGroupSize", type::getVec3U() ) ) }
	{
	}

	//*************************************************************************

	OutVertex::OutVertex( ShaderWriter & writer )
		: gl_out{ writer, stmt::PerVertexDecl::Source::eVertexOutput }
	{
	}

	//*************************************************************************

	OutTessellationControl::OutTessellationControl( ShaderWriter & writer )
		: gl_TessLevelOuter{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelOuter", type::getFloat( 4u ) ) ) }
		, gl_TessLevelInner{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_TessLevelInner", type::getFloat( 2u ) ) ) }
		, gl_out{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_out", nullptr ) ) }// TODO
	{
	}

	//*************************************************************************

	OutTessellationEvaluation::OutTessellationEvaluation( ShaderWriter & writer )
		: gl_out{ writer, stmt::PerVertexDecl::Source::eTessellationControlOutput }
	{
	}

	//*************************************************************************

	OutGeometry::OutGeometry( ShaderWriter & writer )
		: gl_PrimitiveID{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_PrimitiveID", type::getInt() ) ) }
		, gl_Layer{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_Layer", type::getInt() ) ) }
		, gl_ViewportIndex{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_ViewportIndex", type::getInt() ) ) }
		, gl_out{ writer, stmt::PerVertexDecl::Source::eGeometryOutput }
	{
	}

	//*************************************************************************

	OutFragment::OutFragment( ShaderWriter & writer )
		: gl_FragDepth{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_FragDepth", type::getFloat() ) ) }
		, gl_SampleMask{ &writer.getShader(), makeIdent( writer.getShader().registerBuiltin( "gl_SampleMask", type::getInt( type::UnknownArraySize ) ) ) }
	{
	}

	//*************************************************************************
}
