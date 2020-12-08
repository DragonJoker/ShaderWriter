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
	struct ImageFormatTraitsT;

	template< ast::type::ImageFormat FormatT >
	using ImageSampleT = typename ImageFormatTraitsT< FormatT >::SampleType;

	template< ast::type::ImageFormat FormatT >
	using ImageFetchT = typename ImageFormatTraitsT< FormatT >::FetchType;

	template< ast::type::ImageFormat FormatT >
	using ImageGatherT = typename ImageFormatTraitsT< FormatT >::GatherType;

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isSingleFormatV{ ImageFormatTraitsT< FormatT >::isSingle };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isFloatFormatV{ ImageFormatTraitsT< FormatT >::isFloat };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isSIntFormatV{ ImageFormatTraitsT< FormatT >::isSInt };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isUIntFormatV{ ImageFormatTraitsT< FormatT >::isUInt };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isIntFormatV{ isSIntFormatV< FormatT > || isUIntFormatV< FormatT > };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isSingleIntFormatV{ isIntFormatV< FormatT > && isSingleFormatV< FormatT > };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isSingleFloatFormatV{ isFloatFormatV< FormatT > && isSingleFormatV< FormatT > };

	template< ast::type::ImageFormat FormatT >
	static constexpr bool isSingleInt32FormatV{ isSingleIntFormatV< FormatT > && ( ImageFormatTraitsT< FormatT >::size == 32u ) };

	template< ast::type::ImageDim DimT, bool ArrayedT >
	struct ImageCoordsGetterT;

	template< ast::type::ImageDim DimT, bool ArrayedT >
	using ImageCoordsT = typename ImageCoordsGetterT< DimT, ArrayedT >::CoordsType;

	template< ast::type::ImageDim DimT, bool ArrayedT >
	using ImageSizeT = typename ImageCoordsGetterT< DimT, ArrayedT >::SizeType;

	template< ast::type::AccessKind AccessT >
	static constexpr bool isReadableV{ AccessT == ast::type::AccessKind::eRead || AccessT == ast::type::AccessKind::eReadWrite };

	template< ast::type::AccessKind AccessT >
	static constexpr bool isWritableV{ AccessT == ast::type::AccessKind::eWrite || AccessT == ast::type::AccessKind::eReadWrite };

	template< ast::type::AccessKind AccessT >
	static constexpr bool isReadWriteV{ AccessT == ast::type::AccessKind::eReadWrite };

	struct Image
		: public Value
	{
		SDW_API Image( ast::type::ImageFormat format
			, ShaderWriter & writer
			, expr::ExprPtr expr );
		SDW_API Image( Image const & rhs );
		template< typename T >
		inline Image & operator=( T const & rhs );
		SDW_API operator uint32_t();

	private:
		ast::type::ImageFormat m_format;
	};

	namespace img
	{
		template< ast::type::ImageFormat FormatT
			, ast::type::AccessKind AccessT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT
			, typename EnableT = void >
		struct ImageFuncsT
			: public Image
		{
			inline ImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr );
			template< typename T >
			inline ImageFuncsT & operator=( T const & rhs );
		};
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageT
		: public img::ImageFuncsT< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT >
	{
		inline ImageT( ShaderWriter & writer
			, expr::ExprPtr expr );
		inline ImageT( ImageT const & rhs );
		template< typename T >
		inline ImageT & operator=( T const & rhs );

		static inline ast::type::ImageConfiguration makeConfig();

		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Image.inl"

#endif
