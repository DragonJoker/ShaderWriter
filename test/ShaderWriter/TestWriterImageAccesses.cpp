#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	struct CoordsGetter;

	template<>
	struct CoordsGetter< ast::type::ImageDim::e1D, false >
	{
		using Type = sdw::Int;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e2D, false >
	{
		using Type = sdw::IVec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e3D, false >
	{
		using Type = sdw::IVec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eRect, false >
	{
		using Type = sdw::IVec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eCube, false >
	{
		using Type = sdw::IVec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eBuffer, false >
	{
		using Type = sdw::Int;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e1D, true >
	{
		using Type = sdw::IVec2;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::e2D, true >
	{
		using Type = sdw::IVec3;
	};

	template<>
	struct CoordsGetter< ast::type::ImageDim::eCube, true >
	{
		using Type = sdw::IVec3;
	};

	template< ast::type::ImageDim DimT
		, bool ArrayedT >
	using CoordsGetterT = typename CoordsGetter< DimT, ArrayedT >::Type;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSizeTester
	{
		static void test()
		{
			auto name = "testImageSize" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSize( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageSize()
	{
		ImageSizeTester< FImg1DRGBA32F >::test();
		ImageSizeTester< FImg1DRGBA8I >::test();
		ImageSizeTester< FImg1DRGBA8U >::test();
		ImageSizeTester< FImg2DRGBA32F >::test();
		ImageSizeTester< FImg2DRGBA8I >::test();
		ImageSizeTester< FImg2DRGBA8U >::test();
		ImageSizeTester< FImg3DRGBA32F >::test();
		ImageSizeTester< FImg3DRGBA8I >::test();
		ImageSizeTester< FImg3DRGBA8U >::test();
		ImageSizeTester< FImgRectRGBA32F >::test();
		ImageSizeTester< FImgRectRGBA8I >::test();
		ImageSizeTester< FImgRectRGBA8U >::test();
		ImageSizeTester< FImgCubeRGBA32F >::test();
		ImageSizeTester< FImgCubeRGBA8I >::test();
		ImageSizeTester< FImgCubeRGBA8U >::test();
		ImageSizeTester< FImgBufferRGBA32F >::test();
		ImageSizeTester< FImgBufferRGBA8I >::test();
		ImageSizeTester< FImgBufferRGBA8U >::test();
		ImageSizeTester< FImg1DArrayRGBA32F >::test();
		ImageSizeTester< FImg1DArrayRGBA8I >::test();
		ImageSizeTester< FImg1DArrayRGBA8U >::test();
		ImageSizeTester< FImg2DArrayRGBA32F >::test();
		ImageSizeTester< FImg2DArrayRGBA8I >::test();
		ImageSizeTester< FImg2DArrayRGBA8U >::test();
		ImageSizeTester< FImgCubeArrayRGBA32F >::test();
		ImageSizeTester< FImgCubeArrayRGBA8I >::test();
		ImageSizeTester< FImgCubeArrayRGBA8U >::test();
		ImageSizeTester< FImg2DMSRGBA32F >::test();
		ImageSizeTester< FImg2DMSRGBA8I >::test();
		ImageSizeTester< FImg2DMSRGBA8U >::test();
		ImageSizeTester< FImg2DMSArrayRGBA32F >::test();
		ImageSizeTester< FImg2DMSArrayRGBA8I >::test();
		ImageSizeTester< FImg2DMSArrayRGBA8U >::test();

		ImageSizeTester< IImg1DRGBA32F >::test();
		ImageSizeTester< IImg1DRGBA8I >::test();
		ImageSizeTester< IImg1DRGBA8U >::test();
		ImageSizeTester< IImg2DRGBA32F >::test();
		ImageSizeTester< IImg2DRGBA8I >::test();
		ImageSizeTester< IImg2DRGBA8U >::test();
		ImageSizeTester< IImg3DRGBA32F >::test();
		ImageSizeTester< IImg3DRGBA8I >::test();
		ImageSizeTester< IImg3DRGBA8U >::test();
		ImageSizeTester< IImgRectRGBA32F >::test();
		ImageSizeTester< IImgRectRGBA8I >::test();
		ImageSizeTester< IImgRectRGBA8U >::test();
		ImageSizeTester< IImgCubeRGBA32F >::test();
		ImageSizeTester< IImgCubeRGBA8I >::test();
		ImageSizeTester< IImgCubeRGBA8U >::test();
		ImageSizeTester< IImgBufferRGBA32F >::test();
		ImageSizeTester< IImgBufferRGBA8I >::test();
		ImageSizeTester< IImgBufferRGBA8U >::test();
		ImageSizeTester< IImg1DArrayRGBA32F >::test();
		ImageSizeTester< IImg1DArrayRGBA8I >::test();
		ImageSizeTester< IImg1DArrayRGBA8U >::test();
		ImageSizeTester< IImg2DArrayRGBA32F >::test();
		ImageSizeTester< IImg2DArrayRGBA8I >::test();
		ImageSizeTester< IImg2DArrayRGBA8U >::test();
		ImageSizeTester< IImgCubeArrayRGBA32F >::test();
		ImageSizeTester< IImgCubeArrayRGBA8I >::test();
		ImageSizeTester< IImgCubeArrayRGBA8U >::test();
		ImageSizeTester< IImg2DMSRGBA32F >::test();
		ImageSizeTester< IImg2DMSRGBA8I >::test();
		ImageSizeTester< IImg2DMSRGBA8U >::test();
		ImageSizeTester< IImg2DMSArrayRGBA32F >::test();
		ImageSizeTester< IImg2DMSArrayRGBA8I >::test();
		ImageSizeTester< IImg2DMSArrayRGBA8U >::test();

		ImageSizeTester< UImg1DRGBA32F >::test();
		ImageSizeTester< UImg1DRGBA8I >::test();
		ImageSizeTester< UImg1DRGBA8U >::test();
		ImageSizeTester< UImg2DRGBA32F >::test();
		ImageSizeTester< UImg2DRGBA8I >::test();
		ImageSizeTester< UImg2DRGBA8U >::test();
		ImageSizeTester< UImg3DRGBA32F >::test();
		ImageSizeTester< UImg3DRGBA8I >::test();
		ImageSizeTester< UImg3DRGBA8U >::test();
		ImageSizeTester< UImgRectRGBA32F >::test();
		ImageSizeTester< UImgRectRGBA8I >::test();
		ImageSizeTester< UImgRectRGBA8U >::test();
		ImageSizeTester< UImgCubeRGBA32F >::test();
		ImageSizeTester< UImgCubeRGBA8I >::test();
		ImageSizeTester< UImgCubeRGBA8U >::test();
		ImageSizeTester< UImgBufferRGBA32F >::test();
		ImageSizeTester< UImgBufferRGBA8I >::test();
		ImageSizeTester< UImgBufferRGBA8U >::test();
		ImageSizeTester< UImg1DArrayRGBA32F >::test();
		ImageSizeTester< UImg1DArrayRGBA8I >::test();
		ImageSizeTester< UImg1DArrayRGBA8U >::test();
		ImageSizeTester< UImg2DArrayRGBA32F >::test();
		ImageSizeTester< UImg2DArrayRGBA8I >::test();
		ImageSizeTester< UImg2DArrayRGBA8U >::test();
		ImageSizeTester< UImgCubeArrayRGBA32F >::test();
		ImageSizeTester< UImgCubeArrayRGBA8I >::test();
		ImageSizeTester< UImgCubeArrayRGBA8U >::test();
		ImageSizeTester< UImg2DMSRGBA32F >::test();
		ImageSizeTester< UImg2DMSRGBA8I >::test();
		ImageSizeTester< UImg2DMSRGBA8U >::test();
		ImageSizeTester< UImg2DMSArrayRGBA32F >::test();
		ImageSizeTester< UImg2DMSArrayRGBA8I >::test();
		ImageSizeTester< UImg2DMSArrayRGBA8U >::test();
	}
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSamplesTester
	{
		static void test()
		{
			auto name = "testImageSamples" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSamples( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageSamples()
	{
		ImageSamplesTester< FImg2DMSRGBA32F >::test();
		ImageSamplesTester< FImg2DMSRGBA8I >::test();
		ImageSamplesTester< FImg2DMSRGBA8U >::test();
		ImageSamplesTester< FImg2DMSArrayRGBA32F >::test();
		ImageSamplesTester< FImg2DMSArrayRGBA8I >::test();
		ImageSamplesTester< FImg2DMSArrayRGBA8U >::test();

		ImageSamplesTester< IImg2DMSRGBA32F >::test();
		ImageSamplesTester< IImg2DMSRGBA8I >::test();
		ImageSamplesTester< IImg2DMSRGBA8U >::test();
		ImageSamplesTester< IImg2DMSArrayRGBA32F >::test();
		ImageSamplesTester< IImg2DMSArrayRGBA8I >::test();
		ImageSamplesTester< IImg2DMSArrayRGBA8U >::test();

		ImageSamplesTester< UImg2DMSRGBA32F >::test();
		ImageSamplesTester< UImg2DMSRGBA8I >::test();
		ImageSamplesTester< UImg2DMSRGBA8U >::test();
		ImageSamplesTester< UImg2DMSArrayRGBA32F >::test();
		ImageSamplesTester< UImg2DMSArrayRGBA8I >::test();
		ImageSamplesTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageLoadTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageLoadTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageLoad" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ) ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageLoadTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageLoad" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ), 0_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageLoad()
	{
		ImageLoadTester< FImg1DRGBA32F >::test();
		ImageLoadTester< FImg1DRGBA8I >::test();
		ImageLoadTester< FImg1DRGBA8U >::test();
		ImageLoadTester< FImg2DRGBA32F >::test();
		ImageLoadTester< FImg2DRGBA8I >::test();
		ImageLoadTester< FImg2DRGBA8U >::test();
		ImageLoadTester< FImg3DRGBA32F >::test();
		ImageLoadTester< FImg3DRGBA8I >::test();
		ImageLoadTester< FImg3DRGBA8U >::test();
		ImageLoadTester< FImgRectRGBA32F >::test();
		ImageLoadTester< FImgRectRGBA8I >::test();
		ImageLoadTester< FImgRectRGBA8U >::test();
		ImageLoadTester< FImgCubeRGBA32F >::test();
		ImageLoadTester< FImgCubeRGBA8I >::test();
		ImageLoadTester< FImgCubeRGBA8U >::test();
		ImageLoadTester< FImgBufferRGBA32F >::test();
		ImageLoadTester< FImgBufferRGBA8I >::test();
		ImageLoadTester< FImgBufferRGBA8U >::test();
		ImageLoadTester< FImg1DArrayRGBA32F >::test();
		ImageLoadTester< FImg1DArrayRGBA8I >::test();
		ImageLoadTester< FImg1DArrayRGBA8U >::test();
		ImageLoadTester< FImg2DArrayRGBA32F >::test();
		ImageLoadTester< FImg2DArrayRGBA8I >::test();
		ImageLoadTester< FImg2DArrayRGBA8U >::test();
		ImageLoadTester< FImgCubeArrayRGBA32F >::test();
		ImageLoadTester< FImgCubeArrayRGBA8I >::test();
		ImageLoadTester< FImgCubeArrayRGBA8U >::test();
		ImageLoadTester< FImg2DMSRGBA32F >::test();
		ImageLoadTester< FImg2DMSRGBA8I >::test();
		ImageLoadTester< FImg2DMSRGBA8U >::test();
		ImageLoadTester< FImg2DMSArrayRGBA32F >::test();
		ImageLoadTester< FImg2DMSArrayRGBA8I >::test();
		ImageLoadTester< FImg2DMSArrayRGBA8U >::test();

		ImageLoadTester< IImg1DRGBA32F >::test();
		ImageLoadTester< IImg1DRGBA8I >::test();
		ImageLoadTester< IImg1DRGBA8U >::test();
		ImageLoadTester< IImg2DRGBA32F >::test();
		ImageLoadTester< IImg2DRGBA8I >::test();
		ImageLoadTester< IImg2DRGBA8U >::test();
		ImageLoadTester< IImg3DRGBA32F >::test();
		ImageLoadTester< IImg3DRGBA8I >::test();
		ImageLoadTester< IImg3DRGBA8U >::test();
		ImageLoadTester< IImgRectRGBA32F >::test();
		ImageLoadTester< IImgRectRGBA8I >::test();
		ImageLoadTester< IImgRectRGBA8U >::test();
		ImageLoadTester< IImgCubeRGBA32F >::test();
		ImageLoadTester< IImgCubeRGBA8I >::test();
		ImageLoadTester< IImgCubeRGBA8U >::test();
		ImageLoadTester< IImgBufferRGBA32F >::test();
		ImageLoadTester< IImgBufferRGBA8I >::test();
		ImageLoadTester< IImgBufferRGBA8U >::test();
		ImageLoadTester< IImg1DArrayRGBA32F >::test();
		ImageLoadTester< IImg1DArrayRGBA8I >::test();
		ImageLoadTester< IImg1DArrayRGBA8U >::test();
		ImageLoadTester< IImg2DArrayRGBA32F >::test();
		ImageLoadTester< IImg2DArrayRGBA8I >::test();
		ImageLoadTester< IImg2DArrayRGBA8U >::test();
		ImageLoadTester< IImgCubeArrayRGBA32F >::test();
		ImageLoadTester< IImgCubeArrayRGBA8I >::test();
		ImageLoadTester< IImgCubeArrayRGBA8U >::test();
		ImageLoadTester< IImg2DMSRGBA32F >::test();
		ImageLoadTester< IImg2DMSRGBA8I >::test();
		ImageLoadTester< IImg2DMSRGBA8U >::test();
		ImageLoadTester< IImg2DMSArrayRGBA32F >::test();
		ImageLoadTester< IImg2DMSArrayRGBA8I >::test();
		ImageLoadTester< IImg2DMSArrayRGBA8U >::test();

		ImageLoadTester< UImg1DRGBA32F >::test();
		ImageLoadTester< UImg1DRGBA8I >::test();
		ImageLoadTester< UImg1DRGBA8U >::test();
		ImageLoadTester< UImg2DRGBA32F >::test();
		ImageLoadTester< UImg2DRGBA8I >::test();
		ImageLoadTester< UImg2DRGBA8U >::test();
		ImageLoadTester< UImg3DRGBA32F >::test();
		ImageLoadTester< UImg3DRGBA8I >::test();
		ImageLoadTester< UImg3DRGBA8U >::test();
		ImageLoadTester< UImgRectRGBA32F >::test();
		ImageLoadTester< UImgRectRGBA8I >::test();
		ImageLoadTester< UImgRectRGBA8U >::test();
		ImageLoadTester< UImgCubeRGBA32F >::test();
		ImageLoadTester< UImgCubeRGBA8I >::test();
		ImageLoadTester< UImgCubeRGBA8U >::test();
		ImageLoadTester< UImgBufferRGBA32F >::test();
		ImageLoadTester< UImgBufferRGBA8I >::test();
		ImageLoadTester< UImgBufferRGBA8U >::test();
		ImageLoadTester< UImg1DArrayRGBA32F >::test();
		ImageLoadTester< UImg1DArrayRGBA8I >::test();
		ImageLoadTester< UImg1DArrayRGBA8U >::test();
		ImageLoadTester< UImg2DArrayRGBA32F >::test();
		ImageLoadTester< UImg2DArrayRGBA8I >::test();
		ImageLoadTester< UImg2DArrayRGBA8U >::test();
		ImageLoadTester< UImgCubeArrayRGBA32F >::test();
		ImageLoadTester< UImgCubeArrayRGBA8I >::test();
		ImageLoadTester< UImgCubeArrayRGBA8U >::test();
		ImageLoadTester< UImg2DMSRGBA32F >::test();
		ImageLoadTester< UImg2DMSRGBA8I >::test();
		ImageLoadTester< UImg2DMSRGBA8U >::test();
		ImageLoadTester< UImg2DMSArrayRGBA32F >::test();
		ImageLoadTester< UImg2DMSArrayRGBA8I >::test();
		ImageLoadTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAddTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAddTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAddTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicAdd()
	{
		ImageIAtomicAddTester< FImg1DRGBA32F >::test();
		ImageIAtomicAddTester< FImg1DRGBA8I >::test();
		ImageIAtomicAddTester< FImg1DRGBA8U >::test();
		ImageIAtomicAddTester< FImg2DRGBA32F >::test();
		ImageIAtomicAddTester< FImg2DRGBA8I >::test();
		ImageIAtomicAddTester< FImg2DRGBA8U >::test();
		ImageIAtomicAddTester< FImg3DRGBA32F >::test();
		ImageIAtomicAddTester< FImg3DRGBA8I >::test();
		ImageIAtomicAddTester< FImg3DRGBA8U >::test();
		ImageIAtomicAddTester< FImgRectRGBA32F >::test();
		ImageIAtomicAddTester< FImgRectRGBA8I >::test();
		ImageIAtomicAddTester< FImgRectRGBA8U >::test();
		ImageIAtomicAddTester< FImgCubeRGBA32F >::test();
		ImageIAtomicAddTester< FImgCubeRGBA8I >::test();
		ImageIAtomicAddTester< FImgCubeRGBA8U >::test();
		ImageIAtomicAddTester< FImgBufferRGBA32F >::test();
		ImageIAtomicAddTester< FImgBufferRGBA8I >::test();
		ImageIAtomicAddTester< FImgBufferRGBA8U >::test();
		ImageIAtomicAddTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicAddTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicAddTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicAddTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicAddTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicAddTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicAddTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicAddTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicAddTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicAddTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicAddTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicAddTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicAddTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicAddTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicAddTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicAddTester< IImg1DRGBA32F >::test();
		ImageIAtomicAddTester< IImg1DRGBA8I >::test();
		ImageIAtomicAddTester< IImg1DRGBA8U >::test();
		ImageIAtomicAddTester< IImg2DRGBA32F >::test();
		ImageIAtomicAddTester< IImg2DRGBA8I >::test();
		ImageIAtomicAddTester< IImg2DRGBA8U >::test();
		ImageIAtomicAddTester< IImg3DRGBA32F >::test();
		ImageIAtomicAddTester< IImg3DRGBA8I >::test();
		ImageIAtomicAddTester< IImg3DRGBA8U >::test();
		ImageIAtomicAddTester< IImgRectRGBA32F >::test();
		ImageIAtomicAddTester< IImgRectRGBA8I >::test();
		ImageIAtomicAddTester< IImgRectRGBA8U >::test();
		ImageIAtomicAddTester< IImgCubeRGBA32F >::test();
		ImageIAtomicAddTester< IImgCubeRGBA8I >::test();
		ImageIAtomicAddTester< IImgCubeRGBA8U >::test();
		ImageIAtomicAddTester< IImgBufferRGBA32F >::test();
		ImageIAtomicAddTester< IImgBufferRGBA8I >::test();
		ImageIAtomicAddTester< IImgBufferRGBA8U >::test();
		ImageIAtomicAddTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicAddTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicAddTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicAddTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicAddTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicAddTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicAddTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicAddTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicAddTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicAddTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicAddTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicAddTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicAddTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicAddTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicAddTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicAddTester< UImg1DRGBA32F >::test();
		ImageIAtomicAddTester< UImg1DRGBA8I >::test();
		ImageIAtomicAddTester< UImg1DRGBA8U >::test();
		ImageIAtomicAddTester< UImg2DRGBA32F >::test();
		ImageIAtomicAddTester< UImg2DRGBA8I >::test();
		ImageIAtomicAddTester< UImg2DRGBA8U >::test();
		ImageIAtomicAddTester< UImg3DRGBA32F >::test();
		ImageIAtomicAddTester< UImg3DRGBA8I >::test();
		ImageIAtomicAddTester< UImg3DRGBA8U >::test();
		ImageIAtomicAddTester< UImgRectRGBA32F >::test();
		ImageIAtomicAddTester< UImgRectRGBA8I >::test();
		ImageIAtomicAddTester< UImgRectRGBA8U >::test();
		ImageIAtomicAddTester< UImgCubeRGBA32F >::test();
		ImageIAtomicAddTester< UImgCubeRGBA8I >::test();
		ImageIAtomicAddTester< UImgCubeRGBA8U >::test();
		ImageIAtomicAddTester< UImgBufferRGBA32F >::test();
		ImageIAtomicAddTester< UImgBufferRGBA8I >::test();
		ImageIAtomicAddTester< UImgBufferRGBA8U >::test();
		ImageIAtomicAddTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicAddTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicAddTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicAddTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicAddTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicAddTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicAddTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicAddTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicAddTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicAddTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicAddTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicAddTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicAddTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicAddTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicAddTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAddTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAddTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAddTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicAdd()
	{
		ImageUAtomicAddTester< FImg1DRGBA32F >::test();
		ImageUAtomicAddTester< FImg1DRGBA8I >::test();
		ImageUAtomicAddTester< FImg1DRGBA8U >::test();
		ImageUAtomicAddTester< FImg2DRGBA32F >::test();
		ImageUAtomicAddTester< FImg2DRGBA8I >::test();
		ImageUAtomicAddTester< FImg2DRGBA8U >::test();
		ImageUAtomicAddTester< FImg3DRGBA32F >::test();
		ImageUAtomicAddTester< FImg3DRGBA8I >::test();
		ImageUAtomicAddTester< FImg3DRGBA8U >::test();
		ImageUAtomicAddTester< FImgRectRGBA32F >::test();
		ImageUAtomicAddTester< FImgRectRGBA8I >::test();
		ImageUAtomicAddTester< FImgRectRGBA8U >::test();
		ImageUAtomicAddTester< FImgCubeRGBA32F >::test();
		ImageUAtomicAddTester< FImgCubeRGBA8I >::test();
		ImageUAtomicAddTester< FImgCubeRGBA8U >::test();
		ImageUAtomicAddTester< FImgBufferRGBA32F >::test();
		ImageUAtomicAddTester< FImgBufferRGBA8I >::test();
		ImageUAtomicAddTester< FImgBufferRGBA8U >::test();
		ImageUAtomicAddTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicAddTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicAddTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicAddTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicAddTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicAddTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicAddTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicAddTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicAddTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicAddTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicAddTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicAddTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicAddTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicAddTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicAddTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicAddTester< IImg1DRGBA32F >::test();
		ImageUAtomicAddTester< IImg1DRGBA8I >::test();
		ImageUAtomicAddTester< IImg1DRGBA8U >::test();
		ImageUAtomicAddTester< IImg2DRGBA32F >::test();
		ImageUAtomicAddTester< IImg2DRGBA8I >::test();
		ImageUAtomicAddTester< IImg2DRGBA8U >::test();
		ImageUAtomicAddTester< IImg3DRGBA32F >::test();
		ImageUAtomicAddTester< IImg3DRGBA8I >::test();
		ImageUAtomicAddTester< IImg3DRGBA8U >::test();
		ImageUAtomicAddTester< IImgRectRGBA32F >::test();
		ImageUAtomicAddTester< IImgRectRGBA8I >::test();
		ImageUAtomicAddTester< IImgRectRGBA8U >::test();
		ImageUAtomicAddTester< IImgCubeRGBA32F >::test();
		ImageUAtomicAddTester< IImgCubeRGBA8I >::test();
		ImageUAtomicAddTester< IImgCubeRGBA8U >::test();
		ImageUAtomicAddTester< IImgBufferRGBA32F >::test();
		ImageUAtomicAddTester< IImgBufferRGBA8I >::test();
		ImageUAtomicAddTester< IImgBufferRGBA8U >::test();
		ImageUAtomicAddTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicAddTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicAddTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicAddTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicAddTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicAddTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicAddTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicAddTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicAddTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicAddTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicAddTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicAddTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicAddTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicAddTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicAddTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicAddTester< UImg1DRGBA32F >::test();
		ImageUAtomicAddTester< UImg1DRGBA8I >::test();
		ImageUAtomicAddTester< UImg1DRGBA8U >::test();
		ImageUAtomicAddTester< UImg2DRGBA32F >::test();
		ImageUAtomicAddTester< UImg2DRGBA8I >::test();
		ImageUAtomicAddTester< UImg2DRGBA8U >::test();
		ImageUAtomicAddTester< UImg3DRGBA32F >::test();
		ImageUAtomicAddTester< UImg3DRGBA8I >::test();
		ImageUAtomicAddTester< UImg3DRGBA8U >::test();
		ImageUAtomicAddTester< UImgRectRGBA32F >::test();
		ImageUAtomicAddTester< UImgRectRGBA8I >::test();
		ImageUAtomicAddTester< UImgRectRGBA8U >::test();
		ImageUAtomicAddTester< UImgCubeRGBA32F >::test();
		ImageUAtomicAddTester< UImgCubeRGBA8I >::test();
		ImageUAtomicAddTester< UImgCubeRGBA8U >::test();
		ImageUAtomicAddTester< UImgBufferRGBA32F >::test();
		ImageUAtomicAddTester< UImgBufferRGBA8I >::test();
		ImageUAtomicAddTester< UImgBufferRGBA8U >::test();
		ImageUAtomicAddTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicAddTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicAddTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicAddTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicAddTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicAddTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicAddTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicAddTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicAddTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicAddTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicAddTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicAddTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicAddTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicAddTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicAddTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMinTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMinTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMinTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicMin()
	{
		ImageIAtomicMinTester< FImg1DRGBA32F >::test();
		ImageIAtomicMinTester< FImg1DRGBA8I >::test();
		ImageIAtomicMinTester< FImg1DRGBA8U >::test();
		ImageIAtomicMinTester< FImg2DRGBA32F >::test();
		ImageIAtomicMinTester< FImg2DRGBA8I >::test();
		ImageIAtomicMinTester< FImg2DRGBA8U >::test();
		ImageIAtomicMinTester< FImg3DRGBA32F >::test();
		ImageIAtomicMinTester< FImg3DRGBA8I >::test();
		ImageIAtomicMinTester< FImg3DRGBA8U >::test();
		ImageIAtomicMinTester< FImgRectRGBA32F >::test();
		ImageIAtomicMinTester< FImgRectRGBA8I >::test();
		ImageIAtomicMinTester< FImgRectRGBA8U >::test();
		ImageIAtomicMinTester< FImgCubeRGBA32F >::test();
		ImageIAtomicMinTester< FImgCubeRGBA8I >::test();
		ImageIAtomicMinTester< FImgCubeRGBA8U >::test();
		ImageIAtomicMinTester< FImgBufferRGBA32F >::test();
		ImageIAtomicMinTester< FImgBufferRGBA8I >::test();
		ImageIAtomicMinTester< FImgBufferRGBA8U >::test();
		ImageIAtomicMinTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicMinTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicMinTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicMinTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicMinTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicMinTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicMinTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicMinTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicMinTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicMinTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicMinTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicMinTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicMinTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicMinTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicMinTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicMinTester< IImg1DRGBA32F >::test();
		ImageIAtomicMinTester< IImg1DRGBA8I >::test();
		ImageIAtomicMinTester< IImg1DRGBA8U >::test();
		ImageIAtomicMinTester< IImg2DRGBA32F >::test();
		ImageIAtomicMinTester< IImg2DRGBA8I >::test();
		ImageIAtomicMinTester< IImg2DRGBA8U >::test();
		ImageIAtomicMinTester< IImg3DRGBA32F >::test();
		ImageIAtomicMinTester< IImg3DRGBA8I >::test();
		ImageIAtomicMinTester< IImg3DRGBA8U >::test();
		ImageIAtomicMinTester< IImgRectRGBA32F >::test();
		ImageIAtomicMinTester< IImgRectRGBA8I >::test();
		ImageIAtomicMinTester< IImgRectRGBA8U >::test();
		ImageIAtomicMinTester< IImgCubeRGBA32F >::test();
		ImageIAtomicMinTester< IImgCubeRGBA8I >::test();
		ImageIAtomicMinTester< IImgCubeRGBA8U >::test();
		ImageIAtomicMinTester< IImgBufferRGBA32F >::test();
		ImageIAtomicMinTester< IImgBufferRGBA8I >::test();
		ImageIAtomicMinTester< IImgBufferRGBA8U >::test();
		ImageIAtomicMinTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicMinTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicMinTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicMinTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicMinTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicMinTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicMinTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicMinTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicMinTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicMinTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicMinTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicMinTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicMinTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicMinTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicMinTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicMinTester< UImg1DRGBA32F >::test();
		ImageIAtomicMinTester< UImg1DRGBA8I >::test();
		ImageIAtomicMinTester< UImg1DRGBA8U >::test();
		ImageIAtomicMinTester< UImg2DRGBA32F >::test();
		ImageIAtomicMinTester< UImg2DRGBA8I >::test();
		ImageIAtomicMinTester< UImg2DRGBA8U >::test();
		ImageIAtomicMinTester< UImg3DRGBA32F >::test();
		ImageIAtomicMinTester< UImg3DRGBA8I >::test();
		ImageIAtomicMinTester< UImg3DRGBA8U >::test();
		ImageIAtomicMinTester< UImgRectRGBA32F >::test();
		ImageIAtomicMinTester< UImgRectRGBA8I >::test();
		ImageIAtomicMinTester< UImgRectRGBA8U >::test();
		ImageIAtomicMinTester< UImgCubeRGBA32F >::test();
		ImageIAtomicMinTester< UImgCubeRGBA8I >::test();
		ImageIAtomicMinTester< UImgCubeRGBA8U >::test();
		ImageIAtomicMinTester< UImgBufferRGBA32F >::test();
		ImageIAtomicMinTester< UImgBufferRGBA8I >::test();
		ImageIAtomicMinTester< UImgBufferRGBA8U >::test();
		ImageIAtomicMinTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicMinTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicMinTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicMinTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicMinTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicMinTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicMinTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicMinTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicMinTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicMinTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicMinTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicMinTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicMinTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicMinTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicMinTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMinTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMinTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMinTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicMin()
	{
		ImageUAtomicMinTester< FImg1DRGBA32F >::test();
		ImageUAtomicMinTester< FImg1DRGBA8I >::test();
		ImageUAtomicMinTester< FImg1DRGBA8U >::test();
		ImageUAtomicMinTester< FImg2DRGBA32F >::test();
		ImageUAtomicMinTester< FImg2DRGBA8I >::test();
		ImageUAtomicMinTester< FImg2DRGBA8U >::test();
		ImageUAtomicMinTester< FImg3DRGBA32F >::test();
		ImageUAtomicMinTester< FImg3DRGBA8I >::test();
		ImageUAtomicMinTester< FImg3DRGBA8U >::test();
		ImageUAtomicMinTester< FImgRectRGBA32F >::test();
		ImageUAtomicMinTester< FImgRectRGBA8I >::test();
		ImageUAtomicMinTester< FImgRectRGBA8U >::test();
		ImageUAtomicMinTester< FImgCubeRGBA32F >::test();
		ImageUAtomicMinTester< FImgCubeRGBA8I >::test();
		ImageUAtomicMinTester< FImgCubeRGBA8U >::test();
		ImageUAtomicMinTester< FImgBufferRGBA32F >::test();
		ImageUAtomicMinTester< FImgBufferRGBA8I >::test();
		ImageUAtomicMinTester< FImgBufferRGBA8U >::test();
		ImageUAtomicMinTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicMinTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicMinTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicMinTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicMinTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicMinTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicMinTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicMinTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicMinTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicMinTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicMinTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicMinTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicMinTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicMinTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicMinTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicMinTester< IImg1DRGBA32F >::test();
		ImageUAtomicMinTester< IImg1DRGBA8I >::test();
		ImageUAtomicMinTester< IImg1DRGBA8U >::test();
		ImageUAtomicMinTester< IImg2DRGBA32F >::test();
		ImageUAtomicMinTester< IImg2DRGBA8I >::test();
		ImageUAtomicMinTester< IImg2DRGBA8U >::test();
		ImageUAtomicMinTester< IImg3DRGBA32F >::test();
		ImageUAtomicMinTester< IImg3DRGBA8I >::test();
		ImageUAtomicMinTester< IImg3DRGBA8U >::test();
		ImageUAtomicMinTester< IImgRectRGBA32F >::test();
		ImageUAtomicMinTester< IImgRectRGBA8I >::test();
		ImageUAtomicMinTester< IImgRectRGBA8U >::test();
		ImageUAtomicMinTester< IImgCubeRGBA32F >::test();
		ImageUAtomicMinTester< IImgCubeRGBA8I >::test();
		ImageUAtomicMinTester< IImgCubeRGBA8U >::test();
		ImageUAtomicMinTester< IImgBufferRGBA32F >::test();
		ImageUAtomicMinTester< IImgBufferRGBA8I >::test();
		ImageUAtomicMinTester< IImgBufferRGBA8U >::test();
		ImageUAtomicMinTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicMinTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicMinTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicMinTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicMinTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicMinTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicMinTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicMinTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicMinTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicMinTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicMinTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicMinTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicMinTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicMinTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicMinTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicMinTester< UImg1DRGBA32F >::test();
		ImageUAtomicMinTester< UImg1DRGBA8I >::test();
		ImageUAtomicMinTester< UImg1DRGBA8U >::test();
		ImageUAtomicMinTester< UImg2DRGBA32F >::test();
		ImageUAtomicMinTester< UImg2DRGBA8I >::test();
		ImageUAtomicMinTester< UImg2DRGBA8U >::test();
		ImageUAtomicMinTester< UImg3DRGBA32F >::test();
		ImageUAtomicMinTester< UImg3DRGBA8I >::test();
		ImageUAtomicMinTester< UImg3DRGBA8U >::test();
		ImageUAtomicMinTester< UImgRectRGBA32F >::test();
		ImageUAtomicMinTester< UImgRectRGBA8I >::test();
		ImageUAtomicMinTester< UImgRectRGBA8U >::test();
		ImageUAtomicMinTester< UImgCubeRGBA32F >::test();
		ImageUAtomicMinTester< UImgCubeRGBA8I >::test();
		ImageUAtomicMinTester< UImgCubeRGBA8U >::test();
		ImageUAtomicMinTester< UImgBufferRGBA32F >::test();
		ImageUAtomicMinTester< UImgBufferRGBA8I >::test();
		ImageUAtomicMinTester< UImgBufferRGBA8U >::test();
		ImageUAtomicMinTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicMinTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicMinTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicMinTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicMinTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicMinTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicMinTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicMinTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicMinTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicMinTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicMinTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicMinTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicMinTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicMinTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicMinTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMaxTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMaxTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMaxTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicMax()
	{
		ImageIAtomicMaxTester< FImg1DRGBA32F >::test();
		ImageIAtomicMaxTester< FImg1DRGBA8I >::test();
		ImageIAtomicMaxTester< FImg1DRGBA8U >::test();
		ImageIAtomicMaxTester< FImg2DRGBA32F >::test();
		ImageIAtomicMaxTester< FImg2DRGBA8I >::test();
		ImageIAtomicMaxTester< FImg2DRGBA8U >::test();
		ImageIAtomicMaxTester< FImg3DRGBA32F >::test();
		ImageIAtomicMaxTester< FImg3DRGBA8I >::test();
		ImageIAtomicMaxTester< FImg3DRGBA8U >::test();
		ImageIAtomicMaxTester< FImgRectRGBA32F >::test();
		ImageIAtomicMaxTester< FImgRectRGBA8I >::test();
		ImageIAtomicMaxTester< FImgRectRGBA8U >::test();
		ImageIAtomicMaxTester< FImgCubeRGBA32F >::test();
		ImageIAtomicMaxTester< FImgCubeRGBA8I >::test();
		ImageIAtomicMaxTester< FImgCubeRGBA8U >::test();
		ImageIAtomicMaxTester< FImgBufferRGBA32F >::test();
		ImageIAtomicMaxTester< FImgBufferRGBA8I >::test();
		ImageIAtomicMaxTester< FImgBufferRGBA8U >::test();
		ImageIAtomicMaxTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicMaxTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicMaxTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicMaxTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicMaxTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicMaxTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicMaxTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicMaxTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicMaxTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicMaxTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicMaxTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicMaxTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicMaxTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicMaxTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicMaxTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicMaxTester< IImg1DRGBA32F >::test();
		ImageIAtomicMaxTester< IImg1DRGBA8I >::test();
		ImageIAtomicMaxTester< IImg1DRGBA8U >::test();
		ImageIAtomicMaxTester< IImg2DRGBA32F >::test();
		ImageIAtomicMaxTester< IImg2DRGBA8I >::test();
		ImageIAtomicMaxTester< IImg2DRGBA8U >::test();
		ImageIAtomicMaxTester< IImg3DRGBA32F >::test();
		ImageIAtomicMaxTester< IImg3DRGBA8I >::test();
		ImageIAtomicMaxTester< IImg3DRGBA8U >::test();
		ImageIAtomicMaxTester< IImgRectRGBA32F >::test();
		ImageIAtomicMaxTester< IImgRectRGBA8I >::test();
		ImageIAtomicMaxTester< IImgRectRGBA8U >::test();
		ImageIAtomicMaxTester< IImgCubeRGBA32F >::test();
		ImageIAtomicMaxTester< IImgCubeRGBA8I >::test();
		ImageIAtomicMaxTester< IImgCubeRGBA8U >::test();
		ImageIAtomicMaxTester< IImgBufferRGBA32F >::test();
		ImageIAtomicMaxTester< IImgBufferRGBA8I >::test();
		ImageIAtomicMaxTester< IImgBufferRGBA8U >::test();
		ImageIAtomicMaxTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicMaxTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicMaxTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicMaxTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicMaxTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicMaxTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicMaxTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicMaxTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicMaxTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicMaxTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicMaxTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicMaxTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicMaxTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicMaxTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicMaxTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicMaxTester< UImg1DRGBA32F >::test();
		ImageIAtomicMaxTester< UImg1DRGBA8I >::test();
		ImageIAtomicMaxTester< UImg1DRGBA8U >::test();
		ImageIAtomicMaxTester< UImg2DRGBA32F >::test();
		ImageIAtomicMaxTester< UImg2DRGBA8I >::test();
		ImageIAtomicMaxTester< UImg2DRGBA8U >::test();
		ImageIAtomicMaxTester< UImg3DRGBA32F >::test();
		ImageIAtomicMaxTester< UImg3DRGBA8I >::test();
		ImageIAtomicMaxTester< UImg3DRGBA8U >::test();
		ImageIAtomicMaxTester< UImgRectRGBA32F >::test();
		ImageIAtomicMaxTester< UImgRectRGBA8I >::test();
		ImageIAtomicMaxTester< UImgRectRGBA8U >::test();
		ImageIAtomicMaxTester< UImgCubeRGBA32F >::test();
		ImageIAtomicMaxTester< UImgCubeRGBA8I >::test();
		ImageIAtomicMaxTester< UImgCubeRGBA8U >::test();
		ImageIAtomicMaxTester< UImgBufferRGBA32F >::test();
		ImageIAtomicMaxTester< UImgBufferRGBA8I >::test();
		ImageIAtomicMaxTester< UImgBufferRGBA8U >::test();
		ImageIAtomicMaxTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicMaxTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicMaxTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicMaxTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicMaxTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicMaxTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicMaxTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicMaxTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicMaxTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicMaxTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicMaxTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicMaxTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicMaxTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicMaxTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicMaxTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMaxTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMaxTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMaxTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicMax()
	{
		ImageUAtomicMaxTester< FImg1DRGBA32F >::test();
		ImageUAtomicMaxTester< FImg1DRGBA8I >::test();
		ImageUAtomicMaxTester< FImg1DRGBA8U >::test();
		ImageUAtomicMaxTester< FImg2DRGBA32F >::test();
		ImageUAtomicMaxTester< FImg2DRGBA8I >::test();
		ImageUAtomicMaxTester< FImg2DRGBA8U >::test();
		ImageUAtomicMaxTester< FImg3DRGBA32F >::test();
		ImageUAtomicMaxTester< FImg3DRGBA8I >::test();
		ImageUAtomicMaxTester< FImg3DRGBA8U >::test();
		ImageUAtomicMaxTester< FImgRectRGBA32F >::test();
		ImageUAtomicMaxTester< FImgRectRGBA8I >::test();
		ImageUAtomicMaxTester< FImgRectRGBA8U >::test();
		ImageUAtomicMaxTester< FImgCubeRGBA32F >::test();
		ImageUAtomicMaxTester< FImgCubeRGBA8I >::test();
		ImageUAtomicMaxTester< FImgCubeRGBA8U >::test();
		ImageUAtomicMaxTester< FImgBufferRGBA32F >::test();
		ImageUAtomicMaxTester< FImgBufferRGBA8I >::test();
		ImageUAtomicMaxTester< FImgBufferRGBA8U >::test();
		ImageUAtomicMaxTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicMaxTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicMaxTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicMaxTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicMaxTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicMaxTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicMaxTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicMaxTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicMaxTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicMaxTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicMaxTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicMaxTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicMaxTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicMaxTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicMaxTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicMaxTester< IImg1DRGBA32F >::test();
		ImageUAtomicMaxTester< IImg1DRGBA8I >::test();
		ImageUAtomicMaxTester< IImg1DRGBA8U >::test();
		ImageUAtomicMaxTester< IImg2DRGBA32F >::test();
		ImageUAtomicMaxTester< IImg2DRGBA8I >::test();
		ImageUAtomicMaxTester< IImg2DRGBA8U >::test();
		ImageUAtomicMaxTester< IImg3DRGBA32F >::test();
		ImageUAtomicMaxTester< IImg3DRGBA8I >::test();
		ImageUAtomicMaxTester< IImg3DRGBA8U >::test();
		ImageUAtomicMaxTester< IImgRectRGBA32F >::test();
		ImageUAtomicMaxTester< IImgRectRGBA8I >::test();
		ImageUAtomicMaxTester< IImgRectRGBA8U >::test();
		ImageUAtomicMaxTester< IImgCubeRGBA32F >::test();
		ImageUAtomicMaxTester< IImgCubeRGBA8I >::test();
		ImageUAtomicMaxTester< IImgCubeRGBA8U >::test();
		ImageUAtomicMaxTester< IImgBufferRGBA32F >::test();
		ImageUAtomicMaxTester< IImgBufferRGBA8I >::test();
		ImageUAtomicMaxTester< IImgBufferRGBA8U >::test();
		ImageUAtomicMaxTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicMaxTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicMaxTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicMaxTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicMaxTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicMaxTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicMaxTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicMaxTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicMaxTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicMaxTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicMaxTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicMaxTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicMaxTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicMaxTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicMaxTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicMaxTester< UImg1DRGBA32F >::test();
		ImageUAtomicMaxTester< UImg1DRGBA8I >::test();
		ImageUAtomicMaxTester< UImg1DRGBA8U >::test();
		ImageUAtomicMaxTester< UImg2DRGBA32F >::test();
		ImageUAtomicMaxTester< UImg2DRGBA8I >::test();
		ImageUAtomicMaxTester< UImg2DRGBA8U >::test();
		ImageUAtomicMaxTester< UImg3DRGBA32F >::test();
		ImageUAtomicMaxTester< UImg3DRGBA8I >::test();
		ImageUAtomicMaxTester< UImg3DRGBA8U >::test();
		ImageUAtomicMaxTester< UImgRectRGBA32F >::test();
		ImageUAtomicMaxTester< UImgRectRGBA8I >::test();
		ImageUAtomicMaxTester< UImgRectRGBA8U >::test();
		ImageUAtomicMaxTester< UImgCubeRGBA32F >::test();
		ImageUAtomicMaxTester< UImgCubeRGBA8I >::test();
		ImageUAtomicMaxTester< UImgCubeRGBA8U >::test();
		ImageUAtomicMaxTester< UImgBufferRGBA32F >::test();
		ImageUAtomicMaxTester< UImgBufferRGBA8I >::test();
		ImageUAtomicMaxTester< UImgBufferRGBA8U >::test();
		ImageUAtomicMaxTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicMaxTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicMaxTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicMaxTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicMaxTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicMaxTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicMaxTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicMaxTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicMaxTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicMaxTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicMaxTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicMaxTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicMaxTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicMaxTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicMaxTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAndTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAndTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAndTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicAnd()
	{
		ImageIAtomicAndTester< FImg1DRGBA32F >::test();
		ImageIAtomicAndTester< FImg1DRGBA8I >::test();
		ImageIAtomicAndTester< FImg1DRGBA8U >::test();
		ImageIAtomicAndTester< FImg2DRGBA32F >::test();
		ImageIAtomicAndTester< FImg2DRGBA8I >::test();
		ImageIAtomicAndTester< FImg2DRGBA8U >::test();
		ImageIAtomicAndTester< FImg3DRGBA32F >::test();
		ImageIAtomicAndTester< FImg3DRGBA8I >::test();
		ImageIAtomicAndTester< FImg3DRGBA8U >::test();
		ImageIAtomicAndTester< FImgRectRGBA32F >::test();
		ImageIAtomicAndTester< FImgRectRGBA8I >::test();
		ImageIAtomicAndTester< FImgRectRGBA8U >::test();
		ImageIAtomicAndTester< FImgCubeRGBA32F >::test();
		ImageIAtomicAndTester< FImgCubeRGBA8I >::test();
		ImageIAtomicAndTester< FImgCubeRGBA8U >::test();
		ImageIAtomicAndTester< FImgBufferRGBA32F >::test();
		ImageIAtomicAndTester< FImgBufferRGBA8I >::test();
		ImageIAtomicAndTester< FImgBufferRGBA8U >::test();
		ImageIAtomicAndTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicAndTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicAndTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicAndTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicAndTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicAndTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicAndTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicAndTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicAndTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicAndTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicAndTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicAndTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicAndTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicAndTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicAndTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicAndTester< IImg1DRGBA32F >::test();
		ImageIAtomicAndTester< IImg1DRGBA8I >::test();
		ImageIAtomicAndTester< IImg1DRGBA8U >::test();
		ImageIAtomicAndTester< IImg2DRGBA32F >::test();
		ImageIAtomicAndTester< IImg2DRGBA8I >::test();
		ImageIAtomicAndTester< IImg2DRGBA8U >::test();
		ImageIAtomicAndTester< IImg3DRGBA32F >::test();
		ImageIAtomicAndTester< IImg3DRGBA8I >::test();
		ImageIAtomicAndTester< IImg3DRGBA8U >::test();
		ImageIAtomicAndTester< IImgRectRGBA32F >::test();
		ImageIAtomicAndTester< IImgRectRGBA8I >::test();
		ImageIAtomicAndTester< IImgRectRGBA8U >::test();
		ImageIAtomicAndTester< IImgCubeRGBA32F >::test();
		ImageIAtomicAndTester< IImgCubeRGBA8I >::test();
		ImageIAtomicAndTester< IImgCubeRGBA8U >::test();
		ImageIAtomicAndTester< IImgBufferRGBA32F >::test();
		ImageIAtomicAndTester< IImgBufferRGBA8I >::test();
		ImageIAtomicAndTester< IImgBufferRGBA8U >::test();
		ImageIAtomicAndTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicAndTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicAndTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicAndTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicAndTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicAndTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicAndTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicAndTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicAndTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicAndTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicAndTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicAndTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicAndTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicAndTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicAndTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicAndTester< UImg1DRGBA32F >::test();
		ImageIAtomicAndTester< UImg1DRGBA8I >::test();
		ImageIAtomicAndTester< UImg1DRGBA8U >::test();
		ImageIAtomicAndTester< UImg2DRGBA32F >::test();
		ImageIAtomicAndTester< UImg2DRGBA8I >::test();
		ImageIAtomicAndTester< UImg2DRGBA8U >::test();
		ImageIAtomicAndTester< UImg3DRGBA32F >::test();
		ImageIAtomicAndTester< UImg3DRGBA8I >::test();
		ImageIAtomicAndTester< UImg3DRGBA8U >::test();
		ImageIAtomicAndTester< UImgRectRGBA32F >::test();
		ImageIAtomicAndTester< UImgRectRGBA8I >::test();
		ImageIAtomicAndTester< UImgRectRGBA8U >::test();
		ImageIAtomicAndTester< UImgCubeRGBA32F >::test();
		ImageIAtomicAndTester< UImgCubeRGBA8I >::test();
		ImageIAtomicAndTester< UImgCubeRGBA8U >::test();
		ImageIAtomicAndTester< UImgBufferRGBA32F >::test();
		ImageIAtomicAndTester< UImgBufferRGBA8I >::test();
		ImageIAtomicAndTester< UImgBufferRGBA8U >::test();
		ImageIAtomicAndTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicAndTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicAndTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicAndTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicAndTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicAndTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicAndTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicAndTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicAndTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicAndTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicAndTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicAndTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicAndTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicAndTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicAndTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAndTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAndTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAndTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicAnd()
	{
		ImageUAtomicAndTester< FImg1DRGBA32F >::test();
		ImageUAtomicAndTester< FImg1DRGBA8I >::test();
		ImageUAtomicAndTester< FImg1DRGBA8U >::test();
		ImageUAtomicAndTester< FImg2DRGBA32F >::test();
		ImageUAtomicAndTester< FImg2DRGBA8I >::test();
		ImageUAtomicAndTester< FImg2DRGBA8U >::test();
		ImageUAtomicAndTester< FImg3DRGBA32F >::test();
		ImageUAtomicAndTester< FImg3DRGBA8I >::test();
		ImageUAtomicAndTester< FImg3DRGBA8U >::test();
		ImageUAtomicAndTester< FImgRectRGBA32F >::test();
		ImageUAtomicAndTester< FImgRectRGBA8I >::test();
		ImageUAtomicAndTester< FImgRectRGBA8U >::test();
		ImageUAtomicAndTester< FImgCubeRGBA32F >::test();
		ImageUAtomicAndTester< FImgCubeRGBA8I >::test();
		ImageUAtomicAndTester< FImgCubeRGBA8U >::test();
		ImageUAtomicAndTester< FImgBufferRGBA32F >::test();
		ImageUAtomicAndTester< FImgBufferRGBA8I >::test();
		ImageUAtomicAndTester< FImgBufferRGBA8U >::test();
		ImageUAtomicAndTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicAndTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicAndTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicAndTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicAndTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicAndTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicAndTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicAndTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicAndTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicAndTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicAndTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicAndTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicAndTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicAndTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicAndTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicAndTester< IImg1DRGBA32F >::test();
		ImageUAtomicAndTester< IImg1DRGBA8I >::test();
		ImageUAtomicAndTester< IImg1DRGBA8U >::test();
		ImageUAtomicAndTester< IImg2DRGBA32F >::test();
		ImageUAtomicAndTester< IImg2DRGBA8I >::test();
		ImageUAtomicAndTester< IImg2DRGBA8U >::test();
		ImageUAtomicAndTester< IImg3DRGBA32F >::test();
		ImageUAtomicAndTester< IImg3DRGBA8I >::test();
		ImageUAtomicAndTester< IImg3DRGBA8U >::test();
		ImageUAtomicAndTester< IImgRectRGBA32F >::test();
		ImageUAtomicAndTester< IImgRectRGBA8I >::test();
		ImageUAtomicAndTester< IImgRectRGBA8U >::test();
		ImageUAtomicAndTester< IImgCubeRGBA32F >::test();
		ImageUAtomicAndTester< IImgCubeRGBA8I >::test();
		ImageUAtomicAndTester< IImgCubeRGBA8U >::test();
		ImageUAtomicAndTester< IImgBufferRGBA32F >::test();
		ImageUAtomicAndTester< IImgBufferRGBA8I >::test();
		ImageUAtomicAndTester< IImgBufferRGBA8U >::test();
		ImageUAtomicAndTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicAndTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicAndTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicAndTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicAndTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicAndTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicAndTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicAndTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicAndTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicAndTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicAndTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicAndTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicAndTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicAndTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicAndTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicAndTester< UImg1DRGBA32F >::test();
		ImageUAtomicAndTester< UImg1DRGBA8I >::test();
		ImageUAtomicAndTester< UImg1DRGBA8U >::test();
		ImageUAtomicAndTester< UImg2DRGBA32F >::test();
		ImageUAtomicAndTester< UImg2DRGBA8I >::test();
		ImageUAtomicAndTester< UImg2DRGBA8U >::test();
		ImageUAtomicAndTester< UImg3DRGBA32F >::test();
		ImageUAtomicAndTester< UImg3DRGBA8I >::test();
		ImageUAtomicAndTester< UImg3DRGBA8U >::test();
		ImageUAtomicAndTester< UImgRectRGBA32F >::test();
		ImageUAtomicAndTester< UImgRectRGBA8I >::test();
		ImageUAtomicAndTester< UImgRectRGBA8U >::test();
		ImageUAtomicAndTester< UImgCubeRGBA32F >::test();
		ImageUAtomicAndTester< UImgCubeRGBA8I >::test();
		ImageUAtomicAndTester< UImgCubeRGBA8U >::test();
		ImageUAtomicAndTester< UImgBufferRGBA32F >::test();
		ImageUAtomicAndTester< UImgBufferRGBA8I >::test();
		ImageUAtomicAndTester< UImgBufferRGBA8U >::test();
		ImageUAtomicAndTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicAndTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicAndTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicAndTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicAndTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicAndTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicAndTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicAndTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicAndTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicAndTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicAndTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicAndTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicAndTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicAndTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicAndTester< UImg2DMSArrayRGBA8U >::test();
	}
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicOrTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicOrTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicOrTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicOr()
	{
		ImageIAtomicOrTester< FImg1DRGBA32F >::test();
		ImageIAtomicOrTester< FImg1DRGBA8I >::test();
		ImageIAtomicOrTester< FImg1DRGBA8U >::test();
		ImageIAtomicOrTester< FImg2DRGBA32F >::test();
		ImageIAtomicOrTester< FImg2DRGBA8I >::test();
		ImageIAtomicOrTester< FImg2DRGBA8U >::test();
		ImageIAtomicOrTester< FImg3DRGBA32F >::test();
		ImageIAtomicOrTester< FImg3DRGBA8I >::test();
		ImageIAtomicOrTester< FImg3DRGBA8U >::test();
		ImageIAtomicOrTester< FImgRectRGBA32F >::test();
		ImageIAtomicOrTester< FImgRectRGBA8I >::test();
		ImageIAtomicOrTester< FImgRectRGBA8U >::test();
		ImageIAtomicOrTester< FImgCubeRGBA32F >::test();
		ImageIAtomicOrTester< FImgCubeRGBA8I >::test();
		ImageIAtomicOrTester< FImgCubeRGBA8U >::test();
		ImageIAtomicOrTester< FImgBufferRGBA32F >::test();
		ImageIAtomicOrTester< FImgBufferRGBA8I >::test();
		ImageIAtomicOrTester< FImgBufferRGBA8U >::test();
		ImageIAtomicOrTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicOrTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicOrTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicOrTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicOrTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicOrTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicOrTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicOrTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicOrTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicOrTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicOrTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicOrTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicOrTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicOrTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicOrTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicOrTester< IImg1DRGBA32F >::test();
		ImageIAtomicOrTester< IImg1DRGBA8I >::test();
		ImageIAtomicOrTester< IImg1DRGBA8U >::test();
		ImageIAtomicOrTester< IImg2DRGBA32F >::test();
		ImageIAtomicOrTester< IImg2DRGBA8I >::test();
		ImageIAtomicOrTester< IImg2DRGBA8U >::test();
		ImageIAtomicOrTester< IImg3DRGBA32F >::test();
		ImageIAtomicOrTester< IImg3DRGBA8I >::test();
		ImageIAtomicOrTester< IImg3DRGBA8U >::test();
		ImageIAtomicOrTester< IImgRectRGBA32F >::test();
		ImageIAtomicOrTester< IImgRectRGBA8I >::test();
		ImageIAtomicOrTester< IImgRectRGBA8U >::test();
		ImageIAtomicOrTester< IImgCubeRGBA32F >::test();
		ImageIAtomicOrTester< IImgCubeRGBA8I >::test();
		ImageIAtomicOrTester< IImgCubeRGBA8U >::test();
		ImageIAtomicOrTester< IImgBufferRGBA32F >::test();
		ImageIAtomicOrTester< IImgBufferRGBA8I >::test();
		ImageIAtomicOrTester< IImgBufferRGBA8U >::test();
		ImageIAtomicOrTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicOrTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicOrTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicOrTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicOrTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicOrTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicOrTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicOrTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicOrTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicOrTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicOrTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicOrTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicOrTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicOrTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicOrTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicOrTester< UImg1DRGBA32F >::test();
		ImageIAtomicOrTester< UImg1DRGBA8I >::test();
		ImageIAtomicOrTester< UImg1DRGBA8U >::test();
		ImageIAtomicOrTester< UImg2DRGBA32F >::test();
		ImageIAtomicOrTester< UImg2DRGBA8I >::test();
		ImageIAtomicOrTester< UImg2DRGBA8U >::test();
		ImageIAtomicOrTester< UImg3DRGBA32F >::test();
		ImageIAtomicOrTester< UImg3DRGBA8I >::test();
		ImageIAtomicOrTester< UImg3DRGBA8U >::test();
		ImageIAtomicOrTester< UImgRectRGBA32F >::test();
		ImageIAtomicOrTester< UImgRectRGBA8I >::test();
		ImageIAtomicOrTester< UImgRectRGBA8U >::test();
		ImageIAtomicOrTester< UImgCubeRGBA32F >::test();
		ImageIAtomicOrTester< UImgCubeRGBA8I >::test();
		ImageIAtomicOrTester< UImgCubeRGBA8U >::test();
		ImageIAtomicOrTester< UImgBufferRGBA32F >::test();
		ImageIAtomicOrTester< UImgBufferRGBA8I >::test();
		ImageIAtomicOrTester< UImgBufferRGBA8U >::test();
		ImageIAtomicOrTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicOrTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicOrTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicOrTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicOrTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicOrTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicOrTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicOrTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicOrTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicOrTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicOrTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicOrTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicOrTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicOrTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicOrTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicOrTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicOrTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicOrTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicOr()
	{
		ImageUAtomicOrTester< FImg1DRGBA32F >::test();
		ImageUAtomicOrTester< FImg1DRGBA8I >::test();
		ImageUAtomicOrTester< FImg1DRGBA8U >::test();
		ImageUAtomicOrTester< FImg2DRGBA32F >::test();
		ImageUAtomicOrTester< FImg2DRGBA8I >::test();
		ImageUAtomicOrTester< FImg2DRGBA8U >::test();
		ImageUAtomicOrTester< FImg3DRGBA32F >::test();
		ImageUAtomicOrTester< FImg3DRGBA8I >::test();
		ImageUAtomicOrTester< FImg3DRGBA8U >::test();
		ImageUAtomicOrTester< FImgRectRGBA32F >::test();
		ImageUAtomicOrTester< FImgRectRGBA8I >::test();
		ImageUAtomicOrTester< FImgRectRGBA8U >::test();
		ImageUAtomicOrTester< FImgCubeRGBA32F >::test();
		ImageUAtomicOrTester< FImgCubeRGBA8I >::test();
		ImageUAtomicOrTester< FImgCubeRGBA8U >::test();
		ImageUAtomicOrTester< FImgBufferRGBA32F >::test();
		ImageUAtomicOrTester< FImgBufferRGBA8I >::test();
		ImageUAtomicOrTester< FImgBufferRGBA8U >::test();
		ImageUAtomicOrTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicOrTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicOrTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicOrTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicOrTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicOrTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicOrTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicOrTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicOrTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicOrTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicOrTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicOrTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicOrTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicOrTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicOrTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicOrTester< IImg1DRGBA32F >::test();
		ImageUAtomicOrTester< IImg1DRGBA8I >::test();
		ImageUAtomicOrTester< IImg1DRGBA8U >::test();
		ImageUAtomicOrTester< IImg2DRGBA32F >::test();
		ImageUAtomicOrTester< IImg2DRGBA8I >::test();
		ImageUAtomicOrTester< IImg2DRGBA8U >::test();
		ImageUAtomicOrTester< IImg3DRGBA32F >::test();
		ImageUAtomicOrTester< IImg3DRGBA8I >::test();
		ImageUAtomicOrTester< IImg3DRGBA8U >::test();
		ImageUAtomicOrTester< IImgRectRGBA32F >::test();
		ImageUAtomicOrTester< IImgRectRGBA8I >::test();
		ImageUAtomicOrTester< IImgRectRGBA8U >::test();
		ImageUAtomicOrTester< IImgCubeRGBA32F >::test();
		ImageUAtomicOrTester< IImgCubeRGBA8I >::test();
		ImageUAtomicOrTester< IImgCubeRGBA8U >::test();
		ImageUAtomicOrTester< IImgBufferRGBA32F >::test();
		ImageUAtomicOrTester< IImgBufferRGBA8I >::test();
		ImageUAtomicOrTester< IImgBufferRGBA8U >::test();
		ImageUAtomicOrTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicOrTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicOrTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicOrTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicOrTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicOrTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicOrTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicOrTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicOrTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicOrTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicOrTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicOrTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicOrTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicOrTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicOrTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicOrTester< UImg1DRGBA32F >::test();
		ImageUAtomicOrTester< UImg1DRGBA8I >::test();
		ImageUAtomicOrTester< UImg1DRGBA8U >::test();
		ImageUAtomicOrTester< UImg2DRGBA32F >::test();
		ImageUAtomicOrTester< UImg2DRGBA8I >::test();
		ImageUAtomicOrTester< UImg2DRGBA8U >::test();
		ImageUAtomicOrTester< UImg3DRGBA32F >::test();
		ImageUAtomicOrTester< UImg3DRGBA8I >::test();
		ImageUAtomicOrTester< UImg3DRGBA8U >::test();
		ImageUAtomicOrTester< UImgRectRGBA32F >::test();
		ImageUAtomicOrTester< UImgRectRGBA8I >::test();
		ImageUAtomicOrTester< UImgRectRGBA8U >::test();
		ImageUAtomicOrTester< UImgCubeRGBA32F >::test();
		ImageUAtomicOrTester< UImgCubeRGBA8I >::test();
		ImageUAtomicOrTester< UImgCubeRGBA8U >::test();
		ImageUAtomicOrTester< UImgBufferRGBA32F >::test();
		ImageUAtomicOrTester< UImgBufferRGBA8I >::test();
		ImageUAtomicOrTester< UImgBufferRGBA8U >::test();
		ImageUAtomicOrTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicOrTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicOrTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicOrTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicOrTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicOrTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicOrTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicOrTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicOrTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicOrTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicOrTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicOrTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicOrTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicOrTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicOrTester< UImg2DMSArrayRGBA8U >::test();
	}
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicXorTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicXorTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicXorTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicXor()
	{
		ImageIAtomicXorTester< FImg1DRGBA32F >::test();
		ImageIAtomicXorTester< FImg1DRGBA8I >::test();
		ImageIAtomicXorTester< FImg1DRGBA8U >::test();
		ImageIAtomicXorTester< FImg2DRGBA32F >::test();
		ImageIAtomicXorTester< FImg2DRGBA8I >::test();
		ImageIAtomicXorTester< FImg2DRGBA8U >::test();
		ImageIAtomicXorTester< FImg3DRGBA32F >::test();
		ImageIAtomicXorTester< FImg3DRGBA8I >::test();
		ImageIAtomicXorTester< FImg3DRGBA8U >::test();
		ImageIAtomicXorTester< FImgRectRGBA32F >::test();
		ImageIAtomicXorTester< FImgRectRGBA8I >::test();
		ImageIAtomicXorTester< FImgRectRGBA8U >::test();
		ImageIAtomicXorTester< FImgCubeRGBA32F >::test();
		ImageIAtomicXorTester< FImgCubeRGBA8I >::test();
		ImageIAtomicXorTester< FImgCubeRGBA8U >::test();
		ImageIAtomicXorTester< FImgBufferRGBA32F >::test();
		ImageIAtomicXorTester< FImgBufferRGBA8I >::test();
		ImageIAtomicXorTester< FImgBufferRGBA8U >::test();
		ImageIAtomicXorTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicXorTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicXorTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicXorTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicXorTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicXorTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicXorTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicXorTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicXorTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicXorTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicXorTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicXorTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicXorTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicXorTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicXorTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicXorTester< IImg1DRGBA32F >::test();
		ImageIAtomicXorTester< IImg1DRGBA8I >::test();
		ImageIAtomicXorTester< IImg1DRGBA8U >::test();
		ImageIAtomicXorTester< IImg2DRGBA32F >::test();
		ImageIAtomicXorTester< IImg2DRGBA8I >::test();
		ImageIAtomicXorTester< IImg2DRGBA8U >::test();
		ImageIAtomicXorTester< IImg3DRGBA32F >::test();
		ImageIAtomicXorTester< IImg3DRGBA8I >::test();
		ImageIAtomicXorTester< IImg3DRGBA8U >::test();
		ImageIAtomicXorTester< IImgRectRGBA32F >::test();
		ImageIAtomicXorTester< IImgRectRGBA8I >::test();
		ImageIAtomicXorTester< IImgRectRGBA8U >::test();
		ImageIAtomicXorTester< IImgCubeRGBA32F >::test();
		ImageIAtomicXorTester< IImgCubeRGBA8I >::test();
		ImageIAtomicXorTester< IImgCubeRGBA8U >::test();
		ImageIAtomicXorTester< IImgBufferRGBA32F >::test();
		ImageIAtomicXorTester< IImgBufferRGBA8I >::test();
		ImageIAtomicXorTester< IImgBufferRGBA8U >::test();
		ImageIAtomicXorTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicXorTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicXorTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicXorTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicXorTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicXorTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicXorTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicXorTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicXorTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicXorTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicXorTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicXorTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicXorTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicXorTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicXorTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicXorTester< UImg1DRGBA32F >::test();
		ImageIAtomicXorTester< UImg1DRGBA8I >::test();
		ImageIAtomicXorTester< UImg1DRGBA8U >::test();
		ImageIAtomicXorTester< UImg2DRGBA32F >::test();
		ImageIAtomicXorTester< UImg2DRGBA8I >::test();
		ImageIAtomicXorTester< UImg2DRGBA8U >::test();
		ImageIAtomicXorTester< UImg3DRGBA32F >::test();
		ImageIAtomicXorTester< UImg3DRGBA8I >::test();
		ImageIAtomicXorTester< UImg3DRGBA8U >::test();
		ImageIAtomicXorTester< UImgRectRGBA32F >::test();
		ImageIAtomicXorTester< UImgRectRGBA8I >::test();
		ImageIAtomicXorTester< UImgRectRGBA8U >::test();
		ImageIAtomicXorTester< UImgCubeRGBA32F >::test();
		ImageIAtomicXorTester< UImgCubeRGBA8I >::test();
		ImageIAtomicXorTester< UImgCubeRGBA8U >::test();
		ImageIAtomicXorTester< UImgBufferRGBA32F >::test();
		ImageIAtomicXorTester< UImgBufferRGBA8I >::test();
		ImageIAtomicXorTester< UImgBufferRGBA8U >::test();
		ImageIAtomicXorTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicXorTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicXorTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicXorTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicXorTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicXorTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicXorTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicXorTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicXorTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicXorTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicXorTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicXorTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicXorTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicXorTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicXorTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicXorTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicXorTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicXorTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicXor()
	{
		ImageUAtomicXorTester< FImg1DRGBA32F >::test();
		ImageUAtomicXorTester< FImg1DRGBA8I >::test();
		ImageUAtomicXorTester< FImg1DRGBA8U >::test();
		ImageUAtomicXorTester< FImg2DRGBA32F >::test();
		ImageUAtomicXorTester< FImg2DRGBA8I >::test();
		ImageUAtomicXorTester< FImg2DRGBA8U >::test();
		ImageUAtomicXorTester< FImg3DRGBA32F >::test();
		ImageUAtomicXorTester< FImg3DRGBA8I >::test();
		ImageUAtomicXorTester< FImg3DRGBA8U >::test();
		ImageUAtomicXorTester< FImgRectRGBA32F >::test();
		ImageUAtomicXorTester< FImgRectRGBA8I >::test();
		ImageUAtomicXorTester< FImgRectRGBA8U >::test();
		ImageUAtomicXorTester< FImgCubeRGBA32F >::test();
		ImageUAtomicXorTester< FImgCubeRGBA8I >::test();
		ImageUAtomicXorTester< FImgCubeRGBA8U >::test();
		ImageUAtomicXorTester< FImgBufferRGBA32F >::test();
		ImageUAtomicXorTester< FImgBufferRGBA8I >::test();
		ImageUAtomicXorTester< FImgBufferRGBA8U >::test();
		ImageUAtomicXorTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicXorTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicXorTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicXorTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicXorTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicXorTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicXorTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicXorTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicXorTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicXorTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicXorTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicXorTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicXorTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicXorTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicXorTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicXorTester< IImg1DRGBA32F >::test();
		ImageUAtomicXorTester< IImg1DRGBA8I >::test();
		ImageUAtomicXorTester< IImg1DRGBA8U >::test();
		ImageUAtomicXorTester< IImg2DRGBA32F >::test();
		ImageUAtomicXorTester< IImg2DRGBA8I >::test();
		ImageUAtomicXorTester< IImg2DRGBA8U >::test();
		ImageUAtomicXorTester< IImg3DRGBA32F >::test();
		ImageUAtomicXorTester< IImg3DRGBA8I >::test();
		ImageUAtomicXorTester< IImg3DRGBA8U >::test();
		ImageUAtomicXorTester< IImgRectRGBA32F >::test();
		ImageUAtomicXorTester< IImgRectRGBA8I >::test();
		ImageUAtomicXorTester< IImgRectRGBA8U >::test();
		ImageUAtomicXorTester< IImgCubeRGBA32F >::test();
		ImageUAtomicXorTester< IImgCubeRGBA8I >::test();
		ImageUAtomicXorTester< IImgCubeRGBA8U >::test();
		ImageUAtomicXorTester< IImgBufferRGBA32F >::test();
		ImageUAtomicXorTester< IImgBufferRGBA8I >::test();
		ImageUAtomicXorTester< IImgBufferRGBA8U >::test();
		ImageUAtomicXorTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicXorTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicXorTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicXorTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicXorTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicXorTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicXorTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicXorTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicXorTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicXorTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicXorTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicXorTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicXorTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicXorTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicXorTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicXorTester< UImg1DRGBA32F >::test();
		ImageUAtomicXorTester< UImg1DRGBA8I >::test();
		ImageUAtomicXorTester< UImg1DRGBA8U >::test();
		ImageUAtomicXorTester< UImg2DRGBA32F >::test();
		ImageUAtomicXorTester< UImg2DRGBA8I >::test();
		ImageUAtomicXorTester< UImg2DRGBA8U >::test();
		ImageUAtomicXorTester< UImg3DRGBA32F >::test();
		ImageUAtomicXorTester< UImg3DRGBA8I >::test();
		ImageUAtomicXorTester< UImg3DRGBA8U >::test();
		ImageUAtomicXorTester< UImgRectRGBA32F >::test();
		ImageUAtomicXorTester< UImgRectRGBA8I >::test();
		ImageUAtomicXorTester< UImgRectRGBA8U >::test();
		ImageUAtomicXorTester< UImgCubeRGBA32F >::test();
		ImageUAtomicXorTester< UImgCubeRGBA8I >::test();
		ImageUAtomicXorTester< UImgCubeRGBA8U >::test();
		ImageUAtomicXorTester< UImgBufferRGBA32F >::test();
		ImageUAtomicXorTester< UImgBufferRGBA8I >::test();
		ImageUAtomicXorTester< UImgBufferRGBA8U >::test();
		ImageUAtomicXorTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicXorTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicXorTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicXorTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicXorTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicXorTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicXorTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicXorTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicXorTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicXorTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicXorTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicXorTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicXorTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicXorTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicXorTester< UImg2DMSArrayRGBA8U >::test();
	}
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicExchangeTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicExchangeTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicExchangeTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicExchange()
	{
		ImageIAtomicExchangeTester< FImg1DRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg1DRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg1DRGBA8U >::test();
		ImageIAtomicExchangeTester< FImg2DRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg2DRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg2DRGBA8U >::test();
		ImageIAtomicExchangeTester< FImg3DRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg3DRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg3DRGBA8U >::test();
		ImageIAtomicExchangeTester< FImgRectRGBA32F >::test();
		ImageIAtomicExchangeTester< FImgRectRGBA8I >::test();
		ImageIAtomicExchangeTester< FImgRectRGBA8U >::test();
		ImageIAtomicExchangeTester< FImgCubeRGBA32F >::test();
		ImageIAtomicExchangeTester< FImgCubeRGBA8I >::test();
		ImageIAtomicExchangeTester< FImgCubeRGBA8U >::test();
		ImageIAtomicExchangeTester< FImgBufferRGBA32F >::test();
		ImageIAtomicExchangeTester< FImgBufferRGBA8I >::test();
		ImageIAtomicExchangeTester< FImgBufferRGBA8U >::test();
		ImageIAtomicExchangeTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicExchangeTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicExchangeTester< IImg1DRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg1DRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg1DRGBA8U >::test();
		ImageIAtomicExchangeTester< IImg2DRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg2DRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg2DRGBA8U >::test();
		ImageIAtomicExchangeTester< IImg3DRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg3DRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg3DRGBA8U >::test();
		ImageIAtomicExchangeTester< IImgRectRGBA32F >::test();
		ImageIAtomicExchangeTester< IImgRectRGBA8I >::test();
		ImageIAtomicExchangeTester< IImgRectRGBA8U >::test();
		ImageIAtomicExchangeTester< IImgCubeRGBA32F >::test();
		ImageIAtomicExchangeTester< IImgCubeRGBA8I >::test();
		ImageIAtomicExchangeTester< IImgCubeRGBA8U >::test();
		ImageIAtomicExchangeTester< IImgBufferRGBA32F >::test();
		ImageIAtomicExchangeTester< IImgBufferRGBA8I >::test();
		ImageIAtomicExchangeTester< IImgBufferRGBA8U >::test();
		ImageIAtomicExchangeTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicExchangeTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicExchangeTester< UImg1DRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg1DRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg1DRGBA8U >::test();
		ImageIAtomicExchangeTester< UImg2DRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg2DRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg2DRGBA8U >::test();
		ImageIAtomicExchangeTester< UImg3DRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg3DRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg3DRGBA8U >::test();
		ImageIAtomicExchangeTester< UImgRectRGBA32F >::test();
		ImageIAtomicExchangeTester< UImgRectRGBA8I >::test();
		ImageIAtomicExchangeTester< UImgRectRGBA8U >::test();
		ImageIAtomicExchangeTester< UImgCubeRGBA32F >::test();
		ImageIAtomicExchangeTester< UImgCubeRGBA8I >::test();
		ImageIAtomicExchangeTester< UImgCubeRGBA8U >::test();
		ImageIAtomicExchangeTester< UImgBufferRGBA32F >::test();
		ImageIAtomicExchangeTester< UImgBufferRGBA8I >::test();
		ImageIAtomicExchangeTester< UImgBufferRGBA8U >::test();
		ImageIAtomicExchangeTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicExchangeTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicExchangeTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicExchangeTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicExchangeTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicExchangeTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicExchangeTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicExchangeTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicExchange()
	{
		ImageUAtomicExchangeTester< FImg1DRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg1DRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg1DRGBA8U >::test();
		ImageUAtomicExchangeTester< FImg2DRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg2DRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg2DRGBA8U >::test();
		ImageUAtomicExchangeTester< FImg3DRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg3DRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg3DRGBA8U >::test();
		ImageUAtomicExchangeTester< FImgRectRGBA32F >::test();
		ImageUAtomicExchangeTester< FImgRectRGBA8I >::test();
		ImageUAtomicExchangeTester< FImgRectRGBA8U >::test();
		ImageUAtomicExchangeTester< FImgCubeRGBA32F >::test();
		ImageUAtomicExchangeTester< FImgCubeRGBA8I >::test();
		ImageUAtomicExchangeTester< FImgCubeRGBA8U >::test();
		ImageUAtomicExchangeTester< FImgBufferRGBA32F >::test();
		ImageUAtomicExchangeTester< FImgBufferRGBA8I >::test();
		ImageUAtomicExchangeTester< FImgBufferRGBA8U >::test();
		ImageUAtomicExchangeTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicExchangeTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicExchangeTester< IImg1DRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg1DRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg1DRGBA8U >::test();
		ImageUAtomicExchangeTester< IImg2DRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg2DRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg2DRGBA8U >::test();
		ImageUAtomicExchangeTester< IImg3DRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg3DRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg3DRGBA8U >::test();
		ImageUAtomicExchangeTester< IImgRectRGBA32F >::test();
		ImageUAtomicExchangeTester< IImgRectRGBA8I >::test();
		ImageUAtomicExchangeTester< IImgRectRGBA8U >::test();
		ImageUAtomicExchangeTester< IImgCubeRGBA32F >::test();
		ImageUAtomicExchangeTester< IImgCubeRGBA8I >::test();
		ImageUAtomicExchangeTester< IImgCubeRGBA8U >::test();
		ImageUAtomicExchangeTester< IImgBufferRGBA32F >::test();
		ImageUAtomicExchangeTester< IImgBufferRGBA8I >::test();
		ImageUAtomicExchangeTester< IImgBufferRGBA8U >::test();
		ImageUAtomicExchangeTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicExchangeTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicExchangeTester< UImg1DRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg1DRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg1DRGBA8U >::test();
		ImageUAtomicExchangeTester< UImg2DRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg2DRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg2DRGBA8U >::test();
		ImageUAtomicExchangeTester< UImg3DRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg3DRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg3DRGBA8U >::test();
		ImageUAtomicExchangeTester< UImgRectRGBA32F >::test();
		ImageUAtomicExchangeTester< UImgRectRGBA8I >::test();
		ImageUAtomicExchangeTester< UImgRectRGBA8U >::test();
		ImageUAtomicExchangeTester< UImgCubeRGBA32F >::test();
		ImageUAtomicExchangeTester< UImgCubeRGBA8I >::test();
		ImageUAtomicExchangeTester< UImgCubeRGBA8U >::test();
		ImageUAtomicExchangeTester< UImgBufferRGBA32F >::test();
		ImageUAtomicExchangeTester< UImgBufferRGBA8I >::test();
		ImageUAtomicExchangeTester< UImgBufferRGBA8U >::test();
		ImageUAtomicExchangeTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicExchangeTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicExchangeTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicExchangeTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicExchangeTester< UImg2DMSArrayRGBA8U >::test();
	}
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicCompSwapTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicCompSwapTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_i, 3_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicCompSwapTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i, 3_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageIAtomicCompSwap()
	{
		ImageIAtomicCompSwapTester< FImg1DRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg1DRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg1DRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImg2DRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg2DRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg2DRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImg3DRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg3DRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg3DRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImgRectRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImgRectRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImgRectRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImgCubeRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImgCubeRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImgCubeRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImgBufferRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImgBufferRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImgBufferRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImg1DArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg1DArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg1DArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImg2DArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg2DArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg2DArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImgCubeArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImgCubeArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImgCubeArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImg2DMSRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg2DMSRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg2DMSRGBA8U >::test();
		ImageIAtomicCompSwapTester< FImg2DMSArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< FImg2DMSArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< FImg2DMSArrayRGBA8U >::test();

		ImageIAtomicCompSwapTester< IImg1DRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg1DRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg1DRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImg2DRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg2DRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg2DRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImg3DRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg3DRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg3DRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImgRectRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImgRectRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImgRectRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImgCubeRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImgCubeRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImgCubeRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImgBufferRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImgBufferRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImgBufferRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImg1DArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg1DArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg1DArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImg2DArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg2DArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg2DArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImgCubeArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImgCubeArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImgCubeArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImg2DMSRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg2DMSRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg2DMSRGBA8U >::test();
		ImageIAtomicCompSwapTester< IImg2DMSArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< IImg2DMSArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< IImg2DMSArrayRGBA8U >::test();

		ImageIAtomicCompSwapTester< UImg1DRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg1DRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg1DRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImg2DRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg2DRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg2DRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImg3DRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg3DRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg3DRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImgRectRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImgRectRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImgRectRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImgCubeRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImgCubeRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImgCubeRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImgBufferRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImgBufferRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImgBufferRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImg1DArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg1DArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg1DArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImg2DArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg2DArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg2DArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImgCubeArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImgCubeArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImgCubeArrayRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImg2DMSRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg2DMSRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg2DMSRGBA8U >::test();
		ImageIAtomicCompSwapTester< UImg2DMSArrayRGBA32F >::test();
		ImageIAtomicCompSwapTester< UImg2DMSArrayRGBA8I >::test();
		ImageIAtomicCompSwapTester< UImg2DMSArrayRGBA8U >::test();
	}

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicCompSwapTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicCompSwapTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_u, 3_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, ast::type::ImageFormat FormatT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicCompSwapTester< SampledT, DimT, FormatT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = CoordsGetterT< DimT, ArrayedT >;

		static void test()
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, FormatT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, FormatT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u, 3_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment );
			}
			testEnd();
		};
	};

	void testsImageUAtomicCompSwap()
	{
		ImageUAtomicCompSwapTester< FImg1DRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg1DRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg1DRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImg2DRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg2DRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg2DRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImg3DRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg3DRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg3DRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImgRectRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImgRectRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImgRectRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImgCubeRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImgCubeRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImgCubeRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImgBufferRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImgBufferRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImgBufferRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImg1DArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg1DArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg1DArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImg2DArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg2DArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg2DArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImgCubeArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImgCubeArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImgCubeArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImg2DMSRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg2DMSRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg2DMSRGBA8U >::test();
		ImageUAtomicCompSwapTester< FImg2DMSArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< FImg2DMSArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< FImg2DMSArrayRGBA8U >::test();

		ImageUAtomicCompSwapTester< IImg1DRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg1DRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg1DRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImg2DRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg2DRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg2DRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImg3DRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg3DRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg3DRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImgRectRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImgRectRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImgRectRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImgCubeRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImgCubeRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImgCubeRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImgBufferRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImgBufferRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImgBufferRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImg1DArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg1DArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg1DArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImg2DArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg2DArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg2DArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImgCubeArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImgCubeArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImgCubeArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImg2DMSRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg2DMSRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg2DMSRGBA8U >::test();
		ImageUAtomicCompSwapTester< IImg2DMSArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< IImg2DMSArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< IImg2DMSArrayRGBA8U >::test();

		ImageUAtomicCompSwapTester< UImg1DRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg1DRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg1DRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImg2DRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg2DRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg2DRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImg3DRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg3DRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg3DRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImgRectRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImgRectRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImgRectRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImgCubeRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImgCubeRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImgCubeRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImgBufferRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImgBufferRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImgBufferRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImg1DArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg1DArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg1DArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImg2DArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg2DArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg2DArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImgCubeArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImgCubeArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImgCubeArrayRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImg2DMSRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg2DMSRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg2DMSRGBA8U >::test();
		ImageUAtomicCompSwapTester< UImg2DMSArrayRGBA32F >::test();
		ImageUAtomicCompSwapTester< UImg2DMSArrayRGBA8I >::test();
		ImageUAtomicCompSwapTester< UImg2DMSArrayRGBA8U >::test();
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterImageAccesses" );
	testsImageSize();
	testsImageSamples();
	testsImageLoad();
	testsImageIAtomicAdd();
	testsImageUAtomicAdd();
	testsImageIAtomicMin();
	testsImageUAtomicMin();
	testsImageIAtomicMax();
	testsImageUAtomicMax();
	testsImageIAtomicAnd();
	testsImageUAtomicAnd();
	testsImageIAtomicOr();
	testsImageUAtomicOr();
	testsImageIAtomicXor();
	testsImageUAtomicXor();
	testsImageIAtomicExchange();
	testsImageUAtomicExchange();
	testsImageIAtomicCompSwap();
	testsImageUAtomicCompSwap();
	testSuiteEnd();
}
