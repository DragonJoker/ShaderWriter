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
			auto name = "testSample" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProj" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleLodShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, test::getDefault < OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleConstOffsetShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault < OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleConstOffsetBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).sample( test::getDefault< SampleT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleConstOffsetShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjConstOffsetShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjConstOffsetBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjConstOffsetShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleLodConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).lod( test::getDefault< SampleT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleLodShadowConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjShadowLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjLodConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjShadowLodConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleShadowGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleShadowGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleProjGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleProjShadowGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleGather" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleGatherConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 1_i
								, test::getDefault< OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadowConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto i = writer.declSampledImg< FormatT, DimT, ArrayedT, MsT >( "i", 0u, 0u );
				auto s = writer.declSampler< DepthT >( "s", 1u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto e = writer.declLocale( "e"
							, combine( i, s ).gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleGatherOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadowOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			auto name = "testSampleGatherOffsets" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testSampleGatherShadowOffsets" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
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

				if constexpr ( DimT == ast::type::ImageDim::eBuffer )
				{
					test::writeShader( writer, testCounts, Compilers_AllButSpv16 );
				}
				else
				{
					test::writeShader( writer, testCounts, CurrentCompilers );
				}
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
		TesterT< FormatT, Img1DBase, false >::test( testCounts );
		TesterT< FormatT, Img2DBase, false >::test( testCounts );
		TesterT< FormatT, Img3DBase, false >::test( testCounts );
		TesterT< FormatT, ImgCubeBase, false >::test( testCounts );
		TesterT< FormatT, ImgBufferBase, false >::test( testCounts );
		TesterT< FormatT, Img1DArrayBase, false >::test( testCounts );
		TesterT< FormatT, Img2DArrayBase, false >::test( testCounts );
		TesterT< FormatT, ImgCubeArrayBase, false >::test( testCounts );

		if constexpr ( isFloatFormat( FormatT ) )
		{
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
	}
	template< template< ast::type::ImageFormat, ast::type::ImageDim, bool, bool, bool, typename Enable = void > typename TesterT >
	void testsTextures( test::sdw_test::TestCounts & testCounts )
	{
		testsTexture< ast::type::ImageFormat::SDW_TestImageFormat, TesterT >( testCounts );
	}
	/**@}*/
#pragma endregion
}

#endif

#define testName testConcat( TestWriterSampledImageAccesses, SDW_TestImageFormat )

sdwTestSuiteMain( testName )
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

sdwTestSuiteLaunch( testName )
