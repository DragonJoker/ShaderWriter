#include "GlslToSpv.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 4464 )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wuseless-cast"
#pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma GCC diagnostic ignored "-Wdeprecated-copy-dtor"
#pragma GCC diagnostic ignored "-Wdeprecated-copy"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wshadow-field-in-constructor"
#pragma clang diagnostic ignored "-Wsigned-enum-bitfield"
#pragma clang diagnostic ignored "-Wsuggest-destructor-override"
#pragma clang diagnostic ignored "-Wsuggest-override"
#include <glslang/Public/ShaderLang.h>
#include <glslang/SPIRV/GlslangToSpv.h>

#include <locale>
#pragma clang diagnostic pop
#pragma GCC diagnostic pop
#pragma warning( pop )

namespace test
{
	namespace
	{
		struct BlockLocale
		{
			BlockLocale()
			{
				m_prvLoc = std::locale( "" );

				if ( m_prvLoc.name() != "C" )
				{
					std::locale::global( std::locale{ "C" } );
				}
			}

			~BlockLocale()
			{
				if ( m_prvLoc.name() != "C" )
				{
					std::locale::global( m_prvLoc );
				}
			}

		private:
			std::locale m_prvLoc;
		};

		void doInitResources( TBuiltInResource & resources )
		{
			resources.limits.doWhileLoops = true;
			resources.limits.generalAttributeMatrixVectorIndexing = true;
			resources.limits.generalConstantMatrixVectorIndexing = true;
			resources.limits.generalSamplerIndexing = true;
			resources.limits.generalUniformIndexing = true;
			resources.limits.generalVariableIndexing = true;
			resources.limits.generalVaryingIndexing = true;
			resources.limits.nonInductiveForLoops = true;
			resources.limits.whileLoops = true;
			resources.maxAtomicCounterBindings = 1;
			resources.maxAtomicCounterBufferSize = 16384;
			resources.maxClipDistances = 6;
			resources.maxClipPlanes = 6;
			resources.maxCombinedAtomicCounterBuffers = 1;
			resources.maxCombinedAtomicCounters = 8;
			resources.maxCombinedClipAndCullDistances = 6;
			resources.maxCombinedImageUniforms = 8;
			resources.maxCombinedImageUnitsAndFragmentOutputs = 8;
			resources.maxCombinedShaderOutputResources = 8;
			resources.maxCombinedTextureImageUnits = 80;
			resources.maxComputeAtomicCounterBuffers = 1;
			resources.maxComputeAtomicCounters = 8;
			resources.maxComputeImageUniforms = 8;
			resources.maxComputeTextureImageUnits = 16;
			resources.maxComputeUniformComponents = 1024;
			resources.maxComputeWorkGroupCountX = 512;
			resources.maxComputeWorkGroupCountY = 512;
			resources.maxComputeWorkGroupCountZ = 512;
			resources.maxComputeWorkGroupSizeX = 512;
			resources.maxComputeWorkGroupSizeY = 512;
			resources.maxComputeWorkGroupSizeZ = 512;
			resources.maxCullDistances = 16;
			resources.maxDrawBuffers = 16;
			resources.maxFragmentAtomicCounterBuffers = 1;
			resources.maxFragmentAtomicCounters = 8;
			resources.maxFragmentImageUniforms = 8;
			resources.maxFragmentInputComponents = 32;
			resources.maxFragmentInputVectors = 15;
			resources.maxFragmentUniformComponents = 4096;
			resources.maxFragmentUniformVectors = 16;
			resources.maxGeometryAtomicCounterBuffers = 0;
			resources.maxGeometryAtomicCounters = 0;
			resources.maxGeometryImageUniforms = 0;
			resources.maxGeometryInputComponents = 32;
			resources.maxGeometryOutputComponents = 32;
			resources.maxGeometryOutputVertices = 256;
			resources.maxGeometryTextureImageUnits = 16;
			resources.maxGeometryTotalOutputComponents = 32;
			resources.maxGeometryUniformComponents = 1024;
			resources.maxGeometryVaryingComponents = 32;
			resources.maxImageSamples = 0;
			resources.maxImageUnits = 8;
			resources.maxLights = 32;
			resources.maxPatchVertices = 32;
			resources.maxProgramTexelOffset = 32;
			resources.maxSamples = 4;
			resources.maxTessControlAtomicCounterBuffers = 0;
			resources.maxTessControlAtomicCounters = 0;
			resources.maxTessControlImageUniforms = 0;
			resources.maxTessControlInputComponents = 32;
			resources.maxTessControlOutputComponents = 128;
			resources.maxTessControlTextureImageUnits = 16;
			resources.maxTessControlTotalOutputComponents = 32;
			resources.maxTessControlUniformComponents = 1024;
			resources.maxTessEvaluationAtomicCounterBuffers = 0;
			resources.maxTessEvaluationAtomicCounters = 0;
			resources.maxTessEvaluationImageUniforms = 0;
			resources.maxTessEvaluationInputComponents = 32;
			resources.maxTessEvaluationOutputComponents = 32;
			resources.maxTessEvaluationTextureImageUnits = 16;
			resources.maxTessEvaluationUniformComponents = 1024;
			resources.maxTessGenLevel = 32;
			resources.maxTessPatchComponents = 32;
			resources.maxTextureCoords = 32;
			resources.maxTextureImageUnits = 32;
			resources.maxTextureUnits = 32;
			resources.maxTransformFeedbackBuffers = 4;
			resources.maxTransformFeedbackInterleavedComponents = 64;
			resources.maxVaryingComponents = 32;
			resources.maxVaryingFloats = 32;
			resources.maxVaryingVectors = 8;
			resources.maxVertexAtomicCounterBuffers = 0;
			resources.maxVertexAtomicCounters = 0;
			resources.maxVertexAttribs = 64;
			resources.maxVertexImageUniforms = 0;
			resources.maxVertexOutputComponents = 32;
			resources.maxVertexOutputVectors = 16;
			resources.maxVertexTextureImageUnits = 32;
			resources.maxVertexUniformComponents = 4096;
			resources.maxVertexUniformVectors = 128;
			resources.maxViewports = 32;
			resources.minProgramTexelOffset = -8;
		}

		EShLanguage doGetLanguage( ast::ShaderStage stage )
		{
			switch ( stage )
			{
			case ast::ShaderStage::eVertex:
				return EShLangVertex;

			case ast::ShaderStage::eTessellationControl:
				return EShLangTessControl;

			case ast::ShaderStage::eTessellationEvaluation:
				return EShLangTessEvaluation;

			case ast::ShaderStage::eGeometry:
				return EShLangGeometry;

			case ast::ShaderStage::eFragment:
				return EShLangFragment;

			case ast::ShaderStage::eCompute:
				return EShLangCompute;

			default:
				AST_Failure( "Unsupported shader stage." );
				return EShLangVertex;
			}
		}
	}

	void initialiseGlslang()
	{
		glslang::InitializeProcess();
	}

	void cleanupGlslang()
	{
		glslang::FinalizeProcess();
	}

	std::vector< uint32_t > compileGlslToSpv( ast::ShaderStage stage
		, std::string const & shader )
	{
		std::vector< uint32_t > spirv;
		BlockLocale guard;
		TBuiltInResource resources;
		doInitResources( resources );

		// Enable SPIR-V and Vulkan rules when parsing GLSL
		auto messages = EShMessages( EShMsgSpvRules | EShMsgVulkanRules );
		auto glstage = doGetLanguage( stage );

		std::string source = shader;

		glslang::TShader glshader{ glstage };
		char const * const str = source.c_str();
		glshader.setStrings( &str, 1 );

		if ( !glshader.parse( &resources, 100, false, messages ) )
		{
			throw std::runtime_error{ "Shader compilation failed." };
		}

		glslang::TProgram glprogram;
		glprogram.addShader( &glshader );

		if ( !glprogram.link( messages ) )
		{
			throw std::runtime_error{ "Shader linkage failed." };
		}

		glslang::GlslangToSpv( *glprogram.getIntermediate( glstage ), spirv );
		return spirv;
	}
}
