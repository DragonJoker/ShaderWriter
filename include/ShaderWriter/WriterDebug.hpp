/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterDebug_H___
#define ___SDW_WriterDebug_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	SDW_API std::string writePreprocessedDebug( Shader const & shader
		, ast::PreprocessResult & preprocessResult );
}

#endif
