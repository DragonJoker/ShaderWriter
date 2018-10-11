/*
See LICENSE file in root folder
*/
#ifndef ___Writer_InputLayout_H___
#define ___Writer_InputLayout_H___
#pragma once

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	struct InputLayout
	{
		enum class Kind
		{
			ePointList,
			eLineList,
			eLineStrip,
			eTriangleList,
			eTriangleStrip,
			eTriangleFan,
			eLineListWithAdjacency,
			eLineStripWithAdjacency,
			eTriangleListWithAdjacency,
			eTriangleStripWithAdjacency,
		};

		explicit InputLayout( Kind p_kind )
			: m_kind{ p_kind }
		{
		}

		Kind m_kind;
	};
}

#endif
