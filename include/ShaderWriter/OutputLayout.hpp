/*
See LICENSE file in root folder
*/
#ifndef ___Writer_OutputLayout_H___
#define ___Writer_OutputLayout_H___
#pragma once

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	struct OutputLayout
	{
		OutputLayout( Kind p_kind, uint32_t p_count )
			: m_kind{ p_kind }
			, m_count{ p_count }
		{
		}

		Kind m_kind;
		uint32_t m_count;
	};
}

#endif
