/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ShaderAST/Expr/EnumCombinedImageAccess.hpp>
#include <ShaderAST/Expr/ExprCombinedImageAccessCall.hpp>

namespace sdw
{
	//*****************************************************************************************

	namespace combinedSmplImg
	{
		size_t constexpr ImgBaseCount = size_t( type::ImageDim::eBuffer ) + 1u;
		size_t constexpr ArrayImgCount = 3u;
		size_t constexpr NonShadowImgCount = ImgBaseCount + ArrayImgCount;
		size_t constexpr ShadowImgBaseCount = 3u;
		size_t constexpr ShadowArrayImgBaseCount = 3u;
		using IntrinsicsList = std::array< expr::CombinedImageAccess, NonShadowImgCount + ShadowImgBaseCount + ShadowArrayImgBaseCount >;

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
						return size_t( expr::CombinedImageAccess::eInvalid );
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
					else
					{
						assert( false );
						return size_t( expr::CombinedImageAccess::eInvalid );
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
					return size_t( expr::CombinedImageAccess::eInvalid );
				}
			}
			else
			{
				return size_t( DimT );
			}
		}

		static constexpr IntrinsicsList textureSizeF
		{
			expr::CombinedImageAccess::eTextureSize1DF,
			expr::CombinedImageAccess::eTextureSize2DF,
			expr::CombinedImageAccess::eTextureSize3DF,
			expr::CombinedImageAccess::eTextureSizeCubeF,
			expr::CombinedImageAccess::eTextureSizeBufferF,

			expr::CombinedImageAccess::eTextureSize1DArrayF,
			expr::CombinedImageAccess::eTextureSize2DArrayF,
			expr::CombinedImageAccess::eTextureSizeCubeArrayF,

			expr::CombinedImageAccess::eTextureSize1DShadowF,
			expr::CombinedImageAccess::eTextureSize2DShadowF,
			expr::CombinedImageAccess::eTextureSizeCubeShadowF,

			expr::CombinedImageAccess::eTextureSize1DArrayShadowF,
			expr::CombinedImageAccess::eTextureSize2DArrayShadowF,
			expr::CombinedImageAccess::eTextureSizeCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureSizeI
		{
			expr::CombinedImageAccess::eTextureSize1DI,
			expr::CombinedImageAccess::eTextureSize2DI,
			expr::CombinedImageAccess::eTextureSize3DI,
			expr::CombinedImageAccess::eTextureSizeCubeI,
			expr::CombinedImageAccess::eTextureSizeBufferI,

			expr::CombinedImageAccess::eTextureSize1DArrayI,
			expr::CombinedImageAccess::eTextureSize2DArrayI,
			expr::CombinedImageAccess::eTextureSizeCubeArrayI,
		};
		static constexpr IntrinsicsList textureSizeU
		{
			expr::CombinedImageAccess::eTextureSize1DU,
			expr::CombinedImageAccess::eTextureSize2DU,
			expr::CombinedImageAccess::eTextureSize3DU,
			expr::CombinedImageAccess::eTextureSizeCubeU,
			expr::CombinedImageAccess::eTextureSizeBufferU,

			expr::CombinedImageAccess::eTextureSize1DArrayU,
			expr::CombinedImageAccess::eTextureSize2DArrayU,
			expr::CombinedImageAccess::eTextureSizeCubeArrayU,
		};

		static constexpr IntrinsicsList textureQueryLodF
		{
			expr::CombinedImageAccess::eTextureQueryLod1DF,
			expr::CombinedImageAccess::eTextureQueryLod2DF,
			expr::CombinedImageAccess::eTextureQueryLod3DF,
			expr::CombinedImageAccess::eTextureQueryLodCubeF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureQueryLod1DArrayF,
			expr::CombinedImageAccess::eTextureQueryLod2DArrayF,
			expr::CombinedImageAccess::eTextureQueryLodCubeArrayF,

			expr::CombinedImageAccess::eTextureQueryLod1DShadowF,
			expr::CombinedImageAccess::eTextureQueryLod2DShadowF,
			expr::CombinedImageAccess::eTextureQueryLodCubeShadowF,

			expr::CombinedImageAccess::eTextureQueryLod1DArrayShadowF,
			expr::CombinedImageAccess::eTextureQueryLod2DArrayShadowF,
			expr::CombinedImageAccess::eTextureQueryLodCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureQueryLodI
		{
			expr::CombinedImageAccess::eTextureQueryLod1DI,
			expr::CombinedImageAccess::eTextureQueryLod2DI,
			expr::CombinedImageAccess::eTextureQueryLod3DI,
			expr::CombinedImageAccess::eTextureQueryLodCubeI,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureQueryLod1DArrayI,
			expr::CombinedImageAccess::eTextureQueryLod2DArrayI,
			expr::CombinedImageAccess::eTextureQueryLodCubeArrayI,
		};
		static constexpr IntrinsicsList textureQueryLodU
		{
			expr::CombinedImageAccess::eTextureQueryLod1DU,
			expr::CombinedImageAccess::eTextureQueryLod2DU,
			expr::CombinedImageAccess::eTextureQueryLod3DU,
			expr::CombinedImageAccess::eTextureQueryLodCubeU,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureQueryLod1DArrayU,
			expr::CombinedImageAccess::eTextureQueryLod2DArrayU,
			expr::CombinedImageAccess::eTextureQueryLodCubeArrayU,
		};

		static constexpr IntrinsicsList textureQueryLevelsF
		{
			expr::CombinedImageAccess::eTextureQueryLevels1DF,
			expr::CombinedImageAccess::eTextureQueryLevels2DF,
			expr::CombinedImageAccess::eTextureQueryLevels3DF,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureQueryLevels1DArrayF,
			expr::CombinedImageAccess::eTextureQueryLevels2DArrayF,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayF,

			expr::CombinedImageAccess::eTextureQueryLevels1DShadowF,
			expr::CombinedImageAccess::eTextureQueryLevels2DShadowF,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeShadowF,

			expr::CombinedImageAccess::eTextureQueryLevels1DArrayShadowF,
			expr::CombinedImageAccess::eTextureQueryLevels2DArrayShadowF,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureQueryLevelsI
		{
			expr::CombinedImageAccess::eTextureQueryLevels1DI,
			expr::CombinedImageAccess::eTextureQueryLevels2DI,
			expr::CombinedImageAccess::eTextureQueryLevels3DI,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeI,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureQueryLevels1DArrayI,
			expr::CombinedImageAccess::eTextureQueryLevels2DArrayI,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayI,
		};
		static constexpr IntrinsicsList textureQueryLevelsU
		{
			expr::CombinedImageAccess::eTextureQueryLevels1DU,
			expr::CombinedImageAccess::eTextureQueryLevels2DU,
			expr::CombinedImageAccess::eTextureQueryLevels3DU,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeU,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureQueryLevels1DArrayU,
			expr::CombinedImageAccess::eTextureQueryLevels2DArrayU,
			expr::CombinedImageAccess::eTextureQueryLevelsCubeArrayU,
		};

		static constexpr IntrinsicsList textureF
		{
			expr::CombinedImageAccess::eTexture1DF,
			expr::CombinedImageAccess::eTexture2DF,
			expr::CombinedImageAccess::eTexture3DF,
			expr::CombinedImageAccess::eTextureCubeF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexture1DArrayF,
			expr::CombinedImageAccess::eTexture2DArrayF,
			expr::CombinedImageAccess::eTextureCubeArrayF,

			expr::CombinedImageAccess::eTexture1DShadowF,
			expr::CombinedImageAccess::eTexture2DShadowF,
			expr::CombinedImageAccess::eTextureCubeShadowF,

			expr::CombinedImageAccess::eTexture1DArrayShadowF,
			expr::CombinedImageAccess::eTexture2DArrayShadowF,
			expr::CombinedImageAccess::eTextureCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureI
		{
			expr::CombinedImageAccess::eTexture1DI,
			expr::CombinedImageAccess::eTexture2DI,
			expr::CombinedImageAccess::eTexture3DI,
			expr::CombinedImageAccess::eTextureCubeI,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexture1DArrayI,
			expr::CombinedImageAccess::eTexture2DArrayI,
			expr::CombinedImageAccess::eTextureCubeArrayI,
		};
		static constexpr IntrinsicsList textureU
		{
			expr::CombinedImageAccess::eTexture1DU,
			expr::CombinedImageAccess::eTexture2DU,
			expr::CombinedImageAccess::eTexture3DU,
			expr::CombinedImageAccess::eTextureCubeU,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexture1DArrayU,
			expr::CombinedImageAccess::eTexture2DArrayU,
			expr::CombinedImageAccess::eTextureCubeArrayU,
		};

		static constexpr IntrinsicsList textureBiasF
		{
			expr::CombinedImageAccess::eTexture1DFBias,
			expr::CombinedImageAccess::eTexture2DFBias,
			expr::CombinedImageAccess::eTexture3DFBias,
			expr::CombinedImageAccess::eTextureCubeFBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexture1DArrayFBias,
			expr::CombinedImageAccess::eTexture2DArrayFBias,
			expr::CombinedImageAccess::eTextureCubeArrayFBias,

			expr::CombinedImageAccess::eTexture1DShadowFBias,
			expr::CombinedImageAccess::eTexture2DShadowFBias,
			expr::CombinedImageAccess::eTextureCubeShadowFBias,

			expr::CombinedImageAccess::eTexture1DArrayShadowFBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureBiasI
		{
			expr::CombinedImageAccess::eTexture1DIBias,
			expr::CombinedImageAccess::eTexture2DIBias,
			expr::CombinedImageAccess::eTexture3DIBias,
			expr::CombinedImageAccess::eTextureCubeIBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexture1DArrayIBias,
			expr::CombinedImageAccess::eTexture2DArrayIBias,
			expr::CombinedImageAccess::eTextureCubeArrayIBias,
		};
		static constexpr IntrinsicsList textureBiasU
		{
			expr::CombinedImageAccess::eTexture1DUBias,
			expr::CombinedImageAccess::eTexture2DUBias,
			expr::CombinedImageAccess::eTexture3DUBias,
			expr::CombinedImageAccess::eTextureCubeUBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexture1DArrayUBias,
			expr::CombinedImageAccess::eTexture2DArrayUBias,
			expr::CombinedImageAccess::eTextureCubeArrayUBias,
		};

		static constexpr IntrinsicsList textureOffsetF
		{
			expr::CombinedImageAccess::eTextureOffset1DF,
			expr::CombinedImageAccess::eTextureOffset2DF,
			expr::CombinedImageAccess::eTextureOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayF,
			expr::CombinedImageAccess::eTextureOffset2DArrayF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DShadowF,
			expr::CombinedImageAccess::eTextureOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayShadowF,
			expr::CombinedImageAccess::eTextureOffset2DArrayShadowF,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetI
		{
			expr::CombinedImageAccess::eTextureOffset1DI,
			expr::CombinedImageAccess::eTextureOffset2DI,
			expr::CombinedImageAccess::eTextureOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayI,
			expr::CombinedImageAccess::eTextureOffset2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetU
		{
			expr::CombinedImageAccess::eTextureOffset1DU,
			expr::CombinedImageAccess::eTextureOffset2DU,
			expr::CombinedImageAccess::eTextureOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayU,
			expr::CombinedImageAccess::eTextureOffset2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureOffsetBiasF
		{
			expr::CombinedImageAccess::eTextureOffset1DFBias,
			expr::CombinedImageAccess::eTextureOffset2DFBias,
			expr::CombinedImageAccess::eTextureOffset3DFBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayFBias,
			expr::CombinedImageAccess::eTextureOffset2DArrayFBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DShadowFBias,
			expr::CombinedImageAccess::eTextureOffset2DShadowFBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetBiasI
		{
			expr::CombinedImageAccess::eTextureOffset1DIBias,
			expr::CombinedImageAccess::eTextureOffset2DIBias,
			expr::CombinedImageAccess::eTextureOffset3DIBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayIBias,
			expr::CombinedImageAccess::eTextureOffset2DArrayIBias,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureOffsetBiasU
		{
			expr::CombinedImageAccess::eTextureOffset1DUBias,
			expr::CombinedImageAccess::eTextureOffset2DUBias,
			expr::CombinedImageAccess::eTextureOffset3DUBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureOffset1DArrayUBias,
			expr::CombinedImageAccess::eTextureOffset2DArrayUBias,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjF
		{
			expr::CombinedImageAccess::eTextureProj1DF2,
			expr::CombinedImageAccess::eTextureProj2DF3,
			expr::CombinedImageAccess::eTextureProj3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProj1DShadowF,
			expr::CombinedImageAccess::eTextureProj2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjI
		{
			expr::CombinedImageAccess::eTextureProj1DI2,
			expr::CombinedImageAccess::eTextureProj2DI3,
			expr::CombinedImageAccess::eTextureProj3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjU
		{
			expr::CombinedImageAccess::eTextureProj1DU2,
			expr::CombinedImageAccess::eTextureProj2DU3,
			expr::CombinedImageAccess::eTextureProj3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjBiasF
		{
			expr::CombinedImageAccess::eTextureProj1DF2Bias,
			expr::CombinedImageAccess::eTextureProj2DF3Bias,
			expr::CombinedImageAccess::eTextureProj3DFBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProj1DShadowFBias,
			expr::CombinedImageAccess::eTextureProj2DShadowFBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjBiasI
		{
			expr::CombinedImageAccess::eTextureProj1DI2Bias,
			expr::CombinedImageAccess::eTextureProj2DI3Bias,
			expr::CombinedImageAccess::eTextureProj3DIBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjBiasU
		{
			expr::CombinedImageAccess::eTextureProj1DU2Bias,
			expr::CombinedImageAccess::eTextureProj2DU3Bias,
			expr::CombinedImageAccess::eTextureProj3DUBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjOffsetF
		{
			expr::CombinedImageAccess::eTextureProjOffset1DF2,
			expr::CombinedImageAccess::eTextureProjOffset2DF3,
			expr::CombinedImageAccess::eTextureProjOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProjOffset1DShadowF,
			expr::CombinedImageAccess::eTextureProjOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetI
		{
			expr::CombinedImageAccess::eTextureProjOffset1DI2,
			expr::CombinedImageAccess::eTextureProjOffset2DI3,
			expr::CombinedImageAccess::eTextureProjOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetU
		{
			expr::CombinedImageAccess::eTextureProjOffset1DU2,
			expr::CombinedImageAccess::eTextureProjOffset2DU3,
			expr::CombinedImageAccess::eTextureProjOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjOffsetBiasF
		{
			expr::CombinedImageAccess::eTextureProjOffset1DF2Bias,
			expr::CombinedImageAccess::eTextureProjOffset2DF3Bias,
			expr::CombinedImageAccess::eTextureProjOffset3DFBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProjOffset1DShadowFBias,
			expr::CombinedImageAccess::eTextureProjOffset2DShadowFBias,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetBiasI
		{
			expr::CombinedImageAccess::eTextureProjOffset1DI2Bias,
			expr::CombinedImageAccess::eTextureProjOffset2DI3Bias,
			expr::CombinedImageAccess::eTextureProjOffset3DIBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjOffsetBiasU
		{
			expr::CombinedImageAccess::eTextureProjOffset1DU2Bias,
			expr::CombinedImageAccess::eTextureProjOffset2DU3Bias,
			expr::CombinedImageAccess::eTextureProjOffset3DUBias,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureLodF
		{
			expr::CombinedImageAccess::eTextureLod1DF,
			expr::CombinedImageAccess::eTextureLod2DF,
			expr::CombinedImageAccess::eTextureLod3DF,
			expr::CombinedImageAccess::eTextureLodCubeF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLod1DArrayF,
			expr::CombinedImageAccess::eTextureLod2DArrayF,
			expr::CombinedImageAccess::eTextureLodCubeArrayF,

			expr::CombinedImageAccess::eTextureLod1DShadowF,
			expr::CombinedImageAccess::eTextureLod2DShadowF,
			expr::CombinedImageAccess::eTextureLodCubeShadowF,

			expr::CombinedImageAccess::eTextureLod1DArrayShadowF,
			expr::CombinedImageAccess::eTextureLod2DArrayShadowF,
			expr::CombinedImageAccess::eTextureLodCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureLodI
		{
			expr::CombinedImageAccess::eTextureLod1DI,
			expr::CombinedImageAccess::eTextureLod2DI,
			expr::CombinedImageAccess::eTextureLod3DI,
			expr::CombinedImageAccess::eTextureLodCubeI,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLod1DArrayI,
			expr::CombinedImageAccess::eTextureLod2DArrayI,
			expr::CombinedImageAccess::eTextureLodCubeArrayI,
		};
		static constexpr IntrinsicsList textureLodU
		{
			expr::CombinedImageAccess::eTextureLod1DU,
			expr::CombinedImageAccess::eTextureLod2DU,
			expr::CombinedImageAccess::eTextureLod3DU,
			expr::CombinedImageAccess::eTextureLodCubeU,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLod1DArrayU,
			expr::CombinedImageAccess::eTextureLod2DArrayU,
			expr::CombinedImageAccess::eTextureLodCubeArrayU,
		};

		static constexpr IntrinsicsList textureLodOffsetF
		{
			expr::CombinedImageAccess::eTextureLodOffset1DF,
			expr::CombinedImageAccess::eTextureLodOffset2DF,
			expr::CombinedImageAccess::eTextureLodOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLodOffset1DArrayF,
			expr::CombinedImageAccess::eTextureLodOffset2DArrayF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLodOffset1DShadowF,
			expr::CombinedImageAccess::eTextureLodOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLodOffset1DArrayShadowF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureLodOffsetI
		{
			expr::CombinedImageAccess::eTextureLodOffset1DI,
			expr::CombinedImageAccess::eTextureLodOffset2DI,
			expr::CombinedImageAccess::eTextureLodOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLodOffset1DArrayI,
			expr::CombinedImageAccess::eTextureLodOffset2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureLodOffsetU
		{
			expr::CombinedImageAccess::eTextureLodOffset1DU,
			expr::CombinedImageAccess::eTextureLodOffset2DU,
			expr::CombinedImageAccess::eTextureLodOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureLodOffset1DArrayU,
			expr::CombinedImageAccess::eTextureLodOffset2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjLodF
		{
			expr::CombinedImageAccess::eTextureProjLod1DF2,
			expr::CombinedImageAccess::eTextureProjLod2DF3,
			expr::CombinedImageAccess::eTextureProjLod3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProjLod1DShadowF,
			expr::CombinedImageAccess::eTextureProjLod2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodI
		{
			expr::CombinedImageAccess::eTextureProjLod1DI2,
			expr::CombinedImageAccess::eTextureProjLod2DI3,
			expr::CombinedImageAccess::eTextureProjLod3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodU
		{
			expr::CombinedImageAccess::eTextureProjLod1DU2,
			expr::CombinedImageAccess::eTextureProjLod2DU3,
			expr::CombinedImageAccess::eTextureProjLod3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjLodOffsetF
		{
			expr::CombinedImageAccess::eTextureProjLodOffset1DF2,
			expr::CombinedImageAccess::eTextureProjLodOffset2DF3,
			expr::CombinedImageAccess::eTextureProjLodOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProjLodOffset1DShadowF,
			expr::CombinedImageAccess::eTextureProjLodOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodOffsetI
		{
			expr::CombinedImageAccess::eTextureProjLodOffset1DI2,
			expr::CombinedImageAccess::eTextureProjLodOffset2DI3,
			expr::CombinedImageAccess::eTextureProjLodOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjLodOffsetU
		{
			expr::CombinedImageAccess::eTextureProjLodOffset1DU2,
			expr::CombinedImageAccess::eTextureProjLodOffset2DU3,
			expr::CombinedImageAccess::eTextureProjLodOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList texelFetchF
		{
			expr::CombinedImageAccess::eTexelFetch1DF,
			expr::CombinedImageAccess::eTexelFetch2DF,
			expr::CombinedImageAccess::eTexelFetch3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTexelFetchBufferF,

			expr::CombinedImageAccess::eTexelFetch1DArrayF,
			expr::CombinedImageAccess::eTexelFetch2DArrayF,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchI
		{
			expr::CombinedImageAccess::eTexelFetch1DI,
			expr::CombinedImageAccess::eTexelFetch2DI,
			expr::CombinedImageAccess::eTexelFetch3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTexelFetchBufferI,

			expr::CombinedImageAccess::eTexelFetch1DArrayI,
			expr::CombinedImageAccess::eTexelFetch2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchU
		{
			expr::CombinedImageAccess::eTexelFetch1DU,
			expr::CombinedImageAccess::eTexelFetch2DU,
			expr::CombinedImageAccess::eTexelFetch3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTexelFetchBufferU,

			expr::CombinedImageAccess::eTexelFetch1DArrayU,
			expr::CombinedImageAccess::eTexelFetch2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList texelFetchOffsetF
		{
			expr::CombinedImageAccess::eTexelFetchOffset1DF,
			expr::CombinedImageAccess::eTexelFetchOffset2DF,
			expr::CombinedImageAccess::eTexelFetchOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexelFetchOffset1DArrayF,
			expr::CombinedImageAccess::eTexelFetchOffset2DArrayF,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchOffsetI
		{
			expr::CombinedImageAccess::eTexelFetchOffset1DI,
			expr::CombinedImageAccess::eTexelFetchOffset2DI,
			expr::CombinedImageAccess::eTexelFetchOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexelFetchOffset1DArrayI,
			expr::CombinedImageAccess::eTexelFetchOffset2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList texelFetchOffsetU
		{
			expr::CombinedImageAccess::eTexelFetchOffset1DU,
			expr::CombinedImageAccess::eTexelFetchOffset2DU,
			expr::CombinedImageAccess::eTexelFetchOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTexelFetchOffset1DArrayU,
			expr::CombinedImageAccess::eTexelFetchOffset2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureGradF
		{
			expr::CombinedImageAccess::eTextureGrad1DF,
			expr::CombinedImageAccess::eTextureGrad2DF,
			expr::CombinedImageAccess::eTextureGrad3DF,
			expr::CombinedImageAccess::eTextureGradCubeF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGrad1DArrayF,
			expr::CombinedImageAccess::eTextureGrad2DArrayF,
			expr::CombinedImageAccess::eTextureGradCubeArrayF,

			expr::CombinedImageAccess::eTextureGrad1DShadowF,
			expr::CombinedImageAccess::eTextureGrad2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGrad1DArrayShadowF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGradI
		{
			expr::CombinedImageAccess::eTextureGrad1DI,
			expr::CombinedImageAccess::eTextureGrad2DI,
			expr::CombinedImageAccess::eTextureGrad3DI,
			expr::CombinedImageAccess::eTextureGradCubeI,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGrad1DArrayI,
			expr::CombinedImageAccess::eTextureGrad2DArrayI,
			expr::CombinedImageAccess::eTextureGradCubeArrayI,
		};
		static constexpr IntrinsicsList textureGradU
		{
			expr::CombinedImageAccess::eTextureGrad1DU,
			expr::CombinedImageAccess::eTextureGrad2DU,
			expr::CombinedImageAccess::eTextureGrad3DU,
			expr::CombinedImageAccess::eTextureGradCubeU,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGrad1DArrayU,
			expr::CombinedImageAccess::eTextureGrad2DArrayU,
			expr::CombinedImageAccess::eTextureGradCubeArrayU,
		};

		static constexpr IntrinsicsList textureGradOffsetF
		{
			expr::CombinedImageAccess::eTextureGradOffset1DF,
			expr::CombinedImageAccess::eTextureGradOffset2DF,
			expr::CombinedImageAccess::eTextureGradOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGradOffset1DArrayF,
			expr::CombinedImageAccess::eTextureGradOffset2DArrayF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGradOffset1DShadowF,
			expr::CombinedImageAccess::eTextureGradOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGradOffset1DArrayShadowF,
			expr::CombinedImageAccess::eTextureGradOffset2DArrayShadowF,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGradOffsetI
		{
			expr::CombinedImageAccess::eTextureGradOffset1DI,
			expr::CombinedImageAccess::eTextureGradOffset2DI,
			expr::CombinedImageAccess::eTextureGradOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGradOffset1DArrayI,
			expr::CombinedImageAccess::eTextureGradOffset2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGradOffsetU
		{
			expr::CombinedImageAccess::eTextureGradOffset1DU,
			expr::CombinedImageAccess::eTextureGradOffset2DU,
			expr::CombinedImageAccess::eTextureGradOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureGradOffset1DArrayU,
			expr::CombinedImageAccess::eTextureGradOffset2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjGradF
		{
			expr::CombinedImageAccess::eTextureProjGrad1DF2,
			expr::CombinedImageAccess::eTextureProjGrad2DF3,
			expr::CombinedImageAccess::eTextureProjGrad3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProjGrad1DShadowF,
			expr::CombinedImageAccess::eTextureProjGrad2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradI
		{
			expr::CombinedImageAccess::eTextureProjGrad1DI2,
			expr::CombinedImageAccess::eTextureProjGrad2DI3,
			expr::CombinedImageAccess::eTextureProjGrad3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradU
		{
			expr::CombinedImageAccess::eTextureProjGrad1DU2,
			expr::CombinedImageAccess::eTextureProjGrad2DU3,
			expr::CombinedImageAccess::eTextureProjGrad3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureProjGradOffsetF
		{
			expr::CombinedImageAccess::eTextureProjGradOffset1DF2,
			expr::CombinedImageAccess::eTextureProjGradOffset2DF3,
			expr::CombinedImageAccess::eTextureProjGradOffset3DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eTextureProjGradOffset1DShadowF,
			expr::CombinedImageAccess::eTextureProjGradOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradOffsetI
		{
			expr::CombinedImageAccess::eTextureProjGradOffset1DI2,
			expr::CombinedImageAccess::eTextureProjGradOffset2DI3,
			expr::CombinedImageAccess::eTextureProjGradOffset3DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureProjGradOffsetU
		{
			expr::CombinedImageAccess::eTextureProjGradOffset1DU2,
			expr::CombinedImageAccess::eTextureProjGradOffset2DU3,
			expr::CombinedImageAccess::eTextureProjGradOffset3DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureGatherF
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherCubeF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DArrayF,
			expr::CombinedImageAccess::eTextureGatherCubeArrayF,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DShadowF,
			expr::CombinedImageAccess::eTextureGatherCubeShadowF,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DArrayShadowF,
			expr::CombinedImageAccess::eTextureGatherCubeArrayShadowF,
		};
		static constexpr IntrinsicsList textureGatherI
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherCubeI,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DArrayI,
			expr::CombinedImageAccess::eTextureGatherCubeArrayI,
		};
		static constexpr IntrinsicsList textureGatherU
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherCubeU,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGather2DArrayU,
			expr::CombinedImageAccess::eTextureGatherCubeArrayU,
		};

		static constexpr IntrinsicsList textureGatherOffsetF
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DArrayF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DArrayShadowF,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetI
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetU
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffset2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList textureGatherOffsetsF
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DF,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DArrayF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DShadowF,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DArrayShadowF,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetsI
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DI,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DArrayI,
			expr::CombinedImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList textureGatherOffsetsU
		{
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DU,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eInvalid,

			expr::CombinedImageAccess::eInvalid,
			expr::CombinedImageAccess::eTextureGatherOffsets2DArrayU,
			expr::CombinedImageAccess::eInvalid,
		};
	}

	//*************************************************************************

	template< type::ImageFormat FormatT >
	struct CombinedImageFormatTraitsT< FormatT, std::enable_if_t< isFloatFormatV< FormatT > > >
	{
		static constexpr combinedSmplImg::IntrinsicsList const & textureSize = combinedSmplImg::textureSizeF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureQueryLod = combinedSmplImg::textureQueryLodF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureQueryLevels = combinedSmplImg::textureQueryLevelsF;
		static constexpr combinedSmplImg::IntrinsicsList const & texture = combinedSmplImg::textureF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureBias = combinedSmplImg::textureBiasF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureOffset = combinedSmplImg::textureOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureOffsetBias = combinedSmplImg::textureOffsetBiasF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProj = combinedSmplImg::textureProjF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjBias = combinedSmplImg::textureProjBiasF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjOffset = combinedSmplImg::textureProjOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjOffsetBias = combinedSmplImg::textureProjOffsetBiasF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureLod = combinedSmplImg::textureLodF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureLodOffset = combinedSmplImg::textureLodOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjLod = combinedSmplImg::textureProjLodF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjLodOffset = combinedSmplImg::textureProjLodOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & texelFetch = combinedSmplImg::texelFetchF;
		static constexpr combinedSmplImg::IntrinsicsList const & texelFetchOffset = combinedSmplImg::texelFetchOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGrad = combinedSmplImg::textureGradF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGradOffset = combinedSmplImg::textureGradOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjGrad = combinedSmplImg::textureProjGradF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjGradOffset = combinedSmplImg::textureProjGradOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGather = combinedSmplImg::textureGatherF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGatherOffset = combinedSmplImg::textureGatherOffsetF;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGatherOffsets = combinedSmplImg::textureGatherOffsetsF;
	};

	template< type::ImageFormat FormatT >
	struct CombinedImageFormatTraitsT< FormatT, std::enable_if_t< isSIntFormatV< FormatT > > >
	{
		static constexpr combinedSmplImg::IntrinsicsList const & textureSize = combinedSmplImg::textureSizeI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureQueryLod = combinedSmplImg::textureQueryLodI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureQueryLevels = combinedSmplImg::textureQueryLevelsI;
		static constexpr combinedSmplImg::IntrinsicsList const & texture = combinedSmplImg::textureI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureBias = combinedSmplImg::textureBiasI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureOffset = combinedSmplImg::textureOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureOffsetBias = combinedSmplImg::textureOffsetBiasI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProj = combinedSmplImg::textureProjI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjBias = combinedSmplImg::textureProjBiasI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjOffset = combinedSmplImg::textureProjOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjOffsetBias = combinedSmplImg::textureProjOffsetBiasI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureLod = combinedSmplImg::textureLodI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureLodOffset = combinedSmplImg::textureLodOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjLod = combinedSmplImg::textureProjLodI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjLodOffset = combinedSmplImg::textureProjLodOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & texelFetch = combinedSmplImg::texelFetchI;
		static constexpr combinedSmplImg::IntrinsicsList const & texelFetchOffset = combinedSmplImg::texelFetchOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGrad = combinedSmplImg::textureGradI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGradOffset = combinedSmplImg::textureGradOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjGrad = combinedSmplImg::textureProjGradI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjGradOffset = combinedSmplImg::textureProjGradOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGather = combinedSmplImg::textureGatherI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGatherOffset = combinedSmplImg::textureGatherOffsetI;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGatherOffsets = combinedSmplImg::textureGatherOffsetsI;
	};

	template< type::ImageFormat FormatT >
	struct CombinedImageFormatTraitsT< FormatT, std::enable_if_t< isUIntFormatV< FormatT > > >
	{
		static constexpr combinedSmplImg::IntrinsicsList const & textureSize = combinedSmplImg::textureSizeU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureQueryLod = combinedSmplImg::textureQueryLodU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureQueryLevels = combinedSmplImg::textureQueryLevelsU;
		static constexpr combinedSmplImg::IntrinsicsList const & texture = combinedSmplImg::textureU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureBias = combinedSmplImg::textureBiasU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureOffset = combinedSmplImg::textureOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureOffsetBias = combinedSmplImg::textureOffsetBiasU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProj = combinedSmplImg::textureProjU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjBias = combinedSmplImg::textureProjBiasU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjOffset = combinedSmplImg::textureProjOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjOffsetBias = combinedSmplImg::textureProjOffsetBiasU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureLod = combinedSmplImg::textureLodU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureLodOffset = combinedSmplImg::textureLodOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjLod = combinedSmplImg::textureProjLodU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjLodOffset = combinedSmplImg::textureProjLodOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & texelFetch = combinedSmplImg::texelFetchU;
		static constexpr combinedSmplImg::IntrinsicsList const & texelFetchOffset = combinedSmplImg::texelFetchOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGrad = combinedSmplImg::textureGradU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGradOffset = combinedSmplImg::textureGradOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjGrad = combinedSmplImg::textureProjGradU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureProjGradOffset = combinedSmplImg::textureProjGradOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGather = combinedSmplImg::textureGatherU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGatherOffset = combinedSmplImg::textureGatherOffsetU;
		static constexpr combinedSmplImg::IntrinsicsList const & textureGatherOffsets = combinedSmplImg::textureGatherOffsetsU;
	};
	
	//*************************************************************************

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::eBuffer, false >
	{
		using SampleType = sdw::Int32;
		using FetchType = sdw::Int32;
		using SizeType = sdw::Int32;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::e1D, false >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Float;
		using ProjType = sdw::Vec2;
		using OffsetType = sdw::Int32;
		using FetchType = sdw::Int32;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::Int32;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::e2D, false >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec2;
		using ProjType = sdw::Vec3;
		using OffsetType = sdw::I32Vec2;
		using FetchType = sdw::I32Vec2;
		using DerivativeType = sdw::Vec2;
		using GatherType = sdw::Vec2;
		using SizeType = sdw::I32Vec2;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::e3D, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
		using ProjType = sdw::Vec4;
		using OffsetType = sdw::I32Vec3;
		using FetchType = sdw::I32Vec3;
		using DerivativeType = sdw::Vec3;
		using SizeType = sdw::I32Vec3;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::eCube, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using FetchType = sdw::Vec3;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::I32Vec2;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::e1D, true >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Vec2;
		using OffsetType = sdw::Int32;
		using FetchType = sdw::I32Vec2;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::I32Vec2;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::e2D, true >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec3;
		using OffsetType = sdw::I32Vec2;
		using FetchType = sdw::I32Vec3;
		using DerivativeType = sdw::Vec2;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::I32Vec3;
	};

	template<>
	struct CombinedImageCoordsGetterT< ast::type::ImageDim::eCube, true >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec4;
		using FetchType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using GatherType = sdw::Vec4;
		using SizeType = sdw::I32Vec3;
	};

	namespace combinedSmplImg
	{
		//*****************************************************************************************

		template< typename ReturnT
			, type::ImageFormat FormatT
			, type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT
			, expr::CombinedImageAccess CombinedImageAccessT
			, typename ... ParamsT >
		ReturnWrapperT< ReturnT > writeCombinedImageAccessCall( CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & image
			, ParamsT const & ... params )
		{
			static_assert( CombinedImageAccessT != expr::CombinedImageAccess::eInvalid );
			static_assert( CombinedImageAccessT != expr::CombinedImageAccess::eUndefined );

			auto & exprCache = findExprCache( image, params... );
			auto & typesCache = findTypesCache( image, params... );
			return ReturnWrapperT< ReturnT >{ findWriterMandat( image, params... )
				, exprCache.makeCombinedImageAccessCall( ReturnT::makeType( typesCache )
					, CombinedImageAccessT
					, makeExpr( image )
					, makeExpr( params )... )
				, areOptionalEnabled( image, params... ) };
		}

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct TexSizeFuncT
		{
			using SizeT = CombinedImageSizeT< DimT, ArrayedT >;

			auto getSize()const
			{
				return writeCombinedImageAccessCall< SizeT, FormatT, DimT, ArrayedT, MsT, DepthT
					, CombinedImageFormatTraitsT< FormatT >::textureSize[combinedSmplImg::getIndex< DimT, ArrayedT, DepthT >()] >( get() );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct TexSizeLevelFuncT
		{
			using SizeT = CombinedImageSizeT< DimT, ArrayedT >;

			auto getSize( Int32 const & level )const
			{
				return writeCombinedImageAccessCall< SizeT, FormatT, DimT, ArrayedT, MsT, DepthT
					, CombinedImageFormatTraitsT< FormatT >::textureSize[combinedSmplImg::getIndex< DimT, ArrayedT, DepthT >()] >( get()
						, level );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct QueryLodFuncT
		{
			using QueryLodT = CombinedImageQueryLodT< DimT, ArrayedT >;

			auto getLod( QueryLodT const & coord )const
			{
				return writeCombinedImageAccessCall< Vec2, FormatT, DimT, ArrayedT, MsT, DepthT
					, CombinedImageFormatTraitsT< FormatT >::textureQueryLod[combinedSmplImg::getIndex< DimT, ArrayedT, DepthT >()] >( get()
						, coord );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct QueryLevelsFuncT
		{
			auto getLevels()const
			{
				return writeCombinedImageAccessCall< Int32, FormatT, DimT, ArrayedT, MsT, DepthT
					, CombinedImageFormatTraitsT< FormatT >::textureQueryLevels[combinedSmplImg::getIndex< DimT, ArrayedT, DepthT >()] >( get() );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;

			auto sample( SampleT const & coord )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::texture[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, Float const & ref )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::texture[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleBiasFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, Float const & bias )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureBias[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefBiasFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, Float const & ref
				, Float const & bias )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureBias[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleOffsetFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefOffsetFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleOffsetBiasFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureOffsetBias[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefOffsetBiasFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto sample( SampleT const & coord
				, Float const & ref
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureOffsetBias[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleLodFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;

			auto lod( SampleT const & coord
				, Float const & lod )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureLod[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefLodFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;

			auto lod( SampleT const & coord
				, Float const & ref
				, Float const & lod )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureLod[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleLodOffsetFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto lod( SampleT const & coord
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureLodOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefLodOffsetFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto lod( SampleT const & coord
				, Float const & ref
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureLodOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProj[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, Float const & ref )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProj[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjBiasFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, Float const & bias )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjBias[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjBiasFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, Float const & ref
				, Float const & bias )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjBias[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjOffsetFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjOffsetFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjOffsetBiasFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjOffsetBias[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, offset
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjOffsetBiasFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto proj( SampleProjT const & coord
				, Float const & ref
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjOffsetBias[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset
						, bias );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjLodFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;

			auto projLod( SampleProjT const & coord
				, Float const & lod )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjLod[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjLodFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;

			auto projLod( SampleProjT const & coord
				, Float const & ref
				, Float const & lod )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjLod[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleProjLodOffsetFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto projLod( SampleProjT const & coord
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjLodOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, lod
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleRefProjLodOffsetFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto projLod( SampleProjT const & coord
				, Float const & ref
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjLodOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, lod
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchFuncT
		{
			using FetchT = CombinedImageFetchT< DimT, ArrayedT >;

			auto fetch( FetchT const & coord )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::texelFetch[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchLevelFuncT
		{
			using FetchT = CombinedImageFetchT< DimT, ArrayedT >;

			auto fetch( FetchT const & coord
				, Int32 const & level )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::texelFetch[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, level );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct FetchLevelOffsetFuncT
		{
			using FetchT = CombinedImageFetchT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto fetch( FetchT const & coord
				, Int32 const & level
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::texelFetchOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, level
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;

			auto grad( SampleT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureGrad[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;

			auto grad( SampleT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureGrad[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradOffsetFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto grad( SampleT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureGradOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefOffsetFuncT
		{
			using SampleT = CombinedImageSampleT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto grad( SampleT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureGradOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradProjFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;

			auto projGrad( SampleProjT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjGrad[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefProjFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;

			auto projGrad( SampleProjT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjGrad[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradProjOffsetFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto projGrad( SampleProjT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureProjGradOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, dPdx
						, dPdy
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};
		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GradRefProjOffsetFuncT
		{
			using SampleProjT = CombinedImageSampleProjT< DimT, ArrayedT >;
			using DerivativeT = CombinedImageDerivativeT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto projGrad( SampleProjT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeCombinedImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureProjGradOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, dPdx
						, dPdy
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
			struct GatherFuncT
		{
			using GatherT = CombinedImageGatherT< DimT, ArrayedT >;

			auto gather( GatherT const & coord
				, Int32 const & comp )const
			{
				return writeCombinedImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureGather[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, comp );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefFuncT
		{
			using GatherT = CombinedImageGatherT< DimT, ArrayedT >;

			auto gather( GatherT const & coord
				, Float const & ref )const
			{
				return writeCombinedImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureGather[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetFuncT
		{
			using GatherT = CombinedImageGatherT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto gather( GatherT const & coord
				, Int32 const & comp
				, OffsetT const & offset )const
			{
				return writeCombinedImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureGatherOffset[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, comp
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefOffsetFuncT
		{
			using GatherT = CombinedImageGatherT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto gather( GatherT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				return writeCombinedImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureGatherOffset[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offset );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherOffsetsFuncT
		{
			using GatherT = CombinedImageGatherT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto gather( GatherT const & coord
				, Int32 const & comp
				, Array< OffsetT > const & offsets )const
			{
				return writeCombinedImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, CombinedImageFormatTraitsT< FormatT >::textureGatherOffsets[combinedSmplImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, coord
						, comp
						, offsets );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, false > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct GatherRefOffsetsFuncT
		{
			using GatherT = CombinedImageGatherT< DimT, ArrayedT >;
			using OffsetT = CombinedImageOffsetT< DimT, ArrayedT >;

			auto gather( GatherT const & coord
				, Float const & ref
				, Array< OffsetT > const & offsets )const
			{
				return writeCombinedImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, CombinedImageFormatTraitsT< FormatT >::textureGatherOffsets[combinedSmplImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, coord
						, ref
						, offsets );
			}

		private:
			CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & get()const
			{
				return static_cast< CombinedImageT< FormatT, DimT, ArrayedT, MsT, true > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is2dV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is1dV< DimT, ArrayedT, DepthT >
				|| sdw::is3dV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is1dArrayV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is2dArrayV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	
		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::isCubeV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , CombinedImageFuncsT );

			using SampleFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using GatherFuncT< FormatT, DimT, ArrayedT, MsT >::gather;

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is1dShadowV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is2dShadowV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , CombinedImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using SampleRefLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::lod;
			using GradRefFuncT< FormatT, DimT, ArrayedT, MsT >::grad;
			using GradRefOffsetFuncT< FormatT, DimT, ArrayedT, MsT >::grad;

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
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
			SDW_DeclValue( , CombinedImageFuncsT );

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

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
				|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeLevelFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLodFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public QueryLevelsFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleRefLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public GatherRefFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , CombinedImageFuncsT );

			using SampleRefFuncT< FormatT, DimT, ArrayedT, MsT >::sample;
			using SampleRefBiasFuncT< FormatT, DimT, ArrayedT, MsT >::sample;

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT
			, bool DepthT >
		struct CombinedImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, DepthT
			, std::enable_if_t< ( sdw::isBufferV< DimT, ArrayedT, DepthT > ) > >
			: public CombinedImage
			, public TexSizeFuncT< FormatT, DimT, ArrayedT, MsT, DepthT >
			, public FetchFuncT< FormatT, DimT, ArrayedT, MsT >
		{
			SDW_DeclValue( , CombinedImageFuncsT );

			CombinedImageFuncsT( ShaderWriter & writer
				, expr::ExprPtr expr
				, bool enabled )
				: CombinedImage{ writer, std::move( expr ), enabled }
			{
			}

			template< typename T >
			CombinedImageFuncsT & operator=( T const & rhs )
			{
				CombinedImage::operator=( rhs );
				return *this;
			}
		};

		//*************************************************************************
	}

	template< typename T >
	CombinedImage & CombinedImage::operator=( T const & rhs )
	{
		this->updateContainer( rhs );
		auto & shader = findWriterMandat( *this, rhs );

		if ( areOptionalEnabled( *this, rhs ) )
		{
			addStmt( shader
				, sdw::makeSimple( getStmtCache( shader )
					, sdw::makeAssign( getExpr()->getType()
						, makeExpr( shader, getExpr() )
						, makeExpr( shader, rhs ) ) ) );
		}

		return *this;
	}

	//*************************************************************************

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >::CombinedImageT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: combinedSmplImg::CombinedImageFuncsT< FormatT, DimT, ArrayedT, MsT, DepthT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	template< typename T >
	CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT > & CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >::operator=( T const & rhs )
	{
		combinedSmplImg::CombinedImageFuncsT< FormatT, DimT, ArrayedT, MsT, DepthT >::operator=( rhs );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	ast::type::ImageConfiguration CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, ast::type::AccessKind::eRead, DimT, ArrayedT, MsT >( true );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	inline ast::type::TypePtr CombinedImageT< FormatT, DimT, ArrayedT, MsT, DepthT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getCombinedImage( makeConfig(), DepthT );
	}

	//*************************************************************************
}
