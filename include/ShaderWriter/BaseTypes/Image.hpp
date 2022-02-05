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

	template< ast::type::AccessKind AccessT >
	static constexpr bool isReadableV{ AccessT == ast::type::AccessKind::eRead || AccessT == ast::type::AccessKind::eReadWrite };

	template< ast::type::AccessKind AccessT >
	static constexpr bool isWritableV{ AccessT == ast::type::AccessKind::eWrite || AccessT == ast::type::AccessKind::eReadWrite };

	template< ast::type::AccessKind AccessT >
	static constexpr bool isReadWriteV{ AccessT == ast::type::AccessKind::eReadWrite };
}

#include "Image.inl"

#endif
