#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSizeTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageSize" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSize( s ) );
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
	struct ImageSamplesTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageSamples" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSamples( s ) );
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
		, bool DepthT >
	struct ImageSamplesTester< FormatT, DimT, ArrayedT, DepthT, false >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageLoadTester
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
	struct ImageLoadTester< FormatT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageLoad" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ) ) );
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
	struct ImageLoadTester< FormatT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageLoad" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ), 0_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAddTester
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
	struct ImageIAtomicAddTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicAddTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAddTester
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
	struct ImageUAtomicAddTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicAddTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMinTester
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
	struct ImageIAtomicMinTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicMinTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMinTester
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
	struct ImageUAtomicMinTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicMinTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMaxTester
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
	struct ImageIAtomicMaxTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicMaxTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMaxTester
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
	struct ImageUAtomicMaxTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicMaxTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAndTester
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
	struct ImageIAtomicAndTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicAndTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAndTester
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
	struct ImageUAtomicAndTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicAndTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicOrTester
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
	struct ImageIAtomicOrTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicOrTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicOrTester
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
	struct ImageUAtomicOrTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicOrTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicXorTester
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
	struct ImageIAtomicXorTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicXorTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicXorTester
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
	struct ImageUAtomicXorTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicXorTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicExchangeTester
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
	struct ImageIAtomicExchangeTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
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
	struct ImageIAtomicExchangeTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicExchangeTester
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
	struct ImageUAtomicExchangeTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
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
	struct ImageUAtomicExchangeTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicCompSwapTester
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
	struct ImageIAtomicCompSwapTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_i, 3_i ) );
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
	struct ImageIAtomicCompSwapTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i, 3_i ) );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicCompSwapTester
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
	struct ImageUAtomicCompSwapTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_u, 3_u ) );
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
	struct ImageUAtomicCompSwapTester< FormatT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( FormatT, DimT, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer;
				auto s = writer.declImage< FormatT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u );
				writer.inputLayout( 1u );
				writer.implementFunction< sdw::Void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u, 3_u ) );
					} );
				test::writeShader( writer
					, testCounts );
			}
			testEnd();
		};
	};

	template< ast::type::ImageFormat FormatT
		, template< ast::type::Kind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageFormats( test::sdw_test::TestCounts & testCounts )
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
	void testsImage( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::ImageFormat::eRgba32f, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba16f, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg32f, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg16f, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR32f, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR16f, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba32i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba16i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba8i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg32i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg16i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg8i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR16i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR8i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba32u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba16u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRgba8u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg32u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg16u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eRg8u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR32u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR16u, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR8u, TesterT >( testCounts );
	}

	template< template< ast::type::ImageFormat, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageAtomic( test::sdw_test::TestCounts & testCounts )
	{
		testsImageFormats< ast::type::ImageFormat::eR32i, TesterT >( testCounts );
		testsImageFormats< ast::type::ImageFormat::eR32u, TesterT >( testCounts );
	}
}

int main( int argc, char ** argv )
{
	sdwTestSuiteBegin( "TestWriterImageAccesses" );
	testsImage< ImageSizeTester >( testCounts );
	testsImage< ImageSamplesTester >( testCounts );
	testsImage< ImageLoadTester >( testCounts );
	testsImageAtomic< ImageIAtomicAddTester >( testCounts );
	testsImageAtomic< ImageUAtomicAddTester >( testCounts );
	testsImageAtomic< ImageIAtomicMinTester >( testCounts );
	testsImageAtomic< ImageUAtomicMinTester >( testCounts );
	testsImageAtomic< ImageIAtomicMaxTester >( testCounts );
	testsImageAtomic< ImageUAtomicMaxTester >( testCounts );
	testsImageAtomic< ImageIAtomicAndTester >( testCounts );
	testsImageAtomic< ImageUAtomicAndTester >( testCounts );
	testsImageAtomic< ImageIAtomicOrTester >( testCounts );
	testsImageAtomic< ImageUAtomicOrTester >( testCounts );
	testsImageAtomic< ImageIAtomicXorTester >( testCounts );
	testsImageAtomic< ImageUAtomicXorTester >( testCounts );
	testsImageAtomic< ImageIAtomicExchangeTester >( testCounts );
	testsImageAtomic< ImageUAtomicExchangeTester >( testCounts );
	testsImageAtomic< ImageIAtomicCompSwapTester >( testCounts );
	testsImageAtomic< ImageUAtomicCompSwapTester >( testCounts );
	sdwTestSuiteEnd();
}
