#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"
#pragma warning( disable:5245 )

namespace
{
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

	struct MyVertexOut
		: public sdw::StructInstance
	{
		MyVertexOut( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, positionHS{ getMember< sdw::Vec4 >( "positionHS" ) }
			, positionVS{ getMember< sdw::Vec3 >( "positionVS" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, meshletIndex{ getMember< sdw::UInt >( "meshletIndex" ) }
		{
		}

		SDW_DeclStructInstance( , MyVertexOut );

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

	template< sdw::var::Flag FlagT >
	struct MyVertexOutT
		: public sdw::StructInstance
	{
		MyVertexOutT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, positionVS{ getMember< sdw::Vec3 >( "positionVS" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, meshletIndex{ getMember< sdw::UInt >( "meshletIndex" ) }
		{
		}

		SDW_DeclStructInstance( , MyVertexOutT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eStd430
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "VertexOut"
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

		sdw::Vec3 positionVS;
		sdw::Vec3 normal;
		sdw::UInt meshletIndex;
	};

	namespace render
	{
		struct Constants
			: public sdw::StructInstance
		{
			Constants( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, world{ getMember< sdw::Mat4 >( "world" ) }
				, worldView{ getMember< sdw::Mat4 >( "worldView" ) }
				, worldViewProj{ getMember< sdw::Mat4 >( "worldViewProj" ) }
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
					result->declMember( "world"
						, sdw::type::Kind::eMat4x4F
						, sdw::type::NotArray );
					result->declMember( "worldView"
						, sdw::type::Kind::eMat4x4F
						, sdw::type::NotArray );
					result->declMember( "worldViewProj"
						, sdw::type::Kind::eMat4x4F
						, sdw::type::NotArray );
					result->declMember( "drawMeshlets"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::Mat4 world;
			sdw::Mat4 worldView;
			sdw::Mat4 worldViewProj;
			sdw::UInt drawMeshlets;
		};

		struct MeshInfo
			: public sdw::StructInstance
		{
			MeshInfo( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, indexBytes{ getMember< sdw::UInt >( "indexBytes" ) }
				, meshletOffset{ getMember< sdw::UInt >( "meshletOffset" ) }
			{
			}

			SDW_DeclStructInstance( , MeshInfo );

			static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getStruct( sdw::type::MemoryLayout::eStd140
					, "MeshInfo" );

				if ( result->empty() )
				{
					result->declMember( "indexBytes"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
					result->declMember( "meshletOffset"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::UInt indexBytes;
			sdw::UInt meshletOffset;
		};
	}

	namespace instancing
	{
		struct Constants
			: public sdw::StructInstance
		{
			Constants( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, view{ getMember< sdw::Mat4 >( "view" ) }
				, viewProj{ getMember< sdw::Mat4 >( "viewProj" ) }
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
					result->declMember( "drawMeshlets"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::Mat4 view;
			sdw::Mat4 viewProj;
			sdw::UInt drawMeshlets;
		};

		struct DrawParams
			: public sdw::StructInstance
		{
			DrawParams( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, instanceCount{ getMember< sdw::UInt >( "instanceCount" ) }
				, instanceOffset{ getMember< sdw::UInt >( "instanceOffset" ) }
			{
			}

			SDW_DeclStructInstance( , DrawParams );

			static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getStruct( sdw::type::MemoryLayout::eStd140
					, "DrawParams" );

				if ( result->empty() )
				{
					result->declMember( "instanceCount"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
					result->declMember( "instanceOffset"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::UInt instanceCount;
			sdw::UInt instanceOffset;
		};

		struct MeshInfo
			: public sdw::StructInstance
		{
			MeshInfo( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, indexBytes{ getMember< sdw::UInt >( "indexBytes" ) }
				, meshletCount{ getMember< sdw::UInt >( "meshletCount" ) }
				, meshletOffset{ getMember< sdw::UInt >( "meshletOffset" ) }
			{
			}

			SDW_DeclStructInstance( , MeshInfo );

			static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getStruct( sdw::type::MemoryLayout::eStd140
					, "MeshInfo" );

				if ( result->empty() )
				{
					result->declMember( "indexBytes"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
					result->declMember( "meshletCount"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
					result->declMember( "meshletOffset"
						, sdw::type::Kind::eUInt
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::UInt indexBytes;
			sdw::UInt meshletCount;
			sdw::UInt meshletOffset;
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
			{
			}

			SDW_DeclStructInstance( , Instance );

			static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
					, "Instance" );

				if ( result->empty() )
				{
					result->declMember( "world"
						, sdw::type::Kind::eMat4x4F
						, sdw::type::NotArray );
					result->declMember( "worldInvTranspose"
						, sdw::type::Kind::eMat4x4F
						, sdw::type::NotArray );
				}

				return result;
			}

			sdw::Mat4 world;
			sdw::Mat4 worldInvTranspose;
		};
	}

	template< sdw::var::Flag FlagT >
	struct PerVertexColourT
		: public sdw::StructInstance
	{
		PerVertexColourT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, colour{ getMember< sdw::Vec4 >( "colour" ) }
		{
		}

		SDW_DeclStructInstance( , PerVertexColourT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eStd430
				, ( FlagT == sdw::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "PerVertexColour"
				, FlagT );

			if ( result->empty() )
			{
				uint32_t index = 0u;
				result->declMember( "colour"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, index++ );
			}

			return result;
		}

		sdw::Vec4 colour;
	};

	void pointX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "pointX" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		testEnd();
	}

	void pointXY( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "pointXY" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 2u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		testEnd();
	}

	void pointXYZ( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "pointXYZ" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 2u
				, 2u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		testEnd();
	}

	void point( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "point" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( MeshInT < VoidT >{ writer, 8u, 1u, 1u }
				, MeshVertexListOutT< VoidT >{ writer, 64u }
				, PointsMeshPrimitiveListOutT< VoidT >{ writer, 126u }
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, PointsMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, Compilers_NoHLSL );
		}
		testEnd();
	}

	void lineX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lineX" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void lineXY( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lineXY" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 2u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void lineXYZ( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lineXYZ" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 2u
				, 2u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void line( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "line" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( MeshInT < VoidT >{ writer, 8u, 1u, 1u }
				, MeshVertexListOutT< VoidT >{ writer, 64u }
				, LinesMeshPrimitiveListOutT< VoidT >{ writer, 126u }
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, LinesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void triangleX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "triangleX" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void triangleXY( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "triangleXY" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 2u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void triangleXYZ( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "triangleXYZ" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( 8u
				, 2u
				, 2u
				, 64u
				, 126u
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void triangle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "triangle" );
		using namespace sdw;
		{
			MeshWriter writer;
			writer.implementMainT< VoidT, VoidT, VoidT >( MeshInT < VoidT >{ writer, 8u, 1u, 1u }
				, MeshVertexListOutT< VoidT >{ writer, 64u }
				, TrianglesMeshPrimitiveListOutT< VoidT >{ writer, 126u }
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< VoidT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void oneTriangle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "oneTriangle" );
		using namespace sdw;
		{
			MeshWriter writer;
			const auto vertices = writer.declConstantArray< Vec3 >( "vertices"
				, std::vector< Vec3 >{ vec3( -1.0_f, -1.0_f, 0.0_f ), vec3( 0.0_f, 1.0_f, 0.0_f ), vec3( 1.0_f, -1.0_f, 0.0_f ) } );
			const auto colors = writer.declConstantArray< Vec3 >( "colors"
				, std::vector< Vec3 >{ vec3( 1.0_f, 0.0_f, 0.0_f ), vec3( 0.0_f, 1.0_f, 0.0_f ), vec3( 0.0_f, 0.0_f, 1.0_f ) } );
			writer.implementMainT< VoidT, PerVertexColourT, VoidT >( MeshInT < VoidT >{ writer, 1u, 1u, 1u }
				, MeshVertexListOutT< PerVertexColourT >{ writer, 3u }
				, TrianglesMeshPrimitiveListOutT< VoidT >{ writer, 1u }
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< PerVertexColourT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{
					primOut.setMeshOutputCounts( 3_u, 1_u );

					// Vertices position
					vtxOut[0].position = vec4( vertices[0], 1.0 );
					vtxOut[1].position = vec4( vertices[1], 1.0 );
					vtxOut[2].position = vec4( vertices[2], 1.0 );
					// Vertices color
					vtxOut[0].colour = vec4( colors[0], 1.0 );
					vtxOut[1].colour = vec4( colors[1], 1.0 );
					vtxOut[2].colour = vec4( colors[2], 1.0 );

					primOut[0].primitiveIndex = uvec3( 0_u, 1_u, 2_u );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void renderMeshlet( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "renderMeshlet" );
		using namespace sdw;
		using namespace render;
		{
			MeshWriter writer;

			auto Globals = writer.declUniformBuffer( "bufferGlobals", 0u, 0u );
			auto globals = Globals.declStructMember< Constants >( "globals" );
			Globals.end();

			auto MeshInfos = writer.declUniformBuffer( "bufferMeshInfos", 1u, 0u );
			auto meshInfo = MeshInfos.declStructMember< MeshInfo >( "meshInfo" );
			MeshInfos.end();

			auto vertices = writer.declArrayShaderStorageBuffer< Vertex >( "bufferVertices", 0u, 1u );
			auto meshlets = writer.declArrayShaderStorageBuffer< Meshlet >( "bufferMeshlets", 1u, 1u );
			auto uniqueVertexIndices = writer.declArrayShaderStorageBuffer< Index >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayShaderStorageBuffer< Index >( "bufferPrimitiveIndices", 3u, 1u );

			auto unpackPrimitive = writer.implementFunction< UVec3 >( "unpackPrimitive"
				, [&]( UInt primitive )
				{
					// Unpacks a 10 bits per index triangle from a 32-bit uint.
					writer.returnStmt( uvec3( primitive & 0x3FF
						, ( primitive >> 10 ) & 0x3FF
						, ( primitive >> 20 ) & 0x3FF ) );
				}
				, InUInt{ writer, "primitive" } );

			auto getPrimitive = writer.implementFunction< UVec3 >( "getPrimitive"
				, [&]( Meshlet m
					, UInt index )
				{
					writer.returnStmt( unpackPrimitive( primitiveIndices[m.primOffset + index].index ) );
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "index" } );

			auto getVertexIndex = writer.implementFunction< UInt >( "getVertexIndex"
				, [&]( Meshlet m
					, UInt localIndex )
				{
					localIndex = m.vertOffset + localIndex;

					IF( writer, meshInfo.indexBytes == 4 ) // 32-bit Vertex Indices
					{
						writer.returnStmt( uniqueVertexIndices[localIndex].index );
					}
					ELSE // 16-bit Vertex Indices
					{
						// Byte address must be 4-byte aligned.
						auto wordOffset = writer.declLocale( "wordOffset", ( localIndex & 0x1 ) );
						auto byteOffset = writer.declLocale( "byteOffset", ( localIndex / 2 ) );

						// Grab the pair of 16-bit indices, shift & mask off proper 16-bits.
						auto indexPair = writer.declLocale( "indexPair", uniqueVertexIndices[byteOffset].index );
						auto index = writer.declLocale( "index", ( indexPair >> ( wordOffset * 16 ) ) & 0xffff );

						writer.returnStmt( index );
					}
					FI;
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "localIndex" } );

			auto getVertexAttributes = writer.implementFunction< MyVertexOut >( "getVertexAttributes"
				, [&]( UInt meshletIndex
					, UInt vertexIndex )
				{
					auto v = writer.declLocale( "v", vertices[vertexIndex] );

					auto vout = writer.declLocale< MyVertexOut >( "vout" );
					vout.positionVS = ( globals.worldView * vec4( v.position, 1.0f ) ).xyz();
					vout.positionHS = globals.worldViewProj * vec4( v.position, 1 );
					vout.normal = ( globals.world * vec4( v.normal, 0.0f ) ).xyz();
					vout.meshletIndex = meshletIndex;

					writer.returnStmt( vout );
				}
				, InUInt{ writer, "meshletIndex" }
				, InUInt{ writer, "vertexIndex" } );

			writer.implementMainT< VoidT, MyVertexOutT, VoidT >( MeshInT < VoidT >{ writer, 32u, 1u, 1u }
				, MeshVertexListOutT< MyVertexOutT >{ writer, 252u }
				, TrianglesMeshPrimitiveListOutT< VoidT >{ writer, 84u }
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< MyVertexOutT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{
					auto gid = in.workGroupID.x();
					auto gtid = in.localInvocationID.x();
					auto m = writer.declLocale( "m", meshlets[meshInfo.meshletOffset + gid] );

					primOut.setMeshOutputCounts( m.vertCount, m.primCount );

					IF( writer, gtid < m.primCount )
					{
						primOut[gtid].primitiveIndex = getPrimitive( m, gtid );
					}
					FI;

					IF( writer, gtid < m.vertCount )
					{
						auto vertexIndex = writer.declLocale( "vertexIndex", getVertexIndex( m, gtid ) );
						auto vertex = writer.declLocale( "vertex", getVertexAttributes( gtid, vertexIndex ) );
						vtxOut[gtid].position = vertex.positionHS;
						vtxOut[gtid].positionVS = vertex.positionVS;
						vtxOut[gtid].normal = vertex.normal;
						vtxOut[gtid].meshletIndex = vertex.meshletIndex;
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void meshletInstancing( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "meshletInstancing" );
		using namespace sdw;
		using namespace instancing;
		{
			MeshWriter writer;

			auto Globals = writer.declUniformBuffer( "bufferGlobals", 0u, 0u );
			auto globals = Globals.declStructMember< Constants >( "globals" );
			Globals.end();

			auto DrawParam = writer.declUniformBuffer( "bufferDrawParams", 1u, 0u );
			auto drawParams = DrawParam.declStructMember< DrawParams >( "drawParams" );
			DrawParam.end();

			auto MeshInfos = writer.declUniformBuffer( "bufferMeshInfos", 2u, 0u );
			auto meshInfos = MeshInfos.declStructMember< MeshInfo >( "meshInfos" );
			MeshInfos.end();

			auto vertices = writer.declArrayShaderStorageBuffer< Vertex >( "bufferVertices", 0u, 1u );
			auto meshlets = writer.declArrayShaderStorageBuffer< Meshlet >( "bufferMeshlets", 1u, 1u );
			auto uniqueVertexIndices = writer.declArrayShaderStorageBuffer< Index >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayShaderStorageBuffer< Index >( "bufferPrimitiveIndices", 3u, 1u );
			auto instances = writer.declArrayShaderStorageBuffer< Instance >( "bufferInstances", 4u, 1u );

			auto unpackPrimitive = writer.implementFunction< UVec3 >( "unpackPrimitive"
				, [&]( UInt primitive )
				{
					// Unpacks a 10 bits per index triangle from a 32-bit uint.
					writer.returnStmt( uvec3( primitive & 0x3FF
						, ( primitive >> 10 ) & 0x3FF
						, ( primitive >> 20 ) & 0x3FF ) );
				}
				, InUInt{ writer, "primitive" } );

			auto getPrimitive = writer.implementFunction< UVec3 >( "getPrimitive"
				, [&]( Meshlet m
					, UInt index )
				{
					writer.returnStmt( unpackPrimitive( primitiveIndices[m.primOffset + index].index ) );
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "index" } );

			auto getVertexIndex = writer.implementFunction< UInt >( "getVertexIndex"
				, [&]( Meshlet m
					, UInt localIndex )
				{
					localIndex = m.vertOffset + localIndex;

					IF( writer, meshInfos.indexBytes == 4 ) // 32-bit Vertex Indices
					{
						writer.returnStmt( uniqueVertexIndices[localIndex].index );
					}
					ELSE // 16-bit Vertex Indices
					{
						// Byte address must be 4-byte aligned.
						auto wordOffset = writer.declLocale( "wordOffset", ( localIndex & 0x1 ) );
						auto byteOffset = writer.declLocale( "byteOffset", ( localIndex / 2 ) );

						// Grab the pair of 16-bit indices, shift & mask off proper 16-bits.
						auto indexPair = writer.declLocale( "indexPair", uniqueVertexIndices[byteOffset].index );
						auto index = writer.declLocale( "index", ( indexPair >> ( wordOffset * 16 ) ) & 0xffff );

						writer.returnStmt( index );
					}
					FI;
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "localIndex" } );

			auto getVertexAttributes = writer.implementFunction< MyVertexOut >( "getVertexAttributes"
				, [&]( UInt meshletIndex
					, UInt vertexIndex
					, UInt instanceIndex )
				{
					auto n = writer.declLocale( "n", instances[drawParams.instanceOffset + instanceIndex] );
					auto v = writer.declLocale( "v", vertices[vertexIndex] );

					auto positionWS = writer.declLocale( "positionWS", n.world * vec4( v.position, 1.0_f ) );

					auto vout = writer.declLocale< MyVertexOut >( "vout" );
					vout.positionVS = ( globals.view * positionWS ).xyz();
					vout.positionHS = globals.viewProj * positionWS;
					vout.normal = ( n.worldInvTranspose * vec4( v.normal, 0.0f ) ).xyz();
					vout.meshletIndex = meshletIndex;

					writer.returnStmt( vout );
				}
				, InUInt{ writer, "meshletIndex" }
				, InUInt{ writer, "vertexIndex" }
				, InUInt{ writer, "instanceIndex" } );

			static uint32_t constexpr MaxVerts = 252u;
			static uint32_t constexpr MaxPrims = 84u;

			writer.implementMainT< VoidT, MyVertexOutT, VoidT >( MeshInT < VoidT >{ writer, 32u, 1u, 1u }
				, MeshVertexListOutT< MyVertexOutT >{ writer, MaxVerts }
				, TrianglesMeshPrimitiveListOutT< VoidT >{ writer, MaxPrims }
				, [&]( MeshInT< VoidT > in
					, MeshVertexListOutT< MyVertexOutT > vtxOut
					, TrianglesMeshPrimitiveListOutT< VoidT > primOut )
				{
					auto gid = in.workGroupID.x();
					auto gtid = in.localInvocationIndex;
					auto meshletIndex = writer.declLocale( "meshletIndex", gid /drawParams.instanceCount );
					auto m = writer.declLocale( "m", meshlets[meshletIndex] );

					// Determine instance count - only 1 instance per threadgroup in the general case
					auto startInstance = writer.declLocale( "startInstance", gid % drawParams.instanceCount );
					auto instanceCount = writer.declLocale( "instanceCount", 1_u );

					// Last meshlet in mesh may be be packed - multiple instances submitted by a single threadgroup.
					IF( writer, meshletIndex == meshInfos.meshletCount - 1_u )
					{
						auto instancesPerGroup = writer.declLocale( "instancesPerGroup", min( MaxVerts / m.vertCount, MaxPrims / m.primCount ) );

						// Determine how many packed instances there are in this group
						auto unpackedGroupCount = writer.declLocale( "unpackedGroupCount", ( meshInfos.meshletCount - 1_u ) * drawParams.instanceCount );
						auto packedIndex = writer.declLocale( "packedIndex", gid - unpackedGroupCount );

						startInstance = packedIndex * instancesPerGroup;
						instanceCount = min( drawParams.instanceCount - startInstance, instancesPerGroup );
					}
					FI;

					// Compute our total vertex & primitive counts
					auto vertCount = writer.declLocale( "vertCount", m.vertCount * instanceCount );
					auto primCount = writer.declLocale( "primCount", m.primCount * instanceCount );

					primOut.setMeshOutputCounts( vertCount, primCount );

					IF( writer, gtid < vertCount )
					{
						auto readIndex = writer.declLocale( "readIndex", gtid % m.vertCount );  // Wrap our reads for packed instancing.
						auto instanceId = writer.declLocale( "instanceId", gtid / m.vertCount ); // Instance index into this threadgroup's instances (only non-zero for packed threadgroups.)

						auto vertexIndex = writer.declLocale( "vertexIndex", getVertexIndex( m, readIndex ) );
						auto instanceIndex = writer.declLocale( "instanceIndex", startInstance + instanceId );

						auto vertex = writer.declLocale( "vertex", getVertexAttributes( meshletIndex, vertexIndex, instanceIndex ) );
						vtxOut[gtid].position = vertex.positionHS;
						vtxOut[gtid].positionVS = vertex.positionVS;
						vtxOut[gtid].normal = vertex.normal;
						vtxOut[gtid].meshletIndex = vertex.meshletIndex;
					}
					FI;

					IF( writer, gtid < primCount )
					{
						auto readIndex = writer.declLocale( "readIndex", gtid % m.primCount );  // Wrap our reads for packed instancing.
						auto instanceId = writer.declLocale( "instanceId", gtid / m.primCount ); // Instance index within this threadgroup (only non-zero in last meshlet threadgroups.)

						// Must offset the vertex indices to this thread's instanced verts
						primOut[gtid].primitiveIndex = getPrimitive( m, readIndex ) + ( m.vertCount * instanceId );
					}
					FI;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterMeshShader )
{
	sdwTestSuiteBegin();

	pointX( testCounts );
	pointXY( testCounts );
	pointXYZ( testCounts );
	point( testCounts );
	lineX( testCounts );
	lineXY( testCounts );
	lineXYZ( testCounts );
	line( testCounts );
	triangleX( testCounts );
	triangleXY( testCounts );
	triangleXYZ( testCounts );
	triangle( testCounts );
	oneTriangle( testCounts );
	renderMeshlet( testCounts );
	meshletInstancing( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterMeshShader )
