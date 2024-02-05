#include "Common.hpp"
#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/IOStructHelper.hpp>
#include <ShaderWriter/CompositeTypes/IOStructInstanceHelper.hpp>
#include <ShaderWriter/CompositeTypes/PushConstantBuffer.hpp>

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	template< sdw::var::Flag FlagT >
	using ColourTStructT = sdw::IOStructInstanceHelperT< FlagT
		, "Colour"
		, sdw::IOVec4Field< "colour", 0u > >;
	template< sdw::var::Flag FlagT >
	using PosColStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PosCol"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec4Field< "position", 0u >
		, sdw::IOVec4Field< "colour", 1u > >;

	template< sdw::var::Flag FlagT >
	struct ColourT
		: public ColourTStructT< FlagT >
	{
		ColourT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: ColourTStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto colour()const
		{
			return this->template getMember< "colour" >();
		}
	};

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

		auto position()const
		{
			return this->template getMember< "position" >();
		}
		auto colour()const
		{
			return this->template getMember< "colour" >();
		}
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
	struct IOVoxelGeomT
		: sdw::StructInstance
	{
		IOVoxelGeomT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, texcoord{ getMember< sdw::Vec3 >( "texcoord" ) }
			, axis{ getMember< sdw::UInt >( "axis" ) }
			, aabb{ getMember< sdw::Vec4 >( "aabb" ) }
		{
		}

		SDW_DeclStructInstance( , IOVoxelGeomT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "VoxelGeom"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				uint32_t index = 0u;
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "axis"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray
					, index++ );
				result->declMember( "aabb"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, index++ );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "VoxelGeom" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "axis"
					, sdw::type::Kind::eUInt
					, sdw::type::NotArray );
				result->declMember( "aabb"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;
		sdw::Vec3 texcoord;
		sdw::UInt axis;
		sdw::Vec4 aabb;
	};

	template< sdw::var::Flag FlagT >
	struct VoxelIOT
		: sdw::StructInstance
	{
		VoxelIOT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec3 >( "position" ) }
			, normal{ getMember< sdw::Vec3 >( "normal" ) }
			, texcoord{ getMember< sdw::Vec3 >( "texcoord" ) }
		{
		}

		SDW_DeclStructInstance( , VoxelIOT );

		static sdw::type::IOStructPtr makeIOType( sdw::type::TypesCache & cache
			, ast::EntryPoint entryPoint )
		{
			auto result = cache.getIOStruct( "VoxelData"
				, entryPoint
				, FlagT );

			if ( result->empty() )
			{
				uint32_t index = 0u;
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray
					, index++ );
			}

			return result;
		}

		static sdw::type::BaseStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getStruct( sdw::type::MemoryLayout::eStd430
				, "VoxelData" );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "normal"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
				result->declMember( "texcoord"
					, sdw::type::Kind::eVec3F
					, sdw::type::NotArray );
			}

			return result;
		}

		sdw::Vec3 position;
		sdw::Vec3 normal;
		sdw::Vec3 texcoord;
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
	using PNTriPatchStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PNTriPatch"
		, sdw::type::MemoryLayout::eC
		, sdw::IOVec3Field< "wpB030", 0u >
		, sdw::IOVec3Field< "wpB021", 1u >
		, sdw::IOVec3Field< "wpB012", 2u >
		, sdw::IOVec3Field< "wpB003", 3u >
		, sdw::IOVec3Field< "wpB102", 4u >
		, sdw::IOVec3Field< "wpB201", 5u >
		, sdw::IOVec3Field< "wpB300", 6u >
		, sdw::IOVec3Field< "wpB210", 7u >
		, sdw::IOVec3Field< "wpB120", 8u >
		, sdw::IOVec3Field< "wpB111", 9u > >;

	template< sdw::var::Flag FlagT >
	using PosColNmlStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PosColNml"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec4Field< "position", 0u >
		, sdw::IOVec3Field< "normal", 2u >
		, sdw::IOVec4Field< "colour", 3u > >;
	template< sdw::var::Flag FlagT >
	struct PNTriPatchT
		: PNTriPatchStructT< FlagT >
	{
		PNTriPatchT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: PNTriPatchStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto wpB030()const { return this->template getMember< "wpB030" >(); }
		auto wpB021()const { return this->template getMember< "wpB021" >(); }
		auto wpB012()const { return this->template getMember< "wpB012" >(); }
		auto wpB003()const { return this->template getMember< "wpB003" >(); }
		auto wpB102()const { return this->template getMember< "wpB102" >(); }
		auto wpB201()const { return this->template getMember< "wpB201" >(); }
		auto wpB300()const { return this->template getMember< "wpB300" >(); }
		auto wpB210()const { return this->template getMember< "wpB210" >(); }
		auto wpB120()const { return this->template getMember< "wpB120" >(); }
		auto wpB111()const { return this->template getMember< "wpB111" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct PosColNmlT
		: PosColNmlStructT< FlagT >
	{
		PosColNmlT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: PosColNmlStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
		auto normal()const { return this->template getMember< "normal" >(); }
		auto colour()const { return this->template getMember< "colour" >(); }
	};

	void vtx_frag( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vtx_frag" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColT, PosColT >( [&]( VertexInT< PosColT > in
				, VertexOutT< PosColT > out )
				{
					out.colour() = in.colour();
					out.position() = in.position();
					out.vtx.position = in.position();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					IF( writer, in.position().x() < 0.0_f )
					{
						writer.demote();
					}
					FI;

					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void charles( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "charles" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			// Shader constants
			auto positions = writer.declConstantArray<Vec4>( "positions"
				, std::vector< Vec4 >
				{
					vec4( 0.0_f, -0.5f, 0.0f, 1.0f ),
					vec4( 0.5_f, 0.5f, 0.0f, 1.0f ),
					vec4( -0.5_f, 0.5f, 0.0f, 1.0f ),
				} );

			auto colors = writer.declConstantArray<Vec4>( "colors"
				, std::vector< Vec4 >
				{
					vec4( 1.0_f, 0.0f, 0.0f, 1.0f ),
					vec4( 0.0_f, 1.0f, 0.0f, 1.0f ),
					vec4( 0.0_f, 0.0f, 1.0f, 1.0f ),
				} );

			writer.implementMainT< PosColT, PosColT >( [&]( VertexInT< PosColT > in
				, VertexOutT< PosColT > out )
				{
					out.colour() = colors[in.vertexIndex];
					out.position() = positions[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					out.colour() = colors[0];
					out.position() = positions[0];
					out.vtx.position = positions[0];

					out.colour() = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.position() = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void charles_approx( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "charles_approx" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			// Shader constants
			auto positions = writer.declConstantArray<Vec4>( "positions"
				, std::vector< Vec4 >
			{
					vec4( 0.0_f, -0.5, 0.0, 1.0 ),
					vec4( 0.5_f, 0.5, 0.0, 1.0 ),
					vec4( -0.5_f, 0.5, 0.0, 1.0 ),
			} );

			auto colors = writer.declConstantArray<Vec4>( "colors"
				, std::vector< Vec4 >
			{
					vec4( 1.0_f, 0.0, 0.0, 1.0 ),
					vec4( 0.0_f, 1.0, 0.0, 1.0 ),
					vec4( 0.0_f, 0.0, 1.0, 1.0 ),
			} );

			writer.implementMainT< PosColT, PosColT >( [&]( VertexInT< PosColT > in
				, VertexOutT< PosColT > out )
				{
					out.colour() = colors[in.vertexIndex];
					out.position() = positions[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					out.colour() = colors[0];
					out.position() = positions[0];
					out.vtx.position = positions[0];

					out.colour() = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void charles_latest( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "charles_latest" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			// Shader constants
			auto positions = writer.declConstantArray<Vec2>(
				"positions",
				std::vector<Vec2>{
					vec2( -1.0_f, -1.0_f ), vec2( 0.0_f, -1.0_f ), vec2( 1.0_f, -1.0_f ),
					vec2( -1.0_f, 0.0_f ), vec2( 0.0_f, 0.0_f ), vec2( 1.0_f, 0.0_f ),
					vec2( -1.0_f, 1.0_f ), vec2( 0.0_f, 1.0_f ), vec2( 1.0_f, 1.0_f ) } );

			auto colors = writer.declConstantArray<Vec3>(
				"colors", std::vector<Vec3>{
					vec3( 1.0_f, 0.0_f, 0.0_f ), vec3( 1.0_f, 1.0_f, 1.0_f ),
					vec3( 0.0_f, 0.0_f, 1.0_f ), vec3( 1.0_f, 0.0_f, 0.0_f ),
					vec3( 0.0_f, 1.0_f, 0.0_f ), vec3( 0.0_f, 0.0_f, 1.0_f ),
					vec3( 0.0_f, 0.0_f, 0.0_f ), vec3( 0.0_f, 0.0_f, 0.0_f ),
					vec3( 0.0_f, 0.0_f, 0.0_f ) } );

			auto indices = writer.declConstantArray<Int>(
				"indices", std::vector<Int>{
					0_i, 1_i, 6_i, 6_i, 1_i, 7_i,
					1_i, 2_i, 7_i, 7_i, 2_i, 8_i } );

			writer.implementMainT< PosColT, PosColT >( [&]( VertexInT< PosColT > in
				, VertexOutT< PosColT > out )
				{
					out.position() =
						vec4( positions[indices[in.vertexIndex]], 0.0_f, 1.0_f );
					out.vtx.position =
						vec4( positions[indices[in.vertexIndex]], 0.0_f, 1.0_f );
					out.colour() = vec4( colors[indices[in.vertexIndex]], 1.0_f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void drawID( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "drawID" );
		using namespace sdw;

		ShaderArray shaders;
		{
			{
				sdw::VertexWriter writer{ &testCounts.allocator };
				auto drawID = writer.declOutput<UInt>( "drawID", 0 );
				writer.implementMain( [&]( sdw::VertexIn in, sdw::VertexOut out )
					{
						drawID = writer.cast<UInt>( in.drawID );
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
				shaders.emplace_back( std::move( writer.getShader() ) );
			}
			{
				sdw::FragmentWriter writer{ &testCounts.allocator };
				auto drawID = writer.declInput<UInt>( "drawID", 0 );
				auto fragOutput = writer.declOutput<UInt>( "fragOutput", 0 );
				writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						fragOutput = drawID;
					} );
				test::writeShader( writer
					, testCounts, CurrentCompilers );
				shaders.emplace_back( std::move( writer.getShader() ) );
			}
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void charles_drawID( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "charles_drawID" );
		using namespace sdw;

		ShaderArray shaders;
		{
			{
				sdw::VertexWriter writer{ &testCounts.allocator };

				auto pos = writer.declInput<Vec2>( "pos", 0 );
				auto uvs = writer.declInput<Vec2>( "uvs", 1 );
				auto col = writer.declInput<Vec4>( "col", 2 );

				auto fragUv = writer.declOutput<Vec2>( "fragUv", 0 );
				auto fragCol = writer.declOutput<Vec4>( "fragCol", 1 );

				ArrayStorageBufferT< Mat4 > ssbo{ writer, "ssbo", Mat4::makeType( writer.getTypesCache() ), ast::type::MemoryLayout::eStd430, 1, 0, true };

				PushConstantBuffer pcb = writer.declPushConstantsBuffer( "pcb" );
				pcb.declMember<Int>( "firstMatrix" );
				pcb.end();

				writer.implementMain(
					[&]( sdw::VertexIn in, sdw::VertexOut out )
					{
						auto matrix = ssbo[writer.cast<UInt>( in.drawID + pcb.getMember<Int>( "firstMatrix" ) )];
						out.vtx.position =
							matrix * vec4( pos.x(), pos.y(), 0.0_f, 1.0_f );
						fragUv = uvs;
						fragCol = col;
					} );
				test::writeShader( writer
					, testCounts
					, CurrentCompilers );
				shaders.emplace_back( std::move( writer.getShader() ) );
			}
			{
				using TextureType =
					sdw::CombinedImageT<ast::type::ImageFormat::eR32f,
					ast::type::ImageDim::e2D, false, false, false>;

				sdw::FragmentWriter writer{ &testCounts.allocator };

				auto fragUv = writer.declInput<Vec2>( "fragUv", 0 );
				auto fragCol = writer.declInput<Vec4>( "fragCol", 1 );

				auto color = writer.declOutput<Vec4>( "color", 0 );

				TextureType fontTexture =
					writer.declCombinedImg<TextureType>( "fontTexture", 0, 0 );

				writer.implementMain(
					[&]( sdw::FragmentIn in, sdw::FragmentOut out )
					{
						auto i = writer.declLocale( "i", fontTexture.sample(fragUv));
						auto s = writer.declLocale( "s", writer.cast<Float>(i) / 255.0_f);

						color = vec4( fragCol.r(), fragCol.g(), fragCol.b(),
							fragCol.a() * s );
					} );
				test::writeShader( writer
					, testCounts
					, CurrentCompilers );
				shaders.emplace_back( std::move( writer.getShader() ) );
			}
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void arthapzMin( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arthapzMin" );
		sdw::ShaderArray shaders;
		{
			auto writer = sdw::VertexWriter{ &testCounts.allocator };

			writer.implementMainT< PosNmlTexTanT, PosNmlTexTanT >( [&]( sdw::VertexInT< PosNmlTexTanT > in
				, sdw::VertexOutT< PosNmlTexTanT > out )
				{
					using namespace sdw;

					out.texcoord = in.texcoord;
					out.normal = in.normal;
					out.position = in.position;
					out.tangent = in.tangent;
					out.vtx.position = vec4( in.position, 1.f );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			auto writer = sdw::FragmentWriter{ &testCounts.allocator };
			auto base_color_sampler = writer.declCombinedImg< FImg2DRgba32 >( "base_color_sampler", 0, 2 );

			auto getEmissiveColor = writer.implementFunction< sdw::Vec4 >( "getEmissiveColor"
				, [&]()
				{
					writer.returnStmt( sdw::vec4( 0._f, 0.f, 0.f, 0.f ) );
				} );

			writer.implementMainT< PosNmlTexTanT, ColourT >( [&]( sdw::FragmentInT< PosNmlTexTanT > in
				, sdw::FragmentOutT< ColourT > out )
				{
					out.colour() = base_color_sampler.sample( in.texcoord ) + getEmissiveColor();
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void arthapz( test::sdw_test::TestCounts & testCounts
		, bool hasEmissiveMap
		, bool hasNormalMap )
	{
		testBegin( "arthapz"
			+ std::to_string( hasEmissiveMap )
			+ std::to_string( hasNormalMap ) );
		sdw::ShaderArray shaders;
		{
			auto writer = sdw::VertexWriter{ &testCounts.allocator };

			auto camera = sdw::UniformBuffer{ writer, "camera", 0, 0 };
			camera.declMember<sdw::Vec4>( "camera_position" );
			camera.declMember<sdw::Mat4>( "camera_projection" );
			camera.declMember<sdw::Mat4>( "camera_view" );
			camera.end();

			auto transform = sdw::UniformBuffer{ writer, "transform", 1, 0 };
			transform.declMember<sdw::Mat4>( "transform_model" );
			transform.declMember<sdw::Mat4>( "transform_inverted_model" );
			transform.end();

			writer.implementMainT< PosNmlTexTanT, PosNmlTexTanT >( [&]( sdw::VertexInT< PosNmlTexTanT > in
				, sdw::VertexOutT< PosNmlTexTanT > out )
				{
					using namespace sdw;

					auto model_space_position =
						writer.declLocale( "model_space_position",
							transform.getMember<Mat4>( "transform_model" ) * vec4( in.position, 1.f ) );

					out.position = model_space_position.xyz() / model_space_position.w();
					out.normal = normalize(
						transpose( mat3( transform.getMember<Mat4>( "transform_inverted_model" ) ) ) * in.normal );
					out.texcoord = in.texcoord;
					out.tangent = in.tangent;

					out.vtx.position = camera.getMember<Mat4>( "camera_projection" ) *
						camera.getMember<Mat4>( "camera_view" ) * vec4( out.position, 1.f ); // TODO: Disable output as RHS ?
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			auto writer = sdw::FragmentWriter{ &testCounts.allocator };

			auto camera = sdw::UniformBuffer{ writer, "camera", 0, 0 };
			camera.declMember<sdw::Vec4>( "position" );
			camera.declMember<sdw::Mat4>( "projection" );
			camera.declMember<sdw::Mat4>( "view" );
			camera.end();

			auto material = sdw::PushConstantBuffer{ writer, "material", ast::type::MemoryLayout::eStd140 };
			material.declMember<sdw::Vec4>( "base_color_factor" );
			material.declMember<sdw::Vec4>( "emissive_factor" );
			material.declMember<sdw::Float>( "metallic_factor" );
			material.declMember<sdw::Float>( "roughness_factor" );
			material.declMember<sdw::Float>( "ambiant_occlusion_factor" );
			material.declMember<sdw::Float>( "PAD0" );
			material.end();

			auto base_color_sampler = writer.declCombinedImg<FImg2DRgba32>( "base_color_sampler", 0, 2 );
			auto normal_sampler = writer.declCombinedImg<FImg2DRgba32>( "normal_sampler", 1, 2 );
			auto metallic_roughness_sampler =
				writer.declCombinedImg<FImg2DRgba32>( "metallic_roughness_sampler", 2, 2 );
			auto ambiant_occlusion_sampler =
				writer.declCombinedImg<FImg2DRgba32>( "ambiant_occlusion_sampler", 3, 2 );
			auto emissive_sampler = writer.declCombinedImg<FImg2DRgba32>( "emissive_sampler", 4, 2 );

			auto getEmissiveColor = writer.implementFunction<sdw::Vec4>( "getEmissiveColor"
				, [&]( sdw::Vec2 const & texcoord )
				{
					if ( hasEmissiveMap )
						writer.returnStmt( emissive_sampler.sample( texcoord ) *
							material.getMember<sdw::Vec4>( "emissive_factor" ) );
					else
						writer.returnStmt( sdw::vec4( 0._f, 0.f, 0.f, 0.f ) );
				}
				, sdw::InVec2{ writer, "texcoord" } );

			auto getNormal = writer.implementFunction<sdw::Vec3>( "getNormal"
				, [&]( sdw::Vec3 const & normal
					, sdw::Vec2 const & texcoord
					, sdw::Vec4 const & tangent )
				{
					if ( hasNormalMap )
					{
						auto tangent_normal =
							writer.declLocale( "tangent_normal",
								normal_sampler.sample( texcoord ).xyz() * 2.f - 1.f );

						auto N = writer.declLocale( "N", sdw::normalize( normal ) );
						auto T = writer.declLocale( "T", sdw::normalize( tangent.xyz() ) );
						auto B = writer.declLocale( "B", -sdw::normalize( sdw::cross( N, T ) ) );

						auto TBN = writer.declLocale<sdw::Mat3>( "TBN", sdw::mat3( T, B, N ) );

						writer.returnStmt( sdw::normalize( TBN * tangent_normal ) );
					}
					else
						writer.returnStmt( normal );
				}
				, sdw::InVec3{ writer, "normal" }
				, sdw::InVec2{ writer, "texcoord" }
				, sdw::InVec4{ writer, "tangent" } );

			writer.implementMainT< PosNmlTexTanT, ColourT >( [&]( sdw::FragmentInT< PosNmlTexTanT > in
				, sdw::FragmentOutT< ColourT > out )
				{
					auto N = writer.declLocale<sdw::Vec3>( "N"
						, sdw::normalize( getNormal( in.normal, in.texcoord, in.tangent ) ) );
					auto V = writer.declLocale<sdw::Vec3>( "V",
						camera.getMember<sdw::Vec4>( "position" ).xyz() -
						in.position );

					out.colour() = base_color_sampler.sample( in.texcoord ) + getEmissiveColor( in.texcoord );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void clipDistance( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "clipDistance" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			auto cfg = writer.declUniformBuffer( "Config", 0u, 0u );
			auto mvps = cfg.declMember< sdw::Mat4 >( "mvps", 6u );
			auto tiles = cfg.declMember< sdw::Vec4 >( "tiles" );
			auto instances = cfg.declMember< sdw::UVec4 >( "instances", 6u );
			cfg.end();

			writer.implementMainT< PositionT, PositionT >( [&]( sdw::VertexInT< PositionT > in
				, sdw::VertexOutT< PositionT > out )
				{
					auto tileIndex = writer.declLocale( "tileIndex"
						, instances[in.instanceIndex / 4][in.instanceIndex % 4] );
					auto tileMin = writer.declLocale( "tileMin"
						, ( ( tiles.zw() * 2.0_f - 1.0_f )
							* vec2( writer.cast< Float >( tileIndex % writer.cast< UInt >( tiles.x() ) )
								, writer.cast< Float >( tileIndex / writer.cast< UInt >( tiles.x() ) ) ) ) );
					auto tileMax = writer.declLocale( "tileMax"
						, tileMin + tiles.zw() * 2.0_f );

					auto p = writer.declLocale( "p"
						, mvps[tileIndex] * in.position );
					out.vtx.position = p;

					out.vtx.clipDistance[0] = dot( vec4( 1.0_f, 0.0_f, 0.0_f, -tileMin.x() ), p );
					out.vtx.clipDistance[1] = dot( vec4( -1.0_f, 0.0_f, 0.0_f, tileMax.x() ), p );
					out.vtx.clipDistance[2] = dot( vec4( 0.0_f, -1.0_f, 0.0_f, -tileMin.y() ), p );
					out.vtx.clipDistance[3] = dot( vec4( 0.0_f, 1.0_f, 0.0_f, tileMax.y() ), p );
					out.vtx.clipDistance[4] = 0.0_f;
					out.vtx.clipDistance[5] = 0.0_f;
					out.vtx.clipDistance[6] = 0.0_f;
					out.vtx.clipDistance[7] = 0.0_f;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, ColourT >( [&]( sdw::FragmentInT< PositionT > in
				, sdw::FragmentOutT< ColourT > out )
				{
					out.colour() = vec4( 1.0_f, 0.0f, 1.0f, 0.0f );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void basicPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "basicPipeline" );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer myUbo{ writer, "MyUbo", 0u, 0u };
			auto mvp = myUbo.declMember< sdw::Mat4 >( "mvp" );
			myUbo.end();

			writer.implementMainT< PosColT, ColourT >( [&]( VertexInT< PosColT > const & in
				, VertexOutT< ColourT > out )
				{
					out.colour() = in.colour();
					out.vtx.position = mvp * in.position();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< ColourT, ColourT >( [&]( FragmentInT< ColourT > const & in
				, FragmentOutT< ColourT > out )
				{
					out.colour() = in.colour();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void geometryPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "geometryPipeline" );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, PositionT >( [&]( VertexInT< PositionT > in
				, VertexOutT< PositionT > out )
				{
					out.position = in.position;
					out.vtx.position = out.position;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };

			UniformBuffer voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto mvp = voxelizeUbo.declMember< Mat4 >( "mvp" );
			voxelizeUbo.end();

			using MyTriangleList = TriangleListT< PositionT >;
			using MyTriangleStream = TriangleStreamT< PositionT >;

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, MyTriangleStream out )
				{
					auto pos = writer.declLocale< Vec4 >( "pos" );

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
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< PositionT, ColourT >( [&]( FragmentInT< PositionT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour() = in.position;
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void voxelPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "voxelPipeline" );
		using namespace sdw;
		sdw::ShaderArray shaders;

		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< VoxelIOT, VoxelIOT >( [&]( VertexInT< VoxelIOT > in
				, sdw::VertexOutT< VoxelIOT > out )
				{
					out.position = in.position;
					out.normal = in.normal.xyz();
					out.texcoord = in.texcoord.xyz();
					out.vtx.position = vec4( in.position, 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			using MyTriangleList = sdw::TriangleListT< VoxelIOT >;
			using MyTriangleStream = sdw::TriangleStreamT< IOVoxelGeomT >;

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&]( GeometryIn in
				, MyTriangleList list
				, MyTriangleStream out )
				{
					auto faceNormal = writer.declLocale( "faceNormal"
						, normalize( cross( list[1].position - list[0].position, list[2].position - list[0].position ) ) );
					auto NdotXAxis = writer.declLocale( "NdotXAxis"
						, abs( faceNormal.x() ) );
					auto NdotYAxis = writer.declLocale( "NdotYAxis"
						, abs( faceNormal.y() ) );
					auto NdotZAxis = writer.declLocale( "NdotZAxis"
						, abs( faceNormal.z() ) );
					auto proj = writer.declLocale< Mat4 >( "proj" );
					auto curPosition = writer.declLocaleArray( "curPosition"
						, 3u
						, std::vector< sdw::Vec4 >
					{
						list[0].vtx.position,
							list[1].vtx.position,
							list[2].vtx.position,
					} );
					auto axis = writer.declLocale( "axis", 0_u );

					//Find the axis the maximize the projected area of this triangle
					IF( writer, NdotXAxis > NdotYAxis && NdotXAxis > NdotZAxis )
					{
						proj = c3d_vpX;
						axis = 1_u;
					}
					ELSEIF( NdotYAxis > NdotXAxis && NdotYAxis > NdotZAxis )
					{
						proj = c3d_vpY;
						axis = 2_u;
					}
					ELSE
					{
						proj = c3d_vpZ;
					axis = 3_u;
					}
					FI;

					auto pos = writer.declLocaleArray< Vec4 >( "pos", 3u );

					//transform vertices to clip space
					pos[0] = proj * curPosition[0];
					pos[1] = proj * curPosition[1];
					pos[2] = proj * curPosition[2];

					//Next we enlarge the triangle to enable conservative rasterization
					auto aabb = writer.declLocale< Vec4 >( "aabb" );
					auto hPixel = writer.declLocale< Vec2 >( "hPixel"
						, vec2( 1.0_f ) / c3d_size );
					auto pl = writer.declLocale< Float >( "pl"
						, 1.4142135637309_f / c3d_size.x() );

					//calculate AABB of this triangle
					aabb.xy() = pos[0].xy();
					aabb.zw() = pos[0].xy();

					aabb.xy() = min( pos[1].xy(), aabb.xy() );
					aabb.zw() = max( pos[1].xy(), aabb.zw() );

					aabb.xy() = min( pos[2].xy(), aabb.xy() );
					aabb.zw() = max( pos[2].xy(), aabb.zw() );

					//Enlarge half-pixel
					aabb.xy() -= hPixel;
					aabb.zw() += hPixel;

					//find 3 triangle edge plane
					auto e0 = writer.declLocale( "e0"
						, vec3( pos[1].xy() - pos[0].xy(), 0 ) );
					auto e1 = writer.declLocale( "e1"
						, vec3( pos[2].xy() - pos[1].xy(), 0 ) );
					auto e2 = writer.declLocale( "e2"
						, vec3( pos[0].xy() - pos[2].xy(), 0 ) );
					auto n0 = writer.declLocale( "n0"
						, cross( e0, vec3( 0.0_f, 0, 1 ) ) );
					auto n1 = writer.declLocale( "n1"
						, cross( e1, vec3( 0.0_f, 0, 1 ) ) );
					auto n2 = writer.declLocale( "n2"
						, cross( e2, vec3( 0.0_f, 0, 1 ) ) );

					//dilate the triangle
					pos[0].xy() = pos[0].xy() + pl * ( ( e2.xy() / dot( e2.xy(), n0.xy() ) ) + ( e0.xy() / dot( e0.xy(), n2.xy() ) ) );
					pos[1].xy() = pos[1].xy() + pl * ( ( e0.xy() / dot( e0.xy(), n1.xy() ) ) + ( e1.xy() / dot( e1.xy(), n0.xy() ) ) );
					pos[2].xy() = pos[2].xy() + pl * ( ( e1.xy() / dot( e1.xy(), n2.xy() ) ) + ( e2.xy() / dot( e2.xy(), n1.xy() ) ) );

					out.vtx.position = pos[0];
					out.position = pos[0].xyz();
					out.normal = list[0].normal;
					out.texcoord = list[0].texcoord;
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.vtx.position = pos[1];
					out.position = pos[1].xyz();
					out.normal = list[1].normal;
					out.texcoord = list[1].texcoord;
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.vtx.position = pos[2];
					out.position = pos[2].xyz();
					out.normal = list[2].normal;
					out.texcoord = list[2].texcoord;
					out.axis = axis;
					out.aabb = aabb;
					out.append();

					out.restartStrip();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			auto pxl_voxelVisibility = writer.declStorageImg< WUImg3DR8 >( "pxl_voxelVisibility", 1u, 1u );

			sdw::UniformBuffer voxelizeUbo{ writer, "VoxelizeUbo", 0u, 0u };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			writer.implementMainT< IOVoxelGeomT, ColourT >( [&]( FragmentInT< IOVoxelGeomT > in
				, FragmentOutT< ColourT > out )
				{
					IF( writer
						, in.position.x() < in.aabb.x()
						|| in.position.y() < in.aabb.y()
						|| in.position.x() > in.aabb.z()
						|| in.position.y() > in.aabb.w() )
					{
						writer.terminate();
					}
					FI;

					auto width = writer.declLocale( "width"
						, writer.cast< Int >( c3d_size.x() ) );
					auto temp = writer.declLocale( "temp"
						, ivec3( writer.cast< Int >( in.fragCoord.x() )
							, writer.cast< Int >( in.fragCoord.y() )
							, width * writer.cast< Int >( in.fragCoord.z() ) ) );
					auto texcoord = writer.declLocale< IVec3 >( "texcoord" );

					IF( writer, in.axis == 1_u )
					{
						texcoord.x() = width - temp.z();
						texcoord.z() = temp.x();
						texcoord.y() = temp.y();
					}
					ELSEIF( in.axis == 2_u )
					{
						texcoord.z() = temp.y();
						texcoord.y() = width - temp.z();
						texcoord.x() = temp.x();
					}
					ELSE
					{
						texcoord = temp;
					}
					FI;

					pxl_voxelVisibility.store( texcoord, 1_u );
					out.colour() = vec4( vec3( texcoord ), 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		testEnd();
	}

	void tessellationPipeline( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "tessellationPipeline" );
		using namespace sdw;
		static uint32_t constexpr maxPoints = 3u;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColNmlT, PosColNmlT >( [&]( VertexInT< PosColNmlT > in
				, sdw::VertexOutT< PosColNmlT > out )
				{
					out.position() = in.position();
					out.normal() = in.normal();
					out.colour() = in.colour();
					out.vtx.position = in.position();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::TessellationControlWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer ubo{ writer, "Wow", 0u, 0u };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			auto c3d_mapNormal = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapNormal", 1u, 0u );

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

			writer.implementPatchRoutineT< PosColNmlT, maxPoints, PNTriPatchT >( 6u
				, [&]( TessControlPatchRoutineIn in
					, TessControlListInT< PosColNmlT, maxPoints > listIn
					, TrianglesTessPatchOutT< PNTriPatchT > patchOut )
				{
				// The original vertices stay the same
					patchOut.wpB030() = listIn[0].position().xyz();
					patchOut.wpB003() = listIn[1].position().xyz();
					patchOut.wpB300() = listIn[2].position().xyz();

					// Edges are names according to the opposing vertex
					auto edgeB300 = writer.declLocale( "edgeB300"
						, patchOut.wpB003() - patchOut.wpB030() );
					auto edgeB030 = writer.declLocale( "edgeB030"
						, patchOut.wpB300() - patchOut.wpB003() );
					auto edgeB003 = writer.declLocale( "edgeB003"
						, patchOut.wpB030() - patchOut.wpB300() );

					// Generate two midpoints on each edge
					patchOut.wpB021() = patchOut.wpB030() + edgeB300 / 3.0f;
					patchOut.wpB012() = patchOut.wpB030() + edgeB300 * 2.0f / 3.0f;
					patchOut.wpB102() = patchOut.wpB003() + edgeB030 / 3.0f;
					patchOut.wpB201() = patchOut.wpB003() + edgeB030 * 2.0f / 3.0f;
					patchOut.wpB210() = patchOut.wpB300() + edgeB003 / 3.0f;
					patchOut.wpB120() = patchOut.wpB300() + edgeB003 * 2.0f / 3.0f;

					// Project each midpoint on the plane defined by the nearest vertex and its normal
					patchOut.wpB021() = projectToPlane( patchOut.wpB021()
						, patchOut.wpB030()
						, listIn[0].normal() );
					patchOut.wpB012() = projectToPlane( patchOut.wpB012()
						, patchOut.wpB003()
						, listIn[1].normal() );
					patchOut.wpB102() = projectToPlane( patchOut.wpB102()
						, patchOut.wpB003()
						, listIn[1].normal() );
					patchOut.wpB201() = projectToPlane( patchOut.wpB201()
						, patchOut.wpB300()
						, listIn[2].normal() );
					patchOut.wpB210() = projectToPlane( patchOut.wpB210()
						, patchOut.wpB300()
						, listIn[2].normal() );
					patchOut.wpB120() = projectToPlane( patchOut.wpB120()
						, patchOut.wpB030()
						, listIn[0].normal() );

					// Handle the center
					auto center = writer.declLocale( "center"
						, ( patchOut.wpB003()
							+ patchOut.wpB030()
							+ patchOut.wpB300() ) / 3.0f );
					patchOut.wpB111() = ( patchOut.wpB021()
						+ patchOut.wpB012()
						+ patchOut.wpB102()
						+ patchOut.wpB201()
						+ patchOut.wpB210()
						+ patchOut.wpB120() ) / 6.0f;
					patchOut.wpB111() += ( patchOut.wpB111() - center ) / 2.0f;

					// Calculate the distance from the camera to the three control points
					auto eyeToVertexDistance0 = writer.declLocale( "eyeToVertexDistance0"
						, distance( pos, listIn[0].position().xyz() ) );
					auto eyeToVertexDistance1 = writer.declLocale( "eyeToVertexDistance1"
						, distance( pos, listIn[1].position().xyz() ) );
					auto eyeToVertexDistance2 = writer.declLocale( "eyeToVertexDistance2"
						, distance( pos, listIn[2].position().xyz() ) );

					// Calculate the tessellation levels
					patchOut.tessLevelOuter[0] = getTessLevel( eyeToVertexDistance1, eyeToVertexDistance2 );
					patchOut.tessLevelOuter[1] = getTessLevel( eyeToVertexDistance2, eyeToVertexDistance0 );
					patchOut.tessLevelOuter[2] = getTessLevel( eyeToVertexDistance0, eyeToVertexDistance1 );
					patchOut.tessLevelInner[0] = patchOut.tessLevelOuter[2];
				} );

			writer.implementMainT< PosColNmlT, maxPoints, ColourT >( ast::type::Partitioning::eEqual
				, ast::type::OutputTopology::ePoint
				, ast::type::PrimitiveOrdering::eCCW
				, 3u
				, [&]( TessControlMainIn in
					, TessControlListInT< PosColNmlT, maxPoints > listIn
					, TrianglesTessControlListOutT< ColourT > listOut )
				{
					listOut.colour() = listIn[in.invocationID].colour();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
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

			auto interpolate4D = writer.implementFunction< Vec4 >( "interpolate4D"
				, [&]( Vec3 const & tessCoord
					, Vec4 const & v0
					, Vec4 const & v1
					, Vec4 const & v2 )
				{
					writer.returnStmt( vec4( tessCoord.x() ) * v0
						+ vec4( tessCoord.y() ) * v1
						+ vec4( tessCoord.z() ) * v2 );
				}
				, InVec3{ writer, "tessCoord" }
				, InVec4{ writer, "v0" }
				, InVec4{ writer, "v1" }
				, InVec4{ writer, "v2" } );

			writer.implementMainT< ColourT, maxPoints, PNTriPatchT, ColourT >( 6u
				, type::Partitioning::eEqual
				, type::PrimitiveOrdering::eCCW
				, [&]( TessEvalMainIn mainIn
					, TessEvalListInT< ColourT, maxPoints > listIn
					, TrianglesTessPatchInT< PNTriPatchT > patchIn
					, TessEvalDataOutT< ColourT > out )
				{
					// Interpolate the attributes of the output vertex using the barycentric coordinates
					out.colour() = interpolate4D( patchIn.tessCoord
						, listIn[0].colour()
						, listIn[1].colour()
						, listIn[2].colour() );

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

					auto pos = writer.declLocale( "pos"
						, patchIn.wpB300() * wPow3
							+ patchIn.wpB030() * uPow3
							+ patchIn.wpB003() * vPow3
							+ patchIn.wpB210() * 3.0f * wPow2 * u
							+ patchIn.wpB120() * 3.0f * w * uPow2
							+ patchIn.wpB201() * 3.0f * wPow2 * v
							+ patchIn.wpB021() * 3.0f * uPow2 * v
							+ patchIn.wpB102() * 3.0f * w * vPow2
							+ patchIn.wpB012() * 3.0f * u * vPow2
							+ patchIn.wpB111() * 6.0f * w * u * v );

					out.vtx.position = mtx * vec4( pos, 1.0f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< ColourT, ColourT >( [&]( FragmentInT< ColourT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour() = in.colour();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}

	void arraySsboTextureLookup( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arraySsboTextureLookup" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto fragUvw = writer.declInput< Vec3 >( "fragUvw", 0u );
			auto outColor = writer.declOutput< Vec4 >( "outColor", 0u );

			sdw::StorageBuffer colorsSsbo = writer.declStorageBuffer( "colorsBuffer", 0u, 1u );
			auto colors = colorsSsbo.declMemberArray< Vec4 >( "colors" );
			colorsSsbo.end();

			auto volumeTexture = writer.declCombinedImg< UCombinedImage3DR32 >( "volumeTexture", 1u, 1u );

			writer.implementMain(
				[&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					outColor = colors[volumeTexture.sample( fragUvw )];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void pcbHelper( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "pcbHelper" );
		using namespace sdw;
		{
			using PcbParent = sdw::PushConstantBufferHelperT< sdw::type::MemoryLayout::eC
				, sdw::Vec4Field< "color" > >;
			class Pcb : public PcbParent
			{
			public:
				using PcbParent::PcbParent;

				auto color() {
					return getMember<"color">();
				}
			};

			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto color = writer.declOutput< Vec4 >( "color", 0u );

			Pcb pcb{ writer, "pcb" };

			writer.implementMain( [&]( sdw::FragmentIn in, sdw::FragmentOut out )
				{
					color = pcb.color();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		testEnd();
	}

	void radianceComputer( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "radianceComputer" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			// Inputs
			auto position = writer.declInput< Vec3 >( "position", 0u );
			UniformBuffer matrix{ writer, "Matrix", 0u, 0u };
			auto c3d_viewProjection = matrix.declMember< Mat4 >( "c3d_viewProjection" );
			matrix.end();

			// Outputs
			auto vtx_worldPosition = writer.declOutput< Vec3 >( "vtx_worldPosition", 0u );

			writer.implementMainT< VoidT, VoidT >( [&]( VertexIn in
				, VertexOut out )
				{
					vtx_worldPosition = position;
					out.vtx.position = ( c3d_viewProjection * vec4( position, 1.0_f ) ).xyww();
				} );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			// Inputs
			auto vtx_worldPosition = writer.declInput< Vec3 >( "vtx_worldPosition", 0u );
			auto c3d_mapEnvironment = writer.declCombinedImg< FImgCubeRgba32 >( "c3d_mapEnvironment", 1u, 0u );

			// Outputs
			auto outColour = writer.declOutput< Vec4 >( "outColour", 0u );

			writer.implementMainT< VoidT, VoidT >( [&]( FragmentIn in
				, FragmentOut out )
				{
					// From https://learnopengl.com/#!PBR/Lighting
					// the sample direction equals the hemisphere's orientation 
					auto normal = writer.declLocale( "normal"
						, normalize( vtx_worldPosition ) );

					auto irradiance = writer.declLocale( "irradiance"
						, vec3( 0.0_f ) );

					auto up = writer.declLocale( "up"
						, vec3( 0.0_f, 1.0_f, 0.0_f ) );
					auto right = writer.declLocale( "right"
						, cross( up, normal ) );
					up = cross( normal, right );

					auto sampleDelta = writer.declLocale( "sampleDelta"
						, 0.025_f );
					auto nrSamples = writer.declLocale( "nrSamples"
						, 0_i );

					FOR( writer, Float, phi, 0.0_f, phi < 6.253184_f, phi += sampleDelta )
					{
						FOR( writer, Float, theta, 0.0_f, theta < 1.570796_f, theta += sampleDelta )
						{
							// spherical to cartesian (in tangent space)
							auto tangentSample = writer.declLocale( "tangentSample"
								, vec3( sin( theta ) * cos( phi ), sin( theta ) * sin( phi ), cos( theta ) ) );
							// tangent space to world
							auto sampleVec = writer.declLocale( "sampleVec"
								, right * tangentSample.x() + up * tangentSample.y() + normal * tangentSample.z() );

							irradiance += c3d_mapEnvironment.lod( sampleVec, 0.0_f ).rgb() * cos( theta ) * sin( theta );
							nrSamples = nrSamples + 1;
						}
						ROF;
					}
					ROF;

					irradiance = irradiance * 3.141592_f *( 1.0_f / writer.cast< Float >( nrSamples ) );
					outColour = vec4( irradiance, 1.0_f );
				} );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}

		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterShader )
{
	sdwTestSuiteBegin();
	vtx_frag( testCounts );
	charles( testCounts );
	charles_approx( testCounts );
	charles_latest( testCounts );
	drawID( testCounts );
	charles_drawID( testCounts );
	arthapzMin( testCounts );
	arthapz( testCounts, false, false );
	arthapz( testCounts, false, true );
	arthapz( testCounts, true, false );
	arthapz( testCounts, true, true );
	clipDistance( testCounts );
	basicPipeline( testCounts );
	geometryPipeline( testCounts );
	voxelPipeline( testCounts );
	tessellationPipeline( testCounts );
	arraySsboTextureLookup( testCounts );
	pcbHelper( testCounts );
	radianceComputer( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterShader )
