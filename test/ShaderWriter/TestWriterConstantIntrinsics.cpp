#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	template< typename ValueT >
	using ValueTHelper = sdw::StructInstanceHelperT< "Values"
		, ast::type::MemoryLayout::eStd430
		, sdw::StructFieldT< ValueT, "a" > >;

	template< typename ValueT >
	struct ValuesT
		: public ValueTHelper< ValueT >
	{
		ValuesT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: ValueTHelper< ValueT >{ writer, std::move( expr ), enabled }
		{
		}

		auto a()const { return this->template getMember< "a" >(); }
	};

	template< typename ValueT >
	void testDegreesT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testDegrees" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, degrees( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 300u ) );
					auto result = writer.declLocale( "result"
						, radians( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, cosh( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, sinh( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, tanh( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, cos( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, sin( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, tan( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, acos( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, asin( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, atan( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
	void testATan2T( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testATan2" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, atan2( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testATan2( test::sdw_test::TestCounts & testCounts )
	{
		testATan2T< sdw::Float >( "1F", testCounts );
		testATan2T< sdw::Vec2 >( "2F", testCounts );
		testATan2T< sdw::Vec3 >( "3F", testCounts );
		testATan2T< sdw::Vec4 >( "4F", testCounts );
	}

	template< typename ValueT >
	void testACoshT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testACosh" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 10u ) );
					auto result = writer.declLocale( "result"
						, acosh( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, asinh( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, atanh( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, pow( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, exp( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, log( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, exp2( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, log2( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, sqrt( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, inverseSqrt( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, abs( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, sign( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, floor( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, trunc( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, round( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 15u ) );
					auto result = writer.declLocale( "result"
						, roundEven( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, ceil( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 5u ) );
					auto result = writer.declLocale( "result"
						, fract( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, mod( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
	void testMinT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testMin" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, min( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, max( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer, 1 ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer ) );
					auto x = writer.declLocale< ValueT >( "x"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, clamp( v, w, x ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto x = writer.declLocale< ValueT >( "x"
						, test::getDefault< ValueT >( writer, 8 ) );
					auto result = writer.declLocale( "result"
						, mix( v, w, x ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, step( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto x = writer.declLocale< ValueT >( "x"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, smoothStep( v, w, x ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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

	template< typename ValueT, typename ValueU >
	void testIsnanT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testIsnan" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, sdw::isnan( v ) );

					if constexpr ( std::is_same_v< ValueU, UInt > )
					{
						ssbo[0].a() = writer.cast< UInt >( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testIsnan( test::sdw_test::TestCounts & testCounts )
	{
		testIsnanT< sdw::Float, sdw::UInt >( "1F", testCounts );
		testIsnanT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testIsnanT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testIsnanT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testIsnanT< sdw::Double, sdw::UInt >( "1D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testIsnanT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT, typename ValueU >
	void testIsinfT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testIsinf" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, sdw::isinf( v ) );

					if constexpr ( std::is_same_v< ValueU, UInt > )
					{
						ssbo[0].a() = writer.cast< UInt >( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testIsinf( test::sdw_test::TestCounts & testCounts )
	{
		testIsinfT< sdw::Float, sdw::UInt >( "1F", testCounts );
		testIsinfT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testIsinfT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testIsinfT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testIsinfT< sdw::Double, sdw::UInt >( "1D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts, Compilers_NoHLSL );
		testIsinfT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testFmaT( std::string name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testFma" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto x = writer.declLocale< ValueT >( "x"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, fma( v, w, x ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testFrexp" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueU >( "w"
						, test::getDefault< ValueU >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, frexp( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testLdexp" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueU >( "w"
						, test::getDefault< ValueU >( writer ) );
					auto result = writer.declLocale( "result"
						, ldexp( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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

	template< typename ValueT, typename ValueU >
	void testLengthT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testLength" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, length( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testLength( test::sdw_test::TestCounts & testCounts )
	{
		testLengthT< sdw::Float, sdw::Float >( "1F", testCounts );
		testLengthT< sdw::Vec2, sdw::Float >( "2F", testCounts );
		testLengthT< sdw::Vec3, sdw::Float >( "3F", testCounts );
		testLengthT< sdw::Vec4, sdw::Float >( "4F", testCounts );
		testLengthT< sdw::Double, sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec2, sdw::Double >( "2D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec3, sdw::Double >( "3D", testCounts, Compilers_NoHLSL );
		testLengthT< sdw::DVec4, sdw::Double >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT, typename ValueU >
	void testDistanceT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testDistance" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, distance( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testDistance( test::sdw_test::TestCounts & testCounts )
	{
		testDistanceT< sdw::Float, sdw::Float >( "1F", testCounts );
		testDistanceT< sdw::Vec2, sdw::Float >( "2F", testCounts );
		testDistanceT< sdw::Vec3, sdw::Float >( "3F", testCounts );
		testDistanceT< sdw::Vec4, sdw::Float >( "4F", testCounts );
		testDistanceT< sdw::Double, sdw::Double >( "1D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec2, sdw::Double >( "2D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec3, sdw::Double >( "3D", testCounts, Compilers_NoHLSL );
		testDistanceT< sdw::DVec4, sdw::Double >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT, typename ValueU >
	void testDotT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testDot" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, dot( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testDot( test::sdw_test::TestCounts & testCounts )
	{
		testDotT< sdw::Vec2, sdw::Float >( "2F", testCounts );
		testDotT< sdw::Vec3, sdw::Float >( "3F", testCounts );
		testDotT< sdw::Vec4, sdw::Float >( "4F", testCounts );
		testDotT< sdw::DVec2, sdw::Double >( "2D", testCounts, Compilers_NoHLSL );
		testDotT< sdw::DVec3, sdw::Double >( "3D", testCounts, Compilers_NoHLSL );
		testDotT< sdw::DVec4, sdw::Double >( "4D", testCounts, Compilers_NoHLSL );
	}

	template< typename ValueT >
	void testCrossT( std::string name
		, test::sdw_test::TestCounts & testCounts
		, test::Compilers const & compilers = CurrentCompilers )
	{
		testBegin( "testCross" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, cross( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testNormalize" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, normalize( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testFaceForward" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto x = writer.declLocale< ValueT >( "x"
						, test::getDefault< ValueT >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, faceForward( v, w, x ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testReflect" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, reflect( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testRefract" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto x = writer.declLocale< Float >( "x"
						, test::getDefault< Float >( writer, 4 ) );
					auto result = writer.declLocale( "result"
						, sdw::refract( v, w, x ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testMatrixCompMult" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, matrixCompMult( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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

	template< typename LhsT, typename RhsT, typename MatT >
	void testOuterProductT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testOuterProduct" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< MatT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< LhsT >( "v"
						, test::getDefault< LhsT >( writer ) );
					auto w = writer.declLocale< RhsT >( "w"
						, test::getDefault< RhsT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, outerProduct( v, w ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testOuterProduct( test::sdw_test::TestCounts & testCounts )
	{
		testOuterProductT< sdw::Vec2, sdw::Vec2, sdw::Mat2x2 >( "2x2F", testCounts );
		testOuterProductT< sdw::Vec2, sdw::Vec3, sdw::Mat3x2 >( "2x3F", testCounts );
		testOuterProductT< sdw::Vec2, sdw::Vec4, sdw::Mat4x2 >( "2x4F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec2, sdw::Mat2x3 >( "3x2F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec3, sdw::Mat3x3 >( "3x3F", testCounts );
		testOuterProductT< sdw::Vec3, sdw::Vec4, sdw::Mat4x3 >( "3x4F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec2, sdw::Mat2x4 >( "4x2F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec3, sdw::Mat3x4 >( "4x3F", testCounts );
		testOuterProductT< sdw::Vec4, sdw::Vec4, sdw::Mat4x4 >( "4x4F", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec2, sdw::DMat2x2 >( "2x2D", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec3, sdw::DMat3x2 >( "2x3D", testCounts );
		testOuterProductT< sdw::DVec2, sdw::DVec4, sdw::DMat4x2 >( "2x4D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec2, sdw::DMat2x3 >( "3x2D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec3, sdw::DMat3x3 >( "3x3D", testCounts );
		testOuterProductT< sdw::DVec3, sdw::DVec4, sdw::DMat4x3 >( "3x4D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec2, sdw::DMat2x4 >( "4x2D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec3, sdw::DMat3x4 >( "4x3D", testCounts );
		testOuterProductT< sdw::DVec4, sdw::DVec4, sdw::DMat4x4 >( "4x4D", testCounts );
	}

	template< typename ValueT >
	void testTransposeT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testTranspose" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, transpose( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testDeterminant" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, determinant( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testInverse" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueT > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, inverse( v ) );
					ssbo[0].a() = result;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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

	template< typename ValueT, typename ValueU >
	void testLessThanT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThan" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, lessThan( v, w ) );

					if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testLessThan( test::sdw_test::TestCounts & testCounts )
	{
		testLessThanT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testLessThanT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testLessThanT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testLessThanT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts );
		testLessThanT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts );
		testLessThanT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts );
		testLessThanT< sdw::IVec2, sdw::UVec2 >( "2I", testCounts );
		testLessThanT< sdw::IVec3, sdw::UVec3 >( "3I", testCounts );
		testLessThanT< sdw::IVec4, sdw::UVec4 >( "4I", testCounts );
		testLessThanT< sdw::UVec2, sdw::UVec2 >( "2U", testCounts );
		testLessThanT< sdw::UVec3, sdw::UVec3 >( "3U", testCounts );
		testLessThanT< sdw::UVec4, sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testLessThanEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testLessThanEqual" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, lessThanEqual( v, w ) );

					if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testLessThanEqual( test::sdw_test::TestCounts & testCounts )
	{
		testLessThanEqualT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testLessThanEqualT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testLessThanEqualT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testLessThanEqualT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts );
		testLessThanEqualT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts );
		testLessThanEqualT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts );
		testLessThanEqualT< sdw::IVec2, sdw::UVec2 >( "2I", testCounts );
		testLessThanEqualT< sdw::IVec3, sdw::UVec3 >( "3I", testCounts );
		testLessThanEqualT< sdw::IVec4, sdw::UVec4 >( "4I", testCounts );
		testLessThanEqualT< sdw::UVec2, sdw::UVec2 >( "2U", testCounts );
		testLessThanEqualT< sdw::UVec3, sdw::UVec3 >( "3U", testCounts );
		testLessThanEqualT< sdw::UVec4, sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testGreaterThanT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThan" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, greaterThan( v, w ) );

					if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testGreaterThan( test::sdw_test::TestCounts & testCounts )
	{
		testGreaterThanT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testGreaterThanT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testGreaterThanT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testGreaterThanT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts );
		testGreaterThanT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts );
		testGreaterThanT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts );
		testGreaterThanT< sdw::IVec2, sdw::UVec2 >( "2I", testCounts );
		testGreaterThanT< sdw::IVec3, sdw::UVec3 >( "3I", testCounts );
		testGreaterThanT< sdw::IVec4, sdw::UVec4 >( "4I", testCounts );
		testGreaterThanT< sdw::UVec2, sdw::UVec2 >( "2U", testCounts );
		testGreaterThanT< sdw::UVec3, sdw::UVec3 >( "3U", testCounts );
		testGreaterThanT< sdw::UVec4, sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testGreaterThanEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testGreaterThanEqual" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, greaterThanEqual( v, w ) );

					if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testGreaterThanEqual( test::sdw_test::TestCounts & testCounts )
	{
		testGreaterThanEqualT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testGreaterThanEqualT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testGreaterThanEqualT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testGreaterThanEqualT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts );
		testGreaterThanEqualT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts );
		testGreaterThanEqualT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts );
		testGreaterThanEqualT< sdw::IVec2, sdw::UVec2 >( "2I", testCounts );
		testGreaterThanEqualT< sdw::IVec3, sdw::UVec3 >( "3I", testCounts );
		testGreaterThanEqualT< sdw::IVec4, sdw::UVec4 >( "4I", testCounts );
		testGreaterThanEqualT< sdw::UVec2, sdw::UVec2 >( "2U", testCounts );
		testGreaterThanEqualT< sdw::UVec3, sdw::UVec3 >( "3U", testCounts );
		testGreaterThanEqualT< sdw::UVec4, sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testEqual" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, equal( v, w ) );

					if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testEqual( test::sdw_test::TestCounts & testCounts )
	{
		testEqualT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testEqualT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testEqualT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testEqualT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts );
		testEqualT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts );
		testEqualT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts );
		testEqualT< sdw::IVec2, sdw::UVec2 >( "2I", testCounts );
		testEqualT< sdw::IVec3, sdw::UVec3 >( "3I", testCounts );
		testEqualT< sdw::IVec4, sdw::UVec4 >( "4I", testCounts );
		testEqualT< sdw::UVec2, sdw::UVec2 >( "2U", testCounts );
		testEqualT< sdw::UVec3, sdw::UVec3 >( "3U", testCounts );
		testEqualT< sdw::UVec4, sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testNotEqualT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNotEqual" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto w = writer.declLocale< ValueT >( "w"
						, test::getDefault< ValueT >( writer, 2 ) );
					auto result = writer.declLocale( "result"
						, notEqual( v, w ) );

					if constexpr ( std::is_same_v< ValueU, UVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueU, UVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNotEqual( test::sdw_test::TestCounts & testCounts )
	{
		testNotEqualT< sdw::Vec2, sdw::UVec2 >( "2F", testCounts );
		testNotEqualT< sdw::Vec3, sdw::UVec3 >( "3F", testCounts );
		testNotEqualT< sdw::Vec4, sdw::UVec4 >( "4F", testCounts );
		testNotEqualT< sdw::DVec2, sdw::UVec2 >( "2D", testCounts );
		testNotEqualT< sdw::DVec3, sdw::UVec3 >( "3D", testCounts );
		testNotEqualT< sdw::DVec4, sdw::UVec4 >( "4D", testCounts );
		testNotEqualT< sdw::IVec2, sdw::UVec2 >( "2I", testCounts );
		testNotEqualT< sdw::IVec3, sdw::UVec3 >( "3I", testCounts );
		testNotEqualT< sdw::IVec4, sdw::UVec4 >( "4I", testCounts );
		testNotEqualT< sdw::UVec2, sdw::UVec2 >( "2U", testCounts );
		testNotEqualT< sdw::UVec3, sdw::UVec3 >( "3U", testCounts );
		testNotEqualT< sdw::UVec4, sdw::UVec4 >( "4U", testCounts );
	}

	template< typename ValueT >
	void testAllT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testAll" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< UInt > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, all( v ) );
					ssbo[0].a() = writer.cast< UInt >( result );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
		testBegin( "testAny" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< UInt > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, any( v ) );
					ssbo[0].a() = writer.cast< UInt >( result );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testAny( test::sdw_test::TestCounts & testCounts )
	{
		testAnyT< sdw::BVec2 >( "2", testCounts );
		testAnyT< sdw::BVec3 >( "3", testCounts );
		testAnyT< sdw::BVec4 >( "4", testCounts );
	}

	template< typename ValueT, typename ValueU >
	void testNotT( std::string const & name
		, test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testNot" + name );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT< ValueU > >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 16u
				, [&]( ComputeIn in )
				{
					auto v = writer.declLocale< ValueT >( "v"
						, test::getDefault< ValueT >( writer ) );
					auto result = writer.declLocale( "result"
						, binNot( v ) );

					if constexpr ( std::is_same_v< ValueT, BVec2 > )
					{
						ssbo[0].a() = uvec2( result );
					}
					else if constexpr ( std::is_same_v< ValueT, BVec3 > )
					{
						ssbo[0].a() = uvec3( result );
					}
					else if constexpr ( std::is_same_v< ValueT, BVec4 > )
					{
						ssbo[0].a() = uvec4( result );
					}
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void testNot( test::sdw_test::TestCounts & testCounts )
	{
		testNotT< sdw::BVec2, sdw::UVec2 >( "2", testCounts );
		testNotT< sdw::BVec3, sdw::UVec3 >( "3", testCounts );
		testNotT< sdw::BVec4, sdw::UVec4 >( "4", testCounts );
	}
}

sdwTestSuiteMain( TestWriterConstantIntrinsics )
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
	testATan2( testCounts );
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
	testMin( testCounts );
	testMax( testCounts );
	testClamp( testCounts );
	testMix( testCounts );
	testStep( testCounts );
	testSmoothStep( testCounts );
	testFma( testCounts );
	testIsnan( testCounts );
	testIsinf( testCounts );
	testLessThan( testCounts );
	testLessThanEqual( testCounts );
	testGreaterThan( testCounts );
	testGreaterThanEqual( testCounts );
	testEqual( testCounts );
	testNotEqual( testCounts );
	testAll( testCounts );
	testAny( testCounts );
	testNot( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterConstantIntrinsics )
