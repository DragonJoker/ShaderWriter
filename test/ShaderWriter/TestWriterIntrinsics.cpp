#include "../Common.hpp"
#include "WriterCommon.hpp"

namespace
{
	void testDegrees1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDegrees1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = degrees( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDegrees2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDegrees2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = degrees( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDegrees3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDegrees3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = degrees( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDegrees4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDegrees4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = degrees( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRadians1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRadians1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = radians( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRadians2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRadians2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = radians( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRadians3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRadians3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = radians( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRadians4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRadians4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = radians( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCosh1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCosh1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = cosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCosh2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCosh2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = cosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCosh3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCosh3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = cosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCosh4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCosh4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = cosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSinh1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSinh1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = sinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSinh2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSinh2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = sinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSinh3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSinh3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = sinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSinh4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSinh4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = sinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTanh1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTanh1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = tanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTanh2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTanh2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = tanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTanh3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTanh3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = tanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTanh4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTanh4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = tanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCos1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCos1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = cos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCos2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCos2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = cos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCos3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCos3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = cos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCos4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCos4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = cos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSin1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSin1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = sin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSin2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSin2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = sin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSin3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSin3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = sin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSin4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSin4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = sin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTan1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTan1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = tan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTan2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTan2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = tan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTan3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTan3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = tan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTan4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTan4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = tan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACos1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACos1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = acos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACos2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACos2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = acos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACos3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACos3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = acos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACos4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACos4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = acos( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASin1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASin1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = asin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASin2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASin2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = asin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASin3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASin3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = asin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASin4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASin4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = asin( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATan1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATan1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = atan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATan2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATan2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = atan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATan3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATan3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = atan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATan4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATan4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = atan( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACosh1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACosh1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = acosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACosh2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACosh2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = acosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACosh3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACosh3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = acosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testACosh4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACosh4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = acosh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASinh1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASinh1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = asinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASinh2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASinh2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = asinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASinh3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASinh3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = asinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testASinh4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASinh4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = asinh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATanh1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATanh1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = atanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATanh2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATanh2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = atanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATanh3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATanh3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = atanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testATanh4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATanh4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = atanh( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPow1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPow1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					v1 = pow( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPow2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPow2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					v1 = pow( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPow3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPow3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					v1 = pow( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testPow4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPow4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					v1 = pow( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = exp( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = exp( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = exp( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = exp( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = log( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = log( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = log( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = log( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp21F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp21F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = exp2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp22F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp22F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = exp2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp23F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp23F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = exp2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testExp24F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp24F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = exp2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog21F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog21F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = log2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog22F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog22F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = log2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog23F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog23F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = log2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLog24F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog24F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = log2( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSqrt4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverseSqrt4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Int >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< IVec2 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< IVec3 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAbs4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< IVec4 >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Int >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< IVec2 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< IVec3 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSign4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< IVec4 >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloor4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testTrunc4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRound4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRoundEven1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	void testCeil1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCeil4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Float >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec3 >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< Double >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec2 >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec3 >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFract4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< DVec4 >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMod4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testModf4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Int >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec2 >( "v1" );
					auto v2 = writer.declLocale< IVec2 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec3 >( "v1" );
					auto v2 = writer.declLocale< IVec3 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec4 >( "v1" );
					auto v2 = writer.declLocale< IVec4 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UInt >( "v1" );
					auto v2 = writer.declLocale< UInt >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec2 >( "v1" );
					auto v2 = writer.declLocale< UVec2 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec3 >( "v1" );
					auto v2 = writer.declLocale< UVec3 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMin4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec4 >( "v1" );
					auto v2 = writer.declLocale< UVec4 >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Int >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec2 >( "v1" );
					auto v2 = writer.declLocale< IVec2 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec3 >( "v1" );
					auto v2 = writer.declLocale< IVec3 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec4 >( "v1" );
					auto v2 = writer.declLocale< IVec4 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UInt >( "v1" );
					auto v2 = writer.declLocale< UInt >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec2 >( "v1" );
					auto v2 = writer.declLocale< UVec2 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec3 >( "v1" );
					auto v2 = writer.declLocale< UVec3 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMax4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec4 >( "v1" );
					auto v2 = writer.declLocale< UVec4 >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					auto v3 = writer.declLocale< Vec2 >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					auto v3 = writer.declLocale< Vec3 >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					auto v3 = writer.declLocale< Vec4 >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					auto v3 = writer.declLocale< Double >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					auto v3 = writer.declLocale< DVec2 >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					auto v3 = writer.declLocale< DVec3 >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testClamp4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					auto v3 = writer.declLocale< DVec4 >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					auto v3 = writer.declLocale< Vec2 >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					auto v3 = writer.declLocale< Vec3 >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					auto v3 = writer.declLocale< Vec4 >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					auto v3 = writer.declLocale< Double >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					auto v3 = writer.declLocale< DVec2 >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					auto v3 = writer.declLocale< DVec3 >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testMix4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					auto v3 = writer.declLocale< DVec4 >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testStep4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					auto v3 = writer.declLocale< Vec2 >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					auto v3 = writer.declLocale< Vec3 >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					auto v3 = writer.declLocale< Vec4 >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					auto v3 = writer.declLocale< Double >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					auto v3 = writer.declLocale< DVec2 >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					auto v3 = writer.declLocale< DVec3 >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testSmoothStep4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					auto v3 = writer.declLocale< DVec4 >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsnan4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsnan4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					sdw::isnan( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIsinf4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIsinf4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					sdw::isinf( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToInt1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToInt2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToInt3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToInt4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToUInt1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToUInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToUInt2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToUInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToUInt3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToUInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFloatBitsToUInt4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToUInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIntBitsToFloat1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Int >( "v1" );
					auto res = writer.declLocale( "res"
						, intBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIntBitsToFloat2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec2 >( "v1" );
					auto res = writer.declLocale( "res"
						, intBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIntBitsToFloat3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec3 >( "v1" );
					auto res = writer.declLocale( "res"
						, intBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testIntBitsToFloat4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< IVec4 >( "v1" );
					auto res = writer.declLocale( "res"
						, intBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUIntBitsToFloat1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUIntBitsToFloat1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UInt >( "v1" );
					auto res = writer.declLocale( "res"
						, uintBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUIntBitsToFloat2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUIntBitsToFloat2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec2 >( "v1" );
					auto res = writer.declLocale( "res"
						, uintBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUIntBitsToFloat3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUIntBitsToFloat3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec3 >( "v1" );
					auto res = writer.declLocale( "res"
						, uintBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testUIntBitsToFloat4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUIntBitsToFloat4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< UVec4 >( "v1" );
					auto res = writer.declLocale( "res"
						, uintBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					auto v3 = writer.declLocale< Vec2 >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					auto v3 = writer.declLocale< Vec3 >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					auto v3 = writer.declLocale< Vec4 >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					auto v3 = writer.declLocale< Double >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					auto v3 = writer.declLocale< DVec2 >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					auto v3 = writer.declLocale< DVec3 >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFma4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					auto v3 = writer.declLocale< DVec4 >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< IVec2 >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< IVec3 >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< IVec4 >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< IVec2 >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< IVec3 >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFrexp4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< IVec4 >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< IVec2 >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< IVec3 >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< IVec4 >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< IVec2 >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< IVec3 >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLdexp4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< IVec4 >( "v2" );
					v1 = ldexp( v1, v2 );
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	void testLength1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testLength4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLength4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					length( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDistance4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDistance4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					distance( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDot4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDot4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					dot( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCrossF( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCrossF" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					cross( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testCrossD( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCrossD" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					cross( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testNormalize4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNormalize4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					normalize( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					auto v3 = writer.declLocale< Vec2 >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					auto v3 = writer.declLocale< Vec3 >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					auto v3 = writer.declLocale< Vec4 >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					auto v3 = writer.declLocale< Double >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					auto v3 = writer.declLocale< DVec2 >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					auto v3 = writer.declLocale< DVec3 >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFaceForward4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFaceForward4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					auto v3 = writer.declLocale< DVec4 >( "v3" );
					faceForward( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testReflect4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testReflect4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					reflect( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract1F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract1F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Float >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec3 >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec4 >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract1D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract1D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Double >( "v1" );
					auto v2 = writer.declLocale< Double >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec2 >( "v1" );
					auto v2 = writer.declLocale< DVec2 >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec3 >( "v1" );
					auto v2 = writer.declLocale< DVec3 >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testRefract4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRefract4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< DVec4 >( "v1" );
					auto v2 = writer.declLocale< DVec4 >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					refract( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts );
		}
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	template< typename LhsT, typename RhsT >
	void testOuterProduct( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto lhs = writer.declLocale< LhsT >( "lhs" );
					auto rhs = writer.declLocale< RhsT >( "rhs" );
					auto res = writer.declLocale( "res"
						, outerProduct( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testOuterProduct2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x2F" );
		testOuterProduct< sdw::Vec2, sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct2x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x3F" );
		testOuterProduct< sdw::Vec2, sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct2x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x4F" );
		testOuterProduct< sdw::Vec2, sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct3x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x2F" );
		testOuterProduct< sdw::Vec2, sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct3x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x3F" );
		testOuterProduct< sdw::Vec2, sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct3x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x4F" );
		testOuterProduct< sdw::Vec2, sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct4x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x2F" );
		testOuterProduct< sdw::Vec4, sdw::Vec2 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct4x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x3F" );
		testOuterProduct< sdw::Vec4, sdw::Vec3 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct4x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x4F" );
		testOuterProduct< sdw::Vec4, sdw::Vec4 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct2x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x2D" );
		testOuterProduct< sdw::DVec2, sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct2x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x3D" );
		testOuterProduct< sdw::DVec2, sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct2x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct2x4D" );
		testOuterProduct< sdw::DVec2, sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct3x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x2D" );
		testOuterProduct< sdw::DVec3, sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct3x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x3D" );
		testOuterProduct< sdw::DVec3, sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct3x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct3x4D" );
		testOuterProduct< sdw::DVec3, sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct4x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x2D" );
		testOuterProduct< sdw::DVec4, sdw::DVec2 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct4x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x3D" );
		testOuterProduct< sdw::DVec4, sdw::DVec3 >( testName, testCounts );
		testEnd();
	}

	void testOuterProduct4x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct4x4D" );
		testOuterProduct< sdw::DVec4, sdw::DVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testTranspose( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v = writer.declLocale< ValueT >( "v" );
					auto r = writer.declLocale( "r"
						, transpose( v ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testTranspose2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x2F" );
		testTranspose< sdw::Mat2 >( testName, testCounts );
		testEnd();
	}

	void testTranspose2x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x3F" );
		testTranspose< sdw::Mat2x3 >( testName, testCounts );
		testEnd();
	}

	void testTranspose2x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x4F" );
		testTranspose< sdw::Mat2x4 >( testName, testCounts );
		testEnd();
	}

	void testTranspose3x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x2F" );
		testTranspose< sdw::Mat3x2 >( testName, testCounts );
		testEnd();
	}

	void testTranspose3x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x3F" );
		testTranspose< sdw::Mat3 >( testName, testCounts );
		testEnd();
	}

	void testTranspose3x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x4F" );
		testTranspose< sdw::Mat3x4 >( testName, testCounts );
		testEnd();
	}

	void testTranspose4x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x2F" );
		testTranspose< sdw::Mat4x2 >( testName, testCounts );
		testEnd();
	}

	void testTranspose4x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x3F" );
		testTranspose< sdw::Mat4x3 >( testName, testCounts );
		testEnd();
	}

	void testTranspose4x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x4F" );
		testTranspose< sdw::Mat4 >( testName, testCounts );
		testEnd();
	}

	void testTranspose2x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x2D" );
		testTranspose< sdw::DMat2 >( testName, testCounts );
		testEnd();
	}

	void testTranspose2x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x3D" );
		testTranspose< sdw::DMat2x3 >( testName, testCounts );
		testEnd();
	}

	void testTranspose2x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose2x4D" );
		testTranspose< sdw::DMat2x4 >( testName, testCounts );
		testEnd();
	}

	void testTranspose3x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x2D" );
		testTranspose< sdw::DMat3x2 >( testName, testCounts );
		testEnd();
	}

	void testTranspose3x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x3D" );
		testTranspose< sdw::DMat3 >( testName, testCounts );
		testEnd();
	}

	void testTranspose3x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose3x4D" );
		testTranspose< sdw::DMat3x4 >( testName, testCounts );
		testEnd();
	}

	void testTranspose4x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x2D" );
		testTranspose< sdw::DMat4x2 >( testName, testCounts );
		testEnd();
	}

	void testTranspose4x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x3D" );
		testTranspose< sdw::DMat4x3 >( testName, testCounts );
		testEnd();
	}

	void testTranspose4x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose4x4D" );
		testTranspose< sdw::DMat4 >( testName, testCounts );
		testEnd();
	}

	void testDeterminant2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant2x2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat2 >( "m" );
					determinant( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDeterminant2x2D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant2x2D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat2 >( "m" );
					determinant( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDeterminant3x3F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant3x3F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat3 >( "m" );
					determinant( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDeterminant3x3D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant3x3D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat3 >( "m" );
					determinant( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDeterminant4x4F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant4x4F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< Mat4 >( "m" );
					determinant( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDeterminant4x4D( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDeterminant4x4D" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto m = writer.declLocale< DMat4 >( "m" );
					determinant( m );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInverse2x2F( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse2x2F" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	template< typename ValueT >
	void testLessThan( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
	void testAll( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, all( operand ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testAll2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAll2" );
		testAll< sdw::BVec2 >( testName, testCounts );
		testEnd();
	}

	void testAll3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAll3" );
		testAll< sdw::BVec3 >( testName, testCounts );
		testEnd();
	}

	void testAll4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAll4" );
		testAll< sdw::BVec4 >( testName, testCounts );
		testEnd();
	}

	template< typename ValueT >
	void testAny( std::string const & testName
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, any( operand ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
	}

	void testAny2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAny2" );
		testAny< sdw::BVec2 >( testName, testCounts );
		testEnd();
	}

	void testAny3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAny3" );
		testAny< sdw::BVec3 >( testName, testCounts );
		testEnd();
	}

	void testAny4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAny4" );
		testAny< sdw::BVec4 >( testName, testCounts );
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
			writer.implementFunction< sdw::Void >( "main"
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

	void testUaddCarry1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	void testBitfieldExtract1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	void testBitfieldInsert1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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
			writer.implementFunction< sdw::Void >( "main"
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

	void testBitfieldReverse1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitfieldReverse4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testBitCount4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindLSB4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB1I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB1I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB2I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB2I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB3I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB3I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB4I( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB4I" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< IVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB1U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB1U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB2U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB2U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec2 >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB3U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB3U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec3 >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFindMSB4U( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB4U" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UVec4 >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicAddI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAddI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicAdd( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicAddU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAddU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicAdd( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicMinI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMinI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			auto & shader = writer.getShader();
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicMin( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicMinU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMinU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicMin( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicMaxI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMaxI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicMax( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicMaxU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMaxU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicMax( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicAndI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAndI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicAnd( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicAndU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAndU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicAnd( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicOrI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicOrI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicOr( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicOrU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicOrU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicOr( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicXorI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicXorI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicXor( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicXorU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicXorU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicXor( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicExchangeI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchangeI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< Int >( "x", 0_i );
					writer.declLocale( "r"
						, atomicExchange( bo[0].getMember< sdw::Int >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicExchangeU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicExchangeU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto x = writer.declLocale< UInt >( "x", 0_u );
					writer.declLocale( "r"
						, atomicExchange( bo[0].getMember< sdw::UInt >( name ), x ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicCompSwapI( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicCompSwapI" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::Int >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale< UInt >( "c", 0_u );
					auto v = writer.declLocale< UInt >( "v", 1_u );
					writer.declLocale( "r"
						, atomicCompSwap( bo[0].getMember< sdw::Int >( name ), c, v ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testAtomicCompSwapU( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicCompSwapU" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			std::string const name = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< sdw::UInt >( name );
			type.end();
			sdw::StructuredSsbo bo{ writer, "Datas", type.getType(), 1u, 1u };
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto c = writer.declLocale< UInt >( "c", 0_u );
					auto v = writer.declLocale< UInt >( "v", 1_u );
					writer.declLocale( "r"
						, atomicCompSwap( bo[0].getMember< sdw::UInt >( name ), c, v ) );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdx1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdx1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					dFdx( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdx2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdx2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					dFdx( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdx3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdx3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					dFdx( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdx4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdx4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					dFdx( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxCoarse1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					dFdxCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxCoarse2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					dFdxCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxCoarse3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					dFdxCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxCoarse4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					dFdxCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxFine1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					dFdxFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxFine2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					dFdxFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxFine3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					dFdxFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdxFine4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					dFdxFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdy1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdy1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					dFdy( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdy2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdy2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					dFdy( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdy3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdy3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					dFdy( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdy4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdy4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					dFdy( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyCoarse1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					dFdyCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyCoarse2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					dFdyCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyCoarse3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					dFdyCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyCoarse4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					dFdyCoarse( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyFine1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					dFdyFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyFine2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					dFdyFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyFine3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					dFdyFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testDFdyFine4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					dFdyFine( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFwidth1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFwidth1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					fwidth( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFwidth2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFwidth2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					fwidth( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFwidth3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFwidth3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					fwidth( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testFwidth4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFwidth4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					fwidth( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtCentroid1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					interpolateAtCentroid( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtCentroid2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					interpolateAtCentroid( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtCentroid3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					interpolateAtCentroid( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtCentroid4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					interpolateAtCentroid( v1 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtSample1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					interpolateAtSample( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtSample2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					interpolateAtSample( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtSample3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					interpolateAtSample( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtSample4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Int >( "v2" );
					interpolateAtSample( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtOffset1( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset1" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Float >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					interpolateAtOffset( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtOffset2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset2" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec2 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					interpolateAtOffset( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtOffset3( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset3" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec3 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					interpolateAtOffset( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts );
		}
		testEnd();
	}

	void testInterpolateAtOffset4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset4" );
		using namespace sdw;
		{
			ComputeWriter writer;
			writer.inputLayout( 1u );
			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto v1 = writer.declLocale< Vec4 >( "v1" );
					auto v2 = writer.declLocale< Vec2 >( "v2" );
					interpolateAtOffset( v1, v2 );
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
	testDegrees1F( testCounts );
	testDegrees2F( testCounts );
	testDegrees3F( testCounts );
	testDegrees4F( testCounts );
	testRadians1F( testCounts );
	testRadians2F( testCounts );
	testRadians3F( testCounts );
	testRadians4F( testCounts );
	testCos1F( testCounts );
	testCos2F( testCounts );
	testCos3F( testCounts );
	testCos4F( testCounts );
	testSin1F( testCounts );
	testSin2F( testCounts );
	testSin3F( testCounts );
	testSin4F( testCounts );
	testTan1F( testCounts );
	testTan2F( testCounts );
	testTan3F( testCounts );
	testTan4F( testCounts );
	testCosh1F( testCounts );
	testCosh2F( testCounts );
	testCosh3F( testCounts );
	testCosh4F( testCounts );
	testSinh1F( testCounts );
	testSinh2F( testCounts );
	testSinh3F( testCounts );
	testSinh4F( testCounts );
	testTanh1F( testCounts );
	testTanh2F( testCounts );
	testTanh3F( testCounts );
	testTanh4F( testCounts );
	testACos1F( testCounts );
	testACos2F( testCounts );
	testACos3F( testCounts );
	testACos4F( testCounts );
	testASin1F( testCounts );
	testASin2F( testCounts );
	testASin3F( testCounts );
	testASin4F( testCounts );
	testATan1F( testCounts );
	testATan2F( testCounts );
	testATan3F( testCounts );
	testATan4F( testCounts );
	testACosh1F( testCounts );
	testACosh2F( testCounts );
	testACosh3F( testCounts );
	testACosh4F( testCounts );
	testASinh1F( testCounts );
	testASinh2F( testCounts );
	testASinh3F( testCounts );
	testASinh4F( testCounts );
	testATanh1F( testCounts );
	testATanh2F( testCounts );
	testATanh3F( testCounts );
	testATanh4F( testCounts );
	testPow1F( testCounts );
	testPow2F( testCounts );
	testPow3F( testCounts );
	testPow4F( testCounts );
	testExp1F( testCounts );
	testExp2F( testCounts );
	testExp3F( testCounts );
	testExp4F( testCounts );
	testLog1F( testCounts );
	testLog2F( testCounts );
	testLog3F( testCounts );
	testLog4F( testCounts );
	testExp21F( testCounts );
	testExp22F( testCounts );
	testExp23F( testCounts );
	testExp24F( testCounts );
	testLog21F( testCounts );
	testLog22F( testCounts );
	testLog23F( testCounts );
	testLog24F( testCounts );
	testSqrt1F( testCounts );
	testSqrt2F( testCounts );
	testSqrt3F( testCounts );
	testSqrt4F( testCounts );
	testSqrt1D( testCounts );
	testSqrt2D( testCounts );
	testSqrt3D( testCounts );
	testSqrt4D( testCounts );
	testInverseSqrt1F( testCounts );
	testInverseSqrt2F( testCounts );
	testInverseSqrt3F( testCounts );
	testInverseSqrt4F( testCounts );
	testInverseSqrt1D( testCounts );
	testInverseSqrt2D( testCounts );
	testInverseSqrt3D( testCounts );
	testInverseSqrt4D( testCounts );
	testAbs1F( testCounts );
	testAbs2F( testCounts );
	testAbs3F( testCounts );
	testAbs4F( testCounts );
	testAbs1D( testCounts );
	testAbs2D( testCounts );
	testAbs3D( testCounts );
	testAbs4D( testCounts );
	testAbs1I( testCounts );
	testAbs2I( testCounts );
	testAbs3I( testCounts );
	testAbs4I( testCounts );
	testSign1F( testCounts );
	testSign2F( testCounts );
	testSign3F( testCounts );
	testSign4F( testCounts );
	testSign1D( testCounts );
	testSign2D( testCounts );
	testSign3D( testCounts );
	testSign4D( testCounts );
	testSign1I( testCounts );
	testSign2I( testCounts );
	testSign3I( testCounts );
	testSign4I( testCounts );
	testFloor1F( testCounts );
	testFloor2F( testCounts );
	testFloor3F( testCounts );
	testFloor4F( testCounts );
	testFloor1D( testCounts );
	testFloor2D( testCounts );
	testFloor3D( testCounts );
	testFloor4D( testCounts );
	testTrunc1F( testCounts );
	testTrunc2F( testCounts );
	testTrunc3F( testCounts );
	testTrunc4F( testCounts );
	testTrunc1D( testCounts );
	testTrunc2D( testCounts );
	testTrunc3D( testCounts );
	testTrunc4D( testCounts );
	testRound1F( testCounts );
	testRound2F( testCounts );
	testRound3F( testCounts );
	testRound4F( testCounts );
	testRound1D( testCounts );
	testRound2D( testCounts );
	testRound3D( testCounts );
	testRound4D( testCounts );
	testRoundEven1F( testCounts );
	testRoundEven2F( testCounts );
	testRoundEven3F( testCounts );
	testRoundEven4F( testCounts );
	testRoundEven1D( testCounts );
	testRoundEven2D( testCounts );
	testRoundEven3D( testCounts );
	testRoundEven4D( testCounts );
	testCeil1F( testCounts );
	testCeil2F( testCounts );
	testCeil3F( testCounts );
	testCeil4F( testCounts );
	testCeil1D( testCounts );
	testCeil2D( testCounts );
	testCeil3D( testCounts );
	testCeil4D( testCounts );
	testFract1F( testCounts );
	testFract2F( testCounts );
	testFract3F( testCounts );
	testFract4F( testCounts );
	testFract1D( testCounts );
	testFract2D( testCounts );
	testFract3D( testCounts );
	testFract4D( testCounts );
	testMod1F( testCounts );
	testMod2F( testCounts );
	testMod3F( testCounts );
	testMod4F( testCounts );
	testMod1D( testCounts );
	testMod2D( testCounts );
	testMod3D( testCounts );
	testMod4D( testCounts );
	testModf1F( testCounts );
	testModf2F( testCounts );
	testModf3F( testCounts );
	testModf4F( testCounts );
	testModf1D( testCounts );
	testModf2D( testCounts );
	testModf3D( testCounts );
	testModf4D( testCounts );
	testMin1F( testCounts );
	testMin2F( testCounts );
	testMin3F( testCounts );
	testMin4F( testCounts );
	testMin1D( testCounts );
	testMin2D( testCounts );
	testMin3D( testCounts );
	testMin4D( testCounts );
	testMin1I( testCounts );
	testMin2I( testCounts );
	testMin3I( testCounts );
	testMin4I( testCounts );
	testMin1U( testCounts );
	testMin2U( testCounts );
	testMin3U( testCounts );
	testMin4U( testCounts );
	testMax1F( testCounts );
	testMax2F( testCounts );
	testMax3F( testCounts );
	testMax4F( testCounts );
	testMax1D( testCounts );
	testMax2D( testCounts );
	testMax3D( testCounts );
	testMax4D( testCounts );
	testMax1I( testCounts );
	testMax2I( testCounts );
	testMax3I( testCounts );
	testMax4I( testCounts );
	testMax1U( testCounts );
	testMax2U( testCounts );
	testMax3U( testCounts );
	testMax4U( testCounts );
	testClamp1F( testCounts );
	testClamp2F( testCounts );
	testClamp3F( testCounts );
	testClamp4F( testCounts );
	testClamp1D( testCounts );
	testClamp2D( testCounts );
	testClamp3D( testCounts );
	testClamp4D( testCounts );
	testMix1F( testCounts );
	testMix2F( testCounts );
	testMix3F( testCounts );
	testMix4F( testCounts );
	testMix1D( testCounts );
	testMix2D( testCounts );
	testMix3D( testCounts );
	testMix4D( testCounts );
	testStep1F( testCounts );
	testStep2F( testCounts );
	testStep3F( testCounts );
	testStep4F( testCounts );
	testStep1D( testCounts );
	testStep2D( testCounts );
	testStep3D( testCounts );
	testStep4D( testCounts );
	testSmoothStep1F( testCounts );
	testSmoothStep2F( testCounts );
	testSmoothStep3F( testCounts );
	testSmoothStep4F( testCounts );
	testSmoothStep1D( testCounts );
	testSmoothStep2D( testCounts );
	testSmoothStep3D( testCounts );
	testSmoothStep4D( testCounts );
	testIsnan1F( testCounts );
	testIsnan2F( testCounts );
	testIsnan3F( testCounts );
	testIsnan4F( testCounts );
	testIsnan1D( testCounts );
	testIsnan2D( testCounts );
	testIsnan3D( testCounts );
	testIsnan4D( testCounts );
	testIsinf1F( testCounts );
	testIsinf2F( testCounts );
	testIsinf3F( testCounts );
	testIsinf4F( testCounts );
	testIsinf1D( testCounts );
	testIsinf2D( testCounts );
	testIsinf3D( testCounts );
	testIsinf4D( testCounts );
	testFloatBitsToInt1( testCounts );
	testFloatBitsToInt2( testCounts );
	testFloatBitsToInt3( testCounts );
	testFloatBitsToInt4( testCounts );
	testFloatBitsToUInt1( testCounts );
	testFloatBitsToUInt2( testCounts );
	testFloatBitsToUInt3( testCounts );
	testFloatBitsToUInt4( testCounts );
	testIntBitsToFloat1( testCounts );
	testIntBitsToFloat2( testCounts );
	testIntBitsToFloat3( testCounts );
	testIntBitsToFloat4( testCounts );
	testUIntBitsToFloat1( testCounts );
	testUIntBitsToFloat2( testCounts );
	testUIntBitsToFloat3( testCounts );
	testUIntBitsToFloat4( testCounts );
	testFma1F( testCounts );
	testFma2F( testCounts );
	testFma3F( testCounts );
	testFma4F( testCounts );
	testFma1D( testCounts );
	testFma2D( testCounts );
	testFma3D( testCounts );
	testFma4D( testCounts );
	testFrexp1F( testCounts );
	testFrexp2F( testCounts );
	testFrexp3F( testCounts );
	testFrexp4F( testCounts );
	testFrexp1D( testCounts );
	testFrexp2D( testCounts );
	testFrexp3D( testCounts );
	testFrexp4D( testCounts );
	testLdexp1F( testCounts );
	testLdexp2F( testCounts );
	testLdexp3F( testCounts );
	testLdexp4F( testCounts );
	testLdexp1D( testCounts );
	testLdexp2D( testCounts );
	testLdexp3D( testCounts );
	testLdexp4D( testCounts );
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
	testLength1F( testCounts );
	testLength2F( testCounts );
	testLength3F( testCounts );
	testLength4F( testCounts );
	testLength1D( testCounts );
	testLength2D( testCounts );
	testLength3D( testCounts );
	testLength4D( testCounts );
	testDistance1F( testCounts );
	testDistance2F( testCounts );
	testDistance3F( testCounts );
	testDistance4F( testCounts );
	testDistance1D( testCounts );
	testDistance2D( testCounts );
	testDistance3D( testCounts );
	testDistance4D( testCounts );
	testDot1F( testCounts );
	testDot2F( testCounts );
	testDot3F( testCounts );
	testDot4F( testCounts );
	testDot1D( testCounts );
	testDot2D( testCounts );
	testDot3D( testCounts );
	testDot4D( testCounts );
	testCrossF( testCounts );
	testCrossD( testCounts );
	testNormalize1F( testCounts );
	testNormalize2F( testCounts );
	testNormalize3F( testCounts );
	testNormalize4F( testCounts );
	testNormalize1D( testCounts );
	testNormalize2D( testCounts );
	testNormalize3D( testCounts );
	testNormalize4D( testCounts );
	testFaceForward1F( testCounts );
	testFaceForward2F( testCounts );
	testFaceForward3F( testCounts );
	testFaceForward4F( testCounts );
	testFaceForward1D( testCounts );
	testFaceForward2D( testCounts );
	testFaceForward3D( testCounts );
	testFaceForward4D( testCounts );
	testReflect1F( testCounts );
	testReflect2F( testCounts );
	testReflect3F( testCounts );
	testReflect4F( testCounts );
	testReflect1D( testCounts );
	testReflect2D( testCounts );
	testReflect3D( testCounts );
	testReflect4D( testCounts );
	testRefract1F( testCounts );
	testRefract2F( testCounts );
	testRefract3F( testCounts );
	testRefract4F( testCounts );
	testRefract1D( testCounts );
	testRefract2D( testCounts );
	testRefract3D( testCounts );
	testRefract4D( testCounts );
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
	testOuterProduct2x2F( testCounts );
	testOuterProduct2x3F( testCounts );
	testOuterProduct2x4F( testCounts );
	testOuterProduct3x2F( testCounts );
	testOuterProduct3x3F( testCounts );
	testOuterProduct3x4F( testCounts );
	testOuterProduct4x2F( testCounts );
	testOuterProduct4x3F( testCounts );
	testOuterProduct4x4F( testCounts );
	testOuterProduct2x2D( testCounts );
	testOuterProduct2x3D( testCounts );
	testOuterProduct2x4D( testCounts );
	testOuterProduct3x2D( testCounts );
	testOuterProduct3x3D( testCounts );
	testOuterProduct3x4D( testCounts );
	testOuterProduct4x2D( testCounts );
	testOuterProduct4x3D( testCounts );
	testOuterProduct4x4D( testCounts );
	testTranspose2x2F( testCounts );
	testTranspose2x3F( testCounts );
	testTranspose2x4F( testCounts );
	testTranspose3x2F( testCounts );
	testTranspose3x3F( testCounts );
	testTranspose3x4F( testCounts );
	testTranspose4x2F( testCounts );
	testTranspose4x3F( testCounts );
	testTranspose4x4F( testCounts );
	testTranspose2x2D( testCounts );
	testTranspose2x3D( testCounts );
	testTranspose2x4D( testCounts );
	testTranspose3x2D( testCounts );
	testTranspose3x3D( testCounts );
	testTranspose3x4D( testCounts );
	testTranspose4x2D( testCounts );
	testTranspose4x3D( testCounts );
	testTranspose4x4D( testCounts );
	testDeterminant2x2F( testCounts );
	testDeterminant3x3F( testCounts );
	testDeterminant4x4F( testCounts );
	testDeterminant2x2D( testCounts );
	testDeterminant3x3D( testCounts );
	testDeterminant4x4D( testCounts );
	testInverse2x2F( testCounts );
	testInverse3x3F( testCounts );
	testInverse4x4F( testCounts );
	testInverse2x2D( testCounts );
	testInverse3x3D( testCounts );
	testInverse4x4D( testCounts );
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
	testAll2( testCounts );
	testAll3( testCounts );
	testAll4( testCounts );
	testAny2( testCounts );
	testAny3( testCounts );
	testAny4( testCounts );
	testNot2( testCounts );
	testNot3( testCounts );
	testNot4( testCounts );
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
	testBitfieldExtract1I( testCounts );
	testBitfieldExtract2I( testCounts );
	testBitfieldExtract3I( testCounts );
	testBitfieldExtract4I( testCounts );
	testBitfieldExtract1U( testCounts );
	testBitfieldExtract2U( testCounts );
	testBitfieldExtract3U( testCounts );
	testBitfieldExtract4U( testCounts );
	testBitfieldInsert1I( testCounts );
	testBitfieldInsert2I( testCounts );
	testBitfieldInsert3I( testCounts );
	testBitfieldInsert4I( testCounts );
	testBitfieldInsert1U( testCounts );
	testBitfieldInsert2U( testCounts );
	testBitfieldInsert3U( testCounts );
	testBitfieldInsert4U( testCounts );
	testBitfieldReverse1I( testCounts );
	testBitfieldReverse2I( testCounts );
	testBitfieldReverse3I( testCounts );
	testBitfieldReverse4I( testCounts );
	testBitfieldReverse1U( testCounts );
	testBitfieldReverse2U( testCounts );
	testBitfieldReverse3U( testCounts );
	testBitfieldReverse4U( testCounts );
	testBitCount1I( testCounts );
	testBitCount2I( testCounts );
	testBitCount3I( testCounts );
	testBitCount4I( testCounts );
	testBitCount1U( testCounts );
	testBitCount2U( testCounts );
	testBitCount3U( testCounts );
	testBitCount4U( testCounts );
	testFindLSB1I( testCounts );
	testFindLSB2I( testCounts );
	testFindLSB3I( testCounts );
	testFindLSB4I( testCounts );
	testFindLSB1U( testCounts );
	testFindLSB2U( testCounts );
	testFindLSB3U( testCounts );
	testFindLSB4U( testCounts );
	testFindMSB1I( testCounts );
	testFindMSB2I( testCounts );
	testFindMSB3I( testCounts );
	testFindMSB4I( testCounts );
	testFindMSB1U( testCounts );
	testFindMSB2U( testCounts );
	testFindMSB3U( testCounts );
	testFindMSB4U( testCounts );
	testAtomicAddI( testCounts );
	testAtomicAddU( testCounts );
	testAtomicMinI( testCounts );
	testAtomicMinU( testCounts );
	testAtomicMaxI( testCounts );
	testAtomicMaxU( testCounts );
	testAtomicAndI( testCounts );
	testAtomicAndU( testCounts );
	testAtomicOrI( testCounts );
	testAtomicOrU( testCounts );
	testAtomicXorI( testCounts );
	testAtomicXorU( testCounts );
	testAtomicExchangeI( testCounts );
	testAtomicExchangeU( testCounts );
	testAtomicCompSwapI( testCounts );
	testAtomicCompSwapU( testCounts );
	testDFdx1( testCounts );
	testDFdx2( testCounts );
	testDFdx3( testCounts );
	testDFdx4( testCounts );
	testDFdxCoarse1( testCounts );
	testDFdxCoarse2( testCounts );
	testDFdxCoarse3( testCounts );
	testDFdxCoarse4( testCounts );
	testDFdxFine1( testCounts );
	testDFdxFine2( testCounts );
	testDFdxFine3( testCounts );
	testDFdxFine4( testCounts );
	testDFdy1( testCounts );
	testDFdy2( testCounts );
	testDFdy3( testCounts );
	testDFdy4( testCounts );
	testDFdyCoarse1( testCounts );
	testDFdyCoarse2( testCounts );
	testDFdyCoarse3( testCounts );
	testDFdyCoarse4( testCounts );
	testDFdyFine1( testCounts );
	testDFdyFine2( testCounts );
	testDFdyFine3( testCounts );
	testDFdyFine4( testCounts );
	testFwidth1( testCounts );
	testFwidth2( testCounts );
	testFwidth3( testCounts );
	testFwidth4( testCounts );
	testInterpolateAtCentroid1( testCounts );
	testInterpolateAtCentroid2( testCounts );
	testInterpolateAtCentroid3( testCounts );
	testInterpolateAtCentroid4( testCounts );
	testInterpolateAtSample1( testCounts );
	testInterpolateAtSample2( testCounts );
	testInterpolateAtSample3( testCounts );
	testInterpolateAtSample4( testCounts );
	testInterpolateAtOffset1( testCounts );
	testInterpolateAtOffset2( testCounts );
	testInterpolateAtOffset3( testCounts );
	testInterpolateAtOffset4( testCounts );
	sdwTestSuiteEnd();
}
