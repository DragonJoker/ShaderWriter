#include "Common.hpp"
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
		testBegin( "testDegrees" + name );
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
		testEnd();
	}

	void testDegrees( test::sdw_test::TestCounts & testCounts )
	{
		testDegreesT< sdw::Float >( "1F", testCounts );
		testDegreesT< sdw::Vec2 >( "2F", testCounts );
		testDegreesT< sdw::Vec3 >( "3F", testCounts );
		testDegreesT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testRadiansT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRadians" + name );
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
		testEnd();
	}

	void testRadians( test::sdw_test::TestCounts & testCounts )
	{
		testRadiansT< sdw::Float >( "1F", testCounts );
		testRadiansT< sdw::Vec2 >( "2F", testCounts );
		testRadiansT< sdw::Vec3 >( "3F", testCounts );
		testRadiansT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testCoshT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCosh" + name );
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
		testEnd();
	}

	void testCosh( test::sdw_test::TestCounts & testCounts )
	{
		testCoshT< sdw::Float >( "1F", testCounts );
		testCoshT< sdw::Vec2 >( "2F", testCounts );
		testCoshT< sdw::Vec3 >( "3F", testCounts );
		testCoshT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testSinhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSinh" + name );
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
		testEnd();
	}

	void testSinh( test::sdw_test::TestCounts & testCounts )
	{
		testSinhT< sdw::Float >( "1F", testCounts );
		testSinhT< sdw::Vec2 >( "2F", testCounts );
		testSinhT< sdw::Vec3 >( "3F", testCounts );
		testSinhT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testTanhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTanh" + name );
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
		testEnd();
	}

	void testTanh( test::sdw_test::TestCounts & testCounts )
	{
		testTanhT< sdw::Float >( "1F", testCounts );
		testTanhT< sdw::Vec2 >( "2F", testCounts );
		testTanhT< sdw::Vec3 >( "3F", testCounts );
		testTanhT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testCosT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCos" + name );
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
		testEnd();
	}

	void testCos( test::sdw_test::TestCounts & testCounts )
	{
		testCosT< sdw::Float >( "1F", testCounts );
		testCosT< sdw::Vec2 >( "2F", testCounts );
		testCosT< sdw::Vec3 >( "3F", testCounts );
		testCosT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testSinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSin" + name );
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
		testEnd();
	}

	void testSin( test::sdw_test::TestCounts & testCounts )
	{
		testSinT< sdw::Float >( "1F", testCounts );
		testSinT< sdw::Vec2 >( "2F", testCounts );
		testSinT< sdw::Vec3 >( "3F", testCounts );
		testSinT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testTanT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTan" + name );
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
		testEnd();
	}

	void testTan( test::sdw_test::TestCounts & testCounts )
	{
		testTanT< sdw::Float >( "1F", testCounts );
		testTanT< sdw::Vec2 >( "2F", testCounts );
		testTanT< sdw::Vec3 >( "3F", testCounts );
		testTanT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testACosT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACos" + name );
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
		testEnd();
	}

	void testACos( test::sdw_test::TestCounts & testCounts )
	{
		testACosT< sdw::Float >( "1F", testCounts );
		testACosT< sdw::Vec2 >( "2F", testCounts );
		testACosT< sdw::Vec3 >( "3F", testCounts );
		testACosT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testASinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASin" + name );
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
		testEnd();
	}

	void testASin( test::sdw_test::TestCounts & testCounts )
	{
		testASinT< sdw::Float >( "1F", testCounts );
		testASinT< sdw::Vec2 >( "2F", testCounts );
		testASinT< sdw::Vec3 >( "3F", testCounts );
		testASinT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testATanT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATan" + name );
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
		testEnd();
	}

	void testATan( test::sdw_test::TestCounts & testCounts )
	{
		testATanT< sdw::Float >( "1F", testCounts );
		testATanT< sdw::Vec2 >( "2F", testCounts );
		testATanT< sdw::Vec3 >( "3F", testCounts );
		testATanT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testACoshT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACosh" + name );
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
		testEnd();
	}

	void testACosh( test::sdw_test::TestCounts & testCounts )
	{
		testACoshT< sdw::Float >( "1F", testCounts );
		testACoshT< sdw::Vec2 >( "2F", testCounts );
		testACoshT< sdw::Vec3 >( "3F", testCounts );
		testACoshT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testASinhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testASinh" + name );
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
		testEnd();
	}

	void testASinh( test::sdw_test::TestCounts & testCounts )
	{
		testASinhT< sdw::Float >( "1F", testCounts );
		testASinhT< sdw::Vec2 >( "2F", testCounts );
		testASinhT< sdw::Vec3 >( "3F", testCounts );
		testASinhT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testATanhT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATanh" + name );
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
		testEnd();
	}

	void testATanh( test::sdw_test::TestCounts & testCounts )
	{
		testATanhT< sdw::Float >( "1F", testCounts );
		testATanhT< sdw::Vec2 >( "2F", testCounts );
		testATanhT< sdw::Vec3 >( "3F", testCounts );
		testATanhT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testPowT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPow" + name );
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
		testEnd();
	}

	void testPow( test::sdw_test::TestCounts & testCounts )
	{
		testPowT< sdw::Float >( "1F", testCounts );
		testPowT< sdw::Vec2 >( "2F", testCounts );
		testPowT< sdw::Vec3 >( "3F", testCounts );
		testPowT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testExpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp" + name );
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
		testEnd();
	}

	void testExp( test::sdw_test::TestCounts & testCounts )
	{
		testExpT< sdw::Float >( "1F", testCounts );
		testExpT< sdw::Vec2 >( "2F", testCounts );
		testExpT< sdw::Vec3 >( "3F", testCounts );
		testExpT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testLogT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog" + name );
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
		testEnd();
	}

	void testLog( test::sdw_test::TestCounts & testCounts )
	{
		testLogT< sdw::Float >( "1F", testCounts );
		testLogT< sdw::Vec2 >( "2F", testCounts );
		testLogT< sdw::Vec3 >( "3F", testCounts );
		testLogT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testExp2T( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testExp2_" + name );
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
		testEnd();
	}

	void testExp2( test::sdw_test::TestCounts & testCounts )
	{
		testExp2T< sdw::Float >( "1F", testCounts );
		testExp2T< sdw::Vec2 >( "2F", testCounts );
		testExp2T< sdw::Vec3 >( "3F", testCounts );
		testExp2T< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testLog2T( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLog2_" + name );
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
		testEnd();
	}

	void testLog2( test::sdw_test::TestCounts & testCounts )
	{
		testLog2T< sdw::Float >( "1F", testCounts );
		testLog2T< sdw::Vec2 >( "2F", testCounts );
		testLog2T< sdw::Vec3 >( "3F", testCounts );
		testLog2T< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testSqrtT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSqrt" + name );
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
		testEnd();
	}

	void testSqrt( test::sdw_test::TestCounts & testCounts )
	{
		testSqrtT< sdw::Float >( "1F", testCounts );
		testSqrtT< sdw::Vec2 >( "2F", testCounts );
		testSqrtT< sdw::Vec3 >( "3F", testCounts );
		testSqrtT< sdw::Vec4 >( "4F", testCounts );
		testSqrtT< sdw::Double >( "1D", testCounts );
		testSqrtT< sdw::DVec2 >( "2D", testCounts );
		testSqrtT< sdw::DVec3 >( "3D", testCounts );
		testSqrtT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testInverseSqrtT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverseSqrt" + name );
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
		testEnd();
	}

	void testInverseSqrt( test::sdw_test::TestCounts & testCounts )
	{
		testInverseSqrtT< sdw::Float >( "1F", testCounts );
		testInverseSqrtT< sdw::Vec2 >( "2F", testCounts );
		testInverseSqrtT< sdw::Vec3 >( "3F", testCounts );
		testInverseSqrtT< sdw::Vec4 >( "4F", testCounts );
		testInverseSqrtT< sdw::Double >( "1D", testCounts );
		testInverseSqrtT< sdw::DVec2 >( "2D", testCounts );
		testInverseSqrtT< sdw::DVec3 >( "3D", testCounts );
		testInverseSqrtT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testAbsT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAbs" + name );
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
		testEnd();
	}

	void testAbs( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSignT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSign" + name );
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
		testEnd();
	}

	void testSign( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testFloorT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloor" + name );
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
		testEnd();
	}

	void testFloor( test::sdw_test::TestCounts & testCounts )
	{
		testFloorT< sdw::Float >( "1F", testCounts );
		testFloorT< sdw::Vec2 >( "2F", testCounts );
		testFloorT< sdw::Vec3 >( "3F", testCounts );
		testFloorT< sdw::Vec4 >( "4F", testCounts );
		testFloorT< sdw::Double >( "1D", testCounts );
		testFloorT< sdw::DVec2 >( "2D", testCounts );
		testFloorT< sdw::DVec3 >( "3D", testCounts );
		testFloorT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testTruncT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTrunc" + name );
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
		testEnd();
	}

	void testTrunc( test::sdw_test::TestCounts & testCounts )
	{
		testTruncT< sdw::Float >( "1F", testCounts );
		testTruncT< sdw::Vec2 >( "2F", testCounts );
		testTruncT< sdw::Vec3 >( "3F", testCounts );
		testTruncT< sdw::Vec4 >( "4F", testCounts );
		testTruncT< sdw::Double >( "1D", testCounts );
		testTruncT< sdw::DVec2 >( "2D", testCounts );
		testTruncT< sdw::DVec3 >( "3D", testCounts );
		testTruncT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testRoundT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRound" + name );
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
		testEnd();
	}

	void testRound( test::sdw_test::TestCounts & testCounts )
	{
		testRoundT< sdw::Float >( "1F", testCounts );
		testRoundT< sdw::Vec2 >( "2F", testCounts );
		testRoundT< sdw::Vec3 >( "3F", testCounts );
		testRoundT< sdw::Vec4 >( "4F", testCounts );
		testRoundT< sdw::Double >( "1D", testCounts );
		testRoundT< sdw::DVec2 >( "2D", testCounts );
		testRoundT< sdw::DVec3 >( "3D", testCounts );
		testRoundT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testRoundEvenT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testRoundEven" + name );
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
		testEnd();
	}

	void testRoundEven( test::sdw_test::TestCounts & testCounts )
	{
		testRoundEvenT< sdw::Float >( "1F", testCounts );
		testRoundEvenT< sdw::Vec2 >( "2F", testCounts );
		testRoundEvenT< sdw::Vec3 >( "3F", testCounts );
		testRoundEvenT< sdw::Vec4 >( "4F", testCounts );
		testRoundEvenT< sdw::Double >( "1D", testCounts );
		testRoundEvenT< sdw::DVec2 >( "2D", testCounts );
		testRoundEvenT< sdw::DVec3 >( "3D", testCounts );
		testRoundEvenT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testCeilT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testCeil" + name );
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
		testEnd();
	}

	void testCeil( test::sdw_test::TestCounts & testCounts )
	{
		testCeilT< sdw::Float >( "1F", testCounts );
		testCeilT< sdw::Vec2 >( "2F", testCounts );
		testCeilT< sdw::Vec3 >( "3F", testCounts );
		testCeilT< sdw::Vec4 >( "4F", testCounts );
		testCeilT< sdw::Double >( "1D", testCounts );
		testCeilT< sdw::DVec2 >( "2D", testCounts );
		testCeilT< sdw::DVec3 >( "3D", testCounts );
		testCeilT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testFractT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFract" + name );
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
		testEnd();
	}

	void testFract( test::sdw_test::TestCounts & testCounts )
	{
		testFractT< sdw::Float >( "1F", testCounts );
		testFractT< sdw::Vec2 >( "2F", testCounts );
		testFractT< sdw::Vec3 >( "3F", testCounts );
		testFractT< sdw::Vec4 >( "4F", testCounts );
		testFractT< sdw::Double >( "1D", testCounts );
		testFractT< sdw::DVec2 >( "2D", testCounts );
		testFractT< sdw::DVec3 >( "3D", testCounts );
		testFractT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testModT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMod" + name );
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
		testEnd();
	}

	void testMod( test::sdw_test::TestCounts & testCounts )
	{
		testModT< sdw::Float >( "1F", testCounts );
		testModT< sdw::Vec2 >( "2F", testCounts );
		testModT< sdw::Vec3 >( "3F", testCounts );
		testModT< sdw::Vec4 >( "4F", testCounts );
		testModT< sdw::Double >( "1D", testCounts );
		testModT< sdw::DVec2 >( "2D", testCounts );
		testModT< sdw::DVec3 >( "3D", testCounts );
		testModT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testModfT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testModf" + name );
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
		testEnd();
	}

	void testModf( test::sdw_test::TestCounts & testCounts )
	{
		testModfT< sdw::Float >( "1F", testCounts );
		testModfT< sdw::Vec2 >( "2F", testCounts );
		testModfT< sdw::Vec3 >( "3F", testCounts );
		testModfT< sdw::Vec4 >( "4F", testCounts );
		testModfT< sdw::Double >( "1D", testCounts );
		testModfT< sdw::DVec2 >( "2D", testCounts );
		testModfT< sdw::DVec3 >( "3D", testCounts );
		testModfT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testMinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin" + name );
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
		testEnd();
	}

	void testMin( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testMaxT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMax" + name );
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
		testEnd();
	}

	void testMax( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testClampT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testClamp" + name );
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
		testEnd();
	}

	void testClamp( test::sdw_test::TestCounts & testCounts )
	{
		testClampT< sdw::Float >( "1F", testCounts );
		testClampT< sdw::Vec2 >( "2F", testCounts );
		testClampT< sdw::Vec3 >( "3F", testCounts );
		testClampT< sdw::Vec4 >( "4F", testCounts );
		testClampT< sdw::Double >( "1D", testCounts );
		testClampT< sdw::DVec2 >( "2D", testCounts );
		testClampT< sdw::DVec3 >( "3D", testCounts );
		testClampT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testMixT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMix" + name );
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
		testEnd();
	}

	void testMix( test::sdw_test::TestCounts & testCounts )
	{
		testMixT< sdw::Float >( "1F", testCounts );
		testMixT< sdw::Vec2 >( "2F", testCounts );
		testMixT< sdw::Vec3 >( "3F", testCounts );
		testMixT< sdw::Vec4 >( "4F", testCounts );
		testMixT< sdw::Double >( "1D", testCounts );
		testMixT< sdw::DVec2 >( "2D", testCounts );
		testMixT< sdw::DVec3 >( "3D", testCounts );
		testMixT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testStepT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testStep" + name );
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
		testEnd();
	}

	void testStep( test::sdw_test::TestCounts & testCounts )
	{
		testStepT< sdw::Float >( "1F", testCounts );
		testStepT< sdw::Vec2 >( "2F", testCounts );
		testStepT< sdw::Vec3 >( "3F", testCounts );
		testStepT< sdw::Vec4 >( "4F", testCounts );
		testStepT< sdw::Double >( "1D", testCounts );
		testStepT< sdw::DVec2 >( "2D", testCounts );
		testStepT< sdw::DVec3 >( "3D", testCounts );
		testStepT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testSmoothStepT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSmoothStep" + name );
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
		testEnd();
	}

	void testSmoothStep( test::sdw_test::TestCounts & testCounts )
	{
		testSmoothStepT< sdw::Float >( "1F", testCounts );
		testSmoothStepT< sdw::Vec2 >( "2F", testCounts );
		testSmoothStepT< sdw::Vec3 >( "3F", testCounts );
		testSmoothStepT< sdw::Vec4 >( "4F", testCounts );
		testSmoothStepT< sdw::Double >( "1D", testCounts );
		testSmoothStepT< sdw::DVec2 >( "2D", testCounts );
		testSmoothStepT< sdw::DVec3 >( "3D", testCounts );
		testSmoothStepT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT >
	void testIsnanT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testIsnan" + name );
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
		testEnd();
	}

	void testIsnan( test::sdw_test::TestCounts & testCounts )
	{
		testIsnanT< sdw::Float >( "1F", testCounts );
		testIsnanT< sdw::Vec2 >( "2F", testCounts );
		testIsnanT< sdw::Vec3 >( "3F", testCounts );
		testIsnanT< sdw::Vec4 >( "4F", testCounts );
		testIsnanT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testIsinfT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testIsinf" + name );
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
		testEnd();
	}

	void testIsinf( test::sdw_test::TestCounts & testCounts )
	{
		testIsinfT< sdw::Float >( "1F", testCounts );
		testIsinfT< sdw::Vec2 >( "2F", testCounts );
		testIsinfT< sdw::Vec3 >( "3F", testCounts );
		testIsinfT< sdw::Vec4 >( "4F", testCounts );
		testIsinfT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testFloatBitsToIntT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToInt" + name );
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
		testEnd();
	}

	void testFloatBitsToInt( test::sdw_test::TestCounts & testCounts )
	{
		testFloatBitsToIntT< sdw::Float >( "1F", testCounts );
		testFloatBitsToIntT< sdw::Vec2 >( "2F", testCounts );
		testFloatBitsToIntT< sdw::Vec3 >( "3F", testCounts );
		testFloatBitsToIntT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testFloatBitsToUIntT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFloatBitsToUInt" + name );
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
		testEnd();
	}

	void testFloatBitsToUInt( test::sdw_test::TestCounts & testCounts )
	{
		testFloatBitsToUIntT< sdw::Float >( "1F", testCounts );
		testFloatBitsToUIntT< sdw::Vec2 >( "2F", testCounts );
		testFloatBitsToUIntT< sdw::Vec3 >( "3F", testCounts );
		testFloatBitsToUIntT< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testIntBitsToFloatT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testIntBitsToFloat" + name );
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
		testEnd();
	}

	void testIntBitsToFloat( test::sdw_test::TestCounts & testCounts )
	{
		testIntBitsToFloatT< sdw::Int >( "1I", testCounts );
		testIntBitsToFloatT< sdw::IVec2 >( "2I", testCounts );
		testIntBitsToFloatT< sdw::IVec3 >( "3I", testCounts );
		testIntBitsToFloatT< sdw::IVec4 >( "4I", testCounts );
	}

	template< typename ValueT >
	void testUIntBitsToFloatT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUIntBitsToFloat" + name );
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
		testEnd();
	}

	void testUIntBitsToFloat( test::sdw_test::TestCounts & testCounts )
	{
		testUIntBitsToFloatT< sdw::UInt >( "1U", testCounts );
		testUIntBitsToFloatT< sdw::UVec2 >( "2U", testCounts );
		testUIntBitsToFloatT< sdw::UVec3 >( "3U", testCounts );
		testUIntBitsToFloatT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testFmaT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma" + name );
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
		testEnd();
	}

	void testFma( test::sdw_test::TestCounts & testCounts )
	{
		testFmaT< sdw::Float >( "1F", testCounts );
		testFmaT< sdw::Vec2 >( "2F", testCounts );
		testFmaT< sdw::Vec3 >( "3F", testCounts );
		testFmaT< sdw::Vec4 >( "4F", testCounts );
		testFmaT< sdw::Double >( "1D", testCounts );
		testFmaT< sdw::DVec2 >( "2D", testCounts );
		testFmaT< sdw::DVec3 >( "3D", testCounts );
		testFmaT< sdw::DVec4 >( "4D", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testFrexpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFrexp" ) + name;
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
		testEnd();
	}

	void testFrexp( test::sdw_test::TestCounts & testCounts )
	{
		testFrexpT< sdw::Float, sdw::Int >( "1F", testCounts );
		testFrexpT< sdw::Vec2, sdw::IVec2 >( "2F", testCounts );
		testFrexpT< sdw::Vec3, sdw::IVec3 >( "3F", testCounts );
		testFrexpT< sdw::Vec4, sdw::IVec4 >( "4F", testCounts );
		testFrexpT< sdw::Double, sdw::Int >( "1D", testCounts );
		testFrexpT< sdw::DVec2, sdw::IVec2 >( "2D", testCounts );
		testFrexpT< sdw::DVec3, sdw::IVec3 >( "3D", testCounts );
		testFrexpT< sdw::DVec4, sdw::IVec4 >( "4D", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testLdexpT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLdexp" ) + name;
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
		testEnd();
	}

	void testLdexp( test::sdw_test::TestCounts & testCounts )
	{
		testLdexpT< sdw::Float, sdw::Int >( "1F", testCounts );
		testLdexpT< sdw::Vec2, sdw::IVec2 >( "2F", testCounts );
		testLdexpT< sdw::Vec3, sdw::IVec3 >( "3F", testCounts );
		testLdexpT< sdw::Vec4, sdw::IVec4 >( "4F", testCounts );
		testLdexpT< sdw::Double, sdw::Int >( "1D", testCounts );
		testLdexpT< sdw::DVec2, sdw::IVec2 >( "2D", testCounts );
		testLdexpT< sdw::DVec3, sdw::IVec3 >( "3D", testCounts );
		testLdexpT< sdw::DVec4, sdw::IVec4 >( "4D", testCounts );
	}

	void testPackDouble2x32( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackDouble2x32" );
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
		testEnd();
	}

	void testPackHalf2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackHalf2x16" );
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
		testEnd();
	}

	void testPackSnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackSnorm2x16" );
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
		testEnd();
	}

	void testPackUnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackUnorm2x16" );
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
		testEnd();
	}

	void testPackSnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackSnorm4x8" );
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
		testEnd();
	}

	void testPackUnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testPackUnorm4x8" );
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
		testEnd();
	}

	void testUnpackDouble2x32( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackDouble2x32" );
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
		testEnd();
	}

	void testUnpackHalf2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackHalf2x16" );
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
		testEnd();
	}

	void testUnpackSnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackSnorm2x16" );
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
		testEnd();
	}

	void testUnpackUnorm2x16( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackUnorm2x16" );
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
		testEnd();
	}

	void testUnpackSnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackSnorm4x8" );
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
		testEnd();
	}

	void testUnpackUnorm4x8( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUnpackUnorm4x8" );
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
		testEnd();
	}

	template< typename ValueT >
	void testLengthT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testLength" ) + name;
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
		testEnd();
	}

	void testLength( test::sdw_test::TestCounts & testCounts )
	{
		testLengthT< sdw::Float >( "1F", testCounts );
		testLengthT< sdw::Vec2 >( "2F", testCounts );
		testLengthT< sdw::Vec3 >( "3F", testCounts );
		testLengthT< sdw::Vec4 >( "4F", testCounts );
		testLengthT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testDistanceT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testDistance" ) + name;
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
		testEnd();
	}

	void testDistance( test::sdw_test::TestCounts & testCounts )
	{
		testDistanceT< sdw::Float >( "1F", testCounts );
		testDistanceT< sdw::Vec2 >( "2F", testCounts );
		testDistanceT< sdw::Vec3 >( "3F", testCounts );
		testDistanceT< sdw::Vec4 >( "4F", testCounts );
		testDistanceT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testDotT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testDot" ) + name;
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
		testEnd();
	}

	void testDot( test::sdw_test::TestCounts & testCounts )
	{
		testDotT< sdw::Vec2 >( "2F", testCounts );
		testDotT< sdw::Vec3 >( "3F", testCounts );
		testDotT< sdw::Vec4 >( "4F", testCounts );
		testDotT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testDotT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testDotT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testCrossT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testCross" ) + name;
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
		testEnd();
	}

	void testCross( test::sdw_test::TestCounts & testCounts )
	{
		testCrossT< sdw::Vec3 >( "3F", testCounts );
		testCrossT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testNormalizeT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testNormalize" ) + name;
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
		testEnd();
	}

	void testNormalize( test::sdw_test::TestCounts & testCounts )
	{
		testNormalizeT< sdw::Float >( "1F", testCounts );
		testNormalizeT< sdw::Vec2 >( "2F", testCounts );
		testNormalizeT< sdw::Vec3 >( "3F", testCounts );
		testNormalizeT< sdw::Vec4 >( "4F", testCounts );
		testNormalizeT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testNormalizeT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testNormalizeT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testNormalizeT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testFaceForwardT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testFaceForward" ) + name;
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
		testEnd();
	}

	void testFaceForward( test::sdw_test::TestCounts & testCounts )
	{
		testFaceForwardT< sdw::Float >( "1F", testCounts );
		testFaceForwardT< sdw::Vec2 >( "2F", testCounts );
		testFaceForwardT< sdw::Vec3 >( "3F", testCounts );
		testFaceForwardT< sdw::Vec4 >( "4F", testCounts );
		testFaceForwardT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testFaceForwardT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testFaceForwardT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testFaceForwardT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testReflectT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testReflect" ) + name;
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
		testEnd();
	}

	void testReflect( test::sdw_test::TestCounts & testCounts )
	{
		testReflectT< sdw::Float >( "1F", testCounts );
		testReflectT< sdw::Vec2 >( "2F", testCounts );
		testReflectT< sdw::Vec3 >( "3F", testCounts );
		testReflectT< sdw::Vec4 >( "4F", testCounts );
		testReflectT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testReflectT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testReflectT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testReflectT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testRefractT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testRefract" ) + name;
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
		testEnd();
	}

	void testRefract( test::sdw_test::TestCounts & testCounts )
	{
		testRefractT< sdw::Float >( "1F", testCounts );
		testRefractT< sdw::Vec2 >( "2F", testCounts );
		testRefractT< sdw::Vec3 >( "3F", testCounts );
		testRefractT< sdw::Vec4 >( "4F", testCounts );
		testRefractT< sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testRefractT< sdw::DVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testRefractT< sdw::DVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testRefractT< sdw::DVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testMatrixCompMultT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixCompMult" ) + name;
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
		testEnd();
	}

	void testMatrixCompMult( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testMatrixMultT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMatrixMult" ) + name;
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
		testEnd();
	}

	void testMatrixMult( test::sdw_test::TestCounts & testCounts )
	{
		testMatrixMultT< sdw::Mat2x2 >( "2x2F", testCounts );
		testMatrixMultT< sdw::Mat3x3 >( "3x3F", testCounts );
		testMatrixMultT< sdw::Mat4x4 >( "4x4F", testCounts );;
		testMatrixMultT< sdw::DMat2x2 >( "2x2D", testCounts );
		testMatrixMultT< sdw::DMat3x3 >( "3x3D", testCounts );
		testMatrixMultT< sdw::DMat4x4 >( "4x4D", testCounts );
	}

	template< typename LhsT, typename RhsT >
	void testOuterProductT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct" ) + name;
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
		testEnd();
	}

	void testOuterProduct( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testTransposeT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose" ) + name;
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
		testEnd();
	}

	void testTranspose( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testDeterminantT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testDeterminant" ) + name;
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
		testEnd();
	}

	void testDeterminant( test::sdw_test::TestCounts & testCounts )
	{
		testDeterminantT< sdw::Mat2x2 >( "2x2F", testCounts );
		testDeterminantT< sdw::Mat3x3 >( "3x3F", testCounts );
		testDeterminantT< sdw::Mat4x4 >( "4x4F", testCounts );
		testDeterminantT< sdw::DMat2x2 >( "2x2D", testCounts, Compilers_NoHLSL );
		testDeterminantT< sdw::DMat3x3 >( "3x3D", testCounts, Compilers_NoHLSL );
		testDeterminantT< sdw::DMat4x4 >( "4x4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testInverseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInverse" ) + name;
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
		testEnd();
	}

	void testInverse( test::sdw_test::TestCounts & testCounts )
	{
		testInverseT< sdw::Mat2x2 >( "2x2F", testCounts );
		testInverseT< sdw::Mat3x3 >( "3x3F", testCounts );
		testInverseT< sdw::Mat4x4 >( "4x4F", testCounts );
		testInverseT< sdw::DMat2x2 >( "2x2D", testCounts );
		testInverseT< sdw::DMat3x3 >( "3x3D", testCounts );
		testInverseT< sdw::DMat4x4 >( "4x4D", testCounts );
	}

	template< typename ValueT >
	void testLessThanT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan" ) + name;
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
		testEnd();
	}

	void testLessThan( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testLessThanEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual" ) + name;
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
		testEnd();
	}

	void testLessThanEqual( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testGreaterThanT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan" ) + name;
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
		testEnd();
	}

	void testGreaterThan( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testGreaterThanEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual" ) + name;
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
		testEnd();
	}

	void testGreaterThanEqual( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual" ) + name;
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
		testEnd();
	}

	void testEqual( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testNotEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual" ) + name;
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
		testEnd();
	}

	void testNotEqual( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testAllT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAll" ) + name;
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
		testEnd();
	}

	void testAll( test::sdw_test::TestCounts & testCounts )
	{
		testAllT< sdw::BVec2 >( "2", testCounts );
		testAllT< sdw::BVec3 >( "3", testCounts );
		testAllT< sdw::BVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testAnyT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAny" ) + name;
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
		testEnd();
	}

	void testAny( test::sdw_test::TestCounts & testCounts )
	{
		testAnyT< sdw::BVec2 >( "2", testCounts );
		testAnyT< sdw::BVec3 >( "3", testCounts );
		testAnyT< sdw::BVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testNotT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNot" ) + name;
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
		testEnd();
	}

	void testNot( test::sdw_test::TestCounts & testCounts )
	{
		testNotT< sdw::BVec2 >( "2", testCounts );
		testNotT< sdw::BVec3 >( "3", testCounts );
		testNotT< sdw::BVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testUaddCarryT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUaddCarry" ) + name;
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
		testEnd();
	}

	void testUaddCarry( test::sdw_test::TestCounts & testCounts )
	{
		testUaddCarryT< sdw::UInt >( "1", testCounts );
		testUaddCarryT< sdw::UVec2 >( "2", testCounts );
		testUaddCarryT< sdw::UVec3 >( "3", testCounts );
		testUaddCarryT< sdw::UVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testUsubBorrowT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUsubBorrow" ) + name;
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
		testEnd();
	}

	void testUsubBorrow( test::sdw_test::TestCounts & testCounts )
	{
		testUsubBorrowT< sdw::UInt >( "1", testCounts );
		testUsubBorrowT< sdw::UVec2 >( "2", testCounts );
		testUsubBorrowT< sdw::UVec3 >( "3", testCounts );
		testUsubBorrowT< sdw::UVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testUmulExtendedT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testUmulExtended" ) + name;
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
		testEnd();
	}

	void testUmulExtended( test::sdw_test::TestCounts & testCounts )
	{
		testUmulExtendedT< sdw::UInt >( "1", testCounts );
		testUmulExtendedT< sdw::UVec2 >( "2", testCounts );
		testUmulExtendedT< sdw::UVec3 >( "3", testCounts );
		testUmulExtendedT< sdw::UVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testImulExtendedT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testImulExtended" ) + name;
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
		testEnd();
	}

	void testImulExtended( test::sdw_test::TestCounts & testCounts )
	{
		testImulExtendedT< sdw::Int >( "1", testCounts );
		testImulExtendedT< sdw::IVec2 >( "2", testCounts );
		testImulExtendedT< sdw::IVec3 >( "3", testCounts );
		testImulExtendedT< sdw::IVec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testBitfieldExtractT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldExtract" ) + name;
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
		testEnd();
	}

	void testBitfieldExtract( test::sdw_test::TestCounts & testCounts )
	{
		testBitfieldExtractT< sdw::Int >( "1I", testCounts );
		testBitfieldExtractT< sdw::IVec2 >( "2I", testCounts );
		testBitfieldExtractT< sdw::IVec3 >( "3I", testCounts );
		testBitfieldExtractT< sdw::IVec4 >( "4I", testCounts );
		testBitfieldExtractT< sdw::UInt >( "1U", testCounts );
		testBitfieldExtractT< sdw::UVec2 >( "2U", testCounts );
		testBitfieldExtractT< sdw::UVec3 >( "3U", testCounts );
		testBitfieldExtractT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testBitfieldInsertT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldInsert" ) + name;
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
		testEnd();
	}

	void testBitfieldInsert( test::sdw_test::TestCounts & testCounts )
	{
		testBitfieldInsertT< sdw::Int >( "1I", testCounts );
		testBitfieldInsertT< sdw::IVec2 >( "2I", testCounts );
		testBitfieldInsertT< sdw::IVec3 >( "3I", testCounts );
		testBitfieldInsertT< sdw::IVec4 >( "4I", testCounts );
		testBitfieldInsertT< sdw::UInt >( "1U", testCounts );
		testBitfieldInsertT< sdw::UVec2 >( "2U", testCounts );
		testBitfieldInsertT< sdw::UVec3 >( "3U", testCounts );
		testBitfieldInsertT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testBitfieldReverseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitfieldReverse" ) + name;
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
		testEnd();
	}

	void testBitfieldReverse( test::sdw_test::TestCounts & testCounts )
	{
		testBitfieldReverseT< sdw::Int >( "1I", testCounts );
		testBitfieldReverseT< sdw::IVec2 >( "2I", testCounts );
		testBitfieldReverseT< sdw::IVec3 >( "3I", testCounts );
		testBitfieldReverseT< sdw::IVec4 >( "4I", testCounts );
		testBitfieldReverseT< sdw::UInt >( "1U", testCounts );
		testBitfieldReverseT< sdw::UVec2 >( "2U", testCounts );
		testBitfieldReverseT< sdw::UVec3 >( "3U", testCounts );
		testBitfieldReverseT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testBitCountT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBitCount" ) + name;
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
		testEnd();
	}

	void testBitCount( test::sdw_test::TestCounts & testCounts )
	{
		testBitCountT< sdw::Int >( "1I", testCounts );
		testBitCountT< sdw::IVec2 >( "2I", testCounts );
		testBitCountT< sdw::IVec3 >( "3I", testCounts );
		testBitCountT< sdw::IVec4 >( "4I", testCounts );
		testBitCountT< sdw::UInt >( "1U", testCounts );
		testBitCountT< sdw::UVec2 >( "2U", testCounts );
		testBitCountT< sdw::UVec3 >( "3U", testCounts );
		testBitCountT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testFindLSBT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindLSB" ) + name;
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
		testEnd();
	}

	void testFindLSB( test::sdw_test::TestCounts & testCounts )
	{
		testFindLSBT< sdw::Int >( "1I", testCounts );
		testFindLSBT< sdw::IVec2 >( "2I", testCounts );
		testFindLSBT< sdw::IVec3 >( "3I", testCounts );
		testFindLSBT< sdw::IVec4 >( "4I", testCounts );
		testFindLSBT< sdw::UInt >( "1U", testCounts );
		testFindLSBT< sdw::UVec2 >( "2U", testCounts );
		testFindLSBT< sdw::UVec3 >( "3U", testCounts );
		testFindLSBT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testFindMSBT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFindMSB" ) + name;
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
		testEnd();
	}

	void testFindMSB( test::sdw_test::TestCounts & testCounts )
	{
		testFindMSBT< sdw::Int >( "1I", testCounts );
		testFindMSBT< sdw::IVec2 >( "2I", testCounts );
		testFindMSBT< sdw::IVec3 >( "3I", testCounts );
		testFindMSBT< sdw::IVec4 >( "4I", testCounts );
		testFindMSBT< sdw::UInt >( "1U", testCounts );
		testFindMSBT< sdw::UVec2 >( "2U", testCounts );
		testFindMSBT< sdw::UVec3 >( "3U", testCounts );
		testFindMSBT< sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testAtomicAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testAtomicAdd" ) + name;
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
		testEnd();
	}

	void testAtomicAdd( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicAddT< sdw::Int >( "I", testCounts );
		testAtomicAddT< sdw::UInt >( "U", testCounts );
		testAtomicAddT< sdw::Float >( "F", testCounts );
		//testAtomicAddT< sdw::HVec2 >( "2H", testCounts, Compilers_NoHLSL );
		//testAtomicAddT< sdw::HVec4 >( "4H", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testAtomicMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMin" ) + name;
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
		testEnd();
	}

	void testAtomicMin( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicMinT< sdw::Int >( "I", testCounts );
		testAtomicMinT< sdw::UInt >( "U", testCounts );
	}

	template< typename ValueT >
	void testAtomicMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicMax" ) + name;
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
		testEnd();
	}

	void testAtomicMax( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicMaxT< sdw::Int >( "I", testCounts );
		testAtomicMaxT< sdw::UInt >( "U", testCounts );
	}

	template< typename ValueT >
	void testAtomicAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicAnd" ) + name;
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
		testEnd();
	}

	void testAtomicAnd( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicAndT< sdw::Int >( "I", testCounts );
		testAtomicAndT< sdw::UInt >( "U", testCounts );
	}

	template< typename ValueT >
	void testAtomicOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicOr" ) + name;
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
		testEnd();
	}

	void testAtomicOr( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicOrT< sdw::Int >( "I", testCounts );
		testAtomicOrT< sdw::UInt >( "U", testCounts );
	}

	template< typename ValueT >
	void testAtomicXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicXor" ) + name;
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
		testEnd();
	}

	void testAtomicXor( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicXorT< sdw::Int >( "I", testCounts );
		testAtomicXorT< sdw::UInt >( "U", testCounts );
	}

	template< typename ValueT >
	void testAtomicExchangeT( std::string const & name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testAtomicExchange" ) + name;
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
		testEnd();
	}

	void testAtomicExchange( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicExchangeT< sdw::Int >( "I", testCounts );
		testAtomicExchangeT< sdw::UInt >( "U", testCounts );
		testAtomicExchangeT< sdw::Float >( "F", testCounts, Compilers_NoHLSL );
		//testAtomicExchangeT< sdw::HVec2 >( "2H", testCounts, Compilers_NoHLSL );
		//testAtomicExchangeT< sdw::HVec4 >( "4H", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testAtomicCompSwapT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAtomicCompSwap" ) + name;
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
		testEnd();
	}

	void testAtomicCompSwap( test::sdw_test::TestCounts & testCounts )
	{
		testAtomicCompSwapT< sdw::Int >( "I", testCounts );
		testAtomicCompSwapT< sdw::UInt >( "U", testCounts );
	}

	template< typename ValueT >
	void testDFdxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdx" ) + name;
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
		testEnd();
	}

	void testDFdx( test::sdw_test::TestCounts & testCounts )
	{
		testDFdxT< sdw::Float >( "1", testCounts );
		testDFdxT< sdw::Vec2 >( "2", testCounts );
		testDFdxT< sdw::Vec3 >( "3", testCounts );
		testDFdxT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testDFdxCoarseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxCoarse" ) + name;
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
		testEnd();
	}

	void testDFdxCoarse( test::sdw_test::TestCounts & testCounts )
	{
		testDFdxCoarseT< sdw::Float >( "1", testCounts );
		testDFdxCoarseT< sdw::Vec2 >( "2", testCounts );
		testDFdxCoarseT< sdw::Vec3 >( "3", testCounts );
		testDFdxCoarseT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testDFdxFineT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdxFine" ) + name;
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
		testEnd();
	}

	void testDFdxFine( test::sdw_test::TestCounts & testCounts )
	{
		testDFdxFineT< sdw::Float >( "1", testCounts );
		testDFdxFineT< sdw::Vec2 >( "2", testCounts );
		testDFdxFineT< sdw::Vec3 >( "3", testCounts );
		testDFdxFineT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testDFdyT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdy" ) + name;
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
		testEnd();
	}

	void testDFdy( test::sdw_test::TestCounts & testCounts )
	{
		testDFdyT< sdw::Float >( "1", testCounts );
		testDFdyT< sdw::Vec2 >( "2", testCounts );
		testDFdyT< sdw::Vec3 >( "3", testCounts );
		testDFdyT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testDFdyCoarseT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyCoarse" ) + name;
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
		testEnd();
	}

	void testDFdyCoarse( test::sdw_test::TestCounts & testCounts )
	{
		testDFdyCoarseT< sdw::Float >( "1", testCounts );
		testDFdyCoarseT< sdw::Vec2 >( "2", testCounts );
		testDFdyCoarseT< sdw::Vec3 >( "3", testCounts );
		testDFdyCoarseT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testDFdyFineT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDFdyFine" ) + name;
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
		testEnd();
	}

	void testDFdyFine( test::sdw_test::TestCounts & testCounts )
	{
		testDFdyFineT< sdw::Float >( "1", testCounts );
		testDFdyFineT< sdw::Vec2 >( "2", testCounts );
		testDFdyFineT< sdw::Vec3 >( "3", testCounts );
		testDFdyFineT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testFwidthT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFwidth" ) + name;
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
		testEnd();
	}

	void testFwidth( test::sdw_test::TestCounts & testCounts )
	{
		testFwidthT< sdw::Float >( "1", testCounts );
		testFwidthT< sdw::Vec2 >( "2", testCounts );
		testFwidthT< sdw::Vec3 >( "3", testCounts );
		testFwidthT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testInterpolateAtCentroidT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtCentroid" ) + name;
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
		testEnd();
	}

	void testInterpolateAtCentroid( test::sdw_test::TestCounts & testCounts )
	{
		testInterpolateAtCentroidT< sdw::Float >( "1", testCounts );
		testInterpolateAtCentroidT< sdw::Vec2 >( "2", testCounts );
		testInterpolateAtCentroidT< sdw::Vec3 >( "3", testCounts );
		testInterpolateAtCentroidT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testInterpolateAtSampleT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtSample" ) + name;
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
		testEnd();
	}

	void testInterpolateAtSample( test::sdw_test::TestCounts & testCounts )
	{
		testInterpolateAtSampleT< sdw::Float >( "1", testCounts );
		testInterpolateAtSampleT< sdw::Vec2 >( "2", testCounts );
		testInterpolateAtSampleT< sdw::Vec3 >( "3", testCounts );
		testInterpolateAtSampleT< sdw::Vec4 >( "4", testCounts );
	}

	template< typename ValueT >
	void testInterpolateAtOffsetT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testInterpolateAtOffset" ) + name;
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
		testEnd();
	}

	void testInterpolateAtOffset( test::sdw_test::TestCounts & testCounts )
	{
		testInterpolateAtOffsetT< sdw::Float >( "1", testCounts );
		testInterpolateAtOffsetT< sdw::Vec2 >( "2", testCounts );
		testInterpolateAtOffsetT< sdw::Vec3 >( "3", testCounts );
		testInterpolateAtOffsetT< sdw::Vec4 >( "4", testCounts );
	}

	void testBarrier( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testBarrier" );
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
		testEnd();
	}

	void testMemoryBarrier( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMemoryBarrier" );
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
		testEnd();
	}

	void testMemoryBarrierBuffer( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMemoryBarrierBuffer" );
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
		testEnd();
	}

	void testMemoryBarrierShared( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMemoryBarrierShared" );
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
		testEnd();
	}

	void testMemoryBarrierImage( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMemoryBarrierImage" );
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
		testEnd();
	}

	void testGroupMemoryBarrier( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGroupMemoryBarrier" );
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
		testEnd();
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

	void testSetMeshOutputCountsNV( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSetMeshOutputCountsNV" );
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
		testEnd();
	}

	void testSetMeshOutputCounts( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSetMeshOutputCounts" );
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
		testEnd();
	}

	void testDispatchMeshNV( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDispatchMeshNV" );
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
		testEnd();
	}

	void testDispatchMesh( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDispatchMesh" );
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
		testEnd();
	}

	void testHelperInvocation( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testHelperInvocation" );
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
		testEnd();
	}

	void testSubgroupBarrier( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupBarrier" );
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
		testEnd();
	}

	void testSubgroupMemoryBarrier( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMemoryBarrier" );
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
		testEnd();
	}

	void testSubgroupMemoryBarrierBuffer( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMemoryBarrierBuffer" );
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
		testEnd();
	}

	void testSubgroupMemoryBarrierShared( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMemoryBarrierShared" );
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
		testEnd();
	}

	void testSubgroupMemoryBarrierImage( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupMemoryBarrierImage" );
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
		testEnd();
	}

	void testSubgroupElect( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupElect" );
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
		testEnd();
	}

	void testSubgroupAll( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAll" );
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
		testEnd();
	}

	void testSubgroupAny( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSubgroupAny" );
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
		testEnd();
	}

	template< typename ValueT >
	void testSubgroupAllEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupAllEqual" + name );
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
		testEnd();
	}

	void testSubgroupAllEqual( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupBroadcastT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBroadcast" + name );
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
		testEnd();
	}

	void testSubgroupBroadcast( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupBroadcastFirstT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBroadcastFirst" + name );
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
		testEnd();
	}

	void testSubgroupBroadcastFirst( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	void testSubgroupBallot( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallot" );
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
		testEnd();
	}

	void testSubgroupInverseBallot( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInverseBallot" );
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
		testEnd();
	}

	void testSubgroupBallotBitExtract( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallotBitExtract" );
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
		testEnd();
	}

	void testSubgroupBallotBitCount( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallotBitCount" );
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
		testEnd();
	}

	void testSubgroupBallotInclusiveBitCount( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallotInclusiveBitCount" );
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
		testEnd();
	}

	void testSubgroupBallotExclusiveBitCount( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallotExclusiveBitCount" );
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
		testEnd();
	}

	void testSubgroupBallotFindLSB( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallotFindLSB" );
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
		testEnd();
	}

	void testSubgroupBallotFindMSB( test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupBallotFindLSB" );
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
		testEnd();
	}

	template< typename ValueT >
	void testSubgroupShuffleT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupShuffle" + name );
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
		testEnd();
	}

	void testSubgroupShuffle( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupShuffleXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupShuffleXor" + name );
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
		testEnd();
	}

	void testSubgroupShuffleXor( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupShuffleUpT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupShuffleUp" + name );
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
		testEnd();
	}

	void testSubgroupShuffleUp( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupShuffleDownT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupShuffleDown" + name );
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
		testEnd();
	}

	void testSubgroupShuffleDown( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupAdd" + name );
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
		testEnd();
	}

	void testSubgroupAdd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveAdd" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveAdd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveAdd" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveAdd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterAddT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterAdd" + name );
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
		testEnd();
	}

	void testSubgroupClusterAdd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupMul" + name );
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
		testEnd();
	}

	void testSubgroupMul( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveMul" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveMul( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveMul" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveMul( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterMulT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterMul" + name );
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
		testEnd();
	}

	void testSubgroupClusterMul( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupMin" + name );
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
		testEnd();
	}

	void testSubgroupMin( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveMin" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveMin( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveMin" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveMin( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterMinT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterMin" + name );
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
		testEnd();
	}

	void testSubgroupClusterMin( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupMax" + name );
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
		testEnd();
	}

	void testSubgroupMax( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveMax" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveMax( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveMax" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveMax( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterMaxT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterMax" + name );
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
		testEnd();
	}

	void testSubgroupClusterMax( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupAnd" + name );
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
		testEnd();
	}

	void testSubgroupAnd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveAnd" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveAnd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveAnd" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveAnd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterAndT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterAnd" + name );
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
		testEnd();
	}

	void testSubgroupClusterAnd( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupOr" + name );
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
		testEnd();
	}

	void testSubgroupOr( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveOr" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveOr( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveOr" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveOr( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterOrT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterOr" + name );
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
		testEnd();
	}

	void testSubgroupClusterOr( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupXor" + name );
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
		testEnd();
	}

	void testSubgroupXor( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupInclusiveXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupInclusiveXor" + name );
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
		testEnd();
	}

	void testSubgroupInclusiveXor( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupExclusiveXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupExclusiveXor" + name );
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
		testEnd();
	}

	void testSubgroupExclusiveXor( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupClusterXorT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupClusterXor" + name );
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
		testEnd();
	}

	void testSubgroupClusterXor( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupQuadBroadcastT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupQuadBroadcast" + name );
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
		testEnd();
	}

	void testSubgroupQuadBroadcast( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupQuadSwapHorizontalT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupQuadSwapHorizontal" + name );
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
		testEnd();
	}

	void testSubgroupQuadSwapHorizontal( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupQuadSwapVerticalT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupQuadSwapVertical" + name );
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
		testEnd();
	}

	void testSubgroupQuadSwapVertical( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testSubgroupQuadSwapDiagonalT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testSubgroupQuadSwapDiagonal" + name );
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
		testEnd();
	}

	void testSubgroupQuadSwapDiagonal( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testReadInvocationT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testReadInvocation" + name );
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
		testEnd();
	}

	void testReadInvocation( test::sdw_test::TestCounts & testCounts )
	{
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
	}

	template< typename ValueT >
	void testReadFirstInvocationT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		using namespace sdw;
		testBegin( "testReadFirstInvocation" + name );
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
		testEnd();
	}

	void testReadFirstInvocation( test::sdw_test::TestCounts & testCounts )
	{
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
	}
}

sdwTestSuiteMain( TestWriterIntrinsics )
{
	sdwTestSuiteBegin();
	testDegrees( testCounts );
	testRadians( testCounts );
	testCos( testCounts );
	testSin( testCounts );
	testTan( testCounts );
	testCosh( testCounts );
	testSinh( testCounts );
	testTanh( testCounts );
	testACos( testCounts );
	testASin( testCounts );
	testATan( testCounts );
	testACosh( testCounts );
	testASinh( testCounts );
	testATanh( testCounts );
	testPow( testCounts );
	testExp( testCounts );
	testLog( testCounts );
	testExp2( testCounts );
	testLog2( testCounts );
	testSqrt( testCounts );
	testInverseSqrt( testCounts );
	testAbs( testCounts );
	testSign( testCounts );
	testFloor( testCounts );
	testTrunc( testCounts );
	testRound( testCounts );
	testRoundEven( testCounts );
	testCeil( testCounts );
	testFract( testCounts );
	testMod( testCounts );
	testModf( testCounts );
	testMin( testCounts );
	testMax( testCounts );
	testClamp( testCounts );
	testMix( testCounts );
	testStep( testCounts );
	testSmoothStep( testCounts );
	testIsnan( testCounts );
	testIsinf( testCounts );
	testFloatBitsToInt( testCounts );
	testFloatBitsToUInt( testCounts );
	testIntBitsToFloat( testCounts );
	testUIntBitsToFloat( testCounts );
	testFma( testCounts );
	testFrexp( testCounts );
	testLdexp( testCounts );
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
	testLength( testCounts );
	testDistance( testCounts );
	testDot( testCounts );
	testCross( testCounts );
	testNormalize( testCounts );
	testFaceForward( testCounts );
	testReflect( testCounts );
	testRefract( testCounts );
	testMatrixCompMult( testCounts );
	testMatrixMult( testCounts );
	testOuterProduct( testCounts );
	testTranspose( testCounts );
	testDeterminant( testCounts );
	testInverse( testCounts );
	testLessThan( testCounts );
	testLessThanEqual( testCounts );
	testGreaterThan( testCounts );
	testGreaterThanEqual( testCounts );
	testEqual( testCounts );
	testNotEqual( testCounts );
	testAll( testCounts );
	testAny( testCounts );
	testNot( testCounts );
	testUaddCarry( testCounts );
	testUsubBorrow( testCounts );
	testUmulExtended( testCounts );
	testImulExtended( testCounts );
	testBitfieldExtract( testCounts );
	testBitfieldInsert( testCounts );
	testBitfieldReverse( testCounts );
	testBitCount( testCounts );
	testFindLSB( testCounts );
	testFindMSB( testCounts );
	testAtomicAdd( testCounts );
	testAtomicMin( testCounts );
	testAtomicMax( testCounts );
	testAtomicAnd( testCounts );
	testAtomicOr( testCounts );
	testAtomicXor( testCounts );
	testAtomicExchange( testCounts );
	testAtomicCompSwap( testCounts );
	testDFdx( testCounts );
	testDFdxCoarse( testCounts );
	testDFdxFine( testCounts );
	testDFdy( testCounts );
	testDFdyCoarse( testCounts );
	testDFdyFine( testCounts );
	testFwidth( testCounts );
	testInterpolateAtCentroid( testCounts );
	testInterpolateAtSample( testCounts );
	testInterpolateAtOffset( testCounts );
	//testEmitStreamVertex( testCounts );
	//testEndStreamPrimitive( testCounts );
	//testEmitVertex( testCounts );
	//testEndPrimitive( testCounts );
	testBarrier( testCounts );
	testMemoryBarrier( testCounts );
	testMemoryBarrierBuffer( testCounts );
	testMemoryBarrierShared( testCounts );
	testMemoryBarrierImage( testCounts );
	testGroupMemoryBarrier( testCounts );
	//testTraceRay( testCounts );
	//testReportIntersection( testCounts );
	//testExecuteCallable( testCounts );
	testSetMeshOutputCountsNV( testCounts );
	testSetMeshOutputCounts( testCounts );
	testDispatchMeshNV( testCounts );
	testDispatchMesh( testCounts );
	testHelperInvocation( testCounts );
	testSubgroupBarrier( testCounts );
	testSubgroupMemoryBarrier( testCounts );
	testSubgroupMemoryBarrierBuffer( testCounts );
	testSubgroupMemoryBarrierShared( testCounts );
	testSubgroupMemoryBarrierImage( testCounts );
	testSubgroupElect( testCounts );
	testSubgroupAll( testCounts );
	testSubgroupAny( testCounts );
	testSubgroupAllEqual( testCounts );
	testSubgroupBroadcast( testCounts );
	testSubgroupBroadcastFirst( testCounts );
	testSubgroupBallot( testCounts );
	testSubgroupInverseBallot( testCounts );
	testSubgroupBallotBitExtract( testCounts );
	testSubgroupBallotBitCount( testCounts );
	testSubgroupBallotInclusiveBitCount( testCounts );
	testSubgroupBallotExclusiveBitCount( testCounts );
	testSubgroupBallotFindLSB( testCounts );
	testSubgroupBallotFindMSB( testCounts );
	testSubgroupShuffle( testCounts );
	testSubgroupShuffleXor( testCounts );
	testSubgroupShuffleUp( testCounts );
	testSubgroupShuffleDown( testCounts );
	testSubgroupAdd( testCounts );
	testSubgroupInclusiveAdd( testCounts );
	testSubgroupExclusiveAdd( testCounts );
	testSubgroupClusterAdd( testCounts );
	testSubgroupMul( testCounts );
	testSubgroupInclusiveMul( testCounts );
	testSubgroupExclusiveMul( testCounts );
	testSubgroupClusterMul( testCounts );
	testSubgroupMin( testCounts );
	testSubgroupInclusiveMin( testCounts );
	testSubgroupExclusiveMin( testCounts );
	testSubgroupClusterMin( testCounts );
	testSubgroupMax( testCounts );
	testSubgroupInclusiveMax( testCounts );
	testSubgroupExclusiveMax( testCounts );
	testSubgroupClusterMax( testCounts );
	testSubgroupAnd( testCounts );
	testSubgroupInclusiveAnd( testCounts );
	testSubgroupExclusiveAnd( testCounts );
	testSubgroupClusterAnd( testCounts );
	testSubgroupOr( testCounts );
	testSubgroupInclusiveOr( testCounts );
	testSubgroupExclusiveOr( testCounts );
	testSubgroupClusterOr( testCounts );
	testSubgroupXor( testCounts );
	testSubgroupInclusiveXor( testCounts );
	testSubgroupExclusiveXor( testCounts );
	testSubgroupClusterXor( testCounts );
	testSubgroupQuadBroadcast( testCounts );
	testSubgroupQuadSwapHorizontal( testCounts );
	testSubgroupQuadSwapVertical( testCounts );
	testSubgroupQuadSwapDiagonal( testCounts );
	testReadInvocation( testCounts );
	testReadFirstInvocation( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterIntrinsics )
