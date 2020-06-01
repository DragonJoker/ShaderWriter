/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	template<>
	struct TypeTraits< void >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVoid;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = void;
	};
	
	template<>
	struct TypeTraits< bool >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eBoolean;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< int32_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< uint32_t >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< float >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eFloat;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< double >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eDouble;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< Void >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVoid;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = void;
	};

	template<>
	struct TypeTraits< Boolean >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eBoolean;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eInt > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eUInt > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eInt > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eInt;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< IntegerValue< ast::type::Kind::eUInt > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eUInt;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eFloat > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eFloat;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< ArithmeticValue< ast::type::Kind::eDouble > >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eDouble;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< BVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2B;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< BVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3B;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< BVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4B;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = bool;
	};

	template<>
	struct TypeTraits< IVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2I;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< IVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3I;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< IVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4I;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = int32_t;
	};

	template<>
	struct TypeTraits< UVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2U;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< UVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3U;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< UVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4U;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = uint32_t;
	};

	template<>
	struct TypeTraits< Vec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2F;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Vec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3F;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Vec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4F;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< DVec2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec2D;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DVec3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec3D;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DVec4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eVec4D;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< Mat2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x2F;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat2x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x3F;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat2x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x4F;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x3F;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat3x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x2F;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat3x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x4F;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x4F;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat4x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x2F;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = float;
	};

	template<>
	struct TypeTraits< Mat4x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x3F;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = float;
	};

	template<>
	struct TypeTraits< DMat2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x2D;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat2x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x3D;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat2x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat2x4D;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x3D;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat3x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x2D;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat3x4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat3x4D;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat4 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x4D;
		static bool constexpr HasArithmeticOperators = true;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat4x2 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x2D;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = double;
	};

	template<>
	struct TypeTraits< DMat4x3 >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eMat4x3D;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = double;
	};

	template<>
	struct TypeTraits< StructInstance >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eStruct;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = void;
	};

	template<>
	struct TypeTraits< SampledImage >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eSampledImage;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = void;
	};

	template<>
	struct TypeTraits< Sampler >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eSampler;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = void;
	};

	template<>
	struct TypeTraits< Image >
	{
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::eImage;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = void;
	};

	template< typename T >
	struct TypeTraits< Array< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = false;
		using CppType = typename TypeTraits< T >::CppType;
	};

	template< typename T >
	struct TypeTraits< Optional< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
	};

	template< typename T >
	struct TypeTraits< MaybeOptional< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
	};

	template< typename T >
	struct TypeTraits< InParam< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
	};

	template< typename T >
	struct TypeTraits< OutParam< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
	};

	template< typename T >
	struct TypeTraits< InOutParam< T > >
	{
		static ast::type::Kind constexpr TypeEnum = TypeTraits< T >::TypeEnum;
		static bool constexpr HasArithmeticOperators = TypeTraits< T >::HasArithmeticOperators;
		using CppType = typename TypeTraits< T >::CppType;
	};

	//***********************************************************************************************

#define Writer_Image( Prefix, TypeName, Format, Value )\
	template<>\
	struct TypeTraits< R##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	};\
	template<>\
	struct TypeTraits< W##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	};\
	template<>\
	struct TypeTraits< RW##Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	}

#define Writer_SampledImage( Prefix, TypeName, Format, Value )\
	template<>\
	struct TypeTraits< Prefix##TypeName##Format >\
	{\
		static ast::type::Kind constexpr TypeEnum = ast::type::Kind::Value;\
	}

	Writer_Image( , ImageBuffer, Rgba32, eImage );
	Writer_Image( , Image1D, Rgba32, eImage );
	Writer_Image( , Image2D, Rgba32, eImage );
	Writer_Image( , Image3D, Rgba32, eImage );
	Writer_Image( , ImageCube, Rgba32, eImage );
	Writer_Image( , Image1DArray, Rgba32, eImage );
	Writer_Image( , Image2DArray, Rgba32, eImage );
	Writer_Image( , ImageCubeArray, Rgba32, eImage );
	Writer_Image( , Image2DMS, Rgba32, eImage );
	Writer_Image( , Image2DMSArray, Rgba32, eImage );
	Writer_SampledImage( , SampledImageBuffer, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage1D, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage2D, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage3D, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImageCube, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage1DArray, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage2DArray, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArray, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage2DMS, Rgba32, eSampledImage );
	Writer_SampledImage( , SampledImage2DMSArray, Rgba32, eSampledImage );
	Writer_Image( , ImageBuffer, Rgba16, eImage );
	Writer_Image( , Image1D, Rgba16, eImage );
	Writer_Image( , Image2D, Rgba16, eImage );
	Writer_Image( , Image3D, Rgba16, eImage );
	Writer_Image( , ImageCube, Rgba16, eImage );
	Writer_Image( , Image1DArray, Rgba16, eImage );
	Writer_Image( , Image2DArray, Rgba16, eImage );
	Writer_Image( , ImageCubeArray, Rgba16, eImage );
	Writer_Image( , Image2DMS, Rgba16, eImage );
	Writer_Image( , Image2DMSArray, Rgba16, eImage );
	Writer_SampledImage( , SampledImageBuffer, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage1D, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage2D, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage3D, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImageCube, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage1DArray, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage2DArray, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArray, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage2DMS, Rgba16, eSampledImage );
	Writer_SampledImage( , SampledImage2DMSArray, Rgba16, eSampledImage );
	Writer_Image( , ImageBuffer, Rg32, eImage );
	Writer_Image( , Image1D, Rg32, eImage );
	Writer_Image( , Image2D, Rg32, eImage );
	Writer_Image( , Image3D, Rg32, eImage );
	Writer_Image( , ImageCube, Rg32, eImage );
	Writer_Image( , Image1DArray, Rg32, eImage );
	Writer_Image( , Image2DArray, Rg32, eImage );
	Writer_Image( , ImageCubeArray, Rg32, eImage );
	Writer_Image( , Image2DMS, Rg32, eImage );
	Writer_Image( , Image2DMSArray, Rg32, eImage );
	Writer_SampledImage( , SampledImageBuffer, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage1D, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage2D, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage3D, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImageCube, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage1DArray, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage2DArray, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArray, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage2DMS, Rg32, eSampledImage );
	Writer_SampledImage( , SampledImage2DMSArray, Rg32, eSampledImage );
	Writer_Image( , ImageBuffer, Rg16, eImage );
	Writer_Image( , Image1D, Rg16, eImage );
	Writer_Image( , Image2D, Rg16, eImage );
	Writer_Image( , Image3D, Rg16, eImage );
	Writer_Image( , ImageCube, Rg16, eImage );
	Writer_Image( , Image1DArray, Rg16, eImage );
	Writer_Image( , Image2DArray, Rg16, eImage );
	Writer_Image( , ImageCubeArray, Rg16, eImage );
	Writer_Image( , Image2DMS, Rg16, eImage );
	Writer_Image( , Image2DMSArray, Rg16, eImage );
	Writer_SampledImage( , SampledImageBuffer, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage1D, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage2D, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage3D, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImageCube, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage1DArray, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage2DArray, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArray, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage2DMS, Rg16, eSampledImage );
	Writer_SampledImage( , SampledImage2DMSArray, Rg16, eSampledImage );
	Writer_Image( , ImageBuffer, R32, eImage );
	Writer_Image( , Image1D, R32, eImage );
	Writer_Image( , Image2D, R32, eImage );
	Writer_Image( , Image3D, R32, eImage );
	Writer_Image( , ImageCube, R32, eImage );
	Writer_Image( , Image1DArray, R32, eImage );
	Writer_Image( , Image2DArray, R32, eImage );
	Writer_Image( , ImageCubeArray, R32, eImage );
	Writer_Image( , Image2DMS, R32, eImage );
	Writer_Image( , Image2DMSArray, R32, eImage );
	Writer_SampledImage( , SampledImageBuffer, R32, eSampledImage );
	Writer_SampledImage( , SampledImage1D, R32, eSampledImage );
	Writer_SampledImage( , SampledImage2D, R32, eSampledImage );
	Writer_SampledImage( , SampledImage3D, R32, eSampledImage );
	Writer_SampledImage( , SampledImageCube, R32, eSampledImage );
	Writer_SampledImage( , SampledImage1DArray, R32, eSampledImage );
	Writer_SampledImage( , SampledImage2DArray, R32, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArray, R32, eSampledImage );
	Writer_SampledImage( , SampledImage2DMS, R32, eSampledImage );
	Writer_SampledImage( , SampledImage2DMSArray, R32, eSampledImage );
	Writer_Image( , ImageBuffer, R16, eImage );
	Writer_Image( , Image1D, R16, eImage );
	Writer_Image( , Image2D, R16, eImage );
	Writer_Image( , Image3D, R16, eImage );
	Writer_Image( , ImageCube, R16, eImage );
	Writer_Image( , Image1DArray, R16, eImage );
	Writer_Image( , Image2DArray, R16, eImage );
	Writer_Image( , ImageCubeArray, R16, eImage );
	Writer_Image( , Image2DMS, R16, eImage );
	Writer_Image( , Image2DMSArray, R16, eImage );
	Writer_SampledImage( , SampledImageBuffer, R16, eSampledImage );
	Writer_SampledImage( , SampledImage1D, R16, eSampledImage );
	Writer_SampledImage( , SampledImage2D, R16, eSampledImage );
	Writer_SampledImage( , SampledImage3D, R16, eSampledImage );
	Writer_SampledImage( , SampledImageCube, R16, eSampledImage );
	Writer_SampledImage( , SampledImage1DArray, R16, eSampledImage );
	Writer_SampledImage( , SampledImage2DArray, R16, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArray, R16, eSampledImage );
	Writer_SampledImage( , SampledImage2DMS, R16, eSampledImage );
	Writer_SampledImage( , SampledImage2DMSArray, R16, eSampledImage );
	Writer_SampledImage( , SampledImage1DShadow, R32, eSampledImage );
	Writer_SampledImage( , SampledImage2DShadow, R32, eSampledImage );
	Writer_SampledImage( , SampledImageCubeShadow, R32, eSampledImage );
	Writer_SampledImage( , SampledImage1DArrayShadow, R32, eSampledImage );
	Writer_SampledImage( , SampledImage2DArrayShadow, R32, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArrayShadow, R32, eSampledImage );
	Writer_SampledImage( , SampledImage1DShadow, R16, eSampledImage );
	Writer_SampledImage( , SampledImage2DShadow, R16, eSampledImage );
	Writer_SampledImage( , SampledImageCubeShadow, R16, eSampledImage );
	Writer_SampledImage( , SampledImage1DArrayShadow, R16, eSampledImage );
	Writer_SampledImage( , SampledImage2DArrayShadow, R16, eSampledImage );
	Writer_SampledImage( , SampledImageCubeArrayShadow, R16, eSampledImage );
	Writer_Image( I, ImageBuffer, Rgba32, eImage );
	Writer_Image( I, Image1D, Rgba32, eImage );
	Writer_Image( I, Image2D, Rgba32, eImage );
	Writer_Image( I, Image3D, Rgba32, eImage );
	Writer_Image( I, ImageCube, Rgba32, eImage );
	Writer_Image( I, Image1DArray, Rgba32, eImage );
	Writer_Image( I, Image2DArray, Rgba32, eImage );
	Writer_Image( I, ImageCubeArray, Rgba32, eImage );
	Writer_Image( I, Image2DMS, Rgba32, eImage );
	Writer_Image( I, Image2DMSArray, Rgba32, eImage );
	Writer_SampledImage( I, SampledImageBuffer, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, Rgba32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, Rgba32, eSampledImage );
	Writer_Image( I, ImageBuffer, Rgba16, eImage );
	Writer_Image( I, Image1D, Rgba16, eImage );
	Writer_Image( I, Image2D, Rgba16, eImage );
	Writer_Image( I, Image3D, Rgba16, eImage );
	Writer_Image( I, ImageCube, Rgba16, eImage );
	Writer_Image( I, Image1DArray, Rgba16, eImage );
	Writer_Image( I, Image2DArray, Rgba16, eImage );
	Writer_Image( I, ImageCubeArray, Rgba16, eImage );
	Writer_Image( I, Image2DMS, Rgba16, eImage );
	Writer_Image( I, Image2DMSArray, Rgba16, eImage );
	Writer_SampledImage( I, SampledImageBuffer, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, Rgba16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, Rgba16, eSampledImage );
	Writer_Image( I, ImageBuffer, Rgba8, eImage );
	Writer_Image( I, Image1D, Rgba8, eImage );
	Writer_Image( I, Image2D, Rgba8, eImage );
	Writer_Image( I, Image3D, Rgba8, eImage );
	Writer_Image( I, ImageCube, Rgba8, eImage );
	Writer_Image( I, Image1DArray, Rgba8, eImage );
	Writer_Image( I, Image2DArray, Rgba8, eImage );
	Writer_Image( I, ImageCubeArray, Rgba8, eImage );
	Writer_Image( I, Image2DMS, Rgba8, eImage );
	Writer_Image( I, Image2DMSArray, Rgba8, eImage );
	Writer_SampledImage( I, SampledImageBuffer, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, Rgba8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, Rgba8, eSampledImage );
	Writer_Image( I, ImageBuffer, Rg32, eImage );
	Writer_Image( I, Image1D, Rg32, eImage );
	Writer_Image( I, Image2D, Rg32, eImage );
	Writer_Image( I, Image3D, Rg32, eImage );
	Writer_Image( I, ImageCube, Rg32, eImage );
	Writer_Image( I, Image1DArray, Rg32, eImage );
	Writer_Image( I, Image2DArray, Rg32, eImage );
	Writer_Image( I, ImageCubeArray, Rg32, eImage );
	Writer_Image( I, Image2DMS, Rg32, eImage );
	Writer_Image( I, Image2DMSArray, Rg32, eImage );
	Writer_SampledImage( I, SampledImageBuffer, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, Rg32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, Rg32, eSampledImage );
	Writer_Image( I, ImageBuffer, Rg16, eImage );
	Writer_Image( I, Image1D, Rg16, eImage );
	Writer_Image( I, Image2D, Rg16, eImage );
	Writer_Image( I, Image3D, Rg16, eImage );
	Writer_Image( I, ImageCube, Rg16, eImage );
	Writer_Image( I, Image1DArray, Rg16, eImage );
	Writer_Image( I, Image2DArray, Rg16, eImage );
	Writer_Image( I, ImageCubeArray, Rg16, eImage );
	Writer_Image( I, Image2DMS, Rg16, eImage );
	Writer_Image( I, Image2DMSArray, Rg16, eImage );
	Writer_SampledImage( I, SampledImageBuffer, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, Rg16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, Rg16, eSampledImage );
	Writer_Image( I, ImageBuffer, Rg8, eImage );
	Writer_Image( I, Image1D, Rg8, eImage );
	Writer_Image( I, Image2D, Rg8, eImage );
	Writer_Image( I, Image3D, Rg8, eImage );
	Writer_Image( I, ImageCube, Rg8, eImage );
	Writer_Image( I, Image1DArray, Rg8, eImage );
	Writer_Image( I, Image2DArray, Rg8, eImage );
	Writer_Image( I, ImageCubeArray, Rg8, eImage );
	Writer_Image( I, Image2DMS, Rg8, eImage );
	Writer_Image( I, Image2DMSArray, Rg8, eImage );
	Writer_SampledImage( I, SampledImageBuffer, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, Rg8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, Rg8, eSampledImage );
	Writer_Image( I, ImageBuffer, R32, eImage );
	Writer_Image( I, Image1D, R32, eImage );
	Writer_Image( I, Image2D, R32, eImage );
	Writer_Image( I, Image3D, R32, eImage );
	Writer_Image( I, ImageCube, R32, eImage );
	Writer_Image( I, Image1DArray, R32, eImage );
	Writer_Image( I, Image2DArray, R32, eImage );
	Writer_Image( I, ImageCubeArray, R32, eImage );
	Writer_Image( I, Image2DMS, R32, eImage );
	Writer_Image( I, Image2DMSArray, R32, eImage );
	Writer_SampledImage( I, SampledImageBuffer, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, R32, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, R32, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, R32, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, R32, eSampledImage );
	Writer_Image( I, ImageBuffer, R16, eImage );
	Writer_Image( I, Image1D, R16, eImage );
	Writer_Image( I, Image2D, R16, eImage );
	Writer_Image( I, Image3D, R16, eImage );
	Writer_Image( I, ImageCube, R16, eImage );
	Writer_Image( I, Image1DArray, R16, eImage );
	Writer_Image( I, Image2DArray, R16, eImage );
	Writer_Image( I, ImageCubeArray, R16, eImage );
	Writer_Image( I, Image2DMS, R16, eImage );
	Writer_Image( I, Image2DMSArray, R16, eImage );
	Writer_SampledImage( I, SampledImageBuffer, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, R16, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, R16, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, R16, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, R16, eSampledImage );
	Writer_Image( I, ImageBuffer, R8, eImage );
	Writer_Image( I, Image1D, R8, eImage );
	Writer_Image( I, Image2D, R8, eImage );
	Writer_Image( I, Image3D, R8, eImage );
	Writer_Image( I, ImageCube, R8, eImage );
	Writer_Image( I, Image1DArray, R8, eImage );
	Writer_Image( I, Image2DArray, R8, eImage );
	Writer_Image( I, ImageCubeArray, R8, eImage );
	Writer_Image( I, Image2DMS, R8, eImage );
	Writer_Image( I, Image2DMSArray, R8, eImage );
	Writer_SampledImage( I, SampledImageBuffer, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage1D, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage2D, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage3D, R8, eSampledImage );
	Writer_SampledImage( I, SampledImageCube, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage1DArray, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DArray, R8, eSampledImage );
	Writer_SampledImage( I, SampledImageCubeArray, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMS, R8, eSampledImage );
	Writer_SampledImage( I, SampledImage2DMSArray, R8, eSampledImage );
	Writer_Image( U, ImageBuffer, Rgba32, eImage );
	Writer_Image( U, Image1D, Rgba32, eImage );
	Writer_Image( U, Image2D, Rgba32, eImage );
	Writer_Image( U, Image3D, Rgba32, eImage );
	Writer_Image( U, ImageCube, Rgba32, eImage );
	Writer_Image( U, Image1DArray, Rgba32, eImage );
	Writer_Image( U, Image2DArray, Rgba32, eImage );
	Writer_Image( U, ImageCubeArray, Rgba32, eImage );
	Writer_Image( U, Image2DMS, Rgba32, eImage );
	Writer_Image( U, Image2DMSArray, Rgba32, eImage );
	Writer_SampledImage( U, SampledImageBuffer, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, Rgba32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, Rgba32, eSampledImage );
	Writer_Image( U, ImageBuffer, Rgba16, eImage );
	Writer_Image( U, Image1D, Rgba16, eImage );
	Writer_Image( U, Image2D, Rgba16, eImage );
	Writer_Image( U, Image3D, Rgba16, eImage );
	Writer_Image( U, ImageCube, Rgba16, eImage );
	Writer_Image( U, Image1DArray, Rgba16, eImage );
	Writer_Image( U, Image2DArray, Rgba16, eImage );
	Writer_Image( U, ImageCubeArray, Rgba16, eImage );
	Writer_Image( U, Image2DMS, Rgba16, eImage );
	Writer_Image( U, Image2DMSArray, Rgba16, eImage );
	Writer_SampledImage( U, SampledImageBuffer, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, Rgba16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, Rgba16, eSampledImage );
	Writer_Image( U, ImageBuffer, Rgba8, eImage );
	Writer_Image( U, Image1D, Rgba8, eImage );
	Writer_Image( U, Image2D, Rgba8, eImage );
	Writer_Image( U, Image3D, Rgba8, eImage );
	Writer_Image( U, ImageCube, Rgba8, eImage );
	Writer_Image( U, Image1DArray, Rgba8, eImage );
	Writer_Image( U, Image2DArray, Rgba8, eImage );
	Writer_Image( U, ImageCubeArray, Rgba8, eImage );
	Writer_Image( U, Image2DMS, Rgba8, eImage );
	Writer_Image( U, Image2DMSArray, Rgba8, eImage );
	Writer_SampledImage( U, SampledImageBuffer, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, Rgba8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, Rgba8, eSampledImage );
	Writer_Image( U, ImageBuffer, Rg32, eImage );
	Writer_Image( U, Image1D, Rg32, eImage );
	Writer_Image( U, Image2D, Rg32, eImage );
	Writer_Image( U, Image3D, Rg32, eImage );
	Writer_Image( U, ImageCube, Rg32, eImage );
	Writer_Image( U, Image1DArray, Rg32, eImage );
	Writer_Image( U, Image2DArray, Rg32, eImage );
	Writer_Image( U, ImageCubeArray, Rg32, eImage );
	Writer_Image( U, Image2DMS, Rg32, eImage );
	Writer_Image( U, Image2DMSArray, Rg32, eImage );
	Writer_SampledImage( U, SampledImageBuffer, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, Rg32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, Rg32, eSampledImage );
	Writer_Image( U, ImageBuffer, Rg16, eImage );
	Writer_Image( U, Image1D, Rg16, eImage );
	Writer_Image( U, Image2D, Rg16, eImage );
	Writer_Image( U, Image3D, Rg16, eImage );
	Writer_Image( U, ImageCube, Rg16, eImage );
	Writer_Image( U, Image1DArray, Rg16, eImage );
	Writer_Image( U, Image2DArray, Rg16, eImage );
	Writer_Image( U, ImageCubeArray, Rg16, eImage );
	Writer_Image( U, Image2DMS, Rg16, eImage );
	Writer_Image( U, Image2DMSArray, Rg16, eImage );
	Writer_SampledImage( U, SampledImageBuffer, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, Rg16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, Rg16, eSampledImage );
	Writer_Image( U, ImageBuffer, Rg8, eImage );
	Writer_Image( U, Image1D, Rg8, eImage );
	Writer_Image( U, Image2D, Rg8, eImage );
	Writer_Image( U, Image3D, Rg8, eImage );
	Writer_Image( U, ImageCube, Rg8, eImage );
	Writer_Image( U, Image1DArray, Rg8, eImage );
	Writer_Image( U, Image2DArray, Rg8, eImage );
	Writer_Image( U, ImageCubeArray, Rg8, eImage );
	Writer_Image( U, Image2DMS, Rg8, eImage );
	Writer_Image( U, Image2DMSArray, Rg8, eImage );
	Writer_SampledImage( U, SampledImageBuffer, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, Rg8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, Rg8, eSampledImage );
	Writer_Image( U, ImageBuffer, R32, eImage );
	Writer_Image( U, Image1D, R32, eImage );
	Writer_Image( U, Image2D, R32, eImage );
	Writer_Image( U, Image3D, R32, eImage );
	Writer_Image( U, ImageCube, R32, eImage );
	Writer_Image( U, Image1DArray, R32, eImage );
	Writer_Image( U, Image2DArray, R32, eImage );
	Writer_Image( U, ImageCubeArray, R32, eImage );
	Writer_Image( U, Image2DMS, R32, eImage );
	Writer_Image( U, Image2DMSArray, R32, eImage );
	Writer_SampledImage( U, SampledImageBuffer, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, R32, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, R32, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, R32, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, R32, eSampledImage );
	Writer_Image( U, ImageBuffer, R16, eImage );
	Writer_Image( U, Image1D, R16, eImage );
	Writer_Image( U, Image2D, R16, eImage );
	Writer_Image( U, Image3D, R16, eImage );
	Writer_Image( U, ImageCube, R16, eImage );
	Writer_Image( U, Image1DArray, R16, eImage );
	Writer_Image( U, Image2DArray, R16, eImage );
	Writer_Image( U, ImageCubeArray, R16, eImage );
	Writer_Image( U, Image2DMS, R16, eImage );
	Writer_Image( U, Image2DMSArray, R16, eImage );
	Writer_SampledImage( U, SampledImageBuffer, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, R16, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, R16, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, R16, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, R16, eSampledImage );
	Writer_Image( U, ImageBuffer, R8, eImage );
	Writer_Image( U, Image1D, R8, eImage );
	Writer_Image( U, Image2D, R8, eImage );
	Writer_Image( U, Image3D, R8, eImage );
	Writer_Image( U, ImageCube, R8, eImage );
	Writer_Image( U, Image1DArray, R8, eImage );
	Writer_Image( U, Image2DArray, R8, eImage );
	Writer_Image( U, ImageCubeArray, R8, eImage );
	Writer_Image( U, Image2DMS, R8, eImage );
	Writer_Image( U, Image2DMSArray, R8, eImage );
	Writer_SampledImage( U, SampledImageBuffer, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage1D, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage2D, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage3D, R8, eSampledImage );
	Writer_SampledImage( U, SampledImageCube, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage1DArray, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DArray, R8, eSampledImage );
	Writer_SampledImage( U, SampledImageCubeArray, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMS, R8, eSampledImage );
	Writer_SampledImage( U, SampledImage2DMSArray, R8, eSampledImage );

#undef Writer_SampledImage
#undef Writer_Image

	//***********************************************************************************************

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
	struct RealTypeGetter< MaybeOptional< T > >
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

	//***********************************************************************************************
}
