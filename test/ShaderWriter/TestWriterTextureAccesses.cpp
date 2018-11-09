#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	struct CoordsGetter;

	template<>
	struct CoordsGetter< ast::type::ImageDim::eBuffer, false, false >
	{
		using QueryLodType = sdw::Int;
		using SampleType = sdw::Int;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e1D, false, false >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Float;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e2D, false, false >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e3D, false, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eCube, false, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eRect, false, false >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e1D, false, true >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Float;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e2D, false, true >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eCube, false, true >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eRect, false, true >
	{
		using SampleType = sdw::Vec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e1D, true, false >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Vec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e2D, true, false >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e3D, true, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec4;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eCube, true, false >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec4;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e1D, true, true >
	{
		using QueryLodType = sdw::Float;
		using SampleType = sdw::Vec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e2D, true, true >
	{
		using QueryLodType = sdw::Vec2;
		using SampleType = sdw::Vec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eCube, true, true >
	{
		using QueryLodType = sdw::Vec3;
		using SampleType = sdw::Vec4;
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester
	{
		static void test()
		{
			auto name = "testTextureSize" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", textureSize( s, 0_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester< SampledT, ast::type::ImageDim::eBuffer, FormatT, ArrayedT, DepthT, MsT >
	{
		static void test()
		{
			auto name = "testTextureSize" + sdw::debug::getName( SampledT, ast::type::ImageDim::eBuffer, FormatT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, ast::type::ImageDim::eBuffer, FormatT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", textureSize( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester< SampledT, ast::type::ImageDim::eRect, FormatT, ArrayedT, DepthT, MsT >
	{
		static void test()
		{
			auto name = "testTextureSize" + sdw::debug::getName( SampledT, ast::type::ImageDim::eRect, FormatT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, ast::type::ImageDim::eRect, FormatT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", textureSize( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsTextureSize()
	{
		TextureSizeTester< FImg1DRGBA32F >::test();
		TextureSizeTester< FImg1DRGBA8I >::test();
		TextureSizeTester< FImg1DRGBA8U >::test();
		TextureSizeTester< FImg2DRGBA32F >::test();
		TextureSizeTester< FImg2DRGBA8I >::test();
		TextureSizeTester< FImg2DRGBA8U >::test();
		TextureSizeTester< FImg3DRGBA32F >::test();
		TextureSizeTester< FImg3DRGBA8I >::test();
		TextureSizeTester< FImg3DRGBA8U >::test();
		TextureSizeTester< FImgRectRGBA32F >::test();
		TextureSizeTester< FImgRectRGBA8I >::test();
		TextureSizeTester< FImgRectRGBA8U >::test();
		TextureSizeTester< FImgCubeRGBA32F >::test();
		TextureSizeTester< FImgCubeRGBA8I >::test();
		TextureSizeTester< FImgCubeRGBA8U >::test();
		TextureSizeTester< FImgBufferRGBA32F >::test();
		TextureSizeTester< FImgBufferRGBA8I >::test();
		TextureSizeTester< FImgBufferRGBA8U >::test();
		TextureSizeTester< FImg1DArrayRGBA32F >::test();
		TextureSizeTester< FImg1DArrayRGBA8I >::test();
		TextureSizeTester< FImg1DArrayRGBA8U >::test();
		TextureSizeTester< FImg2DArrayRGBA32F >::test();
		TextureSizeTester< FImg2DArrayRGBA8I >::test();
		TextureSizeTester< FImg2DArrayRGBA8U >::test();
		TextureSizeTester< FImgCubeArrayRGBA32F >::test();
		TextureSizeTester< FImgCubeArrayRGBA8I >::test();
		TextureSizeTester< FImgCubeArrayRGBA8U >::test();
		TextureSizeTester< FImg1DShadowRGBA32F >::test();
		TextureSizeTester< FImg2DShadowRGBA32F >::test();
		TextureSizeTester< FImgRectShadowRGBA32F >::test();
		TextureSizeTester< FImgCubeShadowRGBA32F >::test();
		TextureSizeTester< FImg1DArrayShadowRGBA32F >::test();
		TextureSizeTester< FImg2DArrayShadowRGBA32F >::test();
		TextureSizeTester< FImgCubeArrayShadowRGBA32F >::test();

		TextureSizeTester< IImg1DRGBA32F >::test();
		TextureSizeTester< IImg1DRGBA8I >::test();
		TextureSizeTester< IImg1DRGBA8U >::test();
		TextureSizeTester< IImg2DRGBA32F >::test();
		TextureSizeTester< IImg2DRGBA8I >::test();
		TextureSizeTester< IImg2DRGBA8U >::test();
		TextureSizeTester< IImg3DRGBA32F >::test();
		TextureSizeTester< IImg3DRGBA8I >::test();
		TextureSizeTester< IImg3DRGBA8U >::test();
		TextureSizeTester< IImgRectRGBA32F >::test();
		TextureSizeTester< IImgRectRGBA8I >::test();
		TextureSizeTester< IImgRectRGBA8U >::test();
		TextureSizeTester< IImgCubeRGBA32F >::test();
		TextureSizeTester< IImgCubeRGBA8I >::test();
		TextureSizeTester< IImgCubeRGBA8U >::test();
		TextureSizeTester< IImgBufferRGBA32F >::test();
		TextureSizeTester< IImgBufferRGBA8I >::test();
		TextureSizeTester< IImgBufferRGBA8U >::test();
		TextureSizeTester< IImg1DArrayRGBA32F >::test();
		TextureSizeTester< IImg1DArrayRGBA8I >::test();
		TextureSizeTester< IImg1DArrayRGBA8U >::test();
		TextureSizeTester< IImg2DArrayRGBA32F >::test();
		TextureSizeTester< IImg2DArrayRGBA8I >::test();
		TextureSizeTester< IImg2DArrayRGBA8U >::test();
		TextureSizeTester< IImgCubeArrayRGBA32F >::test();
		TextureSizeTester< IImgCubeArrayRGBA8I >::test();
		TextureSizeTester< IImgCubeArrayRGBA8U >::test();

		TextureSizeTester< UImg1DRGBA32F >::test();
		TextureSizeTester< UImg1DRGBA8I >::test();
		TextureSizeTester< UImg1DRGBA8U >::test();
		TextureSizeTester< UImg2DRGBA32F >::test();
		TextureSizeTester< UImg2DRGBA8I >::test();
		TextureSizeTester< UImg2DRGBA8U >::test();
		TextureSizeTester< UImg3DRGBA32F >::test();
		TextureSizeTester< UImg3DRGBA8I >::test();
		TextureSizeTester< UImg3DRGBA8U >::test();
		TextureSizeTester< UImgRectRGBA32F >::test();
		TextureSizeTester< UImgRectRGBA8I >::test();
		TextureSizeTester< UImgRectRGBA8U >::test();
		TextureSizeTester< UImgCubeRGBA32F >::test();
		TextureSizeTester< UImgCubeRGBA8I >::test();
		TextureSizeTester< UImgCubeRGBA8U >::test();
		TextureSizeTester< UImgBufferRGBA32F >::test();
		TextureSizeTester< UImgBufferRGBA8I >::test();
		TextureSizeTester< UImgBufferRGBA8U >::test();
		TextureSizeTester< UImg1DArrayRGBA32F >::test();
		TextureSizeTester< UImg1DArrayRGBA8I >::test();
		TextureSizeTester< UImg1DArrayRGBA8U >::test();
		TextureSizeTester< UImg2DArrayRGBA32F >::test();
		TextureSizeTester< UImg2DArrayRGBA8I >::test();
		TextureSizeTester< UImg2DArrayRGBA8U >::test();
		TextureSizeTester< UImgCubeArrayRGBA32F >::test();
		TextureSizeTester< UImgCubeArrayRGBA8I >::test();
		TextureSizeTester< UImgCubeArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureQueryLodTester
	{
		using Coords = typename CoordsGetter< DimT, ArrayedT, DepthT >::QueryLodType;

		static void test()
		{
			auto name = "testTextureQueryLod" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", textureQueryLod( s, test::getDefault< Coords >( writer.getShader() ) ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		}
	};

	void testsTextureQueryLod()
	{
		TextureQueryLodTester< FImg1DRGBA32F >::test();
		TextureQueryLodTester< FImg1DRGBA8I >::test();
		TextureQueryLodTester< FImg1DRGBA8U >::test();
		TextureQueryLodTester< FImg2DRGBA32F >::test();
		TextureQueryLodTester< FImg2DRGBA8I >::test();
		TextureQueryLodTester< FImg2DRGBA8U >::test();
		TextureQueryLodTester< FImg3DRGBA32F >::test();
		TextureQueryLodTester< FImg3DRGBA8I >::test();
		TextureQueryLodTester< FImg3DRGBA8U >::test();
		TextureQueryLodTester< FImgCubeRGBA32F >::test();
		TextureQueryLodTester< FImgCubeRGBA8I >::test();
		TextureQueryLodTester< FImgCubeRGBA8U >::test();
		TextureQueryLodTester< FImg1DArrayRGBA32F >::test();
		TextureQueryLodTester< FImg1DArrayRGBA8I >::test();
		TextureQueryLodTester< FImg1DArrayRGBA8U >::test();
		TextureQueryLodTester< FImg2DArrayRGBA32F >::test();
		TextureQueryLodTester< FImg2DArrayRGBA8I >::test();
		TextureQueryLodTester< FImg2DArrayRGBA8U >::test();
		TextureQueryLodTester< FImgCubeArrayRGBA32F >::test();
		TextureQueryLodTester< FImgCubeArrayRGBA8I >::test();
		TextureQueryLodTester< FImgCubeArrayRGBA8U >::test();
		TextureQueryLodTester< FImg1DShadowRGBA32F >::test();
		TextureQueryLodTester< FImg2DShadowRGBA32F >::test();
		TextureQueryLodTester< FImgCubeShadowRGBA32F >::test();
		TextureQueryLodTester< FImg1DArrayShadowRGBA32F >::test();
		TextureQueryLodTester< FImg2DArrayShadowRGBA32F >::test();
		TextureQueryLodTester< FImgCubeArrayShadowRGBA32F >::test();

		TextureQueryLodTester< IImg1DRGBA32F >::test();
		TextureQueryLodTester< IImg1DRGBA8I >::test();
		TextureQueryLodTester< IImg1DRGBA8U >::test();
		TextureQueryLodTester< IImg2DRGBA32F >::test();
		TextureQueryLodTester< IImg2DRGBA8I >::test();
		TextureQueryLodTester< IImg2DRGBA8U >::test();
		TextureQueryLodTester< IImg3DRGBA32F >::test();
		TextureQueryLodTester< IImg3DRGBA8I >::test();
		TextureQueryLodTester< IImg3DRGBA8U >::test();
		TextureQueryLodTester< IImgCubeRGBA32F >::test();
		TextureQueryLodTester< IImgCubeRGBA8I >::test();
		TextureQueryLodTester< IImgCubeRGBA8U >::test();
		TextureQueryLodTester< IImg1DArrayRGBA32F >::test();
		TextureQueryLodTester< IImg1DArrayRGBA8I >::test();
		TextureQueryLodTester< IImg1DArrayRGBA8U >::test();
		TextureQueryLodTester< IImg2DArrayRGBA32F >::test();
		TextureQueryLodTester< IImg2DArrayRGBA8I >::test();
		TextureQueryLodTester< IImg2DArrayRGBA8U >::test();
		TextureQueryLodTester< IImgCubeArrayRGBA32F >::test();
		TextureQueryLodTester< IImgCubeArrayRGBA8I >::test();
		TextureQueryLodTester< IImgCubeArrayRGBA8U >::test();

		TextureQueryLodTester< UImg1DRGBA32F >::test();
		TextureQueryLodTester< UImg1DRGBA8I >::test();
		TextureQueryLodTester< UImg1DRGBA8U >::test();
		TextureQueryLodTester< UImg2DRGBA32F >::test();
		TextureQueryLodTester< UImg2DRGBA8I >::test();
		TextureQueryLodTester< UImg2DRGBA8U >::test();
		TextureQueryLodTester< UImg3DRGBA32F >::test();
		TextureQueryLodTester< UImg3DRGBA8I >::test();
		TextureQueryLodTester< UImg3DRGBA8U >::test();
		TextureQueryLodTester< UImgCubeRGBA32F >::test();
		TextureQueryLodTester< UImgCubeRGBA8I >::test();
		TextureQueryLodTester< UImgCubeRGBA8U >::test();
		TextureQueryLodTester< UImg1DArrayRGBA32F >::test();
		TextureQueryLodTester< UImg1DArrayRGBA8I >::test();
		TextureQueryLodTester< UImg1DArrayRGBA8U >::test();
		TextureQueryLodTester< UImg2DArrayRGBA32F >::test();
		TextureQueryLodTester< UImg2DArrayRGBA8I >::test();
		TextureQueryLodTester< UImg2DArrayRGBA8U >::test();
		TextureQueryLodTester< UImgCubeArrayRGBA32F >::test();
		TextureQueryLodTester< UImgCubeArrayRGBA8I >::test();
		TextureQueryLodTester< UImgCubeArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureQueryLevelsTester
	{
		static void test()
		{
			auto name = "testTextureQueryLevels" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", textureQueryLevels( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		}
	};

	void testsTextureQueryLevels()
	{
		TextureQueryLevelsTester< FImg1DRGBA32F >::test();
		TextureQueryLevelsTester< FImg1DRGBA8I >::test();
		TextureQueryLevelsTester< FImg1DRGBA8U >::test();
		TextureQueryLevelsTester< FImg2DRGBA32F >::test();
		TextureQueryLevelsTester< FImg2DRGBA8I >::test();
		TextureQueryLevelsTester< FImg2DRGBA8U >::test();
		TextureQueryLevelsTester< FImg3DRGBA32F >::test();
		TextureQueryLevelsTester< FImg3DRGBA8I >::test();
		TextureQueryLevelsTester< FImg3DRGBA8U >::test();
		TextureQueryLevelsTester< FImgCubeRGBA32F >::test();
		TextureQueryLevelsTester< FImgCubeRGBA8I >::test();
		TextureQueryLevelsTester< FImgCubeRGBA8U >::test();
		TextureQueryLevelsTester< FImg1DArrayRGBA32F >::test();
		TextureQueryLevelsTester< FImg1DArrayRGBA8I >::test();
		TextureQueryLevelsTester< FImg1DArrayRGBA8U >::test();
		TextureQueryLevelsTester< FImg2DArrayRGBA32F >::test();
		TextureQueryLevelsTester< FImg2DArrayRGBA8I >::test();
		TextureQueryLevelsTester< FImg2DArrayRGBA8U >::test();
		TextureQueryLevelsTester< FImgCubeArrayRGBA32F >::test();
		TextureQueryLevelsTester< FImgCubeArrayRGBA8I >::test();
		TextureQueryLevelsTester< FImgCubeArrayRGBA8U >::test();
		TextureQueryLevelsTester< FImg1DShadowRGBA32F >::test();
		TextureQueryLevelsTester< FImg2DShadowRGBA32F >::test();
		TextureQueryLevelsTester< FImgCubeShadowRGBA32F >::test();
		TextureQueryLevelsTester< FImg1DArrayShadowRGBA32F >::test();
		TextureQueryLevelsTester< FImg2DArrayShadowRGBA32F >::test();
		TextureQueryLevelsTester< FImgCubeArrayShadowRGBA32F >::test();

		TextureQueryLevelsTester< IImg1DRGBA32F >::test();
		TextureQueryLevelsTester< IImg1DRGBA8I >::test();
		TextureQueryLevelsTester< IImg1DRGBA8U >::test();
		TextureQueryLevelsTester< IImg2DRGBA32F >::test();
		TextureQueryLevelsTester< IImg2DRGBA8I >::test();
		TextureQueryLevelsTester< IImg2DRGBA8U >::test();
		TextureQueryLevelsTester< IImg3DRGBA32F >::test();
		TextureQueryLevelsTester< IImg3DRGBA8I >::test();
		TextureQueryLevelsTester< IImg3DRGBA8U >::test();
		TextureQueryLevelsTester< IImgCubeRGBA32F >::test();
		TextureQueryLevelsTester< IImgCubeRGBA8I >::test();
		TextureQueryLevelsTester< IImgCubeRGBA8U >::test();
		TextureQueryLevelsTester< IImg1DArrayRGBA32F >::test();
		TextureQueryLevelsTester< IImg1DArrayRGBA8I >::test();
		TextureQueryLevelsTester< IImg1DArrayRGBA8U >::test();
		TextureQueryLevelsTester< IImg2DArrayRGBA32F >::test();
		TextureQueryLevelsTester< IImg2DArrayRGBA8I >::test();
		TextureQueryLevelsTester< IImg2DArrayRGBA8U >::test();
		TextureQueryLevelsTester< IImgCubeArrayRGBA32F >::test();
		TextureQueryLevelsTester< IImgCubeArrayRGBA8I >::test();
		TextureQueryLevelsTester< IImgCubeArrayRGBA8U >::test();

		TextureQueryLevelsTester< UImg1DRGBA32F >::test();
		TextureQueryLevelsTester< UImg1DRGBA8I >::test();
		TextureQueryLevelsTester< UImg1DRGBA8U >::test();
		TextureQueryLevelsTester< UImg2DRGBA32F >::test();
		TextureQueryLevelsTester< UImg2DRGBA8I >::test();
		TextureQueryLevelsTester< UImg2DRGBA8U >::test();
		TextureQueryLevelsTester< UImg3DRGBA32F >::test();
		TextureQueryLevelsTester< UImg3DRGBA8I >::test();
		TextureQueryLevelsTester< UImg3DRGBA8U >::test();
		TextureQueryLevelsTester< UImgCubeRGBA32F >::test();
		TextureQueryLevelsTester< UImgCubeRGBA8I >::test();
		TextureQueryLevelsTester< UImgCubeRGBA8U >::test();
		TextureQueryLevelsTester< UImg1DArrayRGBA32F >::test();
		TextureQueryLevelsTester< UImg1DArrayRGBA8I >::test();
		TextureQueryLevelsTester< UImg1DArrayRGBA8U >::test();
		TextureQueryLevelsTester< UImg2DArrayRGBA32F >::test();
		TextureQueryLevelsTester< UImg2DArrayRGBA8I >::test();
		TextureQueryLevelsTester< UImg2DArrayRGBA8U >::test();
		TextureQueryLevelsTester< UImgCubeArrayRGBA32F >::test();
		TextureQueryLevelsTester< UImgCubeArrayRGBA8I >::test();
		TextureQueryLevelsTester< UImgCubeArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		struct TextureTester
	{
		using Coords = typename CoordsGetter< DimT, ArrayedT, DepthT >::SampleType;

		static void test()
		{
			auto name = "testTexture" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c", texture( s, test::getDefault< Coords >( writer.getShader() ) ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		}
	};

	void testsTexture()
	{
		TextureSizeTester< FImg1DRGBA32F >::test();
		TextureSizeTester< FImg1DRGBA8I >::test();
		TextureSizeTester< FImg1DRGBA8U >::test();
		TextureSizeTester< FImg2DRGBA32F >::test();
		TextureSizeTester< FImg2DRGBA8I >::test();
		TextureSizeTester< FImg2DRGBA8U >::test();
		TextureSizeTester< FImg3DRGBA32F >::test();
		TextureSizeTester< FImg3DRGBA8I >::test();
		TextureSizeTester< FImg3DRGBA8U >::test();
		TextureSizeTester< FImgRectRGBA32F >::test();
		TextureSizeTester< FImgRectRGBA8I >::test();
		TextureSizeTester< FImgRectRGBA8U >::test();
		TextureSizeTester< FImgCubeRGBA32F >::test();
		TextureSizeTester< FImgCubeRGBA8I >::test();
		TextureSizeTester< FImgCubeRGBA8U >::test();
		TextureSizeTester< FImg1DArrayRGBA32F >::test();
		TextureSizeTester< FImg1DArrayRGBA8I >::test();
		TextureSizeTester< FImg1DArrayRGBA8U >::test();
		TextureSizeTester< FImg2DArrayRGBA32F >::test();
		TextureSizeTester< FImg2DArrayRGBA8I >::test();
		TextureSizeTester< FImg2DArrayRGBA8U >::test();
		TextureSizeTester< FImgCubeArrayRGBA32F >::test();
		TextureSizeTester< FImgCubeArrayRGBA8I >::test();
		TextureSizeTester< FImgCubeArrayRGBA8U >::test();
		TextureSizeTester< FImg1DShadowRGBA32F >::test();
		TextureSizeTester< FImg2DShadowRGBA32F >::test();
		TextureSizeTester< FImgRectShadowRGBA32F >::test();
		TextureSizeTester< FImgCubeShadowRGBA32F >::test();
		TextureSizeTester< FImg1DArrayShadowRGBA32F >::test();
		TextureSizeTester< FImg2DArrayShadowRGBA32F >::test();
		TextureSizeTester< FImgCubeArrayShadowRGBA32F >::test();

		TextureSizeTester< IImg1DRGBA32F >::test();
		TextureSizeTester< IImg1DRGBA8I >::test();
		TextureSizeTester< IImg1DRGBA8U >::test();
		TextureSizeTester< IImg2DRGBA32F >::test();
		TextureSizeTester< IImg2DRGBA8I >::test();
		TextureSizeTester< IImg2DRGBA8U >::test();
		TextureSizeTester< IImg3DRGBA32F >::test();
		TextureSizeTester< IImg3DRGBA8I >::test();
		TextureSizeTester< IImg3DRGBA8U >::test();
		TextureSizeTester< IImgRectRGBA32F >::test();
		TextureSizeTester< IImgRectRGBA8I >::test();
		TextureSizeTester< IImgRectRGBA8U >::test();
		TextureSizeTester< IImgCubeRGBA32F >::test();
		TextureSizeTester< IImgCubeRGBA8I >::test();
		TextureSizeTester< IImgCubeRGBA8U >::test();
		TextureSizeTester< IImg1DArrayRGBA32F >::test();
		TextureSizeTester< IImg1DArrayRGBA8I >::test();
		TextureSizeTester< IImg1DArrayRGBA8U >::test();
		TextureSizeTester< IImg2DArrayRGBA32F >::test();
		TextureSizeTester< IImg2DArrayRGBA8I >::test();
		TextureSizeTester< IImg2DArrayRGBA8U >::test();
		TextureSizeTester< IImgCubeArrayRGBA32F >::test();
		TextureSizeTester< IImgCubeArrayRGBA8I >::test();
		TextureSizeTester< IImgCubeArrayRGBA8U >::test();

		TextureSizeTester< UImg1DRGBA32F >::test();
		TextureSizeTester< UImg1DRGBA8I >::test();
		TextureSizeTester< UImg1DRGBA8U >::test();
		TextureSizeTester< UImg2DRGBA32F >::test();
		TextureSizeTester< UImg2DRGBA8I >::test();
		TextureSizeTester< UImg2DRGBA8U >::test();
		TextureSizeTester< UImg3DRGBA32F >::test();
		TextureSizeTester< UImg3DRGBA8I >::test();
		TextureSizeTester< UImg3DRGBA8U >::test();
		TextureSizeTester< UImgRectRGBA32F >::test();
		TextureSizeTester< UImgRectRGBA8I >::test();
		TextureSizeTester< UImgRectRGBA8U >::test();
		TextureSizeTester< UImgCubeRGBA32F >::test();
		TextureSizeTester< UImgCubeRGBA8I >::test();
		TextureSizeTester< UImgCubeRGBA8U >::test();
		TextureSizeTester< UImg1DArrayRGBA32F >::test();
		TextureSizeTester< UImg1DArrayRGBA8I >::test();
		TextureSizeTester< UImg1DArrayRGBA8U >::test();
		TextureSizeTester< UImg2DArrayRGBA32F >::test();
		TextureSizeTester< UImg2DArrayRGBA8I >::test();
		TextureSizeTester< UImg2DArrayRGBA8U >::test();
		TextureSizeTester< UImgCubeArrayRGBA32F >::test();
		TextureSizeTester< UImgCubeArrayRGBA8I >::test();
		TextureSizeTester< UImgCubeArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
		struct TextureShadowTester
	{
		using Coords = typename CoordsGetter< DimT, ArrayedT, true >::SampleType;

		static void test()
		{
			auto name = "testTextureShadow" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, true, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, FormatT, ArrayedT, true, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c", texture( s, test::getDefault< Coords >( writer.getShader() ), 0.5_f ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		}
	};

	void testsTextureShadow()
	{
		TextureShadowTester< FImg1DShadowRGBA32F >::test();
		TextureShadowTester< FImg1DArrayShadowRGBA32F >::test();
		TextureShadowTester< FImg2DShadowRGBA32F >::test();
		TextureShadowTester< FImg2DArrayShadowRGBA32F >::test();
		TextureShadowTester< FImgCubeShadowRGBA32F >::test();
		TextureShadowTester< FImgCubeArrayShadowRGBA32F >::test();
		TextureShadowTester< FImgRectShadowRGBA32F >::test();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterTextureAccesses" );
	testsTextureSize();
	testsTextureQueryLod();
	testsTextureQueryLevels();
	testsTexture();
	testsTextureShadow();
	testSuiteEnd();
}
