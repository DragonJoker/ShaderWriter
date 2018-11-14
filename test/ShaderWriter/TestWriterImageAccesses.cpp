#include "../Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/WriterGlsl.hpp>
#include <ShaderWriter/WriterHlsl.hpp>
#include <ShaderWriter/WriterSpirV.hpp>

namespace
{
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSizeTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageSize" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageSamplesTester
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageSamples" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT >
	struct ImageSamplesTester< SampledT, DimT, ArrayedT, DepthT, false >
	{
		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
		};
	};

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageLoadTester
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
	struct ImageLoadTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageLoad" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageLoadTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageLoad" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAddTester
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
	struct ImageIAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAddTester
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
	struct ImageUAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMinTester
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
	struct ImageIAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMinTester
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
	struct ImageUAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicMaxTester
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
	struct ImageIAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicMaxTester
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
	struct ImageUAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicAndTester
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
	struct ImageIAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicAndTester
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
	struct ImageUAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicOrTester
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
	struct ImageIAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicOrTester
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
	struct ImageUAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicXorTester
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
	struct ImageIAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicXorTester
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
	struct ImageUAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicExchangeTester
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
	struct ImageIAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicExchangeTester
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
	struct ImageUAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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
	
	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageIAtomicCompSwapTester
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
	struct ImageIAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT
		, typename Enable = void >
	struct ImageUAtomicCompSwapTester
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
	struct ImageUAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< !MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT
		, std::enable_if_t< MsT && SampledT == ast::type::Kind::eUInt > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ComputeWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.inputLayout( 1u );
				writer.implementFunction< void >( "main"
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

	template< template< ast::type::Kind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageFormats( test::TestCounts & testCounts
		, std::vector< ast::type::ImageFormat > const & formats )
	{
		for ( auto format : formats )
		{
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

	template< template< ast::type::Kind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImage( test::TestCounts & testCounts )
	{
		static std::vector< ast::type::ImageFormat > const formats
		{
			ast::type::ImageFormat::eUnknown,
			ast::type::ImageFormat::eRgba32f,
			ast::type::ImageFormat::eRgba16f,
			ast::type::ImageFormat::eRg32f,
			ast::type::ImageFormat::eRg16f,
			ast::type::ImageFormat::eR32f,
			ast::type::ImageFormat::eR16f,
			ast::type::ImageFormat::eRgba32i,
			ast::type::ImageFormat::eRgba16i,
			ast::type::ImageFormat::eRgba8i,
			ast::type::ImageFormat::eRg32i,
			ast::type::ImageFormat::eRg16i,
			ast::type::ImageFormat::eRg8i,
			ast::type::ImageFormat::eR32i,
			ast::type::ImageFormat::eR16i,
			ast::type::ImageFormat::eR8i,
			ast::type::ImageFormat::eRgba32u,
			ast::type::ImageFormat::eRgba16u,
			ast::type::ImageFormat::eRgba8u,
			ast::type::ImageFormat::eRg32u,
			ast::type::ImageFormat::eRg16u,
			ast::type::ImageFormat::eRg8u,
			ast::type::ImageFormat::eR32u,
			ast::type::ImageFormat::eR16u,
			ast::type::ImageFormat::eR8u,
		};
		testsImageFormats< TesterT >( testCounts, formats );
	}

	template< template< ast::type::Kind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImageAtomic( test::TestCounts & testCounts )
	{
		static std::vector< ast::type::ImageFormat > const formats
		{
			ast::type::ImageFormat::eR32i,
			ast::type::ImageFormat::eR32u,
		};
		testsImageFormats< TesterT >( testCounts, formats );
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterImageAccesses" );
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
	testSuiteEnd();
}
