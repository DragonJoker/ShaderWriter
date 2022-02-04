/*
See LICENSE file in root folder
*/
#include "ShaderWriter/BaseTypes/Int.hpp"
#include "ShaderWriter/BaseTypes/Sampler.hpp"
#include "ShaderWriter/VecTypes/Vec4.hpp"

#include <ShaderAST/Expr/EnumSampledImageAccess.hpp>
#include <ShaderAST/Expr/ExprSampledImageAccessCall.hpp>

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
		using IntrinsicsList = std::array< expr::SampledImageAccess, NonShadowImgCount + ShadowImgBaseCount + ShadowArrayImgBaseCount >;

		template< type::ImageDim DimT
			, bool ArrayedT
			, bool ComparisonT >
		constexpr size_t getIndex()
		{
			if constexpr ( ComparisonT )
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
						return size_t( expr::SampledImageAccess::eInvalid );
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
						return size_t( expr::SampledImageAccess::eInvalid );
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
					return size_t( expr::SampledImageAccess::eInvalid );
				}
			}
			else
			{
				return size_t( DimT );
			}
		}

		static constexpr IntrinsicsList sampleF
		{
			expr::SampledImageAccess::eSample1DF,
			expr::SampledImageAccess::eSample2DF,
			expr::SampledImageAccess::eSample3DF,
			expr::SampledImageAccess::eSampleCubeF,
			expr::SampledImageAccess::eSample2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayF,
			expr::SampledImageAccess::eSample2DArrayF,
			expr::SampledImageAccess::eSampleCubeArrayF,

			expr::SampledImageAccess::eSample1DShadowF,
			expr::SampledImageAccess::eSample2DShadowF,
			expr::SampledImageAccess::eSampleCubeShadowF,
			expr::SampledImageAccess::eSample2DRectShadowF,

			expr::SampledImageAccess::eSample1DArrayShadowF,
			expr::SampledImageAccess::eSample2DArrayShadowF,
			expr::SampledImageAccess::eSampleCubeArrayShadowF,
		};
		static constexpr IntrinsicsList sampleI
		{
			expr::SampledImageAccess::eSample1DI,
			expr::SampledImageAccess::eSample2DI,
			expr::SampledImageAccess::eSample3DI,
			expr::SampledImageAccess::eSampleCubeI,
			expr::SampledImageAccess::eSample2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayI,
			expr::SampledImageAccess::eSample2DArrayI,
			expr::SampledImageAccess::eSampleCubeArrayI,
		};
		static constexpr IntrinsicsList sampleU
		{
			expr::SampledImageAccess::eSample1DU,
			expr::SampledImageAccess::eSample2DU,
			expr::SampledImageAccess::eSample3DU,
			expr::SampledImageAccess::eSampleCubeU,
			expr::SampledImageAccess::eSample2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayU,
			expr::SampledImageAccess::eSample2DArrayU,
			expr::SampledImageAccess::eSampleCubeArrayU,
		};

		static constexpr IntrinsicsList sampleBiasF
		{
			expr::SampledImageAccess::eSample1DFBias,
			expr::SampledImageAccess::eSample2DFBias,
			expr::SampledImageAccess::eSample3DFBias,
			expr::SampledImageAccess::eSampleCubeFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayFBias,
			expr::SampledImageAccess::eSample2DArrayFBias,
			expr::SampledImageAccess::eSampleCubeArrayFBias,

			expr::SampledImageAccess::eSample1DShadowFBias,
			expr::SampledImageAccess::eSample2DShadowFBias,
			expr::SampledImageAccess::eSampleCubeShadowFBias,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayShadowFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleBiasI
		{
			expr::SampledImageAccess::eSample1DIBias,
			expr::SampledImageAccess::eSample2DIBias,
			expr::SampledImageAccess::eSample3DIBias,
			expr::SampledImageAccess::eSampleCubeIBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayIBias,
			expr::SampledImageAccess::eSample2DArrayIBias,
			expr::SampledImageAccess::eSampleCubeArrayIBias,
		};
		static constexpr IntrinsicsList sampleBiasU
		{
			expr::SampledImageAccess::eSample1DUBias,
			expr::SampledImageAccess::eSample2DUBias,
			expr::SampledImageAccess::eSample3DUBias,
			expr::SampledImageAccess::eSampleCubeUBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSample1DArrayUBias,
			expr::SampledImageAccess::eSample2DArrayUBias,
			expr::SampledImageAccess::eSampleCubeArrayUBias,
		};

		static constexpr IntrinsicsList sampleOffsetF
		{
			expr::SampledImageAccess::eSampleOffset1DF,
			expr::SampledImageAccess::eSampleOffset2DF,
			expr::SampledImageAccess::eSampleOffset3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleOffset2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DArrayF,
			expr::SampledImageAccess::eSampleOffset2DArrayF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DShadowF,
			expr::SampledImageAccess::eSampleOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleOffset2DRectShadowF,

			expr::SampledImageAccess::eSampleOffset1DArrayShadowF,
			expr::SampledImageAccess::eSampleOffset2DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleOffsetI
		{
			expr::SampledImageAccess::eSampleOffset1DI,
			expr::SampledImageAccess::eSampleOffset2DI,
			expr::SampledImageAccess::eSampleOffset3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleOffset2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DArrayI,
			expr::SampledImageAccess::eSampleOffset2DArrayI,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleOffsetU
		{
			expr::SampledImageAccess::eSampleOffset1DU,
			expr::SampledImageAccess::eSampleOffset2DU,
			expr::SampledImageAccess::eSampleOffset3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleOffset2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DArrayU,
			expr::SampledImageAccess::eSampleOffset2DArrayU,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleOffsetBiasF
		{
			expr::SampledImageAccess::eSampleOffset1DFBias,
			expr::SampledImageAccess::eSampleOffset2DFBias,
			expr::SampledImageAccess::eSampleOffset3DFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DArrayFBias,
			expr::SampledImageAccess::eSampleOffset2DArrayFBias,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DShadowFBias,
			expr::SampledImageAccess::eSampleOffset2DShadowFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleOffsetBiasI
		{
			expr::SampledImageAccess::eSampleOffset1DIBias,
			expr::SampledImageAccess::eSampleOffset2DIBias,
			expr::SampledImageAccess::eSampleOffset3DIBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DArrayIBias,
			expr::SampledImageAccess::eSampleOffset2DArrayIBias,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleOffsetBiasU
		{
			expr::SampledImageAccess::eSampleOffset1DUBias,
			expr::SampledImageAccess::eSampleOffset2DUBias,
			expr::SampledImageAccess::eSampleOffset3DUBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleOffset1DArrayUBias,
			expr::SampledImageAccess::eSampleOffset2DArrayUBias,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjF
		{
			expr::SampledImageAccess::eSampleProj1DF2,
			expr::SampledImageAccess::eSampleProj2DF3,
			expr::SampledImageAccess::eSampleProj3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProj2DRectF3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProj1DShadowF,
			expr::SampledImageAccess::eSampleProj2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProj2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjI
		{
			expr::SampledImageAccess::eSampleProj1DI2,
			expr::SampledImageAccess::eSampleProj2DI3,
			expr::SampledImageAccess::eSampleProj3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProj2DRectI3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjU
		{
			expr::SampledImageAccess::eSampleProj1DU2,
			expr::SampledImageAccess::eSampleProj2DU3,
			expr::SampledImageAccess::eSampleProj3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProj2DRectU3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjBiasF
		{
			expr::SampledImageAccess::eSampleProj1DF2Bias,
			expr::SampledImageAccess::eSampleProj2DF3Bias,
			expr::SampledImageAccess::eSampleProj3DFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProj1DShadowFBias,
			expr::SampledImageAccess::eSampleProj2DShadowFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjBiasI
		{
			expr::SampledImageAccess::eSampleProj1DI2Bias,
			expr::SampledImageAccess::eSampleProj2DI3Bias,
			expr::SampledImageAccess::eSampleProj3DIBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjBiasU
		{
			expr::SampledImageAccess::eSampleProj1DU2Bias,
			expr::SampledImageAccess::eSampleProj2DU3Bias,
			expr::SampledImageAccess::eSampleProj3DUBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjOffsetF
		{
			expr::SampledImageAccess::eSampleProjOffset1DF2,
			expr::SampledImageAccess::eSampleProjOffset2DF3,
			expr::SampledImageAccess::eSampleProjOffset3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjOffset2DRectF3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProjOffset1DShadowF,
			expr::SampledImageAccess::eSampleProjOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjOffset2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjOffsetI
		{
			expr::SampledImageAccess::eSampleProjOffset1DI2,
			expr::SampledImageAccess::eSampleProjOffset2DI3,
			expr::SampledImageAccess::eSampleProjOffset3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjOffset2DRectI3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjOffsetU
		{
			expr::SampledImageAccess::eSampleProjOffset1DU2,
			expr::SampledImageAccess::eSampleProjOffset2DU3,
			expr::SampledImageAccess::eSampleProjOffset3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjOffset2DRectU3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjOffsetBiasF
		{
			expr::SampledImageAccess::eSampleProjOffset1DF2Bias,
			expr::SampledImageAccess::eSampleProjOffset2DF3Bias,
			expr::SampledImageAccess::eSampleProjOffset3DFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProjOffset1DShadowFBias,
			expr::SampledImageAccess::eSampleProjOffset2DShadowFBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjOffsetBiasI
		{
			expr::SampledImageAccess::eSampleProjOffset1DI2Bias,
			expr::SampledImageAccess::eSampleProjOffset2DI3Bias,
			expr::SampledImageAccess::eSampleProjOffset3DIBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjOffsetBiasU
		{
			expr::SampledImageAccess::eSampleProjOffset1DU2Bias,
			expr::SampledImageAccess::eSampleProjOffset2DU3Bias,
			expr::SampledImageAccess::eSampleProjOffset3DUBias,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleLodF
		{
			expr::SampledImageAccess::eSampleLod1DF,
			expr::SampledImageAccess::eSampleLod2DF,
			expr::SampledImageAccess::eSampleLod3DF,
			expr::SampledImageAccess::eSampleLodCubeF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLod1DArrayF,
			expr::SampledImageAccess::eSampleLod2DArrayF,
			expr::SampledImageAccess::eSampleLodCubeArrayF,

			expr::SampledImageAccess::eSampleLod1DShadowF,
			expr::SampledImageAccess::eSampleLod2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLod1DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleLodI
		{
			expr::SampledImageAccess::eSampleLod1DI,
			expr::SampledImageAccess::eSampleLod2DI,
			expr::SampledImageAccess::eSampleLod3DI,
			expr::SampledImageAccess::eSampleLodCubeI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLod1DArrayI,
			expr::SampledImageAccess::eSampleLod2DArrayI,
			expr::SampledImageAccess::eSampleLodCubeArrayI,
		};
		static constexpr IntrinsicsList sampleLodU
		{
			expr::SampledImageAccess::eSampleLod1DU,
			expr::SampledImageAccess::eSampleLod2DU,
			expr::SampledImageAccess::eSampleLod3DU,
			expr::SampledImageAccess::eSampleLodCubeU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLod1DArrayU,
			expr::SampledImageAccess::eSampleLod2DArrayU,
			expr::SampledImageAccess::eSampleLodCubeArrayU,
		};

		static constexpr IntrinsicsList sampleLodOffsetF
		{
			expr::SampledImageAccess::eSampleLodOffset1DF,
			expr::SampledImageAccess::eSampleLodOffset2DF,
			expr::SampledImageAccess::eSampleLodOffset3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLodOffset1DArrayF,
			expr::SampledImageAccess::eSampleLodOffset2DArrayF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLodOffset1DShadowF,
			expr::SampledImageAccess::eSampleLodOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLodOffset1DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleLodOffsetI
		{
			expr::SampledImageAccess::eSampleLodOffset1DI,
			expr::SampledImageAccess::eSampleLodOffset2DI,
			expr::SampledImageAccess::eSampleLodOffset3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLodOffset1DArrayI,
			expr::SampledImageAccess::eSampleLodOffset2DArrayI,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleLodOffsetU
		{
			expr::SampledImageAccess::eSampleLodOffset1DU,
			expr::SampledImageAccess::eSampleLodOffset2DU,
			expr::SampledImageAccess::eSampleLodOffset3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleLodOffset1DArrayU,
			expr::SampledImageAccess::eSampleLodOffset2DArrayU,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjLodF
		{
			expr::SampledImageAccess::eSampleProjLod1DF2,
			expr::SampledImageAccess::eSampleProjLod2DF3,
			expr::SampledImageAccess::eSampleProjLod3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProjLod1DShadowF,
			expr::SampledImageAccess::eSampleProjLod2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjLodI
		{
			expr::SampledImageAccess::eSampleProjLod1DI2,
			expr::SampledImageAccess::eSampleProjLod2DI3,
			expr::SampledImageAccess::eSampleProjLod3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjLodU
		{
			expr::SampledImageAccess::eSampleProjLod1DU2,
			expr::SampledImageAccess::eSampleProjLod2DU3,
			expr::SampledImageAccess::eSampleProjLod3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjLodOffsetF
		{
			expr::SampledImageAccess::eSampleProjLodOffset1DF2,
			expr::SampledImageAccess::eSampleProjLodOffset2DF3,
			expr::SampledImageAccess::eSampleProjLodOffset3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProjLodOffset1DShadowF,
			expr::SampledImageAccess::eSampleProjLodOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjLodOffsetI
		{
			expr::SampledImageAccess::eSampleProjLodOffset1DI2,
			expr::SampledImageAccess::eSampleProjLodOffset2DI3,
			expr::SampledImageAccess::eSampleProjLodOffset3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjLodOffsetU
		{
			expr::SampledImageAccess::eSampleProjLodOffset1DU2,
			expr::SampledImageAccess::eSampleProjLodOffset2DU3,
			expr::SampledImageAccess::eSampleProjLodOffset3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleGradF
		{
			expr::SampledImageAccess::eSampleGrad1DF,
			expr::SampledImageAccess::eSampleGrad2DF,
			expr::SampledImageAccess::eSampleGrad3DF,
			expr::SampledImageAccess::eSampleGradCubeF,
			expr::SampledImageAccess::eSampleGrad2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGrad1DArrayF,
			expr::SampledImageAccess::eSampleGrad2DArrayF,
			expr::SampledImageAccess::eSampleGradCubeArrayF,

			expr::SampledImageAccess::eSampleGrad1DShadowF,
			expr::SampledImageAccess::eSampleGrad2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGrad2DRectShadowF,

			expr::SampledImageAccess::eSampleGrad1DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGradI
		{
			expr::SampledImageAccess::eSampleGrad1DI,
			expr::SampledImageAccess::eSampleGrad2DI,
			expr::SampledImageAccess::eSampleGrad3DI,
			expr::SampledImageAccess::eSampleGradCubeI,
			expr::SampledImageAccess::eSampleGrad2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGrad1DArrayI,
			expr::SampledImageAccess::eSampleGrad2DArrayI,
			expr::SampledImageAccess::eSampleGradCubeArrayI,
		};
		static constexpr IntrinsicsList sampleGradU
		{
			expr::SampledImageAccess::eSampleGrad1DU,
			expr::SampledImageAccess::eSampleGrad2DU,
			expr::SampledImageAccess::eSampleGrad3DU,
			expr::SampledImageAccess::eSampleGradCubeU,
			expr::SampledImageAccess::eSampleGrad2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGrad1DArrayU,
			expr::SampledImageAccess::eSampleGrad2DArrayU,
			expr::SampledImageAccess::eSampleGradCubeArrayU,
		};

		static constexpr IntrinsicsList sampleGradOffsetF
		{
			expr::SampledImageAccess::eSampleGradOffset1DF,
			expr::SampledImageAccess::eSampleGradOffset2DF,
			expr::SampledImageAccess::eSampleGradOffset3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGradOffset2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGradOffset1DArrayF,
			expr::SampledImageAccess::eSampleGradOffset2DArrayF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGradOffset1DShadowF,
			expr::SampledImageAccess::eSampleGradOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGradOffset2DRectShadowF,

			expr::SampledImageAccess::eSampleGradOffset1DArrayShadowF,
			expr::SampledImageAccess::eSampleGradOffset2DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGradOffsetI
		{
			expr::SampledImageAccess::eSampleGradOffset1DI,
			expr::SampledImageAccess::eSampleGradOffset2DI,
			expr::SampledImageAccess::eSampleGradOffset3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGradOffset2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGradOffset1DArrayI,
			expr::SampledImageAccess::eSampleGradOffset2DArrayI,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGradOffsetU
		{
			expr::SampledImageAccess::eSampleGradOffset1DU,
			expr::SampledImageAccess::eSampleGradOffset2DU,
			expr::SampledImageAccess::eSampleGradOffset3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGradOffset2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleGradOffset1DArrayU,
			expr::SampledImageAccess::eSampleGradOffset2DArrayU,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjGradF
		{
			expr::SampledImageAccess::eSampleProjGrad1DF2,
			expr::SampledImageAccess::eSampleProjGrad2DF3,
			expr::SampledImageAccess::eSampleProjGrad3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGrad2DRectF3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProjGrad1DShadowF,
			expr::SampledImageAccess::eSampleProjGrad2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGrad2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjGradI
		{
			expr::SampledImageAccess::eSampleProjGrad1DI2,
			expr::SampledImageAccess::eSampleProjGrad2DI3,
			expr::SampledImageAccess::eSampleProjGrad3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGrad2DRectI3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjGradU
		{
			expr::SampledImageAccess::eSampleProjGrad1DU2,
			expr::SampledImageAccess::eSampleProjGrad2DU3,
			expr::SampledImageAccess::eSampleProjGrad3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGrad2DRectU3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleProjGradOffsetF
		{
			expr::SampledImageAccess::eSampleProjGradOffset1DF2,
			expr::SampledImageAccess::eSampleProjGradOffset2DF3,
			expr::SampledImageAccess::eSampleProjGradOffset3DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGradOffset2DRectF3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eSampleProjGradOffset1DShadowF,
			expr::SampledImageAccess::eSampleProjGradOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGradOffset2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjGradOffsetI
		{
			expr::SampledImageAccess::eSampleProjGradOffset1DI2,
			expr::SampledImageAccess::eSampleProjGradOffset2DI3,
			expr::SampledImageAccess::eSampleProjGradOffset3DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGradOffset2DRectI3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleProjGradOffsetU
		{
			expr::SampledImageAccess::eSampleProjGradOffset1DU2,
			expr::SampledImageAccess::eSampleProjGradOffset2DU3,
			expr::SampledImageAccess::eSampleProjGradOffset3DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleProjGradOffset2DRectU3,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleGatherF
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherCubeF,
			expr::SampledImageAccess::eSampleGather2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DArrayF,
			expr::SampledImageAccess::eSampleGatherCubeArrayF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DShadowF,
			expr::SampledImageAccess::eSampleGatherCubeShadowF,
			expr::SampledImageAccess::eSampleGather2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DArrayShadowF,
			expr::SampledImageAccess::eSampleGatherCubeArrayShadowF,
		};
		static constexpr IntrinsicsList sampleGatherI
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherCubeI,
			expr::SampledImageAccess::eSampleGather2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DArrayI,
			expr::SampledImageAccess::eSampleGatherCubeArrayI,
		};
		static constexpr IntrinsicsList sampleGatherU
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherCubeU,
			expr::SampledImageAccess::eSampleGather2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGather2DArrayU,
			expr::SampledImageAccess::eSampleGatherCubeArrayU,
		};

		static constexpr IntrinsicsList sampleGatherOffsetF
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DArrayF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGatherOffsetI
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DArrayI,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGatherOffsetU
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffset2DArrayU,
			expr::SampledImageAccess::eInvalid,
		};

		static constexpr IntrinsicsList sampleGatherOffsetsF
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DRectF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DArrayF,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DShadowF,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DRectShadowF,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DArrayShadowF,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGatherOffsetsI
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DI,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DRectI,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DArrayI,
			expr::SampledImageAccess::eInvalid,
		};
		static constexpr IntrinsicsList sampleGatherOffsetsU
		{
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DU,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DRectU,
			expr::SampledImageAccess::eInvalid,

			expr::SampledImageAccess::eInvalid,
			expr::SampledImageAccess::eSampleGatherOffsets2DArrayU,
			expr::SampledImageAccess::eInvalid,
		};
	}

	//*************************************************************************

	template< type::ImageFormat FormatT >
	struct SampledImageFormatTraitsT< FormatT, std::enable_if_t< isFloatFormatV< FormatT > > >
	{
		static constexpr sampledImg::IntrinsicsList const & sample = sampledImg::sampleF;
		static constexpr sampledImg::IntrinsicsList const & sampleBias = sampledImg::sampleBiasF;
		static constexpr sampledImg::IntrinsicsList const & sampleOffset = sampledImg::sampleOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleOffsetBias = sampledImg::sampleOffsetBiasF;
		static constexpr sampledImg::IntrinsicsList const & sampleProj = sampledImg::sampleProjF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjBias = sampledImg::sampleProjBiasF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjOffset = sampledImg::sampleProjOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjOffsetBias = sampledImg::sampleProjOffsetBiasF;
		static constexpr sampledImg::IntrinsicsList const & sampleLod = sampledImg::sampleLodF;
		static constexpr sampledImg::IntrinsicsList const & sampleLodOffset = sampledImg::sampleLodOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjLod = sampledImg::sampleProjLodF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjLodOffset = sampledImg::sampleProjLodOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleGrad = sampledImg::sampleGradF;
		static constexpr sampledImg::IntrinsicsList const & sampleGradOffset = sampledImg::sampleGradOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjGrad = sampledImg::sampleProjGradF;
		static constexpr sampledImg::IntrinsicsList const & sampleProjGradOffset = sampledImg::sampleProjGradOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleGather = sampledImg::sampleGatherF;
		static constexpr sampledImg::IntrinsicsList const & sampleGatherOffset = sampledImg::sampleGatherOffsetF;
		static constexpr sampledImg::IntrinsicsList const & sampleGatherOffsets = sampledImg::sampleGatherOffsetsF;
	};

	template< type::ImageFormat FormatT >
	struct SampledImageFormatTraitsT< FormatT, std::enable_if_t< isSIntFormatV< FormatT > > >
	{
		static constexpr sampledImg::IntrinsicsList const & sample = sampledImg::sampleI;
		static constexpr sampledImg::IntrinsicsList const & sampleBias = sampledImg::sampleBiasI;
		static constexpr sampledImg::IntrinsicsList const & sampleOffset = sampledImg::sampleOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleOffsetBias = sampledImg::sampleOffsetBiasI;
		static constexpr sampledImg::IntrinsicsList const & sampleProj = sampledImg::sampleProjI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjBias = sampledImg::sampleProjBiasI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjOffset = sampledImg::sampleProjOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjOffsetBias = sampledImg::sampleProjOffsetBiasI;
		static constexpr sampledImg::IntrinsicsList const & sampleLod = sampledImg::sampleLodI;
		static constexpr sampledImg::IntrinsicsList const & sampleLodOffset = sampledImg::sampleLodOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjLod = sampledImg::sampleProjLodI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjLodOffset = sampledImg::sampleProjLodOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleGrad = sampledImg::sampleGradI;
		static constexpr sampledImg::IntrinsicsList const & sampleGradOffset = sampledImg::sampleGradOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjGrad = sampledImg::sampleProjGradI;
		static constexpr sampledImg::IntrinsicsList const & sampleProjGradOffset = sampledImg::sampleProjGradOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleGather = sampledImg::sampleGatherI;
		static constexpr sampledImg::IntrinsicsList const & sampleGatherOffset = sampledImg::sampleGatherOffsetI;
		static constexpr sampledImg::IntrinsicsList const & sampleGatherOffsets = sampledImg::sampleGatherOffsetsI;
	};

	template< type::ImageFormat FormatT >
	struct SampledImageFormatTraitsT< FormatT, std::enable_if_t< isUIntFormatV< FormatT > > >
	{
		static constexpr sampledImg::IntrinsicsList const & sample = sampledImg::sampleU;
		static constexpr sampledImg::IntrinsicsList const & sampleBias = sampledImg::sampleBiasU;
		static constexpr sampledImg::IntrinsicsList const & sampleOffset = sampledImg::sampleOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleOffsetBias = sampledImg::sampleOffsetBiasU;
		static constexpr sampledImg::IntrinsicsList const & sampleProj = sampledImg::sampleProjU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjBias = sampledImg::sampleProjBiasU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjOffset = sampledImg::sampleProjOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjOffsetBias = sampledImg::sampleProjOffsetBiasU;
		static constexpr sampledImg::IntrinsicsList const & sampleLod = sampledImg::sampleLodU;
		static constexpr sampledImg::IntrinsicsList const & sampleLodOffset = sampledImg::sampleLodOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjLod = sampledImg::sampleProjLodU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjLodOffset = sampledImg::sampleProjLodOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleGrad = sampledImg::sampleGradU;
		static constexpr sampledImg::IntrinsicsList const & sampleGradOffset = sampledImg::sampleGradOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjGrad = sampledImg::sampleProjGradU;
		static constexpr sampledImg::IntrinsicsList const & sampleProjGradOffset = sampledImg::sampleProjGradOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleGather = sampledImg::sampleGatherU;
		static constexpr sampledImg::IntrinsicsList const & sampleGatherOffset = sampledImg::sampleGatherOffsetU;
		static constexpr sampledImg::IntrinsicsList const & sampleGatherOffsets = sampledImg::sampleGatherOffsetsU;
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
		using SampleType = sdw::Vec3;
		using DerivativeType = sdw::Vec3;
		using FetchType = sdw::Vec3;
		using GatherType = sdw::Vec3;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e1D, true >
	{
		using SampleType = sdw::Vec2;
		using OffsetType = sdw::Int;
		using FetchType = sdw::IVec2;
		using DerivativeType = sdw::Float;
		using SizeType = sdw::IVec2;
	};

	template<>
	struct SampledImageCoordsGetterT< ast::type::ImageDim::e2D, true >
	{
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
			, bool MsT
			, bool ComparisonT
			, expr::SampledImageAccess SampledImageAccessT
			, typename ... ParamsT >
		ReturnWrapperT< ReturnT > writeSampledImageAccessCall( SampledImageT< FormatT, DimT, ArrayedT, MsT > const & image
			, SamplerT< ComparisonT > const & sampler
			, ParamsT const & ... params )
		{
			static_assert( SampledImageAccessT != expr::SampledImageAccess::eInvalid );
			static_assert( SampledImageAccessT != expr::SampledImageAccess::eUndefined );

			auto & cache = findTypesCache( image, params... );
			return ReturnWrapperT< ReturnT >{ findWriterMandat( image, params... )
				, expr::makeSampledImageAccessCall( ReturnT::makeType( cache )
					, SampledImageAccessT
					, makeExpr( image )
					, makeExpr( sampler )
					, makeExpr( params )... )
				, areOptionalEnabled( image, params... ) };
		}

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampleFuncT
		{
			using SampleT = SampledImageSampleT< DimT, ArrayedT >;

			auto sample( SamplerT< false > const & sampler
				, SampleT const & coord )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sample[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord );
			}

			auto sample( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sample[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto sample( SamplerT< false > const & sampler
				, SampleT const & coord
				, Float const & bias )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, bias );
			}

			auto sample( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, Float const & bias )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto sample( SamplerT< false > const & sampler
				, SampleT const & coord
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, offset );
			}

			auto sample( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto sample( SamplerT< false > const & sampler
				, SampleT const & coord
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleOffsetBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, offset
						, bias );
			}

			auto sample( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleOffsetBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, offset
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto lod( SamplerT< false > const & sampler
				, SampleT const & coord
				, Float const & lod )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleLod[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, lod );
			}

			auto lod( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, Float const & lod )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleLod[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto lod( SamplerT< false > const & sampler
				, SampleT const & coord
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleLodOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, lod
						, offset );
			}

			auto lod( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleLodOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, lod
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto proj( SamplerT< false > const & sampler
				, SampleProjT const & coord )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProj[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord );
			}

			auto proj( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProj[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto proj( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, Float const & bias )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, bias );
			}

			auto proj( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, Float const & bias )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto proj( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, offset );
			}

			auto proj( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto proj( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjOffsetBias[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, offset
						, bias );
			}

			auto proj( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, OffsetT const & offset
				, Float const & bias )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjOffsetBias[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, offset
						, bias );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto projLod( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, Float const & lod )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjLod[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, lod );
			}

			auto projLod( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, Float const & lod )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjLod[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, lod );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto projLod( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjLodOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, lod
						, offset );
			}

			auto projLod( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, Float const & lod
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjLodOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, lod
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto grad( SamplerT< false > const & sampler
				, SampleT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleGrad[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, dPdx
						, dPdy );
			}

			auto grad( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleGrad[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, dPdx
						, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto grad( SamplerT< false > const & sampler
				, SampleT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleGradOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, dPdx
						, dPdy
						, offset );
			}

			auto grad( SamplerT< true > const & sampler
				, SampleT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleGradOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, dPdx
						, dPdy
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto projGrad( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjGrad[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, dPdx
						, dPdy );
			}

			auto projGrad( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy )const
			{
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjGrad[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, dPdx
						, dPdy );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto projGrad( SamplerT< false > const & sampler
				, SampleProjT const & coord
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleProjGradOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, dPdx
						, dPdy
						, offset );
			}

			auto projGrad( SamplerT< true > const & sampler
				, SampleProjT const & coord
				, Float const & ref
				, DerivativeT const & dPdx
				, DerivativeT const & dPdy
				, OffsetT const & offset )const
			{
				assert( offset.getExpr()->isConstant() );
				return writeSampledImageAccessCall< ImageSampleT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleProjGradOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, dPdx
						, dPdy
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto gather( SamplerT< false > const & sampler
				, GatherT const & coord
				, Int const & comp )const
			{
				return writeSampledImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleGather[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, comp );
			}

			auto gather( SamplerT< true > const & sampler
				, GatherT const & coord
				, Float const & ref )const
			{
				return writeSampledImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleGather[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto gather( SamplerT< false > const & sampler
				, GatherT const & coord
				, Int const & comp
				, OffsetT const & offset )const
			{
				return writeSampledImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleGatherOffset[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, comp
						, offset );
			}

			auto gather( SamplerT< true > const & sampler
				, GatherT const & coord
				, Float const & ref
				, OffsetT const & offset )const
			{
				return writeSampledImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleGatherOffset[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, offset );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
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

			auto gather( SamplerT< false > const & sampler
				, GatherT const & coord
				, Int const & comp
				, Array< OffsetT > const & offsets )const
			{
				return writeSampledImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, false
					, SampledImageFormatTraitsT< FormatT >::sampleGatherOffsets[sampledImg::getIndex< DimT, ArrayedT, false >()] >( get()
						, sampler
						, coord
						, comp
						, offsets );
			}

			auto gather( SamplerT< true > const & sampler
				, GatherT const & coord
				, Float const & ref
				, Array< OffsetT > const & offsets )const
			{
				return writeSampledImageAccessCall< ImageGatherT< FormatT >, FormatT, DimT, ArrayedT, MsT, true
					, SampledImageFormatTraitsT< FormatT >::sampleGatherOffsets[sampledImg::getIndex< DimT, ArrayedT, true >()] >( get()
						, sampler
						, coord
						, ref
						, offsets );
			}

		private:
			SampledImageT< FormatT, DimT, ArrayedT, MsT > const & get()const
			{
				return static_cast< SampledImageT< FormatT, DimT, ArrayedT, MsT > const & >( *this );
			}
		};

		//*************************************************************************

		template< ast::type::ImageFormat FormatT
			, ast::type::ImageDim DimT
			, bool ArrayedT
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( sdw::isSpl2dV< DimT, ArrayedT > ) > >
			: public SampledImage
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
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( sdw::isSpl1dV< DimT, ArrayedT >
				|| sdw::isSpl3dV< DimT, ArrayedT > ) > >
			: public SampledImage
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
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( sdw::isSpl1dArrayV< DimT, ArrayedT > ) > >
			: public SampledImage
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
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
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( sdw::isSpl2dArrayV< DimT, ArrayedT > ) > >
			: public SampledImage
			, public SampleFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleOffsetBiasFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodFuncT< FormatT, DimT, ArrayedT, MsT >
			, public SampleLodOffsetFuncT< FormatT, DimT, ArrayedT, MsT >
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
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( sdw::isSplCubeV< DimT, ArrayedT >
				|| sdw::isSplCubeArrayV< DimT, ArrayedT > ) > >
			: public SampledImage
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
			, bool MsT >
		struct SampledImageFuncsT< FormatT
			, DimT
			, ArrayedT
			, MsT
			, std::enable_if_t< ( sdw::isSplBufferV< DimT, ArrayedT > ) > >
			: public SampledImage
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
		, bool MsT >
	SampledImageT< FormatT, DimT, ArrayedT, MsT >::SampledImageT( ShaderWriter & writer
		, expr::ExprPtr expr
		, bool enabled )
		: sampledImg::SampledImageFuncsT< FormatT, DimT, ArrayedT, MsT >{ writer, std::move( expr ), enabled }
	{
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	template< typename T >
	SampledImageT< FormatT, DimT, ArrayedT, MsT > & SampledImageT< FormatT, DimT, ArrayedT, MsT >::operator=( T const & rhs )
	{
		sampledImg::SampledImageFuncsT< FormatT, DimT, ArrayedT, MsT >::operator=( rhs );
		return *this;
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	ast::type::ImageConfiguration SampledImageT< FormatT, DimT, ArrayedT, MsT >::makeConfig()
	{
		return ast::type::makeConfig< FormatT, ast::type::AccessKind::eRead, DimT, ArrayedT, MsT >( true );
	}

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT >
	inline ast::type::TypePtr SampledImageT< FormatT, DimT, ArrayedT, MsT >::makeType( ast::type::TypesCache & cache )
	{
		return cache.getSampledImage( makeConfig() );
	}

	//*************************************************************************
}
