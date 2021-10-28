#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

#undef ForceDisplayShaders
#define ForceDisplayShaders true

#undef CurrentCompilers
#define CurrentCompilers Compilers_NoHLSL

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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
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

		static sdw::type::StructPtr makeType( sdw::type::TypesCache & cache )
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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Surface"
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

		static sdw::type::StructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Surface" );

			if ( result->empty() )
			{
				result->declMember( "position", sdw::type::Kind::eVec3F );
				result->declMember( "normal", sdw::type::Kind::eVec3F );
				result->declMember( "tangent", sdw::type::Kind::eVec3F );
				result->declMember( "bitangent", sdw::type::Kind::eVec3F );
				result->declMember( "texture", sdw::type::Kind::eVec3F );
				result->declMember( "instance", sdw::type::Kind::eInt );
				result->end();
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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "SimplePatch"
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

		sdw::Vec3 control;
	};

	template< sdw::var::Flag FlagT >
	struct BezierPatchT
		: sdw::StructInstance
	{
		BezierPatchT( sdw::ShaderWriter & writer
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

		SDW_DeclStructInstance( , BezierPatchT );

		template< sdw::var::Flag FlagU >
		BezierPatchT operator=( BezierPatchT< FlagU > const & rhs )
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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "BezierPatch"
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
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< VoidT, 32u, VoidT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = 2.0_f;
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, 32u, VoidT >( 6u
				, [&]( TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessPatchOutT< VoidT > patch )
				{
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
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< VoidT, 32u, PositionT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					listOut[0].position = listIn[0].vtx.position.xyz();
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = 2.0_f;
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, 32u, VoidT >( 6u
				, [&]( TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessPatchOutT< VoidT > patch )
				{
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
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< PositionT, 32u, VoidT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = listIn[0].position.y();
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, 32u, VoidT >( 6u
				, [&]( TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessPatchOutT< VoidT > patch )
				{
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
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< PositionT, 32u, PositionT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					listOut[0].position = listIn[0].position;
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = listIn[0].position.y();
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, 32u, VoidT >( 6u
				, [&]( TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessPatchOutT< VoidT > patch )
				{
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
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< VoidT, 32u, VoidT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = 2.0_f;
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, 32u, SimplePatchT >( 6u
				, [&]( TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patch )
				{
					patch.control = vec3( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificOutputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificOutputOnlyPatch" );
		using namespace sdw;
		{
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< VoidT, 32u, PositionT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					listOut[0].position = listIn[0].vtx.position.xyz();
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = 2.0_f;
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< VoidT, 32u, SimplePatchT >( 6u
				, [&]( TessControlListInT< VoidT, 32u > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patch )
				{
					patch.control = vec3( 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificInputOnlyPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificInputOnlyPatch" );
		using namespace sdw;
		{
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< PositionT, 32u, VoidT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< VoidT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = listIn[0].position.y();
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, 32u, SimplePatchT >( 6u
				, [&]( TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patch )
				{
					patch.control = listIn[0].position;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void specificInAndOutPatch( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "specificInAndOutPatch" );
		using namespace sdw;
		{
			TessellationControlWriter writer;

			writer.implementPatchRoutineT< PositionT, 32u, PositionT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< PositionT > listOut )
				{
					listOut[0].vtx.position = listIn[0].vtx.position;
					listOut[0].position = listIn[0].position;
					out.tessLevelOuter[0] = listIn[0].vtx.position.w();
					out.tessLevelOuter[1] = listIn[0].position.y();
					out.tessLevelInner[0] = out.tessLevelOuter[1];
				} );

			writer.implementMainT< PositionT, 32u, SimplePatchT >( 6u
				, [&]( TessControlListInT< PositionT, 32u > listIn
					, TrianglesTessPatchOutT< SimplePatchT > patch )
				{
					patch.control = listIn[0].position;
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
			TessellationControlWriter writer;

			// TCS inputs
			sdw::Ubo ubo{ writer, "Wow", 0u, 0u };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			auto c3d_mapNormal = writer.declSampledImage< FImg2DRgba32 >( "c3d_mapNormal", 0u, 0u );
			auto c3d_mapHeight = writer.declSampledImage< FImg2DRgba32 >( "c3d_mapHeight", 1u, 0u );

			auto getTessLevel = writer.implementFunction< Float >( "getTessLevel"
				, [&]( Float const & a
					, Float const & b )
				{
					auto avgDistance = writer.declLocale( "avgDistance"
						, ( a + b ) / 2.0 );

					IF( writer, avgDistance <= 20.0 )
					{
						writer.returnStmt( 256.0_f );
					}
					ELSEIF( avgDistance <= 50.0 )
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

			writer.implementPatchRoutineT< SurfaceT, 32u, SurfaceT >( ast::type::OutputPartitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::OutputVertexOrder::eCCW
				, 1u
				, [&]( TessControlIn in
					, TessControlListInT< SurfaceT, 32u > listIn
					, TrianglesTessControlOut out
					, TrianglesTessControlListOutT< SurfaceT > listOut )
				{
					// Set the control points of the output patch
					FOR( writer, Int, i, 0, i < 3_i, i++ )
					{
						auto tbn = writer.declLocale( "tbn"
							, mat3( normalize( listIn[i].tangent )
								, normalize( listIn[i].bitangent )
								, normalize( listIn[i].normal ) ) );
						auto v3MapNormal = writer.declLocale( "v3MapNormal"
							, c3d_mapNormal.lod( listIn[i].texture.xy(), 0.0_f ).xyz() );
						v3MapNormal = normalize( v3MapNormal * 2.0_f - vec3( 1.0_f, 1.0, 1.0 ) );
						listOut[i].normal = normalize( tbn * v3MapNormal );
						listOut[i].tangent = listIn[i].tangent;
						listOut[i].bitangent = listIn[i].bitangent;
						listOut[i].texture = listIn[i].texture;
						listOut[i].instance = listIn[i].instance;
					}
					ROF;

					// Calculate the distance from the camera to the three control points
					auto eyeToVertexDistance0 = writer.declLocale( "eyeToVertexDistance0"
						, distance( pos, listIn[0].position ) );
					auto eyeToVertexDistance1 = writer.declLocale( "eyeToVertexDistance1"
						, distance( pos, listIn[1].position ) );
					auto eyeToVertexDistance2 = writer.declLocale( "eyeToVertexDistance2"
						, distance( pos, listIn[2].position ) );

					// Calculate the tessellation levels
					out.tessLevelOuter[0] = getTessLevel( eyeToVertexDistance1, eyeToVertexDistance2 );
					out.tessLevelOuter[1] = getTessLevel( eyeToVertexDistance2, eyeToVertexDistance0 );
					out.tessLevelOuter[2] = getTessLevel( eyeToVertexDistance0, eyeToVertexDistance1 );
					out.tessLevelInner[0] = out.tessLevelOuter[2];
				} );

			writer.implementMainT< SurfaceT, 32u, BezierPatchT >( 6u
				, [&]( TessControlListInT< SurfaceT, 32u > listIn
					, TrianglesTessPatchOutT< BezierPatchT > patch )
				{
					// The original vertices stay the same
					patch.wpB030 = listIn[0].position;
					patch.wpB003 = listIn[1].position;
					patch.wpB300 = listIn[2].position;

					// Edges are names according to the opposing vertex
					auto edgeB300 = writer.declLocale( "edgeB300"
						, patch.wpB003 - patch.wpB030 );
					auto edgeB030 = writer.declLocale( "edgeB030"
						, patch.wpB300 - patch.wpB003 );
					auto edgeB003 = writer.declLocale( "edgeB003"
						, patch.wpB030 - patch.wpB300 );

					// Generate two midpoints on each edge
					patch.wpB021 = patch.wpB030 + edgeB300 / 3.0;
					patch.wpB012 = patch.wpB030 + edgeB300 * 2.0 / 3.0;
					patch.wpB102 = patch.wpB003 + edgeB030 / 3.0;
					patch.wpB201 = patch.wpB003 + edgeB030 * 2.0 / 3.0;
					patch.wpB210 = patch.wpB300 + edgeB003 / 3.0;
					patch.wpB120 = patch.wpB300 + edgeB003 * 2.0 / 3.0;

					// Project each midpoint on the plane defined by the nearest vertex and its normal
					patch.wpB021 = projectToPlane( patch.wpB021
						, patch.wpB030
						, listIn[0].normal );
					patch.wpB012 = projectToPlane( patch.wpB012
						, patch.wpB003
						, listIn[1].normal );
					patch.wpB102 = projectToPlane( patch.wpB102
						, patch.wpB003
						, listIn[1].normal );
					patch.wpB201 = projectToPlane( patch.wpB201
						, patch.wpB300
						, listIn[2].normal );
					patch.wpB210 = projectToPlane( patch.wpB210
						, patch.wpB300
						, listIn[2].normal );
					patch.wpB120 = projectToPlane( patch.wpB120
						, patch.wpB030
						, listIn[0].normal );

					// Handle the center
					auto center = writer.declLocale( "center"
						, ( patch.wpB003
							+ patch.wpB030
							+ patch.wpB300 ) / 3.0 );
					patch.wpB111 = ( patch.wpB021
						+ patch.wpB012
						+ patch.wpB102
						+ patch.wpB201
						+ patch.wpB210
						+ patch.wpB120 ) / 6.0;
					patch.wpB111 += ( patch.wpB111 - center ) / 2.0;
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
	specificInputOnly( testCounts );
	specificOutputOnly( testCounts );
	specificInAndOut( testCounts );
	noSpecificIOPatch( testCounts );
	specificInputOnlyPatch( testCounts );
	specificOutputOnlyPatch( testCounts );
	specificInAndOutPatch( testCounts );
	tessellationControl( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterTessellationControlShader )
