#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	template< typename ValueT >
	void testDegreesT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDegrees" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = degrees( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDegrees )
	{
		sdwTestBegin( "testDegrees" );
		testDegreesT< sdw::Float >( "1F", testCounts );
		testDegreesT< sdw::Vec2 >( "2F", testCounts );
		testDegreesT< sdw::Vec3 >( "3F", testCounts );
		testDegreesT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testRadiansT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testRadians" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = radians( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testRadians )
	{
		sdwTestBegin( "testRadians" );
		testRadiansT< sdw::Float >( "1F", testCounts );
		testRadiansT< sdw::Vec2 >( "2F", testCounts );
		testRadiansT< sdw::Vec3 >( "3F", testCounts );
		testRadiansT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testCoshT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testCosh" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = cosh( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testCosh )
	{
		sdwTestBegin( "testCosh" );
		testCoshT< sdw::Float >( "1F", testCounts );
		testCoshT< sdw::Vec2 >( "2F", testCounts );
		testCoshT< sdw::Vec3 >( "3F", testCounts );
		testCoshT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSinhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testSinh" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = sinh( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSinh )
	{
		sdwTestBegin( "testSinh" );
		testSinhT< sdw::Float >( "1F", testCounts );
		testSinhT< sdw::Vec2 >( "2F", testCounts );
		testSinhT< sdw::Vec3 >( "3F", testCounts );
		testSinhT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testTanhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testTanh" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = tanh( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testTanh )
	{
		sdwTestBegin( "testTanh" );
		testTanhT< sdw::Float >( "1F", testCounts );
		testTanhT< sdw::Vec2 >( "2F", testCounts );
		testTanhT< sdw::Vec3 >( "3F", testCounts );
		testTanhT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testCosT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testCos" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = cos( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testCos )
	{
		sdwTestBegin( "testCos" );
		testCosT< sdw::Float >( "1F", testCounts );
		testCosT< sdw::Vec2 >( "2F", testCounts );
		testCosT< sdw::Vec3 >( "3F", testCounts );
		testCosT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testSin" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = sin( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSin )
	{
		sdwTestBegin( "testSin" );
		testSinT< sdw::Float >( "1F", testCounts );
		testSinT< sdw::Vec2 >( "2F", testCounts );
		testSinT< sdw::Vec3 >( "3F", testCounts );
		testSinT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testTanT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testTan" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = tan( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testTan )
	{
		sdwTestBegin( "testTan" );
		testTanT< sdw::Float >( "1F", testCounts );
		testTanT< sdw::Vec2 >( "2F", testCounts );
		testTanT< sdw::Vec3 >( "3F", testCounts );
		testTanT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testACosT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testACos" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = acos( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testACos )
	{
		sdwTestBegin( "testACos" );
		testACosT< sdw::Float >( "1F", testCounts );
		testACosT< sdw::Vec2 >( "2F", testCounts );
		testACosT< sdw::Vec3 >( "3F", testCounts );
		testACosT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testASinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testASin" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = asin( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testASin )
	{
		sdwTestBegin( "testASin" );
		testASinT< sdw::Float >( "1F", testCounts );
		testASinT< sdw::Vec2 >( "2F", testCounts );
		testASinT< sdw::Vec3 >( "3F", testCounts );
		testASinT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testATanT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testATan" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = atan( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testATan )
	{
		sdwTestBegin( "testATan" );
		testATanT< sdw::Float >( "1F", testCounts );
		testATanT< sdw::Vec2 >( "2F", testCounts );
		testATanT< sdw::Vec3 >( "3F", testCounts );
		testATanT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testATan2T( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testATan2" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto y = writer.declLocale< ValueT >( "y" );
					auto x = writer.declLocale< ValueT >( "x" );
					x = atan2( y, x );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testATan2 )
	{
		sdwTestBegin( "testATan2" );
		testATan2T< sdw::Float >( "1F", testCounts );
		testATan2T< sdw::Vec2 >( "2F", testCounts );
		testATan2T< sdw::Vec3 >( "3F", testCounts );
		testATan2T< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testACoshT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testACosh" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = acosh( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testACosh )
	{
		sdwTestBegin( "testACosh" );
		testACoshT< sdw::Float >( "1F", testCounts );
		testACoshT< sdw::Vec2 >( "2F", testCounts );
		testACoshT< sdw::Vec3 >( "3F", testCounts );
		testACoshT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testASinhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testASinh" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = asinh( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testASinh )
	{
		sdwTestBegin( "testASinh" );
		testASinhT< sdw::Float >( "1F", testCounts );
		testASinhT< sdw::Vec2 >( "2F", testCounts );
		testASinhT< sdw::Vec3 >( "3F", testCounts );
		testASinhT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testATanhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testATanh" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = atanh( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testATanh )
	{
		sdwTestBegin( "testATanh" );
		testATanhT< sdw::Float >( "1F", testCounts );
		testATanhT< sdw::Vec2 >( "2F", testCounts );
		testATanhT< sdw::Vec3 >( "3F", testCounts );
		testATanhT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testPowT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testPow" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					v1 = pow( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testPow )
	{
		sdwTestBegin( "testPow" );
		testPowT< sdw::Float >( "1F", testCounts );
		testPowT< sdw::Vec2 >( "2F", testCounts );
		testPowT< sdw::Vec3 >( "3F", testCounts );
		testPowT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testExpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testExp" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = exp( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testExp )
	{
		sdwTestBegin( "testExp" );
		testExpT< sdw::Float >( "1F", testCounts );
		testExpT< sdw::Vec2 >( "2F", testCounts );
		testExpT< sdw::Vec3 >( "3F", testCounts );
		testExpT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testLogT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testLog" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = log( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testLog )
	{
		sdwTestBegin( "testLog" );
		testLogT< sdw::Float >( "1F", testCounts );
		testLogT< sdw::Vec2 >( "2F", testCounts );
		testLogT< sdw::Vec3 >( "3F", testCounts );
		testLogT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testExp2T( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testExp2_" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = exp2( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testExp2 )
	{
		sdwTestBegin( "testExp2" );
		testExp2T< sdw::Float >( "1F", testCounts );
		testExp2T< sdw::Vec2 >( "2F", testCounts );
		testExp2T< sdw::Vec3 >( "3F", testCounts );
		testExp2T< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testLog2T( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testLog2_" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = log2( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testLog2 )
	{
		sdwTestBegin( "testLog2" );
		testLog2T< sdw::Float >( "1F", testCounts );
		testLog2T< sdw::Vec2 >( "2F", testCounts );
		testLog2T< sdw::Vec3 >( "3F", testCounts );
		testLog2T< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSqrtT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testSqrt" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = sqrt( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSqrt )
	{
		sdwTestBegin( "testSqrt" );
		testSqrtT< sdw::Float >( "1F", testCounts );
		testSqrtT< sdw::Vec2 >( "2F", testCounts );
		testSqrtT< sdw::Vec3 >( "3F", testCounts );
		testSqrtT< sdw::Vec4 >( "4F", testCounts );
		testSqrtT< sdw::Double >( "1D", testCounts );
		testSqrtT< sdw::DVec2 >( "2D", testCounts );
		testSqrtT< sdw::DVec3 >( "3D", testCounts );
		testSqrtT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testInverseSqrtT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testInverseSqrt" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = inverseSqrt( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testInverseSqrt )
	{
		sdwTestBegin( "testInverseSqrt" );
		testInverseSqrtT< sdw::Float >( "1F", testCounts );
		testInverseSqrtT< sdw::Vec2 >( "2F", testCounts );
		testInverseSqrtT< sdw::Vec3 >( "3F", testCounts );
		testInverseSqrtT< sdw::Vec4 >( "4F", testCounts );
		testInverseSqrtT< sdw::Double >( "1D", testCounts );
		testInverseSqrtT< sdw::DVec2 >( "2D", testCounts );
		testInverseSqrtT< sdw::DVec3 >( "3D", testCounts );
		testInverseSqrtT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAbsT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAbs" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = abs( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAbs )
	{
		sdwTestBegin( "testAbs" );
		testAbsT< sdw::Float >( "1F", testCounts );
		testAbsT< sdw::Vec2 >( "2F", testCounts );
		testAbsT< sdw::Vec3 >( "3F", testCounts );
		testAbsT< sdw::Vec4 >( "4F", testCounts );
		testAbsT< sdw::Double >( "1D", testCounts );
		testAbsT< sdw::DVec2 >( "2D", testCounts );
		testAbsT< sdw::DVec3 >( "3D", testCounts );
		testAbsT< sdw::DVec4 >( "4D", testCounts );
		testAbsT< sdw::Int >( "1I", testCounts );
		testAbsT< sdw::IVec2 >( "2I", testCounts );
		testAbsT< sdw::IVec3 >( "3I", testCounts );
		testAbsT< sdw::IVec4 >( "4I", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSignT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testSign" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = sign( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSign )
	{
		sdwTestBegin( "testSign" );
		testSignT< sdw::Float >( "1F", testCounts );
		testSignT< sdw::Vec2 >( "2F", testCounts );
		testSignT< sdw::Vec3 >( "3F", testCounts );
		testSignT< sdw::Vec4 >( "4F", testCounts );
		testSignT< sdw::Double >( "1D", testCounts );
		testSignT< sdw::DVec2 >( "2D", testCounts );
		testSignT< sdw::DVec3 >( "3D", testCounts );
		testSignT< sdw::DVec4 >( "4D", testCounts );
		testSignT< sdw::Int >( "1I", testCounts );
		testSignT< sdw::IVec2 >( "2I", testCounts );
		testSignT< sdw::IVec3 >( "3I", testCounts );
		testSignT< sdw::IVec4 >( "4I", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFloorT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFloor" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = floor( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFloor )
	{
		sdwTestBegin( "testFloor" );
		testFloorT< sdw::Float >( "1F", testCounts );
		testFloorT< sdw::Vec2 >( "2F", testCounts );
		testFloorT< sdw::Vec3 >( "3F", testCounts );
		testFloorT< sdw::Vec4 >( "4F", testCounts );
		testFloorT< sdw::Double >( "1D", testCounts );
		testFloorT< sdw::DVec2 >( "2D", testCounts );
		testFloorT< sdw::DVec3 >( "3D", testCounts );
		testFloorT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testTruncT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testTrunc" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = trunc( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testTrunc )
	{
		sdwTestBegin( "testTrunc" );
		testTruncT< sdw::Float >( "1F", testCounts );
		testTruncT< sdw::Vec2 >( "2F", testCounts );
		testTruncT< sdw::Vec3 >( "3F", testCounts );
		testTruncT< sdw::Vec4 >( "4F", testCounts );
		testTruncT< sdw::Double >( "1D", testCounts );
		testTruncT< sdw::DVec2 >( "2D", testCounts );
		testTruncT< sdw::DVec3 >( "3D", testCounts );
		testTruncT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testRoundT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testRound" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = round( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testRound )
	{
		sdwTestBegin( "testRound" );
		testRoundT< sdw::Float >( "1F", testCounts );
		testRoundT< sdw::Vec2 >( "2F", testCounts );
		testRoundT< sdw::Vec3 >( "3F", testCounts );
		testRoundT< sdw::Vec4 >( "4F", testCounts );
		testRoundT< sdw::Double >( "1D", testCounts );
		testRoundT< sdw::DVec2 >( "2D", testCounts );
		testRoundT< sdw::DVec3 >( "3D", testCounts );
		testRoundT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testRoundEvenT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testRoundEven" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = roundEven( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testRoundEven )
	{
		sdwTestBegin( "testRoundEven" );
		testRoundEvenT< sdw::Float >( "1F", testCounts );
		testRoundEvenT< sdw::Vec2 >( "2F", testCounts );
		testRoundEvenT< sdw::Vec3 >( "3F", testCounts );
		testRoundEvenT< sdw::Vec4 >( "4F", testCounts );
		testRoundEvenT< sdw::Double >( "1D", testCounts );
		testRoundEvenT< sdw::DVec2 >( "2D", testCounts );
		testRoundEvenT< sdw::DVec3 >( "3D", testCounts );
		testRoundEvenT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testCeilT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testCeil" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = ceil( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testCeil )
	{
		sdwTestBegin( "testCeil" );
		testCeilT< sdw::Float >( "1F", testCounts );
		testCeilT< sdw::Vec2 >( "2F", testCounts );
		testCeilT< sdw::Vec3 >( "3F", testCounts );
		testCeilT< sdw::Vec4 >( "4F", testCounts );
		testCeilT< sdw::Double >( "1D", testCounts );
		testCeilT< sdw::DVec2 >( "2D", testCounts );
		testCeilT< sdw::DVec3 >( "3D", testCounts );
		testCeilT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFractT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFract" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					v = fract( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFract )
	{
		sdwTestBegin( "testFract" );
		testFractT< sdw::Float >( "1F", testCounts );
		testFractT< sdw::Vec2 >( "2F", testCounts );
		testFractT< sdw::Vec3 >( "3F", testCounts );
		testFractT< sdw::Vec4 >( "4F", testCounts );
		testFractT< sdw::Double >( "1D", testCounts );
		testFractT< sdw::DVec2 >( "2D", testCounts );
		testFractT< sdw::DVec3 >( "3D", testCounts );
		testFractT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testModT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testMod" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					v1 = mod( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testMod )
	{
		sdwTestBegin( "testMod" );
		testModT< sdw::Float >( "1F", testCounts );
		testModT< sdw::Vec2 >( "2F", testCounts );
		testModT< sdw::Vec3 >( "3F", testCounts );
		testModT< sdw::Vec4 >( "4F", testCounts );
		testModT< sdw::Double >( "1D", testCounts );
		testModT< sdw::DVec2 >( "2D", testCounts );
		testModT< sdw::DVec3 >( "3D", testCounts );
		testModT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testModfT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testModf" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					v1 = modf( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testModf )
	{
		sdwTestBegin( "testModf" );
		testModfT< sdw::Float >( "1F", testCounts );
		testModfT< sdw::Vec2 >( "2F", testCounts );
		testModfT< sdw::Vec3 >( "3F", testCounts );
		testModfT< sdw::Vec4 >( "4F", testCounts );
		testModfT< sdw::Double >( "1D", testCounts );
		testModfT< sdw::DVec2 >( "2D", testCounts );
		testModfT< sdw::DVec3 >( "3D", testCounts );
		testModfT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testMinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testMin" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					v1 = min( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testMin )
	{
		sdwTestBegin( "testMin" );
		testMinT< sdw::Float >( "1F", testCounts );
		testMinT< sdw::Vec2 >( "2F", testCounts );
		testMinT< sdw::Vec3 >( "3F", testCounts );
		testMinT< sdw::Vec4 >( "4F", testCounts );
		testMinT< sdw::Double >( "1D", testCounts );
		testMinT< sdw::DVec2 >( "2D", testCounts );
		testMinT< sdw::DVec3 >( "3D", testCounts );
		testMinT< sdw::DVec4 >( "4D", testCounts );
		testMinT< sdw::Int >( "1I", testCounts );
		testMinT< sdw::IVec2 >( "2I", testCounts );
		testMinT< sdw::IVec3 >( "3I", testCounts );
		testMinT< sdw::IVec4 >( "4I", testCounts );
		testMinT< sdw::UInt >( "1U", testCounts );
		testMinT< sdw::UVec2 >( "2U", testCounts );
		testMinT< sdw::UVec3 >( "3U", testCounts );
		testMinT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testMaxT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testMax" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					v1 = max( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testMax )
	{
		sdwTestBegin( "testMax" );
		testMaxT< sdw::Float >( "1F", testCounts );
		testMaxT< sdw::Vec2 >( "2F", testCounts );
		testMaxT< sdw::Vec3 >( "3F", testCounts );
		testMaxT< sdw::Vec4 >( "4F", testCounts );
		testMaxT< sdw::Double >( "1D", testCounts );
		testMaxT< sdw::DVec2 >( "2D", testCounts );
		testMaxT< sdw::DVec3 >( "3D", testCounts );
		testMaxT< sdw::DVec4 >( "4D", testCounts );
		testMaxT< sdw::Int >( "1I", testCounts );
		testMaxT< sdw::IVec2 >( "2I", testCounts );
		testMaxT< sdw::IVec3 >( "3I", testCounts );
		testMaxT< sdw::IVec4 >( "4I", testCounts );
		testMaxT< sdw::UInt >( "1U", testCounts );
		testMaxT< sdw::UVec2 >( "2U", testCounts );
		testMaxT< sdw::UVec3 >( "3U", testCounts );
		testMaxT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testClampT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testClamp" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					auto v3 = writer.declLocale< ValueT >( "v3" );
					v1 = clamp( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testClamp )
	{
		sdwTestBegin( "testClamp" );
		testClampT< sdw::Float >( "1F", testCounts );
		testClampT< sdw::Vec2 >( "2F", testCounts );
		testClampT< sdw::Vec3 >( "3F", testCounts );
		testClampT< sdw::Vec4 >( "4F", testCounts );
		testClampT< sdw::Double >( "1D", testCounts );
		testClampT< sdw::DVec2 >( "2D", testCounts );
		testClampT< sdw::DVec3 >( "3D", testCounts );
		testClampT< sdw::DVec4 >( "4D", testCounts );
		testClampT< sdw::Int32 >( "1I", testCounts );
		testClampT< sdw::I32Vec2 >( "2I", testCounts );
		testClampT< sdw::I32Vec3 >( "3I", testCounts );
		testClampT< sdw::I32Vec4 >( "4I", testCounts );
		testClampT< sdw::UInt32 >( "1U", testCounts );
		testClampT< sdw::U32Vec2 >( "2U", testCounts );
		testClampT< sdw::U32Vec3 >( "3U", testCounts );
		testClampT< sdw::U32Vec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testMixT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testMix" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					auto v3 = writer.declLocale< ValueT >( "v3" );
					v1 = mix( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testMix )
	{
		sdwTestBegin( "testMix" );
		testMixT< sdw::Float >( "1F", testCounts );
		testMixT< sdw::Vec2 >( "2F", testCounts );
		testMixT< sdw::Vec3 >( "3F", testCounts );
		testMixT< sdw::Vec4 >( "4F", testCounts );
		testMixT< sdw::Double >( "1D", testCounts );
		testMixT< sdw::DVec2 >( "2D", testCounts );
		testMixT< sdw::DVec3 >( "3D", testCounts );
		testMixT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testStepT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testStep" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					v1 = step( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testStep )
	{
		sdwTestBegin( "testStep" );
		testStepT< sdw::Float >( "1F", testCounts );
		testStepT< sdw::Vec2 >( "2F", testCounts );
		testStepT< sdw::Vec3 >( "3F", testCounts );
		testStepT< sdw::Vec4 >( "4F", testCounts );
		testStepT< sdw::Double >( "1D", testCounts );
		testStepT< sdw::DVec2 >( "2D", testCounts );
		testStepT< sdw::DVec3 >( "3D", testCounts );
		testStepT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSmoothStepT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testSmoothStep" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					auto v3 = writer.declLocale< ValueT >( "v3" );
					v1 = smoothStep( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSmoothStep )
	{
		sdwTestBegin( "testSmoothStep" );
		testSmoothStepT< sdw::Float >( "1F", testCounts );
		testSmoothStepT< sdw::Vec2 >( "2F", testCounts );
		testSmoothStepT< sdw::Vec3 >( "3F", testCounts );
		testSmoothStepT< sdw::Vec4 >( "4F", testCounts );
		testSmoothStepT< sdw::Double >( "1D", testCounts );
		testSmoothStepT< sdw::DVec2 >( "2D", testCounts );
		testSmoothStepT< sdw::DVec3 >( "3D", testCounts );
		testSmoothStepT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testIsnanT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testIsnan" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					writer.declLocale( "r", sdw::isnan( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testIsnan )
	{
		sdwTestBegin( "testIsnan" );
		testIsnanT< sdw::Float >( "1F", testCounts );
		testIsnanT< sdw::Vec2 >( "2F", testCounts );
		testIsnanT< sdw::Vec3 >( "3F", testCounts );
		testIsnanT< sdw::Vec4 >( "4F", testCounts );
		testIsnanT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testIsinfT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testIsinf" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					writer.declLocale( "r", sdw::isinf( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testIsinf )
	{
		sdwTestBegin( "testIsinf" );
		testIsinfT< sdw::Float >( "1F", testCounts );
		testIsinfT< sdw::Vec2 >( "2F", testCounts );
		testIsinfT< sdw::Vec3 >( "3F", testCounts );
		testIsinfT< sdw::Vec4 >( "4F", testCounts );
		testIsinfT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFloatBitsToIntT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFloatBitsToInt" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFloatBitsToInt )
	{
		sdwTestBegin( "testFloatBitsToInt" );
		testFloatBitsToIntT< sdw::Float >( "1F", testCounts );
		testFloatBitsToIntT< sdw::Vec2 >( "2F", testCounts );
		testFloatBitsToIntT< sdw::Vec3 >( "3F", testCounts );
		testFloatBitsToIntT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFloatBitsToUIntT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFloatBitsToUInt" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto res = writer.declLocale( "res"
						, floatBitsToUInt( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFloatBitsToUInt )
	{
		sdwTestBegin( "testFloatBitsToUInt" );
		testFloatBitsToUIntT< sdw::Float >( "1F", testCounts );
		testFloatBitsToUIntT< sdw::Vec2 >( "2F", testCounts );
		testFloatBitsToUIntT< sdw::Vec3 >( "3F", testCounts );
		testFloatBitsToUIntT< sdw::Vec4 >( "4F", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testIntBitsToFloatT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testIntBitsToFloat" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto res = writer.declLocale( "res"
						, intBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testIntBitsToFloat )
	{
		sdwTestBegin( "testIntBitsToFloat" );
		testIntBitsToFloatT< sdw::Int >( "1I", testCounts );
		testIntBitsToFloatT< sdw::IVec2 >( "2I", testCounts );
		testIntBitsToFloatT< sdw::IVec3 >( "3I", testCounts );
		testIntBitsToFloatT< sdw::IVec4 >( "4I", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testUIntBitsToFloatT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testUIntBitsToFloat" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto res = writer.declLocale( "res"
						, uintBitsToFloat( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testUIntBitsToFloat )
	{
		sdwTestBegin( "testUIntBitsToFloat" );
		testUIntBitsToFloatT< sdw::UInt >( "1U", testCounts );
		testUIntBitsToFloatT< sdw::UVec2 >( "2U", testCounts );
		testUIntBitsToFloatT< sdw::UVec3 >( "3U", testCounts );
		testUIntBitsToFloatT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFmaT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFma" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					auto v3 = writer.declLocale< ValueT >( "v3" );
					v1 = fma( v1, v2, v3 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFma )
	{
		sdwTestBegin( "testFma" );
		testFmaT< sdw::Float >( "1F", testCounts );
		testFmaT< sdw::Vec2 >( "2F", testCounts );
		testFmaT< sdw::Vec3 >( "3F", testCounts );
		testFmaT< sdw::Vec4 >( "4F", testCounts );
		testFmaT< sdw::Double >( "1D", testCounts );
		testFmaT< sdw::DVec2 >( "2D", testCounts );
		testFmaT< sdw::DVec3 >( "3D", testCounts );
		testFmaT< sdw::DVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT, typename ValueU >
	void testFrexpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFrexp" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueU >( "v2" );
					v1 = frexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFrexp )
	{
		sdwTestBegin( "testFrexp" );
		testFrexpT< sdw::Float, sdw::Int >( "1F", testCounts );
		testFrexpT< sdw::Vec2, sdw::IVec2 >( "2F", testCounts );
		testFrexpT< sdw::Vec3, sdw::IVec3 >( "3F", testCounts );
		testFrexpT< sdw::Vec4, sdw::IVec4 >( "4F", testCounts );
		testFrexpT< sdw::Double, sdw::Int >( "1D", testCounts );
		testFrexpT< sdw::DVec2, sdw::IVec2 >( "2D", testCounts );
		testFrexpT< sdw::DVec3, sdw::IVec3 >( "3D", testCounts );
		testFrexpT< sdw::DVec4, sdw::IVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT, typename ValueU >
	void testLdexpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testLdexp" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueU >( "v2" );
					v1 = ldexp( v1, v2 );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testLdexp )
	{
		sdwTestBegin( "testLdexp" );
		testLdexpT< sdw::Float, sdw::Int >( "1F", testCounts );
		testLdexpT< sdw::Vec2, sdw::IVec2 >( "2F", testCounts );
		testLdexpT< sdw::Vec3, sdw::IVec3 >( "3F", testCounts );
		testLdexpT< sdw::Vec4, sdw::IVec4 >( "4F", testCounts );
		testLdexpT< sdw::Double, sdw::Int >( "1D", testCounts );
		testLdexpT< sdw::DVec2, sdw::IVec2 >( "2D", testCounts );
		testLdexpT< sdw::DVec3, sdw::IVec3 >( "3D", testCounts );
		testLdexpT< sdw::DVec4, sdw::IVec4 >( "4D", testCounts );
		sdwTestEnd();
	}

	TEST_F( SDWTest, testPackDouble2x32 )
	{
		sdwTestBegin( "testPackDouble2x32" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UVec2 >( "v" );
					auto r = writer.declLocale< Double >( "r" );
					r = packDouble2x32( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testPackHalf2x16 )
	{
		sdwTestBegin( "testPackHalf2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packHalf2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testPackSnorm2x16 )
	{
		sdwTestBegin( "testPackSnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testPackUnorm2x16 )
	{
		sdwTestBegin( "testPackUnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec2 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testPackSnorm4x8 )
	{
		sdwTestBegin( "testPackSnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packSnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testPackUnorm4x8 )
	{
		sdwTestBegin( "testPackUnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					auto r = writer.declLocale< UInt >( "r" );
					r = packUnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testUnpackDouble2x32 )
	{
		sdwTestBegin( "testUnpackDouble2x32" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< Double >( "v" );
					auto r = writer.declLocale< UVec2 >( "r" );
					r = unpackDouble2x32( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testUnpackHalf2x16 )
	{
		sdwTestBegin( "testUnpackHalf2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackHalf2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testUnpackSnorm2x16 )
	{
		sdwTestBegin( "testUnpackSnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackSnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testUnpackUnorm2x16 )
	{
		sdwTestBegin( "testUnpackUnorm2x16" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec2 >( "r" );
					r = unpackUnorm2x16( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testUnpackSnorm4x8 )
	{
		sdwTestBegin( "testUnpackSnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackSnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testUnpackUnorm4x8 )
	{
		sdwTestBegin( "testUnpackUnorm4x8" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< UInt >( "v" );
					auto r = writer.declLocale< Vec4 >( "r" );
					r = unpackUnorm4x8( v );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	template< typename ValueT >
	void testLengthT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testLength" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					writer.declLocale( "r", length( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testLength )
	{
		sdwTestBegin( "testLength" );
		testLengthT< sdw::Float >( "1F", testCounts );
		testLengthT< sdw::Vec2 >( "2F", testCounts );
		testLengthT< sdw::Vec3 >( "3F", testCounts );
		testLengthT< sdw::Vec4 >( "4F", testCounts );
		testLengthT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDistanceT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testDistance" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					writer.declLocale( "r", distance( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testDistance )
	{
		sdwTestBegin( "testDistance" );
		testDistanceT< sdw::Float >( "1F", testCounts );
		testDistanceT< sdw::Vec2 >( "2F", testCounts );
		testDistanceT< sdw::Vec3 >( "3F", testCounts );
		testDistanceT< sdw::Vec4 >( "4F", testCounts );
		testDistanceT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDotT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testDot" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					writer.declLocale( "r", dot( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testDot )
	{
		sdwTestBegin( "testDot" );
		testDotT< sdw::Vec2 >( "2F", testCounts );
		testDotT< sdw::Vec3 >( "3F", testCounts );
		testDotT< sdw::Vec4 >( "4F", testCounts );
		testDotT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testDotT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testDotT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testCrossT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testCross" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					writer.declLocale( "r", cross( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testCross )
	{
		sdwTestBegin( "testCross" );
		testCrossT< sdw::Vec3 >( "3F", testCounts );
		testCrossT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testNormalizeT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testNormalize" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					writer.declLocale( "r", normalize( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testNormalize )
	{
		sdwTestBegin( "testNormalize" );
		testNormalizeT< sdw::Float >( "1F", testCounts );
		testNormalizeT< sdw::Vec2 >( "2F", testCounts );
		testNormalizeT< sdw::Vec3 >( "3F", testCounts );
		testNormalizeT< sdw::Vec4 >( "4F", testCounts );
		testNormalizeT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testNormalizeT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testNormalizeT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testNormalizeT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFaceForwardT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testFaceForward" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					auto v3 = writer.declLocale< ValueT >( "v3" );
					writer.declLocale( "r", faceForward( v1, v2, v3 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testFaceForward )
	{
		sdwTestBegin( "testFaceForward" );
		testFaceForwardT< sdw::Float >( "1F", testCounts );
		testFaceForwardT< sdw::Vec2 >( "2F", testCounts );
		testFaceForwardT< sdw::Vec3 >( "3F", testCounts );
		testFaceForwardT< sdw::Vec4 >( "4F", testCounts );
		testFaceForwardT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testFaceForwardT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testFaceForwardT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testFaceForwardT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testReflectT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testReflect" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					writer.declLocale( "r", reflect( v1, v2 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testReflect )
	{
		sdwTestBegin( "testReflect" );
		testReflectT< sdw::Float >( "1F", testCounts );
		testReflectT< sdw::Vec2 >( "2F", testCounts );
		testReflectT< sdw::Vec3 >( "3F", testCounts );
		testReflectT< sdw::Vec4 >( "4F", testCounts );
		testReflectT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testReflectT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testReflectT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testReflectT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testRefractT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testRefract" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto v2 = writer.declLocale< ValueT >( "v2" );
					auto v3 = writer.declLocale< Float >( "v3" );
					writer.declLocale( "r", refract( v1, v2, v3 ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testRefract )
	{
		sdwTestBegin( "testRefract" );
		testRefractT< sdw::Float >( "1F", testCounts );
		testRefractT< sdw::Vec2 >( "2F", testCounts );
		testRefractT< sdw::Vec3 >( "3F", testCounts );
		testRefractT< sdw::Vec4 >( "4F", testCounts );
		testRefractT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testRefractT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testRefractT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testRefractT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testMatrixCompMultT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testMatrixCompMult" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, matrixCompMult( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testMatrixCompMult )
	{
		sdwTestBegin( "testMatrixCompMult" );
		testMatrixCompMultT< sdw::Mat2x2 >( "2x2F", testCounts );
		testMatrixCompMultT< sdw::Mat2x3 >( "2x3F", testCounts );
		testMatrixCompMultT< sdw::Mat2x4 >( "2x4F", testCounts );
		testMatrixCompMultT< sdw::Mat3x2 >( "3x2F", testCounts );
		testMatrixCompMultT< sdw::Mat3x3 >( "3x3F", testCounts );
		testMatrixCompMultT< sdw::Mat3x4 >( "3x4F", testCounts );
		testMatrixCompMultT< sdw::Mat4x2 >( "4x2F", testCounts );
		testMatrixCompMultT< sdw::Mat4x3 >( "4x3F", testCounts );
		testMatrixCompMultT< sdw::Mat4x4 >( "4x4F", testCounts );
		testMatrixCompMultT< sdw::DMat2x2 >( "2x2D", testCounts );
		testMatrixCompMultT< sdw::DMat2x3 >( "2x3D", testCounts );
		testMatrixCompMultT< sdw::DMat2x4 >( "2x4D", testCounts );
		testMatrixCompMultT< sdw::DMat3x2 >( "3x2D", testCounts );
		testMatrixCompMultT< sdw::DMat3x3 >( "3x3D", testCounts );
		testMatrixCompMultT< sdw::DMat3x4 >( "3x4D", testCounts );
		testMatrixCompMultT< sdw::DMat4x2 >( "4x2D", testCounts );
		testMatrixCompMultT< sdw::DMat4x3 >( "4x3D", testCounts );
		testMatrixCompMultT< sdw::DMat4x4 >( "4x4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testMatrixMultT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testMatrixMult" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lhs * rhs );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testMatrixMult )
	{
		sdwTestBegin( "testMatrixMult" );
		testMatrixMultT< sdw::Mat2x2 >( "2x2F", testCounts );
		testMatrixMultT< sdw::Mat3x3 >( "3x3F", testCounts );
		testMatrixMultT< sdw::Mat4x4 >( "4x4F", testCounts );;
		testMatrixMultT< sdw::DMat2x2 >( "2x2D", testCounts );
		testMatrixMultT< sdw::DMat3x3 >( "3x3D", testCounts );
		testMatrixMultT< sdw::DMat4x4 >( "4x4D", testCounts );
		sdwTestEnd();
	}

	template< typename LhsT, typename RhsT >
	void testOuterProductT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testOuterProduct" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< LhsT >( "lhs" );
					auto rhs = writer.declLocale< RhsT >( "rhs" );
					auto res = writer.declLocale( "res"
						, outerProduct( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testOuterProduct )
	{
		sdwTestBegin( "testOuterProduct" );
		testOuterProductT< sdw::Vec2, sdw::Vec2 >( "2x2F", testCounts );
		testOuterProductT< sdw::Vec2, sdw::Vec3 >( "2x3F", testCounts );
		testOuterProductT< sdw::Vec2, sdw::Vec4 >( "2x4F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec2 >( "3x2F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec3 >( "3x3F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec4 >( "3x4F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec2 >( "4x2F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec3 >( "4x3F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec4 >( "4x4F", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec2 >( "2x2D", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec3 >( "2x3D", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec4 >( "2x4D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec2 >( "3x2D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec3 >( "3x3D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec4 >( "3x4D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec2 >( "4x2D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec3 >( "4x3D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec4 >( "4x4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testTransposeT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testTranspose" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto v = writer.declLocale< ValueT >( "v" );
					auto r = writer.declLocale( "r"
						, transpose( v ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testTranspose )
	{
		sdwTestBegin( "testTranspose" );
		testTransposeT< sdw::Mat2x2 >( "2x2F", testCounts );
		testTransposeT< sdw::Mat2x3 >( "2x3F", testCounts );
		testTransposeT< sdw::Mat2x4 >( "2x4F", testCounts );
		testTransposeT< sdw::Mat3x2 >( "3x2F", testCounts );
		testTransposeT< sdw::Mat3x3 >( "3x3F", testCounts );
		testTransposeT< sdw::Mat3x4 >( "3x4F", testCounts );
		testTransposeT< sdw::Mat4x2 >( "4x2F", testCounts );
		testTransposeT< sdw::Mat4x3 >( "4x3F", testCounts );
		testTransposeT< sdw::Mat4x4 >( "4x4F", testCounts );
		testTransposeT< sdw::DMat2x2 >( "2x2D", testCounts );
		testTransposeT< sdw::DMat2x3 >( "2x3D", testCounts );
		testTransposeT< sdw::DMat2x4 >( "2x4D", testCounts );
		testTransposeT< sdw::DMat3x2 >( "3x2D", testCounts );
		testTransposeT< sdw::DMat3x3 >( "3x3D", testCounts );
		testTransposeT< sdw::DMat3x4 >( "3x4D", testCounts );
		testTransposeT< sdw::DMat4x2 >( "4x2D", testCounts );
		testTransposeT< sdw::DMat4x3 >( "4x3D", testCounts );
		testTransposeT< sdw::DMat4x4 >( "4x4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDeterminantT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testDeterminant" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto m = writer.declLocale< ValueT >( "m" );
					writer.declLocale( "r", determinant( m ) );
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testDeterminant )
	{
		sdwTestBegin( "testDeterminant" );
		testDeterminantT< sdw::Mat2x2 >( "2x2F", testCounts );
		testDeterminantT< sdw::Mat3x3 >( "3x3F", testCounts );
		testDeterminantT< sdw::Mat4x4 >( "4x4F", testCounts );
		testDeterminantT< sdw::DMat2x2 >( "2x2D", testCounts, Compilers_NoHLSL );
		testDeterminantT< sdw::DMat3x3 >( "3x3D", testCounts, Compilers_NoHLSL );
		testDeterminantT< sdw::DMat4x4 >( "4x4D", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testInverseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testInverse" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto m = writer.declLocale< ValueT >( "m" );
					writer.declLocale( "r", inverse( m ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testInverse )
	{
		sdwTestBegin( "testInverse" );
		testInverseT< sdw::Mat2x2 >( "2x2F", testCounts );
		testInverseT< sdw::Mat3x3 >( "3x3F", testCounts );
		testInverseT< sdw::Mat4x4 >( "4x4F", testCounts );
		testInverseT< sdw::DMat2x2 >( "2x2D", testCounts );
		testInverseT< sdw::DMat3x3 >( "3x3D", testCounts );
		testInverseT< sdw::DMat4x4 >( "4x4D", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testLessThanT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testLessThan" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThan( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testLessThan )
	{
		sdwTestBegin( "testLessThan" );
		testLessThanT< sdw::Vec2 >( "2F", testCounts );
		testLessThanT< sdw::Vec3 >( "3F", testCounts );
		testLessThanT< sdw::Vec4 >( "4F", testCounts );
		testLessThanT< sdw::DVec2 >( "2D", testCounts );
		testLessThanT< sdw::DVec3 >( "3D", testCounts );
		testLessThanT< sdw::DVec4 >( "4D", testCounts );
		testLessThanT< sdw::IVec2 >( "2I", testCounts );
		testLessThanT< sdw::IVec3 >( "3I", testCounts );
		testLessThanT< sdw::IVec4 >( "4I", testCounts );
		testLessThanT< sdw::UVec2 >( "2U", testCounts );
		testLessThanT< sdw::UVec3 >( "3U", testCounts );
		testLessThanT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testLessThanEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testLessThanEqual" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, lessThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testLessThanEqual )
	{
		sdwTestBegin( "testLessThanEqual" );
		testLessThanEqualT< sdw::Vec2 >( "2F", testCounts );
		testLessThanEqualT< sdw::Vec3 >( "3F", testCounts );
		testLessThanEqualT< sdw::Vec4 >( "4F", testCounts );
		testLessThanEqualT< sdw::DVec2 >( "2D", testCounts );
		testLessThanEqualT< sdw::DVec3 >( "3D", testCounts );
		testLessThanEqualT< sdw::DVec4 >( "4D", testCounts );
		testLessThanEqualT< sdw::IVec2 >( "2I", testCounts );
		testLessThanEqualT< sdw::IVec3 >( "3I", testCounts );
		testLessThanEqualT< sdw::IVec4 >( "4I", testCounts );
		testLessThanEqualT< sdw::UVec2 >( "2U", testCounts );
		testLessThanEqualT< sdw::UVec3 >( "3U", testCounts );
		testLessThanEqualT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testGreaterThanT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testGreaterThan" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThan( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testGreaterThan )
	{
		sdwTestBegin( "testGreaterThan" );
		testGreaterThanT< sdw::Vec2 >( "2F", testCounts );
		testGreaterThanT< sdw::Vec3 >( "3F", testCounts );
		testGreaterThanT< sdw::Vec4 >( "4F", testCounts );
		testGreaterThanT< sdw::DVec2 >( "2D", testCounts );
		testGreaterThanT< sdw::DVec3 >( "3D", testCounts );
		testGreaterThanT< sdw::DVec4 >( "4D", testCounts );
		testGreaterThanT< sdw::IVec2 >( "2I", testCounts );
		testGreaterThanT< sdw::IVec3 >( "3I", testCounts );
		testGreaterThanT< sdw::IVec4 >( "4I", testCounts );
		testGreaterThanT< sdw::UVec2 >( "2U", testCounts );
		testGreaterThanT< sdw::UVec3 >( "3U", testCounts );
		testGreaterThanT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testGreaterThanEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testGreaterThanEqual" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, greaterThanEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testGreaterThanEqual )
	{
		sdwTestBegin( "testGreaterThanEqual" );
		testGreaterThanEqualT< sdw::Vec2 >( "2F", testCounts );
		testGreaterThanEqualT< sdw::Vec3 >( "3F", testCounts );
		testGreaterThanEqualT< sdw::Vec4 >( "4F", testCounts );
		testGreaterThanEqualT< sdw::DVec2 >( "2D", testCounts );
		testGreaterThanEqualT< sdw::DVec3 >( "3D", testCounts );
		testGreaterThanEqualT< sdw::DVec4 >( "4D", testCounts );
		testGreaterThanEqualT< sdw::IVec2 >( "2I", testCounts );
		testGreaterThanEqualT< sdw::IVec3 >( "3I", testCounts );
		testGreaterThanEqualT< sdw::IVec4 >( "4I", testCounts );
		testGreaterThanEqualT< sdw::UVec2 >( "2U", testCounts );
		testGreaterThanEqualT< sdw::UVec3 >( "3U", testCounts );
		testGreaterThanEqualT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testEqual" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, equal( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testEqual )
	{
		sdwTestBegin( "testEqual" );
		testEqualT< sdw::Vec2 >( "2F", testCounts );
		testEqualT< sdw::Vec3 >( "3F", testCounts );
		testEqualT< sdw::Vec4 >( "4F", testCounts );
		testEqualT< sdw::DVec2 >( "2D", testCounts );
		testEqualT< sdw::DVec3 >( "3D", testCounts );
		testEqualT< sdw::DVec4 >( "4D", testCounts );
		testEqualT< sdw::IVec2 >( "2I", testCounts );
		testEqualT< sdw::IVec3 >( "3I", testCounts );
		testEqualT< sdw::IVec4 >( "4I", testCounts );
		testEqualT< sdw::UVec2 >( "2U", testCounts );
		testEqualT< sdw::UVec3 >( "3U", testCounts );
		testEqualT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testNotEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testNotEqual" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto lhs = writer.declLocale< ValueT >( "lhs" );
					auto rhs = writer.declLocale< ValueT >( "rhs" );
					auto res = writer.declLocale( "res"
						, notEqual( lhs, rhs ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testNotEqual )
	{
		sdwTestBegin( "testNotEqual" );
		testNotEqualT< sdw::Vec2 >( "2F", testCounts );
		testNotEqualT< sdw::Vec3 >( "3F", testCounts );
		testNotEqualT< sdw::Vec4 >( "4F", testCounts );
		testNotEqualT< sdw::DVec2 >( "2D", testCounts );
		testNotEqualT< sdw::DVec3 >( "3D", testCounts );
		testNotEqualT< sdw::DVec4 >( "4D", testCounts );
		testNotEqualT< sdw::IVec2 >( "2I", testCounts );
		testNotEqualT< sdw::IVec3 >( "3I", testCounts );
		testNotEqualT< sdw::IVec4 >( "4I", testCounts );
		testNotEqualT< sdw::UVec2 >( "2U", testCounts );
		testNotEqualT< sdw::UVec3 >( "3U", testCounts );
		testNotEqualT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAllT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAll" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, all( operand ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAll )
	{
		sdwTestBegin( "testAll" );
		testAllT< sdw::BVec2 >( "2", testCounts );
		testAllT< sdw::BVec3 >( "3", testCounts );
		testAllT< sdw::BVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAnyT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAny" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, any( operand ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAny )
	{
		sdwTestBegin( "testAny" );
		testAnyT< sdw::BVec2 >( "2", testCounts );
		testAnyT< sdw::BVec3 >( "3", testCounts );
		testAnyT< sdw::BVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testNotT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testNot" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto operand = writer.declLocale< ValueT >( "operand" );
					auto res = writer.declLocale( "res"
						, binNot( operand ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testNot )
	{
		sdwTestBegin( "testNot" );
		testNotT< sdw::BVec2 >( "2", testCounts );
		testNotT< sdw::BVec3 >( "3", testCounts );
		testNotT< sdw::BVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testUaddCarryT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testUaddCarry" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto y = writer.declLocale< ValueT >( "y" );
					auto c = writer.declLocale< ValueT >( "c" );
					auto r = writer.declLocale< ValueT >( "r"
						, uaddCarry( x, y, c ) );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testUaddCarry )
	{
		sdwTestBegin( "testUaddCarry" );
		testUaddCarryT< sdw::UInt >( "1", testCounts );
		testUaddCarryT< sdw::UVec2 >( "2", testCounts );
		testUaddCarryT< sdw::UVec3 >( "3", testCounts );
		testUaddCarryT< sdw::UVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testUsubBorrowT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testUsubBorrow" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto y = writer.declLocale< ValueT >( "y" );
					auto b = writer.declLocale< ValueT >( "b" );
					auto r = writer.declLocale< ValueT >( "r"
						, usubBorrow( x, y, b ) );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testUsubBorrow )
	{
		sdwTestBegin( "testUsubBorrow" );
		testUsubBorrowT< sdw::UInt >( "1", testCounts );
		testUsubBorrowT< sdw::UVec2 >( "2", testCounts );
		testUsubBorrowT< sdw::UVec3 >( "3", testCounts );
		testUsubBorrowT< sdw::UVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testUmulExtendedT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testUmulExtended" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto y = writer.declLocale< ValueT >( "y" );
					auto h = writer.declLocale< ValueT >( "h" );
					auto l = writer.declLocale< ValueT >( "l" );
					umulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testUmulExtended )
	{
		sdwTestBegin( "testUmulExtended" );
		testUmulExtendedT< sdw::UInt >( "1", testCounts );
		testUmulExtendedT< sdw::UVec2 >( "2", testCounts );
		testUmulExtendedT< sdw::UVec3 >( "3", testCounts );
		testUmulExtendedT< sdw::UVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testImulExtendedT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testImulExtended" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto y = writer.declLocale< ValueT >( "y" );
					auto h = writer.declLocale< ValueT >( "h" );
					auto l = writer.declLocale< ValueT >( "l" );
					imulExtended( x, y, h, l );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testImulExtended )
	{
		sdwTestBegin( "testImulExtended" );
		testImulExtendedT< sdw::Int >( "1", testCounts );
		testImulExtendedT< sdw::IVec2 >( "2", testCounts );
		testImulExtendedT< sdw::IVec3 >( "3", testCounts );
		testImulExtendedT< sdw::IVec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testBitfieldExtractT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testBitfieldExtract" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldExtract( x, o, b ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testBitfieldExtract )
	{
		sdwTestBegin( "testBitfieldExtract" );
		testBitfieldExtractT< sdw::Int >( "1I", testCounts );
		testBitfieldExtractT< sdw::IVec2 >( "2I", testCounts );
		testBitfieldExtractT< sdw::IVec3 >( "3I", testCounts );
		testBitfieldExtractT< sdw::IVec4 >( "4I", testCounts );
		testBitfieldExtractT< sdw::UInt >( "1U", testCounts );
		testBitfieldExtractT< sdw::UVec2 >( "2U", testCounts );
		testBitfieldExtractT< sdw::UVec3 >( "3U", testCounts );
		testBitfieldExtractT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testBitfieldInsertT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testBitfieldInsert" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto y = writer.declLocale< ValueT >( "y" );
					auto o = writer.declLocale< Int >( "o" );
					auto b = writer.declLocale< Int >( "b" );
					auto r = writer.declLocale( "r"
						, bitfieldInsert( x, y, o, b ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testBitfieldInsert )
	{
		sdwTestBegin( "testBitfieldInsert" );
		testBitfieldInsertT< sdw::Int >( "1I", testCounts );
		testBitfieldInsertT< sdw::IVec2 >( "2I", testCounts );
		testBitfieldInsertT< sdw::IVec3 >( "3I", testCounts );
		testBitfieldInsertT< sdw::IVec4 >( "4I", testCounts );
		testBitfieldInsertT< sdw::UInt >( "1U", testCounts );
		testBitfieldInsertT< sdw::UVec2 >( "2U", testCounts );
		testBitfieldInsertT< sdw::UVec3 >( "3U", testCounts );
		testBitfieldInsertT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testBitfieldReverseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testBitfieldReverse" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto r = writer.declLocale( "r"
						, bitfieldReverse( x ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testBitfieldReverse )
	{
		sdwTestBegin( "testBitfieldReverse" );
		testBitfieldReverseT< sdw::Int >( "1I", testCounts );
		testBitfieldReverseT< sdw::IVec2 >( "2I", testCounts );
		testBitfieldReverseT< sdw::IVec3 >( "3I", testCounts );
		testBitfieldReverseT< sdw::IVec4 >( "4I", testCounts );
		testBitfieldReverseT< sdw::UInt >( "1U", testCounts );
		testBitfieldReverseT< sdw::UVec2 >( "2U", testCounts );
		testBitfieldReverseT< sdw::UVec3 >( "3U", testCounts );
		testBitfieldReverseT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testBitCountT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testBitCount" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto r = writer.declLocale( "r"
						, bitCount( x ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testBitCount )
	{
		sdwTestBegin( "testBitCount" );
		testBitCountT< sdw::Int >( "1I", testCounts );
		testBitCountT< sdw::IVec2 >( "2I", testCounts );
		testBitCountT< sdw::IVec3 >( "3I", testCounts );
		testBitCountT< sdw::IVec4 >( "4I", testCounts );
		testBitCountT< sdw::UInt >( "1U", testCounts );
		testBitCountT< sdw::UVec2 >( "2U", testCounts );
		testBitCountT< sdw::UVec3 >( "3U", testCounts );
		testBitCountT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFindLSBT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFindLSB" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto r = writer.declLocale( "r"
						, findLSB( x ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFindLSB )
	{
		sdwTestBegin( "testFindLSB" );
		testFindLSBT< sdw::Int >( "1I", testCounts );
		testFindLSBT< sdw::IVec2 >( "2I", testCounts );
		testFindLSBT< sdw::IVec3 >( "3I", testCounts );
		testFindLSBT< sdw::IVec4 >( "4I", testCounts );
		testFindLSBT< sdw::UInt >( "1U", testCounts );
		testFindLSBT< sdw::UVec2 >( "2U", testCounts );
		testFindLSBT< sdw::UVec3 >( "3U", testCounts );
		testFindLSBT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFindMSBT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFindMSB" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x" );
					auto r = writer.declLocale( "r"
						, findMSB( x ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFindMSB )
	{
		sdwTestBegin( "testFindMSB" );
		testFindMSBT< sdw::Int >( "1I", testCounts );
		testFindMSBT< sdw::IVec2 >( "2I", testCounts );
		testFindMSBT< sdw::IVec3 >( "3I", testCounts );
		testFindMSBT< sdw::IVec4 >( "4I", testCounts );
		testFindMSBT< sdw::UInt >( "1U", testCounts );
		testFindMSBT< sdw::UVec2 >( "2U", testCounts );
		testFindMSBT< sdw::UVec3 >( "3U", testCounts );
		testFindMSBT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testAtomicAdd" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicAdd( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicAdd( bo[0].getMember< ValueT >( mbrName ), x );
					atomicAdd( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testAtomicAdd )
	{
		sdwTestBegin( "testAtomicAdd" );
		testAtomicAddT< sdw::Int >( "I", testCounts );
		testAtomicAddT< sdw::UInt >( "U", testCounts );
		testAtomicAddT< sdw::Float >( "F", testCounts );
		//testAtomicAddT< sdw::HVec2 >( "2H", testCounts, Compilers_NoHLSL );
		//testAtomicAddT< sdw::HVec4 >( "4H", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicMin" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicMin( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicMin( bo[0].getMember< ValueT >( mbrName ), x );
					atomicMin( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicMin )
	{
		sdwTestBegin( "testAtomicMin" );
		testAtomicMinT< sdw::Int >( "I", testCounts );
		testAtomicMinT< sdw::UInt >( "U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicMax" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicMax( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicMax( bo[0].getMember< ValueT >( mbrName ), x );
					atomicMax( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicMax )
	{
		sdwTestBegin( "testAtomicMax" );
		testAtomicMaxT< sdw::Int >( "I", testCounts );
		testAtomicMaxT< sdw::UInt >( "U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicAnd" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicAnd( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicAnd( bo[0].getMember< ValueT >( mbrName ), x );
					atomicAnd( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicAnd )
	{
		sdwTestBegin( "testAtomicAnd" );
		testAtomicAndT< sdw::Int >( "I", testCounts );
		testAtomicAndT< sdw::UInt >( "U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicOr" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicOr( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicOr( bo[0].getMember< ValueT >( mbrName ), x );
					atomicOr( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicOr )
	{
		sdwTestBegin( "testAtomicOr" );
		testAtomicOrT< sdw::Int >( "I", testCounts );
		testAtomicOrT< sdw::UInt >( "U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicXor" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicXor( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicXor( bo[0].getMember< ValueT >( mbrName ), x );
					atomicXor( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicXor )
	{
		sdwTestBegin( "testAtomicXor" );
		testAtomicXorT< sdw::Int >( "I", testCounts );
		testAtomicXorT< sdw::UInt >( "U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicExchangeT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		astOn( "testAtomicExchange" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto x = writer.declLocale< ValueT >( "x", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicExchange( bo[0].getMember< ValueT >( mbrName ), x ) );
					atomicExchange( bo[0].getMember< ValueT >( mbrName ), x );
					atomicExchange( bo[0].getMember< ValueT >( mbrName ), x ) * x;
				} );
			test::writeShader( writer
				, testCounts, compilers );
		}
	}

	TEST_F( SDWTest, testAtomicExchange )
	{
		sdwTestBegin( "testAtomicExchange" );
		testAtomicExchangeT< sdw::Int >( "I", testCounts );
		testAtomicExchangeT< sdw::UInt >( "U", testCounts );
		testAtomicExchangeT< sdw::Float >( "F", testCounts, Compilers_NoHLSL );
		//testAtomicExchangeT< sdw::HVec2 >( "2H", testCounts, Compilers_NoHLSL );
		//testAtomicExchangeT< sdw::HVec4 >( "4H", testCounts, Compilers_NoHLSL );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testAtomicCompSwapT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testAtomicCompSwap" + name );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			std::string const mbrName = "member";
			sdw::Struct type{ writer, "Type", ast::type::MemoryLayout::eStd140 };
			type.declMember< ValueT >( mbrName );
			type.end();
			sdw::ArrayStorageBufferT< sdw::StructInstance > bo{ writer, "Datas", type.getType(), 1u, 1u, true };
			writer.implementMainT< VoidT >( 1u, [&]( ComputeIn )
				{
					auto c = writer.declLocale< ValueT >( "c", test::getDefault< ValueT >( writer ) );
					auto v = writer.declLocale< ValueT >( "v", test::getDefault< ValueT >( writer ) );
					writer.declLocale( "r"
						, atomicCompSwap( bo[0].getMember< ValueT >( mbrName ), c, v ) );
					atomicCompSwap( bo[0].getMember< ValueT >( mbrName ), c, v );
					atomicCompSwap( bo[0].getMember< ValueT >( mbrName ), c, v ) * c;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testAtomicCompSwap )
	{
		sdwTestBegin( "testAtomicCompSwap" );
		testAtomicCompSwapT< sdw::Int >( "I", testCounts );
		testAtomicCompSwapT< sdw::UInt >( "U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDFdxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDFdx" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", dFdx( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDFdx )
	{
		sdwTestBegin( "testDFdx" );
		testDFdxT< sdw::Float >( "1", testCounts );
		testDFdxT< sdw::Vec2 >( "2", testCounts );
		testDFdxT< sdw::Vec3 >( "3", testCounts );
		testDFdxT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDFdxCoarseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDFdxCoarse" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", dFdxCoarse( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDFdxCoarse )
	{
		sdwTestBegin( "testDFdxCoarse" );
		testDFdxCoarseT< sdw::Float >( "1", testCounts );
		testDFdxCoarseT< sdw::Vec2 >( "2", testCounts );
		testDFdxCoarseT< sdw::Vec3 >( "3", testCounts );
		testDFdxCoarseT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDFdxFineT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDFdxFine" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", dFdxFine( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDFdxFine )
	{
		sdwTestBegin( "testDFdxFine" );
		testDFdxFineT< sdw::Float >( "1", testCounts );
		testDFdxFineT< sdw::Vec2 >( "2", testCounts );
		testDFdxFineT< sdw::Vec3 >( "3", testCounts );
		testDFdxFineT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDFdyT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDFdy" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", dFdy( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDFdy )
	{
		sdwTestBegin( "testDFdy" );
		testDFdyT< sdw::Float >( "1", testCounts );
		testDFdyT< sdw::Vec2 >( "2", testCounts );
		testDFdyT< sdw::Vec3 >( "3", testCounts );
		testDFdyT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDFdyCoarseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDFdyCoarse" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", dFdyCoarse( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDFdyCoarse )
	{
		sdwTestBegin( "testDFdyCoarse" );
		testDFdyCoarseT< sdw::Float >( "1", testCounts );
		testDFdyCoarseT< sdw::Vec2 >( "2", testCounts );
		testDFdyCoarseT< sdw::Vec3 >( "3", testCounts );
		testDFdyCoarseT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testDFdyFineT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testDFdyFine" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", dFdyFine( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testDFdyFine )
	{
		sdwTestBegin( "testDFdyFine" );
		testDFdyFineT< sdw::Float >( "1", testCounts );
		testDFdyFineT< sdw::Vec2 >( "2", testCounts );
		testDFdyFineT< sdw::Vec3 >( "3", testCounts );
		testDFdyFineT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testFwidthT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testFwidth" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto v1 = writer.declLocale< ValueT >( "v1" );
					auto r = writer.declLocale( "r", fwidth( v1 ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testFwidth )
	{
		sdwTestBegin( "testFwidth" );
		testFwidthT< sdw::Float >( "1", testCounts );
		testFwidthT< sdw::Vec2 >( "2", testCounts );
		testFwidthT< sdw::Vec3 >( "3", testCounts );
		testFwidthT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testInterpolateAtCentroidT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testInterpolateAtCentroid" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto inputs = writer.declInput< ValueT >( "inputs", 0u );
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto r = writer.declLocale( "r", interpolateAtCentroid( inputs ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testInterpolateAtCentroid )
	{
		sdwTestBegin( "testInterpolateAtCentroid" );
		testInterpolateAtCentroidT< sdw::Float >( "1", testCounts );
		testInterpolateAtCentroidT< sdw::Vec2 >( "2", testCounts );
		testInterpolateAtCentroidT< sdw::Vec3 >( "3", testCounts );
		testInterpolateAtCentroidT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testInterpolateAtSampleT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testInterpolateAtSample" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto inputs = writer.declInput< ValueT >( "inputs", 0u );
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto r = writer.declLocale( "r", interpolateAtSample( inputs, 0_i ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testInterpolateAtSample )
	{
		sdwTestBegin( "testInterpolateAtSample" );
		testInterpolateAtSampleT< sdw::Float >( "1", testCounts );
		testInterpolateAtSampleT< sdw::Vec2 >( "2", testCounts );
		testInterpolateAtSampleT< sdw::Vec3 >( "3", testCounts );
		testInterpolateAtSampleT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testInterpolateAtOffsetT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		astOn( "testInterpolateAtOffset" + name );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto inputs = writer.declInput< ValueT >( "inputs", 0u );
			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn, FragmentOut )
				{
					auto r = writer.declLocale( "r", interpolateAtOffset( inputs, vec2( -0.5_f ) ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_NoHLSL );
		}
	}

	TEST_F( SDWTest, testInterpolateAtOffset )
	{
		sdwTestBegin( "testInterpolateAtOffset" );
		testInterpolateAtOffsetT< sdw::Float >( "1", testCounts );
		testInterpolateAtOffsetT< sdw::Vec2 >( "2", testCounts );
		testInterpolateAtOffsetT< sdw::Vec3 >( "3", testCounts );
		testInterpolateAtOffsetT< sdw::Vec4 >( "4", testCounts );
		sdwTestEnd();
	}

	TEST_F( SDWTest, testBarrier )
	{
		sdwTestBegin( "testBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.barrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		{
			static constexpr uint32_t MaxPoints = 1u;
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[in.primitiveID].vtx.position.w();
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					writer.barrier();
					listOut.vtx.position = listIn[in.invocationID].vtx.position * 2.0_f;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testMemoryBarrier )
	{
		sdwTestBegin( "testMemoryBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testMemoryBarrierBuffer )
	{
		sdwTestBegin( "testMemoryBarrierBuffer" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrierBuffer();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testMemoryBarrierShared )
	{
		sdwTestBegin( "testMemoryBarrierShared" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrierShared();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testMemoryBarrierImage )
	{
		sdwTestBegin( "testMemoryBarrierImage" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.memoryBarrierImage();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testGroupMemoryBarrier )
	{
		sdwTestBegin( "testGroupMemoryBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.groupMemoryBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	template< sdw::var::Flag FlagT >
	struct PayloadT
		: public sdw::StructInstance
	{
		PayloadT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, meshletIndices{ getMemberArray< sdw::UInt >( "meshletIndices" ) }
		{
		}

		SDW_DeclStructInstance( , PayloadT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Payload"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "meshletIndices"
					, sdw::type::Kind::eUInt
					, 32u
					, ast::type::Struct::InvalidLocation );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Payload" );

			if ( result->empty() )
			{
				result->declMember( "meshletIndices"
					, sdw::type::Kind::eUInt
					, 32u );
			}

			return result;
		}

		sdw::Array< sdw::UInt > meshletIndices;
	};

	TEST_F( SDWTest, testSetMeshOutputCountsNV )
	{
		sdwTestBegin( "testSetMeshOutputCountsNV" );
		using namespace sdw;
		{
			sdw::MeshWriterNV writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshInNV in
					, TaskPayloadInNVT< PayloadT > payload
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshNVPrimitiveListOutT< VoidT > primOut )
				{
					auto index = writer.declLocale( "index"
						, payload.meshletIndices[0_u] );
					primOut.setMeshOutputCounts( 3_u, 1_u );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSetMeshOutputCounts )
	{
		sdwTestBegin( "testSetMeshOutputCounts" );
		using namespace sdw;
		{
			sdw::MeshWriterEXT writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT, VoidT, VoidT >( 32u, 1u, 1u
				, 64u
				, 126u
				, [&]( MeshInEXT in
					, TaskPayloadInEXTT< PayloadT > payload
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshEXTPrimitiveListOutT< VoidT > primOut )
				{
					auto index = writer.declLocale( "index"
						, payload.meshletIndices[0_u] );
					primOut.setMeshOutputCounts( 3_u, 1_u );
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts, Compilers_NoGLSL );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testDispatchMeshNV )
	{
		sdwTestBegin( "testDispatchMeshNV" );
		using namespace sdw;
		{
			sdw::TaskWriterNV writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( 32u
				, TaskPayloadOutNVT< PayloadT >{ writer }
				, [&]( TaskInNV in
					, TaskPayloadOutNVT< PayloadT > payload )
				{
					payload.meshletIndices[0_u] = 1_u;
					payload.dispatchMesh( 1_u );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testDispatchMesh )
	{
		sdwTestBegin( "testDispatchMesh" );
		using namespace sdw;
		{
			sdw::TaskWriterEXT writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( 32u, 1u, 1u
				, TaskPayloadOutEXTT< PayloadT >{ writer }
				, [&]( TaskInEXT in
					, TaskPayloadOutEXTT< PayloadT > payload )
				{
					payload.meshletIndices[0_u] = 1_u;
					payload.dispatchMesh( 1_u, 1_u, 1_u );
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts, Compilers_NoGLSL );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testHelperInvocation )
	{
		sdwTestBegin( "testHelperInvocation" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< sdw::VoidT, sdw::VoidT >( [&]( sdw::FragmentInT< sdw::VoidT >
				, sdw::FragmentOutT< sdw::VoidT > )
				{
					auto isHelper = writer.declLocale( "isHelper"
						, helperInvocation( writer ) );
				} );
			test::writeShader( writer
				, testCounts, Compilers_SPIRV );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBarrier )
	{
		sdwTestBegin( "testSubgroupBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrier )
	{
		sdwTestBegin( "testSubgroupMemoryBarrier" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrier();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrierBuffer )
	{
		sdwTestBegin( "testSubgroupMemoryBarrierBuffer" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrierBuffer();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrierShared )
	{
		sdwTestBegin( "testSubgroupMemoryBarrierShared" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrierShared();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupMemoryBarrierImage )
	{
		sdwTestBegin( "testSubgroupMemoryBarrierImage" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					writer.subgroupMemoryBarrierImage();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupElect )
	{
		sdwTestBegin( "testSubgroupElect" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					auto result = writer.declLocale( "result"
						, subgroupElect( writer ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupAll )
	{
		sdwTestBegin( "testSubgroupAll" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					auto op = writer.declLocale< Boolean >( "op"
						, test::getDefault< Boolean >( writer ) );
					auto result = writer.declLocale( "result"
						, subgroupAll( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupAny )
	{
		sdwTestBegin( "testSubgroupAny" );
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMain( 32u
				, [&]( sdw::ComputeIn in )
				{
					auto op = writer.declLocale< Boolean >( "op"
						, test::getDefault< Boolean >( writer ) );
					auto result = writer.declLocale( "result"
						, subgroupAny( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupAllEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupAllEqual" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op" );
					auto res = writer.declLocale( "res"
						, subgroupAllEqual( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupAllEqual )
	{
		sdwTestBegin( "testSubgroupAllEqual" );
		testSubgroupAllEqualT< sdw::Float >( "1F", testCounts );
		testSubgroupAllEqualT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupAllEqualT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupAllEqualT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupAllEqualT< sdw::Double >( "1D", testCounts );
		testSubgroupAllEqualT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupAllEqualT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupAllEqualT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupAllEqualT< sdw::Int >( "1I", testCounts );
		testSubgroupAllEqualT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupAllEqualT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupAllEqualT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupAllEqualT< sdw::UInt >( "1U", testCounts );
		testSubgroupAllEqualT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupAllEqualT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupAllEqualT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupAllEqualT< sdw::Boolean >( "1B", testCounts );
		testSubgroupAllEqualT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupAllEqualT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupAllEqualT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupBroadcastT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupBroadcast" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBroadcast( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupBroadcast )
	{
		sdwTestBegin( "testSubgroupBroadcast" );
		testSubgroupBroadcastT< sdw::Float >( "1F", testCounts );
		testSubgroupBroadcastT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupBroadcastT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupBroadcastT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupBroadcastT< sdw::Double >( "1D", testCounts );
		testSubgroupBroadcastT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupBroadcastT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupBroadcastT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupBroadcastT< sdw::Int >( "1I", testCounts );
		testSubgroupBroadcastT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupBroadcastT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupBroadcastT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupBroadcastT< sdw::UInt >( "1U", testCounts );
		testSubgroupBroadcastT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupBroadcastT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupBroadcastT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupBroadcastT< sdw::Boolean >( "1B", testCounts );
		testSubgroupBroadcastT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupBroadcastT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupBroadcastT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupBroadcastFirstT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupBroadcastFirst" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBroadcastFirst( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupBroadcastFirst )
	{
		sdwTestBegin( "testSubgroupBroadcastFirst" );
		testSubgroupBroadcastFirstT< sdw::Float >( "1F", testCounts );
		testSubgroupBroadcastFirstT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupBroadcastFirstT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupBroadcastFirstT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupBroadcastFirstT< sdw::Double >( "1D", testCounts );
		testSubgroupBroadcastFirstT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupBroadcastFirstT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupBroadcastFirstT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupBroadcastFirstT< sdw::Int >( "1I", testCounts );
		testSubgroupBroadcastFirstT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupBroadcastFirstT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupBroadcastFirstT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupBroadcastFirstT< sdw::UInt >( "1U", testCounts );
		testSubgroupBroadcastFirstT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupBroadcastFirstT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupBroadcastFirstT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupBroadcastFirstT< sdw::Boolean >( "1B", testCounts );
		testSubgroupBroadcastFirstT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupBroadcastFirstT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupBroadcastFirstT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallot )
	{
		sdwTestBegin( "testSubgroupBallot" );
		using namespace sdw;
		astOn( "testSubgroupBallot" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< Boolean >( "op"
						, test::getDefault< Boolean >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallot( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupInverseBallot )
	{
		sdwTestBegin( "testSubgroupInverseBallot" );
		using namespace sdw;
		astOn( "testSubgroupInverseBallot" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupInverseBallot( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallotBitExtract )
	{
		sdwTestBegin( "testSubgroupBallotBitExtract" );
		using namespace sdw;
		astOn( "testSubgroupBallotBitExtract" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotBitExtract( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallotBitCount )
	{
		sdwTestBegin( "testSubgroupBallotBitCount" );
		using namespace sdw;
		astOn( "testSubgroupBallotBitCount" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotBitCount( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallotInclusiveBitCount )
	{
		sdwTestBegin( "testSubgroupBallotInclusiveBitCount" );
		using namespace sdw;
		astOn( "testSubgroupBallotInclusiveBitCount" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotInclusiveBitCount( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallotExclusiveBitCount )
	{
		sdwTestBegin( "testSubgroupBallotExclusiveBitCount" );
		using namespace sdw;
		astOn( "testSubgroupBallotExclusiveBitCount" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotExclusiveBitCount( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallotFindLSB )
	{
		sdwTestBegin( "testSubgroupBallotFindLSB" );
		using namespace sdw;
		astOn( "testSubgroupBallotFindLSB" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op" 
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotFindLSB( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	TEST_F( SDWTest, testSubgroupBallotFindMSB )
	{
		sdwTestBegin( "testSubgroupBallotFindMSB" );
		using namespace sdw;
		astOn( "testSubgroupBallotFindLSB" );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< UVec4 >( "op"  
						, test::getDefault< UVec4 >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupBallotFindMSB( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupShuffleT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupShuffle" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op" 
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffle( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupShuffle )
	{
		sdwTestBegin( "testSubgroupShuffle" );
		testSubgroupShuffleT< sdw::Float >( "1F", testCounts );
		testSubgroupShuffleT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupShuffleT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupShuffleT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupShuffleT< sdw::Double >( "1D", testCounts );
		testSubgroupShuffleT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupShuffleT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupShuffleT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupShuffleT< sdw::Int >( "1I", testCounts );
		testSubgroupShuffleT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupShuffleT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupShuffleT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupShuffleT< sdw::UInt >( "1U", testCounts );
		testSubgroupShuffleT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupShuffleT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupShuffleT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupShuffleT< sdw::Boolean >( "1B", testCounts );
		testSubgroupShuffleT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupShuffleT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupShuffleT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupShuffleXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupShuffleXor" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffle( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupShuffleXor )
	{
		sdwTestBegin( "testSubgroupShuffleXor" );
		testSubgroupShuffleXorT< sdw::Float >( "1F", testCounts );
		testSubgroupShuffleXorT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupShuffleXorT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupShuffleXorT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupShuffleXorT< sdw::Double >( "1D", testCounts );
		testSubgroupShuffleXorT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupShuffleXorT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupShuffleXorT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupShuffleXorT< sdw::Int >( "1I", testCounts );
		testSubgroupShuffleXorT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupShuffleXorT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupShuffleXorT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupShuffleXorT< sdw::UInt >( "1U", testCounts );
		testSubgroupShuffleXorT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupShuffleXorT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupShuffleXorT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupShuffleXorT< sdw::Boolean >( "1B", testCounts );
		testSubgroupShuffleXorT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupShuffleXorT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupShuffleXorT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupShuffleUpT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupShuffleUp" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffleUp( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupShuffleUp )
	{
		sdwTestBegin( "testSubgroupShuffleUp" );
		testSubgroupShuffleUpT< sdw::Float >( "1F", testCounts );
		testSubgroupShuffleUpT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupShuffleUpT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupShuffleUpT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupShuffleUpT< sdw::Double >( "1D", testCounts );
		testSubgroupShuffleUpT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupShuffleUpT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupShuffleUpT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupShuffleUpT< sdw::Int >( "1I", testCounts );
		testSubgroupShuffleUpT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupShuffleUpT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupShuffleUpT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupShuffleUpT< sdw::UInt >( "1U", testCounts );
		testSubgroupShuffleUpT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupShuffleUpT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupShuffleUpT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupShuffleUpT< sdw::Boolean >( "1B", testCounts );
		testSubgroupShuffleUpT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupShuffleUpT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupShuffleUpT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupShuffleDownT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupShuffleDown" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupShuffleDown( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupShuffleDown )
	{
		sdwTestBegin( "testSubgroupShuffleDown" );
		testSubgroupShuffleDownT< sdw::Float >( "1F", testCounts );
		testSubgroupShuffleDownT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupShuffleDownT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupShuffleDownT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupShuffleDownT< sdw::Double >( "1D", testCounts );
		testSubgroupShuffleDownT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupShuffleDownT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupShuffleDownT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupShuffleDownT< sdw::Int >( "1I", testCounts );
		testSubgroupShuffleDownT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupShuffleDownT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupShuffleDownT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupShuffleDownT< sdw::UInt >( "1U", testCounts );
		testSubgroupShuffleDownT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupShuffleDownT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupShuffleDownT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupShuffleDownT< sdw::Boolean >( "1B", testCounts );
		testSubgroupShuffleDownT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupShuffleDownT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupShuffleDownT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupAdd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupAdd )
	{
		sdwTestBegin( "testSubgroupAdd" );
		testSubgroupAddT< sdw::Float >( "1F", testCounts );
		testSubgroupAddT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupAddT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupAddT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupAddT< sdw::Double >( "1D", testCounts );
		testSubgroupAddT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupAddT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupAddT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupAddT< sdw::Int >( "1I", testCounts );
		testSubgroupAddT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupAddT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupAddT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupAddT< sdw::UInt >( "1U", testCounts );
		testSubgroupAddT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupAddT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupAddT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveAdd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveAdd )
	{
		sdwTestBegin( "testSubgroupInclusiveAdd" );
		testSubgroupInclusiveAddT< sdw::Float >( "1F", testCounts );
		testSubgroupInclusiveAddT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupInclusiveAddT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupInclusiveAddT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupInclusiveAddT< sdw::Double >( "1D", testCounts );
		testSubgroupInclusiveAddT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupInclusiveAddT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupInclusiveAddT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupInclusiveAddT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveAddT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveAddT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveAddT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveAddT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveAddT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveAddT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveAddT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveAdd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveAdd )
	{
		sdwTestBegin( "testSubgroupExclusiveAdd" );
		testSubgroupExclusiveAddT< sdw::Float >( "1F", testCounts );
		testSubgroupExclusiveAddT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupExclusiveAddT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupExclusiveAddT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupExclusiveAddT< sdw::Double >( "1D", testCounts );
		testSubgroupExclusiveAddT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupExclusiveAddT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupExclusiveAddT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupExclusiveAddT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveAddT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveAddT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveAddT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveAddT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveAddT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveAddT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveAddT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterAdd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAdd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterAdd )
	{
		sdwTestBegin( "testSubgroupClusterAdd" );
		testSubgroupClusterAddT< sdw::Float >( "1F", testCounts );
		testSubgroupClusterAddT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupClusterAddT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupClusterAddT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupClusterAddT< sdw::Double >( "1D", testCounts );
		testSubgroupClusterAddT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupClusterAddT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupClusterAddT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupClusterAddT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterAddT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterAddT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterAddT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterAddT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterAddT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterAddT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterAddT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupMul" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupMul )
	{
		sdwTestBegin( "testSubgroupMul" );
		testSubgroupMulT< sdw::Float >( "1F", testCounts );
		testSubgroupMulT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupMulT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupMulT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupMulT< sdw::Double >( "1D", testCounts );
		testSubgroupMulT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupMulT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupMulT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupMulT< sdw::Int >( "1I", testCounts );
		testSubgroupMulT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupMulT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupMulT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupMulT< sdw::UInt >( "1U", testCounts );
		testSubgroupMulT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupMulT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupMulT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveMul" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveMul )
	{
		sdwTestBegin( "testSubgroupInclusiveMul" );
		testSubgroupInclusiveMulT< sdw::Float >( "1F", testCounts );
		testSubgroupInclusiveMulT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupInclusiveMulT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupInclusiveMulT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupInclusiveMulT< sdw::Double >( "1D", testCounts );
		testSubgroupInclusiveMulT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupInclusiveMulT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupInclusiveMulT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupInclusiveMulT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveMulT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveMulT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveMulT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveMulT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveMulT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveMulT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveMulT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveMul" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveMul )
	{
		sdwTestBegin( "testSubgroupExclusiveMul" );
		testSubgroupExclusiveMulT< sdw::Float >( "1F", testCounts );
		testSubgroupExclusiveMulT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupExclusiveMulT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupExclusiveMulT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupExclusiveMulT< sdw::Double >( "1D", testCounts );
		testSubgroupExclusiveMulT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupExclusiveMulT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupExclusiveMulT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupExclusiveMulT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveMulT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveMulT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveMulT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveMulT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveMulT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveMulT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveMulT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterMul" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMul( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterMul )
	{
		sdwTestBegin( "testSubgroupClusterMul" );
		testSubgroupClusterMulT< sdw::Float >( "1F", testCounts );
		testSubgroupClusterMulT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupClusterMulT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupClusterMulT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupClusterMulT< sdw::Double >( "1D", testCounts );
		testSubgroupClusterMulT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupClusterMulT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupClusterMulT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupClusterMulT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterMulT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterMulT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterMulT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterMulT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterMulT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterMulT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterMulT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupMin" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupMin )
	{
		sdwTestBegin( "testSubgroupMin" );
		testSubgroupMinT< sdw::Float >( "1F", testCounts );
		testSubgroupMinT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupMinT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupMinT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupMinT< sdw::Double >( "1D", testCounts );
		testSubgroupMinT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupMinT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupMinT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupMinT< sdw::Int >( "1I", testCounts );
		testSubgroupMinT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupMinT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupMinT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupMinT< sdw::UInt >( "1U", testCounts );
		testSubgroupMinT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupMinT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupMinT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveMin" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveMin )
	{
		sdwTestBegin( "testSubgroupInclusiveMin" );
		testSubgroupInclusiveMinT< sdw::Float >( "1F", testCounts );
		testSubgroupInclusiveMinT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupInclusiveMinT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupInclusiveMinT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupInclusiveMinT< sdw::Double >( "1D", testCounts );
		testSubgroupInclusiveMinT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupInclusiveMinT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupInclusiveMinT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupInclusiveMinT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveMinT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveMinT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveMinT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveMinT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveMinT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveMinT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveMinT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveMin" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveMin )
	{
		sdwTestBegin( "testSubgroupExclusiveMin" );
		testSubgroupExclusiveMinT< sdw::Float >( "1F", testCounts );
		testSubgroupExclusiveMinT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupExclusiveMinT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupExclusiveMinT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupExclusiveMinT< sdw::Double >( "1D", testCounts );
		testSubgroupExclusiveMinT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupExclusiveMinT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupExclusiveMinT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupExclusiveMinT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveMinT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveMinT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveMinT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveMinT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveMinT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveMinT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveMinT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterMin" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMin( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterMin )
	{
		sdwTestBegin( "testSubgroupClusterMin" );
		testSubgroupClusterMinT< sdw::Float >( "1F", testCounts );
		testSubgroupClusterMinT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupClusterMinT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupClusterMinT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupClusterMinT< sdw::Double >( "1D", testCounts );
		testSubgroupClusterMinT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupClusterMinT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupClusterMinT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupClusterMinT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterMinT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterMinT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterMinT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterMinT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterMinT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterMinT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterMinT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupMax" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupMax )
	{
		sdwTestBegin( "testSubgroupMax" );
		testSubgroupMaxT< sdw::Float >( "1F", testCounts );
		testSubgroupMaxT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupMaxT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupMaxT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupMaxT< sdw::Double >( "1D", testCounts );
		testSubgroupMaxT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupMaxT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupMaxT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupMaxT< sdw::Int >( "1I", testCounts );
		testSubgroupMaxT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupMaxT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupMaxT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupMaxT< sdw::UInt >( "1U", testCounts );
		testSubgroupMaxT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupMaxT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupMaxT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveMax" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveMax )
	{
		sdwTestBegin( "testSubgroupInclusiveMax" );
		testSubgroupInclusiveMaxT< sdw::Float >( "1F", testCounts );
		testSubgroupInclusiveMaxT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupInclusiveMaxT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupInclusiveMaxT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupInclusiveMaxT< sdw::Double >( "1D", testCounts );
		testSubgroupInclusiveMaxT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupInclusiveMaxT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupInclusiveMaxT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupInclusiveMaxT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveMaxT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveMaxT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveMaxT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveMaxT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveMaxT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveMaxT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveMaxT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveMax" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveMax )
	{
		sdwTestBegin( "testSubgroupExclusiveMax" );
		testSubgroupExclusiveMaxT< sdw::Float >( "1F", testCounts );
		testSubgroupExclusiveMaxT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupExclusiveMaxT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupExclusiveMaxT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupExclusiveMaxT< sdw::Double >( "1D", testCounts );
		testSubgroupExclusiveMaxT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupExclusiveMaxT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupExclusiveMaxT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupExclusiveMaxT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveMaxT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveMaxT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveMaxT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveMaxT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveMaxT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveMaxT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveMaxT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterMax" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupMax( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterMax )
	{
		sdwTestBegin( "testSubgroupClusterMax" );
		testSubgroupClusterMaxT< sdw::Float >( "1F", testCounts );
		testSubgroupClusterMaxT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupClusterMaxT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupClusterMaxT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupClusterMaxT< sdw::Double >( "1D", testCounts );
		testSubgroupClusterMaxT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupClusterMaxT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupClusterMaxT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupClusterMaxT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterMaxT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterMaxT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterMaxT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterMaxT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterMaxT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterMaxT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterMaxT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupAnd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupAnd )
	{
		sdwTestBegin( "testSubgroupAnd" );
		testSubgroupAndT< sdw::Int >( "1I", testCounts );
		testSubgroupAndT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupAndT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupAndT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupAndT< sdw::UInt >( "1U", testCounts );
		testSubgroupAndT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupAndT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupAndT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupAndT< sdw::Boolean >( "1B", testCounts );
		testSubgroupAndT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupAndT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupAndT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveAnd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveAnd )
	{
		sdwTestBegin( "testSubgroupInclusiveAnd" );
		testSubgroupInclusiveAndT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveAndT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveAndT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveAndT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveAndT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveAndT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveAndT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveAndT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupInclusiveAndT< sdw::Boolean >( "1B", testCounts );
		testSubgroupInclusiveAndT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupInclusiveAndT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupInclusiveAndT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveAnd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveAnd )
	{
		sdwTestBegin( "testSubgroupExclusiveAnd" );
		testSubgroupExclusiveAndT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveAndT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveAndT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveAndT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveAndT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveAndT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveAndT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveAndT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupExclusiveAndT< sdw::Boolean >( "1B", testCounts );
		testSubgroupExclusiveAndT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupExclusiveAndT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupExclusiveAndT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterAnd" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupAnd( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterAnd )
	{
		sdwTestBegin( "testSubgroupClusterAnd" );
		testSubgroupClusterAndT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterAndT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterAndT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterAndT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterAndT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterAndT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterAndT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterAndT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupClusterAndT< sdw::Boolean >( "1B", testCounts );
		testSubgroupClusterAndT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupClusterAndT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupClusterAndT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupOr" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupOr )
	{
		sdwTestBegin( "testSubgroupOr" );
		testSubgroupOrT< sdw::Int >( "1I", testCounts );
		testSubgroupOrT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupOrT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupOrT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupOrT< sdw::UInt >( "1U", testCounts );
		testSubgroupOrT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupOrT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupOrT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupOrT< sdw::Boolean >( "1B", testCounts );
		testSubgroupOrT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupOrT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupOrT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveOr" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveOr )
	{
		sdwTestBegin( "testSubgroupInclusiveOr" );
		testSubgroupInclusiveOrT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveOrT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveOrT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveOrT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveOrT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveOrT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveOrT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveOrT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupInclusiveOrT< sdw::Boolean >( "1B", testCounts );
		testSubgroupInclusiveOrT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupInclusiveOrT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupInclusiveOrT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveOr" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveOr )
	{
		sdwTestBegin( "testSubgroupExclusiveOr" );
		testSubgroupExclusiveOrT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveOrT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveOrT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveOrT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveOrT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveOrT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveOrT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveOrT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupExclusiveOrT< sdw::Boolean >( "1B", testCounts );
		testSubgroupExclusiveOrT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupExclusiveOrT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupExclusiveOrT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterOr" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupOr( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterOr )
	{
		sdwTestBegin( "testSubgroupClusterOr" );
		testSubgroupClusterOrT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterOrT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterOrT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterOrT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterOrT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterOrT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterOrT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterOrT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupClusterOrT< sdw::Boolean >( "1B", testCounts );
		testSubgroupClusterOrT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupClusterOrT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupClusterOrT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupXor" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupXor )
	{
		sdwTestBegin( "testSubgroupXor" );
		testSubgroupXorT< sdw::Int >( "1I", testCounts );
		testSubgroupXorT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupXorT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupXorT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupXorT< sdw::UInt >( "1U", testCounts );
		testSubgroupXorT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupXorT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupXorT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupXorT< sdw::Boolean >( "1B", testCounts );
		testSubgroupXorT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupXorT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupXorT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupInclusiveXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupInclusiveXor" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupInclusiveXor )
	{
		sdwTestBegin( "testSubgroupInclusiveXor" );
		testSubgroupInclusiveXorT< sdw::Int >( "1I", testCounts );
		testSubgroupInclusiveXorT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupInclusiveXorT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupInclusiveXorT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupInclusiveXorT< sdw::UInt >( "1U", testCounts );
		testSubgroupInclusiveXorT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupInclusiveXorT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupInclusiveXorT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupInclusiveXorT< sdw::Boolean >( "1B", testCounts );
		testSubgroupInclusiveXorT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupInclusiveXorT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupInclusiveXorT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupExclusiveXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupExclusiveXor" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupExclusiveXor )
	{
		sdwTestBegin( "testSubgroupExclusiveXor" );
		testSubgroupExclusiveXorT< sdw::Int >( "1I", testCounts );
		testSubgroupExclusiveXorT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupExclusiveXorT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupExclusiveXorT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupExclusiveXorT< sdw::UInt >( "1U", testCounts );
		testSubgroupExclusiveXorT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupExclusiveXorT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupExclusiveXorT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupExclusiveXorT< sdw::Boolean >( "1B", testCounts );
		testSubgroupExclusiveXorT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupExclusiveXorT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupExclusiveXorT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupClusterXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupClusterXor" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupXor( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupClusterXor )
	{
		sdwTestBegin( "testSubgroupClusterXor" );
		testSubgroupClusterXorT< sdw::Int >( "1I", testCounts );
		testSubgroupClusterXorT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupClusterXorT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupClusterXorT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupClusterXorT< sdw::UInt >( "1U", testCounts );
		testSubgroupClusterXorT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupClusterXorT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupClusterXorT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupClusterXorT< sdw::Boolean >( "1B", testCounts );
		testSubgroupClusterXorT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupClusterXorT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupClusterXorT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupQuadBroadcastT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupQuadBroadcast" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadBroadcast( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupQuadBroadcast )
	{
		sdwTestBegin( "testSubgroupQuadBroadcast" );
		testSubgroupQuadBroadcastT< sdw::Float >( "1F", testCounts );
		testSubgroupQuadBroadcastT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupQuadBroadcastT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupQuadBroadcastT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupQuadBroadcastT< sdw::Double >( "1D", testCounts );
		testSubgroupQuadBroadcastT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupQuadBroadcastT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupQuadBroadcastT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupQuadBroadcastT< sdw::Int >( "1I", testCounts );
		testSubgroupQuadBroadcastT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupQuadBroadcastT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupQuadBroadcastT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupQuadBroadcastT< sdw::UInt >( "1U", testCounts );
		testSubgroupQuadBroadcastT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupQuadBroadcastT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupQuadBroadcastT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupQuadBroadcastT< sdw::Boolean >( "1B", testCounts );
		testSubgroupQuadBroadcastT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupQuadBroadcastT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupQuadBroadcastT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupQuadSwapHorizontalT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupQuadSwapHorizontal" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadSwapHorizontal( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupQuadSwapHorizontal )
	{
		sdwTestBegin( "testSubgroupQuadSwapHorizontal" );
		testSubgroupQuadSwapHorizontalT< sdw::Float >( "1F", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::Double >( "1D", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::Int >( "1I", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::UInt >( "1U", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::Boolean >( "1B", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupQuadSwapHorizontalT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupQuadSwapVerticalT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupQuadSwapVertical" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadSwapVertical( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupQuadSwapVertical )
	{
		sdwTestBegin( "testSubgroupQuadSwapVertical" );
		testSubgroupQuadSwapVerticalT< sdw::Float >( "1F", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::Double >( "1D", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::Int >( "1I", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::UInt >( "1U", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::Boolean >( "1B", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupQuadSwapVerticalT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testSubgroupQuadSwapDiagonalT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testSubgroupQuadSwapDiagonal" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, subgroupQuadSwapDiagonal( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testSubgroupQuadSwapDiagonal )
	{
		sdwTestBegin( "testSubgroupQuadSwapDiagonal" );
		testSubgroupQuadSwapDiagonalT< sdw::Float >( "1F", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::Vec2 >( "2F", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::Vec3 >( "3F", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::Vec4 >( "4F", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::Double >( "1D", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::DVec2 >( "2D", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::DVec3 >( "3D", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::DVec4 >( "4D", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::Int >( "1I", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::IVec2 >( "2I", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::IVec3 >( "3I", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::IVec4 >( "4I", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::UInt >( "1U", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::UVec2 >( "2U", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::UVec3 >( "3U", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::UVec4 >( "4U", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::Boolean >( "1B", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::BVec2 >( "2B", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::BVec3 >( "3B", testCounts );
		testSubgroupQuadSwapDiagonalT< sdw::BVec4 >( "4B", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testReadInvocationT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testReadInvocation" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, readInvocation( op, 1_u ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testReadInvocation )
	{
		sdwTestBegin( "testReadInvocation" );
		testReadInvocationT< sdw::Float >( "1F", testCounts );
		testReadInvocationT< sdw::Vec2 >( "2F", testCounts );
		testReadInvocationT< sdw::Vec3 >( "3F", testCounts );
		testReadInvocationT< sdw::Vec4 >( "4F", testCounts );
		testReadInvocationT< sdw::Double >( "1D", testCounts );
		testReadInvocationT< sdw::DVec2 >( "2D", testCounts );
		testReadInvocationT< sdw::DVec3 >( "3D", testCounts );
		testReadInvocationT< sdw::DVec4 >( "4D", testCounts );
		testReadInvocationT< sdw::Int >( "1I", testCounts );
		testReadInvocationT< sdw::IVec2 >( "2I", testCounts );
		testReadInvocationT< sdw::IVec3 >( "3I", testCounts );
		testReadInvocationT< sdw::IVec4 >( "4I", testCounts );
		testReadInvocationT< sdw::UInt >( "1U", testCounts );
		testReadInvocationT< sdw::UVec2 >( "2U", testCounts );
		testReadInvocationT< sdw::UVec3 >( "3U", testCounts );
		testReadInvocationT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}

	template< typename ValueT >
	void testReadFirstInvocationT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		astOn( "testReadFirstInvocation" + name );
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn )
				{
					auto op = writer.declLocale< ValueT >( "op"
						, test::getDefault< ValueT >( writer ) );
					auto res = writer.declLocale( "res"
						, readFirstInvocation( op ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
	}

	TEST_F( SDWTest, testReadFirstInvocation )
	{
		sdwTestBegin( "testReadFirstInvocation" );
		testReadFirstInvocationT< sdw::Float >( "1F", testCounts );
		testReadFirstInvocationT< sdw::Vec2 >( "2F", testCounts );
		testReadFirstInvocationT< sdw::Vec3 >( "3F", testCounts );
		testReadFirstInvocationT< sdw::Vec4 >( "4F", testCounts );
		testReadFirstInvocationT< sdw::Double >( "1D", testCounts );
		testReadFirstInvocationT< sdw::DVec2 >( "2D", testCounts );
		testReadFirstInvocationT< sdw::DVec3 >( "3D", testCounts );
		testReadFirstInvocationT< sdw::DVec4 >( "4D", testCounts );
		testReadFirstInvocationT< sdw::Int >( "1I", testCounts );
		testReadFirstInvocationT< sdw::IVec2 >( "2I", testCounts );
		testReadFirstInvocationT< sdw::IVec3 >( "3I", testCounts );
		testReadFirstInvocationT< sdw::IVec4 >( "4I", testCounts );
		testReadFirstInvocationT< sdw::UInt >( "1U", testCounts );
		testReadFirstInvocationT< sdw::UVec2 >( "2U", testCounts );
		testReadFirstInvocationT< sdw::UVec3 >( "3U", testCounts );
		testReadFirstInvocationT< sdw::UVec4 >( "4U", testCounts );
		sdwTestEnd();
	}
}

sdwTestSuiteMain()
