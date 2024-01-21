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
		SDW_DeclValue( SDW_API, SampledImage );

		SDW_API SampledImage( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		SampledImage & operator=( T const & rhs );
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct SampledImageT
		: public SampledImage
	{
		SDW_DeclValue( , SampledImageT );

		static constexpr ast::type::ImageFormat Format = FormatT;
		static constexpr ast::type::ImageDim Dim = DimT;
		static constexpr bool Arrayed = ArrayedT;
		static constexpr bool Ms = MsT;

		SampledImageT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		SampledImageT & operator=( T const & rhs );

		static ast::type::ImageConfiguration makeConfig();
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "SampledImage.inl"

#endif
