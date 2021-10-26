#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

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

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache )
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

	void specificMemberInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInputOnly" );
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

	void specificGlobalInputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInputOnly" );
		using namespace sdw;
		{
			VertexWriter writer;
			auto position = writer.declInput< Vec3 >( "position", 0u );

			writer.implementMainT< VoidT, VoidT >( [&]( VertexInT< VoidT > in
				, VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( position, 1.0_f );
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
			VertexWriter writer;
			auto offset = writer.declInput< Vec3 >( "offset", 1u );

			writer.implementMainT< PositionT, VoidT >( [&]( VertexInT< PositionT > in
				, VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( in.position + offset, 1.0_f );
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

	void specificGlobalOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalOutputOnly" );
		using namespace sdw;
		{
			VertexWriter writer;
			auto position = writer.declOutput< Vec3 >( "position", 0u );

			writer.implementMainT< VoidT, VoidT >( [&]( VertexInT< VoidT > in
				, VertexOutT< VoidT > out )
				{
					position = vec3( 1.0_f );
					out.vtx.position = vec4( position, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedOutputOnly( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedOutputOnly" );
		using namespace sdw;
		{
			VertexWriter writer;
			auto offset = writer.declOutput< Vec3 >( "offset", 1u );

			writer.implementMainT< VoidT, PositionT >( [&]( VertexInT< VoidT > in
				, VertexOutT< PositionT > out )
				{
					offset = vec3( 2.0_f );
					out.position = vec3( 1.0_f );
					out.vtx.position = vec4( out.position, 1.0_f );
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

	void specificGlobalInAndOut( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInAndOut" );
		using namespace sdw;
		{
			VertexWriter writer;
			auto inPosition = writer.declInput< Vec3 >( "inPosition", 0u );
			auto outPosition = writer.declOutput< Vec3 >( "outPosition", 0u );

			writer.implementMainT< VoidT, VoidT >( [&]( VertexInT< VoidT > in
				, VertexOutT< VoidT > out )
				{
					outPosition = inPosition;
					out.vtx.position = vec4( inPosition, 1.0_f );
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
			VertexWriter writer;
			auto inOffset = writer.declInput< Vec3 >( "inOffset", 1u );
			auto outOffset = writer.declOutput< Vec3 >( "outOffset", 1u );

			writer.implementMainT< PositionT, PositionT >( [&]( VertexInT< PositionT > in
				, VertexOutT< PositionT > out )
				{
					outOffset = inOffset;
					out.position = in.position;
					out.vtx.position = vec4( in.position, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void vertex( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vertex" );
		using namespace sdw;
		VertexWriter writer;

		writer.implementMainT< PositionT, PositionT >( [&]( sdw::VertexInT< PositionT > in
			, sdw::VertexOutT< PositionT > out )
			{
				out.position = in.position;
				out.vtx.position = vec4( in.position.x(), in.position.y(), 0.0, 1.0 );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace posOff
	{
		template< sdw::var::Flag FlagT >
		struct PositionT
			: sdw::StructInstance
		{
			PositionT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, position{ getMember< sdw::Vec4 >( "position" ) }
				, texoff{ getMember< sdw::Vec2 >( "texoff" ) }
			{
			}

			SDW_DeclStructInstance( , PositionT );

			static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
					, ( FlagT == ast::var::Flag::eShaderOutput
						? std::string{ "Output" }
						: std::string{ "Input" } ) + "Position"
					, FlagT );

				if ( result->empty() )
				{
					result->declMember( "position"
						, sdw::type::Kind::eVec4F
						, sdw::type::NotArray
						, 0u );
					result->declMember( "texoff"
						, sdw::type::Kind::eVec2F
						, sdw::type::NotArray
						, 1u );
				}

				return result;
			}

			sdw::Vec4 position;
			sdw::Vec2 texoff;
		};
		using InputPosition = PositionT< sdw::var::Flag::eShaderInput >;
		using OutputPosition = PositionT< sdw::var::Flag::eShaderOutput >;
	}

	void smaaEdgeDetectionVS( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "smaaEdgeDetectionVS" );
		using namespace sdw;
		using namespace posOff;
		{
			VertexWriter writer;

			float w = 300;
			float h = 200;
			std::array< float, 4u > renderTargetMetrics{ 1.0f / w, 1.0f / h, w, h };

			// Shader constants
			auto c3d_rtMetrics = writer.declConstant( "SMAA_RT_METRICS"
				, vec4( Float( renderTargetMetrics[0] ), renderTargetMetrics[1], renderTargetMetrics[2], renderTargetMetrics[3] ) );

			// Shader inputs
			auto position = writer.declInput< Vec2 >( "position", 0u );
			auto uv = writer.declInput< Vec2 >( "uv", 1u );

			// Shader outputs
			auto vtx_texture = writer.declOutput< Vec2 >( "vtx_texture", 0u );
			auto vtx_offset = writer.declOutputArray< Vec4 >( "vtx_offset", 1u, 3u );

			/**
			 * Edge Detection Vertex Shader
			 */
			auto SMAAEdgeDetectionVS = writer.implementFunction< sdw::Void >( "SMAAEdgeDetectionVS"
				, [&]( Vec2 const & texCoord
					, Array< Vec4 > offset )
				{
					offset[0] = fma( c3d_rtMetrics.xyxy(), vec4( Float{ -1.0f }, 0.0_f, 0.0_f, Float{ -1.0f } ), vec4( texCoord.xy(), texCoord.xy() ) );
					offset[1] = fma( c3d_rtMetrics.xyxy(), vec4( 1.0_f, 0.0_f, 0.0_f, 1.0_f ), vec4( texCoord.xy(), texCoord.xy() ) );
					offset[2] = fma( c3d_rtMetrics.xyxy(), vec4( Float{ -2.0f }, 0.0_f, 0.0_f, Float{ -2.0f } ), vec4( texCoord.xy(), texCoord.xy() ) );
				}
				, InVec2{ writer, "texCoord" }
				, OutVec4Array{ writer, "offset", 3u } );

			writer.implementMainT< VoidT, VoidT >( [&]( sdw::VertexInT< VoidT > in
				, sdw::VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( position, 0.0_f, 1.0_f );
					vtx_texture = uv;
					vtx_offset[0] = vec4( 0.0_f );
					vtx_offset[1] = vec4( 0.0_f );
					vtx_offset[2] = vec4( 0.0_f );
					SMAAEdgeDetectionVS( vtx_texture, vtx_offset );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	void constVectorShuffle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "constVectorShuffle" );
		using namespace sdw;
		{
			using namespace sdw;
			VertexWriter writer;

			// Shader constants
			auto constVec = writer.declConstant( "constVec"
				, vec4( 300.0_f ) );

			writer.implementMainT< VoidT, VoidT >( [&]( VertexInT< VoidT >
				, VertexOutT< VoidT > )
				{
					auto loc = writer.declLocale( "loc"
						, length( constVec.xyxy() ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterVertexShader )
{
	sdwTestSuiteBegin();
	noSpecificIO( testCounts );
	specificMemberInputOnly( testCounts );
	specificGlobalInputOnly( testCounts );
	specificMixedInputOnly( testCounts );
	specificMemberOutputOnly( testCounts );
	specificGlobalOutputOnly( testCounts );
	specificMixedOutputOnly( testCounts );
	specificMemberInAndOut( testCounts );
	specificGlobalInAndOut( testCounts );
	specificMixedInAndOut( testCounts );
	constVectorShuffle( testCounts );
	vertex( testCounts );
	smaaEdgeDetectionVS( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterVertexShader )
