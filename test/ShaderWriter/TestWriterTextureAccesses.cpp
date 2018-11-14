#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

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
	static bool constexpr isRect = ( !DepthT ) && ( !ArrayedT ) && ( DimT == ast::type::ImageDim::eRect );
	
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureSizeTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester< SampledT, DimT, ArrayedT, DepthT, MsT
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
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureSizeLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureSizeTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< isBuffer< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureSize" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureQueryLodTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureQueryLodTester< SampledT, DimT, ArrayedT, DepthT, MsT
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

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureQueryLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureQueryLevelsTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureQueryLevelsTester< SampledT, DimT, ArrayedT, DepthT, MsT
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
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureQueryLevels" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTexture" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureShadow" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureBiasTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureBiasTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureBiasTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProj" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadow" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjBiasTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjBiasTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjBiasTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureLodTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureLodShadow" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureOffsetShadow" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureOffsetBiasTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetBiasTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureOffsetBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureOffsetBiasTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureOffsetShadowBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TexelFetchTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TexelFetchTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TexelFetchTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< isRect< DimT, ArrayedT, DepthT >
			|| isBuffer< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTexelFetch" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TexelFetchOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TexelFetchOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchOffsetLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texelFetchOffset( s
								, test::getDefault< FetchT >( writer.getShader() )
								, 1_i
								, 0_i ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TexelFetchOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< isRect< DimT, ArrayedT, DepthT > > >
	{
		using FetchT = typename sdw::SampledImageFetchT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTexelFetchOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto c = writer.declLocale( "c"
							, texelFetchOffset( s
								, test::getDefault< FetchT >( writer.getShader() )
								, 0_i ) );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffsetShadow" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjOffsetBiasTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetBiasTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffsetBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjOffsetBiasTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjOffsetShadowBias" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureLodOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodOffsetTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureLodOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureLodOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureLodShadowOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjLodTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowLod" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjLodOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjLodOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjLodOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowLodOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGradTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGrad" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowGrad" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGradOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradOffsetTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| is1DArray< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGradOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGradOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is1DArrayShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleT = typename sdw::SampledImageSampleT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureShadowGradOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjGradTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjGrad" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowGrad" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureProjGradOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradOffsetTester < SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1D< DimT, ArrayedT, DepthT >
			|| is2D< DimT, ArrayedT, DepthT >
			|| is3D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjGradOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureProjGradOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is1DShadow< DimT, ArrayedT, DepthT >
			|| is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT > > >
	{
		using SampleProjT = typename sdw::SampledImageSampleProjT< DimT, ArrayedT >;
		using DerivativeT = typename sdw::SampledImageDerivativeT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureProjShadowGradOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGather" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2DShadow< DimT, ArrayedT, DepthT >
			|| isCubeShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT >
			|| isCubeArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadow" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherCompTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherCompTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| isCube< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT >
			|| isCubeArray< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherComp" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherOffsetTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowOffset" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherOffsetCompTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetCompTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsetComp" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherOffsetsTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetsTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsets" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetsTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2DShadow< DimT, ArrayedT, DepthT >
			|| isRectShadow< DimT, ArrayedT, DepthT >
			|| is2DArrayShadow< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherShadowOffsets" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
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
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct TextureGatherOffsetsCompTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct TextureGatherOffsetsCompTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< is2D< DimT, ArrayedT, DepthT >
			|| isRect< DimT, ArrayedT, DepthT >
			|| is2DArray< DimT, ArrayedT, DepthT > > >
	{
		using GatherT = typename sdw::SampledImageGatherT< DimT, ArrayedT >;
		using OffsetT = typename sdw::SampledImageOffsetT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testTextureGatherOffsetsComp" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, DepthT, MsT );
			testBegin( name );
			using namespace sdw;
			{
				FragmentWriter writer{ false };
				auto s = writer.declSampledImage< SampledT, DimT, ArrayedT, DepthT, MsT >( "s", 0u, 0u );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto offsets = writer.declLocaleArray< OffsetT >( "offsets", 4u );
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
	template< template< ast::type::Kind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsTexture( test::TestCounts & testCounts )
	{
		for ( uint32_t i = 0u; i <= uint32_t( ast::type::ImageFormat::eR8u ); ++i )
		{
			auto format = ast::type::ImageFormat( i );

			if ( isFloatFormat( format ) )
			{
				TesterT< FImg1D >::test( format, testCounts );
				TesterT< FImg2D >::test( format, testCounts );
				TesterT< FImg3D >::test( format, testCounts );
				TesterT< FImgRect >::test( format, testCounts );
				TesterT< FImgCube >::test( format, testCounts );
				TesterT< FImgBuffer >::test( format, testCounts );
				TesterT< FImg1DArray >::test( format, testCounts );
				TesterT< FImg2DArray >::test( format, testCounts );
				TesterT< FImgCubeArray >::test( format, testCounts );
				TesterT< FImg1DShadow >::test( format, testCounts );
				TesterT< FImg2DShadow >::test( format, testCounts );
				TesterT< FImgRectShadow >::test( format, testCounts );
				TesterT< FImgCubeShadow >::test( format, testCounts );
				TesterT< FImg1DArrayShadow >::test( format, testCounts );
				TesterT< FImg2DArrayShadow >::test( format, testCounts );
				TesterT< FImgCubeArrayShadow >::test( format, testCounts );
			}
			else if ( isSIntFormat( format ) )
			{
				TesterT< IImg1D >::test( format, testCounts );
				TesterT< IImg2D >::test( format, testCounts );
				TesterT< IImg3D >::test( format, testCounts );
				TesterT< IImgRect >::test( format, testCounts );
				TesterT< IImgCube >::test( format, testCounts );
				TesterT< IImgBuffer >::test( format, testCounts );
				TesterT< IImg1DArray >::test( format, testCounts );
				TesterT< IImg2DArray >::test( format, testCounts );
				TesterT< IImgCubeArray >::test( format, testCounts );
			}
			else if ( isUIntFormat( format ) )
			{
				TesterT< UImg1D >::test( format, testCounts );
				TesterT< UImg2D >::test( format, testCounts );
				TesterT< UImg3D >::test( format, testCounts );
				TesterT< UImgRect >::test( format, testCounts );
				TesterT< UImgCube >::test( format, testCounts );
				TesterT< UImgBuffer >::test( format, testCounts );
				TesterT< UImg1DArray >::test( format, testCounts );
				TesterT< UImg2DArray >::test( format, testCounts );
				TesterT< UImgCubeArray >::test( format, testCounts );
			}
		}
	}
	/**@}*/
#pragma endregion
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterTextureAccesses" );
	testsTexture< TextureSizeTester >( testCounts );
	testsTexture< TextureQueryLodTester >( testCounts );
	testsTexture< TextureQueryLevelsTester >( testCounts );
	testsTexture< TextureTester >( testCounts );
	testsTexture< TextureBiasTester >( testCounts );
	testsTexture< TextureProjTester >( testCounts );
	testsTexture< TextureProjBiasTester >( testCounts );
	testsTexture< TextureLodTester >( testCounts );
	testsTexture< TextureOffsetTester >( testCounts );
	testsTexture< TextureOffsetBiasTester >( testCounts );
	testsTexture< TexelFetchTester >( testCounts );
	testsTexture< TexelFetchOffsetTester >( testCounts );
	testsTexture< TextureProjOffsetTester >( testCounts );
	testsTexture< TextureProjOffsetBiasTester >( testCounts );
	testsTexture< TextureLodOffsetTester >( testCounts );
	testsTexture< TextureProjLodTester >( testCounts );
	testsTexture< TextureProjLodOffsetTester >( testCounts );
	testsTexture< TextureGradTester >( testCounts );
	testsTexture< TextureGradOffsetTester >( testCounts );
	testsTexture< TextureProjGradTester >( testCounts );
	testsTexture< TextureProjGradOffsetTester >( testCounts );
	testsTexture< TextureGatherTester >( testCounts );
	testsTexture< TextureGatherCompTester >( testCounts );
	testsTexture< TextureGatherOffsetTester >( testCounts );
	testsTexture< TextureGatherOffsetCompTester >( testCounts );
	testsTexture< TextureGatherOffsetsTester >( testCounts );
	testsTexture< TextureGatherOffsetsCompTester >( testCounts );
	testSuiteEnd();
}
