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
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ast::type::ImageConfiguration makeConfig( bool sampled
		, bool readOnly );

	struct Image
		: public Value
	{
		Image( Shader * shader
			, expr::ExprPtr expr );
		Image( Image const & rhs );
		template< typename T >
		inline Image & operator=( T const & rhs );
		operator uint32_t();
	};

	template< ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageT
		: public Image
	{
		inline ImageT( Shader * shader
			, expr::ExprPtr expr );
		inline ImageT( ImageT const & rhs );
		template< typename T >
		inline ImageT & operator=( T const & rhs );
		inline operator uint32_t();

		static inline ast::type::ImageConfiguration makeConfig();
	};
}

#include "Image.inl"

#endif
