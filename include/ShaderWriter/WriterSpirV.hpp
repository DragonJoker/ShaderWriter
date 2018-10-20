/*
See LICENSE file in root folder
*/
#ifndef ___Writer_WriterSpirV_H___
#define ___Writer_WriterSpirV_H___

#include "ShaderWriterPrerequisites.hpp"

#include <vector>

namespace sdw
{
	std::vector< uint32_t > writeSpirV( Shader & shader, ShaderType type );
}

#endif
