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

#define Writer_Image( Prefix, TypeName, Sampled )\
	using Prefix##TypeName = TypeName##T< Sampled >;\
	Writer_Parameter( Prefix##TypeName )

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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageT;
	struct Sampler;
	struct SampledImage;
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
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

	template< ast::type::Kind SampledT >
	using ImageBufferT = ImageT< SampledT
		, ast::type::ImageDim::eBuffer
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image1DT = ImageT< SampledT
		, ast::type::ImageDim::e1D
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DT = ImageT< SampledT
		, ast::type::ImageDim::e2D
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image3DT = ImageT< SampledT
		, ast::type::ImageDim::e3D
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using ImageCubeT = ImageT< SampledT
		, ast::type::ImageDim::eCube
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DRectT = ImageT< SampledT
		, ast::type::ImageDim::eRect
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image1DArrayT = ImageT< SampledT
		, ast::type::ImageDim::e1D
		, true
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DArrayT = ImageT< SampledT
		, ast::type::ImageDim::e2D
		, true
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using ImageCubeArrayT = ImageT< SampledT
		, ast::type::ImageDim::eCube
		, true
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using Image1DShadowT = ImageT< SampledT
		, ast::type::ImageDim::e1D
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DShadowT = ImageT< SampledT
		, ast::type::ImageDim::e2D
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using ImageCubeShadowT = ImageT< SampledT
		, ast::type::ImageDim::eCube
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DRectShadowT = ImageT< SampledT
		, ast::type::ImageDim::eRect
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using Image1DArrayShadowT = ImageT< SampledT
		, ast::type::ImageDim::e1D
		, true
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DArrayShadowT = ImageT< SampledT
		, ast::type::ImageDim::e2D
		, true
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using ImageCubeArrayShadowT = ImageT< SampledT
		, ast::type::ImageDim::eCube
		, true
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using Image2DMST = ImageT< SampledT
		, ast::type::ImageDim::e2D
		, false
		, false
		, true >;
	template< ast::type::Kind SampledT >
	using Image2DMSArrayT = ImageT< SampledT
		, ast::type::ImageDim::e2D
		, true
		, false
		, true >;

	template< ast::type::Kind SampledT >
	using SampledImageBufferT = SampledImageT< SampledT
		, ast::type::ImageDim::eBuffer
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage1DT = SampledImageT< SampledT
		, ast::type::ImageDim::e1D
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DT = SampledImageT< SampledT
		, ast::type::ImageDim::e2D
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage3DT = SampledImageT< SampledT
		, ast::type::ImageDim::e3D
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DRectT = SampledImageT< SampledT
		, ast::type::ImageDim::eRect
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImageCubeT = SampledImageT< SampledT
		, ast::type::ImageDim::eCube
		, false
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage1DArrayT = SampledImageT< SampledT
		, ast::type::ImageDim::e1D
		, true
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DArrayT = SampledImageT< SampledT
		, ast::type::ImageDim::e2D
		, true
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImageCubeArrayT = SampledImageT< SampledT
		, ast::type::ImageDim::eCube
		, true
		, false
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage1DShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::e1D
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::e2D
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DRectShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::eRect
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImageCubeShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::eCube
		, false
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage1DArrayShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::e1D
		, true
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DArrayShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::e2D
		, true
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImageCubeArrayShadowT = SampledImageT< SampledT
		, ast::type::ImageDim::eCube
		, true
		, true
		, false >;
	template< ast::type::Kind SampledT >
	using SampledImage2DMST = SampledImageT< SampledT
		, ast::type::ImageDim::e2D
		, false
		, false
		, true >;
	template< ast::type::Kind SampledT >
	using SampledImage2DMSArrayT = SampledImageT< SampledT
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

	Writer_Image( , ImageBuffer, ast::type::Kind::eFloat );
	Writer_Image( , Image1D, ast::type::Kind::eFloat );
	Writer_Image( , Image2D, ast::type::Kind::eFloat );
	Writer_Image( , Image3D, ast::type::Kind::eFloat );
	Writer_Image( , Image2DRect, ast::type::Kind::eFloat );
	Writer_Image( , ImageCube, ast::type::Kind::eFloat );
	Writer_Image( , Image1DArray, ast::type::Kind::eFloat );
	Writer_Image( , Image2DArray, ast::type::Kind::eFloat );
	Writer_Image( , ImageCubeArray, ast::type::Kind::eFloat );
	Writer_Image( , Image2DMS, ast::type::Kind::eFloat );
	Writer_Image( , Image2DMSArray, ast::type::Kind::eFloat );
	Writer_Image( , SampledImageBuffer, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage1D, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2D, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage3D, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DRect, ast::type::Kind::eFloat );
	Writer_Image( , SampledImageCube, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage1DArray, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DArray, ast::type::Kind::eFloat );
	Writer_Image( , SampledImageCubeArray, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage1DShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DRectShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImageCubeShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage1DArrayShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DArrayShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImageCubeArrayShadow, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DMS, ast::type::Kind::eFloat );
	Writer_Image( , SampledImage2DMSArray, ast::type::Kind::eFloat );
	Writer_Image( I, ImageBuffer, ast::type::Kind::eInt );
	Writer_Image( I, Image1D, ast::type::Kind::eInt );
	Writer_Image( I, Image2D, ast::type::Kind::eInt );
	Writer_Image( I, Image3D, ast::type::Kind::eInt );
	Writer_Image( I, Image2DRect, ast::type::Kind::eInt );
	Writer_Image( I, ImageCube, ast::type::Kind::eInt );
	Writer_Image( I, Image1DArray, ast::type::Kind::eInt );
	Writer_Image( I, Image2DArray, ast::type::Kind::eInt );
	Writer_Image( I, ImageCubeArray, ast::type::Kind::eInt );
	Writer_Image( I, Image2DMS, ast::type::Kind::eInt );
	Writer_Image( I, Image2DMSArray, ast::type::Kind::eInt );
	Writer_Image( I, SampledImageBuffer, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage1D, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage2D, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage3D, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage2DRect, ast::type::Kind::eInt );
	Writer_Image( I, SampledImageCube, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage1DArray, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage2DArray, ast::type::Kind::eInt );
	Writer_Image( I, SampledImageCubeArray, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage2DMS, ast::type::Kind::eInt );
	Writer_Image( I, SampledImage2DMSArray, ast::type::Kind::eInt );
	Writer_Image( U, ImageBuffer, ast::type::Kind::eUInt );
	Writer_Image( U, Image1D, ast::type::Kind::eUInt );
	Writer_Image( U, Image2D, ast::type::Kind::eUInt );
	Writer_Image( U, Image3D, ast::type::Kind::eUInt );
	Writer_Image( U, Image2DRect, ast::type::Kind::eUInt );
	Writer_Image( U, ImageCube, ast::type::Kind::eUInt );
	Writer_Image( U, Image1DArray, ast::type::Kind::eUInt );
	Writer_Image( U, Image2DArray, ast::type::Kind::eUInt );
	Writer_Image( U, ImageCubeArray, ast::type::Kind::eUInt );
	Writer_Image( U, Image2DMS, ast::type::Kind::eUInt );
	Writer_Image( U, Image2DMSArray, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImageBuffer, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage1D, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage2D, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage3D, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage2DRect, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImageCube, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage1DArray, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage2DArray, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImageCubeArray, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage2DMS, ast::type::Kind::eUInt );
	Writer_Image( U, SampledImage2DMSArray, ast::type::Kind::eUInt );

	template< typename T >
	struct TypeTraits;
}

#undef Writer_Image
#undef Writer_Parameter

#include "ShaderWriterPrerequisites.inl"
#include "Helpers.hpp"

#endif
