#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/StructHelper.hpp>
#include <ShaderWriter/CompositeTypes/StructInstanceHelper.hpp>

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	struct ValuesT
		: public sdw::StructInstanceHelperT< "Values"
			, ast::type::MemoryLayout::eStd430
			, sdw::Vec4Field< "a" >
			, sdw::Vec4Field< "b" >
			, sdw::Vec4Field< "c" >
			, sdw::Vec4Field< "d" >
			, sdw::UVec4Field< "e" > >
	{
		ValuesT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: StructInstanceHelperT{ writer, std::move( expr ), enabled }
		{
		}

		auto a()const { return getMember< "a" >(); }
		auto b()const { return getMember< "b" >(); }
		auto c()const { return getMember< "c" >(); }
		auto d()const { return getMember< "d" >(); }
		auto e()const { return getMember< "e" >(); }
	};

	struct Intersection
		: public sdw::StructInstanceHelperT < "Intersection"
			, sdw::type::MemoryLayout::eC
			, sdw::Vec3Field< "point" >
			, sdw::BooleanField< "valid" >
			, sdw::FloatField< "t" > >
	{
		Intersection( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstanceHelperT{ writer, std::move( expr ), enabled }
		{
		}

		explicit Intersection( sdw::ShaderWriter & writer )
			: Intersection{ writer, vec3( 0.0_f ), 0_b, -1.0_f }
		{
		}

		Intersection( sdw::ShaderWriter & writer
			, sdw::Vec3 const & p )
			: Intersection{ writer, p, 0_b, -1.0_f }
		{
		}

		Intersection( sdw::ShaderWriter & writer
			, sdw::Vec3 const & p
			, sdw::Boolean const & v )
			: Intersection{ writer, p, v, -1.0_f }
		{
		}

		Intersection( sdw::ShaderWriter & writer
			, sdw::Vec3 const & p
			, sdw::Boolean const & v
			, sdw::Float const & t )
			: Intersection{ writer
			, sdw::makeAggrInit( makeType( writer.getTypesCache() ), getIntersectionInit( p, v, t ) )
			, true }
		{
		}

		auto point()const
		{
			return getMember< "point" >();
		}

		auto valid()const
		{
			return getMember< "valid" >();
		}

		auto t()const
		{
			return getMember< "t" >();
		}

		static sdw::expr::ExprList getIntersectionInit( sdw::Vec3 const & p
			, sdw::Boolean const & v
			, sdw::Float const & t )
		{
			sdw::expr::ExprList result;
			result.emplace_back( makeExpr( p ) );
			result.emplace_back( makeExpr( v ) );
			result.emplace_back( makeExpr( t ) );
			return result;
		}
	};

	void noFlatteningExpected( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noFlatteningExpected" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto value = writer.declLocale( "value"
						, vec4( 0.0_f, 1.0_f, 2.0_f, 3.0_f ) );
					auto result = writer.declLocale( "result"
						, value.xyz() );
					ssbo[0].a().xyz() = result;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void flattenLiterals( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "flattenLiterals" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto value0 = writer.declLocale( "value0"
						, vec4( vec3( 0.0_f ), 3.0_f ) );
					auto value1 = writer.declLocale( "value1"
						, vec4( vec2( 1.0_f ), vec2( 2.0_f ) ) );
					auto value2 = writer.declLocale( "value2"
						, vec4( 1.0_f, vec3( 3.0_f ) ) );
					auto result0 = writer.declLocale( "result0"
						, value0.xw() );
					ssbo[0].a().xy() = result0;
					auto result1 = writer.declLocale( "result1"
						, value1.xw() );
					ssbo[1].a().xy() = result1;
					auto result2 = writer.declLocale( "result2"
						, value2.xw() );
					ssbo[2].a().xy() = result2;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void flattenVariables( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "flattenVariables" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssboIn", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > inputs )
				{
					auto in = ssbo[0];
					auto result0 = writer.declLocale( "result0"
						, vec4( in.a() ) );
					auto result1 = writer.declLocale( "result1"
						, vec4( in.a().x(), in.a().y(), in.a().z(), in.a().w() ) );
					auto result2 = writer.declLocale( "result2"
						, vec4( in.a().xyzw() ) );
					auto result3 = writer.declLocale( "result3"
						, vec4( in.a().xyz(), 1.0_f ) );
					auto result4 = writer.declLocale( "result4"
						, vec4( in.a().xy(), in.b().xy() ) );
					auto result5 = writer.declLocale( "result5"
						, vec4( in.a().x(), in.b().xyz() ) );
					auto result6 = writer.declLocale( "result6"
						, vec4( in.a().x(), in.b().y(), in.c().z(), in.d().w() ) );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void constIndexConstArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "constIndexConstArray" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto values = writer.declConstantArray( "values"
						, std::vector< sdw::Float >{ 0.0_f, 0.0_f, 0.0_f, 1.0_f } );
					auto result = writer.declLocale( "result"
						, values[0] );
					ssbo[0].a().x() = result;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void nonConstIndexConstArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "nonConstIndexConstArray" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto values = writer.declConstantArray( "values"
						, std::vector< sdw::Float >{ 0.0_f, 0.0_f, 0.0_f, 1.0_f } );
					auto result = writer.declLocale( "result"
						, values[ssbo[0].e().x()] );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void swizzleConstCompositeCtor( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "swizzleConstCompositeCtor" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto values = writer.declConstant( "values"
						, vec4( 0.0_f, 1.0_f, 2.0_f, 3.0_f ) );
					auto result0 = writer.declLocale( "result0"
						, values.x() );
					ssbo[0].a().x() = result0;
					auto result1 = writer.declLocale( "result1"
						, values.xw() );
					ssbo[1].a().xy() = result1;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void constCompositeCtorFuncParam( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "constCompositeCtorFuncParam" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			auto test1 = writer.implementFunction< sdw::Void >( "test1"
				, [&]( sdw::Float const p )
				{
				}
				, sdw::InFloat{ writer, "p" } );

			auto test2 = writer.implementFunction< sdw::Void >( "test2"
				, [&]( sdw::Vec2 const p )
				{
				}
				, sdw::InVec2{ writer, "p" } );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto values = writer.declConstant( "values"
						, vec4( 0.0_f, 1.0_f, 2.0_f, 3.0_f ) );
					auto result0 = writer.declLocale( "result0"
						, values.x() );
					test1( result0 );
					test2( values.xw() );
					auto result1 = writer.declLocale( "result1"
						, values.xw() );
					test2( result1 );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void constCompositeCtorVariable( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "constCompositeCtorVariable" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto values = writer.declConstant( "values"
						, vec4( 0.0_f, 1.0_f, 2.0_f, 3.0_f ) );
					auto result0 = writer.declLocale( "result0"
						, values.x() );
					result0 += ssbo[0].a().x();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void compositeCtorIfElse( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "compositeCtorIfElse" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto value0 = writer.declLocale( "value0", vec4( 0.0_f ) );
					auto value1 = writer.declLocale( "value1", vec4( 1.0_f ) );

					IF( writer, ssbo[0].a().x() > 0.0_f )
					{
						value1 = ssbo[0].a() * ssbo[0].b();
					}
					ELSE
					{
						value0 = ssbo[1].a() * ssbo[1].b();
					}
					FI;

					IF( writer, in.localInvocationIndex == 0_u )
					{
						ssbo[2].a() = value0 + value1;
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void compositeCtorVec2FromInt( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "compositeCtorVec2FromInt" );
		using namespace sdw;
		VertexWriter writer{ &testCounts.allocator };
		auto outUV = writer.declOutput< sdw::Vec2 >( "outUV", 0u );

		writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
			, VertexOut out )
			{
				outUV = vec2( ( in.vertexIndex << 1 ) & 2, in.vertexIndex & 2 );
				out.vtx.position = vec4( outUV * 2.0f - 1.0f, 0.0f, 1.0f );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void outputParam( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "outputParam" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			auto test1 = writer.implementFunction< sdw::Void >( "test1"
				, [&]( sdw::Float p )
				{
					p = 1.0_f;
				}
				, sdw::OutFloat{ writer, "p" } );

			auto test2 = writer.implementFunction< sdw::Void >( "test2"
				, [&]( sdw::Float p )
				{
					p = 1.0_f;
				}
				, sdw::InOutFloat{ writer, "p" } );

			auto test3 = writer.implementFunction< sdw::Void >( "test3"
				, [&]( sdw::Float const p )
				{
				}
				, sdw::InFloat{ writer, "p" } );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto value0 = writer.declLocale( "value0", 0.0_f );
					test1( value0 );
					ssbo[0].a().x() = value0;
					auto value1 = writer.declLocale( "value1", 0.0_f );
					test2( value1 );
					ssbo[1].a().x() = value1;
					auto value2 = writer.declLocale( "value2", 0.0_f );
					test3( value2 );
					ssbo[2].a().x() = value2;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void aggrInitMbrSelectLHS( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "aggrInitMbrSelectLHS" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			auto raySphereIntersectNearest = writer.implementFunction< Intersection >( "atm_raySphereIntersectNearest"
				, [&]( sdw::Float const & sphereRadius )
				{
					auto result = writer.declLocale( "result"
						, Intersection{ writer } );

					IF( writer, sphereRadius < 0.0_f )
					{
						result.t() = max( 0.0_f, 1.0_f );
					}
					FI;

					writer.returnStmt( result );
				}
				, sdw::InFloat{ writer, "sphereRadius" } );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto result = writer.declLocale( "result"
						, raySphereIntersectNearest( ssbo[0].b().x() ) );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void ternarySingleComponent( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "ternarySingleComponent" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto check = writer.declLocale( "check"
						, 0.0_f );
					auto tValue = writer.declLocale( "tValue"
						, 1.0_f );
					auto fValue = writer.declLocale( "fValue"
						, 2.0_f );
					auto result = writer.declLocale( "result"
						, writer.ternary( check > 0.0_f, tValue, fValue ) );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void ternaryMultipleComponent( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "ternaryMultipleComponent" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto check = writer.declLocale( "check"
						, 0.0_f );
					auto tValue = writer.declLocale( "tValue"
						, vec4( 1.0_f, 2.0_f, 3.0_f, 4.0_f ) );
					auto fValue = writer.declLocale( "fValue"
						, vec4( 5.0_f, 6.0_f, 7.0_f, 8.0_f ) );
					auto result = writer.declLocale( "result"
						, writer.ternary( check > 0.0_f, tValue, fValue ) );
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

	void less( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "less" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, lhs < rhs );
					ssbo[0].e() = uvec4( result );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void lessEqual( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lessEqual" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, lhs <= rhs );
					ssbo[0].e() = uvec4( result );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void greater( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "greater" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, lhs > rhs );
					ssbo[0].e() = uvec4( result );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void greaterEqual( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "greaterEqual" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, lhs >= rhs );
					ssbo[0].e() = uvec4( result );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void equal( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "equal" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, lhs == rhs );
					ssbo[0].e() = uvec4( result );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void notEqual( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "notEqual" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, lhs != rhs );
					ssbo[0].e() = uvec4( result );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void all( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "all" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, all( lhs == rhs ) );
					ssbo[0].e() = uvec4( bvec4( result ) );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void any( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "any" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, any( lhs == rhs ) );
					ssbo[0].e() = uvec4( bvec4( result ) );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void allVarCtrlExpr( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "allVarCtrlExpr" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, all( lhs == rhs ) );

					IF( writer, result )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					ELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void anyVarCtrlExpr( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "anyCtrlExpr" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );
					auto result = writer.declLocale( "result"
						, any( lhs == rhs ) );

					IF( writer, result )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					ELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void allCtrlExpr( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "allCtrlExpr" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );

					IF( writer, all( lhs == rhs ) )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					ELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void anyCtrlExpr( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "anyCtrlExpr" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto lhs = writer.declLocale( "lhs"
						, vec4( 1.0_f, 0.0_f, 1.0_f, 0.0_f ) );
					auto rhs = writer.declLocale( "rhs"
						, vec4( 1.0_f, 1.0_f, 1.0_f, 1.0_f ) );

					IF( writer, any( lhs == rhs ) )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					ELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void notAllCtrlExpr( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "notAllCtrlExpr" );
		using namespace sdw;

		ShaderArray shaders;
		{
			struct MyStruct
				: sdw::StructInstance
			{
				MyStruct( sdw::ShaderWriter & writer
					, sdw::expr::ExprPtr expr
					, bool enabled )
					: StructInstance{ writer, std::move( expr ), enabled }
					, a{ getMember( "a", vec3( 0.0_f ) ) }
					, b{ getMember( "b", vec3( 0.0_f ) ) }
				{
				}

				static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
				{
					auto result = cache.getStruct( ast::type::MemoryLayout::eC, "MyStruct" );

					if ( result->empty() )
					{
						result->declMember( "a", ast::type::Kind::eVec3F, ast::type::NotArray );
					}

					return result;
				}

				sdw::DefaultedT< sdw::Vec3 > a;
				sdw::DefaultedT< sdw::Vec3 > b;
			};

			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto v = writer.declLocale< MyStruct >( "v" );

					IF( writer, !all( v.b == vec3( 0.0_f ) ) )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void encodeColour( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "encodeColour" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			auto encodeColor = writer.implementFunction<  sdw::UInt >( "encodeColor"
				, [&]( sdw::Vec4 const & color )
				{
					auto hdrRange = writer.declConstant( "hdrRange", 10.0_f );

					// normalize color to LDR
					auto hdr = writer.declLocale( "hdr"
						, length( color.rgb() ) );
					color.rgb() /= hdr;

					// encode LDR color and HDR range
					auto iColor = writer.declLocale( "iColor"
						, uvec3( color.rgb() * 255.0_f ) );
					auto iHDR = writer.declLocale( "iHDR"
						, writer.cast<  sdw::UInt >( clamp( hdr / hdrRange, 0.0_f, 1.0_f ) * 127.0_f ) );
					auto colorMask = writer.declLocale( "colorMask"
						, ( iHDR << 24_u ) | ( iColor.r() << 16_u ) | ( iColor.g() << 8_u ) | iColor.b() );

					// encode alpha into highest bit
					auto iAlpha = writer.declLocale( "iAlpha"
						, writer.ternary( color.a() > 0.0_f, 1_u, 0_u ) );
					colorMask |= ( iAlpha << 31_u );

					writer.returnStmt( colorMask );
				}
				, sdw::InVec4{ writer, "color" } );

			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn in )
				{
					ssbo[in.globalInvocationID.x()].e().x() = encodeColor( ssbo[in.globalInvocationID.x()].a() );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void globalConstantArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "globalConstantArray" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn in )
				{
					auto values = writer.declConstantArray( "values"
						, std::vector< sdw::Vec3 >{ vec3( 0.57735_f, 0.57735, 0.57735 )
						, vec3( 0.57735_f, -0.57735, -0.57735 )
						, vec3( -0.57735_f, 0.57735, -0.57735 )
						, vec3( -0.57735_f, -0.57735, 0.57735 )
						, vec3( -0.903007_f, -0.182696, -0.388844 )
						, vec3( -0.903007_f, 0.182696, 0.388844 )
						, vec3( 0.903007_f, -0.182696, 0.388844 )
						, vec3( 0.903007_f, 0.182696, -0.388844 )
						, vec3( -0.388844_f, -0.903007, -0.182696 )
						, vec3( 0.388844_f, -0.903007, 0.182696 )
						, vec3( 0.388844_f, 0.903007, -0.182696 )
						, vec3( -0.388844_f, 0.903007, 0.182696 )
						, vec3( -0.182696_f, -0.388844, -0.903007 )
						, vec3( 0.182696_f, 0.388844, -0.903007 )
						, vec3( -0.182696_f, 0.388844, 0.903007 )
						, vec3( 0.182696_f, -0.388844, 0.903007 ) } );

					auto test = writer.implementFunction< sdw::Vec4 >( "test"
						, [&]()
						{
							auto result = writer.declLocale( "result"
								, vec4( 0.0_f ) );

							FOR( writer, sdw::UInt, i, 0_u, i < ssbo[0].e().x(), ++i )
							{
								auto value = writer.declLocale( "value"
									, normalize( values[i] + ssbo[0].b().xyz() ) );
								result.xyz() += value;
							}
							ROF;

							// final radiance is average of all the cones radiances
							ssbo[0].a() = result;
						} );

					auto result = writer.declLocale( "result"
						, vec4( 0.0_f ) );

					FOR( writer, sdw::UInt, i, 0_u, i < ssbo[0].e().x(), ++i )
					{
						auto value = writer.declLocale( "value"
							, normalize( values[i] + ssbo[0].b().xyz() ) );
						result.xyz() += value;
					}
					ROF;

					IF( writer, in.localInvocationIndex == 0_u )
					{
						// final radiance is average of all the cones radiances
						ssbo[0].a() = result;
					}
					FI;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterCompositeCtors )
{
	sdwTestSuiteBegin();
	noFlatteningExpected( testCounts );
	flattenLiterals( testCounts );
	flattenVariables( testCounts );
	constIndexConstArray( testCounts );
	nonConstIndexConstArray( testCounts );
	swizzleConstCompositeCtor( testCounts );
	constCompositeCtorFuncParam( testCounts );
	constCompositeCtorVariable( testCounts );
	compositeCtorIfElse( testCounts );
	compositeCtorVec2FromInt( testCounts );
	outputParam( testCounts );
	aggrInitMbrSelectLHS( testCounts );
	ternarySingleComponent( testCounts );
	ternaryMultipleComponent( testCounts );
	less( testCounts );
	lessEqual( testCounts );
	greater( testCounts );
	greaterEqual( testCounts );
	equal( testCounts );
	notEqual( testCounts );
	all( testCounts );
	any( testCounts );
	allVarCtrlExpr( testCounts );
	anyVarCtrlExpr( testCounts );
	allCtrlExpr( testCounts );
	anyCtrlExpr( testCounts );
	notAllCtrlExpr( testCounts );
	encodeColour( testCounts );
	globalConstantArray( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCompositeCtors )
