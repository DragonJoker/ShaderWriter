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
		, bool MsT
		, typename Enable = void >
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
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageSamplesTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
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
					, testCounts );
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
	struct ImageSamplesTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		};
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
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
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageLoadTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && isReadableV< AccessT > > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ) ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageLoadTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && isReadableV< AccessT > > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ), 0_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageStoreTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageStoreTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && isWritableV< AccessT > > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;
		using Sample = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						imageStore( s
							, test::getDefault< Coords >( writer.getShader() )
							, test::getDefault< Sample >( writer.getShader() ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageStoreTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && isWritableV< AccessT > > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;
		using Sample = sdw::ImageSampleT< FormatT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						imageStore( s
							, test::getDefault< Coords >( writer.getShader() )
							, test::getDefault< sdw::Int >( writer.getShader() )
							, test::getDefault< Sample >( writer.getShader() ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAddTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAddTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicAddTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAddTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAddTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicAddTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMinTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMinTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicMinTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMinTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMinTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicMinTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMaxTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMaxTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicMaxTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMaxTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMaxTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicMaxTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAndTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAndTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicAndTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAndTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAndTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicAndTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicOrTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicOrTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicOrTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicOrTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicOrTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicOrTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicXorTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicXorTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicXorTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicXorTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicXorTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicXorTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicExchangeTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicExchangeTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicExchangeTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicExchangeTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicExchangeTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicExchangeTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicCompSwapTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicCompSwapTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_i, 3_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageIAtomicCompSwapTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32i && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i, 3_i ) );
					} );
				test::writeShader( writer
					, testCounts );
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
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicCompSwapTester
	{
		static void test( test::sdw_test::TestCounts & testCounts )
		{
		}
	};

	template< ast::type::ImageFormat FormatT
		, ast::type::AccessKind AccessT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicCompSwapTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_u, 3_u ) );
					} );
				test::writeShader( writer
					, testCounts );
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
	struct ImageUAtomicCompSwapTester< FormatT, AccessT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && FormatT == ast::type::ImageFormat::eR32u && AccessT == ast::type::AccessKind::eReadWrite > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( test::sdw_test::TestCounts & testCounts )
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
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u, 3_u ) );
					} );
				test::writeShader( writer
					, testCounts );
				test::validateShader( writer.getShader()
					, testCounts );
			}
			testEnd();
		};
	};

	template< ast::type::AccessKind AccessT
		, ast::type::ImageFormat FormatT
		, template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool, typename Enable = void > typename TesterT >
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

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool, typename Enable > typename TesterT >
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

	template< template< ast::type::ImageFormat, ast::type::AccessKind, ast::type::ImageDim, bool, bool, bool, typename Enable > typename TesterT >
	void testsImageAtomic( test::sdw_test::TestCounts & testCounts )
	{
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

#endif
}
