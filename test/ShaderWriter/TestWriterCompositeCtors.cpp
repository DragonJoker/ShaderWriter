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
			, sdw::Vec4Field< "d" > >
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
	};

	void noFlatteningExpected( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noFlatteningExpected" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::ComputeWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto result = writer.declLocale( "result"
						, vec4( 0.0_f, 0.0_f, 0.0_f, 1.0_f ) );
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

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > in )
				{
					auto result0 = writer.declLocale( "result0"
						, vec4( vec3( 0.0_f ), 1.0_f ) );
					auto result1 = writer.declLocale( "result1"
						, vec4( vec2( 0.0_f ), vec2( 1.0_f ) ) );
					auto result2 = writer.declLocale( "result2"
						, vec4( 0.0_f, vec3( 1.0_f ) ) );
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
			auto ssbo = writer.declArrayStorageBuffer< ValuesT >( "ssbo", 0u, 0u );

			writer.implementMainT< VoidT >( 32u
				, [&]( ComputeInT< VoidT > inputs )
				{
					auto in = ssbo[0];
					writer.declLocale( "result0"
						, vec4( in.a() ) );
					writer.declLocale( "result1"
						, vec4( in.a().x(), in.a().y(), in.a().z(), in.a().w() ) );
					writer.declLocale( "result2"
						, vec4( in.a().xyzw() ) );
					writer.declLocale( "result3"
						, vec4( in.a().xyz(), 1.0_f ) );
					writer.declLocale( "result4"
						, vec4( in.a().xy(), in.b().xy() ) );
					writer.declLocale( "result5"
						, vec4( in.a().x(), in.b().xyz() ) );
					writer.declLocale( "result6"
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
}

sdwTestSuiteMain( TestWriterCompositeCtors )
{
	sdwTestSuiteBegin();
	noFlatteningExpected( testCounts );
	flattenLiterals( testCounts );
	flattenVariables( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterCompositeCtors )
