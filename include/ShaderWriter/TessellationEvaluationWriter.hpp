/*
See LICENSE file in root folder
*/
#ifndef ___SDW_TessellationEvaluationWriter_H___
#define ___SDW_TessellationEvaluationWriter_H___

#include "ShaderWriter/Writer.hpp"
namespace sdw
{
	/**@{*/
	/**
	*name
	*	Tessellation evaluation shader.
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

	struct OutTessellationEvaluation : Builtin
	{
		SDW_API OutTessellationEvaluation( ShaderWriter & writer );
		//out gl_PerVertex;
		PerVertex vtx;
	};

	class TessellationEvaluationWriter
		: public ShaderWriter
	{
	public:
		SDW_API TessellationEvaluationWriter();

		SDW_API InTessellationEvaluation getIn();
		SDW_API OutTessellationEvaluation getOut();
	};
	/**@}*/
}

#include "TessellationEvaluationWriter.inl"

#endif
