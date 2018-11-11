/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Image_H___
#define ___SDW_Image_H___

#include "Value.hpp"

#include <ASTGenerator/Type/ImageConfiguration.hpp>

namespace sdw
{
	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct ImageCoordsGetter;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using ImageCoordsT = typename ImageCoordsGetter< DimT, ArrayedT >::Type;

	struct Image
		: public Value
	{
		Image( Shader * shader
			, expr::ExprPtr expr
			, ast::type::ImageFormat format );
		Image( Image const & rhs );
		template< typename T >
		inline Image & operator=( T const & rhs );
		operator uint32_t();

	private:
		ast::type::ImageFormat m_format;
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageT
		: public Image
	{
		inline ImageT( Shader * shader
			, expr::ExprPtr expr
			, ast::type::ImageFormat format = ast::type::ImageFormat::eUnknown );
		inline ImageT( ImageT const & rhs );
		template< typename T >
		inline ImageT & operator=( T const & rhs );
		inline operator uint32_t();

		static inline ast::type::ImageConfiguration makeConfig( ast::type::ImageFormat format = ast::type::ImageFormat::eUnknown );
	};
}

#include "Image.inl"

#endif
