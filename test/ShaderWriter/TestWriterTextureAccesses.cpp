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
	static bool constexpr is1D = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2D = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is3D = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e3D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isBuffer = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eBuffer );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCube = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1DArray = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2DArray = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeArray = ( !DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1DShadow = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2DShadow = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isRectShadow = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );

	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeShadow = ( DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is1DArrayShadow = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e1D );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr is2DArrayShadow = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::e2D );
	
	template< ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	static bool constexpr isCubeArrayShadow = ( DepthT ) && ( ArrayedT ) && ( DimT == ast::type::ImageDim::eCube );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT >
			|| is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureSizeLod" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i"
							, textureSize( s, 0_i ) );
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
		, std::enable_if_t< isBuffer< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureSize" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i"
							, textureSize( s ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT >/*
			|| is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT >*/ > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i"
							, textureQueryLod( s, test::getDefault< QueryLodT >( writer.getShader() ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT >
			|| is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testTextureQueryLevels" + sdw::debug::getName( FormatT, DimT, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer;
				auto s = writer.declSampledImage< FormatT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i"
							, textureQueryLevels( s ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texture( s
								, test::getDefault< SampleT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texture( s
								, test::getDefault< SampleT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texture( s
								, test::getDefault< SampleT >( writer.getShader() )
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texture( s
								, test::getDefault< SampleT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProj( s
								, test::getDefault< SampleProjT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProj( s
								, test::getDefault< SampleProjT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProj( s
								, test::getDefault< SampleProjT >( writer.getShader() )
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProj( s
								, test::getDefault< SampleProjT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureLod( s
								, test::getDefault< SampleT >( writer.getShader() )
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureLod( s
								, test::getDefault< SampleT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, test::getDefault < OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, 0.5_f
								, test::getDefault < OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() )
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< OffsetT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texelFetch( s
								, test::getDefault< FetchT >( writer.getShader() )
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
		, std::enable_if_t< isBuffer< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texelFetch( s
								, test::getDefault< FetchT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texelFetchOffset( s
								, test::getDefault< FetchT >( writer.getShader() )
								, 1_i
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() )
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< OffsetT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureLodOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, 1.0_f
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureLodOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjLod( s
								, test::getDefault< SampleProjT >( writer.getShader() )
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjLod( s
								, test::getDefault< SampleProjT >( writer.getShader() )
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjLodOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, 1.0_f
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjLodOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, 0.5_f
								, 1.0_f
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGrad( s
								, test::getDefault< SampleT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGrad( s
								, test::getDefault< SampleT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGradOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGradOffset( s
								, test::getDefault< SampleT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjGrad( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjGrad( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjGradOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureProjGradOffset( s
								, test::getDefault< SampleProjT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< DerivativeT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGather( s
								, test::getDefault< GatherT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGather( s
								, test::getDefault< GatherT >( writer.getShader() )
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
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGather( s
								, test::getDefault< GatherT >( writer.getShader() )
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
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGatherOffset( s
								, test::getDefault< GatherT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGatherOffset( s
								, test::getDefault< GatherT >( writer.getShader() )
								, 0.5_f
								, test::getDefault< OffsetT >( writer.getShader() ) ) );
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
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGatherOffset( s
								, test::getDefault< GatherT >( writer.getShader() )
								, test::getDefault< OffsetT >( writer.getShader() )
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
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
					, test::getDefaultVector< OffsetT >( writer.getShader(), 4u ) );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGatherOffsets( s
								, test::getDefault< GatherT >( writer.getShader() )
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
		, std::enable_if_t< is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
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
					, test::getDefaultVector< OffsetT >( writer.getShader(), 4u ) );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGatherOffsets( s
								, test::getDefault< GatherT >( writer.getShader() )
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
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
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
					, test::getDefaultVector< OffsetT >( writer.getShader(), 4u ) );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, textureGatherOffsets( s
								, test::getDefault< GatherT >( writer.getShader() )
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
	template< ast::type::ImageFormat FormatT, template< ast::type::ImageFormat, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsTexture( test::sdw_test::TestCounts & testCounts )
	{
		if ( isFloatFormat( FormatT ) )
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
		else if ( isSIntFormat( FormatT ) )
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
		else if ( isUIntFormat( FormatT ) )
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
	template< template< ast::type::ImageFormat, ast::type::ImageDim, bool, bool, bool > typename TesterT >
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

int main( int argc, char ** argv )
{
	sdwTestSuiteBegin( "TestWriterTextureAccesses" );
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
}
