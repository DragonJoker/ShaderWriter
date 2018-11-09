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

#define Writer_Image( Prefix, TypeName, Sampled, Value )\
	template<>\
	struct TypeTraits< Prefix##TypeName >\
	{\
		static ast::type::Kind const TypeEnum = ast::type::Kind::Value;\
	}

	Writer_Image( , ImageBuffer, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image1D, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2D, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image3D, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DRect, ast::type::Kind::eFloat, eImage );
	Writer_Image( , ImageCube, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image1DArray, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DArray, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DRectArray, ast::type::Kind::eFloat, eImage );
	Writer_Image( , ImageCubeArray, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image1DShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DRectShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , ImageCubeShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image1DArrayShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DArrayShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , ImageCubeArrayShadow, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DMS, ast::type::Kind::eFloat, eImage );
	Writer_Image( , Image2DMSArray, ast::type::Kind::eFloat, eImage );
	Writer_Image( , SampledImageBuffer, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage1D, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2D, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage3D, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2DRect, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImageCube, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage1DArray, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2DArray, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2DRectArray, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImageCubeArray, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage1DShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2DShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2DRectShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImageCubeShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage1DArrayShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImage2DArrayShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( , SampledImageCubeArrayShadow, ast::type::Kind::eFloat, eSampledImage );
	Writer_Image( I, ImageBuffer, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image1D, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2D, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image3D, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DRect, ast::type::Kind::eInt, eImage );
	Writer_Image( I, ImageCube, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image1DArray, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DArray, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DRectArray, ast::type::Kind::eInt, eImage );
	Writer_Image( I, ImageCubeArray, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image1DShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DRectShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, ImageCubeShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image1DArrayShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DArrayShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, ImageCubeArrayShadow, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DMS, ast::type::Kind::eInt, eImage );
	Writer_Image( I, Image2DMSArray, ast::type::Kind::eInt, eImage );
	Writer_Image( I, SampledImageBuffer, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage1D, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2D, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage3D, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2DRect, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImageCube, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage1DArray, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2DArray, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2DRectArray, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImageCubeArray, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage1DShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2DShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2DRectShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImageCubeShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage1DArrayShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImage2DArrayShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( I, SampledImageCubeArrayShadow, ast::type::Kind::eInt, eSampledImage );
	Writer_Image( U, ImageBuffer, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image1D, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2D, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image3D, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DRect, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, ImageCube, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image1DArray, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DArray, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DRectArray, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, ImageCubeArray, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image1DShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DRectShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, ImageCubeShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image1DArrayShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DArrayShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, ImageCubeArrayShadow, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DMS, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, Image2DMSArray, ast::type::Kind::eUInt, eImage );
	Writer_Image( U, SampledImageBuffer, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage1D, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2D, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage3D, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2DRect, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImageCube, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage1DArray, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2DArray, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2DRectArray, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImageCubeArray, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage1DShadow, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2DShadow, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2DRectShadow, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImageCubeShadow, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage1DArrayShadow, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImage2DArrayShadow, ast::type::Kind::eUInt, eSampledImage );
	Writer_Image( U, SampledImageCubeArrayShadow, ast::type::Kind::eUInt, eSampledImage );

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

	//***********************************************************************************************
}
