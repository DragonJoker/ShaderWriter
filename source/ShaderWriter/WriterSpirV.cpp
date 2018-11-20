/*
See LICENSE file in root folder
*/
#include "ShaderWriter/WriterSpirV.hpp"

#include "ShaderWriter/Shader.hpp"

#include "ShaderWriter/SPIRV/SpirvStmtAdapter.hpp"
#include "ShaderWriter/SPIRV/SpirvStmtVisitor.hpp"

#include "ShaderWriter/SPIRV/spirv/GLSL.std.450.hpp"

#include <sstream>
#include <iomanip>

namespace sdw
{
	namespace
	{
		std::string getSourceLanguageName( uint32_t value )
		{
			switch ( spv::SourceLanguage( value ) )
			{
			case spv::SourceLanguage::Unknown:
				return "Unknown";
			case spv::SourceLanguage::ESSL:
				return "ESSL";
			case spv::SourceLanguage::GLSL:
				return "GLSL";
			case spv::SourceLanguage::OpenCL_C:
				return "OpenCL_C";
			case spv::SourceLanguage::OpenCL_CPP:
				return "OpenCL_CPP";
			case spv::SourceLanguage::HLSL:
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
			case spv::Capability::Matrix:
				return "Matrix";
			case spv::Capability::Shader:
				return "Shader";
			case spv::Capability::Geometry:
				return "Geometry";
			case spv::Capability::Tessellation:
				return "Tessellation";
			case spv::Capability::Addresses:
				return "Addresses";
			case spv::Capability::Linkage:
				return "Linkage";
			case spv::Capability::Kernel:
				return "Kernel";
			case spv::Capability::Vector16:
				return "Vector16";
			case spv::Capability::Float16Buffer:
				return "Float16Buffer";
			case spv::Capability::Float16:
				return "Float16";
			case spv::Capability::Float64:
				return "Float64";
			case spv::Capability::Int64:
				return "Int64";
			case spv::Capability::Int64Atomics:
				return "Int64Atomics";
			case spv::Capability::ImageBasic:
				return "ImageBasic";
			case spv::Capability::ImageReadWrite:
				return "ImageReadWrite";
			case spv::Capability::ImageMipmap:
				return "ImageMipmap";
			case spv::Capability::Pipes:
				return "Pipes";
			case spv::Capability::Groups:
				return "Groups";
			case spv::Capability::DeviceEnqueue:
				return "DeviceEnqueue";
			case spv::Capability::LiteralSampler:
				return "LiteralSampler";
			case spv::Capability::AtomicStorage:
				return "AtomicStorage";
			case spv::Capability::Int16:
				return "Int16";
			case spv::Capability::TessellationPointSize:
				return "TessellationPointSize";
			case spv::Capability::GeometryPointSize:
				return "GeometryPointSize";
			case spv::Capability::ImageGatherExtended:
				return "ImageGatherExtended";
			case spv::Capability::StorageImageMultisample:
				return "StorageImageMultisample";
			case spv::Capability::UniformBufferArrayDynamicIndexing:
				return "UniformBufferArrayDynamicIndexing";
			case spv::Capability::SampledImageArrayDynamicIndexing:
				return "SampledImageArrayDynamicIndexing";
			case spv::Capability::StorageBufferArrayDynamicIndexing:
				return "StorageBufferArrayDynamicIndexing";
			case spv::Capability::StorageImageArrayDynamicIndexing:
				return "StorageImageArrayDynamicIndexing";
			case spv::Capability::ClipDistance:
				return "ClipDistance";
			case spv::Capability::CullDistance:
				return "CullDistance";
			case spv::Capability::ImageCubeArray:
				return "ImageCubeArray";
			case spv::Capability::SampleRateShading:
				return "SampleRateShading";
			case spv::Capability::ImageRect:
				return "ImageRect";
			case spv::Capability::SampledRect:
				return "SampledRect";
			case spv::Capability::GenericPointer:
				return "GenericPointer";
			case spv::Capability::Int8:
				return "Int8";
			case spv::Capability::InputAttachment:
				return "InputAttachment";
			case spv::Capability::SparseResidency:
				return "SparseResidency";
			case spv::Capability::MinLod:
				return "MinLod";
			case spv::Capability::Sampled1D:
				return "Sampled1D";
			case spv::Capability::Image1D:
				return "Image1D";
			case spv::Capability::SampledCubeArray:
				return "SampledCubeArray";
			case spv::Capability::SampledBuffer:
				return "SampledBuffer";
			case spv::Capability::ImageBuffer:
				return "ImageBuffer";
			case spv::Capability::ImageMSArray:
				return "ImageMSArray";
			case spv::Capability::StorageImageExtendedFormats:
				return "StorageImageExtendedFormats";
			case spv::Capability::ImageQuery:
				return "ImageQuery";
			case spv::Capability::DerivativeControl:
				return "DerivativeControl";
			case spv::Capability::InterpolationFunction:
				return "InterpolationFunction";
			case spv::Capability::TransformFeedback:
				return "TransformFeedback";
			case spv::Capability::GeometryStreams:
				return "GeometryStreams";
			case spv::Capability::StorageImageReadWithoutFormat:
				return "StorageImageReadWithoutFormat";
			case spv::Capability::StorageImageWriteWithoutFormat:
				return "StorageImageWriteWithoutFormat";
			case spv::Capability::MultiViewport:
				return "MultiViewport";
			case spv::Capability::SubgroupDispatch:
				return "SubgroupDispatch";
			case spv::Capability::NamedBarrier:
				return "NamedBarrier";
			case spv::Capability::PipeStorage:
				return "PipeStorage";
			case spv::Capability::SubgroupBallotKHR:
				return "SubgroupBallotKHR";
			case spv::Capability::DrawParameters:
				return "DrawParameters";
			case spv::Capability::SubgroupVoteKHR:
				return "SubgroupVoteKHR";
			case spv::Capability::StorageBuffer16BitAccess:
				return "StorageBuffer16BitAccess";
			case spv::Capability::StorageUniform16:
				return "StorageUniform16";
			case spv::Capability::StoragePushConstant16:
				return "StoragePushConstant16";
			case spv::Capability::StorageInputOutput16:
				return "StorageInputOutput16";
			case spv::Capability::DeviceGroup:
				return "DeviceGroup";
			case spv::Capability::MultiView:
				return "MultiView";
			case spv::Capability::VariablePointersStorageBuffer:
				return "VariablePointersStorageBuffer";
			case spv::Capability::VariablePointers:
				return "VariablePointers";
			case spv::Capability::AtomicStorageOps:
				return "AtomicStorageOps";
			case spv::Capability::SampleMaskPostDepthCoverage:
				return "SampleMaskPostDepthCoverage";
			case spv::Capability::ImageGatherBiasLodAMD:
				return "ImageGatherBiasLodAMD";
			case spv::Capability::FragmentMaskAMD:
				return "FragmentMaskAMD";
			case spv::Capability::StencilExportEXT:
				return "StencilExportEXT";
			case spv::Capability::ImageReadWriteLodAMD:
				return "ImageReadWriteLodAMD";
			case spv::Capability::SampleMaskOverrideCoverageNV:
				return "SampleMaskOverrideCoverageNV";
			case spv::Capability::GeometryShaderPassthroughNV:
				return "GeometryShaderPassthroughNV";
			case spv::Capability::ShaderViewportIndexLayerEXT:
				return "ShaderViewportIndexLayer";
			case spv::Capability::ShaderViewportMaskNV:
				return "ShaderViewportMaskNV";
			case spv::Capability::ShaderStereoViewNV:
				return "ShaderStereoViewNV";
			case spv::Capability::PerViewAttributesNV:
				return "PerViewAttributesNV";
			case spv::Capability::SubgroupShuffleINTEL:
				return "SubgroupShuffleINTEL";
			case spv::Capability::SubgroupBufferBlockIOINTEL:
				return "SubgroupBufferBlockIOINTEL";
			case spv::Capability::SubgroupImageBlockIOINTEL:
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
			case spv::AddressingModel::Logical:
				return "Logical";
			case spv::AddressingModel::Physical32:
				return "Physical32";
			case spv::AddressingModel::Physical64:
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
			case spv::MemoryModel::Simple:
				return "Simple";
			case spv::MemoryModel::GLSL450:
				return "GLSL450";
			case spv::MemoryModel::OpenCL:
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
			case spv::ExecutionModel::Vertex:
				return "Vertex";
			case spv::ExecutionModel::TessellationControl:
				return "TessellationControl";
			case spv::ExecutionModel::TessellationEvaluation:
				return "TessellationEvaluation";
			case spv::ExecutionModel::Geometry:
				return "Geometry";
			case spv::ExecutionModel::Fragment:
				return "Fragment";
			case spv::ExecutionModel::GLCompute:
				return "GLCompute";
			case spv::ExecutionModel::Kernel:
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
			case spv::ExecutionMode::Invocations:
				return "Invocations";
			case spv::ExecutionMode::SpacingEqual:
				return "SpacingEqual";
			case spv::ExecutionMode::SpacingFractionalEven:
				return "SpacingFractionalEven";
			case spv::ExecutionMode::SpacingFractionalOdd:
				return "SpacingFractionalOdd";
			case spv::ExecutionMode::VertexOrderCw:
				return "VertexOrderCw";
			case spv::ExecutionMode::VertexOrderCcw:
				return "VertexOrderCcw";
			case spv::ExecutionMode::PixelCenterInteger:
				return "PixelCenterInteger";
			case spv::ExecutionMode::OriginUpperLeft:
				return "OriginUpperLeft";
			case spv::ExecutionMode::OriginLowerLeft:
				return "OriginLowerLeft";
			case spv::ExecutionMode::EarlyFragmentTests:
				return "EarlyFragmentTests";
			case spv::ExecutionMode::PointMode:
				return "PointMode";
			case spv::ExecutionMode::Xfb:
				return "Xfb";
			case spv::ExecutionMode::DepthReplacing:
				return "DepthReplacing";
			case spv::ExecutionMode::DepthGreater:
				return "DepthGreater";
			case spv::ExecutionMode::DepthLess:
				return "DepthLess";
			case spv::ExecutionMode::DepthUnchanged:
				return "DepthUnchanged";
			case spv::ExecutionMode::LocalSize:
				return "LocalSize";
			case spv::ExecutionMode::LocalSizeHint:
				return "LocalSizeHint";
			case spv::ExecutionMode::InputPoints:
				return "InputPoints";
			case spv::ExecutionMode::InputLines:
				return "InputLines";
			case spv::ExecutionMode::InputLinesAdjacency:
				return "InputLinesAdjacency";
			case spv::ExecutionMode::Triangles:
				return "Triangles";
			case spv::ExecutionMode::InputTrianglesAdjacency:
				return "InputTrianglesAdjacency";
			case spv::ExecutionMode::Quads:
				return "Quads";
			case spv::ExecutionMode::Isolines:
				return "Isolines";
			case spv::ExecutionMode::OutputVertices:
				return "OutputVertices";
			case spv::ExecutionMode::OutputPoints:
				return "OutputPoints";
			case spv::ExecutionMode::OutputLineStrip:
				return "OutputLineStrip";
			case spv::ExecutionMode::OutputTriangleStrip:
				return "OutputTriangleStrip";
			case spv::ExecutionMode::VecTypeHint:
				return "VecTypeHint";
			case spv::ExecutionMode::ContractionOff:
				return "ContractionOff";
			case spv::ExecutionMode::Initializer:
				return "Initializer";
			case spv::ExecutionMode::Finalizer:
				return "Finalizer";
			case spv::ExecutionMode::SubgroupSize:
				return "SubgroupSize";
			case spv::ExecutionMode::SubgroupsPerWorkgroup:
				return "SubgroupsPerWorkgroup";
			case spv::ExecutionMode::SubgroupsPerWorkgroupId:
				return "SubgroupsPerWorkgroupId";
			case spv::ExecutionMode::LocalSizeId:
				return "LocalSizeId";
			case spv::ExecutionMode::LocalSizeHintId:
				return "LocalSizeHintId";
			case spv::ExecutionMode::PostDepthCoverage:
				return "PostDepthCoverage";
			case spv::ExecutionMode::StencilRefReplacingEXT:
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
			case spv::AccessQualifier::ReadOnly:
				return "ReadOnly";
			case spv::AccessQualifier::WriteOnly:
				return "WriteOnly";
			case spv::AccessQualifier::ReadWrite:
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
			case spv::StorageClass::UniformConstant:
				return "UniformConstant";
			case spv::StorageClass::Input:
				return "Input";
			case spv::StorageClass::Uniform:
				return "Uniform";
			case spv::StorageClass::Output:
				return "Output";
			case spv::StorageClass::Workgroup:
				return "Workgroup";
			case spv::StorageClass::CrossWorkgroup:
				return "CrossWorkgroup";
			case spv::StorageClass::Private:
				return "Private";
			case spv::StorageClass::Function:
				return "Function";
			case spv::StorageClass::Generic:
				return "Generic";
			case spv::StorageClass::PushConstant:
				return "PushConstant";
			case spv::StorageClass::AtomicCounter:
				return "AtomicCounter";
			case spv::StorageClass::Image:
				return "Image";
			case spv::StorageClass::StorageBuffer:
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
			case spv::ImageFormat::Unknown:
				return "Unknown";
			case spv::ImageFormat::Rgba32f:
				return "Rgba32f";
			case spv::ImageFormat::Rgba16f:
				return "Rgba16f";
			case spv::ImageFormat::R32f:
				return "R32f";
			case spv::ImageFormat::Rgba8:
				return "Rgba8";
			case spv::ImageFormat::Rgba8Snorm:
				return "Rgba8Snorm";
			case spv::ImageFormat::Rg32f:
				return "Rg32f";
			case spv::ImageFormat::Rg16f:
				return "Rg16f";
			case spv::ImageFormat::R11fG11fB10f:
				return "R11fG11fB10f";
			case spv::ImageFormat::R16f:
				return "R16f";
			case spv::ImageFormat::Rgba16:
				return "Rgba16";
			case spv::ImageFormat::Rgb10A2:
				return "Rgb10A2";
			case spv::ImageFormat::Rg16:
				return "Rg16";
			case spv::ImageFormat::Rg8:
				return "Rg8";
			case spv::ImageFormat::R16:
				return "R16";
			case spv::ImageFormat::R8:
				return "R8";
			case spv::ImageFormat::Rgba16Snorm:
				return "Rgba16Snorm";
			case spv::ImageFormat::Rg16Snorm:
				return "Rg16Snorm";
			case spv::ImageFormat::Rg8Snorm:
				return "Rg8Snorm";
			case spv::ImageFormat::R16Snorm:
				return "R16Snorm";
			case spv::ImageFormat::R8Snorm:
				return "R8Snorm";
			case spv::ImageFormat::Rgba32i:
				return "Rgba32i";
			case spv::ImageFormat::Rgba16i:
				return "Rgba16i";
			case spv::ImageFormat::Rgba8i:
				return "Rgba8i";
			case spv::ImageFormat::R32i:
				return "R32i";
			case spv::ImageFormat::Rg32i:
				return "Rg32i";
			case spv::ImageFormat::Rg16i:
				return "Rg16i";
			case spv::ImageFormat::Rg8i:
				return "Rg8i";
			case spv::ImageFormat::R16i:
				return "R16i";
			case spv::ImageFormat::R8i:
				return "R8i";
			case spv::ImageFormat::Rgba32ui:
				return "Rgba32ui";
			case spv::ImageFormat::Rgba16ui:
				return "Rgba16ui";
			case spv::ImageFormat::Rgba8ui:
				return "Rgba8ui";
			case spv::ImageFormat::R32ui:
				return "R32ui";
			case spv::ImageFormat::Rgb10a2ui:
				return "Rgb10a2ui";
			case spv::ImageFormat::Rg32ui:
				return "Rg32ui";
			case spv::ImageFormat::Rg16ui:
				return "Rg16ui";
			case spv::ImageFormat::Rg8ui:
				return "Rg8ui";
			case spv::ImageFormat::R16ui:
				return "R16ui";
			case spv::ImageFormat::R8ui:
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
			case spv::Dim::Dim1D:
				return "Dim1D";
			case spv::Dim::Dim2D:
				return "Dim2D";
			case spv::Dim::Dim3D:
				return "Dim3D";
			case spv::Dim::Cube:
				return "Cube";
			case spv::Dim::Rect:
				return "Rect";
			case spv::Dim::Buffer:
				return "Buffer";
			case spv::Dim::SubpassData:
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
			case spv::BuiltIn::Position:
				return "Position";
			case spv::BuiltIn::PointSize:
				return "PointSize";
			case spv::BuiltIn::ClipDistance:
				return "ClipDistance";
			case spv::BuiltIn::CullDistance:
				return "CullDistance";
			case spv::BuiltIn::VertexId:
				return "VertexId";
			case spv::BuiltIn::InstanceId:
				return "InstanceId";
			case spv::BuiltIn::PrimitiveId:
				return "PrimitiveId";
			case spv::BuiltIn::InvocationId:
				return "InvocationId";
			case spv::BuiltIn::Layer:
				return "Layer";
			case spv::BuiltIn::ViewportIndex:
				return "ViewportIndex";
			case spv::BuiltIn::TessLevelOuter:
				return "TessLevelOuter";
			case spv::BuiltIn::TessLevelInner:
				return "TessLevelInner";
			case spv::BuiltIn::TessCoord:
				return "TessCoord";
			case spv::BuiltIn::PatchVertices:
				return "PatchVertices";
			case spv::BuiltIn::FragCoord:
				return "FragCoord";
			case spv::BuiltIn::PointCoord:
				return "PointCoord";
			case spv::BuiltIn::FrontFacing:
				return "FrontFacing";
			case spv::BuiltIn::SampleId:
				return "SampleId";
			case spv::BuiltIn::SamplePosition:
				return "SamplePosition";
			case spv::BuiltIn::SampleMask:
				return "SampleMask";
			case spv::BuiltIn::FragDepth:
				return "FragDepth";
			case spv::BuiltIn::HelperInvocation:
				return "HelperInvocation";
			case spv::BuiltIn::NumWorkgroups:
				return "NumWorkgroups";
			case spv::BuiltIn::WorkgroupSize:
				return "WorkgroupSize";
			case spv::BuiltIn::WorkgroupId:
				return "WorkgroupId";
			case spv::BuiltIn::LocalInvocationId:
				return "LocalInvocationId";
			case spv::BuiltIn::GlobalInvocationId:
				return "GlobalInvocationId";
			case spv::BuiltIn::LocalInvocationIndex:
				return "LocalInvocationIndex";
			case spv::BuiltIn::WorkDim:
				return "WorkDim";
			case spv::BuiltIn::GlobalSize:
				return "GlobalSize";
			case spv::BuiltIn::EnqueuedWorkgroupSize:
				return "EnqueuedWorkgroupSize";
			case spv::BuiltIn::GlobalOffset:
				return "GlobalOffset";
			case spv::BuiltIn::GlobalLinearId:
				return "GlobalLinearId";
			case spv::BuiltIn::SubgroupSize:
				return "SubgroupSize";
			case spv::BuiltIn::SubgroupMaxSize:
				return "SubgroupMaxSize";
			case spv::BuiltIn::NumSubgroups:
				return "NumSubgroups";
			case spv::BuiltIn::NumEnqueuedSubgroups:
				return "NumEnqueuedSubgroups";
			case spv::BuiltIn::SubgroupId:
				return "SubgroupId";
			case spv::BuiltIn::SubgroupLocalInvocationId:
				return "SubgroupLocalInvocationId";
			case spv::BuiltIn::VertexIndex:
				return "VertexIndex";
			case spv::BuiltIn::InstanceIndex:
				return "InstanceIndex";
			case spv::BuiltIn::SubgroupEqMaskKHR:
				return "SubgroupEqMaskKHR";
			case spv::BuiltIn::SubgroupGeMaskKHR:
				return "SubgroupGeMaskKHR";
			case spv::BuiltIn::SubgroupGtMaskKHR:
				return "SubgroupGtMaskKHR";
			case spv::BuiltIn::SubgroupLeMaskKHR:
				return "SubgroupLeMaskKHR";
			case spv::BuiltIn::SubgroupLtMaskKHR:
				return "SubgroupLtMaskKHR";
			case spv::BuiltIn::BaseVertex:
				return "BaseVertex";
			case spv::BuiltIn::BaseInstance:
				return "BaseInstance";
			case spv::BuiltIn::DrawIndex:
				return "DrawIndex";
			case spv::BuiltIn::DeviceIndex:
				return "DeviceIndex";
			case spv::BuiltIn::ViewIndex:
				return "ViewIndex";
			case spv::BuiltIn::BaryCoordNoPerspAMD:
				return "BaryCoordNoPerspAMD";
			case spv::BuiltIn::BaryCoordNoPerspCentroidAMD:
				return "BaryCoordNoPerspCentroidAMD";
			case spv::BuiltIn::BaryCoordNoPerspSampleAMD:
				return "BaryCoordNoPerspSampleAMD";
			case spv::BuiltIn::BaryCoordSmoothAMD:
				return "BaryCoordSmoothAMD";
			case spv::BuiltIn::BaryCoordSmoothCentroidAMD:
				return "BaryCoordSmoothCentroidAMD";
			case spv::BuiltIn::BaryCoordSmoothSampleAMD:
				return "BaryCoordSmoothSampleAMD";
			case spv::BuiltIn::BaryCoordPullModelAMD:
				return "BaryCoordPullModelAMD";
			case spv::BuiltIn::FragStencilRefEXT:
				return "FragStencilRefEXT";
			case spv::BuiltIn::ViewportMaskNV:
				return "ViewportMaskNV";
			case spv::BuiltIn::SecondaryPositionNV:
				return "SecondaryPositionNV";
			case spv::BuiltIn::SecondaryViewportMaskNV:
				return "SecondaryViewportMaskNV";
			case spv::BuiltIn::PositionPerViewNV:
				return "PositionPerViewNV";
			case spv::BuiltIn::ViewportMaskPerViewNV:
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
			case spv::Decoration::RelaxedPrecision:
				return "RelaxedPrecision";
			case spv::Decoration::SpecId:
				return "SpecId";
			case spv::Decoration::Block:
				return "Block";
			case spv::Decoration::BufferBlock:
				return "BufferBlock";
			case spv::Decoration::RowMajor:
				return "RowMajor";
			case spv::Decoration::ColMajor:
				return "ColMajor";
			case spv::Decoration::ArrayStride:
				return "ArrayStride";
			case spv::Decoration::MatrixStride:
				return "MatrixStride";
			case spv::Decoration::GLSLShared:
				return "GLSLShared";
			case spv::Decoration::GLSLPacked:
				return "GLSLPacked";
			case spv::Decoration::CPacked:
				return "CPacked";
			case spv::Decoration::BuiltIn:
				return "BuiltIn";
			case spv::Decoration::NoPerspective:
				return "NoPerspective";
			case spv::Decoration::Flat:
				return "Flat";
			case spv::Decoration::Patch:
				return "Patch";
			case spv::Decoration::Centroid:
				return "Centroid";
			case spv::Decoration::Sample:
				return "Sample";
			case spv::Decoration::Invariant:
				return "Invariant";
			case spv::Decoration::Restrict:
				return "Restrict";
			case spv::Decoration::Aliased:
				return "Aliased";
			case spv::Decoration::Volatile:
				return "Volatile";
			case spv::Decoration::Constant:
				return "Constant";
			case spv::Decoration::Coherent:
				return "Coherent";
			case spv::Decoration::NonWritable:
				return "NonWritable";
			case spv::Decoration::NonReadable:
				return "NonReadable";
			case spv::Decoration::Uniform:
				return "Uniform";
			case spv::Decoration::SaturatedConversion:
				return "SaturatedConversion";
			case spv::Decoration::Stream:
				return "Stream";
			case spv::Decoration::Location:
				return "Location";
			case spv::Decoration::Component:
				return "Component";
			case spv::Decoration::Index:
				return "Index";
			case spv::Decoration::Binding:
				return "Binding";
			case spv::Decoration::DescriptorSet:
				return "DescriptorSet";
			case spv::Decoration::Offset:
				return "Offset";
			case spv::Decoration::XfbBuffer:
				return "XfbBuffer";
			case spv::Decoration::XfbStride:
				return "XfbStride";
			case spv::Decoration::FuncParamAttr:
				return "FuncParamAttr";
			case spv::Decoration::FPRoundingMode:
				return "FPRoundingMode";
			case spv::Decoration::FPFastMathMode:
				return "FPFastMathMode";
			case spv::Decoration::LinkageAttributes:
				return "LinkageAttributes";
			case spv::Decoration::NoContraction:
				return "NoContraction";
			case spv::Decoration::InputAttachmentIndex:
				return "InputAttachmentIndex";
			case spv::Decoration::Alignment:
				return "Alignment";
			case spv::Decoration::MaxByteOffset:
				return "MaxByteOffset";
			case spv::Decoration::AlignmentId:
				return "AlignmentId";
			case spv::Decoration::MaxByteOffsetId:
				return "MaxByteOffsetId";
			case spv::Decoration::ExplicitInterpAMD:
				return "ExplicitInterpAMD";
			case spv::Decoration::OverrideCoverageNV:
				return "OverrideCoverageNV";
			case spv::Decoration::PassthroughNV:
				return "PassthroughNV";
			case spv::Decoration::ViewportRelativeNV:
				return "ViewportRelativeNV";
			case spv::Decoration::SecondaryViewportRelativeNV:
				return "SecondaryViewportRelativeNV";
			case spv::Decoration::HlslCounterBufferGOOGLE:
				return "HlslCounterBufferGOOGLE";
			case spv::Decoration::HlslSemanticGOOGLE:
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
			case spv::FunctionParameterAttribute::Zext:
				return "Zext";
			case spv::FunctionParameterAttribute::Sext:
				return "Sext";
			case spv::FunctionParameterAttribute::ByVal:
				return "ByVal";
			case spv::FunctionParameterAttribute::Sret:
				return "Sret";
			case spv::FunctionParameterAttribute::NoAlias:
				return "NoAlias";
			case spv::FunctionParameterAttribute::NoCapture:
				return "NoCapture";
			case spv::FunctionParameterAttribute::NoWrite:
				return "NoWrite";
			case spv::FunctionParameterAttribute::NoReadWrite:
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
			case spv::FPRoundingMode::RTE:
				return "RTE";
			case spv::FPRoundingMode::RTZ:
				return "RTZ";
			case spv::FPRoundingMode::RTP:
				return "RTP";
			case spv::FPRoundingMode::RTN:
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
			case spv::LinkageType::Export:
				return "Export";
			case spv::LinkageType::Import:
				return "Import";
			default:
				assert( false && "Unsupported LinkageType" );
				return "Undefined";
			}
		}

		std::string getImageOperandsName( uint32_t value )
		{
			std::stringstream stream;
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::ImageOperandsMask::Bias ) )
			{
				stream << sep << "Bias";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::Lod ) )
			{
				stream << sep << "Lod";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::Grad ) )
			{
				stream << sep << "Grad";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::ConstOffset ) )
			{
				stream << sep << "ConstOffset";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::Offset ) )
			{
				stream << sep << "Offset";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::ConstOffsets ) )
			{
				stream << sep << "ConstOffsets";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::Sample ) )
			{
				stream << sep << "Sample";
				sep = "|";
			}

			if ( value & uint32_t( spv::ImageOperandsMask::MinLod ) )
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

		std::string getFunctionControlMaskName( uint32_t value )
		{
			std::stringstream stream;
			std::string sep;
			stream << "[";

			if ( value & uint32_t( spv::FunctionControlMask::Inline ) )
			{
				stream << sep << "Inline";
				sep = "|";
			}

			if ( value & uint32_t( spv::FunctionControlMask::DontInline ) )
			{
				stream << sep << "DontInline";
				sep = "|";
			}

			if ( value & uint32_t( spv::FunctionControlMask::Pure ) )
			{
				stream << sep << "Pure";
				sep = "|";
			}

			if ( value & uint32_t( spv::FunctionControlMask::Const ) )
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
			std::stringstream stream;
			std::string sep;
			stream << "[";

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeMask::NotNaN ) )
			{
				stream << sep << "NotNaN";
				sep = "|";
			}

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeMask::NotInf ) )
			{
				stream << sep << "NotInf";
				sep = "|";
			}

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeMask::NSZ ) )
			{
				stream << sep << "NSZ";
				sep = "|";
			}

			if ( uint32_t( value ) & uint32_t( spv::FPFastMathModeMask::AllowRecip ) )
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

		using IdNames = std::map< spv::Id, std::string >;

		std::string writeId( spv::Id const & id )
		{
			std::stringstream stream;
			stream << std::setw( 5 ) << std::right << ( "%" + std::to_string( id ) );
			return stream.str();
		}

		std::string write( spv::Id id
			, IdNames const & names )
		{
			std::stringstream stream;
			stream << " %" << id;
			auto it = names.find( id );

			if ( it != names.end() )
			{
				stream << "(" << it->second << ")";
			}

			return stream.str();
		}

		std::ostream & write( std::optional< spv::Id > id
			, IdNames const & names
			, std::ostream & stream )
		{
			if ( id.has_value() )
			{
				stream << write( id.value(), names );
			}

			return stream;
		}

		std::ostream & write( spirv::IdList const & ids
			, IdNames const & names
			, std::ostream & stream )
		{
			for ( auto & id : ids )
			{
				write( id, names, stream );
			}

			return stream;
		}

		std::ostream & writeExtension( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );

			if ( opCode == spv::Op::OpExtInstImport )
			{
				names.emplace( instruction.resultId.value(), instruction.name.value() );
				stream << writeId( instruction.resultId.value() ) << " =";
				stream << " " << spirv::getOperatorName( opCode );
				stream << " \"" << instruction.name.value() << "\"";
				write( instruction.operands, names, stream );
			}
			else if ( opCode == spv::Op::OpExtension )
			{
				stream << "        " << spirv::getOperatorName( opCode );
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeDebug( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );
			assert( opCode == spv::Op::OpName
				|| opCode == spv::Op::OpMemberName
				|| opCode == spv::Op::OpSource );
			stream << "        " << spirv::getOperatorName( opCode );

			if ( opCode == spv::Op::OpName )
			{
				names.emplace( instruction.resultId.value(), instruction.name.value() );
				assert( instruction.resultId.has_value() );
				write( instruction.resultId, names, stream );
				assert( instruction.name.has_value() );
				stream << " \"" << instruction.name.value() << "\"";
			}
			else if ( opCode == spv::Op::OpMemberName )
			{
				assert( instruction.operands.size() == 2u );
				write( instruction.operands.front(), names, stream );
				stream << " " << instruction.operands.back();
				assert( instruction.name.has_value() );
				stream << " \"" << instruction.name.value() << "\"";
			}
			else if ( opCode == spv::Op::OpSource )
			{
				assert( instruction.operands.size() >= 2u );
				stream << " " << getSourceLanguageName( instruction.operands[0] );
				stream << " " << instruction.operands[1];

				if ( instruction.operands.size() > 2 )
				{
					stream << " " << instruction.operands[2];
				}

				if ( instruction.name.has_value() )
				{
					stream << " \"" << instruction.name.value() << "\"";
				}
			}

			return stream;
		}

		std::ostream & writeDecoration( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );
			assert( opCode == spv::Op::OpDecorate || opCode == spv::Op::OpMemberDecorate );
			stream << "        " << spirv::getOperatorName( opCode );
			auto it = instruction.operands.begin();

			if ( opCode == spv::Op::OpDecorate )
			{
				write( *it, names, stream );
				++it;
			}
			else if ( opCode == spv::Op::OpMemberDecorate )
			{
				write( *it, names, stream );
				++it;
				stream << " " << *it;
				++it;
			}

			auto decoration = spv::Decoration( *it );
			stream << " " << getName( decoration );
			++it;

			if ( decoration == spv::Decoration::BuiltIn )
			{
				stream << " " << getName( spv::BuiltIn( *it ) );
				++it;
			}
			else if ( decoration == spv::Decoration::FuncParamAttr )
			{
				stream << " " << getName( spv::FunctionParameterAttribute( *it ) );
				++it;
			}
			else if ( decoration == spv::Decoration::FPRoundingMode )
			{
				stream << " " << getName( spv::FPRoundingMode( *it ) );
				++it;
			}
			else if ( decoration == spv::Decoration::FPFastMathMode )
			{
				stream << " " << getFPFastMathModeName( *it );
				++it;
			}
			else if ( decoration == spv::Decoration::LinkageAttributes )
			{
				stream << " \"" << instruction.name.value() << "\"";
				stream << " " << getName( spv::LinkageType( *it ) );
				++it;
			}
			else if ( decoration == spv::Decoration::SpecId
				|| decoration == spv::Decoration::ArrayStride
				|| decoration == spv::Decoration::MatrixStride
				|| decoration == spv::Decoration::Stream
				|| decoration == spv::Decoration::Location
				|| decoration == spv::Decoration::Component
				|| decoration == spv::Decoration::Index
				|| decoration == spv::Decoration::Binding
				|| decoration == spv::Decoration::DescriptorSet
				|| decoration == spv::Decoration::Offset
				|| decoration == spv::Decoration::XfbBuffer
				|| decoration == spv::Decoration::XfbStride
				|| decoration == spv::Decoration::InputAttachmentIndex
				|| decoration == spv::Decoration::Alignment
				|| decoration == spv::Decoration::SecondaryViewportRelativeNV )
			{
				stream << " " << *it;
				++it;
			}

			return stream;
		}

		std::ostream & writeType( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			stream << writeId( instruction.resultId.value() ) << " =";
			auto opCode = spv::Op( instruction.op.opCode );
			stream << " " << spirv::getOperatorName( opCode );

			if ( opCode == spv::Op::OpTypeFunction )
			{
				names.emplace( instruction.resultId.value(), "func" );
				// First being return type ID, other ones being parameters type ID.
				for ( auto & operand : instruction.operands )
				{
					write( operand, names, stream );
				}
			}
			else if ( opCode == spv::Op::OpTypePointer )
			{
				// Storage class then Type ID.
				names.emplace( instruction.resultId.value(), "ptr" );
				stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );
				write( instruction.operands[1], names, stream );
			}
			else if ( opCode == spv::Op::OpTypeStruct )
			{
				names.emplace( instruction.resultId.value(), "struct" );
				// Members IDs.
				for ( auto & operand : instruction.operands )
				{
					write( operand, names, stream );
				}
			}
			else if ( opCode == spv::Op::OpTypeBool )
			{
				names.emplace( instruction.resultId.value(), "bool" );
			}
			else if ( opCode == spv::Op::OpTypeInt )
			{
				names.emplace( instruction.resultId.value(), "int" );
				// Width then Signedness.
				stream << " " << instruction.operands[0];
				stream << " " << instruction.operands[1];
			}
			else if ( opCode == spv::Op::OpTypeFloat )
			{
				names.emplace( instruction.resultId.value(), "float" );
				// Width.
				stream << " " << instruction.operands[0];
			}
			else if ( opCode == spv::Op::OpTypeVector )
			{
				names.emplace( instruction.resultId.value(), "vec" );
				// Component type and components count.
				if ( !instruction.operands.empty() )
				{
					write( instruction.operands[0], names, stream );
					stream << " " << instruction.operands[1];
				}
			}
			else if ( opCode == spv::Op::OpTypeMatrix )
			{
				names.emplace( instruction.resultId.value(), "mat" );
				// Component type and components count.
				if ( !instruction.operands.empty() )
				{
					write( instruction.operands[0], names, stream );
					stream << " " << instruction.operands[1];
				}
			}
			else if ( opCode == spv::Op::OpTypeArray )
			{
				names.emplace( instruction.resultId.value(), "array" );
				// Component type and components count.
				if ( !instruction.operands.empty() )
				{
					write( instruction.operands[0], names, stream );
					write( instruction.operands[1], names, stream );
				}
			}
			else if ( opCode == spv::Op::OpTypeImage )
			{
				names.emplace( instruction.resultId.value(), "img" );
				// Sampled Type, Dim, Depth, Arrayed, MS, Sampled, Format.
				write( instruction.operands[0], names, stream );
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
			else if ( opCode == spv::Op::OpTypeSampledImage )
			{
				names.emplace( instruction.resultId.value(), "simg" );
				// Image type.
				write( instruction.operands[0], names, stream );
			}
			else if ( opCode == spv::Op::OpTypeRuntimeArray )
			{
				names.emplace( instruction.resultId.value(), "dynarray" );
				// Element type.
				write( instruction.operands[0], names, stream );
			}

			return stream;
		}

		std::ostream & writeGlobalVariable( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			std::string result;
			auto opCode = spv::Op( instruction.op.opCode );
			stream << writeId( instruction.resultId.value() ) << " =";
			stream << " " << spirv::getOperatorName( opCode );
			write( instruction.resultType.value(), names, stream );
			stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );

			for ( size_t i = 1u; i < instruction.operands.size(); ++i )
			{
				write( instruction.operands[i], names, stream );
			}

			return stream;
		}

		std::ostream & writeConstant( spirv::Instruction const & instruction
			, type::Kind type
			, IdNames & names
			, std::ostream & stream )
		{
			assert( instruction.resultId.has_value() );
			assert( instruction.resultType.has_value() );
			stream << writeId( instruction.resultId.value() ) << " =";
			auto opCode = spv::Op( instruction.op.opCode );
			stream << " " << spirv::getOperatorName( opCode );
			write( instruction.resultType.value(), names, stream );

			if ( opCode == spv::Op::OpConstant )
			{
				switch ( type )
				{
				case type::Kind::eBoolean:
					names.emplace( instruction.resultId.value(), std::to_string( bool( instruction.operands[0] ) ) );
					stream << " " << bool( instruction.operands[0] );
					break;
				case type::Kind::eInt:
					names.emplace( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
					stream << " " << int32_t( instruction.operands[0] );
					break;
				case type::Kind::eUInt:
					names.emplace( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
					stream << " " << instruction.operands[0];
					break;
				case type::Kind::eFloat:
					names.emplace( instruction.resultId.value(), std::to_string( *reinterpret_cast< float const * >( instruction.operands.data() ) ) );
					stream << " " << *reinterpret_cast< float const * >( instruction.operands.data() );
					break;
				case type::Kind::eDouble:
					assert( instruction.operands.size() >= 2 );
					{
						names.emplace( instruction.resultId.value(), std::to_string( *reinterpret_cast< double const * >( instruction.operands.data() ) ) );
						stream << " " << *reinterpret_cast< double const * >( instruction.operands.data() );
					}
					break;
				}
			}
			else if ( opCode == spv::Op::OpConstantComposite )
			{
				names.emplace( instruction.resultId.value(), "const" );
				write( instruction.operands, names, stream );
			}

			return stream;
		}

		std::ostream & writeSpecConstant( spirv::Instruction const & instruction
			, type::Kind type
			, IdNames & names
			, std::ostream & stream )
		{
			assert( instruction.resultId.has_value() );
			assert( instruction.resultType.has_value() );
			stream << writeId( instruction.resultId.value() ) << " =";
			auto opCode = spv::Op( instruction.op.opCode );
			stream << " " << spirv::getOperatorName( opCode );
			write( instruction.resultType.value(), names, stream );

			if ( opCode == spv::Op::OpSpecConstant )
			{
				switch ( type )
				{
				case type::Kind::eBoolean:
					names.emplace( instruction.resultId.value(), std::to_string( bool( instruction.operands[0] ) ) );
					stream << " " << bool( instruction.operands[0] );
					break;
				case type::Kind::eInt:
					names.emplace( instruction.resultId.value(), std::to_string( int32_t( instruction.operands[0] ) ) );
					stream << " " << int32_t( instruction.operands[0] );
					break;
				case type::Kind::eUInt:
					names.emplace( instruction.resultId.value(), std::to_string( instruction.operands[0] ) );
					stream << " " << instruction.operands[0];
					break;
				case type::Kind::eFloat:
					names.emplace( instruction.resultId.value(), std::to_string( *reinterpret_cast< float const * >( instruction.operands.data() ) ) );
					stream << " " << *reinterpret_cast< float const * >( instruction.operands.data() );
					break;
				case type::Kind::eDouble:
					assert( instruction.operands.size() >= 2 );
					{
						names.emplace( instruction.resultId.value(), std::to_string( *reinterpret_cast< double const * >( instruction.operands.data() ) ) );
						stream << " " << *reinterpret_cast< double const * >( instruction.operands.data() );
					}
					break;
				}
			}
			else if ( opCode == spv::Op::OpSpecConstantComposite )
			{
				names.emplace( instruction.resultId.value(), "specconst" );
				write( instruction.operands, names, stream );
			}

			return stream;
		}

		std::ostream & writeGlobalDeclaration( spirv::Instruction const & instruction
			, IdNames & names
			, spirv::Module const & module
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );

			if ( opCode == spv::Op::OpConstant
				|| opCode == spv::Op::OpConstantComposite )
			{
				writeConstant( instruction, module.getLiteralType( instruction.resultId.value() ), names, stream ) << "\n";
			}
			else if ( opCode == spv::Op::OpSpecConstant
				|| opCode == spv::Op::OpSpecConstantComposite )
			{
				writeSpecConstant( instruction, module.getLiteralType( instruction.resultId.value() ), names, stream ) << "\n";
			}
			else if ( opCode == spv::Op::OpVariable )
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
			, IdNames & names
			, spirv::Module const & module
			, std::ostream & stream )
		{
			for ( auto & instruction : instructions )
			{
				writeGlobalDeclaration( instruction, names, module, stream );
			}

			return stream;
		}

		std::ostream & writeExtInst( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			write( instruction.operands[0], names, stream );
			stream << " " << getName( spv::GLSLstd450( instruction.operands[1] ) );

			for ( size_t i = 2u; i < instruction.operands.size(); ++i )
			{
				write( instruction.operands[i], names, stream );
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeFuncVariable( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			stream << " " << getName( spv::StorageClass( instruction.operands[0] ) );

			for ( size_t i = 1u; i < instruction.operands.size(); ++i )
			{
				write( instruction.operands[i], names, stream );
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSample( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );

			if ( instruction.operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[2] );

				for ( size_t i = 3u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSampleDref( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );
			// Dref
			write( instruction.operands[2], names, stream );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSampleProj( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );

			if ( instruction.operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[2] );

				for ( size_t i = 3u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageSampleProjDref( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Sampled Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );
			// Dref
			write( instruction.operands[2], names, stream );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageFetch( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );

			if ( instruction.operands.size() > 3u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[2] );

				for ( size_t i = 3u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageGather( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );
			// Component
			write( instruction.operands[2], names, stream );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeImageDrefGather( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			// Image
			write( instruction.operands[0], names, stream );
			// Coordinate
			write( instruction.operands[1], names, stream );
			// Dref
			write( instruction.operands[2], names, stream );

			if ( instruction.operands.size() > 4u )
			{
				// Optional ImageOperands
				stream << " " << getImageOperandsName( instruction.operands[3] );

				for ( size_t i = 4u; i < instruction.operands.size(); ++i )
				{
					write( instruction.operands[i], names, stream );
				}
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeStore( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			write( instruction.operands[0], names, stream );
			write( instruction.operands[1], names, stream );

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeLoad( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			write( instruction.operands[0], names, stream );

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeBranch( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			write( instruction.operands[0], names, stream );

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeVectorShuffle( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			write( instruction.operands[0], names, stream );
			write( instruction.operands[1], names, stream );

			for ( size_t i = 2u; i < instruction.operands.size(); ++i )
			{
				stream << " " << instruction.operands[i];
			}

			if ( instruction.name.has_value() )
			{
				stream << " \"" << instruction.name.value() << "\"";
			}

			return stream;
		}

		std::ostream & writeCompositeExtract( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			write( instruction.operands[0], names, stream );
			stream << " " << instruction.operands[1];
			return stream;
		}

		std::ostream & writeBlockInstruction( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );

			if ( instruction.resultId.has_value() )
			{
				stream << writeId( instruction.resultId.value() ) << " =";
			}
			else
			{
				stream << "       ";
			}

			stream << " " << spirv::getOperatorName( opCode );

			if ( instruction.resultType.has_value() )
			{
				stream << write( instruction.resultType.value(), names );
			}

			if ( opCode == spv::Op::OpExtInst )
			{
				writeExtInst( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpVariable )
			{
				writeFuncVariable( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageSampleImplicitLod
				|| opCode == spv::Op::OpImageSampleExplicitLod )
			{
				writeImageSample( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageSampleDrefImplicitLod
				|| opCode == spv::Op::OpImageSampleDrefExplicitLod )
			{
				writeImageSampleDref( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageSampleProjImplicitLod
				|| opCode == spv::Op::OpImageSampleProjExplicitLod )
			{
				writeImageSampleProj( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageSampleProjDrefImplicitLod
				|| opCode == spv::Op::OpImageSampleProjDrefExplicitLod )
			{
				writeImageSampleProjDref( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageFetch )
			{
				writeImageFetch( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageGather )
			{
				writeImageGather( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpImageDrefGather )
			{
				writeImageDrefGather( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpStore )
			{
				writeStore( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpLoad )
			{
				writeLoad( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpVectorShuffle )
			{
				writeVectorShuffle( instruction, names, stream );
			}
			else if ( opCode == spv::Op::OpCompositeExtract )
			{
				writeCompositeExtract( instruction, names, stream );
			}
			else
			{
				write( instruction.operands, names, stream );

				if ( instruction.name.has_value() )
				{
					stream << " \"" << instruction.name.value() << "\"";
				}
			}

			return stream;
		}

		template< typename Type >
		std::ostream & writeInstructions( std::vector< Type > const & instructions
			, IdNames & names
			, std::ostream & ( *writer )( Type const &, IdNames &, std::ostream & )
			, std::ostream & stream )
		{
			for ( auto & instruction : instructions )
			{
				writer( instruction, names, stream ) << "\n";
			}

			return stream;
		}

		std::ostream & writeBlock( spirv::Block const & block
			, IdNames & names
			, std::ostream & stream )
		{
			writeInstructions( block.instructions, names, writeBlockInstruction, stream );
			writeBlockInstruction( block.blockEnd, names, stream );
			return stream;
		}

		std::ostream & writeFunctionDecl( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );
			stream << writeId( instruction.resultId.value() ) << " =";
			stream << " " << spirv::getOperatorName( opCode );
			stream << write( instruction.resultType.value(), names );

			if ( opCode == spv::Op::OpFunction )
			{
				stream << " " << getFunctionControlMaskName( instruction.operands[0] );
				stream << " " << write( instruction.operands[1], names );
			}

			return stream;
		}

		std::ostream & writeFunction( spirv::Function const & function
			, IdNames & names
			, std::ostream & stream )
		{
			writeInstructions( function.declaration, names, writeFunctionDecl, stream );
			writeInstructions( function.cfg.blocks, names, writeBlock, stream );
			return stream;
		}

		std::ostream & writeCapability( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );
			stream << "        " << spirv::getOperatorName( opCode );
			stream << " " << getName( spv::Capability( instruction.operands[0] ) );
			return stream;
		}

		std::ostream & writeImport( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			return stream;
		}

		std::ostream & writeMemoryModel( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );
			stream << "        " + spirv::getOperatorName( opCode );
			stream << " " + getName( spv::AddressingModel( instruction.operands[0] ) );
			stream << " " + getName( spv::MemoryModel( instruction.operands[1] ) );
			stream << "\n";
			return stream;
		}

		std::ostream & writeEntryPoint( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );
			stream << "        " + spirv::getOperatorName( opCode );
			stream << " " + getName( spv::ExecutionModel( instruction.operands[0] ) );
			stream << " %" + std::to_string( instruction.operands[1] );
			stream << " \"" + instruction.name.value() + "\"";

			for ( size_t i = 2u; i < instruction.operands.size(); ++i )
			{
				stream << " %" + std::to_string( instruction.operands[i] );
			}

			stream << "\n";
			return stream;
		}

		std::ostream & writeExecutionMode( spirv::Instruction const & instruction
			, IdNames & names
			, std::ostream & stream )
		{
			auto opCode = spv::Op( instruction.op.opCode );

			if ( opCode == spv::Op::OpExecutionMode )
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
			IdNames names;

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
			, size_t & result )
		{
			for ( auto & value : values )
			{
				count( value, result );
			}
		}

		template< typename T >
		void count( std::optional< T > const & value
			, size_t & result )
		{
			if ( value.has_value() )
			{
				count( value.value(), result );
			}
		}

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

		void count( spirv::Instruction const & instruction
			, size_t & result )
		{
			count( instruction.op, result );
			count( instruction.resultType, result );
			count( instruction.resultId, result );
			count( instruction.operands, result );
			count( instruction.packedName, result );
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
		void serialize( std::vector< T > const & values
			, std::vector< uint32_t > & result )
		{
			for ( auto & value : values )
			{
				serialize( value, result );
			}
		}

		template< typename T >
		void serialize( std::optional< T > const & value
			, std::vector< uint32_t > & result )
		{
			if ( value.has_value() )
			{
				serialize( value.value(), result );
			}
		}

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

		void serialize( spirv::Instruction const & instruction
			, std::vector< uint32_t > & result )
		{
			assert( instruction.op.opCount != 0 );
			serialize( instruction.op, result );
			serialize( instruction.resultType, result );
			serialize( instruction.resultId, result );
			serialize( instruction.operands, result );
			serialize( instruction.packedName, result );
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

		spirv::Module compileSpirV( Shader const & shader, ShaderType type )
		{
			auto container = spirv::StmtAdapter::submit( shader, type );
			return spirv::StmtVisitor::submit( container.get(), type );
		}
	}

	std::string writeSpirv( Shader const & shader
		, ShaderType type
		, bool writeHeader )
	{
		auto module = compileSpirV( shader, type );
		std::stringstream stream;
		write( module, writeHeader, stream );
		return stream.str();
	}

	std::vector< uint32_t > serialiseSpirv( Shader const & shader
		, ShaderType type )
	{
		auto module = compileSpirV( shader, type );
		std::vector< uint32_t > result;
		result.reserve( count( module ) );
		serialize( module, result );
		return result;
	}
}
