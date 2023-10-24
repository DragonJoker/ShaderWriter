#include "Common.hpp"
#include "WriterCommon.hpp"

#define SDW_PreferredMeshShadingExtension SDW_MeshShadingNV
#include <ShaderWriter/MeshWriter.hpp>
#include <ShaderWriter/TaskWriter.hpp>

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

	struct TriIndex
		: public sdw::StructInstance
	{
		TriIndex( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, index{ getMember< sdw::U8Vec3 >( "index" ) }
		{
		}

		SDW_DeclStructInstance( , TriIndex );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "TriIndex" );

			if ( result->empty() )
			{
				result->declMember( "index"
					, sdw::type::Kind::eVec3U8
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::U8Vec3 index;
	};

	struct VtxIndex
		: public sdw::StructInstance
	{
		VtxIndex( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, index{ getMember< sdw::UInt >( "index" ) }
		{
		}

		SDW_DeclStructInstance( , VtxIndex );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "VtxIndex" );

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

	namespace payload
	{
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
						, 32u
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
						, 32u );
				}

				return result;
			}

			sdw::Array< sdw::UInt > meshletIndices;
		};
	}

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

	namespace cull
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

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "PerVertexColour"
				, entryPoint
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

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "PerVertexColour" );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray );
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
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, PointsMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
		}
		testEnd();
	}

	void point( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "point" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, PointsMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, PointsMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
		}
		testEnd();
	}

	void lineX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "lineX" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, LinesMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void line( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "line" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, LinesMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, LinesMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void triangleX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "triangleX" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void triangle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "triangle" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, TrianglesMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void oneTriangle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "oneTriangle" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			const auto vertices = writer.declConstantArray< Vec3 >( "vertices"
				, std::vector< Vec3 >{ vec3( -1.0_f, -1.0_f, 0.0_f ), vec3( 0.0_f, 1.0_f, 0.0_f ), vec3( 1.0_f, -1.0_f, 0.0_f ) } );
			const auto colors = writer.declConstantArray< Vec3 >( "colors"
				, std::vector< Vec3 >{ vec3( 1.0_f, 0.0_f, 0.0_f ), vec3( 0.0_f, 1.0_f, 0.0_f ), vec3( 0.0_f, 0.0_f, 1.0_f ) } );
			writer.implementMainT< VoidT, PerVertexColourT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOutT< PerVertexColourT >{ writer, 3u }
				, TrianglesMeshPrimitiveListOut{ writer, 1u }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOutT< PerVertexColourT > vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
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
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void taskPayload( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "taskPayload" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< payload::PayloadT, VoidT, VoidT >( 32u
				, TaskPayloadInT< payload::PayloadT >{ writer }
				, MeshVertexListOut{ writer, 3u }
				, TrianglesMeshPrimitiveListOut{ writer, 1u }
				, [&]( MeshIn in
					, TaskPayloadInT< payload::PayloadT > payload
					, MeshVertexListOut vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
			{
				primOut.setMeshOutputCounts( 3_u, payload.meshletIndices[0u] );
				primOut[0].primitiveIndex = uvec3( 0_u, 1_u, 2_u );
			} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void renderMeshlet( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "renderMeshlet" );
		using namespace sdw;
		using namespace render;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };

			auto Globals = writer.declUniformBuffer( "bufferGlobals", 0u, 0u );
			auto globals = Globals.declMember< Constants >( "globals" );
			Globals.end();

			auto MeshInfos = writer.declUniformBuffer( "bufferMeshInfos", 1u, 0u );
			auto meshInfo = MeshInfos.declMember< MeshInfo >( "meshInfo" );
			MeshInfos.end();

			auto vertices = writer.declArrayStorageBuffer< Vertex >( "bufferVertices", 0u, 1u );
			auto meshlets = writer.declArrayStorageBuffer< Meshlet >( "bufferMeshlets", 1u, 1u );
			auto uniqueVertexIndices = writer.declArrayStorageBuffer< VtxIndex >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayStorageBuffer< TriIndex >( "bufferPrimitiveIndices", 3u, 1u );

			auto getPrimitive = writer.implementFunction< UVec3 >( "getPrimitive"
				, [&]( Meshlet m
					, UInt index )
				{
					auto primIndices = writer.declLocale( "primIndices", primitiveIndices[m.primOffset + index].index );
					writer.returnStmt( uvec3( primIndices ) );
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "index" } );

			auto getVertexIndex = writer.implementFunction< UInt >( "getVertexIndex"
				, [&]( Meshlet m
					, UInt localIndex )
				{
					localIndex = m.vertOffset + localIndex;

					IF( writer, meshInfo.indexBytes == 4_u ) // 32-bit Vertex Indices
					{
						writer.returnStmt( uniqueVertexIndices[localIndex].index );
					}
					ELSE // 16-bit Vertex Indices
					{
						// Byte address must be 4-byte aligned.
						auto wordOffset = writer.declLocale( "wordOffset", ( localIndex & 0x1_u ) );
						auto byteOffset = writer.declLocale( "byteOffset", ( localIndex / 2_u ) );

						// Grab the pair of 16-bit indices, shift & mask off proper 16-bits.
						auto indexPair = writer.declLocale( "indexPair", uniqueVertexIndices[byteOffset].index );
						auto index = writer.declLocale( "index", ( indexPair >> ( wordOffset * 16_u ) ) & 0xffff_u );

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
					vout.positionVS = vec3( globals.worldView * vec4( v.position, 1.0f ) );
					vout.positionHS = globals.worldViewProj * vec4( v.position, 1 );
					vout.normal = ( globals.world * vec4( v.normal, 0.0f ) ).xyz();
					vout.meshletIndex = meshletIndex;

					writer.returnStmt( vout );
				}
				, InUInt{ writer, "meshletIndex" }
				, InUInt{ writer, "vertexIndex" } );

			writer.implementMainT< VoidT, MyVertexOutT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOutT< MyVertexOutT >{ writer, 252u }
				, TrianglesMeshPrimitiveListOut{ writer, 84u }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOutT< MyVertexOutT > vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
					auto gid = in.workGroupID;
					auto gtid = in.localInvocationID;
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
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void meshletInstancing( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "meshletInstancing" );
		using namespace sdw;
		using namespace instancing;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };

			auto Globals = writer.declUniformBuffer( "bufferGlobals", 0u, 0u );
			auto globals = Globals.declMember< Constants >( "globals" );
			Globals.end();

			auto DrawParam = writer.declUniformBuffer( "bufferDrawParams", 1u, 0u );
			auto drawParams = DrawParam.declMember< DrawParams >( "drawParams" );
			DrawParam.end();

			auto MeshInfos = writer.declUniformBuffer( "bufferMeshInfos", 2u, 0u );
			auto meshInfos = MeshInfos.declMember< MeshInfo >( "meshInfos" );
			MeshInfos.end();

			auto vertices = writer.declArrayStorageBuffer< Vertex >( "bufferVertices", 0u, 1u );
			auto meshlets = writer.declArrayStorageBuffer< Meshlet >( "bufferMeshlets", 1u, 1u );
			auto uniqueVertexIndices = writer.declArrayStorageBuffer< VtxIndex >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayStorageBuffer< TriIndex >( "bufferPrimitiveIndices", 3u, 1u );
			auto instances = writer.declArrayStorageBuffer< Instance >( "bufferInstances", 4u, 1u );

			auto getPrimitive = writer.implementFunction< UVec3 >( "getPrimitive"
				, [&]( Meshlet m
					, UInt index )
				{
					auto primIndices = writer.declLocale( "primIndices", primitiveIndices[m.primOffset + index].index );
					writer.returnStmt( uvec3( primIndices ) );
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "index" } );

			auto getVertexIndex = writer.implementFunction< UInt >( "getVertexIndex"
				, [&]( Meshlet m
					, UInt localIndex )
				{
					localIndex = m.vertOffset + localIndex;

					IF( writer, meshInfos.indexBytes == 4_u ) // 32-bit Vertex Indices
					{
						writer.returnStmt( uniqueVertexIndices[localIndex].index );
					}
					ELSE // 16-bit Vertex Indices
					{
						// Byte address must be 4-byte aligned.
						auto wordOffset = writer.declLocale( "wordOffset", ( localIndex & 0x1_u ) );
						auto byteOffset = writer.declLocale( "byteOffset", ( localIndex / 2_u ) );

						// Grab the pair of 16-bit indices, shift & mask off proper 16-bits.
						auto indexPair = writer.declLocale( "indexPair", uniqueVertexIndices[byteOffset].index );
						auto index = writer.declLocale( "index", ( indexPair >> ( wordOffset * 16_u ) ) & 0xffff_u );

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

			writer.implementMainT< VoidT, MyVertexOutT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOutT< MyVertexOutT >{ writer, MaxVerts }
				, TrianglesMeshPrimitiveListOut{ writer, MaxPrims }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOutT< MyVertexOutT > vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
					auto gid = in.workGroupID;
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
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void checkConstantsLayout( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "checkConstantsLayout" );
		using namespace sdw;
		using namespace cull;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };

			auto Globals = writer.declUniformBuffer( "bufferConstants", 0u, 0u );
			auto constants = Globals.declMember< Constants >( "constants" );
			Globals.end();

			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, TrianglesMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void cullMeshlet( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "cullMeshlet" );
		using namespace sdw;
		using namespace cull;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };

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
			auto uniqueVertexIndices = writer.declArrayStorageBuffer< VtxIndex >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayStorageBuffer< TriIndex >( "bufferPrimitiveIndices", 3u, 1u );
			auto meshletCullData = writer.declArrayStorageBuffer< CullData >( "bufferMeshletCullData", 4u, 1u );

			auto getPrimitive = writer.implementFunction< UVec3 >( "getPrimitive"
				, [&]( Meshlet m
					, UInt index )
				{
					auto primIndices = writer.declLocale( "primIndices", primitiveIndices[m.primOffset + index].index );
					writer.returnStmt( uvec3( primIndices ) );
				}
				, InParam< Meshlet >{ writer, "m" }
				, InUInt{ writer, "index" } );

			auto getVertexIndex = writer.implementFunction< UInt >( "getVertexIndex"
				, [&]( Meshlet m
					, UInt localIndex )
				{
					localIndex = m.vertOffset + localIndex;

					IF( writer, meshInfos.indexSize == 4_u ) // 32-bit Vertex Indices
					{
						writer.returnStmt( uniqueVertexIndices[localIndex].index );
					}
					ELSE // 16-bit Vertex Indices
					{
						// Byte address must be 4-byte aligned.
						auto wordOffset = writer.declLocale( "wordOffset", ( localIndex & 0x1_u ) );
						auto byteOffset = writer.declLocale( "byteOffset", ( localIndex / 2_u ) );

						// Grab the pair of 16-bit indices, shift & mask off proper 16-bits.
						auto indexPair = writer.declLocale( "indexPair", uniqueVertexIndices[byteOffset].index );
						auto index = writer.declLocale( "index", ( indexPair >> ( wordOffset * 16_u ) ) & 0xffff_u );

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

					auto positionWS = writer.declLocale( "positionWS", instance.world * vec4( v.position, 1.0_f ) );

					auto vout = writer.declLocale< MyVertexOut >( "vout" );
					vout.positionVS = ( positionWS * constants.view ).xyz();
					vout.positionHS = positionWS * constants.viewProj;
					vout.normal = ( vec4( v.normal, 0.0f ) * instance.worldInvTranspose ).xyz();
					vout.meshletIndex = meshletIndex;

					writer.returnStmt( vout );
				}
				, InUInt{ writer, "meshletIndex" }
				, InUInt{ writer, "vertexIndex" } );

			static uint32_t constexpr MaxVerts = 252u;
			static uint32_t constexpr MaxPrims = 84u;

			writer.implementMainT< PayloadT, MyVertexOutT, VoidT >( 32u
				, TaskPayloadInT< PayloadT >{ writer }
				, MeshVertexListOutT< MyVertexOutT >{ writer, MaxVerts }
				, TrianglesMeshPrimitiveListOut{ writer, MaxPrims }
				, [&]( MeshIn in
					, TaskPayloadInT< PayloadT > payload
					, MeshVertexListOutT< MyVertexOutT > vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
					auto dtid = in.globalInvocationID;
					auto gid = in.workGroupID;
					auto gtid = in.localInvocationID;
					// Load the meshlet from the AS payload data
					auto meshletIndex = writer.declLocale( "meshletIndex", payload.meshletIndices[gid] );

					// Catch any out-of-range indices (in case too many MS threadgroups were dispatched from AS)
					IF( writer, meshletIndex >= meshInfos.meshletCount )
					{
						writer.returnStmt();
					}
					FI;

					// Load the meshlet
					auto m = writer.declLocale( "m", meshlets[meshletIndex] );

					// Our vertex and primitive counts come directly from the meshlet
					primOut.setMeshOutputCounts( m.vertCount, m.primCount );

					//--------------------------------------------------------------------
					// Export Primitive & Vertex Data

					IF( writer, gtid < m.vertCount )
					{
						auto vertexIndex = writer.declLocale( "vertexIndex", getVertexIndex( m, gtid ) );
						auto vertex = writer.declLocale( "vertex", getVertexAttributes( meshletIndex, vertexIndex ) );
						vtxOut[gtid].position = vertex.positionHS;
						vtxOut[gtid].positionVS = vertex.positionVS;
						vtxOut[gtid].normal = vertex.normal;
						vtxOut[gtid].meshletIndex = vertex.meshletIndex;
					}
					FI;

					IF( writer, gtid < m.primCount )
					{
						primOut[gtid].primitiveIndex = getPrimitive( m, gtid );
					}
					FI;
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void writePackedPrimitiveIndices( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "writePackedPrimitiveIndices" );
		using namespace sdw;
		using namespace cull;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };

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
			auto uniqueVertexIndices = writer.declArrayStorageBuffer< VtxIndex >( "bufferUniqueVertexIndices", 2u, 1u );
			auto primitiveIndices = writer.declArrayStorageBuffer< TriIndex >( "bufferPrimitiveIndices", 3u, 1u );
			auto meshletCullData = writer.declArrayStorageBuffer< CullData >( "bufferMeshletCullData", 4u, 1u );

			auto getVertexIndex = writer.implementFunction< UInt >( "getVertexIndex"
				, [&]( Meshlet m
					, UInt localIndex )
				{
					localIndex = m.vertOffset + localIndex;

					IF( writer, meshInfos.indexSize == 4_u ) // 32-bit Vertex Indices
					{
						writer.returnStmt( uniqueVertexIndices[localIndex].index );
					}
					ELSE // 16-bit Vertex Indices
					{
						// Byte address must be 4-byte aligned.
						auto wordOffset = writer.declLocale( "wordOffset", ( localIndex & 0x1_u ) );
						auto byteOffset = writer.declLocale( "byteOffset", ( localIndex / 2_u ) );

						// Grab the pair of 16-bit indices, shift & mask off proper 16-bits.
						auto indexPair = writer.declLocale( "indexPair", uniqueVertexIndices[byteOffset].index );
						auto index = writer.declLocale( "index", ( indexPair >> ( wordOffset * 16_u ) ) & 0xffff_u );

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

					auto positionWS = writer.declLocale( "positionWS", instance.world * vec4( v.position, 1.0_f ) );

					auto vout = writer.declLocale< MyVertexOut >( "vout" );
					vout.positionVS = ( positionWS * constants.view ).xyz();
					vout.positionHS = positionWS * constants.viewProj;
					vout.normal = ( vec4( v.normal, 0.0f ) * instance.worldInvTranspose ).xyz();
					vout.meshletIndex = meshletIndex;

					writer.returnStmt( vout );
				}
				, InUInt{ writer, "meshletIndex" }
				, InUInt{ writer, "vertexIndex" } );

			static uint32_t constexpr MaxVerts = 252u;
			static uint32_t constexpr MaxPrims = 84u;

			writer.implementMainT< PayloadT, MyVertexOutT, VoidT >( 32u
				, TaskPayloadInT< PayloadT >{ writer }
				, MeshVertexListOutT< MyVertexOutT >{ writer, MaxVerts }
				, TrianglesMeshPrimitiveListOut{ writer, MaxPrims }
				, [&]( MeshIn in
					, TaskPayloadInT< PayloadT > payload
					, MeshVertexListOutT< MyVertexOutT > vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
					auto dtid = in.globalInvocationID;
					auto gid = in.workGroupID;
					auto gtid = in.localInvocationID;
					// Load the meshlet from the AS payload data
					auto meshletIndex = writer.declLocale( "meshletIndex", payload.meshletIndices[gid] );

					// Catch any out-of-range indices (in case too many MS threadgroups were dispatched from AS)
					IF( writer, meshletIndex >= meshInfos.meshletCount )
					{
						writer.returnStmt();
					}
					FI;

					// Load the meshlet
					auto m = writer.declLocale( "m", meshlets[meshletIndex] );

					// Our vertex and primitive counts come directly from the meshlet
					primOut.setMeshOutputCounts( m.vertCount, m.primCount );

					//--------------------------------------------------------------------
					// Export Primitive & Vertex Data

					IF( writer, gtid < m.vertCount )
					{
						auto vertexIndex = writer.declLocale( "vertexIndex", getVertexIndex( m, gtid ) );
						auto vertex = writer.declLocale( "vertex", getVertexAttributes( meshletIndex, vertexIndex ) );
						vtxOut[gtid].position = vertex.positionHS;
						vtxOut[gtid].positionVS = vertex.positionVS;
						vtxOut[gtid].normal = vertex.normal;
						vtxOut[gtid].meshletIndex = vertex.meshletIndex;
					}
					FI;

					IF( writer, gtid < m.primCount )
					{
						auto primIndices = writer.declLocale( "primIndices", primitiveIndices[m.primOffset + gtid].index );
						primOut[gtid].primitiveIndex = uvec3( primIndices );
					}
					FI;
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void subgroupPointX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupPointX" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshSubgroupIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, PointsMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
		}
		testEnd();
	}

	void subgroupPoint( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupPoint" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, PointsMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshSubgroupIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, PointsMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
		}
		testEnd();
	}

	void subgroupLineX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupLineX" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshSubgroupIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, LinesMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void subgroupLine( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupLine" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, LinesMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshSubgroupIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, LinesMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void subgroupTriangleX( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupTriangleX" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, 64u
				, 126u
				, [&]( MeshSubgroupIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{
				} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}

	void subgroupTriangle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "subgroupTriangle" );
		using namespace sdw;
		{
			sdw::MeshWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, VoidT, VoidT >( 32u
				, TaskPayloadIn{ writer }
				, MeshVertexListOut{ writer, 64u }
				, TrianglesMeshPrimitiveListOut{ writer, 126u }
				, [&]( MeshSubgroupIn in
					, TaskPayloadIn payload
					, MeshVertexListOut vtxOut
					, TrianglesMeshPrimitiveListOut primOut )
				{} );
			test::expectError( "Invalid capability operand: 5"
				, testCounts );
			test::writeShader( writer
				, testCounts
				, Compilers_NoGLSL );
		}
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterMeshShaderEXT )
{
	sdwTestSuiteBegin();

	pointX( testCounts );
	point( testCounts );
	lineX( testCounts );
	line( testCounts );
	triangleX( testCounts );
	triangle( testCounts );
	oneTriangle( testCounts );
	taskPayload( testCounts );
	renderMeshlet( testCounts );
	meshletInstancing( testCounts );
	checkConstantsLayout( testCounts );
	cullMeshlet( testCounts );
	writePackedPrimitiveIndices( testCounts );
	subgroupPointX( testCounts );
	subgroupPoint( testCounts );
	subgroupLineX( testCounts );
	subgroupLine( testCounts );
	subgroupTriangleX( testCounts );
	subgroupTriangle( testCounts );

	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterMeshShaderEXT )
