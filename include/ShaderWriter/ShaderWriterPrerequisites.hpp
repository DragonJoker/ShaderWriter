/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Prerequisites_H___
#define ___SDW_Prerequisites_H___

#include <map>

#include <ASTGenerator/Type/Type.hpp>
#include <ASTGenerator/Type/ImageConfiguration.hpp>

#define Writer_Parameter( TypeName )\
	using In##TypeName = InParam< TypeName >;\
	using Out##TypeName = OutParam< TypeName >;\
	using InOut##TypeName = InOutParam< TypeName >

#define Writer_Image( TypeName, Format )\
	using TypeName##Format = TypeName##T< ast::type::ImageFormat::e##Format >;\
	Writer_Parameter( TypeName##Format )

#define Writer_Images( Format )\
	Writer_Image( ImageBuffer, Format );\
	Writer_Image( Image1D, Format );\
	Writer_Image( Image2D, Format );\
	Writer_Image( Image3D, Format );\
	Writer_Image( ImageCube, Format );\
	Writer_Image( Image2DRect, Format );\
	Writer_Image( Image1DArray, Format );\
	Writer_Image( Image2DArray, Format );\
	Writer_Image( ImageCubeArray, Format );\
	Writer_Image( Image1DShadow, Format );\
	Writer_Image( Image2DShadow, Format );\
	Writer_Image( ImageCubeShadow, Format );\
	Writer_Image( Image2DRectShadow, Format );\
	Writer_Image( Image1DArrayShadow, Format );\
	Writer_Image( Image2DArrayShadow, Format );\
	Writer_Image( ImageCubeArrayShadow, Format );\
	Writer_Image( Image2DMS, Format );\
	Writer_Image( Image2DMSArray, Format );\
	Writer_Image( SampledImage1D, Format );\
	Writer_Image( SampledImage2D, Format );\
	Writer_Image( SampledImage3D, Format );\
	Writer_Image( SampledImageCube, Format );\
	Writer_Image( SampledImage1DArray, Format );\
	Writer_Image( SampledImage2DArray, Format );\
	Writer_Image( SampledImageCubeArray, Format );\
	Writer_Image( SampledImage1DShadow, Format );\
	Writer_Image( SampledImage2DShadow, Format );\
	Writer_Image( SampledImageCubeShadow, Format );\
	Writer_Image( SampledImage1DArrayShadow, Format );\
	Writer_Image( SampledImage2DArrayShadow, Format );\
	Writer_Image( SampledImageCubeArrayShadow, Format )

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
	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageT;
	struct Sampler;
	struct SampledImage;
	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		struct SampledImageT;

	struct Value;
	struct Void;
	struct Boolean;
	struct Int;
	struct UInt;
	struct Float;
	struct Double;

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

	template< ast::type::ImageFormat FormatT >
	using ImageBufferT = ImageT< ast::type::ImageDim::eBuffer
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image1DT = ImageT< ast::type::ImageDim::e1D
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DT = ImageT< ast::type::ImageDim::e2D
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image3DT = ImageT< ast::type::ImageDim::e3D
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using ImageCubeT = ImageT< ast::type::ImageDim::eCube
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DRectT = ImageT< ast::type::ImageDim::eRect
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image1DArrayT = ImageT< ast::type::ImageDim::e1D
		, FormatT
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DArrayT = ImageT< ast::type::ImageDim::e2D
		, FormatT
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using ImageCubeArrayT = ImageT< ast::type::ImageDim::eCube
		, FormatT
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image1DShadowT = ImageT< ast::type::ImageDim::e1D
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DShadowT = ImageT< ast::type::ImageDim::e2D
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using ImageCubeShadowT = ImageT< ast::type::ImageDim::eCube
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DRectShadowT = ImageT< ast::type::ImageDim::eRect
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image1DArrayShadowT = ImageT< ast::type::ImageDim::e1D
		, FormatT
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DArrayShadowT = ImageT< ast::type::ImageDim::e2D
		, FormatT
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using ImageCubeArrayShadowT = ImageT< ast::type::ImageDim::eCube
		, FormatT
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using Image2DMST = ImageT< ast::type::ImageDim::e2D
		, FormatT
		, false
		, false
		, true >;
	template< ast::type::ImageFormat FormatT >
	using Image2DMSArrayT = ImageT< ast::type::ImageDim::e2D
		, FormatT
		, true
		, false
		, true >;

	template< ast::type::ImageFormat FormatT >
	using SampledImage1DT = SampledImageT< ast::type::ImageDim::e1D
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DT = SampledImageT< ast::type::ImageDim::e2D
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage3DT = SampledImageT< ast::type::ImageDim::e3D
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeT = SampledImageT< ast::type::ImageDim::eCube
		, FormatT
		, false
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DArrayT = SampledImageT< ast::type::ImageDim::e1D
		, FormatT
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DArrayT = SampledImageT< ast::type::ImageDim::e2D
		, FormatT
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeArrayT = SampledImageT< ast::type::ImageDim::eCube
		, FormatT
		, true
		, false
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DShadowT = SampledImageT< ast::type::ImageDim::e1D
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DShadowT = SampledImageT< ast::type::ImageDim::e2D
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeShadowT = SampledImageT< ast::type::ImageDim::eCube
		, FormatT
		, false
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage1DArrayShadowT = SampledImageT< ast::type::ImageDim::e1D
		, FormatT
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImage2DArrayShadowT = SampledImageT< ast::type::ImageDim::e2D
		, FormatT
		, true
		, true
		, false >;
	template< ast::type::ImageFormat FormatT >
	using SampledImageCubeArrayShadowT = SampledImageT< ast::type::ImageDim::eCube
		, FormatT
		, true
		, true
		, false >;

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

	Writer_Images( Unknown );
	Writer_Images( Rgba32f );
	Writer_Images( Rgba16f );
	Writer_Images( Rg32f );
	Writer_Images( Rg16f );
	Writer_Images( R32f );
	Writer_Images( R16f );
	Writer_Images( Rgba32i );
	Writer_Images( Rgba16i );
	Writer_Images( Rgba8i );
	Writer_Images( Rg32i );
	Writer_Images( Rg16i );
	Writer_Images( Rg8i );
	Writer_Images( R32i );
	Writer_Images( R16i );
	Writer_Images( R8i );
	Writer_Images( Rgba32u );
	Writer_Images( Rgba16u );
	Writer_Images( Rgba8u );
	Writer_Images( Rg32u );
	Writer_Images( Rg16u );
	Writer_Images( R32u );
	Writer_Images( Rg8u );
	Writer_Images( R16u );
	Writer_Images( R8u );

	template< typename T >
	struct TypeTraits;
}

#undef Writer_Images
#undef Writer_Image
#undef Writer_Parameter

#include "ShaderWriterPrerequisites.inl"
#include "Helpers.hpp"

#endif
