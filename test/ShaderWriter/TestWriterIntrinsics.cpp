#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void testRoundEven1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPackDouble2x32( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackDouble2x32" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UVec2 >( "v" );
					auto r = writer.declLocale< Double >( "r" );
					r = packDouble2x32( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPackHalf2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackHalf2x16" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packHalf2x16( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPackSnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackSnorm2x16" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPackUnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackUnorm2x16" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPackSnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackSnorm4x8" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPackUnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackUnorm4x8" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUnpackDouble2x32( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackDouble2x32" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					auto r = writer.declLocale< UVec2 >( "r" );
					r = unpackDouble2x32( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUnpackHalf2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackHalf2x16" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackHalf2x16( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUnpackSnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackSnorm2x16" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackSnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUnpackUnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackUnorm2x16" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackUnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUnpackSnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackSnorm4x8" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackSnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUnpackUnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackUnorm4x8" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackUnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	template< typename ValueT >
	void testLessThan( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThan( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testLessThan2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2F" );
		testLessThan< sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThan3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3F" );
		testLessThan< sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThan4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4F" );
		testLessThan< sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testLessThan2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2D" );
		testLessThan< sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThan3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3D" );
		testLessThan< sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThan4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4D" );
		testLessThan< sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testLessThan2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2I" );
		testLessThan< sdw::IVec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThan3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3I" );
		testLessThan< sdw::IVec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThan4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4I" );
		testLessThan< sdw::IVec4 >( testName, testCounts );
		testEnd();
	}

	void testLessThan2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan2U" );
		testLessThan< sdw::UVec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThan3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan3U" );
		testLessThan< sdw::UVec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThan4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan4U" );
		testLessThan< sdw::UVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testLessThanEqual( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testLessThanEqual2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2F" );
		testLessThanEqual< sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3F" );
		testLessThanEqual< sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4F" );
		testLessThanEqual< sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2D" );
		testLessThanEqual< sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3D" );
		testLessThanEqual< sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4D" );
		testLessThanEqual< sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2I" );
		testLessThanEqual< sdw::IVec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3I" );
		testLessThanEqual< sdw::IVec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4I" );
		testLessThanEqual< sdw::IVec4 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual2U" );
		testLessThanEqual< sdw::UVec2 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual3U" );
		testLessThanEqual< sdw::UVec3 >( testName, testCounts );
		testEnd();
	}

	void testLessThanEqual4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual4U" );
		testLessThanEqual< sdw::UVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testGreaterThan( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThan( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testGreaterThan2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2F" );
		testGreaterThan< sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3F" );
		testGreaterThan< sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4F" );
		testGreaterThan< sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2D" );
		testGreaterThan< sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3D" );
		testGreaterThan< sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4D" );
		testGreaterThan< sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2I" );
		testGreaterThan< sdw::IVec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3I" );
		testGreaterThan< sdw::IVec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4I" );
		testGreaterThan< sdw::IVec4 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan2U" );
		testGreaterThan< sdw::UVec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan3U" );
		testGreaterThan< sdw::UVec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThan4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan4U" );
		testGreaterThan< sdw::UVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testGreaterThanEqual( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testGreaterThanEqual2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2F" );
		testGreaterThanEqual< sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3F" );
		testGreaterThanEqual< sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4F" );
		testGreaterThanEqual< sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2D" );
		testGreaterThanEqual< sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3D" );
		testGreaterThanEqual< sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4D" );
		testGreaterThanEqual< sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2I" );
		testGreaterThanEqual< sdw::IVec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3I" );
		testGreaterThanEqual< sdw::IVec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4I" );
		testGreaterThanEqual< sdw::IVec4 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual2U" );
		testGreaterThanEqual< sdw::UVec2 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual3U" );
		testGreaterThanEqual< sdw::UVec3 >( testName, testCounts );
		testEnd();
	}

	void testGreaterThanEqual4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual4U" );
		testGreaterThanEqual< sdw::UVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testEqual( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, equal( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testEqual2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual2F" );
		testEqual< sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testEqual3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual3F" );
		testEqual< sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testEqual4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual4F" );
		testEqual< sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testEqual2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual2D" );
		testEqual< sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testEqual3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual3D" );
		testEqual< sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testEqual4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual4D" );
		testEqual< sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testEqual2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual2I" );
		testEqual< sdw::IVec2 >( testName, testCounts );
		testEnd();
	}

	void testEqual3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual3I" );
		testEqual< sdw::IVec3 >( testName, testCounts );
		testEnd();
	}

	void testEqual4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual4I" );
		testEqual< sdw::IVec4 >( testName, testCounts );
		testEnd();
	}

	void testEqual2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual2U" );
		testEqual< sdw::UVec2 >( testName, testCounts );
		testEnd();
	}

	void testEqual3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual3U" );
		testEqual< sdw::UVec3 >( testName, testCounts );
		testEnd();
	}

	void testEqual4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual4U" );
		testEqual< sdw::UVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testNotEqual( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, notEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testNotEqual2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2F" );
		testNotEqual< sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3F" );
		testNotEqual< sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4F" );
		testNotEqual< sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2D" );
		testNotEqual< sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3D" );
		testNotEqual< sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4D" );
		testNotEqual< sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2I" );
		testNotEqual< sdw::IVec2 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3I" );
		testNotEqual< sdw::IVec3 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4I" );
		testNotEqual< sdw::IVec4 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual2U" );
		testNotEqual< sdw::UVec2 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual3U" );
		testNotEqual< sdw::UVec3 >( testName, testCounts );
		testEnd();
	}

	void testNotEqual4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual4U" );
		testNotEqual< sdw::UVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testNot( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, binNot( operand ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testNot2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNot2" );
		testNot< sdw::BVec2 >( testName, testCounts );
		testEnd();
	}

	void testNot3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNot3" );
		testNot< sdw::BVec3 >( testName, testCounts );
		testEnd();
	}

	void testNot4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNot4" );
		testNot< sdw::BVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testMatrixCompMult( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, matrixCompMult( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testMatrixCompMult2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x2F" );
		testMatrixCompMult< sdw::Mat2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult2x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x3F" );
		testMatrixCompMult< sdw::Mat2x3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult2x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x4F" );
		testMatrixCompMult< sdw::Mat2x4 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult3x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x2F" );
		testMatrixCompMult< sdw::Mat3x2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult3x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x3F" );
		testMatrixCompMult< sdw::Mat3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult3x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x4F" );
		testMatrixCompMult< sdw::Mat3x4 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult4x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x2F" );
		testMatrixCompMult< sdw::Mat4x2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult4x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x3F" );
		testMatrixCompMult< sdw::Mat4x3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult4x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x4F" );
		testMatrixCompMult< sdw::Mat4 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult2x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x2D" );
		testMatrixCompMult< sdw::DMat2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult2x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x3D" );
		testMatrixCompMult< sdw::DMat2x3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult2x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult2x4D" );
		testMatrixCompMult< sdw::DMat2x4 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult3x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x2D" );
		testMatrixCompMult< sdw::DMat3x2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult3x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x3D" );
		testMatrixCompMult< sdw::DMat3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult3x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult3x4D" );
		testMatrixCompMult< sdw::DMat3x4 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult4x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x2D" );
		testMatrixCompMult< sdw::DMat4x2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult4x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x3D" );
		testMatrixCompMult< sdw::DMat4x3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixCompMult4x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult4x4D" );
		testMatrixCompMult< sdw::DMat4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testMatrixMult( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lhs * rhs );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testMatrixMult2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult2x2F" );
		testMatrixMult< sdw::Mat2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixMult3x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult3x3F" );
		testMatrixMult< sdw::Mat3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixMult4x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult4x4F" );
		testMatrixMult< sdw::Mat4 >( testName, testCounts );
		testEnd();
	}

	void testMatrixMult2x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult2x2D" );
		testMatrixMult< sdw::DMat2 >( testName, testCounts );
		testEnd();
	}

	void testMatrixMult3x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult3x3D" );
		testMatrixMult< sdw::DMat3 >( testName, testCounts );
		testEnd();
	}

	void testMatrixMult4x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult4x4D" );
		testMatrixMult< sdw::DMat4 >( testName, testCounts );
		testEnd();
	}

	void testInverse2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse2x2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat2 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverse2x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse2x2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat2 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverse3x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse3x3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat3 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverse3x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse3x3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat3 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverse4x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse4x4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat4 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverse4x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse4x4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat4 >( "m" );
					m = inverse( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUaddCarry1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto c = writer.declLocale< UInt >( "c" );
					auto r = writer.declLocale< UInt >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUaddCarry2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto c = writer.declLocale< UVec2 >( "c" );
					auto r = writer.declLocale< UVec2 >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUaddCarry3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto c = writer.declLocale< UVec3 >( "c" );
					auto r = writer.declLocale< UVec3 >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUaddCarry4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto c = writer.declLocale< UVec4 >( "c" );
					auto r = writer.declLocale< UVec4 >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUsubBorrow1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto b = writer.declLocale< UInt >( "b" );
					auto r = writer.declLocale< UInt >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUsubBorrow2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto b = writer.declLocale< UVec2 >( "b" );
					auto r = writer.declLocale< UVec2 >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUsubBorrow3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto b = writer.declLocale< UVec3 >( "b" );
					auto r = writer.declLocale< UVec3 >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUsubBorrow4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto b = writer.declLocale< UVec4 >( "b" );
					auto r = writer.declLocale< UVec4 >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUmulExtended1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto h = writer.declLocale< UInt >( "h" );
					auto l = writer.declLocale< UInt >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUmulExtended2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto h = writer.declLocale< UVec2 >( "h" );
					auto l = writer.declLocale< UVec2 >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUmulExtended3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto h = writer.declLocale< UVec3 >( "h" );
					auto l = writer.declLocale< UVec3 >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testUmulExtended4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto h = writer.declLocale< UVec4 >( "h" );
					auto l = writer.declLocale< UVec4 >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testImulExtended1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto y = writer.declLocale< Int >( "y" );
					auto h = writer.declLocale< Int >( "h" );
					auto l = writer.declLocale< Int >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testImulExtended2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto y = writer.declLocale< IVec2 >( "y" );
					auto h = writer.declLocale< IVec2 >( "h" );
					auto l = writer.declLocale< IVec2 >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testImulExtended3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto y = writer.declLocale< IVec3 >( "y" );
					auto h = writer.declLocale< IVec3 >( "h" );
					auto l = writer.declLocale< IVec3 >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testImulExtended4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto y = writer.declLocale< IVec4 >( "y" );
					auto h = writer.declLocale< IVec4 >( "h" );
					auto l = writer.declLocale< IVec4 >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, true
				, false );
		}
		testEnd();
	}

	void testBitfieldInsert1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto y = writer.declLocale< Int >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto y = writer.declLocale< IVec2 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto y = writer.declLocale< IVec3 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto y = writer.declLocale< IVec4 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto y = writer.declLocale< UInt >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto y = writer.declLocale< UVec2 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto y = writer.declLocale< UVec3 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldInsert4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto y = writer.declLocale< UVec4 >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldExtract4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}
}

int main( int argc, char ** argv )
{
	sdwTestSuiteBegin( "TestWriterIntrinsics" );
	testRoundEven1F( testCounts );
	testRoundEven2F( testCounts );
	testRoundEven3F( testCounts );
	testRoundEven4F( testCounts );
	testRoundEven1D( testCounts );
	testRoundEven2D( testCounts );
	testRoundEven3D( testCounts );
	testRoundEven4D( testCounts );
	testPackDouble2x32( testCounts );
	testPackHalf2x16( testCounts );
	testPackSnorm2x16( testCounts );
	testPackUnorm2x16( testCounts );
	testPackSnorm4x8( testCounts );
	testPackUnorm4x8( testCounts );
	testUnpackDouble2x32( testCounts );
	testUnpackHalf2x16( testCounts );
	testUnpackSnorm2x16( testCounts );
	testUnpackUnorm2x16( testCounts );
	testUnpackSnorm4x8( testCounts );
	testUnpackUnorm4x8( testCounts );
	testLessThan2F( testCounts );
	testLessThan3F( testCounts );
	testLessThan4F( testCounts );
	testLessThan2D( testCounts );
	testLessThan3D( testCounts );
	testLessThan4D( testCounts );
	testLessThan2I( testCounts );
	testLessThan3I( testCounts );
	testLessThan4I( testCounts );
	testLessThan2U( testCounts );
	testLessThan3U( testCounts );
	testLessThan4U( testCounts );
	testLessThanEqual2F( testCounts );
	testLessThanEqual3F( testCounts );
	testLessThanEqual4F( testCounts );
	testLessThanEqual2D( testCounts );
	testLessThanEqual3D( testCounts );
	testLessThanEqual4D( testCounts );
	testLessThanEqual2I( testCounts );
	testLessThanEqual3I( testCounts );
	testLessThanEqual4I( testCounts );
	testLessThanEqual2U( testCounts );
	testLessThanEqual3U( testCounts );
	testLessThanEqual4U( testCounts );
	testGreaterThan2F( testCounts );
	testGreaterThan3F( testCounts );
	testGreaterThan4F( testCounts );
	testGreaterThan2D( testCounts );
	testGreaterThan3D( testCounts );
	testGreaterThan4D( testCounts );
	testGreaterThan2I( testCounts );
	testGreaterThan3I( testCounts );
	testGreaterThan4I( testCounts );
	testGreaterThan2U( testCounts );
	testGreaterThan3U( testCounts );
	testGreaterThan4U( testCounts );
	testGreaterThanEqual2F( testCounts );
	testGreaterThanEqual3F( testCounts );
	testGreaterThanEqual4F( testCounts );
	testGreaterThanEqual2D( testCounts );
	testGreaterThanEqual3D( testCounts );
	testGreaterThanEqual4D( testCounts );
	testGreaterThanEqual2I( testCounts );
	testGreaterThanEqual3I( testCounts );
	testGreaterThanEqual4I( testCounts );
	testGreaterThanEqual2U( testCounts );
	testGreaterThanEqual3U( testCounts );
	testGreaterThanEqual4U( testCounts );
	testEqual2F( testCounts );
	testEqual3F( testCounts );
	testEqual4F( testCounts );
	testEqual2D( testCounts );
	testEqual3D( testCounts );
	testEqual4D( testCounts );
	testEqual2I( testCounts );
	testEqual3I( testCounts );
	testEqual4I( testCounts );
	testEqual2U( testCounts );
	testEqual3U( testCounts );
	testEqual4U( testCounts );
	testNotEqual2F( testCounts );
	testNotEqual3F( testCounts );
	testNotEqual4F( testCounts );
	testNotEqual2D( testCounts );
	testNotEqual3D( testCounts );
	testNotEqual4D( testCounts );
	testNotEqual2I( testCounts );
	testNotEqual3I( testCounts );
	testNotEqual4I( testCounts );
	testNotEqual2U( testCounts );
	testNotEqual3U( testCounts );
	testNotEqual4U( testCounts );
	testNot2( testCounts );
	testNot3( testCounts );
	testNot4( testCounts );
	testMatrixCompMult2x2F( testCounts );
	testMatrixCompMult2x3F( testCounts );
	testMatrixCompMult2x4F( testCounts );
	testMatrixCompMult3x2F( testCounts );
	testMatrixCompMult3x3F( testCounts );
	testMatrixCompMult3x4F( testCounts );
	testMatrixCompMult4x2F( testCounts );
	testMatrixCompMult4x3F( testCounts );
	testMatrixCompMult4x4F( testCounts );
	testMatrixCompMult2x2D( testCounts );
	testMatrixCompMult2x3D( testCounts );
	testMatrixCompMult2x4D( testCounts );
	testMatrixCompMult3x2D( testCounts );
	testMatrixCompMult3x3D( testCounts );
	testMatrixCompMult3x4D( testCounts );
	testMatrixCompMult4x2D( testCounts );
	testMatrixCompMult4x3D( testCounts );
	testMatrixCompMult4x4D( testCounts );
	testMatrixMult2x2F( testCounts );
	testMatrixMult3x3F( testCounts );
	testMatrixMult4x4F( testCounts );
	testMatrixMult2x2D( testCounts );
	testMatrixMult3x3D( testCounts );
	testMatrixMult4x4D( testCounts );
	testInverse2x2F( testCounts );
	testInverse2x2D( testCounts );
	testInverse3x3F( testCounts );
	testInverse3x3D( testCounts );
	testInverse4x4F( testCounts );
	testInverse4x4D( testCounts );
	testUaddCarry1( testCounts );
	testUaddCarry2( testCounts );
	testUaddCarry3( testCounts );
	testUaddCarry4( testCounts );
	testUsubBorrow1( testCounts );
	testUsubBorrow2( testCounts );
	testUsubBorrow3( testCounts );
	testUsubBorrow4( testCounts );
	testUmulExtended1( testCounts );
	testUmulExtended2( testCounts );
	testUmulExtended3( testCounts );
	testUmulExtended4( testCounts );
	testImulExtended1( testCounts );
	testImulExtended2( testCounts );
	testImulExtended3( testCounts );
	testImulExtended4( testCounts );
	testBitfieldInsert1I( testCounts );
	testBitfieldInsert2I( testCounts );
	testBitfieldInsert3I( testCounts );
	testBitfieldInsert4I( testCounts );
	testBitfieldInsert1U( testCounts );
	testBitfieldInsert2U( testCounts );
	testBitfieldInsert3U( testCounts );
	testBitfieldInsert4U( testCounts );
	testBitfieldExtract1I( testCounts );
	testBitfieldExtract2I( testCounts );
	testBitfieldExtract3I( testCounts );
	testBitfieldExtract4I( testCounts );
	testBitfieldExtract1U( testCounts );
	testBitfieldExtract2U( testCounts );
	testBitfieldExtract3U( testCounts );
	testBitfieldExtract4U( testCounts );
	sdwTestSuiteEnd();
}
