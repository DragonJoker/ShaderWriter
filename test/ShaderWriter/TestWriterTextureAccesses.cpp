#include "../Common.hpp"
#include "WriterCommon.hpp"

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
	static constexpr bool hasLodV = !( sdw::isBufferV< DimT, ArrayedT, DepthT >
		|| sdw::isRectV< DimT, ArrayedT, DepthT >
		|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > );

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
#pragma region textureSize
	/**
	*name
	*	textureSize
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< hasLodV< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureSizeLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto j = writer.declLocale( "j"
							, s.getSize( 0_i ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		};
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !hasLodV< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureSize" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto j = writer.declLocale( "j"
							, s.getSize() );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		};
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureQueryLodTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< hasLodV< DimT, ArrayedT, DepthT > > >
	{
		using QueryLodT = typename sdw::SampledImageQueryLodT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureQueryLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto j = writer.declLocale( "j"
							, s.getLod( test::getDefault< QueryLodT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts
					, true, !isShadowV< DimT, ArrayedT, DepthT >, true );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureQueryLevelsTester< FormatT, DimT, ArrayedT, DepthT, MsT
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
			auto name = "testTextureQueryLevels" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto j = writer.declLocale( "j"
							, s.getLevels() );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexture" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< isShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureBiasTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureBiasTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureProjTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProj" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureProjBiasTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjBiasTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureLodTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureLodShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, test::getDefault < OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureOffsetShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault < OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureOffsetBiasTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetBiasTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureOffsetBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetBiasTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureOffsetShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.sample( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TexelFetchTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.fetch( test::getDefault< FetchT >( writer )
								, 1_i ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TexelFetchTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::isBufferV< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexelFetch" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.fetch( test::getDefault< FetchT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TexelFetchOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TexelFetchOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchOffsetLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.fetch( test::getDefault< FetchT >( writer )
								, 1_i
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffsetShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjOffsetBiasTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetBiasTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffsetBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetBiasTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffsetShadowBias" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.proj( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureLodOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodOffsetTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureLodOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureLodShadowOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.lod( test::getDefault< SampleT >( writer )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureProjLodTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjLodOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjLodOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowLodOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projLod( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureGradTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGradOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradOffsetTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGradOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is1dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowGradOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.grad( test::getDefault< SampleT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureProjGradTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowGrad" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjGradOffsetTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradOffsetTester < FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is3dV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjGradOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is1dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowGradOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.projGrad( test::getDefault< SampleProjT >( writer )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< DerivativeT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureGatherTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGather" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadow" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, 0.5_f ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGatherComp
	/**
	*name
	*	textureGatherComp
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherCompTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherCompTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT >
			|| sdw::isCubeArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherComp" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, 1_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowOffset" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, test::getDefault< OffsetT >( writer ) ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsetComp
	/**
	*name
	*	textureGatherOffsetComp
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherOffsetCompTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetCompTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsetComp" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, test::getDefault< OffsetT >( writer )
								, 1_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool DepthT
		, bool MsT
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
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetsTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsets" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, offsets ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetsTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dShadowV< DimT, ArrayedT, DepthT >
			|| sdw::isRectShadowV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayShadowV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowOffsets" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, 0.5_f
								, offsets ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};
	/**@}*/
#pragma endregion
#pragma region textureGatherOffsetsComp
	/**
	*name
	*	textureGatherOffsetsComp
	*/
	/**@{*/
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherOffsetsCompTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetsCompTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< sdw::is2dV< DimT, ArrayedT, DepthT >
			|| sdw::is2dArrayV< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsetsComp" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				auto offsets = writer.declConstantArray< OffsetT >( "offsets"
					, test::getDefaultVector< OffsetT >( writer, 4u ) );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto d = writer.declLocale( "d"
							, s.gather( test::getDefault< GatherT >( writer )
								, offsets
								, 1_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
			TesterT< FormatT, Img1D >::test( testCounts );
			TesterT< FormatT, Img2D >::test( testCounts );
			TesterT< FormatT, Img3D >::test( testCounts );
			TesterT< FormatT, ImgCube >::test( testCounts );
			TesterT< FormatT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, Img1DArray >::test( testCounts );
			TesterT< FormatT, Img2DArray >::test( testCounts );
			TesterT< FormatT, ImgCubeArray >::test( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				TesterT< FormatT, Img1DShadow >::test( testCounts );
				TesterT< FormatT, Img2DShadow >::test( testCounts );
				TesterT< FormatT, ImgCubeShadow >::test( testCounts );
				TesterT< FormatT, Img1DArrayShadow >::test( testCounts );
				TesterT< FormatT, Img2DArrayShadow >::test( testCounts );
				TesterT< FormatT, ImgCubeArrayShadow >::test( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			TesterT< FormatT, Img1D >::test( testCounts );
			TesterT< FormatT, Img2D >::test( testCounts );
			TesterT< FormatT, Img3D >::test( testCounts );
			TesterT< FormatT, ImgCube >::test( testCounts );
			TesterT< FormatT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, Img1DArray >::test( testCounts );
			TesterT< FormatT, Img2DArray >::test( testCounts );
			TesterT< FormatT, ImgCubeArray >::test( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			TesterT< FormatT, Img1D >::test( testCounts );
			TesterT< FormatT, Img2D >::test( testCounts );
			TesterT< FormatT, Img3D >::test( testCounts );
			TesterT< FormatT, ImgCube >::test( testCounts );
			TesterT< FormatT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, Img1DArray >::test( testCounts );
			TesterT< FormatT, Img2DArray >::test( testCounts );
			TesterT< FormatT, ImgCubeArray >::test( testCounts );
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

sdwTestSuiteMain( TestWriterTextureAccesses )
{
#if !defined( __APPLE__ )

	sdwTestSuiteBegin();
	testsTextures< TextureSizeTester >( testCounts );
	testsTextures< TextureQueryLodTester >( testCounts );
	testsTextures< TextureQueryLevelsTester >( testCounts );
	testsTextures< TextureTester >( testCounts );
	testsTextures< TextureBiasTester >( testCounts );
	testsTextures< TextureProjTester >( testCounts );
	testsTextures< TextureProjBiasTester >( testCounts );
	testsTextures< TextureLodTester >( testCounts );
	testsTextures< TextureOffsetTester >( testCounts );
	testsTextures< TextureOffsetBiasTester >( testCounts );
	testsTextures< TexelFetchTester >( testCounts );
	testsTextures< TexelFetchOffsetTester >( testCounts );
	testsTextures< TextureProjOffsetTester >( testCounts );
	testsTextures< TextureProjOffsetBiasTester >( testCounts );
	testsTextures< TextureLodOffsetTester >( testCounts );
	testsTextures< TextureProjLodTester >( testCounts );
	testsTextures< TextureProjLodOffsetTester >( testCounts );
	testsTextures< TextureGradTester >( testCounts );
	testsTextures< TextureGradOffsetTester >( testCounts );
	testsTextures< TextureProjGradTester >( testCounts );
	testsTextures< TextureProjGradOffsetTester >( testCounts );
	testsTextures< TextureGatherTester >( testCounts );
	testsTextures< TextureGatherCompTester >( testCounts );
	testsTextures< TextureGatherOffsetTester >( testCounts );
	testsTextures< TextureGatherOffsetCompTester >( testCounts );
	testsTextures< TextureGatherOffsetsTester >( testCounts );
	testsTextures< TextureGatherOffsetsCompTester >( testCounts );
	sdwTestSuiteEnd();

#endif
}

sdwTestSuiteLaunch( TestWriterTextureAccesses )
