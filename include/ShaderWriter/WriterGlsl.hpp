/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterGlsl_H___
#define ___SDW_WriterGlsl_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	std::string compileGlsl( Shader const & shader
		, ShaderType type
		, SpecialisationInfo const & specialisation );
}

#endif
