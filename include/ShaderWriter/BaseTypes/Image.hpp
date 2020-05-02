/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Image_H___
#define ___SDW_Image_H___

#include "ShaderWriter/Value.hpp"

#include <ShaderAST/Type/ImageConfiguration.hpp>

namespace sdw
{
	template< ast::type::ImageFormat FormatT >
	struct ImageSampleGetter;

	template< ast::type::ImageFormat FormatT >
	using ImageSampleT = typename ImageSampleGetter< FormatT >::SampleType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
		struct ImageCoordsGetter;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using ImageCoordsT = typename ImageCoordsGetter< DimT, ArrayedT >::CoordsType;

	struct Image
		: public Value
	{
		SDW_API Image( ast::type::ImageFormat format
			, Shader * shader
			, expr::ExprPtr expr );
		SDW_API Image( Image const & rhs );
		template< typename T >
		inline Image & operator=( T const & rhs );
		SDW_API operator uint32_t();

	private:
		ast::type::ImageFormat m_format;
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
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

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Image.inl"

#endif
