/*
See LICENSE file in root folder
*/
#ifndef ___Writer_WriterDebug_H___
#define ___Writer_WriterDebug_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	std::string writeDebug( Shader & shader );
	std::string writeDebug( stmt::Container * stmt );
}

#endif
