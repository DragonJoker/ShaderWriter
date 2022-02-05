#include "Common.hpp"
#include "WriterCommon.hpp"

#if !defined( __APPLE__ )

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
#pragma region Helpers
	/**
	*name
	*	Helpers
	*/
	/**@{*/
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static constexpr bool isShadowV = ( sdw::is1dShadowV< DimT, ArrayedT, DepthT >
		|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
		|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
		|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
		|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
		|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
		|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > );
	/**@}*/
#pragma endregion
#pragma region texture
	/**
	*name
	*	texture
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSample" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< isShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureBias
	/**
	*name
	*	textureBias
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageBiasTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProj
	/**
	*name
	*	textureProj
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProj" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjBias
	/**
	*name
	*	textureProjBias
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjBiasTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureLod
	/**
	*name
	*	textureLod
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageLodTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleLodShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureOffset
	/**
	*name
	*	textureOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, test::getDefault < OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleConstOffsetShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault < OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureOffsetBias
	/**
	*name
	*	textureOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageConstOffsetBiasTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleConstOffsetBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleConstOffsetShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjOffset
	/**
	*name
	*	textureProjOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjConstOffsetShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjOffsetBias
	/**
	*name
	*	textureProjOffsetBias
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjConstOffsetBiasTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjConstOffsetBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjConstOffsetShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureLodOffset
	/**
	*name
	*	textureLodOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageLodConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageLodConstOffsetTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleLodConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageLodConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleLodShadowConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjLod
	/**
	*name
	*	textureProjLod
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjLodTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjLodOffset
	/**
	*name
	*	textureProjLodOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjLodConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjLodConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjLodConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjLodConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowLodConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGrad
	/**
	*name
	*	textureGrad
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageGradTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGradTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGradTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleShadowGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGradOffset
	/**
	*name
	*	textureGradOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageGradConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGradConstOffsetTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGradConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGradConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleShadowGradConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjGrad
	/**
	*name
	*	textureProjGrad
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjGradTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjGradTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjGradTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureProjGradOffset
	/**
	*name
	*	textureProjGradOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageProjGradConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjGradConstOffsetTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjGradConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageProjGradConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowGradConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGather
	/**
	*name
	*	textureGather
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageGatherTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGather" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGatherOffset
	/**
	*name
	*	textureGatherOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageGatherConstOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadowConstOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageGatherOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto p = writer.declConstant< OffsetT >( "p"
							, test::getDefault< OffsetT >( writer ) );
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, p ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadowOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto p = writer.declConstant< OffsetT >( "p"
							, test::getDefault< OffsetT >( writer ) );
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, p ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsets
	/**
	*name
	*	textureGatherOffsets
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct SampledImageGatherOffsetsTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherOffsetsTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherOffsets" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, offsets ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT >
	struct SampledImageGatherOffsetsTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadowOffsets" + sdw::debug::getName( FormatT, DimT, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, offsets ) );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region Main test function
	/**
	*name
	*	Main test function
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT, template< ast::type::ImageFormat, ast::type::ImageDim, bool, bool, bool, typename Enable = void > typename TesterT >
	void testsTexture( test::sdw_test::TestCounts & testCounts )
	{
		if constexpr ( isFloatFormat( FormatT ) )
		{
			TesterT< FormatT, Img1DBase, false >::test( testCounts );
			TesterT< FormatT, Img2DBase, false >::test( testCounts );
			TesterT< FormatT, Img3DBase, false >::test( testCounts );
			TesterT< FormatT, ImgCubeBase, false >::test( testCounts );
			TesterT< FormatT, ImgBufferBase, false >::test( testCounts );
			TesterT< FormatT, Img1DArrayBase, false >::test( testCounts );
			TesterT< FormatT, Img2DArrayBase, false >::test( testCounts );
			TesterT< FormatT, ImgCubeArrayBase, false >::test( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				TesterT< FormatT, Img1DBase, true >::test( testCounts );
				TesterT< FormatT, Img2DBase, true >::test( testCounts );
				TesterT< FormatT, ImgCubeBase, true >::test( testCounts );
				TesterT< FormatT, Img1DArrayBase, true >::test( testCounts );
				TesterT< FormatT, Img2DArrayBase, true >::test( testCounts );
				TesterT< FormatT, ImgCubeArrayBase, true >::test( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			TesterT< FormatT, Img1DBase, false >::test( testCounts );
			TesterT< FormatT, Img2DBase, false >::test( testCounts );
			TesterT< FormatT, Img3DBase, false >::test( testCounts );
			TesterT< FormatT, ImgCubeBase, false >::test( testCounts );
			TesterT< FormatT, ImgBufferBase, false >::test( testCounts );
			TesterT< FormatT, Img1DArrayBase, false >::test( testCounts );
			TesterT< FormatT, Img2DArrayBase, false >::test( testCounts );
			TesterT< FormatT, ImgCubeArrayBase, false >::test( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			TesterT< FormatT, Img1DBase, false >::test( testCounts );
			TesterT< FormatT, Img2DBase, false >::test( testCounts );
			TesterT< FormatT, Img3DBase, false >::test( testCounts );
			TesterT< FormatT, ImgCubeBase, false >::test( testCounts );
			TesterT< FormatT, ImgBufferBase, false >::test( testCounts );
			TesterT< FormatT, Img1DArrayBase, false >::test( testCounts );
			TesterT< FormatT, Img2DArrayBase, false >::test( testCounts );
			TesterT< FormatT, ImgCubeArrayBase, false >::test( testCounts );
		}
	}
	template< template< ast::type::ImageFormat, ast::type::ImageDim, bool, bool, bool, typename Enable = void > typename TesterT >
	void testsTextures( test::sdw_test::TestCounts & testCounts )
	{
		testsTexture< ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsTexture< ast::type::ImageFormat::eR8u, TesterT >( testCounts );
	}
	/**@}*/
#pragma endregion
}

#endif

sdwTestSuiteMain( TestWriterSampledImageAccesses )
{
	sdwTestSuiteBegin();
#if !defined( __APPLE__ )

	testsTextures< SampledImageTester >( testCounts );
	testsTextures< SampledImageBiasTester >( testCounts );
	testsTextures< SampledImageProjTester >( testCounts );
	testsTextures< SampledImageProjBiasTester >( testCounts );
	testsTextures< SampledImageLodTester >( testCounts );
	testsTextures< SampledImageConstOffsetTester >( testCounts );
	testsTextures< SampledImageConstOffsetBiasTester >( testCounts );
	testsTextures< SampledImageProjConstOffsetTester >( testCounts );
	testsTextures< SampledImageProjConstOffsetBiasTester >( testCounts );
	testsTextures< SampledImageLodConstOffsetTester >( testCounts );
	testsTextures< SampledImageProjLodTester >( testCounts );
	testsTextures< SampledImageProjLodConstOffsetTester >( testCounts );
	testsTextures< SampledImageGradTester >( testCounts );
	testsTextures< SampledImageGradConstOffsetTester >( testCounts );
	testsTextures< SampledImageProjGradTester >( testCounts );
	testsTextures< SampledImageProjGradConstOffsetTester >( testCounts );
	testsTextures< SampledImageGatherTester >( testCounts );
	testsTextures< SampledImageGatherConstOffsetTester >( testCounts );
	testsTextures< SampledImageGatherOffsetTester >( testCounts );
	testsTextures< SampledImageGatherOffsetsTester >( testCounts );

#endif
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterSampledImageAccesses )
