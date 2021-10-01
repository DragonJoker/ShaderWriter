/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ShaderAST/Expr/EnumTextureAccess.hpp>
#include <ShaderAST/Expr/ExprTextureAccessCall.hpp>

namespace sdw
{
	//*****************************************************************************************

	namespace sampledImg
	{
		size_t constexpr ImgBaseCount = size_t( type::ImageDim::eBuffer ) + 1u;
		size_t constexpr ArrayImgCount = 3u;
		size_t constexpr NonShadowImgCount = ImgBaseCount + ArrayImgCount;
		size_t constexpr ShadowImgBaseCount = 4u;
		size_t constexpr ShadowArrayImgBaseCount = 3u;
		using IntrinsicsList = std::array< expr::TextureAccess, NonShadowImgCount + ShadowImgBaseCount + ShadowArrayImgBaseCount >;

		template< type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT >
			constexpr size_t getIndex()
		{
			if constexpr ( DepthT )
			{
				if constexpr ( ArrayedT )
				{
					if constexpr ( DimT == type::ImageDim::e1D )
					{
						return NonShadowImgCount + ShadowImgBaseCount + 0u;
					}
					else if constexpr ( DimT == type::ImageDim::e2D )
					{
						return NonShadowImgCount + ShadowImgBaseCount + 1u;
					}
					else if constexpr ( DimT == type::ImageDim::eCube )
					{
						return NonShadowImgCount + ShadowImgBaseCount + 2u;
					}
					else
					{
						assert( false );
						return size_t( expr::TextureAccess::eInvalid );
					}
				}
				else
				{
					if constexpr ( DimT == type::ImageDim::e1D )
					{
						return NonShadowImgCount +  0u;
					}
					else if constexpr ( DimT == type::ImageDim::e2D )
					{
						return NonShadowImgCount +  1u;
					}
					else if constexpr ( DimT == type::ImageDim::eCube )
					{
						return NonShadowImgCount +  2u;
					}
					else if constexpr ( DimT == type::ImageDim::eRect )
					{
						return NonShadowImgCount +  3u;
					}
					else
					{
						assert( false );
						return size_t( expr::TextureAccess::eInvalid );
					}
				}
			}
			else if constexpr ( ArrayedT )
			{
				if constexpr ( DimT == type::ImageDim::e1D )
				{
					return ImgBaseCount + 0u;
				}
				else if constexpr ( DimT == type::ImageDim::e2D )
				{
					return ImgBaseCount + 1u;
				}
				else if constexpr ( DimT == type::ImageDim::eCube )
				{
					return ImgBaseCount + 2u;
				}
				else
				{
					assert( false );
					return size_t( expr::TextureAccess::eInvalid );
				}
			}
			else
			{
				return size_t( DimT );
			}
		}

		static constexpr IntrinsicsList textureSizeF
		{
			expr::TextureAccess::eTextureSize1DF,
			expr::TextureAccess::eTextureSize2DF,
			expr::TextureAccess::eTextureSize3DF,
			expr::TextureAccess::eTextureSizeCubeF,
			expr::TextureAccess::eTextureSize2DRectF,
			expr::TextureAccess::eTextureSizeBufferF,

			expr::TextureAccess::eTextureSize1DArrayF,
			expr::TextureAccess::eTextureSize2DArrayF,
			expr::TextureAccess::eTextureSizeCubeArrayF,

			expr::TextureAccess::eTextureSize1DShadowF,
			expr::TextureAccess::eTextureSize2DShadowF,
			expr::TextureAccess::eTextureSizeCubeShadowF,
			expr::TextureAccess::eTextureSize2DRectShadowF,

			expr::TextureAccess::eTextureSize1DArrayShadowF,
			expr::TextureAccess::eTextureSize2DArrayShadowF,
			expr::TextureAccess::eTextureSizeCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureSizeI
		{
			expr::TextureAccess::eTextureSize1DI,
			expr::TextureAccess::eTextureSize2DI,
			expr::TextureAccess::eTextureSize3DI,
			expr::TextureAccess::eTextureSizeCubeI,
			expr::TextureAccess::eTextureSize2DRectI,
			expr::TextureAccess::eTextureSizeBufferI,

			expr::TextureAccess::eTextureSize1DArrayI,
			expr::TextureAccess::eTextureSize2DArrayI,
			expr::TextureAccess::eTextureSizeCubeArrayI,
		};
		static constexpr IntrinsicsList textureSizeU
		{
			expr::TextureAccess::eTextureSize1DU,
			expr::TextureAccess::eTextureSize2DU,
			expr::TextureAccess::eTextureSize3DU,
			expr::TextureAccess::eTextureSizeCubeU,
			expr::TextureAccess::eTextureSize2DRectU,
			expr::TextureAccess::eTextureSizeBufferU,

			expr::TextureAccess::eTextureSize1DArrayU,
			expr::TextureAccess::eTextureSize2DArrayU,
			expr::TextureAccess::eTextureSizeCubeArrayU,
		};

		static constexpr IntrinsicsList textureQueryLodF
		{
			expr::TextureAccess::eTextureQueryLod1DF,
			expr::TextureAccess::eTextureQueryLod2DF,
			expr::TextureAccess::eTextureQueryLod3DF,
			expr::TextureAccess::eTextureQueryLodCubeF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLod1DArrayF,
			expr::TextureAccess::eTextureQueryLod2DArrayF,
			expr::TextureAccess::eTextureQueryLodCubeArrayF,

			expr::TextureAccess::eTextureQueryLod1DShadowF,
			expr::TextureAccess::eTextureQueryLod2DShadowF,
			expr::TextureAccess::eTextureQueryLodCubeShadowF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLod1DArrayShadowF,
			expr::TextureAccess::eTextureQueryLod2DArrayShadowF,
			expr::TextureAccess::eTextureQueryLodCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureQueryLodI
		{
			expr::TextureAccess::eTextureQueryLod1DI,
			expr::TextureAccess::eTextureQueryLod2DI,
			expr::TextureAccess::eTextureQueryLod3DI,
			expr::TextureAccess::eTextureQueryLodCubeI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLod1DArrayI,
			expr::TextureAccess::eTextureQueryLod2DArrayI,
			expr::TextureAccess::eTextureQueryLodCubeArrayI,
		};
		static constexpr IntrinsicsList textureQueryLodU
		{
			expr::TextureAccess::eTextureQueryLod1DU,
			expr::TextureAccess::eTextureQueryLod2DU,
			expr::TextureAccess::eTextureQueryLod3DU,
			expr::TextureAccess::eTextureQueryLodCubeU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLod1DArrayU,
			expr::TextureAccess::eTextureQueryLod2DArrayU,
			expr::TextureAccess::eTextureQueryLodCubeArrayU,
		};

		static constexpr IntrinsicsList textureQueryLevelsF
		{
			expr::TextureAccess::eTextureQueryLevels1DF,
			expr::TextureAccess::eTextureQueryLevels2DF,
			expr::TextureAccess::eTextureQueryLevels3DF,
			expr::TextureAccess::eTextureQueryLevelsCubeF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLevels1DArrayF,
			expr::TextureAccess::eTextureQueryLevels2DArrayF,
			expr::TextureAccess::eTextureQueryLevelsCubeArrayF,

			expr::TextureAccess::eTextureQueryLevels1DShadowF,
			expr::TextureAccess::eTextureQueryLevels2DShadowF,
			expr::TextureAccess::eTextureQueryLevelsCubeShadowF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLevels1DArrayShadowF,
			expr::TextureAccess::eTextureQueryLevels2DArrayShadowF,
			expr::TextureAccess::eTextureQueryLevelsCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureQueryLevelsI
		{
			expr::TextureAccess::eTextureQueryLevels1DI,
			expr::TextureAccess::eTextureQueryLevels2DI,
			expr::TextureAccess::eTextureQueryLevels3DI,
			expr::TextureAccess::eTextureQueryLevelsCubeI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLevels1DArrayI,
			expr::TextureAccess::eTextureQueryLevels2DArrayI,
			expr::TextureAccess::eTextureQueryLevelsCubeArrayI,
		};
		static constexpr IntrinsicsList textureQueryLevelsU
		{
			expr::TextureAccess::eTextureQueryLevels1DU,
			expr::TextureAccess::eTextureQueryLevels2DU,
			expr::TextureAccess::eTextureQueryLevels3DU,
			expr::TextureAccess::eTextureQueryLevelsCubeU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureQueryLevels1DArrayU,
			expr::TextureAccess::eTextureQueryLevels2DArrayU,
			expr::TextureAccess::eTextureQueryLevelsCubeArrayU,
		};

		static constexpr IntrinsicsList textureF
		{
			expr::TextureAccess::eTexture1DF,
			expr::TextureAccess::eTexture2DF,
			expr::TextureAccess::eTexture3DF,
			expr::TextureAccess::eTextureCubeF,
			expr::TextureAccess::eTexture2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayF,
			expr::TextureAccess::eTexture2DArrayF,
			expr::TextureAccess::eTextureCubeArrayF,

			expr::TextureAccess::eTexture1DShadowF,
			expr::TextureAccess::eTexture2DShadowF,
			expr::TextureAccess::eTextureCubeShadowF,
			expr::TextureAccess::eTexture2DRectShadowF,

			expr::TextureAccess::eTexture1DArrayShadowF,
			expr::TextureAccess::eTexture2DArrayShadowF,
			expr::TextureAccess::eTextureCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureI
		{
			expr::TextureAccess::eTexture1DI,
			expr::TextureAccess::eTexture2DI,
			expr::TextureAccess::eTexture3DI,
			expr::TextureAccess::eTextureCubeI,
			expr::TextureAccess::eTexture2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayI,
			expr::TextureAccess::eTexture2DArrayI,
			expr::TextureAccess::eTextureCubeArrayI,
		};
		static constexpr IntrinsicsList textureU
		{
			expr::TextureAccess::eTexture1DU,
			expr::TextureAccess::eTexture2DU,
			expr::TextureAccess::eTexture3DU,
			expr::TextureAccess::eTextureCubeU,
			expr::TextureAccess::eTexture2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayU,
			expr::TextureAccess::eTexture2DArrayU,
			expr::TextureAccess::eTextureCubeArrayU,
		};

		static constexpr IntrinsicsList textureBiasF
		{
			expr::TextureAccess::eTexture1DFBias,
			expr::TextureAccess::eTexture2DFBias,
			expr::TextureAccess::eTexture3DFBias,
			expr::TextureAccess::eTextureCubeFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayFBias,
			expr::TextureAccess::eTexture2DArrayFBias,
			expr::TextureAccess::eTextureCubeArrayFBias,

			expr::TextureAccess::eTexture1DShadowFBias,
			expr::TextureAccess::eTexture2DShadowFBias,
			expr::TextureAccess::eTextureCubeShadowFBias,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayShadowFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureBiasI
		{
			expr::TextureAccess::eTexture1DIBias,
			expr::TextureAccess::eTexture2DIBias,
			expr::TextureAccess::eTexture3DIBias,
			expr::TextureAccess::eTextureCubeIBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayIBias,
			expr::TextureAccess::eTexture2DArrayIBias,
			expr::TextureAccess::eTextureCubeArrayIBias,
		};
		static constexpr IntrinsicsList textureBiasU
		{
			expr::TextureAccess::eTexture1DUBias,
			expr::TextureAccess::eTexture2DUBias,
			expr::TextureAccess::eTexture3DUBias,
			expr::TextureAccess::eTextureCubeUBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexture1DArrayUBias,
			expr::TextureAccess::eTexture2DArrayUBias,
			expr::TextureAccess::eTextureCubeArrayUBias,
		};

		static constexpr IntrinsicsList textureOffsetF
		{
			expr::TextureAccess::eTextureOffset1DF,
			expr::TextureAccess::eTextureOffset2DF,
			expr::TextureAccess::eTextureOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureOffset2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DArrayF,
			expr::TextureAccess::eTextureOffset2DArrayF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DShadowF,
			expr::TextureAccess::eTextureOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureOffset2DRectShadowF,

			expr::TextureAccess::eTextureOffset1DArrayShadowF,
			expr::TextureAccess::eTextureOffset2DArrayShadowF,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetI
		{
			expr::TextureAccess::eTextureOffset1DI,
			expr::TextureAccess::eTextureOffset2DI,
			expr::TextureAccess::eTextureOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureOffset2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DArrayI,
			expr::TextureAccess::eTextureOffset2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetU
		{
			expr::TextureAccess::eTextureOffset1DU,
			expr::TextureAccess::eTextureOffset2DU,
			expr::TextureAccess::eTextureOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureOffset2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DArrayU,
			expr::TextureAccess::eTextureOffset2DArrayU,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureOffsetBiasF
		{
			expr::TextureAccess::eTextureOffset1DFBias,
			expr::TextureAccess::eTextureOffset2DFBias,
			expr::TextureAccess::eTextureOffset3DFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DArrayFBias,
			expr::TextureAccess::eTextureOffset2DArrayFBias,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DShadowFBias,
			expr::TextureAccess::eTextureOffset2DShadowFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetBiasI
		{
			expr::TextureAccess::eTextureOffset1DIBias,
			expr::TextureAccess::eTextureOffset2DIBias,
			expr::TextureAccess::eTextureOffset3DIBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DArrayIBias,
			expr::TextureAccess::eTextureOffset2DArrayIBias,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetBiasU
		{
			expr::TextureAccess::eTextureOffset1DUBias,
			expr::TextureAccess::eTextureOffset2DUBias,
			expr::TextureAccess::eTextureOffset3DUBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureOffset1DArrayUBias,
			expr::TextureAccess::eTextureOffset2DArrayUBias,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjF
		{
			expr::TextureAccess::eTextureProj1DF2,
			expr::TextureAccess::eTextureProj2DF3,
			expr::TextureAccess::eTextureProj3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProj2DRectF3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProj1DShadowF,
			expr::TextureAccess::eTextureProj2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProj2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjI
		{
			expr::TextureAccess::eTextureProj1DI2,
			expr::TextureAccess::eTextureProj2DI3,
			expr::TextureAccess::eTextureProj3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProj2DRectI3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjU
		{
			expr::TextureAccess::eTextureProj1DU2,
			expr::TextureAccess::eTextureProj2DU3,
			expr::TextureAccess::eTextureProj3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProj2DRectU3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjBiasF
		{
			expr::TextureAccess::eTextureProj1DF2Bias,
			expr::TextureAccess::eTextureProj2DF3Bias,
			expr::TextureAccess::eTextureProj3DFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProj1DShadowFBias,
			expr::TextureAccess::eTextureProj2DShadowFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjBiasI
		{
			expr::TextureAccess::eTextureProj1DI2Bias,
			expr::TextureAccess::eTextureProj2DI3Bias,
			expr::TextureAccess::eTextureProj3DIBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjBiasU
		{
			expr::TextureAccess::eTextureProj1DU2Bias,
			expr::TextureAccess::eTextureProj2DU3Bias,
			expr::TextureAccess::eTextureProj3DUBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjOffsetF
		{
			expr::TextureAccess::eTextureProjOffset1DF2,
			expr::TextureAccess::eTextureProjOffset2DF3,
			expr::TextureAccess::eTextureProjOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjOffset2DRectF3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProjOffset1DShadowF,
			expr::TextureAccess::eTextureProjOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjOffset2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetI
		{
			expr::TextureAccess::eTextureProjOffset1DI2,
			expr::TextureAccess::eTextureProjOffset2DI3,
			expr::TextureAccess::eTextureProjOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjOffset2DRectI3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetU
		{
			expr::TextureAccess::eTextureProjOffset1DU2,
			expr::TextureAccess::eTextureProjOffset2DU3,
			expr::TextureAccess::eTextureProjOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjOffset2DRectU3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjOffsetBiasF
		{
			expr::TextureAccess::eTextureProjOffset1DF2Bias,
			expr::TextureAccess::eTextureProjOffset2DF3Bias,
			expr::TextureAccess::eTextureProjOffset3DFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProjOffset1DShadowFBias,
			expr::TextureAccess::eTextureProjOffset2DShadowFBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetBiasI
		{
			expr::TextureAccess::eTextureProjOffset1DI2Bias,
			expr::TextureAccess::eTextureProjOffset2DI3Bias,
			expr::TextureAccess::eTextureProjOffset3DIBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetBiasU
		{
			expr::TextureAccess::eTextureProjOffset1DU2Bias,
			expr::TextureAccess::eTextureProjOffset2DU3Bias,
			expr::TextureAccess::eTextureProjOffset3DUBias,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureLodF
		{
			expr::TextureAccess::eTextureLod1DF,
			expr::TextureAccess::eTextureLod2DF,
			expr::TextureAccess::eTextureLod3DF,
			expr::TextureAccess::eTextureLodCubeF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLod1DArrayF,
			expr::TextureAccess::eTextureLod2DArrayF,
			expr::TextureAccess::eTextureLodCubeArrayF,

			expr::TextureAccess::eTextureLod1DShadowF,
			expr::TextureAccess::eTextureLod2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLod1DArrayShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureLodI
		{
			expr::TextureAccess::eTextureLod1DI,
			expr::TextureAccess::eTextureLod2DI,
			expr::TextureAccess::eTextureLod3DI,
			expr::TextureAccess::eTextureLodCubeI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLod1DArrayI,
			expr::TextureAccess::eTextureLod2DArrayI,
			expr::TextureAccess::eTextureLodCubeArrayI,
		};
		static constexpr IntrinsicsList textureLodU
		{
			expr::TextureAccess::eTextureLod1DU,
			expr::TextureAccess::eTextureLod2DU,
			expr::TextureAccess::eTextureLod3DU,
			expr::TextureAccess::eTextureLodCubeU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLod1DArrayU,
			expr::TextureAccess::eTextureLod2DArrayU,
			expr::TextureAccess::eTextureLodCubeArrayU,
		};

		static constexpr IntrinsicsList textureLodOffsetF
		{
			expr::TextureAccess::eTextureLodOffset1DF,
			expr::TextureAccess::eTextureLodOffset2DF,
			expr::TextureAccess::eTextureLodOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLodOffset1DArrayF,
			expr::TextureAccess::eTextureLodOffset2DArrayF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLodOffset1DShadowF,
			expr::TextureAccess::eTextureLodOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLodOffset1DArrayShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureLodOffsetI
		{
			expr::TextureAccess::eTextureLodOffset1DI,
			expr::TextureAccess::eTextureLodOffset2DI,
			expr::TextureAccess::eTextureLodOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLodOffset1DArrayI,
			expr::TextureAccess::eTextureLodOffset2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureLodOffsetU
		{
			expr::TextureAccess::eTextureLodOffset1DU,
			expr::TextureAccess::eTextureLodOffset2DU,
			expr::TextureAccess::eTextureLodOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureLodOffset1DArrayU,
			expr::TextureAccess::eTextureLodOffset2DArrayU,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjLodF
		{
			expr::TextureAccess::eTextureProjLod1DF2,
			expr::TextureAccess::eTextureProjLod2DF3,
			expr::TextureAccess::eTextureProjLod3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProjLod1DShadowF,
			expr::TextureAccess::eTextureProjLod2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodI
		{
			expr::TextureAccess::eTextureProjLod1DI2,
			expr::TextureAccess::eTextureProjLod2DI3,
			expr::TextureAccess::eTextureProjLod3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodU
		{
			expr::TextureAccess::eTextureProjLod1DU2,
			expr::TextureAccess::eTextureProjLod2DU3,
			expr::TextureAccess::eTextureProjLod3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjLodOffsetF
		{
			expr::TextureAccess::eTextureProjLodOffset1DF2,
			expr::TextureAccess::eTextureProjLodOffset2DF3,
			expr::TextureAccess::eTextureProjLodOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProjLodOffset1DShadowF,
			expr::TextureAccess::eTextureProjLodOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodOffsetI
		{
			expr::TextureAccess::eTextureProjLodOffset1DI2,
			expr::TextureAccess::eTextureProjLodOffset2DI3,
			expr::TextureAccess::eTextureProjLodOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodOffsetU
		{
			expr::TextureAccess::eTextureProjLodOffset1DU2,
			expr::TextureAccess::eTextureProjLodOffset2DU3,
			expr::TextureAccess::eTextureProjLodOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList texelFetchF
		{
			expr::TextureAccess::eTexelFetch1DF,
			expr::TextureAccess::eTexelFetch2DF,
			expr::TextureAccess::eTexelFetch3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTexelFetch2DRectF,
			expr::TextureAccess::eTexelFetchBufferF,

			expr::TextureAccess::eTexelFetch1DArrayF,
			expr::TextureAccess::eTexelFetch2DArrayF,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchI
		{
			expr::TextureAccess::eTexelFetch1DI,
			expr::TextureAccess::eTexelFetch2DI,
			expr::TextureAccess::eTexelFetch3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTexelFetch2DRectI,
			expr::TextureAccess::eTexelFetchBufferI,

			expr::TextureAccess::eTexelFetch1DArrayI,
			expr::TextureAccess::eTexelFetch2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchU
		{
			expr::TextureAccess::eTexelFetch1DU,
			expr::TextureAccess::eTexelFetch2DU,
			expr::TextureAccess::eTexelFetch3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTexelFetch2DRectU,
			expr::TextureAccess::eTexelFetchBufferU,

			expr::TextureAccess::eTexelFetch1DArrayU,
			expr::TextureAccess::eTexelFetch2DArrayU,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList texelFetchOffsetF
		{
			expr::TextureAccess::eTexelFetchOffset1DF,
			expr::TextureAccess::eTexelFetchOffset2DF,
			expr::TextureAccess::eTexelFetchOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTexelFetchOffset2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexelFetchOffset1DArrayF,
			expr::TextureAccess::eTexelFetchOffset2DArrayF,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchOffsetI
		{
			expr::TextureAccess::eTexelFetchOffset1DI,
			expr::TextureAccess::eTexelFetchOffset2DI,
			expr::TextureAccess::eTexelFetchOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTexelFetchOffset2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexelFetchOffset1DArrayI,
			expr::TextureAccess::eTexelFetchOffset2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchOffsetU
		{
			expr::TextureAccess::eTexelFetchOffset1DU,
			expr::TextureAccess::eTexelFetchOffset2DU,
			expr::TextureAccess::eTexelFetchOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTexelFetchOffset2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTexelFetchOffset1DArrayU,
			expr::TextureAccess::eTexelFetchOffset2DArrayU,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureGradF
		{
			expr::TextureAccess::eTextureGrad1DF,
			expr::TextureAccess::eTextureGrad2DF,
			expr::TextureAccess::eTextureGrad3DF,
			expr::TextureAccess::eTextureGradCubeF,
			expr::TextureAccess::eTextureGrad2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGrad1DArrayF,
			expr::TextureAccess::eTextureGrad2DArrayF,
			expr::TextureAccess::eTextureGradCubeArrayF,

			expr::TextureAccess::eTextureGrad1DShadowF,
			expr::TextureAccess::eTextureGrad2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGrad2DRectShadowF,

			expr::TextureAccess::eTextureGrad1DArrayShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGradI
		{
			expr::TextureAccess::eTextureGrad1DI,
			expr::TextureAccess::eTextureGrad2DI,
			expr::TextureAccess::eTextureGrad3DI,
			expr::TextureAccess::eTextureGradCubeI,
			expr::TextureAccess::eTextureGrad2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGrad1DArrayI,
			expr::TextureAccess::eTextureGrad2DArrayI,
			expr::TextureAccess::eTextureGradCubeArrayI,
		};
		static constexpr IntrinsicsList textureGradU
		{
			expr::TextureAccess::eTextureGrad1DU,
			expr::TextureAccess::eTextureGrad2DU,
			expr::TextureAccess::eTextureGrad3DU,
			expr::TextureAccess::eTextureGradCubeU,
			expr::TextureAccess::eTextureGrad2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGrad1DArrayU,
			expr::TextureAccess::eTextureGrad2DArrayU,
			expr::TextureAccess::eTextureGradCubeArrayU,
		};

		static constexpr IntrinsicsList textureGradOffsetF
		{
			expr::TextureAccess::eTextureGradOffset1DF,
			expr::TextureAccess::eTextureGradOffset2DF,
			expr::TextureAccess::eTextureGradOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGradOffset2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGradOffset1DArrayF,
			expr::TextureAccess::eTextureGradOffset2DArrayF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGradOffset1DShadowF,
			expr::TextureAccess::eTextureGradOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGradOffset2DRectShadowF,

			expr::TextureAccess::eTextureGradOffset1DArrayShadowF,
			expr::TextureAccess::eTextureGradOffset2DArrayShadowF,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGradOffsetI
		{
			expr::TextureAccess::eTextureGradOffset1DI,
			expr::TextureAccess::eTextureGradOffset2DI,
			expr::TextureAccess::eTextureGradOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGradOffset2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGradOffset1DArrayI,
			expr::TextureAccess::eTextureGradOffset2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGradOffsetU
		{
			expr::TextureAccess::eTextureGradOffset1DU,
			expr::TextureAccess::eTextureGradOffset2DU,
			expr::TextureAccess::eTextureGradOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGradOffset2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureGradOffset1DArrayU,
			expr::TextureAccess::eTextureGradOffset2DArrayU,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjGradF
		{
			expr::TextureAccess::eTextureProjGrad1DF2,
			expr::TextureAccess::eTextureProjGrad2DF3,
			expr::TextureAccess::eTextureProjGrad3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGrad2DRectF3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProjGrad1DShadowF,
			expr::TextureAccess::eTextureProjGrad2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGrad2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradI
		{
			expr::TextureAccess::eTextureProjGrad1DI2,
			expr::TextureAccess::eTextureProjGrad2DI3,
			expr::TextureAccess::eTextureProjGrad3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGrad2DRectI3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradU
		{
			expr::TextureAccess::eTextureProjGrad1DU2,
			expr::TextureAccess::eTextureProjGrad2DU3,
			expr::TextureAccess::eTextureProjGrad3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGrad2DRectU3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjGradOffsetF
		{
			expr::TextureAccess::eTextureProjGradOffset1DF2,
			expr::TextureAccess::eTextureProjGradOffset2DF3,
			expr::TextureAccess::eTextureProjGradOffset3DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGradOffset2DRectF3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eTextureProjGradOffset1DShadowF,
			expr::TextureAccess::eTextureProjGradOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGradOffset2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradOffsetI
		{
			expr::TextureAccess::eTextureProjGradOffset1DI2,
			expr::TextureAccess::eTextureProjGradOffset2DI3,
			expr::TextureAccess::eTextureProjGradOffset3DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGradOffset2DRectI3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradOffsetU
		{
			expr::TextureAccess::eTextureProjGradOffset1DU2,
			expr::TextureAccess::eTextureProjGradOffset2DU3,
			expr::TextureAccess::eTextureProjGradOffset3DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureProjGradOffset2DRectU3,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureGatherF
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherCubeF,
			expr::TextureAccess::eTextureGather2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DArrayF,
			expr::TextureAccess::eTextureGatherCubeArrayF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DShadowF,
			expr::TextureAccess::eTextureGatherCubeShadowF,
			expr::TextureAccess::eTextureGather2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DArrayShadowF,
			expr::TextureAccess::eTextureGatherCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureGatherI
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherCubeI,
			expr::TextureAccess::eTextureGather2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DArrayI,
			expr::TextureAccess::eTextureGatherCubeArrayI,
		};
		static constexpr IntrinsicsList textureGatherU
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherCubeU,
			expr::TextureAccess::eTextureGather2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGather2DArrayU,
			expr::TextureAccess::eTextureGatherCubeArrayU,
		};

		static constexpr IntrinsicsList textureGatherOffsetF
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DArrayF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DArrayShadowF,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetI
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetU
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffset2DArrayU,
			expr::TextureAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureGatherOffsetsF
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DRectF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DArrayF,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DShadowF,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DRectShadowF,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DArrayShadowF,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetsI
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DI,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DRectI,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DArrayI,
			expr::TextureAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetsU
		{
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DU,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DRectU,
			expr::TextureAccess::eInvalid,

			expr::TextureAccess::eInvalid,
			expr::TextureAccess::eTextureGatherOffsets2DArrayU,
			expr::TextureAccess::eInvalid,
		};
	}

	//*************************************************************************

	template< type::ImageFormat FormatT >
	struct SampledImageFormatTraitsT< FormatT, std::enable_if_t< isFloatFormatV< FormatT > > >
	{
		static constexpr sampledImg::IntrinsicsList const & textureSize = sampledImg::textureSizeF;
		static constexpr sampledImg::IntrinsicsList const & textureQueryLod = sampledImg::textureQueryLodF;
		static constexpr sampledImg::IntrinsicsList const & textureQueryLevels = sampledImg::textureQueryLevelsF;
		static constexpr sampledImg::IntrinsicsList const & texture = sampledImg::textureF;
		static constexpr sampledImg::IntrinsicsList const & textureBias = sampledImg::textureBiasF;
		static constexpr sampledImg::IntrinsicsList const & textureOffset = sampledImg::textureOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureOffsetBias = sampledImg::textureOffsetBiasF;
		static constexpr sampledImg::IntrinsicsList const & textureProj = sampledImg::textureProjF;
		static constexpr sampledImg::IntrinsicsList const & textureProjBias = sampledImg::textureProjBiasF;
		static constexpr sampledImg::IntrinsicsList const & textureProjOffset = sampledImg::textureProjOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureProjOffsetBias = sampledImg::textureProjOffsetBiasF;
		static constexpr sampledImg::IntrinsicsList const & textureLod = sampledImg::textureLodF;
		static constexpr sampledImg::IntrinsicsList const & textureLodOffset = sampledImg::textureLodOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureProjLod = sampledImg::textureProjLodF;
		static constexpr sampledImg::IntrinsicsList const & textureProjLodOffset = sampledImg::textureProjLodOffsetF;
		static constexpr sampledImg::IntrinsicsList const & texelFetch = sampledImg::texelFetchF;
		static constexpr sampledImg::IntrinsicsList const & texelFetchOffset = sampledImg::texelFetchOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureGrad = sampledImg::textureGradF;
		static constexpr sampledImg::IntrinsicsList const & textureGradOffset = sampledImg::textureGradOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureProjGrad = sampledImg::textureProjGradF;
		static constexpr sampledImg::IntrinsicsList const & textureProjGradOffset = sampledImg::textureProjGradOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureGather = sampledImg::textureGatherF;
		static constexpr sampledImg::IntrinsicsList const & textureGatherOffset = sampledImg::textureGatherOffsetF;
		static constexpr sampledImg::IntrinsicsList const & textureGatherOffsets = sampledImg::textureGatherOffsetsF;
	};

	template< type::ImageFormat FormatT >
	struct SampledImageFormatTraitsT< FormatT, std::enable_if_t< isSIntFormatV< FormatT > > >
	{
		static constexpr sampledImg::IntrinsicsList const & textureSize = sampledImg::textureSizeI;
		static constexpr sampledImg::IntrinsicsList const & textureQueryLod = sampledImg::textureQueryLodI;
		static constexpr sampledImg::IntrinsicsList const & textureQueryLevels = sampledImg::textureQueryLevelsI;
		static constexpr sampledImg::IntrinsicsList const & texture = sampledImg::textureI;
		static constexpr sampledImg::IntrinsicsList const & textureBias = sampledImg::textureBiasI;
		static constexpr sampledImg::IntrinsicsList const & textureOffset = sampledImg::textureOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureOffsetBias = sampledImg::textureOffsetBiasI;
		static constexpr sampledImg::IntrinsicsList const & textureProj = sampledImg::textureProjI;
		static constexpr sampledImg::IntrinsicsList const & textureProjBias = sampledImg::textureProjBiasI;
		static constexpr sampledImg::IntrinsicsList const & textureProjOffset = sampledImg::textureProjOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureProjOffsetBias = sampledImg::textureProjOffsetBiasI;
		static constexpr sampledImg::IntrinsicsList const & textureLod = sampledImg::textureLodI;
		static constexpr sampledImg::IntrinsicsList const & textureLodOffset = sampledImg::textureLodOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureProjLod = sampledImg::textureProjLodI;
		static constexpr sampledImg::IntrinsicsList const & textureProjLodOffset = sampledImg::textureProjLodOffsetI;
		static constexpr sampledImg::IntrinsicsList const & texelFetch = sampledImg::texelFetchI;
		static constexpr sampledImg::IntrinsicsList const & texelFetchOffset = sampledImg::texelFetchOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureGrad = sampledImg::textureGradI;
		static constexpr sampledImg::IntrinsicsList const & textureGradOffset = sampledImg::textureGradOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureProjGrad = sampledImg::textureProjGradI;
		static constexpr sampledImg::IntrinsicsList const & textureProjGradOffset = sampledImg::textureProjGradOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureGather = sampledImg::textureGatherI;
		static constexpr sampledImg::IntrinsicsList const & textureGatherOffset = sampledImg::textureGatherOffsetI;
		static constexpr sampledImg::IntrinsicsList const & textureGatherOffsets = sampledImg::textureGatherOffsetsI;
	};

	template< type::ImageFormat FormatT >
	struct SampledImageFormatTraitsT< FormatT, std::enable_if_t< isUIntFormatV< FormatT > > >
	{
		static constexpr sampledImg::IntrinsicsList const & textureSize = sampledImg::textureSizeU;
		static constexpr sampledImg::IntrinsicsList const & textureQueryLod = sampledImg::textureQueryLodU;
		static constexpr sampledImg::IntrinsicsList const & textureQueryLevels = sampledImg::textureQueryLevelsU;
		static constexpr sampledImg::IntrinsicsList const & texture = sampledImg::textureU;
		static constexpr sampledImg::IntrinsicsList const & textureBias = sampledImg::textureBiasU;
		static constexpr sampledImg::IntrinsicsList const & textureOffset = sampledImg::textureOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureOffsetBias = sampledImg::textureOffsetBiasU;
		static constexpr sampledImg::IntrinsicsList const & textureProj = sampledImg::textureProjU;
		static constexpr sampledImg::IntrinsicsList const & textureProjBias = sampledImg::textureProjBiasU;
		static constexpr sampledImg::IntrinsicsList const & textureProjOffset = sampledImg::textureProjOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureProjOffsetBias = sampledImg::textureProjOffsetBiasU;
		static constexpr sampledImg::IntrinsicsList const & textureLod = sampledImg::textureLodU;
		static constexpr sampledImg::IntrinsicsList const & textureLodOffset = sampledImg::textureLodOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureProjLod = sampledImg::textureProjLodU;
		static constexpr sampledImg::IntrinsicsList const & textureProjLodOffset = sampledImg::textureProjLodOffsetU;
		static constexpr sampledImg::IntrinsicsList const & texelFetch = sampledImg::texelFetchU;
		static constexpr sampledImg::IntrinsicsList const & texelFetchOffset = sampledImg::texelFetchOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureGrad = sampledImg::textureGradU;
		static constexpr sampledImg::IntrinsicsList const & textureGradOffset = sampledImg::textureGradOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureProjGrad = sampledImg::textureProjGradU;
		static constexpr sampledImg::IntrinsicsList const & textureProjGradOffset = sampledImg::textureProjGradOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureGather = sampledImg::textureGatherU;
		static constexpr sampledImg::IntrinsicsList const & textureGatherOffset = sampledImg::textureGatherOffsetU;
		static constexpr sampledImg::IntrinsicsList const & textureGatherOffsets = sampledImg::textureGatherOffsetsU;
	};
	
	//*************************************************************************

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::eBuffer, false >
	{
		using SampleType = sdw::Int;
		using FetchType = sdw::Int;
		using SizeType = sdw::Int;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e1D, false >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Float;
		using ProjType = sdw::Vec2;
		using OffsetType = sdw::Int;
		using FetchType = sdw::Int;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::Int;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e2D, false >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec2;
		using ProjType = sdw::Vec3;
		using OffsetType = sdw::IVec2;
		using FetchType = sdw::IVec2;
		using DerivativeType = sdw::Vec2;
		using GatherType = sdw::Vec2;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e3D, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
		using ProjType = sdw::Vec4;
		using OffsetType = sdw::IVec3;
		using FetchType = sdw::IVec3;
		using DerivativeType = sdw::Vec3;
		using SizeType = sdw::IVec3;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::eCube, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using FetchType = sdw::Vec3;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e1D, true >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Vec2;
		using OffsetType = sdw::Int;
		using FetchType = sdw::IVec2;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e2D, true >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec3;
		using OffsetType = sdw::IVec2;
		using FetchType = sdw::IVec3;
		using DerivativeType = sdw::Vec2;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::IVec3;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::eCube, true >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec4;
		using FetchType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using GatherType = sdw::Vec4;
		using SizeType = sdw::IVec3;
	};

	namespace sampledImg
	{
		//*****************************************************************************************

		template< typename ReturnT
			, type::ImageFormat FormatT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT
			, expr::TextureAccess TextureAccessT
			, typename ... ParamsT >
		ReturnT writeTextureAccessCall( SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & image
			, ParamsT const & ... params )
		{
			static_assert( TextureAccessT != expr::TextureAccess::eInvalid );
			static_assert( TextureAccessT != expr::TextureAccess::eUndefined );

			auto & cache = findTypesCache( image, params... );
			return ReturnT{ findWriterMandat( image, params... )
				, expr::makeTextureAccessCall( ReturnT::makeType( cache )
					, TextureAccessT
					, makeExpr( image )
					, makeExpr( params )... )
				, areOptionalEnabled( image, params... ) };
		}

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct TexSizeFuncT
		{
			using SizeT = SampledImageSizeT< DimT, ArrayedT >;

			SizeT getSize()const
			{
				return writeTextureAccessCall< SizeT, FormatT, DimT, ArrayedT, DepthT, MsT
					, SampledImageFormatTraitsT< FormatT >::textureSize[sampledImg::getIndex< DimT, ArrayedT, DepthT >()] >( get() );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct TexSizeLevelFuncT
		{
			using SizeT = SampledImageSizeT< DimT, ArrayedT >;

			SizeT getSize( Int const & level )const
			{
				return writeTextureAccessCall< SizeT, FormatT, DimT, ArrayedT, DepthT, MsT
					, SampledImageFormatTraitsT< FormatT >::textureSize[sampledImg::getIndex< DimT, ArrayedT, DepthT >()] >( get()
						, level );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct QueryLodFuncT
		{
			using QueryLodT = SampledImageQueryLodT< DimT, ArrayedT >;

			Vec2 getLod( QueryLodT const & coord )const
			{
				return writeTextureAccessCall< Vec2, FormatT, DimT, ArrayedT, DepthT, MsT
					, SampledImageFormatTraitsT< FormatT >::textureQueryLod[sampledImg::getIndex< DimT, ArrayedT, DepthT >()] >( get()
						, coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct QueryLevelsFuncT
		{
			Int getLevels()const
			{
				return writeTextureAccessCall< Int, FormatT, DimT, ArrayedT, DepthT, MsT
					, SampledImageFormatTraitsT< FormatT >::textureQueryLevels[sampledImg::getIndex< DimT, ArrayedT, DepthT >()] >( get() );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::texture[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, Float const & ref )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::texture[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, Float const & bias )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, Float const & ref
				, Float const & bias )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleOffsetBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureOffsetBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefOffsetBiasFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > sample( SampleT const & coord
				, Float const & ref
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureOffsetBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleLodFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			ImageSampleT< FormatT > lod( SampleT const & coord
				, Float const & lod )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureLod[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefLodFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			ImageSampleT< FormatT > lod( SampleT const & coord
				, Float const & ref
				, Float const & lod )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureLod[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleLodOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > lod( SampleT const & coord
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureLodOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefLodOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > lod( SampleT const & coord
				, Float const & ref
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureLodOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProj[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, Float const & ref )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProj[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, Float const & bias )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, Float const & ref
				, Float const & bias )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjOffsetBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjOffsetBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjOffsetBiasFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > proj( SampleProjT const & coord
				, Float const & ref
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjOffsetBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjLodFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projLod( SampleProjT const & coord
				, Float const & lod )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjLod[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjLodFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projLod( SampleProjT const & coord
				, Float const & ref
				, Float const & lod )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjLod[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjLodOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projLod( SampleProjT const & coord
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjLodOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjLodOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projLod( SampleProjT const & coord
				, Float const & ref
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjLodOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchFuncT
		{
			using FetchT = SampledImageFetchT< DimT, ArrayedT >;

			ImageSampleT< FormatT > fetch( FetchT const & coord )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::texelFetch[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchLevelFuncT
		{
			using FetchT = SampledImageFetchT< DimT, ArrayedT >;

			ImageSampleT< FormatT > fetch( FetchT const & coord
				, Int const & level )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::texelFetch[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, level );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchLevelOffsetFuncT
		{
			using FetchT = SampledImageFetchT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > fetch( FetchT const & coord
				, Int const & level
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::texelFetchOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, level
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			ImageSampleT< FormatT > grad( SampleT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGrad[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			ImageSampleT< FormatT > grad( SampleT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGrad[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > grad( SampleT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGradOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefOffsetFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > grad( SampleT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGradOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projGrad( SampleProjT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjGrad[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefProjFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projGrad( SampleProjT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjGrad[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projGrad( SampleProjT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjGradOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};
		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefProjOffsetFuncT
		{
			using SampleProjT = SampledImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = SampledImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageSampleT< FormatT > projGrad( SampleProjT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeTextureAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureProjGradOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
			struct GatherFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;

			ImageGatherT< FormatT > gather( GatherT const & coord
				, Int const & comp )const
			{
				return writeTextureAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGather[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, comp );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;

			ImageGatherT< FormatT > gather( GatherT const & coord
				, Float const & ref )const
			{
				return writeTextureAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGather[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageGatherT< FormatT > gather( GatherT const & coord
				, Int const & comp
				, OffsetT const & offset )const
			{
				return writeTextureAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGatherOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, comp
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefOffsetFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageGatherT< FormatT > gather( GatherT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				return writeTextureAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGatherOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetsFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageGatherT< FormatT > gather( GatherT const & coord
				, Int const & comp
				, Array< OffsetT > const & offsets )const
			{
				return writeTextureAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, false, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGatherOffsets[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, comp
						, offsets );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, false, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefOffsetsFuncT
		{
			using GatherT = SampledImageGatherT< DimT, ArrayedT >;
			using OffsetT = SampledImageOffsetT< DimT, ArrayedT >;

			ImageGatherT< FormatT > gather( GatherT const & coord
				, Float const & ref
				, Array< OffsetT > const & offsets )const
			{
				return writeTextureAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, true, MsT
					, SampledImageFormatTraitsT< FormatT >::textureGatherOffsets[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offsets );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, true, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dArrayV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dArrayV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >
			, public FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using FetchLevelFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using FetchLevelOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::fetch;
			using GradFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjLodFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using SampleRefProjLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projLod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isRectShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using SampleRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::proj;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefProjFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GradRefProjOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::projGrad;
			using GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::gather;
			using GatherRefOffsetsFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool DepthT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, DepthT
			, MsT
			, std::enable_if_t< ( sdw::isBufferV< DimT, ArrayedT, DepthT > ) > >
			: public SampledImage
			, public TexSizeFuncT< FormatT, DimT, ArrayedT, DepthT, MsT >
			, public FetchFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , SampledImageFuncsT );

			SampledImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: SampledImage{ FormatT, writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			SampledImageFuncsT & operator=( T const & rhs )
			{
				SampledImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	}

	template< typename T >
	SampledImage & SampledImage::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = findWriterMandat( *this, rhs );

		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( shader
				, sdw::makeSimple( sdw::makeAssign( getExpr()->getType()
					, makeExpr( shader, getExpr() )
					, makeExpr( shader, rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::SampledImageT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: sampledImg::SampledImageFuncsT< FormatT, DimT, ArrayedT, DepthT, MsT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	template< typename T >
	SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT > & SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::operator=( T const & rhs )
	{
		sampledImg::SampledImageFuncsT< FormatT, DimT, ArrayedT, DepthT, MsT >::operator=( rhs );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	ast::type::ImageConfiguration SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, ast::type::AccessKind::eRead, DimT, ArrayedT, DepthT, MsT >( true );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	inline ast::type::TypePtr SampledImageT< FormatT, DimT, ArrayedT, DepthT, MsT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getSampledImage( makeConfig() );
	}

	//*************************************************************************
}
