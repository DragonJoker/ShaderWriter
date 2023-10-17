#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/IOStructHelper.hpp>
#include <ShaderWriter/CompositeTypes/IOStructInstanceHelper.hpp>

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

					ssbo[2].a() = value0 + value1;
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
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCompositeCtors )
