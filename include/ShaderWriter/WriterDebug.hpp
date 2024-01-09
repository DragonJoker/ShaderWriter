/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterDebug_H___
#define ___SDW_WriterDebug_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	SDW_API std::string writeDebug( Shader const & shader );
	SDW_API std::string writeDebug( stmt::Container const & stmt );
	SDW_API std::string writeDebugPreprocessed( Shader const & shader );
	SDW_API std::string writeDebugPreprocessed( Shader const & shader
		, stmt::Container const & stmt );
}

#endif
