/*
See LICENSE file in root folder
*/
#include "CompilerSpirV/compileSpirV.hpp"

#include "SpirvStmtAdapter.hpp"
#include "SpirvStmtConfigFiller.hpp"
#include "SpirvStmtVisitor.hpp"

#include "CompilerSpirV/spirv/GLSL.std.450.hpp"

#include <ShaderAST/Shader.hpp>

#include <ShaderAST/Visitors/StmtSimplifier.hpp>

#include <sstream>
#include <iomanip>

namespace spirv
{
	namespace
	{
		std::stringstream getStream()
		{
			std::stringstream stream;
			std::locale loc{ "C" };
			stream.imbue( loc );
			return stream;
		}

		std::string getSourceLanguageName( uint32_t value )
		{
			switch ( spv::SourceLanguage( value ) )
			{
			case spv::SourceLanguageUnknown:
				return "Unknown";
			case spv::SourceLanguageESSL:
				return "ESSL";
			case spv::SourceLanguageGLSL:
				return "GLSL";
			case spv::SourceLanguageOpenCL_C:
				return "OpenCL_C";
			case spv::SourceLanguageOpenCL_CPP:
				return "OpenCL_CPP";
			case spv::SourceLanguageHLSL:
				return "HLSL";
			default:
				assert( false && "Unsupported SourceLanguage" );
				return "Undefined";
			}
		}

		std::string getName( spv::Capability value )
		{
			switch ( value )
			{
			case spv::CapabilityMatrix:
				return "Matrix";
			case spv::CapabilityShader:
				return "Shader";
			case spv::CapabilityGeometry:
				return "Geometry";
			case spv::CapabilityTessellation:
				return "Tessellation";
			case spv::CapabilityAddresses:
				return "Addresses";
			case spv::CapabilityLinkage:
				return "Linkage";
			case spv::CapabilityKernel:
				return "Kernel";
			case spv::CapabilityVector16:
				return "Vector16";
			case spv::CapabilityFloat16Buffer:
				return "Float16Buffer";
			case spv::CapabilityFloat16:
				return "Float16";
			case spv::CapabilityFloat64:
				return "Float64";
			case spv::CapabilityInt64:
				return "Int64";
			case spv::CapabilityInt64Atomics:
				return "Int64Atomics";
			case spv::CapabilityImageBasic:
				return "ImageBasic";
			case spv::CapabilityImageReadWrite:
				return "ImageReadWrite";
			case spv::CapabilityImageMipmap:
				return "ImageMipmap";
			case spv::CapabilityPipes:
				return "Pipes";
			case spv::CapabilityGroups:
				return "Groups";
			case spv::CapabilityDeviceEnqueue:
				return "DeviceEnqueue";
			case spv::CapabilityLiteralSampler:
				return "LiteralSampler";
			case spv::CapabilityAtomicStorage:
				return "AtomicStorage";
			case spv::CapabilityInt16:
				return "Int16";
			case spv::CapabilityTessellationPointSize:
				return "TessellationPointSize";
			case spv::CapabilityGeometryPointSize:
				return "GeometryPointSize";
			case spv::CapabilityImageGatherExtended:
				return "ImageGatherExtended";
			case spv::CapabilityStorageImageMultisample:
				return "StorageImageMultisample";
			case spv::CapabilityUniformBufferArrayDynamicIndexing:
				return "UniformBufferArrayDynamicIndexing";
			case spv::CapabilitySampledImageArrayDynamicIndexing:
				return "SampledImageArrayDynamicIndexing";
			case spv::CapabilityStorageBufferArrayDynamicIndexing:
				return "StorageBufferArrayDynamicIndexing";
			case spv::CapabilityStorageImageArrayDynamicIndexing:
				return "StorageImageArrayDynamicIndexing";
			case spv::CapabilityClipDistance:
				return "ClipDistance";
			case spv::CapabilityCullDistance:
				return "CullDistance";
			case spv::CapabilityImageCubeArray:
				return "ImageCubeArray";
			case spv::CapabilitySampleRateShading:
				return "SampleRateShading";
			case spv::CapabilityImageRect:
				return "ImageRect";
			case spv::CapabilitySampledRect:
				return "SampledRect";
			case spv::CapabilityGenericPointer:
				return "GenericPointer";
			case spv::CapabilityInt8:
				return "Int8";
			case spv::CapabilityInputAttachment:
				return "InputAttachment";
			case spv::CapabilitySparseResidency:
				return "SparseResidency";
			case spv::CapabilityMinLod:
				return "MinLod";
			case spv::CapabilitySampled1D:
				return "Sampled1D";
			case spv::CapabilityImage1D:
				return "Image1D";
			case spv::CapabilitySampledCubeArray:
				return "SampledCubeArray";
			case spv::CapabilitySampledBuffer:
				return "SampledBuffer";
			case spv::CapabilityImageBuffer:
				return "ImageBuffer";
			case spv::CapabilityImageMSArray:
				return "ImageMSArray";
			case spv::CapabilityStorageImageExtendedFormats:
				return "StorageImageExtendedFormats";
			case spv::CapabilityImageQuery:
				return "ImageQuery";
			case spv::CapabilityDerivativeControl:
				return "DerivativeControl";
			case spv::CapabilityInterpolationFunction:
				return "InterpolationFunction";
			case spv::CapabilityTransformFeedback:
				return "TransformFeedback";
			case spv::CapabilityGeometryStreams:
				return "GeometryStreams";
			case spv::CapabilityStorageImageReadWithoutFormat:
				return "StorageImageReadWithoutFormat";
			case spv::CapabilityStorageImageWriteWithoutFormat:
				return "StorageImageWriteWithoutFormat";
			case spv::CapabilityMultiViewport:
				return "MultiViewport";
			case spv::CapabilitySubgroupDispatch:
				return "SubgroupDispatch";
			case spv::CapabilityNamedBarrier:
				return "NamedBarrier";
			case spv::CapabilityPipeStorage:
				return "PipeStorage";
			case spv::CapabilitySubgroupBallotKHR:
				return "SubgroupBallotKHR";
			case spv::CapabilityDrawParameters:
				return "DrawParameters";
			case spv::CapabilitySubgroupVoteKHR:
				return "SubgroupVoteKHR";
			case spv::CapabilityStorageBuffer16BitAccess:
				return "StorageBuffer16BitAccess";
			case spv::CapabilityStorageUniform16:
				return "StorageUniform16";
			case spv::CapabilityStoragePushConstant16:
				return "StoragePushConstant16";
			case spv::CapabilityStorageInputOutput16:
				return "StorageInputOutput16";
			case spv::CapabilityDeviceGroup:
				return "DeviceGroup";
			case spv::CapabilityMultiView:
				return "MultiView";
			case spv::CapabilityVariablePointersStorageBuffer:
				return "VariablePointersStorageBuffer";
			case spv::CapabilityVariablePointers:
				return "VariablePointers";
			case spv::CapabilityAtomicStorageOps:
				return "AtomicStorageOps";
			case spv::CapabilitySampleMaskPostDepthCoverage:
				return "SampleMaskPostDepthCoverage";
			case spv::CapabilityImageGatherBiasLodAMD:
				return "ImageGatherBiasLodAMD";
			case spv::CapabilityFragmentMaskAMD:
				return "FragmentMaskAMD";
			case spv::CapabilityStencilExportEXT:
				return "StencilExportEXT";
			case spv::CapabilityImageReadWriteLodAMD:
				return "ImageReadWriteLodAMD";
			case spv::CapabilitySampleMaskOverrideCoverageNV:
				return "SampleMaskOverrideCoverageNV";
			case spv::CapabilityGeometryShaderPassthroughNV:
				return "GeometryShaderPassthroughNV";
			case spv::CapabilityShaderViewportIndexLayerEXT:
				return "ShaderViewportIndexLayer";
			case spv::CapabilityShaderViewportMaskNV:
				return "ShaderViewportMaskNV";
			case spv::CapabilityShaderStereoViewNV:
				return "ShaderStereoViewNV";
			case spv::CapabilityPerViewAttributesNV:
				return "PerViewAttributesNV";
			case spv::CapabilitySubgroupShuffleINTEL:
				return "SubgroupShuffleINTEL";
			case spv::CapabilitySubgroupBufferBlockIOINTEL:
				return "SubgroupBufferBlockIOINTEL";
			case spv::CapabilitySubgroupImageBlockIOINTEL:
				return "SubgroupImageBlockIOINTEL";
			default:
				assert( false && "Unsupported Capability" );
				return "Undefined";
			}
		}

		std::string getName( spv::AddressingModel value )
		{
			switch ( value )
			{
			case spv::AddressingModelLogical:
				return "Logical";
			case spv::AddressingModelPhysical32:
				return "Physical32";
			case spv::AddressingModelPhysical64:
				return "Physical64";
			default:
				assert( false && "Unsupported AddressingModel" );
				return "Undefined";
			}
		}

		std::string getName( spv::MemoryModel value )
		{
			switch ( value )
			{
			case spv::MemoryModelSimple:
				return "Simple";
			case spv::MemoryModelGLSL450:
				return "GLSL450";
			case spv::MemoryModelOpenCL:
				return "OpenCL";
			default:
				assert( false && "Unsupported MemoryModel" );
				return "Undefined";
			}
		}

		std::string getName( spv::ExecutionModel value )
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
			default:
				assert( false && "Unsupported ExecutionModel" );
				return "Undefined";
			}
		}

		std::string getName( spv::ExecutionMode value )
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
			case spv::ExecutionModePostDepthCoverage:
				return "PostDepthCoverage";
			case spv::ExecutionModeStencilRefReplacingEXT:
				return "StencilRefReplacingEXT";
			default:
				assert( false && "Unsupported ExecutionMode" );
				return "Undefined";
			}
		}

		std::string getName( spv::AccessQualifier value )
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
				assert( false && "Unsupported AccessQualifier" );
				return "Undefined";
			}
		}

		std::string getName( spv::GLSLstd450 value )
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
				assert( false && "Unsupported GLSLstd450" );
				return "Undefined";
			}
		}

		std::string getName( spv::StorageClass value )
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
			default:
				assert( false && "Unsupported StorageClass" );
				return "Undefined";
			}
		}

		std::string getName( spv::ImageFormat value )
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
				assert( false && "Unsupported ImageFormat" );
				return "Undefined";
			}
		}

		std::string getName( spv::Dim value )
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
				assert( false && "Unsupported Dim" );
				return "Undefined";
			}
		}

		std::string getName( spv::BuiltIn value )
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
			default:
				assert( false && "Unsupported BuiltIn" );
				return "Undefined";
			}
		}

		std::string getName( spv::Decoration value )
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
			case spv::DecorationHlslCounterBufferGOOGLE:
				return "HlslCounterBufferGOOGLE";
			case spv::DecorationHlslSemanticGOOGLE:
				return "HlslSemanticGOOGLE";
			default:
				assert( false && "Unsupported Decoration" );
				return "Undefined";
			}
		}

		std::string getName( spv::FunctionParameterAttribute value )
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
				assert( false && "Unsupported FunctionParameterAttribute" );
				return "Undefined";
			}
		}

		std::string getName( spv::FPRoundingMode value )
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
				assert( false && "Unsupported FPRoundingMode" );
				return "Undefined";
			}
		}

		std::string getName( spv::LinkageType value )
		{
			switch ( value )
			{
			case spv::LinkageTypeExport:
				return "Export";
			case spv::LinkageTypeImport:
				return "Import";
			default:
				assert( false && "Unsupported LinkageType" );
				return "Undefined";
			}
		}

		std::string getName( spv::Scope value )
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
			default:
				//assert( false && "Unsupported Scope" );
				return "Undefined";
			}
		}

		std::string getSelectionControlName( uint32_t value )
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

		std::string getMemoryAccessName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::MemoryAccessAlignedMask ) )
			{
				stream << sep << "AlignedMask";
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

			if ( value == uint32_t( spv::MemoryAccessMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		std::string getLoopControlName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

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

			if ( value & uint32_t( spv::LoopControlDontUnrollMask ) )
			{
				stream << sep << "DontUnroll";
				sep = "|";
			}

			if ( value & uint32_t( spv::LoopControlUnrollMask ) )
			{
				stream << sep << "Unroll";
				sep = "|";
			}

			if ( value == uint32_t( spv::LoopControlMaskNone ) )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		std::string getImageOperandsName( uint32_t value )
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

			if ( !value )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		std::string getMemorySemanticsName( uint32_t value )
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

			if ( !value )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		std::string getFunctionControlMaskName( uint32_t value )
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

			if ( !value )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		std::string getFPFastMathModeName( uint32_t value )
		{
			auto stream = getStream();
			std::string sep;
			stream << "[";

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeNotNaNMask ) )
			{
				stream << sep << "NotNaN";
				sep = "|";
			}

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeNotInfMask ) )
			{
				stream << sep << "NotInf";
				sep = "|";
			}

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeNSZMask ) )
			{
				stream << sep << "NSZ";
				sep = "|";
			}

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeAllowRecipMask ) )
			{
				stream << sep << "AllowRecip";
				sep = "|";
			}

			if ( !value )
			{
				stream << sep << "None";
			}

			stream << "]";
			return stream.str();
		}

		template< typename InstructionType >
		inline void checkType( Instruction const & instruction )
		{
			return assertType< InstructionType::op
				, InstructionType::hasReturnTypeId
				, InstructionType::hasResultId
				, InstructionType::operandsCount
				, InstructionType::hasName
				, InstructionType::hasLabels >( instruction );
		}

		struct NameCache
		{
			using IdNames = std::map< spv::Id, std::string >;

			void add( spv::Id id, std::string const & name )
			{
				names.emplace( id, name );
			}

			void addType( spv::Id id, std::string const & name )
			{
				add( id, name );
				types.emplace( id, name );
			}

			std::string getFloatTypeName( Instruction const & instruction )const
			{
				assert( instruction.op.opCode == spv::OpTypeFloat );
				auto width = instruction.operands[0];
				std::string result;

				if ( width <= 16u )
				{
					result = "half";
				}
				else if ( width <= 32 )
				{
					result = "float";
				}
				else
				{
					result = "double";
				}

				return result;
			}

			std::string getIntTypeName( Instruction const & instruction )const
			{
				assert( instruction.op.opCode == spv::OpTypeInt );
				auto width = instruction.operands[0];
				auto signedness = instruction.operands[1];
				std::string result;

				if ( width <= 16u )
				{
					result = "short";
				}
				else if ( width <= 32 )
				{
					result = "int";
				}
				else
				{
					result = "int64";
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

			std::string getVecTypeName( Instruction const & instruction )const
			{
				assert( instruction.op.opCode == spv::OpTypeVector );
				std::string result = "v";
				auto componentType = instruction.operands[0];
				auto componentCount = instruction.operands[1];
				result += std::to_string( componentCount );
				auto it = types.find( componentType );
				assert( it != types.end() );
				result += it->second;
				return result;
			}

			std::string getMatTypeName( Instruction const & instruction )const
			{
				assert( instruction.op.opCode == spv::OpTypeMatrix );
				std::string result = "m";
				auto componentType = instruction.operands[0];
				auto componentCount = instruction.operands[1];
				result += std::to_string( componentCount );
				auto it = types.find( componentType );
				assert( it != types.end() );
				result += it->second;
				return result;
			}

			std::string getPtrTypeName( Instruction const & instruction )const
			{
				assert( instruction.op.opCode == spv::OpTypePointer );
				auto storageClass = spv::StorageClass( instruction.operands[0] );
				auto pointedType = instruction.operands[1];
				auto it = types.find( pointedType );
				assert( it != types.end() );
				auto result = it->second;

				switch ( storageClass )
				{
				case spv::StorageClassUniformConstant:
					result += "UniformConstPtr";
					break;
				case spv::StorageClassInput:
					result += "InputPtr";
					break;
				case spv::StorageClassUniform:
					result += "UniformPtr";
					break;
				case spv::StorageClassOutput:
					result += "OutputPtr";
					break;
				case spv::StorageClassWorkgroup:
					result += "WorkgroupPtr";
					break;
				case spv::StorageClassCrossWorkgroup:
					result += "CrossWorkgroupPtr";
					break;
				case spv::StorageClassPrivate:
					result += "PrivatePtr";
					break;
				case spv::StorageClassFunction:
					result += "FunctionPtr";
					break;
				case spv::StorageClassGeneric:
					result += "GenericPtr";
					break;
				case spv::StorageClassPushConstant:
					result += "PushConstantPtr";
					break;
				case spv::StorageClassAtomicCounter:
					result += "AtomicCounterPtr";
					break;
				case spv::StorageClassImage:
					result += "ImagePtr";
					break;
				case spv::StorageClassStorageBuffer:
					result += "StorageBufferPtr";
					break;
				default:
					break;
				}

				return result;
			}

			std::string get( spv::Id id )const
			{
				std::string result;
				auto it = names.find( id );

				if ( it != names.end() )
				{
					result = "(" + it->second + ")";
				}

				return result;
			}

			IdNames names;
			IdNames types;
		};

		std::string writeId( spv::Id const & id )
		{
			auto stream = getStream();
			stream << std::setw( 5 ) << std::right << ( "%" + std::to_string( id ) );
			return stream.str();
		}

		std::string write( spv::Id id
			, NameCache const & names )
		{
			auto stream = getStream();
			stream << " %" << id << names.get( id );
			return stream.str();
		}

		std::ostream & write( Optional< spv::Id > id
			, NameCache const & names
			, std::ostream & stream )
		{
			if ( bool( id ) )
			{
				stream << write( id.value(), names );
			}

			return stream;
		}

		std::ostream & write( spirv::IdList const & ids
			, NameCache const & names
			, std::ostream & stream )
		{
			for ( auto & id : ids )
			{
				write( id, names, stream );
			}

			return stream;
		}

		std::ostream & writeExtension( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );

			if ( opCode == spv::OpExtInstImport )
			{
				checkType< ExtInstImportInstruction >( *instruction );
				names.add( instruction->resultId.value(), instruction->name.value() );
				stream << writeId( instruction->resultId.value() ) << " =";
				stream << " " << spirv::getOperatorName( opCode );
				stream << " \"" << instruction->name.value() << "\"";
				write( instruction->operands, names, stream );
			}
			else if ( opCode == spv::OpExtension )
			{
				checkType< ExtensionInstruction >( *instruction );
				stream << "        " << spirv::getOperatorName( opCode );
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeDebug( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );
			assert( opCode == spv::OpName
				|| opCode == spv::OpMemberName
				|| opCode == spv::OpSource );
			stream << "        " << spirv::getOperatorName( opCode );

			if ( opCode == spv::OpName )
			{
				checkType< NameInstruction >( *instruction );
				names.add( instruction->resultId.value(), instruction->name.value() );
				write( instruction->resultId, names, stream );
				stream << " \"" << instruction->name.value() << "\"";
			}
			else if ( opCode == spv::OpMemberName )
			{
				checkType< MemberNameInstruction >( *instruction );
				write( instruction->returnTypeId.value(), names, stream );
				stream << " " << instruction->resultId.value();
				stream << " \"" << instruction->name.value() << "\"";
			}
			else if ( opCode == spv::OpSource )
			{
				checkType< SourceInstruction >( *instruction );
				assert( instruction->operands.size() >= 2u );
				stream << " " << getSourceLanguageName( instruction->operands[0] );
				stream << " " << instruction->operands[1];

				if ( instruction->operands.size() > 2 )
				{
					stream << " " << instruction->operands[2];
				}

				if ( bool( instruction->name ) )
				{
					stream << " \"" << instruction->name.value() << "\"";
				}
			}

			return stream;
		}

		std::ostream & writeDecoration( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );
			assert( opCode == spv::OpDecorate || opCode == spv::OpMemberDecorate );
			stream << "        " << spirv::getOperatorName( opCode );
			auto it = instruction->operands.begin();

			if ( opCode == spv::OpDecorate )
			{
				checkType< DecorateInstruction >( *instruction );
				write( *it, names, stream );
				++it;
			}
			else if ( opCode == spv::OpMemberDecorate )
			{
				checkType< MemberDecorateInstruction >( *instruction );
				write( *it, names, stream );
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
				stream << " \"" << instruction->name.value() << "\"";
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
				|| decoration == spv::DecorationSecondaryViewportRelativeNV )
			{
				stream << " " << *it;
				++it;
			}

			return stream;
		}

		std::ostream & writeType( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			stream << writeId( instruction->resultId.value() ) << " =";
			auto opCode = spv::Op( instruction->op.opCode );
			stream << " " << spirv::getOperatorName( opCode );

			if ( opCode == spv::OpTypeFunction )
			{
				checkType< FunctionTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "func" );
				// First being return type ID, other ones being parameters type ID.
				for ( auto & operand : instruction->operands )
				{
					write( operand, names, stream );
				}
			}
			else if ( opCode == spv::OpTypePointer )
			{
				// Storage class then Type ID.
				checkType< PointerTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), names.getPtrTypeName( *instruction ) );
				stream << " " << getName( spv::StorageClass( instruction->operands[0] ) );
				write( instruction->operands[1], names, stream );
			}
			else if ( opCode == spv::OpTypeStruct )
			{
				checkType< StructTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "struct" );
				// Members IDs.
				for ( auto & operand : instruction->operands )
				{
					write( operand, names, stream );
				}
			}
			else if ( opCode == spv::OpTypeBool )
			{
				checkType< BooleanTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "bool" );
			}
			else if ( opCode == spv::OpTypeInt )
			{
				checkType< IntTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), names.getIntTypeName( *instruction ) );
				// Width then Signedness.
				stream << " " << instruction->operands[0];
				stream << " " << instruction->operands[1];
			}
			else if ( opCode == spv::OpTypeFloat )
			{
				checkType< FloatTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), names.getFloatTypeName( *instruction ) );
				// Width.
				stream << " " << instruction->operands[0];
			}
			else if ( opCode == spv::OpTypeVector )
			{
				checkType< VectorTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), names.getVecTypeName( *instruction ) );
				// Component type and components count.
				write( instruction->operands[0], names, stream );
				stream << " " << instruction->operands[1];
			}
			else if ( opCode == spv::OpTypeMatrix )
			{
				checkType< MatrixTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), names.getMatTypeName( *instruction ) );
				// Component type and components count.
				write( instruction->operands[0], names, stream );
				stream << " " << instruction->operands[1];
			}
			else if ( opCode == spv::OpTypeArray )
			{
				checkType< ArrayTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "array" );
				// Component type and components count.
				write( instruction->operands[0], names, stream );
				write( instruction->operands[1], names, stream );
			}
			else if ( opCode == spv::OpTypeImage )
			{
				checkType< ImageTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "img" );
				// Sampled Type, Dim, Depth, Arrayed, MS, Sampled, Format.
				write( instruction->operands[0], names, stream );
				stream << " " << getName( spv::Dim( instruction->operands[1] ) );
				stream << " " << instruction->operands[2];
				stream << " " << instruction->operands[3];
				stream << " " << instruction->operands[4];
				stream << " " << instruction->operands[5];
				stream << " " << getName( spv::ImageFormat( instruction->operands[6] ) );

				// Optional Access Qualifier
				if ( instruction->operands.size() > 7 )
				{
					stream << " " << getName( spv::AccessQualifier( instruction->operands[7] ) );
				}
			}
			else if ( opCode == spv::OpTypeSampledImage )
			{
				checkType< SampledImageTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "simg" );
				// Image type.
				write( instruction->operands[0], names, stream );
			}
			else if ( opCode == spv::OpTypeRuntimeArray )
			{
				checkType< RuntimeArrayTypeInstruction >( *instruction );
				names.addType( instruction->resultId.value(), "dynarray" );
				// Element type.
				write( instruction->operands[0], names, stream );
			}

			return stream;
		}

		std::ostream & writeGlobalVariable( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< VariableInstruction >( *instruction );
			std::string result;
			auto opCode = spv::Op( instruction->op.opCode );
			stream << writeId( instruction->resultId.value() ) << " =";
			stream << " " << spirv::getOperatorName( opCode );
			write( instruction->returnTypeId.value(), names, stream );
			stream << " " << getName( spv::StorageClass( instruction->operands[0] ) );

			for ( size_t i = 1u; i < instruction->operands.size(); ++i )
			{
				write( instruction->operands[i], names, stream );
			}

			return stream;
		}

		std::ostream & writeConstant( spirv::InstructionPtr const & instruction
			, ast::type::Kind type
			, NameCache & names
			, std::ostream & stream )
		{
			assert( bool( instruction->resultId ) );
			assert( bool( instruction->returnTypeId ) );
			stream << writeId( instruction->resultId.value() ) << " =";
			auto opCode = spv::Op( instruction->op.opCode );
			stream << " " << spirv::getOperatorName( opCode );
			write( instruction->returnTypeId.value(), names, stream );

			if ( opCode == spv::OpConstant )
			{
				checkType< ConstantInstruction >( *instruction );
				switch ( type )
				{
				case ast::type::Kind::eBoolean:
					names.add( instruction->resultId.value(), std::to_string( bool( instruction->operands[0] ) ) );
					stream << " " << bool( instruction->operands[0] );
					break;
				case ast::type::Kind::eInt:
					names.add( instruction->resultId.value(), std::to_string( int32_t( instruction->operands[0] ) ) );
					stream << " " << int32_t( instruction->operands[0] );
					break;
				case ast::type::Kind::eUInt:
					names.add( instruction->resultId.value(), std::to_string( instruction->operands[0] ) );
					stream << " " << instruction->operands[0];
					break;
				case ast::type::Kind::eFloat:
					names.add( instruction->resultId.value(), std::to_string( *reinterpret_cast< float const * >( instruction->operands.data() ) ) );
					stream << " " << *reinterpret_cast< float const * >( instruction->operands.data() );
					break;
				case ast::type::Kind::eDouble:
					assert( instruction->operands.size() >= 2 );
					{
						names.add( instruction->resultId.value(), std::to_string( *reinterpret_cast< double const * >( instruction->operands.data() ) ) );
						stream << " " << *reinterpret_cast< double const * >( instruction->operands.data() );
					}
					break;
				default:
					break;
				}
			}
			else if ( opCode == spv::OpConstantComposite )
			{
				checkType< ConstantCompositeInstruction >( *instruction );
				names.add( instruction->resultId.value(), "const" );
				write( instruction->operands, names, stream );
			}

			return stream;
		}

		std::ostream & writeSpecConstant( spirv::InstructionPtr const & instruction
			, ast::type::Kind type
			, NameCache & names
			, std::ostream & stream )
		{
			assert( bool( instruction->resultId ) );
			assert( bool( instruction->returnTypeId ) );
			stream << writeId( instruction->resultId.value() ) << " =";
			auto opCode = spv::Op( instruction->op.opCode );
			stream << " " << spirv::getOperatorName( opCode );
			write( instruction->returnTypeId.value(), names, stream );

			if ( opCode == spv::OpSpecConstant )
			{
				checkType< SpecConstantInstruction >( *instruction );
				switch ( type )
				{
				case ast::type::Kind::eBoolean:
					names.add( instruction->resultId.value(), std::to_string( bool( instruction->operands[0] ) ) );
					stream << " " << bool( instruction->operands[0] );
					break;
				case ast::type::Kind::eInt:
					names.add( instruction->resultId.value(), std::to_string( int32_t( instruction->operands[0] ) ) );
					stream << " " << int32_t( instruction->operands[0] );
					break;
				case ast::type::Kind::eUInt:
					names.add( instruction->resultId.value(), std::to_string( instruction->operands[0] ) );
					stream << " " << instruction->operands[0];
					break;
				case ast::type::Kind::eFloat:
					names.add( instruction->resultId.value(), std::to_string( *reinterpret_cast< float const * >( instruction->operands.data() ) ) );
					stream << " " << *reinterpret_cast< float const * >( instruction->operands.data() );
					break;
				case ast::type::Kind::eDouble:
					assert( instruction->operands.size() >= 2 );
					{
						names.add( instruction->resultId.value(), std::to_string( *reinterpret_cast< double const * >( instruction->operands.data() ) ) );
						stream << " " << *reinterpret_cast< double const * >( instruction->operands.data() );
					}
					break;
				default:
					break;
				}
			}
			else if ( opCode == spv::OpSpecConstantComposite )
			{
				checkType< SpecConstantCompositeInstruction >( *instruction );
				names.add( instruction->resultId.value(), "specconst" );
				write( instruction->operands, names, stream );
			}

			return stream;
		}

		std::ostream & writeGlobalDeclaration( spirv::InstructionPtr const & instruction
			, NameCache & names
			, spirv::Module const & module
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );

			if ( opCode == spv::OpConstant
				|| opCode == spv::OpConstantComposite )
			{
				writeConstant( instruction, module.getLiteralType( instruction->resultId.value() ), names, stream ) << "\n";
			}
			else if ( opCode == spv::OpSpecConstant
				|| opCode == spv::OpSpecConstantComposite )
			{
				writeSpecConstant( instruction, module.getLiteralType( instruction->resultId.value() ), names, stream ) << "\n";
			}
			else if ( opCode == spv::OpVariable )
			{
				writeGlobalVariable( instruction, names, stream ) << "\n";
			}
			else
			{
				writeType( instruction, names, stream ) << "\n";
			}

			return stream;
		}

		std::ostream & writeGlobalDeclarations( spirv::InstructionList const & instructions
			, NameCache & names
			, spirv::Module const & module
			, std::ostream & stream )
		{
			for ( auto & instruction : instructions )
			{
				writeGlobalDeclaration( instruction, names, module, stream );
			}

			return stream;
		}

		std::ostream & writeExtInst( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< ExtInstInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			stream << " " << getName( spv::GLSLstd450( instruction->operands[1] ) );

			for ( size_t i = 2u; i < instruction->operands.size(); ++i )
			{
				write( instruction->operands[i], names, stream );
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeFuncVariable( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< VariableInstruction >( *instruction );
			stream << " " << getName( spv::StorageClass( instruction->operands[0] ) );

			for ( size_t i = 1u; i < instruction->operands.size(); ++i )
			{
				write( instruction->operands[i], names, stream );
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSample( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );

			if ( instruction->operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[2] );

				for ( size_t i = 3u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSampleDref( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );
			// Dref
			write( instruction->operands[2], names, stream );

			if ( instruction->operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[3] );

				for ( size_t i = 4u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSampleProj( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );

			if ( instruction->operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[2] );

				for ( size_t i = 3u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSampleProjDref( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );
			// Dref
			write( instruction->operands[2], names, stream );

			if ( instruction->operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[3] );

				for ( size_t i = 4u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageFetch( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );

			if ( instruction->operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[2] );

				for ( size_t i = 3u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageGather( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );
			// Component
			write( instruction->operands[2], names, stream );

			if ( instruction->operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[3] );

				for ( size_t i = 4u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageDrefGather( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			// Image
			write( instruction->operands[0], names, stream );
			// Coordinate
			write( instruction->operands[1], names, stream );
			// Dref
			write( instruction->operands[2], names, stream );

			if ( instruction->operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction->operands[3] );

				for ( size_t i = 4u; i < instruction->operands.size(); ++i )
				{
					write( instruction->operands[i], names, stream );
				}
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeStore( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< StoreInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			write( instruction->operands[1], names, stream );

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeLoad( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< LoadInstruction >( *instruction );
			write( instruction->operands[0], names, stream );

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeCopyMemory( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< CopyMemoryInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			write( instruction->operands[1], names, stream );

			if ( instruction->operands.size() > 2u )
			{
				stream << " " << getMemoryAccessName( instruction->operands[2] );
			}

			return stream;
		}

		std::ostream & writeSwitch( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< SwitchInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			write( instruction->operands[1], names, stream );

			if ( bool( instruction->labels ) )
			{
				for ( auto & label : instruction->labels.value() )
				{
					stream << " " << label.first;
					write( label.second, names, stream );
				}
			}

			return stream;
		}

		std::ostream & writeVectorShuffle( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< VectorShuffleInstruction >( *instruction );
			write( instruction->operands[0], names, stream );

			if ( instruction->operands[1] == spv::Id( spv::OpUndef ) )
			{
				stream << " Undef";
			}
			else
			{
				write( instruction->operands[1], names, stream );
			}

			for ( size_t i = 2u; i < instruction->operands.size(); ++i )
			{
				stream << " " << instruction->operands[i];
			}

			if ( bool( instruction->name ) )
			{
				stream << " \"" << instruction->name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeCompositeExtract( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< CompositeExtractInstruction >( *instruction );
			write( instruction->operands[0], names, stream );

			for ( auto i = 1u; i < instruction->operands.size(); ++i )
			{
				stream << " " << instruction->operands[i];
			}

			return stream;
		}

		std::ostream & writeSpecConstantOp( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< SpecConstantInstruction >( *instruction );
			stream << " " << spirv::getOperatorName( spv::Op( instruction->operands[0] ) );

			for ( size_t i = 1u; i < instruction->operands.size(); ++i )
			{
				write( instruction->operands[i], names, stream );
			}

			return stream;
		}

		std::ostream & writeLoopMergeOp( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< LoopMergeInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			write( instruction->operands[1], names, stream );
			stream << " " << getLoopControlName( instruction->operands[2] );
			return stream;
		}

		std::ostream & writeSelectionMergeOp( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< SelectionMergeInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			stream << " " << getSelectionControlName( instruction->operands[1] );
			return stream;
		}

		std::ostream & writeBranch( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< BranchInstruction >( *instruction );
			write( instruction->operands[0], names, stream );
			return stream;
		}

		std::ostream & writeBranchConditional( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			checkType< BranchConditionalInstruction >( *instruction );
			// Condition
			write( instruction->operands[0], names, stream );
			// True label
			write( instruction->operands[1], names, stream );
			// False label
			write( instruction->operands[2], names, stream );

			if ( instruction->operands.size() > 3u )
			{
				// Optional Weights.
				assert( instruction->operands.size() == 5u );
				stream << " " << instruction->operands[3];
				stream << " " << instruction->operands[4];
			}

			return stream;
		}

		std::ostream & writeAtomicAdd( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			assert( instruction->operands.size() == 4u );
			write( instruction->operands[0], names, stream );
			stream << " " << getName( spv::Scope( instruction->operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction->operands[2] );
			write( instruction->operands[3], names, stream );
			return stream;
		}

		std::ostream & writeAtomicMinMax( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			assert( instruction->operands.size() == 4u );
			write( instruction->operands[0], names, stream );
			stream << " " << getName( spv::Scope( instruction->operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction->operands[2] );
			write( instruction->operands[3], names, stream );
			return stream;
		}

		std::ostream & writeAtomicAndOrXor( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			assert( instruction->operands.size() == 4u );
			write( instruction->operands[0], names, stream );
			stream << " " << getName( spv::Scope( instruction->operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction->operands[2] );
			write( instruction->operands[3], names, stream );
			return stream;
		}

		std::ostream & writeAtomicExchange( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			assert( instruction->operands.size() == 4u );
			write( instruction->operands[0], names, stream );
			stream << " " << getName( spv::Scope( instruction->operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction->operands[2] );
			write( instruction->operands[3], names, stream );
			return stream;
		}

		std::ostream & writeAtomicCompExchange( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			assert( instruction->operands.size() == 6u );
			write( instruction->operands[0], names, stream );
			stream << " " << getName( spv::Scope( instruction->operands[1] ) );
			stream << " " << getMemorySemanticsName( instruction->operands[2] );
			stream << " " << getMemorySemanticsName( instruction->operands[3] );
			write( instruction->operands[4], names, stream );
			write( instruction->operands[5], names, stream );
			return stream;
		}

		std::ostream & writeBlockInstruction( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );

			if ( bool( instruction->resultId ) )
			{
				stream << writeId( instruction->resultId.value() ) << " =";
			}
			else
			{
				stream << "       ";
			}

			stream << " " << spirv::getOperatorName( opCode );

			if ( bool( instruction->returnTypeId ) )
			{
				stream << write( instruction->returnTypeId.value(), names );
			}

			if ( opCode == spv::OpExtInst )
			{
				writeExtInst( instruction, names, stream );
			}
			else if ( opCode == spv::OpVariable )
			{
				writeFuncVariable( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageSampleImplicitLod
				|| opCode == spv::OpImageSampleExplicitLod )
			{
				writeImageSample( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageSampleDrefImplicitLod
				|| opCode == spv::OpImageSampleDrefExplicitLod )
			{
				writeImageSampleDref( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageSampleProjImplicitLod
				|| opCode == spv::OpImageSampleProjExplicitLod )
			{
				writeImageSampleProj( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageSampleProjDrefImplicitLod
				|| opCode == spv::OpImageSampleProjDrefExplicitLod )
			{
				writeImageSampleProjDref( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageFetch )
			{
				writeImageFetch( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageGather )
			{
				writeImageGather( instruction, names, stream );
			}
			else if ( opCode == spv::OpImageDrefGather )
			{
				writeImageDrefGather( instruction, names, stream );
			}
			else if ( opCode == spv::OpStore )
			{
				writeStore( instruction, names, stream );
			}
			else if ( opCode == spv::OpLoad )
			{
				writeLoad( instruction, names, stream );
			}
			else if ( opCode == spv::OpCopyMemory )
			{
				writeCopyMemory( instruction, names, stream );
			}
			else if ( opCode == spv::OpSwitch )
			{
				writeSwitch( instruction, names, stream );
			}
			else if ( opCode == spv::OpVectorShuffle )
			{
				writeVectorShuffle( instruction, names, stream );
			}
			else if ( opCode == spv::OpCompositeExtract )
			{
				writeCompositeExtract( instruction, names, stream );
			}
			else if ( opCode == spv::OpSpecConstantOp )
			{
				writeSpecConstantOp( instruction, names, stream );
			}
			else if ( opCode == spv::OpLoopMerge )
			{
				writeLoopMergeOp( instruction, names, stream );
			}
			else if ( opCode == spv::OpSelectionMerge )
			{
				writeSelectionMergeOp( instruction, names, stream );
			}
			else if ( opCode == spv::OpBranch )
			{
				writeBranch( instruction, names, stream );
			}
			else if ( opCode == spv::OpBranchConditional )
			{
				writeBranchConditional( instruction, names, stream );
			}
			else if ( opCode == spv::OpAtomicIAdd )
			{
				writeAtomicAdd( instruction, names, stream );
			}
			else if ( opCode == spv::OpAtomicUMin
				|| opCode == spv::OpAtomicSMin
				|| opCode == spv::OpAtomicUMax
				|| opCode == spv::OpAtomicSMax )
			{
				writeAtomicMinMax( instruction, names, stream );
			}
			else if ( opCode == spv::OpAtomicAnd
				|| opCode == spv::OpAtomicOr
				|| opCode == spv::OpAtomicXor )
			{
				writeAtomicAndOrXor( instruction, names, stream );
			}
			else if ( opCode == spv::OpAtomicExchange )
			{
				writeAtomicExchange( instruction, names, stream );
			}
			else if ( opCode == spv::OpAtomicCompareExchange )
			{
				writeAtomicCompExchange( instruction, names, stream );
			}
			else
			{
				write( instruction->operands, names, stream );

				if ( bool( instruction->name ) )
				{
					stream << " \"" << instruction->name.value() << "\"";
				}
			}

			return stream;
		}

		template< typename Type >
		std::ostream & writeInstructions( std::vector< Type > const & instructions
			, NameCache & names
			, std::ostream & ( *writer )( Type const &, NameCache &, std::ostream & )
			, std::ostream & stream )
		{
			for ( auto & instruction : instructions )
			{
				writer( instruction, names, stream ) << "\n";
			}

			return stream;
		}

		std::ostream & writeBlock( spirv::Block const & block
			, NameCache & names
			, std::ostream & stream )
		{
			writeInstructions( block.instructions, names, writeBlockInstruction, stream );
			writeBlockInstruction( block.blockEnd, names, stream );
			return stream;
		}

		std::ostream & writeFunctionDecl( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );
			stream << writeId( instruction->resultId.value() ) << " =";
			stream << " " << spirv::getOperatorName( opCode );
			stream << write( instruction->returnTypeId.value(), names );

			if ( opCode == spv::OpFunction )
			{
				stream << " " << getFunctionControlMaskName( instruction->operands[0] );
				stream << " " << write( instruction->operands[1], names );
			}

			return stream;
		}

		std::ostream & writeFunction( spirv::Function const & function
			, NameCache & names
			, std::ostream & stream )
		{
			writeInstructions( function.declaration, names, writeFunctionDecl, stream );
			writeInstructions( function.cfg.blocks, names, writeBlock, stream );
			return stream;
		}

		std::ostream & writeCapability( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );
			stream << "        " << spirv::getOperatorName( opCode );
			stream << " " << getName( spv::Capability( instruction->operands[0] ) );
			return stream;
		}

		std::ostream & writeImport( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			return stream;
		}

		std::ostream & writeMemoryModel( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );
			stream << "        " + spirv::getOperatorName( opCode );
			stream << " " + getName( spv::AddressingModel( instruction->operands[0] ) );
			stream << " " + getName( spv::MemoryModel( instruction->operands[1] ) );
			stream << "\n";
			return stream;
		}

		std::ostream & writeEntryPoint( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );
			stream << "        " + spirv::getOperatorName( opCode );
			stream << " " + getName( spv::ExecutionModel( instruction->returnTypeId.value() ) );
			stream << " %" + std::to_string( instruction->resultId.value() );
			stream << " \"" + instruction->name.value() + "\"";

			for ( size_t i = 0u; i < instruction->operands.size(); ++i )
			{
				stream << " %" + std::to_string( instruction->operands[i] );
			}

			stream << "\n";
			return stream;
		}

		std::ostream & writeExecutionMode( spirv::InstructionPtr const & instruction
			, NameCache & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction->op.opCode );

			if ( opCode == spv::OpExecutionMode )
			{
				stream << "        " + spirv::getOperatorName( opCode );
				stream << " %" + std::to_string( instruction->operands[0] );
				stream << " " + getName( spv::ExecutionMode( instruction->operands[1] ) );

				for ( size_t i = 2u; i < instruction->operands.size(); ++i )
				{
					stream << " " + std::to_string( instruction->operands[i] );
				}
			}

			return stream;
		}

		std::ostream & writeHeader( spirv::IdList const & ids
			, std::ostream & stream )
		{
			assert( ids.size() == 5u );
			stream << "; Magic:     0x" << std::hex << std::setw( 8u ) << std::setfill( '0' ) << ids[0] << std::endl;
			stream << "; Version:   0x" << std::hex << std::setw( 8u ) << std::setfill( '0' ) << ids[1] << std::endl;
			stream << "; Generator: 0x" << std::hex << std::setw( 8u ) << std::setfill( '0' ) << ids[2] << std::endl;
			stream << "; Bound:     " << std::dec << ids[3] << std::endl;
			stream << "; Schema:    " << ids[4] << std::endl;
			return stream;
		}

		std::ostream & write( spirv::Module const & module
			, bool doWriteHeader
			, std::ostream & stream )
		{
			NameCache names;

			if ( doWriteHeader )
			{
				writeHeader( module.header, stream ) << std::endl;
				writeInstructions( module.capabilities, names, writeCapability, stream );
				writeInstructions( module.extensions, names, writeExtension, stream );
				writeInstructions( module.imports, names, writeImport, stream );
				writeMemoryModel( module.memoryModel, names, stream );
				writeEntryPoint( module.entryPoint, names, stream );
				writeInstructions( module.executionModes, names, writeExecutionMode, stream ) << std::endl;
			}

			stream << "; Debug" << std::endl;
			writeInstructions( module.debug, names, writeDebug, stream ) << std::endl;
			stream << "; Decorations" << std::endl;
			writeInstructions( module.decorations, names, writeDecoration, stream ) << std::endl;
			stream << "; Types, Constants, and Global Variables" << std::endl;
			writeGlobalDeclarations( module.globalDeclarations, names, module, stream ) << std::endl;
			stream << "; Functions" << std::endl;
			writeInstructions( module.functions, names, writeFunction, stream ) << std::endl;
			return stream;
		}

		template< typename T >
		void count( std::vector< T > const & values
			, size_t & result );

		template< typename T >
		void count( Optional< T > const & value
			, size_t & result );

		void count( spv::Id const & id
			, size_t & result )
		{
			++result;
		}

		void count( spirv::Op const & op
			, size_t & result )
		{
			++result;
		}

		void count( spirv::InstructionPtr const & instruction
			, size_t & result )
		{
			count( instruction->op, result );
			count( instruction->returnTypeId, result );
			count( instruction->resultId, result );
			count( instruction->operands, result );
			count( instruction->packedName, result );
		}

		void count( spirv::Block const & block
			, size_t & result )
		{
			count( block.instructions, result );
			count( block.blockEnd, result );
		}

		void count( spirv::ControlFlowGraph const & cfg
			, size_t & result )
		{
			count( cfg.blocks, result );
		}

		void count( spirv::Function const & function
			, size_t & result )
		{
			count( function.declaration, result );
			count( function.cfg, result );
		}

		size_t count( spirv::Module const & module )
		{
			size_t result{};
			count( module.header, result );
			count( module.capabilities, result );
			count( module.extensions, result );
			count( module.imports, result );
			count( module.memoryModel, result );
			count( module.entryPoint, result );
			count( module.executionModes, result );
			count( module.debug, result );
			count( module.decorations, result );
			count( module.globalDeclarations, result );
			count( module.functions, result );
			return result;
		}

		template< typename T >
		void count( std::vector< T > const & values
			, size_t & result )
		{
			for ( auto & value : values )
			{
				count( value, result );
			}
		}

		template< typename T >
		void count( Optional< T > const & value
			, size_t & result )
		{
			if ( bool( value ) )
			{
				count( value.value(), result );
			}
		}

		template< typename T >
		void serialize( std::vector< T > const & values
			, std::vector< uint32_t > & result );

		template< typename T >
		void serialize( Optional< T > const & value
			, std::vector< uint32_t > & result );

		void serialize( spv::Id const & id
			, std::vector< uint32_t > & result )
		{
			result.push_back( id );
		}

		void serialize( spirv::Op const & op
			, std::vector< uint32_t > & result )
		{
			result.push_back( uint32_t( op.op ) );
		}

		void serialize( spirv::InstructionPtr const & instruction
			, std::vector< uint32_t > & result )
		{
			Instruction::serialize( result, *instruction );
		}

		void serialize( spirv::Block const & block
			, std::vector< uint32_t > & result )
		{
			serialize( block.instructions, result );
			serialize( block.blockEnd, result );
		}

		void serialize( spirv::ControlFlowGraph const & cfg
			, std::vector< uint32_t > & result )
		{
			serialize( cfg.blocks, result );
		}

		void serialize( spirv::Function const & function
			, std::vector< uint32_t > & result )
		{
			serialize( function.declaration, result );
			serialize( function.cfg, result );
		}

		void serialize( spirv::Module const & module
			, std::vector< uint32_t > & result )
		{
			serialize( module.header, result );
			serialize( module.capabilities, result );
			serialize( module.extensions, result );
			serialize( module.imports, result );
			serialize( module.memoryModel, result );
			serialize( module.entryPoint, result );
			serialize( module.executionModes, result );
			serialize( module.debug, result );
			serialize( module.decorations, result );
			serialize( module.globalDeclarations, result );
			serialize( module.functions, result );
		}

		template< typename T >
		void serialize( std::vector< T > const & values
			, std::vector< uint32_t > & result )
		{
			for ( auto & value : values )
			{
				serialize( value, result );
			}
		}

		template< typename T >
		void serialize( Optional< T > const & value
			, std::vector< uint32_t > & result )
		{
			if ( bool( value ) )
			{
				serialize( value.value(), result );
			}
		}

		spirv::Module compileSpirV( ast::Shader const & shader )
		{
			auto simplified = ast::StmtSimplifier::submit( shader.getTypesCache()
				, shader.getStatements() );
			ModuleConfig config = spirv::StmtConfigFiller::submit( simplified.get() );
			auto spirvStatements = spirv::StmtAdapter::submit( simplified.get(), config );
			return spirv::StmtVisitor::submit( shader.getTypesCache(), spirvStatements.get(), shader.getType(), config );
		}
	}

	std::string writeSpirv( ast::Shader const & shader
		, bool writeHeader )
	{
		auto module = compileSpirV( shader );
		auto stream = getStream();
		write( module, writeHeader, stream );
		return stream.str();
	}

	std::vector< uint32_t > serialiseSpirv( ast::Shader const & shader )
	{
		auto module = compileSpirV( shader );
		std::vector< uint32_t > result;
		auto size = count( module );
		result.reserve( size );
		serialize( module, result );
		return result;
	}
}
