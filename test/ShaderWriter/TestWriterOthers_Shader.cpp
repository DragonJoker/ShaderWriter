#include "WriterCommon.hpp"

#include <ShaderWriter/CompositeTypes/IOStructHelper.hpp>
#include <ShaderWriter/CompositeTypes/IOStructInstanceHelper.hpp>
#include <ShaderWriter/CompositeTypes/PushConstantBuffer.hpp>

#pragma warning( disable:5245 )
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wunused-member-function"

// Due to an unexpected crash in my driver, graphics pipelines with tessellation shaders can't be created when using SPIR-V, even if the tessellation shader itself looks valid.
#define TessellationCompilers Compilers_NoSPIRV

namespace
{
	template< sdw::var::Flag FlagT >
	using UIntTStructT = sdw::IOStructInstanceHelperT< FlagT
		, "DrawData"
		, sdw::IOUIntField< "data", 0u > >;
	template< sdw::var::Flag FlagT >
	using TexcoordStructT = sdw::IOStructInstanceHelperT< FlagT
		, "Texcoord"
		, sdw::IOVec2Field< "texcoord", 0u > >;
	template< sdw::var::Flag FlagT >
	using ColourStructT = sdw::IOStructInstanceHelperT< FlagT
		, "Colour"
		, sdw::IOVec4Field< "colour", 0u > >;
	template< sdw::var::Flag FlagT >
	using Position3StructT = sdw::MixedStructInstanceHelperT< FlagT
		, "Position3"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec3Field< "position", 0u > >;
	template< sdw::var::Flag FlagT >
	using Position4StructT = sdw::MixedStructInstanceHelperT< FlagT
		, "Position4"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec4Field< "position", 0u > >;
	template< sdw::var::Flag FlagT >
	using PosColStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PosCol"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec4Field< "position", 0u >
		, sdw::IOVec4Field< "colour", 1u > >;
	template< sdw::var::Flag FlagT >
	using PosTexStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PosTex"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec3Field< "position", 0u >
		, sdw::IOVec2Field< "texcoord", 1u > >;
	template< sdw::var::Flag FlagT >
	using PosColNmlStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PosColNml"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec4Field< "position", 0u >
		, sdw::IOVec3Field< "normal", 2u >
		, sdw::IOVec4Field< "colour", 3u > >;
	template< sdw::var::Flag FlagT >
	using PosNmlTexTanStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "PosNmlTexTan"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec3Field< "position", 0u >
		, sdw::IOVec3Field< "normal", 1u >
		, sdw::IOVec2Field< "texcoord", 2u >
		, sdw::IOVec4Field< "tangent", 3u > >;
	template< sdw::var::Flag FlagT >
	using IOVoxelGeomStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "VoxelGeom"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec3Field< "position", 0u >
		, sdw::IOUIntField< "axis", 1u >
		, sdw::IOVec4Field< "aabb", 2u > >;
	template< sdw::var::Flag FlagT >
	using SurfaceStructT = sdw::MixedStructInstanceHelperT< FlagT
		, "Surface"
		, sdw::type::MemoryLayout::eStd430
		, sdw::IOVec3Field< "position", 0u >
		, sdw::IOVec3Field< "normal", 1u >
		, sdw::IOVec3Field< "tangent", 2u >
		, sdw::IOVec3Field< "bitangent", 3u >
		, sdw::IOVec3Field< "texcoord", 4u >
		, sdw::IOIntField< "instance", 5u > >;
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
	struct UIntData
		: public UIntTStructT< FlagT >
	{
		UIntData( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: UIntTStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto data()const { return this->template getMember< "data" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct TexcoordT
		: public TexcoordStructT< FlagT >
	{
		TexcoordT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: TexcoordStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto texcoord()const { return this->template getMember< "texcoord" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct ColourT
		: public ColourStructT< FlagT >
	{
		ColourT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: ColourStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto colour()const { return this->template getMember< "colour" >(); }
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

		auto position()const { return this->template getMember< "position" >(); }
		auto colour()const { return this->template getMember< "colour" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct PosTexT
		: public PosTexStructT< FlagT >
	{
		PosTexT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: PosTexStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
		auto texcoord()const { return this->template getMember< "texcoord" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct Position3T
		: public Position3StructT< FlagT >
	{
		Position3T( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: Position3StructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct Position4T
		: public Position4StructT< FlagT >
	{
		Position4T( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: Position4StructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct PosNmlTexTanT
		: public PosNmlTexTanStructT< FlagT >
	{
		PosNmlTexTanT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: PosNmlTexTanStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
		auto normal()const { return this->template getMember< "normal" >(); }
		auto texcoord()const { return this->template getMember< "texcoord" >(); }
		auto tangent()const { return this->template getMember< "tangent" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct IOVoxelGeomT
		: public IOVoxelGeomStructT< FlagT >
	{
		IOVoxelGeomT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: IOVoxelGeomStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
		auto axis()const { return this->template getMember< "axis" >(); }
		auto aabb()const { return this->template getMember< "aabb" >(); }
	};

	template< sdw::var::Flag FlagT >
	struct SurfaceT
		: public SurfaceStructT< FlagT >
	{
		SurfaceT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: SurfaceStructT< FlagT >{ writer, std::move( expr ), enabled }
		{
		}

		auto position()const { return this->template getMember< "position" >(); }
		auto normal()const { return this->template getMember< "normal" >(); }
		auto tangent()const { return this->template getMember< "tangent" >(); }
		auto bitangent()const { return this->template getMember< "bitangent" >(); }
		auto texcoord()const { return this->template getMember< "texcoord" >(); }
		auto instance()const { return this->template getMember< "instance" >(); }
	};

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

	TEST_F( SDWTest, vtx_frag )
	{
		sdwTestBegin( "vtx_frag" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColT, PosColT >( []( VertexInT< PosColT > const & in
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

			writer.implementMainT< PosColT, ColourT >( [&writer]( FragmentInT< PosColT > const & in
				, FragmentOutT< ColourT > const & out )
				{
					sdwIF( writer, in.position().x() < 0.0_f )
					{
						writer.demote();
					}
					sdwFI

					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, charles )
	{
		sdwTestBegin( "charles" );
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

			writer.implementMainT< PosColT, ColourT >( [&colors, &positions]( VertexInT< PosColT > const & in
				, VertexOutT< ColourT > out )
				{
					out.colour() = colors[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					out.colour() = colors[0];
					out.vtx.position = positions[0];

					out.colour() = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< ColourT, ColourT >( []( FragmentInT< ColourT > const & in
				, FragmentOutT< ColourT > const & out )
				{
					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, charles_approx )
	{
		sdwTestBegin( "charles_approx" );
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

			writer.implementMainT< PosColT, ColourT >( [&colors, &positions]( VertexInT< PosColT > const & in
				, VertexOutT< ColourT > out )
				{
					out.colour() = colors[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					out.colour() = colors[0];
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

			writer.implementMainT< ColourT, ColourT >( []( FragmentInT< ColourT > const & in
				, FragmentOutT< ColourT > const & out )
				{
					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, charles_latest )
	{
		sdwTestBegin( "charles_latest" );
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

			writer.implementMainT< ColourT, ColourT >( [&colors, &positions, &indices]( VertexInT< ColourT > const & in
				, VertexOutT< ColourT > out )
				{
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

			writer.implementMainT< ColourT, ColourT >( []( FragmentInT< ColourT > const & in
				, FragmentOutT< ColourT > const & out )
				{
					out.colour() = in.colour();
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, drawID )
	{
		sdwTestBegin( "drawID" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			writer.implementMainT< VoidT, UIntData >( [&writer]( sdw::VertexIn const & in, sdw::VertexOutT< UIntData > const & out )
				{
					out.data() = writer.cast<UInt>(in.drawID);
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			writer.implementMainT< UIntData, UIntData >( []( sdw::FragmentInT< UIntData > const & in
				, sdw::FragmentOutT< UIntData > const & out )
				{
					out.data() = in.data();
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, charles_drawID )
	{
		sdwTestBegin( "charles_drawID" );
		using namespace sdw;

		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			auto pos = writer.declInput<Vec2>( "pos", 0 );
			auto uvs = writer.declInput<Vec2>( "uvs", 1 );
			auto col = writer.declInput<Vec4>( "col", 2 );

			auto fragUv = writer.declOutput<Vec2>( "fragUv", 0 );
			auto fragCol = writer.declOutput<Vec4>( "fragCol", 1 );

			auto ssbo = writer.declArrayStorageBuffer< Mat4 >( "ssbo", 1, 0, true );

			PushConstantBuffer pcb = writer.declPushConstantsBuffer( "pcb" );
			pcb.declMember<Int>( "firstMatrix" );
			pcb.end();

			writer.implementMain(
				[&writer, &ssbo, &pcb, &fragUv, &fragCol, &uvs, &col, &pos]( sdw::VertexIn const & in, sdw::VertexOut out )
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
				[&writer, &fontTexture, &fragUv, &fragCol, &color]( sdw::FragmentIn const &, sdw::FragmentOut const & )
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

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, arthapzMin )
	{
		sdwTestBegin( "arthapzMin" );
		sdw::ShaderArray shaders;
		{
			auto writer = sdw::VertexWriter{ &testCounts.allocator };

			writer.implementMainT< PosTexT, TexcoordT >( []( sdw::VertexInT< PosTexT > const & in
				, sdw::VertexOutT< TexcoordT > out )
				{
					using namespace sdw;

					out.texcoord() = in.texcoord();
					out.vtx.position = vec4( in.position(), 1.f);
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

			writer.implementMainT< TexcoordT, ColourT >( [&base_color_sampler, &getEmissiveColor]( sdw::FragmentInT< TexcoordT > const & in
				, sdw::FragmentOutT< ColourT > const & out )
				{
					out.colour() = base_color_sampler.sample( in.texcoord() ) + getEmissiveColor();
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	struct ArthapzParams
	{
		bool hasEmissiveMap;
		bool hasNormalMap;
	};
	ArthapzParams makeArthapzParams( bool hasEmissiveMap
		, bool hasNormalMap )
	{
		return ArthapzParams{ hasEmissiveMap, hasNormalMap };
	}

	static const ArthapzParams ff = makeArthapzParams( false, false );
	static const ArthapzParams ft = makeArthapzParams( false, true );
	static const ArthapzParams tf = makeArthapzParams( true, false );
	static const ArthapzParams tt = makeArthapzParams( true, true );

	std::string getArthapzParamsName( ArthapzParams const & p )
	{
		std::string result;
		if ( p.hasEmissiveMap )
			result += "Emissive";
		else
			result += "None";
		if ( p.hasNormalMap )
			result += "Normal";
		else
			result += "None";
		return result;
	}

	struct ArthapzParam
		: public SDWTest
		, public ::testing::WithParamInterface< ArthapzParams >
	{
	};

	TEST_P( ArthapzParam, arthapz )
	{
		auto params = GetParam();
		auto hasEmissiveMap = params.hasEmissiveMap;
		auto hasNormalMap = params.hasNormalMap;
		sdwTestBegin( "arthapz"
			+ std::to_string( hasEmissiveMap )
			+ std::to_string( hasNormalMap ) );
		sdw::ShaderArray shaders;
		{
			auto writer = sdw::VertexWriter{ &testCounts.allocator };

			auto camera = sdw::UniformBuffer{ writer.declUniformBuffer( "camera", 0, 0 ) };
			camera.declMember<sdw::Vec4>( "camera_position" );
			camera.declMember<sdw::Mat4>( "camera_projection" );
			camera.declMember<sdw::Mat4>( "camera_view" );
			camera.end();

			auto transform = sdw::UniformBuffer{ writer.declUniformBuffer( "transform", 1, 0 ) };
			transform.declMember<sdw::Mat4>( "transform_model" );
			transform.declMember<sdw::Mat4>( "transform_inverted_model" );
			transform.end();

			writer.implementMainT< PosNmlTexTanT, PosNmlTexTanT >( [&writer, &transform, &camera]( sdw::VertexInT< PosNmlTexTanT > const & in
				, sdw::VertexOutT< PosNmlTexTanT > out )
				{
					using namespace sdw;

					auto model_space_position =
						writer.declLocale( "model_space_position",
							transform.getMember<Mat4>( "transform_model" ) * vec4( in.position(), 1.f));

					out.position() = model_space_position.xyz() / model_space_position.w();
					out.normal() = normalize(
						transpose( mat3( transform.getMember<Mat4>( "transform_inverted_model" ) ) ) * in.normal() );
					out.texcoord() = in.texcoord();
					out.tangent() = in.tangent();

					out.vtx.position = camera.getMember<Mat4>( "camera_projection" ) *
						camera.getMember<Mat4>( "camera_view" ) * vec4( out.position(), 1.f);
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			auto writer = sdw::FragmentWriter{ &testCounts.allocator };

			auto camera = sdw::UniformBuffer{ writer.declUniformBuffer( "camera", 0, 0 ) };
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

			writer.implementMainT< PosNmlTexTanT, ColourT >( [&writer, &getNormal, &getEmissiveColor, &camera, &base_color_sampler]( sdw::FragmentInT< PosNmlTexTanT > const & in
				, sdw::FragmentOutT< ColourT > const & out )
				{
					auto N = writer.declLocale<sdw::Vec3>( "N"
						, sdw::normalize( getNormal( in.normal(), in.texcoord(), in.tangent() ) ) );
					auto V = writer.declLocale<sdw::Vec3>( "V",
						camera.getMember<sdw::Vec4>( "position" ).xyz() - in.position() );

					out.colour() = base_color_sampler.sample( in.texcoord() ) + getEmissiveColor( in.texcoord() );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}
	INSTANTIATE_TEST_SUITE_P( arthapz
		, ArthapzParam
		, testing::Values( ff, ft, tf, tt )
		, astTestNameP( ArthapzParams, getArthapzParamsName ) );

	TEST_F( SDWTest, clipDistance )
	{
		sdwTestBegin( "clipDistance" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };
			auto cfg = writer.declUniformBuffer( "Config", 0u, 0u );
			auto mvps = cfg.declMember< sdw::Mat4 >( "mvps", 6u );
			auto tiles = cfg.declMember< sdw::Vec4 >( "tiles" );
			auto instances = cfg.declMember< sdw::UVec4 >( "instances", 6u );
			cfg.end();

			writer.implementMainT< Position4T, VoidT >( [&writer, &mvps, &tiles, &instances]( sdw::VertexInT< Position4T > const & in
				, sdw::VertexOutT< VoidT > out )
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
						, mvps[tileIndex] * in.position() );
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

			writer.implementMainT< VoidT, ColourT >( []( sdw::FragmentIn const &
				, sdw::FragmentOutT< ColourT > const & out )
				{
					out.colour() = vec4( 1.0_f, 0.0f, 1.0f, 0.0f );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, basicPipeline )
	{
		sdwTestBegin( "basicPipeline" );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer myUbo{ writer.declUniformBuffer( "MyUbo", 0u, 0u ) };
			auto mvp = myUbo.declMember< sdw::Mat4 >( "mvp" );
			myUbo.end();

			writer.implementMainT< PosColT, ColourT >( [&mvp]( VertexInT< PosColT > const & in
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

			writer.implementMainT< ColourT, ColourT >( []( FragmentInT< ColourT > const & in
				, FragmentOutT< ColourT > const & out )
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
		sdwTestEnd()
	}

	TEST_F( SDWTest, geometryPipeline )
	{
		sdwTestBegin( "geometryPipeline" );
		using namespace sdw;
		ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< Position4T, VoidT >( []( VertexInT< Position4T > const & in
				, VertexOutT< VoidT > out )
				{
					out.vtx.position = in.position();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer voxelizeUbo{ writer.declUniformBuffer( "VoxelizeUbo", 0u, 0u ) };
			auto mvp = voxelizeUbo.declMember< Mat4 >( "mvp" );
			voxelizeUbo.end();

			using MyTriangleList = TriangleListT< VoidT >;
			using MyTriangleStream = TriangleStreamT< Position4T >;

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&writer, &mvp]( GeometryIn const &
				, MyTriangleList const & list
				, MyTriangleStream out )
				{
					auto pos = writer.declLocale< Vec4 >( "pos" );

					pos = mvp * list[0].vtx.position;
					out.position() = pos;
					out.vtx.position = pos;
					out.append();

					pos = mvp * list[1].vtx.position;
					out.position() = pos;
					out.vtx.position = pos;
					out.append();

					pos = mvp * list[2].vtx.position;
					out.position() = pos;
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

			writer.implementMainT< Position4T, ColourT >( []( FragmentInT< Position4T > const & in
				, FragmentOutT< ColourT > const & out )
				{
					out.colour() = in.position();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, voxelPipeline )
	{
		sdwTestBegin( "voxelPipeline" );
		using namespace sdw;
		sdw::ShaderArray shaders;

		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< Position3T, Position3T >( []( VertexInT< Position3T > const & in
				, sdw::VertexOutT< Position3T > out )
				{
					out.position() = in.position();
					out.vtx.position = vec4( in.position(), 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::GeometryWriter writer{ &testCounts.allocator };

			sdw::UniformBuffer voxelizeUbo{ writer.declUniformBuffer( "VoxelizeUbo", 0u, 0u ) };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			using MyTriangleList = sdw::TriangleListT< Position3T >;
			using MyTriangleStream = sdw::TriangleStreamT< IOVoxelGeomT >;

			writer.implementMainT< 3u, MyTriangleList, MyTriangleStream >( [&writer, &c3d_vpX, &c3d_vpY, &c3d_vpZ, c3d_size]( GeometryIn const &
				, MyTriangleList const & list
				, MyTriangleStream out )
				{
					auto faceNormal = writer.declLocale( "faceNormal"
						, normalize( cross( list[1].position() - list[0].position(), list[2].position() - list[0].position() ) ) );
					auto NdotXAxis = writer.declLocale( "NdotXAxis"
						, abs( faceNormal.x() ) );
					auto NdotYAxis = writer.declLocale( "NdotYAxis"
						, abs( faceNormal.y() ) );
					auto NdotZAxis = writer.declLocale( "NdotZAxis"
						, abs( faceNormal.z() ) );
					auto proj = writer.declLocale< Mat4 >( "proj" );
					auto curPosition = writer.declLocaleArray( "curPosition"
						, 3u
						, std::vector< sdw::Vec4 >{ list[0].vtx.position
							, list[1].vtx.position
							, list[2].vtx.position } );
					auto axis = writer.declLocale( "axis", 0_u );

					//Find the axis the maximize the projected area of this triangle
					sdwIF( writer, NdotXAxis > NdotYAxis && NdotXAxis > NdotZAxis )
					{
						proj = c3d_vpX;
						axis = 1_u;
					}
					sdwELSEIF( NdotYAxis > NdotXAxis && NdotYAxis > NdotZAxis )
					{
						proj = c3d_vpY;
						axis = 2_u;
					}
					sdwELSE
					{
						proj = c3d_vpZ;
						axis = 3_u;
					}
						sdwFI

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
					out.position() = pos[0].xyz();
					out.axis() = axis;
					out.aabb() = aabb;
					out.append();

					out.vtx.position = pos[1];
					out.position() = pos[1].xyz();
					out.axis() = axis;
					out.aabb() = aabb;
					out.append();

					out.vtx.position = pos[2];
					out.position() = pos[2].xyz();
					out.axis() = axis;
					out.aabb() = aabb;
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

			sdw::UniformBuffer voxelizeUbo{ writer.declUniformBuffer( "VoxelizeUbo", 0u, 0u ) };
			auto c3d_vpX = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpX" );
			auto c3d_vpY = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpY" );
			auto c3d_vpZ = voxelizeUbo.declMember< sdw::Mat4 >( "c3d_vpZ" );
			auto c3d_size = voxelizeUbo.declMember< sdw::Vec2 >( "c3d_size" );
			voxelizeUbo.end();

			writer.implementMainT< IOVoxelGeomT, ColourT >( [&writer, c3d_size, &pxl_voxelVisibility]( FragmentInT< IOVoxelGeomT > const & in
				, FragmentOutT< ColourT > const & out )
				{
					sdwIF( writer
						, in.position().x() < in.aabb().x()
						|| in.position().y() < in.aabb().y()
						|| in.position().x() > in.aabb().z()
						|| in.position().y() > in.aabb().w() )
					{
						writer.terminate();
					}
					sdwFI

					auto width = writer.declLocale( "width"
						, writer.cast< Int >( c3d_size.x() ) );
					auto temp = writer.declLocale( "temp"
						, ivec3( writer.cast< Int >( in.fragCoord.x() )
							, writer.cast< Int >( in.fragCoord.y() )
							, width * writer.cast< Int >( in.fragCoord.z() ) ) );
					auto texcoord = writer.declLocale< IVec3 >( "texcoord" );

					sdwIF( writer, in.axis() == 1_u )
					{
						texcoord.x() = width - temp.z();
						texcoord.z() = temp.x();
						texcoord.y() = temp.y();
					}
					sdwELSEIF( in.axis() == 2_u )
					{
						texcoord.z() = temp.y();
						texcoord.y() = width - temp.z();
						texcoord.x() = temp.x();
					}
					sdwELSE
					{
						texcoord = temp;
					}
					sdwFI

					pxl_voxelVisibility.store( texcoord, 1_u );
					out.colour() = vec4( vec3( texcoord ), 1.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, tessellationPipeline )
	{
		sdwTestBegin( "tessellationPipeline" );
		using namespace sdw;
		static uint32_t constexpr maxPoints = 3u;
		sdw::ShaderArray shaders;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			writer.implementMainT< PosColNmlT, PosColNmlT >( []( VertexInT< PosColNmlT > const & in
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

			sdw::UniformBuffer ubo{ writer.declUniformBuffer( "Wow", 0u, 0u ) };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			auto c3d_mapNormal = writer.declCombinedImg< FImg2DRgba32 >( "c3d_mapNormal", 1u, 0u );

			auto getTessLevel = writer.implementFunction< Float >( "getTessLevel"
				, [&writer]( Float const & a
					, Float const & b )
				{
					auto avgDistance = writer.declLocale( "avgDistance"
						, ( a + b ) / 2.0_f );

					sdwIF( writer, avgDistance <= 20.0_f )
					{
						writer.returnStmt( 256.0_f );
					}
					sdwELSEIF( avgDistance <= 50.0_f )
					{
						writer.returnStmt( 128.0_f );
					}
					sdwELSEIF( avgDistance <= 100.0_f )
					{
						writer.returnStmt( 64.0_f );
					}
					sdwFI

					writer.returnStmt( 16.0_f );
				}
				, InFloat{ writer, "a" }
				, InFloat{ writer, "b" } );

			auto projectToPlane = writer.implementFunction< Vec3 >( "projectToPlane"
				, [&writer]( Vec3 const & point
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
				, [&writer, &projectToPlane, &pos, &getTessLevel]( TessControlPatchRoutineIn const &
					, TessControlListInT< PosColNmlT, maxPoints > const & listIn
					, TrianglesTessPatchOutT< PNTriPatchT > const & patchOut )
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
				, []( TessControlMainIn const & in
					, TessControlListInT< PosColNmlT, maxPoints > const & listIn
					, TrianglesTessControlListOutT< ColourT > const & listOut )
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

			sdw::UniformBuffer ubo{ writer.declUniformBuffer( "Wow", 0u, 0u ) };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

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
				, [&writer, &interpolate4D, &mtx]( TessEvalMainIn const &
					, TessEvalListInT< ColourT, maxPoints > const & listIn
					, TrianglesTessPatchInT< PNTriPatchT > const & patchIn
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

					auto patchPos = writer.declLocale( "patchPos"
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

					out.vtx.position = mtx * vec4( patchPos, 1.0f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };

			writer.implementMainT< ColourT, ColourT >( []( FragmentInT< ColourT > const & in
				, FragmentOutT< ColourT > const & out )
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
			, TessellationCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, arraySsboTextureLookup )
	{
		sdwTestBegin( "arraySsboTextureLookup" );
		using namespace sdw;
		{
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto fragUvw = writer.declInput< Vec3 >( "fragUvw", 0u );
			auto outColor = writer.declOutput< Vec4 >( "outColor", 0u );

			sdw::StorageBuffer colorsSsbo = writer.declStorageBuffer( "colorsBuffer", 0u, 1u );
			auto colors = colorsSsbo.declMemberArray< Vec4 >( "colors" );
			colorsSsbo.end();

			auto volumeTexture = writer.declCombinedImg< UCombinedImage3DR32 >( "volumeTexture", 1u, 1u );

			writer.implementMainT< VoidT, ColourT >(
				[&colors, &volumeTexture, &fragUvw]( sdw::FragmentIn const &, sdw::FragmentOutT< ColourT > const & out )
				{
					out.colour() = colors[volumeTexture.sample(fragUvw)];
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, pcbHelper )
	{
		sdwTestBegin( "pcbHelper" );
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

			writer.implementMain( [&pcb, &color]( sdw::FragmentIn const &, sdw::FragmentOut const & )
				{
					color = pcb.color();
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, radianceComputer )
	{
		sdwTestBegin( "radianceComputer" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			sdw::VertexWriter writer{ &testCounts.allocator };

			// Inputs
			auto position = writer.declInput< Vec3 >( "position", 0u );
			sdw::UniformBuffer matrix{ writer.declUniformBuffer( "Matrix", 0u, 0u ) };
			auto c3d_viewProjection = matrix.declMember< Mat4 >( "c3d_viewProjection" );
			matrix.end();

			// Outputs
			auto vtx_worldPosition = writer.declOutput< Vec3 >( "vtx_worldPosition", 0u );

			writer.implementMainT< VoidT, VoidT >( [&position, &vtx_worldPosition, &c3d_viewProjection]( VertexIn const &
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

			writer.implementMainT< VoidT, VoidT >( [&writer, &vtx_worldPosition, &c3d_mapEnvironment, &outColour]( FragmentIn const &
				, FragmentOut const & )
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

					sdwFOR( writer, Float, phi, 0.0_f, phi < 6.253184_f, phi += sampleDelta )
					{
						sdwFOR( writer, Float, theta, 0.0_f, theta < 1.570796_f, theta += sampleDelta )
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
						sdwROF
					}
					sdwROF

					irradiance = irradiance * 3.141592_f *( 1.0_f / writer.cast< Float >( nrSamples ) );
					outColour = vec4( irradiance, 1.0_f );
				} );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}

		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbafStorageImages )
	{
		sdwTestBegin( "declareAll2DRgbafStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgRgba = writer.declStorageImg< WImage2DRgba >( "imgRgba", binding++, set );
			auto imgRgba32 = writer.declStorageImg< WImage2DRgba32 >( "imgRgba32", binding++, set );
			auto imgRgba16 = writer.declStorageImg< WImage2DRgba16 >( "imgRgba16", binding++, set );
			auto imgRgba16Snorm = writer.declStorageImg< WImage2DRgba16Snorm >( "imgRgba16Snorm", binding++, set );
			auto imgRgba16Unorm = writer.declStorageImg< WImage2DRgba16Unorm >( "imgRgba16Unorm", binding++, set );
			auto imgRgba8Snorm = writer.declStorageImg< WImage2DRgba8Snorm >( "imgRgba8Snorm", binding++, set );
			auto imgRgba8Unorm = writer.declStorageImg< WImage2DRgba8Unorm >( "imgRgba8Unorm", binding++, set );
			auto imgRgb10A2 = writer.declStorageImg< WImage2DRgb10A2 >( "imgRgb10A2", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgRgba.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgba32.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgba16.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgba16Snorm.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgba16Unorm.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgba8Snorm.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgba8Unorm.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
					imgRgb10A2.store( ivec2( in.localInvocationID.xy() ), vec4( 0.0_f ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbafCombinedImages )
	{
		sdwTestBegin( "declareAll2DRgbafCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgRgba = writer.declCombinedImg< CombinedImage2DRgba >( "imgRgba", binding++, set );
			auto imgRgba32 = writer.declCombinedImg< CombinedImage2DRgba32 >( "imgRgba32", binding++, set );
			auto imgRgba16 = writer.declCombinedImg< CombinedImage2DRgba16 >( "imgRgba16", binding++, set );
			auto imgRgba16Snorm = writer.declCombinedImg< CombinedImage2DRgba16Snorm >( "imgRgba16Snorm", binding++, set );
			auto imgRgba16Unorm = writer.declCombinedImg< CombinedImage2DRgba16Unorm >( "imgRgba16Unorm", binding++, set );
			auto imgRgba8Snorm = writer.declCombinedImg< CombinedImage2DRgba8Snorm >( "imgRgba8Snorm", binding++, set );
			auto imgRgba8Unorm = writer.declCombinedImg< CombinedImage2DRgba8Unorm >( "imgRgba8Unorm", binding++, set );
			auto imgRgb10A2 = writer.declCombinedImg< CombinedImage2DRgb10A2 >( "imgRgb10A2", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vRgba = writer.declLocale( "vRgba", imgRgba.sample( in.fragCoord.xy() ) );
					auto vRgba32 = writer.declLocale( "vRgba32", imgRgba32.sample( in.fragCoord.xy() ) );
					auto vRgba16 = writer.declLocale( "vRgba16", imgRgba16.sample( in.fragCoord.xy() ) );
					auto vRgba16Snorm = writer.declLocale( "vRgba16Snorm", imgRgba16Snorm.sample( in.fragCoord.xy() ) );
					auto vRgba16Unorm = writer.declLocale( "vRgba16Unorm", imgRgba16Unorm.sample( in.fragCoord.xy() ) );
					auto vRgba8Snorm = writer.declLocale( "vRgba8Snorm", imgRgba8Snorm.sample( in.fragCoord.xy() ) );
					auto vRgba8Unorm = writer.declLocale( "vRgba8Unorm", imgRgba8Unorm.sample( in.fragCoord.xy() ) );
					auto vRgb10A2 = writer.declLocale( "vRgb10A2", imgRgb10A2.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbafSampledImages )
	{
		sdwTestBegin( "declareAll2DRgbafSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgRgba = writer.declSampledImg< SampledImage2DRgba >( "imgRgba", binding++, set );
			auto imgRgba32 = writer.declSampledImg< SampledImage2DRgba32 >( "imgRgba32", binding++, set );
			auto imgRgba16 = writer.declSampledImg< SampledImage2DRgba16 >( "imgRgba16", binding++, set );
			auto imgRgba16Snorm = writer.declSampledImg< SampledImage2DRgba16Snorm >( "imgRgba16Snorm", binding++, set );
			auto imgRgba16Unorm = writer.declSampledImg< SampledImage2DRgba16Unorm >( "imgRgba16Unorm", binding++, set );
			auto imgRgba8Snorm = writer.declSampledImg< SampledImage2DRgba8Snorm >( "imgRgba8Snorm", binding++, set );
			auto imgRgba8Unorm = writer.declSampledImg< SampledImage2DRgba8Unorm >( "imgRgba8Unorm", binding++, set );
			auto imgRgb10A2 = writer.declSampledImg< SampledImage2DRgb10A2 >( "imgRgb10A2", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vRgba = writer.declLocale( "vRgba", combine( imgRgba, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgba32 = writer.declLocale( "vRgba32", combine( imgRgba32, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgba16 = writer.declLocale( "vRgba16", combine( imgRgba16, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgba16Snorm = writer.declLocale( "vRgba16Snorm", combine( imgRgba16Snorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgba16Unorm = writer.declLocale( "vRgba16Unorm", combine( imgRgba16Unorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgba8Snorm = writer.declLocale( "vRgba8Snorm", combine( imgRgba8Snorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgba8Unorm = writer.declLocale( "vRgba8Unorm", combine( imgRgba8Unorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRgb10A2 = writer.declLocale( "vRgb10A2", combine( imgRgb10A2, sampler ).sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbfStorageImages )
	{
		sdwTestBegin( "declareAll2DRgbfStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgR11fG11fB10f = writer.declStorageImg< WImage2DR11fG11fB10f >( "imgR11fG11fB10f", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgR11fG11fB10f.store( ivec2( in.localInvocationID.xy() ), vec3( 0.0_f ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbfCombinedImages )
	{
		sdwTestBegin( "declareAll2DRgbfCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgR11fG11fB10f = writer.declCombinedImg< CombinedImage2DR11fG11fB10f >( "imgR11fG11fB10f", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vR11fG11fB10f = writer.declLocale( "vR11fG11fB10f", imgR11fG11fB10f.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbfSampledImages )
	{
		sdwTestBegin( "declareAll2DRgbfSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgR11fG11fB10f = writer.declSampledImg< SampledImage2DR11fG11fB10f >( "imgR11fG11fB10f", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vR11fG11fB10f = writer.declLocale( "vR11fG11fB10f", combine( imgR11fG11fB10f, sampler ).sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgfStorageImages )
	{
		sdwTestBegin( "declareAll2DRgfStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgRg = writer.declStorageImg< WImage2DRg >( "imgRg", binding++, set );
			auto imgRg32 = writer.declStorageImg< WImage2DRg32 >( "imgRg32", binding++, set );
			auto imgRg16 = writer.declStorageImg< WImage2DRg16 >( "imgRg16", binding++, set );
			auto imgRg16Snorm = writer.declStorageImg< WImage2DRg16Snorm >( "imgRg16Snorm", binding++, set );
			auto imgRg16Unorm = writer.declStorageImg< WImage2DRg16Unorm >( "imgRg16Unorm", binding++, set );
			auto imgRg8Snorm = writer.declStorageImg< WImage2DRg8Snorm >( "imgRg8Snorm", binding++, set );
			auto imgRg8Unorm = writer.declStorageImg< WImage2DRg8Unorm >( "imgRg8Unorm", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgRg.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
					imgRg32.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
					imgRg16.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
					imgRg16Snorm.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
					imgRg16Unorm.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
					imgRg8Snorm.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
					imgRg8Unorm.store( ivec2( in.localInvocationID.xy() ), vec2( 0.0_f ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgfCombinedImages )
	{
		sdwTestBegin( "declareAll2DRgfCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgRg = writer.declCombinedImg< CombinedImage2DRg >( "imgRg", binding++, set );
			auto imgRg32 = writer.declCombinedImg< CombinedImage2DRg32 >( "imgRg32", binding++, set );
			auto imgRg16 = writer.declCombinedImg< CombinedImage2DRg16 >( "imgRg16", binding++, set );
			auto imgRg16Snorm = writer.declCombinedImg< CombinedImage2DRg16Snorm >( "imgRg16Snorm", binding++, set );
			auto imgRg16Unorm = writer.declCombinedImg< CombinedImage2DRg16Unorm >( "imgRg16Unorm", binding++, set );
			auto imgRg8Snorm = writer.declCombinedImg< CombinedImage2DRg8Snorm >( "imgRg8Snorm", binding++, set );
			auto imgRg8Unorm = writer.declCombinedImg< CombinedImage2DRg8Unorm >( "imgRg8Unorm", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vRg = writer.declLocale( "vRg", imgRg.sample( in.fragCoord.xy() ) );
					auto vRg32 = writer.declLocale( "vRg32", imgRg32.sample( in.fragCoord.xy() ) );
					auto vRg16 = writer.declLocale( "vRg16", imgRg16.sample( in.fragCoord.xy() ) );
					auto vRg16Snorm = writer.declLocale( "vRg16Snorm", imgRg16Snorm.sample( in.fragCoord.xy() ) );
					auto vRg16Unorm = writer.declLocale( "vRg16Unorm", imgRg16Unorm.sample( in.fragCoord.xy() ) );
					auto vRg8Snorm = writer.declLocale( "vRg8Snorm", imgRg8Snorm.sample( in.fragCoord.xy() ) );
					auto vRg8Unorm = writer.declLocale( "vRg8Unorm", imgRg8Unorm.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgfSampledImages )
	{
		sdwTestBegin( "declareAll2DRgfSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgRg = writer.declSampledImg< SampledImage2DRg >( "imgRg", binding++, set );
			auto imgRg32 = writer.declSampledImg< SampledImage2DRg32 >( "imgRg32", binding++, set );
			auto imgRg16 = writer.declSampledImg< SampledImage2DRg16 >( "imgRg16", binding++, set );
			auto imgRg16Snorm = writer.declSampledImg< SampledImage2DRg16Snorm >( "imgRg16Snorm", binding++, set );
			auto imgRg16Unorm = writer.declSampledImg< SampledImage2DRg16Unorm >( "imgRg16Unorm", binding++, set );
			auto imgRg8Snorm = writer.declSampledImg< SampledImage2DRg8Snorm >( "imgRg8Snorm", binding++, set );
			auto imgRg8Unorm = writer.declSampledImg< SampledImage2DRg8Unorm >( "imgRg8Unorm", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vRg = writer.declLocale( "vRg", combine( imgRg, sampler ).sample( in.fragCoord.xy() ) );
					auto vRg32 = writer.declLocale( "vRg32", combine( imgRg32, sampler ).sample( in.fragCoord.xy() ) );
					auto vRg16 = writer.declLocale( "vRg16", combine( imgRg16, sampler ).sample( in.fragCoord.xy() ) );
					auto vRg16Snorm = writer.declLocale( "vRg16Snorm", combine( imgRg16Snorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRg16Unorm = writer.declLocale( "vRg16Unorm", combine( imgRg16Unorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRg8Snorm = writer.declLocale( "vRg8Snorm", combine( imgRg8Snorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRg8Unorm = writer.declLocale( "vRg8Unorm", combine( imgRg8Unorm, sampler ).sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRfStorageImages )
	{
		sdwTestBegin( "declareAll2DRfStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgR = writer.declStorageImg< WImage2DR >( "imgR", binding++, set );
			auto imgR32 = writer.declStorageImg< WImage2DR32 >( "imgR32", binding++, set );
			auto imgR16 = writer.declStorageImg< WImage2DR16 >( "imgR16", binding++, set );
			auto imgR16Unorm = writer.declStorageImg< WImage2DR16Unorm >( "imgR16Unorm", binding++, set );
			auto imgR8Snorm = writer.declStorageImg< WImage2DR8Snorm >( "imgR8Snorm", binding++, set );
			auto imgR8Unorm = writer.declStorageImg< WImage2DR8Unorm >( "imgR8Unorm", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgR.store( ivec2( in.localInvocationID.xy() ), 0.0_f );
					imgR32.store( ivec2( in.localInvocationID.xy() ), 0.0_f );
					imgR16.store( ivec2( in.localInvocationID.xy() ), 0.0_f );
					imgR16Unorm.store( ivec2( in.localInvocationID.xy() ), 0.0_f );
					imgR8Snorm.store( ivec2( in.localInvocationID.xy() ), 0.0_f );
					imgR8Unorm.store( ivec2( in.localInvocationID.xy() ), 0.0_f );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRfCombinedImages )
	{
		sdwTestBegin( "declareAll2DRfCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgR = writer.declCombinedImg< CombinedImage2DR >( "imgR", binding++, set );
			auto imgR32 = writer.declCombinedImg< CombinedImage2DR32 >( "imgR32", binding++, set );
			auto imgR16 = writer.declCombinedImg< CombinedImage2DR16 >( "imgR16", binding++, set );
			auto imgR16Unorm = writer.declCombinedImg< CombinedImage2DR16Unorm >( "imgR16Unorm", binding++, set );
			auto imgR8Snorm = writer.declCombinedImg< CombinedImage2DR8Snorm >( "imgR8Snorm", binding++, set );
			auto imgR8Unorm = writer.declCombinedImg< CombinedImage2DR8Unorm >( "imgR8Unorm", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vR = writer.declLocale( "vR", imgR.sample( in.fragCoord.xy() ) );
					auto vR32 = writer.declLocale( "vR32", imgR32.sample( in.fragCoord.xy() ) );
					auto vR16 = writer.declLocale( "vR16", imgR16.sample( in.fragCoord.xy() ) );
					auto vR16Unorm = writer.declLocale( "vR16Unorm", imgR16Unorm.sample( in.fragCoord.xy() ) );
					auto vR8Snorm = writer.declLocale( "vR8Snorm", imgR8Snorm.sample( in.fragCoord.xy() ) );
					auto vR8Unorm = writer.declLocale( "vR8Unorm", imgR8Unorm.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRfSampledImages )
	{
		sdwTestBegin( "declareAll2DRfSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgR = writer.declSampledImg< SampledImage2DR >( "imgR", binding++, set );
			auto imgR32 = writer.declSampledImg< SampledImage2DR32 >( "imgR32", binding++, set );
			auto imgR16 = writer.declSampledImg< SampledImage2DR16 >( "imgR16", binding++, set );
			auto imgR16Unorm = writer.declSampledImg< SampledImage2DR16Unorm >( "imgR16Unorm", binding++, set );
			auto imgR8Snorm = writer.declSampledImg< SampledImage2DR8Snorm >( "imgR8Snorm", binding++, set );
			auto imgR8Unorm = writer.declSampledImg< SampledImage2DR8Unorm >( "imgR8Unorm", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			auto samplerShadow = writer.declSampler< true >( "samplerShadow", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vR = writer.declLocale( "vR", combine( imgR, sampler ).sample( in.fragCoord.xy() ) );
					auto vR32 = writer.declLocale( "vR32", combine( imgR32, sampler ).sample( in.fragCoord.xy() ) );
					auto vR16 = writer.declLocale( "vR16", combine( imgR16, sampler ).sample( in.fragCoord.xy() ) );
					auto vR16Unorm = writer.declLocale( "vR16Unorm", combine( imgR16Unorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vR8Snorm = writer.declLocale( "vR8Snorm", combine( imgR8Snorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vR8Unorm = writer.declLocale( "vR8Unorm", combine( imgR8Unorm, sampler ).sample( in.fragCoord.xy() ) );
					auto vRShadow = writer.declLocale( "vRShadow", combine( imgR, samplerShadow ).sample( in.fragCoord.xy(), 0.5_f ) );
					auto vR32Shadow = writer.declLocale( "vR32Shadow", combine( imgR32, samplerShadow ).sample( in.fragCoord.xy(), 0.5_f ) );
					auto vR16Shadow = writer.declLocale( "vR16Shadow", combine( imgR16, samplerShadow ).sample( in.fragCoord.xy(), 0.5_f ) );
					auto vR16UnormShadow = writer.declLocale( "vR16UnormShadow", combine( imgR16Unorm, samplerShadow ).sample( in.fragCoord.xy(), 0.5_f ) );
					auto vR8SnormShadow = writer.declLocale( "vR8SnormShadow", combine( imgR8Snorm, samplerShadow ).sample( in.fragCoord.xy(), 0.5_f ) );
					auto vR8UnormShadow = writer.declLocale( "vR8UnormShadow", combine( imgR8Unorm, samplerShadow ).sample( in.fragCoord.xy(), 0.5_f ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbaiStorageImages )
	{
		sdwTestBegin( "declareAll2DRgbaiStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgIRgba32 = writer.declStorageImg< WIImage2DRgba32 >( "imgIRgba32", binding++, set );
			auto imgIRgba16 = writer.declStorageImg< WIImage2DRgba16 >( "imgIRgba16", binding++, set );
			auto imgIRgba8 = writer.declStorageImg< WIImage2DRgba8 >( "imgIRgba8", binding++, set );
			auto imgURgba32 = writer.declStorageImg< WUImage2DRgba32 >( "imgURgba32", binding++, set );
			auto imgURgba16 = writer.declStorageImg< WUImage2DRgba16 >( "imgURgba16", binding++, set );
			auto imgURgba8 = writer.declStorageImg< WUImage2DRgba8 >( "imgURgba8", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgIRgba32.store( ivec2( in.localInvocationID.xy() ), ivec4( 0_i ) );
					imgIRgba16.store( ivec2( in.localInvocationID.xy() ), ivec4( 0_i ) );
					imgIRgba8.store( ivec2( in.localInvocationID.xy() ), ivec4( 0_i ) );
					imgURgba32.store( ivec2( in.localInvocationID.xy() ), uvec4( 0_u ) );
					imgURgba16.store( ivec2( in.localInvocationID.xy() ), uvec4( 0_u ) );
					imgURgba8.store( ivec2( in.localInvocationID.xy() ), uvec4( 0_u ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbaiCombinedImages )
	{
		sdwTestBegin( "declareAll2DRgbaiCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgIRgba32 = writer.declCombinedImg< ICombinedImage2DRgba32 >( "imgIRgba32", binding++, set );
			auto imgIRgba16 = writer.declCombinedImg< ICombinedImage2DRgba16 >( "imgIRgba16", binding++, set );
			auto imgIRgba8 = writer.declCombinedImg< ICombinedImage2DRgba8 >( "imgIRgba8", binding++, set );
			auto imgURgba32 = writer.declCombinedImg< UCombinedImage2DRgba32 >( "imgURgba32", binding++, set );
			auto imgURgba16 = writer.declCombinedImg< UCombinedImage2DRgba16 >( "imgURgba16", binding++, set );
			auto imgURgba8 = writer.declCombinedImg< UCombinedImage2DRgba8 >( "imgURgba8", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vIRgba32 = writer.declLocale( "vIRgba32", imgIRgba32.sample( in.fragCoord.xy() ) );
					auto vIRgba16 = writer.declLocale( "vIRgba16", imgIRgba16.sample( in.fragCoord.xy() ) );
					auto vIRgba8 = writer.declLocale( "vIRgba8", imgIRgba8.sample( in.fragCoord.xy() ) );
					auto vURgba32 = writer.declLocale( "vURgba32", imgURgba32.sample( in.fragCoord.xy() ) );
					auto vURgba16 = writer.declLocale( "vURgba16", imgURgba16.sample( in.fragCoord.xy() ) );
					auto vURgba8 = writer.declLocale( "vURgba8", imgURgba8.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgbaiSampledImages )
	{
		sdwTestBegin( "declareAll2DRgbaiSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgIRgba32 = writer.declSampledImg< ISampledImage2DRgba32 >( "imgIRgba32", binding++, set );
			auto imgIRgba16 = writer.declSampledImg< ISampledImage2DRgba16 >( "imgIRgba16", binding++, set );
			auto imgIRgba8 = writer.declSampledImg< ISampledImage2DRgba8 >( "imgIRgba8", binding++, set );
			auto imgURgba32 = writer.declSampledImg< USampledImage2DRgba32 >( "imgURgba32", binding++, set );
			auto imgURgba16 = writer.declSampledImg< USampledImage2DRgba16 >( "imgURgba16", binding++, set );
			auto imgURgba8 = writer.declSampledImg< USampledImage2DRgba8 >( "imgURgba8", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vIRgba32 = writer.declLocale( "vIRgba32", combine( imgIRgba32, sampler ).sample( in.fragCoord.xy() ) );
					auto vIRgba16 = writer.declLocale( "vIRgba16", combine( imgIRgba16, sampler ).sample( in.fragCoord.xy() ) );
					auto vIRgba8 = writer.declLocale( "vIRgba8", combine( imgIRgba8, sampler ).sample( in.fragCoord.xy() ) );
					auto vURgba32 = writer.declLocale( "vURgba32", combine( imgURgba32, sampler ).sample( in.fragCoord.xy() ) );
					auto vURgba16 = writer.declLocale( "vURgba16", combine( imgURgba16, sampler ).sample( in.fragCoord.xy() ) );
					auto vURgba8 = writer.declLocale( "vURgba8", combine( imgURgba8, sampler ).sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgiStorageImages )
	{
		sdwTestBegin( "declareAll2DRgiStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgIRg32 = writer.declStorageImg< WIImage2DRg32 >( "imgIRg32", binding++, set );
			auto imgIRg16 = writer.declStorageImg< WIImage2DRg16 >( "imgIRg16", binding++, set );
			auto imgIRg8 = writer.declStorageImg< WIImage2DRg8 >( "imgIRg8", binding++, set );
			auto imgURg32 = writer.declStorageImg< WUImage2DRg32 >( "imgURg32", binding++, set );
			auto imgURg16 = writer.declStorageImg< WUImage2DRg16 >( "imgURg16", binding++, set );
			auto imgURg8 = writer.declStorageImg< WUImage2DRg8 >( "imgURg8", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgIRg32.store( ivec2( in.localInvocationID.xy() ), ivec2( 0_i ) );
					imgIRg16.store( ivec2( in.localInvocationID.xy() ), ivec2( 0_i ) );
					imgIRg8.store( ivec2( in.localInvocationID.xy() ), ivec2( 0_i ) );
					imgURg32.store( ivec2( in.localInvocationID.xy() ), uvec2( 0_u ) );
					imgURg16.store( ivec2( in.localInvocationID.xy() ), uvec2( 0_u ) );
					imgURg8.store( ivec2( in.localInvocationID.xy() ), uvec2( 0_u ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgiCombinedImages )
	{
		sdwTestBegin( "declareAll2DRgiCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgIRg32 = writer.declCombinedImg< ICombinedImage2DRg32 >( "imgIRg32", binding++, set );
			auto imgIRg16 = writer.declCombinedImg< ICombinedImage2DRg16 >( "imgIRg16", binding++, set );
			auto imgIRg8 = writer.declCombinedImg< ICombinedImage2DRg8 >( "imgIRg8", binding++, set );
			auto imgURg32 = writer.declCombinedImg< UCombinedImage2DRg32 >( "imgURg32", binding++, set );
			auto imgURg16 = writer.declCombinedImg< UCombinedImage2DRg16 >( "imgURg16", binding++, set );
			auto imgURg8 = writer.declCombinedImg< UCombinedImage2DRg8 >( "imgURg8", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vIRg32 = writer.declLocale( "vIRg32", imgIRg32.sample( in.fragCoord.xy() ) );
					auto vIRg16 = writer.declLocale( "vIRg16", imgIRg16.sample( in.fragCoord.xy() ) );
					auto vIRg8 = writer.declLocale( "vIRg8", imgIRg8.sample( in.fragCoord.xy() ) );
					auto vURg32 = writer.declLocale( "vURg32", imgURg32.sample( in.fragCoord.xy() ) );
					auto vURg16 = writer.declLocale( "vURg16", imgURg16.sample( in.fragCoord.xy() ) );
					auto vURg8 = writer.declLocale( "vURg8", imgURg8.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRgiSampledImages )
	{
		sdwTestBegin( "declareAll2DRgiSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgIRg32 = writer.declSampledImg< ISampledImage2DRg32 >( "imgIRg32", binding++, set );
			auto imgIRg16 = writer.declSampledImg< ISampledImage2DRg16 >( "imgIRg16", binding++, set );
			auto imgIRg8 = writer.declSampledImg< ISampledImage2DRg8 >( "imgIRg8", binding++, set );
			auto imgURg32 = writer.declSampledImg< USampledImage2DRg32 >( "imgURg32", binding++, set );
			auto imgURg16 = writer.declSampledImg< USampledImage2DRg16 >( "imgURg16", binding++, set );
			auto imgURg8 = writer.declSampledImg< USampledImage2DRg8 >( "imgURg8", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vIRg32 = writer.declLocale( "vIRg32", combine( imgIRg32, sampler ).sample( in.fragCoord.xy() ) );
					auto vIRg16 = writer.declLocale( "vIRg16", combine( imgIRg16, sampler ).sample( in.fragCoord.xy() ) );
					auto vIRg8 = writer.declLocale( "vIRg8", combine( imgIRg8, sampler ).sample( in.fragCoord.xy() ) );
					auto vURg32 = writer.declLocale( "vURg32", combine( imgURg32, sampler ).sample( in.fragCoord.xy() ) );
					auto vURg16 = writer.declLocale( "vURg16", combine( imgURg16, sampler ).sample( in.fragCoord.xy() ) );
					auto vURg8 = writer.declLocale( "vURg8", combine( imgURg8, sampler ).sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRiStorageImages )
	{
		sdwTestBegin( "declareAll2DRiStorageImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::ComputeWriter writer{ &testCounts.allocator };
			auto imgIR32 = writer.declStorageImg< WIImage2DR32 >( "imgIR32", binding++, set );
			auto imgIR16 = writer.declStorageImg< WIImage2DR16 >( "imgIR16", binding++, set );
			auto imgIR8 = writer.declStorageImg< WIImage2DR8 >( "imgIR8", binding++, set );
			auto imgUR32 = writer.declStorageImg< WUImage2DR32 >( "imgUR32", binding++, set );
			auto imgUR16 = writer.declStorageImg< WUImage2DR16 >( "imgUR16", binding++, set );
			auto imgUR8 = writer.declStorageImg< WUImage2DR8 >( "imgUR8", binding++, set );
			writer.implementMain( 32u, 32u
				, [&]( sdw::ComputeIn const & in )
				{
					imgIR32.store( ivec2( in.localInvocationID.xy() ), 0_i );
					imgIR16.store( ivec2( in.localInvocationID.xy() ), 0_i );
					imgIR8.store( ivec2( in.localInvocationID.xy() ), 0_i );
					imgUR32.store( ivec2( in.localInvocationID.xy() ), 0_u );
					imgUR16.store( ivec2( in.localInvocationID.xy() ), 0_u );
					imgUR8.store( ivec2( in.localInvocationID.xy() ), 0_u );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
			shaders.emplace_back( std::make_unique< ast::Shader >( std::move( writer.getShader() ) ) );
		}
		test::validateShaders( shaders
			, testCounts
			, CurrentCompilers );
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRiCombinedImages )
	{
		sdwTestBegin( "declareAll2DRiCombinedImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgIR32 = writer.declCombinedImg< ICombinedImage2DR32 >( "imgIR32", binding++, set );
			auto imgIR16 = writer.declCombinedImg< ICombinedImage2DR16 >( "imgIR16", binding++, set );
			auto imgIR8 = writer.declCombinedImg< ICombinedImage2DR8 >( "imgIR8", binding++, set );
			auto imgUR32 = writer.declCombinedImg< UCombinedImage2DR32 >( "imgUR32", binding++, set );
			auto imgUR16 = writer.declCombinedImg< UCombinedImage2DR16 >( "imgUR16", binding++, set );
			auto imgUR8 = writer.declCombinedImg< UCombinedImage2DR8 >( "imgUR8", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vIR32 = writer.declLocale( "vIR32", imgIR32.sample( in.fragCoord.xy() ) );
					auto vIR16 = writer.declLocale( "vIR16", imgIR16.sample( in.fragCoord.xy() ) );
					auto vIR8 = writer.declLocale( "vIR8", imgIR8.sample( in.fragCoord.xy() ) );
					auto vUR32 = writer.declLocale( "vUR32", imgUR32.sample( in.fragCoord.xy() ) );
					auto vUR16 = writer.declLocale( "vUR16", imgUR16.sample( in.fragCoord.xy() ) );
					auto vUR8 = writer.declLocale( "vUR8", imgUR8.sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}

	TEST_F( SDWTest, declareAll2DRiSampledImages )
	{
		sdwTestBegin( "declareAll2DRiSampledImages" );
		std::vector< std::unique_ptr< ast::Shader > > shaders;
		using namespace sdw;
		{
			uint32_t binding{};
			uint32_t set{};
			sdw::FragmentWriter writer{ &testCounts.allocator };
			auto imgIR32 = writer.declSampledImg< ISampledImage2DR32 >( "imgIR32", binding++, set );
			auto imgIR16 = writer.declSampledImg< ISampledImage2DR16 >( "imgIR16", binding++, set );
			auto imgIR8 = writer.declSampledImg< ISampledImage2DR8 >( "imgIR8", binding++, set );
			auto imgUR32 = writer.declSampledImg< USampledImage2DR32 >( "imgUR32", binding++, set );
			auto imgUR16 = writer.declSampledImg< USampledImage2DR16 >( "imgUR16", binding++, set );
			auto imgUR8 = writer.declSampledImg< USampledImage2DR8 >( "imgUR8", binding++, set );
			++set;
			binding = {};
			auto sampler = writer.declSampler< false >( "smp", binding++, set );
			writer.implementMain( [&]( sdw::FragmentIn const & in, sdw::FragmentOut const & )
				{
					auto vIR32 = writer.declLocale( "vIR32", combine( imgIR32, sampler ).sample( in.fragCoord.xy() ) );
					auto vIR16 = writer.declLocale( "vIR16", combine( imgIR16, sampler ).sample( in.fragCoord.xy() ) );
					auto vIR8 = writer.declLocale( "vIR8", combine( imgIR8, sampler ).sample( in.fragCoord.xy() ) );
					auto vUR32 = writer.declLocale( "vUR32", combine( imgUR32, sampler ).sample( in.fragCoord.xy() ) );
					auto vUR16 = writer.declLocale( "vUR16", combine( imgUR16, sampler ).sample( in.fragCoord.xy() ) );
					auto vUR8 = writer.declLocale( "vUR8", combine( imgUR8, sampler ).sample( in.fragCoord.xy() ) );
				} );
			test::writeShader( writer
				, testCounts
				, CurrentCompilers );
		}
		sdwTestEnd()
	}
}

sdwTestSuiteMain()
