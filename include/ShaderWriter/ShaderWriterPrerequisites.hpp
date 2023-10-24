/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Prerequisites_H___
#define ___SDW_Prerequisites_H___

#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Type/TypeArray.hpp>
#include <ShaderAST/Type/TypeCache.hpp>
#include <ShaderAST/Type/TypeGeometryIO.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>

#pragma warning( push )
#pragma warning( disable: 5262 )
#include <map>
#include <type_traits>
#include <vector>
#pragma warning( pop )

#if !defined( SDW_MeshShadingEXT )
#	define SDW_MeshShadingEXT 1
#endif

#if !defined( SDW_MeshShadingNV )
#	define SDW_MeshShadingNV 2
#endif

#define Writer_Parameter( TypeName )\
	using P##TypeName = sdw::Param< TypeName >;\
	using In##TypeName = sdw::InParam< TypeName >;\
	using Out##TypeName = sdw::OutParam< TypeName >;\
	using InOut##TypeName = sdw::InOutParam< TypeName >;\
	using Ret##TypeName = sdw::ReturnWrapperT< TypeName >

#define Writer_ArrayParameter( TypeName )\
	using P##TypeName##Array = sdw::Param< sdw::Array< TypeName > >;\
	using In##TypeName##Array = sdw::InParam< sdw::Array< TypeName > >;\
	using Out##TypeName##Array = sdw::OutParam< sdw::Array< TypeName > >;\
	using InOut##TypeName##Array = sdw::InOutParam< sdw::Array< TypeName > >;\
	using Ret##TypeName##Array = sdw::ReturnWrapperT< sdw::Array< TypeName > >

#if defined( ShaderWriter_Static )
#	define SDW_API
#elif defined( _WIN32 )
#	if defined( ShaderWriter_Exports )
#		define SDW_API __declspec( dllexport )
#	else
#		define SDW_API __declspec( dllimport )
#	endif
#else
#	define SDW_API
#endif

namespace sdw
{
#pragma region Base
	/**
	*name
	*	Base.
	*/
	/**@{*/
	using ShaderArray = ast::ShaderArray;
	class ShaderWriter;
	/**@}*/
#pragma endregion
#pragma region Base types
	/**
	*name
	*	Base types.
	*/
	/**@{*/
	struct Value;
	struct Void;
	struct Boolean;
	struct AccelerationStructure;
	struct RayDesc;

	template< ast::type::Kind KindT >
	struct ArithmeticValue;
	using Half = ArithmeticValue< ast::type::Kind::eHalf >;
	using Float = ArithmeticValue< ast::type::Kind::eFloat >;
	using Double = ArithmeticValue< ast::type::Kind::eDouble >;

	template< ast::type::Kind KindT >
	struct IntegerValue;
	using Int8 = IntegerValue< ast::type::Kind::eInt8 >;
	using Int16 = IntegerValue< ast::type::Kind::eInt16 >;
	using Int32 = IntegerValue< ast::type::Kind::eInt32 >;
	using Int64 = IntegerValue< ast::type::Kind::eInt64 >;
	using UInt8 = IntegerValue< ast::type::Kind::eUInt8 >;
	using UInt16 = IntegerValue< ast::type::Kind::eUInt16 >;
	using UInt32 = IntegerValue< ast::type::Kind::eUInt32 >;
	using UInt64 = IntegerValue< ast::type::Kind::eUInt64 >;

	template< typename TypeT >
	struct Array;
	template< typename TypeT >
	struct DefaultedT;
	template< typename TypeT >
	struct Vec2T;
	template< typename TypeT >
	struct Vec3T;
	template< typename TypeT >
	struct Vec4T;
	template< typename TypeT >
	struct Mat2x2T;
	template< typename TypeT >
	struct Mat2x3T;
	template< typename TypeT >
	struct Mat2x4T;
	template< typename TypeT >
	struct Mat3x3T;
	template< typename TypeT >
	struct Mat3x2T;
	template< typename TypeT >
	struct Mat3x4T;
	template< typename TypeT >
	struct Mat4x4T;
	template< typename TypeT >
	struct Mat4x2T;
	template< typename TypeT >
	struct Mat4x3T;
	template< typename TypeT >
	struct NonUniformT;

	using Vec2 = Vec2T< Float >;
	using Vec3 = Vec3T< Float >;
	using Vec4 = Vec4T< Float >;
	using DVec2 = Vec2T< Double >;
	using DVec3 = Vec3T< Double >;
	using DVec4 = Vec4T< Double >;
	using HVec2 = Vec2T< Half >;
	using HVec4 = Vec4T< Half >;
	using I8Vec2 = Vec2T< Int8 >;
	using I8Vec3 = Vec3T< Int8 >;
	using I8Vec4 = Vec4T< Int8 >;
	using I16Vec2 = Vec2T< Int16 >;
	using I16Vec3 = Vec3T< Int16 >;
	using I16Vec4 = Vec4T< Int16 >;
	using I32Vec2 = Vec2T< Int32 >;
	using I32Vec3 = Vec3T< Int32 >;
	using I32Vec4 = Vec4T< Int32 >;
	using I64Vec2 = Vec2T< Int64 >;
	using I64Vec3 = Vec3T< Int64 >;
	using I64Vec4 = Vec4T< Int64 >;
	using U8Vec2 = Vec2T< UInt8 >;
	using U8Vec3 = Vec3T< UInt8 >;
	using U8Vec4 = Vec4T< UInt8 >;
	using U16Vec2 = Vec2T< UInt16 >;
	using U16Vec3 = Vec3T< UInt16 >;
	using U16Vec4 = Vec4T< UInt16 >;
	using U32Vec2 = Vec2T< UInt32 >;
	using U32Vec3 = Vec3T< UInt32 >;
	using U32Vec4 = Vec4T< UInt32 >;
	using U64Vec2 = Vec2T< UInt64 >;
	using U64Vec3 = Vec3T< UInt64 >;
	using U64Vec4 = Vec4T< UInt64 >;
	using BVec2 = Vec2T< Boolean >;
	using BVec3 = Vec3T< Boolean >;
	using BVec4 = Vec4T< Boolean >;
	using Mat2 = Mat2x2T< Float >;
	using Mat2x2 = Mat2x2T< Float >;
	using Mat2x3 = Mat2x3T< Float >;
	using Mat2x4 = Mat2x4T< Float >;
	using Mat3 = Mat3x3T< Float >;
	using Mat3x3 = Mat3x3T< Float >;
	using Mat3x2 = Mat3x2T< Float >;
	using Mat3x4 = Mat3x4T< Float >;
	using Mat4 = Mat4x4T< Float >;
	using Mat4x4 = Mat4x4T< Float >;
	using Mat4x2 = Mat4x2T< Float >;
	using Mat4x3 = Mat4x3T< Float >;
	using DMat2 = Mat2x2T< Double >;
	using DMat2x2 = Mat2x2T< Double >;
	using DMat2x3 = Mat2x3T< Double >;
	using DMat2x4 = Mat2x4T< Double >;
	using DMat3 = Mat3x3T< Double >;
	using DMat3x2 = Mat3x2T< Double >;
	using DMat3x3 = Mat3x3T< Double >;
	using DMat3x4 = Mat3x4T< Double >;
	using DMat4 = Mat4x4T< Double >;
	using DMat4x2 = Mat4x2T< Double >;
	using DMat4x3 = Mat4x3T< Double >;
	using DMat4x4 = Mat4x4T< Double >;

	using Int = Int32;
	using UInt = UInt32;
	using IVec2 = I32Vec2;
	using IVec3 = I32Vec3;
	using IVec4 = I32Vec4;
	using UVec2 = U32Vec2;
	using UVec3 = U32Vec3;
	using UVec4 = U32Vec4;

	using DoubleArray = Array< Double >;
	using FloatArray = Array< Float >;
	using Int8Array = Array< Int8 >;
	using Int16Array = Array< Int16 >;
	using Int32Array = Array< Int32 >;
	using Int64Array = Array< Int64 >;
	using UInt8Array = Array< UInt8 >;
	using UInt16Array = Array< UInt16 >;
	using UInt32Array = Array< UInt32 >;
	using UInt64Array = Array< UInt64 >;
	using BooleanArray = Array< Boolean >;
	using Vec2Array = Array< Vec2 >;
	using Vec3Array = Array< Vec3 >;
	using Vec4Array = Array< Vec4 >;
	using DVec2Array = Array< DVec2 >;
	using DVec3Array = Array< DVec3 >;
	using DVec4Array = Array< DVec4 >;
	using I8Vec2Array = Array< I8Vec2 >;
	using I8Vec3Array = Array< I8Vec3 >;
	using I8Vec4Array = Array< I8Vec4 >;
	using I16Vec2Array = Array< I16Vec2 >;
	using I16Vec3Array = Array< I16Vec3 >;
	using I16Vec4Array = Array< I16Vec4 >;
	using I32Vec2Array = Array< I32Vec2 >;
	using I32Vec3Array = Array< I32Vec3 >;
	using I32Vec4Array = Array< I32Vec4 >;
	using I64Vec2Array = Array< I64Vec2 >;
	using I64Vec3Array = Array< I64Vec3 >;
	using I64Vec4Array = Array< I64Vec4 >;
	using U8Vec2Array = Array< U8Vec2 >;
	using U8Vec3Array = Array< U8Vec3 >;
	using U8Vec4Array = Array< U8Vec4 >;
	using U16Vec2Array = Array< U16Vec2 >;
	using U16Vec3Array = Array< U16Vec3 >;
	using U16Vec4Array = Array< U16Vec4 >;
	using U32Vec2Array = Array< U32Vec2 >;
	using U32Vec3Array = Array< U32Vec3 >;
	using U32Vec4Array = Array< U32Vec4 >;
	using U64Vec2Array = Array< U64Vec2 >;
	using U64Vec3Array = Array< U64Vec3 >;
	using U64Vec4Array = Array< U64Vec4 >;
	using BVec2Array = Array< BVec2 >;
	using BVec3Array = Array< BVec3 >;
	using BVec4Array = Array< BVec4 >;
	using Mat2Array = Array< Mat2 >;
	using Mat2x3Array = Array< Mat2x3 >;
	using Mat2x4Array = Array< Mat2x4 >;
	using Mat3Array = Array< Mat3 >;
	using Mat3x2Array = Array< Mat3x2 >;
	using Mat3x4Array = Array< Mat3x4 >;
	using Mat4Array = Array< Mat4 >;
	using Mat4x2Array = Array< Mat4x2 >;
	using Mat4x3Array = Array< Mat4x3 >;
	using DMat2Array = Array< DMat2 >;
	using DMat2x3Array = Array< DMat2x3 >;
	using DMat2x4Array = Array< DMat2x4 >;
	using DMat3Array = Array< DMat3 >;
	using DMat3x2Array = Array< DMat3x2 >;
	using DMat3x4Array = Array< DMat3x4 >;
	using DMat4Array = Array< DMat4 >;
	using DMat4x2Array = Array< DMat4x2 >;
	using DMat4x3Array = Array< DMat4x3 >;

	using IntArray = Int32Array;
	using UIntArray = UInt32Array;
	using IVec2Array = I32Vec2Array;
	using IVec3Array = I32Vec3Array;
	using IVec4Array = I32Vec4Array;
	using UVec2Array = U32Vec2Array;
	using UVec3Array = U32Vec3Array;
	using UVec4Array = U32Vec4Array;
	/**@}*/
#pragma endregion
#pragma region Shader interface types
	/**
	*name
	*	Shader interface types.
	*/
	/**@{*/
	class Struct;
	class StructInstance;

	class PushConstantBuffer;
	class StorageBuffer;
	class UniformBuffer;

	template< typename InstanceT >
	class ArrayStorageBufferT;
	/**@}*/
#pragma endregion
#pragma region Shader I/O
	/**
	*name
	*	Shader I/O.
	*/
	/**@{*/
	struct PerVertex;

	struct InTessellationEvaluation;
	struct OutTessellationEvaluation;

	template< ast::var::Flag FlagT >
	struct VoidT;
	template< ast::EntryPoint EntryPointT, ast::var::Flag FlagT, template< ast::var::Flag DataFlagT > typename DataT >
	struct EntryTypeT;
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchInT;
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchOutT;
	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	struct InputT;
	template< ast::EntryPoint EntryPointT, template< ast::var::Flag FlagT > typename DataT >
	struct OutputT;
	template< ast::var::Flag FlagT, typename TypeT >
	struct RayPayloadBaseT;
	template< ast::var::Flag FlagT, typename TypeT >
	struct CallableDataBaseT;
	template< typename TypeT >
	struct HitAttributeT;

	template< typename DataT >
	using RayPayloadInT = RayPayloadBaseT< ast::var::Flag::eShaderInput, DataT >;
	template< typename DataT >
	using RayPayloadT = RayPayloadBaseT< ast::var::Flag::eShaderOutput, DataT >;
	template< typename DataT >
	using CallableDataInT = CallableDataBaseT< ast::var::Flag::eShaderInput, DataT >;
	template< typename DataT >
	using CallableDataT = CallableDataBaseT< ast::var::Flag::eShaderOutput, DataT >;

	template< ast::EntryPoint EntryPointT >
	using Input = InputT< EntryPointT, VoidT >;
	template< ast::EntryPoint EntryPointT >
	using Output = OutputT< EntryPointT, VoidT >;
	using PatchIn = PatchInT< VoidT >;
	using PatchOut = PatchOutT< VoidT >;
	/**@}*/
#pragma endregion
#pragma region Images
	/**
	*name
	*	Images.
	*/
	/**@{*/
	struct StorageImage;
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct StorageImageT;

	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImageBufferT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::eBuffer
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage1DT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e1D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage2DT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage3DT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e3D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImageCubeT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::eCube
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage1DArrayT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e1D
		, true
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage2DArrayT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, true
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImageCubeArrayT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::eCube
		, true
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage2DMST = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, false
		, true >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using StorageImage2DMSArrayT = StorageImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, true
		, true >;

	template< ast::type::ImageFormat FormatT >
	using RImageBufferT = StorageImageBufferT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage1DT = StorageImage1DT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DT = StorageImage2DT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage3DT = StorageImage3DT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImageCubeT = StorageImageCubeT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage1DArrayT = StorageImage1DArrayT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DArrayT = StorageImage2DArrayT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImageCubeArrayT = StorageImageCubeArrayT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DMST = StorageImage2DMST< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DMSArrayT = StorageImage2DMSArrayT< FormatT, ast::type::AccessKind::eRead >;

	template< ast::type::ImageFormat FormatT >
	using WImageBufferT = StorageImageBufferT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage1DT = StorageImage1DT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DT = StorageImage2DT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage3DT = StorageImage3DT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImageCubeT = StorageImageCubeT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage1DArrayT = StorageImage1DArrayT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DArrayT = StorageImage2DArrayT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImageCubeArrayT = StorageImageCubeArrayT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DMST = StorageImage2DMST< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DMSArrayT = StorageImage2DMSArrayT< FormatT, ast::type::AccessKind::eWrite >;

	template< ast::type::ImageFormat FormatT >
	using RWImageBufferT = StorageImageBufferT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage1DT = StorageImage1DT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DT = StorageImage2DT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage3DT = StorageImage3DT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImageCubeT = StorageImageCubeT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage1DArrayT = StorageImage1DArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DArrayT = StorageImage2DArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImageCubeArrayT = StorageImageCubeArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DMST = StorageImage2DMST< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DMSArrayT = StorageImage2DMSArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	/**@}*/
#pragma endregion
#pragma region Samplers
	/**
	*name
	*	Samplers.
	*/
	/**@{*/
	struct Sampler;
	template< bool ComparisonT >
	struct SamplerT;
	/**@}*/
#pragma endregion
#pragma region Sampled images
	/**
	*name
	*	Sampled images.
	*/
	/**@{*/
	struct SampledImage;
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct SampledImageT;

	template< ast::type::ImageFormat FormatT >
	using SampledImageBufferT = SampledImageT< FormatT
		, ast::type::ImageDim::eBuffer
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DT = SampledImageT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage3DT = SampledImageT< FormatT
		, ast::type::ImageDim::e3D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeT = SampledImageT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DMST = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DMSArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, true >;
	/**@}*/
#pragma endregion
#pragma region Combined Sampler and Images
	/**
	*name
	*	Combined Sampler and Images.
	*/
	/**@{*/
	struct CombinedImage;
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT = false >
	struct CombinedImageT;

	template< ast::type::ImageFormat FormatT >
	using CombinedImageBufferT = CombinedImageT< FormatT
		, ast::type::ImageDim::eBuffer
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage1DT = CombinedImageT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage2DT = CombinedImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage3DT = CombinedImageT< FormatT
		, ast::type::ImageDim::e3D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImageCubeT = CombinedImageT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage1DArrayT = CombinedImageT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage2DArrayT = CombinedImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImageCubeArrayT = CombinedImageT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage1DShadowT = CombinedImageT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage2DShadowT = CombinedImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImageCubeShadowT = CombinedImageT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage1DArrayShadowT = CombinedImageT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage2DArrayShadowT = CombinedImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImageCubeArrayShadowT = CombinedImageT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage2DMST = CombinedImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using CombinedImage2DMSArrayT = CombinedImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, true
		, false >;
	/**@}*/
#pragma endregion
#pragma region Function related
	/**
	*name
	*	Function related.
	*/
	/**@{*/
	template< typename RetT, typename ... ParamsT >
	struct Function;
	template< typename TypeT >
	struct Param;
	template< typename TypeT >
	struct InParam;
	template< typename TypeT >
	struct OutParam;
	template< typename TypeT >
	struct InOutParam;
	template< typename TypeT >
	struct ReturnWrapperT;

	Writer_Parameter( Double );
	Writer_Parameter( Float );
	Writer_Parameter( Int8 );
	Writer_Parameter( Int16 );
	Writer_Parameter( Int32 );
	Writer_Parameter( Int64 );
	Writer_Parameter( UInt8 );
	Writer_Parameter( UInt16 );
	Writer_Parameter( UInt32 );
	Writer_Parameter( UInt64 );
	Writer_Parameter( Boolean );
	Writer_Parameter( Vec2 );
	Writer_Parameter( Vec3 );
	Writer_Parameter( Vec4 );
	Writer_Parameter( DVec2 );
	Writer_Parameter( DVec3 );
	Writer_Parameter( DVec4 );
	Writer_Parameter( HVec2 );
	Writer_Parameter( HVec4 );
	Writer_Parameter( I8Vec2 );
	Writer_Parameter( I8Vec3 );
	Writer_Parameter( I8Vec4 );
	Writer_Parameter( I16Vec2 );
	Writer_Parameter( I16Vec3 );
	Writer_Parameter( I16Vec4 );
	Writer_Parameter( I32Vec2 );
	Writer_Parameter( I32Vec3 );
	Writer_Parameter( I32Vec4 );
	Writer_Parameter( I64Vec2 );
	Writer_Parameter( I64Vec3 );
	Writer_Parameter( I64Vec4 );
	Writer_Parameter( U8Vec2 );
	Writer_Parameter( U8Vec3 );
	Writer_Parameter( U8Vec4 );
	Writer_Parameter( U16Vec2 );
	Writer_Parameter( U16Vec3 );
	Writer_Parameter( U16Vec4 );
	Writer_Parameter( U32Vec2 );
	Writer_Parameter( U32Vec3 );
	Writer_Parameter( U32Vec4 );
	Writer_Parameter( U64Vec2 );
	Writer_Parameter( U64Vec3 );
	Writer_Parameter( U64Vec4 );
	Writer_Parameter( BVec2 );
	Writer_Parameter( BVec3 );
	Writer_Parameter( BVec4 );
	Writer_Parameter( Mat2 );
	Writer_Parameter( Mat2x3 );
	Writer_Parameter( Mat2x4 );
	Writer_Parameter( Mat3 );
	Writer_Parameter( Mat3x2 );
	Writer_Parameter( Mat3x4 );
	Writer_Parameter( Mat4 );
	Writer_Parameter( Mat4x2 );
	Writer_Parameter( Mat4x3 );
	Writer_Parameter( DMat2 );
	Writer_Parameter( DMat2x3 );
	Writer_Parameter( DMat2x4 );
	Writer_Parameter( DMat3 );
	Writer_Parameter( DMat3x2 );
	Writer_Parameter( DMat3x4 );
	Writer_Parameter( DMat4 );
	Writer_Parameter( DMat4x2 );
	Writer_Parameter( DMat4x3 );

	Writer_Parameter( DoubleArray );
	Writer_Parameter( FloatArray );
	Writer_Parameter( Int8Array );
	Writer_Parameter( Int16Array );
	Writer_Parameter( Int32Array );
	Writer_Parameter( Int64Array );
	Writer_Parameter( UInt8Array );
	Writer_Parameter( UInt16Array );
	Writer_Parameter( UInt32Array );
	Writer_Parameter( UInt64Array );
	Writer_Parameter( BooleanArray );
	Writer_Parameter( Vec2Array );
	Writer_Parameter( Vec3Array );
	Writer_Parameter( Vec4Array );
	Writer_Parameter( DVec2Array );
	Writer_Parameter( DVec3Array );
	Writer_Parameter( DVec4Array );
	Writer_Parameter( I8Vec2Array );
	Writer_Parameter( I8Vec3Array );
	Writer_Parameter( I8Vec4Array );
	Writer_Parameter( I16Vec2Array );
	Writer_Parameter( I16Vec3Array );
	Writer_Parameter( I16Vec4Array );
	Writer_Parameter( I32Vec2Array );
	Writer_Parameter( I32Vec3Array );
	Writer_Parameter( I32Vec4Array );
	Writer_Parameter( I64Vec2Array );
	Writer_Parameter( I64Vec3Array );
	Writer_Parameter( I64Vec4Array );
	Writer_Parameter( U8Vec2Array );
	Writer_Parameter( U8Vec3Array );
	Writer_Parameter( U8Vec4Array );
	Writer_Parameter( U16Vec2Array );
	Writer_Parameter( U16Vec3Array );
	Writer_Parameter( U16Vec4Array );
	Writer_Parameter( U32Vec2Array );
	Writer_Parameter( U32Vec3Array );
	Writer_Parameter( U32Vec4Array );
	Writer_Parameter( U64Vec2Array );
	Writer_Parameter( U64Vec3Array );
	Writer_Parameter( U64Vec4Array );
	Writer_Parameter( BVec2Array );
	Writer_Parameter( BVec3Array );
	Writer_Parameter( BVec4Array );
	Writer_Parameter( Mat2Array );
	Writer_Parameter( Mat2x3Array );
	Writer_Parameter( Mat2x4Array );
	Writer_Parameter( Mat3Array );
	Writer_Parameter( Mat3x2Array );
	Writer_Parameter( Mat3x4Array );
	Writer_Parameter( Mat4Array );
	Writer_Parameter( Mat4x2Array );
	Writer_Parameter( Mat4x3Array );
	Writer_Parameter( DMat2Array );
	Writer_Parameter( DMat2x3Array );
	Writer_Parameter( DMat2x4Array );
	Writer_Parameter( DMat3Array );
	Writer_Parameter( DMat3x2Array );
	Writer_Parameter( DMat3x4Array );
	Writer_Parameter( DMat4Array );
	Writer_Parameter( DMat4x2Array );
	Writer_Parameter( DMat4x3Array );

	Writer_Parameter( Int );
	Writer_Parameter( UInt );
	Writer_Parameter( IVec2 );
	Writer_Parameter( IVec3 );
	Writer_Parameter( IVec4 );
	Writer_Parameter( UVec2 );
	Writer_Parameter( UVec3 );
	Writer_Parameter( UVec4 );

	Writer_Parameter( IntArray );
	Writer_Parameter( UIntArray );
	Writer_Parameter( IVec2Array );
	Writer_Parameter( IVec3Array );
	Writer_Parameter( IVec4Array );
	Writer_Parameter( UVec2Array );
	Writer_Parameter( UVec3Array );
	Writer_Parameter( UVec4Array );
	/**@}*/
#pragma endregion
#pragma region Function and images related
	/**
	*name
	*	Function and images related.
	*/
	/**@{*/
#	define Writer_StorageImage( Prefix, TypeName, Format, Postfix )\
		template< ast::type::AccessKind AccessT >\
		using Prefix##TypeName##Format##T = Storage##TypeName##T< ast::type::ImageFormat::e##Format##Postfix, AccessT >;\
		using R##Prefix##TypeName##Format = R##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( R##Prefix##TypeName##Format );\
		Writer_ArrayParameter( R##Prefix##TypeName##Format );\
		using W##Prefix##TypeName##Format = W##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( W##Prefix##TypeName##Format );\
		Writer_ArrayParameter( W##Prefix##TypeName##Format );\
		using RW##Prefix##TypeName##Format = RW##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( RW##Prefix##TypeName##Format );\
		Writer_ArrayParameter( RW##Prefix##TypeName##Format )

#	define Writer_UniformImage( Type, Prefix, TypeName, Format, Postfix )\
		using Type##Prefix##TypeName##Format = Prefix##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( Type##Prefix##TypeName##Format );\
		Writer_ArrayParameter( Type##Prefix##TypeName##Format )

#	define Writer_CombinedImage( Prefix, TypeName, Format, Postfix )\
		Writer_UniformImage( Prefix, Combined, TypeName, Format, Postfix )

#	define Writer_SampledImage( Prefix, TypeName, Format, Postfix )\
		Writer_UniformImage( Prefix, Sampled, TypeName, Format, Postfix )

	Writer_StorageImage( , ImageBuffer, Rgba32, f );
	Writer_StorageImage( , Image1D, Rgba32, f );
	Writer_StorageImage( , Image2D, Rgba32, f );
	Writer_StorageImage( , Image3D, Rgba32, f );
	Writer_StorageImage( , ImageCube, Rgba32, f );
	Writer_StorageImage( , Image1DArray, Rgba32, f );
	Writer_StorageImage( , Image2DArray, Rgba32, f );
	Writer_StorageImage( , ImageCubeArray, Rgba32, f );
	Writer_StorageImage( , Image2DMS, Rgba32, f );
	Writer_StorageImage( , Image2DMSArray, Rgba32, f );
	Writer_CombinedImage( , ImageBuffer, Rgba32, f );
	Writer_CombinedImage( , Image1D, Rgba32, f );
	Writer_CombinedImage( , Image2D, Rgba32, f );
	Writer_CombinedImage( , Image3D, Rgba32, f );
	Writer_CombinedImage( , ImageCube, Rgba32, f );
	Writer_CombinedImage( , Image1DArray, Rgba32, f );
	Writer_CombinedImage( , Image2DArray, Rgba32, f );
	Writer_CombinedImage( , ImageCubeArray, Rgba32, f );
	Writer_CombinedImage( , Image2DMS, Rgba32, f );
	Writer_CombinedImage( , Image2DMSArray, Rgba32, f );
	Writer_SampledImage( , ImageBuffer, Rgba32, f );
	Writer_SampledImage( , Image1D, Rgba32, f );
	Writer_SampledImage( , Image2D, Rgba32, f );
	Writer_SampledImage( , Image3D, Rgba32, f );
	Writer_SampledImage( , ImageCube, Rgba32, f );
	Writer_SampledImage( , Image1DArray, Rgba32, f );
	Writer_SampledImage( , Image2DArray, Rgba32, f );
	Writer_SampledImage( , ImageCubeArray, Rgba32, f );
	Writer_SampledImage( , Image2DMS, Rgba32, f );
	Writer_SampledImage( , Image2DMSArray, Rgba32, f );
	Writer_StorageImage( , ImageBuffer, Rgba16, f );
	Writer_StorageImage( , Image1D, Rgba16, f );
	Writer_StorageImage( , Image2D, Rgba16, f );
	Writer_StorageImage( , Image3D, Rgba16, f );
	Writer_StorageImage( , ImageCube, Rgba16, f );
	Writer_StorageImage( , Image1DArray, Rgba16, f );
	Writer_StorageImage( , Image2DArray, Rgba16, f );
	Writer_StorageImage( , ImageCubeArray, Rgba16, f );
	Writer_StorageImage( , Image2DMS, Rgba16, f );
	Writer_StorageImage( , Image2DMSArray, Rgba16, f );
	Writer_CombinedImage( , ImageBuffer, Rgba16, f );
	Writer_CombinedImage( , Image1D, Rgba16, f );
	Writer_CombinedImage( , Image2D, Rgba16, f );
	Writer_CombinedImage( , Image3D, Rgba16, f );
	Writer_CombinedImage( , ImageCube, Rgba16, f );
	Writer_CombinedImage( , Image1DArray, Rgba16, f );
	Writer_CombinedImage( , Image2DArray, Rgba16, f );
	Writer_CombinedImage( , ImageCubeArray, Rgba16, f );
	Writer_CombinedImage( , Image2DMS, Rgba16, f );
	Writer_CombinedImage( , Image2DMSArray, Rgba16, f );
	Writer_SampledImage( , ImageBuffer, Rgba16, f );
	Writer_SampledImage( , Image1D, Rgba16, f );
	Writer_SampledImage( , Image2D, Rgba16, f );
	Writer_SampledImage( , Image3D, Rgba16, f );
	Writer_SampledImage( , ImageCube, Rgba16, f );
	Writer_SampledImage( , Image1DArray, Rgba16, f );
	Writer_SampledImage( , Image2DArray, Rgba16, f );
	Writer_SampledImage( , ImageCubeArray, Rgba16, f );
	Writer_SampledImage( , Image2DMS, Rgba16, f );
	Writer_SampledImage( , Image2DMSArray, Rgba16, f );
	Writer_StorageImage( , ImageBuffer, Rg32, f );
	Writer_StorageImage( , Image1D, Rg32, f );
	Writer_StorageImage( , Image2D, Rg32, f );
	Writer_StorageImage( , Image3D, Rg32, f );
	Writer_StorageImage( , ImageCube, Rg32, f );
	Writer_StorageImage( , Image1DArray, Rg32, f );
	Writer_StorageImage( , Image2DArray, Rg32, f );
	Writer_StorageImage( , ImageCubeArray, Rg32, f );
	Writer_StorageImage( , Image2DMS, Rg32, f );
	Writer_StorageImage( , Image2DMSArray, Rg32, f );
	Writer_CombinedImage( , ImageBuffer, Rg32, f );
	Writer_CombinedImage( , Image1D, Rg32, f );
	Writer_CombinedImage( , Image2D, Rg32, f );
	Writer_CombinedImage( , Image3D, Rg32, f );
	Writer_CombinedImage( , ImageCube, Rg32, f );
	Writer_CombinedImage( , Image1DArray, Rg32, f );
	Writer_CombinedImage( , Image2DArray, Rg32, f );
	Writer_CombinedImage( , ImageCubeArray, Rg32, f );
	Writer_CombinedImage( , Image2DMS, Rg32, f );
	Writer_CombinedImage( , Image2DMSArray, Rg32, f );
	Writer_SampledImage( , ImageBuffer, Rg32, f );
	Writer_SampledImage( , Image1D, Rg32, f );
	Writer_SampledImage( , Image2D, Rg32, f );
	Writer_SampledImage( , Image3D, Rg32, f );
	Writer_SampledImage( , ImageCube, Rg32, f );
	Writer_SampledImage( , Image1DArray, Rg32, f );
	Writer_SampledImage( , Image2DArray, Rg32, f );
	Writer_SampledImage( , ImageCubeArray, Rg32, f );
	Writer_SampledImage( , Image2DMS, Rg32, f );
	Writer_SampledImage( , Image2DMSArray, Rg32, f );
	Writer_StorageImage( , ImageBuffer, Rg16, f );
	Writer_StorageImage( , Image1D, Rg16, f );
	Writer_StorageImage( , Image2D, Rg16, f );
	Writer_StorageImage( , Image3D, Rg16, f );
	Writer_StorageImage( , ImageCube, Rg16, f );
	Writer_StorageImage( , Image1DArray, Rg16, f );
	Writer_StorageImage( , Image2DArray, Rg16, f );
	Writer_StorageImage( , ImageCubeArray, Rg16, f );
	Writer_StorageImage( , Image2DMS, Rg16, f );
	Writer_StorageImage( , Image2DMSArray, Rg16, f );
	Writer_CombinedImage( , ImageBuffer, Rg16, f );
	Writer_CombinedImage( , Image1D, Rg16, f );
	Writer_CombinedImage( , Image2D, Rg16, f );
	Writer_CombinedImage( , Image3D, Rg16, f );
	Writer_CombinedImage( , ImageCube, Rg16, f );
	Writer_CombinedImage( , Image1DArray, Rg16, f );
	Writer_CombinedImage( , Image2DArray, Rg16, f );
	Writer_CombinedImage( , ImageCubeArray, Rg16, f );
	Writer_CombinedImage( , Image2DMS, Rg16, f );
	Writer_CombinedImage( , Image2DMSArray, Rg16, f );
	Writer_SampledImage( , ImageBuffer, Rg16, f );
	Writer_SampledImage( , Image1D, Rg16, f );
	Writer_SampledImage( , Image2D, Rg16, f );
	Writer_SampledImage( , Image3D, Rg16, f );
	Writer_SampledImage( , ImageCube, Rg16, f );
	Writer_SampledImage( , Image1DArray, Rg16, f );
	Writer_SampledImage( , Image2DArray, Rg16, f );
	Writer_SampledImage( , ImageCubeArray, Rg16, f );
	Writer_SampledImage( , Image2DMS, Rg16, f );
	Writer_SampledImage( , Image2DMSArray, Rg16, f );
	Writer_StorageImage( , ImageBuffer, R32, f );
	Writer_StorageImage( , Image1D, R32, f );
	Writer_StorageImage( , Image2D, R32, f );
	Writer_StorageImage( , Image3D, R32, f );
	Writer_StorageImage( , ImageCube, R32, f );
	Writer_StorageImage( , Image1DArray, R32, f );
	Writer_StorageImage( , Image2DArray, R32, f );
	Writer_StorageImage( , ImageCubeArray, R32, f );
	Writer_StorageImage( , Image2DMS, R32, f );
	Writer_StorageImage( , Image2DMSArray, R32, f );
	Writer_CombinedImage( , ImageBuffer, R32, f );
	Writer_CombinedImage( , Image1D, R32, f );
	Writer_CombinedImage( , Image2D, R32, f );
	Writer_CombinedImage( , Image3D, R32, f );
	Writer_CombinedImage( , ImageCube, R32, f );
	Writer_CombinedImage( , Image1DArray, R32, f );
	Writer_CombinedImage( , Image2DArray, R32, f );
	Writer_CombinedImage( , ImageCubeArray, R32, f );
	Writer_CombinedImage( , Image2DMS, R32, f );
	Writer_CombinedImage( , Image2DMSArray, R32, f );
	Writer_SampledImage( , ImageBuffer, R32, f );
	Writer_SampledImage( , Image1D, R32, f );
	Writer_SampledImage( , Image2D, R32, f );
	Writer_SampledImage( , Image3D, R32, f );
	Writer_SampledImage( , ImageCube, R32, f );
	Writer_SampledImage( , Image1DArray, R32, f );
	Writer_SampledImage( , Image2DArray, R32, f );
	Writer_SampledImage( , ImageCubeArray, R32, f );
	Writer_SampledImage( , Image2DMS, R32, f );
	Writer_SampledImage( , Image2DMSArray, R32, f );
	Writer_StorageImage( , ImageBuffer, R16, f );
	Writer_StorageImage( , Image1D, R16, f );
	Writer_StorageImage( , Image2D, R16, f );
	Writer_StorageImage( , Image3D, R16, f );
	Writer_StorageImage( , ImageCube, R16, f );
	Writer_StorageImage( , Image1DArray, R16, f );
	Writer_StorageImage( , Image2DArray, R16, f );
	Writer_StorageImage( , ImageCubeArray, R16, f );
	Writer_StorageImage( , Image2DMS, R16, f );
	Writer_StorageImage( , Image2DMSArray, R16, f );
	Writer_CombinedImage( , ImageBuffer, R16, f );
	Writer_CombinedImage( , Image1D, R16, f );
	Writer_CombinedImage( , Image2D, R16, f );
	Writer_CombinedImage( , Image3D, R16, f );
	Writer_CombinedImage( , ImageCube, R16, f );
	Writer_CombinedImage( , Image1DArray, R16, f );
	Writer_CombinedImage( , Image2DArray, R16, f );
	Writer_CombinedImage( , ImageCubeArray, R16, f );
	Writer_CombinedImage( , Image2DMS, R16, f );
	Writer_CombinedImage( , Image2DMSArray, R16, f );
	Writer_CombinedImage( , Image1DShadow, R32, f );
	Writer_CombinedImage( , Image2DShadow, R32, f );
	Writer_CombinedImage( , ImageCubeShadow, R32, f );
	Writer_CombinedImage( , Image1DArrayShadow, R32, f );
	Writer_CombinedImage( , Image2DArrayShadow, R32, f );
	Writer_CombinedImage( , ImageCubeArrayShadow, R32, f );
	Writer_CombinedImage( , Image1DShadow, R16, f );
	Writer_CombinedImage( , Image2DShadow, R16, f );
	Writer_CombinedImage( , ImageCubeShadow, R16, f );
	Writer_CombinedImage( , Image1DArrayShadow, R16, f );
	Writer_CombinedImage( , Image2DArrayShadow, R16, f );
	Writer_CombinedImage( , ImageCubeArrayShadow, R16, f );
	Writer_SampledImage( , ImageBuffer, R16, f );
	Writer_SampledImage( , Image1D, R16, f );
	Writer_SampledImage( , Image2D, R16, f );
	Writer_SampledImage( , Image3D, R16, f );
	Writer_SampledImage( , ImageCube, R16, f );
	Writer_SampledImage( , Image1DArray, R16, f );
	Writer_SampledImage( , Image2DArray, R16, f );
	Writer_SampledImage( , ImageCubeArray, R16, f );
	Writer_SampledImage( , Image2DMS, R16, f );
	Writer_SampledImage( , Image2DMSArray, R16, f );
	Writer_StorageImage( I, ImageBuffer, Rgba32, i );
	Writer_StorageImage( I, Image1D, Rgba32, i );
	Writer_StorageImage( I, Image2D, Rgba32, i );
	Writer_StorageImage( I, Image3D, Rgba32, i );
	Writer_StorageImage( I, ImageCube, Rgba32, i );
	Writer_StorageImage( I, Image1DArray, Rgba32, i );
	Writer_StorageImage( I, Image2DArray, Rgba32, i );
	Writer_StorageImage( I, ImageCubeArray, Rgba32, i );
	Writer_StorageImage( I, Image2DMS, Rgba32, i );
	Writer_StorageImage( I, Image2DMSArray, Rgba32, i );
	Writer_CombinedImage( I, ImageBuffer, Rgba32, i );
	Writer_CombinedImage( I, Image1D, Rgba32, i );
	Writer_CombinedImage( I, Image2D, Rgba32, i );
	Writer_CombinedImage( I, Image3D, Rgba32, i );
	Writer_CombinedImage( I, ImageCube, Rgba32, i );
	Writer_CombinedImage( I, Image1DArray, Rgba32, i );
	Writer_CombinedImage( I, Image2DArray, Rgba32, i );
	Writer_CombinedImage( I, ImageCubeArray, Rgba32, i );
	Writer_CombinedImage( I, Image2DMS, Rgba32, i );
	Writer_CombinedImage( I, Image2DMSArray, Rgba32, i );
	Writer_SampledImage( I, ImageBuffer, Rgba32, i );
	Writer_SampledImage( I, Image1D, Rgba32, i );
	Writer_SampledImage( I, Image2D, Rgba32, i );
	Writer_SampledImage( I, Image3D, Rgba32, i );
	Writer_SampledImage( I, ImageCube, Rgba32, i );
	Writer_SampledImage( I, Image1DArray, Rgba32, i );
	Writer_SampledImage( I, Image2DArray, Rgba32, i );
	Writer_SampledImage( I, ImageCubeArray, Rgba32, i );
	Writer_SampledImage( I, Image2DMS, Rgba32, i );
	Writer_SampledImage( I, Image2DMSArray, Rgba32, i );
	Writer_StorageImage( I, ImageBuffer, Rgba16, i );
	Writer_StorageImage( I, Image1D, Rgba16, i );
	Writer_StorageImage( I, Image2D, Rgba16, i );
	Writer_StorageImage( I, Image3D, Rgba16, i );
	Writer_StorageImage( I, ImageCube, Rgba16, i );
	Writer_StorageImage( I, Image1DArray, Rgba16, i );
	Writer_StorageImage( I, Image2DArray, Rgba16, i );
	Writer_StorageImage( I, ImageCubeArray, Rgba16, i );
	Writer_StorageImage( I, Image2DMS, Rgba16, i );
	Writer_StorageImage( I, Image2DMSArray, Rgba16, i );
	Writer_CombinedImage( I, ImageBuffer, Rgba16, i );
	Writer_CombinedImage( I, Image1D, Rgba16, i );
	Writer_CombinedImage( I, Image2D, Rgba16, i );
	Writer_CombinedImage( I, Image3D, Rgba16, i );
	Writer_CombinedImage( I, ImageCube, Rgba16, i );
	Writer_CombinedImage( I, Image1DArray, Rgba16, i );
	Writer_CombinedImage( I, Image2DArray, Rgba16, i );
	Writer_CombinedImage( I, ImageCubeArray, Rgba16, i );
	Writer_CombinedImage( I, Image2DMS, Rgba16, i );
	Writer_CombinedImage( I, Image2DMSArray, Rgba16, i );
	Writer_SampledImage( I, ImageBuffer, Rgba16, i );
	Writer_SampledImage( I, Image1D, Rgba16, i );
	Writer_SampledImage( I, Image2D, Rgba16, i );
	Writer_SampledImage( I, Image3D, Rgba16, i );
	Writer_SampledImage( I, ImageCube, Rgba16, i );
	Writer_SampledImage( I, Image1DArray, Rgba16, i );
	Writer_SampledImage( I, Image2DArray, Rgba16, i );
	Writer_SampledImage( I, ImageCubeArray, Rgba16, i );
	Writer_SampledImage( I, Image2DMS, Rgba16, i );
	Writer_SampledImage( I, Image2DMSArray, Rgba16, i );
	Writer_StorageImage( I, ImageBuffer, Rgba8, i );
	Writer_StorageImage( I, Image1D, Rgba8, i );
	Writer_StorageImage( I, Image2D, Rgba8, i );
	Writer_StorageImage( I, Image3D, Rgba8, i );
	Writer_StorageImage( I, ImageCube, Rgba8, i );
	Writer_StorageImage( I, Image1DArray, Rgba8, i );
	Writer_StorageImage( I, Image2DArray, Rgba8, i );
	Writer_StorageImage( I, ImageCubeArray, Rgba8, i );
	Writer_StorageImage( I, Image2DMS, Rgba8, i );
	Writer_StorageImage( I, Image2DMSArray, Rgba8, i );
	Writer_CombinedImage( I, ImageBuffer, Rgba8, i );
	Writer_CombinedImage( I, Image1D, Rgba8, i );
	Writer_CombinedImage( I, Image2D, Rgba8, i );
	Writer_CombinedImage( I, Image3D, Rgba8, i );
	Writer_CombinedImage( I, ImageCube, Rgba8, i );
	Writer_CombinedImage( I, Image1DArray, Rgba8, i );
	Writer_CombinedImage( I, Image2DArray, Rgba8, i );
	Writer_CombinedImage( I, ImageCubeArray, Rgba8, i );
	Writer_CombinedImage( I, Image2DMS, Rgba8, i );
	Writer_CombinedImage( I, Image2DMSArray, Rgba8, i );
	Writer_SampledImage( I, ImageBuffer, Rgba8, i );
	Writer_SampledImage( I, Image1D, Rgba8, i );
	Writer_SampledImage( I, Image2D, Rgba8, i );
	Writer_SampledImage( I, Image3D, Rgba8, i );
	Writer_SampledImage( I, ImageCube, Rgba8, i );
	Writer_SampledImage( I, Image1DArray, Rgba8, i );
	Writer_SampledImage( I, Image2DArray, Rgba8, i );
	Writer_SampledImage( I, ImageCubeArray, Rgba8, i );
	Writer_SampledImage( I, Image2DMS, Rgba8, i );
	Writer_SampledImage( I, Image2DMSArray, Rgba8, i );
	Writer_StorageImage( I, ImageBuffer, Rg32, i );
	Writer_StorageImage( I, Image1D, Rg32, i );
	Writer_StorageImage( I, Image2D, Rg32, i );
	Writer_StorageImage( I, Image3D, Rg32, i );
	Writer_StorageImage( I, ImageCube, Rg32, i );
	Writer_StorageImage( I, Image1DArray, Rg32, i );
	Writer_StorageImage( I, Image2DArray, Rg32, i );
	Writer_StorageImage( I, ImageCubeArray, Rg32, i );
	Writer_StorageImage( I, Image2DMS, Rg32, i );
	Writer_StorageImage( I, Image2DMSArray, Rg32, i );
	Writer_CombinedImage( I, ImageBuffer, Rg32, i );
	Writer_CombinedImage( I, Image1D, Rg32, i );
	Writer_CombinedImage( I, Image2D, Rg32, i );
	Writer_CombinedImage( I, Image3D, Rg32, i );
	Writer_CombinedImage( I, ImageCube, Rg32, i );
	Writer_CombinedImage( I, Image1DArray, Rg32, i );
	Writer_CombinedImage( I, Image2DArray, Rg32, i );
	Writer_CombinedImage( I, ImageCubeArray, Rg32, i );
	Writer_CombinedImage( I, Image2DMS, Rg32, i );
	Writer_CombinedImage( I, Image2DMSArray, Rg32, i );
	Writer_SampledImage( I, ImageBuffer, Rg32, i );
	Writer_SampledImage( I, Image1D, Rg32, i );
	Writer_SampledImage( I, Image2D, Rg32, i );
	Writer_SampledImage( I, Image3D, Rg32, i );
	Writer_SampledImage( I, ImageCube, Rg32, i );
	Writer_SampledImage( I, Image1DArray, Rg32, i );
	Writer_SampledImage( I, Image2DArray, Rg32, i );
	Writer_SampledImage( I, ImageCubeArray, Rg32, i );
	Writer_SampledImage( I, Image2DMS, Rg32, i );
	Writer_SampledImage( I, Image2DMSArray, Rg32, i );
	Writer_StorageImage( I, ImageBuffer, Rg16, i );
	Writer_StorageImage( I, Image1D, Rg16, i );
	Writer_StorageImage( I, Image2D, Rg16, i );
	Writer_StorageImage( I, Image3D, Rg16, i );
	Writer_StorageImage( I, ImageCube, Rg16, i );
	Writer_StorageImage( I, Image1DArray, Rg16, i );
	Writer_StorageImage( I, Image2DArray, Rg16, i );
	Writer_StorageImage( I, ImageCubeArray, Rg16, i );
	Writer_StorageImage( I, Image2DMS, Rg16, i );
	Writer_StorageImage( I, Image2DMSArray, Rg16, i );
	Writer_CombinedImage( I, ImageBuffer, Rg16, i );
	Writer_CombinedImage( I, Image1D, Rg16, i );
	Writer_CombinedImage( I, Image2D, Rg16, i );
	Writer_CombinedImage( I, Image3D, Rg16, i );
	Writer_CombinedImage( I, ImageCube, Rg16, i );
	Writer_CombinedImage( I, Image1DArray, Rg16, i );
	Writer_CombinedImage( I, Image2DArray, Rg16, i );
	Writer_CombinedImage( I, ImageCubeArray, Rg16, i );
	Writer_CombinedImage( I, Image2DMS, Rg16, i );
	Writer_CombinedImage( I, Image2DMSArray, Rg16, i );
	Writer_SampledImage( I, ImageBuffer, Rg16, i );
	Writer_SampledImage( I, Image1D, Rg16, i );
	Writer_SampledImage( I, Image2D, Rg16, i );
	Writer_SampledImage( I, Image3D, Rg16, i );
	Writer_SampledImage( I, ImageCube, Rg16, i );
	Writer_SampledImage( I, Image1DArray, Rg16, i );
	Writer_SampledImage( I, Image2DArray, Rg16, i );
	Writer_SampledImage( I, ImageCubeArray, Rg16, i );
	Writer_SampledImage( I, Image2DMS, Rg16, i );
	Writer_SampledImage( I, Image2DMSArray, Rg16, i );
	Writer_StorageImage( I, ImageBuffer, Rg8, i );
	Writer_StorageImage( I, Image1D, Rg8, i );
	Writer_StorageImage( I, Image2D, Rg8, i );
	Writer_StorageImage( I, Image3D, Rg8, i );
	Writer_StorageImage( I, ImageCube, Rg8, i );
	Writer_StorageImage( I, Image1DArray, Rg8, i );
	Writer_StorageImage( I, Image2DArray, Rg8, i );
	Writer_StorageImage( I, ImageCubeArray, Rg8, i );
	Writer_StorageImage( I, Image2DMS, Rg8, i );
	Writer_StorageImage( I, Image2DMSArray, Rg8, i );
	Writer_CombinedImage( I, ImageBuffer, Rg8, i );
	Writer_CombinedImage( I, Image1D, Rg8, i );
	Writer_CombinedImage( I, Image2D, Rg8, i );
	Writer_CombinedImage( I, Image3D, Rg8, i );
	Writer_CombinedImage( I, ImageCube, Rg8, i );
	Writer_CombinedImage( I, Image1DArray, Rg8, i );
	Writer_CombinedImage( I, Image2DArray, Rg8, i );
	Writer_CombinedImage( I, ImageCubeArray, Rg8, i );
	Writer_CombinedImage( I, Image2DMS, Rg8, i );
	Writer_CombinedImage( I, Image2DMSArray, Rg8, i );
	Writer_SampledImage( I, ImageBuffer, Rg8, i );
	Writer_SampledImage( I, Image1D, Rg8, i );
	Writer_SampledImage( I, Image2D, Rg8, i );
	Writer_SampledImage( I, Image3D, Rg8, i );
	Writer_SampledImage( I, ImageCube, Rg8, i );
	Writer_SampledImage( I, Image1DArray, Rg8, i );
	Writer_SampledImage( I, Image2DArray, Rg8, i );
	Writer_SampledImage( I, ImageCubeArray, Rg8, i );
	Writer_SampledImage( I, Image2DMS, Rg8, i );
	Writer_SampledImage( I, Image2DMSArray, Rg8, i );
	Writer_StorageImage( I, ImageBuffer, R32, i );
	Writer_StorageImage( I, Image1D, R32, i );
	Writer_StorageImage( I, Image2D, R32, i );
	Writer_StorageImage( I, Image3D, R32, i );
	Writer_StorageImage( I, ImageCube, R32, i );
	Writer_StorageImage( I, Image1DArray, R32, i );
	Writer_StorageImage( I, Image2DArray, R32, i );
	Writer_StorageImage( I, ImageCubeArray, R32, i );
	Writer_StorageImage( I, Image2DMS, R32, i );
	Writer_StorageImage( I, Image2DMSArray, R32, i );
	Writer_CombinedImage( I, ImageBuffer, R32, i );
	Writer_CombinedImage( I, Image1D, R32, i );
	Writer_CombinedImage( I, Image2D, R32, i );
	Writer_CombinedImage( I, Image3D, R32, i );
	Writer_CombinedImage( I, ImageCube, R32, i );
	Writer_CombinedImage( I, Image1DArray, R32, i );
	Writer_CombinedImage( I, Image2DArray, R32, i );
	Writer_CombinedImage( I, ImageCubeArray, R32, i );
	Writer_CombinedImage( I, Image2DMS, R32, i );
	Writer_CombinedImage( I, Image2DMSArray, R32, i );
	Writer_SampledImage( I, ImageBuffer, R32, i );
	Writer_SampledImage( I, Image1D, R32, i );
	Writer_SampledImage( I, Image2D, R32, i );
	Writer_SampledImage( I, Image3D, R32, i );
	Writer_SampledImage( I, ImageCube, R32, i );
	Writer_SampledImage( I, Image1DArray, R32, i );
	Writer_SampledImage( I, Image2DArray, R32, i );
	Writer_SampledImage( I, ImageCubeArray, R32, i );
	Writer_SampledImage( I, Image2DMS, R32, i );
	Writer_SampledImage( I, Image2DMSArray, R32, i );
	Writer_StorageImage( I, ImageBuffer, R16, i );
	Writer_StorageImage( I, Image1D, R16, i );
	Writer_StorageImage( I, Image2D, R16, i );
	Writer_StorageImage( I, Image3D, R16, i );
	Writer_StorageImage( I, ImageCube, R16, i );
	Writer_StorageImage( I, Image1DArray, R16, i );
	Writer_StorageImage( I, Image2DArray, R16, i );
	Writer_StorageImage( I, ImageCubeArray, R16, i );
	Writer_StorageImage( I, Image2DMS, R16, i );
	Writer_StorageImage( I, Image2DMSArray, R16, i );
	Writer_CombinedImage( I, ImageBuffer, R16, i );
	Writer_CombinedImage( I, Image1D, R16, i );
	Writer_CombinedImage( I, Image2D, R16, i );
	Writer_CombinedImage( I, Image3D, R16, i );
	Writer_CombinedImage( I, ImageCube, R16, i );
	Writer_CombinedImage( I, Image1DArray, R16, i );
	Writer_CombinedImage( I, Image2DArray, R16, i );
	Writer_CombinedImage( I, ImageCubeArray, R16, i );
	Writer_CombinedImage( I, Image2DMS, R16, i );
	Writer_CombinedImage( I, Image2DMSArray, R16, i );
	Writer_SampledImage( I, ImageBuffer, R16, i );
	Writer_SampledImage( I, Image1D, R16, i );
	Writer_SampledImage( I, Image2D, R16, i );
	Writer_SampledImage( I, Image3D, R16, i );
	Writer_SampledImage( I, ImageCube, R16, i );
	Writer_SampledImage( I, Image1DArray, R16, i );
	Writer_SampledImage( I, Image2DArray, R16, i );
	Writer_SampledImage( I, ImageCubeArray, R16, i );
	Writer_SampledImage( I, Image2DMS, R16, i );
	Writer_SampledImage( I, Image2DMSArray, R16, i );
	Writer_StorageImage( I, ImageBuffer, R8, i );
	Writer_StorageImage( I, Image1D, R8, i );
	Writer_StorageImage( I, Image2D, R8, i );
	Writer_StorageImage( I, Image3D, R8, i );
	Writer_StorageImage( I, ImageCube, R8, i );
	Writer_StorageImage( I, Image1DArray, R8, i );
	Writer_StorageImage( I, Image2DArray, R8, i );
	Writer_StorageImage( I, ImageCubeArray, R8, i );
	Writer_StorageImage( I, Image2DMS, R8, i );
	Writer_StorageImage( I, Image2DMSArray, R8, i );
	Writer_CombinedImage( I, ImageBuffer, R8, i );
	Writer_CombinedImage( I, Image1D, R8, i );
	Writer_CombinedImage( I, Image2D, R8, i );
	Writer_CombinedImage( I, Image3D, R8, i );
	Writer_CombinedImage( I, ImageCube, R8, i );
	Writer_CombinedImage( I, Image1DArray, R8, i );
	Writer_CombinedImage( I, Image2DArray, R8, i );
	Writer_CombinedImage( I, ImageCubeArray, R8, i );
	Writer_CombinedImage( I, Image2DMS, R8, i );
	Writer_CombinedImage( I, Image2DMSArray, R8, i );
	Writer_SampledImage( I, ImageBuffer, R8, i );
	Writer_SampledImage( I, Image1D, R8, i );
	Writer_SampledImage( I, Image2D, R8, i );
	Writer_SampledImage( I, Image3D, R8, i );
	Writer_SampledImage( I, ImageCube, R8, i );
	Writer_SampledImage( I, Image1DArray, R8, i );
	Writer_SampledImage( I, Image2DArray, R8, i );
	Writer_SampledImage( I, ImageCubeArray, R8, i );
	Writer_SampledImage( I, Image2DMS, R8, i );
	Writer_SampledImage( I, Image2DMSArray, R8, i );
	Writer_StorageImage( U, ImageBuffer, Rgba32, u );
	Writer_StorageImage( U, Image1D, Rgba32, u );
	Writer_StorageImage( U, Image2D, Rgba32, u );
	Writer_StorageImage( U, Image3D, Rgba32, u );
	Writer_StorageImage( U, ImageCube, Rgba32, u );
	Writer_StorageImage( U, Image1DArray, Rgba32, u );
	Writer_StorageImage( U, Image2DArray, Rgba32, u );
	Writer_StorageImage( U, ImageCubeArray, Rgba32, u );
	Writer_StorageImage( U, Image2DMS, Rgba32, u );
	Writer_StorageImage( U, Image2DMSArray, Rgba32, u );
	Writer_CombinedImage( U, ImageBuffer, Rgba32, u );
	Writer_CombinedImage( U, Image1D, Rgba32, u );
	Writer_CombinedImage( U, Image2D, Rgba32, u );
	Writer_CombinedImage( U, Image3D, Rgba32, u );
	Writer_CombinedImage( U, ImageCube, Rgba32, u );
	Writer_CombinedImage( U, Image1DArray, Rgba32, u );
	Writer_CombinedImage( U, Image2DArray, Rgba32, u );
	Writer_CombinedImage( U, ImageCubeArray, Rgba32, u );
	Writer_CombinedImage( U, Image2DMS, Rgba32, u );
	Writer_CombinedImage( U, Image2DMSArray, Rgba32, u );
	Writer_SampledImage( U, ImageBuffer, Rgba32, u );
	Writer_SampledImage( U, Image1D, Rgba32, u );
	Writer_SampledImage( U, Image2D, Rgba32, u );
	Writer_SampledImage( U, Image3D, Rgba32, u );
	Writer_SampledImage( U, ImageCube, Rgba32, u );
	Writer_SampledImage( U, Image1DArray, Rgba32, u );
	Writer_SampledImage( U, Image2DArray, Rgba32, u );
	Writer_SampledImage( U, ImageCubeArray, Rgba32, u );
	Writer_SampledImage( U, Image2DMS, Rgba32, u );
	Writer_SampledImage( U, Image2DMSArray, Rgba32, u );
	Writer_StorageImage( U, ImageBuffer, Rgba16, u );
	Writer_StorageImage( U, Image1D, Rgba16, u );
	Writer_StorageImage( U, Image2D, Rgba16, u );
	Writer_StorageImage( U, Image3D, Rgba16, u );
	Writer_StorageImage( U, ImageCube, Rgba16, u );
	Writer_StorageImage( U, Image1DArray, Rgba16, u );
	Writer_StorageImage( U, Image2DArray, Rgba16, u );
	Writer_StorageImage( U, ImageCubeArray, Rgba16, u );
	Writer_StorageImage( U, Image2DMS, Rgba16, u );
	Writer_StorageImage( U, Image2DMSArray, Rgba16, u );
	Writer_CombinedImage( U, ImageBuffer, Rgba16, u );
	Writer_CombinedImage( U, Image1D, Rgba16, u );
	Writer_CombinedImage( U, Image2D, Rgba16, u );
	Writer_CombinedImage( U, Image3D, Rgba16, u );
	Writer_CombinedImage( U, ImageCube, Rgba16, u );
	Writer_CombinedImage( U, Image1DArray, Rgba16, u );
	Writer_CombinedImage( U, Image2DArray, Rgba16, u );
	Writer_CombinedImage( U, ImageCubeArray, Rgba16, u );
	Writer_CombinedImage( U, Image2DMS, Rgba16, u );
	Writer_CombinedImage( U, Image2DMSArray, Rgba16, u );
	Writer_SampledImage( U, ImageBuffer, Rgba16, u );
	Writer_SampledImage( U, Image1D, Rgba16, u );
	Writer_SampledImage( U, Image2D, Rgba16, u );
	Writer_SampledImage( U, Image3D, Rgba16, u );
	Writer_SampledImage( U, ImageCube, Rgba16, u );
	Writer_SampledImage( U, Image1DArray, Rgba16, u );
	Writer_SampledImage( U, Image2DArray, Rgba16, u );
	Writer_SampledImage( U, ImageCubeArray, Rgba16, u );
	Writer_SampledImage( U, Image2DMS, Rgba16, u );
	Writer_SampledImage( U, Image2DMSArray, Rgba16, u );
	Writer_StorageImage( U, ImageBuffer, Rgba8, u );
	Writer_StorageImage( U, Image1D, Rgba8, u );
	Writer_StorageImage( U, Image2D, Rgba8, u );
	Writer_StorageImage( U, Image3D, Rgba8, u );
	Writer_StorageImage( U, ImageCube, Rgba8, u );
	Writer_StorageImage( U, Image1DArray, Rgba8, u );
	Writer_StorageImage( U, Image2DArray, Rgba8, u );
	Writer_StorageImage( U, ImageCubeArray, Rgba8, u );
	Writer_StorageImage( U, Image2DMS, Rgba8, u );
	Writer_StorageImage( U, Image2DMSArray, Rgba8, u );
	Writer_CombinedImage( U, ImageBuffer, Rgba8, u );
	Writer_CombinedImage( U, Image1D, Rgba8, u );
	Writer_CombinedImage( U, Image2D, Rgba8, u );
	Writer_CombinedImage( U, Image3D, Rgba8, u );
	Writer_CombinedImage( U, ImageCube, Rgba8, u );
	Writer_CombinedImage( U, Image1DArray, Rgba8, u );
	Writer_CombinedImage( U, Image2DArray, Rgba8, u );
	Writer_CombinedImage( U, ImageCubeArray, Rgba8, u );
	Writer_CombinedImage( U, Image2DMS, Rgba8, u );
	Writer_CombinedImage( U, Image2DMSArray, Rgba8, u );
	Writer_SampledImage( U, ImageBuffer, Rgba8, u );
	Writer_SampledImage( U, Image1D, Rgba8, u );
	Writer_SampledImage( U, Image2D, Rgba8, u );
	Writer_SampledImage( U, Image3D, Rgba8, u );
	Writer_SampledImage( U, ImageCube, Rgba8, u );
	Writer_SampledImage( U, Image1DArray, Rgba8, u );
	Writer_SampledImage( U, Image2DArray, Rgba8, u );
	Writer_SampledImage( U, ImageCubeArray, Rgba8, u );
	Writer_SampledImage( U, Image2DMS, Rgba8, u );
	Writer_SampledImage( U, Image2DMSArray, Rgba8, u );
	Writer_StorageImage( U, ImageBuffer, Rg32, u );
	Writer_StorageImage( U, Image1D, Rg32, u );
	Writer_StorageImage( U, Image2D, Rg32, u );
	Writer_StorageImage( U, Image3D, Rg32, u );
	Writer_StorageImage( U, ImageCube, Rg32, u );
	Writer_StorageImage( U, Image1DArray, Rg32, u );
	Writer_StorageImage( U, Image2DArray, Rg32, u );
	Writer_StorageImage( U, ImageCubeArray, Rg32, u );
	Writer_StorageImage( U, Image2DMS, Rg32, u );
	Writer_StorageImage( U, Image2DMSArray, Rg32, u );
	Writer_CombinedImage( U, ImageBuffer, Rg32, u );
	Writer_CombinedImage( U, Image1D, Rg32, u );
	Writer_CombinedImage( U, Image2D, Rg32, u );
	Writer_CombinedImage( U, Image3D, Rg32, u );
	Writer_CombinedImage( U, ImageCube, Rg32, u );
	Writer_CombinedImage( U, Image1DArray, Rg32, u );
	Writer_CombinedImage( U, Image2DArray, Rg32, u );
	Writer_CombinedImage( U, ImageCubeArray, Rg32, u );
	Writer_CombinedImage( U, Image2DMS, Rg32, u );
	Writer_CombinedImage( U, Image2DMSArray, Rg32, u );
	Writer_SampledImage( U, ImageBuffer, Rg32, u );
	Writer_SampledImage( U, Image1D, Rg32, u );
	Writer_SampledImage( U, Image2D, Rg32, u );
	Writer_SampledImage( U, Image3D, Rg32, u );
	Writer_SampledImage( U, ImageCube, Rg32, u );
	Writer_SampledImage( U, Image1DArray, Rg32, u );
	Writer_SampledImage( U, Image2DArray, Rg32, u );
	Writer_SampledImage( U, ImageCubeArray, Rg32, u );
	Writer_SampledImage( U, Image2DMS, Rg32, u );
	Writer_SampledImage( U, Image2DMSArray, Rg32, u );
	Writer_StorageImage( U, ImageBuffer, Rg16, u );
	Writer_StorageImage( U, Image1D, Rg16, u );
	Writer_StorageImage( U, Image2D, Rg16, u );
	Writer_StorageImage( U, Image3D, Rg16, u );
	Writer_StorageImage( U, ImageCube, Rg16, u );
	Writer_StorageImage( U, Image1DArray, Rg16, u );
	Writer_StorageImage( U, Image2DArray, Rg16, u );
	Writer_StorageImage( U, ImageCubeArray, Rg16, u );
	Writer_StorageImage( U, Image2DMS, Rg16, u );
	Writer_StorageImage( U, Image2DMSArray, Rg16, u );
	Writer_CombinedImage( U, ImageBuffer, Rg16, u );
	Writer_CombinedImage( U, Image1D, Rg16, u );
	Writer_CombinedImage( U, Image2D, Rg16, u );
	Writer_CombinedImage( U, Image3D, Rg16, u );
	Writer_CombinedImage( U, ImageCube, Rg16, u );
	Writer_CombinedImage( U, Image1DArray, Rg16, u );
	Writer_CombinedImage( U, Image2DArray, Rg16, u );
	Writer_CombinedImage( U, ImageCubeArray, Rg16, u );
	Writer_CombinedImage( U, Image2DMS, Rg16, u );
	Writer_CombinedImage( U, Image2DMSArray, Rg16, u );
	Writer_SampledImage( U, ImageBuffer, Rg16, u );
	Writer_SampledImage( U, Image1D, Rg16, u );
	Writer_SampledImage( U, Image2D, Rg16, u );
	Writer_SampledImage( U, Image3D, Rg16, u );
	Writer_SampledImage( U, ImageCube, Rg16, u );
	Writer_SampledImage( U, Image1DArray, Rg16, u );
	Writer_SampledImage( U, Image2DArray, Rg16, u );
	Writer_SampledImage( U, ImageCubeArray, Rg16, u );
	Writer_SampledImage( U, Image2DMS, Rg16, u );
	Writer_SampledImage( U, Image2DMSArray, Rg16, u );
	Writer_StorageImage( U, ImageBuffer, Rg8, u );
	Writer_StorageImage( U, Image1D, Rg8, u );
	Writer_StorageImage( U, Image2D, Rg8, u );
	Writer_StorageImage( U, Image3D, Rg8, u );
	Writer_StorageImage( U, ImageCube, Rg8, u );
	Writer_StorageImage( U, Image1DArray, Rg8, u );
	Writer_StorageImage( U, Image2DArray, Rg8, u );
	Writer_StorageImage( U, ImageCubeArray, Rg8, u );
	Writer_StorageImage( U, Image2DMS, Rg8, u );
	Writer_StorageImage( U, Image2DMSArray, Rg8, u );
	Writer_CombinedImage( U, ImageBuffer, Rg8, u );
	Writer_CombinedImage( U, Image1D, Rg8, u );
	Writer_CombinedImage( U, Image2D, Rg8, u );
	Writer_CombinedImage( U, Image3D, Rg8, u );
	Writer_CombinedImage( U, ImageCube, Rg8, u );
	Writer_CombinedImage( U, Image1DArray, Rg8, u );
	Writer_CombinedImage( U, Image2DArray, Rg8, u );
	Writer_CombinedImage( U, ImageCubeArray, Rg8, u );
	Writer_CombinedImage( U, Image2DMS, Rg8, u );
	Writer_CombinedImage( U, Image2DMSArray, Rg8, u );
	Writer_SampledImage( U, ImageBuffer, Rg8, u );
	Writer_SampledImage( U, Image1D, Rg8, u );
	Writer_SampledImage( U, Image2D, Rg8, u );
	Writer_SampledImage( U, Image3D, Rg8, u );
	Writer_SampledImage( U, ImageCube, Rg8, u );
	Writer_SampledImage( U, Image1DArray, Rg8, u );
	Writer_SampledImage( U, Image2DArray, Rg8, u );
	Writer_SampledImage( U, ImageCubeArray, Rg8, u );
	Writer_SampledImage( U, Image2DMS, Rg8, u );
	Writer_SampledImage( U, Image2DMSArray, Rg8, u );
	Writer_StorageImage( U, ImageBuffer, R32, u );
	Writer_StorageImage( U, Image1D, R32, u );
	Writer_StorageImage( U, Image2D, R32, u );
	Writer_StorageImage( U, Image3D, R32, u );
	Writer_StorageImage( U, ImageCube, R32, u );
	Writer_StorageImage( U, Image1DArray, R32, u );
	Writer_StorageImage( U, Image2DArray, R32, u );
	Writer_StorageImage( U, ImageCubeArray, R32, u );
	Writer_StorageImage( U, Image2DMS, R32, u );
	Writer_StorageImage( U, Image2DMSArray, R32, u );
	Writer_CombinedImage( U, ImageBuffer, R32, u );
	Writer_CombinedImage( U, Image1D, R32, u );
	Writer_CombinedImage( U, Image2D, R32, u );
	Writer_CombinedImage( U, Image3D, R32, u );
	Writer_CombinedImage( U, ImageCube, R32, u );
	Writer_CombinedImage( U, Image1DArray, R32, u );
	Writer_CombinedImage( U, Image2DArray, R32, u );
	Writer_CombinedImage( U, ImageCubeArray, R32, u );
	Writer_CombinedImage( U, Image2DMS, R32, u );
	Writer_CombinedImage( U, Image2DMSArray, R32, u );
	Writer_SampledImage( U, ImageBuffer, R32, u );
	Writer_SampledImage( U, Image1D, R32, u );
	Writer_SampledImage( U, Image2D, R32, u );
	Writer_SampledImage( U, Image3D, R32, u );
	Writer_SampledImage( U, ImageCube, R32, u );
	Writer_SampledImage( U, Image1DArray, R32, u );
	Writer_SampledImage( U, Image2DArray, R32, u );
	Writer_SampledImage( U, ImageCubeArray, R32, u );
	Writer_SampledImage( U, Image2DMS, R32, u );
	Writer_SampledImage( U, Image2DMSArray, R32, u );
	Writer_StorageImage( U, ImageBuffer, R16, u );
	Writer_StorageImage( U, Image1D, R16, u );
	Writer_StorageImage( U, Image2D, R16, u );
	Writer_StorageImage( U, Image3D, R16, u );
	Writer_StorageImage( U, ImageCube, R16, u );
	Writer_StorageImage( U, Image1DArray, R16, u );
	Writer_StorageImage( U, Image2DArray, R16, u );
	Writer_StorageImage( U, ImageCubeArray, R16, u );
	Writer_StorageImage( U, Image2DMS, R16, u );
	Writer_StorageImage( U, Image2DMSArray, R16, u );
	Writer_CombinedImage( U, ImageBuffer, R16, u );
	Writer_CombinedImage( U, Image1D, R16, u );
	Writer_CombinedImage( U, Image2D, R16, u );
	Writer_CombinedImage( U, Image3D, R16, u );
	Writer_CombinedImage( U, ImageCube, R16, u );
	Writer_CombinedImage( U, Image1DArray, R16, u );
	Writer_CombinedImage( U, Image2DArray, R16, u );
	Writer_CombinedImage( U, ImageCubeArray, R16, u );
	Writer_CombinedImage( U, Image2DMS, R16, u );
	Writer_CombinedImage( U, Image2DMSArray, R16, u );
	Writer_SampledImage( U, ImageBuffer, R16, u );
	Writer_SampledImage( U, Image1D, R16, u );
	Writer_SampledImage( U, Image2D, R16, u );
	Writer_SampledImage( U, Image3D, R16, u );
	Writer_SampledImage( U, ImageCube, R16, u );
	Writer_SampledImage( U, Image1DArray, R16, u );
	Writer_SampledImage( U, Image2DArray, R16, u );
	Writer_SampledImage( U, ImageCubeArray, R16, u );
	Writer_SampledImage( U, Image2DMS, R16, u );
	Writer_SampledImage( U, Image2DMSArray, R16, u );
	Writer_StorageImage( U, ImageBuffer, R8, u );
	Writer_StorageImage( U, Image1D, R8, u );
	Writer_StorageImage( U, Image2D, R8, u );
	Writer_StorageImage( U, Image3D, R8, u );
	Writer_StorageImage( U, ImageCube, R8, u );
	Writer_StorageImage( U, Image1DArray, R8, u );
	Writer_StorageImage( U, Image2DArray, R8, u );
	Writer_StorageImage( U, ImageCubeArray, R8, u );
	Writer_StorageImage( U, Image2DMS, R8, u );
	Writer_StorageImage( U, Image2DMSArray, R8, u );
	Writer_CombinedImage( U, ImageBuffer, R8, u );
	Writer_CombinedImage( U, Image1D, R8, u );
	Writer_CombinedImage( U, Image2D, R8, u );
	Writer_CombinedImage( U, Image3D, R8, u );
	Writer_CombinedImage( U, ImageCube, R8, u );
	Writer_CombinedImage( U, Image1DArray, R8, u );
	Writer_CombinedImage( U, Image2DArray, R8, u );
	Writer_CombinedImage( U, ImageCubeArray, R8, u );
	Writer_CombinedImage( U, Image2DMS, R8, u );
	Writer_CombinedImage( U, Image2DMSArray, R8, u );
	Writer_SampledImage( U, ImageBuffer, R8, u );
	Writer_SampledImage( U, Image1D, R8, u );
	Writer_SampledImage( U, Image2D, R8, u );
	Writer_SampledImage( U, Image3D, R8, u );
	Writer_SampledImage( U, ImageCube, R8, u );
	Writer_SampledImage( U, Image1DArray, R8, u );
	Writer_SampledImage( U, Image2DArray, R8, u );
	Writer_SampledImage( U, ImageCubeArray, R8, u );
	Writer_SampledImage( U, Image2DMS, R8, u );
	Writer_SampledImage( U, Image2DMSArray, R8, u );

#	undef Writer_SampledImage
#	undef Writer_CombinedImage
#	undef Writer_UniformImage
#	undef Writer_StorageImage
	/**@}*/
#pragma endregion
#pragma region Traits
	/**
	*name
	*	Traits.
	*/
	/**@{*/
	template< typename TypeT >
	struct TypeTraits;

	template< typename TypeT >
	using CppTypeT = typename TypeTraits< TypeT >::CppType;

	template< typename TypeT >
	using OperandTypeT = typename TypeTraits< TypeT >::OperandType;

	template< typename TypeT >
	using LargestT = typename TypeTraits< TypeT >::LargestType;

	template< typename TypeT >
	static ast::type::Kind constexpr typeEnumV = TypeTraits< TypeT >::TypeEnum;

	template< typename TypeT >
	using ComponentTypeT = typename TypeTraits< TypeT >::ComponentType;

	template< typename TypeT >
	struct RealTypeGetter;

	template< typename TypeT >
	using RealTypeT = typename RealTypeGetter< TypeT >::Type;

	template< typename LhsT, typename RhsT >
	static bool constexpr isSameV = std::is_same_v< LhsT, RhsT >;

	template< typename LhsT, typename RhsT >
	static bool constexpr isBaseOfV = std::is_base_of_v< LhsT, RhsT >;

	template< typename LhsT, typename RhsT >
	static bool constexpr isSameSizeV = ( TypeTraits< LhsT >::Size == TypeTraits< RhsT >::Size );

	template< typename LhsT, typename RhsT >
	static bool constexpr isSameComponentCountV = ( TypeTraits< LhsT >::ComponentCount == TypeTraits< RhsT >::ComponentCount );

	template< typename TypeT >
	static bool constexpr hasArithmeticOperators = TypeTraits< TypeT >::HasArithmeticOperators;

	template< ast::type::Kind KindT >
	struct TypeKindTraits;

	template< ast::type::Kind KindT >
	using TypeKindT = typename TypeKindTraits< KindT >::Type;

	template< typename LhsT, typename RhsT >
	struct AreCompatibleT
		: std::false_type
	{
	};

	template< typename LhsT, typename RhsT >
	static bool constexpr areCompatible = AreCompatibleT< LhsT, RhsT >::value;

	/**@}*/
#pragma endregion
#pragma region Concepts
	/**
	*name
	*	Concepts.
	*/
	/**@{*/
	template< typename TypeT >
	static constexpr bool isValueV = isSameV< Value, TypeT >
		|| isBaseOfV< Value, TypeT >;

	template< ast::type::Kind KindT >
	static bool constexpr isArithmeticV = ( KindT == ast::type::Kind::eInt8
		|| KindT == ast::type::Kind::eInt32
		|| KindT == ast::type::Kind::eUInt8
		|| KindT == ast::type::Kind::eUInt32
		|| KindT == ast::type::Kind::eUInt64
		|| KindT == ast::type::Kind::eHalf
		|| KindT == ast::type::Kind::eFloat
		|| KindT == ast::type::Kind::eDouble );

	template< ast::type::Kind KindT >
	static bool constexpr isIntegerV = ( KindT == ast::type::Kind::eInt8
		|| KindT == ast::type::Kind::eInt32
		|| KindT == ast::type::Kind::eUInt8
		|| KindT == ast::type::Kind::eUInt32
		|| KindT == ast::type::Kind::eUInt64 );

	template< typename TypeT >
	concept ArithmeticT = ( isArithmeticV< typeEnumV< OperandTypeT< TypeT > > >
		&& isSameV< ArithmeticValue< typeEnumV< OperandTypeT< TypeT > > >, OperandTypeT< TypeT > > );

	template< typename TypeT >
	concept IntegerT = ( isIntegerV< typeEnumV< OperandTypeT< TypeT > > >
		&& isSameV< IntegerValue< typeEnumV< OperandTypeT< TypeT > > >, OperandTypeT< TypeT > > );

	template< typename TypeT, typename ValueT >
	concept VecCompatibleT = ( isSameV< ValueT, OperandTypeT< TypeT > > );

	template< typename TypeT >
	concept ValueT = ( isValueV< TypeT > );
	/**@}*/
#pragma endregion

	SDW_API uint32_t getOuterArraySize( ast::type::PatchDomain domain );
	SDW_API uint32_t getInnerArraySize( ast::type::PatchDomain domain );
	SDW_API bool hasInnerLevel( ast::type::PatchDomain domain );
}

#include "ShaderWriterPrerequisites.inl"
#include "Helpers.hpp"

#endif
