/*
See LICENSE file in root folder
*/
#include "SpirVWrite.hpp"

#include "SpirVHelpers.hpp"

#include "CompilerSpirV/spirv/GLSL.std.450.hpp"
#include "CompilerSpirV/spirv/NonSemantic.Shader.DebugInfo.100.hpp"

#include <sstream>
#include <stdexcept>

namespace spirv
{
	namespace wrthlp
	{
		static std::stringstream getStream()
		{
			std::stringstream stream;
			std::locale loc{ "C" };
			stream.imbue( loc );
			return stream;
		}

		static std::string getSourceLanguageName( uint32_t value )
		{
			switch ( spv::SourceLanguage( value ) )
			{
			case spv::SourceLanguageUnknown:
				return "LanguageUnknown";
			case spv::SourceLanguageESSL:
				return "LanguageESSL";
			case spv::SourceLanguageGLSL:
				return "LanguageGLSL";
			case spv::SourceLanguageOpenCL_C:
				return "LanguageOpenCL_C";
			case spv::SourceLanguageOpenCL_CPP:
				return "LanguageOpenCL_CPP";
			case spv::SourceLanguageHLSL:
				return "LanguageHLSL";
			case spv::SourceLanguageCPP_for_OpenCL:
				return "LanguageCPP_for_OpenCL";
			default:
				AST_Failure( "Unsupported SourceLanguage" );
				return "Undefined";
			}
		}

		static std::string getName( spv::AddressingModel value )
		{
			switch ( value )
			{
			case spv::AddressingModelLogical:
				return "Logical";
			case spv::AddressingModelPhysical32:
				return "Physical32";
			case spv::AddressingModelPhysical64:
				return "Physical64";
			case spv::AddressingModelPhysicalStorageBuffer64:
				return "PhysicalStorageBuffer64";
			default:
				AST_Failure( "Unsupported AddressingModel" );
				return "Undefined";
			}
		}

		static std::string getName( spv::MemoryModel value )
		{
			switch ( value )
			{
			case spv::MemoryModelSimple:
				return "Simple";
			case spv::MemoryModelGLSL450:
				return "GLSL450";
			case spv::MemoryModelOpenCL:
				return "OpenCL";
			case spv::MemoryModelVulkan:
				return "Vulkan";
			default:
				AST_Failure( "Unsupported MemoryModel" );
				return "Undefined";
			}
		}

		static std::string getName( spv::ExecutionModel value )
		{
			switch ( value )
			{
			case spv::ExecutionModelVertex:
				return "Vertex";
			case spv::ExecutionModelTessellationControl:
				return "TessellationControl";
			case spv::ExecutionModelTessellationEvaluation:
				return "TessellationEvaluation";
			case spv::ExecutionModelGeometry:
				return "Geometry";
			case spv::ExecutionModelFragment:
				return "Fragment";
			case spv::ExecutionModelGLCompute:
				return "GLCompute";
			case spv::ExecutionModelKernel:
				return "Kernel";
			case spv::ExecutionModelTaskNV:
				return "TaskNV";
			case spv::ExecutionModelMeshNV:
				return "MeshNV";
			case spv::ExecutionModelTaskEXT:
				return "TaskEXT";
			case spv::ExecutionModelMeshEXT:
				return "MeshEXT";
			case spv::ExecutionModelRayGenerationKHR:
				return "RayGeneration";
			case spv::ExecutionModelIntersectionKHR:
				return "Intersection";
			case spv::ExecutionModelAnyHitKHR:
				return "AnyHit";
			case spv::ExecutionModelClosestHitKHR:
				return "ClosestHit";
			case spv::ExecutionModelMissKHR:
				return "Miss";
			case spv::ExecutionModelCallableKHR:
				return "Callable";
			default:
				AST_Failure( "Unsupported ExecutionModel" );
				return "Undefined";
			}
		}

		static std::string getName( spv::ExecutionMode value )
		{
			switch ( value )
			{
			case spv::ExecutionModeInvocations:
				return "Invocations";
			case spv::ExecutionModeSpacingEqual:
				return "SpacingEqual";
			case spv::ExecutionModeSpacingFractionalEven:
				return "SpacingFractionalEven";
			case spv::ExecutionModeSpacingFractionalOdd:
				return "SpacingFractionalOdd";
			case spv::ExecutionModeVertexOrderCw:
				return "VertexOrderCw";
			case spv::ExecutionModeVertexOrderCcw:
				return "VertexOrderCcw";
			case spv::ExecutionModePixelCenterInteger:
				return "PixelCenterInteger";
			case spv::ExecutionModeOriginUpperLeft:
				return "OriginUpperLeft";
			case spv::ExecutionModeOriginLowerLeft:
				return "OriginLowerLeft";
			case spv::ExecutionModeEarlyFragmentTests:
				return "EarlyFragmentTests";
			case spv::ExecutionModePointMode:
				return "PointMode";
			case spv::ExecutionModeXfb:
				return "Xfb";
			case spv::ExecutionModeDepthReplacing:
				return "DepthReplacing";
			case spv::ExecutionModeDepthGreater:
				return "DepthGreater";
			case spv::ExecutionModeDepthLess:
				return "DepthLess";
			case spv::ExecutionModeDepthUnchanged:
				return "DepthUnchanged";
			case spv::ExecutionModeLocalSize:
				return "LocalSize";
			case spv::ExecutionModeLocalSizeHint:
				return "LocalSizeHint";
			case spv::ExecutionModeInputPoints:
				return "InputPoints";
			case spv::ExecutionModeInputLines:
				return "InputLines";
			case spv::ExecutionModeInputLinesAdjacency:
				return "InputLinesAdjacency";
			case spv::ExecutionModeTriangles:
				return "Triangles";
			case spv::ExecutionModeInputTrianglesAdjacency:
				return "InputTrianglesAdjacency";
			case spv::ExecutionModeQuads:
				return "Quads";
			case spv::ExecutionModeIsolines:
				return "Isolines";
			case spv::ExecutionModeOutputVertices:
				return "OutputVertices";
			case spv::ExecutionModeOutputPoints:
				return "OutputPoints";
			case spv::ExecutionModeOutputLineStrip:
				return "OutputLineStrip";
			case spv::ExecutionModeOutputTriangleStrip:
				return "OutputTriangleStrip";
			case spv::ExecutionModeVecTypeHint:
				return "VecTypeHint";
			case spv::ExecutionModeContractionOff:
				return "ContractionOff";
			case spv::ExecutionModeInitializer:
				return "Initializer";
			case spv::ExecutionModeFinalizer:
				return "Finalizer";
			case spv::ExecutionModeSubgroupSize:
				return "SubgroupSize";
			case spv::ExecutionModeSubgroupsPerWorkgroup:
				return "SubgroupsPerWorkgroup";
			case spv::ExecutionModeSubgroupsPerWorkgroupId:
				return "SubgroupsPerWorkgroupId";
			case spv::ExecutionModeLocalSizeId:
				return "LocalSizeId";
			case spv::ExecutionModeLocalSizeHintId:
				return "LocalSizeHintId";
			case spv::ExecutionModeNonCoherentColorAttachmentReadEXT:
				return "NonCoherentColorAttachmentReadEXT";
			case spv::ExecutionModeNonCoherentDepthAttachmentReadEXT:
				return "NonCoherentDepthAttachmentReadEXT";
			case spv::ExecutionModeNonCoherentStencilAttachmentReadEXT:
				return "NonCoherentStencilAttachmentReadEXT";
			case spv::ExecutionModeSubgroupUniformControlFlowKHR:
				return "SubgroupUniformControlFlowKHR";
			case spv::ExecutionModePostDepthCoverage:
				return "PostDepthCoverage";
			case spv::ExecutionModeDenormPreserve:
				return "DenormPreserve";
			case spv::ExecutionModeDenormFlushToZero:
				return "DenormFlushToZero";
			case spv::ExecutionModeSignedZeroInfNanPreserve:
				return "SignedZeroInfNanPreserve";
			case spv::ExecutionModeRoundingModeRTE:
				return "RoundingModeRTE";
			case spv::ExecutionModeRoundingModeRTZ:
				return "RoundingModeRTZ";
			case spv::ExecutionModeEarlyAndLateFragmentTestsAMD:
				return "EarlyAndLateFragmentTestsAMD";
			case spv::ExecutionModeStencilRefReplacingEXT:
				return "StencilRefReplacingEXT";
			case spv::ExecutionModeCoalescingAMDX:
				return "CoalescingAMDX";
			case spv::ExecutionModeMaxNodeRecursionAMDX:
				return "MaxNodeRecursionAMDX";
			case spv::ExecutionModeStaticNumWorkgroupsAMDX:
				return "StaticNumWorkgroupsAMDX";
			case spv::ExecutionModeShaderIndexAMDX:
				return "ShaderIndexAMDX";
			case spv::ExecutionModeMaxNumWorkgroupsAMDX:
				return "MaxNumWorkgroupsAMDX";
			case spv::ExecutionModeStencilRefUnchangedFrontAMD:
				return "StencilRefUnchangedFrontAMD";
			case spv::ExecutionModeStencilRefGreaterFrontAMD:
				return "StencilRefGreaterFrontAMD";
			case spv::ExecutionModeStencilRefLessFrontAMD:
				return "StencilRefLessFrontAMD";
			case spv::ExecutionModeStencilRefUnchangedBackAMD:
				return "StencilRefUnchangedBackAMD";
			case spv::ExecutionModeStencilRefGreaterBackAMD:
				return "StencilRefGreaterBackAMD";
			case spv::ExecutionModeStencilRefLessBackAMD:
				return "StencilRefLessBackAMD";
			case spv::ExecutionModeQuadDerivativesKHR:
				return "QuadDerivativesKHR";
			case spv::ExecutionModeRequireFullQuadsKHR:
				return "RequireFullQuadsKHR";
			case spv::ExecutionModeOutputLinesEXT:
				return "OutputLinesEXT";
			case spv::ExecutionModeOutputPrimitivesEXT:
				return "OutputPrimitivesEXT";
			case spv::ExecutionModeDerivativeGroupQuadsNV:
				return "DerivativeGroupQuadsNV";
			case spv::ExecutionModeDerivativeGroupLinearNV:
				return "DerivativeGroupLinearNV";
			case spv::ExecutionModeOutputTrianglesEXT:
				return "OutputTrianglesEXT";
			case spv::ExecutionModePixelInterlockOrderedEXT:
				return "PixelInterlockOrderedEXT";
			case spv::ExecutionModePixelInterlockUnorderedEXT:
				return "PixelInterlockUnorderedEXT";
			case spv::ExecutionModeSampleInterlockOrderedEXT:
				return "SampleInterlockOrderedEXT";
			case spv::ExecutionModeSampleInterlockUnorderedEXT:
				return "SampleInterlockUnorderedEXT";
			case spv::ExecutionModeShadingRateInterlockOrderedEXT:
				return "ShadingRateInterlockOrderedEXT";
			case spv::ExecutionModeShadingRateInterlockUnorderedEXT:
				return "ShadingRateInterlockUnorderedEXT";
			case spv::ExecutionModeSharedLocalMemorySizeINTEL:
				return "SharedLocalMemorySizeINTEL";
			case spv::ExecutionModeRoundingModeRTPINTEL:
				return "RoundingModeRTPINTEL";
			case spv::ExecutionModeRoundingModeRTNINTEL:
				return "RoundingModeRTNINTEL";
			case spv::ExecutionModeFloatingPointModeALTINTEL:
				return "FloatingPointModeALTINTEL";
			case spv::ExecutionModeFloatingPointModeIEEEINTEL:
				return "FloatingPointModeIEEEINTEL";
			case spv::ExecutionModeMaxWorkgroupSizeINTEL:
				return "MaxWorkgroupSizeINTEL";
			case spv::ExecutionModeMaxWorkDimINTEL:
				return "MaxWorkDimINTEL";
			case spv::ExecutionModeNoGlobalOffsetINTEL:
				return "NoGlobalOffsetINTEL";
			case spv::ExecutionModeNumSIMDWorkitemsINTEL:
				return "NumSIMDWorkitemsINTEL";
			case spv::ExecutionModeSchedulerTargetFmaxMhzINTEL:
				return "SchedulerTargetFmaxMhzINTEL";
			case spv::ExecutionModeMaximallyReconvergesKHR:
				return "MaximallyReconvergesKHR";
			case spv::ExecutionModeFPFastMathDefault:
				return "FPFastMathDefault";
			case spv::ExecutionModeStreamingInterfaceINTEL:
				return "StreamingInterfaceINTEL";
			case spv::ExecutionModeRegisterMapInterfaceINTEL:
				return "RegisterMapInterfaceINTEL";
			case spv::ExecutionModeNamedBarrierCountINTEL:
				return "NamedBarrierCountINTEL";
			default:
				AST_Failure( "Unsupported ExecutionMode" );
				return "Undefined";
			}
		}

		static std::string getName( spv::AccessQualifier value )
		{
			switch ( value )
			{
			case spv::AccessQualifierReadOnly:
				return "ReadOnly";
			case spv::AccessQualifierWriteOnly:
				return "WriteOnly";
			case spv::AccessQualifierReadWrite:
				return "ReadWrite";
			default:
				AST_Failure( "Unsupported AccessQualifier" );
				return "Undefined";
			}
		}

		static std::string getName( spv::GLSLstd450 value )
		{
			switch ( value )
			{
			case spv::GLSLstd450::Bad:
				return "Bad";
			case spv::GLSLstd450::Round:
				return "Round";
			case spv::GLSLstd450::RoundEven:
				return "RoundEven";
			case spv::GLSLstd450::Trunc:
				return "Trunc";
			case spv::GLSLstd450::FAbs:
				return "FAbs";
			case spv::GLSLstd450::SAbs:
				return "SAbs";
			case spv::GLSLstd450::FSign:
				return "FSign";
			case spv::GLSLstd450::SSign:
				return "SSign";
			case spv::GLSLstd450::Floor:
				return "Floor";
			case spv::GLSLstd450::Ceil:
				return "Ceil";
			case spv::GLSLstd450::Fract:
				return "Fract";
			case spv::GLSLstd450::Radians:
				return "Radians";
			case spv::GLSLstd450::Degrees:
				return "Degrees";
			case spv::GLSLstd450::Sin:
				return "Sin";
			case spv::GLSLstd450::Cos:
				return "Cos";
			case spv::GLSLstd450::Tan:
				return "Tan";
			case spv::GLSLstd450::Asin:
				return "Asin";
			case spv::GLSLstd450::Acos:
				return "Acos";
			case spv::GLSLstd450::Atan:
				return "Atan";
			case spv::GLSLstd450::Sinh:
				return "Sinh";
			case spv::GLSLstd450::Cosh:
				return "Cosh";
			case spv::GLSLstd450::Tanh:
				return "Tanh";
			case spv::GLSLstd450::Asinh:
				return "Asinh";
			case spv::GLSLstd450::Acosh:
				return "Acosh";
			case spv::GLSLstd450::Atanh:
				return "Atanh";
			case spv::GLSLstd450::Atan2:
				return "Atan2";
			case spv::GLSLstd450::Pow:
				return "Pow";
			case spv::GLSLstd450::Exp:
				return "Exp";
			case spv::GLSLstd450::Log:
				return "Log";
			case spv::GLSLstd450::Exp2:
				return "Exp2";
			case spv::GLSLstd450::Log2:
				return "Log2";
			case spv::GLSLstd450::Sqrt:
				return "Sqrt";
			case spv::GLSLstd450::InverseSqrt:
				return "InverseSqrt";
			case spv::GLSLstd450::Determinant:
				return "Determinant";
			case spv::GLSLstd450::MatrixInverse:
				return "MatrixInverse";
			case spv::GLSLstd450::Modf:
				return "Modf";
			case spv::GLSLstd450::ModfStruct:
				return "ModfStruct";
			case spv::GLSLstd450::FMin:
				return "FMin";
			case spv::GLSLstd450::UMin:
				return "UMin";
			case spv::GLSLstd450::SMin:
				return "SMin";
			case spv::GLSLstd450::FMax:
				return "FMax";
			case spv::GLSLstd450::UMax:
				return "UMax";
			case spv::GLSLstd450::SMax:
				return "SMax";
			case spv::GLSLstd450::FClamp:
				return "FClamp";
			case spv::GLSLstd450::UClamp:
				return "UClamp";
			case spv::GLSLstd450::SClamp:
				return "SClamp";
			case spv::GLSLstd450::FMix:
				return "FMix";
			case spv::GLSLstd450::IMix:
				return "IMix";
			case spv::GLSLstd450::Step:
				return "Step";
			case spv::GLSLstd450::SmoothStep:
				return "SmoothStep";
			case spv::GLSLstd450::Fma:
				return "Fma";
			case spv::GLSLstd450::Frexp:
				return "Frexp";
			case spv::GLSLstd450::FrexpStruct:
				return "FrexpStruct";
			case spv::GLSLstd450::Ldexp:
				return "Ldexp";
			case spv::GLSLstd450::PackSnorm4x8:
				return "PackSnorm4x8";
			case spv::GLSLstd450::PackUnorm4x8:
				return "PackUnorm4x8";
			case spv::GLSLstd450::PackSnorm2x16:
				return "PackSnorm2x16";
			case spv::GLSLstd450::PackUnorm2x16:
				return "PackUnorm2x16";
			case spv::GLSLstd450::PackHalf2x16:
				return "PackHalf2x16";
			case spv::GLSLstd450::PackDouble2x32:
				return "PackDouble2x32";
			case spv::GLSLstd450::UnpackSnorm2x16:
				return "UnpackSnorm2x16";
			case spv::GLSLstd450::UnpackUnorm2x16:
				return "UnpackUnorm2x16";
			case spv::GLSLstd450::UnpackHalf2x16:
				return "UnpackHalf2x16";
			case spv::GLSLstd450::UnpackSnorm4x8:
				return "UnpackSnorm4x8";
			case spv::GLSLstd450::UnpackUnorm4x8:
				return "UnpackUnorm4x8";
			case spv::GLSLstd450::UnpackDouble2x32:
				return "UnpackDouble2x32";
			case spv::GLSLstd450::Length:
				return "Length";
			case spv::GLSLstd450::Distance:
				return "Distance";
			case spv::GLSLstd450::Cross:
				return "Cross";
			case spv::GLSLstd450::Normalize:
				return "Normalize";
			case spv::GLSLstd450::FaceForward:
				return "FaceForward";
			case spv::GLSLstd450::Reflect:
				return "Reflect";
			case spv::GLSLstd450::Refract:
				return "Refract";
			case spv::GLSLstd450::FindILsb:
				return "FindILsb";
			case spv::GLSLstd450::FindSMsb:
				return "FindSMsb";
			case spv::GLSLstd450::FindUMsb:
				return "FindUMsb";
			case spv::GLSLstd450::InterpolateAtCentroid:
				return "InterpolateAtCentroid";
			case spv::GLSLstd450::InterpolateAtSample:
				return "InterpolateAtSample";
			case spv::GLSLstd450::InterpolateAtOffset:
				return "InterpolateAtOffset";
			case spv::GLSLstd450::NMin:
				return "NMin";
			case spv::GLSLstd450::NMax:
				return "NMax";
			case spv::GLSLstd450::NClamp:
				return "NClamp";
			case spv::GLSLstd450::Count:
				return "Count";
			default:
				AST_Failure( "Unsupported GLSLstd450" );
				return "Undefined";
			}
		}

		static std::string getName( spv::NonSemanticShaderDebugInfo100Instructions value )
		{
			switch ( value )
			{
			case spv::NonSemanticShaderDebugInfo100Instructions::InfoNone:
				return "DebugInfoNone";
			case spv::NonSemanticShaderDebugInfo100Instructions::CompilationUnit:
				return "DebugCompilationUnit";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeBasic:
				return "DebugTypeBasic";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypePointer:
				return "DebugTypePointer";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeQualifier:
				return "DebugTypeQualifier";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeArray:
				return "DebugTypeArray";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeVector:
				return "DebugTypeVector";
			case spv::NonSemanticShaderDebugInfo100Instructions::Typedef:
				return "DebugTypedef";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeFunction:
				return "DebugTypeFunction";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeEnum:
				return "DebugTypeEnum";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeComposite:
				return "DebugTypeComposite";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeMember:
				return "DebugTypeMember";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeInheritance:
				return "DebugTypeInheritance";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypePtrToMember:
				return "DebugTypePtrToMember";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeTemplate:
				return "DebugTypeTemplate";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeTemplateParameter:
				return "DebugTypeTemplateParameter";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeTemplateTemplateParameter:
				return "DebugTypeTemplateTemplateParameter";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeTemplateParameterPack:
				return "DebugTypeTemplateParameterPack";
			case spv::NonSemanticShaderDebugInfo100Instructions::GlobalVariable:
				return "DebugGlobalVariable";
			case spv::NonSemanticShaderDebugInfo100Instructions::FunctionDeclaration:
				return "DebugFunctionDeclaration";
			case spv::NonSemanticShaderDebugInfo100Instructions::Function:
				return "DebugFunction";
			case spv::NonSemanticShaderDebugInfo100Instructions::LexicalBlock:
				return "DebugLexicalBlock";
			case spv::NonSemanticShaderDebugInfo100Instructions::LexicalBlockDiscriminator:
				return "DebugLexicalBlockDiscriminator";
			case spv::NonSemanticShaderDebugInfo100Instructions::Scope:
				return "DebugScope";
			case spv::NonSemanticShaderDebugInfo100Instructions::NoScope:
				return "DebugNoScope";
			case spv::NonSemanticShaderDebugInfo100Instructions::InlinedAt:
				return "DebugInlinedAt";
			case spv::NonSemanticShaderDebugInfo100Instructions::LocalVariable:
				return "DebugLocalVariable";
			case spv::NonSemanticShaderDebugInfo100Instructions::InlinedVariable:
				return "DebugInlinedVariable";
			case spv::NonSemanticShaderDebugInfo100Instructions::Declare:
				return "DebugDeclare";
			case spv::NonSemanticShaderDebugInfo100Instructions::Value:
				return "DebugValue";
			case spv::NonSemanticShaderDebugInfo100Instructions::Operation:
				return "DebugOperation";
			case spv::NonSemanticShaderDebugInfo100Instructions::Expression:
				return "DebugExpression";
			case spv::NonSemanticShaderDebugInfo100Instructions::MacroDef:
				return "DebugMacroDef";
			case spv::NonSemanticShaderDebugInfo100Instructions::MacroUndef:
				return "DebugMacroUndef";
			case spv::NonSemanticShaderDebugInfo100Instructions::ImportedEntity:
				return "DebugImportedEntity";
			case spv::NonSemanticShaderDebugInfo100Instructions::Source:
				return "DebugSource";
			case spv::NonSemanticShaderDebugInfo100Instructions::FunctionDefinition:
				return "DebugFunctionDefinition";
			case spv::NonSemanticShaderDebugInfo100Instructions::SourceContinued:
				return "DebugSourceContinued";
			case spv::NonSemanticShaderDebugInfo100Instructions::Line:
				return "DebugLine";
			case spv::NonSemanticShaderDebugInfo100Instructions::NoLine:
				return "DebugNoLine";
			case spv::NonSemanticShaderDebugInfo100Instructions::BuildIdentifier:
				return "DebugBuildIdentifier";
			case spv::NonSemanticShaderDebugInfo100Instructions::StoragePath:
				return "DebugStoragePath";
			case spv::NonSemanticShaderDebugInfo100Instructions::EntryPoint:
				return "DebugEntryPoint";
			case spv::NonSemanticShaderDebugInfo100Instructions::TypeMatrix:
				return "DebugTypeMatrix";
			default:
				AST_Failure( "Unsupported OpDebug" );
				return "Undefined";
			}
		}

		static std::string getName( spv::StorageClass value )
		{
			switch ( value )
			{
			case spv::StorageClassUniformConstant:
				return "UniformConstant";
			case spv::StorageClassInput:
				return "Input";
			case spv::StorageClassUniform:
				return "Uniform";
			case spv::StorageClassOutput:
				return "Output";
			case spv::StorageClassWorkgroup:
				return "Workgroup";
			case spv::StorageClassCrossWorkgroup:
				return "CrossWorkgroup";
			case spv::StorageClassPrivate:
				return "Private";
			case spv::StorageClassFunction:
				return "Function";
			case spv::StorageClassGeneric:
				return "Generic";
			case spv::StorageClassPushConstant:
				return "PushConstant";
			case spv::StorageClassAtomicCounter:
				return "AtomicCounter";
			case spv::StorageClassImage:
				return "Image";
			case spv::StorageClassStorageBuffer:
				return "StorageBuffer";
			case spv::StorageClassCallableDataKHR:
				return "CallableData";
			case spv::StorageClassIncomingCallableDataKHR:
				return "IncomingCallableData";
			case spv::StorageClassRayPayloadKHR:
				return "RayPayload";
			case spv::StorageClassHitAttributeKHR:
				return "HitAttribute";
			case spv::StorageClassIncomingRayPayloadKHR:
				return "IncomingRayPayload";
			case spv::StorageClassShaderRecordBufferKHR:
				return "ShaderRecordBuffer";
			case spv::StorageClassPhysicalStorageBuffer:
				return "PhysicalStorageBuffer";
			case spv::StorageClassTaskPayloadWorkgroupEXT:
				return "TaskPayloadWorkgroupEXT";
			case spv::StorageClassCodeSectionINTEL:
				return "CodeSectionINTEL";
			case spv::StorageClassDeviceOnlyINTEL:
				return "DeviceOnlyINTEL";
			case spv::StorageClassHostOnlyINTEL:
				return "HostOnlyINTEL";
			default:
				AST_Failure( "Unsupported StorageClass" );
				return "Undefined";
			}
		}

		static std::string getName( spv::ImageFormat value )
		{
			switch ( value )
			{
			case spv::ImageFormatUnknown:
				return "Unknown";
			case spv::ImageFormatRgba32f:
				return "Rgba32f";
			case spv::ImageFormatRgba16f:
				return "Rgba16f";
			case spv::ImageFormatR32f:
				return "R32f";
			case spv::ImageFormatRgba8:
				return "Rgba8";
			case spv::ImageFormatRgba8Snorm:
				return "Rgba8Snorm";
			case spv::ImageFormatRg32f:
				return "Rg32f";
			case spv::ImageFormatRg16f:
				return "Rg16f";
			case spv::ImageFormatR11fG11fB10f:
				return "R11fG11fB10f";
			case spv::ImageFormatR16f:
				return "R16f";
			case spv::ImageFormatRgba16:
				return "Rgba16";
			case spv::ImageFormatRgb10A2:
				return "Rgb10A2";
			case spv::ImageFormatRg16:
				return "Rg16";
			case spv::ImageFormatRg8:
				return "Rg8";
			case spv::ImageFormatR16:
				return "R16";
			case spv::ImageFormatR8:
				return "R8";
			case spv::ImageFormatRgba16Snorm:
				return "Rgba16Snorm";
			case spv::ImageFormatRg16Snorm:
				return "Rg16Snorm";
			case spv::ImageFormatRg8Snorm:
				return "Rg8Snorm";
			case spv::ImageFormatR16Snorm:
				return "R16Snorm";
			case spv::ImageFormatR8Snorm:
				return "R8Snorm";
			case spv::ImageFormatRgba32i:
				return "Rgba32i";
			case spv::ImageFormatRgba16i:
				return "Rgba16i";
			case spv::ImageFormatRgba8i:
				return "Rgba8i";
			case spv::ImageFormatR32i:
				return "R32i";
			case spv::ImageFormatRg32i:
				return "Rg32i";
			case spv::ImageFormatRg16i:
				return "Rg16i";
			case spv::ImageFormatRg8i:
				return "Rg8i";
			case spv::ImageFormatR16i:
				return "R16i";
			case spv::ImageFormatR8i:
				return "R8i";
			case spv::ImageFormatRgba32ui:
				return "Rgba32ui";
			case spv::ImageFormatRgba16ui:
				return "Rgba16ui";
			case spv::ImageFormatRgba8ui:
				return "Rgba8ui";
			case spv::ImageFormatR32ui:
				return "R32ui";
			case spv::ImageFormatRgb10a2ui:
				return "Rgb10a2ui";
			case spv::ImageFormatRg32ui:
				return "Rg32ui";
			case spv::ImageFormatRg16ui:
				return "Rg16ui";
			case spv::ImageFormatRg8ui:
				return "Rg8ui";
			case spv::ImageFormatR16ui:
				return "R16ui";
			case spv::ImageFormatR8ui:
				return "R8ui";
			default:
				AST_Failure( "Unsupported ImageFormat" );
				return "Undefined";
			}
		}

		static std::string getName( spv::Dim value )
		{
			switch ( value )
			{
			case spv::Dim1D:
				return "Dim1D";
			case spv::Dim2D:
				return "Dim2D";
			case spv::Dim3D:
				return "Dim3D";
			case spv::DimCube:
				return "Cube";
			case spv::DimRect:
				return "Rect";
			case spv::DimBuffer:
				return "Buffer";
			case spv::DimSubpassData:
				return "SubpassData";
			default:
				AST_Failure( "Unsupported Dim" );
				return "Undefined";
			}
		}

		static std::string getName( spv::BuiltIn value )
		{
			switch ( value )
			{
			case spv::BuiltInPosition:
				return "Position";
			case spv::BuiltInPointSize:
				return "PointSize";
			case spv::BuiltInClipDistance:
				return "ClipDistance";
			case spv::BuiltInCullDistance:
				return "CullDistance";
			case spv::BuiltInVertexId:
				return "VertexId";
			case spv::BuiltInInstanceId:
				return "InstanceId";
			case spv::BuiltInPrimitiveId:
				return "PrimitiveId";
			case spv::BuiltInInvocationId:
				return "InvocationId";
			case spv::BuiltInLayer:
				return "Layer";
			case spv::BuiltInViewportIndex:
				return "ViewportIndex";
			case spv::BuiltInTessLevelOuter:
				return "TessLevelOuter";
			case spv::BuiltInTessLevelInner:
				return "TessLevelInner";
			case spv::BuiltInTessCoord:
				return "TessCoord";
			case spv::BuiltInPatchVertices:
				return "PatchVertices";
			case spv::BuiltInFragCoord:
				return "FragCoord";
			case spv::BuiltInPointCoord:
				return "PointCoord";
			case spv::BuiltInFrontFacing:
				return "FrontFacing";
			case spv::BuiltInSampleId:
				return "SampleId";
			case spv::BuiltInSamplePosition:
				return "SamplePosition";
			case spv::BuiltInSampleMask:
				return "SampleMask";
			case spv::BuiltInFragDepth:
				return "FragDepth";
			case spv::BuiltInHelperInvocation:
				return "HelperInvocation";
			case spv::BuiltInNumWorkgroups:
				return "NumWorkgroups";
			case spv::BuiltInWorkgroupSize:
				return "WorkgroupSize";
			case spv::BuiltInWorkgroupId:
				return "WorkgroupId";
			case spv::BuiltInLocalInvocationId:
				return "LocalInvocationId";
			case spv::BuiltInGlobalInvocationId:
				return "GlobalInvocationId";
			case spv::BuiltInLocalInvocationIndex:
				return "LocalInvocationIndex";
			case spv::BuiltInWorkDim:
				return "WorkDim";
			case spv::BuiltInGlobalSize:
				return "GlobalSize";
			case spv::BuiltInEnqueuedWorkgroupSize:
				return "EnqueuedWorkgroupSize";
			case spv::BuiltInGlobalOffset:
				return "GlobalOffset";
			case spv::BuiltInGlobalLinearId:
				return "GlobalLinearId";
			case spv::BuiltInSubgroupSize:
				return "SubgroupSize";
			case spv::BuiltInSubgroupMaxSize:
				return "SubgroupMaxSize";
			case spv::BuiltInNumSubgroups:
				return "NumSubgroups";
			case spv::BuiltInNumEnqueuedSubgroups:
				return "NumEnqueuedSubgroups";
			case spv::BuiltInSubgroupId:
				return "SubgroupId";
			case spv::BuiltInSubgroupLocalInvocationId:
				return "SubgroupLocalInvocationId";
			case spv::BuiltInVertexIndex:
				return "VertexIndex";
			case spv::BuiltInInstanceIndex:
				return "InstanceIndex";
			case spv::BuiltInSubgroupEqMaskKHR:
				return "SubgroupEqMaskKHR";
			case spv::BuiltInSubgroupGeMaskKHR:
				return "SubgroupGeMaskKHR";
			case spv::BuiltInSubgroupGtMaskKHR:
				return "SubgroupGtMaskKHR";
			case spv::BuiltInSubgroupLeMaskKHR:
				return "SubgroupLeMaskKHR";
			case spv::BuiltInSubgroupLtMaskKHR:
				return "SubgroupLtMaskKHR";
			case spv::BuiltInBaseVertex:
				return "BaseVertex";
			case spv::BuiltInBaseInstance:
				return "BaseInstance";
			case spv::BuiltInDrawIndex:
				return "DrawIndex";
			case spv::BuiltInDeviceIndex:
				return "DeviceIndex";
			case spv::BuiltInViewIndex:
				return "ViewIndex";
			case spv::BuiltInBaryCoordNoPerspAMD:
				return "BaryCoordNoPerspAMD";
			case spv::BuiltInBaryCoordNoPerspCentroidAMD:
				return "BaryCoordNoPerspCentroidAMD";
			case spv::BuiltInBaryCoordNoPerspSampleAMD:
				return "BaryCoordNoPerspSampleAMD";
			case spv::BuiltInBaryCoordSmoothAMD:
				return "BaryCoordSmoothAMD";
			case spv::BuiltInBaryCoordSmoothCentroidAMD:
				return "BaryCoordSmoothCentroidAMD";
			case spv::BuiltInBaryCoordSmoothSampleAMD:
				return "BaryCoordSmoothSampleAMD";
			case spv::BuiltInBaryCoordPullModelAMD:
				return "BaryCoordPullModelAMD";
			case spv::BuiltInFragStencilRefEXT:
				return "FragStencilRefEXT";
			case spv::BuiltInViewportMaskNV:
				return "ViewportMaskNV";
			case spv::BuiltInSecondaryPositionNV:
				return "SecondaryPositionNV";
			case spv::BuiltInSecondaryViewportMaskNV:
				return "SecondaryViewportMaskNV";
			case spv::BuiltInPositionPerViewNV:
				return "PositionPerViewNV";
			case spv::BuiltInViewportMaskPerViewNV:
				return "ViewportMaskPerViewNV";
			case spv::BuiltInFullyCoveredEXT:
				return "FullyCoveredEXT";
			case spv::BuiltInTaskCountNV:
				return "TaskCountNV";
			case spv::BuiltInPrimitiveCountNV:
				return "PrimitiveCountNV";
			case spv::BuiltInPrimitiveIndicesNV:
				return "PrimitiveIndicesNV";
			case spv::BuiltInClipDistancePerViewNV:
				return "ClipDistancePerViewNV";
			case spv::BuiltInCullDistancePerViewNV:
				return "CullDistancePerViewNV";
			case spv::BuiltInLayerPerViewNV:
				return "LayerPerViewNV";
			case spv::BuiltInMeshViewCountNV:
				return "MeshViewCountNV";
			case spv::BuiltInMeshViewIndicesNV:
				return "MeshViewIndicesNV";
			case spv::BuiltInBaryCoordNV:
				return "BaryCoordNV";
			case spv::BuiltInBaryCoordNoPerspNV:
				return "BaryCoordNoPerspNV";
			case spv::BuiltInFragSizeEXT:
				return "FragSizeEXT";
			case spv::BuiltInFragInvocationCountEXT:
				return "FragInvocationCountEXT";
			case spv::BuiltInLaunchIdKHR:
				return "LaunchId";
			case spv::BuiltInLaunchSizeKHR:
				return "LaunchSize";
			case spv::BuiltInWorldRayOriginKHR:
				return "WorldRayOrigin";
			case spv::BuiltInWorldRayDirectionKHR:
				return "WorldRayDirection";
			case spv::BuiltInObjectRayOriginKHR:
				return "ObjectRayOrigin";
			case spv::BuiltInObjectRayDirectionKHR:
				return "ObjectRayDirection";
			case spv::BuiltInRayTminKHR:
				return "RayTmin";
			case spv::BuiltInRayTmaxKHR:
				return "RayTmax";
			case spv::BuiltInInstanceCustomIndexKHR:
				return "InstanceCustomIndex";
			case spv::BuiltInObjectToWorldKHR:
				return "ObjectToWorld";
			case spv::BuiltInWorldToObjectKHR:
				return "WorldToObject";
			case spv::BuiltInHitKindKHR:
				return "HitKind";
			case spv::BuiltInIncomingRayFlagsKHR:
				return "IncomingRayFlags";
			case spv::BuiltInRayGeometryIndexKHR:
				return "RayGeometryIndexKHR";
			case spv::BuiltInWarpsPerSMNV:
				return "WarpsPerSMNV";
			case spv::BuiltInSMCountNV:
				return "SMCountNV";
			case spv::BuiltInWarpIDNV:
				return "WarpIDNV";
			case spv::BuiltInSMIDNV:
				return "SMIDNV";
			case spv::BuiltInPrimitiveLineIndicesEXT:
				return "PrimitiveLineIndicesEXT";
			case spv::BuiltInPrimitiveTriangleIndicesEXT:
				return "PrimitiveTriangleIndicesEXT";
			case spv::BuiltInCullPrimitiveEXT:
				return "CullPrimitiveEXT";
			default:
				AST_Failure( "Unsupported BuiltIn" );
				return "Undefined";
			}
		}

		static std::string getName( spv::Decoration value )
		{
			switch ( value )
			{
			case spv::DecorationRelaxedPrecision:
				return "RelaxedPrecision";
			case spv::DecorationSpecId:
				return "SpecId";
			case spv::DecorationBlock:
				return "Block";
			case spv::DecorationBufferBlock:
				return "BufferBlock";
			case spv::DecorationRowMajor:
				return "RowMajor";
			case spv::DecorationColMajor:
				return "ColMajor";
			case spv::DecorationArrayStride:
				return "ArrayStride";
			case spv::DecorationMatrixStride:
				return "MatrixStride";
			case spv::DecorationGLSLShared:
				return "GLSLShared";
			case spv::DecorationGLSLPacked:
				return "GLSLPacked";
			case spv::DecorationCPacked:
				return "CPacked";
			case spv::DecorationBuiltIn:
				return "BuiltIn";
			case spv::DecorationNoPerspective:
				return "NoPerspective";
			case spv::DecorationFlat:
				return "Flat";
			case spv::DecorationPatch:
				return "Patch";
			case spv::DecorationCentroid:
				return "Centroid";
			case spv::DecorationSample:
				return "Sample";
			case spv::DecorationInvariant:
				return "Invariant";
			case spv::DecorationRestrict:
				return "Restrict";
			case spv::DecorationAliased:
				return "Aliased";
			case spv::DecorationVolatile:
				return "Volatile";
			case spv::DecorationConstant:
				return "Constant";
			case spv::DecorationCoherent:
				return "Coherent";
			case spv::DecorationNonWritable:
				return "NonWritable";
			case spv::DecorationNonReadable:
				return "NonReadable";
			case spv::DecorationUniform:
				return "Uniform";
			case spv::DecorationUniformId:
				return "UniformId";
			case spv::DecorationSaturatedConversion:
				return "SaturatedConversion";
			case spv::DecorationStream:
				return "Stream";
			case spv::DecorationLocation:
				return "Location";
			case spv::DecorationComponent:
				return "Component";
			case spv::DecorationIndex:
				return "Index";
			case spv::DecorationBinding:
				return "Binding";
			case spv::DecorationDescriptorSet:
				return "DescriptorSet";
			case spv::DecorationOffset:
				return "Offset";
			case spv::DecorationXfbBuffer:
				return "XfbBuffer";
			case spv::DecorationXfbStride:
				return "XfbStride";
			case spv::DecorationFuncParamAttr:
				return "FuncParamAttr";
			case spv::DecorationFPRoundingMode:
				return "FPRoundingMode";
			case spv::DecorationFPFastMathMode:
				return "FPFastMathMode";
			case spv::DecorationLinkageAttributes:
				return "LinkageAttributes";
			case spv::DecorationNoContraction:
				return "NoContraction";
			case spv::DecorationInputAttachmentIndex:
				return "InputAttachmentIndex";
			case spv::DecorationAlignment:
				return "Alignment";
			case spv::DecorationMaxByteOffset:
				return "MaxByteOffset";
			case spv::DecorationAlignmentId:
				return "AlignmentId";
			case spv::DecorationMaxByteOffsetId:
				return "MaxByteOffsetId";
			case spv::DecorationNoSignedWrap:
				return "NoSignedWrap";
			case spv::DecorationNoUnsignedWrap:
				return "NoUnsignedWrap";
			case spv::DecorationExplicitInterpAMD:
				return "ExplicitInterpAMD";
			case spv::DecorationOverrideCoverageNV:
				return "OverrideCoverageNV";
			case spv::DecorationPassthroughNV:
				return "PassthroughNV";
			case spv::DecorationViewportRelativeNV:
				return "ViewportRelativeNV";
			case spv::DecorationSecondaryViewportRelativeNV:
				return "SecondaryViewportRelativeNV";
			case spv::DecorationPerPrimitiveNV:
				return "PerPrimitiveNV";
			case spv::DecorationPerViewNV:
				return "PerViewNV";
			case spv::DecorationPerTaskNV:
				return "PerTaskNV";
			case spv::DecorationPerVertexKHR:
				return "PerVertexKHR";
			case spv::DecorationNonUniform:
				return "NonUniform";
			case spv::DecorationRestrictPointer:
				return "RestrictPointer";
			case spv::DecorationAliasedPointer:
				return "AliasedPointer";
			case spv::DecorationBindlessSamplerNV:
				return "BindlessSamplerNV";
			case spv::DecorationBindlessImageNV:
				return "BindlessImageNV";
			case spv::DecorationBoundSamplerNV:
				return "BoundSamplerNV";
			case spv::DecorationBoundImageNV:
				return "BoundImageNV";
			case spv::DecorationSIMTCallINTEL:
				return "SIMTCallINTEL";
			case spv::DecorationReferencedIndirectlyINTEL:
				return "ReferencedIndirectlyINTEL";
			case spv::DecorationClobberINTEL:
				return "ClobberINTEL";
			case spv::DecorationSideEffectsINTEL:
				return "SideEffectsINTEL";
			case spv::DecorationVectorComputeVariableINTEL:
				return "VectorComputeVariableINTEL";
			case spv::DecorationFuncParamIOKindINTEL:
				return "FuncParamIOKindINTEL";
			case spv::DecorationVectorComputeFunctionINTEL:
				return "VectorComputeFunctionINTEL";
			case spv::DecorationStackCallINTEL:
				return "StackCallINTEL";
			case spv::DecorationGlobalVariableOffsetINTEL:
				return "GlobalVariableOffsetINTEL";
			case spv::DecorationCounterBuffer:
				return "CounterBuffer";
			case spv::DecorationUserSemantic:
				return "UserSemantic";
			case spv::DecorationUserTypeGOOGLE:
				return "UserTypeGOOGLE";
			case spv::DecorationFunctionRoundingModeINTEL:
				return "FunctionRoundingModeINTEL";
			case spv::DecorationFunctionDenormModeINTEL:
				return "FunctionDenormModeINTEL";
			case spv::DecorationRegisterINTEL:
				return "RegisterINTEL";
			case spv::DecorationMemoryINTEL:
				return "MemoryINTEL";
			case spv::DecorationNumbanksINTEL:
				return "NumbanksINTEL";
			case spv::DecorationBankwidthINTEL:
				return "BankwidthINTEL";
			case spv::DecorationMaxPrivateCopiesINTEL:
				return "MaxPrivateCopiesINTEL";
			case spv::DecorationSinglepumpINTEL:
				return "SinglepumpINTEL";
			case spv::DecorationDoublepumpINTEL:
				return "DoublepumpINTEL";
			case spv::DecorationMaxReplicatesINTEL:
				return "MaxReplicatesINTEL";
			case spv::DecorationSimpleDualPortINTEL:
				return "SimpleDualPortINTEL";
			case spv::DecorationMergeINTEL:
				return "MergeINTEL";
			case spv::DecorationBankBitsINTEL:
				return "BankBitsINTEL";
			case spv::DecorationForcePow2DepthINTEL:
				return "ForcePow2DepthINTEL";
			case spv::DecorationBurstCoalesceINTEL:
				return "BurstCoalesceINTEL";
			case spv::DecorationCacheSizeINTEL:
				return "CacheSizeINTEL";
			case spv::DecorationDontStaticallyCoalesceINTEL:
				return "DontStaticallyCoalesceINTEL";
			case spv::DecorationPrefetchINTEL:
				return "PrefetchINTEL";
			case spv::DecorationStallEnableINTEL:
				return "StallEnableINTEL";
			case spv::DecorationFuseLoopsInFunctionINTEL:
				return "FuseLoopsInFunctionINTEL";
			case spv::DecorationBufferLocationINTEL:
				return "BufferLocationINTEL";
			case spv::DecorationIOPipeStorageINTEL:
				return "IOPipeStorageINTEL";
			case spv::DecorationFunctionFloatingPointModeINTEL:
				return "FunctionFloatingPointModeINTEL";
			case spv::DecorationSingleElementVectorINTEL:
				return "SingleElementVectorINTEL";
			case spv::DecorationVectorComputeCallableFunctionINTEL:
				return "VectorComputeCallableFunctionINTEL";
			case spv::DecorationMediaBlockIOINTEL:
				return "MediaBlockIOINTEL";
			default:
				AST_Failure( "Unsupported Decoration" );
				return "Undefined";
			}
		}

		static std::string getName( spv::FunctionParameterAttribute value )
		{
			switch ( value )
			{
			case spv::FunctionParameterAttributeZext:
				return "Zext";
			case spv::FunctionParameterAttributeSext:
				return "Sext";
			case spv::FunctionParameterAttributeByVal:
				return "ByVal";
			case spv::FunctionParameterAttributeSret:
				return "Sret";
			case spv::FunctionParameterAttributeNoAlias:
				return "NoAlias";
			case spv::FunctionParameterAttributeNoCapture:
				return "NoCapture";
			case spv::FunctionParameterAttributeNoWrite:
				return "NoWrite";
			case spv::FunctionParameterAttributeNoReadWrite:
				return "NoReadWrite";
			default:
				AST_Failure( "Unsupported FunctionParameterAttribute" );
				return "Undefined";
			}
		}

		static std::string getName( spv::FPRoundingMode value )
		{
			switch ( value )
			{
			case spv::FPRoundingModeRTE:
				return "RTE";
			case spv::FPRoundingModeRTZ:
				return "RTZ";
			case spv::FPRoundingModeRTP:
				return "RTP";
			case spv::FPRoundingModeRTN:
				return "RTN";
			default:
				AST_Failure( "Unsupported FPRoundingMode" );
				return "Undefined";
			}
		}

		static std::string getName( spv::LinkageType value )
		{
			switch ( value )
			{
			case spv::LinkageTypeExport:
				return "Export";
			case spv::LinkageTypeImport:
				return "Import";
			case spv::LinkageTypeLinkOnceODR:
				return "LinkOnceODR";
			default:
				AST_Failure( "Unsupported LinkageType" );
				return "Undefined";
			}
		}

		static std::string getName( spv::Scope value )
		{
			auto stream = getStream();

			switch ( value )
			{
			case spv::ScopeCrossDevice:
				return "CrossDevice";
			case spv::ScopeDevice:
				return "Device";
			case spv::ScopeWorkgroup:
				return "Workgroup";
			case spv::ScopeSubgroup:
				return "Subgroup";
			case spv::ScopeInvocation:
				return "Invocation";
			case spv::ScopeQueueFamily:
				return "QueueFamily";
			case spv::ScopeShaderCallKHR:
				return "ShaderCall";
			default:
				//AST_Failure( "Unsupported Scope" );
				return "Undefined";
			}
		}

		static std::string getSelectionControlName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::SelectionControlFlattenMask ) )
			{
				stream << sep << "Flatten";
				sep = "|";
			}

			if ( value & uint32_t( spv::SelectionControlDontFlattenMask ) )
			{
				stream << sep << "DontFlatten";
				sep = "|";
			}

			if ( value == uint32_t( spv::SelectionControlMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		static std::string getMemoryAccessName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::MemoryAccessAlignedMask ) )
			{
				stream << sep << "Aligned";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemoryAccessVolatileMask ) )
			{
				stream << sep << "Volatile";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemoryAccessNontemporalMask ) )
			{
				stream << sep << "Nontemporal";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemoryAccessMakePointerAvailableMask ) )
			{
				stream << sep << "MakePointerAvailableMask";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemoryAccessMakePointerVisibleMask ) )
			{
				stream << sep << "MakePointerVisibleMask";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemoryAccessNonPrivatePointerMask ) )
			{
				stream << sep << "NonPrivatePointerMask";
				sep = "|";
			}

			if ( value == uint32_t( spv::MemoryAccessMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		static std::string getLoopControlName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::LoopControlUnrollMask ) )
			{
				stream << sep << "Unroll";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlDontUnrollMask ) )
			{
				stream << sep << "DontUnroll";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlDependencyInfiniteMask ) )
			{
				stream << sep << "DependencyInfinite";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlDependencyLengthMask ) )
			{
				stream << sep << "DependencyLength";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlMinIterationsMask ) )
			{
				stream << sep << "MinIterations";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlMaxIterationsMask ) )
			{
				stream << sep << "MaxIterations";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlIterationMultipleMask ) )
			{
				stream << sep << "IterationMultiple";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlPeelCountMask ) )
			{
				stream << sep << "PeelCount";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlPartialCountMask ) )
			{
				stream << sep << "PartialCount";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlInitiationIntervalINTELMask ) )
			{
				stream << sep << "InitiationIntervalINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlMaxConcurrencyINTELMask ) )
			{
				stream << sep << "MaxConcurrencyINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlDependencyArrayINTELMask ) )
			{
				stream << sep << "DependencyArrayINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlPipelineEnableINTELMask ) )
			{
				stream << sep << "PipelineEnableINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlLoopCoalesceINTELMask ) )
			{
				stream << sep << "LoopCoalesceINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlMaxInterleavingINTELMask ) )
			{
				stream << sep << "MaxInterleavingINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlSpeculatedIterationsINTELMask ) )
			{
				stream << sep << "SpeculatedIterationsINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlNoFusionINTELMask ) )
			{
				stream << sep << "NoFusionINTEL";
				sep = "|";
			}

			if ( value == uint32_t( spv::LoopControlMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		static std::string getImageOperandsName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::ImageOperandsBiasMask ) )
			{
				stream << sep << "Bias";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsLodMask ) )
			{
				stream << sep << "Lod";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsGradMask ) )
			{
				stream << sep << "Grad";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsConstOffsetMask ) )
			{
				stream << sep << "ConstOffset";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsOffsetMask ) )
			{
				stream << sep << "Offset";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsConstOffsetsMask ) )
			{
				stream << sep << "ConstOffsets";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsSampleMask ) )
			{
				stream << sep << "Sample";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMinLodMask ) )
			{
				stream << sep << "MinLod";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMakeTexelAvailableMask ) )
			{
				stream << sep << "MakeTexelAvailable";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMakeTexelVisibleMask ) )
			{
				stream << sep << "MakeTexelVisible";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsNonPrivateTexelMask ) )
			{
				stream << sep << "NonPrivateTexel";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsVolatileTexelMask ) )
			{
				stream << sep << "VolatileTexel";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsSignExtendMask ) )
			{
				stream << sep << "SignExtend";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsZeroExtendMask ) )
			{
				stream << sep << "ZeroExtend";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsNontemporalMask ) )
			{
				stream << sep << "Nontemporal";
				sep = "|";
			}

			if ( value == uint32_t( spv::ImageOperandsMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		static std::string getMemorySemanticsName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::MemorySemanticsAcquireMask ) )
			{
				stream << sep << "Acquire";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsReleaseMask ) )
			{
				stream << sep << "Release";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsAcquireReleaseMask ) )
			{
				stream << sep << "AcquireRelease";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsSequentiallyConsistentMask ) )
			{
				stream << sep << "SequentiallyConsistent";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsUniformMemoryMask ) )
			{
				stream << sep << "UniformMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsSubgroupMemoryMask ) )
			{
				stream << sep << "SubgroupMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsWorkgroupMemoryMask ) )
			{
				stream << sep << "WorkgroupMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsCrossWorkgroupMemoryMask ) )
			{
				stream << sep << "CrossWorkgroupMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsAtomicCounterMemoryMask ) )
			{
				stream << sep << "AtomicCounterMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsImageMemoryMask ) )
			{
				stream << sep << "ImageMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsOutputMemoryMask ) )
			{
				stream << sep << "OutputMemory";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsMakeAvailableMask ) )
			{
				stream << sep << "MakeAvailable";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsMakeVisibleMask ) )
			{
				stream << sep << "MakeVisible";
				sep = "|";
			}

			if ( value & uint32_t( spv::MemorySemanticsVolatileMask ) )
			{
				stream << sep << "Volatile";
				sep = "|";
			}

			if ( value == uint32_t( spv::MemorySemanticsMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		static std::string getFunctionControlMaskName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::FunctionControlInlineMask ) )
			{
				stream << sep << "Inline";
				sep = "|";
			}

			if ( value & uint32_t( spv::FunctionControlDontInlineMask ) )
			{
				stream << sep << "DontInline";
				sep = "|";
			}

			if ( value & uint32_t( spv::FunctionControlPureMask ) )
			{
				stream << sep << "Pure";
				sep = "|";
			}

			if ( value & uint32_t( spv::FunctionControlConstMask ) )
			{
				stream << sep << "Const";
				sep = "|";
			}

			if ( value == uint32_t( spv::FunctionControlOptNoneINTELMask ) )
			{
				stream << sep << "OptNoneINTEL";
			}

			if ( value == uint32_t( spv::FunctionControlMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		static std::string getFPFastMathModeName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::FPFastMathModeNotNaNMask ) )
			{
				stream << sep << "NotNaN";
				sep = "|";
			}

			if ( value & uint32_t( spv::FPFastMathModeNotInfMask ) )
			{
				stream << sep << "NotInf";
				sep = "|";
			}

			if ( value & uint32_t( spv::FPFastMathModeNSZMask ) )
			{
				stream << sep << "NSZ";
				sep = "|";
			}

			if ( value & uint32_t( spv::FPFastMathModeAllowRecipMask ) )
			{
				stream << sep << "AllowRecip";
				sep = "|";
			}

			if ( value & uint32_t( spv::FPFastMathModeFastMask ) )
			{
				stream << sep << "Fast";
				sep = "|";
			}

			if ( value & uint32_t( spv::FPFastMathModeAllowContractFastINTELMask ) )
			{
				stream << sep << "AllowContractFastINTEL";
				sep = "|";
			}

			if ( value & uint32_t( spv::FPFastMathModeAllowReassocINTELMask ) )
			{
				stream << sep << "AllowReassocINTEL";
				sep = "|";
			}

			if ( value == uint32_t( spv::FPFastMathModeMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		template< typename InstructionType >
		static void checkType( Instruction const & instruction )
		{
			return assertType< InstructionType::Op
				, InstructionType::HasReturnTypeId
				, InstructionType::HasResultId
				, InstructionType::OperandsCount
				, InstructionType::HasName
				, InstructionType::HasLabels >( instruction );
		}

		template< typename T >
		static void count( ast::Vector< T > const & values
			, size_t & result );

		template< typename T >
		static void count( Optional< T > const & value
			, size_t & result );

		static void count( spv::Id const &
			, size_t & result )
		{
			++result;
		}

		static void count( spirv::Op const &
			, size_t & result )
		{
			++result;
		}

		static void count( spirv::Instruction const & instruction
			, size_t & result )
		{
			count( instruction.op, result );
			count( instruction.returnTypeId, result );
			count( instruction.resultId, result );
			count( instruction.operands, result );
			count( instruction.packedName, result );
		}

		template< typename T >
		static void count( ast::Vector< T > const & values
			, size_t & result )
		{
			for ( auto & value : values )
			{
				count( value, result );
			}
		}

		template< typename T >
		static void count( Optional< T > const & value
			, size_t & result )
		{
			if ( bool( value ) )
			{
				count( value.value(), result );
			}
		}

		static std::ostream & writeWord( size_t word
			, std::ostream & stream )
		{
			stream << "(" << std::setw( 8 ) << std::setfill( ' ' ) << word << ")";
			return stream;
		}

		static std::string writeId( spv::Id const & id )
		{
			auto stream = getStream();
			stream << std::setw( 5 ) << std::right << ( "%" + std::to_string( id ) );
			return stream.str();
		}

		static std::string writeStream( spv::Id id
			, NameCache const & names )
		{
			auto stream = getStream();
			stream << " %" << id << names.get( id );
			return stream.str();
		}

		static std::ostream & writeStream( Optional< spv::Id > id
			, std::ostream & stream
			, NameCache const & names )
		{
			if ( bool( id ) )
			{
				stream << writeStream( id.value(), names );
			}

			return stream;
		}

		static std::ostream & writeStream( spirv::IdList const & ids
			, std::ostream & stream
			, NameCache const & names )
		{
			for ( auto & id : ids )
			{
				writeStream( id, stream, names );
			}

			return stream;
		}

		static std::ostream & writeExtension( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache & names
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			
			if ( auto opCode = spv::Op( instruction.op.getOpData().opCode );
				opCode == spv::OpExtInstImport )
			{
				checkType< ExtInstImportInstruction >( instruction );
				names.add( instruction.resultId.value(), instruction.name.value() );
				stream << writeId( instruction.resultId.value() ) << " =";
				stream << " " << spirv::getOperatorName( opCode );
				stream << " \"" << instruction.name.value() << "\"";
				writeStream( instruction.operands, stream, names );
			}
			else if ( opCode == spv::OpExtension )
			{
				checkType< ExtensionInstruction >( instruction );
				stream << "        " << spirv::getOperatorName( opCode );
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeInstruction( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			if ( bool( instruction.resultId ) )
			{
				stream << writeId( instruction.resultId.value() ) << " =";
			}
			else
			{
				stream << "       ";
			}

			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << spirv::getOperatorName( opCode );
			writeStream( instruction.returnTypeId, stream, names );

			for ( auto const & operand : instruction.operands )
			{
				writeStream( operand, stream, names );
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeDebug( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache & names
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			assert( opCode == spv::OpName
				|| opCode == spv::OpString
				|| opCode == spv::OpMemberName
				|| opCode == spv::OpSource
				|| opCode == spv::OpSourceExtension );

			if ( opCode == spv::OpName )
			{
				stream << "        " << spirv::getOperatorName( opCode );
				checkType< NameInstruction >( instruction );
				names.add( instruction.resultId.value(), instruction.name.value() );
				writeStream( instruction.resultId, stream, names );
				stream << " \"" << instruction.name.value() << "\"";
			}
			else if ( opCode == spv::OpString )
			{
				stream << writeId( instruction.resultId.value() ) << " =";
				stream << " " << spirv::getOperatorName( opCode );
				checkType< StringInstruction >( instruction );
				names.add( instruction.resultId.value(), instruction.name.value() );
				stream << " \"" << instruction.name.value() << "\"";
			}
			else if ( opCode == spv::OpMemberName )
			{
				stream << "        " << spirv::getOperatorName( opCode );
				checkType< MemberNameInstruction >( instruction );
				writeStream( instruction.returnTypeId.value(), stream, names );
				stream << " " << instruction.resultId.value();
				stream << " \"" << instruction.name.value() << "\"";
			}
			else if ( opCode == spv::OpSource )
			{
				stream << "        " << spirv::getOperatorName( opCode );
				checkType< SourceInstruction >( instruction );
				assert( instruction.operands.size() >= 2u );
				stream << " " << getSourceLanguageName( instruction.operands[0] );
				stream << " " << instruction.operands[1];

				if ( instruction.operands.size() > 2 )
				{
					stream << " " << instruction.operands[2];
				}

				if ( bool( instruction.name ) )
				{
					stream << " \"" << instruction.name.value() << "\"";
				}
			}
			else if ( opCode == spv::OpSourceExtension )
			{
				checkType< SourceExtensionInstruction >( instruction );
				assert( instruction.operands.empty() );

				if ( bool( instruction.name ) )
				{
					stream << " \"" << instruction.name.value() << "\"";
				}
			}
			else
			{
				writeInstruction( instruction, stream, names );
			}

			return stream;
		}

		static std::ostream & writeDecoration( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			assert( opCode == spv::OpDecorate || opCode == spv::OpMemberDecorate );
			stream << "        " << spirv::getOperatorName( opCode );
			auto it = instruction.operands.begin();

			if ( opCode == spv::OpDecorate )
			{
				checkType< DecorateInstruction >( instruction );
				writeStream( *it, stream, names );
				++it;
			}
			else if ( opCode == spv::OpMemberDecorate )
			{
				checkType< MemberDecorateInstruction >( instruction );
				writeStream( *it, stream, names );
				++it;
				stream << " " << *it;
				++it;
			}

			auto decoration = spv::Decoration( *it );
			stream << " " << getName( decoration );
			++it;

			if ( decoration == spv::DecorationBuiltIn )
			{
				stream << " " << getName( spv::BuiltIn( *it ) );
				++it;
			}
			else if ( decoration == spv::DecorationFuncParamAttr )
			{
				stream << " " << getName( spv::FunctionParameterAttribute( *it ) );
				++it;
			}
			else if ( decoration == spv::DecorationFPRoundingMode )
			{
				stream << " " << getName( spv::FPRoundingMode( *it ) );
				++it;
			}
			else if ( decoration == spv::DecorationFPFastMathMode )
			{
				stream << " " << getFPFastMathModeName( *it );
				++it;
			}
			else if ( decoration == spv::DecorationLinkageAttributes )
			{
				stream << " \"" << instruction.name.value() << "\"";
				stream << " " << getName( spv::LinkageType( *it ) );
				++it;
			}
			else if ( decoration == spv::DecorationSpecId
				|| decoration == spv::DecorationArrayStride
				|| decoration == spv::DecorationMatrixStride
				|| decoration == spv::DecorationStream
				|| decoration == spv::DecorationLocation
				|| decoration == spv::DecorationComponent
				|| decoration == spv::DecorationIndex
				|| decoration == spv::DecorationBinding
				|| decoration == spv::DecorationDescriptorSet
				|| decoration == spv::DecorationOffset
				|| decoration == spv::DecorationXfbBuffer
				|| decoration == spv::DecorationXfbStride
				|| decoration == spv::DecorationInputAttachmentIndex
				|| decoration == spv::DecorationAlignment
				|| decoration == spv::DecorationSecondaryViewportRelativeNV
				|| decoration == spv::DecorationReferencedIndirectlyINTEL
				|| decoration == spv::DecorationCounterBuffer
				|| decoration == spv::DecorationUserSemantic
				|| decoration == spv::DecorationUserTypeGOOGLE
				|| decoration == spv::DecorationRegisterINTEL
				|| decoration == spv::DecorationMemoryINTEL
				|| decoration == spv::DecorationNumbanksINTEL
				|| decoration == spv::DecorationBankwidthINTEL
				|| decoration == spv::DecorationMaxPrivateCopiesINTEL
				|| decoration == spv::DecorationSinglepumpINTEL
				|| decoration == spv::DecorationDoublepumpINTEL
				|| decoration == spv::DecorationMaxReplicatesINTEL
				|| decoration == spv::DecorationSimpleDualPortINTEL
				|| decoration == spv::DecorationMergeINTEL
				|| decoration == spv::DecorationBankBitsINTEL
				|| decoration == spv::DecorationForcePow2DepthINTEL )
			{
				stream << " " << *it;
				++it;
			}

			return stream;
		}

		static std::ostream & writeType( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache & names )
		{
			stream << writeId( instruction.resultId.value() ) << " =";
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << " " << spirv::getOperatorName( opCode );

			if ( opCode == spv::OpTypeVoid )
			{
				names.addType( instruction.resultId.value(), "void" );
			}
			else if ( opCode == spv::OpTypeFunction )
			{
				checkType< FunctionTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "func" );
				// First being return type ID, other ones being parameters type ID.
				for ( auto & operand : instruction.operands )
				{
					writeStream( operand, stream, names );
				}
			}
			else if ( opCode == spv::OpTypePointer )
			{
				// Storage class then Type ID.
				checkType< PointerTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getPtrTypeName( instruction ) );
				stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );
				writeStream( instruction.operands[1], stream, names );
			}
			else if ( opCode == spv::OpTypeForwardPointer )
			{
				// Storage class then Type ID.
				checkType< ForwardPointerTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getPtrTypeName( instruction ) );
				stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );
			}
			else if ( opCode == spv::OpTypeStruct )
			{
				checkType< StructTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getStructTypeName( instruction ) );
				// Members IDs.
				for ( auto & operand : instruction.operands )
				{
					writeStream( operand, stream, names );
				}
			}
			else if ( opCode == spv::OpTypeBool )
			{
				checkType< BooleanTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "bool" );
			}
			else if ( opCode == spv::OpTypeInt )
			{
				checkType< IntTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getIntTypeName( instruction ) );
				// Width then Signedness.
				stream << " " << instruction.operands[0];
				stream << " " << instruction.operands[1];
			}
			else if ( opCode == spv::OpTypeFloat )
			{
				checkType< FloatTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getFloatTypeName( instruction ) );
				// Width.
				stream << " " << instruction.operands[0];
			}
			else if ( opCode == spv::OpTypeVector )
			{
				checkType< VectorTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getVecTypeName( instruction ) );
				// Component type and components count.
				writeStream( instruction.operands[0], stream, names );
				stream << " " << instruction.operands[1];
			}
			else if ( opCode == spv::OpTypeMatrix )
			{
				checkType< MatrixTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getMatTypeName( instruction ) );
				// Component type and components count.
				writeStream( instruction.operands[0], stream, names );
				stream << " " << instruction.operands[1];
			}
			else if ( opCode == spv::OpTypeArray )
			{
				checkType< ArrayTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), names.getArrayTypeName( instruction ) );
				// Component type and components count.
				writeStream( instruction.operands[0], stream, names );
				writeStream( instruction.operands[1], stream, names );
			}
			else if ( opCode == spv::OpTypeImage )
			{
				checkType< ImageTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "img" );
				// Sampled Type, Dim, Depth, Arrayed, MS, Sampled, Format.
				writeStream( instruction.operands[0], stream, names );
				stream << " " << getName( spv::Dim( instruction.operands[1] ) );
				stream << " " << instruction.operands[2];
				stream << " " << instruction.operands[3];
				stream << " " << instruction.operands[4];
				stream << " " << instruction.operands[5];
				stream << " " << getName( spv::ImageFormat( instruction.operands[6] ) );

				// Optional Access Qualifier
				if ( instruction.operands.size() > 7 )
				{
					stream << " " << getName( spv::AccessQualifier( instruction.operands[7] ) );
				}
			}
			else if ( opCode == spv::OpTypeSampler )
			{
				checkType< SamplerTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "splr" );
			}
			else if ( opCode == spv::OpTypeSampledImage )
			{
				checkType< TextureTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "simg" );
				// Image type.
				writeStream( instruction.operands[0], stream, names );
			}
			else if ( opCode == spv::OpTypeAccelerationStructureKHR )
			{
				checkType< AccelerationStructureTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "accst" );
			}
			else if ( opCode == spv::OpTypeRuntimeArray )
			{
				checkType< RuntimeArrayTypeInstruction >( instruction );
				names.addType( instruction.resultId.value(), "dynarray" );
				// Element type.
				writeStream( instruction.operands[0], stream, names );
			}
			else
			{
				writeInstruction( instruction, stream, names );
			}

			return stream;
		}

		static std::ostream & writeGlobalVariable( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< VariableInstruction >( instruction );
			std::string result;
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << writeId( instruction.resultId.value() ) << " =";
			stream << " " << spirv::getOperatorName( opCode );
			writeStream( instruction.returnTypeId.value(), stream, names );
			stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );

			for ( size_t i = 1u; i < instruction.operands.size(); ++i )
			{
				writeStream( instruction.operands[i], stream, names );
			}

			return stream;
		}

		static std::ostream & writeConstant( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache & names
			, ast::type::TypePtr type )
		{
			assert( bool( instruction.resultId ) );
			assert( bool( instruction.returnTypeId ) );
			stream << writeId( instruction.resultId.value() ) << " =";
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << " " << spirv::getOperatorName( opCode );
			writeStream( instruction.returnTypeId.value(), stream, names );

			if ( type == nullptr )
			{
				names.add( instruction.resultId.value(), "Unk" );
				stream << " Unknown value type";
			}
			else
			{
				if ( opCode == spv::OpConstant )
				{
					checkType< ConstantInstruction >( instruction );
					switch ( type->getKind() )
					{
					case ast::type::Kind::eBoolean:
						names.add( instruction.resultId.value(), std::to_string( bool( instruction.operands[0] ) ) );
						stream << " " << bool( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt8:
						names.add( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
						stream << " " << int32_t( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt16:
						names.add( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
						stream << " " << int32_t( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt32:
						names.add( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
						stream << " " << int32_t( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt64:
						names.add( instruction.resultId.value(), std::to_string( ( int64_t( instruction.operands[0] ) << 32 ) + int64_t( instruction.operands[1] ) ) );
						stream << " " << ( ( int64_t( instruction.operands[0] ) << 32 ) + int64_t( instruction.operands[1] ) );
						break;
					case ast::type::Kind::eUInt8:
						names.add( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
						stream << " " << instruction.operands[0];
						break;
					case ast::type::Kind::eUInt16:
						names.add( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
						stream << " " << instruction.operands[0];
						break;
					case ast::type::Kind::eUInt32:
						names.add( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
						stream << " " << instruction.operands[0];
						break;
					case ast::type::Kind::eUInt64:
						names.add( instruction.resultId.value(), std::to_string( ( uint64_t( instruction.operands[0] ) << 32 )+ instruction.operands[1] ) );
						stream << " " << ( ( uint64_t( instruction.operands[0] ) << 32 ) + uint64_t( instruction.operands[1] ) );
						break;
					case ast::type::Kind::eFloat:
	#pragma GCC diagnostic push
	#if defined( __clang__ )
	#	pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
	#else
	#	pragma GCC diagnostic ignored "-Wstrict-aliasing"
	#endif
						names.add( instruction.resultId.value(), std::to_string( *reinterpret_cast< float const * >( instruction.operands.data() ) ) );
						stream << " " << *reinterpret_cast< float const * >( instruction.operands.data() );
	#pragma GCC diagnostic pop
						break;
					case ast::type::Kind::eDouble:
						assert( instruction.operands.size() >= 2 );
						{
	#pragma GCC diagnostic push
	#if defined( __clang__ )
	#	pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
	#else
	#	pragma GCC diagnostic ignored "-Wstrict-aliasing"
	#endif
							names.add( instruction.resultId.value(), std::to_string( *reinterpret_cast< double const * >( instruction.operands.data() ) ) );
							stream << " " << *reinterpret_cast< double const * >( instruction.operands.data() );
	#pragma GCC diagnostic pop
						}
						break;
					default:
						break;
					}
				}
				else if ( opCode == spv::OpConstantComposite )
				{
					checkType< ConstantCompositeInstruction >( instruction );
					names.add( instruction.resultId.value(), "const" );
					writeStream( instruction.operands, stream, names );
				}
				else
				{
					writeInstruction( instruction, stream, names );
				}
			}

			return stream;
		}

		static std::ostream & writeSpecConstant( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache & names
			, ast::type::TypePtr type )
		{
			assert( bool( instruction.resultId ) );
			assert( bool( instruction.returnTypeId ) );
			stream << writeId( instruction.resultId.value() ) << " =";
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << " " << spirv::getOperatorName( opCode );
			writeStream( instruction.returnTypeId.value(), stream, names );

			if ( type == nullptr )
			{
				names.add( instruction.resultId.value(), "Unk" );
				stream << " Unknown value type";
			}
			else
			{
				if ( opCode == spv::OpSpecConstant )
				{
					checkType< SpecConstantInstruction >( instruction );
					switch ( type->getKind() )
					{
					case ast::type::Kind::eBoolean:
						names.add( instruction.resultId.value(), std::to_string( bool( instruction.operands[0] ) ) );
						stream << " " << bool( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt8:
						names.add( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
						stream << " " << int32_t( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt16:
						names.add( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
						stream << " " << int32_t( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt32:
						names.add( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
						stream << " " << int32_t( instruction.operands[0] );
						break;
					case ast::type::Kind::eInt64:
						names.add( instruction.resultId.value(), std::to_string( ( int64_t( instruction.operands[0] ) << 32 ) + int64_t( instruction.operands[1] ) ) );
						stream << " " << ( ( int64_t( instruction.operands[0] ) << 32 ) + int64_t( instruction.operands[1] ) );
						break;
					case ast::type::Kind::eUInt8:
						names.add( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
						stream << " " << instruction.operands[0];
						break;
					case ast::type::Kind::eUInt16:
						names.add( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
						stream << " " << instruction.operands[0];
						break;
					case ast::type::Kind::eUInt32:
						names.add( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
						stream << " " << instruction.operands[0];
						break;
					case ast::type::Kind::eUInt64:
						names.add( instruction.resultId.value(), std::to_string( ( uint64_t( instruction.operands[0] ) << 32 ) + instruction.operands[1] ) );
						stream << " " << ( ( uint64_t( instruction.operands[0] ) << 32 ) + uint64_t( instruction.operands[1] ) );
						break;
					case ast::type::Kind::eFloat:
	#pragma GCC diagnostic push
	#if defined( __clang__ )
	#	pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
	#else
	#	pragma GCC diagnostic ignored "-Wstrict-aliasing"
	#endif
						names.add( instruction.resultId.value(), std::to_string( *reinterpret_cast< float const * >( instruction.operands.data() ) ) );
						stream << " " << *reinterpret_cast< float const * >( instruction.operands.data() );
	#pragma GCC diagnostic pop
						break;
					case ast::type::Kind::eDouble:
						assert( instruction.operands.size() >= 2 );
						{
	#pragma GCC diagnostic push
	#if defined( __clang__ )
	#	pragma GCC diagnostic ignored "-Wundefined-reinterpret-cast"
	#else
	#	pragma GCC diagnostic ignored "-Wstrict-aliasing"
	#endif
							names.add( instruction.resultId.value(), std::to_string( *reinterpret_cast< double const * >( instruction.operands.data() ) ) );
							stream << " " << *reinterpret_cast< double const * >( instruction.operands.data() );
	#pragma GCC diagnostic pop
						}
						break;
					default:
						break;
					}
				}
				else if ( opCode == spv::OpSpecConstantComposite )
				{
					checkType< SpecConstantCompositeInstruction >( instruction );
					names.add( instruction.resultId.value(), "specconst" );
					writeStream( instruction.operands, stream, names );
				}
				else
				{
					writeInstruction( instruction, stream, names );
				}
			}

			return stream;
		}

		static std::ostream & writeExtInst( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names
			, spirv::Module const & shaderModule )
		{
			checkType< ExtInstInstruction >( instruction );

			if ( shaderModule.isExtGlslStd450( instruction.operands[0] ) )
			{
				if ( bool( instruction.resultId ) )
				{
					stream << writeId( instruction.resultId.value() ) << " =";
				}
				else
				{
					stream << "       ";
				}

				stream << " ExtInst";

				if ( bool( instruction.returnTypeId ) )
				{
					stream << writeStream( instruction.returnTypeId.value(), names );
				}

				writeStream( instruction.operands[0], stream, names );
				stream << " " << getName( spv::GLSLstd450( instruction.operands[1] ) );
			}
			else if ( shaderModule.isExtNonSemanticDebugInfo( instruction.operands[0] ) )
			{
				stream << writeId( instruction.resultId.value() ) << " = ExtInst";
				writeStream( instruction.operands[0], stream, names );
				stream << writeStream( instruction.returnTypeId.value(), names );
				stream << " " << getName( spv::NonSemanticShaderDebugInfo100Instructions( instruction.operands[1] ) );
			}
			else
			{
				writeStream( instruction.operands[0], stream, names );
				writeStream( instruction.operands[1], stream, names );
			}

			for ( size_t i = 2u; i < instruction.operands.size(); ++i )
			{
				writeStream( instruction.operands[i], stream, names );
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeGlobalDeclaration( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache & names
			, spirv::Module const & shaderModule
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );

			if ( auto opCode = spv::Op( instruction.op.getOpData().opCode );
				opCode == spv::OpExtInst )
			{
				writeExtInst( instruction, stream, names, shaderModule ) << "\n";
			}
			else if ( opCode == spv::OpConstant
				|| opCode == spv::OpConstantTrue
				|| opCode == spv::OpConstantFalse
				|| opCode == spv::OpConstantComposite )
			{
				writeConstant( instruction, stream, names, shaderModule.getType( DebugId{ instruction.returnTypeId.value() } ) ) << "\n";
			}
			else if ( opCode == spv::OpSpecConstant
				|| opCode == spv::OpSpecConstantTrue
				|| opCode == spv::OpSpecConstantFalse
				|| opCode == spv::OpSpecConstantComposite )
			{
				writeSpecConstant( instruction, stream, names, shaderModule.getType( DebugId{ instruction.returnTypeId.value() } ) ) << "\n";
			}
			else if ( opCode == spv::OpVariable )
			{
				writeGlobalVariable( instruction, stream, names ) << "\n";
			}
			else
			{
				writeType( instruction, stream, names ) << "\n";
			}

			return stream;
		}

		static std::ostream & writeGlobalDeclarations( spirv::InstructionList const & instructions
			, std::ostream & stream
			, NameCache & names
			, spirv::Module const & shaderModule
			, size_t & word )
		{
			for ( auto & instruction : instructions )
			{
				writeGlobalDeclaration( *instruction, stream, names, shaderModule, word );
			}

			return stream;
		}

		static std::ostream & writeFuncVariable( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< VariableInstruction >( instruction );
			stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );

			for ( size_t i = 1u; i < instruction.operands.size(); ++i )
			{
				writeStream( instruction.operands[i], stream, names );
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageSample( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Sampled Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );

			if ( instruction.operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[2] );

				for ( size_t i = 3u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageSampleDref( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Sampled Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );
			// Dref
			writeStream( instruction.operands[2], stream, names );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageSampleProj( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Sampled Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );

			if ( instruction.operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[2] );

				for ( size_t i = 3u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageSampleProjDref( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Sampled Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );
			// Dref
			writeStream( instruction.operands[2], stream, names );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageFetch( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );

			if ( instruction.operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[2] );

				for ( size_t i = 3u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageGather( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );
			// Component
			writeStream( instruction.operands[2], stream, names );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeImageDrefGather( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			// Image
			writeStream( instruction.operands[0], stream, names );
			// Coordinate
			writeStream( instruction.operands[1], stream, names );
			// Dref
			writeStream( instruction.operands[2], stream, names );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					writeStream( instruction.operands[i], stream, names );
				}
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeStore( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< StoreInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );
			writeStream( instruction.operands[1], stream, names );

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeLoad( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< LoadInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );

			if ( instruction.operands.size() > 2u )
			{
				stream << " " << getMemoryAccessName( spv::MemoryAccessMask( instruction.operands[1] ) );
				stream << " " << instruction.operands[2];
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeCopyMemory( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< CopyMemoryInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );
			writeStream( instruction.operands[1], stream, names );

			if ( instruction.operands.size() > 2u )
			{
				stream << " " << getMemoryAccessName( instruction.operands[2] );
			}

			return stream;
		}

		static std::ostream & writeSwitch( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< SwitchInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );
			writeStream( instruction.operands[1], stream, names );

			if ( bool( instruction.labels ) )
			{
				for ( auto const & [word, label] : instruction.labels.value() )
				{
					stream << " " << word;
					writeStream( label, stream, names );
				}
			}

			return stream;
		}

		static std::ostream & writeVectorShuffle( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< VectorShuffleInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );

			if ( instruction.operands[1] == spv::Id( spv::OpUndef ) )
			{
				stream << " Undef";
			}
			else
			{
				writeStream( instruction.operands[1], stream, names );
			}

			for ( size_t i = 2u; i < instruction.operands.size(); ++i )
			{
				stream << " " << instruction.operands[i];
			}

			if ( bool( instruction.name ) )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		static std::ostream & writeCompositeExtract( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< CompositeExtractInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );

			for ( auto i = 1u; i < instruction.operands.size(); ++i )
			{
				stream << " " << instruction.operands[i];
			}

			return stream;
		}

		static std::ostream & writeSpecConstantOp( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< SpecConstantInstruction >( instruction );
			stream << " " << spirv::getOperatorName( spv::Op( instruction.operands[0] ) );

			for ( size_t i = 1u; i < instruction.operands.size(); ++i )
			{
				writeStream( instruction.operands[i], stream, names );
			}

			return stream;
		}

		static std::ostream & writeLoopMergeOp( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< LoopMergeInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );
			writeStream( instruction.operands[1], stream, names );
			stream << " " << getLoopControlName( instruction.operands[2] );
			return stream;
		}

		static std::ostream & writeSelectionMergeOp( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< SelectionMergeInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );
			stream << " " << getSelectionControlName( instruction.operands[1] );
			return stream;
		}

		static std::ostream & writeBranch( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< BranchInstruction >( instruction );
			writeStream( instruction.operands[0], stream, names );
			return stream;
		}

		static std::ostream & writeBranchConditional( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			checkType< BranchConditionalInstruction >( instruction );
			// Condition
			writeStream( instruction.operands[0], stream, names );
			// True label
			writeStream( instruction.operands[1], stream, names );
			// False label
			writeStream( instruction.operands[2], stream, names );

			if ( instruction.operands.size() > 3u )
			{
				// Optional Weights.
				assert( instruction.operands.size() == 5u );
				stream << " " << instruction.operands[3];
				stream << " " << instruction.operands[4];
			}

			return stream;
		}

		static std::ostream & writeAtomicAdd( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			assert( instruction.operands.size() == 4u );
			writeStream( instruction.operands[0], stream, names );
			stream << " " << getName( spv::Scope( instruction.operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction.operands[2] );
			writeStream( instruction.operands[3], stream, names );
			return stream;
		}

		static std::ostream & writeAtomicMinMax( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			assert( instruction.operands.size() == 4u );
			writeStream( instruction.operands[0], stream, names );
			stream << " " << getName( spv::Scope( instruction.operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction.operands[2] );
			writeStream( instruction.operands[3], stream, names );
			return stream;
		}

		static std::ostream & writeAtomicAndOrXor( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			assert( instruction.operands.size() == 4u );
			writeStream( instruction.operands[0], stream, names );
			stream << " " << getName( spv::Scope( instruction.operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction.operands[2] );
			writeStream( instruction.operands[3], stream, names );
			return stream;
		}

		static std::ostream & writeAtomicExchange( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			assert( instruction.operands.size() == 4u );
			writeStream( instruction.operands[0], stream, names );
			stream << " " << getName( spv::Scope( instruction.operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction.operands[2] );
			writeStream( instruction.operands[3], stream, names );
			return stream;
		}

		static std::ostream & writeAtomicCompExchange( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names )
		{
			assert( instruction.operands.size() == 6u );
			writeStream( instruction.operands[0], stream, names );
			stream << " " << getName( spv::Scope( instruction.operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction.operands[2] );
			stream << " " << getMemorySemanticsName( instruction.operands[3] );
			writeStream( instruction.operands[4], stream, names );
			writeStream( instruction.operands[5], stream, names );
			return stream;
		}

		static std::ostream & writeBlockInstruction( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names
			, spirv::Module const & shaderModule
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );

			if ( auto opCode = spv::Op( instruction.op.getOpData().opCode );
				opCode == spv::OpExtInst )
			{
				writeExtInst( instruction, stream, names, shaderModule );
			}
			else
			{
				if ( bool( instruction.resultId ) )
				{
					stream << writeId( instruction.resultId.value() ) << " =";
				}
				else
				{
					stream << "       ";
				}

				stream << " " << spirv::getOperatorName( opCode );

				if ( bool( instruction.returnTypeId ) )
				{
					stream << writeStream( instruction.returnTypeId.value(), names );
				}

				if ( opCode == spv::OpVariable )
				{
					writeFuncVariable( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageSampleImplicitLod
					|| opCode == spv::OpImageSampleExplicitLod )
				{
					writeImageSample( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageSampleDrefImplicitLod
					|| opCode == spv::OpImageSampleDrefExplicitLod )
				{
					writeImageSampleDref( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageSampleProjImplicitLod
					|| opCode == spv::OpImageSampleProjExplicitLod )
				{
					writeImageSampleProj( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageSampleProjDrefImplicitLod
					|| opCode == spv::OpImageSampleProjDrefExplicitLod )
				{
					writeImageSampleProjDref( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageFetch )
				{
					writeImageFetch( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageGather )
				{
					writeImageGather( instruction, stream, names );
				}
				else if ( opCode == spv::OpImageDrefGather )
				{
					writeImageDrefGather( instruction, stream, names );
				}
				else if ( opCode == spv::OpStore )
				{
					writeStore( instruction, stream, names );
				}
				else if ( opCode == spv::OpLoad )
				{
					writeLoad( instruction, stream, names );
				}
				else if ( opCode == spv::OpCopyMemory )
				{
					writeCopyMemory( instruction, stream, names );
				}
				else if ( opCode == spv::OpSwitch )
				{
					writeSwitch( instruction, stream, names );
				}
				else if ( opCode == spv::OpVectorShuffle )
				{
					writeVectorShuffle( instruction, stream, names );
				}
				else if ( opCode == spv::OpCompositeExtract )
				{
					writeCompositeExtract( instruction, stream, names );
				}
				else if ( opCode == spv::OpSpecConstantOp )
				{
					writeSpecConstantOp( instruction, stream, names );
				}
				else if ( opCode == spv::OpLoopMerge )
				{
					writeLoopMergeOp( instruction, stream, names );
				}
				else if ( opCode == spv::OpSelectionMerge )
				{
					writeSelectionMergeOp( instruction, stream, names );
				}
				else if ( opCode == spv::OpBranch )
				{
					writeBranch( instruction, stream, names );
				}
				else if ( opCode == spv::OpBranchConditional )
				{
					writeBranchConditional( instruction, stream, names );
				}
				else if ( opCode == spv::OpAtomicIAdd
					|| opCode == spv::OpAtomicFAddEXT )
				{
					writeAtomicAdd( instruction, stream, names );
				}
				else if ( opCode == spv::OpAtomicUMin
					|| opCode == spv::OpAtomicSMin
					|| opCode == spv::OpAtomicUMax
					|| opCode == spv::OpAtomicSMax )
				{
					writeAtomicMinMax( instruction, stream, names );
				}
				else if ( opCode == spv::OpAtomicAnd
					|| opCode == spv::OpAtomicOr
					|| opCode == spv::OpAtomicXor )
				{
					writeAtomicAndOrXor( instruction, stream, names );
				}
				else if ( opCode == spv::OpAtomicExchange )
				{
					writeAtomicExchange( instruction, stream, names );
				}
				else if ( opCode == spv::OpAtomicCompareExchange )
				{
					writeAtomicCompExchange( instruction, stream, names );
				}
				else
				{
					writeStream( instruction.operands, stream, names );

					if ( bool( instruction.name ) )
					{
						stream << " \"" << instruction.name.value() << "\"";
					}
				}
			}

			return stream;
		}

		template< typename WriterT, typename ... ParamsT >
		static std::ostream & writeInstructions( BlockList const & instructions
			, WriterT writer
			, std::ostream & stream
			, ParamsT && ... params )
		{
			for ( auto & instruction : instructions )
			{
				writer( instruction, stream, std::forward< ParamsT >( params )... ) << "\n";
			}

			return stream;
		}

		template< typename WriterT, typename ... ParamsT >
		static std::ostream & writeInstructions( FunctionList const & instructions
			, WriterT writer
			, std::ostream & stream
			, ParamsT && ... params )
		{
			for ( auto & instruction : instructions )
			{
				writer( instruction, stream, std::forward< ParamsT >( params )... ) << "\n";
			}

			return stream;
		}

		template< typename WriterT, typename ... ParamsT >
		static std::ostream & writeInstructions( InstructionList const & instructions
			, WriterT writer
			, std::ostream & stream
			, ParamsT && ... params )
		{
			for ( auto & instruction : instructions )
			{
				writer( *instruction, stream, std::forward< ParamsT >( params )... ) << "\n";
			}

			return stream;
		}

		static std::ostream & writeBlock( spirv::Block const & block
			, std::ostream & stream
			, NameCache & names
			, spirv::Module const & shaderModule
			, size_t & word )
		{
			writeInstructions( block.instructions, writeBlockInstruction, stream, names, shaderModule, word );
			writeBlockInstruction( *block.blockEnd, stream, names, shaderModule, word );
			return stream;
		}

		static std::ostream & writeFunctionDecl( spirv::Instruction const & instruction
			, std::ostream & stream
			, NameCache const & names
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << writeStream( instruction.resultId.value(), names ) << " =";
			stream << " " << spirv::getOperatorName( opCode );
			stream << writeStream( instruction.returnTypeId.value(), names );

			if ( opCode == spv::OpFunction )
			{
				stream << " " << getFunctionControlMaskName( instruction.operands[0] );
				stream << " " << writeStream( instruction.operands[1], names );
			}

			return stream;
		}

		static std::ostream & writeFunction( spirv::Function const & function
			, std::ostream & stream
			, NameCache & names
			, spirv::Module const & shaderModule
			, size_t & word )
		{
			writeInstructions( function.declaration, writeFunctionDecl, stream, names, word );
			writeInstructions( function.cfg.blocks, writeBlock, stream, names, shaderModule, word );
			return stream;
		}

		static std::ostream & writeCapability( spirv::Instruction const & instruction
			, std::ostream & stream
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << "        " << spirv::getOperatorName( opCode );
			stream << " " << spirv::getName( spv::Capability( instruction.operands[0] ) );
			return stream;
		}

		static std::ostream & writeMemoryModel( spirv::Instruction const & instruction
			, std::ostream & stream
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << "        " + spirv::getOperatorName( opCode );
			stream << " " + getName( spv::AddressingModel( instruction.operands[0] ) );
			stream << " " + getName( spv::MemoryModel( instruction.operands[1] ) );
			stream << "\n";
			return stream;
		}

		static std::ostream & writeEntryPoint( spirv::Instruction const & instruction
			, std::ostream & stream
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );
			auto opCode = spv::Op( instruction.op.getOpData().opCode );
			stream << "        " + spirv::getOperatorName( opCode );
			stream << " " + getName( spv::ExecutionModel( instruction.returnTypeId.value() ) );
			stream << " %" + std::to_string( instruction.resultId.value() );
			stream << " \"" + instruction.name.value() + "\"";

			for ( auto const & operand : instruction.operands )
			{
				stream << " %" + std::to_string( operand );
			}

			stream << "\n";
			return stream;
		}

		static std::ostream & writeExecutionMode( spirv::Instruction const & instruction
			, std::ostream & stream
			, size_t & word )
		{
			writeWord( word, stream );
			count( instruction, word );

			if ( auto opCode = spv::Op( instruction.op.getOpData().opCode );
				opCode == spv::OpExecutionMode )
			{
				stream << "        " + spirv::getOperatorName( opCode );
				stream << " %" + std::to_string( instruction.operands[0] );
				stream << " " + getName( spv::ExecutionMode( instruction.operands[1] ) );

				for ( size_t i = 2u; i < instruction.operands.size(); ++i )
				{
					stream << " " + std::to_string( instruction.operands[i] );
				}
			}

			return stream;
		}

		static std::ostream & writeHeader( spirv::IdList const & ids
			, std::ostream & stream
			, size_t & word )
		{
			assert( ids.size() == 5u );
			word += ids.size();
			stream << "; Magic:     0x" << std::hex << std::setw( 8u ) << std::setfill( '0' ) << ids[0] << std::endl;
			stream << "; Version:   0x" << std::hex << std::setw( 8u ) << std::setfill( '0' ) << ids[1] << std::endl;
			stream << "; Generator: 0x" << std::hex << std::setw( 8u ) << std::setfill( '0' ) << ids[2] << std::endl;
			stream << "; Bound:     " << std::dec << ids[3] << std::endl;
			stream << "; Schema:    " << ids[4] << std::endl;
			return stream;
		}

		static std::ostream & writeStream( std::ostream & stream
			, spirv::Module const & shaderModule
			, NameCache & names
			, bool doWriteHeader )
		{
			size_t word{};

			if ( doWriteHeader )
			{
				writeHeader( shaderModule.header, stream, word ) << std::endl;
				writeInstructions( shaderModule.capabilities, writeCapability, stream, word );
				writeInstructions( shaderModule.extensions, writeExtension, stream, names, word );
				writeInstructions( shaderModule.imports, writeExtension, stream, names, word );
				writeMemoryModel( *shaderModule.memoryModel, stream, word );
				writeEntryPoint( *shaderModule.entryPoint, stream, word );
				writeInstructions( shaderModule.executionModes, writeExecutionMode, stream, word ) << std::endl;
			}

			if ( auto & debugStringsDeclarations = shaderModule.getDebugStringsDeclarations();
				!debugStringsDeclarations.empty() )
			{
				stream << "; Debug Strings" << std::endl;
				writeInstructions( debugStringsDeclarations, writeDebug, stream, names, word ) << std::endl;
			}

			if ( auto & debugNamesDeclarations = shaderModule.getDebugNamesDeclarations();
				!debugNamesDeclarations.empty() )
			{
				stream << "; Debug Names and Sources" << std::endl;
				writeInstructions( debugNamesDeclarations, writeDebug, stream, names, word ) << std::endl;
			}

			stream << "; Decorations" << std::endl;
			writeInstructions( shaderModule.decorations, writeDecoration, stream, names, word ) << std::endl;
			stream << "; Constants and Types" << std::endl;
			writeGlobalDeclarations( shaderModule.constantsTypes, stream, names, shaderModule, word ) << std::endl;
			stream << "; Global Variables" << std::endl;
			writeGlobalDeclarations( shaderModule.globalDeclarations, stream, names, shaderModule, word ) << std::endl;

			if ( auto & nonSemanticDebugDeclarations = shaderModule.getNonSemanticDebugDeclarations();
				!nonSemanticDebugDeclarations.empty() )
			{
				stream << "; Debug Types and Variables" << std::endl;
				writeGlobalDeclarations( nonSemanticDebugDeclarations, stream, names, shaderModule, word ) << std::endl;
			}

			stream << "; Functions" << std::endl;
			writeInstructions( shaderModule.functions, writeFunction, stream, names, shaderModule, word ) << std::endl;
			return stream;
		}
	}

	NameCache::NameCache( ast::ShaderAllocatorBlock * alloc )
		: names{ alloc }
		, types{ alloc }
	{
	}

	void NameCache::add( spv::Id id, std::string name )
	{
		names.try_emplace( id, std::move( name ) );
	}

	void NameCache::addMember( spv::Id id, uint32_t index, std::string name )
	{
		auto & mbr = members.try_emplace( id ).first->second;
		mbr.try_emplace( index, std::move( name ) );
	}

	void NameCache::addType( spv::Id id, std::string name )
	{
		add( id, name );
		types.try_emplace( id, std::move( name ) );
	}

	std::string NameCache::getFloatTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypeFloat );
		auto width = instruction.operands[0];
		std::string result;

		if ( width <= 16u )
		{
			result = "f16";
		}
		else if ( width <= 32 )
		{
			result = "f32";
		}
		else
		{
			result = "f64";
		}

		return result;
	}

	std::string NameCache::getIntTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypeInt );
		auto width = instruction.operands[0];
		auto signedness = instruction.operands[1];
		std::string result;

		if ( width <= 8u )
		{
			result = "i8";
		}
		else if ( width <= 16u )
		{
			result = "i16";
		}
		else if ( width <= 32 )
		{
			result = "i32";
		}
		else
		{
			result = "i64";
		}

		if ( signedness == 0u )
		{
			result = "u" + result;
		}
		else if ( signedness == 1u )
		{
			result = "s" + result;
		}

		return result;
	}

	std::string NameCache::getVecTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypeVector );
		std::string result = "v";
		auto componentType = instruction.operands[0];
		auto componentCount = instruction.operands[1];
		result += std::to_string( componentCount );
		auto it = types.find( componentType );
		assert( it != types.end() );
		result += it->second;
		return result;
	}

	std::string NameCache::getMatTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypeMatrix );
		std::string result = "m";
		auto componentType = instruction.operands[0];
		auto componentCount = instruction.operands[1];
		result += std::to_string( componentCount );
		auto it = types.find( componentType );
		assert( it != types.end() );
		result += it->second;
		return result;
	}

	std::string NameCache::getStructTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypeStruct );
		assert( instruction.resultId.has_value() );
		auto resultId = instruction.resultId.value();

		if ( auto it = names.find( resultId );
			it != names.end() )
		{
			return it->second;
		}

		return std::string{};
	}

	std::string NameCache::getArrayTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypeArray );
		auto componentType = instruction.operands[0];
		auto arraySize = getRaw( instruction.operands[1] );
		auto it = types.find( componentType );
		assert( it != types.end() );
		auto result = it->second;
		result += "[" + arraySize + "]";
		return result;
	}

	std::string NameCache::getPtrTypeName( Instruction const & instruction )const
	{
		assert( instruction.op.getOpData().opCode == spv::OpTypePointer
			|| instruction.op.getOpData().opCode == spv::OpTypeForwardPointer );
		auto storageClass = spv::StorageClass( instruction.operands[0] );
		std::string result = wrthlp::getName( storageClass ) + "Ptr";

		if ( instruction.op.getOpData().opCode == spv::OpTypePointer )
		{
			auto pointedType = instruction.operands[1];
			auto it = types.find( pointedType );

			if ( it != types.end() )
			{
				result += "<" + it->second + ">";
			}
			else
			{
				result += "<unknown>";
			}
		}

		return result;
	}

	std::string NameCache::getRaw( spv::Id id )const
	{
		std::string result;

		if ( auto it = names.find( id );
			it != names.end() )
		{
			if ( it->second.find( "\n" ) != std::string::npos )
			{
				result = "...multiline...";
			}
			else
			{
				result = it->second;
			}
		}

		return result;
	}

	std::string NameCache::get( spv::Id id )const
	{
		std::string result = getRaw( id );

		if ( !result.empty() )
		{
			result = "(" + result + ")";
		}

		return result;
	}

	std::string NameCache::getMember( spv::Id id, uint32_t index )const
	{
		std::string result;

		if ( auto it = members.find( id );
			it != members.end() )
		{
			if ( auto mit = it->second.find( index );
				mit != it->second.end() )
			{
				result = mit->second;
			}
		}

		return result;
	}

	std::string write( spirv::Module const & shaderModule
		, NameCache & names
		, bool doWriteHeader )
	{
		auto stream = wrthlp::getStream();
		wrthlp::writeStream( stream, shaderModule, names, doWriteHeader );
		return stream.str();
	}
}
