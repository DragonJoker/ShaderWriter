/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterSpirV_H___
#define ___SDW_WriterSpirV_H___

#include "ShaderWriter/ShaderWriterPrerequisites.hpp"

#include <vector>

namespace sdw
{
	std::string writeSpirv( Shader const & shader
		, ShaderType type
		, bool writeHeader = true );
	std::vector< uint32_t > serializeSpirv( Shader const & shader
		, ShaderType type );
}

#endif
