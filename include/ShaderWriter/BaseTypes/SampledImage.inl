/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

namespace sdw
{
	//*************************************************************************

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::eBuffer, false >
	{
		using SampleType = sdw::Int;
		using FetchType = sdw::Int;
		using SizeType = sdw::Int;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e1D, false >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Float;
		using ProjType = sdw::Vec2;
		using OffsetType = sdw::Int;
		using FetchType = sdw::Int;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::Int;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e2D, false >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec2;
		using ProjType = sdw::Vec3;
		using OffsetType = sdw::IVec2;
		using FetchType = sdw::IVec2;
		using DerivativeType = sdw::Vec2;
		using GatherType = sdw::Vec2;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e3D, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
		using ProjType = sdw::Vec4;
		using OffsetType = sdw::IVec3;
		using FetchType = sdw::IVec3;
		using DerivativeType = sdw::Vec3;
		using SizeType = sdw::IVec3;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::eCube, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using FetchType = sdw::Vec3;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e1D, true >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Vec2;
		using OffsetType = sdw::Int;
		using FetchType = sdw::IVec2;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e2D, true >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec3;
		using OffsetType = sdw::IVec2;
		using FetchType = sdw::IVec3;
		using DerivativeType = sdw::Vec2;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::IVec3;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::eCube, true >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec4;
		using FetchType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using GatherType = sdw::Vec4;
		using SizeType = sdw::IVec3;
	};

	namespace details
	{
		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct TexSizeFuncT
		{
			using SizeT = SampledImageSizeT< DimT, ArrayedT >;

			MaybeOptional< SizeT > getSize()const
			{
				return textureSize( get() );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct TexSizeLevelFuncT
		{
			using SizeT = SampledImageSizeT< DimT, ArrayedT >;

			MaybeOptional< SizeT > getSize( MaybeOptional< Int > const & level )const
			{
				return textureSize( get(), level );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct QueryLodFuncT
		{
			using QueryLodT = SampledImageQueryLodT< DimT, ArrayedT >;

			MaybeOptional< Vec2 > getLod( MaybeOptional< QueryLodT > const & coord )const
			{
				return textureQueryLod( get(), coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct QueryLevelsFuncT
		{
			MaybeOptional< Int > getLevels()const
			{
				return textureQueryLevels( get() );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord )const
			{
				return texture( get(), coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref )const
			{
				return texture( get(), coord, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & bias )const
			{
				return texture( get(), coord, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Float > const & bias )const
			{
				return texture( get(), coord, ref, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureOffset( get(), coord, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureOffset( get(), coord, ref, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleOffsetBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< OffsetT > const & offset
				, MaybeOptional< Float > const & bias )const
			{
				return textureOffset( get(), coord, offset, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefOffsetBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > sample( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< OffsetT > const & offset
				, MaybeOptional< Float > const & bias )const
			{
				return textureOffset( get(), coord, ref, offset, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleLodFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > lod( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & lod )const
			{
				return textureLod( get(), coord, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefLodFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > lod( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Float > const & lod )const
			{
				return textureLod( get(), coord, ref, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleLodOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > lod( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & lod
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureLodOffset( get(), coord, lod, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefLodOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > lod( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Float > const & lod
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureLodOffset( get(), coord, ref, lod, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord )const
			{
				return textureProj( get(), coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref )const
			{
				return textureProj( get(), coord, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & bias )const
			{
				return textureProj( get(), coord, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Float > const & bias )const
			{
				return textureProj( get(), coord, ref, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureProjOffset( get(), coord, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureProjOffset( get(), coord, ref, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjOffsetBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< OffsetT > const & offset
				, MaybeOptional< Float > const & bias )const
			{
				return textureProjOffset( get(), coord, offset, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjOffsetBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > proj( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< OffsetT > const & offset
				, MaybeOptional< Float > const & bias )const
			{
				return textureProjOffset( get(), coord, ref, offset, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjLodFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projLod( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & lod )const
			{
				return textureProjLod( get(), coord, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjLodFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projLod( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Float > const & lod )const
			{
				return textureProjLod( get(), coord, ref, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjLodOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projLod( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & lod
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureProjLodOffset( get(), coord, lod, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjLodOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projLod( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Float > const & lod
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureProjLodOffset( get(), coord, ref, lod, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchFuncT
		{
			using FetchT = SampledImageFetchT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > fetch( MaybeOptional< FetchT > const & coord )const
			{
				return texelFetch( get(), coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchLevelFuncT
		{
			using FetchT = SampledImageFetchT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > fetch( MaybeOptional< FetchT > const & coord
				, MaybeOptional< Int > const & level )const
			{
				return texelFetch( get(), coord, level );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchLevelOffsetFuncT
		{
			using FetchT = SampledImageFetchT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > fetch( MaybeOptional< FetchT > const & coord
				, MaybeOptional< Int > const & level
				, MaybeOptional< OffsetT > const & offset )const
			{
				return texelFetchOffset( get(), coord, level, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > grad( MaybeOptional< SampleT > const & coord
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy )const
			{
				return textureGrad( get(), coord, dPdx, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > grad( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy )const
			{
				return textureGrad( get(), coord, ref, dPdx, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > grad( MaybeOptional< SampleT > const & coord
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureGradOffset( get(), coord, dPdx, dPdy, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > grad( MaybeOptional< SampleT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureGradOffset( get(), coord, ref, dPdx, dPdy, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projGrad( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy )const
			{
				return textureProjGrad( get(), coord, dPdx, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projGrad( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy )const
			{
				return textureProjGrad( get(), coord, ref, dPdx, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projGrad( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureProjGradOffset( get(), coord, dPdx, dPdy, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};
		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageSampleT< FormatT > > projGrad( MaybeOptional< SampleProjT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< DerivativeT > const & dPdx
				, MaybeOptional< DerivativeT > const & dPdy
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureProjGradOffset( get(), coord, ref, dPdx, dPdy, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord )const
			{
				return textureGather( get(), coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< Float > const & ref )const
			{
				return textureGather( get(), coord, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherCompFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< Int > const & comp )const
			{
				return textureGather( get(), coord, comp );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureGatherOffset( get(), coord, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefOffsetFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< OffsetT > const & offset )const
			{
				return textureGatherOffset( get(), coord, ref, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetsCompFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< OffsetT > const & offset
				, MaybeOptional< Int > const & comp )const
			{
				return textureGatherOffset( get(), coord, offset, comp );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetsFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< Array< OffsetT > > const & offsets )const
			{
				return textureGatherOffsets( get(), coord, offsets );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefOffsetsFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< Float > const & ref
				, MaybeOptional< Array< OffsetT > > const & offsets )const
			{
				return textureGatherOffsets( get(), coord, ref, offsets );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetCompFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			MaybeOptional< ImageGatherT< FormatT > > gather( MaybeOptional< GatherT > const & coord
				, MaybeOptional< Array< OffsetT > > const & offsets
				, MaybeOptional< Int > const & comp )const
			{
				return textureGatherOffsets( get(), coord, offsets, comp );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherCompFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetCompFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetsCompFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetsCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dArrayV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dArrayV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherCompFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetCompFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetsCompFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetsCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherCompFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherCompFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isRectShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;

			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isBufferV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public FetchFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SampledImageFuncsT( Shader * shader
				, expr::ExprPtr expr )
				: SampledImage{ FormatT, shader, std::move( expr ) }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	}

	template< typename T >
	SampledImage & SampledImage::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = *findShader( *this, rhs );
		addStmt( shader
			, sdw::makeSimple( sdw::makeAssign( getExpr()->getType()
				, makeExpr( shader, getExpr() )
				, makeExpr( shader, rhs ) ) ) );
		return *this;
	}

	//*************************************************************************

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::SampledImageT( Shader * shader
		, expr::ExprPtr expr )
		: details::SampledImageFuncsT< FormatT, DimT, ArrayedT, DepthT, MsT >{ shader, std::move( expr ) }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > & SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		details::SampledImageFuncsT< FormatT, DimT, ArrayedT, DepthT, MsT >::operator=( rhs );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, ast::type::AccessKind::eRead, DimT, ArrayedT, DepthT, MsT >( true );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ast::type::TypePtr SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getSampledImage( makeConfig() );
	}

	//*************************************************************************
}
