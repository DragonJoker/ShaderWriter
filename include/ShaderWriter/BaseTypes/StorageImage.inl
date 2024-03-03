/*
See LICENSE file in root folder
*/
#include <ShaderAST/Expr/EnumStorageImageAccess.hpp>
#include <ShaderAST/Expr/ExprStorageImageAccessCall.hpp>

#include <array>

namespace sdw
{
	//*****************************************************************************************

	namespace storageImg
	{
		size_t constexpr ImgDimBaseCount = size_t( type::ImageDim::eBuffer ) + 1u;
		size_t constexpr ArrayImgCount = 3u;
		size_t constexpr NonMsImgCount = ImgDimBaseCount + ArrayImgCount;
		size_t constexpr MsImgCount = 2u;
		using StorateImageAccessIntrList = std::array< expr::StorageImageAccess, NonMsImgCount + MsImgCount >;

		template< type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		constexpr size_t getImgArrayIndex()
		{
			if constexpr ( MsT )
			{
				return NonMsImgCount
					+ ( ArrayedT ? 1u : 0u );
			}
			else if constexpr ( ArrayedT )
			{
				if constexpr ( DimT == type::ImageDim::e1D )
				{
					return ImgDimBaseCount + 0u;
				}
				else if constexpr ( DimT == type::ImageDim::e2D )
				{
					return ImgDimBaseCount + 1u;
				}
				else if constexpr ( DimT == type::ImageDim::eCube )
				{
					return ImgDimBaseCount + 2u;
				}
				else
				{
					assert( false );
					return size_t( expr::StorageImageAccess::eInvalid );
				}
			}
			else
			{
				return size_t( DimT );
			}
		}

		static constexpr StorateImageAccessIntrList imageSizeF
		{
			expr::StorageImageAccess::eImageSize1DF,
			expr::StorageImageAccess::eImageSize2DF,
			expr::StorageImageAccess::eImageSize3DF,
			expr::StorageImageAccess::eImageSizeCubeF,
			expr::StorageImageAccess::eImageSizeBufferF,

			expr::StorageImageAccess::eImageSize1DArrayF,
			expr::StorageImageAccess::eImageSize2DArrayF,
			expr::StorageImageAccess::eImageSizeCubeArrayF,

			expr::StorageImageAccess::eImageSize2DMSF,
			expr::StorageImageAccess::eImageSize2DMSArrayF,
		};
		static constexpr StorateImageAccessIntrList imageSamplesF
		{
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,

			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,

			expr::StorageImageAccess::eImageSamples2DMSF,
			expr::StorageImageAccess::eImageSamples2DMSArrayF,
		};
		static constexpr StorateImageAccessIntrList imageLoadF
		{
			expr::StorageImageAccess::eImageLoad1DF,
			expr::StorageImageAccess::eImageLoad2DF,
			expr::StorageImageAccess::eImageLoad3DF,
			expr::StorageImageAccess::eImageLoadCubeF,
			expr::StorageImageAccess::eImageLoadBufferF,

			expr::StorageImageAccess::eImageLoad1DArrayF,
			expr::StorageImageAccess::eImageLoad2DArrayF,
			expr::StorageImageAccess::eImageLoadCubeArrayF,

			expr::StorageImageAccess::eImageLoad2DMSF,
			expr::StorageImageAccess::eImageLoad2DMSArrayF,
		};
		static constexpr StorateImageAccessIntrList imageStoreF
		{
			expr::StorageImageAccess::eImageStore1DF,
			expr::StorageImageAccess::eImageStore2DF,
			expr::StorageImageAccess::eImageStore3DF,
			expr::StorageImageAccess::eImageStoreCubeF,
			expr::StorageImageAccess::eImageStoreBufferF,

			expr::StorageImageAccess::eImageStore1DArrayF,
			expr::StorageImageAccess::eImageStore2DArrayF,
			expr::StorageImageAccess::eImageStoreCubeArrayF,

			expr::StorageImageAccess::eImageStore2DMSF,
			expr::StorageImageAccess::eImageStore2DMSArrayF,
		};
		static constexpr StorateImageAccessIntrList imageAtomicAddF
		{
			expr::StorageImageAccess::eImageAtomicAdd1DF,
			expr::StorageImageAccess::eImageAtomicAdd2DF,
			expr::StorageImageAccess::eImageAtomicAdd3DF,
			expr::StorageImageAccess::eImageAtomicAddCubeF,
			expr::StorageImageAccess::eImageAtomicAddBufferF,

			expr::StorageImageAccess::eImageAtomicAdd1DArrayF,
			expr::StorageImageAccess::eImageAtomicAdd2DArrayF,
			expr::StorageImageAccess::eImageAtomicAddCubeArrayF,

			expr::StorageImageAccess::eImageAtomicAdd2DMSF,
			expr::StorageImageAccess::eImageAtomicAdd2DMSArrayF,
		};
		static constexpr StorateImageAccessIntrList imageAtomicExchangeF
		{
			expr::StorageImageAccess::eImageAtomicExchange1DF,
			expr::StorageImageAccess::eImageAtomicExchange2DF,
			expr::StorageImageAccess::eImageAtomicExchange3DF,
			expr::StorageImageAccess::eImageAtomicExchangeCubeF,
			expr::StorageImageAccess::eImageAtomicExchangeBufferF,

			expr::StorageImageAccess::eImageAtomicExchange1DArrayF,
			expr::StorageImageAccess::eImageAtomicExchange2DArrayF,
			expr::StorageImageAccess::eImageAtomicExchangeCubeArrayF,

			expr::StorageImageAccess::eImageAtomicExchange2DMSF,
			expr::StorageImageAccess::eImageAtomicExchange2DMSArrayF,
		};

		static constexpr StorateImageAccessIntrList imageSizeI
		{
			expr::StorageImageAccess::eImageSize1DI,
			expr::StorageImageAccess::eImageSize2DI,
			expr::StorageImageAccess::eImageSize3DI,
			expr::StorageImageAccess::eImageSizeCubeI,
			expr::StorageImageAccess::eImageSizeBufferI,

			expr::StorageImageAccess::eImageSize1DArrayI,
			expr::StorageImageAccess::eImageSize2DArrayI,
			expr::StorageImageAccess::eImageSizeCubeArrayI,

			expr::StorageImageAccess::eImageSize2DMSI,
			expr::StorageImageAccess::eImageSize2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageSamplesI
		{
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,

			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,

			expr::StorageImageAccess::eImageSamples2DMSI,
			expr::StorageImageAccess::eImageSamples2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageLoadI
		{
			expr::StorageImageAccess::eImageLoad1DI,
			expr::StorageImageAccess::eImageLoad2DI,
			expr::StorageImageAccess::eImageLoad3DI,
			expr::StorageImageAccess::eImageLoadCubeI,
			expr::StorageImageAccess::eImageLoadBufferI,

			expr::StorageImageAccess::eImageLoad1DArrayI,
			expr::StorageImageAccess::eImageLoad2DArrayI,
			expr::StorageImageAccess::eImageLoadCubeArrayI,

			expr::StorageImageAccess::eImageLoad2DMSI,
			expr::StorageImageAccess::eImageLoad2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageStoreI
		{
			expr::StorageImageAccess::eImageStore1DI,
			expr::StorageImageAccess::eImageStore2DI,
			expr::StorageImageAccess::eImageStore3DI,
			expr::StorageImageAccess::eImageStoreCubeI,
			expr::StorageImageAccess::eImageStoreBufferI,

			expr::StorageImageAccess::eImageStore1DArrayI,
			expr::StorageImageAccess::eImageStore2DArrayI,
			expr::StorageImageAccess::eImageStoreCubeArrayI,

			expr::StorageImageAccess::eImageStore2DMSI,
			expr::StorageImageAccess::eImageStore2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicAddI
		{
			expr::StorageImageAccess::eImageAtomicAdd1DI,
			expr::StorageImageAccess::eImageAtomicAdd2DI,
			expr::StorageImageAccess::eImageAtomicAdd3DI,
			expr::StorageImageAccess::eImageAtomicAddCubeI,
			expr::StorageImageAccess::eImageAtomicAddBufferI,

			expr::StorageImageAccess::eImageAtomicAdd1DArrayI,
			expr::StorageImageAccess::eImageAtomicAdd2DArrayI,
			expr::StorageImageAccess::eImageAtomicAddCubeArrayI,

			expr::StorageImageAccess::eImageAtomicAdd2DMSI,
			expr::StorageImageAccess::eImageAtomicAdd2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicMinI
		{
			expr::StorageImageAccess::eImageAtomicMin1DI,
			expr::StorageImageAccess::eImageAtomicMin2DI,
			expr::StorageImageAccess::eImageAtomicMin3DI,
			expr::StorageImageAccess::eImageAtomicMinCubeI,
			expr::StorageImageAccess::eImageAtomicMinBufferI,

			expr::StorageImageAccess::eImageAtomicMin1DArrayI,
			expr::StorageImageAccess::eImageAtomicMin2DArrayI,
			expr::StorageImageAccess::eImageAtomicMinCubeArrayI,

			expr::StorageImageAccess::eImageAtomicMin2DMSI,
			expr::StorageImageAccess::eImageAtomicMin2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicMaxI
		{
			expr::StorageImageAccess::eImageAtomicMax1DI,
			expr::StorageImageAccess::eImageAtomicMax2DI,
			expr::StorageImageAccess::eImageAtomicMax3DI,
			expr::StorageImageAccess::eImageAtomicMaxCubeI,
			expr::StorageImageAccess::eImageAtomicMaxBufferI,

			expr::StorageImageAccess::eImageAtomicMax1DArrayI,
			expr::StorageImageAccess::eImageAtomicMax2DArrayI,
			expr::StorageImageAccess::eImageAtomicMaxCubeArrayI,

			expr::StorageImageAccess::eImageAtomicMax2DMSI,
			expr::StorageImageAccess::eImageAtomicMax2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicAndI
		{
			expr::StorageImageAccess::eImageAtomicAnd1DI,
			expr::StorageImageAccess::eImageAtomicAnd2DI,
			expr::StorageImageAccess::eImageAtomicAnd3DI,
			expr::StorageImageAccess::eImageAtomicAndCubeI,
			expr::StorageImageAccess::eImageAtomicAndBufferI,

			expr::StorageImageAccess::eImageAtomicAnd1DArrayI,
			expr::StorageImageAccess::eImageAtomicAnd2DArrayI,
			expr::StorageImageAccess::eImageAtomicAndCubeArrayI,

			expr::StorageImageAccess::eImageAtomicAnd2DMSI,
			expr::StorageImageAccess::eImageAtomicAnd2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicOrI
		{
			expr::StorageImageAccess::eImageAtomicOr1DI,
			expr::StorageImageAccess::eImageAtomicOr2DI,
			expr::StorageImageAccess::eImageAtomicOr3DI,
			expr::StorageImageAccess::eImageAtomicOrCubeI,
			expr::StorageImageAccess::eImageAtomicOrBufferI,

			expr::StorageImageAccess::eImageAtomicOr1DArrayI,
			expr::StorageImageAccess::eImageAtomicOr2DArrayI,
			expr::StorageImageAccess::eImageAtomicOrCubeArrayI,

			expr::StorageImageAccess::eImageAtomicOr2DMSI,
			expr::StorageImageAccess::eImageAtomicOr2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicXorI
		{
			expr::StorageImageAccess::eImageAtomicXor1DI,
			expr::StorageImageAccess::eImageAtomicXor2DI,
			expr::StorageImageAccess::eImageAtomicXor3DI,
			expr::StorageImageAccess::eImageAtomicXorCubeI,
			expr::StorageImageAccess::eImageAtomicXorBufferI,

			expr::StorageImageAccess::eImageAtomicXor1DArrayI,
			expr::StorageImageAccess::eImageAtomicXor2DArrayI,
			expr::StorageImageAccess::eImageAtomicXorCubeArrayI,

			expr::StorageImageAccess::eImageAtomicXor2DMSI,
			expr::StorageImageAccess::eImageAtomicXor2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicExchangeI
		{
			expr::StorageImageAccess::eImageAtomicExchange1DI,
			expr::StorageImageAccess::eImageAtomicExchange2DI,
			expr::StorageImageAccess::eImageAtomicExchange3DI,
			expr::StorageImageAccess::eImageAtomicExchangeCubeI,
			expr::StorageImageAccess::eImageAtomicExchangeBufferI,

			expr::StorageImageAccess::eImageAtomicExchange1DArrayI,
			expr::StorageImageAccess::eImageAtomicExchange2DArrayI,
			expr::StorageImageAccess::eImageAtomicExchangeCubeArrayI,

			expr::StorageImageAccess::eImageAtomicExchange2DMSI,
			expr::StorageImageAccess::eImageAtomicExchange2DMSArrayI,
		};
		static constexpr StorateImageAccessIntrList imageAtomicCompSwapI
		{
			expr::StorageImageAccess::eImageAtomicCompSwap1DI,
			expr::StorageImageAccess::eImageAtomicCompSwap2DI,
			expr::StorageImageAccess::eImageAtomicCompSwap3DI,
			expr::StorageImageAccess::eImageAtomicCompSwapCubeI,
			expr::StorageImageAccess::eImageAtomicCompSwapBufferI,

			expr::StorageImageAccess::eImageAtomicCompSwap1DArrayI,
			expr::StorageImageAccess::eImageAtomicCompSwap2DArrayI,
			expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayI,

			expr::StorageImageAccess::eImageAtomicCompSwap2DMSI,
			expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayI,
		};

		static constexpr StorateImageAccessIntrList imageSizeU
		{
			expr::StorageImageAccess::eImageSize1DU,
			expr::StorageImageAccess::eImageSize2DU,
			expr::StorageImageAccess::eImageSize3DU,
			expr::StorageImageAccess::eImageSizeCubeU,
			expr::StorageImageAccess::eImageSizeBufferU,

			expr::StorageImageAccess::eImageSize1DArrayU,
			expr::StorageImageAccess::eImageSize2DArrayU,
			expr::StorageImageAccess::eImageSizeCubeArrayU,

			expr::StorageImageAccess::eImageSize2DMSU,
			expr::StorageImageAccess::eImageSize2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageSamplesU
		{
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,

			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,
			expr::StorageImageAccess::eInvalid,

			expr::StorageImageAccess::eImageSamples2DMSU,
			expr::StorageImageAccess::eImageSamples2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageLoadU
		{
			expr::StorageImageAccess::eImageLoad1DU,
			expr::StorageImageAccess::eImageLoad2DU,
			expr::StorageImageAccess::eImageLoad3DU,
			expr::StorageImageAccess::eImageLoadCubeU,
			expr::StorageImageAccess::eImageLoadBufferU,

			expr::StorageImageAccess::eImageLoad1DArrayU,
			expr::StorageImageAccess::eImageLoad2DArrayU,
			expr::StorageImageAccess::eImageLoadCubeArrayU,

			expr::StorageImageAccess::eImageLoad2DMSU,
			expr::StorageImageAccess::eImageLoad2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageStoreU
		{
			expr::StorageImageAccess::eImageStore1DU,
			expr::StorageImageAccess::eImageStore2DU,
			expr::StorageImageAccess::eImageStore3DU,
			expr::StorageImageAccess::eImageStoreCubeU,
			expr::StorageImageAccess::eImageStoreBufferU,

			expr::StorageImageAccess::eImageStore1DArrayU,
			expr::StorageImageAccess::eImageStore2DArrayU,
			expr::StorageImageAccess::eImageStoreCubeArrayU,

			expr::StorageImageAccess::eImageStore2DMSU,
			expr::StorageImageAccess::eImageStore2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicAddU
		{
			expr::StorageImageAccess::eImageAtomicAdd1DU,
			expr::StorageImageAccess::eImageAtomicAdd2DU,
			expr::StorageImageAccess::eImageAtomicAdd3DU,
			expr::StorageImageAccess::eImageAtomicAddCubeU,
			expr::StorageImageAccess::eImageAtomicAddBufferU,

			expr::StorageImageAccess::eImageAtomicAdd1DArrayU,
			expr::StorageImageAccess::eImageAtomicAdd2DArrayU,
			expr::StorageImageAccess::eImageAtomicAddCubeArrayU,

			expr::StorageImageAccess::eImageAtomicAdd2DMSU,
			expr::StorageImageAccess::eImageAtomicAdd2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicMinU
		{
			expr::StorageImageAccess::eImageAtomicMin1DU,
			expr::StorageImageAccess::eImageAtomicMin2DU,
			expr::StorageImageAccess::eImageAtomicMin3DU,
			expr::StorageImageAccess::eImageAtomicMinCubeU,
			expr::StorageImageAccess::eImageAtomicMinBufferU,

			expr::StorageImageAccess::eImageAtomicMin1DArrayU,
			expr::StorageImageAccess::eImageAtomicMin2DArrayU,
			expr::StorageImageAccess::eImageAtomicMinCubeArrayU,

			expr::StorageImageAccess::eImageAtomicMin2DMSU,
			expr::StorageImageAccess::eImageAtomicMin2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicMaxU
		{
			expr::StorageImageAccess::eImageAtomicMax1DU,
			expr::StorageImageAccess::eImageAtomicMax2DU,
			expr::StorageImageAccess::eImageAtomicMax3DU,
			expr::StorageImageAccess::eImageAtomicMaxCubeU,
			expr::StorageImageAccess::eImageAtomicMaxBufferU,

			expr::StorageImageAccess::eImageAtomicMax1DArrayU,
			expr::StorageImageAccess::eImageAtomicMax2DArrayU,
			expr::StorageImageAccess::eImageAtomicMaxCubeArrayU,
			expr::StorageImageAccess::eImageAtomicMax2DMSU,

			expr::StorageImageAccess::eImageAtomicMax2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicAndU
		{
			expr::StorageImageAccess::eImageAtomicAnd1DU,
			expr::StorageImageAccess::eImageAtomicAnd2DU,
			expr::StorageImageAccess::eImageAtomicAnd3DU,
			expr::StorageImageAccess::eImageAtomicAndCubeU,
			expr::StorageImageAccess::eImageAtomicAndBufferU,

			expr::StorageImageAccess::eImageAtomicAnd1DArrayU,
			expr::StorageImageAccess::eImageAtomicAnd2DArrayU,
			expr::StorageImageAccess::eImageAtomicAndCubeArrayU,

			expr::StorageImageAccess::eImageAtomicAnd2DMSU,
			expr::StorageImageAccess::eImageAtomicAnd2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicOrU
		{
			expr::StorageImageAccess::eImageAtomicOr1DU,
			expr::StorageImageAccess::eImageAtomicOr2DU,
			expr::StorageImageAccess::eImageAtomicOr3DU,
			expr::StorageImageAccess::eImageAtomicOrCubeU,
			expr::StorageImageAccess::eImageAtomicOrBufferU,

			expr::StorageImageAccess::eImageAtomicOr1DArrayU,
			expr::StorageImageAccess::eImageAtomicOr2DArrayU,
			expr::StorageImageAccess::eImageAtomicOrCubeArrayU,

			expr::StorageImageAccess::eImageAtomicOr2DMSU,
			expr::StorageImageAccess::eImageAtomicOr2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicXorU
		{
			expr::StorageImageAccess::eImageAtomicXor1DU,
			expr::StorageImageAccess::eImageAtomicXor2DU,
			expr::StorageImageAccess::eImageAtomicXor3DU,
			expr::StorageImageAccess::eImageAtomicXorCubeU,
			expr::StorageImageAccess::eImageAtomicXorBufferU,

			expr::StorageImageAccess::eImageAtomicXor1DArrayU,
			expr::StorageImageAccess::eImageAtomicXor2DArrayU,
			expr::StorageImageAccess::eImageAtomicXorCubeArrayU,

			expr::StorageImageAccess::eImageAtomicXor2DMSU,
			expr::StorageImageAccess::eImageAtomicXor2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicExchangeU
		{
			expr::StorageImageAccess::eImageAtomicExchange1DU,
			expr::StorageImageAccess::eImageAtomicExchange2DU,
			expr::StorageImageAccess::eImageAtomicExchange3DU,
			expr::StorageImageAccess::eImageAtomicExchangeCubeU,
			expr::StorageImageAccess::eImageAtomicExchangeBufferU,

			expr::StorageImageAccess::eImageAtomicExchange1DArrayU,
			expr::StorageImageAccess::eImageAtomicExchange2DArrayU,
			expr::StorageImageAccess::eImageAtomicExchangeCubeArrayU,

			expr::StorageImageAccess::eImageAtomicExchange2DMSU,
			expr::StorageImageAccess::eImageAtomicExchange2DMSArrayU,
		};
		static constexpr StorateImageAccessIntrList imageAtomicCompSwapU
		{
			expr::StorageImageAccess::eImageAtomicCompSwap1DU,
			expr::StorageImageAccess::eImageAtomicCompSwap2DU,
			expr::StorageImageAccess::eImageAtomicCompSwap3DU,
			expr::StorageImageAccess::eImageAtomicCompSwapCubeU,
			expr::StorageImageAccess::eImageAtomicCompSwapBufferU,

			expr::StorageImageAccess::eImageAtomicCompSwap1DArrayU,
			expr::StorageImageAccess::eImageAtomicCompSwap2DArrayU,
			expr::StorageImageAccess::eImageAtomicCompSwapCubeArrayU,

			expr::StorageImageAccess::eImageAtomicCompSwap2DMSU,
			expr::StorageImageAccess::eImageAtomicCompSwap2DMSArrayU,
		};
	}

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eUnknown >
		: public ImageFormatTraitsT< type::ImageFormat::eUnknown >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba32f >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba32f >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba16f >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba16f >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg32f >
		: public ImageFormatTraitsT< type::ImageFormat::eRg32f >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg16f >
		: public ImageFormatTraitsT< type::ImageFormat::eRg16f >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicAdd = storageImg::imageAtomicAddF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicExchange = storageImg::imageAtomicExchangeF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR32f >
		: public ImageFormatTraitsT< type::ImageFormat::eR32f >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicAdd = storageImg::imageAtomicAddF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicExchange = storageImg::imageAtomicExchangeF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR16f >
		: public ImageFormatTraitsT< type::ImageFormat::eR16f >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadF;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreF;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba32i >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba32i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba16i >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba16i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba8i >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba8i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg32i >
		: public ImageFormatTraitsT< type::ImageFormat::eRg32i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg16i >
		: public ImageFormatTraitsT< type::ImageFormat::eRg16i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg8i >
		: public ImageFormatTraitsT< type::ImageFormat::eRg8i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR32i >
		: public ImageFormatTraitsT< type::ImageFormat::eR32i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicAdd = storageImg::imageAtomicAddI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicMin = storageImg::imageAtomicMinI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicMax = storageImg::imageAtomicMaxI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicAnd = storageImg::imageAtomicAndI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicOr = storageImg::imageAtomicOrI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicXor = storageImg::imageAtomicXorI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicExchange = storageImg::imageAtomicExchangeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicCompSwap = storageImg::imageAtomicCompSwapI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR16i >
		: public ImageFormatTraitsT< type::ImageFormat::eR16i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR8i >
		: public ImageFormatTraitsT< type::ImageFormat::eR8i >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadI;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreI;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba32u >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba32u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba16u >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba16u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRgba8u >
		: public ImageFormatTraitsT< type::ImageFormat::eRgba8u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg32u >
		: public ImageFormatTraitsT< type::ImageFormat::eRg32u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg16u >
		: public ImageFormatTraitsT< type::ImageFormat::eRg16u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eRg8u >
		: public ImageFormatTraitsT< type::ImageFormat::eRg8u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR32u >
		: public ImageFormatTraitsT< type::ImageFormat::eR32u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicAdd = storageImg::imageAtomicAddU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicMin = storageImg::imageAtomicMinU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicMax = storageImg::imageAtomicMaxU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicAnd = storageImg::imageAtomicAndU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicOr = storageImg::imageAtomicOrU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicXor = storageImg::imageAtomicXorU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicExchange = storageImg::imageAtomicExchangeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageAtomicCompSwap = storageImg::imageAtomicCompSwapU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR16u >
		: public ImageFormatTraitsT< type::ImageFormat::eR16u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	template<>
	struct StorageImageFormatTraitsT< type::ImageFormat::eR8u >
		: public ImageFormatTraitsT< type::ImageFormat::eR8u >
	{
		static constexpr storageImg::StorateImageAccessIntrList const & imageSize = storageImg::imageSizeU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageSamples = storageImg::imageSamplesU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageLoad = storageImg::imageLoadU;
		static constexpr storageImg::StorateImageAccessIntrList const & imageStore = storageImg::imageStoreU;
	};

	//*****************************************************************************************

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e1D, false >
	{
		using CoordsType = Int32;
		using SizeType = Int32;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e2D, false >
	{
		using CoordsType = I32Vec2;
		using SizeType = I32Vec2;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e3D, false >
	{
		using CoordsType = I32Vec3;
		using SizeType = I32Vec3;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::eCube, false >
	{
		using CoordsType = I32Vec3;
		using SizeType = I32Vec2;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::eBuffer, false >
	{
		using CoordsType = Int32;
		using SizeType = Int32;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e1D, true >
	{
		using CoordsType = I32Vec2;
		using SizeType = I32Vec2;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::e2D, true >
	{
		using CoordsType = I32Vec3;
		using SizeType = I32Vec3;
	};

	template<>
	struct StorageImageCoordsGetterT< type::ImageDim::eCube, true >
	{
		using CoordsType = I32Vec3;
		using SizeType = I32Vec3;
	};

	namespace storageImg
	{
		//*****************************************************************************************

		template< typename ReturnT
			, type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, expr::StorageImageAccess ImageAccessT
			, typename ... ParamsT >
		ReturnWrapperT< ReturnT > writeImageAccessCall( StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & image
			, ParamsT const & ... params )
		{
			static_assert( ImageAccessT != expr::StorageImageAccess::eInvalid );
			static_assert( ImageAccessT != expr::StorageImageAccess::eUndefined );

			auto & writer = findWriterMandat( image, params... );
			auto & typesCache = findTypesCache( writer );
			return ReturnWrapperT< ReturnT >{ findWriterMandat( image, params... )
				, getExprCache( writer ).makeStorageImageAccessCall( ReturnT::makeType( typesCache )
					, ImageAccessT
					, makeExpr( image )
					, makeExpr( params )... )
				, areOptionalEnabled( image, params... ) };
		}

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, expr::StorageImageAccess ImageAccessT
			, typename ... ParamsT >
		void writeVoidImageAccessCall( StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & image
			, ParamsT const & ... params )
		{
			static_assert( ImageAccessT != expr::StorageImageAccess::eInvalid );
			static_assert( ImageAccessT != expr::StorageImageAccess::eUndefined );

			auto & writer = findWriterMandat( image, params... );
			auto & typesCache = findTypesCache( writer );

			if ( areOptionalEnabled( image, params... ) )
			{
				addStmt( writer
					, sdw::makeSimple( getStmtCache( writer )
						, getExprCache( writer ).makeStorageImageAccessCall( Void::makeType( typesCache )
							, ImageAccessT
							, makeExpr( image )
							, makeExpr( params )... ) ) );
			}
		}

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct ImgSizeFuncT
		{
			using SizeT = StorageImageSizeT< DimT, ArrayedT >;

			auto getSize()const
			{
				return writeImageAccessCall< SizeT, FormatT, AccessT, DimT, ArrayedT, MsT
					, StorageImageFormatTraitsT< FormatT >::imageSize[getImgArrayIndex< DimT, ArrayedT, MsT >()] >( get() );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgSamplesFuncT
		{
			auto getSamples()const
			{
				return writeImageAccessCall< Int32, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageSamples[getImgArrayIndex< DimT, ArrayedT, true >()] >( get() );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgLoadFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto load( CoordsT const & coord )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageLoad[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
					, coord );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsLoadFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto load( CoordsT const & coord
				, Int32 const & sample )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageLoad[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
					, coord
					, sample );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgStoreFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( CoordsT const & coord
				, FetchT const & value )const
			{
				writeVoidImageAccessCall<  FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageStore[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsStoreFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				writeVoidImageAccessCall<  FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageStore[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicAddFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAdd( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAdd[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicAddFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAdd( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAdd[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicMinFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMin( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMin[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicMinFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMin( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMin[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicMaxFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMax( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMax[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicMaxFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicMax( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicMax[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicAndFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAnd( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAnd[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicAndFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicAnd( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicAnd[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicOrFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicOr( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicOr[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicOrFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicOr( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicOr[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicXorFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicXor( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicXor[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicXorFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicXor( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicXor[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicExchangeFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicExchange( CoordsT const & coord
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicExchange[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicExchangeFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicExchange( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & value )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicExchange[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, value );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgAtomicCompSwapFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicCompSwap( CoordsT const & coord
				, FetchT const & compare
				, FetchT const & data )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, false
					, StorageImageFormatTraitsT< FormatT >::imageAtomicCompSwap[getImgArrayIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, compare
						, data );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT >
		struct ImgMsAtomicCompSwapFuncT
		{
			using CoordsT = StorageImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			auto atomicCompSwap( CoordsT const & coord
				, Int32 const & sample
				, FetchT const & compare
				, FetchT const & data )const
			{
				return writeImageAccessCall< FetchT, FormatT, AccessT, DimT, ArrayedT, true
					, StorageImageFormatTraitsT< FormatT >::imageAtomicCompSwap[getImgArrayIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, sample
						, compare
						, data );
			}

		private:
			StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & get()const
			{
				return static_cast< StorageImageT< FormatT, AccessT, DimT, ArrayedT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		template< type::ImageFormat FormatT >
		struct IsAtomicFloatFormat : std::false_type
		{
		};

		template<>
		struct IsAtomicFloatFormat< type::ImageFormat::eR32f > : std::true_type
		{
		};

		template< type::ImageFormat FormatT >
		static constexpr bool isAtomicFloatFormatV = IsAtomicFloatFormat< FormatT >::value;

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isAtomicFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > )
				&& ( !isAtomicFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< type::ImageFormat FormatT
			, type::AccessKind AccessT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct StorageImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public StorageImage
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT >
			, public ImgMsAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT >
		{
			SDW_DeclValue( , StorageImageFuncsT );

			StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: StorageImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			StorageImageFuncsT & operator=( T const & rhs )
			{
				StorageImage::operator=( rhs );
				return *this;
			}
		};

		//*****************************************************************************************
	}

	template< typename T >
	StorageImage & StorageImage::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = findWriterMandat( *this, rhs );

		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( shader
				, sdw::makeSimple( getStmtCache( shader )
					, sdw::makeAssign( getExpr()->getType()
						, makeExpr( shader, getExpr() )
						, makeExpr( shader, rhs ) ) ) );
		}

		return *this;
	}

	//*****************************************************************************************

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::StorageImageT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: storageImg::StorageImageFuncsT< FormatT, AccessT, DimT, ArrayedT, MsT >{ writer, std::move( expr ), enabled }
	{
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	template< typename T >
	StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT > & StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::operator=( T const & rhs )
	{
		storageImg::StorageImageFuncsT< FormatT, AccessT, DimT, ArrayedT, MsT >::operator=( rhs );
		return *this;
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	type::ImageConfiguration StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::makeConfig()
	{
		return type::makeConfig< FormatT, AccessT, DimT, ArrayedT, MsT >( false );
	}

	template< type::ImageFormat FormatT
		, type::AccessKind AccessT
		, type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline type::TypePtr StorageImageT< FormatT, AccessT, DimT, ArrayedT, MsT >::makeType( type::TypesCache & cache )
	{
		return cache.getImage( makeConfig() );
	}

	//*****************************************************************************************
}
