/*
See LICENSE file in root folder
*/
namespace sdw
{
	//***********************************************************************************************

	template<>
	struct SamplerTypeTraits< SamplerType::eBufferF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBufferF;
		using Type = SamplerBuffer;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DF;
		using Type = Sampler1D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DF;
		using Type = Sampler2D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e3DF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3DF;
		using Type = Sampler3D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeF;
		using Type = SamplerCube;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRectF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectF;
		using Type = Sampler2DRect;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DShadowF;
		using Type = Sampler1DShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DShadowF;
		using Type = Sampler2DShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeShadowF;
		using Type = SamplerCubeShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRectShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectShadowF;
		using Type = Sampler2DRectShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayF;
		using Type = Sampler1DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayF;
		using Type = Sampler2DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayF;
		using Type = SamplerCubeArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArrayShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayShadowF;
		using Type = Sampler1DArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArrayShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayShadowF;
		using Type = Sampler2DArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArrayShadowF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayShadowF;
		using Type = SamplerCubeArrayShadow;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eBufferI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBufferI;
		using Type = ISamplerBuffer;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DI;
		using Type = ISampler1D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DI;
		using Type = ISampler2D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e3DI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3DI;
		using Type = ISampler3D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeI;
		using Type = ISamplerCube;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRectI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectI;
		using Type = ISampler2DRect;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayI;
		using Type = ISampler1DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayI;
		using Type = ISampler2DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayI;
		using Type = ISamplerCubeArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eBufferU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBufferU;
		using Type = USamplerBuffer;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DU;
		using Type = USampler1D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DU;
		using Type = USampler2D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e3DU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3DU;
		using Type = USampler3D;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeU;
		using Type = USamplerCube;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DRectU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectU;
		using Type = USampler2DRect;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e1DArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayU;
		using Type = USampler1DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::e2DArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayU;
		using Type = USampler2DArray;
	};

	template<>
	struct SamplerTypeTraits< SamplerType::eCubeArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayU;
		using Type = USamplerCubeArray;
	};

	template< SamplerType ST >
	using SamplerTypeT = typename SamplerTypeTraits< ST >::Type;

	//***********************************************************************************************

	template<>
	struct ImageTypeTraits< ImageType::eBufferF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageBufferF;
		using Type = ImageBuffer;
	};

	template<>
	struct ImageTypeTraits< ImageType::e1DF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DF;
		using Type = Image1D;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DF;
		using Type = Image2D;
	};

	template<>
	struct ImageTypeTraits< ImageType::e3DF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage3DF;
		using Type = Image3D;
	};

	template<>
	struct ImageTypeTraits< ImageType::eCubeF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeF;
		using Type = ImageCube;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DRectF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DRectF;
		using Type = Image2DRect;
	};

	template<>
	struct ImageTypeTraits< ImageType::e1DArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DArrayF;
		using Type = Image1DArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DArrayF;
		using Type = Image2DArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::eCubeArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeArrayF;
		using Type = ImageCubeArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DMSF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSF;
		using Type = Image2DMS;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DMSArrayF >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSArrayF;
		using Type = Image2DMSArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::eBufferI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageBufferI;
		using Type = IImageBuffer;
	};

	template<>
	struct ImageTypeTraits< ImageType::e1DI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DI;
		using Type = IImage1D;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DI;
		using Type = IImage2D;
	};

	template<>
	struct ImageTypeTraits< ImageType::e3DI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage3DI;
		using Type = IImage3D;
	};

	template<>
	struct ImageTypeTraits< ImageType::eCubeI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeI;
		using Type = IImageCube;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DRectI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DRectI;
		using Type = IImage2DRect;
	};

	template<>
	struct ImageTypeTraits< ImageType::e1DArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DArrayI;
		using Type = IImage1DArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DArrayI;
		using Type = IImage2DArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::eCubeArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeArrayI;
		using Type = IImageCubeArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DMSI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSI;
		using Type = IImage2DMS;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DMSArrayI >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSArrayI;
		using Type = IImage2DMSArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::eBufferU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageBufferU;
		using Type = UImageBuffer;
	};

	template<>
	struct ImageTypeTraits< ImageType::e1DU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DU;
		using Type = UImage1D;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DU;
		using Type = UImage2D;
	};

	template<>
	struct ImageTypeTraits< ImageType::e3DU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage3DU;
		using Type = UImage3D;
	};

	template<>
	struct ImageTypeTraits< ImageType::eCubeU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeU;
		using Type = UImageCube;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DRectU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DRectU;
		using Type = UImage2DRect;
	};

	template<>
	struct ImageTypeTraits< ImageType::e1DArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DArrayU;
		using Type = UImage1DArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DArrayU;
		using Type = UImage2DArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::eCubeArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeArrayU;
		using Type = UImageCubeArray;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DMSU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSU;
		using Type = UImage2DMS;
	};

	template<>
	struct ImageTypeTraits< ImageType::e2DMSArrayU >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSArrayU;
		using Type = UImage2DMSArray;
	};

	template< ImageType ST >
	using ImageTypeT = typename ImageTypeTraits< ST >::Type;

	//***********************************************************************************************

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
	struct TypeTraits< SamplerBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBufferF;
	};

	template<>
	struct TypeTraits< Sampler1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DF;
	};

	template<>
	struct TypeTraits< Sampler2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DF;
	};

	template<>
	struct TypeTraits< Sampler3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3DF;
	};

	template<>
	struct TypeTraits< SamplerCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeF;
	};

	template<>
	struct TypeTraits< Sampler2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectF;
	};

	template<>
	struct TypeTraits< Sampler1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayF;
	};

	template<>
	struct TypeTraits< Sampler2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayF;
	};

	template<>
	struct TypeTraits< SamplerCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayF;
	};

	template<>
	struct TypeTraits< Sampler1DShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DShadowF;
	};

	template<>
	struct TypeTraits< Sampler2DShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DShadowF;
	};

	template<>
	struct TypeTraits< SamplerCubeShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeShadowF;
	};

	template<>
	struct TypeTraits< Sampler2DRectShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectShadowF;
	};

	template<>
	struct TypeTraits< Sampler1DArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayShadowF;
	};

	template<>
	struct TypeTraits< Sampler2DArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayShadowF;
	};

	template<>
	struct TypeTraits< SamplerCubeArrayShadow >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayShadowF;
	};

	template<>
	struct TypeTraits< ISamplerBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBufferI;
	};

	template<>
	struct TypeTraits< ISampler1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DI;
	};

	template<>
	struct TypeTraits< ISampler2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DI;
	};

	template<>
	struct TypeTraits< ISampler3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3DI;
	};

	template<>
	struct TypeTraits< ISamplerCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeI;
	};

	template<>
	struct TypeTraits< ISampler2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectI;
	};

	template<>
	struct TypeTraits< ISampler1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayI;
	};

	template<>
	struct TypeTraits< ISampler2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayI;
	};

	template<>
	struct TypeTraits< ISamplerCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayI;
	};

	template<>
	struct TypeTraits< USamplerBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerBufferU;
	};

	template<>
	struct TypeTraits< USampler1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DU;
	};

	template<>
	struct TypeTraits< USampler2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DU;
	};

	template<>
	struct TypeTraits< USampler3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler3DU;
	};

	template<>
	struct TypeTraits< USamplerCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeU;
	};

	template<>
	struct TypeTraits< USampler2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DRectU;
	};

	template<>
	struct TypeTraits< USampler1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler1DArrayU;
	};

	template<>
	struct TypeTraits< USampler2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSampler2DArrayU;
	};

	template<>
	struct TypeTraits< USamplerCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eSamplerCubeArrayU;
	};

	template<>
	struct TypeTraits< ImageBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageBufferF;
	};

	template<>
	struct TypeTraits< Image1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DF;
	};

	template<>
	struct TypeTraits< Image2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DF;
	};

	template<>
	struct TypeTraits< Image3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage3DF;
	};

	template<>
	struct TypeTraits< ImageCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeF;
	};

	template<>
	struct TypeTraits< Image2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DRectF;
	};

	template<>
	struct TypeTraits< Image1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DArrayF;
	};

	template<>
	struct TypeTraits< Image2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DArrayF;
	};

	template<>
	struct TypeTraits< ImageCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeArrayF;
	};

	template<>
	struct TypeTraits< Image2DMS >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSF;
	};

	template<>
	struct TypeTraits< Image2DMSArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSArrayF;
	};

	template<>
	struct TypeTraits< IImageBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageBufferI;
	};

	template<>
	struct TypeTraits< IImage1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DI;
	};

	template<>
	struct TypeTraits< IImage2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DI;
	};

	template<>
	struct TypeTraits< IImage3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage3DI;
	};

	template<>
	struct TypeTraits< IImageCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeI;
	};

	template<>
	struct TypeTraits< IImage2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DRectI;
	};

	template<>
	struct TypeTraits< IImage1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DArrayI;
	};

	template<>
	struct TypeTraits< IImage2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DArrayI;
	};

	template<>
	struct TypeTraits< IImageCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeArrayI;
	};

	template<>
	struct TypeTraits< IImage2DMS >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSI;
	};

	template<>
	struct TypeTraits< IImage2DMSArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSArrayI;
	};

	template<>
	struct TypeTraits< UImageBuffer >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageBufferU;
	};

	template<>
	struct TypeTraits< UImage1D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DU;
	};

	template<>
	struct TypeTraits< UImage2D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DU;
	};

	template<>
	struct TypeTraits< UImage3D >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage3DU;
	};

	template<>
	struct TypeTraits< UImageCube >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeU;
	};

	template<>
	struct TypeTraits< UImage2DRect >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DRectU;
	};

	template<>
	struct TypeTraits< UImage1DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage1DArrayU;
	};

	template<>
	struct TypeTraits< UImage2DArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DArrayU;
	};

	template<>
	struct TypeTraits< UImageCubeArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImageCubeArrayU;
	};

	template<>
	struct TypeTraits< UImage2DMS >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSU;
	};

	template<>
	struct TypeTraits< UImage2DMSArray >
	{
		static ast::type::Kind const TypeEnum = ast::type::Kind::eImage2DMSArrayU;
	};

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
