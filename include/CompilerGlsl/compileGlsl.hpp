/*
See LICENSE file in root folder
*/
#ifndef ___SDW_WriterGlsl_H___
#define ___SDW_WriterGlsl_H___

#include <ShaderWriter/ShaderWriterPrerequisites.hpp>

#if defined( _WIN32 )
#	if defined( CompilerGlsl_Exports )
#		define SDWGLSL_API __declspec( dllexport )
#	else
#		define SDWGLSL_API __declspec( dllimport )
#	endif
#else
#	define SDWGLSL_API
#endif

namespace glsl
{
	struct GlslConfig
	{
		ast::ShaderStage shaderStage;
		uint32_t shaderLanguageVersion{ 430 };
		bool vulkanGlsl{ false };
		bool flipVertY{ false };
		bool fixupClipDepth{ false };
		bool hasStd430Layout{ false };
		bool hasShaderStorageBuffers{ false };
		bool hasDescriptorSets{ false };
		bool hasBaseInstance{ false };
	};

	SDWGLSL_API std::string compileGlsl( sdw::Shader const & shader
		, ast::SpecialisationInfo const & specialisation
		, GlslConfig const & config );
}

#endif
