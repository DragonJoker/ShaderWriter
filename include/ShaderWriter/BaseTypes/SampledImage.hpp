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
		SDW_API SampledImage( ast::type::ImageFormat format
			, Shader * shader
			, expr::ExprPtr expr );
		template< typename T >
		inline SampledImage & operator=( T const & rhs );
		SDW_API operator uint32_t();
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct SampledImageT
		: public SampledImage
	{
		inline SampledImageT( Shader * shader
			, expr::ExprPtr expr );
		template< typename T >
		inline SampledImageT & operator=( T const & rhs );
		inline operator uint32_t();

		static inline ast::type::ImageConfiguration makeConfig();

		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "SampledImage.inl"

#endif
