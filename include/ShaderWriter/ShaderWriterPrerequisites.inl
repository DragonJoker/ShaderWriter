/*
See LICENSE file in root folder
*/
namespace sdw
{
	template<>
	struct TypeTraits< Boolean >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eBoolean;
	};

	template<>
	struct TypeTraits< Int >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eInt;
	};

	template<>
	struct TypeTraits< UInt >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eUInt;
	};

	template<>
	struct TypeTraits< Float >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eFloat;
	};

	template<>
	struct TypeTraits< Double >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eDouble;
	};

	template<>
	struct TypeTraits< BVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2B;
	};

	template<>
	struct TypeTraits< BVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3B;
	};

	template<>
	struct TypeTraits< BVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4B;
	};

	template<>
	struct TypeTraits< IVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2I;
	};

	template<>
	struct TypeTraits< IVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3I;
	};

	template<>
	struct TypeTraits< IVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4I;
	};

	template<>
	struct TypeTraits< UVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2U;
	};

	template<>
	struct TypeTraits< UVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3U;
	};

	template<>
	struct TypeTraits< UVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4U;
	};

	template<>
	struct TypeTraits< Vec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2F;
	};

	template<>
	struct TypeTraits< Vec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3F;
	};

	template<>
	struct TypeTraits< Vec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4F;
	};

	template<>
	struct TypeTraits< DVec2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec2D;
	};

	template<>
	struct TypeTraits< DVec3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec3D;
	};

	template<>
	struct TypeTraits< DVec4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eVec4D;
	};

	template<>
	struct TypeTraits< Mat2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x2F;
	};

	template<>
	struct TypeTraits< Mat2x3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x3F;
	};

	template<>
	struct TypeTraits< Mat2x4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x4F;
	};

	template<>
	struct TypeTraits< Mat3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x3F;
	};

	template<>
	struct TypeTraits< Mat3x2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x2F;
	};

	template<>
	struct TypeTraits< Mat3x4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x4F;
	};

	template<>
	struct TypeTraits< Mat4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x4F;
	};

	template<>
	struct TypeTraits< Mat4x2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x2F;
	};

	template<>
	struct TypeTraits< Mat4x3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x3F;
	};

	template<>
	struct TypeTraits< DMat2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x2D;
	};

	template<>
	struct TypeTraits< DMat2x3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x3D;
	};

	template<>
	struct TypeTraits< DMat2x4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat2x4D;
	};

	template<>
	struct TypeTraits< DMat3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x3D;
	};

	template<>
	struct TypeTraits< DMat3x2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x2D;
	};

	template<>
	struct TypeTraits< DMat3x4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat3x4D;
	};

	template<>
	struct TypeTraits< DMat4 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x4D;
	};

	template<>
	struct TypeTraits< DMat4x2 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x2D;
	};

	template<>
	struct TypeTraits< DMat4x3 >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eMat4x3D;
	};

	template<>
	struct TypeTraits< StructInstance >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eStruct;
	};

	template<>
	struct TypeTraits< SampledImage >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampledImage;
	};

	template<>
	struct TypeTraits< Image >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage;
	};

#define Writer_Image( Prefix, TypeName, Format, Value )\
	template<>\
	struct TypeTraits< Prefix##TypeName##Format >\
	{\
		static ast::type::Kind const TypeEnum = ast::type::Kind::Value;\
	}

	Writer_Image( , ImageBuffer, Rgba32, eImage );
	Writer_Image( , Image1D, Rgba32, eImage );
	Writer_Image( , Image2D, Rgba32, eImage );
	Writer_Image( , Image3D, Rgba32, eImage );
	Writer_Image( , Image2DRect, Rgba32, eImage );
	Writer_Image( , ImageCube, Rgba32, eImage );
	Writer_Image( , Image1DArray, Rgba32, eImage );
	Writer_Image( , Image2DArray, Rgba32, eImage );
	Writer_Image( , ImageCubeArray, Rgba32, eImage );
	Writer_Image( , Image2DMS, Rgba32, eImage );
	Writer_Image( , Image2DMSArray, Rgba32, eImage );
	Writer_Image( , SampledImageBuffer, Rgba32, eSampledImage );
	Writer_Image( , SampledImage1D, Rgba32, eSampledImage );
	Writer_Image( , SampledImage2D, Rgba32, eSampledImage );
	Writer_Image( , SampledImage3D, Rgba32, eSampledImage );
	Writer_Image( , SampledImage2DRect, Rgba32, eSampledImage );
	Writer_Image( , SampledImageCube, Rgba32, eSampledImage );
	Writer_Image( , SampledImage1DArray, Rgba32, eSampledImage );
	Writer_Image( , SampledImage2DArray, Rgba32, eSampledImage );
	Writer_Image( , SampledImageCubeArray, Rgba32, eSampledImage );
	Writer_Image( , SampledImage2DMS, Rgba32, eSampledImage );
	Writer_Image( , SampledImage2DMSArray, Rgba32, eSampledImage );
	Writer_Image( , ImageBuffer, Rgba16, eImage );
	Writer_Image( , Image1D, Rgba16, eImage );
	Writer_Image( , Image2D, Rgba16, eImage );
	Writer_Image( , Image3D, Rgba16, eImage );
	Writer_Image( , Image2DRect, Rgba16, eImage );
	Writer_Image( , ImageCube, Rgba16, eImage );
	Writer_Image( , Image1DArray, Rgba16, eImage );
	Writer_Image( , Image2DArray, Rgba16, eImage );
	Writer_Image( , ImageCubeArray, Rgba16, eImage );
	Writer_Image( , Image2DMS, Rgba16, eImage );
	Writer_Image( , Image2DMSArray, Rgba16, eImage );
	Writer_Image( , SampledImageBuffer, Rgba16, eSampledImage );
	Writer_Image( , SampledImage1D, Rgba16, eSampledImage );
	Writer_Image( , SampledImage2D, Rgba16, eSampledImage );
	Writer_Image( , SampledImage3D, Rgba16, eSampledImage );
	Writer_Image( , SampledImage2DRect, Rgba16, eSampledImage );
	Writer_Image( , SampledImageCube, Rgba16, eSampledImage );
	Writer_Image( , SampledImage1DArray, Rgba16, eSampledImage );
	Writer_Image( , SampledImage2DArray, Rgba16, eSampledImage );
	Writer_Image( , SampledImageCubeArray, Rgba16, eSampledImage );
	Writer_Image( , SampledImage2DMS, Rgba16, eSampledImage );
	Writer_Image( , SampledImage2DMSArray, Rgba16, eSampledImage );
	Writer_Image( , ImageBuffer, Rg32, eImage );
	Writer_Image( , Image1D, Rg32, eImage );
	Writer_Image( , Image2D, Rg32, eImage );
	Writer_Image( , Image3D, Rg32, eImage );
	Writer_Image( , Image2DRect, Rg32, eImage );
	Writer_Image( , ImageCube, Rg32, eImage );
	Writer_Image( , Image1DArray, Rg32, eImage );
	Writer_Image( , Image2DArray, Rg32, eImage );
	Writer_Image( , ImageCubeArray, Rg32, eImage );
	Writer_Image( , Image2DMS, Rg32, eImage );
	Writer_Image( , Image2DMSArray, Rg32, eImage );
	Writer_Image( , SampledImageBuffer, Rg32, eSampledImage );
	Writer_Image( , SampledImage1D, Rg32, eSampledImage );
	Writer_Image( , SampledImage2D, Rg32, eSampledImage );
	Writer_Image( , SampledImage3D, Rg32, eSampledImage );
	Writer_Image( , SampledImage2DRect, Rg32, eSampledImage );
	Writer_Image( , SampledImageCube, Rg32, eSampledImage );
	Writer_Image( , SampledImage1DArray, Rg32, eSampledImage );
	Writer_Image( , SampledImage2DArray, Rg32, eSampledImage );
	Writer_Image( , SampledImageCubeArray, Rg32, eSampledImage );
	Writer_Image( , SampledImage2DMS, Rg32, eSampledImage );
	Writer_Image( , SampledImage2DMSArray, Rg32, eSampledImage );
	Writer_Image( , ImageBuffer, Rg16, eImage );
	Writer_Image( , Image1D, Rg16, eImage );
	Writer_Image( , Image2D, Rg16, eImage );
	Writer_Image( , Image3D, Rg16, eImage );
	Writer_Image( , Image2DRect, Rg16, eImage );
	Writer_Image( , ImageCube, Rg16, eImage );
	Writer_Image( , Image1DArray, Rg16, eImage );
	Writer_Image( , Image2DArray, Rg16, eImage );
	Writer_Image( , ImageCubeArray, Rg16, eImage );
	Writer_Image( , Image2DMS, Rg16, eImage );
	Writer_Image( , Image2DMSArray, Rg16, eImage );
	Writer_Image( , SampledImageBuffer, Rg16, eSampledImage );
	Writer_Image( , SampledImage1D, Rg16, eSampledImage );
	Writer_Image( , SampledImage2D, Rg16, eSampledImage );
	Writer_Image( , SampledImage3D, Rg16, eSampledImage );
	Writer_Image( , SampledImage2DRect, Rg16, eSampledImage );
	Writer_Image( , SampledImageCube, Rg16, eSampledImage );
	Writer_Image( , SampledImage1DArray, Rg16, eSampledImage );
	Writer_Image( , SampledImage2DArray, Rg16, eSampledImage );
	Writer_Image( , SampledImageCubeArray, Rg16, eSampledImage );
	Writer_Image( , SampledImage2DMS, Rg16, eSampledImage );
	Writer_Image( , SampledImage2DMSArray, Rg16, eSampledImage );
	Writer_Image( , ImageBuffer, R32, eImage );
	Writer_Image( , Image1D, R32, eImage );
	Writer_Image( , Image2D, R32, eImage );
	Writer_Image( , Image3D, R32, eImage );
	Writer_Image( , Image2DRect, R32, eImage );
	Writer_Image( , ImageCube, R32, eImage );
	Writer_Image( , Image1DArray, R32, eImage );
	Writer_Image( , Image2DArray, R32, eImage );
	Writer_Image( , ImageCubeArray, R32, eImage );
	Writer_Image( , Image2DMS, R32, eImage );
	Writer_Image( , Image2DMSArray, R32, eImage );
	Writer_Image( , SampledImageBuffer, R32, eSampledImage );
	Writer_Image( , SampledImage1D, R32, eSampledImage );
	Writer_Image( , SampledImage2D, R32, eSampledImage );
	Writer_Image( , SampledImage3D, R32, eSampledImage );
	Writer_Image( , SampledImage2DRect, R32, eSampledImage );
	Writer_Image( , SampledImageCube, R32, eSampledImage );
	Writer_Image( , SampledImage1DArray, R32, eSampledImage );
	Writer_Image( , SampledImage2DArray, R32, eSampledImage );
	Writer_Image( , SampledImageCubeArray, R32, eSampledImage );
	Writer_Image( , SampledImage2DMS, R32, eSampledImage );
	Writer_Image( , SampledImage2DMSArray, R32, eSampledImage );
	Writer_Image( , ImageBuffer, R16, eImage );
	Writer_Image( , Image1D, R16, eImage );
	Writer_Image( , Image2D, R16, eImage );
	Writer_Image( , Image3D, R16, eImage );
	Writer_Image( , Image2DRect, R16, eImage );
	Writer_Image( , ImageCube, R16, eImage );
	Writer_Image( , Image1DArray, R16, eImage );
	Writer_Image( , Image2DArray, R16, eImage );
	Writer_Image( , ImageCubeArray, R16, eImage );
	Writer_Image( , Image2DMS, R16, eImage );
	Writer_Image( , Image2DMSArray, R16, eImage );
	Writer_Image( , SampledImageBuffer, R16, eSampledImage );
	Writer_Image( , SampledImage1D, R16, eSampledImage );
	Writer_Image( , SampledImage2D, R16, eSampledImage );
	Writer_Image( , SampledImage3D, R16, eSampledImage );
	Writer_Image( , SampledImage2DRect, R16, eSampledImage );
	Writer_Image( , SampledImageCube, R16, eSampledImage );
	Writer_Image( , SampledImage1DArray, R16, eSampledImage );
	Writer_Image( , SampledImage2DArray, R16, eSampledImage );
	Writer_Image( , SampledImageCubeArray, R16, eSampledImage );
	Writer_Image( , SampledImage2DMS, R16, eSampledImage );
	Writer_Image( , SampledImage2DMSArray, R16, eSampledImage );
	Writer_Image( , SampledImage1DShadow, R32, eSampledImage );
	Writer_Image( , SampledImage2DShadow, R32, eSampledImage );
	Writer_Image( , SampledImage2DRectShadow, R32, eSampledImage );
	Writer_Image( , SampledImageCubeShadow, R32, eSampledImage );
	Writer_Image( , SampledImage1DArrayShadow, R32, eSampledImage );
	Writer_Image( , SampledImage2DArrayShadow, R32, eSampledImage );
	Writer_Image( , SampledImageCubeArrayShadow, R32, eSampledImage );
	Writer_Image( , SampledImage1DShadow, R16, eSampledImage );
	Writer_Image( , SampledImage2DShadow, R16, eSampledImage );
	Writer_Image( , SampledImage2DRectShadow, R16, eSampledImage );
	Writer_Image( , SampledImageCubeShadow, R16, eSampledImage );
	Writer_Image( , SampledImage1DArrayShadow, R16, eSampledImage );
	Writer_Image( , SampledImage2DArrayShadow, R16, eSampledImage );
	Writer_Image( , SampledImageCubeArrayShadow, R16, eSampledImage );
	Writer_Image( I, ImageBuffer, Rgba32, eImage );
	Writer_Image( I, Image1D, Rgba32, eImage );
	Writer_Image( I, Image2D, Rgba32, eImage );
	Writer_Image( I, Image3D, Rgba32, eImage );
	Writer_Image( I, Image2DRect, Rgba32, eImage );
	Writer_Image( I, ImageCube, Rgba32, eImage );
	Writer_Image( I, Image1DArray, Rgba32, eImage );
	Writer_Image( I, Image2DArray, Rgba32, eImage );
	Writer_Image( I, ImageCubeArray, Rgba32, eImage );
	Writer_Image( I, Image2DMS, Rgba32, eImage );
	Writer_Image( I, Image2DMSArray, Rgba32, eImage );
	Writer_Image( I, SampledImageBuffer, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage1D, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage2D, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage3D, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage2DRect, Rgba32, eSampledImage );
	Writer_Image( I, SampledImageCube, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage1DArray, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage2DArray, Rgba32, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage2DMS, Rgba32, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, Rgba32, eSampledImage );
	Writer_Image( I, ImageBuffer, Rgba16, eImage );
	Writer_Image( I, Image1D, Rgba16, eImage );
	Writer_Image( I, Image2D, Rgba16, eImage );
	Writer_Image( I, Image3D, Rgba16, eImage );
	Writer_Image( I, Image2DRect, Rgba16, eImage );
	Writer_Image( I, ImageCube, Rgba16, eImage );
	Writer_Image( I, Image1DArray, Rgba16, eImage );
	Writer_Image( I, Image2DArray, Rgba16, eImage );
	Writer_Image( I, ImageCubeArray, Rgba16, eImage );
	Writer_Image( I, Image2DMS, Rgba16, eImage );
	Writer_Image( I, Image2DMSArray, Rgba16, eImage );
	Writer_Image( I, SampledImageBuffer, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage1D, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage2D, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage3D, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage2DRect, Rgba16, eSampledImage );
	Writer_Image( I, SampledImageCube, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage1DArray, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage2DArray, Rgba16, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage2DMS, Rgba16, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, Rgba16, eSampledImage );
	Writer_Image( I, ImageBuffer, Rgba8, eImage );
	Writer_Image( I, Image1D, Rgba8, eImage );
	Writer_Image( I, Image2D, Rgba8, eImage );
	Writer_Image( I, Image3D, Rgba8, eImage );
	Writer_Image( I, Image2DRect, Rgba8, eImage );
	Writer_Image( I, ImageCube, Rgba8, eImage );
	Writer_Image( I, Image1DArray, Rgba8, eImage );
	Writer_Image( I, Image2DArray, Rgba8, eImage );
	Writer_Image( I, ImageCubeArray, Rgba8, eImage );
	Writer_Image( I, Image2DMS, Rgba8, eImage );
	Writer_Image( I, Image2DMSArray, Rgba8, eImage );
	Writer_Image( I, SampledImageBuffer, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage1D, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage2D, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage3D, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage2DRect, Rgba8, eSampledImage );
	Writer_Image( I, SampledImageCube, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage1DArray, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage2DArray, Rgba8, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage2DMS, Rgba8, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, Rgba8, eSampledImage );
	Writer_Image( I, ImageBuffer, Rg32, eImage );
	Writer_Image( I, Image1D, Rg32, eImage );
	Writer_Image( I, Image2D, Rg32, eImage );
	Writer_Image( I, Image3D, Rg32, eImage );
	Writer_Image( I, Image2DRect, Rg32, eImage );
	Writer_Image( I, ImageCube, Rg32, eImage );
	Writer_Image( I, Image1DArray, Rg32, eImage );
	Writer_Image( I, Image2DArray, Rg32, eImage );
	Writer_Image( I, ImageCubeArray, Rg32, eImage );
	Writer_Image( I, Image2DMS, Rg32, eImage );
	Writer_Image( I, Image2DMSArray, Rg32, eImage );
	Writer_Image( I, SampledImageBuffer, Rg32, eSampledImage );
	Writer_Image( I, SampledImage1D, Rg32, eSampledImage );
	Writer_Image( I, SampledImage2D, Rg32, eSampledImage );
	Writer_Image( I, SampledImage3D, Rg32, eSampledImage );
	Writer_Image( I, SampledImage2DRect, Rg32, eSampledImage );
	Writer_Image( I, SampledImageCube, Rg32, eSampledImage );
	Writer_Image( I, SampledImage1DArray, Rg32, eSampledImage );
	Writer_Image( I, SampledImage2DArray, Rg32, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, Rg32, eSampledImage );
	Writer_Image( I, SampledImage2DMS, Rg32, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, Rg32, eSampledImage );
	Writer_Image( I, ImageBuffer, Rg16, eImage );
	Writer_Image( I, Image1D, Rg16, eImage );
	Writer_Image( I, Image2D, Rg16, eImage );
	Writer_Image( I, Image3D, Rg16, eImage );
	Writer_Image( I, Image2DRect, Rg16, eImage );
	Writer_Image( I, ImageCube, Rg16, eImage );
	Writer_Image( I, Image1DArray, Rg16, eImage );
	Writer_Image( I, Image2DArray, Rg16, eImage );
	Writer_Image( I, ImageCubeArray, Rg16, eImage );
	Writer_Image( I, Image2DMS, Rg16, eImage );
	Writer_Image( I, Image2DMSArray, Rg16, eImage );
	Writer_Image( I, SampledImageBuffer, Rg16, eSampledImage );
	Writer_Image( I, SampledImage1D, Rg16, eSampledImage );
	Writer_Image( I, SampledImage2D, Rg16, eSampledImage );
	Writer_Image( I, SampledImage3D, Rg16, eSampledImage );
	Writer_Image( I, SampledImage2DRect, Rg16, eSampledImage );
	Writer_Image( I, SampledImageCube, Rg16, eSampledImage );
	Writer_Image( I, SampledImage1DArray, Rg16, eSampledImage );
	Writer_Image( I, SampledImage2DArray, Rg16, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, Rg16, eSampledImage );
	Writer_Image( I, SampledImage2DMS, Rg16, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, Rg16, eSampledImage );
	Writer_Image( I, ImageBuffer, Rg8, eImage );
	Writer_Image( I, Image1D, Rg8, eImage );
	Writer_Image( I, Image2D, Rg8, eImage );
	Writer_Image( I, Image3D, Rg8, eImage );
	Writer_Image( I, Image2DRect, Rg8, eImage );
	Writer_Image( I, ImageCube, Rg8, eImage );
	Writer_Image( I, Image1DArray, Rg8, eImage );
	Writer_Image( I, Image2DArray, Rg8, eImage );
	Writer_Image( I, ImageCubeArray, Rg8, eImage );
	Writer_Image( I, Image2DMS, Rg8, eImage );
	Writer_Image( I, Image2DMSArray, Rg8, eImage );
	Writer_Image( I, SampledImageBuffer, Rg8, eSampledImage );
	Writer_Image( I, SampledImage1D, Rg8, eSampledImage );
	Writer_Image( I, SampledImage2D, Rg8, eSampledImage );
	Writer_Image( I, SampledImage3D, Rg8, eSampledImage );
	Writer_Image( I, SampledImage2DRect, Rg8, eSampledImage );
	Writer_Image( I, SampledImageCube, Rg8, eSampledImage );
	Writer_Image( I, SampledImage1DArray, Rg8, eSampledImage );
	Writer_Image( I, SampledImage2DArray, Rg8, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, Rg8, eSampledImage );
	Writer_Image( I, SampledImage2DMS, Rg8, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, Rg8, eSampledImage );
	Writer_Image( I, ImageBuffer, R32, eImage );
	Writer_Image( I, Image1D, R32, eImage );
	Writer_Image( I, Image2D, R32, eImage );
	Writer_Image( I, Image3D, R32, eImage );
	Writer_Image( I, Image2DRect, R32, eImage );
	Writer_Image( I, ImageCube, R32, eImage );
	Writer_Image( I, Image1DArray, R32, eImage );
	Writer_Image( I, Image2DArray, R32, eImage );
	Writer_Image( I, ImageCubeArray, R32, eImage );
	Writer_Image( I, Image2DMS, R32, eImage );
	Writer_Image( I, Image2DMSArray, R32, eImage );
	Writer_Image( I, SampledImageBuffer, R32, eSampledImage );
	Writer_Image( I, SampledImage1D, R32, eSampledImage );
	Writer_Image( I, SampledImage2D, R32, eSampledImage );
	Writer_Image( I, SampledImage3D, R32, eSampledImage );
	Writer_Image( I, SampledImage2DRect, R32, eSampledImage );
	Writer_Image( I, SampledImageCube, R32, eSampledImage );
	Writer_Image( I, SampledImage1DArray, R32, eSampledImage );
	Writer_Image( I, SampledImage2DArray, R32, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, R32, eSampledImage );
	Writer_Image( I, SampledImage2DMS, R32, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, R32, eSampledImage );
	Writer_Image( I, ImageBuffer, R16, eImage );
	Writer_Image( I, Image1D, R16, eImage );
	Writer_Image( I, Image2D, R16, eImage );
	Writer_Image( I, Image3D, R16, eImage );
	Writer_Image( I, Image2DRect, R16, eImage );
	Writer_Image( I, ImageCube, R16, eImage );
	Writer_Image( I, Image1DArray, R16, eImage );
	Writer_Image( I, Image2DArray, R16, eImage );
	Writer_Image( I, ImageCubeArray, R16, eImage );
	Writer_Image( I, Image2DMS, R16, eImage );
	Writer_Image( I, Image2DMSArray, R16, eImage );
	Writer_Image( I, SampledImageBuffer, R16, eSampledImage );
	Writer_Image( I, SampledImage1D, R16, eSampledImage );
	Writer_Image( I, SampledImage2D, R16, eSampledImage );
	Writer_Image( I, SampledImage3D, R16, eSampledImage );
	Writer_Image( I, SampledImage2DRect, R16, eSampledImage );
	Writer_Image( I, SampledImageCube, R16, eSampledImage );
	Writer_Image( I, SampledImage1DArray, R16, eSampledImage );
	Writer_Image( I, SampledImage2DArray, R16, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, R16, eSampledImage );
	Writer_Image( I, SampledImage2DMS, R16, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, R16, eSampledImage );
	Writer_Image( I, ImageBuffer, R8, eImage );
	Writer_Image( I, Image1D, R8, eImage );
	Writer_Image( I, Image2D, R8, eImage );
	Writer_Image( I, Image3D, R8, eImage );
	Writer_Image( I, Image2DRect, R8, eImage );
	Writer_Image( I, ImageCube, R8, eImage );
	Writer_Image( I, Image1DArray, R8, eImage );
	Writer_Image( I, Image2DArray, R8, eImage );
	Writer_Image( I, ImageCubeArray, R8, eImage );
	Writer_Image( I, Image2DMS, R8, eImage );
	Writer_Image( I, Image2DMSArray, R8, eImage );
	Writer_Image( I, SampledImageBuffer, R8, eSampledImage );
	Writer_Image( I, SampledImage1D, R8, eSampledImage );
	Writer_Image( I, SampledImage2D, R8, eSampledImage );
	Writer_Image( I, SampledImage3D, R8, eSampledImage );
	Writer_Image( I, SampledImage2DRect, R8, eSampledImage );
	Writer_Image( I, SampledImageCube, R8, eSampledImage );
	Writer_Image( I, SampledImage1DArray, R8, eSampledImage );
	Writer_Image( I, SampledImage2DArray, R8, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, R8, eSampledImage );
	Writer_Image( I, SampledImage2DMS, R8, eSampledImage );
	Writer_Image( I, SampledImage2DMSArray, R8, eSampledImage );
	Writer_Image( U, ImageBuffer, Rgba32, eImage );
	Writer_Image( U, Image1D, Rgba32, eImage );
	Writer_Image( U, Image2D, Rgba32, eImage );
	Writer_Image( U, Image3D, Rgba32, eImage );
	Writer_Image( U, Image2DRect, Rgba32, eImage );
	Writer_Image( U, ImageCube, Rgba32, eImage );
	Writer_Image( U, Image1DArray, Rgba32, eImage );
	Writer_Image( U, Image2DArray, Rgba32, eImage );
	Writer_Image( U, ImageCubeArray, Rgba32, eImage );
	Writer_Image( U, Image2DMS, Rgba32, eImage );
	Writer_Image( U, Image2DMSArray, Rgba32, eImage );
	Writer_Image( U, SampledImageBuffer, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage1D, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage2D, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage3D, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage2DRect, Rgba32, eSampledImage );
	Writer_Image( U, SampledImageCube, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage1DArray, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage2DArray, Rgba32, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage2DMS, Rgba32, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, Rgba32, eSampledImage );
	Writer_Image( U, ImageBuffer, Rgba16, eImage );
	Writer_Image( U, Image1D, Rgba16, eImage );
	Writer_Image( U, Image2D, Rgba16, eImage );
	Writer_Image( U, Image3D, Rgba16, eImage );
	Writer_Image( U, Image2DRect, Rgba16, eImage );
	Writer_Image( U, ImageCube, Rgba16, eImage );
	Writer_Image( U, Image1DArray, Rgba16, eImage );
	Writer_Image( U, Image2DArray, Rgba16, eImage );
	Writer_Image( U, ImageCubeArray, Rgba16, eImage );
	Writer_Image( U, Image2DMS, Rgba16, eImage );
	Writer_Image( U, Image2DMSArray, Rgba16, eImage );
	Writer_Image( U, SampledImageBuffer, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage1D, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage2D, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage3D, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage2DRect, Rgba16, eSampledImage );
	Writer_Image( U, SampledImageCube, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage1DArray, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage2DArray, Rgba16, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage2DMS, Rgba16, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, Rgba16, eSampledImage );
	Writer_Image( U, ImageBuffer, Rgba8, eImage );
	Writer_Image( U, Image1D, Rgba8, eImage );
	Writer_Image( U, Image2D, Rgba8, eImage );
	Writer_Image( U, Image3D, Rgba8, eImage );
	Writer_Image( U, Image2DRect, Rgba8, eImage );
	Writer_Image( U, ImageCube, Rgba8, eImage );
	Writer_Image( U, Image1DArray, Rgba8, eImage );
	Writer_Image( U, Image2DArray, Rgba8, eImage );
	Writer_Image( U, ImageCubeArray, Rgba8, eImage );
	Writer_Image( U, Image2DMS, Rgba8, eImage );
	Writer_Image( U, Image2DMSArray, Rgba8, eImage );
	Writer_Image( U, SampledImageBuffer, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage1D, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage2D, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage3D, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage2DRect, Rgba8, eSampledImage );
	Writer_Image( U, SampledImageCube, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage1DArray, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage2DArray, Rgba8, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage2DMS, Rgba8, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, Rgba8, eSampledImage );
	Writer_Image( U, ImageBuffer, Rg32, eImage );
	Writer_Image( U, Image1D, Rg32, eImage );
	Writer_Image( U, Image2D, Rg32, eImage );
	Writer_Image( U, Image3D, Rg32, eImage );
	Writer_Image( U, Image2DRect, Rg32, eImage );
	Writer_Image( U, ImageCube, Rg32, eImage );
	Writer_Image( U, Image1DArray, Rg32, eImage );
	Writer_Image( U, Image2DArray, Rg32, eImage );
	Writer_Image( U, ImageCubeArray, Rg32, eImage );
	Writer_Image( U, Image2DMS, Rg32, eImage );
	Writer_Image( U, Image2DMSArray, Rg32, eImage );
	Writer_Image( U, SampledImageBuffer, Rg32, eSampledImage );
	Writer_Image( U, SampledImage1D, Rg32, eSampledImage );
	Writer_Image( U, SampledImage2D, Rg32, eSampledImage );
	Writer_Image( U, SampledImage3D, Rg32, eSampledImage );
	Writer_Image( U, SampledImage2DRect, Rg32, eSampledImage );
	Writer_Image( U, SampledImageCube, Rg32, eSampledImage );
	Writer_Image( U, SampledImage1DArray, Rg32, eSampledImage );
	Writer_Image( U, SampledImage2DArray, Rg32, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, Rg32, eSampledImage );
	Writer_Image( U, SampledImage2DMS, Rg32, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, Rg32, eSampledImage );
	Writer_Image( U, ImageBuffer, Rg16, eImage );
	Writer_Image( U, Image1D, Rg16, eImage );
	Writer_Image( U, Image2D, Rg16, eImage );
	Writer_Image( U, Image3D, Rg16, eImage );
	Writer_Image( U, Image2DRect, Rg16, eImage );
	Writer_Image( U, ImageCube, Rg16, eImage );
	Writer_Image( U, Image1DArray, Rg16, eImage );
	Writer_Image( U, Image2DArray, Rg16, eImage );
	Writer_Image( U, ImageCubeArray, Rg16, eImage );
	Writer_Image( U, Image2DMS, Rg16, eImage );
	Writer_Image( U, Image2DMSArray, Rg16, eImage );
	Writer_Image( U, SampledImageBuffer, Rg16, eSampledImage );
	Writer_Image( U, SampledImage1D, Rg16, eSampledImage );
	Writer_Image( U, SampledImage2D, Rg16, eSampledImage );
	Writer_Image( U, SampledImage3D, Rg16, eSampledImage );
	Writer_Image( U, SampledImage2DRect, Rg16, eSampledImage );
	Writer_Image( U, SampledImageCube, Rg16, eSampledImage );
	Writer_Image( U, SampledImage1DArray, Rg16, eSampledImage );
	Writer_Image( U, SampledImage2DArray, Rg16, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, Rg16, eSampledImage );
	Writer_Image( U, SampledImage2DMS, Rg16, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, Rg16, eSampledImage );
	Writer_Image( U, ImageBuffer, Rg8, eImage );
	Writer_Image( U, Image1D, Rg8, eImage );
	Writer_Image( U, Image2D, Rg8, eImage );
	Writer_Image( U, Image3D, Rg8, eImage );
	Writer_Image( U, Image2DRect, Rg8, eImage );
	Writer_Image( U, ImageCube, Rg8, eImage );
	Writer_Image( U, Image1DArray, Rg8, eImage );
	Writer_Image( U, Image2DArray, Rg8, eImage );
	Writer_Image( U, ImageCubeArray, Rg8, eImage );
	Writer_Image( U, Image2DMS, Rg8, eImage );
	Writer_Image( U, Image2DMSArray, Rg8, eImage );
	Writer_Image( U, SampledImageBuffer, Rg8, eSampledImage );
	Writer_Image( U, SampledImage1D, Rg8, eSampledImage );
	Writer_Image( U, SampledImage2D, Rg8, eSampledImage );
	Writer_Image( U, SampledImage3D, Rg8, eSampledImage );
	Writer_Image( U, SampledImage2DRect, Rg8, eSampledImage );
	Writer_Image( U, SampledImageCube, Rg8, eSampledImage );
	Writer_Image( U, SampledImage1DArray, Rg8, eSampledImage );
	Writer_Image( U, SampledImage2DArray, Rg8, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, Rg8, eSampledImage );
	Writer_Image( U, SampledImage2DMS, Rg8, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, Rg8, eSampledImage );
	Writer_Image( U, ImageBuffer, R32, eImage );
	Writer_Image( U, Image1D, R32, eImage );
	Writer_Image( U, Image2D, R32, eImage );
	Writer_Image( U, Image3D, R32, eImage );
	Writer_Image( U, Image2DRect, R32, eImage );
	Writer_Image( U, ImageCube, R32, eImage );
	Writer_Image( U, Image1DArray, R32, eImage );
	Writer_Image( U, Image2DArray, R32, eImage );
	Writer_Image( U, ImageCubeArray, R32, eImage );
	Writer_Image( U, Image2DMS, R32, eImage );
	Writer_Image( U, Image2DMSArray, R32, eImage );
	Writer_Image( U, SampledImageBuffer, R32, eSampledImage );
	Writer_Image( U, SampledImage1D, R32, eSampledImage );
	Writer_Image( U, SampledImage2D, R32, eSampledImage );
	Writer_Image( U, SampledImage3D, R32, eSampledImage );
	Writer_Image( U, SampledImage2DRect, R32, eSampledImage );
	Writer_Image( U, SampledImageCube, R32, eSampledImage );
	Writer_Image( U, SampledImage1DArray, R32, eSampledImage );
	Writer_Image( U, SampledImage2DArray, R32, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, R32, eSampledImage );
	Writer_Image( U, SampledImage2DMS, R32, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, R32, eSampledImage );
	Writer_Image( U, ImageBuffer, R16, eImage );
	Writer_Image( U, Image1D, R16, eImage );
	Writer_Image( U, Image2D, R16, eImage );
	Writer_Image( U, Image3D, R16, eImage );
	Writer_Image( U, Image2DRect, R16, eImage );
	Writer_Image( U, ImageCube, R16, eImage );
	Writer_Image( U, Image1DArray, R16, eImage );
	Writer_Image( U, Image2DArray, R16, eImage );
	Writer_Image( U, ImageCubeArray, R16, eImage );
	Writer_Image( U, Image2DMS, R16, eImage );
	Writer_Image( U, Image2DMSArray, R16, eImage );
	Writer_Image( U, SampledImageBuffer, R16, eSampledImage );
	Writer_Image( U, SampledImage1D, R16, eSampledImage );
	Writer_Image( U, SampledImage2D, R16, eSampledImage );
	Writer_Image( U, SampledImage3D, R16, eSampledImage );
	Writer_Image( U, SampledImage2DRect, R16, eSampledImage );
	Writer_Image( U, SampledImageCube, R16, eSampledImage );
	Writer_Image( U, SampledImage1DArray, R16, eSampledImage );
	Writer_Image( U, SampledImage2DArray, R16, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, R16, eSampledImage );
	Writer_Image( U, SampledImage2DMS, R16, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, R16, eSampledImage );
	Writer_Image( U, ImageBuffer, R8, eImage );
	Writer_Image( U, Image1D, R8, eImage );
	Writer_Image( U, Image2D, R8, eImage );
	Writer_Image( U, Image3D, R8, eImage );
	Writer_Image( U, Image2DRect, R8, eImage );
	Writer_Image( U, ImageCube, R8, eImage );
	Writer_Image( U, Image1DArray, R8, eImage );
	Writer_Image( U, Image2DArray, R8, eImage );
	Writer_Image( U, ImageCubeArray, R8, eImage );
	Writer_Image( U, Image2DMS, R8, eImage );
	Writer_Image( U, Image2DMSArray, R8, eImage );
	Writer_Image( U, SampledImageBuffer, R8, eSampledImage );
	Writer_Image( U, SampledImage1D, R8, eSampledImage );
	Writer_Image( U, SampledImage2D, R8, eSampledImage );
	Writer_Image( U, SampledImage3D, R8, eSampledImage );
	Writer_Image( U, SampledImage2DRect, R8, eSampledImage );
	Writer_Image( U, SampledImageCube, R8, eSampledImage );
	Writer_Image( U, SampledImage1DArray, R8, eSampledImage );
	Writer_Image( U, SampledImage2DArray, R8, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, R8, eSampledImage );
	Writer_Image( U, SampledImage2DMS, R8, eSampledImage );
	Writer_Image( U, SampledImage2DMSArray, R8, eSampledImage );

#undef Writer_Image

	template< typename T >
	struct TypeTraits< InParam< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< Optional< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< OutParam< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	struct TypeTraits< InOutParam< T > >
	{
		static ast::type::Kind const TypeEnum = TypeTraits< T >::TypeEnum;
	};

	template< typename T >
	static ast::type::Kind constexpr typeEnum = TypeTraits< T >::TypeEnum;

	template< typename T >
	struct RealTypeGetter
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< InParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< Optional< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< OutParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	struct RealTypeGetter< InOutParam< T > >
	{
		using Type = T;
	};

	template< typename T >
	using RealType = typename RealTypeGetter< T >::Type;

	//***********************************************************************************************
}
