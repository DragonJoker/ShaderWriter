/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Prerequisites_H___
#define ___SDW_Prerequisites_H___

#include <map>

#include <ShaderAST/Type/Type.hpp>
#include <ShaderAST/Type/TypeArray.hpp>
#include <ShaderAST/Type/TypeCache.hpp>
#include <ShaderAST/Type/ImageConfiguration.hpp>

#define Writer_Parameter( TypeName )\
	using In##TypeName = sdw::InParam< TypeName >;\
	using Out##TypeName = sdw::OutParam< TypeName >;\
	using InOut##TypeName = sdw::InOutParam< TypeName >

#define Writer_ArrayParameter( TypeName )\
	using In##TypeName##Array = sdw::InParam< sdw::Array< TypeName > >;\
	using Out##TypeName##Array = sdw::OutParam< sdw::Array< TypeName > >;\
	using InOut##TypeName##Array = sdw::InOutParam< sdw::Array< TypeName > >

#define Writer_Image( Prefix, TypeName, Format, Postfix )\
	using Prefix##TypeName##Format = TypeName##T< ast::type::ImageFormat::e##Format##Postfix >;\
	Writer_Parameter( Prefix##TypeName##Format );\
	Writer_ArrayParameter( Prefix##TypeName##Format )

namespace sdw
{
	class Shader;
	class ShaderWriter;

	enum class ShaderType
	{
		eVertex,
		eTessellationControl,
		eTessellationEvaluation,
		eGeometry,
		eCompute,
		eFragment,
	};

	template< typename T >
	struct Array;
	template< typename TypeT >
	struct InParam;
	template< typename TypeT >
	struct OutParam;
	template< typename TypeT >
	struct InOutParam;
	template< typename TypeT >
	struct Optional;
	template< typename TypeT >
	struct MaybeOptional;
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
	struct Image;
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageT;
	struct Sampler;
	struct SampledImage;
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct SampledImageT;
	template< typename InstanceT >
	class ArraySsboT;

	struct Value;
	struct Void;
	struct Bool;

	template< ast::type::Kind KindT >
	struct ArithmeticValue;
	template< ast::type::Kind KindT >
	struct IntegerValue;

	using Float = ArithmeticValue< ast::type::Kind::eFloat >;
	using Double = ArithmeticValue< ast::type::Kind::eDouble >;
	using Int = IntegerValue< ast::type::Kind::eInt >;
	using UInt = IntegerValue< ast::type::Kind::eUInt >;

	class Struct;
	class StructInstance;

	using Vec2 = Vec2T< Float >;
	using Vec3 = Vec3T< Float >;
	using Vec4 = Vec4T< Float >;
	using DVec2 = Vec2T< Double >;
	using DVec3 = Vec3T< Double >;
	using DVec4 = Vec4T< Double >;
	using IVec2 = Vec2T< Int >;
	using IVec3 = Vec3T< Int >;
	using IVec4 = Vec4T< Int >;
	using UVec2 = Vec2T< UInt >;
	using UVec3 = Vec3T< UInt >;
	using UVec4 = Vec4T< UInt >;
	using BVec2 = Vec2T< Bool >;
	using BVec3 = Vec3T< Bool >;
	using BVec4 = Vec4T< Bool >;
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

	using StructuredSsbo = ArraySsboT< StructInstance >;

	template< ast::type::ImageFormat FormatT >
	using ImageBufferT = ImageT< FormatT
		, ast::type::ImageDim::eBuffer
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image1DT = ImageT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DT = ImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image3DT = ImageT< FormatT
		, ast::type::ImageDim::e3D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using ImageCubeT = ImageT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image1DArrayT = ImageT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DArrayT = ImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using ImageCubeArrayT = ImageT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DMST = ImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using Image2DMSArrayT = ImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, true >;

	template< ast::type::ImageFormat FormatT >
	using SampledImageBufferT = SampledImageT< FormatT
		, ast::type::ImageDim::eBuffer
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DT = SampledImageT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage3DT = SampledImageT< FormatT
		, ast::type::ImageDim::e3D
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeT = SampledImageT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DShadowT = SampledImageT< FormatT
		, ast::type::ImageDim::e1D
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DShadowT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeShadowT = SampledImageT< FormatT
		, ast::type::ImageDim::eCube
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DArrayShadowT = SampledImageT< FormatT
		, ast::type::ImageDim::e1D
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DArrayShadowT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeArrayShadowT = SampledImageT< FormatT
		, ast::type::ImageDim::eCube
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DMST = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DMSArrayT = SampledImageT< FormatT
		, ast::type::ImageDim::e2D
		, true
		, false
		, true >;

	template< typename RetT, typename ... ParamsT >
	struct Function;
	template< typename TypeT >
	struct InParam;
	template< typename TypeT >
	struct OutParam;
	template< typename TypeT >
	struct InOutParam;

	Writer_Parameter( Double );
	Writer_Parameter( Float );
	Writer_Parameter( Int );
	Writer_Parameter( UInt );
	Writer_Parameter( Bool );
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
	Writer_ArrayParameter( Bool );
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
	Writer_Image( , SampledImageBuffer, Rgba32, f );
	Writer_Image( , SampledImage1D, Rgba32, f );
	Writer_Image( , SampledImage2D, Rgba32, f );
	Writer_Image( , SampledImage3D, Rgba32, f );
	Writer_Image( , SampledImageCube, Rgba32, f );
	Writer_Image( , SampledImage1DArray, Rgba32, f );
	Writer_Image( , SampledImage2DArray, Rgba32, f );
	Writer_Image( , SampledImageCubeArray, Rgba32, f );
	Writer_Image( , SampledImage2DMS, Rgba32, f );
	Writer_Image( , SampledImage2DMSArray, Rgba32, f );
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
	Writer_Image( , SampledImageBuffer, Rgba16, f );
	Writer_Image( , SampledImage1D, Rgba16, f );
	Writer_Image( , SampledImage2D, Rgba16, f );
	Writer_Image( , SampledImage3D, Rgba16, f );
	Writer_Image( , SampledImageCube, Rgba16, f );
	Writer_Image( , SampledImage1DArray, Rgba16, f );
	Writer_Image( , SampledImage2DArray, Rgba16, f );
	Writer_Image( , SampledImageCubeArray, Rgba16, f );
	Writer_Image( , SampledImage2DMS, Rgba16, f );
	Writer_Image( , SampledImage2DMSArray, Rgba16, f );
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
	Writer_Image( , SampledImageBuffer, Rg32, f );
	Writer_Image( , SampledImage1D, Rg32, f );
	Writer_Image( , SampledImage2D, Rg32, f );
	Writer_Image( , SampledImage3D, Rg32, f );
	Writer_Image( , SampledImageCube, Rg32, f );
	Writer_Image( , SampledImage1DArray, Rg32, f );
	Writer_Image( , SampledImage2DArray, Rg32, f );
	Writer_Image( , SampledImageCubeArray, Rg32, f );
	Writer_Image( , SampledImage2DMS, Rg32, f );
	Writer_Image( , SampledImage2DMSArray, Rg32, f );
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
	Writer_Image( , SampledImageBuffer, Rg16, f );
	Writer_Image( , SampledImage1D, Rg16, f );
	Writer_Image( , SampledImage2D, Rg16, f );
	Writer_Image( , SampledImage3D, Rg16, f );
	Writer_Image( , SampledImageCube, Rg16, f );
	Writer_Image( , SampledImage1DArray, Rg16, f );
	Writer_Image( , SampledImage2DArray, Rg16, f );
	Writer_Image( , SampledImageCubeArray, Rg16, f );
	Writer_Image( , SampledImage2DMS, Rg16, f );
	Writer_Image( , SampledImage2DMSArray, Rg16, f );
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
	Writer_Image( , SampledImageBuffer, R32, f );
	Writer_Image( , SampledImage1D, R32, f );
	Writer_Image( , SampledImage2D, R32, f );
	Writer_Image( , SampledImage3D, R32, f );
	Writer_Image( , SampledImageCube, R32, f );
	Writer_Image( , SampledImage1DArray, R32, f );
	Writer_Image( , SampledImage2DArray, R32, f );
	Writer_Image( , SampledImageCubeArray, R32, f );
	Writer_Image( , SampledImage2DMS, R32, f );
	Writer_Image( , SampledImage2DMSArray, R32, f );
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
	Writer_Image( , SampledImageBuffer, R16, f );
	Writer_Image( , SampledImage1D, R16, f );
	Writer_Image( , SampledImage2D, R16, f );
	Writer_Image( , SampledImage3D, R16, f );
	Writer_Image( , SampledImageCube, R16, f );
	Writer_Image( , SampledImage1DArray, R16, f );
	Writer_Image( , SampledImage2DArray, R16, f );
	Writer_Image( , SampledImageCubeArray, R16, f );
	Writer_Image( , SampledImage2DMS, R16, f );
	Writer_Image( , SampledImage2DMSArray, R16, f );
	Writer_Image( , SampledImage1DShadow, R32, f );
	Writer_Image( , SampledImage2DShadow, R32, f );
	Writer_Image( , SampledImageCubeShadow, R32, f );
	Writer_Image( , SampledImage1DArrayShadow, R32, f );
	Writer_Image( , SampledImage2DArrayShadow, R32, f );
	Writer_Image( , SampledImageCubeArrayShadow, R32, f );
	Writer_Image( , SampledImage1DShadow, R16, f );
	Writer_Image( , SampledImage2DShadow, R16, f );
	Writer_Image( , SampledImageCubeShadow, R16, f );
	Writer_Image( , SampledImage1DArrayShadow, R16, f );
	Writer_Image( , SampledImage2DArrayShadow, R16, f );
	Writer_Image( , SampledImageCubeArrayShadow, R16, f );
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
	Writer_Image( I, SampledImageBuffer, Rgba32, i );
	Writer_Image( I, SampledImage1D, Rgba32, i );
	Writer_Image( I, SampledImage2D, Rgba32, i );
	Writer_Image( I, SampledImage3D, Rgba32, i );
	Writer_Image( I, SampledImageCube, Rgba32, i );
	Writer_Image( I, SampledImage1DArray, Rgba32, i );
	Writer_Image( I, SampledImage2DArray, Rgba32, i );
	Writer_Image( I, SampledImageCubeArray, Rgba32, i );
	Writer_Image( I, SampledImage2DMS, Rgba32, i );
	Writer_Image( I, SampledImage2DMSArray, Rgba32, i );
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
	Writer_Image( I, SampledImageBuffer, Rgba16, i );
	Writer_Image( I, SampledImage1D, Rgba16, i );
	Writer_Image( I, SampledImage2D, Rgba16, i );
	Writer_Image( I, SampledImage3D, Rgba16, i );
	Writer_Image( I, SampledImageCube, Rgba16, i );
	Writer_Image( I, SampledImage1DArray, Rgba16, i );
	Writer_Image( I, SampledImage2DArray, Rgba16, i );
	Writer_Image( I, SampledImageCubeArray, Rgba16, i );
	Writer_Image( I, SampledImage2DMS, Rgba16, i );
	Writer_Image( I, SampledImage2DMSArray, Rgba16, i );
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
	Writer_Image( I, SampledImageBuffer, Rgba8, i );
	Writer_Image( I, SampledImage1D, Rgba8, i );
	Writer_Image( I, SampledImage2D, Rgba8, i );
	Writer_Image( I, SampledImage3D, Rgba8, i );
	Writer_Image( I, SampledImageCube, Rgba8, i );
	Writer_Image( I, SampledImage1DArray, Rgba8, i );
	Writer_Image( I, SampledImage2DArray, Rgba8, i );
	Writer_Image( I, SampledImageCubeArray, Rgba8, i );
	Writer_Image( I, SampledImage2DMS, Rgba8, i );
	Writer_Image( I, SampledImage2DMSArray, Rgba8, i );
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
	Writer_Image( I, SampledImageBuffer, Rg32, i );
	Writer_Image( I, SampledImage1D, Rg32, i );
	Writer_Image( I, SampledImage2D, Rg32, i );
	Writer_Image( I, SampledImage3D, Rg32, i );
	Writer_Image( I, SampledImageCube, Rg32, i );
	Writer_Image( I, SampledImage1DArray, Rg32, i );
	Writer_Image( I, SampledImage2DArray, Rg32, i );
	Writer_Image( I, SampledImageCubeArray, Rg32, i );
	Writer_Image( I, SampledImage2DMS, Rg32, i );
	Writer_Image( I, SampledImage2DMSArray, Rg32, i );
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
	Writer_Image( I, SampledImageBuffer, Rg16, i );
	Writer_Image( I, SampledImage1D, Rg16, i );
	Writer_Image( I, SampledImage2D, Rg16, i );
	Writer_Image( I, SampledImage3D, Rg16, i );
	Writer_Image( I, SampledImageCube, Rg16, i );
	Writer_Image( I, SampledImage1DArray, Rg16, i );
	Writer_Image( I, SampledImage2DArray, Rg16, i );
	Writer_Image( I, SampledImageCubeArray, Rg16, i );
	Writer_Image( I, SampledImage2DMS, Rg16, i );
	Writer_Image( I, SampledImage2DMSArray, Rg16, i );
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
	Writer_Image( I, SampledImageBuffer, Rg8, i );
	Writer_Image( I, SampledImage1D, Rg8, i );
	Writer_Image( I, SampledImage2D, Rg8, i );
	Writer_Image( I, SampledImage3D, Rg8, i );
	Writer_Image( I, SampledImageCube, Rg8, i );
	Writer_Image( I, SampledImage1DArray, Rg8, i );
	Writer_Image( I, SampledImage2DArray, Rg8, i );
	Writer_Image( I, SampledImageCubeArray, Rg8, i );
	Writer_Image( I, SampledImage2DMS, Rg8, i );
	Writer_Image( I, SampledImage2DMSArray, Rg8, i );
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
	Writer_Image( I, SampledImageBuffer, R32, i );
	Writer_Image( I, SampledImage1D, R32, i );
	Writer_Image( I, SampledImage2D, R32, i );
	Writer_Image( I, SampledImage3D, R32, i );
	Writer_Image( I, SampledImageCube, R32, i );
	Writer_Image( I, SampledImage1DArray, R32, i );
	Writer_Image( I, SampledImage2DArray, R32, i );
	Writer_Image( I, SampledImageCubeArray, R32, i );
	Writer_Image( I, SampledImage2DMS, R32, i );
	Writer_Image( I, SampledImage2DMSArray, R32, i );
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
	Writer_Image( I, SampledImageBuffer, R16, i );
	Writer_Image( I, SampledImage1D, R16, i );
	Writer_Image( I, SampledImage2D, R16, i );
	Writer_Image( I, SampledImage3D, R16, i );
	Writer_Image( I, SampledImageCube, R16, i );
	Writer_Image( I, SampledImage1DArray, R16, i );
	Writer_Image( I, SampledImage2DArray, R16, i );
	Writer_Image( I, SampledImageCubeArray, R16, i );
	Writer_Image( I, SampledImage2DMS, R16, i );
	Writer_Image( I, SampledImage2DMSArray, R16, i );
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
	Writer_Image( I, SampledImageBuffer, R8, i );
	Writer_Image( I, SampledImage1D, R8, i );
	Writer_Image( I, SampledImage2D, R8, i );
	Writer_Image( I, SampledImage3D, R8, i );
	Writer_Image( I, SampledImageCube, R8, i );
	Writer_Image( I, SampledImage1DArray, R8, i );
	Writer_Image( I, SampledImage2DArray, R8, i );
	Writer_Image( I, SampledImageCubeArray, R8, i );
	Writer_Image( I, SampledImage2DMS, R8, i );
	Writer_Image( I, SampledImage2DMSArray, R8, i );
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
	Writer_Image( U, SampledImageBuffer, Rgba32, u );
	Writer_Image( U, SampledImage1D, Rgba32, u );
	Writer_Image( U, SampledImage2D, Rgba32, u );
	Writer_Image( U, SampledImage3D, Rgba32, u );
	Writer_Image( U, SampledImageCube, Rgba32, u );
	Writer_Image( U, SampledImage1DArray, Rgba32, u );
	Writer_Image( U, SampledImage2DArray, Rgba32, u );
	Writer_Image( U, SampledImageCubeArray, Rgba32, u );
	Writer_Image( U, SampledImage2DMS, Rgba32, u );
	Writer_Image( U, SampledImage2DMSArray, Rgba32, u );
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
	Writer_Image( U, SampledImageBuffer, Rgba16, u );
	Writer_Image( U, SampledImage1D, Rgba16, u );
	Writer_Image( U, SampledImage2D, Rgba16, u );
	Writer_Image( U, SampledImage3D, Rgba16, u );
	Writer_Image( U, SampledImageCube, Rgba16, u );
	Writer_Image( U, SampledImage1DArray, Rgba16, u );
	Writer_Image( U, SampledImage2DArray, Rgba16, u );
	Writer_Image( U, SampledImageCubeArray, Rgba16, u );
	Writer_Image( U, SampledImage2DMS, Rgba16, u );
	Writer_Image( U, SampledImage2DMSArray, Rgba16, u );
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
	Writer_Image( U, SampledImageBuffer, Rgba8, u );
	Writer_Image( U, SampledImage1D, Rgba8, u );
	Writer_Image( U, SampledImage2D, Rgba8, u );
	Writer_Image( U, SampledImage3D, Rgba8, u );
	Writer_Image( U, SampledImageCube, Rgba8, u );
	Writer_Image( U, SampledImage1DArray, Rgba8, u );
	Writer_Image( U, SampledImage2DArray, Rgba8, u );
	Writer_Image( U, SampledImageCubeArray, Rgba8, u );
	Writer_Image( U, SampledImage2DMS, Rgba8, u );
	Writer_Image( U, SampledImage2DMSArray, Rgba8, u );
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
	Writer_Image( U, SampledImageBuffer, Rg32, u );
	Writer_Image( U, SampledImage1D, Rg32, u );
	Writer_Image( U, SampledImage2D, Rg32, u );
	Writer_Image( U, SampledImage3D, Rg32, u );
	Writer_Image( U, SampledImageCube, Rg32, u );
	Writer_Image( U, SampledImage1DArray, Rg32, u );
	Writer_Image( U, SampledImage2DArray, Rg32, u );
	Writer_Image( U, SampledImageCubeArray, Rg32, u );
	Writer_Image( U, SampledImage2DMS, Rg32, u );
	Writer_Image( U, SampledImage2DMSArray, Rg32, u );
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
	Writer_Image( U, SampledImageBuffer, Rg16, u );
	Writer_Image( U, SampledImage1D, Rg16, u );
	Writer_Image( U, SampledImage2D, Rg16, u );
	Writer_Image( U, SampledImage3D, Rg16, u );
	Writer_Image( U, SampledImageCube, Rg16, u );
	Writer_Image( U, SampledImage1DArray, Rg16, u );
	Writer_Image( U, SampledImage2DArray, Rg16, u );
	Writer_Image( U, SampledImageCubeArray, Rg16, u );
	Writer_Image( U, SampledImage2DMS, Rg16, u );
	Writer_Image( U, SampledImage2DMSArray, Rg16, u );
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
	Writer_Image( U, SampledImageBuffer, Rg8, u );
	Writer_Image( U, SampledImage1D, Rg8, u );
	Writer_Image( U, SampledImage2D, Rg8, u );
	Writer_Image( U, SampledImage3D, Rg8, u );
	Writer_Image( U, SampledImageCube, Rg8, u );
	Writer_Image( U, SampledImage1DArray, Rg8, u );
	Writer_Image( U, SampledImage2DArray, Rg8, u );
	Writer_Image( U, SampledImageCubeArray, Rg8, u );
	Writer_Image( U, SampledImage2DMS, Rg8, u );
	Writer_Image( U, SampledImage2DMSArray, Rg8, u );
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
	Writer_Image( U, SampledImageBuffer, R32, u );
	Writer_Image( U, SampledImage1D, R32, u );
	Writer_Image( U, SampledImage2D, R32, u );
	Writer_Image( U, SampledImage3D, R32, u );
	Writer_Image( U, SampledImageCube, R32, u );
	Writer_Image( U, SampledImage1DArray, R32, u );
	Writer_Image( U, SampledImage2DArray, R32, u );
	Writer_Image( U, SampledImageCubeArray, R32, u );
	Writer_Image( U, SampledImage2DMS, R32, u );
	Writer_Image( U, SampledImage2DMSArray, R32, u );
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
	Writer_Image( U, SampledImageBuffer, R16, u );
	Writer_Image( U, SampledImage1D, R16, u );
	Writer_Image( U, SampledImage2D, R16, u );
	Writer_Image( U, SampledImage3D, R16, u );
	Writer_Image( U, SampledImageCube, R16, u );
	Writer_Image( U, SampledImage1DArray, R16, u );
	Writer_Image( U, SampledImage2DArray, R16, u );
	Writer_Image( U, SampledImageCubeArray, R16, u );
	Writer_Image( U, SampledImage2DMS, R16, u );
	Writer_Image( U, SampledImage2DMSArray, R16, u );
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
	Writer_Image( U, SampledImageBuffer, R8, u );
	Writer_Image( U, SampledImage1D, R8, u );
	Writer_Image( U, SampledImage2D, R8, u );
	Writer_Image( U, SampledImage3D, R8, u );
	Writer_Image( U, SampledImageCube, R8, u );
	Writer_Image( U, SampledImage1DArray, R8, u );
	Writer_Image( U, SampledImage2DArray, R8, u );
	Writer_Image( U, SampledImageCubeArray, R8, u );
	Writer_Image( U, SampledImage2DMS, R8, u );
	Writer_Image( U, SampledImage2DMSArray, R8, u );

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
}

#undef Writer_Image

#include "ShaderWriterPrerequisites.inl"
#include "Helpers.hpp"

#endif
