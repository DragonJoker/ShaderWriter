/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterSpirV_H___
#define ___SDW_WriterSpirV_H___

#include "ShaderWriterPrerequisites.hpp"

#include <vector>

namespace sdw
{
	std::string writeSpirv( Shader const & shader
		, bool writeHeader = true );
	std::vector< uint32_t > serialiseSpirv( Shader const & shader );
}

#endif
