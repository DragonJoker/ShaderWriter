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

#define Writer_Image( TypeName, Format, Value )\
	template<>\
	struct TypeTraits< TypeName##Format >\
	{\
		static ast::type::Kind const TypeEnum = ast::type::Kind::Value;\
	}

#define Writer_Images( Format )\
	Writer_Image( ImageBuffer, Format, eImage );\
	Writer_Image( Image1D, Format, eImage );\
	Writer_Image( Image2D, Format, eImage );\
	Writer_Image( Image3D, Format, eImage );\
	Writer_Image( ImageCube, Format, eImage );\
	Writer_Image( Image2DRect, Format, eImage );\
	Writer_Image( Image1DArray, Format, eImage );\
	Writer_Image( Image2DArray, Format, eImage );\
	Writer_Image( ImageCubeArray, Format, eImage );\
	Writer_Image( Image1DShadow, Format, eImage );\
	Writer_Image( Image2DShadow, Format, eImage );\
	Writer_Image( ImageCubeShadow, Format, eImage );\
	Writer_Image( Image2DRectShadow, Format, eImage );\
	Writer_Image( Image1DArrayShadow, Format, eImage );\
	Writer_Image( Image2DArrayShadow, Format, eImage );\
	Writer_Image( ImageCubeArrayShadow, Format, eImage );\
	Writer_Image( Image2DMS, Format, eImage );\
	Writer_Image( Image2DMSArray, Format, eImage );\
	Writer_Image( SampledImage1D, Format, eSampledImage );\
	Writer_Image( SampledImage2D, Format, eSampledImage );\
	Writer_Image( SampledImage3D, Format, eSampledImage );\
	Writer_Image( SampledImageCube, Format, eSampledImage );\
	Writer_Image( SampledImage1DArray, Format, eSampledImage );\
	Writer_Image( SampledImage2DArray, Format, eSampledImage );\
	Writer_Image( SampledImageCubeArray, Format, eSampledImage );\
	Writer_Image( SampledImage1DShadow, Format, eSampledImage );\
	Writer_Image( SampledImage2DShadow, Format, eSampledImage );\
	Writer_Image( SampledImageCubeShadow, Format, eSampledImage );\
	Writer_Image( SampledImage1DArrayShadow, Format, eSampledImage );\
	Writer_Image( SampledImage2DArrayShadow, Format, eSampledImage );\
	Writer_Image( SampledImageCubeArrayShadow, Format, eSampledImage )

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
	Writer_Images( Rg8u );
	Writer_Images( R32u );
	Writer_Images( R16u );
	Writer_Images( R8u );

#undef Writer_Images
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
