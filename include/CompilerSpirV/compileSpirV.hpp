/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterSpirV_H___
#define ___SDW_WriterSpirV_H___

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

#include <vector>

namespace spirv
{
	std::string writeSpirv( sdw::Shader const & shader
		, bool writeHeader = true );
	std::vector< uint32_t > serialiseSpirv( sdw::Shader const & shader );
}

#endif
