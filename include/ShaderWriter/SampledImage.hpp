/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SampledImage_H___
#define ___SDW_SampledImage_H___

#include "Image.hpp"

namespace sdw
{
	struct SampledImage
		: public Value
	{
		SampledImage( Shader * shader
			, expr::ExprPtr expr );
		template< typename T >
		inline SampledImage & operator=( T const & rhs );
		operator uint32_t();
	};

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
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
	};
}

#include "SampledImage.inl"

#endif
