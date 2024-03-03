/*
See LICENSE file in root folder
*/
#ifndef ___SDW_CombinedImage_H___
#define ___SDW_CombinedImage_H___

#include "Image.hpp"

namespace sdw
{
	template< ast::type::ImageFormat FormatT, typename Enable = void >
	struct CombinedImageFormatTraitsT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct CombinedImageCoordsGetterT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageQueryLodT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::QueryLodType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageSampleT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::SampleType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageSampleProjT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::ProjType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageOffsetT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::OffsetType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageFetchT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::FetchType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageDerivativeT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::DerivativeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageGatherT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::GatherType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CombinedImageSizeT = typename CombinedImageCoordsGetterT< DimT, ArrayedT >::SizeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1dV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is3dV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e3D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isBufferV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eBuffer );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1dArrayV = ( !DepthT ) && ArrayedT && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dArrayV = ( !DepthT ) && ArrayedT && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeArrayV = ( !DepthT ) && ArrayedT && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1dShadowV = DepthT && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dShadowV = DepthT && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeShadowV = DepthT && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1dArrayShadowV = DepthT && ArrayedT && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dArrayShadowV = DepthT && ArrayedT && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeArrayShadowV = DepthT && ArrayedT && ( DimT == ast::type::ImageDim::eCube );

	struct CombinedImage
		: public Value
	{
		SDW_DeclValue( SDW_API, CombinedImage );

		SDW_API CombinedImage( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		CombinedImage & operator=( T const & rhs );
	};

	namespace combinedSmplImg
	{
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT
			, typename EnableT = void >
		struct CombinedImageFuncsT
			: public CombinedImage
		{
			SDW_DeclValue( , CombinedImageFuncsT );

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled );

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs );
		};
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct CombinedImageT
		: public combinedSmplImg::CombinedImageFuncsT< FormatT, DimT, ArrayedT, MsT, DepthT >
	{
		SDW_DeclValue( , CombinedImageT );

		static constexpr ast::type::ImageFormat Format = FormatT;
		static constexpr ast::type::ImageDim Dim = DimT;
		static constexpr bool Arrayed = ArrayedT;
		static constexpr bool Ms = MsT;
		static constexpr bool Depth = DepthT;

		CombinedImageT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		CombinedImageT & operator=( T const & rhs );

		static ast::type::ImageConfiguration makeConfig();
		static ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "CombinedImage.inl"

#endif
