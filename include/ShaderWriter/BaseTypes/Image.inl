/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
	//*****************************************************************************************

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eUnknown >
	{
		using SampleType = Vec4;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba32f >
	{
		using SampleType = Vec4;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba16f >
	{
		using SampleType = Vec4;
		using FetchType = HVec4;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg32f >
	{
		using SampleType = Vec2;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg16f >
	{
		using SampleType = Vec2;
		using FetchType = HVec2;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR32f >
	{
		using SampleType = Float;
		using FetchType = SampleType;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR16f >
	{
		using SampleType = Float;
		using FetchType = Half;
		using GatherType = Vec4;
		static constexpr bool isFloat = true;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba32i >
	{
		using SampleType = IVec4;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba16i >
	{
		using SampleType = IVec4;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba8i >
	{
		using SampleType = IVec4;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg32i >
	{
		using SampleType = IVec2;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg16i >
	{
		using SampleType = IVec2;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg8i >
	{
		using SampleType = IVec2;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR32i >
	{
		using SampleType = Int;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR16i >
	{
		using SampleType = Int;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR8i >
	{
		using SampleType = Int;
		using FetchType = SampleType;
		using GatherType = IVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = true;
		static constexpr bool isUInt = false;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 8u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba32u >
	{
		using SampleType = UVec4;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 128u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba16u >
	{
		using SampleType = UVec4;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRgba8u >
	{
		using SampleType = UVec4;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg32u >
	{
		using SampleType = UVec2;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 64u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg16u >
	{
		using SampleType = UVec2;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eRg8u >
	{
		using SampleType = UVec2;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = false;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR32u >
	{
		using SampleType = UInt;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 32u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR16u >
	{
		using SampleType = UInt;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 16u;
	};

	template<>
	struct ImageFormatTraitsT< ast::type::ImageFormat::eR8u >
	{
		using SampleType = UInt;
		using FetchType = SampleType;
		using GatherType = UVec4;
		static constexpr bool isFloat = false;
		static constexpr bool isSInt = false;
		static constexpr bool isUInt = true;
		static constexpr bool isSingle = true;
		static constexpr size_t size = 8u;
	};

	//*****************************************************************************************

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::e1D, false >
	{
		using CoordsType = Int;
		using SizeType = Int;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::e2D, false >
	{
		using CoordsType = IVec2;
		using SizeType = IVec2;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::e3D, false >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::eCube, false >
	{
		using CoordsType = IVec3;
		using SizeType = IVec2;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::eBuffer, false >
	{
		using CoordsType = Int;
		using SizeType = Int;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::e1D, true >
	{
		using CoordsType = IVec2;
		using SizeType = IVec2;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::e2D, true >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	template<>
	struct ImageCoordsGetterT< ast::type::ImageDim::eCube, true >
	{
		using CoordsType = IVec3;
		using SizeType = IVec3;
	};

	namespace details
	{
		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImgSizeFuncT
		{
			using SizeT = ImageSizeT< DimT, ArrayedT >;

			MaybeOptional< SizeT > getSize()const
			{
				return imageSize( get() );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgSamplesFuncT
		{
			MaybeOptional< Int > getSamples()const
			{
				return imageSamples( get() );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgLoadFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;

			MaybeOptional< ImageFetchT< FormatT > > load( MaybeOptional< CoordsT > const & coord )const
			{
				return imageLoad( get(), coord );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsLoadFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;

			MaybeOptional< ImageFetchT< FormatT > > load( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample )const
			{
				return imageLoad( get(), coord, sample );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgStoreFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				imageStore( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsStoreFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			void store( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				imageStore( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicAddFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicAdd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicAdd( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicAddFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicAdd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicAdd( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicMinFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicMin( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicMin( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicMinFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicMin( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicMin( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicMaxFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicMax( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicMax( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicMaxFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicMax( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicMax( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicAndFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicAnd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicAnd( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicAndFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicAnd( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicAnd( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicOrFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicOr( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicOr( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicOrFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicOr( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicOr( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicXorFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicXor( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicXor( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicXorFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicXor( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicXor( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicExchangeFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicExchange( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicExchange( get(), coord, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicExchangeFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicExchange( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & value )const
			{
				return imageAtomicExchange( get(), coord, sample, value );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgAtomicCompSwapFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicCompSwap( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< FetchT > const & compare
				, MaybeOptional< FetchT > const & data )const
			{
				return imageAtomicCompSwap( get(), coord, compare, data );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, false > const & >( *this );
			}
		};

		//*****************************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
		struct ImgMsAtomicCompSwapFuncT
		{
			using CoordsT = ImageCoordsT< DimT, ArrayedT >;
			using FetchT = ImageFetchT< FormatT >;

			MaybeOptional< ImageFetchT< FormatT > > atomicCompSwap( MaybeOptional< CoordsT > const & coord
				, MaybeOptional< Int > const & sample
				, MaybeOptional< FetchT > const & compare
				, MaybeOptional< FetchT > const & data )const
			{
				return imageAtomicCompSwap( get(), coord, sample, compare, data );
			}

		private:
			ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & get()const
			{
				return static_cast< ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( !MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( !isReadableV< AccessT > )
				&& ( isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( !isWritableV< AccessT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( !isSingleInt32FormatV< FormatT > && !isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isFloatFormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct ImageFuncsT< FormatT
			, AccessT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( ( MsT )
				&& ( isReadableV< AccessT > )
				&& ( isWritableV< AccessT > )
				&& ( isSingleInt32FormatV< FormatT > ) ) > >
			: public Image
			, public ImgSizeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
			, public ImgSamplesFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsLoadFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsStoreFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicAddFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicMinFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicMaxFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicAndFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicOrFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicXorFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicExchangeFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
			, public ImgMsAtomicCompSwapFuncT< FormatT, AccessT, DimT, ArrayedT, DepthT >
		{
			ImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: Image{ FormatT, shader, std::move( expr ) }
			{
			}

			ImageFuncsT( ImageFuncsT const & rhs )
				: Image{ rhs }
			{
			}

			template< typename T >
			ImageFuncsT & operator=( T const & rhs )
			{
				Image::operator=( rhs );
				return *this;
			}
		};

		//*****************************************************************************************
	}

	template< typename T >
	Image & Image::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = *findShader( *this, rhs );
		addStmt( shader
			, makeSimple( makeAssign( getExpr()->getType()
				, makeExpr( shader, getExpr() )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	//*****************************************************************************************

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::ImageT( Shader * shader
		, expr::ExprPtr expr )
		: details::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >{ shader, std::move( expr ) }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::ImageT( ImageT const & rhs )
		: details::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >{ rhs }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT > & ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		details::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::operator=( rhs );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >( false );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ast::type::TypePtr ImageT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getImage( makeConfig() );
	}

	//*****************************************************************************************
}
