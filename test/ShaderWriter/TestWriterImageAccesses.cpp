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
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSize( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageSamples( s ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageLoadTester;

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
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ) ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageLoad( s, test::getDefault< Coords >( writer.getShader() ), 0_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicAddTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicAddTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicAddTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAdd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAdd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicMinTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicMinTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicMinTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMin" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMin( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicMaxTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicMaxTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicMaxTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicMax" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicMax( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicAndTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicAndTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicAndTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicAnd" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicAnd( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicOrTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicOrTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicOrTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicOr" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicOr( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicXorTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicXorTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicXorTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicXor" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicXor( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicExchangeTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicExchangeTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicExchangeTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicExchange" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicExchange( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicCompSwapTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageIAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_i, 3_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageIAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_i, 3_i ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicCompSwapTester;

	template< ast::type::Kind SampledT
		, ast::type::ImageDim DimT
		, bool ArrayedT
		, bool DepthT
		, bool MsT >
	struct ImageUAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< !MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 2_u, 3_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
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
	struct ImageUAtomicCompSwapTester< SampledT, DimT, ArrayedT, DepthT, MsT, std::enable_if_t< MsT > >
	{
		using Coords = sdw::ImageCoordsT< DimT, ArrayedT >;

		static void test( ast::type::ImageFormat format, test::TestCounts & testCounts )
		{
			auto name = "testImageAtomicCompSwap" + sdw::debug::getName( SampledT, DimT, format, ArrayedT, false, MsT );
			testBegin( name );
			using namespace sdw;
			{
				ShaderWriter writer{ false };
				auto s = writer.declImage< SampledT, DimT, ArrayedT, false, MsT >( "s", 0u, 0u, format );
				writer.implementFunction< void >( "main"
					, [&]()
					{
						auto i = writer.declLocale( "i", imageAtomicCompSwap( s, test::getDefault< Coords >( writer.getShader() ), 0_i, 2_u, 3_u ) );
					} );
				test::writeShader( writer.getShader()
					, sdw::ShaderType::eFragment
					, testCounts );
			}
			testEnd();
		};
	};

	template< template< ast::type::Kind, ast::type::ImageDim, bool, bool, bool > typename TesterT >
	void testsImage( test::TestCounts & testCounts )
	{
		for ( uint32_t i = 0u; i <= uint32_t( ast::type::ImageFormat::eR8u ); ++i )
		{
			auto format = ast::type::ImageFormat( i );
			TesterT< FImg1D >::test( format, testCounts );
			TesterT< FImg2D >::test( format, testCounts );
			TesterT< FImg3D >::test( format, testCounts );
			TesterT< FImgRect >::test( format, testCounts );
			TesterT< FImgCube >::test( format, testCounts );
			TesterT< FImgBuffer >::test( format, testCounts );
			TesterT< FImg1DArray >::test( format, testCounts );
			TesterT< FImg2DArray >::test( format, testCounts );
			TesterT< FImgCubeArray >::test( format, testCounts );
			TesterT< FImg2DMS >::test( format, testCounts );
			TesterT< FImg2DMSArray >::test( format, testCounts );

			TesterT< IImg1D >::test( format, testCounts );
			TesterT< IImg2D >::test( format, testCounts );
			TesterT< IImg3D >::test( format, testCounts );
			TesterT< IImgRect >::test( format, testCounts );
			TesterT< IImgCube >::test( format, testCounts );
			TesterT< IImgBuffer >::test( format, testCounts );
			TesterT< IImg1DArray >::test( format, testCounts );
			TesterT< IImg2DArray >::test( format, testCounts );
			TesterT< IImgCubeArray >::test( format, testCounts );
			TesterT< IImg2DMS >::test( format, testCounts );
			TesterT< IImg2DMSArray >::test( format, testCounts );

			TesterT< UImg1D >::test( format, testCounts );
			TesterT< UImg2D >::test( format, testCounts );
			TesterT< UImg3D >::test( format, testCounts );
			TesterT< UImgRect >::test( format, testCounts );
			TesterT< UImgCube >::test( format, testCounts );
			TesterT< UImgBuffer >::test( format, testCounts );
			TesterT< UImg1DArray >::test( format, testCounts );
			TesterT< UImg2DArray >::test( format, testCounts );
			TesterT< UImgCubeArray >::test( format, testCounts );
			TesterT< UImg2DMS >::test( format, testCounts );
			TesterT< UImg2DMSArray >::test( format, testCounts );
		}
	}
}

int main( int argc, char ** argv )
{
	testSuiteBegin( "TestWriterImageAccesses" );
	testsImage< ImageSizeTester >( testCounts );
	testsImage< ImageSamplesTester >( testCounts );
	testsImage< ImageLoadTester >( testCounts );
	testsImage< ImageIAtomicAddTester >( testCounts );
	testsImage< ImageUAtomicAddTester >( testCounts );
	testsImage< ImageIAtomicMinTester >( testCounts );
	testsImage< ImageUAtomicMinTester >( testCounts );
	testsImage< ImageIAtomicMaxTester >( testCounts );
	testsImage< ImageUAtomicMaxTester >( testCounts );
	testsImage< ImageIAtomicAndTester >( testCounts );
	testsImage< ImageUAtomicAndTester >( testCounts );
	testsImage< ImageIAtomicOrTester >( testCounts );
	testsImage< ImageUAtomicOrTester >( testCounts );
	testsImage< ImageIAtomicXorTester >( testCounts );
	testsImage< ImageUAtomicXorTester >( testCounts );
	testsImage< ImageIAtomicExchangeTester >( testCounts );
	testsImage< ImageUAtomicExchangeTester >( testCounts );
	testsImage< ImageIAtomicCompSwapTester >( testCounts );
	testsImage< ImageUAtomicCompSwapTester >( testCounts );
	testSuiteEnd();
}
