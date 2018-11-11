/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SampledImage_H___
#define ___SDW_SampledImage_H___

#include "Image.hpp"

namespace sdw
{
	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct SampledImageCoordsGetter;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageQueryLodT = typename SampledImageCoordsGetter< DimT, ArrayedT >::QueryLodType;
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSampleT = typename SampledImageCoordsGetter< DimT, ArrayedT >::SampleType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSampleProjT = typename SampledImageCoordsGetter< DimT, ArrayedT >::ProjType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageOffsetT = typename SampledImageCoordsGetter< DimT, ArrayedT >::OffsetType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageFetchT = typename SampledImageCoordsGetter< DimT, ArrayedT >::FetchType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageDerivativeT = typename SampledImageCoordsGetter< DimT, ArrayedT >::DerivativeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageGatherT = typename SampledImageCoordsGetter< DimT, ArrayedT >::GatherType;

	struct SampledImage
		: public Value
	{
		SampledImage( Shader * shader
			, expr::ExprPtr expr
			, ast::type::ImageFormat format );
		template< typename T >
		inline SampledImage & operator=( T const & rhs );
		operator uint32_t();

	private:
		ast::type::ImageFormat m_format;
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct SampledImageT
		: public SampledImage
	{
		inline SampledImageT( Shader * shader
			, expr::ExprPtr expr
			, ast::type::ImageFormat format = ast::type::ImageFormat::eUnknown );
		template< typename T >
		inline SampledImageT & operator=( T const & rhs );
		inline operator uint32_t();

		static inline ast::type::ImageConfiguration makeConfig( ast::type::ImageFormat format = ast::type::ImageFormat::eUnknown );
	};
}

#include "SampledImage.inl"

#endif
