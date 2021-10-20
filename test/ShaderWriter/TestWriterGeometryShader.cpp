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

		static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eStd430
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Position"
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

		sdw::Vec3 position;
	};
	using InputPosition = PositionT< sdw::var::Flag::eShaderInput >;

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			GeometryWriter writer;

			writer.implementMainT< 1u, PointList, PointStream >( [&]( PointList in
				, PointStream out )
				{
					out.vtx.position = in.vtx[0].position;
					out.append();
					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificOutputOnly" );
		using namespace sdw;
		{
			GeometryWriter writer;
			using MyTriangleStream = sdw::TriangleStreamT< PositionT >;

			writer.implementMainT< 3u, TriangleList, MyTriangleStream >( [&]( TriangleList in
				, MyTriangleStream out )
				{
					out.position = in.vtx[0].position.xyz();
					out.vtx.position = in.vtx[0].position;
					out.append();

					out.position = in.vtx[1].position.xyz();
					out.vtx.position = in.vtx[1].position;
					out.append();

					out.position = in.vtx[2].position.xyz();
					out.vtx.position = in.vtx[2].position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificInputOnly" );
		using namespace sdw;
		{
			GeometryWriter writer;
			using MyTriangleList = sdw::TriangleListT< PositionT >;

			writer.implementMainT< 3u, MyTriangleList, TriangleStream >( [&]( MyTriangleList in
				, TriangleStream out )
				{
					out.vtx.position = vec4( in[0].position, 0.0_f ) + in.vtx[0].position;
					out.append();

					out.vtx.position = vec4( in[1].position, 0.0_f ) + in.vtx[1].position;
					out.append();

					out.vtx.position = vec4( in[2].position, 0.0_f ) + in.vtx[2].position;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificInAndOut" );
		using namespace sdw;
		{
			GeometryWriter writer;
			using MyTriangleList = sdw::TriangleListT< PositionT >;
			using MyTriangleStream = sdw::TriangleStreamT< PositionT >;

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&]( MyTriangleList in
				, MyTriangleStream out )
				{
					out.position = in[0].position;
					out.vtx.position = in.vtx[0].position;
					out.append();

					out.position = in[1].position;
					out.vtx.position = in.vtx[1].position;
					out.append();

					out.position = in[2].position;
					out.vtx.position = in.vtx[2].position;
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
	specificInputOnly( testCounts );
	specificOutputOnly( testCounts );
	specificInAndOut( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterGeometryShader )
