#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	static constexpr uint32_t MaxPoints = 1u;

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
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
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

	template< sdw::var::Flag FlagT >
	struct SurfaceT
		: sdw::StructInstance
	{
		SurfaceT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, tangent{ getMember< sdw::Vec3 >( "tangent" ) }
			, bitangent{ getMember< sdw::Vec3 >( "bitangent" ) }
			, texture{ getMember< sdw::Vec3 >( "texture" ) }
			, instance{ getMember< sdw::Int >( "instance" ) }
		{
		}

		SDW_DeclStructInstance( , SurfaceT );

		template< sdw::var::Flag FlagU >
		SurfaceT operator=( SurfaceT< FlagU > const & rhs )
		{
			position = rhs.position;
			normal = rhs.normal;
			tangent = rhs.tangent;
			bitangent = rhs.bitangent;
			texture = rhs.texture;
			instance = rhs.instance;

			return *this;
		}

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Surface"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				uint32_t index = 0u;
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray
					, index++ );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray
					, index++ );
				result->declMember( "tangent"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray
					, index++ );
				result->declMember( "bitangent"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray
					, index++ );
				result->declMember( "texture"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray
					, index++ );
				result->declMember( "instance"
					, sdw::type::Kind::eInt
					, ast::type::NotArray
					, index++ );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
				, "Surface" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray );
				result->declMember( "tangent"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray );
				result->declMember( "bitangent"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray );
				result->declMember( "texture"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray );
				result->declMember( "instance"
					, sdw::type::Kind::eInt
					, ast::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;
		sdw::Vec3 tangent;
		sdw::Vec3 bitangent;
		sdw::Vec3 texture;
		sdw::Int instance;
	};

	template< sdw::var::Flag FlagT >
	struct SimplePatchT
		: sdw::StructInstance
	{
		SimplePatchT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, control{ getMember< sdw::Vec3 >( "control" ) }
		{
		}

		SDW_DeclStructInstance( , SimplePatchT );

		template< sdw::var::Flag FlagU >
		SimplePatchT operator=( SimplePatchT< FlagU > const & rhs )
		{
			control = rhs.control;
		}

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "SimplePatch"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "control"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray
					, 0u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
				, "SimplePatch" );

			if ( result->empty() )
			{
				result->declMember( "control"
					, sdw::type::Kind::eVec3F
					, ast::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 control;
	};

	template< sdw::var::Flag FlagT >
	struct PNTriPatchT
		: sdw::StructInstance
	{
		PNTriPatchT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, wpB030{ getMember< sdw::Vec3 >( "wpB030" ) }
			, wpB021{ getMember< sdw::Vec3 >( "wpB021" ) }
			, wpB012{ getMember< sdw::Vec3 >( "wpB012" ) }
			, wpB003{ getMember< sdw::Vec3 >( "wpB003" ) }
			, wpB102{ getMember< sdw::Vec3 >( "wpB102" ) }
			, wpB201{ getMember< sdw::Vec3 >( "wpB201" ) }
			, wpB300{ getMember< sdw::Vec3 >( "wpB300" ) }
			, wpB210{ getMember< sdw::Vec3 >( "wpB210" ) }
			, wpB120{ getMember< sdw::Vec3 >( "wpB120" ) }
			, wpB111{ getMember< sdw::Vec3 >( "wpB111" ) }
		{
		}

		SDW_DeclStructInstance( , PNTriPatchT );

		template< sdw::var::Flag FlagU >
		PNTriPatchT operator=( PNTriPatchT< FlagU > const & rhs )
		{
			wpB030 = rhs.wpB030;
			wpB021 = rhs.wpB021;
			wpB012 = rhs.wpB012;
			wpB003 = rhs.wpB003;
			wpB102 = rhs.wpB102;
			wpB201 = rhs.wpB201;
			wpB300 = rhs.wpB300;
			wpB210 = rhs.wpB210;
			wpB120 = rhs.wpB120;
			wpB111 = rhs.wpB111;

			return *this;
		}

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "PNTriPatch"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				uint32_t index = 0u;
				result->declMember( "wpB030", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB021", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB012", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB003", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB102", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB201", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB300", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB210", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB120", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->declMember( "wpB111", sdw::type::Kind::eVec3F, sdw::type::NotArray, index++ );
				result->end();
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
				, "PNTriPatch" );

			if ( result->empty() )
			{
				result->declMember( "wpB030", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB021", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB012", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB003", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB102", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB201", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB300", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB210", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB120", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->declMember( "wpB111", sdw::type::Kind::eVec3F, sdw::type::NotArray );
				result->end();
			}

			return result;
		}

		sdw::Vec3 wpB030;
		sdw::Vec3 wpB021;
		sdw::Vec3 wpB012;
		sdw::Vec3 wpB003;
		sdw::Vec3 wpB102;
		sdw::Vec3 wpB201;
		sdw::Vec3 wpB300;
		sdw::Vec3 wpB210;
		sdw::Vec3 wpB120;
		sdw::Vec3 wpB111;
	};

	void noSpecificIO( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIO" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, MaxPoints, VoidT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					writer.declLocale( "patchVerticesIn", mainIn.patchVerticesIn );
					writer.declLocale( "primitiveID", mainIn.primitiveID );

					writer.declLocale( "tessCoord", patchIn.tessCoord );
					writer.declLocale( "tessLevelInner", patchIn.tessLevelInner[0] );
					writer.declLocale( "tessLevelOuter", patchIn.tessLevelOuter[0] );

					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, MaxPoints, VoidT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += listIn[0].position;
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, VoidT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += offset[0];
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementMainT< PositionT, MaxPoints, VoidT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += listIn[0].position;
					out.vtx.position.xyz() += offset[0];
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, MaxPoints, VoidT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.position = listIn[0u].vtx.position.xyz();
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, VoidT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					posoff[0] = listIn[0].vtx.position.xyz();
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, VoidT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.position = listIn[0u].vtx.position.xyz();
					posoff[0] = listIn[0].vtx.position.xyz();
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, MaxPoints, VoidT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += listIn[0].position;
					out.position = listIn[0u].vtx.position.xyz();
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, VoidT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += offset[0];
					posoff[0] = listIn[0].vtx.position.xyz();
					posoff[0] += offset[0];
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
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< PositionT, MaxPoints, VoidT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< VoidT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += listIn[0].position;
					out.vtx.position.xyz() += offset[0];
					out.position = listIn[0u].vtx.position.xyz();
					out.position += offset[0];
					posoff[0] = listIn[0].vtx.position.xyz();
					posoff[0] += offset[0];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void noSpecificIOPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "noSpecificIOPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, MaxPoints, SimplePatchT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					out.vtx.position = listIn[0u].vtx.position;
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = loc
						* listIn[0u].vtx.position
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberInputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInputOnlyPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, MaxPoints, SimplePatchT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.vtx.position.xyz() += listIn[0].position;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalInputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInputOnlyPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, SimplePatchT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.vtx.position.xyz() += offset[0];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedInputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedInputOnlyPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementMainT< PositionT, MaxPoints, SimplePatchT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.vtx.position.xyz() += listIn[0].position;
					out.vtx.position.xyz() += offset[0];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberOutputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberOutputOnlyPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoidT, MaxPoints, SimplePatchT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.position = listIn[0u].vtx.position.xyz();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalOutputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalOutputOnlyPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, SimplePatchT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					posoff[0] = listIn[0].vtx.position.xyz();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedOutputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedOutputOnlyPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, SimplePatchT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.position = listIn[0u].vtx.position.xyz();
					posoff[0] = listIn[0].vtx.position.xyz();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMemberInAndOutPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMemberInAndOutPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, MaxPoints, SimplePatchT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.vtx.position.xyz() += listIn[0].position;
					out.position = listIn[0u].vtx.position.xyz();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificGlobalInAndOutPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificGlobalInAndOutPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< VoidT, MaxPoints, SimplePatchT, VoidT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< VoidT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.vtx.position.xyz() += offset[0];
					posoff[0] = listIn[0].vtx.position.xyz();
					posoff[0] += offset[0];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificMixedInAndOutPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificMixedInAndOutPatch" );
		using namespace sdw;
		{
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementMainT< PositionT, MaxPoints, SimplePatchT, PositionT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchInT< SimplePatchT > patchIn
					, TessEvalDataOutT< PositionT > out )
				{
					auto ctrl = writer.declLocale( "ctrl"
						, patchIn.control );
					auto loc = writer.declLocale( "loc"
						, patchIn.tessLevelOuter[0] );
					out.vtx.position = listIn[0u].vtx.position;
					out.vtx.position += loc
						* vec4( patchIn.tessCoord, 1.0_f );
					out.vtx.position.xyz() += ctrl;
					out.vtx.position.xyz() += listIn[0].position;
					out.vtx.position.xyz() += offset[0];
					out.position = listIn[0u].vtx.position.xyz();
					out.position += offset[0];
					posoff[0] = listIn[0].vtx.position.xyz();
					posoff[0] += offset[0];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void tessellationEvaluation( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "tessellationEvaluation" );
		using namespace sdw;
		{
			static uint32_t constexpr maxPoints = 3u;
			sdw::TessellationEvaluationWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer ubo{ writer, "Wow", 0u, 0u };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			auto interpolate1D = writer.implementFunction< Float >( "interpolate1D"
				, [&]( Vec3 const & tessCoord
					, Int const & v0
					, Int const & v1
					, Int const & v2 )
				{
					writer.returnStmt( tessCoord.x() * writer.cast< Float >( v0 )
						+ tessCoord.y() * writer.cast< Float >( v1 )
						+ tessCoord.z() * writer.cast< Float >( v2 ) );
				}
				, InVec3{ writer, "tessCoord" }
				, InInt{ writer, "v0" }
				, InInt{ writer, "v1" }
				, InInt{ writer, "v2" } );

			auto interpolate2D = writer.implementFunction< Vec2 >( "interpolate2D"
				, [&]( Vec3 const & tessCoord
					, Vec2 const & v0
					, Vec2 const & v1
					, Vec2 const & v2 )
				{
					writer.returnStmt( vec2( tessCoord.x() ) * v0
						+ vec2( tessCoord.y() ) * v1
						+ vec2( tessCoord.z() ) * v2 );
				}
				, InVec3{ writer, "tessCoord" }
				, InVec2{ writer, "v0" }
				, InVec2{ writer, "v1" }
				, InVec2{ writer, "v2" } );

			auto interpolate3D = writer.implementFunction< Vec3 >( "interpolate3D"
				, [&]( Vec3 const & tessCoord
					, Vec3 const & v0
					, Vec3 const & v1
					, Vec3 const & v2 )
				{
					writer.returnStmt( vec3( tessCoord.x() ) * v0
						+ vec3( tessCoord.y() ) * v1
						+ vec3( tessCoord.z() ) * v2 );
				}
				, InVec3{ writer, "tessCoord" }
				, InVec3{ writer, "v0" }
				, InVec3{ writer, "v1" }
				, InVec3{ writer, "v2" } );

			writer.implementMainT< SurfaceT, maxPoints, PNTriPatchT, SurfaceT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< SurfaceT, maxPoints > listIn
					, TrianglesTessPatchInT< PNTriPatchT > patchIn
					, TessEvalDataOutT< SurfaceT > out )
				{
					// Interpolate the attributes of the output vertex using the barycentric coordinates
					out.normal = interpolate3D( patchIn.tessCoord
						, listIn[0].normal
						, listIn[1].normal
						, listIn[2].normal );
					out.tangent = interpolate3D( patchIn.tessCoord
						, listIn[0].tangent
						, listIn[1].tangent
						, listIn[2].tangent );
					out.bitangent = interpolate3D( patchIn.tessCoord
						, listIn[0].bitangent
						, listIn[1].bitangent
						, listIn[2].bitangent );
					out.texture = interpolate3D( patchIn.tessCoord
						, listIn[0].texture
						, listIn[1].texture
						, listIn[2].texture );
					out.instance = writer.cast< Int >( interpolate1D( patchIn.tessCoord
						, listIn[0].instance
						, listIn[1].instance
						, listIn[2].instance ) );
					out.normal = normalize( out.normal );
					out.tangent = normalize( out.tangent );
					out.bitangent = normalize( out.bitangent );

					auto u = writer.declLocale( "u"
						, patchIn.tessCoord.x() );
					auto v = writer.declLocale( "v"
						, patchIn.tessCoord.y() );
					auto w = writer.declLocale( "w"
						, patchIn.tessCoord.z() );

					auto uPow3 = writer.declLocale( "uPow3"
						, pow( u, 3.0_f ) );
					auto vPow3 = writer.declLocale( "vPow3"
						, pow( v, 3.0_f ) );
					auto wPow3 = writer.declLocale( "wPow3"
						, pow( w, 3.0_f ) );
					auto uPow2 = writer.declLocale( "uPow2"
						, pow( u, 2.0_f ) );
					auto vPow2 = writer.declLocale( "vPow2"
						, pow( v, 2.0_f ) );
					auto wPow2 = writer.declLocale( "wPow2"
						, pow( w, 2.0_f ) );

					out.position = patchIn.wpB300 * wPow3
						+ patchIn.wpB030 * uPow3
						+ patchIn.wpB003 * vPow3
						+ patchIn.wpB210 * 3.0f * wPow2 * u
						+ patchIn.wpB120 * 3.0f * w * uPow2
						+ patchIn.wpB201 * 3.0f * wPow2 * v
						+ patchIn.wpB021 * 3.0f * uPow2 * v
						+ patchIn.wpB102 * 3.0f * w * vPow2
						+ patchIn.wpB012 * 3.0f * u * vPow2
						+ patchIn.wpB111 * 6.0f * w * u * v;

					out.vtx.position = mtx * vec4( out.position, 1.0f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterTessellationEvaluationShader )
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

	noSpecificIOPatch( testCounts );
	specificMemberInputOnlyPatch( testCounts );
	specificGlobalInputOnlyPatch( testCounts );
	specificMixedInputOnlyPatch( testCounts );
	specificMemberOutputOnlyPatch( testCounts );
	specificGlobalOutputOnlyPatch( testCounts );
	specificMixedOutputOnlyPatch( testCounts );
	specificMemberInAndOutPatch( testCounts );
	specificGlobalInAndOutPatch( testCounts );
	specificMixedInAndOutPatch( testCounts );

	tessellationEvaluation( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterTessellationEvaluationShader )
