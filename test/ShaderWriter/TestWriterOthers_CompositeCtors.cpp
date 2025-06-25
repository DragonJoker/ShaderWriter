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

	TEST_F( SDWTest, noFlatteningExpected )
	{
		sdwTestBegin( "noFlatteningExpected" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, flattenLiterals )
	{
		sdwTestBegin( "flattenLiterals" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, flattenVariables )
	{
		sdwTestBegin( "flattenVariables" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, constIndexConstArray )
	{
		sdwTestBegin( "constIndexConstArray" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, nonConstIndexConstArray )
	{
		sdwTestBegin( "nonConstIndexConstArray" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, swizzleConstCompositeCtor )
	{
		sdwTestBegin( "swizzleConstCompositeCtor" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, constCompositeCtorFuncParam )
	{
		sdwTestBegin( "constCompositeCtorFuncParam" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, constCompositeCtorVariable )
	{
		sdwTestBegin( "constCompositeCtorVariable" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, compositeCtorIfElse )
	{
		sdwTestBegin( "compositeCtorIfElse" );
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

					sdwIF( writer, ssbo[0].a().x() > 0.0_f )
					{
						value1 = ssbo[0].a() * ssbo[0].b();
					}
					sdwELSE
					{
						value0 = ssbo[1].a() * ssbo[1].b();
					}
					sdwFI

					sdwIF( writer, in.localInvocationIndex == 0_u )
					{
						ssbo[2].a() = value0 + value1;
					}
					sdwFI
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, compositeCtorVec2FromInt )
	{
		sdwTestBegin( "compositeCtorVec2FromInt" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, outputParam )
	{
		sdwTestBegin( "outputParam" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, aggrInitMbrSelectLHS )
	{
		sdwTestBegin( "aggrInitMbrSelectLHS" );
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

					sdwIF( writer, sphereRadius < 0.0_f )
					{
						result.t() = max( 0.0_f, 1.0_f );
					}
					sdwFI

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
		sdwTestEnd()
	}

	TEST_F( SDWTest, ternarySingleComponent )
	{
		sdwTestBegin( "ternarySingleComponent" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto astCheck = writer.declLocale( "astCheck"
						, 0.0_f );
					auto tValue = writer.declLocale( "tValue"
						, 1.0_f );
					auto fValue = writer.declLocale( "fValue"
						, 2.0_f );
					auto result = writer.declLocale( "result"
						, writer.ternary( astCheck > 0.0_f, tValue, fValue ) );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, ternaryMultipleComponent )
	{
		sdwTestBegin( "ternaryMultipleComponent" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto astCheck = writer.declLocale( "astCheck"
						, 0.0_f );
					auto tValue = writer.declLocale( "tValue"
						, vec4( 1.0_f, 2.0_f, 3.0_f, 4.0_f ) );
					auto fValue = writer.declLocale( "fValue"
						, vec4( 5.0_f, 6.0_f, 7.0_f, 8.0_f ) );
					auto result = writer.declLocale( "result"
						, writer.ternary( astCheck > 0.0_f, tValue, fValue ) );
					ssbo[0].a() = result;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, less )
	{
		sdwTestBegin( "less" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, lessEqual )
	{
		sdwTestBegin( "lessEqual" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, greater )
	{
		sdwTestBegin( "greater" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, greaterEqual )
	{
		sdwTestBegin( "greaterEqual" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, equal )
	{
		sdwTestBegin( "equal" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, notEqual )
	{
		sdwTestBegin( "notEqual" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, all )
	{
		sdwTestBegin( "all" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, any )
	{
		sdwTestBegin( "any" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, allVarCtrlExpr )
	{
		sdwTestBegin( "allVarCtrlExpr" );
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

					sdwIF( writer, result )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					sdwELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					sdwFI
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, anyVarCtrlExpr )
	{
		sdwTestBegin( "anyCtrlExpr" );
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

					sdwIF( writer, result )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					sdwELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					sdwFI
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, allCtrlExpr )
	{
		sdwTestBegin( "allCtrlExpr" );
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

					sdwIF( writer, all( lhs == rhs ) )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					sdwELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					sdwFI
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, anyCtrlExpr )
	{
		sdwTestBegin( "anyCtrlExpr" );
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

					sdwIF( writer, any( lhs == rhs ) )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					sdwELSE
					{
						ssbo[1].e() = uvec4( 0u );
					}
					sdwFI
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, notAllCtrlExpr )
	{
		sdwTestBegin( "notAllCtrlExpr" );
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

					sdwIF( writer, !all( v.b == vec3( 0.0_f ) ) )
					{
						ssbo[0].e() = uvec4( 1u );
					}
					sdwFI
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, encodeColour )
	{
		sdwTestBegin( "encodeColour" );
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, globalConstantArray )
	{
		sdwTestBegin( "globalConstantArray" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			if ( auto timerBlock = testCounts.beginTimer( "Writing" ) )
			{
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

											sdwFOR( writer, sdw::UInt, i, 0_u, i < ssbo[0].e().x(), ++i )
											{
												auto value = writer.declLocale( "value"
													, normalize( values[i] + ssbo[0].b().xyz() ) );
												result.xyz() += value;
											}
											sdwROF

											// final radiance is average of all the cones radiances
												ssbo[0].a() = result;
								} );

							auto result = writer.declLocale( "result"
								, vec4( 0.0_f ) );

							sdwFOR( writer, sdw::UInt, i, 0_u, i < ssbo[0].e().x(), ++i )
							{
								auto value = writer.declLocale( "value"
									, normalize( values[i] + ssbo[0].b().xyz() ) );
								result.xyz() += value;
							}
							sdwROF

								sdwIF( writer, in.localInvocationIndex == 0_u )
							{
								// final radiance is average of all the cones radiances
								ssbo[0].a() = result;
							}
							sdwFI
					} );
			}
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, fromCppTypes )
	{
		sdwTestBegin( "fromCppTypes" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeIn in )
				{
					auto b_2 = writer.declLocale( "b_2", bvec2( false, false ) );
					auto b_3 = writer.declLocale( "b_3", bvec3( false, false, false ) );
					auto b_4 = writer.declLocale( "b_4", bvec4( false, false, false, false ) );
					auto f_2 = writer.declLocale( "f_2", vec2( float( 0 ), float( 1 ) ) );
					auto f_3 = writer.declLocale( "f_3", vec3( float( 0 ), float( 1 ), float( 2 ) ) );
					auto f_4 = writer.declLocale( "f_4", vec4( float( 0 ), float( 1 ), float( 2 ), float( 3 ) ) );
					auto d_2 = writer.declLocale( "d_2", dvec2( double( 0 ), double( 1 ) ) );
					auto d_3 = writer.declLocale( "d_3", dvec3( double( 0 ), double( 1 ), double( 2 ) ) );
					auto d_4 = writer.declLocale( "d_4", dvec4( double( 0 ), double( 1 ), double( 2 ), double( 3 ) ) );
					auto i8_2 = writer.declLocale( "i8_2", i8vec2( int8_t( 0 ), int8_t( 1 ) ) );
					auto i8_3 = writer.declLocale( "i8_3", i8vec3( int8_t( 0 ), int8_t( 1 ), int8_t( 2 ) ) );
					auto i8_4 = writer.declLocale( "i8_4", i8vec4( int8_t( 0 ), int8_t( 1 ), int8_t( 2 ), int8_t( 3 ) ) );
					auto i16_2 = writer.declLocale( "i16_2", i16vec2( int16_t( 0 ), int16_t( 1 ) ) );
					auto i16_3 = writer.declLocale( "i16_3", i16vec3( int16_t( 0 ), int16_t( 1 ), int16_t( 2 ) ) );
					auto i16_4 = writer.declLocale( "i16_4", i16vec4( int16_t( 0 ), int16_t( 1 ), int16_t( 2 ), int16_t( 3 ) ) );
					auto i32_2 = writer.declLocale( "i32_2", i32vec2( int32_t( 0 ), int32_t( 1 ) ) );
					auto i32_3 = writer.declLocale( "i32_3", i32vec3( int32_t( 0 ), int32_t( 1 ), int32_t( 2 ) ) );
					auto i32_4 = writer.declLocale( "i32_4", i32vec4( int32_t( 0 ), int32_t( 1 ), int32_t( 2 ), int32_t( 3 ) ) );
					auto i64_2 = writer.declLocale( "i64_2", i64vec2( int64_t( 0 ), int64_t( 1 ) ) );
					auto i64_3 = writer.declLocale( "i64_3", i64vec3( int64_t( 0 ), int64_t( 1 ), int64_t( 2 ) ) );
					auto i64_4 = writer.declLocale( "i64_4", i64vec4( int64_t( 0 ), int64_t( 1 ), int64_t( 2 ), int64_t( 3 ) ) );
					auto u8_2 = writer.declLocale( "u8_2", i8vec2( uint8_t( 0 ), uint8_t( 1 ) ) );
					auto u8_3 = writer.declLocale( "u8_3", i8vec3( uint8_t( 0 ), uint8_t( 1 ), uint8_t( 2 ) ) );
					auto u8_4 = writer.declLocale( "u8_4", i8vec4( uint8_t( 0 ), uint8_t( 1 ), uint8_t( 2 ), uint8_t( 3 ) ) );
					auto u16_2 = writer.declLocale( "u16_2", i16vec2( uint16_t( 0 ), uint16_t( 1 ) ) );
					auto u16_3 = writer.declLocale( "u16_3", i16vec3( uint16_t( 0 ), uint16_t( 1 ), uint16_t( 2 ) ) );
					auto u16_4 = writer.declLocale( "u16_4", i16vec4( uint16_t( 0 ), uint16_t( 1 ), uint16_t( 2 ), uint16_t( 3 ) ) );
					auto u32_2 = writer.declLocale( "u32_2", u32vec2( uint32_t( 0 ), uint32_t( 1 ) ) );
					auto u32_3 = writer.declLocale( "u32_3", u32vec3( uint32_t( 0 ), uint32_t( 1 ), uint32_t( 2 ) ) );
					auto u32_4 = writer.declLocale( "u32_4", u32vec4( uint32_t( 0 ), uint32_t( 1 ), uint32_t( 2 ), uint32_t( 3 ) ) );
					auto u64_2 = writer.declLocale( "u64_2", u64vec2( uint64_t( 0 ), uint64_t( 1 ) ) );
					auto u64_3 = writer.declLocale( "u64_3", u64vec3( uint64_t( 0 ), uint64_t( 1 ), uint64_t( 2 ) ) );
					auto u64_4 = writer.declLocale( "u64_4", u64vec4( uint64_t( 0 ), uint64_t( 1 ), uint64_t( 2 ), uint64_t( 3 ) ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
