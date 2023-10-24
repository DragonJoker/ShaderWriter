#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/ModernGraphicsWriterEXT.hpp>
#include <ShaderWriter/ModernGraphicsWriterNV.hpp>
#include <ShaderWriter/RayTraceWriter.hpp>
#include <ShaderWriter/TraditionalGraphicsWriter.hpp>
#include <ShaderWriter/CompositeTypes/IOStructHelper.hpp>
#include <ShaderWriter/CompositeTypes/IOStructInstanceHelper.hpp>
#include <ShaderWriter/CompositeTypes/PushConstantBuffer.hpp>

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

#define RayTraceCompilers Compilers_NoHLSL
#define MeshEXTCompilers Compilers_NoGLSL

namespace
{
	static uint32_t const ThreadsPerWave = 32u;

	template< sdw::var::Flag FlagT >
	struct ColourT
		: sdw::StructInstance
	{
		ColourT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, colour{ getMember< sdw::Vec4 >( "colour" ) }
		{
		}

		SDW_DeclStructInstance( , ColourT );

		static ast::type::IOStructPtr makeIOType( ast::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "Colour"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, ast::type::Kind::eVec4F
					, ast::type::NotArray
					, 0u );
			}

			return result;
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eC
				, "Colour" );

			if ( result->empty() )
			{
				result->declMember( "colour"
					, ast::type::Kind::eVec4F
					, ast::type::NotArray );
			}

			return result;
		}

		sdw::Vec4 colour;
	};

	template< sdw::var::Flag FlagT >
	struct PositionT
		: sdw::StructInstance
	{
		PositionT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec4 >( "position" ) }
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
			}

			return result;
		}

		sdw::Vec4 position;
	};

	template< sdw::var::Flag FlagT >
	using PosColStructT = sdw::IOStructInstanceHelperT< FlagT
		, "PosCol"
		, sdw::IOVec4Field< "position", 0u >
		, sdw::IOVec4Field< "colour", 1u > >;

	template< sdw::var::Flag FlagT >
	struct PosColT
		: public PosColStructT< FlagT >
	{
		PosColT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: PosColStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
		auto colour()const { return this->template getMember< "colour" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct PosNmlTexTanT
		: sdw::StructInstance
	{
		PosNmlTexTanT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
			, tangent{ getMember< sdw::Vec4 >( "tangent" ) }
		{
		}

		SDW_DeclStructInstance( , PosNmlTexTanT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "PosNmlTexTan"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 1u );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray
					, 2u );
				result->declMember( "tangent"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, 3u );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eC
				, "PosNmlTexTan" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 0u );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, 1u );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray
					, 2u );
				result->declMember( "tangent"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, 3u );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;
		sdw::Vec2 texcoord;
		sdw::Vec4 tangent;
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
			auto result = cache.getIOStruct( "PNTri"
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
	struct HitPayload
		: sdw::StructInstance
	{
		HitPayload( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, color{ getMember< sdw::Vec3 >( "color" ) }
		{
		}

		SDW_DeclStructInstance( , HitPayload );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "HitPayload" );

			if ( result->empty() )
			{
				result->declMember( "color"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 color;
	};

	struct ObjDesc
		: sdw::StructInstance
	{
		ObjDesc( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, txtOffset{ getMember< sdw::Int >( "txtOffset" ) }
			, vertexAddress{ getMember< sdw::UInt64 >( "vertexAddress" ) }
			, indexAddress{ getMember< sdw::UInt64 >( "indexAddress" ) }
			, materialAddress{ getMember< sdw::UInt64 >( "materialAddress" ) }
			, materialIndexAddress{ getMember< sdw::UInt64 >( "materialIndexAddress" ) }
		{
		}

		SDW_DeclStructInstance( , ObjDesc );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "ObjDesc" );

			if ( result->empty() )
			{
				result->declMember( "txtOffset"
					, sdw::type::Kind::eInt
					, sdw::type::NotArray );
				result->declMember( "vertexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "indexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "materialAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
				result->declMember( "materialIndexAddress"
					, sdw::type::Kind::eUInt64
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Int txtOffset;
		sdw::UInt64 vertexAddress;
		sdw::UInt64 indexAddress;
		sdw::UInt64 materialAddress;
		sdw::UInt64 materialIndexAddress;
	};

	template< ast::type::MemoryLayout LayoutT >
	struct VertexT
		: sdw::StructInstance
	{
		VertexT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, pos{ getMember< sdw::Vec3 >( "pos" ) }
			, nrm{ getMember< sdw::Vec3 >( "nrm" ) }
			, color{ getMember< sdw::Vec3 >( "color" ) }
			, texCoord{ getMember< sdw::Vec2 >( "texCoord" ) }
		{
		}

		SDW_DeclStructInstance( , VertexT );

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( LayoutT
				, "Vertex" );

			if ( result->empty() )
			{
				result->declMember( "pos"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "nrm"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "color"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "texCoord"
					, sdw::type::Kind::eVec2F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 pos;
		sdw::Vec3 nrm;
		sdw::Vec3 color;
		sdw::Vec2 texCoord;
	};
	using Vertex430 = VertexT< sdw::type::MemoryLayout::eStd430 >;
	using VertexScalar = VertexT< sdw::type::MemoryLayout::eScalar >;

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
				result->declMember( "world"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
				result->declMember( "worldView"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
				result->declMember( "worldViewProj"
					, sdw::type::Kind::eMat4x4F
					, sdw::type::NotArray );
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

		sdw::Mat4 world;
		sdw::Mat4 worldView;
		sdw::Mat4 worldViewProj;
		sdw::Mat4 view;
		sdw::Mat4 viewProj;
		sdw::Array< sdw::Vec4 > planes;
		sdw::Vec3 viewPosition;
		sdw::UInt highlightedIndex;
		sdw::Vec3 cullViewPosition;
		sdw::UInt selectedIndex;
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
			, meshletCount{ getMember< sdw::UInt >( "meshletCount" ) }
			, meshletOffset{ getMember< sdw::UInt >( "meshletOffset" ) }
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
				result->declMember( "indexBytes"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "meshletCount"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "meshletOffset"
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

		sdw::UInt indexBytes;
		sdw::UInt meshletCount;
		sdw::UInt meshletOffset;
		sdw::UInt lastMeshletVertCount;
		sdw::UInt lastMeshletPrimCount;
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
				result->declMember( "positionHS"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, index++ );
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

	void basicPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicPipeline" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };

		// Vertex Shader
		writer.implementEntryPointT< PosColT, PosColT >( [&]( sdw::VertexInT< PosColT > in
			, sdw::VertexOutT< PosColT > out )
			{
				out.colour() = in.colour();
				out.position() = in.position();
				out.vtx.position = in.position();
			} );

		// Fragment Shader
		writer.implementEntryPointT< PosColT, ColourT >( [&]( sdw::FragmentInT< PosColT > in
			, sdw::FragmentOutT< ColourT > out )
			{
				IF( writer, in.position().x() < 0.0_f )
				{
					writer.demote();
				}
				FI;

				out.colour = in.colour();
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void geometryPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "geometryPipeline" );
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };

		sdw::UniformBuffer voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
		auto mvp = voxelizeUbo.declMember< sdw::Mat4 >( "mvp" );
		voxelizeUbo.end();

		using MyTriangleList = sdw::TriangleListT< PositionT >;
		using MyTriangleStream = sdw::TriangleStreamT< PositionT >;

		// Vertex Shader
		writer.implementEntryPointT< PositionT, PositionT >( [&]( sdw::VertexInT< PositionT > in
			, sdw::VertexOutT< PositionT > out )
			{
				out.position = in.position;
				out.vtx.position = out.position;
			} );

		// Geometry Shader
		writer.implementEntryPointT< 3u, MyTriangleList, MyTriangleStream >( [&]( sdw::GeometryIn in
			, MyTriangleList list
			, MyTriangleStream out )
			{
				auto pos = writer.declLocale< sdw::Vec4 >( "pos" );

				pos = mvp * list[0].vtx.position;
				out.position = pos;
				out.vtx.position = pos;
				out.append();

				pos = mvp * list[1].vtx.position;
				out.position = pos;
				out.vtx.position = pos;
				out.append();

				pos = mvp * list[2].vtx.position;
				out.position = pos;
				out.vtx.position = pos;
				out.append();

				out.restartStrip();
			} );

		// Fragment Shader
		writer.implementEntryPointT< PositionT, ColourT >( [&]( sdw::FragmentInT< PositionT > in
			, sdw::FragmentOutT< ColourT > out )
			{
				out.colour = in.position;
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void tessellationPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "tessellationPipeline" );
		static uint32_t constexpr maxPoints = 3u;
		sdw::TraditionalGraphicsWriter writer{ &testCounts.allocator };

		sdw::UniformBuffer ubo{ writer, "Wow", 0u, 0u };
		auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
		auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
		ubo.end();

		auto c3d_mapNormal = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapNormal", 1u, 0u );

		auto getTessLevel = writer.implementFunction< sdw::Float >( "getTessLevel"
			, [&]( sdw::Float const & a
				, sdw::Float const & b )
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
			, sdw::InFloat{ writer, "a" }
			, sdw::InFloat{ writer, "b" } );

		auto projectToPlane = writer.implementFunction< sdw::Vec3 >( "projectToPlane"
			, [&]( sdw::Vec3 const & point
				, sdw::Vec3 const & planePoint
				, sdw::Vec3 const & planeNormal )
			{
				auto v = writer.declLocale( "v"
					, point - planePoint );
				writer.returnStmt( point - dot( v, planeNormal ) * planeNormal );
			}
			, sdw::InVec3{ writer, "point" }
			, sdw::InVec3{ writer, "planePoint" }
			, sdw::InVec3{ writer, "planeNormal " } );

		auto interpolate1D = writer.implementFunction< sdw::Float >( "interpolate1D"
			, [&]( sdw::Vec3 const & tessCoord
				, sdw::Int const & v0
				, sdw::Int const & v1
				, sdw::Int const & v2 )
			{
				writer.returnStmt( tessCoord.x() * writer.cast< sdw::Float >( v0 )
					+ tessCoord.y() * writer.cast< sdw::Float >( v1 )
					+ tessCoord.z() * writer.cast< sdw::Float >( v2 ) );
			}
			, sdw::InVec3{ writer, "tessCoord" }
			, sdw::InInt{ writer, "v0" }
			, sdw::InInt{ writer, "v1" }
			, sdw::InInt{ writer, "v2" } );

		auto interpolate2D = writer.implementFunction< sdw::Vec2 >( "interpolate2D"
			, [&]( sdw::Vec3 const & tessCoord
				, sdw::Vec2 const & v0
				, sdw::Vec2 const & v1
				, sdw::Vec2 const & v2 )
			{
				writer.returnStmt( vec2( tessCoord.x() ) * v0
					+ vec2( tessCoord.y() ) * v1
					+ vec2( tessCoord.z() ) * v2 );
			}
			, sdw::InVec3{ writer, "tessCoord" }
			, sdw::InVec2{ writer, "v0" }
			, sdw::InVec2{ writer, "v1" }
			, sdw::InVec2{ writer, "v2" } );

		auto interpolate3D = writer.implementFunction< sdw::Vec3 >( "interpolate3D"
			, [&]( sdw::Vec3 const & tessCoord
				, sdw::Vec3 const & v0
				, sdw::Vec3 const & v1
				, sdw::Vec3 const & v2 )
			{
				writer.returnStmt( vec3( tessCoord.x() ) * v0
					+ vec3( tessCoord.y() ) * v1
					+ vec3( tessCoord.z() ) * v2 );
			}
			, sdw::InVec3{ writer, "tessCoord" }
			, sdw::InVec3{ writer, "v0" }
			, sdw::InVec3{ writer, "v1" }
			, sdw::InVec3{ writer, "v2" } );

		// Vertex Shader
		writer.implementEntryPointT< SurfaceT, SurfaceT >( [&]( sdw::VertexInT< SurfaceT > in
			, sdw::VertexOutT< SurfaceT > out )
			{
				out.position = in.position;
				out.normal = in.normal;
				out.tangent = in.tangent;
				out.bitangent = in.bitangent;
				out.texture = in.texture;
				out.instance = in.instance;
				out.vtx.position = vec4( in.position, 1.0_f );
			} );

		// Tessellation Control Shader
		writer.implementPatchRoutineT< SurfaceT, maxPoints, PNTriPatchT >( 6u
			, [&]( sdw::TessControlPatchRoutineIn in
				, sdw::TessControlListInT< SurfaceT, maxPoints > listIn
				, sdw::TrianglesTessPatchOutT< PNTriPatchT > patchOut )
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

		writer.implementEntryPointT< SurfaceT, maxPoints, SurfaceT >( sdw::type::Partitioning::eEqual
			, sdw::type::OutputTopology::ePoint
			, sdw::type::PrimitiveOrdering::eCCW
			, 3u
			, [&]( sdw::TessControlMainIn in
				, sdw::TessControlListInT< SurfaceT, maxPoints > listIn
				, sdw::TrianglesTessControlListOutT< SurfaceT > listOut )
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

		// Tessellation Evaluation Shader
		writer.implementEntryPointT< SurfaceT, maxPoints, PNTriPatchT, SurfaceT >( 6u
			, sdw::type::Partitioning::eEqual
			, sdw::type::PrimitiveOrdering::eCCW
			, [&]( sdw::TessEvalMainIn mainIn
				, sdw::TessEvalListInT< SurfaceT, maxPoints > listIn
				, sdw::TrianglesTessPatchInT< PNTriPatchT > patchIn
				, sdw::TessEvalDataOutT< SurfaceT > out )
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
				out.instance = writer.cast< sdw::Int >( interpolate1D( patchIn.tessCoord
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

		// Fragment Shader
		writer.implementEntryPointT< SurfaceT, ColourT >( [&]( sdw::FragmentInT< SurfaceT > in
			, sdw::FragmentOutT< ColourT > out )
			{
				out.colour = vec4( vec3( in.normal ), 1.0_f );
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void rayTracePipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "rayTracePipeline" );
		sdw::RayTraceWriter writer{ &testCounts.allocator };

		auto topLevelAS = writer.declAccelerationStructure( "topLevelAS", 0u, 0u );
		auto image = writer.declStorageImg< WFImg2DRgba32 >( "image", 1u, 0u );

		auto ubo = writer.declUniformBuffer( "GlobalUniforms", 2u, 0u );
		auto viewProj = ubo.declMember< sdw::Mat4 >( "viewProj" );
		auto viewInverse = ubo.declMember< sdw::Mat4 >( "viewInverse" );
		auto projInverse = ubo.declMember< sdw::Mat4 >( "projInverse" );
		auto clearColor = ubo.declMember< sdw::Vec4 >( "clearColor" );
		ubo.end();

		auto objDescs = writer.declArrayStorageBuffer< ObjDesc >( "ObjDescs", 0u, 1u );
		auto Vertices = writer.declBufferReference< sdw::ArrayStorageBufferT< VertexScalar > >( "Vertices", sdw::type::MemoryLayout::eScalar, sdw::type::Storage::ePhysicalStorageBuffer );
		auto Indices = writer.declBufferReference< sdw::ArrayStorageBufferT< sdw::IVec3 > >( "Indices", sdw::type::MemoryLayout::eScalar, sdw::type::Storage::ePhysicalStorageBuffer );

		auto traceRay = writer.implementFunction< sdw::Vec3 >( "traceRay"
			, [&]( sdw::Vec2 const samplePos )
			{
				auto target = writer.declLocale( "target"
					, projInverse * vec4( samplePos.x(), samplePos.y(), 1.0_f, 1.0_f ) );
				auto rayFlags = writer.declLocale( "rayFlags"
					, sdw::RayFlags::Opaque() );
				auto ray = writer.declLocale< sdw::RayDesc >( "ray" );
				ray.origin = vec3( viewInverse * vec4( 0.0_f, 0.0_f, 0.0_f, 1.0_f ) );
				ray.direction = vec3( viewInverse * vec4( normalize( target.xyz() ), 0.0_f ) );
				ray.tMin = 0.001_f;
				ray.tMax = 10000.0_f;
				auto rayPayload = writer.declRayPayload< HitPayload >( "rayPayload", 0u );
				rayPayload.traceRay( topLevelAS	// acceleration structure
					, rayFlags					// rayFlags
					, 0xFF_u					// cullMask
					, 0_u						// sbtRecordOffset
					, 0_u						// sbtRecordStride
					, 0_u						// missIndex
					, ray );
				writer.returnStmt( rayPayload.color );
			}
			, sdw::InVec2{ writer, "samplePos" } );

		// Ray Generation shader
		writer.implementEntryPoint( [&]( sdw::RayGenerationIn in )
			{
				auto const pixelCenter = writer.declLocale( "pixelCenter"
					, vec2( in.launchID.xy() ) + vec2( 0.5_f ) );
				auto const inUV = writer.declLocale( "inUV"
					, pixelCenter / vec2( in.launchSize.xy() ) );
				auto samplePos = writer.declLocale( "samplePos"
					, inUV * 2.0_f - 1.0_f );
				image.store( ivec2( in.launchID.xy() ), vec4( traceRay( samplePos ), 1.0_f ) );
			} );

		// Ray Closest Hit shader
		writer.implementEntryPointT< HitPayload, sdw::Vec2 >( sdw::RayPayloadInT< HitPayload >{ writer, 0u }
			, sdw::HitAttributeT< sdw::Vec2 >{ writer }
			, [&]( sdw::RayClosestHitIn in
				, sdw::RayPayloadInT< HitPayload > prd
				, sdw::HitAttributeT< sdw::Vec2 > attribs )
			{
				// Object data
				auto objResource = writer.declLocale( "objResource", objDescs[writer.cast< sdw::UInt >( in.instanceCustomIndex )] );
				auto indices = Indices( "indices", objResource.indexAddress );
				auto vertices = Vertices( "vertices", objResource.vertexAddress );

				// Indices of the triangle
				auto ind = writer.declLocale( "ind", indices[writer.cast< sdw::UInt >( in.primitiveID )] );

				// Vertex of the triangle
				auto v0 = writer.declLocale( "v0", vertices[writer.cast< sdw::UInt >( ind.x() )] );
				auto v1 = writer.declLocale( "v1", vertices[writer.cast< sdw::UInt >( ind.y() )] );
				auto v2 = writer.declLocale( "v2", vertices[writer.cast< sdw::UInt >( ind.z() )] );

				auto const barycentrics = writer.declLocale( "barycentrics"
					, vec3( 1.0_f - attribs.x() - attribs.y(), attribs.x(), attribs.y() ) );

				// Computing the coordinates of the hit position
				auto const pos = writer.declLocale( "pos", v0.pos * barycentrics.x() + v1.pos * barycentrics.y() + v2.pos * barycentrics.z() );
				auto const worldPos = writer.declLocale( "worldPos", in.objectToWorld * vec4( pos, 1.0 ) );  // Transforming the position to world space

				prd.color = worldPos;
			} );

		// Ray Miss shader
		writer.implementEntryPointT< HitPayload >( sdw::RayPayloadInT< HitPayload >{ writer, 0u }
			, [&]( sdw::RayMissIn in
				, sdw::RayPayloadInT< HitPayload > payload )
			{
				payload.color = clearColor.xyz() * 0.8_f;
			} );

		test::writeProgram( writer
			, testCounts, RayTraceCompilers );
		testEnd();
	}

	void taskMeshPipelineEXT( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "taskMeshPipelineEXT" );
		sdw::ModernGraphicsWriterEXT writer{ &testCounts.allocator };

		auto Globals = writer.declUniformBuffer( "bufferGlobals", 0u, 0u );
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

		auto getPrimitive = writer.implementFunction< sdw::UVec3 >( "getPrimitive"
			, [&]( Meshlet meshlet
				, sdw::UInt index )
			{
				auto primIndices = writer.declLocale( "primIndices", primitiveIndices[meshlet.primOffset + index].index );
				writer.returnStmt( uvec3( primIndices ) );
			}
			, sdw::InParam< Meshlet >{ writer, "meshlet" }
			, sdw::InUInt{ writer, "index" } );

		auto getVertexIndex = writer.implementFunction< sdw::UInt >( "getVertexIndex"
			, [&]( Meshlet meshlet
				, sdw::UInt localIndex )
			{
				localIndex = meshlet.vertOffset + localIndex;

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
			, sdw::InParam< Meshlet >{ writer, "meshlet" }
			, sdw::InUInt{ writer, "localIndex" } );

		auto getVertexAttributes = writer.implementFunction< MyVertexOut >( "getVertexAttributes"
			, [&]( sdw::UInt meshletIndex
				, sdw::UInt vertexIndex )
			{
				auto v = writer.declLocale( "v", vertices[vertexIndex] );

				auto vout = writer.declLocale< MyVertexOut >( "vout" );
				vout.positionVS = ( constants.worldView * vec4( v.position, 1.0f ) ).xyz();
				vout.positionHS = constants.worldViewProj * vec4( v.position, 1 );
				vout.normal = ( constants.world * vec4( v.normal, 0.0f ) ).xyz();
				vout.meshletIndex = meshletIndex;

				writer.returnStmt( vout );
			}
			, sdw::InUInt{ writer, "meshletIndex" }
			, sdw::InUInt{ writer, "vertexIndex" } );
			uint32_t constexpr CullFlag = 0x1u;

		auto isConeDegenerate = writer.implementFunction< sdw::Boolean >( "isConeDegenerate"
			, [&]( CullData c )
			{
				writer.returnStmt( ( c.normalCone >> 24u ) == 0xff_u );
			}
			, sdw::InParam< CullData >{ writer, "c" } );

		auto unpackCone = writer.implementFunction< sdw::Vec4 >( "unpackCone"
			, [&]( sdw::UInt packedCone )
			{
				auto v = writer.declLocale< sdw::Vec4 >( "v" );
				v.x() = writer.cast< sdw::Float >( ( packedCone >> 0u ) & 0xFF_u );
				v.y() = writer.cast< sdw::Float >( ( packedCone >> 8u ) & 0xFF_u );
				v.z() = writer.cast< sdw::Float >( ( packedCone >> 16u ) & 0xFF_u );
				v.w() = writer.cast< sdw::Float >( ( packedCone >> 24u ) & 0xFF_u );

				v = v / 255.0f;
				v.xyz() = v.xyz() * 2.0f - 1.0f;

				writer.returnStmt( v );
			}
			, sdw::InUInt{ writer, "packedCone" } );

		auto isVisible = writer.implementFunction< sdw::Boolean >( "isVisible"
			, [&]( CullData c
				, sdw::Mat4 world
				, sdw::Float scale
				, sdw::Vec3 viewPos )
			{
				IF( writer, ( instance.flags & CullFlag ) == 0_u )
				{
					writer.returnStmt( sdw::Boolean{ true } );
				}
				FI;

				// Do a cull test of the bounding sphere against the view frustum planes.
				auto center = writer.declLocale( "center", vec4( c.boundingSphere.xyz(), 1.0_f ) * world );
				auto radius = writer.declLocale( "radius", c.boundingSphere.w() * scale );

				for ( int i = 0; i < 6; ++i )
				{
					if ( dot( center, constants.planes[i] ) < -radius )
					{
						writer.returnStmt( sdw::Boolean{ false } );
					}
				}

				// Do normal cone culling
				IF( writer, isConeDegenerate( c ) )
				{
					writer.returnStmt( sdw::Boolean{ true } ); // Cone is degenerate - spread is wider than a hemisphere.
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
					writer.returnStmt( sdw::Boolean{ false } );
				}
				FI;

				// All tests passed - it will merit pixels
				writer.returnStmt( sdw::Boolean{ true } );
			}
			, sdw::InParam< CullData >{ writer, "c" }
			, sdw::InMat4{ writer, "world" }
			, sdw::InFloat{ writer, "scale" }
			, sdw::InVec3{ writer, "viewPos" } );

		// Task Shader
		writer.implementEntryPointT< PayloadT >( ThreadsPerWave, 1u, 1u
			, sdw::TaskPayloadOutEXTT< PayloadT >{ writer }
			, [&]( sdw::TaskSubgroupIn in
				, sdw::TaskPayloadOutEXTT< PayloadT > payload )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto baseId = writer.declLocale( "baseId", in.workGroupID );
				auto meshletId = writer.declLocale( "meshletId", ( baseId * 32u + laneId ) );
				auto visible = writer.declLocale( "visible"
					, isVisible( meshletCullData[meshletId]
						, instance.world
						, instance.scale
						, constants.cullViewPosition ) );
				auto vote = writer.declLocale( "vote", subgroupBallot( visible ) );
				auto tasks = writer.declLocale( "tasks", subgroupBallotBitCount( vote ) );
				auto idxOffset = writer.declLocale( "idxOffset", subgroupBallotExclusiveBitCount( vote ) );

				// Compact visible meshlets into the export payload array
				IF( writer, visible )
				{
					payload.meshletIndices[idxOffset] = meshletId;
				}
				FI;

				writer.dispatchMesh( tasks, 1_u, 1_u, payload );
			} );

		// Mesh Shader
		writer.implementEntryPointT< sdw::VoidT, MyVertexOutT, sdw::VoidT >( 32u, 1u, 1u
			, sdw::TaskPayloadInEXT{ writer }
			, sdw::MeshVertexListOutT< MyVertexOutT >{ writer, 252u }
			, sdw::TrianglesMeshEXTPrimitiveListOut{ writer, 84u }
			, [&]( sdw::MeshSubgroupIn in
				, sdw::TaskPayloadInEXT payload
				, sdw::MeshVertexListOutT< MyVertexOutT > vtxOut
				, sdw::TrianglesMeshEXTPrimitiveListOut primOut )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto baseId = writer.declLocale( "baseId", in.workGroupID );
				auto meshlet = writer.declLocale( "meshlet", meshlets[meshInfos.meshletOffset + baseId] );

				primOut.setMeshOutputCounts( meshlet.vertCount, meshlet.primCount );

				IF( writer, laneId < meshlet.primCount )
				{
					primOut[laneId].primitiveIndex = getPrimitive( meshlet, laneId );
				}
				FI;

				IF( writer, laneId < meshlet.vertCount )
				{
					auto vertexIndex = writer.declLocale( "vertexIndex", getVertexIndex( meshlet, laneId ) );
					auto vertex = writer.declLocale( "vertex", getVertexAttributes( laneId, vertexIndex ) );
					vtxOut[laneId].position = vertex.positionHS;
					vtxOut[laneId].positionHS = vertex.positionHS;
					vtxOut[laneId].positionVS = vertex.positionVS;
					vtxOut[laneId].normal = vertex.normal;
					vtxOut[laneId].meshletIndex = vertex.meshletIndex;
				}
				FI;
			} );

		// Fragment Shader
		writer.implementEntryPointT< MyVertexOutT, ColourT >( [&]( sdw::FragmentInT< MyVertexOutT > in
			, sdw::FragmentOutT< ColourT > out )
			{
				IF( writer, in.positionHS.x() < 0.0_f )
				{
					writer.demote();
				}
				FI;

				out.colour = vec4( in.normal, 1.0_f );
			} );

		test::writeProgram( writer
			, testCounts, MeshEXTCompilers );
		test::validateProgram( writer
			, testCounts, MeshEXTCompilers );
		testEnd();
	}

	void taskMeshPipelineNV( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "taskMeshPipelineNV" );
		sdw::ModernGraphicsWriterNV writer{ &testCounts.allocator };

		auto Globals = writer.declUniformBuffer( "bufferGlobals", 0u, 0u );
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

		auto unpackPrimitive = writer.implementFunction< sdw::UVec3 >( "unpackPrimitive"
			, [&]( sdw::UInt primitive )
			{
				// Unpacks a 10 bits per index triangle from a 32-bit uint.
				writer.returnStmt( uvec3( primitive & 0x3FF_u
					, ( primitive >> 10_u ) & 0x3FF_u
					, ( primitive >> 20_u ) & 0x3FF_u ) );
			}
			, sdw::InUInt{ writer, "primitive" } );

		auto getPrimitive = writer.implementFunction< sdw::UVec3 >( "getPrimitive"
			, [&]( Meshlet meshlet
				, sdw::UInt index )
			{
				writer.returnStmt( unpackPrimitive( primitiveIndices[meshlet.primOffset + index].index ) );
			}
			, sdw::InParam< Meshlet >{ writer, "meshlet" }
			, sdw::InUInt{ writer, "index" } );

		auto getVertexIndex = writer.implementFunction< sdw::UInt >( "getVertexIndex"
			, [&]( Meshlet meshlet
				, sdw::UInt localIndex )
			{
				localIndex = meshlet.vertOffset + localIndex;

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
			, sdw::InParam< Meshlet >{ writer, "meshlet" }
			, sdw::InUInt{ writer, "localIndex" } );

		auto getVertexAttributes = writer.implementFunction< MyVertexOut >( "getVertexAttributes"
			, [&]( sdw::UInt meshletIndex
				, sdw::UInt vertexIndex )
			{
				auto v = writer.declLocale( "v", vertices[vertexIndex] );

				auto vout = writer.declLocale< MyVertexOut >( "vout" );
				vout.positionVS = ( constants.worldView * vec4( v.position, 1.0f ) ).xyz();
				vout.positionHS = constants.worldViewProj * vec4( v.position, 1 );
				vout.normal = ( constants.world * vec4( v.normal, 0.0f ) ).xyz();
				vout.meshletIndex = meshletIndex;

				writer.returnStmt( vout );
			}
			, sdw::InUInt{ writer, "meshletIndex" }
			, sdw::InUInt{ writer, "vertexIndex" } );

		uint32_t constexpr CullFlag = 0x1u;

		auto isConeDegenerate = writer.implementFunction< sdw::Boolean >( "isConeDegenerate"
			, [&]( CullData c )
			{
				writer.returnStmt( ( c.normalCone >> 24u ) == 0xff_u );
			}
			, sdw::InParam< CullData >{ writer, "c" } );

		auto unpackCone = writer.implementFunction< sdw::Vec4 >( "unpackCone"
			, [&]( sdw::UInt packedCone )
			{
				auto v = writer.declLocale< sdw::Vec4 >( "v" );
				v.x() = writer.cast< sdw::Float >( ( packedCone >> 0u ) & 0xFF_u );
				v.y() = writer.cast< sdw::Float >( ( packedCone >> 8u ) & 0xFF_u );
				v.z() = writer.cast< sdw::Float >( ( packedCone >> 16u ) & 0xFF_u );
				v.w() = writer.cast< sdw::Float >( ( packedCone >> 24u ) & 0xFF_u );

				v = v / 255.0f;
				v.xyz() = v.xyz() * 2.0f - 1.0f;

				writer.returnStmt( v );
			}
			, sdw::InUInt{ writer, "packedCone" } );

		auto isVisible = writer.implementFunction< sdw::Boolean >( "isVisible"
			, [&]( CullData c
				, sdw::Mat4 world
				, sdw::Float scale
				, sdw::Vec3 viewPos )
			{
				IF( writer, ( instance.flags & CullFlag ) == 0_u )
				{
					writer.returnStmt( sdw::Boolean{ true } );
				}
				FI;

				// Do a cull test of the bounding sphere against the view frustum planes.
				auto center = writer.declLocale( "center", vec4( c.boundingSphere.xyz(), 1.0_f ) * world );
				auto radius = writer.declLocale( "radius", c.boundingSphere.w() * scale );

				for ( int i = 0; i < 6; ++i )
				{
					if ( dot( center, constants.planes[i] ) < -radius )
					{
						writer.returnStmt( sdw::Boolean{ false } );
					}
				}

				// Do normal cone culling
				IF( writer, isConeDegenerate( c ) )
				{
					writer.returnStmt( sdw::Boolean{ true } ); // Cone is degenerate - spread is wider than a hemisphere.
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
					writer.returnStmt( sdw::Boolean{ false } );
				}
				FI;

				// All tests passed - it will merit pixels
				writer.returnStmt( sdw::Boolean{ true } );
			}
			, sdw::InParam< CullData >{ writer, "c" }
			, sdw::InMat4{ writer, "world" }
			, sdw::InFloat{ writer, "scale" }
			, sdw::InVec3{ writer, "viewPos" } );

		// Task Shader
		writer.implementEntryPointT< PayloadT >( ThreadsPerWave
			, sdw::TaskPayloadOutNVT< PayloadT >{ writer }
			, [&]( sdw::TaskSubgroupIn in
				, sdw::TaskPayloadOutNVT< PayloadT > payload )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto baseId = writer.declLocale( "baseId", in.workGroupID );
				auto meshletId = writer.declLocale( "meshletId", ( baseId * 32u + laneId ) );
				auto visible = writer.declLocale( "visible"
					, isVisible( meshletCullData[meshletId]
						, instance.world
						, instance.scale
						, constants.cullViewPosition ) );
				auto vote = writer.declLocale( "vote", subgroupBallot( visible ) );
				auto tasks = writer.declLocale( "tasks", subgroupBallotBitCount( vote ) );
				auto idxOffset = writer.declLocale( "idxOffset", subgroupBallotExclusiveBitCount( vote ) );

				// Compact visible meshlets into the export payload array
				IF( writer, visible )
				{
					payload.meshletIndices[idxOffset] = meshletId;
				}
				FI;

				writer.dispatchMesh( tasks, payload );
			} );

		// Mesh Shader
		writer.implementEntryPointT< sdw::VoidT, MyVertexOutT, sdw::VoidT >( 32u
			, sdw::TaskPayloadInNV{ writer }
			, sdw::MeshVertexListOutT< MyVertexOutT >{ writer, 252u }
			, sdw::TrianglesMeshNVPrimitiveListOut{ writer, 84u }
			, [&]( sdw::MeshSubgroupIn in
				, sdw::TaskPayloadInNV payload
				, sdw::MeshVertexListOutT< MyVertexOutT > vtxOut
				, sdw::TrianglesMeshNVPrimitiveListOut primOut )
			{
				auto laneId = writer.declLocale( "laneId", in.localInvocationID );
				auto baseId = writer.declLocale( "baseId", in.workGroupID );
				auto meshlet = writer.declLocale( "meshlet", meshlets[meshInfos.meshletOffset + baseId] );

				primOut.setMeshOutputCounts( meshlet.vertCount, meshlet.primCount );

				IF( writer, laneId < meshlet.primCount )
				{
					primOut[laneId].primitiveIndex = getPrimitive( meshlet, laneId );
				}
				FI;

				IF( writer, laneId < meshlet.vertCount )
				{
					auto vertexIndex = writer.declLocale( "vertexIndex", getVertexIndex( meshlet, laneId ) );
					auto vertex = writer.declLocale( "vertex", getVertexAttributes( laneId, vertexIndex ) );
					vtxOut[laneId].position = vertex.positionHS;
					vtxOut[laneId].positionVS = vertex.positionVS;
					vtxOut[laneId].normal = vertex.normal;
					vtxOut[laneId].meshletIndex = vertex.meshletIndex;
				}
				FI;
			} );

		// Fragment Shader
		writer.implementEntryPointT< MyVertexOutT, ColourT >( [&]( sdw::FragmentInT< MyVertexOutT > in
			, sdw::FragmentOutT< ColourT > out )
			{
				IF( writer, in.positionHS.x() < 0.0_f )
				{
					writer.demote();
				}
				FI;

				out.colour = vec4( in.normal, 1.0_f );
			} );

		test::writeProgram( writer
			, testCounts, CurrentCompilers );
		test::validateProgram( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterProgram )
{
	sdwTestSuiteBegin();
	basicPipeline( testCounts );
	geometryPipeline( testCounts );
	tessellationPipeline( testCounts );
	rayTracePipeline( testCounts );
	taskMeshPipelineEXT( testCounts );
	taskMeshPipelineNV( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterProgram )
