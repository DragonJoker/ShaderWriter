/*
See LICENSE file in root folder
*/
#ifndef ___SDW_SampledImage_H___
#define ___SDW_SampledImage_H___

#include "Image.hpp"

namespace sdw
{
	template< ast::type::ImageFormat FormatT, typename Enable = void >
	struct SampledImageFormatTraitsT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct SampledImageCoordsGetterT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSampleT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::SampleType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSampleProjT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::ProjType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageOffsetT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::OffsetType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageDerivativeT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::DerivativeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageGatherT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::GatherType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using SampledImageSizeT = typename SampledImageCoordsGetterT< DimT, ArrayedT >::SizeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSpl1dV = ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSpl2dV = ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSpl3dV = ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e3D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSplRectV = ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSplBufferV = ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eBuffer );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSplCubeV = ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSpl1dArrayV = ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSpl2dArrayV = ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	static bool constexpr isSplCubeArrayV = ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

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

	namespace sampledImg
	{
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, typename EnableT = void >
		struct SampledImageFuncsT
			: public SampledImage
		{
			SDW_DeclValue( , SampledImageFuncsT );

			inline SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled );

			template< typename T >
			inline SampledImageFuncsT & operator=( T const & rhs );
		};
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	struct SampledImageT
		: public sampledImg::SampledImageFuncsT< FormatT, DimT, ArrayedT, MsT >
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
