/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterHlsl_H___
#define ___SDW_WriterHlsl_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	std::string writeHlsl( Shader const & shader, ShaderType type );
}

#endif
