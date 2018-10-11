/*
See LICENSE file in root folder
*/
#ifndef ___Writer_PerVertex_H___
#define ___Writer_PerVertex_H___
#pragma once

#include "Vec4.hpp"

namespace sdw
{
	struct gl_PerVertex
		: public Value
	{
		enum Source
		{
			eVertexOutput,
			eTessellationControlInput,
			eTessellationControlOutput,
			eTessellationEvaluationInput,
			eTessellationEvaluationOutput,
			eGeometryInput,
			eGeometryOutput,
		};
		gl_PerVertex();
		gl_PerVertex( Shader & shader, Source source = eVertexOutput );
		Vec4 gl_Position()const;
		Float gl_PointSize()const;
		Float gl_ClipDistance()const;
	};
}

#endif
