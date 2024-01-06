#include "GlslToSpv.hpp"

#pragma warning( push )
#pragma warning( disable: 4365 )
#pragma warning( disable: 4464 )
#pragma warning( disable: 5262 )
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

			~BlockLocale()noexcept
			{
				try
				{
					if ( m_prvLoc.name() != "C" )
					{
						std::locale::global( m_prvLoc );
					}
				}
				catch ( ... )
				{
				}
			}

		private:
			std::locale m_prvLoc;
		};

		void doInitResources( TBuiltInResource & resources )
		{
			resources.limits.nonInductiveForLoops = true;
			resources.limits.whileLoops = true;
			resources.limits.doWhileLoops = true;
			resources.limits.generalUniformIndexing = true;
			resources.limits.generalAttributeMatrixVectorIndexing = true;
			resources.limits.generalVaryingIndexing = true;
			resources.limits.generalSamplerIndexing = true;
			resources.limits.generalVariableIndexing = true;
			resources.limits.generalConstantMatrixVectorIndexing = true;

			resources.maxLights = 32;
			resources.maxClipPlanes = 6;
			resources.maxTextureUnits = 32;
			resources.maxTextureCoords = 32;
			resources.maxVertexAttribs = 64;
			resources.maxVertexUniformComponents = 4096;
			resources.maxVaryingFloats = 32;
			resources.maxVertexTextureImageUnits = 32;
			resources.maxCombinedTextureImageUnits = 80;
			resources.maxTextureImageUnits = 32;
			resources.maxFragmentUniformComponents = 4096;
			resources.maxDrawBuffers = 16;
			resources.maxVertexUniformVectors = 128;
			resources.maxVaryingVectors = 8;
			resources.maxFragmentUniformVectors = 16;
			resources.maxVertexOutputVectors = 16;
			resources.maxFragmentInputVectors = 15;
			resources.minProgramTexelOffset = -8;
			resources.maxProgramTexelOffset = 32;
			resources.maxClipDistances = 6;
			resources.maxComputeWorkGroupCountX = 512;
			resources.maxComputeWorkGroupCountY = 512;
			resources.maxComputeWorkGroupCountZ = 512;
			resources.maxComputeWorkGroupSizeX = 512;
			resources.maxComputeWorkGroupSizeY = 512;
			resources.maxComputeWorkGroupSizeZ = 512;
			resources.maxComputeUniformComponents = 1024;
			resources.maxComputeTextureImageUnits = 16;
			resources.maxComputeImageUniforms = 8;
			resources.maxComputeAtomicCounters = 8;
			resources.maxComputeAtomicCounterBuffers = 1;
			resources.maxVaryingComponents = 32;
			resources.maxVertexOutputComponents = 32;
			resources.maxGeometryInputComponents = 32;
			resources.maxGeometryOutputComponents = 32;
			resources.maxFragmentInputComponents = 32;
			resources.maxImageUnits = 8;
			resources.maxCombinedImageUnitsAndFragmentOutputs = 8;
			resources.maxCombinedShaderOutputResources = 8;
			resources.maxImageSamples = 0;
			resources.maxVertexImageUniforms = 0;
			resources.maxTessControlImageUniforms = 0;
			resources.maxTessEvaluationImageUniforms = 0;
			resources.maxGeometryImageUniforms = 0;
			resources.maxFragmentImageUniforms = 8;
			resources.maxCombinedImageUniforms = 8;
			resources.maxGeometryTextureImageUnits = 16;
			resources.maxGeometryOutputVertices = 256;
			resources.maxGeometryTotalOutputComponents = 32;
			resources.maxGeometryUniformComponents = 1024;
			resources.maxGeometryVaryingComponents = 32;
			resources.maxTessControlInputComponents = 32;
			resources.maxTessControlOutputComponents = 128;
			resources.maxTessControlTextureImageUnits = 16;
			resources.maxTessControlUniformComponents = 1024;
			resources.maxTessControlTotalOutputComponents = 32;
			resources.maxTessEvaluationInputComponents = 32;
			resources.maxTessEvaluationOutputComponents = 32;
			resources.maxTessEvaluationTextureImageUnits = 16;
			resources.maxTessEvaluationUniformComponents = 1024;
			resources.maxTessPatchComponents = 32;
			resources.maxPatchVertices = 32;
			resources.maxTessGenLevel = 32;
			resources.maxViewports = 32;
			resources.maxVertexAtomicCounters = 0;
			resources.maxTessControlAtomicCounters = 0;
			resources.maxTessEvaluationAtomicCounters = 0;
			resources.maxGeometryAtomicCounters = 0;
			resources.maxFragmentAtomicCounters = 8;
			resources.maxCombinedAtomicCounters = 8;
			resources.maxAtomicCounterBindings = 1;
			resources.maxVertexAtomicCounterBuffers = 0;
			resources.maxTessControlAtomicCounterBuffers = 0;
			resources.maxTessEvaluationAtomicCounterBuffers = 0;
			resources.maxGeometryAtomicCounterBuffers = 0;
			resources.maxFragmentAtomicCounterBuffers = 1;
			resources.maxCombinedAtomicCounterBuffers = 1;
			resources.maxAtomicCounterBufferSize = 16384;
			resources.maxTransformFeedbackBuffers = 4;
			resources.maxTransformFeedbackInterleavedComponents = 64;
			resources.maxCullDistances = 16;
			resources.maxCombinedClipAndCullDistances = 6;
			resources.maxSamples = 4;
			resources.maxMeshOutputVerticesNV = 256;
			resources.maxMeshOutputPrimitivesNV = 256;
			resources.maxMeshWorkGroupSizeX_NV = 128;
			resources.maxMeshWorkGroupSizeY_NV = 128;
			resources.maxMeshWorkGroupSizeZ_NV = 128;
			resources.maxTaskWorkGroupSizeX_NV = 128;
			resources.maxTaskWorkGroupSizeY_NV = 128;
			resources.maxTaskWorkGroupSizeZ_NV = 128;
			resources.maxMeshViewCountNV = 4;
			resources.maxMeshOutputVerticesEXT = 256;
			resources.maxMeshOutputPrimitivesEXT = 256;
			resources.maxMeshWorkGroupSizeX_EXT = 128;
			resources.maxMeshWorkGroupSizeY_EXT = 128;
			resources.maxMeshWorkGroupSizeZ_EXT = 128;
			resources.maxTaskWorkGroupSizeX_EXT = 128;
			resources.maxTaskWorkGroupSizeY_EXT = 128;
			resources.maxTaskWorkGroupSizeZ_EXT = 128;
			resources.maxMeshViewCountEXT = 4;
			resources.maxDualSourceDrawBuffersEXT = 4;
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
			case ast::ShaderStage::eTaskNV:
				return EShLangTaskNV;
			case ast::ShaderStage::eMeshNV:
				return EShLangMeshNV;
			case ast::ShaderStage::eTask:
				return EShLangTask;
			case ast::ShaderStage::eMesh:
				return EShLangMesh;
			case ast::ShaderStage::eFragment:
				return EShLangFragment;
			case ast::ShaderStage::eCompute:
				return EShLangCompute;
			case ast::ShaderStage::eRayAnyHit:
				return EShLangAnyHit;
			case ast::ShaderStage::eCallable:
				return EShLangCallable;
			case ast::ShaderStage::eRayClosestHit:
				return EShLangClosestHit;
			case ast::ShaderStage::eRayGeneration:
				return EShLangRayGen;
			case ast::ShaderStage::eRayIntersection:
				return EShLangIntersect;
			case ast::ShaderStage::eRayMiss:
				return EShLangMiss;
			default:
				AST_Failure( "Unsupported shader stage." );
				return EShLangVertex;
			}
		}

		glslang::EShTargetLanguageVersion doGetLanguageVersion( uint32_t spvVersion )
		{
			switch ( spvVersion )
			{
			case 110u:
				return glslang::EShTargetSpv_1_1;
			case 120u:
				return glslang::EShTargetSpv_1_2;
			case 130u:
				return glslang::EShTargetSpv_1_3;
			case 140u:
				return glslang::EShTargetSpv_1_4;
			case 150u:
				return glslang::EShTargetSpv_1_5;
			case 160u:
				return glslang::EShTargetSpv_1_6;
			default:
				return glslang::EShTargetSpv_1_0;
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
		, std::string_view shader
		, uint32_t spvVersion )
	{
		std::vector< uint32_t > spirv;
		BlockLocale guard;
		TBuiltInResource resources;
		doInitResources( resources );

		// Enable SPIR-V and Vulkan rules when parsing GLSL
		auto messages = EShMessages( EShMsgSpvRules | EShMsgVulkanRules );
		auto glstage = doGetLanguage( stage );
		glslang::TShader glshader{ glstage };
		glshader.setEnvTarget( glslang::EShTargetSpv
			, doGetLanguageVersion( spvVersion ) );

		char const * const str = shader.data();
		glshader.setStrings( &str, 1 );

		if ( !glshader.parse( &resources, 100, false, messages ) )
		{
			throw std::runtime_error{ std::string{ "Shader compilation failed.\n" } + glshader.getInfoLog() };
		}

		glslang::TProgram glprogram;
		glprogram.addShader( &glshader );

		if ( !glprogram.link( messages ) )
		{
			if ( glprogram.getInfoLog() )
			{
				throw std::runtime_error{ std::string{ "Program linkage failed.\n" } + glprogram.getInfoLog() };
			}
		}

		glslang::GlslangToSpv( *glprogram.getIntermediate( glstage ), spirv );
		return spirv;
	}
}
