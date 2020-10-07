#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< ast::type::AccessKind AccessT >
	static constexpr bool isReadableV{ AccessT == ast::type::AccessKind::eRead || AccessT == ast::type::AccessKind::eReadWrite };

	template< ast::type::AccessKind AccessT >
	static constexpr bool isWritableV{ AccessT == ast::type::AccessKind::eWrite || AccessT == ast::type::AccessKind::eReadWrite };

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSizeTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageSize" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSize( s ) );
					} );
				test::writeShader( writer
					, testCounts
					, true, false, false );
				test::writeShader( writer
					, testCounts
					, false, true, true );
				test::validateShader( writer.getShader()
					, testCounts );
			}
			testEnd();
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSamplesTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( MsT )
			{
				auto name = "testImageSamples" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							auto i = writer.declLocale( "i", imageSamples( s ) );
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageLoadTester
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( isReadableV< AccessT > )
			{
				auto name = "testImageLoad" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageLoad( s
									, test::getDefault< Coords >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageLoad( s
									, test::getDefault< Coords >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageStoreTester
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;
		using Sample = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( isWritableV< AccessT > )
			{
				auto name = "testImageStore" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								imageStore( s
									, test::getDefault< Coords >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< Sample >( writer.getShader() ) );
							}
							else
							{
								imageStore( s
									, test::getDefault< Coords >( writer.getShader() )
									, test::getDefault< Sample >( writer.getShader() ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicAddTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( isFloatFormat( FormatT )
					|| FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicAdd" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicAdd( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicAdd( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );

					if constexpr ( !isFloatFormat( FormatT ) )
					{
						test::writeShader( writer
							, testCounts
							, true, false, false );
						test::validateShader( writer.getShader()
							, testCounts );
					}

					test::writeShader( writer
						, testCounts
						, false, ( FormatT == ast::type::ImageFormat::eR32i || FormatT == ast::type::ImageFormat::eR32u ), true );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicMinTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicMin" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicMin( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicMin( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicMaxTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicMax" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicMax( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicMax( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicAndTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicAnd" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicAnd( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicAnd( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicOrTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicOr" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicOr( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicOr( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicXorTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicXor" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicXor( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicXor( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicExchangeTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( isFloatFormat( FormatT )
					|| FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicExchange" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicExchange( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicExchange( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );

					if constexpr ( !isFloatFormat( FormatT ) )
					{
						test::writeShader( writer
							, testCounts
							, true, false, false );
						test::validateShader( writer.getShader()
							, testCounts );
					}

					test::writeShader( writer
						, testCounts
						, false, ( FormatT == ast::type::ImageFormat::eR32i || FormatT == ast::type::ImageFormat::eR32u ), true );
				}
				testEnd();
			}
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageAtomicCompSwapTester
	{
		using CoordsT = sdw::ImageCoordsT< DimT, ArrayedT >;
		using SampleT = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			if constexpr ( AccessT == ast::type::AccessKind::eReadWrite
				&& ( FormatT == ast::type::ImageFormat::eR32i
					|| FormatT == ast::type::ImageFormat::eR32u ) )
			{
				auto name = "testImageAtomicCompSwap" + sdw::debug::getName( FormatT, AccessT, DimT, ArrayedT, false, MsT );
				testBegin( name );
				using namespace sdw;
				{
					ComputeWriter writer;
					auto s = writer.declImage< FormatT, AccessT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
					writer.inputLayout( 1u );
					writer.implementFunction< sdw::Void >( "main"
						, [&]()
						{
							if constexpr ( MsT )
							{
								auto i = writer.declLocale( "i", imageAtomicCompSwap( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< sdw::Int >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
							else
							{
								auto i = writer.declLocale( "i", imageAtomicCompSwap( s
									, test::getDefault< CoordsT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() )
									, test::getDefault< SampleT >( writer.getShader() ) ) );
							}
						} );
					test::writeShader( writer
						, testCounts
						, true, false, false );
					test::writeShader( writer
						, testCounts
						, false, true, true );
					test::validateShader( writer.getShader()
						, testCounts );
				}
				testEnd();
			}
		};
	};

	template< ast::type::AccessKind AccessT
		, ast::type::ImageFormat FormatT
		, template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageFormats( test::sdw_test::TestCounts & testCounts )
	{
		if constexpr ( isFloatFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1D >::test( testCounts );
			TesterT< FormatT, AccessT, Img2D >::test( testCounts );
			TesterT< FormatT, AccessT, Img3D >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCube >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArray >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArray >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArray >::test( testCounts );

			if constexpr ( FormatT == ast::type::ImageFormat::eR32f
				|| FormatT == ast::type::ImageFormat::eR16f )
			{
				TesterT< FormatT, AccessT, Img1DShadow >::test( testCounts );
				TesterT< FormatT, AccessT, Img2DShadow >::test( testCounts );
				TesterT< FormatT, AccessT, ImgCubeShadow >::test( testCounts );
				TesterT< FormatT, AccessT, Img1DArrayShadow >::test( testCounts );
				TesterT< FormatT, AccessT, Img2DArrayShadow >::test( testCounts );
				TesterT< FormatT, AccessT, ImgCubeArrayShadow >::test( testCounts );
			}
		}
		else if constexpr ( isSIntFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1D >::test( testCounts );
			TesterT< FormatT, AccessT, Img2D >::test( testCounts );
			TesterT< FormatT, AccessT, Img3D >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCube >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArray >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArray >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArray >::test( testCounts );
		}
		else if constexpr ( isUIntFormat( FormatT ) )
		{
			TesterT< FormatT, AccessT, Img1D >::test( testCounts );
			TesterT< FormatT, AccessT, Img2D >::test( testCounts );
			TesterT< FormatT, AccessT, Img3D >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCube >::test( testCounts );
			TesterT< FormatT, AccessT, ImgBuffer >::test( testCounts );
			TesterT< FormatT, AccessT, Img1DArray >::test( testCounts );
			TesterT< FormatT, AccessT, Img2DArray >::test( testCounts );
			TesterT< FormatT, AccessT, ImgCubeArray >::test( testCounts );
		}
	}

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImage( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eRead, ast::type::ImageFormat::eR8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eWrite, ast::type::ImageFormat::eR8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR8u, TesterT >( testCounts );
	}

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageAtomic( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::AccessKind::eReadWrite, ast::type::ImageFormat::eR32u, TesterT >( testCounts );
	}
}

int main( int argc, char ** argv )
{
#if !defined( __APPLE__ )

	sdwTestSuiteBegin( "TestWriterImageAccesses" );
	testsImage< ImageSizeTester >( testCounts );
	testsImage< ImageSamplesTester >( testCounts );
	testsImage< ImageLoadTester >( testCounts );
	testsImage< ImageStoreTester >( testCounts );
	testsImageAtomic< ImageAtomicAddTester >( testCounts );
	testsImageAtomic< ImageAtomicMinTester >( testCounts );
	testsImageAtomic< ImageAtomicMaxTester >( testCounts );
	testsImageAtomic< ImageAtomicAndTester >( testCounts );
	testsImageAtomic< ImageAtomicOrTester >( testCounts );
	testsImageAtomic< ImageAtomicXorTester >( testCounts );
	testsImageAtomic< ImageAtomicExchangeTester >( testCounts );
	testsImageAtomic< ImageAtomicCompSwapTester >( testCounts );
	sdwTestSuiteEnd();

#endif
}
