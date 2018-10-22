/*
See LICENSE file in root folder
*/
#ifndef ___Writer_WriterGlsl_H___
#define ___Writer_WriterGlsl_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	std::string writeGlsl( Shader & shader, ShaderType type );
	std::string writeGlsl( stmt::Container * stmt, ShaderType type );
}

#endif
