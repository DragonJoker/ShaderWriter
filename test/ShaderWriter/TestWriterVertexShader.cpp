#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
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

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Position"
				, entryPoint
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

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "Position" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec3F
					, ast::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
	};

	template< sdw::var::Flag FlagT >
	struct PosTexT
		: sdw::StructInstance
	{
		PosTexT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec2 >( "position" ) }
			, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
		{
		}

		SDW_DeclStructInstance( , PosTexT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "PosTex"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray
					, 0u );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray
					, 1u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
				, "PosTex" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec2 position;
		sdw::Vec2 texcoord;
	};

	template< ast::var::Flag FlagT >
	struct SmaaVertexInT
		: sdw::StructInstance
	{
		SmaaVertexInT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec2 >( "position" ) }
			, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
		{
		}

		SDW_DeclStructInstance( , SmaaVertexInT );

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "SmaaVertex"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec2F
					, ast::type::NotArray
					, 0u );
				result->declMember( "texcoord"
					, ast::type::Kind::eVec2F
					, ast::type::NotArray
					, 1u );
			}

			return result;
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "SmaaVertex" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, ast::type::Kind::eVec2F
					, ast::type::NotArray );
				result->declMember( "texcoord"
					, ast::type::Kind::eVec2F
					, ast::type::NotArray );
			}

			return result;
		}

		sdw::Vec2 position;
		sdw::Vec2 texcoord;
	};

	template< ast::var::Flag FlagT >
	struct SmaaVertexOutT
		: sdw::StructInstance
	{
		SmaaVertexOutT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
			, offset{ getMemberArray< sdw::Vec4 >( "offset" ) }
		{
		}

		SDW_DeclStructInstance( , SmaaVertexOutT );

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "SmaaVertex"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "texcoord"
					, ast::type::Kind::eVec2F
					, ast::type::NotArray
					, 0u );
				result->declMember( "offset"
					, ast::type::Kind::eVec4F
					, 3u
					, 1u );
			}

			return result;
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "SmaaVertex" );

			if ( result->empty() )
			{
				result->declMember( "texcoord"
					, ast::type::Kind::eVec2F
					, ast::type::NotArray );
				result->declMember( "offset"
					, ast::type::Kind::eVec4F
					, 3u );
			}

			return result;
		}

		sdw::Vec2 texcoord;
		sdw::Array< sdw::Vec4 > offset;
	};

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, VoidT >( [&]( VertexInT< VoidT > in
				, VertexOutT< VoidT > out )
				{
					writer.declLocale( "drawID", in.drawID );
					writer.declLocale( "baseInstance", in.baseInstance );
					writer.declLocale( "baseVertex", in.baseVertex );
					writer.declLocale( "instanceIndex", in.instanceIndex );
					writer.declLocale( "vertexIndex", in.vertexIndex );
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
			sdw::VertexWriter writer{ &testCounts.allocator };

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::VertexWriter writer{ &testCounts.allocator };

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::VertexWriter writer{ &testCounts.allocator };

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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
			sdw::VertexWriter writer{ &testCounts.allocator };
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
		sdw::VertexWriter writer{ &testCounts.allocator };

		writer.implementMainT< PosTexT, PosTexT >( [&]( sdw::VertexInT< PosTexT > in
			, sdw::VertexOutT< PosTexT > out )
			{
				out.texcoord = in.texcoord;
				out.position = in.position;
				out.vtx.position = vec4( in.position.xy(), 0.0, 1.0 );
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

			static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
				, ast::EntryPoint entryPoint )
			{
				auto result = cache.getIOStruct( "Position"
					, entryPoint
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

			static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getStruct( sdw::type::MemoryLayout::eC
					, "Position" );

				if ( result->empty() )
				{
					result->declMember( "position"
						, sdw::type::Kind::eVec4F
						, sdw::type::NotArray );
					result->declMember( "texoff"
						, sdw::type::Kind::eVec2F
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::Vec4 position;
			sdw::Vec2 texoff;
		};
		using InputPosition = PositionT< sdw::var::Flag::eShaderInput >;
		using OutputPosition = PositionT< sdw::var::Flag::eShaderOutput >;
	}

	void constVectorShuffle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "constVectorShuffle" );
		using namespace sdw;
		{
			using namespace sdw;
			sdw::VertexWriter writer{ &testCounts.allocator };

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

	void smaaEdgeDetectionVS( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "smaaEdgeDetectionVS" );
		using namespace sdw;
		using namespace posOff;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			float w = 300;
			float h = 200;
			std::array< float, 4u > renderTargetMetrics{ 1.0f / w, 1.0f / h, w, h };

			auto outTexcoord = writer.declOutput< Vec2 >( "outTexcoord", 0u );
			auto outOffset = writer.declOutputArray< Vec4 >( "outOffset", 1u, 3u );

			// Shader constants
			auto c3d_rtMetrics = writer.declConstant( "SMAA_RT_METRICS"
				, vec4( Float( renderTargetMetrics[0] ), renderTargetMetrics[1], renderTargetMetrics[2], renderTargetMetrics[3] ) );

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

			writer.implementMainT< SmaaVertexInT, VoidT >( [&]( sdw::VertexInT< SmaaVertexInT > in
				, sdw::VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( in.position, 0.0_f, 1.0_f );
					outTexcoord = in.texcoord;
					outOffset[0] = vec4( 0.0_f );
					outOffset[1] = vec4( 0.0_f );
					outOffset[2] = vec4( 0.0_f );
					SMAAEdgeDetectionVS( outTexcoord, outOffset );
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
