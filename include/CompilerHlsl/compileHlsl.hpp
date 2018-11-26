/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterHlsl_H___
#define ___SDW_WriterHlsl_H___

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

namespace hlsl
{
	std::string compileHlsl( sdw::Shader const & shader
		, ast::SpecialisationInfo const & specialisation );
}

#endif
