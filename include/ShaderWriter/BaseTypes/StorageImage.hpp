/*
See LICENSE file in root folder
*/
#ifndef ___SDW_StorageImage_H___
#define ___SDW_StorageImage_H___

#include "Image.hpp"

namespace sdw
{
	template< ast::type::ImageFormat FormatT >
	struct StorageImageFormatTraitsT;

	template< ast::type::ImageDim DimT, bool ArrayedT >
	struct StorageImageCoordsGetterT;

	template< ast::type::ImageDim DimT, bool ArrayedT >
	using StorageImageCoordsT = typename StorageImageCoordsGetterT< DimT, ArrayedT >::CoordsType;

	template< ast::type::ImageDim DimT, bool ArrayedT >
	using StorageImageSizeT = typename StorageImageCoordsGetterT< DimT, ArrayedT >::SizeType;

	struct StorageImage
		: public Value
	{
		SDW_DeclValue( SDW_API, StorageImage );

		SDW_API StorageImage( ast::type::ImageFormat format
			, ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline StorageImage & operator=( T const & rhs );
		SDW_API operator uint32_t();
	};

	namespace storageImg
	{
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename EnableT = void >
		struct StorageImageFuncsT
			: public StorageImage
		{
			SDW_DeclValue( , StorageImageFuncsT );

			inline StorageImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled );

			template< typename T >
			inline StorageImageFuncsT & operator=( T const & rhs );
		};
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct StorageImageT
		: public storageImg::StorageImageFuncsT< FormatT, AccessT, DimT, ArrayedT, MsT >
	{
		SDW_DeclValue( , StorageImageT );

		static constexpr ast::type::ImageFormat Format = FormatT;
		static constexpr ast::type::AccessKind Access = AccessT;
		static constexpr ast::type::ImageDim Dim = DimT;
		static constexpr bool Arrayed = ArrayedT;
		static constexpr bool Ms = MsT;

		inline StorageImageT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline StorageImageT & operator=( T const & rhs );

		static inline ast::type::ImageConfiguration makeConfig();

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "StorageImage.inl"

#endif
