#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	template< sdw::var::Flag FlagT >
	struct PositionT
		: sdw::StructInstance
	{
		PositionT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
		{
		}

		SDW_DeclStructInstance( , PositionT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Position"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Position" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
	};
	using InputPosition = PositionT< sdw::var::Flag::eShaderInput >;

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };

			writer.implementMainT< 1u, PointList, PointStream >( [&]( GeometryIn in
				, PointList list
				, PointStream out )
				{
					writer.declLocale( "invocationID", in.invocationID );
					writer.declLocale( "primitiveID", in.primitiveID );

					out.layer = 0_i;
					out.viewportIndex = 0_i;
					out.primitiveID = in.primitiveID;

					out.vtx.position = list[0].vtx.position;
					out.append();
					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInputOnly" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleList = sdw::TriangleListT< PositionT >;

			writer.implementMainT< 3u, MyTriangleList, TriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, TriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.vtx.position = vec4( list[0].position, 0.0_f ) + list[0].vtx.position;
					out.append();

					out.vtx.position = vec4( list[1].position, 0.0_f ) + list[1].vtx.position;
					out.append();

					out.vtx.position = vec4( list[2].position, 0.0_f ) + list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalOnly" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleList = sdw::TriangleListT< VoidT >;
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, 3u );

			writer.implementMainT< 3u, MyTriangleList, TriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, TriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.vtx.position = vec4( offset[0], 0.0_f ) + list[0].vtx.position;
					out.append();

					out.vtx.position = vec4( offset[1], 0.0_f ) + list[1].vtx.position;
					out.append();

					out.vtx.position = vec4( offset[2], 0.0_f ) + list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedInputOnly" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleList = sdw::TriangleListT< PositionT >;
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, 3u );

			writer.implementMainT< 3u, MyTriangleList, TriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, TriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.vtx.position = vec4( list[0].position, 0.0_f ) + vec4( offset[0], 0.0_f ) + list[0].vtx.position;
					out.append();

					out.vtx.position = vec4( list[1].position, 0.0_f ) + vec4( offset[1], 0.0_f ) + list[1].vtx.position;
					out.append();

					out.vtx.position = vec4( list[2].position, 0.0_f ) + vec4( offset[2], 0.0_f ) + list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberOutputOnly" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleStream = sdw::TriangleStreamT< PositionT >;

			writer.implementMainT< 3u, TriangleList, MyTriangleStream >( [&]( GeometryIn in
				, TriangleList list
				, MyTriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.position = list[0].vtx.position.xyz();
					out.vtx.position = list[0].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = list[1].vtx.position.xyz();
					out.vtx.position = list[1].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = list[2].vtx.position.xyz();
					out.vtx.position = list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInAndOut" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleList = sdw::TriangleListT< PositionT >;
			using MyTriangleStream = sdw::TriangleStreamT< PositionT >;

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, MyTriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.position = list[0].position;
					out.vtx.position = list[0].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = list[1].position;
					out.vtx.position = list[1].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = list[2].position;
					out.vtx.position = list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInAndOut" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleList = sdw::TriangleListT< VoidT >;
			using MyTriangleStream = sdw::TriangleStreamT< PositionT >;
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, 3u );

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, MyTriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.position = offset[0];
					out.vtx.position = list[0].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = offset[1];
					out.vtx.position = list[1].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = offset[2];
					out.vtx.position = list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedInAndOut" );
		using namespace sdw;
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };
			using MyTriangleList = sdw::TriangleListT< PositionT >;
			using MyTriangleStream = sdw::TriangleStreamT< PositionT >;
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, 3u );

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, MyTriangleStream out )
				{
					out.primitiveID = in.primitiveID;
					out.position = list[0].position + offset[0];
					out.vtx.position = list[0].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = list[1].position + offset[1];
					out.vtx.position = list[1].vtx.position;
					out.append();

					out.primitiveID = in.primitiveID;
					out.position = list[2].position + offset[2];
					out.vtx.position = list[2].vtx.position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterGeometryShader )
{
	sdwTestSuiteBegin();
	noSpecificIO( testCounts );
	specificMemberInputOnly( testCounts );
	specificGlobalInputOnly( testCounts );
	specificMixedInputOnly( testCounts );
	specificMemberOutputOnly( testCounts );
	specificMemberInAndOut( testCounts );
	specificGlobalInAndOut( testCounts );
	specificMixedInAndOut( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterGeometryShader )
