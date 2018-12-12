/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Builtins_H___
#define ___SDW_Builtins_H___

#include "ShaderWriter/BaseTypes/Array.hpp"
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/Float.hpp"
#include "ShaderWriter/CompositeTypes/PerVertex.hpp"
#include "ShaderWriter/VecTypes/Vec3.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
#pragma region Built-in inputs
	/**
	*name
	*	Built-in inputs.
	*/
	/**@{*/
	/**
	*name
	*	Vertex shader.
	*/
	/**@{*/
	struct InVertex
	{
		InVertex( ShaderWriter & writer );
		//in int gl_VertexID;
		Int const gl_VertexID;
		//in int gl_InstanceID;
		Int const gl_InstanceID;
		//in int gl_DrawID;
		Int const gl_DrawID;
		//in int gl_BaseVertex;
		Int const gl_BaseVertex;
		//in int gl_BaseInstance;
		Int const gl_BaseInstance;
	};
	/**@}*/
	/**
	*name
	*	Tessellation control shader.
	*/
	/**@{*/
	struct InTessellationControl
	{
		InTessellationControl( ShaderWriter & writer );
		//in int gl_PatchVerticesIn;
		Int const gl_PatchVerticesIn;
		//in int gl_PrimitiveID;
		Int const gl_PrimitiveID;
		//in int gl_InvocationID;
		Int const gl_InvocationID;
		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		Array< gl_PerVertex > const gl_in;
	};
	/**@}*/
	/**
	*name
	*	Tessellation evaluation shader.
	*/
	/**@{*/
	struct InTessellationEvaluation
	{
		InTessellationEvaluation( ShaderWriter & writer );
		//in vec3 gl_TessCoord;
		Vec3 const gl_TessCoord;
		//in int gl_PatchVerticesIn;
		Int const gl_PatchVerticesIn;
		//in int gl_PrimitiveID;
		Int const gl_PrimitiveID;
		//patch in float gl_TessLevelOuter[4];
		Array< Float > const gl_TessLevelOuter;
		//patch in float gl_TessLevelInner[2];
		Array< Float > const gl_TessLevelInner;
		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		Array< gl_PerVertex > const gl_in;
	};
	/**@}*/
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	struct InGeometry
	{
		InGeometry( ShaderWriter & writer );
		//in int gl_PrimitiveIDIn;
		Int const gl_PrimitiveIDIn;
		//in int gl_InvocationID;
		Int const gl_InvocationID;
		//in gl_PerVertex gl_in[];
		Array< gl_PerVertex > const gl_in;
	};
	/**@}*/
	/**
	*name
	*	Fragment shader.
	*/
	/**@{*/
	struct InFragment
	{
		InFragment( ShaderWriter & writer );
		//in vec4 gl_FragCoord;
		Vec4 const gl_FragCoord;
		//in bool gl_FrontFacing;
		Bool const gl_FrontFacing;
		//in vec2 gl_PointCoord;
		Vec2 const gl_PointCoord;
		//in int gl_SampleID;
		Int const gl_SampleID;
		//in vec2 gl_SamplePosition;
		Vec2 const gl_SamplePosition;
		//in int gl_SampleMaskIn[];
		Array< Int > const gl_SampleMaskIn;
		//in float gl_ClipDistance[];
		Array < Float > const gl_ClipDistance;
		//in int gl_PrimitiveID;
		Int const gl_PrimitiveID;
		//in int gl_Layer;
		Int const gl_Layer;
		//in int gl_ViewportIndex;
		Int const gl_ViewportIndex;
	};
	/**@}*/
	/**
	*name
	*	Compute shader.
	*/
	/**@{*/
	struct InCompute
	{
		InCompute( ShaderWriter & writer );
		//in uvec3 gl_NumWorkGroups;
		UVec3 const gl_NumWorkGroups;
		//in uvec3 gl_WorkGroupID;
		UVec3 const gl_WorkGroupID;
		//in uvec3 gl_LocalInvocationID;
		UVec3 const gl_LocalInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		UVec3 const gl_GlobalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		UInt const gl_LocalInvocationIndex;
		//const uvec3 gl_WorkGroupSize;
		UVec3 const gl_WorkGroupSize;
	};
	/**@}*/
	/**@}*/
#pragma endregion
#pragma region Built-in outputs
	/**
	*name
	*	Built-in outputs.
	*/
	/**@{*/
	/**
	*name
	*	Vertex shader.
	*/
	/**@{*/
	struct OutVertex
	{
		OutVertex( ShaderWriter & writer );
		//out gl_PerVertex;
		gl_PerVertex gl_out;
	};
	/**@}*/
	/**
	*name
	*	Tessellation control shader.
	*/
	/**@{*/
	struct OutTessellationControl
	{
		OutTessellationControl( ShaderWriter & writer );
		//patch out float gl_TessLevelOuter[4];
		Array< Float > gl_TessLevelOuter;
		//patch out float gl_TessLevelInner[2];
		Array< Float > gl_TessLevelInner;
		//out gl_PerVertex gl_out[];
		Array< gl_PerVertex > gl_out;
	};
	/**@}*/
	/**
	*name
	*	Tessellation evaluation shader.
	*/
	/**@{*/
	struct OutTessellationEvaluation
	{
		OutTessellationEvaluation( ShaderWriter & writer );
		//out gl_PerVertex;
		gl_PerVertex gl_out;
	};
	/**@}*/
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	struct OutGeometry
	{
		OutGeometry( ShaderWriter & writer );
		//out int gl_PrimitiveID;
		Int gl_PrimitiveID;
		//out int gl_Layer;
		Int gl_Layer;
		//out int gl_ViewportIndex;
		Int gl_ViewportIndex;
		//out gl_PerVertex;
		gl_PerVertex gl_out;
	};
	/**@}*/
	/**
	*name
	*	Fragment shader.
	*/
	/**@{*/
	struct OutFragment
	{
		OutFragment( ShaderWriter & writer );
		//out float gl_FragDepth;
		Float gl_FragDepth;
		//out int gl_SampleMask[];
		Array< Int > gl_SampleMask;
	};
	/**@}*/
	/**@}*/
#pragma endregion
}

#endif
