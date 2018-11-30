/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterGlsl_H___
#define ___SDW_WriterGlsl_H___

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

namespace glsl
{
	struct GlslConfig
	{
		uint32_t shaderLanguageVersion{ 430 };
		uint32_t vulkanGlsl{ false };
		bool hasStd430Layout{ false };
		bool hasShaderStorageBuffers{ false };
		bool hasDescriptorSets{ false };
		bool hasBaseInstance{ false };
	};

	std::string compileGlsl( sdw::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig const & config );
}

#endif
