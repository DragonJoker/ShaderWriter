/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Prerequisites_H___
#define ___SDW_Prerequisites_H___

#include <map>

#include <ASTGenerator/Type/Type.hpp>

#define Writer_Parameter( TypeName )\
	using In##TypeName = InParam< TypeName >;\
	using Out##TypeName = OutParam< TypeName >;\
	using InOut##TypeName = InOutParam< TypeName >

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

	enum class SamplerType
	{
		eBufferF,
		e1DF,
		e2DF,
		e3DF,
		eCubeF,
		e2DRectF,
		e1DArrayF,
		e2DArrayF,
		eCubeArrayF,
		e1DShadowF,
		e2DShadowF,
		eCubeShadowF,
		e2DRectShadowF,
		e1DArrayShadowF,
		e2DArrayShadowF,
		eCubeArrayShadowF,
		eBufferI,
		e1DI,
		e2DI,
		e3DI,
		eCubeI,
		e2DRectI,
		e1DArrayI,
		e2DArrayI,
		eCubeArrayI,
		eBufferU,
		e1DU,
		e2DU,
		e3DU,
		eCubeU,
		e2DRectU,
		e1DArrayU,
		e2DArrayU,
		eCubeArrayU,
	};

	enum class ImageType
	{
		eBufferF,
		e1DF,
		e2DF,
		e3DF,
		eCubeF,
		e2DRectF,
		e1DArrayF,
		e2DArrayF,
		eCubeArrayF,
		e2DMSF,
		e2DMSArrayF,
		eBufferI,
		e1DI,
		e2DI,
		e3DI,
		eCubeI,
		e2DRectI,
		e1DArrayI,
		e2DArrayI,
		eCubeArrayI,
		e2DMSI,
		e2DMSArrayI,
		eBufferU,
		e1DU,
		e2DU,
		e3DU,
		eCubeU,
		e2DRectU,
		e1DArrayU,
		e2DArrayU,
		eCubeArrayU,
		e2DMSU,
		e2DMSArrayU,
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
	template< SamplerType ST >
	struct SamplerT;
	template< ImageType ST >
	struct ImageT;

	struct Value;
	struct Void;
	struct Boolean;
	struct Int;
	struct UInt;
	struct Float;
	struct Double;

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

	using SamplerBuffer = SamplerT< SamplerType::eBufferF >;
	using Sampler1D = SamplerT< SamplerType::e1DF >;
	using Sampler2D = SamplerT< SamplerType::e2DF >;
	using Sampler3D = SamplerT< SamplerType::e3DF >;
	using SamplerCube = SamplerT< SamplerType::eCubeF >;
	using Sampler2DRect = SamplerT< SamplerType::e2DRectF >;
	using Sampler1DArray = SamplerT< SamplerType::e1DArrayF >;
	using Sampler2DArray = SamplerT< SamplerType::e2DArrayF >;
	using SamplerCubeArray = SamplerT< SamplerType::eCubeArrayF >;
	using Sampler1DShadow = SamplerT< SamplerType::e1DShadowF >;
	using Sampler2DShadow = SamplerT< SamplerType::e2DShadowF >;
	using SamplerCubeShadow = SamplerT< SamplerType::eCubeShadowF >;
	using Sampler2DRectShadow = SamplerT< SamplerType::e2DRectShadowF >;
	using Sampler1DArrayShadow = SamplerT< SamplerType::e1DArrayShadowF >;
	using Sampler2DArrayShadow = SamplerT< SamplerType::e2DArrayShadowF >;
	using SamplerCubeArrayShadow = SamplerT< SamplerType::eCubeArrayShadowF >;

	using ISamplerBuffer = SamplerT< SamplerType::eBufferI >;
	using ISampler1D = SamplerT< SamplerType::e1DI >;
	using ISampler2D = SamplerT< SamplerType::e2DI >;
	using ISampler3D = SamplerT< SamplerType::e3DI >;
	using ISamplerCube = SamplerT< SamplerType::eCubeI >;
	using ISampler2DRect = SamplerT< SamplerType::e2DRectI >;
	using ISampler1DArray = SamplerT< SamplerType::e1DArrayI >;
	using ISampler2DArray = SamplerT< SamplerType::e2DArrayI >;
	using ISamplerCubeArray = SamplerT< SamplerType::eCubeArrayI >;

	using USamplerBuffer = SamplerT< SamplerType::eBufferU >;
	using USampler1D = SamplerT< SamplerType::e1DU >;
	using USampler2D = SamplerT< SamplerType::e2DU >;
	using USampler3D = SamplerT< SamplerType::e3DU >;
	using USamplerCube = SamplerT< SamplerType::eCubeU >;
	using USampler2DRect = SamplerT< SamplerType::e2DRectU >;
	using USampler1DArray = SamplerT< SamplerType::e1DArrayU >;
	using USampler2DArray = SamplerT< SamplerType::e2DArrayU >;
	using USamplerCubeArray = SamplerT< SamplerType::eCubeArrayU >;

	using ImageBuffer = ImageT< ImageType::eBufferF >;
	using Image1D = ImageT< ImageType::e1DF >;
	using Image2D = ImageT< ImageType::e2DF >;
	using Image3D = ImageT< ImageType::e3DF >;
	using ImageCube = ImageT< ImageType::eCubeF >;
	using Image2DRect = ImageT< ImageType::e2DRectF >;
	using Image1DArray = ImageT< ImageType::e1DArrayF >;
	using Image2DArray = ImageT< ImageType::e2DArrayF >;
	using ImageCubeArray = ImageT< ImageType::eCubeArrayF >;
	using Image2DMS = ImageT< ImageType::e2DMSF >;
	using Image2DMSArray = ImageT< ImageType::e2DMSArrayF >;

	using IImageBuffer = ImageT< ImageType::eBufferI >;
	using IImage1D = ImageT< ImageType::e1DI >;
	using IImage2D = ImageT< ImageType::e2DI >;
	using IImage3D = ImageT< ImageType::e3DI >;
	using IImageCube = ImageT< ImageType::eCubeI >;
	using IImage2DRect = ImageT< ImageType::e2DRectI >;
	using IImage1DArray = ImageT< ImageType::e1DArrayI >;
	using IImage2DArray = ImageT< ImageType::e2DArrayI >;
	using IImageCubeArray = ImageT< ImageType::eCubeArrayI >;
	using IImage2DMS = ImageT< ImageType::e2DMSI >;
	using IImage2DMSArray = ImageT< ImageType::e2DMSArrayI >;

	using UImageBuffer = ImageT< ImageType::eBufferU >;
	using UImage1D = ImageT< ImageType::e1DU >;
	using UImage2D = ImageT< ImageType::e2DU >;
	using UImage3D = ImageT< ImageType::e3DU >;
	using UImageCube = ImageT< ImageType::eCubeU >;
	using UImage2DRect = ImageT< ImageType::e2DRectU >;
	using UImage1DArray = ImageT< ImageType::e1DArrayU >;
	using UImage2DArray = ImageT< ImageType::e2DArrayU >;
	using UImageCubeArray = ImageT< ImageType::eCubeArrayU >;
	using UImage2DMS = ImageT< ImageType::e2DMSU >;
	using UImage2DMSArray = ImageT< ImageType::e2DMSArrayU >;

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
	Writer_Parameter( SamplerBuffer );
	Writer_Parameter( Sampler1D );
	Writer_Parameter( Sampler2D );
	Writer_Parameter( Sampler3D );
	Writer_Parameter( SamplerCube );
	Writer_Parameter( Sampler2DRect );
	Writer_Parameter( Sampler1DArray );
	Writer_Parameter( Sampler2DArray );
	Writer_Parameter( SamplerCubeArray );
	Writer_Parameter( Sampler1DShadow );
	Writer_Parameter( Sampler2DShadow );
	Writer_Parameter( SamplerCubeShadow );
	Writer_Parameter( Sampler2DRectShadow );
	Writer_Parameter( Sampler1DArrayShadow );
	Writer_Parameter( Sampler2DArrayShadow );
	Writer_Parameter( SamplerCubeArrayShadow );
	Writer_Parameter( ISamplerBuffer );
	Writer_Parameter( ISampler1D );
	Writer_Parameter( ISampler2D );
	Writer_Parameter( ISampler3D );
	Writer_Parameter( ISamplerCube );
	Writer_Parameter( ISampler2DRect );
	Writer_Parameter( ISampler1DArray );
	Writer_Parameter( ISampler2DArray );
	Writer_Parameter( ISamplerCubeArray );
	Writer_Parameter( USamplerBuffer );
	Writer_Parameter( USampler1D );
	Writer_Parameter( USampler2D );
	Writer_Parameter( USampler3D );
	Writer_Parameter( USamplerCube );
	Writer_Parameter( USampler2DRect );
	Writer_Parameter( USampler1DArray );
	Writer_Parameter( USampler2DArray );
	Writer_Parameter( USamplerCubeArray );
	Writer_Parameter( ImageBuffer );
	Writer_Parameter( Image1D );
	Writer_Parameter( Image2D );
	Writer_Parameter( Image3D );
	Writer_Parameter( ImageCube );
	Writer_Parameter( Image2DRect );
	Writer_Parameter( Image1DArray );
	Writer_Parameter( Image2DArray );
	Writer_Parameter( ImageCubeArray );
	Writer_Parameter( Image2DMS );
	Writer_Parameter( Image2DMSArray );
	Writer_Parameter( IImageBuffer );
	Writer_Parameter( IImage1D );
	Writer_Parameter( IImage2D );
	Writer_Parameter( IImage3D );
	Writer_Parameter( IImageCube );
	Writer_Parameter( IImage2DRect );
	Writer_Parameter( IImage1DArray );
	Writer_Parameter( IImage2DArray );
	Writer_Parameter( IImageCubeArray );
	Writer_Parameter( IImage2DMS );
	Writer_Parameter( IImage2DMSArray );
	Writer_Parameter( UImageBuffer );
	Writer_Parameter( UImage1D );
	Writer_Parameter( UImage2D );
	Writer_Parameter( UImage3D );
	Writer_Parameter( UImageCube );
	Writer_Parameter( UImage2DRect );
	Writer_Parameter( UImage1DArray );
	Writer_Parameter( UImage2DArray );
	Writer_Parameter( UImageCubeArray );
	Writer_Parameter( UImage2DMS );
	Writer_Parameter( UImage2DMSArray );

	template< typename T >
	struct TypeTraits;
	template< SamplerType ST >
	struct SamplerTypeTraits;
	template< ImageType ST >
	struct ImageTypeTraits;
}

#undef Writer_Parameter

#include "ShaderWriterPrerequisites.inl"
#include "Helpers.hpp"

#endif
