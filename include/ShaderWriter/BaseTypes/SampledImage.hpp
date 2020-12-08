/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SampledImage_H___
#define ___SDW_SampledImage_H___

#include "Image.hpp"

namespace sdw
{
	template< ast::type::ImageFormat FormatT, typename Enable = void >
	struct SampledImageFormatTraitsT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct SampledImageCoordsGetterT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageQueryLodT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::QueryLodType;
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSampleT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::SampleType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSampleProjT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::ProjType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageOffsetT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::OffsetType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageFetchT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::FetchType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageDerivativeT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::DerivativeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageGatherT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::GatherType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSizeT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::SizeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is1dV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is2dV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is3dV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e3D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isRectV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isBufferV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eBuffer );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isCubeV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is1dArrayV = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is2dArrayV = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isCubeArrayV = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is1dShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is2dShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isRectShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isCubeShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is1dArrayShadowV = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr is2dArrayShadowV = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
		static bool constexpr isCubeArrayShadowV = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	struct SampledImage
		: public Value
	{
		SDW_API SampledImage( ast::type::ImageFormat format
			, ShaderWriter & writer
			, expr::ExprPtr expr );
		template< typename T >
		inline SampledImage & operator=( T const & rhs );
		SDW_API operator uint32_t();
	};

	namespace sampledImg
	{
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT
			, typename EnableT = void >
		struct SampledImageFuncsT
			: public SampledImage
		{
			inline SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr );
			template< typename T >
			inline SampledImageFuncsT & operator=( T const & rhs );
		};
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct SampledImageT
		: public sampledImg::SampledImageFuncsT< FormatT, DimT, ArrayedT, DepthT, MsT >
	{
		inline SampledImageT( ShaderWriter & writer
			, expr::ExprPtr expr );
		template< typename T >
		inline SampledImageT & operator=( T const & rhs );

		static inline ast::type::ImageConfiguration makeConfig();
		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "SampledImage.inl"

#endif
