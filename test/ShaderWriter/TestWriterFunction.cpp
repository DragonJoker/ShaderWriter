#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/UniformBuffer.hpp>

#pragma warning( disable:5245 )
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	struct St
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , St );

		St( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, a{ getMember< sdw::Vec4 >( "a" ) }
			, b{ getMemberArray< sdw::Vec4 >( "b" ) }
		{
		}

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer, makeType( writer.getTypesCache() ) );
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140, "St" );

			if ( result->empty() )
			{
				result->declMember( "a", ast::type::Kind::eVec4F );
				result->declMember( "b", ast::type::Kind::eVec4F, 4u );
			}

			return result;
		}

		sdw::Vec4 a;
		sdw::Array< sdw::Vec4 > b;
	};
	using InSt = sdw::InParam< St >;

	struct St2
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , St2 );

		St2( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, a{ getMember< St >( "a" ) }
			, b{ getMember< sdw::Vec4 >( "b" ) }
		{
		}

		static std::unique_ptr< sdw::Struct > declare( sdw::ShaderWriter & writer )
		{
			return std::make_unique< sdw::Struct >( writer, makeType( writer.getTypesCache() ) );
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd140, "St2" );

			if ( result->empty() )
			{
				result->declMember( "a", St::makeType( cache ) );
				result->declMember( "b", ast::type::Kind::eVec4F );
			}

			return result;
		}

		St a;
		sdw::Vec4 b;
	};
	using InSt2 = sdw::InParam< St2 >;

	template< typename ValueT >
	void testSingleInParamLiteral( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamLiteral" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( test::getDefault< ValueT >( writer ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamConstant( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamConstant" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
				auto v = writer.declConstant< ValueT >( "v", test::getDefault< ValueT >( writer ) );
				test( test::getDefault< ValueT >( writer ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamConstantArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamConstantArray" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };
		auto c = writer.declConstantArray< ValueT >( "c"
			, std::vector< ValueT >{ test::getDefault< ValueT >( writer )
				, test::getDefault< ValueT >( writer ) } );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT s )
			{
				auto a = writer.declLocale< ValueT >( "a", c[0_u] * s );
			}
			, sdw::InParam< ValueT >{ writer, "s" } );

		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
				auto s = writer.declLocale( "s", test::getDefault< ValueT >( writer ) );
				test( s );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< ValueT >( "v" );
				test( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamArrayVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamArrayVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< ValueT >( "a", 4u );
				test( a[0] );
				test( a[test::getDefault< UInt >( writer )] );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamInputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamInputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto inpa = writer.declInput< ValueT >( "inpa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( inpa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamOutputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamOutputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutput< ValueT >( "outa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				outa = test::getDefault< ValueT >( writer );
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamUniformVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamUniformVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		UniformBuffer buffer{ writer, "MyUbo", 4u, 0u };
		buffer.declMember< ValueT >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamStorageVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamStorageVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< ValueT >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInParamStructMember( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInParamStructMember" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< ValueT >( "v" );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p );
				p = a;
			}
			, sdw::InParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMember< ValueT >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleOutParamVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleOutParamVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p = a;
			}
			, sdw::OutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< ValueT >( "v" );
				test( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleOutParamArrayVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleOutParamArrayVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p = a;
			}
			, sdw::OutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< ValueT >( "a", 4u );
				test( a[0] );
				test( a[test::getDefault< UInt >( writer )] );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleOutParamOutputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleOutParamOutputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutput< ValueT >( "outa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p = a;
			}
			, sdw::OutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleOutParamStorageVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleOutParamUniformVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< ValueT >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p = a;
			}
			, sdw::OutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleOutParamStructMember( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleOutParamStructMember" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< ValueT >( "v" );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p = a;
			}
			, sdw::OutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMember< ValueT >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInOutParamVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInOutParamVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< ValueT >( "v" );
				test( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInOutParamArrayVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInOutParamArrayVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< ValueT >( "a", 4u );
				test( a[0] );
				test( a[test::getDefault< UInt >( writer )] );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInOutParamOutputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInOutParamOutputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutput< ValueT >( "outa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				outa = test::getDefault< ValueT >( writer );
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInOutParamStorageVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInOutParamUniformVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< ValueT >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testSingleInOutParamStructMember( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testSingleInOutParamStructMember" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< ValueT >( "v" );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( ValueT p )
			{
				auto a = writer.declLocale< ValueT >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< ValueT >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMember< ValueT >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamLiteral( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamLiteral" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( test::getDefaultArray< ValueT >( writer, 4u ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamConstant( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamConstant" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declConstantArray< ValueT >( "a", test::getDefaultVector< ValueT >( writer, 4u ) );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< ValueT >( "a", 4u );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamInputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamInputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto inpa = writer.declInputArray< ValueT >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( inpa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamOutputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamInputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutputArray< ValueT >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				outa[0] = test::getDefault< ValueT >( writer );
				outa[1] = test::getDefault< ValueT >( writer );
				outa[2] = test::getDefault< ValueT >( writer );
				outa[3] = test::getDefault< ValueT >( writer );
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamUniformVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamUniformVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		UniformBuffer buffer{ writer, "MyUbo", 4u, 0u };
		buffer.declMember< ValueT >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMemberArray< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamStorageVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamStorageVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< ValueT >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMemberArray< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInParamStructMember( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInParamStructMember" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< ValueT >( "v", 4u );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMemberArray< ValueT >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayOutParamVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayOutParamVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::OutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< ValueT >( "a", 4u );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayOutParamOutputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayOutParamOutputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutputArray< ValueT >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
		, sdw::OutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayOutParamStorageVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayOutParamStorageVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		auto uv = buffer.declMember< ValueT >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefaultArray< ValueT >( writer, 4u ) );
				p = a;
			}
		, sdw::OutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayOutParamStructMember( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayOutParamStructMember" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< ValueT >( "v", 4u );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::OutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMemberArray< ValueT >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInOutParamVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInOutParamVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< ValueT >( "a", 4u );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInOutParamOutputVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInOutParamOutputVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutputArray< ValueT >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
		, sdw::InOutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInOutParamStorageVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInOutParamStorageVariable" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< ValueT >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMemberArray< ValueT >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testArrayInOutParamStructMember( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "testArrayInOutParamStructMember" + ast::debug::getTypeName( sdw::typeEnumV< ValueT > ) );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< ValueT >( "v", 4u );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< ValueT > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< ValueT >( "a", test::getDefault< ValueT >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< ValueT > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMemberArray< ValueT >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInArray" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };
		
		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & p )
			{
			}
			, InVec4Array{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto va = writer.declLocaleArray< Vec4 >( "va", 4u );
				foo01( va );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInOutVec4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInOutVec4" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto foo02 = writer.implementFunction< sdw::Void >( "foo02"
			, [&]( Vec4 p )
			{
				p = p + vec4( 1.0_f );
			}
			, InOutVec4{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				foo02( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInMat4InVec4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInMat4InVec4" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		UniformBuffer buffer{ writer, "Matrices", 0u, 0u };
		auto c3d_viewMatrix = buffer.declMember< Mat4 >( "c3d_viewMatrix" );
		buffer.end();

		auto foo03 = writer.implementFunction< Vec4 >( "foo03"
			, [&]( Mat4 const & m
				, Vec4 const & p )
			{
				writer.returnStmt( m * p );
			}
			, InMat4{ writer, "m" }
			, InVec4{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto m = writer.declLocale< Mat4 >( "m" );
				foo03( m, v );
				auto r = writer.declLocale< Vec4 >( "r"
					, foo03( c3d_viewMatrix, v ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInStInVec4( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInStInVec4" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto st = St::declare( writer );

		auto foo04 = writer.implementFunction< Vec4 >( "foo04"
			, [&]( St const & m
				, Vec4 const & p )
			{
				FOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					m.b[i] *= p;
				}
				ROF;
				writer.returnStmt( m.a * p );
			}
			, InSt{ writer, "m" }
			, InVec4{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto inst = st->getInstance< St >( "inst", true );
				v = foo04( inst, v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInSpImgInVec2( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInSpImgInVec2" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto c3d_maps = writer.declCombinedImgArray< FImg2DRgba32 >( "c3d_maps", 1u, 0u, 4u );

		auto foo05 = writer.implementFunction< Vec4 >( "foo05"
			, [&]( CombinedImage2DRgba32 const & sim
				, Vec2 const & pos )
			{
				writer.returnStmt( sim.sample( pos ) );
			}
			, InCombinedImage2DRgba32{ writer, "sim" }
			, InVec2{ writer, "pos" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				v = foo05( c3d_maps[0_u], vec2( 0.0_f, 1.0_f ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInVec4Ass( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInVec4Ass" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto foo06 = writer.implementFunction< Vec2 >( "foo06"
			, [&]( Vec2 const & e )
			{
				e.r() = e.r() * abs( 5.0_f * e.r() - 5.0_f * 0.75_f );
				writer.returnStmt( round( e ) );
			}
			, InVec2{ writer, "e" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto e = writer.declLocale< Vec2 >( "e" );
				e = foo06( e );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void params( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "params" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		UniformBuffer buffer{ writer, "Matrices", 0u, 0u };
		auto c3d_viewMatrix = buffer.declMember< Mat4 >( "c3d_viewMatrix" );
		buffer.end();

		auto c3d_maps = writer.declCombinedImgArray< FImg2DRgba32 >( "c3d_maps", 1u, 0u, 4u );

		auto st = St::declare( writer );

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & arr )
			{
			}
			, InVec4Array{ writer, "arr", 4u } );

		auto foo02 = writer.implementFunction< sdw::Void >( "foo02"
			, [&]( Vec4 pos )
			{
				pos = pos + vec4( 1.0_f );
			}
			, InOutVec4{ writer, "pos" } );

		auto foo03 = writer.implementFunction< Vec4 >( "foo03"
			, [&]( Mat4 const & mtx
				, Vec4 const & pos )
			{
				writer.returnStmt( mtx * pos );
			}
			, InMat4{ writer, "mtx" }
			, InVec4{ writer, "pos" } );

		auto foo04 = writer.implementFunction< Vec4 >( "foo04"
			, [&]( St const & str
				, Vec4 const & pos )
			{
				FOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					str.b[i] *= pos;
				}
				ROF;
				writer.returnStmt( str.a * pos );
			}
			, InSt{ writer, "str" }
			, InVec4{ writer, "pos" } );

		auto foo05 = writer.implementFunction< Vec4 >( "foo05"
			, [&]( CombinedImage2DRgba32 const & sim
				, Vec2 const & pos )
			{
				writer.returnStmt( sim.sample( pos ) );
			}
			, InCombinedImage2DRgba32{ writer, "sim" }
			, InVec2{ writer, "pos" } );

		auto foo06 = writer.implementFunction< Vec2 >( "foo06"
			, [&]( Vec2 const & pos )
			{
				pos.r() = pos.r() * abs( 5.0_f * pos.r() - 5.0_f * 0.75_f );
				writer.returnStmt( round( pos ) );
			}
			, InVec2{ writer, "pos" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto va = writer.declLocaleArray< Vec4 >( "va", 4u );
				auto m = writer.declLocale< Mat4 >( "m" );
				foo01( va );
				foo02( v );
				foo03( m, v );
				auto r = writer.declLocale< Vec4 >( "r"
					, foo03( c3d_viewMatrix, v ) );
				auto inst = st->getInstance< St >( "inst", true );
				v = foo04( inst, v );
				v = foo05( c3d_maps[0_u], vec2( 0.0_f, 1.0_f ) );
				auto e = writer.declLocale< Vec2 >( "e" );
				e = foo06( e );
			} );

		test::expectError( "must be a memory object declaration"
			, testCounts );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void arrayParamAccessInOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arrayAccessInOut" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< sdw::Void >( "foo01"
			, [&]( Array< Vec4 > const & pp
				, Vec4 pv
				, Int const & pi )
			{
				auto j = writer.declLocale< Int >( "j" );
				pv = pp[j];
			}
			, InVec4Array{ writer, "pp", 4u }
			, OutVec4{ writer, "pv" }
			, InInt{ writer, "pi" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto p = writer.declLocaleArray< Vec4 >( "p", 4u );
				auto v = writer.declLocale< Vec4 >( "v" );
				auto i = writer.declLocale< Int >( "i" );
				foo01( p, v, i );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void vecParamAccessInIndex( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vecAccessInIndex" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< Float >( "foo01"
			, [&]( Float const & d 
				, Vec3 const & pp )
			{
				writer.returnStmt( pp[0] / ( ( pp[1] * d ) + pp[2] ) );
			}
			, InFloat{ writer, "pv" }
			, InVec3{ writer, "pp" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto p = writer.declLocale< Vec3 >( "p" );
				auto v = writer.declLocale< Float >( "v", 0.0_f );
				v = foo01( v, p );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void rImageParamForward( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "rImageParamForward" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto s = writer.declStorageImg< RFImg3DRgba32 >( "s", 0u, 0u );

		auto foo01 = writer.implementFunction< Void >( "foo01"
			, [&]( RImage3DRgba32 const & ps
				, Vec3 pp )
			{
			}
			, InRImage3DRgba32{ writer, "ps" }
			, InVec3{ writer, "pp" } );

		auto foo02 = writer.implementFunction< Void >( "foo02"
			, [&]( RImage3DRgba32 const & ps
				, Vec3 pp )
			{
				foo01( ps, pp );
			}
			, InRImage3DRgba32{ writer, "ps" }
			, InVec3{ writer, "pp" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto p = writer.declLocale< Vec3 >( "p" );
				foo02( s, p );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void wImageParamForward( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "wImageParamForward" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto s = writer.declStorageImg< WFImg3DRgba32 >( "s", 0u, 0u );

		auto foo01 = writer.implementFunction< Void >( "foo01"
			, [&]( WImage3DRgba32 const & ps
				, Vec3 pp )
			{
			}
			, InWImage3DRgba32{ writer, "ps" }
			, InVec3{ writer, "pp" } );

		auto foo02 = writer.implementFunction< Void >( "foo02"
			, [&]( WImage3DRgba32 const & ps
				, Vec3 pp )
			{
				foo01( ps, pp );
			}
			, InWImage3DRgba32{ writer, "ps" }
			, InVec3{ writer, "pp" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto p = writer.declLocale< Vec3 >( "p" );
				foo02( s, p );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void rwImageParamForward( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "rwImageParamForward" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto s = writer.declStorageImg< RWFImg3DRgba32 >( "s", 0u, 0u );

		auto foo01 = writer.implementFunction< Void >( "foo01"
			, [&]( RWImage3DRgba32 const & ps
				, Vec3 pp )
			{
			}
			, InRWImage3DRgba32{ writer, "ps" }
			, InVec3{ writer, "pp" } );

		auto foo02 = writer.implementFunction< Void >( "foo02"
			, [&]( RWImage3DRgba32 const & ps
				, Vec3 pp )
			{
				foo01( ps, pp );
			}
			, InRWImage3DRgba32{ writer, "ps" }
			, InVec3{ writer, "pp" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto p = writer.declLocale< Vec3 >( "p" );
				foo02( s, p );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void structInParam( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "structInParam" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		St::declare( writer );

		auto foo01 = writer.implementFunction< Vec4 >( "foo01"
			, [&]( St const & pst )
			{
				auto lr = writer.declLocale< Vec4 >( "lr" );
				lr = pst.a;
				writer.returnStmt( lr );
			}
			, InSt{ writer, "pst" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto r = writer.declLocale< Vec4 >( "r" );
				auto st = writer.declLocale< St >( "st" );
				r = foo01( st );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void structInParamForward( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "structInParamForward" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		St::declare( writer );
		St2::declare( writer );

		auto foo01 = writer.implementFunction< Vec4 >( "foo01"
			, [&]( St const & pst )
			{
				auto lr = writer.declLocale< Vec4 >( "lr" );
				lr = pst.a;
				writer.returnStmt( lr );
			}
			, InSt{ writer, "pst" } );

		auto foo02 = writer.implementFunction< Vec4 >( "foo02"
			, [&]( St2 const & pst2 )
			{
				writer.returnStmt( foo01( pst2.a ) );
			}
			, InSt2{ writer, "pst2" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto r = writer.declLocale< Vec4 >( "r" );
				auto st2 = writer.declLocale< St2 >( "st2" );
				r = foo02( st2 );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramInWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramInWhile" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< Float >( "foo01"
			, [&]( Float test
				, Float const & end )
			{
				WHILE( writer, test > end )
				{
					test -= end;
				}
				ELIHW;

				writer.returnStmt( test );
			}
			, InFloat{ writer, "test" }
			, InFloat{ writer, "end" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto v = writer.declLocale< Float >( "v" );
				auto e = writer.declLocale< Float >( "e" );
				v = foo01( v, e );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramMbrAccessInWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "paramMbrAccessInWhile" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		St::declare( writer );

		auto foo01 = writer.implementFunction< Float >( "foo01"
			, [&]( Float ptest1
				, Float const & pend1 )
			{
				writer.returnStmt( writer.ternary( ptest1 > pend1, ptest1, pend1 ) );
			}
			, InFloat{ writer, "ptest1" }
			, InFloat{ writer, "pend1" } );

		auto foo02 = writer.implementFunction< Float >( "foo02"
			, [&]( St const & pst
				, Float ptest
				, Float const & pend )
			{
				WHILE( writer, ptest > pend )
				{
					ptest = foo01( pst.a.x(), pend );
				}
				ELIHW;

				writer.returnStmt( pst.a.x() );
			}
			, InSt{ writer, "pst" }
			, InFloat{ writer, "ptest" }
			, InFloat{ writer, "pend" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto v = writer.declLocale< Float >( "v" );
				auto e = writer.declLocale< Float >( "e" );
				auto st = writer.declLocale< St >( "st" );
				v = foo02( st, v, e );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void removeGamma( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "removeGamma" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				IF( writer, gamma < 0.0_f )
				{
					writer.returnStmt( srgb );
				}
				FI;

				writer.returnStmt( pow( srgb, vec3( gamma ) ) );
			}
			, InFloat{ writer, "gamma" }
			, InVec3{ writer, "srgb" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto f = writer.declLocale< Float >( "f" );
				auto v = writer.declLocale< Vec3 >( "v" );
				v = removeGamma( f, v );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void returns( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "returns" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		St::declare( writer );
		St2::declare( writer );

		auto foo01 = writer.implementFunction< St2 >( "foo01"
			, [&]( Vec4 const & p )
			{
				auto result = writer.declLocale< St2 >( "result" );
				result.a.a = p * 2.0_f;
				result.a.b[0] = p * 2.0_f;
				result.a.b[1] = p * 3.0_f;
				result.a.b[2] = p * 4.0_f;
				result.a.b[3] = p * 5.0_f;
				result.b = p * 6.0_f;
				writer.returnStmt( result );
			}
			, InVec4{ writer, "p" } );

		auto foo02 = writer.implementFunction< Vec4 >( "foo02"
			, [&]( St2 const & p )
			{
				writer.returnStmt( p.a.a );
			}
			, InSt2{ writer, "p" } );

		auto foo03 = writer.implementFunction< Float >( "foo03"
			, [&]( Vec4 const & p )
			{
				IF( writer, p.x() )
				{
					writer.returnStmt( p.y() );
				}
				ELSE
				{
					writer.returnStmt( p.z() );
				}
				FI;
			}
			, InVec4{ writer, "p" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				v = foo02( foo01( v ) );
				auto r = writer.declLocale( "r"
					, foo01( v ) );
				v += foo02( r );
				v.x() = foo03( v );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void returnAfterWhile( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "returnAfterWhile" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< Vec2 >( "foo01"
			, [&]( Vec2 const & texcoord
				, Vec2 const & dir
				, Vec2 e )
			{
				auto coord = writer.declLocale( "coord"
					, vec4( texcoord, -1.0_f, 1.0_f ) );
				auto t = writer.declLocale( "t"
					, vec3( 0.5_f, 1.2_f, 1.0_f ) );

				WHILE( writer, coord.z() < 15.0_f && coord.w() > 0.9_f )
				{
					coord.xyz() = fma( t, vec3( dir, 1.0_f ), coord.xyz() );
					e = normalize( coord.xy() );
					coord.w() = dot( e, vec2( 0.5_f, 0.5_f ) );
				}
				ELIHW;

				writer.returnStmt( coord.zw() );
			}
			, InVec2{ writer, "texcoord" }
			, InVec2{ writer, "dir" }
			, OutVec2{ writer, "e" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto v = writer.declLocale< Vec2 >( "v" );
				auto e = writer.declLocale< Vec2 >( "e" );
				v = foo01( v, v, e );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void paramIfElseIf( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "fog" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< Vec4 >( "foo01"
			, [&]( Vec4 const & colour
				, UInt type
				, Float factor )
			{
				auto bgColour = writer.declLocale( "bgColour", colour );
				auto result = writer.declLocale( "result", colour );

				IF( writer, type == 0_u )
				{
					result = vec4( mix( bgColour, colour, vec4( factor ) ).rgb(), colour.a() );
				}
				ELSEIF( type == 1_u )
				{
					result = vec4( mix( bgColour, colour, vec4( factor ) ).rgb(), colour.a() );
				}
				FI;

				writer.returnStmt( result );
			}
			, InVec4{ writer, "colour" }
			, InUInt{ writer, "type" }
			, InFloat{ writer, "factor" } );

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto v = writer.declLocale< Vec4 >( "v" );
				auto t = writer.declLocale< UInt >( "t" );
				auto f = writer.declLocale< Float >( "f" );
				v = foo01( v, t, f );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void nestedFunctionDecl( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "nestedFunctionDecl" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
					, [&]( Float const & gamma
						, Vec3 const & srgb )
					{
						IF( writer, gamma < 0.0_f )
						{
							writer.returnStmt( srgb );
						}
						FI;

						writer.returnStmt( pow( srgb, vec3( gamma ) ) );
					}
					, InFloat{ writer, "gamma" }
					, InVec3{ writer, "srgb" } );

				auto f = writer.declLocale< Float >( "f" );
				auto v = writer.declLocale< Vec3 >( "v" );
				v = removeGamma( f, v );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	template< typename ValueT >
	void testParams( test::sdw_test::TestCounts & testCounts )
	{
		testSingleInParamLiteral< ValueT >( testCounts );
		testSingleInParamConstant< ValueT >( testCounts );
		testSingleInParamConstantArray< ValueT >( testCounts );
		testSingleInParamVariable< ValueT >( testCounts );
		testSingleInParamArrayVariable< ValueT >( testCounts );
		testSingleInParamInputVariable< ValueT >( testCounts );
		testSingleInParamUniformVariable< ValueT >( testCounts );
		testSingleInParamStorageVariable< ValueT >( testCounts );
		testSingleInParamStructMember< ValueT >( testCounts );

		testSingleOutParamVariable< ValueT >( testCounts );
		testSingleOutParamArrayVariable< ValueT >( testCounts );
		testSingleOutParamStorageVariable< ValueT >( testCounts );
		testSingleOutParamStructMember< ValueT >( testCounts );

		testSingleInOutParamVariable< ValueT >( testCounts );
		testSingleInOutParamArrayVariable< ValueT >( testCounts );
		testSingleInOutParamStorageVariable< ValueT >( testCounts );
		testSingleInOutParamStructMember< ValueT >( testCounts );

		testArrayInParamLiteral< ValueT >( testCounts );
		testArrayInParamConstant< ValueT >( testCounts );
		testArrayInParamVariable< ValueT >( testCounts );

		if constexpr ( !std::is_same_v< ValueT, sdw::Mat2 >
			&& !std::is_same_v< ValueT, sdw::Mat3 >
			&& !std::is_same_v< ValueT, sdw::Mat4 > )
		{
			testSingleInParamOutputVariable< ValueT >( testCounts );
			testArrayInParamInputVariable< ValueT >( testCounts );
			testArrayInParamOutputVariable< ValueT >( testCounts );
		}

		testArrayInParamUniformVariable< ValueT >( testCounts );
		testArrayInParamStorageVariable< ValueT >( testCounts );
		testArrayInParamStructMember< ValueT >( testCounts );

		testArrayOutParamVariable< ValueT >( testCounts );

		if constexpr ( !std::is_same_v< ValueT, sdw::Mat2 >
			&& !std::is_same_v< ValueT, sdw::Mat3 >
			&& !std::is_same_v< ValueT, sdw::Mat4 > )
		{
			testSingleOutParamOutputVariable< ValueT >( testCounts );
			testArrayOutParamOutputVariable< ValueT >( testCounts );
		}

		testArrayOutParamStorageVariable< ValueT >( testCounts );
		testArrayOutParamStructMember< ValueT >( testCounts );

		testArrayInOutParamVariable< ValueT >( testCounts );

		if constexpr ( !std::is_same_v< ValueT, sdw::Mat2 >
			&& !std::is_same_v< ValueT, sdw::Mat3 >
			&& !std::is_same_v< ValueT, sdw::Mat4 > )
		{
			testSingleInOutParamOutputVariable< ValueT >( testCounts );
			testArrayInOutParamOutputVariable< ValueT >( testCounts );
		}

		testArrayInOutParamStorageVariable< ValueT >( testCounts );
		testArrayInOutParamStructMember< ValueT >( testCounts );
	}
}

sdwTestSuiteMain( TestWriterFunction )
{
	sdwTestSuiteBegin();
	testParams< sdw::Int >( testCounts );
	testParams< sdw::UInt >( testCounts );
	testParams< sdw::Float >( testCounts );
	testParams< sdw::IVec2 >( testCounts );
	testParams< sdw::UVec2 >( testCounts );
	testParams< sdw::Vec2 >( testCounts );
	testParams< sdw::IVec3 >( testCounts );
	testParams< sdw::UVec3 >( testCounts );
	testParams< sdw::Vec3 >( testCounts );
	testParams< sdw::IVec4 >( testCounts );
	testParams< sdw::UVec4 >( testCounts );
	testParams< sdw::Vec4 >( testCounts );
	testParams< sdw::Mat2 >( testCounts );
	testParams< sdw::Mat3 >( testCounts );
	testParams< sdw::Mat4 >( testCounts );
	paramInArray( testCounts );
	paramInOutVec4( testCounts );
	paramInMat4InVec4( testCounts );
	paramInStInVec4( testCounts );
	paramInSpImgInVec2( testCounts );
	paramInVec4Ass( testCounts );
	params( testCounts );
	arrayParamAccessInOut( testCounts );
	vecParamAccessInIndex( testCounts );
	rImageParamForward( testCounts );
	wImageParamForward( testCounts );
	rwImageParamForward( testCounts );
	structInParam( testCounts );
	structInParamForward( testCounts );
	removeGamma( testCounts );
	returns( testCounts );
	returnAfterWhile( testCounts );
	paramInWhile( testCounts );
	paramMbrAccessInWhile( testCounts );
	paramIfElseIf( testCounts );
	nestedFunctionDecl( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterFunction )
