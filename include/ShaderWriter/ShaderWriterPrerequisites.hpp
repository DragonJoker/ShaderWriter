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

#include <map>
#include <type_traits>
#include <vector>

#define Writer_Parameter( TypeName )\
	using P##TypeName = sdw::Param< TypeName >;\
	using In##TypeName = sdw::InParam< TypeName >;\
	using Out##TypeName = sdw::OutParam< TypeName >;\
	using InOut##TypeName = sdw::InOutParam< TypeName >

#define Writer_ArrayParameter( TypeName )\
	using P##TypeName##Array = sdw::Param< sdw::Array< TypeName > >;\
	using In##TypeName##Array = sdw::InParam< sdw::Array< TypeName > >;\
	using Out##TypeName##Array = sdw::OutParam< sdw::Array< TypeName > >;\
	using InOut##TypeName##Array = sdw::InOutParam< sdw::Array< TypeName > >

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
	using Int = IntegerValue< ast::type::Kind::eInt >;
	using UInt = IntegerValue< ast::type::Kind::eUInt >;
	using UInt64 = IntegerValue< ast::type::Kind::eUInt64 >;

	template< typename T >
	struct Array;
	template< typename TypeT >
	struct Vec2T;
	template< typename TypeT >
	struct Vec3T;
	template< typename TypeT >
	struct Vec4T;
	template< typename TypeT >
	struct Mat2T;
	template< typename TypeT >
	struct Mat2x3T;
	template< typename TypeT >
	struct Mat2x4T;
	template< typename TypeT >
	struct Mat3T;
	template< typename TypeT >
	struct Mat3x2T;
	template< typename TypeT >
	struct Mat3x4T;
	template< typename TypeT >
	struct Mat4T;
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
	using IVec2 = Vec2T< Int >;
	using IVec3 = Vec3T< Int >;
	using IVec4 = Vec4T< Int >;
	using UVec2 = Vec2T< UInt >;
	using UVec3 = Vec3T< UInt >;
	using UVec4 = Vec4T< UInt >;
	using U64Vec2 = Vec2T< UInt64 >;
	using U64Vec3 = Vec3T< UInt64 >;
	using U64Vec4 = Vec4T< UInt64 >;
	using BVec2 = Vec2T< Boolean >;
	using BVec3 = Vec3T< Boolean >;
	using BVec4 = Vec4T< Boolean >;
	using Mat2 = Mat2T< Float >;
	using Mat2x3 = Mat2x3T< Float >;
	using Mat2x4 = Mat2x4T< Float >;
	using Mat3 = Mat3T< Float >;
	using Mat3x2 = Mat3x2T< Float >;
	using Mat3x4 = Mat3x4T< Float >;
	using Mat4 = Mat4T< Float >;
	using Mat4x2 = Mat4x2T< Float >;
	using Mat4x3 = Mat4x3T< Float >;
	using DMat2 = Mat2T< Double >;
	using DMat2x3 = Mat2x3T< Double >;
	using DMat2x4 = Mat2x4T< Double >;
	using DMat3 = Mat3T< Double >;
	using DMat3x2 = Mat3x2T< Double >;
	using DMat3x4 = Mat3x4T< Double >;
	using DMat4 = Mat4T< Double >;
	using DMat4x2 = Mat4x2T< Double >;
	using DMat4x3 = Mat4x3T< Double >;
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

	class Pcb;
	class Ssbo;
	class Ubo;

	template< typename InstanceT >
	class ArraySsboT;
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
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchInT;
	template< template< ast::var::Flag FlagT > typename DataT >
	struct PatchOutT;
	template< template< ast::var::Flag FlagT > typename DataT >
	struct InputT;
	template< template< ast::var::Flag FlagT > typename DataT >
	struct OutputT;
	template< ast::var::Flag FlagT, typename ValueT >
	struct RayPayloadBaseT;
	template< ast::var::Flag FlagT, typename ValueT >
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

	using Input = InputT< VoidT >;
	using Output = OutputT< VoidT >;
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
	struct Image;
	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct ImageT;

	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using ImageBufferT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::eBuffer
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image1DT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e1D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image2DT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image3DT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e3D
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using ImageCubeT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::eCube
		, false
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image1DArrayT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e1D
		, true
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image2DArrayT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, true
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using ImageCubeArrayT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::eCube
		, true
		, false >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image2DMST = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, false
		, true >;
	template< ast::type::ImageFormat FormatT, ast::type::AccessKind AccessT >
	using Image2DMSArrayT = ImageT< FormatT
		, AccessT
		, ast::type::ImageDim::e2D
		, true
		, true >;

	template< ast::type::ImageFormat FormatT >
	using RImageBufferT = ImageBufferT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage1DT = Image1DT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DT = Image2DT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage3DT = Image3DT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImageCubeT = ImageCubeT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage1DArrayT = Image1DArrayT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DArrayT = Image2DArrayT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImageCubeArrayT = ImageCubeArrayT< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DMST = Image2DMST< FormatT, ast::type::AccessKind::eRead >;
	template< ast::type::ImageFormat FormatT >
	using RImage2DMSArrayT = Image2DMSArrayT< FormatT, ast::type::AccessKind::eRead >;

	template< ast::type::ImageFormat FormatT >
	using WImageBufferT = ImageBufferT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage1DT = Image1DT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DT = Image2DT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage3DT = Image3DT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImageCubeT = ImageCubeT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage1DArrayT = Image1DArrayT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DArrayT = Image2DArrayT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImageCubeArrayT = ImageCubeArrayT< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DMST = Image2DMST< FormatT, ast::type::AccessKind::eWrite >;
	template< ast::type::ImageFormat FormatT >
	using WImage2DMSArrayT = Image2DMSArrayT< FormatT, ast::type::AccessKind::eWrite >;

	template< ast::type::ImageFormat FormatT >
	using RWImageBufferT = ImageBufferT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage1DT = Image1DT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DT = Image2DT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage3DT = Image3DT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImageCubeT = ImageCubeT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage1DArrayT = Image1DArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DArrayT = Image2DArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImageCubeArrayT = ImageCubeArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DMST = Image2DMST< FormatT, ast::type::AccessKind::eReadWrite >;
	template< ast::type::ImageFormat FormatT >
	using RWImage2DMSArrayT = Image2DMSArrayT< FormatT, ast::type::AccessKind::eReadWrite >;
	/**@}*/
#pragma endregion
#pragma region Samplers
	/**
	*name
	*	Samplers.
	*/
	/**@{*/
	struct Sampler;
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
	struct Texture;
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct TextureT;

	template< ast::type::ImageFormat FormatT >
	using TextureBufferT = TextureT< FormatT
		, ast::type::ImageDim::eBuffer
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture1DT = TextureT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture2DT = TextureT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture3DT = TextureT< FormatT
		, ast::type::ImageDim::e3D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using TextureCubeT = TextureT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture1DArrayT = TextureT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture2DArrayT = TextureT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using TextureCubeArrayT = TextureT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture1DShadowT = TextureT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using Texture2DShadowT = TextureT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using TextureCubeShadowT = TextureT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using Texture1DArrayShadowT = TextureT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using Texture2DArrayShadowT = TextureT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using TextureCubeArrayShadowT = TextureT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using Texture2DMST = TextureT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Texture2DMSArrayT = TextureT< FormatT
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
	template< typename ValueT >
	struct ReturnWrapperT;

	Writer_Parameter( Double );
	Writer_Parameter( Float );
	Writer_Parameter( Int );
	Writer_Parameter( UInt );
	Writer_Parameter( UInt64 );
	Writer_Parameter( Boolean );
	Writer_Parameter( Vec2 );
	Writer_Parameter( Vec3 );
	Writer_Parameter( Vec4 );
	Writer_Parameter( DVec2 );
	Writer_Parameter( DVec3 );
	Writer_Parameter( DVec4 );
	Writer_Parameter( IVec2 );
	Writer_Parameter( IVec3 );
	Writer_Parameter( IVec4 );
	Writer_Parameter( UVec2 );
	Writer_Parameter( UVec3 );
	Writer_Parameter( UVec4 );
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

	Writer_ArrayParameter( Double );
	Writer_ArrayParameter( Float );
	Writer_ArrayParameter( Int );
	Writer_ArrayParameter( UInt );
	Writer_ArrayParameter( UInt64 );
	Writer_ArrayParameter( Boolean );
	Writer_ArrayParameter( Vec2 );
	Writer_ArrayParameter( Vec3 );
	Writer_ArrayParameter( Vec4 );
	Writer_ArrayParameter( DVec2 );
	Writer_ArrayParameter( DVec3 );
	Writer_ArrayParameter( DVec4 );
	Writer_ArrayParameter( IVec2 );
	Writer_ArrayParameter( IVec3 );
	Writer_ArrayParameter( IVec4 );
	Writer_ArrayParameter( UVec2 );
	Writer_ArrayParameter( UVec3 );
	Writer_ArrayParameter( UVec4 );
	Writer_ArrayParameter( BVec2 );
	Writer_ArrayParameter( BVec3 );
	Writer_ArrayParameter( BVec4 );
	Writer_ArrayParameter( Mat2 );
	Writer_ArrayParameter( Mat2x3 );
	Writer_ArrayParameter( Mat2x4 );
	Writer_ArrayParameter( Mat3 );
	Writer_ArrayParameter( Mat3x2 );
	Writer_ArrayParameter( Mat3x4 );
	Writer_ArrayParameter( Mat4 );
	Writer_ArrayParameter( Mat4x2 );
	Writer_ArrayParameter( Mat4x3 );
	Writer_ArrayParameter( DMat2 );
	Writer_ArrayParameter( DMat2x3 );
	Writer_ArrayParameter( DMat2x4 );
	Writer_ArrayParameter( DMat3 );
	Writer_ArrayParameter( DMat3x2 );
	Writer_ArrayParameter( DMat3x4 );
	Writer_ArrayParameter( DMat4 );
	Writer_ArrayParameter( DMat4x2 );
	Writer_ArrayParameter( DMat4x3 );
	/**@}*/
#pragma endregion
#pragma region Function and images related
	/**
	*name
	*	Function and images related.
	*/
	/**@{*/
#	define Writer_Image( Prefix, TypeName, Format, Postfix )\
		template< ast::type::AccessKind AccessT >\
		using Prefix##TypeName##Format##T = TypeName##T< ast::type::ImageFormat::e##Format##Postfix, AccessT >;\
		using R##Prefix##TypeName##Format = R##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( R##Prefix##TypeName##Format );\
		Writer_ArrayParameter( R##Prefix##TypeName##Format );\
		using W##Prefix##TypeName##Format = W##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( W##Prefix##TypeName##Format );\
		Writer_ArrayParameter( W##Prefix##TypeName##Format );\
		using RW##Prefix##TypeName##Format = RW##TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( RW##Prefix##TypeName##Format );\
		Writer_ArrayParameter( RW##Prefix##TypeName##Format )

#	define Writer_Texture( Prefix, TypeName, Format, Postfix )\
		using Prefix##TypeName##Format = TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
		Writer_Parameter( Prefix##TypeName##Format );\
		Writer_ArrayParameter( Prefix##TypeName##Format )

	Writer_Image( , ImageBuffer, Rgba32, f );
	Writer_Image( , Image1D, Rgba32, f );
	Writer_Image( , Image2D, Rgba32, f );
	Writer_Image( , Image3D, Rgba32, f );
	Writer_Image( , ImageCube, Rgba32, f );
	Writer_Image( , Image1DArray, Rgba32, f );
	Writer_Image( , Image2DArray, Rgba32, f );
	Writer_Image( , ImageCubeArray, Rgba32, f );
	Writer_Image( , Image2DMS, Rgba32, f );
	Writer_Image( , Image2DMSArray, Rgba32, f );
	Writer_Texture( , TextureBuffer, Rgba32, f );
	Writer_Texture( , Texture1D, Rgba32, f );
	Writer_Texture( , Texture2D, Rgba32, f );
	Writer_Texture( , Texture3D, Rgba32, f );
	Writer_Texture( , TextureCube, Rgba32, f );
	Writer_Texture( , Texture1DArray, Rgba32, f );
	Writer_Texture( , Texture2DArray, Rgba32, f );
	Writer_Texture( , TextureCubeArray, Rgba32, f );
	Writer_Texture( , Texture2DMS, Rgba32, f );
	Writer_Texture( , Texture2DMSArray, Rgba32, f );
	Writer_Image( , ImageBuffer, Rgba16, f );
	Writer_Image( , Image1D, Rgba16, f );
	Writer_Image( , Image2D, Rgba16, f );
	Writer_Image( , Image3D, Rgba16, f );
	Writer_Image( , ImageCube, Rgba16, f );
	Writer_Image( , Image1DArray, Rgba16, f );
	Writer_Image( , Image2DArray, Rgba16, f );
	Writer_Image( , ImageCubeArray, Rgba16, f );
	Writer_Image( , Image2DMS, Rgba16, f );
	Writer_Image( , Image2DMSArray, Rgba16, f );
	Writer_Texture( , TextureBuffer, Rgba16, f );
	Writer_Texture( , Texture1D, Rgba16, f );
	Writer_Texture( , Texture2D, Rgba16, f );
	Writer_Texture( , Texture3D, Rgba16, f );
	Writer_Texture( , TextureCube, Rgba16, f );
	Writer_Texture( , Texture1DArray, Rgba16, f );
	Writer_Texture( , Texture2DArray, Rgba16, f );
	Writer_Texture( , TextureCubeArray, Rgba16, f );
	Writer_Texture( , Texture2DMS, Rgba16, f );
	Writer_Texture( , Texture2DMSArray, Rgba16, f );
	Writer_Image( , ImageBuffer, Rg32, f );
	Writer_Image( , Image1D, Rg32, f );
	Writer_Image( , Image2D, Rg32, f );
	Writer_Image( , Image3D, Rg32, f );
	Writer_Image( , ImageCube, Rg32, f );
	Writer_Image( , Image1DArray, Rg32, f );
	Writer_Image( , Image2DArray, Rg32, f );
	Writer_Image( , ImageCubeArray, Rg32, f );
	Writer_Image( , Image2DMS, Rg32, f );
	Writer_Image( , Image2DMSArray, Rg32, f );
	Writer_Texture( , TextureBuffer, Rg32, f );
	Writer_Texture( , Texture1D, Rg32, f );
	Writer_Texture( , Texture2D, Rg32, f );
	Writer_Texture( , Texture3D, Rg32, f );
	Writer_Texture( , TextureCube, Rg32, f );
	Writer_Texture( , Texture1DArray, Rg32, f );
	Writer_Texture( , Texture2DArray, Rg32, f );
	Writer_Texture( , TextureCubeArray, Rg32, f );
	Writer_Texture( , Texture2DMS, Rg32, f );
	Writer_Texture( , Texture2DMSArray, Rg32, f );
	Writer_Image( , ImageBuffer, Rg16, f );
	Writer_Image( , Image1D, Rg16, f );
	Writer_Image( , Image2D, Rg16, f );
	Writer_Image( , Image3D, Rg16, f );
	Writer_Image( , ImageCube, Rg16, f );
	Writer_Image( , Image1DArray, Rg16, f );
	Writer_Image( , Image2DArray, Rg16, f );
	Writer_Image( , ImageCubeArray, Rg16, f );
	Writer_Image( , Image2DMS, Rg16, f );
	Writer_Image( , Image2DMSArray, Rg16, f );
	Writer_Texture( , TextureBuffer, Rg16, f );
	Writer_Texture( , Texture1D, Rg16, f );
	Writer_Texture( , Texture2D, Rg16, f );
	Writer_Texture( , Texture3D, Rg16, f );
	Writer_Texture( , TextureCube, Rg16, f );
	Writer_Texture( , Texture1DArray, Rg16, f );
	Writer_Texture( , Texture2DArray, Rg16, f );
	Writer_Texture( , TextureCubeArray, Rg16, f );
	Writer_Texture( , Texture2DMS, Rg16, f );
	Writer_Texture( , Texture2DMSArray, Rg16, f );
	Writer_Image( , ImageBuffer, R32, f );
	Writer_Image( , Image1D, R32, f );
	Writer_Image( , Image2D, R32, f );
	Writer_Image( , Image3D, R32, f );
	Writer_Image( , ImageCube, R32, f );
	Writer_Image( , Image1DArray, R32, f );
	Writer_Image( , Image2DArray, R32, f );
	Writer_Image( , ImageCubeArray, R32, f );
	Writer_Image( , Image2DMS, R32, f );
	Writer_Image( , Image2DMSArray, R32, f );
	Writer_Texture( , TextureBuffer, R32, f );
	Writer_Texture( , Texture1D, R32, f );
	Writer_Texture( , Texture2D, R32, f );
	Writer_Texture( , Texture3D, R32, f );
	Writer_Texture( , TextureCube, R32, f );
	Writer_Texture( , Texture1DArray, R32, f );
	Writer_Texture( , Texture2DArray, R32, f );
	Writer_Texture( , TextureCubeArray, R32, f );
	Writer_Texture( , Texture2DMS, R32, f );
	Writer_Texture( , Texture2DMSArray, R32, f );
	Writer_Image( , ImageBuffer, R16, f );
	Writer_Image( , Image1D, R16, f );
	Writer_Image( , Image2D, R16, f );
	Writer_Image( , Image3D, R16, f );
	Writer_Image( , ImageCube, R16, f );
	Writer_Image( , Image1DArray, R16, f );
	Writer_Image( , Image2DArray, R16, f );
	Writer_Image( , ImageCubeArray, R16, f );
	Writer_Image( , Image2DMS, R16, f );
	Writer_Image( , Image2DMSArray, R16, f );
	Writer_Texture( , TextureBuffer, R16, f );
	Writer_Texture( , Texture1D, R16, f );
	Writer_Texture( , Texture2D, R16, f );
	Writer_Texture( , Texture3D, R16, f );
	Writer_Texture( , TextureCube, R16, f );
	Writer_Texture( , Texture1DArray, R16, f );
	Writer_Texture( , Texture2DArray, R16, f );
	Writer_Texture( , TextureCubeArray, R16, f );
	Writer_Texture( , Texture2DMS, R16, f );
	Writer_Texture( , Texture2DMSArray, R16, f );
	Writer_Texture( , Texture1DShadow, R32, f );
	Writer_Texture( , Texture2DShadow, R32, f );
	Writer_Texture( , TextureCubeShadow, R32, f );
	Writer_Texture( , Texture1DArrayShadow, R32, f );
	Writer_Texture( , Texture2DArrayShadow, R32, f );
	Writer_Texture( , TextureCubeArrayShadow, R32, f );
	Writer_Texture( , Texture1DShadow, R16, f );
	Writer_Texture( , Texture2DShadow, R16, f );
	Writer_Texture( , TextureCubeShadow, R16, f );
	Writer_Texture( , Texture1DArrayShadow, R16, f );
	Writer_Texture( , Texture2DArrayShadow, R16, f );
	Writer_Texture( , TextureCubeArrayShadow, R16, f );
	Writer_Image( I, ImageBuffer, Rgba32, i );
	Writer_Image( I, Image1D, Rgba32, i );
	Writer_Image( I, Image2D, Rgba32, i );
	Writer_Image( I, Image3D, Rgba32, i );
	Writer_Image( I, ImageCube, Rgba32, i );
	Writer_Image( I, Image1DArray, Rgba32, i );
	Writer_Image( I, Image2DArray, Rgba32, i );
	Writer_Image( I, ImageCubeArray, Rgba32, i );
	Writer_Image( I, Image2DMS, Rgba32, i );
	Writer_Image( I, Image2DMSArray, Rgba32, i );
	Writer_Texture( I, TextureBuffer, Rgba32, i );
	Writer_Texture( I, Texture1D, Rgba32, i );
	Writer_Texture( I, Texture2D, Rgba32, i );
	Writer_Texture( I, Texture3D, Rgba32, i );
	Writer_Texture( I, TextureCube, Rgba32, i );
	Writer_Texture( I, Texture1DArray, Rgba32, i );
	Writer_Texture( I, Texture2DArray, Rgba32, i );
	Writer_Texture( I, TextureCubeArray, Rgba32, i );
	Writer_Texture( I, Texture2DMS, Rgba32, i );
	Writer_Texture( I, Texture2DMSArray, Rgba32, i );
	Writer_Image( I, ImageBuffer, Rgba16, i );
	Writer_Image( I, Image1D, Rgba16, i );
	Writer_Image( I, Image2D, Rgba16, i );
	Writer_Image( I, Image3D, Rgba16, i );
	Writer_Image( I, ImageCube, Rgba16, i );
	Writer_Image( I, Image1DArray, Rgba16, i );
	Writer_Image( I, Image2DArray, Rgba16, i );
	Writer_Image( I, ImageCubeArray, Rgba16, i );
	Writer_Image( I, Image2DMS, Rgba16, i );
	Writer_Image( I, Image2DMSArray, Rgba16, i );
	Writer_Texture( I, TextureBuffer, Rgba16, i );
	Writer_Texture( I, Texture1D, Rgba16, i );
	Writer_Texture( I, Texture2D, Rgba16, i );
	Writer_Texture( I, Texture3D, Rgba16, i );
	Writer_Texture( I, TextureCube, Rgba16, i );
	Writer_Texture( I, Texture1DArray, Rgba16, i );
	Writer_Texture( I, Texture2DArray, Rgba16, i );
	Writer_Texture( I, TextureCubeArray, Rgba16, i );
	Writer_Texture( I, Texture2DMS, Rgba16, i );
	Writer_Texture( I, Texture2DMSArray, Rgba16, i );
	Writer_Image( I, ImageBuffer, Rgba8, i );
	Writer_Image( I, Image1D, Rgba8, i );
	Writer_Image( I, Image2D, Rgba8, i );
	Writer_Image( I, Image3D, Rgba8, i );
	Writer_Image( I, ImageCube, Rgba8, i );
	Writer_Image( I, Image1DArray, Rgba8, i );
	Writer_Image( I, Image2DArray, Rgba8, i );
	Writer_Image( I, ImageCubeArray, Rgba8, i );
	Writer_Image( I, Image2DMS, Rgba8, i );
	Writer_Image( I, Image2DMSArray, Rgba8, i );
	Writer_Texture( I, TextureBuffer, Rgba8, i );
	Writer_Texture( I, Texture1D, Rgba8, i );
	Writer_Texture( I, Texture2D, Rgba8, i );
	Writer_Texture( I, Texture3D, Rgba8, i );
	Writer_Texture( I, TextureCube, Rgba8, i );
	Writer_Texture( I, Texture1DArray, Rgba8, i );
	Writer_Texture( I, Texture2DArray, Rgba8, i );
	Writer_Texture( I, TextureCubeArray, Rgba8, i );
	Writer_Texture( I, Texture2DMS, Rgba8, i );
	Writer_Texture( I, Texture2DMSArray, Rgba8, i );
	Writer_Image( I, ImageBuffer, Rg32, i );
	Writer_Image( I, Image1D, Rg32, i );
	Writer_Image( I, Image2D, Rg32, i );
	Writer_Image( I, Image3D, Rg32, i );
	Writer_Image( I, ImageCube, Rg32, i );
	Writer_Image( I, Image1DArray, Rg32, i );
	Writer_Image( I, Image2DArray, Rg32, i );
	Writer_Image( I, ImageCubeArray, Rg32, i );
	Writer_Image( I, Image2DMS, Rg32, i );
	Writer_Image( I, Image2DMSArray, Rg32, i );
	Writer_Texture( I, TextureBuffer, Rg32, i );
	Writer_Texture( I, Texture1D, Rg32, i );
	Writer_Texture( I, Texture2D, Rg32, i );
	Writer_Texture( I, Texture3D, Rg32, i );
	Writer_Texture( I, TextureCube, Rg32, i );
	Writer_Texture( I, Texture1DArray, Rg32, i );
	Writer_Texture( I, Texture2DArray, Rg32, i );
	Writer_Texture( I, TextureCubeArray, Rg32, i );
	Writer_Texture( I, Texture2DMS, Rg32, i );
	Writer_Texture( I, Texture2DMSArray, Rg32, i );
	Writer_Image( I, ImageBuffer, Rg16, i );
	Writer_Image( I, Image1D, Rg16, i );
	Writer_Image( I, Image2D, Rg16, i );
	Writer_Image( I, Image3D, Rg16, i );
	Writer_Image( I, ImageCube, Rg16, i );
	Writer_Image( I, Image1DArray, Rg16, i );
	Writer_Image( I, Image2DArray, Rg16, i );
	Writer_Image( I, ImageCubeArray, Rg16, i );
	Writer_Image( I, Image2DMS, Rg16, i );
	Writer_Image( I, Image2DMSArray, Rg16, i );
	Writer_Texture( I, TextureBuffer, Rg16, i );
	Writer_Texture( I, Texture1D, Rg16, i );
	Writer_Texture( I, Texture2D, Rg16, i );
	Writer_Texture( I, Texture3D, Rg16, i );
	Writer_Texture( I, TextureCube, Rg16, i );
	Writer_Texture( I, Texture1DArray, Rg16, i );
	Writer_Texture( I, Texture2DArray, Rg16, i );
	Writer_Texture( I, TextureCubeArray, Rg16, i );
	Writer_Texture( I, Texture2DMS, Rg16, i );
	Writer_Texture( I, Texture2DMSArray, Rg16, i );
	Writer_Image( I, ImageBuffer, Rg8, i );
	Writer_Image( I, Image1D, Rg8, i );
	Writer_Image( I, Image2D, Rg8, i );
	Writer_Image( I, Image3D, Rg8, i );
	Writer_Image( I, ImageCube, Rg8, i );
	Writer_Image( I, Image1DArray, Rg8, i );
	Writer_Image( I, Image2DArray, Rg8, i );
	Writer_Image( I, ImageCubeArray, Rg8, i );
	Writer_Image( I, Image2DMS, Rg8, i );
	Writer_Image( I, Image2DMSArray, Rg8, i );
	Writer_Texture( I, TextureBuffer, Rg8, i );
	Writer_Texture( I, Texture1D, Rg8, i );
	Writer_Texture( I, Texture2D, Rg8, i );
	Writer_Texture( I, Texture3D, Rg8, i );
	Writer_Texture( I, TextureCube, Rg8, i );
	Writer_Texture( I, Texture1DArray, Rg8, i );
	Writer_Texture( I, Texture2DArray, Rg8, i );
	Writer_Texture( I, TextureCubeArray, Rg8, i );
	Writer_Texture( I, Texture2DMS, Rg8, i );
	Writer_Texture( I, Texture2DMSArray, Rg8, i );
	Writer_Image( I, ImageBuffer, R32, i );
	Writer_Image( I, Image1D, R32, i );
	Writer_Image( I, Image2D, R32, i );
	Writer_Image( I, Image3D, R32, i );
	Writer_Image( I, ImageCube, R32, i );
	Writer_Image( I, Image1DArray, R32, i );
	Writer_Image( I, Image2DArray, R32, i );
	Writer_Image( I, ImageCubeArray, R32, i );
	Writer_Image( I, Image2DMS, R32, i );
	Writer_Image( I, Image2DMSArray, R32, i );
	Writer_Texture( I, TextureBuffer, R32, i );
	Writer_Texture( I, Texture1D, R32, i );
	Writer_Texture( I, Texture2D, R32, i );
	Writer_Texture( I, Texture3D, R32, i );
	Writer_Texture( I, TextureCube, R32, i );
	Writer_Texture( I, Texture1DArray, R32, i );
	Writer_Texture( I, Texture2DArray, R32, i );
	Writer_Texture( I, TextureCubeArray, R32, i );
	Writer_Texture( I, Texture2DMS, R32, i );
	Writer_Texture( I, Texture2DMSArray, R32, i );
	Writer_Image( I, ImageBuffer, R16, i );
	Writer_Image( I, Image1D, R16, i );
	Writer_Image( I, Image2D, R16, i );
	Writer_Image( I, Image3D, R16, i );
	Writer_Image( I, ImageCube, R16, i );
	Writer_Image( I, Image1DArray, R16, i );
	Writer_Image( I, Image2DArray, R16, i );
	Writer_Image( I, ImageCubeArray, R16, i );
	Writer_Image( I, Image2DMS, R16, i );
	Writer_Image( I, Image2DMSArray, R16, i );
	Writer_Texture( I, TextureBuffer, R16, i );
	Writer_Texture( I, Texture1D, R16, i );
	Writer_Texture( I, Texture2D, R16, i );
	Writer_Texture( I, Texture3D, R16, i );
	Writer_Texture( I, TextureCube, R16, i );
	Writer_Texture( I, Texture1DArray, R16, i );
	Writer_Texture( I, Texture2DArray, R16, i );
	Writer_Texture( I, TextureCubeArray, R16, i );
	Writer_Texture( I, Texture2DMS, R16, i );
	Writer_Texture( I, Texture2DMSArray, R16, i );
	Writer_Image( I, ImageBuffer, R8, i );
	Writer_Image( I, Image1D, R8, i );
	Writer_Image( I, Image2D, R8, i );
	Writer_Image( I, Image3D, R8, i );
	Writer_Image( I, ImageCube, R8, i );
	Writer_Image( I, Image1DArray, R8, i );
	Writer_Image( I, Image2DArray, R8, i );
	Writer_Image( I, ImageCubeArray, R8, i );
	Writer_Image( I, Image2DMS, R8, i );
	Writer_Image( I, Image2DMSArray, R8, i );
	Writer_Texture( I, TextureBuffer, R8, i );
	Writer_Texture( I, Texture1D, R8, i );
	Writer_Texture( I, Texture2D, R8, i );
	Writer_Texture( I, Texture3D, R8, i );
	Writer_Texture( I, TextureCube, R8, i );
	Writer_Texture( I, Texture1DArray, R8, i );
	Writer_Texture( I, Texture2DArray, R8, i );
	Writer_Texture( I, TextureCubeArray, R8, i );
	Writer_Texture( I, Texture2DMS, R8, i );
	Writer_Texture( I, Texture2DMSArray, R8, i );
	Writer_Image( U, ImageBuffer, Rgba32, u );
	Writer_Image( U, Image1D, Rgba32, u );
	Writer_Image( U, Image2D, Rgba32, u );
	Writer_Image( U, Image3D, Rgba32, u );
	Writer_Image( U, ImageCube, Rgba32, u );
	Writer_Image( U, Image1DArray, Rgba32, u );
	Writer_Image( U, Image2DArray, Rgba32, u );
	Writer_Image( U, ImageCubeArray, Rgba32, u );
	Writer_Image( U, Image2DMS, Rgba32, u );
	Writer_Image( U, Image2DMSArray, Rgba32, u );
	Writer_Texture( U, TextureBuffer, Rgba32, u );
	Writer_Texture( U, Texture1D, Rgba32, u );
	Writer_Texture( U, Texture2D, Rgba32, u );
	Writer_Texture( U, Texture3D, Rgba32, u );
	Writer_Texture( U, TextureCube, Rgba32, u );
	Writer_Texture( U, Texture1DArray, Rgba32, u );
	Writer_Texture( U, Texture2DArray, Rgba32, u );
	Writer_Texture( U, TextureCubeArray, Rgba32, u );
	Writer_Texture( U, Texture2DMS, Rgba32, u );
	Writer_Texture( U, Texture2DMSArray, Rgba32, u );
	Writer_Image( U, ImageBuffer, Rgba16, u );
	Writer_Image( U, Image1D, Rgba16, u );
	Writer_Image( U, Image2D, Rgba16, u );
	Writer_Image( U, Image3D, Rgba16, u );
	Writer_Image( U, ImageCube, Rgba16, u );
	Writer_Image( U, Image1DArray, Rgba16, u );
	Writer_Image( U, Image2DArray, Rgba16, u );
	Writer_Image( U, ImageCubeArray, Rgba16, u );
	Writer_Image( U, Image2DMS, Rgba16, u );
	Writer_Image( U, Image2DMSArray, Rgba16, u );
	Writer_Texture( U, TextureBuffer, Rgba16, u );
	Writer_Texture( U, Texture1D, Rgba16, u );
	Writer_Texture( U, Texture2D, Rgba16, u );
	Writer_Texture( U, Texture3D, Rgba16, u );
	Writer_Texture( U, TextureCube, Rgba16, u );
	Writer_Texture( U, Texture1DArray, Rgba16, u );
	Writer_Texture( U, Texture2DArray, Rgba16, u );
	Writer_Texture( U, TextureCubeArray, Rgba16, u );
	Writer_Texture( U, Texture2DMS, Rgba16, u );
	Writer_Texture( U, Texture2DMSArray, Rgba16, u );
	Writer_Image( U, ImageBuffer, Rgba8, u );
	Writer_Image( U, Image1D, Rgba8, u );
	Writer_Image( U, Image2D, Rgba8, u );
	Writer_Image( U, Image3D, Rgba8, u );
	Writer_Image( U, ImageCube, Rgba8, u );
	Writer_Image( U, Image1DArray, Rgba8, u );
	Writer_Image( U, Image2DArray, Rgba8, u );
	Writer_Image( U, ImageCubeArray, Rgba8, u );
	Writer_Image( U, Image2DMS, Rgba8, u );
	Writer_Image( U, Image2DMSArray, Rgba8, u );
	Writer_Texture( U, TextureBuffer, Rgba8, u );
	Writer_Texture( U, Texture1D, Rgba8, u );
	Writer_Texture( U, Texture2D, Rgba8, u );
	Writer_Texture( U, Texture3D, Rgba8, u );
	Writer_Texture( U, TextureCube, Rgba8, u );
	Writer_Texture( U, Texture1DArray, Rgba8, u );
	Writer_Texture( U, Texture2DArray, Rgba8, u );
	Writer_Texture( U, TextureCubeArray, Rgba8, u );
	Writer_Texture( U, Texture2DMS, Rgba8, u );
	Writer_Texture( U, Texture2DMSArray, Rgba8, u );
	Writer_Image( U, ImageBuffer, Rg32, u );
	Writer_Image( U, Image1D, Rg32, u );
	Writer_Image( U, Image2D, Rg32, u );
	Writer_Image( U, Image3D, Rg32, u );
	Writer_Image( U, ImageCube, Rg32, u );
	Writer_Image( U, Image1DArray, Rg32, u );
	Writer_Image( U, Image2DArray, Rg32, u );
	Writer_Image( U, ImageCubeArray, Rg32, u );
	Writer_Image( U, Image2DMS, Rg32, u );
	Writer_Image( U, Image2DMSArray, Rg32, u );
	Writer_Texture( U, TextureBuffer, Rg32, u );
	Writer_Texture( U, Texture1D, Rg32, u );
	Writer_Texture( U, Texture2D, Rg32, u );
	Writer_Texture( U, Texture3D, Rg32, u );
	Writer_Texture( U, TextureCube, Rg32, u );
	Writer_Texture( U, Texture1DArray, Rg32, u );
	Writer_Texture( U, Texture2DArray, Rg32, u );
	Writer_Texture( U, TextureCubeArray, Rg32, u );
	Writer_Texture( U, Texture2DMS, Rg32, u );
	Writer_Texture( U, Texture2DMSArray, Rg32, u );
	Writer_Image( U, ImageBuffer, Rg16, u );
	Writer_Image( U, Image1D, Rg16, u );
	Writer_Image( U, Image2D, Rg16, u );
	Writer_Image( U, Image3D, Rg16, u );
	Writer_Image( U, ImageCube, Rg16, u );
	Writer_Image( U, Image1DArray, Rg16, u );
	Writer_Image( U, Image2DArray, Rg16, u );
	Writer_Image( U, ImageCubeArray, Rg16, u );
	Writer_Image( U, Image2DMS, Rg16, u );
	Writer_Image( U, Image2DMSArray, Rg16, u );
	Writer_Texture( U, TextureBuffer, Rg16, u );
	Writer_Texture( U, Texture1D, Rg16, u );
	Writer_Texture( U, Texture2D, Rg16, u );
	Writer_Texture( U, Texture3D, Rg16, u );
	Writer_Texture( U, TextureCube, Rg16, u );
	Writer_Texture( U, Texture1DArray, Rg16, u );
	Writer_Texture( U, Texture2DArray, Rg16, u );
	Writer_Texture( U, TextureCubeArray, Rg16, u );
	Writer_Texture( U, Texture2DMS, Rg16, u );
	Writer_Texture( U, Texture2DMSArray, Rg16, u );
	Writer_Image( U, ImageBuffer, Rg8, u );
	Writer_Image( U, Image1D, Rg8, u );
	Writer_Image( U, Image2D, Rg8, u );
	Writer_Image( U, Image3D, Rg8, u );
	Writer_Image( U, ImageCube, Rg8, u );
	Writer_Image( U, Image1DArray, Rg8, u );
	Writer_Image( U, Image2DArray, Rg8, u );
	Writer_Image( U, ImageCubeArray, Rg8, u );
	Writer_Image( U, Image2DMS, Rg8, u );
	Writer_Image( U, Image2DMSArray, Rg8, u );
	Writer_Texture( U, TextureBuffer, Rg8, u );
	Writer_Texture( U, Texture1D, Rg8, u );
	Writer_Texture( U, Texture2D, Rg8, u );
	Writer_Texture( U, Texture3D, Rg8, u );
	Writer_Texture( U, TextureCube, Rg8, u );
	Writer_Texture( U, Texture1DArray, Rg8, u );
	Writer_Texture( U, Texture2DArray, Rg8, u );
	Writer_Texture( U, TextureCubeArray, Rg8, u );
	Writer_Texture( U, Texture2DMS, Rg8, u );
	Writer_Texture( U, Texture2DMSArray, Rg8, u );
	Writer_Image( U, ImageBuffer, R32, u );
	Writer_Image( U, Image1D, R32, u );
	Writer_Image( U, Image2D, R32, u );
	Writer_Image( U, Image3D, R32, u );
	Writer_Image( U, ImageCube, R32, u );
	Writer_Image( U, Image1DArray, R32, u );
	Writer_Image( U, Image2DArray, R32, u );
	Writer_Image( U, ImageCubeArray, R32, u );
	Writer_Image( U, Image2DMS, R32, u );
	Writer_Image( U, Image2DMSArray, R32, u );
	Writer_Texture( U, TextureBuffer, R32, u );
	Writer_Texture( U, Texture1D, R32, u );
	Writer_Texture( U, Texture2D, R32, u );
	Writer_Texture( U, Texture3D, R32, u );
	Writer_Texture( U, TextureCube, R32, u );
	Writer_Texture( U, Texture1DArray, R32, u );
	Writer_Texture( U, Texture2DArray, R32, u );
	Writer_Texture( U, TextureCubeArray, R32, u );
	Writer_Texture( U, Texture2DMS, R32, u );
	Writer_Texture( U, Texture2DMSArray, R32, u );
	Writer_Image( U, ImageBuffer, R16, u );
	Writer_Image( U, Image1D, R16, u );
	Writer_Image( U, Image2D, R16, u );
	Writer_Image( U, Image3D, R16, u );
	Writer_Image( U, ImageCube, R16, u );
	Writer_Image( U, Image1DArray, R16, u );
	Writer_Image( U, Image2DArray, R16, u );
	Writer_Image( U, ImageCubeArray, R16, u );
	Writer_Image( U, Image2DMS, R16, u );
	Writer_Image( U, Image2DMSArray, R16, u );
	Writer_Texture( U, TextureBuffer, R16, u );
	Writer_Texture( U, Texture1D, R16, u );
	Writer_Texture( U, Texture2D, R16, u );
	Writer_Texture( U, Texture3D, R16, u );
	Writer_Texture( U, TextureCube, R16, u );
	Writer_Texture( U, Texture1DArray, R16, u );
	Writer_Texture( U, Texture2DArray, R16, u );
	Writer_Texture( U, TextureCubeArray, R16, u );
	Writer_Texture( U, Texture2DMS, R16, u );
	Writer_Texture( U, Texture2DMSArray, R16, u );
	Writer_Image( U, ImageBuffer, R8, u );
	Writer_Image( U, Image1D, R8, u );
	Writer_Image( U, Image2D, R8, u );
	Writer_Image( U, Image3D, R8, u );
	Writer_Image( U, ImageCube, R8, u );
	Writer_Image( U, Image1DArray, R8, u );
	Writer_Image( U, Image2DArray, R8, u );
	Writer_Image( U, ImageCubeArray, R8, u );
	Writer_Image( U, Image2DMS, R8, u );
	Writer_Image( U, Image2DMSArray, R8, u );
	Writer_Texture( U, TextureBuffer, R8, u );
	Writer_Texture( U, Texture1D, R8, u );
	Writer_Texture( U, Texture2D, R8, u );
	Writer_Texture( U, Texture3D, R8, u );
	Writer_Texture( U, TextureCube, R8, u );
	Writer_Texture( U, Texture1DArray, R8, u );
	Writer_Texture( U, Texture2DArray, R8, u );
	Writer_Texture( U, TextureCubeArray, R8, u );
	Writer_Texture( U, Texture2DMS, R8, u );
	Writer_Texture( U, Texture2DMSArray, R8, u );

#	undef Writer_Texture
#	undef Writer_Image
	/**@}*/
#pragma endregion
#pragma region Traits
	/**
	*name
	*	Traits.
	*/
	/**@{*/
	template< typename T >
	struct TypeTraits;

	template< typename T >
	using CppTypeT = typename TypeTraits< T >::CppType;

	template< typename T >
	static ast::type::Kind constexpr typeEnum = TypeTraits< T >::TypeEnum;

	template< typename T >
	struct RealTypeGetter;

	template< typename T >
	using RealTypeT = typename RealTypeGetter< T >::Type;

	template< typename T, typename U >
	static bool constexpr IsSameV = std::is_same< T, U >::value;

	template< typename T, typename U >
	static bool constexpr IsSameSizeV = ( TypeTraits< T >::Size == TypeTraits< U >::Size );

	template< typename T, typename U >
	static bool constexpr isSameComponentCountV = ( TypeTraits< T >::ComponentCount == TypeTraits< U >::ComponentCount );

	template< typename T >
	static bool constexpr hasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;

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

	SDW_API uint32_t getOuterArraySize( ast::type::PatchDomain domain );
	SDW_API uint32_t getInnerArraySize( ast::type::PatchDomain domain );
	SDW_API bool hasInnerLevel( ast::type::PatchDomain domain );
}

#include "ShaderWriterPrerequisites.inl"
#include "Helpers.hpp"

#endif
