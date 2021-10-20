#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

#undef CurrentCompilers
#define CurrentCompilers Compilers_All

namespace
{
	template< ast::var::Flag FlagT >
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

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
				, ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Position"
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray
					, 0u );
			}

			return result;
		}

		sdw::Vec3 position;
	};

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			VertexWriter writer;

			writer.implementMainT< VoidT, VoidT >( [&]( VertexInT< VoidT > in
				, VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( 1.0_f );
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
			VertexWriter writer;

			writer.implementMainT< VoidT, PositionT >( [&]( VertexInT< VoidT > in
				, VertexOutT< PositionT > out )
				{
					out.position = vec3( 1.0_f );
					out.vtx.position = vec4( out.position, 1.0_f );
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
			VertexWriter writer;

			writer.implementMainT< PositionT, VoidT >( [&]( VertexInT< PositionT > in
				, VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( in.position, 1.0_f );
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
			VertexWriter writer;

			writer.implementMainT< PositionT, PositionT >( [&]( VertexInT< PositionT > in
				, VertexOutT< PositionT > out )
				{
					out.position = in.position;
					out.vtx.position = vec4( in.position, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterVertexShader )
{
	sdwTestSuiteBegin();
	noSpecificIO( testCounts );
	specificInputOnly( testCounts );
	specificOutputOnly( testCounts );
	specificInAndOut( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterVertexShader )
