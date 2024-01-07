#include "Common.hpp"
#include "WriterCommon.hpp"

#define SDW_PreferredMeshShadingExtension SDW_MeshShadingEXT
#include <ShaderWriter/TaskWriter.hpp>

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
	static uint32_t const ThreadsPerWave = 32u;

	struct Constants
		: public sdw::StructInstance
	{
		Constants( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, view{ getMember< sdw::Mat4 >( "view" ) }
			, viewProj{ getMember< sdw::Mat4 >( "viewProj" ) }
			, planes{ getMemberArray< sdw::Vec4 >( "planes" ) }
			, viewPosition{ getMember< sdw::Vec3 >( "viewPosition" ) }
			, highlightedIndex{ getMember< sdw::UInt >( "highlightedIndex" ) }
			, cullViewPosition{ getMember< sdw::Vec3 >( "cullViewPosition" ) }
			, selectedIndex{ getMember< sdw::UInt >( "selectedIndex" ) }
			, drawMeshlets{ getMember< sdw::UInt >( "drawMeshlets" ) }
		{
		}

		SDW_DeclStructInstance( , Constants );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd140
				, "Constants" );

			if ( result->empty() )
			{
				result->declMember( "view"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
				result->declMember( "viewProj"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
				result->declMember( "planes"
					, sdw::type::Kind::eVec4F
					, 6u );
				result->declMember( "viewPosition"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "highlightedIndex"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "cullViewPosition"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "selectedIndex"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "drawMeshlets"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Mat4 view;
		sdw::Mat4 viewProj;
		sdw::Array< sdw::Vec4 > planes;
		sdw::Vec3 viewPosition;
		sdw::UInt highlightedIndex;
		sdw::Vec3 cullViewPosition;
		sdw::UInt selectedIndex;
		sdw::UInt drawMeshlets;
	};

	struct Instance
		: public sdw::StructInstance
	{
		Instance( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, world{ getMember< sdw::Mat4 >( "world" ) }
			, worldInvTranspose{ getMember< sdw::Mat4 >( "worldInvTranspose" ) }
			, scale{ getMember< sdw::Float >( "scale" ) }
			, flags{ getMember< sdw::UInt >( "flags" ) }
		{
		}

		SDW_DeclStructInstance( , Instance );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd140
				, "Instance" );

			if ( result->empty() )
			{
				result->declMember( "world"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
				result->declMember( "worldInvTranspose"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
				result->declMember( "scale"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
				result->declMember( "flags"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Mat4 world;
		sdw::Mat4 worldInvTranspose;
		sdw::Float scale;
		sdw::UInt flags;
	};

	struct Meshlet
		: public sdw::StructInstance
	{
		Meshlet( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, vertCount{ getMember< sdw::UInt >( "vertCount" ) }
			, vertOffset{ getMember< sdw::UInt >( "vertOffset" ) }
			, primCount{ getMember< sdw::UInt >( "primCount" ) }
			, primOffset{ getMember< sdw::UInt >( "primOffset" ) }
		{
		}

		SDW_DeclStructInstance( , Meshlet );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Meshlet" );

			if ( result->empty() )
			{
				result->declMember( "vertCount"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "vertOffset"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "primCount"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "primOffset"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::UInt vertCount;
		sdw::UInt vertOffset;
		sdw::UInt primCount;
		sdw::UInt primOffset;
	};

	struct Vertex
		: public sdw::StructInstance
	{
		Vertex( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
		{
		}

		SDW_DeclStructInstance( , Vertex );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Vertex" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;
	};

	struct Index
		: public sdw::StructInstance
	{
		Index( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, index{ getMember< sdw::UInt >( "index" ) }
		{
		}

		SDW_DeclStructInstance( , Index );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Index" );

			if ( result->empty() )
			{
				result->declMember( "index"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::UInt index;
	};

	struct CullData
		: public sdw::StructInstance
	{
		CullData( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, boundingSphere{ getMember< sdw::Vec4 >( "boundingSphere" ) }
			, normalCone{ getMember< sdw::UInt >( "normalCone" ) }
			, apexOffset{ getMember< sdw::Float >( "apexOffset" ) }
		{
		}

		SDW_DeclStructInstance( , CullData );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "CullData" );

			if ( result->empty() )
			{
				result->declMember( "boundingSphere"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray );
				result->declMember( "normalCone"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "apexOffset"
					, sdw::type::Kind::eFloat
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec4 boundingSphere;
		sdw::UInt normalCone;
		sdw::Float apexOffset;
	};

	struct MeshInfo
		: public sdw::StructInstance
	{
		MeshInfo( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, indexSize{ getMember< sdw::UInt >( "indexSize" ) }
			, meshletCount{ getMember< sdw::UInt >( "meshletCount" ) }
			, lastMeshletVertCount{ getMember< sdw::UInt >( "lastMeshletVertCount" ) }
			, lastMeshletPrimCount{ getMember< sdw::UInt >( "lastMeshletPrimCount" ) }
		{
		}

		SDW_DeclStructInstance( , MeshInfo );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd140
				, "MeshInfo" );

			if ( result->empty() )
			{
				result->declMember( "indexSize"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "meshletCount"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "lastMeshletVertCount"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "lastMeshletPrimCount"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::UInt indexSize;
		sdw::UInt meshletCount;
		sdw::UInt lastMeshletVertCount;
		sdw::UInt lastMeshletPrimCount;
	};

	template< sdw::var::Flag FlagT >
	struct PayloadT
		: public sdw::StructInstance
	{
		PayloadT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, meshletIndices{ getMemberArray< sdw::UInt >( "meshletIndices" ) }
		{
		}

		SDW_DeclStructInstance( , PayloadT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Payload"
				, entryPoint
				, ast::var::Flag( FlagT | ast::var::Flag::ePerTask ) );

			if ( result->empty() )
			{
				result->declMember( "meshletIndices"
					, sdw::type::Kind::eUInt
					, ThreadsPerWave
					, ast::type::Struct::InvalidLocation );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "Payload" );

			if ( result->empty() )
			{
				result->declMember( "meshletIndices"
					, sdw::type::Kind::eUInt
					, ThreadsPerWave );
			}

			return result;
		}

		sdw::Array< sdw::UInt > meshletIndices;
	};

	template< sdw::var::Flag FlagT >
	struct MyVertexOutT
		: public sdw::StructInstance
	{
		MyVertexOutT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, positionHS{ getMember< sdw::Vec4 >( "positionHS", true ) }
			, positionVS{ getMember< sdw::Vec3 >( "positionVS" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, meshletIndex{ getMember< sdw::UInt >( "meshletIndex" ) }
		{
		}

		SDW_DeclStructInstance( , MyVertexOutT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "VertexOut"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				uint32_t index = 0u;
				result->declMember( "positionVS"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "meshletIndex"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray
					, index++ );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "VertexOut" );

			if ( result->empty() )
			{
				result->declMember( "positionHS"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray );
				result->declMember( "positionVS"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "meshletIndex"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec4 positionHS;
		sdw::Vec3 positionVS;
		sdw::Vec3 normal;
		sdw::UInt meshletIndex;
	};
	using MyVertexOut = MyVertexOutT< sdw::var::Flag::eNone >;

	void basicX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicX" );
		using namespace sdw;
		{
			sdw::TaskWriter writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( SDW_TaskLocalSize( ThreadsPerWave, 1u, 1u )
				, TaskPayloadOutT< PayloadT >{ writer }
			, [&]( TaskIn in
				, TaskPayloadOutT< PayloadT > payload )
			{
				payload.meshletIndices[0_u] = 1_u;
				sdw::dispatchMesh( payload, 1_u );
			} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void cullMeshlet( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "cullMeshlet" );
		using namespace sdw;
		{
			sdw::TaskWriter writer{ &testCounts.allocator };
			auto Globals = writer.declUniformBuffer( "bufferConstants", 0u, 0u );
			auto constants = Globals.declMember< Constants >( "constants" );
			Globals.end();

			auto MeshInfos = writer.declUniformBuffer( "bufferMeshInfos", 1u, 0u );
			auto meshInfos = MeshInfos.declMember< MeshInfo >( "meshInfos" );
			MeshInfos.end();

			auto Instances = writer.declUniformBuffer( "bufferInstance", 2u, 0u );
			auto instance = Instances.declMember< Instance >( "instance" );
			Instances.end();

			auto vertices = writer.declArrayStorageBuffer< Vertex >( "bufferVertices", 0u, 1u );
			auto meshlets = writer.declArrayStorageBuffer< Meshlet >( "bufferMeshlets", 1u, 1u );
			auto uniqueVertexIndices = writer.declArrayStorageBuffer< Index >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayStorageBuffer< Index >( "bufferPrimitiveIndices", 3u, 1u );
			auto meshletCullData = writer.declArrayStorageBuffer< CullData >( "bufferMeshletCullData", 4u, 1u );

			uint32_t constexpr CullFlag = 0x1u;

			auto isConeDegenerate = writer.implementFunction< Boolean >( "isConeDegenerate"
				, [&]( CullData c )
				{
					writer.returnStmt( ( c.normalCone >> 24u ) == 0xff_u );
				}
			, InParam< CullData >{ writer, "c" } );

			auto unpackCone = writer.implementFunction< Vec4 >( "unpackCone"
				, [&]( UInt packedCone )
				{
					auto v = writer.declLocale< Vec4 >( "v" );
					v.x() = writer.cast< Float >( ( packedCone >> 0u ) & 0xFF_u );
					v.y() = writer.cast< Float >( ( packedCone >> 8u ) & 0xFF_u );
					v.z() = writer.cast< Float >( ( packedCone >> 16u ) & 0xFF_u );
					v.w() = writer.cast< Float >( ( packedCone >> 24u ) & 0xFF_u );

					v = v / 255.0f;
					v.xyz() = v.xyz() * 2.0f - 1.0f;

					writer.returnStmt( v );
				}
			, InParam< UInt >{ writer, "packedCone" } );

			auto isVisible = writer.implementFunction< Boolean >( "isVisible"
				, [&]( CullData c
					, Mat4 world
					, Float scale
					, Vec3 viewPos )
				{
					IF( writer, ( instance.flags & CullFlag ) == 0_u )
					{
						writer.returnStmt( Boolean{ true } );
					}
					FI;

					// Do a cull test of the bounding sphere against the view frustum planes.
					auto center = writer.declLocale( "center", vec4( c.boundingSphere.xyz(), 1.0_f ) * world );
					auto radius = writer.declLocale( "radius", c.boundingSphere.w() * scale );

					for ( int i = 0; i < 6; ++i )
					{
						IF( writer, dot( center, constants.planes[i] ) < -radius )
						{
							writer.returnStmt( Boolean{ false } );
						}
						FI;
					}

					// Do normal cone culling
					IF( writer, isConeDegenerate( c ) )
					{
						writer.returnStmt( Boolean{ true } ); // Cone is degenerate - spread is wider than a hemisphere.
					}
					FI;

					// Unpack the normal cone from its 8-bit uint compression
					auto normalCone = writer.declLocale( "normalCone", unpackCone( c.normalCone ) );

					// Transform axis to world space
					auto axis = writer.declLocale( "axis", normalize( vec4( normalCone.xyz(), 0 ) * world ).xyz() );

					// Offset the normal cone axis from the meshlet center-point - make sure to account for world scaling
					auto apex = writer.declLocale( "apex", center.xyz() - axis * c.apexOffset * scale );
					auto view = writer.declLocale( "view", normalize( viewPos - apex ) );

					// The normal cone w-component stores -cos(angle + 90 deg)
					// This is the min dot product along the inverted axis from which all the meshlet's triangles are backface
					IF( writer, dot( view, -axis ) > normalCone.w() )
					{
						writer.returnStmt( Boolean{ false } );
					}
					FI;

					// All tests passed - it will merit pixels
					writer.returnStmt( Boolean{ true } );
				}
				, InParam< CullData >{ writer, "c" }
				, InParam< Mat4 >{ writer, "world" }
				, InParam< Float >{ writer, "scale" }
				, InParam< Vec3 >{ writer, "viewPos" } );

			writer.implementMainT< PayloadT >( SDW_TaskLocalSize( ThreadsPerWave, 1u, 1u )
				, TaskPayloadOutT< PayloadT >{ writer }
			, [&]( TaskIn in
				, TaskPayloadOutT< PayloadT > payload )
			{
				auto dtid = in.globalInvocationID.x();
				auto gid = in.workGroupID.x();
				auto gtid = in.localInvocationID.x();

				auto visible = writer.declLocale( "visible", Boolean{ false } );

				// Check bounds of meshlet cull data resource
				IF( writer, dtid < meshInfos.meshletCount )
				{
					// Do visibility testing for this thread
					visible = isVisible( meshletCullData[dtid]
						, instance.world
						, instance.scale, constants.cullViewPosition );
				}
				FI;

				// Compact visible meshlets into the export payload array
				IF( writer, visible )
				{
					//auto index = writer.declLocale( "index", WavePrefixCountBits( visible ) );
					payload.meshletIndices[7_u/*index*/] = dtid;
				}
				FI;

				// Dispatch the required number of MS threadgroups to render the visible meshlets
				//auto visibleCount = writer.declLocale( "visibleCount", WaveActiveCountBits( visible ) );
				sdw::dispatchMesh( payload, 18_u/*visibleCount*/ );
			} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void subgroupBasicX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupBasicX" );
		using namespace sdw;
		{
			sdw::TaskWriter writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( SDW_TaskLocalSize( ThreadsPerWave, 1u, 1u )
				, TaskPayloadOutT< PayloadT >{ writer }
			, [&]( TaskSubgroupIn in
				, TaskPayloadOutT< PayloadT > payload )
			{
				payload.meshletIndices[0_u] = 1_u;
				sdw::dispatchMesh( payload, 1_u );
			} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void subgroupBasicXDispatchFromPayload( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupBasicXDispatchFromPayload" );
		using namespace sdw;
		{
			sdw::TaskWriter writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( SDW_TaskLocalSize( ThreadsPerWave, 1u, 1u )
				, TaskPayloadOutT< PayloadT >{ writer }
			, [&]( TaskSubgroupIn in
				, TaskPayloadOutT< PayloadT > payload )
			{
				payload.meshletIndices[0_u] = 1_u;
				payload.dispatchMesh( SDW_TaskDispatch( 1_u, 1_u, 1_u ) );
			} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void subgroupBasicXDispatchFromWriter( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupBasicXDispatchFromWriter" );
		using namespace sdw;
		{
			sdw::TaskWriter writer{ &testCounts.allocator };
			writer.implementMainT< PayloadT >( SDW_TaskLocalSize( ThreadsPerWave, 1u, 1u )
				, TaskPayloadOutT< PayloadT >{ writer }
			, [&]( TaskSubgroupIn in
				, TaskPayloadOutT< PayloadT > payload )
			{
				payload.meshletIndices[0_u] = 1_u;
				writer.dispatchMesh( SDW_TaskDispatch( 1_u, 1_u, 1_u ), payload );
			} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterTaskShaderEXT )
{
	sdwTestSuiteBegin();

	basicX( testCounts );
	cullMeshlet( testCounts );
	subgroupBasicX( testCounts );
	subgroupBasicXDispatchFromPayload( testCounts );
	subgroupBasicXDispatchFromWriter( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterTaskShaderEXT )
