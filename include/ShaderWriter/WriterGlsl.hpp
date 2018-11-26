/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterGlsl_H___
#define ___SDW_WriterGlsl_H___

#include "ShaderWriterPrerequisites.hpp"

namespace sdw
{
	struct GlslConfig
	{
		uint32_t shaderLanguageVersion{ 420 };
		bool hasStd430Layout{ false };
		bool hasShaderStorageBuffers{ false };
		bool hasDescriptorSets{ false };
		bool hasBaseInstance{ false };
	};

	std::string compileGlsl( Shader const & shader
		, SpecialisationInfo const & specialisation
		, GlslConfig const & config );
}

#endif
