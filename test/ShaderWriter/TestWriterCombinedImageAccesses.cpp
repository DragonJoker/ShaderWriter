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
	static constexpr bool hasLodV = !sdw::isBufferV< DimT, ArrayedT, DepthT >;

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
#pragma region textureSize
	/**
	*name
	*	textureSize
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct TextureSizeTester
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
	struct TextureSizeTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< hasLodV< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureSizeLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto j = writer.declLocale( "j"
							, s.getSize( 0_i ) );
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
	struct TextureSizeTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< !hasLodV< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureSize" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto j = writer.declLocale( "j"
							, s.getSize() );
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
#pragma region textureQueryLod
	/**
	*name
	*	textureQueryLod
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct TextureQueryLodTester
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
	struct TextureQueryLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< hasLodV< DimT, ArrayedT, DepthT > > >
	{
		using QueryLodT = typename sdw::CombinedImageQueryLodT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureQueryLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto j = writer.declLocale( "j"
							, s.getLod( test::getDefault< QueryLodT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts
					, { true, true, !isShadowV< DimT, ArrayedT, DepthT >, true, ForceDisplayShaders, 0x00010600u } );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureQueryLevels
	/**
	*name
	*	textureQueryLevels
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct TextureQueryLevelsTester
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
	struct TextureQueryLevelsTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureQueryLevels" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto j = writer.declLocale( "j"
							, s.getLevels() );
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
	struct TextureTester
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
	struct TextureTester< FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTexture" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer ) ) );
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
	struct TextureTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< isShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
	struct TextureBiasTester
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
	struct TextureBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
	struct TextureBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
	struct TextureProjTester
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
	struct TextureProjTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProj" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer ) ) );
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
	struct TextureProjTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjBiasTester
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
	struct TextureProjBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureLodTester
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
	struct TextureLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
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
	struct TextureLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureLodShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
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
	struct TextureConstOffsetTester
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
	struct TextureConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
	struct TextureConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureConstOffsetShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
	struct TextureConstOffsetBiasTester
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
	struct TextureConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureConstOffsetBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
	struct TextureConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureConstOffsetShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
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
#pragma region texelFetch
	/**
	*name
	*	texelFetch
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct TexelFetchTester
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
	struct TexelFetchTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::CombinedImageFetchT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.fetch( test::getDefault< FetchT >( writer )
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
	struct TexelFetchTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::isBufferV< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::CombinedImageFetchT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexelFetch" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.fetch( test::getDefault< FetchT >( writer ) ) );
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
#pragma region texelFetchOffset
	/**
	*name
	*	texelFetchOffset
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool MsT
		, bool DepthT
		, typename Enable = void >
	struct TexelFetchConstOffsetTester
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
	struct TexelFetchConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::CombinedImageFetchT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchConstOffsetLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.fetch( test::getDefault< FetchT >( writer )
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
	struct TextureProjConstOffsetTester
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
	struct TextureProjConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjConstOffsetShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjConstOffsetBiasTester
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
	struct TextureProjConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjConstOffsetBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjConstOffsetBiasTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjConstOffsetShadowBias" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
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
	struct TextureLodConstOffsetTester
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
	struct TextureLodConstOffsetTester < FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureLodConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
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
	struct TextureLodConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureLodShadowConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
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
	struct TextureProjLodTester
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
	struct TextureProjLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjLodTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowLod" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjLodConstOffsetTester
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
	struct TextureProjLodConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjLodConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjLodConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowLodConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
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
	struct TextureGradTester
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
	struct TextureGradTester < FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
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
	struct TextureGradTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::CombinedImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
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
	struct TextureGradConstOffsetTester
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
	struct TextureGradConstOffsetTester < FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
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
	struct TextureGradConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
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
			auto name = "testTextureShadowGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
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
	struct TextureProjGradTester
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
	struct TextureProjGradTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjGradTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowGrad" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjGradConstOffsetTester
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
	struct TextureProjGradConstOffsetTester < FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
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
	struct TextureProjGradConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::CombinedImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::CombinedImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowGradConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
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
	struct TextureGatherTester
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
	struct TextureGatherTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGather" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
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
	struct TextureGatherTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadow" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
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
	struct TextureGatherConstOffsetTester
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
	struct TextureGatherConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
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
	struct TextureGatherConstOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowConstOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
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
	struct TextureGatherOffsetTester
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
	struct TextureGatherOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto o = writer.declLocale< OffsetT >( "o" );
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, 1_i
								, o ) );
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
	struct TextureGatherOffsetTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowOffset" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto o = writer.declLocale< OffsetT >( "o" );
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, o ) );
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
	struct TextureGatherOffsetsTester
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
	struct TextureGatherOffsetsTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsets" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
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
	struct TextureGatherOffsetsTester< FormatT, DimT, ArrayedT, MsT, DepthT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::CombinedImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::CombinedImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowOffsets" + sdw::debug::getImageTypeName( FormatT, ast::type::AccessKind::eRead, DimT, ast::type::Trinary::eDontCare, ArrayedT, MsT, DepthT );
			testBegin( name );
			using namespace sdw;
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto s = writer.declCombinedImg< FormatT, DimT, ArrayedT, MsT, DepthT >( "s", 0u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
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

#define testName testConcat( TestWriterCombinedImageAccesses, SDW_TestImageFormat )

sdwTestSuiteMain( testName )
{
	sdwTestSuiteBegin();
#if !defined( __APPLE__ )

	testsTextures< TextureSizeTester >( testCounts );
	testsTextures< TextureQueryLodTester >( testCounts );
	testsTextures< TextureQueryLevelsTester >( testCounts );
	testsTextures< TextureTester >( testCounts );
	testsTextures< TextureBiasTester >( testCounts );
	testsTextures< TextureProjTester >( testCounts );
	testsTextures< TextureProjBiasTester >( testCounts );
	testsTextures< TextureLodTester >( testCounts );
	testsTextures< TextureConstOffsetTester >( testCounts );
	testsTextures< TextureConstOffsetBiasTester >( testCounts );
	testsTextures< TexelFetchTester >( testCounts );
	testsTextures< TexelFetchConstOffsetTester >( testCounts );
	testsTextures< TextureProjConstOffsetTester >( testCounts );
	testsTextures< TextureProjConstOffsetBiasTester >( testCounts );
	testsTextures< TextureLodConstOffsetTester >( testCounts );
	testsTextures< TextureProjLodTester >( testCounts );
	testsTextures< TextureProjLodConstOffsetTester >( testCounts );
	testsTextures< TextureGradTester >( testCounts );
	testsTextures< TextureGradConstOffsetTester >( testCounts );
	testsTextures< TextureProjGradTester >( testCounts );
	testsTextures< TextureProjGradConstOffsetTester >( testCounts );
	testsTextures< TextureGatherTester >( testCounts );
	testsTextures< TextureGatherConstOffsetTester >( testCounts );
	testsTextures< TextureGatherOffsetTester >( testCounts );
	testsTextures< TextureGatherOffsetsTester >( testCounts );

#endif
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( testName )
