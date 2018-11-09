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
