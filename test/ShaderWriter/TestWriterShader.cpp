#include "Common.hpp"
#include "WriterCommon.hpp"

#pragma clang diagnostic ignored "-Wunused-member-function"

namespace
{
	void reference( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "reference" );
		using namespace sdw;

		FragmentWriter writer;
		auto color1 = writer.declInput< Vec4 >( "color1", 0u );
		auto multiplier = writer.declInput< Vec4 >( "multiplier", 1u );
		auto color2 = writer.declInput< Vec4 >( "color2", 2u );
		auto color = writer.declOutput< Vec4 >( "color", 0u );

		Struct S{ writer, "S" };
		S.declMember< Int >( "b" );
		S.declMember< Vec4 >( "v", 5u );
		S.declMember< Int >( "i" );
		S.end();

		Ubo blockName{ writer, "blockName", 0u, 0u };
		blockName.declStructMember( "s", S );
		blockName.declMember< Int >( "cond" );
		blockName.end();
		auto s = blockName.getMember< StructInstance >( "s" );
		auto cond = blockName.getMember< Int >( "cond" );

		writer.implementFunction< sdw::Void >( "main", [&]()
			{
				auto scale = writer.declLocale( "scale"
					, vec4( 1.0_f, 1.0_f, 2.0_f, 1.0_f ) );
				auto sv = s.getMemberArray< Vec4 >( "v" );

				IF( writer, cond != 0_i )
				{
					color = color1 + sv[2];
				}
				ELSE
				{
					color = sqrt( color2 ) * scale;
				}
				FI;

				FOR( writer, Int, i, 0_i, i < 4_i, ++i )
				{
					color *= multiplier;
				}
				ROF;
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace vtx
	{
		template< sdw::var::Flag FlagT >
		struct VtxInT
			: sdw::StructInstance
		{
			VtxInT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, position{ getMember< sdw::Vec2 >( "position" ) }
				, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
			{
			}

			SDW_DeclStructInstance( , VtxInT );

			static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
					, "VtxInT"
					, FlagT );

				if ( result->empty() )
				{
					result->declMember( "position"
						, sdw::type::Kind::eVec2F
						, sdw::type::NotArray
						, 0u );
					result->declMember( "texcoord"
						, sdw::type::Kind::eVec2F
						, sdw::type::NotArray
						, 1u );
				}

				return result;
			}

			sdw::Vec2 position;
			sdw::Vec2 texcoord;
		};

		template< sdw::var::Flag FlagT >
		struct VtxOutT
			: sdw::StructInstance
		{
			VtxOutT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, position{ getMember< sdw::Vec2 >( "position" ) }
			{
			}

			SDW_DeclStructInstance( , VtxOutT );

			static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
					, "VtxOutT"
					, FlagT );

				if ( result->empty() )
				{
					result->declMember( "position"
						, sdw::type::Kind::eVec2F
						, sdw::type::NotArray
						, 0u );
				}

				return result;
			}

			sdw::Vec2 position;
		};

		template< sdw::var::Flag FlagT >
		struct FrgInT
			: sdw::StructInstance
		{
			FrgInT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
			{
			}

			SDW_DeclStructInstance( , FrgInT );

			static ast::type::IOStructPtr makeType( ast::type::TypesCache & cache )
			{
				auto result = cache.getIOStruct( ast::type::MemoryLayout::eC
					, "FragmentIn"
					, FlagT );

				if ( result->empty() )
				{
					result->declMember( "texcoord"
						, ast::type::Kind::eVec2F
						, ast::type::NotArray
						, 0u );
				}

				return result;
			}

			sdw::Vec2 texcoord;
		};
	}

	void vertex( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vertex" );
		using namespace sdw;
		using namespace vtx;
		VertexWriter writer;

		writer.implementMainT< VtxInT, VtxOutT >( [&]( sdw::VertexInT< VtxInT > in
			, sdw::VertexOutT< VtxOutT > out )
			{
				out.position = in.texcoord;
				out.vtx.position = vec4( in.position.x(), in.position.y(), 0.0, 1.0 );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void fragment( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "fragment" );
		using namespace sdw;
		using namespace vtx;

		FragmentWriter writer;
		// Shader inputs
		Ubo hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapDiffuse = writer.declSampledImage< FImg2DRgba32 >( "c3d_mapDiffuse", 1u, 0u );

		// Shader outputs
		auto pxl_rgb = writer.declOutput< Vec4 >( "pxl_rgb", 0 );

		auto applyGamma = writer.implementFunction< Vec3 >( "applyGamma"
			, [&]( Float const & gamma
				, Vec3 const & hdr )
			{
				writer.returnStmt( pow( abs( hdr ), vec3( 1.0_f / gamma ) ) );
			}
			, InFloat{ writer, "gamma" }
			, InVec3{ writer, "hdr" } );

		auto shoulderStrength = writer.declConstant< Float >( "ShoulderStrength", 0.15_f );
		auto linearStrength = writer.declConstant< Float >( "LinearStrength", 0.50_f );
		auto linearAngle = writer.declConstant< Float >( "LinearAngle", 0.10_f );
		auto toeStrength = writer.declConstant< Float >( "ToeStrength", 0.20_f );
		auto toeNumerator = writer.declConstant< Float >( "ToeNumerator", 0.02_f );
		auto toeDenominator = writer.declConstant< Float >( "ToeDenominator", 0.30_f );
		auto linearWhitePointValue = writer.declConstant< Float >( "LinearWhitePointValue", 11.2_f );
		auto exposureBias = writer.declConstant< Float >( "ExposureBias", 2.0_f );

		auto uncharted2ToneMap = writer.implementFunction< Vec3 >( "uncharted2ToneMap"
			, [&]( Vec3 const & x )
			{
				writer.returnStmt( (
					(
						x
						* ( x * shoulderStrength + linearAngle * linearStrength )
						+ toeStrength * toeNumerator )
					/ (
						x
						* ( x * shoulderStrength + linearStrength )
						+ toeStrength * toeDenominator ) )
					- toeNumerator / toeDenominator );
			}
			, InVec3{ writer, "x" } );

		auto sampleTex = writer.implementFunction< Vec3 >( "sampleTex"
			, [&]( SampledImage2DRgba32 const & tex
				, Vec2 const & coords )
			{
				writer.returnStmt( tex.sample( coords ).rgb() );
			}
			, InSampledImage2DRgba32{ writer, "tex" }
			, InVec2{ writer, "coords" } );

		writer.implementMainT< FrgInT >( [&]( InputT< FrgInT > in )
			{
				auto hdrColor = writer.declLocale( "hdrColor"
					, sampleTex( c3d_mapDiffuse, in.texcoord ) );
				hdrColor *= vec3( exposureBias ); // Hardcoded Exposure Adjustment.

				auto current = writer.declLocale( "current"
					, uncharted2ToneMap( hdrColor * c3d_exposure ) );

				auto whiteScale = writer.declLocale( "whiteScale"
					, vec3( 1.0_f ) / uncharted2ToneMap( vec3( linearWhitePointValue ) ) );
				auto colour = writer.declLocale( "colour"
					, current * whiteScale );

				pxl_rgb = vec4( applyGamma( c3d_gamma, colour ), 1.0 );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void compute( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "compute" );
		using namespace sdw;
		ComputeWriter writer;
		auto in = writer.getIn();
		ArraySsboT< UInt > ssbo{ writer, "Datas", writer.getTypesCache().getUInt(), ast::type::MemoryLayout::eStd140 , 0u, 0u, true };
		auto img = writer.declImage< RWUImg2DR32 >( "img", 1u, 0u );

		writer.inputLayout( 16u, 16u );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				ssbo[in.globalInvocationID.x()]
					= ssbo[in.globalInvocationID.x()]
					* ssbo[in.globalInvocationID.x()];
				img.store( ivec2( in.globalInvocationID.xy() )
					, ssbo[in.globalInvocationID.x()] );
			} );

		test::writeShader( writer.getShader()
			, testCounts, CurrentCompilers );

#if !defined( __APPLE__ )
		// Disabled on apple since somebody somewhere thinks putting an ivec3 inside an uint3 intrinsic is doable :/.
		test::validateShader( writer.getShader()
			, testCounts, CurrentCompilers );
#endif

		testEnd();
	}

	void swizzles( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "swizzles" );
		using namespace sdw;
		ComputeWriter writer;

		auto c3d_mapDepth = writer.declSampledImage< FImg2DRgba32 >( "c3d_mapDepth", 1u, 0u );

		auto SMAAEdgeDetectionVS = writer.implementFunction< sdw::Void >( "SMAAEdgeDetectionVS"
			, [&]( Vec4 const & rtMetrics
				, Vec2 const & texcoord
				, Array< Vec4 > offset )
			{
				offset[0] = fma( rtMetrics.xyxy(), vec4( -1.0_f, 0.0, 0.0, -1.0 ), vec4( texcoord.xy(), texcoord.xy() ) );
				offset[1] = fma( rtMetrics.xyxy(), vec4( 1.0_f, 0.0, 0.0, 1.0 ), vec4( texcoord.xy(), texcoord.xy() ) );
				offset[2] = fma( rtMetrics.xyxy(), vec4( -2.0_f, 0.0, 0.0, -2.0 ), vec4( texcoord.xy(), texcoord.xy() ) );
			}
			, InVec4{ writer, "rtMetrics" }
			, InVec2{ writer, "texcoord" }
			, OutVec4Array{ writer, "offset", 3u } );

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto csPosition = writer.declLocale< Vec4 >( "csPosition" );
				csPosition.xyz() /= csPosition.w();
				csPosition.x() /= fma( csPosition.x(), 0.5_f, 0.5_f );
				auto csPositions = writer.declLocaleArray< Vec4 >( "csPositions", 4u );
				csPositions[0].xyz() /= csPositions[1].w();
				auto ssPosition = writer.declLocale< IVec2 >( "ssPosition" );
				auto position = writer.declLocale< Vec3 >( "position" );
				position.z() = c3d_mapDepth.fetch( ssPosition, 0_i ).r();
				auto lrtMetrics = writer.declLocale< Vec4 >( "lrtMetrics" );
				auto ltexcoord = writer.declLocale< Vec2 >( "ltexcoord" );
				auto loffset = writer.declLocaleArray< Vec4 >( "loffset", 3u );
				SMAAEdgeDetectionVS( lrtMetrics, ltexcoord, loffset );
				auto L = writer.declLocale< Float >( "L" );
				auto Lright = writer.declLocale< Float >( "Lright" );
				auto Lbottom = writer.declLocale< Float >( "Lbottom" );
				auto delta = writer.declLocale< Vec4 >( "delta" );
				delta.zw() = abs( L - vec2( Lright, Lbottom ) );
				auto texcoord = writer.declLocale< Vec2 >( "texcoord" );
				auto a = writer.declLocale< Vec4 >( "a" );
				a.wz() = c3d_mapDepth.lod( texcoord, 0.0_f ).xz();
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void conversions( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "conversions" );
		using namespace sdw;
		ComputeWriter writer;

		writer.inputLayout( 16 );
		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto o = writer.declLocaleArray( "o"
					, 6u
					, std::vector< Float >{
						{
							-1.0_f, -0.6667_f, -0.3333_f, 0.3333_f, 0.6667_f, 1.0_f
						} } );
				auto offset = writer.declLocale( "offset"
					, sdw::fma( vec2( o[0] )
						, vec2( 1.0_f )
						, vec2( 0.0_f ) ) );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void outputs( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "outputs" );
		using namespace sdw;
		FragmentWriter writer;

		auto pxl_velocity( writer.declOutput< Vec4 >( "pxl_velocity", 0u ) );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				pxl_velocity.xy() = vec2( 0.0_f );
			} );

		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void skybox( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "skybox" );
		using namespace sdw;
		FragmentWriter writer;

		// Shader inputs
		Ubo hdrConfig{ writer, "BufferHdrConfig", 0u, 0u };
		auto c3d_exposure = hdrConfig.declMember< Float >( "c3d_exposure" );
		auto c3d_gamma = hdrConfig.declMember< Float >( "c3d_gamma" );
		hdrConfig.end();

		auto c3d_mapSkybox = writer.declSampledImage< FImg2DRgba32 >( "c3d_mapSkybox", 1u, 0u );
		auto vtx_texture = writer.declInput< Vec2 >( "vtx_texture", 0u );

		auto removeGamma = writer.implementFunction< Vec3 >( "removeGamma"
			, [&]( Float const & gamma
				, Vec3 const & srgb )
			{
				writer.returnStmt( pow( srgb, vec3( gamma ) ) );
			}
			, InFloat{ writer, "gamma" }
			, InVec3{ writer, "srgb" } );

		// Shader outputs
		auto pxl_FragColor = writer.declOutput< Vec4 >( "pxl_FragColor", 0u );

		writer.implementFunction< sdw::Void >( "main"
			, [&]()
			{
				auto colour = writer.declLocale( "colour"
					, c3d_mapSkybox.sample( vtx_texture ) );

				pxl_FragColor = vec4( removeGamma( c3d_gamma, colour.xyz() ), colour.w() );
				pxl_FragColor = vec4( removeGamma( 0.1_f, vec3( 0.0_f, 0.0_f, 0.0_f ) ), colour.w() );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace posCol
	{
		template< sdw::var::Flag FlagT >
		struct VtxDataT
			: sdw::StructInstance
		{
			VtxDataT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, position{ getMember< sdw::Vec4 >( "position" ) }
				, colour{ getMember< sdw::Vec4 >( "colour" ) }
			{
			}

			SDW_DeclStructInstance( , VtxDataT );

			static sdw::type::IOStructPtr makeType( sdw::type::TypesCache & cache )
			{
				auto result = cache.getIOStruct( sdw::type::MemoryLayout::eC
					, ( FlagT == ast::var::Flag::eShaderOutput
						? std::string{ "Output" }
						: std::string{ "Input" } ) + "VtxData"
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
	}

	void vtx_frag( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "vtx_frag" );
		using namespace sdw;
		using namespace posCol;

		ShaderArray shaders;
		{
			VertexWriter writer;

			writer.implementMainT< VtxDataT, VtxDataT >( [&]( VertexInT< VtxDataT > in
				, VertexOutT< VtxDataT > out )
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

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "fragColor", 0u );

			writer.implementMainT< VtxDataT >( [&]( InputT< VtxDataT > in )
				{
					outColor = in.colour;
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
		using namespace posCol;

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

			writer.implementMainT< VtxDataT, VtxDataT >( [&]( VertexInT< VtxDataT > in
				, VertexOutT< VtxDataT > out )
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

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "fragColor", 0u );

			writer.implementMainT< VtxDataT >( [&]( InputT< VtxDataT > in )
				{
					outColor = in.colour;
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
		using namespace posCol;

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

			writer.implementMainT< VtxDataT, VtxDataT >( [&]( VertexInT< VtxDataT > in
				, VertexOutT< VtxDataT > out )
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

			// Shader outputs
			auto outColor = writer.declOutput< Vec4 >( "fragColor", 0u );

			writer.implementMainT< VtxDataT >( [&]( InputT< VtxDataT > in )
				{
					outColor = in.colour;
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
		using namespace posCol;

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

			writer.implementMainT< VtxDataT, VtxDataT >( [&]( VertexInT< VtxDataT > in
				, VertexOutT< VtxDataT > out )
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

			// Shader outputs
			auto fragColor = writer.declOutput<Vec4>( "fragColor", 0u );

			writer.implementMainT< VtxDataT >( [&]( InputT< VtxDataT > in )
				{
					fragColor = in.colour;
				} );

			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void radiance_computer( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "radiance_computer" );
		using namespace sdw;
		using namespace posCol;
		FragmentWriter writer;

		// Inputs
		auto c3d_mapEnvironment = writer.declSampledImage< FImgCubeRgba32 >( "c3d_mapEnvironment", 1u, 0u );

		// Outputs
		auto pxl_fragColor = writer.declOutput< Vec4 >( "pxl_FragColor", 0u );

		writer.implementMainT< VtxDataT >( [&]( InputT< VtxDataT > in )
			{
				// From https://learnopengl.com/#!PBR/Lighting
				// the sample direction equals the hemisphere's orientation 
				auto normal = writer.declLocale( "normal"
					, normalize( in.position.xyz() ) );

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

				FOR( writer, Float, phi, 0.0_f, phi < 6.283185482025146484375_f, phi += sampleDelta )
				{
					FOR( writer, Float, theta, 0.0_f, theta < 1.57079637050628662109375_f, theta += sampleDelta )
					{
						// spherical to cartesian (in tangent space)
						auto tangentSample = writer.declLocale( "tangentSample"
							, vec3( sin( theta ) * cos( phi ), sin( theta ) * sin( phi ), cos( theta ) ) );
						// tangent space to world
						auto sampleVec = writer.declLocale( "sampleVec"
							, right * tangentSample.x() + up * tangentSample.y() + normal * tangentSample.z() );

						irradiance += c3d_mapEnvironment.sample( sampleVec ).rgb() * cos( theta ) * sin( theta );
						nrSamples = nrSamples + 1;
					}
					ROF;
				}
				ROF;

				irradiance = irradiance * 3.1415927410125732421875_f *( 1.0_f / writer.cast< Float >( nrSamples ) );
				pxl_fragColor = vec4( irradiance, 1.0_f );
			} );
		test::writeShader( writer
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace posTexNmlTan
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
				, normal{ getMember< sdw::Vec3 >( "normal" ) }
				, texcoord{ getMember< sdw::Vec2 >( "texcoord" ) }
				, tangent{ getMember< sdw::Vec4 >( "tangent" ) }
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
	}

	void arthapzMin( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "arthapzMin" );
		sdw::ShaderArray shaders;
		using namespace posTexNmlTan;
		{
			auto writer = sdw::VertexWriter{};

			writer.implementMainT< PositionT, PositionT >( [&]( sdw::VertexInT< PositionT > in
				, sdw::VertexOutT< PositionT > out )
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
			auto frag_color = writer.declOutput<sdw::Vec4>( "frag_color", 0u );
			auto base_color_sampler = writer.declSampledImage<FImg2DRgba32>( "base_color_sampler", 0, 2 );

			auto getEmissiveColor = writer.implementFunction<sdw::Vec4>( "getEmissiveColor", [&]()
				{
					writer.returnStmt( sdw::vec4( 0._f, 0.f, 0.f, 0.f ) );
				} );

			writer.implementMainT< PositionT >( [&]( sdw::InputT< PositionT > in )
				{
					frag_color = base_color_sampler.sample( in.texcoord ) + getEmissiveColor();
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
		using namespace posTexNmlTan;
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

			writer.implementMainT< PositionT, PositionT >( [&]( sdw::VertexInT< PositionT > in
				, sdw::VertexOutT< PositionT > out )
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
			auto frag_color = writer.declOutput<sdw::Vec4>( "frag_color", 0u );

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

			auto out = writer.getOut();

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

			writer.implementMainT< PositionT >( [&]( sdw::InputT< PositionT > in )
				{
					auto N = writer.declLocale<sdw::Vec3>( "N"
						, sdw::normalize( getNormal( in.normal, in.texcoord, in.tangent ) ) );
					auto V = writer.declLocale<sdw::Vec3>( "V",
						camera.getMember<sdw::Vec4>( "position" ).xyz() -
						in.position );

					frag_color = base_color_sampler.sample( in.texcoord ) + getEmissiveColor( in.texcoord );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}

		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	namespace pos
	{
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
		using InputPosition = PositionT< sdw::var::Flag::eShaderInput >;
		using OutputPosition = PositionT< sdw::var::Flag::eShaderOutput >;
	}

	void clipDistance( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "clipDistance" );
		using namespace sdw;
		using namespace pos;
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

			auto outColor = writer.declOutput< sdw::Vec4 >( "outColor", 0u );

			writer.implementMain( [&]()
				{
					outColor = vec4( 1.0_f, 0.0f, 1.0f, 0.0f );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void simpleStore( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "simpleStore" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			ComputeWriter writer;
			auto kernelImage =
				writer.declImage<RWFImg2DRgba32>( "kernelImage", 0, 0 );
			writer.inputLayout( 32u );
			auto in = writer.getIn();

			writer.implementMain( [&]()
				{
					IVec2 iuv = writer.declLocale(
						"iuv", ivec2( writer.cast<Int>( in.globalInvocationID.x() ),
							writer.cast<Int>( in.globalInvocationID.y() ) ) );

					kernelImage.store( iuv, vec4( 1.0_f ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	struct Voxel
		: public sdw::StructInstance
	{
		SDW_DeclStructInstance( , Voxel );

		Voxel( sdw::ShaderWriter & writer
			, ast::expr::ExprPtr expr
			, bool enabled )
			: StructInstance{ writer, std::move( expr ), enabled }
			, colorMask{ getMember< sdw::UInt >( "colorMask" ) }
			, normalMask{ getMember< sdw::UInt >( "normalMask" ) }
		{
		}

		static ast::type::BaseStructPtr makeType( ast::type::TypesCache & cache )
		{
			auto result = cache.getStruct( ast::type::MemoryLayout::eStd430
				, "Voxel" );

			if ( result->empty() )
			{
				result->declMember( "colorMask", ast::type::Kind::eUInt );
				result->declMember( "normalMask", ast::type::Kind::eUInt );
			}

			return result;
		}

		// Raw values
		sdw::UInt colorMask;
		sdw::UInt normalMask;

	private:
		using sdw::StructInstance::getMember;
		using sdw::StructInstance::getMemberArray;
	};

	void voxelToTexture( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "voxelToTexture" );
		using namespace sdw;
		sdw::ShaderArray shaders;

		{
			enum IDs : uint32_t
			{
				eVoxelUbo,
				eVoxels,
				eResult,
			};

			using namespace sdw;
			ComputeWriter writer;

			writer.inputLayout( 256u, 1u, 1u );

			// Inputs
			sdw::Ubo voxelizer{ writer
				, "VoxelUbo"
				, eVoxelUbo
				, 0u };
			auto c3d_voxelTransform = voxelizer.declMember< sdw::Mat4 >( "c3d_voxelTransform" );
			auto c3d_voxelCenter = voxelizer.declMember< sdw::Vec4 >( "c3d_voxelCenter" );
			auto c3d_voxelSize = voxelizer.declMember< sdw::Float >( "c3d_voxelSize" );
			auto c3d_voxelSizeInverse = voxelizer.declMember< sdw::Float >( "c3d_voxelSizeInverse" );
			auto c3d_voxelResolution = voxelizer.declMember< sdw::Float >( "c3d_voxelResolution" );
			auto c3d_voxelResolutionInverse = voxelizer.declMember< sdw::Float >( "c3d_voxelResolutionInverse" );
			voxelizer.end();

			auto voxels( writer.declArrayShaderStorageBuffer< Voxel >( "voxels"
				, eVoxels
				, 0u ) );
			auto in = writer.getIn();

			// Outputs
			auto result( writer.declImage< RWFImg3DRgba32 >( "result"
				, eResult
				, 0u ) );

			auto decodeColor = writer.implementFunction< Vec4 >( "decodeColor"
				, [&]( UInt const & colorMask )
				{
					auto hdrRange = writer.declConstant( "hdrRange", 10.0_f );

					auto color = writer.declLocale< Vec4 >( "color" );
					auto hdr = writer.declLocale( "hdr"
						, writer.cast< Float >( ( colorMask >> 24u ) & 0x0000007f ) );
					color.r() = writer.cast< Float >( ( colorMask >> 16u ) & 0x000000ff );
					color.g() = writer.cast< Float >( ( colorMask >> 8u ) & 0x000000ff );
					color.b() = writer.cast< Float >( colorMask & 0x000000ff );

					hdr /= 127.0f;
					color.rgb() /= vec3( 255.0_f );

					color.rgb() *= hdr * hdrRange;

					color.a() = writer.cast< Float >( ( colorMask >> 31u ) & 0x00000001_u );

					writer.returnStmt( color );
				}
				, InUInt{ writer, "colorMask" } );

			auto unflatten = writer.implementFunction< UVec3 >( "unflatten3D"
				, [&]( UInt idx
					, UVec3 const & dim )
				{
					auto z = writer.declLocale( "z"
						, idx / ( dim.x() * dim.y() ) );
					idx -= ( z * dim.x() * dim.y() );
					auto y = writer.declLocale( "y"
						, idx / dim.x() );
					auto x = writer.declLocale( "x"
						, idx % dim.x() );
					writer.returnStmt( uvec3( x, y, z ) );
				}
				, InUInt{ writer, "idx" }
				, InUVec3{ writer, "dim" } );

			writer.implementMain( [&]()
				{
					auto color = writer.declLocale( "color"
						, decodeColor( voxels[in.globalInvocationID.x()].colorMask ) );

					IF( writer, color.a() > 0.0_f )
					{
						auto coord = writer.declLocale( "coord"
							, ivec3( unflatten( in.globalInvocationID.x()
								, uvec3( writer.cast< UInt >( c3d_voxelResolution ) ) ) ) );
						result.store( coord, color );
					}
					FI;

					voxels[in.globalInvocationID.x()].colorMask = 0_u;
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void imageArray( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "imageArray" );
		using namespace sdw;
		sdw::ShaderArray shaders;
		{
			ComputeWriter writer;
			auto srcImage = writer.declImage<RFImg2DRgba32>( "srcImage", 0, 0 );
			auto dstImage = writer.declImageArray<RWFImg2DRgba32>( "dstImage", 1, 0, 8u );
			writer.inputLayout( 32u );
			auto in = writer.getIn();

			writer.implementMain( [&]()
				{
					IVec2 iuv = writer.declLocale(
						"iuv", ivec2( writer.cast<Int>( in.globalInvocationID.x() ),
							writer.cast<Int>( in.globalInvocationID.y() ) ) );

					dstImage[1].store( iuv, srcImage.load( iuv ) );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void textureOffset( test::sdw_test::TestCounts & testCounts )
	{
		auto name = "textureOffset";
		testBegin( name );
		using namespace sdw;
		{
			FragmentWriter writer;
			auto tex = writer.declInput< Vec2 >( "tex", 0u );
			auto r = writer.declInput< Float >( "r", 1u );
			auto d = writer.declInput< Vec2 >( "d", 2u );
			auto s = writer.declSampledImage< FImg2DRgba32 >( "s", 0u, 0u );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto factor = writer.declLocale( "factor"
						, r * s.lod( tex, 0.0_f, ivec2( 0_i, -2_i ) ).r() );
				} );
			test::writeShader( writer
				, testCounts
				, Compilers_SPIRV );
		}
		testEnd();
	}

	void accessChainAlias( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "accessChainAlias" );
		using namespace sdw;
		ShaderArray shaders;
		{
			auto writer = ComputeWriter{};
			writer.inputLayout( 16u, 16u );

			sdw::Ubo ubo{ writer, "Wow", 0u, 0u };
			auto mtx = ubo.declMember< sdw::Mat4 >( "mtx" );
			auto pos = ubo.declMember< sdw::Vec3 >( "pos" );
			ubo.end();

			writer.implementMain( [&]()
				{
					auto tmp = writer.declLocale( "tmp"
						, normalize( transpose( mat3( mtx ) ) * pos ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
			shaders.emplace_back( std::move( writer.getShader() ) );
		}
		test::validateShaders( shaders
			, testCounts, CurrentCompilers );
		testEnd();
	}

	void constVectorShuffle( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "constVectorShuffle" );
		using namespace sdw;
		{
			using namespace sdw;
			VertexWriter writer;

			// Shader constants
			auto constVec = writer.declConstant( "constVec"
				, vec4( 300.0_f ) );

			writer.implementFunction< sdw::Void >( "main"
				, [&]()
				{
					auto loc = writer.declLocale( "loc"
						, length( constVec.xyxy() ) );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	namespace posOff
	{
		template< sdw::var::Flag FlagT >
		struct PositionT
			: sdw::StructInstance
		{
			PositionT( sdw::ShaderWriter & writer
				, sdw::expr::ExprPtr expr
				, bool enabled = true )
				: sdw::StructInstance{ writer, std::move( expr ), enabled }
				, position{ getMember< sdw::Vec4 >( "position" ) }
				, texoff{ getMember< sdw::Vec2 >( "texoff" ) }
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
					result->declMember( "texoff"
						, sdw::type::Kind::eVec2F
						, sdw::type::NotArray
						, 1u );
				}

				return result;
			}

			sdw::Vec4 position;
			sdw::Vec2 texoff;
		};
		using InputPosition = PositionT< sdw::var::Flag::eShaderInput >;
		using OutputPosition = PositionT< sdw::var::Flag::eShaderOutput >;
	}

	void smaaEdgeDetectionVS( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "smaaEdgeDetectionVS" );
		using namespace sdw;
		using namespace posOff;
		{
			VertexWriter writer;

			float w = 300;
			float h = 200;
			std::array< float, 4u > renderTargetMetrics{ 1.0f / w, 1.0f / h, w, h };

			// Shader constants
			auto c3d_rtMetrics = writer.declConstant( "SMAA_RT_METRICS"
				, vec4( Float( renderTargetMetrics[0] ), renderTargetMetrics[1], renderTargetMetrics[2], renderTargetMetrics[3] ) );

			// Shader inputs
			auto position = writer.declInput< Vec2 >( "position", 0u );
			auto uv = writer.declInput< Vec2 >( "uv", 1u );

			// Shader outputs
			auto vtx_texture = writer.declOutput< Vec2 >( "vtx_texture", 0u );
			auto vtx_offset = writer.declOutputArray< Vec4 >( "vtx_offset", 1u, 3u );

			/**
			 * Edge Detection Vertex Shader
			 */
			auto SMAAEdgeDetectionVS = writer.implementFunction< sdw::Void >( "SMAAEdgeDetectionVS"
				, [&]( Vec2 const & texCoord
					, Array< Vec4 > offset )
				{
					offset[0] = fma( c3d_rtMetrics.xyxy(), vec4( Float{ -1.0f }, 0.0_f, 0.0_f, Float{ -1.0f } ), vec4( texCoord.xy(), texCoord.xy() ) );
					offset[1] = fma( c3d_rtMetrics.xyxy(), vec4( 1.0_f, 0.0_f, 0.0_f, 1.0_f ), vec4( texCoord.xy(), texCoord.xy() ) );
					offset[2] = fma( c3d_rtMetrics.xyxy(), vec4( Float{ -2.0f }, 0.0_f, 0.0_f, Float{ -2.0f } ), vec4( texCoord.xy(), texCoord.xy() ) );
				}
				, InVec2{ writer, "texCoord" }
				, OutVec4Array{ writer, "offset", 3u } );

			writer.implementMainT< VoidT, VoidT >( [&]( sdw::VertexInT< VoidT > in
				, sdw::VertexOutT< VoidT > out )
				{
					out.vtx.position = vec4( position, 0.0_f, 1.0_f );
					vtx_texture = uv;
					vtx_offset[0] = vec4( 0.0_f );
					vtx_offset[1] = vec4( 0.0_f );
					vtx_offset[2] = vec4( 0.0_f );
					SMAAEdgeDetectionVS( vtx_texture, vtx_offset );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		testEnd();
	}

	void duplicateLoadTest( test::sdw_test::TestCounts & testCounts )
	{
		testBegin( "duplicateLoadTest" );
		using namespace sdw;
		ShaderArray shaders;
		{
			ComputeWriter writer;
			writer.inputLayout( 16u, 16u );

			auto foo = writer.implementFunction< sdw::Vec4 >( "foo"
				, [&]( Vec3 const & t
					, Vec2 const & dir )
				{
					auto coord = writer.declLocale< Vec4 >( "coord" );
					coord.xyz() = fma( t, vec3( dir, 1.0_f ), coord.xyz() );
					writer.returnStmt( coord );
				}
				, InVec3{ writer, "t" }
				, InVec2{ writer, "dir" } );

			writer.implementMain( [&]()
				{
					auto t = writer.declLocale( "t", vec3( 0.5_f ) );
					auto dir = writer.declLocale( "dir", vec2( 1.0_f ) );
					foo( t, dir );
				} );
			test::writeShader( writer
				, testCounts, CurrentCompilers );
		}
		//test::validateShaders( shaders
		//	, testCounts );
		testEnd();
	}
}

sdwTestSuiteMain( TestWriterShader )
{
	sdwTestSuiteBegin();
	reference( testCounts );
	vertex( testCounts );
	fragment( testCounts );
	compute( testCounts );
	swizzles( testCounts );
	conversions( testCounts );
	outputs( testCounts );
	skybox( testCounts );
	vtx_frag( testCounts );
	charles( testCounts );
	charles_approx( testCounts );
	charles_latest( testCounts );
	radiance_computer( testCounts );
	arthapzMin( testCounts );
	arthapz( testCounts, false, false );
	arthapz( testCounts, false, true );
	arthapz( testCounts, true, false );
	arthapz( testCounts, true, true );
	simpleStore( testCounts );
	voxelToTexture( testCounts );
	clipDistance( testCounts );
	imageArray( testCounts );
	textureOffset( testCounts );
	accessChainAlias( testCounts );
	constVectorShuffle( testCounts );
	smaaEdgeDetectionVS( testCounts );
	duplicateLoadTest( testCounts );
	sdwTestSuiteEnd();
}

sdwTestSuiteLaunch( TestWriterShader )
