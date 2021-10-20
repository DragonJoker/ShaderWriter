#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
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

		static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
				, ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Colour"
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

		static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
				, ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "Position"
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

		sdw::Vec4 position;
	};

	template< sdw::var::Flag FlagT >
	struct PosColT
		: sdw::StructInstance
	{
		PosColT( sdw::ShaderWriter & writer
			, sdw::expr::ExprPtr expr
			, bool enabled = true )
			: sdw::StructInstance{ writer, std::move( expr ), enabled }
			, position{ getMember< sdw::Vec4 >( "position" ) }
			, colour{ getMember< sdw::Vec4 >( "colour" ) }
		{
		}

		SDW_DeclStructInstance( , PosColT );

		static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
				, ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "PosCol"
				, FlagT );

			if ( result->empty() )
			{
				result->declMember( "position"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, 0u );
				result->declMember( "colour"
					, sdw::type::Kind::eVec4F
					, sdw::type::NotArray
					, 1u );
			}

			return result;
		}

		sdw::Vec4 position;
		sdw::Vec4 colour;
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

		static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
		{
			auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
				, ( FlagT == ast::var::Flag::eShaderOutput
					? std::string{ "Output" }
					: std::string{ "Input" } ) + "PosNmlTexTan"
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

		sdw::Vec3 position;
		sdw::Vec3 normal;
		sdw::Vec2 texcoord;
		sdw::Vec4 tangent;
	};

	void vtx_frag( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vtx_frag" );
		using namespace sdw;

		ShaderArray shaders;
		{
			VertexWriter writer;

			writer.implementMainT< PosColT, PosColT >( [&]( VertexInT< PosColT > in
				, VertexOutT< PosColT > out )
				{
					out.colour = in.colour;
					out.position = in.position;
					out.vtx.position = in.position;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			FragmentWriter writer;

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = in.colour;
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
			VertexWriter writer;
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
					out.colour = colors[in.vertexIndex];
					out.position = positions[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					out.colour = colors[0];
					out.position = positions[0];
					out.vtx.position = positions[0];

					out.colour = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			using namespace sdw;
			FragmentWriter writer;

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = in.colour;
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
			VertexWriter writer;
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
					out.colour = colors[in.vertexIndex];
					out.position = positions[in.vertexIndex];
					out.vtx.position = positions[in.vertexIndex];

					out.colour = colors[0];
					out.position = positions[0];
					out.vtx.position = positions[0];

					out.colour = vec4( 1.0_f, 0.0f, 0.0f, 1.0f );
					out.vtx.position = vec4( 0.0_f, 0.0f, 0.0f, 1.0f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = in.colour;
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
			VertexWriter writer;

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
					out.position =
						vec4( positions[indices[in.vertexIndex]], 0.0_f, 1.0_f );
					out.vtx.position =
						vec4( positions[indices[in.vertexIndex]], 0.0_f, 1.0_f );
					out.colour = vec4( colors[indices[in.vertexIndex]], 1.0_f );
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			writer.implementMainT< PosColT, ColourT >( [&]( FragmentInT< PosColT > in
				, FragmentOutT< ColourT > out )
				{
					out.colour = in.colour;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
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
			auto writer = sdw::VertexWriter{};

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
			auto writer = sdw::FragmentWriter{};
			auto base_color_sampler = writer.declSampledImage<FImg2DRgba32>( "base_color_sampler", 0, 2 );

			auto getEmissiveColor = writer.implementFunction<sdw::Vec4>( "getEmissiveColor", [&]()
				{
					writer.returnStmt( sdw::vec4( 0._f, 0.f, 0.f, 0.f ) );
				} );

			writer.implementMainT< PosNmlTexTanT, ColourT >( [&]( sdw::FragmentInT< PosNmlTexTanT > in
				, sdw::FragmentOutT< ColourT > out )
				{
					out.colour = base_color_sampler.sample( in.texcoord ) + getEmissiveColor();
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
			auto writer = sdw::VertexWriter{};

			auto camera = sdw::Ubo{ writer, "camera", 0, 0 };
			camera.declMember<sdw::Vec4>( "camera_position" );
			camera.declMember<sdw::Mat4>( "camera_projection" );
			camera.declMember<sdw::Mat4>( "camera_view" );
			camera.end();

			auto transform = sdw::Ubo{ writer, "transform", 1, 0 };
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
			auto writer = sdw::FragmentWriter{};

			auto camera = sdw::Ubo{ writer, "camera", 0, 0 };
			camera.declMember<sdw::Vec4>( "position" );
			camera.declMember<sdw::Mat4>( "projection" );
			camera.declMember<sdw::Mat4>( "view" );
			camera.end();

			auto material = sdw::Pcb{ writer, "material", ast::type::MemoryLayout::eStd140 };
			material.declMember<sdw::Vec4>( "base_color_factor" );
			material.declMember<sdw::Vec4>( "emissive_factor" );
			material.declMember<sdw::Float>( "metallic_factor" );
			material.declMember<sdw::Float>( "roughness_factor" );
			material.declMember<sdw::Float>( "ambiant_occlusion_factor" );
			material.declMember<sdw::Float>( "PAD0" );
			material.end();

			auto base_color_sampler = writer.declSampledImage<FImg2DRgba32>( "base_color_sampler", 0, 2 );
			auto normal_sampler = writer.declSampledImage<FImg2DRgba32>( "normal_sampler", 1, 2 );
			auto metallic_roughness_sampler =
				writer.declSampledImage<FImg2DRgba32>( "metallic_roughness_sampler", 2, 2 );
			auto ambiant_occlusion_sampler =
				writer.declSampledImage<FImg2DRgba32>( "ambiant_occlusion_sampler", 3, 2 );
			auto emissive_sampler = writer.declSampledImage<FImg2DRgba32>( "emissive_sampler", 4, 2 );

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

					out.colour = base_color_sampler.sample( in.texcoord ) + getEmissiveColor( in.texcoord );
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
			VertexWriter writer;
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
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		{
			FragmentWriter writer;

			writer.implementMainT< PositionT, ColourT >( [&]( sdw::FragmentInT< PositionT > in
				, sdw::FragmentOutT< ColourT > out )
				{
					out.colour = vec4( 1.0_f, 0.0f, 1.0f, 0.0f );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
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
	arthapzMin( testCounts );
	arthapz( testCounts, false, false );
	arthapz( testCounts, false, true );
	arthapz( testCounts, true, false );
	arthapz( testCounts, true, true );
	clipDistance( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterShader )
