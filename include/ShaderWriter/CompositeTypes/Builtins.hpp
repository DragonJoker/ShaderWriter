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
#pragma region Base declarations
	/**
	*name
	*	Base declarations.
	*/
	/**@{*/
	struct Builtin
	{
		SDW_API Builtin( ShaderWriter & writer );

		inline ShaderWriter * getWriter()const
		{
			return m_writer;
		}

		inline ast::Shader * getShader()const
		{
			return m_shader;
		}

	private:
		ShaderWriter * m_writer;
		ast::Shader * m_shader;
	};
	/**@}*/
#pragma endregion
#pragma region I/O
	/**
	*name
	*	I/O.
	*/
	/**@{*/
	/**
	*	Placeholder for I/O empty types.
	*/
	template< ast::var::Flag FlagT >
	struct VoidT
		: public Value
	{
		VoidT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	/**
	*	Holds input data for shaders.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct InputT
		: public DataT< ast::var::Flag::eShaderInput >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderInput;

		InputT( ShaderWriter & writer );
		InputT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	/**
	*	Holds output data for shaders.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct OutputT
		: public DataT< ast::var::Flag::eShaderOutput >
	{
		static constexpr ast::var::Flag FlagT = ast::var::Flag::eShaderOutput;

		OutputT( ShaderWriter & writer );
		OutputT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
	/**@}*/
#pragma endregion
#pragma region Vertex shader
	/**
	*name
	*	Vertex shader.
	*/
	/**@{*/
	/**
	*	Holds input data for a vertex shader.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct VertexInT
		: public InputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		VertexInT( ShaderWriter & writer );
		VertexInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		//in int gl_VertexIndex;
		Int const vertexIndex;
		//in int gl_InstanceIndex;
		Int const instanceIndex;
		//in int gl_DrawID;
		Int const drawID;
		//in int gl_BaseVertex;
		Int const baseVertex;
		//in int gl_BaseInstance;
		Int const baseInstance;
	};
	/**
	*	Holds per vertex output data.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct VertexOutT
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

		VertexOutT( ShaderWriter & writer );
		VertexOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		PerVertex vtx;
	};
	/**@}*/
#pragma endregion
#pragma region Geometry shader
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	template< template< ast::var::Flag FlagT > typename DataT
		, type::InputLayout LayoutT >
	struct GeomInT
		: Array< InputT< DataT > >
	{
		static constexpr ast::var::Flag FlagT = InputT< DataT >::FlagT;

		GeomInT( ShaderWriter & writer );
		GeomInT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		Array< PerVertex > vtx;
	};
	/**
	*	Holds data and functions to append primitives to the stream or restart it.
	*/
	template< template< ast::var::Flag FlagT > typename DataT >
	struct GeomOutT
		: public OutputT< DataT >
	{
		static constexpr ast::var::Flag FlagT = OutputT< DataT >::FlagT;

	protected:
		GeomOutT( ShaderWriter & writer
			, type::OutputLayout layout
			, uint32_t count );

	public:
		GeomOutT( ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled = true );

		void append();
		void restartStrip();

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );

		PerVertex vtx;
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct PointStreamT
		: public GeomOutT< DataT >
	{
		PointStreamT( ShaderWriter & writer
			, uint32_t count );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct LineStreamT
		: public GeomOutT< DataT >
	{
		LineStreamT( ShaderWriter & writer
			, uint32_t count );
	};

	template< template< ast::var::Flag FlagT > typename DataT >
	struct TriangleStreamT
		: public GeomOutT< DataT >
	{
		TriangleStreamT( ShaderWriter & writer
			, uint32_t count );
	};
	/**@}*/
	/**@}*/
#pragma endregion
#pragma region Built-in inputs
	/**
	*name
	*	Built-in inputs.
	*/
	/**@{*/
	/**
	*name
	*	Tessellation control shader.
	*/
	/**@{*/
	struct InTessellationControl : Builtin
	{
		SDW_API InTessellationControl( ShaderWriter & writer );
		//in int gl_PatchVerticesIn;
		Int const patchVerticesIn;
		//in int gl_PrimitiveID;
		Int const primitiveID;
		//in int gl_InvocationID;
		Int const invocationID;
		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		Array< PerVertex > const vtx;
	};
	/**@}*/
	/**
	*name
	*	Tessellation evaluation shader.
	*/
	/**@{*/
	struct InTessellationEvaluation : Builtin
	{
		SDW_API InTessellationEvaluation( ShaderWriter & writer );
		//in vec3 gl_TessCoord;
		Vec3 const tessCoord;
		//in int gl_PatchVerticesIn;
		Int const patchVerticesIn;
		//in int gl_PrimitiveID;
		Int const primitiveID;
		//patch in float gl_TessLevelOuter[4];
		Array< Float > const tessLevelOuter;
		//patch in float gl_TessLevelInner[2];
		Array< Float > const tessLevelInner;
		//patch in gl_PerVertex gl_in[gl_MaxPatchVertices];
		Array< PerVertex > const vtx;
	};
	/**@}*/
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	struct InGeometry : Builtin
	{
		SDW_API InGeometry( ShaderWriter & writer );
		//in int gl_PrimitiveIDIn;
		Int const primitiveIDIn;
		//in int gl_InvocationID;
		Int const invocationID;
	};
	/**@}*/
	/**
	*name
	*	Fragment shader.
	*/
	/**@{*/
	struct InFragment : Builtin
	{
		SDW_API InFragment( ShaderWriter & writer );
		//in vec4 gl_FragCoord;
		Vec4 const fragCoord;
		//in bool gl_FrontFacing;
		Boolean const frontFacing;
		//in vec2 gl_PointCoord;
		Vec2 const pointCoord;
		//in int gl_SampleID;
		Int const sampleID;
		//in vec2 gl_SamplePosition;
		Vec2 const samplePosition;
		//in int gl_SampleMaskIn[];
		Array< Int > const sampleMaskIn;
		//in float gl_ClipDistance[];
		Array < Float > const clipDistance;
		//in int gl_PrimitiveID;
		Int const primitiveID;
		//in int gl_Layer;
		Int const layer;
		//in int gl_ViewportIndex;
		Int const viewportIndex;
	};
	/**@}*/
	/**
	*name
	*	Compute shader.
	*/
	/**@{*/
	struct InCompute : Builtin
	{
		SDW_API InCompute( ShaderWriter & writer );
		//in uvec3 gl_NumWorkGroups;
		UVec3 const numWorkGroups;
		//in uvec3 gl_WorkGroupID;
		UVec3 const workGroupID;
		//in uvec3 gl_LocalInvocationID;
		UVec3 const localInvocationID;
		//in uvec3 gl_GlobalInvocationID;
		UVec3 const globalInvocationID;
		//in uint  gl_LocalInvocationIndex;
		UInt const localInvocationIndex;
		//const uvec3 gl_WorkGroupSize;
		UVec3 const workGroupSize;
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
	*	Tessellation control shader.
	*/
	/**@{*/
	struct OutTessellationControl : Builtin
	{
		SDW_API OutTessellationControl( ShaderWriter & writer );
		//patch out float gl_TessLevelOuter[4];
		Array< Float > tessLevelOuter;
		//patch out float gl_TessLevelInner[2];
		Array< Float > tessLevelInner;
		//out gl_PerVertex gl_out[];
		Array< PerVertex > vtx;
	};
	/**@}*/
	/**
	*name
	*	Tessellation evaluation shader.
	*/
	/**@{*/
	struct OutTessellationEvaluation : Builtin
	{
		SDW_API OutTessellationEvaluation( ShaderWriter & writer );
		//out gl_PerVertex;
		PerVertex vtx;
	};
	/**@}*/
	/**
	*name
	*	Geometry shader.
	*/
	/**@{*/
	struct OutGeometry : Builtin
	{
		SDW_API OutGeometry( ShaderWriter & writer );
		//out int gl_PrimitiveID;
		Int primitiveID;
		//out int gl_Layer;
		Int layer;
		//out int gl_ViewportIndex;
		Int viewportIndex;
	};
	/**@}*/
	/**
	*name
	*	Fragment shader.
	*/
	/**@{*/
	struct OutFragment : Builtin
	{
		SDW_API OutFragment( ShaderWriter & writer );
		//out float gl_FragDepth;
		Float fragDepth;
		//out int gl_SampleMask[];
		Array< Int > sampleMask;
	};
	/**@}*/
	/**@}*/
#pragma endregion
}

#include "Builtins.inl"

#endif
