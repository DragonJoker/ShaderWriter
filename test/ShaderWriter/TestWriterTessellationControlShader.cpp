#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[in.primitiveID].vtx.position.w();
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					writer.declLocale( "invocationID", in.invocationID );
					writer.declLocale( "primitiveID", in.primitiveID );

					listOut.vtx.position = listIn[in.invocationID].vtx.position * 2.0_f;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< PositionT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = vec4( listIn[in.invocationID].position, 1.0_f );
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = vec4( offset[in.invocationID], 1.0_f );
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementPatchRoutineT< PositionT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = vec4( listIn[in.invocationID].position + offset[in.invocationID], 1.0_f );
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].vtx.position.xyz();
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					posoff[in.invocationID] = listIn[in.invocationID].vtx.position.xyz();
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].vtx.position.xyz();
					posoff[in.invocationID] = listIn[in.invocationID].vtx.position.xyz();
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< PositionT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].position;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					posoff[in.invocationID] = offset[in.invocationID];
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< PositionT, MaxPoints, VoidT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< VoidT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].position;
					posoff[in.invocationID] = offset[in.invocationID];
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< VoidT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< PositionT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< PositionT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );

			writer.implementPatchRoutineT< PositionT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< PositionT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< VoidT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< VoidT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].vtx.position.xyz();
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					posoff[in.invocationID] = listIn[in.invocationID].vtx.position.xyz();
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< VoidT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].vtx.position.xyz();
					posoff[in.invocationID] = listIn[in.invocationID].vtx.position.xyz();
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			writer.implementPatchRoutineT< PositionT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = 4.0_f;
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< PositionT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].position;
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< VoidT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = 2.0_f;
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< VoidT, MaxPoints, VoidT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< VoidT, MaxPoints > listIn
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					posoff[in.invocationID] = offset[in.invocationID];
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
			sdw::TessellationControlWriter writer{ &testCounts.allocator };
			auto offset = writer.declInputArray< Vec3 >( "offset", 1u, MaxPoints );
			auto posoff = writer.declOutputArray< Vec3 >( "posoff", 1u, MaxPoints );

			writer.implementPatchRoutineT< PositionT, MaxPoints, SimplePatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patchOut )
				{
					patchOut.tessLevelOuter[0] = listIn[0].vtx.position.w();
					patchOut.tessLevelOuter[1] = listIn[0].position.x();
					patchOut.tessLevelOuter[2] = offset[0].y();
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[1];

					patchOut.control = vec3( 1.0_f );
				} );

			writer.implementMainT< PositionT, MaxPoints, PositionT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 1u
				, [&]( TessControlMainIn in
					, TessControlListInT< PositionT, MaxPoints > listIn
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut.vtx.position = listIn[in.invocationID].vtx.position;
					listOut.position = listIn[in.invocationID].position;
					posoff[in.invocationID] = offset[in.invocationID];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void tessellationControl( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "tessellationControl" );
		using namespace sdw;
		{
			static uint32_t constexpr maxPoints = 3u;
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			// TCS inputs
			sdw::UniformBuffer ubo{ writer, "Wow", 0u, 0u };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			auto c3d_mapNormal = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapNormal", 0u, 0u );
			auto c3d_mapHeight = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapHeight", 1u, 0u );

			auto getTessLevel = writer.implementFunction< Float >( "getTessLevel"
				, [&]( Float const & a
					, Float const & b )
				{
					auto avgDistance = writer.declLocale( "avgDistance"
						, ( a + b ) / 2.0_f );

					IF( writer, avgDistance <= 20.0_f )
					{
						writer.returnStmt( 256.0_f );
					}
					ELSEIF( avgDistance <= 50.0_f )
					{
						writer.returnStmt( 128.0_f );
					}
					ELSEIF( avgDistance <= 100.0_f )
					{
						writer.returnStmt( 64.0_f );
					}
					FI;

					writer.returnStmt( 16.0_f );
				}
				, InFloat{ writer, "a" }
				, InFloat{ writer, "b" } );

			auto projectToPlane = writer.implementFunction< Vec3 >( "projectToPlane"
				, [&]( Vec3 const & point
					, Vec3 const & planePoint
					, Vec3 const & planeNormal )
				{
					auto v = writer.declLocale( "v"
						, point - planePoint );
					writer.returnStmt( point - dot( v, planeNormal ) * planeNormal );
				}
				, InVec3{ writer, "point" }
				, InVec3{ writer, "planePoint" }
				, InVec3{ writer, "planeNormal " } );

			writer.implementPatchRoutineT< SurfaceT, maxPoints, PNTriPatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< SurfaceT, maxPoints > listIn
					, TrianglesTessPatchOutT< PNTriPatchT > patchOut )
				{
					// The original vertices stay the same
					patchOut.wpB030 = listIn[0].position;
					patchOut.wpB003 = listIn[1].position;
					patchOut.wpB300 = listIn[2].position;

					// Edges are names according to the opposing vertex
					auto edgeB300 = writer.declLocale( "edgeB300"
						, patchOut.wpB003 - patchOut.wpB030 );
					auto edgeB030 = writer.declLocale( "edgeB030"
						, patchOut.wpB300 - patchOut.wpB003 );
					auto edgeB003 = writer.declLocale( "edgeB003"
						, patchOut.wpB030 - patchOut.wpB300 );

					// Generate two midpoints on each edge
					patchOut.wpB021 = patchOut.wpB030 + edgeB300 / 3.0f;
					patchOut.wpB012 = patchOut.wpB030 + edgeB300 * 2.0f / 3.0f;
					patchOut.wpB102 = patchOut.wpB003 + edgeB030 / 3.0f;
					patchOut.wpB201 = patchOut.wpB003 + edgeB030 * 2.0f / 3.0f;
					patchOut.wpB210 = patchOut.wpB300 + edgeB003 / 3.0f;
					patchOut.wpB120 = patchOut.wpB300 + edgeB003 * 2.0f / 3.0f;

					// Project each midpoint on the plane defined by the nearest vertex and its normal
					patchOut.wpB021 = projectToPlane( patchOut.wpB021
						, patchOut.wpB030
						, listIn[0].normal );
					patchOut.wpB012 = projectToPlane( patchOut.wpB012
						, patchOut.wpB003
						, listIn[1].normal );
					patchOut.wpB102 = projectToPlane( patchOut.wpB102
						, patchOut.wpB003
						, listIn[1].normal );
					patchOut.wpB201 = projectToPlane( patchOut.wpB201
						, patchOut.wpB300
						, listIn[2].normal );
					patchOut.wpB210 = projectToPlane( patchOut.wpB210
						, patchOut.wpB300
						, listIn[2].normal );
					patchOut.wpB120 = projectToPlane( patchOut.wpB120
						, patchOut.wpB030
						, listIn[0].normal );

					// Handle the center
					auto center = writer.declLocale( "center"
						, ( patchOut.wpB003
							+ patchOut.wpB030
							+ patchOut.wpB300 ) / 3.0f );
					patchOut.wpB111 = ( patchOut.wpB021
						+ patchOut.wpB012
						+ patchOut.wpB102
						+ patchOut.wpB201
						+ patchOut.wpB210
						+ patchOut.wpB120 ) / 6.0f;
					patchOut.wpB111 += ( patchOut.wpB111 - center ) / 2.0f;

					// Calculate the distance from the camera to the three control points
					auto eyeToVertexDistance0 = writer.declLocale( "eyeToVertexDistance0"
						, distance( pos, listIn[0].position ) );
					auto eyeToVertexDistance1 = writer.declLocale( "eyeToVertexDistance1"
						, distance( pos, listIn[1].position ) );
					auto eyeToVertexDistance2 = writer.declLocale( "eyeToVertexDistance2"
						, distance( pos, listIn[2].position ) );

					// Calculate the tessellation levels
					patchOut.tessLevelOuter[0] = getTessLevel( eyeToVertexDistance1, eyeToVertexDistance2 );
					patchOut.tessLevelOuter[1] = getTessLevel( eyeToVertexDistance2, eyeToVertexDistance0 );
					patchOut.tessLevelOuter[2] = getTessLevel( eyeToVertexDistance0, eyeToVertexDistance1 );
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[2];
				} );

			writer.implementMainT< SurfaceT, maxPoints, SurfaceT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 3u
				, [&]( TessControlMainIn in
					, TessControlListInT< SurfaceT, maxPoints > listIn
					, TrianglesTessControlListOutT< SurfaceT > listOut )
				{
					// Set the control points of the output patch
					auto tbn = writer.declLocale( "tbn"
						, mat3( normalize( listIn[in.invocationID].tangent )
							, normalize( listIn[in.invocationID].bitangent )
							, normalize( listIn[in.invocationID].normal ) ) );
					auto v3MapNormal = writer.declLocale( "v3MapNormal"
						, c3d_mapNormal.lod( listIn[in.invocationID].texture.xy(), 0.0_f ).xyz() );
					v3MapNormal = normalize( v3MapNormal * 2.0_f - vec3( 1.0_f, 1.0_f, 1.0_f ) );
					listOut.normal = normalize( tbn * v3MapNormal );
					listOut.tangent = listIn[in.invocationID].tangent;
					listOut.bitangent = listIn[in.invocationID].bitangent;
					listOut.texture = listIn[in.invocationID].texture;
					listOut.instance = listIn[in.invocationID].instance;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterTessellationControlShader )
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

	tessellationControl( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterTessellationControlShader )
