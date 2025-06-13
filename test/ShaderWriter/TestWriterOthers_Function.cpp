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

	using ParamTypes = testing::Types< sdw::Int, sdw::UInt, sdw::Float
		, sdw::IVec2, sdw::UVec2, sdw::Vec2
		, sdw::IVec3, sdw::UVec3, sdw::Vec3
		, sdw::IVec4, sdw::UVec4, sdw::Vec4
		, sdw::Mat2, sdw::Mat3, sdw::Mat4 >;

	class ParamTypeNames
	{
	public:
		template< typename T >
		static std::string GetName( int )
		{
			if constexpr ( std::is_same_v< T, sdw::Int > ) return "sdw::Int";
			if constexpr ( std::is_same_v< T, sdw::UInt > ) return "sdw::UInt";
			if constexpr ( std::is_same_v< T, sdw::Float > ) return "sdw::Float";
			if constexpr ( std::is_same_v< T, sdw::IVec2 > ) return "sdw::IVec2";
			if constexpr ( std::is_same_v< T, sdw::UVec2 > ) return "sdw::UVec2";
			if constexpr ( std::is_same_v< T, sdw::Vec2 > ) return "sdw::Vec2";
			if constexpr ( std::is_same_v< T, sdw::IVec3 > ) return "sdw::IVec3";
			if constexpr ( std::is_same_v< T, sdw::UVec3 > ) return "sdw::UVec3";
			if constexpr ( std::is_same_v< T, sdw::Vec3 > ) return "sdw::Vec3";
			if constexpr ( std::is_same_v< T, sdw::IVec4 > ) return "sdw::IVec4";
			if constexpr ( std::is_same_v< T, sdw::UVec4 > ) return "sdw::UVec4";
			if constexpr ( std::is_same_v< T, sdw::Vec4 > ) return "sdw::Vec4";
			if constexpr ( std::is_same_v< T, sdw::Mat2 > ) return "sdw::Mat2";
			if constexpr ( std::is_same_v< T, sdw::Mat3 > ) return "sdw::Mat3";
			if constexpr ( std::is_same_v< T, sdw::Mat4 > ) return "sdw::Mat4";
		}
	};

	template< typename ParamT >
	struct TestParamsT : public SDWTest
	{
	};

	TYPED_TEST_SUITE( TestParamsT, ParamTypes, ParamTypeNames );

	TYPED_TEST( TestParamsT, testSingleInParamLiteral )
	{
		sdwTestBegin( "testSingleInParamLiteral" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( test::getDefault< TypeParam >( writer ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamConstant )
	{
		sdwTestBegin( "testSingleInParamConstant" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
				auto v = writer.declConstant< TypeParam >( "v", test::getDefault< TypeParam >( writer ) );
				test( test::getDefault< TypeParam >( writer ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamConstantArray )
	{
		sdwTestBegin( "testSingleInParamConstantArray" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };
		auto c = writer.declConstantArray< TypeParam >( "c"
			, std::vector< TypeParam >{ test::getDefault< TypeParam >( writer )
				, test::getDefault< TypeParam >( writer ) } );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam s )
			{
				auto a = writer.declLocale< TypeParam >( "a", c[0_u] * s );
			}
			, sdw::InParam< TypeParam >{ writer, "s" } );

		writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
			{
				auto s = writer.declLocale( "s", test::getDefault< TypeParam >( writer ) );
				test( s );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamVariable )
	{
		sdwTestBegin( "testSingleInParamVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< TypeParam >( "v" );
				test( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamArrayVariable )
	{
		sdwTestBegin( "testSingleInParamArrayVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< TypeParam >( "a", 4u );
				test( a[0] );
				test( a[test::getDefault< UInt >( writer )] );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamInputVariable )
	{
		sdwTestBegin( "testSingleInParamInputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto inpa = writer.declInput< TypeParam >( "inpa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( inpa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamUniformVariable )
	{
		sdwTestBegin( "testSingleInParamUniformVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		UniformBuffer buffer{ writer, "MyUbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamStorageVariable )
	{
		sdwTestBegin( "testSingleInParamStorageVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInParamStructMember )
	{
		sdwTestBegin( "testSingleInParamStructMember" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< TypeParam >( "v" );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMember< TypeParam >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleOutParamVariable )
	{
		sdwTestBegin( "testSingleOutParamVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p = a;
			}
			, sdw::OutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< TypeParam >( "v" );
				test( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleOutParamArrayVariable )
	{
		sdwTestBegin( "testSingleOutParamArrayVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p = a;
			}
			, sdw::OutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< TypeParam >( "a", 4u );
				test( a[0] );
				test( a[test::getDefault< UInt >( writer )] );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleOutParamStorageVariable )
	{
		sdwTestBegin( "testSingleOutParamUniformVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p = a;
			}
			, sdw::OutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleOutParamStructMember )
	{
		sdwTestBegin( "testSingleOutParamStructMember" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< TypeParam >( "v" );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p = a;
			}
			, sdw::OutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMember< TypeParam >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInOutParamVariable )
	{
		sdwTestBegin( "testSingleInOutParamVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto v = writer.declLocale< TypeParam >( "v" );
				test( v );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInOutParamArrayVariable )
	{
		sdwTestBegin( "testSingleInOutParamArrayVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< TypeParam >( "a", 4u );
				test( a[0] );
				test( a[test::getDefault< UInt >( writer )] );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInOutParamStorageVariable )
	{
		sdwTestBegin( "testSingleInOutParamUniformVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v" );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMember< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testSingleInOutParamStructMember )
	{
		sdwTestBegin( "testSingleInOutParamStructMember" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< TypeParam >( "v" );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMember< TypeParam >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInParamLiteral )
	{
		sdwTestBegin( "testArrayInParamLiteral" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( test::getDefaultArray< TypeParam >( writer, 4u ) );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInParamConstant )
	{
		sdwTestBegin( "testArrayInParamConstant" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declConstantArray< TypeParam >( "a", test::getDefaultVector< TypeParam >( writer, 4u ) );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInParamVariable )
	{
		sdwTestBegin( "testArrayInParamVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< TypeParam >( "a", 4u );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInParamUniformVariable )
	{
		sdwTestBegin( "testArrayInParamUniformVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		UniformBuffer buffer{ writer, "MyUbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMemberArray< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInParamStorageVariable )
	{
		sdwTestBegin( "testArrayInParamStorageVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMemberArray< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInParamStructMember )
	{
		sdwTestBegin( "testArrayInParamStructMember" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< TypeParam >( "v", 4u );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMemberArray< TypeParam >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayOutParamVariable )
	{
		sdwTestBegin( "testArrayOutParamVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::OutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< TypeParam >( "a", 4u );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayOutParamStorageVariable )
	{
		sdwTestBegin( "testArrayOutParamStorageVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		auto uv = buffer.declMember< TypeParam >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefaultArray< TypeParam >( writer, 4u ) );
				p = a;
			}
		, sdw::OutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayOutParamStructMember )
	{
		sdwTestBegin( "testArrayOutParamStructMember" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< TypeParam >( "v", 4u );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::OutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMemberArray< TypeParam >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInOutParamVariable )
	{
		sdwTestBegin( "testArrayInOutParamVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto a = writer.declLocaleArray< TypeParam >( "a", 4u );
				test( a );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsT, testArrayInOutParamStorageVariable )
	{
		sdwTestBegin( "testArrayInOutParamStorageVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		StorageBuffer buffer{ writer, "MySsbo", 4u, 0u };
		buffer.declMember< TypeParam >( "v", 4u );
		buffer.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto uv = buffer.getMemberArray< TypeParam >( "v" );
				test( uv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	using ParamTypesNoMatrix = testing::Types< sdw::Int, sdw::UInt, sdw::Float
		, sdw::IVec2, sdw::UVec2, sdw::Vec2
		, sdw::IVec3, sdw::UVec3, sdw::Vec3
		, sdw::IVec4, sdw::UVec4, sdw::Vec4 >;

	template< typename ParamT >
	struct TestParamsNoMatrixT : public SDWTest
	{
	};

	TYPED_TEST( TestParamsT, testArrayInOutParamStructMember )
	{
		sdwTestBegin( "testArrayInOutParamStructMember" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		Struct st{ writer, "St" };
		st.declMember< TypeParam >( "v", 4u );
		st.end();

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				auto s = st.getInstance< StructInstance >( "s", true );
				auto sv = s.getMemberArray< TypeParam >( "v" );
				test( sv );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST_SUITE( TestParamsNoMatrixT, ParamTypesNoMatrix, ParamTypeNames );

	TYPED_TEST( TestParamsNoMatrixT, testSingleInParamOutputVariable )
	{
		sdwTestBegin( "testSingleInParamOutputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutput< TypeParam >( "outa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p );
				p = a;
			}
			, sdw::InParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				outa = test::getDefault< TypeParam >( writer );
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsNoMatrixT, testArrayInParamInputVariable )
	{
		sdwTestBegin( "testArrayInParamInputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto inpa = writer.declInputArray< TypeParam >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( inpa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsNoMatrixT, testArrayInParamOutputVariable )
	{
		sdwTestBegin( "testArrayInParamInputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutputArray< TypeParam >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				outa[0] = test::getDefault< TypeParam >( writer );
				outa[1] = test::getDefault< TypeParam >( writer );
				outa[2] = test::getDefault< TypeParam >( writer );
				outa[3] = test::getDefault< TypeParam >( writer );
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsNoMatrixT, testSingleOutParamOutputVariable )
	{
		sdwTestBegin( "testSingleOutParamOutputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutput< TypeParam >( "outa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p = a;
			}
			, sdw::OutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsNoMatrixT, testArrayOutParamOutputVariable )
	{
		sdwTestBegin( "testArrayOutParamOutputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutputArray< TypeParam >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::OutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsNoMatrixT, testSingleInOutParamOutputVariable )
	{
		sdwTestBegin( "testSingleInOutParamOutputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutput< TypeParam >( "outa", 0 );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( TypeParam p )
			{
				auto a = writer.declLocale< TypeParam >( "a", p * p );
				p = a;
			}
			, sdw::InOutParam< TypeParam >{ writer, "p" } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				outa = test::getDefault< TypeParam >( writer );
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TYPED_TEST( TestParamsNoMatrixT, testArrayInOutParamOutputVariable )
	{
		sdwTestBegin( "testArrayInOutParamOutputVariable" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto outa = writer.declOutputArray< TypeParam >( "inpa", 0, 4u );

		auto test = writer.implementFunction< sdw::Void >( "test"
			, [&]( Array< TypeParam > p )
			{
				auto i = writer.declLocale< UInt >( "i", 1_u );
				auto a = writer.declLocale< TypeParam >( "a", test::getDefault< TypeParam >( writer ) );
				p[0_u] = a;
				p[i] = a;
				p[i + 1_u] = a;
				p[i * 3_u] = a;
			}
			, sdw::InOutParam< Array< TypeParam > >{ writer, "p", 4u } );

		writer.implementMainT< VoidT, VoidT >( [&]( FragmentInT< VoidT > in
			, FragmentOutT< VoidT > out )
			{
				test( outa );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInArray )
	{
		sdwTestBegin( "paramInArray" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInOutVec4 )
	{
		sdwTestBegin( "paramInOutVec4" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInMat4InVec4 )
	{
		sdwTestBegin( "paramInMat4InVec4" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInStInVec4 )
	{
		sdwTestBegin( "paramInStInVec4" );
		using namespace sdw;
		sdw::FragmentWriter writer{ &testCounts.allocator };

		auto st = St::declare( writer );

		auto foo04 = writer.implementFunction< Vec4 >( "foo04"
			, [&]( St const & m
				, Vec4 const & p )
			{
				sdwFOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					m.b[i] *= p;
				}
				sdwROF
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInSpImgInVec2 )
	{
		sdwTestBegin( "paramInSpImgInVec2" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInVec4Ass )
	{
		sdwTestBegin( "paramInVec4Ass" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, params )
	{
		sdwTestBegin( "params" );
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
				sdwFOR( writer, UInt, i, 0_u, i < 4_u, ++i )
				{
					str.b[i] *= pos;
				}
				sdwROF
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, arrayParamAccessInOut )
	{
		sdwTestBegin( "arrayAccessInOut" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, vecParamAccessInIndex )
	{
		sdwTestBegin( "vecAccessInIndex" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, rImageParamForward )
	{
		sdwTestBegin( "rImageParamForward" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, wImageParamForward )
	{
		sdwTestBegin( "wImageParamForward" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, rwImageParamForward )
	{
		sdwTestBegin( "rwImageParamForward" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, structInParam )
	{
		sdwTestBegin( "structInParam" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, structInParamForward )
	{
		sdwTestBegin( "structInParamForward" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramInWhile )
	{
		sdwTestBegin( "paramInWhile" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< Float >( "foo01"
			, [&]( Float test
				, Float const & end )
			{
				sdwWHILE( writer, test > end )
				{
					test -= end;
				}
				sdwELIHW

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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramMbrAccessInWhile )
	{
		sdwTestBegin( "paramMbrAccessInWhile" );
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
				sdwWHILE( writer, ptest > pend )
				{
					ptest = foo01( pst.a.x(), pend );
				}
				sdwELIHW

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
		sdwTestEnd()
	}

	TEST_F( SDWTest, removeGamma )
	{
		sdwTestBegin( "removeGamma" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				sdwIF( writer, gamma < 0.0_f )
				{
					writer.returnStmt( srgb );
				}
				sdwFI

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
		sdwTestEnd()
	}

	TEST_F( SDWTest, returns )
	{
		sdwTestBegin( "returns" );
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
				sdwIF( writer, p.x() )
				{
					writer.returnStmt( p.y() );
				}
				sdwELSE
				{
					writer.returnStmt( p.z() );
				}
				sdwFI
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, returnAfterWhile )
	{
		sdwTestBegin( "returnAfterWhile" );
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

				sdwWHILE( writer, coord.z() < 15.0_f && coord.w() > 0.9_f )
				{
					coord.xyz() = fma( t, vec3( dir, 1.0_f ), coord.xyz() );
					e = normalize( coord.xy() );
					coord.w() = dot( e, vec2( 0.5_f, 0.5_f ) );
				}
				sdwELIHW

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
		sdwTestEnd()
	}

	TEST_F( SDWTest, paramIfElseIf )
	{
		sdwTestBegin( "fog" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		auto foo01 = writer.implementFunction< Vec4 >( "foo01"
			, [&]( Vec4 const & colour
				, UInt type
				, Float factor )
			{
				auto bgColour = writer.declLocale( "bgColour", colour );
				auto result = writer.declLocale( "result", colour );

				sdwIF( writer, type == 0_u )
				{
					result = vec4( mix( bgColour, colour, vec4( factor ) ).rgb(), colour.a() );
				}
				sdwELSEIF( type == 1_u )
				{
					result = vec4( mix( bgColour, colour, vec4( factor ) ).rgb(), colour.a() );
				}
				sdwFI

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
		sdwTestEnd()
	}

	TEST_F( SDWTest, nestedFunctionDecl )
	{
		sdwTestBegin( "nestedFunctionDecl" );
		using namespace sdw;
		sdw::ComputeWriter writer{ &testCounts.allocator };

		writer.implementMainT< VoidT >( 16u, [&]( ComputeIn in )
			{
				auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
					, [&]( Float const & gamma
						, Vec3 const & srgb )
					{
						sdwIF( writer, gamma < 0.0_f )
						{
							writer.returnStmt( srgb );
						}
						sdwFI

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
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
