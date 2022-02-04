/*
See LICENSE file in root folder
*/
#ifndef ___SDW_Texture_H___
#define ___SDW_Texture_H___

#include "Image.hpp"

namespace sdw
{
	template< ast::type::ImageFormat FormatT, typename Enable = void >
	struct TextureFormatTraitsT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct TextureCoordsGetterT;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureQueryLodT = typename TextureCoordsGetterT< DimT, ArrayedT >::QueryLodType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureSampleT = typename TextureCoordsGetterT< DimT, ArrayedT >::SampleType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureSampleProjT = typename TextureCoordsGetterT< DimT, ArrayedT >::ProjType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureOffsetT = typename TextureCoordsGetterT< DimT, ArrayedT >::OffsetType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureFetchT = typename TextureCoordsGetterT< DimT, ArrayedT >::FetchType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureDerivativeT = typename TextureCoordsGetterT< DimT, ArrayedT >::DerivativeType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureGatherT = typename TextureCoordsGetterT< DimT, ArrayedT >::GatherType;

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using TextureSizeT = typename TextureCoordsGetterT< DimT, ArrayedT >::SizeType;

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
	static bool constexpr isRectV = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );

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
	static bool constexpr is1dArrayV = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dArrayV = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeArrayV = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1dShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isRectShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeShadowV = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1dArrayShadowV = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2dArrayShadowV = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeArrayShadowV = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	struct Texture
		: public Value
	{
		SDW_DeclValue( SDW_API, Texture );

		SDW_API Texture( ast::type::ImageFormat format
			, ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline Texture & operator=( T const & rhs );
		SDW_API operator uint32_t();
	};

	namespace combinedSmplImg
	{
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT
			, typename EnableT = void >
		struct TextureFuncsT
			: public Texture
		{
			SDW_DeclValue( , TextureFuncsT );

			inline TextureFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled );

			template< typename T >
			inline TextureFuncsT & operator=( T const & rhs );
		};
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureT
		: public combinedSmplImg::TextureFuncsT< FormatT, DimT, ArrayedT, DepthT, MsT >
	{
		SDW_DeclValue( , TextureT );

		static constexpr ast::type::ImageFormat Format = FormatT;
		static constexpr ast::type::ImageDim Dim = DimT;
		static constexpr bool Arrayed = ArrayedT;
		static constexpr bool Depth = DepthT;
		static constexpr bool Ms = MsT;

		inline TextureT( ShaderWriter & writer
			, expr::ExprPtr expr
			, bool enabled );

		template< typename T >
		inline TextureT & operator=( T const & rhs );

		static inline ast::type::ImageConfiguration makeConfig();
		static inline ast::type::TypePtr makeType( ast::type::TypesCache & cache );
	};
}

#include "Texture.inl"

#endif
