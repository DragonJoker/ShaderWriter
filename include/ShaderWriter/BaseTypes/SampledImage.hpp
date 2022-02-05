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

		SDW_API SampledImage( ast::type::ImageFormat format
			, ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline SampledImage & operator=( T const & rhs );
		SDW_API operator uint32_t();
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

		inline SampledImageT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline SampledImageT & operator=( T const & rhs );

		static inline ast::type::ImageConfiguration makeConfig();
		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "SampledImage.inl"

#endif
